#include "wf_search.h"
#include "wfApp.h"

//(*InternalHeaders(wf_search)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(wf_search)
const long wf_search::ID_CHOICE_SEARCH = wxNewId();
const long wf_search::ID_TEXTCTRL_SEARCH = wxNewId();
const long wf_search::ID_BUTTON1 = wxNewId();
const long wf_search::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wf_search,wxDialog)
	//(*EventTable(wf_search)
	//*)
END_EVENT_TABLE()

wf_search::wf_search(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(wf_search)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	choice_case = new wxChoice(this, ID_CHOICE_SEARCH, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_SEARCH"));
	choice_case->Append(_("项目WBS NO"));
	choice_case->SetSelection( choice_case->Append(_("项目号(project)")) );
	choice_case->Append(_("四位合同号"));
	choice_case->Append(_("项目名称"));
	BoxSizer2->Add(choice_case, 1, wxALL|wxALIGN_CENTER_VERTICAL, 0);
	tc_search = new wxTextCtrl(this, ID_TEXTCTRL_SEARCH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL_SEARCH"));
	BoxSizer2->Add(tc_search, 3, wxALL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 0);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("确认"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(Button1, 1, wxALL|wxEXPAND, 0);
	Button2 = new wxButton(this, ID_BUTTON2, _("取消"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(Button2, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxEXPAND, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wf_search::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wf_search::OnButton2Click);
	//*)


	choice_case->SetSelection(1);
}

wf_search::~wf_search()
{
	//(*Destroy(wf_search)
	//*)
}


void wf_search::OnButton1Click(wxCommandEvent& event)
{
    if(tc_search->IsEmpty())
    {
        wxLogMessage("请输入查询条件!");
        return;
    }

    i_choice = choice_case->GetSelection();

    str_search = tc_search->GetValue();


    if(str_search.IsEmpty())
    {
        wxMessageBox(_("请务必填写搜索条件!"),_("提示"));
        return;
    }

    EndDialog(wxID_OK);
}

void wf_search::OnButton2Click(wxCommandEvent& event)
{
    EndDialog(wxID_CANCEL);
}

void wf_search::set_choice(wxArrayString &a_str)
{
    choice_case->Clear();
    choice_case->Append(a_str);

    choice_case->SetSelection(0);
}
