//////////////////////////////////////////////////////////////////////////
//
// this class is inherited from wxGridTableBase.h
// and it is revised according to pgAdmin 1.18.1 's source.
//////////////////////////////////////////////////////////////////////////

// wxWindows headers
#include <wx/wx.h>
#include <wx/grid.h>
#include "nstdapptable.h"

// App headers

#include <wx/generic/gridctrl.h>
#include <wx/clipbrd.h>
#include <wx/tokenzr.h>
#include <wx/datectrl.h>
#include "wfApp.h"

nstdappGrid::nstdappGrid(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size)
    : ctlSQLGrid(parent, id, pos, size)
{
}

bool nstdappGrid::CheckRowPresent(int row)
{
    return GetTable()->CheckInCache(row);
}

void nstdappGrid::ResizeEditor(int row, int col)
{

    if (GetTable()->needsResizing(col))
    {
        wxGridCellAttr *attr = GetCellAttr(row, col);
        wxGridCellRenderer *renderer = attr->GetRenderer(this, row, col);
        if ( renderer )
        {
            wxClientDC dc(GetGridWindow());
            wxSize size = renderer->GetBestSize(*this, *attr, dc, row, col);
            renderer->DecRef();

            int w = wxMax(size.GetWidth(), 15) + 20;
            int h = wxMax(size.GetHeight(), 15) + 20;


            wxGridCellEditor *editor = attr->GetEditor(this, row, col);
            if (editor)
            {
                wxRect cellRect = CellToRect(m_currentCellCoords);
                wxRect rect = cellRect;
                rect.SetWidth(w);
                rect.SetHeight(h);

                // we might have scrolled
                CalcUnscrolledPosition(0, 0, &w, &h);
                rect.SetLeft(rect.GetLeft() - w);
                rect.SetTop(rect.GetTop() - h);

                // Clip rect to client size
                GetClientSize(&w, &h);
                rect.SetRight(wxMin(rect.GetRight(), w));
                rect.SetBottom(wxMin(rect.GetBottom(), h));

                // but not smaller than original cell
                rect.SetWidth(wxMax(cellRect.GetWidth(), rect.GetWidth()));
                rect.SetHeight(wxMax(cellRect.GetHeight(), rect.GetHeight()));

                editor->SetSize(rect);
                editor->DecRef();
            }
        }

        attr->DecRef();
    }
}

wxArrayInt nstdappGrid::GetSelectedRows() const
{
    wxArrayInt rows, rows2;

    wxGridCellCoordsArray tl = GetSelectionBlockTopLeft(), br = GetSelectionBlockBottomRight();

    int maxCol = ((nstdappGrid *)this)->GetNumberCols() - 1;
    size_t i;
    for (i = 0 ; i < tl.GetCount() ; i++)
    {
        wxGridCellCoords c1 = tl.Item(i), c2 = br.Item(i);
        if (c1.GetCol() != 0 || c2.GetCol() != maxCol)
            return rows2;

        int j;
        for (j = c1.GetRow() ; j <= c2.GetRow() ; j++)
            rows.Add(j);
    }

    rows2 = wxGrid::GetSelectedRows();

    rows.Sort(ArrayCmp);
    rows2.Sort(ArrayCmp);

    size_t i2 = 0, cellRowMax = rows.GetCount();

    for (i = 0 ; i < rows2.GetCount() ; i++)
    {
        int row = rows2.Item(i);
        while (i2 < cellRowMax && rows.Item(i2) < row)
            i2++;
        if (i2 == cellRowMax || row != rows.Item(i2))
            rows.Add(row);
    }

    return rows;
}

