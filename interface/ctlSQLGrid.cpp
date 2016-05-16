//////////////////////////////////////////////////////////////////////////
//
//modified from pgadmin 1.18.1
//////////////////////////////////////////////////////////////////////////
// wxWindows headers
#include <wx/wx.h>
#include <wx/clipbrd.h>

#include "interface/wxPostgreSQL.h"
#include "ctlSQLGrid.h"
#include "wf_stdafx.h"


#define EXTRAEXTENT_HEIGHT 6
#define EXTRAEXTENT_WIDTH  6

BEGIN_EVENT_TABLE(ctlSQLGrid, wxGrid)
	EVT_MOUSEWHEEL(ctlSQLGrid::OnMouseWheel)
	EVT_KEY_DOWN(ctlSQLGrid::OnSqlKeyDown)
END_EVENT_TABLE()

IMPLEMENT_DYNAMIC_CLASS(ctlSQLGrid, wxGrid)

ctlSQLGrid::ctlSQLGrid()
{
    with_columnname= false;
}

ctlSQLGrid::ctlSQLGrid(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size)
	: wxGrid(parent, id, pos, size, wxWANTS_CHARS | wxVSCROLL | wxHSCROLL)
{
    with_columnname=false;
	// Set cells font
	wxFont fntCells(settings->GetFont(wxSYS_DEFAULT_GUI_FONT));
	SetDefaultCellFont(fntCells);
	// Set labels font
	wxFont fntLabel(settings->GetFont(wxSYS_SYSTEM_FONT));
	fntLabel.SetWeight(wxBOLD);
	SetLabelFont(fntLabel);
	SetColLabelAlignment(wxALIGN_LEFT, wxALIGN_CENTER);
	SetRowLabelSize(50);
	SetDefaultRowSize(fntCells.GetPointSize() * 2);
	SetColLabelSize(fntLabel.GetPointSize() * 4);
	SetDefaultCellOverflow(false);

	Connect(wxID_ANY, wxEVT_GRID_LABEL_LEFT_DCLICK, wxGridEventHandler(ctlSQLGrid::OnLabelDoubleClick));
}


void ctlSQLGrid::is_with_column_name(bool i_with)
{
    with_columnname=true;
}

void ctlSQLGrid::OnCopy(wxCommandEvent &ev)
{
	Copy();
}

void ctlSQLGrid::OnMouseWheel(wxMouseEvent &event)
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

wxString ctlSQLGrid::GetExportLine(int row)
{
	return GetExportLine(row, 0, GetNumberCols() - 1);
}


wxString ctlSQLGrid::GetExportLine(int row, int col1, int col2)
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

wxString ctlSQLGrid::GetExportLine(int row, wxArrayInt cols)
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
//		if (settings->GetCopyQuoting() == 1)
//		{
//			needQuote = IsColText(cols[col]);
//		}
//		else if (settings->GetCopyQuoting() == 2)
			/* Quote everything */
//			needQuote = true;

//		if (needQuote)
//			str.Append(settings->GetCopyQuoteChar());
		str.Append(text);
//		if (needQuote)
//			str.Append(settings->GetCopyQuoteChar());
	}
	return str;
}

wxString ctlSQLGrid::GetColumnName(int colNum)
{
	wxString columnName = GetColLabelValue(colNum);
	columnName = columnName.Left(columnName.find(wxT("\n")));
	return columnName;
}

void ctlSQLGrid::AppendColumnHeader(wxString &str, int start, int end)
{
	size_t i, arrsize;
	arrsize = (end - start + 1);
	wxArrayInt columns;

	for(i = 0; i < arrsize; i++)
	{
		columns.Add(start + i);
	}

	AppendColumnHeader(str, columns);
}

