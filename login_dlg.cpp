#include "login_dlg.h"
#include "pugixml.hpp"
#include "wfApp.h"
#include "security/wxMD5.h"
#include "security/base64.h"
#include "wf_stdafx.h"

//(*InternalHeaders(login_dlg)
#include <wx/intl.h>
#include <wx/string.h>
//*)

extern   para gr_para;
//(*IdInit(login_dlg)
const long login_dlg::ID_STATICTEXT1 = wxNewId();
const long login_dlg::ID_STATICTEXT2 = wxNewId();
const long login_dlg::ID_TEXTCTRL_USER = wxNewId();
const long login_dlg::ID_TEXTCTRL_PWD = wxNewId();
const long login_dlg::ID_CHECKBOX_SAVE = wxNewId();
const long login_dlg::ID_BUTTON1 = wxNewId();
const long login_dlg::ID_BUTTON2 = wxNewId();
const long login_dlg::ID_STATICTEXT3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(login_dlg,wxDialog)
    //(*EventTable(login_dlg)
    //*)
END_EVENT_TABLE()

login_dlg::login_dlg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(login_dlg)
    Create(parent, id, _("系统登录"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    SetClientSize(wxSize(300,192));
    Move(wxDefaultPosition);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("用户名:"), wxPoint(16,40), wxSize(72,13), 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("密码:"), wxPoint(16,80), wxSize(80,13), 0, _T("ID_STATICTEXT2"));
    tc_user = new wxTextCtrl(this, ID_TEXTCTRL_USER, wxEmptyString, wxPoint(96,40), wxSize(152,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_USER"));
    tc_pwd = new wxTextCtrl(this, ID_TEXTCTRL_PWD, wxEmptyString, wxPoint(96,72), wxSize(152,21), wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL_PWD"));
    cb_save = new wxCheckBox(this, ID_CHECKBOX_SAVE, _("是否保存用户名和密码"), wxPoint(32,104), wxSize(240,13), 0, wxDefaultValidator, _T("ID_CHECKBOX_SAVE"));
    cb_save->SetValue(false);
    Button1 = new wxButton(this, ID_BUTTON1, _("登录"), wxPoint(48,128), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(this, ID_BUTTON2, _("取消"), wxPoint(168,128), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    st_message = new wxStaticText(this, ID_STATICTEXT3, wxEmptyString, wxPoint(0,176), wxSize(296,13), 0, _T("ID_STATICTEXT3"));

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&login_dlg::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&login_dlg::OnButton2Click);
    Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&login_dlg::OnInit);
    //*)
}

login_dlg::~login_dlg()
{
    //(*Destroy(login_dlg)
    //*)
}


void login_dlg::OnInit(wxInitDialogEvent& event)
{
    pugi::xml_document ldoc;
    pugi::xml_node lnode;
    pugi::xml_parse_result result;

    result = ldoc.load_file("config.xml");
    bool b_save;
    wxString lpwd;
    if(result)
    {
        lnode =ldoc.child("usrinfo");
        b_save=lnode.child("save").text().as_bool();
        cb_save->SetValue(b_save);
        if(b_save)
        {
            lpwd = wxString(lnode.child_value("password"));
            tc_user->SetValue(wxString(lnode.child_value("usrname")));
            lpwd = Base64::Decode(lpwd);
            tc_pwd->SetValue(lpwd);
        }
    }

}

void login_dlg::OnButton1Click(wxCommandEvent& event)
{
    if(cb_save->IsChecked())
    {
        pugi::xml_document ldoc;
        pugi::xml_node lnode;
        pugi::xml_parse_result result;
        wxString lpwd;

        result = ldoc.load_file("config.xml");
        if(result)
        {
            lnode =ldoc.child("usrinfo");
            lnode.child("save").text().set(cb_save->GetValue());
            lnode.child("usrname").text().set(tc_user->GetValue().mbc_str());
            lpwd = tc_pwd->GetValue();
            lpwd = Base64::Encode(lpwd);
            lnode.child("password").text().set(lpwd.mbc_str());
            ldoc.save_file("config.xml");
        }
    }

    if(tc_user->IsEmpty())
    {
        st_message->SetLabelText(_("用户ID不能为空"));
        return;
    }

    wxPostgreSQLresult *res;
    wxString lpwd;
    wxString lquery= "select employee_id, name, plant, active, role_id, password from v_user_login where employee_id = '" + tc_user->GetValue()+"'";
    res = wxGetApp().conn->Execute(lquery);
    if(res->Status()!=PGRES_TUPLES_OK)
    {
        wxMessageBox(res->ErrorMessage(),_("SELECT failed:"));
        res->Clear();
        return;
    }

    int irow = res->GetRowsNumber();
    if(irow==0)
    {
        st_message->SetLabelText(_("用户不存在!"));
        return;
    }

    res->MoveFirst();
    if(!res->GetBool(3))
    {
        st_message->SetLabelText(_("账户未激活,请联系管理员!"));
        return;
    }

    lpwd.Empty();

    wxMD5 md5_pwd(tc_pwd->GetValue());
    lpwd = md5_pwd.GetDigest(TRUE);

    if(lpwd!=res->GetVal(5))
    {
        st_message->SetLabelText(_("密码错误"));
        res->Clear();
        tc_pwd->Clear();
        return;
    }
    else
    {
        gr_para.login_user = tc_user->GetValue();
        gr_para.login_role = res->GetVal(4).Upper();
        gr_para.login_user_name =  res->GetVal(1);// wxString(res->GetValue(i,1),wxConvUTF8);
        gr_para.plant = res->GetVal(2); //wxString(res->GetValue(i,2));
        gr_para.login_datetime = wxDateTime::Now();
        res->Clear();

        wxGetApp().login_log(0);

        this->EndModal(wxID_OK);
    }

}

void login_dlg::OnButton2Click(wxCommandEvent& event)
{
    this->EndModal(wxID_CANCEL);
}