nstdappTable::nstdappTable(wxPostgreSQLresult * _res, wxString &tablename, wxString &header, wxString _colStoreStatus, const wxString &_pkCols)
{
    tabName = tablename ;
    res = _res;
    pkCols = _pkCols;

    wxArrayString col_label = wxStringTokenize(header, wxT(";"), wxTOKEN_DEFAULT );


    rowsCached = 0;
    rowsAdded = 0;
    rowsStored = 0;
    rowsDeleted = 0;

    dataPool = 0;
    addPool = new cacheLinePool(500);       // arbitrary initial size
    lastRow = -1;
    int i;
    lineIndex = 0;

    nRows = res->GetRowsNumber();
    nCols = res->GetNumberFields();

    for(i=0;i<nCols;i++)
    {
       int i_status = wxAtoi(_colStoreStatus.Mid(i,1));
       colStoreStatus.Add(i_status);
    }

    columns = new sqlEditCellAttr[nCols];
    savedLine.cols = new wxString[nCols];
    bool canInsert = false;

    for (i = 0 ; i < nCols ; i++)
    {

        columns[i].name = res->ColName(i);
        columns[i].type = res->ColTypeOID(i);

        columns[i].typlen = res->ColSize(i);
        columns[i].typmod = res->ColTypeMod(i);
        columns[i].label_name = col_label.Item(i);

        switch(colStoreStatus.Item(i))
        {
        case 0:
              columns[i].attr->SetReadOnly(true);
              columns[i].attr->SetBackgroundColour(*wxLIGHT_GREY);
              break;
        case 1:
               columns[i].attr->SetReadOnly(false);
               columns[i].attr->SetBackgroundColour(*wxWHITE);
               break;
        default:
              columns[i].attr->SetReadOnly(true);
              columns[i].needResize = true;
              break;
        }
    }

    if (nRows)
    {
        dataPool = new cacheLinePool(nRows);
        lineIndex = new int[nRows];
        for (i = 0 ; i < nRows ; i++)
            lineIndex[i] = i;
    }

    if (canInsert)
    {
        // an empty line waiting for inserts
        rowsAdded = 1;
    }
}


nstdappTable::~nstdappTable()
{
    res = 0;
    if (dataPool)
        delete dataPool;

    delete addPool;

    delete[] columns;

    if (lineIndex)
        delete[] lineIndex;
}


int nstdappTable::GetNumberCols()
{
    return nCols;
}


int nstdappTable::GetNumberRows()
{
    return nRows + rowsAdded - rowsDeleted;
}


int nstdappTable::GetNumberStoredRows()
{
    return nRows + rowsStored - rowsDeleted;
}


bool nstdappGrid::IsColText(int col)
{
    return GetTable()->IsColText(col);
}

bool nstdappTable::IsColText(int col)
{
    return !columns[col].numeric && !(columns[col].type == PGOID_TYPE_BOOL);
}

bool nstdappTable::IsColBoolean(int col)
{
    return (columns[col].type == PGOID_TYPE_BOOL);
}

wxString nstdappTable::GetColLabelValue(int col)
{
    return columns[col].label_name;
}

wxString nstdappTable::GetRowLabelValue(int row)
{
    wxString label;
    if (row < nRows - rowsDeleted || GetLine(row)->stored)
        label.Printf(wxT("%d"), row + 1);
    else
        label = wxT("*");
    return label;
}



void nstdappTable::SetColEditor(int col, wxGridCellEditor *editor)
{
    columns[col].attr->SetReadOnly(false);
    columns[col].attr->SetEditor(editor);
}


bool nstdappTable::CheckInCache(int row)
{
    if (row > nRows - rowsDeleted + rowsAdded)
        return false;
    if (row >= nRows - rowsDeleted)
        return true;

    return dataPool->IsFilled(row);
}


cacheLine *nstdappTable::GetLine(int row)
{
    cacheLine *line;
    if (row < nRows - rowsDeleted)
        line = dataPool->Get(lineIndex[row]);
    else
        line = addPool->Get(row - (nRows - rowsDeleted));

    return line;
}



wxString nstdappTable::MakeKey(cacheLine *line)
{
    wxString str_clause=wxEmptyString;
    int icol;
    wxString colname;
    if (!pkCols.IsEmpty())
    {
        wxArrayString stra_pkcols = wxStringTokenize(pkCols, wxT(","),wxTOKEN_DEFAULT );

        int i_count = stra_pkcols.GetCount();
        int i,j;

        for(i=0;i<i_count;i++)
        {
            for(j=0;j<nCols;j++)
            {
                if(stra_pkcols.Item(i)==columns[j].name)
                {
                        colname = stra_pkcols.Item(i);
                        icol =j;
                        break;
                }
            }

            wxString colval = line->cols[icol];

            if (colval.IsEmpty())
                continue;

            if (!str_clause.IsEmpty())
				str_clause += wxT(" AND ");


           str_clause+= qtIdent(colname, false) + wxT("=")+ columns[icol].Quote(colval);
        }
    }
    else str_clause = GetWhereClause();

    return str_clause;
}

