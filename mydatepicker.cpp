#include "mydatepicker.h"

//(*InternalHeaders(mydatepicker)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(mydatepicker)
const long mydatepicker::ID_CALENDARCTRL1 = wxNewId();
const long mydatepicker::ID_BUTTON1 = wxNewId();
const long mydatepicker::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(mydatepicker,wxDialog)
	//(*EventTable(mydatepicker)
	//*)
END_EVENT_TABLE()

mydatepicker::mydatepicker(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(mydatepicker)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;

	Create(parent, id, _("日期选择"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(212,223));
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	cctr_date = new wxCalendarCtrl(this, ID_CALENDARCTRL1, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxCAL_MONDAY_FIRST|wxCAL_SHOW_HOLIDAYS, _T("ID_CALENDARCTRL1"));
	BoxSizer1->Add(cctr_date, 4, wxALL|wxEXPAND, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("确定"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->SetDefault();
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	Button2 = new wxButton(this, ID_BUTTON2, _("取消"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 0);
	SetSizer(BoxSizer1);
	SetSizer(BoxSizer1);
	Layout();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mydatepicker::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mydatepicker::OnButton2Click);
	//*)
}

mydatepicker::~mydatepicker()
{
	//(*Destroy(mydatepicker)
	//*)
}


void mydatepicker::OnButton1Click(wxCommandEvent& event)
{
    m_date_value = cctr_date->GetDate();

    m_value = m_date_value.Format("%Y-%m-%d");
    EndDialog(wxID_OK);
}

void mydatepicker::OnButton2Click(wxCommandEvent& event)
{
    m_value = wxEmptyString;
    EndDialog(wxID_CANCEL);
}

