#include "sqlresulttable.h"
#include "wfApp.h"
#include <wx/tipwin.h>
#include <wx/clipbrd.h>

BEGIN_EVENT_TABLE(sqlResultGrid, wxGrid)
//	EVT_MOUSEWHEEL(sqlResultGrid::OnMouseWheel)
//	EVT_MOTION(sqlResultGrid::show_tooltip)
END_EVENT_TABLE()

//IMPLEMENT_DYNAMIC_CLASS(sqlResultGrid, wxGrid)

sqlResultGrid::sqlResultGrid()
{

}

sqlResultGrid::sqlResultGrid(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size)
    : wxGrid(parent, id, pos, size, wxWANTS_CHARS | wxVSCROLL | wxHSCROLL, _T(""))
{
    GetGridWindow()->Connect(GetGridWindow()->GetId(),wxEVT_MOTION,wxMouseEventHandler(sqlResultGrid::show_tooltip),NULL,this);
    GetGridWindow()->Connect(GetGridWindow()->GetId(), wxEVT_MOUSEWHEEL, wxMouseEventHandler(sqlResultGrid::OnMouseWheel),NULL, this);
    GetGridWindow()->Connect(GetGridWindow()->GetId(), wxEVT_KEY_DOWN, wxKeyEventHandler(sqlResultGrid::OnSqlKeyDown),NULL, this);
}


void sqlResultGrid::OnSqlKeyDown(wxKeyEvent &event)
{
    long key_code = event.GetKeyCode();
    switch(key_code)
    {
    case 'C':
    case 'c':
        if(event.ControlDown())
              Copy();
        break;
    default:
        break;
    }

    event.Skip();
}

void sqlResultGrid::OnCopy(wxCommandEvent &ev)
{
	Copy();
}

int sqlResultGrid::Copy()
{
	wxString str;
	int copied = 0;
	size_t i;



	if (GetSelectedRows().GetCount())
	{

		wxArrayInt rows = GetSelectedRows();

		for (i = 0 ; i < rows.GetCount() ; i++)
		{
			str.Append(GetExportLine(rows.Item(i)));

			if (rows.GetCount() > 1)
				str.Append(END_OF_LINE);
		}

		copied = rows.GetCount();
	}
	else if (GetSelectedCols().GetCount())
	{
		wxArrayInt cols = GetSelectedCols();
		size_t numRows = GetNumberRows();

     	for (i = 0 ; i < numRows ; i++)
		{
			str.Append(GetExportLine(i, cols));

			if (numRows > 1)
				str.Append(END_OF_LINE);
		}

		copied = numRows;
	}
	else if (GetSelectionBlockTopLeft().GetCount() > 0 &&
	         GetSelectionBlockBottomRight().GetCount() > 0)
	{
		unsigned int x1, x2, y1, y2;

		x1 = GetSelectionBlockTopLeft()[0].GetCol();
		x2 = GetSelectionBlockBottomRight()[0].GetCol();
		y1 = GetSelectionBlockTopLeft()[0].GetRow();
		y2 = GetSelectionBlockBottomRight()[0].GetRow();

		for (i = y1; i <= y2; i++)
		{
			str.Append(GetExportLine(i, x1, x2));

			if (y2 > y1)
				str.Append(END_OF_LINE);
		}

		copied = y2 - y1 + 1;
	}
	else
	{
		int row, col;

		row = GetGridCursorRow();
		col = GetGridCursorCol();

		str.Append(GetExportLine(row, col, col));
		copied = 1;
	}

	if (copied && wxTheClipboard->Open())
	{
		wxTheClipboard->SetData(new wxTextDataObject(str));
		wxTheClipboard->Close();
	}
	else
	{
		copied = 0;
	}

	return copied;
}



wxString sqlResultGrid::GetExportLine(int row)
{
	return GetExportLine(row, 0, GetNumberCols() - 1);
}


wxString sqlResultGrid::GetExportLine(int row, int col1, int col2)
{
	wxArrayInt cols;
	wxString str;
	int i;

	if (col2 < col1)
		return str;

	cols.Alloc(col2 - col1 + 1);
	for (i = col1; i <= col2; i++)
	{
		cols.Add(i);
	}

	return GetExportLine(row, cols);
}

