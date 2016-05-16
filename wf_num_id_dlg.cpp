#include "wf_num_id_dlg.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(wf_num_id_dlg)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(wf_num_id_dlg)
const long wf_num_id_dlg::ID_SPINCTRL1 = wxNewId();
const long wf_num_id_dlg::ID_BUTTON1 = wxNewId();
const long wf_num_id_dlg::ID_BUTTON2  = wxNewId();
//*)

BEGIN_EVENT_TABLE(wf_num_id_dlg,wxDialog)
	//(*EventTable(wf_num_id_dlg)
	//*)
END_EVENT_TABLE()

wf_num_id_dlg::wf_num_id_dlg(int _init, wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(wf_num_id_dlg)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("计数"));
	sc_num = new wxSpinCtrl(this, ID_SPINCTRL1, _T("1"), wxDefaultPosition, wxDefaultSize, 0, 1, 100, 1, _T("ID_SPINCTRL1"));
	sc_num->SetValue(_T("1"));
	StaticBoxSizer1->Add(sc_num, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("确定"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2= new wxButton(this, ID_BUTTON2, _("取消"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_SPINCTRL1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&wf_num_id_dlg::Onsc_numChange);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wf_num_id_dlg::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wf_num_id_dlg::OnButton2Click);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&wf_num_id_dlg::OnClose);
	//*)
	m_init= _init;
	sc_num->SetValue(m_init);
}

wf_num_id_dlg::~wf_num_id_dlg()
{
	//(*Destroy(wf_num_id_dlg)
	//*)
}


void wf_num_id_dlg::OnButton1Click(wxCommandEvent& event)
{
    int value=sc_num->GetValue();

    if(value<m_init)
    {
        wxMessageBox(_("填写数值需要大于等于初始值"),_("提示"));
        sc_num->SetValue(m_init);
        return;
    }

    m_value=sc_num->GetValue();

    EndDialog(wxID_OK);
}

void wf_num_id_dlg::OnButton2Click(wxCommandEvent& event)
{
    EndDialog(wxID_CANCEL);
}

void wf_num_id_dlg::Onsc_numChange(wxSpinEvent& event)
{
    if (!sc_num)
        return;

    int value = event.GetInt();

    wxASSERT_MSG( value == sc_num->GetValue(),
                  _T("spinctrl value should be the same") );

    if(value<m_init)
    {
        wxMessageBox(_("填写数值需要大于等于初始值"),_("提示"));
        sc_num->SetValue(m_init);
    }
}

void wf_num_id_dlg::OnClose(wxCloseEvent& event)
{
    EndDialog(wxID_CANCEL);
}