void nstdappTable::UndoLine(int row)
{
    if (lastRow >= 0 && row >= 0)
    {
        cacheLine *line = GetLine(row);
        if (line)
        {
            int i;
            for (i = 0 ; i < nCols ; i++)
                line->cols[i] = savedLine.cols[i];

        }
    }
    lastRow = -1;
}


bool nstdappTable::StoreLine()
{
    bool done = false;
    wxString str_query;

//    GetView()->BeginBatch();
    wxGridUpdateLocker locker(GetView());
    if (lastRow >= 0)
    {
        cacheLine *line = GetLine(lastRow);

        int i;
        wxString colList, valList;

        if (line->stored)
        {
            // UPDATE

            for (i =  0 ; i < nCols ; i++)
            {
                if(colStoreStatus.Item(i) == 0)
                    continue;

                if (savedLine.cols[i] != line->cols[i])
                {
                    if (!valList.IsNull())
                        valList += wxT(", ");
                    valList += qtIdent(columns[i].name,false) + wxT("=") + columns[i].Quote(line->cols[i]);
                }
            }

            if (valList.IsEmpty())
                done = true;
            else
            {
                valList += wxT(", modify_date = '")+DateToAnsiStr(wxDateTime::Now())+wxT("',modify_emp_id = '")+gr_para.login_user+wxT("' ");//by mikewolfli
                wxString key = MakeKey(&savedLine);
                wxASSERT(!key.IsEmpty());
                str_query = wxT("UPDATE ") + tabName + wxT(
                                                   " SET ") + valList + wxT(
                                                   " WHERE ") + key;
                done = wxGetApp().app_sql_update(str_query);
            }
        }
        else
        {
            // INSERT

            for (i = 0 ; i < nCols ; i++)
            {
                if(colStoreStatus.Item(i) == 0)
                    continue;

                if (!columns[i].attr->IsReadOnly() && !line->cols[i].IsEmpty())
                {
                    if (!colList.IsNull())
                    {
                        valList += wxT(", ");
                        colList += wxT(", ");
                    }
                    colList += qtIdent(columns[i].name,false);

                    valList += columns[i].Quote(line->cols[i]);
                }
            }

            if (!valList.IsEmpty())
            {
                colList += wxT(", modify_date, modify_emp_id, create_date, create_emp_id "); //by mikewolfli
                valList += wxT(", '")+ DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+ wxT("' ");//by mikewolfli
                str_query = wxT("INSERT INTO ") + tabName
                                              + wxT("(") + colList
                                              + wxT(") VALUES (") + valList
                                              + wxT(")");
                 //wxPostgreSQLresult *set = wxGetApp().app_sql_select(str_query);
                 done = wxGetApp().app_sql_select(str_query);
               /* if (set)
                {
                    if (set->GetInsertedCount() > 0)
                    {


                        done = true;
                        rowsStored++;
                        wxLogMessage(wxString::Format(wxT("%d rows."),GetNumberStoredRows()));
                        if (rowsAdded == rowsStored)
                            GetView()->AppendRows();

                        // Read back what we inserted to get default vals
                        wxString key = MakeKey(line);

                        if (key.IsEmpty())
                        {
                            // That's a problem: obviously, the key generated isn't present
                            // because it's serial or default or otherwise generated in the backend
                            // we don't get.
                            // That's why the whole line is declared readonly.

                            line->readOnly = true;
                        }
                        else
                        {
                            str_query = wxT("SELECT * FROM ") + tabName +
                                      wxT(" WHERE ") + key;
                            set = wxGetApp().app_sql_select(str_query);
                            if (set)
                            {
                                for (i =  0; i < nCols ; i++)
                                {
                                    line->cols[i] = set->GetVal(columns[i].name);
                                }
                                delete set;
                            }
                        }
                    }
                }*/
            }
        }
        if (done)
        {
            line->stored = true;
            lastRow = -1;
        }
        else
            GetView()->SelectRow(lastRow);
    }

  //  GetView()->EndBatch();

    return done;
}