wxString sqlResultGrid::GetExportLine(int row, wxArrayInt cols)
{
	wxString str;
	unsigned int col;

	if (GetNumberCols() == 0)
		return str;

	for (col = 0 ; col < cols.Count() ; col++)
	{
		if (col > 0)
//			str.Append(settings->GetCopyColSeparator());
            str.Append(wxT("\t"));

		wxString text = GetCellValue(row, cols[col]);

		bool needQuote  = false;

		str.Append(text);

	}
	return str;
}

void sqlResultGrid::show_tooltip( wxMouseEvent& event )
{
  // get cell coords
  wxPoint point = ScreenToClient(wxGetMousePosition());
//  wxPoint point = ScreenToClient(wxPoint(event.GetX(),event.GetY()));
  int x, y;
  CalcUnscrolledPosition(point.x,point.y,&x,&y);


  int row = YToRow(y-GetColLabelSize());
  int col = XToCol(x-GetRowLabelSize());

  if( col == wxNOT_FOUND || row == wxNOT_FOUND )
    {
      event.Skip();
      return;
    }

  // fetch cell value and type
  wxString val = GetCellValue(row, col);

  // show tooltip
  GetGridWindow()->SetToolTip(val);

  event.Skip();
}

wxArrayInt sqlResultGrid::GetSelectedRows() const
{
    wxArrayInt rows, rows2;

    wxGridCellCoordsArray tl = GetSelectionBlockTopLeft(), br = GetSelectionBlockBottomRight();

    int maxCol = ((sqlResultGrid *)this)->GetNumberCols() - 1;
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

void sqlResultGrid::OnMouseWheel(wxMouseEvent &event)
{
	if (event.ControlDown())
	{
		wxFont fontlabel = GetLabelFont();
		wxFont fontcells = GetDefaultCellFont();
		if (event.GetWheelRotation() > 0)
		{
			fontlabel.SetPointSize(fontlabel.GetPointSize() - 1);
			fontcells.SetPointSize(fontcells.GetPointSize() - 1);
		}
		else
		{
			fontlabel.SetPointSize(fontlabel.GetPointSize() + 1);
			fontcells.SetPointSize(fontcells.GetPointSize() + 1);
		}

		SetLabelFont(fontlabel);
		SetDefaultCellFont(fontcells);
		SetColLabelSize(fontlabel.GetPointSize() * 4);
		SetDefaultRowSize(fontcells.GetPointSize() * 2);
		for (int index = 0; index < GetNumberCols(); index++)
			SetColSize(index, -1);
		ForceRefresh();
	}
	else
		event.Skip();
}


sqlResultTable::sqlResultTable(wxPostgreSQLresult * _res, wxString &tablename, wxString &header, int i_use)
{
    //ctor
    res=_res;
    table_name = tablename;
    m_use = i_use;

    rows_num = res->GetRowsNumber();
    cols_num = res->GetNumberFields();

    SetLabelValue(header);

    int i,j;

    for (i=0; i<cols_num; i++)
    {
        colTypes.Add(_res->ColTypeOID(i));
        colNames.Add(_res->ColName(i));
    }

//    m_data.Alloc(rows_num);


    res->MoveFirst();
    if(rows_num>0)
      rows_attr = new sqlResultCellAttr[rows_num];
    else rows_attr = NULL;

    int i_color;//0 white, 1 red, 2 绿色， 3 黄色 4 天蓝色
//    wxString str_prj_catalog;

    int i_font_color;

   wxArrayString line;
   wxString str;

    for(i=0; i<rows_num; i++)
    {
        i_color = 0;
        i_font_color = 0;
        for(j=0; j<cols_num; j++)
        {

            switch(colTypes.Item(j))
            {
            case PGOID_TYPE_BOOL:
                if(res->GetBool(j))
                    str=wxT("Y");
                else str.Empty();

                if(colNames.Item(j)== wxT("is_urgent"))
                {
                    if(res->GetBool(j))
                       i_color = 2;
                }

                if(colNames.Item(j) == wxT("has_nonstd_inst_info"))
                {
                    if(res->GetBool(j))
                        i_font_color = 1;
                }

                break;
            case PGOID_TYPE_INT8:
            case PGOID_TYPE_SERIAL8:
            case PGOID_TYPE_INT2:
            case PGOID_TYPE_INT4:
            case PGOID_TYPE_SERIAL:
                if(colNames.Item(j)== wxT("status"))
                {
                    switch(m_use)
                    {
                      case 0:
                       str = prj_status_to_str(res->GetInt(j));
                       break;
                      case 1:
                        str = nstd_status_to_str(res->GetInt(j));
                        break;
                      default:
                          str.Empty();
                        break;
                    }

                    if(res->GetInt(j) == 4&& m_use ==0)
                        i_color = 1;
                }
                else if(colNames.Item(j)== wxT("project_catalog"))
                {
                    str = prj_catalog_to_str(res->GetInt(j));

                    if(res->GetInt(j) == 6)
                        i_color = 3;
                    else if(res->GetInt(j)== 5)
                        i_color = 4;
                }
                else if(colNames.Item(j)== wxT("nonstd_level"))
                {
                    str = nstd_level_to_str(res->GetInt(j));
                }
                else str = res->GetVal(j);

                break;
            case PGOID_TYPE_DATE:
            case PGOID_TYPE_TIME:
            case PGOID_TYPE_TIMETZ:
            case PGOID_TYPE_TIMESTAMP:
            case PGOID_TYPE_TIMESTAMPTZ:
            case PGOID_TYPE_INTERVAL:

                str = DateToStrFormat(res->GetDate(j));
                break;
            default:
                str = res->GetVal(j);
                break;
            }
            line.Add(str);
            str.Empty();
        }

        rows_attr[i].attr->SetReadOnly();

        switch(i_color)
        {
        case 0:
            rows_attr[i].attr->SetBackgroundColour(*wxWHITE);
            break;
        case 1:
            rows_attr[i].attr->SetBackgroundColour(*wxRED);
            break;
        case 2:
            rows_attr[i].attr->SetBackgroundColour(*wxGREEN);
            break;
        case 3:
            rows_attr[i].attr->SetBackgroundColour(*wxYELLOW);
            break;
        case 4:
            rows_attr[i].attr->SetBackgroundColour(*wxCYAN);
            break;
        default:
            rows_attr[i].attr->SetBackgroundColour(*wxWHITE);
            break;

        }

        switch(i_font_color)
        {
        case 1:
            rows_attr[i].attr->SetTextColour(*wxBLUE);
            break;
        default:
            rows_attr[i].attr->SetTextColour(*wxBLACK);
            break;
        }

//        array_color.Add(i_color);
        m_data.Add(line);
        line.Clear();
        res->MoveNext();
    }

    res=0;
/*
    if(isEditable)
    {

    }*/
}

sqlResultTable::~sqlResultTable()
{
    //dtor
    if(rows_attr)
       delete [] rows_attr;
    rows_attr = 0;
}

void sqlResultTable::Clear()
{
    int row, col;
    int numRows, numCols;

    numRows = m_data.GetCount();
    if ( numRows > 0 )
    {
        numCols = m_data[0].GetCount();

        for ( row = 0; row < numRows; row++ )
        {
           m_data[row].Clear();
        }

        m_data.Clear();
    }

    if(rows_attr)
       delete [] rows_attr;

    rows_attr = 0;
}


wxGridCellAttr *sqlResultTable::GetAttr(int row, int col, wxGridCellAttr::wxAttrKind  kind)
{/*
    if(!m_data.IsEmpty()&& (row >= 0 && row < rows_num))
    {
        sqlResultCellAttr * now_attr = new sqlResultCellAttr();
        switch(array_color.Item(row))
        {
        case 0:
            now_attr->attr->SetBackgroundColour(*wxWHITE);
            break;
        case 1:
            now_attr->attr->SetBackgroundColour(*wxRED);
            break;
        case 2:
            now_attr->attr->SetBackgroundColour(*wxGREEN);
            break;
        case 3:
            now_attr->attr->SetBackgroundColour(*wxYELLOW);
            break;
        case 4:
            now_attr->attr->SetBackgroundColour(*wxCYAN);
            break;
        default:
            now_attr->attr->SetBackgroundColour(*wxWHITE);
            break;
        }
        now_attr->attr->IncRef();
        return now_attr->attr;
    }*/

    if(!m_data.IsEmpty())
    {
        rows_attr[row].attr->IncRef();

        return rows_attr[row].attr;
    }

    return NULL;
}


wxString sqlResultTable::GetValue(int row, int col)
{
    wxCHECK_MSG( (row >= 0 && row < rows_num) &&
                 (col >= 0 && col < cols_num),
                 wxEmptyString,
                 wxT("invalid row or column index in sqlResultTable") );
    return m_data[row][col];
}

void sqlResultTable::SetValue(int row, int col, const wxString &value)
{
    wxCHECK_RET( (row >= 0 && row < rows_num) && (col >= 0 && col < cols_num),
                 wxT("invalid row or column index in sqlResultTable") );
    m_data[row][col] = value;

}


wxString sqlResultTable::GetColLabelValue (int col)
{
    wxCHECK_MSG( (col >= 0 && col < cols_num),
                 wxEmptyString,
                 wxT("column index in sqlResultTable") );
    return col_Labels.Item(col);
}

bool sqlResultTable::AppendRows (size_t numRows)
{
    size_t curNumRows = m_data.GetCount();
    size_t curNumCols = ( curNumRows > 0
                         ? m_data[0].GetCount()
                         : ( GetView() ? GetView()->GetNumberCols() : 0 ) );

    wxArrayString sa;
    if ( curNumCols > 0 )
    {
        sa.Alloc( curNumCols );
        sa.Add( wxEmptyString, curNumCols );
    }

    m_data.Add( sa, numRows );

    if ( GetView() )
    {
        wxGridTableMessage msg( this,
                                wxGRIDTABLE_NOTIFY_ROWS_APPENDED,
                                numRows );

        GetView()->ProcessTableMessage( msg );
    }

    return true;

}

bool sqlResultTable::DeleteRows( size_t pos, size_t numRows)
{
        size_t curNumRows = m_data.GetCount();

    if ( pos >= curNumRows )
    {
        wxFAIL_MSG( wxString::Format
                    (
                        wxT("Called wxGridStringTable::DeleteRows(pos=%lu, N=%lu)\nPos value is invalid for present table with %lu rows"),
                        (unsigned long)pos,
                        (unsigned long)numRows,
                        (unsigned long)curNumRows
                    ) );

        return false;
    }

    if ( numRows > curNumRows - pos )
    {
        numRows = curNumRows - pos;
    }

    if ( numRows >= curNumRows )
    {
        m_data.Clear();
//        array_color.Clear();
    }
    else
    {
        m_data.RemoveAt( pos, numRows );
 //       array_color.RemoveAt(pos,numRows);
    }

    if ( GetView() )
    {
        wxGridTableMessage msg( this,
                                wxGRIDTABLE_NOTIFY_ROWS_DELETED,
                                pos,
                                numRows );

        GetView()->ProcessTableMessage( msg );
    }

    return true;

}

/*
bool sqlResultTable::InsertRows( size_t pos, size_t numRows )
{
    size_t curNumRows = m_data.GetCount();
    size_t curNumCols = ( curNumRows > 0 ? m_data[0].GetCount() :
                          ( GetView() ? GetView()->GetNumberCols() : 0 ) );

    if ( pos >= curNumRows )
    {
        return AppendRows( numRows );
    }

    wxArrayString sa;
    sa.Alloc( curNumCols );
    sa.Add( wxEmptyString, curNumCols );
    m_data.Insert( sa, pos, numRows );

    if ( GetView() )
    {
        wxGridTableMessage msg( this,
                                wxGRIDTABLE_NOTIFY_ROWS_INSERTED,
                                pos,
                                numRows );

        GetView()->ProcessTableMessage( msg );
    }

    return true;
}
*/
void sqlResultTable::SetColLabelValue(int col, const wxString &label)
{
    return;
}

void sqlResultTable::SetRowLabelValue(int row, const wxString &label)
{
    return;
}

wxString sqlResultTable::GetRowLabelValue(int row)
{
    wxCHECK_MSG( (row >= 0 && row < rows_num),
                 wxEmptyString,
                 wxT("invalid row index in sqlResultTable") );
    return NumToStr(row+1);
}

void sqlResultTable::SetLabelValue(wxString label)
{
    col_Labels= wxStringTokenize(label, wxT(";"), wxTOKEN_DEFAULT );
}
