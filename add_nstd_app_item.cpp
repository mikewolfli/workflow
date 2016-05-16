#include "add_nstd_app_item.h"
#include "pugixml.hpp"
#include <wx/msgdlg.h>
#include "wfApp.h"
#include "nstd_reason_list.h"

//(*InternalHeaders(add_nstd_app_item)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(add_nstd_app_item)
const long add_nstd_app_item::ID_STATICTEXT1 = wxNewId();
const long add_nstd_app_item::ID_TEXTCTRL_INDEX = wxNewId();
const long add_nstd_app_item::ID_STATICTEXT3 = wxNewId();
const long add_nstd_app_item::ID_TEXTCTRL_ITEM_NO = wxNewId();
const long add_nstd_app_item::ID_STATICTEXT4 = wxNewId();
const long add_nstd_app_item::ID_CHOICE_CATALOG = wxNewId();
const long add_nstd_app_item::ID_STATICTEXT5 = wxNewId();
const long add_nstd_app_item::ID_COMBOBOX_NSTD_CATALOG = wxNewId();
const long add_nstd_app_item::ID_BUTTON_NSTD_REASON = wxNewId();
const long add_nstd_app_item::ID_TEXTCTRL_NSTD_DESC = wxNewId();
const long add_nstd_app_item::ID_STATICTEXT7 = wxNewId();
const long add_nstd_app_item::ID_TEXTCTRL_STATUS = wxNewId();
const long add_nstd_app_item::ID_CHECKLISTBOX_UNITS = wxNewId();
const long add_nstd_app_item::ID_BUTTON1 = wxNewId();
const long add_nstd_app_item::ID_BUTTON2 = wxNewId();
const long add_nstd_app_item::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(add_nstd_app_item,wxDialog)
	//(*EventTable(add_nstd_app_item)
	//*)
END_EVENT_TABLE()

