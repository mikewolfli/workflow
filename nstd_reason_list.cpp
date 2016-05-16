#include "nstd_reason_list.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(nstd_reason_list)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(nstd_reason_list)
const long nstd_reason_list::ID_CHECKLISTBOX1 = wxNewId();
const long nstd_reason_list::ID_BUTTON1 = wxNewId();
const long nstd_reason_list::ID_BUTTON2 = wxNewId();
const long nstd_reason_list::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(nstd_reason_list,wxDialog)
	//(*EventTable(nstd_reason_list)
	//*)
END_EVENT_TABLE()

nstd_reason_list::nstd_reason_list(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(nstd_reason_list)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	clb_reason = new wxCheckListBox(this, ID_CHECKLISTBOX1, wxDefaultPosition, wxSize(268,125), 0, 0, 0, wxDefaultValidator, _T("ID_CHECKLISTBOX1"));
	BoxSizer2->Add(clb_reason, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer1->Add(BoxSizer2, 5, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("确定"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(Button1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	Button2 = new wxButton(this, ID_BUTTON2, _("取消"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(Button2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	Button3 = new wxButton(this, ID_BUTTON3, _("全选/取消全选"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer3->Add(Button3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_reason_list::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_reason_list::OnButton2Click);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_reason_list::OnButton3Click);
	//*)
}

nstd_reason_list::~nstd_reason_list()
{
	//(*Destroy(nstd_reason_list)
	//*)
}

void nstd_reason_list::OnButton1Click(wxCommandEvent& event)
{
    wxArrayInt array_icheck;
    wxString str;
    int i_count = clb_reason->GetCheckedItems(array_icheck);
    if(i_count==0)
    {
        if(wxMessageBox(_("请选择非标原因!"),_("信息"),wxOK)==wxOK)
            return;
    }

    for(int i =0;i<i_count;i++)
    {
       str = clb_reason->GetString(array_icheck.Item(i));
       m_reason = m_reason + str + wxT(";");
    }

    EndDialog(wxID_OK);
}

void nstd_reason_list::OnButton2Click(wxCommandEvent& event)
{
    EndDialog(wxID_CANCEL);
}

void nstd_reason_list::OnButton3Click(wxCommandEvent& event)
{
    int i_count = clb_reason->GetCount();

    bool b_check = !clb_reason->IsChecked(0);

    for(int i=0;i<i_count; i++)
    {
       clb_reason->Check(i,b_check);
    }

}

void nstd_reason_list::init_checklistbox(wxArrayString &array_str)
{
    clb_reason->Append(array_str);

}
