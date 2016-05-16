#include "nstd_app_item_units.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(nstd_app_item_units)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(nstd_app_item_units)
const long nstd_app_item_units::ID_CHECKLISTBOX1 = wxNewId();
const long nstd_app_item_units::ID_BUTTON1 = wxNewId();
const long nstd_app_item_units::ID_BUTTON2 = wxNewId();
const long nstd_app_item_units::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(nstd_app_item_units,wxDialog)
	//(*EventTable(nstd_app_item_units)
	//*)
END_EVENT_TABLE()

nstd_app_item_units::nstd_app_item_units(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(nstd_app_item_units)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	clb_units = new wxCheckListBox(this, ID_CHECKLISTBOX1, wxDefaultPosition, wxSize(268,125), 0, 0, 0, wxDefaultValidator, _T("ID_CHECKLISTBOX1"));
	BoxSizer2->Add(clb_units, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(BoxSizer2, 5, wxALL|wxEXPAND, 0);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("确定"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(Button1, 1, wxALL|wxEXPAND, 0);
	Button2 = new wxButton(this, ID_BUTTON2, _("取消"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(Button2, 1, wxALL|wxEXPAND, 0);
	Button3 = new wxButton(this, ID_BUTTON3, _("全选/取消全选"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer3->Add(Button3, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_app_item_units::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_app_item_units::OnButton2Click);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_app_item_units::OnButton3Click);
	//*)
}

nstd_app_item_units::~nstd_app_item_units()
{
	//(*Destroy(nstd_app_item_units)
	//*)
}

void nstd_app_item_units::init_checklistbox(wxArrayString &array_str, wxArrayString &array_sel, bool b_sel, bool b_edit)
{
    clb_units->Append(array_str);


    clb_units->Enable(b_edit);

    if(array_sel.IsEmpty())
        return;

    int i_count = array_sel.GetCount();
    int i_row = array_str.GetCount();

    for(int i=0;i<i_count;i++)
    {
        for(int j=0;j<i_row;j++)
        {
            if(array_str.Item(j)==array_sel.Item(i)&& b_sel)
                clb_units->Check(j,true);

        }
    }
}

void nstd_app_item_units::OnButton1Click(wxCommandEvent& event)
{
    wxArrayInt array_icheck;
    wxString str;
    int i_count = clb_units->GetCheckedItems(array_icheck);
    if(i_count==0)
    {
        if(wxMessageBox(_("请选择相关梯号!"),_("信息"),wxOK)==wxOK)
            return;
    }

    for(int i =0;i<i_count;i++)
    {
       str = clb_units->GetString(array_icheck.Item(i));
       m_units = m_units+ str + wxT(";");
       array_units.Add(str);
    }

    EndDialog(wxID_OK);
}

void nstd_app_item_units::OnButton2Click(wxCommandEvent& event)
{
    EndDialog(wxID_CANCEL);
}

void nstd_app_item_units::OnButton3Click(wxCommandEvent& event)
{
    int i_count = clb_units->GetCount();

    bool b_check = !clb_units->IsChecked(0);

    for(int i=0;i<i_count; i++)
    {
       clb_units->Check(i,b_check);
    }

}