void nstdappTable::SetValue(int row, int col, const wxString &value)
{
    cacheLine *line = GetLine(row);

    if (!line)
    {
        // Bad problem, no line!
        return;
    }


    if (row != lastRow)
    {
        if (lastRow >= 0)
            StoreLine();

        if (!line->cols)
            line->cols = new wxString[nCols];

        // remember line contents for later reference in update ... where
        int i;
        for (i = 0 ; i < nCols ; i++)
            savedLine.cols[i] = line->cols[i];
        lastRow = row;
    }
    if(columns[col].name == wxT("status"))
    {
        line->cols[col] = NumToStr(nstd_str_to_status(value));
    }else
        line->cols[col] = value;
}

void nstdappTable::Set_Saved_Line(int row)
{
    cacheLine *line = GetLine(row);

    if (!line)
    {
        // Bad problem, no line!
        return;
    }

    if(line->stored)
    {
        for (int i = 0 ; i < nCols ; i++)
            savedLine.cols[i] = line->cols[i];
    }
}

wxString nstdappTable::GetValue(int row, int col)
{
    wxString val;
    cacheLine *line;
    if (row < nRows - rowsDeleted)
        line = dataPool->Get(lineIndex[row]);
    else
        line = addPool->Get(row - (nRows - rowsDeleted));

    if (!line)
    {
        // Bad problem, no line!
        return val;
    }

    if (!line->cols)
    {
        line->cols = new wxString[nCols];
        if (row < nRows - rowsDeleted)
        {
            if (!res)
            {
//			    wxLogError(_("Unexpected empty cache line: dataSet already closed."));
                wxLogMessage(_("意外的空缓存行: 数据集已经关闭。"));
                return val;
            }

            line->stored = true;
            if (lineIndex[row] != res->CurrentPos() - 1)
                res->Locate(lineIndex[row] + 1);

            int i;
            for (i = 0 ; i < nCols ; i++)
            {
                line->cols[i] = res->GetVal(i);
            }
            rowsCached++;

            if (rowsCached == nRows)
            {
  //              delete res;
                res = 0;
            }
        }
    }
    if (columns[col].type == PGOID_TYPE_BOOL)
    {
        if (line->cols[col] != wxEmptyString)
            line->cols[col] = (StrToBool(line->cols[col]) ? wxT("TRUE") : wxT("FALSE"));
    }

    if(columns[col].name == wxT("status"))
    {
        val = nstd_status_to_str(wxAtoi(line->cols[col]));
    }else
        val = line->cols[col];

    if(columns[col].type == PGOID_TYPE_TIMESTAMP || columns[col].type == PGOID_TYPE_TIMESTAMPTZ)
    {
        val = DateToStrFormat(StrToDateTime(line->cols[col]));
    }

    return val;
}

bool nstdappTable::AppendRows(size_t rows)
{
    rowsAdded += rows;
    GetLine(nRows + rowsAdded - rowsDeleted - 1);

    wxGridTableMessage msg(this, wxGRIDTABLE_NOTIFY_ROWS_APPENDED, rows);
    GetView()->ProcessTableMessage(msg);

    return true;
}


bool nstdappTable::DeleteRows(size_t pos, size_t rows)
{

    size_t i = pos;
    size_t rowsDone = 0;

    while (i < pos + rows)
    {
        cacheLine *line = GetLine(pos);
        if (!line)
            break;

        // If line->cols is null, it probably means we need to force the cacheline to be populated.
        if (!line->cols)
        {
            GetValue(pos, 0);
            line = GetLine(pos);
        }

        if (line->stored)
        {
            wxString key = MakeKey(line);
            wxASSERT(!key.IsEmpty());
            wxString str_query  = wxT("DELETE FROM ") + tabName + wxT(" WHERE ") + key;
            bool done = wxGetApp().app_sql_update(str_query);
            if (!done)
                break;

            if ((int)pos < nRows - rowsDeleted)
            {
                rowsDeleted++;
                if ((int)pos < nRows - rowsDeleted)
                    memmove(lineIndex + pos, lineIndex + pos + 1, sizeof(*lineIndex) * (nRows - rowsDeleted - pos));
            }
            else
            {
                rowsAdded--;
                if (GetLine(pos)->stored)
                    rowsStored--;
                addPool->Delete(pos - (nRows - rowsDeleted));
            }
            rowsDone++;
        }
        else
        {
            // last empty line won't be deleted, just cleared
            int j;
            for (j = 0 ; j < nCols ; j++)
                line->cols[j] = wxT("");
        }
        i++;
    }

    if (rowsDone > 0 && GetView())
    {
        wxGridTableMessage msg(this, wxGRIDTABLE_NOTIFY_ROWS_DELETED, pos, rowsDone);
        GetView()->ProcessTableMessage(msg);
    }
    return (rowsDone != 0);
}


