#include "enter_log.h"

//(*InternalHeaders(enter_log)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(enter_log)
const long enter_log::ID_TEXTCTRL_LOG = wxNewId();
const long enter_log::ID_BUTTON1 = wxNewId();
const long enter_log::ID_BUTTON2 = wxNewId();
const long enter_log::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(enter_log,wxDialog)
	//(*EventTable(enter_log)
	//*)
END_EVENT_TABLE()

enter_log::enter_log(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(enter_log)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;

	Create(parent, id, _("备注输入:"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(350,198));
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	tc_log = new wxTextCtrl(this, ID_TEXTCTRL_LOG, wxEmptyString, wxDefaultPosition, wxSize(441,174), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL_LOG"));
	BoxSizer1->Add(tc_log, 5, wxALL|wxEXPAND, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("连续输入"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("单个输入"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button3 = new wxButton(this, ID_BUTTON3, _("直接拷贝前步"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer2->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 0);
	SetSizer(BoxSizer1);
	SetSizer(BoxSizer1);
	Layout();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&enter_log::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&enter_log::OnButton2Click);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&enter_log::OnButton3Click);
	//*)
}

enter_log::~enter_log()
{
	//(*Destroy(enter_log)
	//*)
}


void enter_log::OnButton1Click(wxCommandEvent& event)
{
}

void enter_log::OnButton2Click(wxCommandEvent& event)
{
}

void enter_log::OnButton3Click(wxCommandEvent& event)
{
}