add_nstd_app_item::add_nstd_app_item(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(add_nstd_app_item)
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	FlexGridSizer1 = new wxFlexGridSizer(11, 2, 0, 0);
	FlexGridSizer1->AddGrowableCol(1);
	FlexGridSizer1->AddGrowableRow(1);
	FlexGridSizer1->AddGrowableRow(3);
	FlexGridSizer1->AddGrowableRow(5);
	FlexGridSizer1->AddGrowableRow(7);
	FlexGridSizer1->AddGrowableRow(9);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("非标申请编号"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_nstd_app_index_id = new wxTextCtrl(this, ID_TEXTCTRL_INDEX, wxEmptyString, wxDefaultPosition, wxSize(150,21), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_INDEX"));
	FlexGridSizer1->Add(tc_nstd_app_index_id, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND, 0);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND, 0);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Item No."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_item_no = new wxTextCtrl(this, ID_TEXTCTRL_ITEM_NO, wxEmptyString, wxDefaultPosition, wxSize(150,21), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_ITEM_NO"));
	FlexGridSizer1->Add(tc_item_no, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND, 0);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND, 0);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("分类"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	choice_catalog = new wxChoice(this, ID_CHOICE_CATALOG, wxDefaultPosition, wxSize(150,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_CATALOG"));
	choice_catalog->Append(_("E"));
	choice_catalog->Append(_("M"));
	FlexGridSizer1->Add(choice_catalog, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND, 0);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND, 0);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("非标类别"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer1->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	combo_nstd_catalog = new wxComboBox(this, ID_COMBOBOX_NSTD_CATALOG, wxEmptyString, wxDefaultPosition, wxSize(150,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_NSTD_CATALOG"));
	FlexGridSizer1->Add(combo_nstd_catalog, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND, 0);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND, 0);
	button_nstd_reason = new wxButton(this, ID_BUTTON_NSTD_REASON, _("非标原因..."), wxDefaultPosition, wxSize(66,23), wxBU_LEFT|wxNO_BORDER|wxTAB_TRAVERSAL, wxDefaultValidator, _T("ID_BUTTON_NSTD_REASON"));
	FlexGridSizer1->Add(button_nstd_reason, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_nstd_desc = new wxTextCtrl(this, ID_TEXTCTRL_NSTD_DESC, wxEmptyString, wxDefaultPosition, wxSize(150,42), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL_NSTD_DESC"));
	FlexGridSizer1->Add(tc_nstd_desc, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND, 0);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND, 0);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("状态"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer1->Add(StaticText7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_status = new wxTextCtrl(this, ID_TEXTCTRL_STATUS, _("CRTD"), wxDefaultPosition, wxSize(150,21), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_STATUS"));
	FlexGridSizer1->Add(tc_status, 1, wxALL|wxEXPAND, 5);
	BoxSizer2->Add(FlexGridSizer1, 1, wxALL|wxEXPAND, 0);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("相关梯清单"));
	clb_units = new wxCheckListBox(this, ID_CHECKLISTBOX_UNITS, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHECKLISTBOX_UNITS"));
	StaticBoxSizer1->Add(clb_units, 1, wxALL|wxEXPAND, 0);
	BoxSizer2->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(BoxSizer2, 6, wxALL|wxEXPAND, 0);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("确定"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer4->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("取消"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer4->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button3 = new wxButton(this, ID_BUTTON3, _("全选/取消全选"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer4->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_CHOICE_CATALOG,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&add_nstd_app_item::Onchoice_catalogSelect);
	Connect(ID_BUTTON_NSTD_REASON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&add_nstd_app_item::Onbutton_nstd_reasonClick);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&add_nstd_app_item::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&add_nstd_app_item::OnButton2Click);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&add_nstd_app_item::OnButton3Click);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&add_nstd_app_item::OnInit);
	//*)

}

add_nstd_app_item::~add_nstd_app_item()
{
	//(*Destroy(add_nstd_app_item)
	//*)
}


void add_nstd_app_item::OnButton2Click(wxCommandEvent& event)
{
    EndDialog(wxID_CANCEL);
}

void add_nstd_app_item::OnButton1Click(wxCommandEvent& event)
{
    m_catalog = choice_catalog->GetString(choice_catalog->GetSelection());
    m_nstd_catalog = combo_nstd_catalog->GetValue();
    m_nstd_desc = tc_nstd_desc->GetValue();
    m_index = tc_nstd_app_index_id->GetValue();
    m_item_no = tc_item_no->GetValue();
    m_status = tc_status->GetValue();

    if(m_catalog.IsEmpty() || m_nstd_catalog.IsEmpty())
    {
         if(wxMessageBox(_("请务必填写分类和非标!"),_("信息"),wxOK)==wxOK)
            return;
    }

    wxArrayInt array_icheck;
    wxString str;
    int i_count = clb_units->GetCheckedItems(array_icheck);
    if(i_count==0)
    {
        if(wxMessageBox(_("请务必选择关联梯号!"),_("信息"),wxOK)==wxOK)
            return;
    }

    m_array_sel.Clear();

    for(int i =0;i<i_count;i++)
    {
       str = clb_units->GetString(array_icheck.Item(i));
       m_array_sel.Add(str);
    }
    EndDialog(wxID_OK);
}

void add_nstd_app_item::init_checklistbox(wxArrayString &array_str, bool b_sel)
{
    clb_units->Append(array_str);

    if(b_sel)
    {
        int i_count = m_array_sel.GetCount();
        int i_row = array_str.GetCount();

        for(int i=0; i<i_count; i++)
        {
            for(int j=0; j<i_row; j++)
            {
                if(array_str.Item(j)==m_array_sel.Item(i))
                    clb_units->Check(j,true);

            }
        }
    }


}

void add_nstd_app_item::Onchoice_catalogSelect(wxCommandEvent& event)
{
    int i_sel = event.GetSelection();

    m_catalog = choice_catalog->GetString(i_sel);

    init_combobox(m_catalog);
}

void add_nstd_app_item::OnInit(wxInitDialogEvent& event)
{
}

void add_nstd_app_item::OnButton3Click(wxCommandEvent& event)
{
    int i_count = clb_units->GetCount();

    bool b_check = !clb_units->IsChecked(0);

    for(int i=0;i<i_count; i++)
    {
       clb_units->Check(i,b_check);
    }
}


void add_nstd_app_item::init_catalog_choice(wxString str)
{
    choice_catalog->Clear();
    if(str.Right(1)== wxT("1"))
    {
        choice_catalog->Append(wxT("E"));
    }

    if(str.Left(1)==wxT("1") || str.Mid(1,1) == wxT("1"))
    {
        choice_catalog->Append(wxT("M"));
    }

}

void add_nstd_app_item::enable_control(bool b_edit)
{
    choice_catalog->Enable(b_edit);
    combo_nstd_catalog->Enable(b_edit);
    tc_nstd_desc->Enable(b_edit);
    tc_status->Enable(b_edit);
    clb_units->Enable(b_edit);
    Button3->Show(b_edit);
    Button1->Show(b_edit);
}

void add_nstd_app_item::Onbutton_nstd_reasonClick(wxCommandEvent& event)
{
    wxString str_catalog = combo_nstd_catalog->GetValue();

    int l_length=str_catalog.Length();

    int i_pos = str_catalog.Find(wxT("|"));

    if(i_pos>=0)
    {
        str_catalog = str_catalog.Right(l_length-i_pos-1);
    }

    wxString str_sql = wxT("Select DISTINCT nstd_reason from extra_non_app_std where nstd_catalog ='")+str_catalog+wxT("';");
    wxPostgreSQLresult * _res=wxGetApp().app_sql_select(str_sql);

     if(_res->Status()!= PGRES_TUPLES_OK)
     {
        _res->Clear();
        return;
     }

     int i_count = _res->GetRowsNumber();
     wxString str_temp;
     wxArrayString array_str;

     if(i_count >0)
     {
        _res->MoveFirst();

        for(int i=0;i<i_count;i++)
        {
           str_temp = _res->GetVal(wxT("nstd_reason"));
           array_str.Add(str_temp);

           _res->MoveNext();
        }
     }
     _res->Clear();

     nstd_reason_list dlg;

     if(!array_str.IsEmpty())
        dlg.init_checklistbox(array_str);

     if(dlg.ShowModal()==wxID_CANCEL)
        return;

     str_temp = tc_nstd_desc->GetValue().Trim();

     if(dlg.m_reason.IsEmpty())
        return;

     if(str_temp.Right(1)==wxT(";")|| str_temp.IsEmpty())
         tc_nstd_desc->SetValue(str_temp+dlg.m_reason);
     else tc_nstd_desc->SetValue(str_temp+wxT(";")+dlg.m_reason);

}

void add_nstd_app_item::init_combobox(wxString str)
{
    pugi::xml_document ldoc;
    pugi::xml_node lnode,litem;
    pugi::xml_parse_result result;
    combo_nstd_catalog->Clear();

    result = ldoc.load_file("para.xml");
    wxString str_item;

    if(result)
    {
        if(str==wxT("E"))
            lnode = ldoc.child("electric");

        if(str == wxT("M"))
        {
            append_sub_list(str);
            return;
        }

        for(litem = lnode.first_child(); litem; litem = litem.next_sibling())
        {
            str_item = wxString(litem.text().as_string());
            combo_nstd_catalog->Append(str_item);
        }
    }

}

void add_nstd_app_item::append_sub_list(wxString str)
{
    wxString str_sql = wxT("Select DISTINCT concat(box_id, '|', nstd_catalog) as catalog, box_id from extra_non_app_std where type ='")+str+wxT("' order by box_id ASC;");
    wxPostgreSQLresult * _res=wxGetApp().app_sql_select(str_sql);

     if(_res->Status()!= PGRES_TUPLES_OK)
     {
        _res->Clear();
        return;
     }

     int i_count = _res->GetRowsNumber();
     wxString str_temp;

     if(i_count >0)
     {
        _res->MoveFirst();

        for(int i=0;i<i_count;i++)
        {
           str_temp = _res->GetVal(wxT("catalog"));
           combo_nstd_catalog->Append(str_temp);

           _res->MoveNext();
        }
     }

     _res->Clear();
}