bool nstdappTable::Paste()
{
    int row, col;
    int start, pos, len;
    wxArrayString data;
    wxString text, quoteChar, colSep;
    bool inQuotes, inData, skipSerial;

    if (!this)
        return false;

    if (wxTheClipboard->Open())
    {
        if (wxTheClipboard->IsSupported(wxDF_TEXT))
        {
            wxTextDataObject textData;
            wxTheClipboard->GetData(textData);
            text = textData.GetText();
        }
        else
        {
            wxTheClipboard->Close();
            return false;
        }
        wxTheClipboard->Close();
    }
    else
    {
        return false;
    }

    start = pos = 0;
    len = text.Len();
    quoteChar = wxT("\"");
    colSep = wxT("\t");
    inQuotes = inData = false;

    while (pos < len && !(text[pos] == '\n' && !inQuotes))
    {
        if (!inData)
        {
            if (text[pos] == quoteChar)
            {
                inQuotes = inData = true;
                pos++;
                start++;
                continue;
            }
            else
            {
                inQuotes = false;
            }
            inData = true;
        }

        if (inQuotes && text[pos] == quoteChar &&
                (text[pos + 1] == colSep || text[pos + 1] == '\r' || text[pos + 1] == '\n'))
        {
            data.Add(text.Mid(start, pos - start));
            start = (pos += 2);
            inData = false;
        }
        else if (!inQuotes && text[pos] == colSep)
        {
            data.Add(text.Mid(start, pos - start));
            start = ++pos;
            inData = false;
        }
        else
        {
            pos++;
        }
    }
    if (start < pos)
    {
        if (inQuotes && text[pos - 1] == quoteChar)
            data.Add(text.Mid(start, pos - start - 1));
        else
            data.Add(text.Mid(start, pos - start));
    }

    row = GetNumberRows() - 1;
    skipSerial = false;

    for (col = 0; col < nCols; col++)
    {
        if (columns[col].type == (unsigned int)PGOID_TYPE_SERIAL ||
                columns[col].type == (unsigned int)PGOID_TYPE_SERIAL8)
        {
            wxMessageDialog msg(GetView()->GetParent(),
                                _("This table contains serial columns. Do you want to use the values in the clipboard for these columns?"),
                                _("Paste Data"), wxYES_NO | wxICON_QUESTION);
            if (msg.ShowModal() != wxID_YES)
            {
                skipSerial = true;
            }
            break;
        }
    }

    bool pasted = false;
    for (col = 0; col < nCols && col < (int)data.GetCount(); col++)
    {
        if (!(skipSerial && (columns[col].type == (unsigned int)PGOID_TYPE_SERIAL ||
                             columns[col].type == (unsigned int)PGOID_TYPE_SERIAL8)))
        {
            SetValue(row, col, data.Item(col));
            GetView()->SetGridCursor(row, col);
            GetView()->MakeCellVisible(row, col);
            pasted = true;
        }
    }
    GetView()->ForceRefresh();

    return pasted;
}

wxGridCellAttr *nstdappTable::GetAttr(int row, int col, wxGridCellAttr::wxAttrKind  kind)
{
    cacheLine *line = GetLine(row);

    if (line && line->readOnly)
    {
        wxGridCellAttr *attr = new wxGridCellAttr(columns[col].attr);
        attr->SetReadOnly();
        return attr;
    }
    else
    {
        columns[col].attr->IncRef();
        return columns[col].attr;
    }


}
