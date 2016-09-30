#include "cf_task_list.h"

//(*InternalHeaders(cf_task_list)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(cf_task_list)
const long cf_task_list::ID_BUTTON1 = wxNewId();
const long cf_task_list::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(cf_task_list,wxDialog)
	//(*EventTable(cf_task_list)
	//*)
END_EVENT_TABLE()

cf_task_list::cf_task_list(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(cf_task_list)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX, _T("id"));
	SetClientSize(wxSize(800,600));
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer1->Add(BoxSizer2, 5, wxALL|wxEXPAND, 0);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("确定"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("取消"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	SetSizer(BoxSizer1);
	Layout();
	Center();
	//*)
}

cf_task_list::~cf_task_list()
{
	//(*Destroy(cf_task_list)
	//*)
}

