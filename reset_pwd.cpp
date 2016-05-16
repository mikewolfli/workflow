#include "reset_pwd.h"
#include "wfApp.h"
#include "./security/wxMD5.h"

//(*InternalHeaders(reset_pwd)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(reset_pwd)
const long reset_pwd::ID_STATICTEXT1 = wxNewId();
const long reset_pwd::ID_TEXTCTRL1 = wxNewId();
const long reset_pwd::ID_STATICTEXT2 = wxNewId();
const long reset_pwd::ID_TEXTCTRL2 = wxNewId();
const long reset_pwd::ID_STATICTEXT3 = wxNewId();
const long reset_pwd::ID_TEXTCTRL3 = wxNewId();
const long reset_pwd::ID_BUTTON1 = wxNewId();
const long reset_pwd::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(reset_pwd,wxDialog)
	//(*EventTable(reset_pwd)
	//*)
END_EVENT_TABLE()

reset_pwd::reset_pwd(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(reset_pwd)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	FlexGridSizer1 = new wxFlexGridSizer(3, 2, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("当前密码"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	tc_oldpwd = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(128,21), wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer1->Add(tc_oldpwd, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("新密码"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	tc_new_pwd = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	FlexGridSizer1->Add(tc_new_pwd, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("确认新密码"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	tc_confirm_pwd = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	FlexGridSizer1->Add(tc_confirm_pwd, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(FlexGridSizer1, 3, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("确定"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("取消"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&reset_pwd::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&reset_pwd::OnButton2Click);
	//*)
}

reset_pwd::~reset_pwd()
{
	//(*Destroy(reset_pwd)
	//*)
}


void reset_pwd::OnButton1Click(wxCommandEvent& event)
{
    wxPostgreSQLresult *res;
    wxString spwd,lpwd;
    wxString lquery= wxT("select employee_id, password from s_login where employee_id = '" + gr_para.login_user+"'");
    res = wxGetApp().conn->Execute(lquery);
    if(res->Status()!=PGRES_TUPLES_OK)
    {
        wxMessageBox(res->ErrorMessage(),_("SELECT failed:"));
        res->Clear();
        return;
    }

    spwd = res->GetVal(wxT("password"));
    res->Clear();

    wxMD5 md5_pwd(tc_oldpwd->GetValue());
    lpwd = md5_pwd.GetDigest(TRUE);

    if(lpwd!= spwd)
    {
        wxMessageBox(_("原密码输入错误!"),_("密码修改"),wxOK);
        tc_oldpwd->Clear();
        return;
    }

    lpwd = tc_new_pwd->GetValue();


    if(tc_confirm_pwd->GetValue() != lpwd )
    {
        wxMessageBox(_("密码确认错误，请重新输入!"),_("密码修改"),wxOK);
        tc_confirm_pwd->Clear();
        return;
    }

    spwd = md5_pwd.GetDigest(lpwd);
    lquery = wxT("UPDATE s_login SET password='")+spwd+wxT("' WHERE employee_id = '" + gr_para.login_user+"'");
    if(wxGetApp().app_sql_update(lquery))
       wxLogMessage(_("密码更改成功!"));

    this->EndDialog(wxID_OK);
}

void reset_pwd::OnButton2Click(wxCommandEvent& event)
{
    this->EndDialog(wxID_CANCEL);
}