void ctlSQLGrid::AppendColumnHeader(wxString &str, wxArrayInt columns)
{
	if(with_columnname)
	{
  //      bool CopyQuoting = (settings->GetCopyQuoting() == 1 || settings->GetCopyQuoting() == 2);

		size_t i;

		for(i = 0; i < columns.Count() ; i++)
		{
			long columnPos = columns.Item(i);
//			if(i > 0)
//				str.Append(settings->GetCopyColSeparator());

//			if(CopyQuoting)
//				str.Append(settings->GetCopyQuoteChar());
			str.Append(GetColumnName(columnPos));
//			if(CopyQuoting)
//				str.Append(settings->GetCopyQuoteChar());

		}
		str.Append(END_OF_LINE);
	}
}

int ctlSQLGrid::Copy()
{
	wxString str;
	int copied = 0;
	size_t i;



	if (GetSelectedRows().GetCount())
	{
		AppendColumnHeader(str, 0, (GetNumberCols() - 1));

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

		AppendColumnHeader(str, cols);

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

		AppendColumnHeader(str, x1, x2);

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

		AppendColumnHeader(str, col, col);

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

void ctlSQLGrid::OnLabelDoubleClick(wxGridEvent &event)
{
	int maxHeight, maxWidth;
	GetClientSize(&maxWidth, &maxHeight);
	int row = event.GetRow();
	int col = event.GetCol();

	int extent, extentWant = 0;

	if (row >= 0)
	{
		for (col = 0 ; col < GetNumberCols() ; col++)
		{
			extent = GetBestSize(row, col).GetHeight();
			if (extent > extentWant)
				extentWant = extent;
		}

		extentWant += EXTRAEXTENT_HEIGHT;
		extentWant = wxMax(extentWant, GetRowMinimalAcceptableHeight());
		extentWant = wxMin(extentWant, maxHeight * 3 / 4);
		int currentHeight = GetRowHeight(row);

		if (currentHeight >= maxHeight * 3 / 4 || currentHeight == extentWant)
			extentWant = GetRowMinimalAcceptableHeight();
		else if (currentHeight < maxHeight / 4)
			extentWant = wxMin(maxHeight / 4, extentWant);
		else if (currentHeight < maxHeight / 2)
			extentWant = wxMin(maxHeight / 2, extentWant);
		else if (currentHeight < maxHeight * 3 / 4)
			extentWant = wxMin(maxHeight * 3 / 4, extentWant);

		if (extentWant != currentHeight)
		{
	//		BeginBatch();
	       wxGridUpdateLocker locker(this);
			if(IsCellEditControlShown())
			{
				HideCellEditControl();
				SaveEditControlValue();
			}

			SetRowSize(row, extentWant);
//			EndBatch();
		}
	}
	else if (col >= 0)
	{
		for (row = 0 ; row < GetNumberRows() ; row++)
		{
			if (CheckRowPresent(row))
			{
				extent = GetBestSize(row, col).GetWidth();
				if (extent > extentWant)
					extentWant = extent;
			}
		}

		extentWant += EXTRAEXTENT_WIDTH;
		extentWant = wxMax(extentWant, GetColMinimalAcceptableWidth());
		extentWant = wxMin(extentWant, maxWidth * 3 / 4);
		int currentWidth = GetColSize(col);

		if (currentWidth >= maxWidth * 3 / 4 || currentWidth == extentWant)
			extentWant = GetColMinimalAcceptableWidth();
		else if (currentWidth < maxWidth / 4)
			extentWant = wxMin(maxWidth / 4, extentWant);
		else if (currentWidth < maxWidth / 2)
			extentWant = wxMin(maxWidth / 2, extentWant);
		else if (currentWidth < maxWidth * 3 / 4)
			extentWant = wxMin(maxWidth * 3 / 4, extentWant);

		if (extentWant != currentWidth)
		{
//			BeginBatch();
            wxGridUpdateLocker locker(this);
			if(IsCellEditControlShown())
			{
				HideCellEditControl();
				SaveEditControlValue();
			}
			SetColSize(col, extentWant);
//			EndBatch();
		}
	}
}
void ctlSQLGrid::OnSqlKeyDown(wxKeyEvent &event)
{
    long key_code = event.GetKeyCode();
    switch(key_code)
    {
    case 'C':
        if(event.ControlDown())
              Copy();
        break;
    default:
        break;
    }

    event.Skip();
}


wxSize ctlSQLGrid::GetBestSize(int row, int col)
{
	wxSize size;

	wxGridCellAttr *attr = GetCellAttr(row, col);
	wxGridCellRenderer *renderer = attr->GetRenderer(this, row, col);
	if ( renderer )
	{
		wxClientDC dc(GetGridWindow());
		size = renderer->GetBestSize(*this, *attr, dc, row, col);
		renderer->DecRef();
	}

	attr->DecRef();

	return size;
}


wxString sqlEditCellAttr::Quote(const wxString &value)
{
    wxString str;
    int i_len = value.Length();
    if (value.IsEmpty())
        str = wxT("NULL");
    else if (value == wxT("\\'\\'"))
        str = wxT("NULL");
    else if (value == wxT("''"))
        str = wxT("NULL");
    else if (type == PGOID_TYPE_BOOL)
        str = value;
    else if (type == PGOID_TYPE_BIT)
        // Don't cast this one
        return wxT("B'") + value + wxT("'");
    else
    {
        str = value;
        if(!str.IsEmpty()&&str!=wxT("''"))
        {
            str.Replace(wxT("'"),wxT("''"));
        }

        str = wxT("'")+str +wxT("'");
    }

    return str;
}


int sqlEditCellAttr::size()
{
    if (typlen == -1 && typmod > 0)
    {
        return (typmod - 4) >> 16;
    }
    else
        return typlen;
}


int sqlEditCellAttr::precision()
{
    if (typlen == -1 && typmod > 0)
    {
        return (typmod - 4) & 0x7fff;
    }
    else
        return -1;
}


cacheLinePool::cacheLinePool(int initialLines)
{
    ptr = new cacheLine*[initialLines];
    if (ptr)
    {
        anzLines = initialLines;
        memset(ptr, 0, sizeof(cacheLine *)*anzLines);
    }
    else
    {
        anzLines = 0;
        wxLogError(_("Out of Memory for cacheLinePool"));
    }
}



cacheLinePool::~cacheLinePool()
{
    if (ptr)
    {
        while (anzLines--)
        {
            if (ptr[anzLines])
                delete ptr[anzLines];
        }
        delete[] ptr;
    }
}



void cacheLinePool::Delete(int lineNo)
{
    if (ptr && lineNo >= 0 && lineNo < anzLines)
    {
#if 1
        if (ptr[lineNo])
            delete ptr[lineNo];

        if (lineNo < anzLines - 1)
        {
            // beware: overlapping copy
            memmove(ptr + lineNo, ptr + lineNo + 1, sizeof(cacheLine *) * (anzLines - lineNo - 1));
        }
#else
        cacheLine *c;
        c = ptr[0];
        ptr[0] = ptr[1];
        ptr[1] = c;
#endif
        ptr[anzLines - 1] = 0;
    }
}


cacheLine *cacheLinePool::Get(int lineNo)
{
    if (lineNo < 0) return 0;

    if (lineNo >= anzLines)
    {
        cacheLine **old = ptr;
        int oldAnz = anzLines;
        anzLines = lineNo + 100;
        ptr = new cacheLine*[anzLines];
        if (!ptr)
        {
            anzLines = 0;
            wxLogError(_("Out of Memory for cacheLinePool"));
        }
        else
        {
            if (oldAnz)
            {
                memcpy(ptr, old, sizeof(cacheLine *)*oldAnz);
                delete[] old;
            }
            memset(ptr + oldAnz, 0, anzLines - oldAnz);
        }
    }

    if (lineNo < anzLines)
    {
        if (!ptr[lineNo])
            ptr[lineNo] = new cacheLine();
        return ptr[lineNo];
    }
    return 0;
}


bool cacheLinePool::IsFilled(int lineNo)
{
    return (lineNo < anzLines && ptr[lineNo]);
}
