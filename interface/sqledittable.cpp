//////////////////////////////////////////////////////////////////////////
//
// this class is inherited from wxGridTableBase.h
// and it is revised according to pgAdmin 1.18.1 's source.
//////////////////////////////////////////////////////////////////////////

// wxWindows headers
#include <wx/wx.h>
#include <wx/grid.h>
#include "sqledittable.h"

// App headers

#include <wx/generic/gridctrl.h>
#include <wx/clipbrd.h>
#include <wx/tokenzr.h>
#include <wx/datectrl.h>
#include "wfApp.h"

ctlSQLEditGrid::ctlSQLEditGrid(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size)
    : ctlSQLGrid(parent, id, pos, size)
{
}

bool ctlSQLEditGrid::CheckRowPresent(int row)
{
    return GetTable()->CheckInCache(row);
}

void ctlSQLEditGrid::ResizeEditor(int row, int col)
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

wxArrayInt ctlSQLEditGrid::GetSelectedRows() const
{
    wxArrayInt rows, rows2;

    wxGridCellCoordsArray tl = GetSelectionBlockTopLeft(), br = GetSelectionBlockBottomRight();

    int maxCol = ((ctlSQLEditGrid *)this)->GetNumberCols() - 1;
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


class sqlGridTextEditor : public wxGridCellTextEditor
{
public:
    virtual wxGridCellEditor *Clone() const
    {
        return new sqlGridTextEditor();
    }
    void Create(wxWindow *parent, wxWindowID id, wxEvtHandler *evtHandler);
    void BeginEdit(int row, int col, wxGrid *grid);


#if wxCHECK_VERSION(2, 9, 0)
    void ApplyEdit(int row, int col, wxGrid *grid);
    bool EndEdit(int row, int col, const wxGrid *grid, const wxString &, wxString *);
#else
    bool EndEdit(int row, int col, wxGrid *grid);
#endif
    wxString GetValue() const;
    virtual void Reset()
    {
        DoReset(m_startValue);
    }
    void StartingKey(wxKeyEvent &event);

protected:
    void DoBeginEdit(const wxString &startValue);
    wxStyledTextCtrl *Text() const
    {
        return (wxStyledTextCtrl *)m_control;
    }
    void DoReset(const wxString &startValue);

    wxString m_startValue;
};




void sqlGridTextEditor::Create(wxWindow *parent, wxWindowID id, wxEvtHandler *evtHandler)
{
    int flags = wxSTC_WRAP_NONE;

    m_control = new wxStyledTextCtrl(parent, id,
                                     wxDefaultPosition, wxDefaultSize, flags
                                    );

    wxGridCellEditor::Create(parent, id, evtHandler);
}


void sqlGridTextEditor::BeginEdit(int row, int col, wxGrid *grid)
{
    m_startValue = grid->GetTable()->GetValue(row, col);
    DoBeginEdit(m_startValue);
    ((ctlSQLEditGrid *)grid)->ResizeEditor(row, col);
}

void sqlGridTextEditor::DoBeginEdit(const wxString &startValue)
{
    Text()->SetMarginWidth(1, 0);
    Text()->SetText(startValue);
    Text()->SetCurrentPos(Text()->GetTextLength());
    Text()->SetUseHorizontalScrollBar(false);
    Text()->SetUseVerticalScrollBar(false);
    Text()->SetSelection(0, -1);
    Text()->SetFocus();
}

#if wxCHECK_VERSION(2, 9, 0)
void sqlGridTextEditor::ApplyEdit(int row, int col, wxGrid *grid)
{
    wxString value = Text()->GetText();
    grid->GetTable()->SetValue(row, col, value);
}
#endif

#if wxCHECK_VERSION(2, 9, 0)
bool sqlGridTextEditor::EndEdit(int row, int col, const wxGrid *grid, const wxString &, wxString *)
#else
bool sqlGridTextEditor::EndEdit(int row, int col, wxGrid *grid)
#endif
{
    bool changed = false;
    wxString value = Text()->GetText();

    if (value != m_startValue)
        changed = true;

#if !wxCHECK_VERSION(2, 9, 0)
    if (changed)
        grid->GetTable()->SetValue(row, col, value);
#endif

    return changed;
}

wxString sqlGridTextEditor::GetValue() const
{
    return Text()->GetText();
}

void sqlGridTextEditor::DoReset(const wxString &startValue)
{
    Text()->SetText(startValue);
    Text()->SetSelection(-1, -1);
}

void sqlGridTextEditor::StartingKey(wxKeyEvent &event)
{
    wxChar ch;

#if wxUSE_UNICODE
    ch = event.GetUnicodeKey();
    if (ch <= 127)
        ch = (wxChar)event.GetKeyCode();
#else
    ch = (wxChar)event.GetKeyCode();
#endif

    if (ch != (wxChar)WXK_BACK)
    {
        Text()->SetText(ch);
        Text()->GotoPos(Text()->GetLength());
    }
}

class sqlGridNumericEditor : public wxGridCellTextEditor
{
public:
    sqlGridNumericEditor(int len = -1, int prec = -1)
    {
        numlen = len;
        numprec = prec;
    }
    virtual wxGridCellEditor *Clone() const
    {
        return new sqlGridNumericEditor(numlen, numprec);
    }
    virtual void Create(wxWindow *parent, wxWindowID id, wxEvtHandler *evtHandler);

    virtual bool IsAcceptedKey(wxKeyEvent &event);
    virtual void BeginEdit(int row, int col, wxGrid *grid);
#if wxCHECK_VERSION(2, 9, 0)
    void ApplyEdit(int row, int col, wxGrid *grid);
    bool EndEdit(int row, int col, const wxGrid *grid, const wxString &, wxString *);
#else
    bool EndEdit(int row, int col, wxGrid *grid);
#endif

    virtual void Reset()
    {
        DoReset(m_startValue);
    }
    virtual void StartingKey(wxKeyEvent &event);
    virtual void SetParameters(const wxString &params);

protected:
    int numlen, numprec;
    wxString m_startValue;

};



void sqlGridNumericEditor::StartingKey(wxKeyEvent &event)
{
    int keycode = event.GetKeyCode();
    bool allowed = false;

    switch (keycode)
    {
    case WXK_DECIMAL:
    case WXK_NUMPAD_DECIMAL:
    case '.':
        if (numprec)
            allowed = true;
        break;
    case '+':
    case WXK_ADD:
    case WXK_NUMPAD_ADD:
    case '-':
    case WXK_SUBTRACT:
    case WXK_NUMPAD_SUBTRACT:

    case WXK_NUMPAD0:
    case WXK_NUMPAD1:
    case WXK_NUMPAD2:
    case WXK_NUMPAD3:
    case WXK_NUMPAD4:
    case WXK_NUMPAD5:
    case WXK_NUMPAD6:
    case WXK_NUMPAD7:
    case WXK_NUMPAD8:
    case WXK_NUMPAD9:
        allowed = true;
        break;
    default:
        if (wxIsdigit(keycode))
            allowed = true;
        break;

    }
    if (allowed)
        wxGridCellTextEditor::StartingKey(event);
    else
        event.Skip();
}



bool sqlGridNumericEditor::IsAcceptedKey(wxKeyEvent &event)
{
    if ( wxGridCellEditor::IsAcceptedKey(event) )
    {
        int keycode = event.GetKeyCode();
        switch ( keycode )
        {
        case WXK_DECIMAL:
        case WXK_NUMPAD_DECIMAL:
            return (numprec != 0);

        case '+':
        case WXK_ADD:
        case WXK_NUMPAD_ADD:
        case '-':
        case WXK_SUBTRACT:
        case WXK_NUMPAD_SUBTRACT:

        case WXK_NUMPAD0:
        case WXK_NUMPAD1:
        case WXK_NUMPAD2:
        case WXK_NUMPAD3:
        case WXK_NUMPAD4:
        case WXK_NUMPAD5:
        case WXK_NUMPAD6:
        case WXK_NUMPAD7:
        case WXK_NUMPAD8:
        case WXK_NUMPAD9:
            return true;
        default:
            return wxIsdigit(keycode) != 0;
        }
    }

    return false;
}



void sqlGridNumericEditor::BeginEdit(int row, int col, wxGrid *grid)
{
    m_startValue = grid->GetTable()->GetValue(row, col);


    wxString value = m_startValue;
    // localize value here

    DoBeginEdit(value);
}

#if wxCHECK_VERSION(2, 9, 0)
void sqlGridNumericEditor::ApplyEdit(int row, int col, wxGrid *grid)
{
    wxString value = Text()->GetValue();
    grid->GetTable()->SetValue(row, col, value);
    m_startValue = wxEmptyString;
    Text()->SetValue(m_startValue);
}
#endif

#if wxCHECK_VERSION(2, 9, 0)
bool sqlGridNumericEditor::EndEdit(int row, int col, const wxGrid *grid, const wxString &, wxString *)
#else
bool sqlGridNumericEditor::EndEdit(int row, int col, wxGrid *grid)
#endif
{
    wxASSERT_MSG(m_control,
                 wxT("The sqlGridNumericEditor must be Created first!"));

    bool changed = false;
    wxString value = Text()->GetValue();

    // de-localize value here

    if (value != m_startValue)
        changed = true;

#if !wxCHECK_VERSION(2, 9, 0)
    if (changed)
        grid->GetTable()->SetValue(row, col, value);

    m_startValue = wxEmptyString;
    Text()->SetValue(m_startValue);
#endif
    return changed;
}


void sqlGridNumericEditor::SetParameters(const wxString &params)
{
    if ( !params )
    {
        // reset to default
        numlen = -1;
        numprec = -1;
    }
    else
    {
        long tmp;
        if ( params.BeforeFirst(wxT(',')).ToLong(&tmp) )
        {
            numlen = (int)tmp;

            if ( params.AfterFirst(wxT(',')).ToLong(&tmp) )
            {
                numprec = (int)tmp;

                // skip the error message below
                return;
            }
        }
    }
}


void sqlGridNumericEditor::Create(wxWindow *parent, wxWindowID id, wxEvtHandler *evtHandler)
{
    m_control = new wxTextCtrl(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize);

    wxGridCellEditor::Create(parent, id, evtHandler);
    Text()->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
}


//////////////////////////////////////////////////////////////////////
// Bool editor
//////////////////////////////////////////////////////////////////////


class sqlGridBoolEditor : public wxGridCellEditor
{
public:
    sqlGridBoolEditor() { }

    virtual void Create(wxWindow *parent, wxWindowID id, wxEvtHandler *evtHandler);

    virtual void SetSize(const wxRect &rect);
    virtual void Show(bool show, wxGridCellAttr *attr = (wxGridCellAttr *)NULL);

    virtual bool IsAcceptedKey(wxKeyEvent &event);
    virtual void BeginEdit(int row, int col, wxGrid *grid);

#if wxCHECK_VERSION(2, 9, 0)
    virtual void ApplyEdit(int row, int col, wxGrid *grid); // pure virtual in wx 2.9+, doesn't exist in prior versions
    virtual bool EndEdit(int row, int col, const wxGrid *grid, const wxString& oldval, wxString *newval);
#else
    virtual bool EndEdit(int row, int col, wxGrid *grid);
#endif

    virtual void Reset();
    virtual void StartingClick();
    virtual void StartingKey(wxKeyEvent &event);

    virtual wxGridCellEditor *Clone() const
    {
        return new sqlGridBoolEditor;
    }

    virtual wxString GetValue() const;

    // set the string values returned by GetValue() for the true and false
    // states, respectively
    static void UseStringValues(const wxString& valueTrue = wxT("TRUE"),
                                const wxString& valueFalse = wxT("FALSE"));

    // return true if the given string is equal to the string representation of
    // true value which we currently use
    static bool IsTrueValue(const wxString& value);

protected:
    wxCheckBox *CBox() const
    {
        return (wxCheckBox *)m_control;
    }

private:
    bool m_value;

    static wxString ms_stringValues[2];

    DECLARE_NO_COPY_CLASS(sqlGridBoolEditor)
};

// the default values for GetValue()
wxString sqlGridBoolEditor::ms_stringValues[2] = { wxT("FALSE"), wxT("TRUE") };

void sqlGridBoolEditor::Create(wxWindow *parent, wxWindowID id, wxEvtHandler *evtHandler)
{
    m_control = new wxCheckBox(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);

    wxGridCellEditor::Create(parent, id, evtHandler);
}

void sqlGridBoolEditor::SetSize(const wxRect &r)
{
    bool resize = false;
    wxSize size = m_control->GetSize();
    wxCoord minSize = wxMin(r.width, r.height);

    // check if the checkbox is not too big/small for this cell
    wxSize sizeBest = m_control->GetBestSize();
    if ( !(size == sizeBest) )
    {
        // reset to default size if it had been made smaller
        size = sizeBest;

        resize = true;
    }

    if ( size.x >= minSize || size.y >= minSize )
    {
        // leave 1 pixel margin
        size.x = size.y = minSize - 2;

        resize = true;
    }

    if ( resize )
    {
        m_control->SetSize(size);
    }

    // position it in the centre of the rectangle (TODO: support alignment?)

#if defined(__WXGTK__)
    // the checkbox without label still has some space to the right in wxGTK,
    // so shift it to the right
    size.x -= 8;
#elif defined(__WXMSW__)
    // here too, but in other way
    size.x += 1;
    size.y -= 2;
#endif

    int hAlign = wxALIGN_CENTRE;
    int vAlign = wxALIGN_CENTRE;
    if (GetCellAttr())
        GetCellAttr()->GetAlignment(& hAlign, & vAlign);

    int x = 0, y = 0;
    if (hAlign == wxALIGN_LEFT)
    {
        x = r.x + 2;
#ifdef __WXMSW__
        x += 2;
#endif
        y = r.y + r.height / 2 - size.y / 2;
    }
    else if (hAlign == wxALIGN_RIGHT)
    {
        x = r.x + r.width - size.x - 2;
        y = r.y + r.height / 2 - size.y / 2;
    }
    else if (hAlign == wxALIGN_CENTRE)
    {
        x = r.x + r.width / 2 - size.x / 2;
        y = r.y + r.height / 2 - size.y / 2;
    }

    m_control->Move(x, y);
}

void sqlGridBoolEditor::Show(bool show, wxGridCellAttr *attr)
{
    m_control->Show(show);

    if ( show )
    {
        wxColour colBg = attr ? attr->GetBackgroundColour() : *wxLIGHT_GREY;
        CBox()->SetBackgroundColour(colBg);
    }
}

void sqlGridBoolEditor::BeginEdit(int row, int col, wxGrid *grid)
{
    wxASSERT_MSG(m_control,
                 wxT("The wxGridCellEditor must be created first!"));

    if (grid->GetTable()->CanGetValueAs(row, col, wxGRID_VALUE_BOOL))
    {
        m_value = grid->GetTable()->GetValueAsBool(row, col);
    }
    else
    {
        wxString cellval( grid->GetTable()->GetValue(row, col) );

        if ( cellval == ms_stringValues[false] )
            m_value = false;
        else if ( cellval == ms_stringValues[true] )
            m_value = true;
        else
        {
            // do not try to be smart here and convert it to true or false
            // because we'll still overwrite it with something different and
            // this risks to be very surprising for the user code, let them
            // know about it
            wxFAIL_MSG( wxT("invalid value for a cell with bool editor!") );
        }
    }

    CBox()->SetValue(m_value);
    CBox()->SetFocus();
}

#if wxCHECK_VERSION(2, 9, 0)
// pure virtual in 2.9+, doesn't exist in prior versions
void sqlGridBoolEditor::ApplyEdit(int row, int col, wxGrid *grid)
{
    wxGridTableBase * const table = grid->GetTable();
    if ( table->CanSetValueAs(row, col, wxGRID_VALUE_BOOL) )
        table->SetValueAsBool(row, col, m_value);
    else
        table->SetValue(row, col, GetValue());
}
#endif

#if wxCHECK_VERSION(2, 9, 0)
bool sqlGridBoolEditor::EndEdit(int row, int col, const wxGrid *grid, const wxString& oldval, wxString *newval)
#else
bool sqlGridBoolEditor::EndEdit(int row, int col, wxGrid *grid)
#endif
{
    bool value = CBox()->GetValue();
    if ( value == m_value )
        return false;

    m_value = value;

#if !wxCHECK_VERSION(2, 9, 0)
    if ( newval )
        *newval = GetValue();
#endif
    return true;
}

void sqlGridBoolEditor::Reset()
{
    wxASSERT_MSG(m_control,
                 wxT("The sqlGridBoolEditor must be created first!"));

    CBox()->SetValue(m_value);
}

void sqlGridBoolEditor::StartingClick()
{
    // We used to cycle the value on click here but
    // that can lead to odd behaviour of the cell.
    // Without cycling here, the checkbox is displayed
    // but the user must toggle the box itself - she
    // cannot just keep clicking the cell.
    CBox()->SetValue(!CBox()->GetValue());
}

bool sqlGridBoolEditor::IsAcceptedKey(wxKeyEvent &event)
{
    if ( wxGridCellEditor::IsAcceptedKey(event) )
    {
        int keycode = event.GetKeyCode();
        switch ( keycode )
        {
        case WXK_SPACE:
        case '+':
        case '-':
        case 'n':
        case 'N':
        case 'y':
        case 'Y':
            return true;
        }
    }

    return false;
}

void sqlGridBoolEditor::StartingKey(wxKeyEvent &event)
{
    int keycode = event.GetKeyCode();
    switch ( keycode )
    {
        case WXK_SPACE:
            CBox()->SetValue(!CBox()->GetValue());
            break;

        case '+':
        case 'y':
        case 'Y':
            CBox()->SetValue(true);
            break;

        case '-':
        case 'n':
        case 'N':
            CBox()->SetValue(false);
            break;
    }
}


// return the value as "1" for true and the empty string for false
wxString sqlGridBoolEditor::GetValue() const
{
    return ms_stringValues[CBox()->GetValue()];
}

/* static */ void
sqlGridBoolEditor::UseStringValues(const wxString& valueTrue,
                                      const wxString& valueFalse)
{
    ms_stringValues[false] = valueFalse;
    ms_stringValues[true] = valueTrue;
}

/* static */ bool
sqlGridBoolEditor::IsTrueValue(const wxString& value)
{
    return value == ms_stringValues[true];
}

//////////////////////////////////////////////////////////////////////
// End Bool editor
//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
// choice editor
//////////////////////////////////////////////////////////////////////

class sqlGridChoiceEditor : public wxGridCellEditor
{
public:
    // if !allowOthers, user can't type a string not in choices array
    sqlGridChoiceEditor(size_t count = 0,
                           const wxString choices[] = NULL,
                           bool allowOthers = false);
    sqlGridChoiceEditor(const wxArrayString& choices,
                           bool allowOthers = false);

    virtual void Create(wxWindow* parent,
                        wxWindowID id,
                        wxEvtHandler* evtHandler);

    virtual void SetSize(const wxRect& rect);

    virtual void PaintBackground(wxDC& dc,
                                 const wxRect& rectCell,
                                 const wxGridCellAttr& attr);

    virtual void BeginEdit(int row, int col, wxGrid* grid);

#if wxCHECK_VERSION(2, 9, 0)
    virtual void ApplyEdit(int row, int col, wxGrid *grid); // pure virtual in wx 2.9+, doesn't exist in prior versions
    virtual bool EndEdit(int row, int col, const wxGrid *grid, const wxString& oldval, wxString *newval);
#else
    virtual bool EndEdit(int row, int col, wxGrid *grid);
#endif

    virtual void Reset();

    // parameters string format is "item1[,item2[...,itemN]]"
    virtual void SetParameters(const wxString& params);

    virtual wxGridCellEditor *Clone() const;

    // added GetValue so we can get the value which is in the control
    virtual wxString GetValue() const;

protected:
    wxComboBox *Combo() const
    {
        return (wxComboBox *)m_control;
    }

private:
    wxString        m_value;
    wxArrayString   m_choices;
    bool            m_allowOthers;

    DECLARE_NO_COPY_CLASS(sqlGridChoiceEditor)
};



sqlGridChoiceEditor::sqlGridChoiceEditor(const wxArrayString& choices,
                                               bool allowOthers)
    : m_choices(choices),
      m_allowOthers(allowOthers) { }

sqlGridChoiceEditor::sqlGridChoiceEditor(size_t count,
                                               const wxString choices[],
                                               bool allowOthers)
                      : m_allowOthers(allowOthers)
{
    if ( count )
    {
        m_choices.Alloc(count);
        for ( size_t n = 0; n < count; n++ )
        {
            m_choices.Add(choices[n]);
        }
    }
}

wxGridCellEditor *sqlGridChoiceEditor::Clone() const
{
    sqlGridChoiceEditor *editor = new sqlGridChoiceEditor;
    editor->m_allowOthers = m_allowOthers;
    editor->m_choices = m_choices;

    return editor;
}

void sqlGridChoiceEditor::Create(wxWindow* parent,
                                    wxWindowID id,
                                    wxEvtHandler* evtHandler)
{
    int style = wxTE_PROCESS_ENTER |
                wxTE_PROCESS_TAB |
                wxBORDER_NONE;

    if ( !m_allowOthers )
        style |= wxCB_READONLY;
    m_control = new wxComboBox(parent, id, wxEmptyString,
                               wxDefaultPosition, wxDefaultSize,
                               m_choices,
                               style);

    wxGridCellEditor::Create(parent, id, evtHandler);
}

void sqlGridChoiceEditor::SetSize(const wxRect &rect)
{
   wxASSERT_MSG(m_control,
                 wxT("The wxGridCellChoiceEditor must be created first!"));

    // Check that the height is not too small to fit the combobox.
    wxRect rectTallEnough = rect;
    const wxSize bestSize = m_control->GetBestSize();
    const wxCoord diffY = bestSize.GetHeight() - rectTallEnough.GetHeight();
    if ( diffY > 0 )
    {
        // Do make it tall enough.
        rectTallEnough.height += diffY;

        // Also centre the effective rectangle vertically with respect to the
        // original one.
        rectTallEnough.y -= diffY/2;
    }
    //else: The rectangle provided is already tall enough.

    wxGridCellEditor::SetSize(rectTallEnough);
}


void sqlGridChoiceEditor::PaintBackground(wxDC& dc,
                                             const wxRect& rectCell,
                                             const wxGridCellAttr& attr)
{
    // as we fill the entire client area, don't do anything here to minimize
    // flicker

    // TODO: It doesn't actually fill the client area since the height of a
    // combo always defaults to the standard.  Until someone has time to
    // figure out the right rectangle to paint, just do it the normal way.
    wxGridCellEditor::PaintBackground(dc, rectCell, attr);
}

void sqlGridChoiceEditor::BeginEdit(int row, int col, wxGrid *grid)
{
    wxASSERT_MSG(m_control,
                 wxT("The wxGridCellEditor must be created first!"));

    wxGridCellEditorEvtHandler* evtHandler = NULL;
    if (m_control)
        evtHandler = wxDynamicCast(m_control->GetEventHandler(), wxGridCellEditorEvtHandler);

    // Don't immediately end if we get a kill focus event within BeginEdit
    if (evtHandler)
        evtHandler->SetInSetFocus(true);

    m_value = grid->GetTable()->GetValue(row, col);

    Reset(); // this updates combo box to correspond to m_value

    Combo()->SetFocus();

#ifdef __WXOSX_COCOA__
    // This is a work around for the combobox being simply dismissed when a
    // choice is made in it under OS X. The bug is almost certainly due to a
    // problem in focus events generation logic but it's not obvious to fix and
    // for now this at least allows to use wxGrid.
    Combo()->Popup();
#endif

    if (evtHandler)
    {
        // When dropping down the menu, a kill focus event
        // happens after this point, so we can't reset the flag yet.
#if !defined(__WXGTK20__)
        evtHandler->SetInSetFocus(false);
#endif
    }
}

#if wxCHECK_VERSION(2, 9, 0)
// pure virtual in 2.9+, doesn't exist in prior versions
void sqlGridChoiceEditor::ApplyEdit(int row, int col, wxGrid *grid)
{
   grid->GetTable()->SetValue(row, col, m_value);
}
#endif

#if wxCHECK_VERSION(2, 9, 0)
bool sqlGridChoiceEditor::EndEdit(int row, int col, const wxGrid *grid, const wxString& oldval, wxString *newval)
#else
bool sqlGridChoiceEditor::EndEdit(int row, int col, wxGrid *grid)
#endif
{
    const wxString value = Combo()->GetValue();
    if ( value == m_value )
        return false;

    m_value = value;
#if wxCHECK_VERSION(2, 9, 0)
    if ( newval )
        *newval = value;
#endif

    return true;
}

void sqlGridChoiceEditor::Reset()
{
   if (m_allowOthers)
    {
        Combo()->SetValue(m_value);
        Combo()->SetInsertionPointEnd();
    }
    else // the combobox is read-only
    {
        // find the right position, or default to the first if not found
        int pos = Combo()->FindString(m_value);
        if (pos == wxNOT_FOUND)
            pos = 0;
        Combo()->SetSelection(pos);
    }
}


void sqlGridChoiceEditor::SetParameters(const wxString& params)
{
    if ( !params )
    {
        // what can we do?
        return;
    }

    m_choices.Empty();

    wxStringTokenizer tk(params, wxT(','));
    while ( tk.HasMoreTokens() )
    {
        m_choices.Add(tk.GetNextToken());
    }
}

wxString sqlGridChoiceEditor::GetValue() const
{

     return Combo()->GetValue();
}

//////////////////////////////////////////////////////////////////////
// End choice editor
//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
// datetimepickereditor
//////////////////////////////////////////////////////////////////////

class sqlGridDateTimeEditor : public wxGridCellEditor
{
public:
    // if !allowOthers, user can't type a string not in choices array
//    sqlGridDateTimeEditor(const wxString fmt = "%Y-%m-%d %H:%M:%S");
    sqlGridDateTimeEditor(const wxString fmt = "%Y-%m-%d");
    virtual void Create(wxWindow* parent,
                        wxWindowID id,
                        wxEvtHandler* evtHandler);

    virtual void SetSize(const wxRect& rect);

    virtual void BeginEdit(int row, int col, wxGrid* grid);

#if wxCHECK_VERSION(2, 9, 0)
    virtual void ApplyEdit(int row, int col, wxGrid *grid); // pure virtual in wx 2.9+, doesn't exist in prior versions
    virtual bool EndEdit(int row, int col, const wxGrid *grid, const wxString& oldval, wxString *newval);
#else
    virtual bool EndEdit(int row, int col, wxGrid *grid);
#endif

    virtual void Reset();

    virtual wxGridCellEditor *Clone() const
    {
        return new sqlGridDateTimeEditor(this->m_fmt);
    }

    // added GetValue so we can get the value which is in the control
    virtual wxString GetValue() const;

protected:
    wxDatePickerCtrl *DatePickCtrl() const
    {
        return (wxDatePickerCtrl *)m_control;
    }

    // string representation of m_valueOld
    wxString GetString() const;

private:
    wxDateTime m_value;
    wxString m_fmt ;

    DECLARE_NO_COPY_CLASS(sqlGridDateTimeEditor)
};


sqlGridDateTimeEditor::sqlGridDateTimeEditor(const wxString fmt)
{
   m_fmt= fmt;
}

wxString sqlGridDateTimeEditor::GetString() const
{
   return m_value.Format(m_fmt)+wxT(" 23:00:00");
}

void sqlGridDateTimeEditor::Create(wxWindow* parent,
                                    wxWindowID id,
                                    wxEvtHandler* evtHandler)
{
	m_control = new wxDatePickerCtrl(parent, id, wxDefaultDateTime,
			wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY);

    wxGridCellEditor::Create(parent, id, evtHandler);
}

void sqlGridDateTimeEditor::SetSize(const wxRect &rect)
{
   wxASSERT_MSG(m_control,
                 wxT("The sqlGridDateTimeEditor must be created first!"));

    // Check that the height is not too small to fit the combobox.
    wxRect rectTallEnough = rect;
    const wxSize bestSize = m_control->GetBestSize();
    const wxCoord diffY = bestSize.GetHeight() - rectTallEnough.GetHeight();
    if ( diffY > 0 )
    {
        // Do make it tall enough.
        rectTallEnough.height += diffY;

        // Also centre the effective rectangle vertically with respect to the
        // original one.
        rectTallEnough.y -= diffY/2;
    }
    //else: The rectangle provided is already tall enough.

    wxGridCellEditor::SetSize(rectTallEnough);
}


void sqlGridDateTimeEditor::BeginEdit(int row, int col, wxGrid *grid)
{
	wxRect rc = grid->CellToRect(row,col);

	wxString value = grid->GetTable()->GetValue(row,col);


	wxDateTime dtValue = StrToDateTime(value);
	DatePickCtrl()->SetValue(dtValue);

	DatePickCtrl()->SetSize(rc.x, rc.y, rc.width, rc.height);
	DatePickCtrl()->Show();
	DatePickCtrl()->SetFocus();
}

#if wxCHECK_VERSION(2, 9, 0)
// pure virtual in 2.9+, doesn't exist in prior versions
void sqlGridDateTimeEditor::ApplyEdit(int row, int col, wxGrid *grid)
{
   grid->GetTable()->SetValue(row, col, GetString());
}
#endif

#if wxCHECK_VERSION(2, 9, 0)
bool sqlGridDateTimeEditor::EndEdit(int row, int col, const wxGrid *grid, const wxString& oldval, wxString *newval)
#else
bool sqlGridDateTimeEditor::EndEdit(int row, int col, wxGrid *grid)
#endif
{
    const wxString value = DateToStrFormat(DatePickCtrl()->GetValue());
    if ( value == GetValue())
        return false;

    m_value = StrToDateTime(value);
#if wxCHECK_VERSION(2, 9, 0)
    if ( newval )
        *newval = value;
#endif

    return true;
}

void sqlGridDateTimeEditor::Reset()
{
    wxASSERT_MSG(m_control,
                 wxT("sqlGridDateTimeEditor must be created first!"));
    DatePickCtrl()->SetValue(m_value);

}


wxString sqlGridDateTimeEditor::GetValue() const
{

     return DateToStrFormat(DatePickCtrl()->GetValue());
}

//////////////////////////////////////////////////////////////////////
// End datetimepicker editor
//////////////////////////////////////////////////////////////////////


sqlEditTable::sqlEditTable(wxPostgreSQLresult * _res, wxString &tablename, wxString &header, wxArrayInt &_colFormat, const wxString &_pkCols)
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

    columns = new sqlEditCellAttr[nCols];
    savedLine.cols = new wxString[nCols];
    bool canInsert = false;

    for (i = 0 ; i < nCols ; i++)
    {
        wxGridCellEditor *editor = 0;

        columns[i].name = res->ColName(i);
        columns[i].type = res->ColTypeOID(i);

        columns[i].typlen = res->ColSize(i);
        columns[i].typmod = res->ColTypeMod(i);
        columns[i].label_name = col_label.Item(i);

        switch(_colFormat.Item(i))
        {
       case wxBoolFormat:
            columns[i].numeric = false;
            columns[i].attr->SetReadOnly(false);
            editor = new sqlGridBoolEditor();
            break;
       case wxIntFormat:
            SetNumberEditor(i, 10);
            break;
       case wxMoneyFormat:
            columns[i].numeric = false;
            columns[i].attr->SetReadOnly(false);
            editor = new wxGridCellTextEditor();
            break;
       case wxDoubleFormat:
            columns[i].numeric = true;
            columns[i].attr->SetReadOnly(false);
            editor = new sqlGridNumericEditor();
            break;
       case wxChoicesFormat:
            columns[i].numeric = true;
            columns[i].attr->SetReadOnly(false);
            editor = new wxGridCellChoiceEditor();
 //           SetChoiceEditor(i, columns[i].name);
            break;
       case wxDateTimeFormat:
            columns[i].numeric = false;
            columns[i].attr->SetReadOnly(false);
            editor = new sqlGridDateTimeEditor(DateToStrFormat(wxDateTime::Today()));
            break;
        default:
            columns[i].numeric = false;
            columns[i].attr->SetReadOnly(false);
            columns[i].needResize = true;
            editor = new sqlGridTextEditor();
            break;
        }

        if (editor)
            columns[i].attr->SetEditor(editor);

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


sqlEditTable::~sqlEditTable()
{
    res = 0;
    if (dataPool)
        delete dataPool;

    delete addPool;

    delete[] columns;

    if (lineIndex)
        delete[] lineIndex;
}


int sqlEditTable::GetNumberCols()
{
    return nCols;
}


int sqlEditTable::GetNumberRows()
{
    return nRows + rowsAdded - rowsDeleted;
}


int sqlEditTable::GetNumberStoredRows()
{
    return nRows + rowsStored - rowsDeleted;
}


bool ctlSQLEditGrid::IsColText(int col)
{
    return GetTable()->IsColText(col);
}

bool sqlEditTable::IsColText(int col)
{
    return !columns[col].numeric && !(columns[col].type == PGOID_TYPE_BOOL);
}

bool sqlEditTable::IsColBoolean(int col)
{
    return (columns[col].type == PGOID_TYPE_BOOL);
}

wxString sqlEditTable::GetColLabelValue(int col)
{
    return columns[col].label_name;
}

wxString sqlEditTable::GetRowLabelValue(int row)
{
    wxString label;
    if (row < nRows - rowsDeleted || GetLine(row)->stored)
        label.Printf(wxT("%d"), row + 1);
    else
        label = wxT("*");
    return label;
}



void sqlEditTable::SetNumberEditor(int col, int len)
{
    columns[col].numeric = true;
    columns[col].attr->SetReadOnly(false);
    columns[col].attr->SetEditor(new sqlGridNumericEditor(len, 0));
}


bool sqlEditTable::CheckInCache(int row)
{
    if (row > nRows - rowsDeleted + rowsAdded)
        return false;
    if (row >= nRows - rowsDeleted)
        return true;

    return dataPool->IsFilled(row);
}


cacheLine *sqlEditTable::GetLine(int row)
{
    cacheLine *line;
    if (row < nRows - rowsDeleted)
        line = dataPool->Get(lineIndex[row]);
    else
        line = addPool->Get(row - (nRows - rowsDeleted));

    return line;
}



wxString sqlEditTable::MakeKey(cacheLine *line)
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



void sqlEditTable::UndoLine(int row)
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


bool sqlEditTable::StoreLine()
{
    bool done = false;
    wxString str_query;

 //   GetView()->BeginBatch();
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
//                if(colStoreStatus.Item(i) == 0)
//                    continue;

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
 //               if(colStoreStatus.Item(i) == 0)
 //                   continue;

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

//                wxLogMessage(str_query);
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

 //   GetView()->EndBatch();

    return done;
}


void sqlEditTable::SetValue(int row, int col, const wxString &value)
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
    line->cols[col] = value;
}



wxString sqlEditTable::GetValue(int row, int col)
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
                wxString val;
                if (res->ColTypeOID(i) == PGOID_TYPE_BYTEA)
                    val = _("<binary data>");
                else
                {
                    val = res->GetVal(i);
                    if (val.IsEmpty())
                    {
                        if (!res->IsNull(i))
                            val = wxEmptyString;
                    }
                    else if (val == wxT("''"))
                        val = wxT("\\'\\'");
                }
                line->cols[i] = val;
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

    if(columns[col].type == PGOID_TYPE_TIMESTAMP || columns[col].type == PGOID_TYPE_TIMESTAMPTZ)
    {
        val = DateToStrFormat(StrToDateTime(line->cols[col]));
    }


    val = line->cols[col];
    return val;
}


