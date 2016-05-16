//////////////////////////////////////////////////////////////////////////
//
// this class is inherited from wxGridTableBase.h
// and it is revised according to pgAdmin 1.18.1 's source.
//////////////////////////////////////////////////////////////////////////

#ifndef __SQLTABLE_H
#define __SQLTABLE_H

#include <wx/grid.h>
#include <wx/stc/stc.h>
#include "interface/wxPostgreSQL.h"
#include "ctlSQLGrid.h"
#include "wf_stdafx.h"

class nstdappTable;

class nstdappGrid : public ctlSQLGrid
{
public:
	nstdappGrid(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size);

	nstdappTable *GetTable()
	{
		return (nstdappTable *)wxGrid::GetTable();
	}
	//wxSize GetBestSize(int row, int col);
	void ResizeEditor(int row, int col);
	wxArrayInt GetSelectedRows() const;
	bool CheckRowPresent(int row);
	virtual bool IsColText(int col);
};

class nstdappTable : public wxGridTableBase
{
public:
	nstdappTable(wxPostgreSQLresult * _res, wxString &tablename, wxString &header, wxString _colStoreStatus, const wxString &_pkCols);
	~nstdappTable();
	bool StoreLine();
	void UndoLine(int row);

	int GetNumberRows();
	int GetNumberStoredRows();
	int GetNumberCols();
	wxString GetColLabelValue(int col);
	wxString GetRowLabelValue(int row);
	wxGridCellAttr *GetAttr(int row, int col, wxGridCellAttr::wxAttrKind kind);

	wxString GetValue(int row, int col);
	void SetValue(int row, int col, const wxString &value);

	bool IsEmptyCell(int row, int col)
	{
		return false;
	}
	bool needsResizing(int col)
	{
		return columns[col].needResize;
	}
	bool AppendRows(size_t rows);
	bool DeleteRows(size_t pos, size_t rows);
	int  LastRow()
	{
		return lastRow;
	}

	void SetLastRow(int i)
	{
	    lastRow = i;
	}
	bool IsColText(int col);
	bool IsColBoolean(int col);

	bool CheckInCache(int row);
	bool IsLineSaved(int row)
	{
		return GetLine(row)->stored;
	}

	bool Paste();

    void SetWhereClause(wxString s_WhereClause)
    {
        str_whereclause = s_WhereClause;
    }

    wxString GetWhereClause()
    {
        return str_whereclause;
    }

    void SetColEditor(int col, wxGridCellEditor *editor);

    cacheLine *GetLine(int row);

    void Set_Saved_Line(int row);

    sqlEditCellAttr * get_col_attr()
    {
        return columns;
    }

private:
	wxPostgreSQLresult *res;
	wxString tabName;
	wxString pkCols;
	wxString str_whereclause;
    wxArrayInt colStoreStatus;

	wxString MakeKey(cacheLine *line);
	cacheLinePool *dataPool, *addPool;
	cacheLine savedLine;
	int lastRow;

	int *lineIndex;     // reindex of lines in dataSet to handle deleted rows

	int nCols;          // columns from dataSet
	int nRows;          // rows initially returned by dataSet
	int rowsCached;     // rows read from dataset; if nRows=rowsCached, dataSet can be deleted
	int rowsAdded;      // rows added (never been in dataSet)
	int rowsStored;     // rows added and stored to db
	int rowsDeleted;    // rows deleted from initial dataSet
	sqlEditCellAttr *columns;

	friend class nstdappGrid;
};

#endif


