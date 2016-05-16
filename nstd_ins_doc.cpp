#include "nstd_ins_doc.h"
#include "wfApp.h"

//(*InternalHeaders(nstd_ins_doc)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(nstd_ins_doc)
const long nstd_ins_doc::ID_CHECKLISTBOX_UNIT_LIST = wxNewId();
const long nstd_ins_doc::ID_BUTTON_SAVE = wxNewId();
const long nstd_ins_doc::ID_BUTTON_ALL = wxNewId();
const long nstd_ins_doc::ID_BUTTON_CANCEL = wxNewId();
//*)

BEGIN_EVENT_TABLE(nstd_ins_doc,wxDialog)
	//(*EventTable(nstd_ins_doc)
	//*)
END_EVENT_TABLE()

nstd_ins_doc::nstd_ins_doc(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(nstd_ins_doc)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, _("非标安装文档项目设定"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("非标项目列表"));
	clb_unit_list = new wxCheckListBox(this, ID_CHECKLISTBOX_UNIT_LIST, wxDefaultPosition, wxDefaultSize, 0, 0, wxLB_MULTIPLE|wxLB_HSCROLL, wxDefaultValidator, _T("ID_CHECKLISTBOX_UNIT_LIST"));
	StaticBoxSizer1->Add(clb_unit_list, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer1->Add(StaticBoxSizer1, 5, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button_Save = new wxButton(this, ID_BUTTON_SAVE, _("非标安装文档设定"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_SAVE"));
	BoxSizer2->Add(Button_Save, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_SELECT_ALL = new wxButton(this, ID_BUTTON_ALL, _("全选/取消选择"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_ALL"));
	BoxSizer2->Add(Button_SELECT_ALL, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Cancel = new wxButton(this, ID_BUTTON_CANCEL, _("取消"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CANCEL"));
	BoxSizer2->Add(Button_Cancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_CHECKLISTBOX_UNIT_LIST,wxEVT_COMMAND_CHECKLISTBOX_TOGGLED,(wxObjectEventFunction)&nstd_ins_doc::Onclb_unit_listToggled);
	Connect(ID_BUTTON_SAVE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_ins_doc::OnButton_SaveClick);
	Connect(ID_BUTTON_ALL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_ins_doc::OnButton_SELECT_ALLClick);
	Connect(ID_BUTTON_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_ins_doc::OnButton_CancelClick);
	//*)

	b_change=false;
}

nstd_ins_doc::~nstd_ins_doc()
{
	//(*Destroy(nstd_ins_doc)
	//*)
	m_status.Clear();
}


void nstd_ins_doc::OnButton_SaveClick(wxCommandEvent& event)
{
    if(b_change)
    {
        save_nstd_ins_doc_status();
    }
    EndDialog(wxID_OK);
}

void nstd_ins_doc::OnButton_SELECT_ALLClick(wxCommandEvent& event)
{
    int i_count = clb_unit_list->GetCount();

    if(i_count ==0)
        return;

    bool b_check = clb_unit_list->IsChecked(0);

    for(int i=0;i<i_count;i++)
    {
        clb_unit_list->Check(i, !b_check);
    }

    b_change = true;
}

void nstd_ins_doc::OnButton_CancelClick(wxCommandEvent& event)
{
    if(b_change)
    {
        if(wxMessageBox(_("修改未保存，是否保存后退出!"),_("修改确认"),wxYES_NO)==wxYES)
            save_nstd_ins_doc_status();
    }
    EndDialog(wxID_CANCEL);
}


bool nstd_ins_doc::init_units_list(wxArrayString &array_units)
{
     clb_unit_list->Append(array_units);

     int i_count = array_units.GetCount();

     wxString str_sql = wxT("select wbs_no, has_nonstd_inst_info from s_unit_info where ");

     for(int i=0;i<i_count;i++)
     {
         if(i == i_count-1)
            str_sql = str_sql+wxT(" wbs_no = '")+array_units.Item(i)+wxT("' ;");
         else
            str_sql = str_sql+wxT(" wbs_no = '")+array_units.Item(i)+wxT("' or ");

     }

     wxPostgreSQLresult* _res;
     _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return false;
    }

    i_count = _res->GetRowsNumber();

    bool b_check;
    wxString str;
    int i_status;

    for(int j=0;j<i_count;j++)
    {
         str=_res->GetVal(wxT("wbs_no"));

         b_check = _res->GetBool(wxT("has_nonstd_inst_info"));
         if(b_check)
            i_status = 1;
         else
            i_status = 0;

         m_status.Add(i_status);
         int i_item = clb_unit_list->FindString(str);
         clb_unit_list->Check(i_item, b_check);

         _res->MoveNext();
    }

    _res->Clear();

    b_change = false;

    return false;

}

void nstd_ins_doc::Onclb_unit_listToggled(wxCommandEvent& event)
{
     int i_index = event.GetInt();
     bool b_status = clb_unit_list->IsChecked(i_index);

     int i_status;

     if(b_status)
        i_status = 1;
     else
        i_status =0;

     if(i_status != m_status.Item(i_index))
        b_change = true;
}


void nstd_ins_doc::save_nstd_ins_doc_status()
{
    int i_count = clb_unit_list->GetCount();

    int i_status;

    bool b_check = false;
    wxString str_wbs;

    for(int i=0;i<i_count;i++)
    {
         b_check = clb_unit_list->IsChecked(i);
         str_wbs = clb_unit_list->GetString(i);

         if(b_check)
            i_status =1;
         else
            i_status =0;

        if(i_status != m_status.Item(i))
        {
           if(save_unit_ins_doc(str_wbs, b_check))
               wxLogMessage(str_wbs+_("非标部件安装文件设置成功!"));
        }
    }

}

bool nstd_ins_doc::save_unit_ins_doc(wxString s_wbs, bool b_status)
{
    wxString str_sql = wxT("UPDATE s_unit_info SET modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("', has_nonstd_inst_info=")+BoolToStr(b_status)+
                       wxT(" where wbs_no ='")+s_wbs+wxT("';");

    return wxGetApp().app_sql_update(str_sql);

}