bool sqlEditTable::AppendRows(size_t rows)
{
    rowsAdded += rows;
    GetLine(nRows + rowsAdded - rowsDeleted - 1);

    wxGridTableMessage msg(this, wxGRIDTABLE_NOTIFY_ROWS_APPENDED, rows);
    GetView()->ProcessTableMessage(msg);

    return true;
}


bool sqlEditTable::DeleteRows(size_t pos, size_t rows)
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


bool sqlEditTable::Paste(int start_row,int start_col, int end_row, int end_col)
{
    int row, col;
    int data_rows, data_cols;
    wxGridStringArray data;
    wxArrayString array_rows,array_cols;
    wxString text, colSep;
    bool skipSerial;

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

    if(text.IsEmpty())
        return false;

    colSep = wxT("\t");
    array_rows = wxStringTokenize(text,END_OF_LINE, wxTOKEN_DEFAULT );

    data_rows = array_rows.GetCount();
    for(int i = 0;i<data_rows;i++)
    {
        array_cols = wxStringTokenize(array_rows.Item(i),colSep, wxTOKEN_DEFAULT );
        data.Add(array_cols);

        if(i==data_rows-1)
            data_cols = array_cols.GetCount();

        array_cols.Clear();
    }

    skipSerial = false;

    for (int i = start_col; i <= end_col; i++)
    {
        if (columns[i].type == (unsigned int)PGOID_TYPE_SERIAL ||
                columns[i].type == (unsigned int)PGOID_TYPE_SERIAL8)
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
    col = end_col-start_col+1;
    row = end_row-start_row+1;
    for(int i =0; i<row; i++)
    {
        if(row<=data_rows)
            array_cols = data.Item(i);
        else break;

            SetLastRow(start_row+i);
            cacheLine *line = GetLine(start_row+i);
            if (!line->cols)
                line->cols = new wxString[col];

        for (int j= 0; j< col; j++)
        {

            if (!(skipSerial && (columns[start_col+j].type == (unsigned int)PGOID_TYPE_SERIAL ||
            columns[start_col+j].type == (unsigned int)PGOID_TYPE_SERIAL8))&& col<=data_cols)
            {
                line->cols[start_col+j] = array_cols.Item(j);
 //               SetValue(start_row+i, start_col+j, array_cols.Item(j));
                GetView()->SetGridCursor(start_row+i, start_col+j);
                GetView()->MakeCellVisible(start_row+i, start_col+j);
                pasted = true;
            }
        }
        array_cols.Clear();

        if(!line->cols[7].IsEmpty())
            StoreLine();
    }


    GetView()->ForceRefresh();

    return pasted;
}

wxGridCellAttr *sqlEditTable::GetAttr(int row, int col, wxGridCellAttr::wxAttrKind  kind)
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
