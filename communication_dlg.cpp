#include "communication_dlg.h"
#include "wfApp.h"

//(*InternalHeaders(communication_dlg)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(communication_dlg)
const long communication_dlg::ID_CHECKBOX_GAD = wxNewId();
const long communication_dlg::ID_CHECKBOX_SPEC_MEMO = wxNewId();
const long communication_dlg::ID_TEXTCTRL_CONTENT = wxNewId();
const long communication_dlg::ID_TEXTCTRL_RETURN = wxNewId();
const long communication_dlg::ID_BUTTON1 = wxNewId();
const long communication_dlg::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(communication_dlg,wxDialog)
	//(*EventTable(communication_dlg)
	//*)
END_EVENT_TABLE()

communication_dlg::communication_dlg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(communication_dlg)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("评审问题相关项"));
	cb_gad = new wxCheckBox(this, ID_CHECKBOX_GAD, _("GAD"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_GAD"));
	cb_gad->SetValue(false);
	StaticBoxSizer1->Add(cb_gad, 1, wxALL|wxALIGN_LEFT, 5);
	cb_specmemo = new wxCheckBox(this, ID_CHECKBOX_SPEC_MEMO, _("Spec Memo"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_SPEC_MEMO"));
	cb_specmemo->SetValue(false);
	StaticBoxSizer1->Add(cb_specmemo, 1, wxALL|wxALIGN_LEFT, 5);
	tc_content = new wxTextCtrl(this, ID_TEXTCTRL_CONTENT, wxEmptyString, wxDefaultPosition, wxSize(271,34), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL_CONTENT"));
	StaticBoxSizer1->Add(tc_content, 1, wxALL|wxALIGN_LEFT, 5);
	tc_return = new wxTextCtrl(this, ID_TEXTCTRL_RETURN, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL_RETURN"));
	StaticBoxSizer1->Add(tc_return, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(StaticBoxSizer1, 3, wxALL|wxEXPAND, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("确认"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("取消"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&communication_dlg::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&communication_dlg::OnButton2Click);
	//*)


 //   show_control();


//     tc_content->SetValue(m_content);
}

communication_dlg::~communication_dlg()
{
	//(*Destroy(communication_dlg)
	//*)
}


void communication_dlg::OnButton1Click(wxCommandEvent& event)
{

    b_gad = cb_gad->IsChecked();
    b_spec = cb_specmemo->IsChecked();

    wxString str_head;

    if(b_gad&&!b_spec)
    {
        str_head=wxT("[GAD]");
    }else if(!b_gad&&b_spec)
    {
        str_head=wxT("[SPEC MEMO]");
    }else if(b_gad&&b_spec)
    {
        str_head = wxT("[GAD+SPEC MEMO]");
    }else
         str_head.Empty();


    switch(m_mode)
    {
    case 0:
        m_content = str_head+tc_content->GetValue();
        break;
    case 1:
        m_return = str_head+tc_return->GetValue();
        break;
    default:
        break;

    }

    EndDialog(wxID_OK);
}

void communication_dlg::OnButton2Click(wxCommandEvent& event)
{
    EndDialog(wxID_CANCEL);
}

void communication_dlg::enable_control()
{
    switch(m_mode)
    {
    case 0:
        tc_content->Show(true);
        tc_return->Show(false);
        break;
    case 1:
        cb_specmemo->Enable(false);
        cb_gad->Enable(false);
        tc_content->Enable(false);
        tc_return->Enable(true);
        break;
    case 2:
        cb_specmemo->Enable(false);
        cb_gad->Enable(false);
        tc_content->Enable(false);
        tc_return->Enable(false);
        break;
    default:
        break;
    }

 //   Layout();
}

void communication_dlg::init_communication(wxString s_id)
{
    wxString s_sql = wxT(" select * from s_review_communication where review_task_id='")+s_id+wxT("' and issue_status <=2;");
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(s_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int i_count = _res->GetRowsNumber();
    wxString str;
    int i_pos, i_len;
    if(i_count >=1)
    {
        b_gad= _res->GetBool(wxT("is_gad"));
        b_spec = _res->GetBool(wxT("is_spec"));

        cb_gad->SetValue(b_gad);
        cb_specmemo->SetValue(b_spec);

        str = _res->GetVal(wxT("issue_content"));
        i_pos = str.Find(wxT("]"));
        i_len = str.Length();
        if(i_pos!=wxNOT_FOUND)
        {
             str = str.Right(i_len-i_pos-1);
        }
        tc_content->SetValue(str);

        str = _res->GetVal(wxT("return_content"));
        i_pos = str.Find(wxT("]"));
        i_len = str.Length();
        if(i_pos!=wxNOT_FOUND)
        {
             str = str.Right(i_len-i_pos-1);
        }
        tc_return->SetValue(str);
    }

    return;
}
