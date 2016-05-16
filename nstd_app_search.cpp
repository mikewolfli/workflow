#include "nstd_app_search.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(nstd_app_search)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(nstd_app_search)
const long nstd_app_search::ID_CHOICE_SELECT = wxNewId();
const long nstd_app_search::ID_TEXTCTRL_VALUE = wxNewId();
const long nstd_app_search::ID_BUTTON1 = wxNewId();
const long nstd_app_search::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(nstd_app_search,wxDialog)
	//(*EventTable(nstd_app_search)
	//*)
END_EVENT_TABLE()

nstd_app_search::nstd_app_search(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(nstd_app_search)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("条件查询"));
	choice_select = new wxChoice(this, ID_CHOICE_SELECT, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_SELECT"));
	choice_select->SetSelection( choice_select->Append(_("显示所有未提交的非标申请")) );
	choice_select->Append(_("显示所有已经走流程的非标申请"));
	choice_select->Append(_("显示所有已经完成的非标申请"));
	choice_select->Append(_("非标申请编号"));
	choice_select->Append(_("项目WBS号"));
	choice_select->Append(_("项目名称"));
	choice_select->Append(_("合同号"));
	StaticBoxSizer1->Add(choice_select, 1, wxALL|wxEXPAND, 0);
	tc_value = new wxTextCtrl(this, ID_TEXTCTRL_VALUE, wxEmptyString, wxDefaultPosition, wxSize(260,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_VALUE"));
	StaticBoxSizer1->Add(tc_value, 2, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("确定"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 0);
	Button2 = new wxButton(this, ID_BUTTON2, _("取消"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_LEFT, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_app_search::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_app_search::OnButton2Click);
	//*)
}

nstd_app_search::~nstd_app_search()
{
	//(*Destroy(nstd_app_search)
	//*)
}


void nstd_app_search::OnButton1Click(wxCommandEvent& event)
{
    i_choice = choice_select->GetSelection();

    if(tc_value->IsEmpty() && i_choice >= 4)
    {
        wxMessageBox(_("请输入查询条件!"),_("提示"),wxOK);
        return;
    }

    str_search = tc_value->GetValue();
    EndDialog(wxID_OK);
}

void nstd_app_search::OnButton2Click(wxCommandEvent& event)
{
    EndDialog(wxID_CANCEL);
}

void nstd_app_search::set_search_case(wxArrayString & array_str)
{
    choice_select->Clear();

    choice_select->Append(array_str);
    choice_select->SetSelection(0);
}
