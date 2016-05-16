#include "connect_para_dlg.h"
#include "pugixml.hpp"
#include <wx/base64.h>
#include "security/base64.h"

//(*InternalHeaders(connect_para_dlg)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(connect_para_dlg)
//const long connect_para_dlg::ID_TEXTCTRL_ERROR = wxNewId();
const long connect_para_dlg::ID_STATICTEXT1 = wxNewId();
const long connect_para_dlg::ID_TEXTCTRL_HOST = wxNewId();
const long connect_para_dlg::ID_STATICTEXT2 = wxNewId();
const long connect_para_dlg::ID_TEXTCTRL_PORT = wxNewId();
const long connect_para_dlg::ID_STATICTEXT3 = wxNewId();
const long connect_para_dlg::ID_TEXTCTRL_DBNAME = wxNewId();
const long connect_para_dlg::ID_STATICTEXT4 = wxNewId();
const long connect_para_dlg::ID_TEXTCTRL_DBUSER = wxNewId();
const long connect_para_dlg::ID_STATICTEXT5 = wxNewId();
const long connect_para_dlg::ID_TEXTCTRL_DBPWD = wxNewId();
const long connect_para_dlg::ID_BUTTON1 = wxNewId();
const long connect_para_dlg::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(connect_para_dlg,wxDialog)
	//(*EventTable(connect_para_dlg)
	//*)
END_EVENT_TABLE()

connect_para_dlg::connect_para_dlg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(connect_para_dlg)
	Create(parent, wxID_ANY, _("connect para"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(400,301));
//	tc_error = new wxTextCtrl(this, ID_TEXTCTRL_ERROR, wxEmptyString, wxPoint(0,0), wxSize(400,80), wxTE_MULTILINE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL_ERROR"));
//	tc_error->Hide();
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("host"), wxPoint(16,104), wxSize(96,13), 0, _T("ID_STATICTEXT1"));
	tc_host = new wxTextCtrl(this, ID_TEXTCTRL_HOST, wxEmptyString, wxPoint(152,96), wxSize(200,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_HOST"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("port"), wxPoint(16,136), wxSize(112,13), 0, _T("ID_STATICTEXT2"));
	tc_port = new wxTextCtrl(this, ID_TEXTCTRL_PORT, wxEmptyString, wxPoint(152,128), wxSize(200,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_PORT"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("dbname"), wxPoint(16,168), wxSize(112,13), 0, _T("ID_STATICTEXT3"));
	tc_dbname = new wxTextCtrl(this, ID_TEXTCTRL_DBNAME, wxEmptyString, wxPoint(152,160), wxSize(200,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_DBNAME"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("dbuser"), wxPoint(16,200), wxSize(104,13), 0, _T("ID_STATICTEXT4"));
	tc_dbuser = new wxTextCtrl(this, ID_TEXTCTRL_DBUSER, wxEmptyString, wxPoint(152,192), wxSize(200,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_DBUSER"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("db password"), wxPoint(16,232), wxSize(104,13), 0, _T("ID_STATICTEXT5"));
	tc_dbpwd = new wxTextCtrl(this, ID_TEXTCTRL_DBPWD, wxEmptyString, wxPoint(152,224), wxSize(200,21), wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL_DBPWD"));
	Button1 = new wxButton(this, ID_BUTTON1, _("ok"), wxPoint(48,264), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(this, ID_BUTTON2, _("cancel"), wxPoint(224,264), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_para_dlg::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_para_dlg::OnButton2Click);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&connect_para_dlg::OnInit);
	//*)
}

connect_para_dlg::~connect_para_dlg()
{
	//(*Destroy(connect_para_dlg)
	//*)
}


void connect_para_dlg::OnButton1Click(wxCommandEvent& event)
{
    wxString ldbpwd;
    pugi::xml_document ldoc;
    pugi::xml_node lnode;
    pugi::xml_parse_result result;

    result = ldoc.load_file("config.xml");
    if(result)
    {
        lnode =ldoc.child("connect").child("host");
        lnode.text().set(tc_host->GetValue().mbc_str());

        lnode =ldoc.child("connect").child("port");
        lnode.text().set(tc_port->GetValue().mbc_str());

        lnode =ldoc.child("connect").child("dbname");
        lnode.text().set(tc_dbname->GetValue().mbc_str());


            lnode =ldoc.child("connect").child("dbuser");
            lnode.text().set(tc_dbuser->GetValue().mbc_str());


            lnode =ldoc.child("connect").child("dbpwd");
            ldbpwd = tc_dbpwd->GetValue();
            ldbpwd = Base64::Encode(ldbpwd);
            lnode.text().set(ldbpwd.mbc_str());


        ldoc.save_file("config.xml");
    }
    this->EndDialog(wxID_OK);
}

void connect_para_dlg::OnButton2Click(wxCommandEvent& event)
{
        this->EndDialog(wxID_CANCEL);
}

void connect_para_dlg::OnInit(wxInitDialogEvent& event)
{
//    tc_error->SetDefaultStyle(wxTextAttr(*wxRED, *wxLIGHT_GREY));
 //   tc_error->SetValue(str_error);

    wxString ldbpwd;
    pugi::xml_document ldoc;
    pugi::xml_node lnode;
    pugi::xml_parse_result result;

    result = ldoc.load_file("config.xml");
    if(result)
    {
        lnode =ldoc.child("connect");
        tc_host->SetValue(wxString(lnode.child_value("host")));
        tc_port->SetValue(wxString(lnode.child_value("port")));
        tc_dbname->SetValue(wxString(lnode.child_value("dbname")));
        tc_dbuser->SetValue(wxString(lnode.child_value("dbuser")));
        ldbpwd = wxString(lnode.child_value("dbpwd"));
        ldbpwd = Base64::Decode(ldbpwd);
        tc_dbpwd->SetValue(ldbpwd);
    }
}
