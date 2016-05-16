//////////////////////////////////////////////////////////////////////////
//
//modified from pgadmin 1.18.1
//
//////////////////////////////////////////////////////////////////////////

#ifndef CTLSQLGRID_H
#define CTLSQLGRID_H

// wxWindows headers
#include <wx/grid.h>
#include <wx/settings.h>


class cacheLine
{
public:
	cacheLine()
	{
		cols = 0;
		stored = false;
		readOnly = false;
	}
	~cacheLine()
	{
		if (cols) delete[] cols;
	}

	wxString *cols;
	bool stored, readOnly;
};


class cacheLinePool
{
public:
	cacheLinePool(int initialLines);
	~cacheLinePool();
	cacheLine *operator[] (int line)
	{
		return Get(line);
	}
	cacheLine *Get(int lineNo);
	bool IsFilled(int lineNo);
	void Delete(int lineNo);

private:
	cacheLine **ptr;
	int anzLines;
};


class sqlCell
{
public:
	sqlCell()
	{
		ClearCell();
	}

	void SetCell(long r, long c)
	{
		row = r;
		col = c;
	}
	void ClearCell()
	{
		row = -1;
		col = -1;
	}
	bool IsSet()
	{
		return row != -1 && col != -1;
	}

	long GetRow()
	{
		return row;
	}
	long GetCol()
	{
		return col;
	}

private:
	long row;
	long col;
};

// we cannot derive from wxGridCellAttr because destructor is private but not virtual
class sqlEditCellAttr
{
public:
	sqlEditCellAttr()
	{
		attr = new wxGridCellAttr;
		isPrimaryKey = false;
		needResize = false;
	}
	~sqlEditCellAttr()
	{
		attr->DecRef();
	}
	int size();
	int precision();

	wxGridCellAttr *attr;
	wxString Quote(const wxString &value);
	wxOid type;
	long typlen, typmod;
	wxString name, label_name;
	bool numeric, isPrimaryKey, needResize;
};


class ctlSQLGrid : public wxGrid
{
public:
	ctlSQLGrid(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size);
	ctlSQLGrid();

	wxString GetExportLine(int row);
	wxString GetExportLine(int row, wxArrayInt cols);
	wxString GetExportLine(int row, int col1, int col2);
	virtual bool IsColText(int col)
	{
		return false;
	}
	int Copy();

	virtual bool CheckRowPresent(int row)
	{
		return true;
	}
	wxSize GetBestSize(int row, int col);
	void OnLabelDoubleClick(wxGridEvent &event);
	void is_with_column_name(bool i_with);

	void OnSqlKeyDown(wxKeyEvent &event);

	DECLARE_DYNAMIC_CLASS(ctlSQLGrid)
	DECLARE_EVENT_TABLE()

private:
	void OnCopy(wxCommandEvent &event);
	void OnMouseWheel(wxMouseEvent &event);
	wxString GetColumnName(int colNum);
	void AppendColumnHeader(wxString &str, int start, int end);
	void AppendColumnHeader(wxString &str, wxArrayInt columns);
	wxSystemSettings *settings;
	bool with_columnname;

};

#endif
