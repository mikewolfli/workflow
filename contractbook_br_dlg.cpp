#include "contractbook_br_dlg.h"
#include "wfApp.h"
#include "wf_stdafx.h"

//(*InternalHeaders(contractbook_br_dlg)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(contractbook_br_dlg)
const long contractbook_br_dlg::ID_LISTVIEW_CONTRACTBOOK_BR = wxNewId();
const long contractbook_br_dlg::ID_BUTTON1 = wxNewId();
const long contractbook_br_dlg::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(contractbook_br_dlg,wxDialog)
	//(*EventTable(contractbook_br_dlg)
	//*)
END_EVENT_TABLE()

contractbook_br_dlg::contractbook_br_dlg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(contractbook_br_dlg)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("借阅表"));
	lv_br = new wxListView(this, ID_LISTVIEW_CONTRACTBOOK_BR, wxDefaultPosition, wxSize(790,354), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTVIEW_CONTRACTBOOK_BR"));
	StaticBoxSizer1->Add(lv_br, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(StaticBoxSizer1, 5, wxALL|wxEXPAND, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button_Change = new wxButton(this, ID_BUTTON1, _("转借"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button_Change, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("取消"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&contractbook_br_dlg::OnButton_ChangeClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&contractbook_br_dlg::OnButton2Click);
	//*)

	m_mode =0;
	init_list_header();


}

contractbook_br_dlg::~contractbook_br_dlg()
{
	//(*Destroy(contractbook_br_dlg)
	//*)
}


void contractbook_br_dlg::OnButton_ChangeClick(wxCommandEvent& event)
{

    int i_count=lv_br->GetSelectedItemCount();

    if(i_count==0)
    {
        wxLogMessage("请先选择需转借的项次!");
        return;
    }

    wxTextEntryDialog tdlg(this, _("请输入8位ID或姓名(支持模糊查询)"), _("转借给谁?"), wxT(""), wxTextEntryDialogStyle, wxDefaultPosition);
    tdlg.SetTextValidator(wxFILTER_EMPTY);
    if (tdlg.ShowModal() == wxID_CANCEL)
    {
        return;
    }

    wxString s_sql, str;

    str = tdlg.GetValue();

    s_sql = wxT("select concat(employee_id,'-',name) as name from s_employee where employee_id like '%")+str+wxT("%' or name like '%")+str+wxT("%' order by employee_id asc;");
    wxPostgreSQLresult *res = wxGetApp().app_sql_select(s_sql);
    if(res->Status()!= PGRES_TUPLES_OK)
    {
        res->Clear();
        return;
    }

    wxArrayString a_member;

    i_count = res->GetRowsNumber();
    if(i_count==0)
    {
        res->Clear();
        return;
    }

    for(int i=0;i<i_count;i++)
    {
         str = res->GetVal(wxT("name"));
         a_member.Add(str);
         res->MoveNext();
    }
    res->Clear();

    wxSingleChoiceDialog dlg(this, _("请选择借阅人"),_("人员选择"), a_member);

    a_member.Clear();
    wxString s_name;

    if(dlg.ShowModal()==wxID_OK)
    {
        s_name=dlg.GetStringSelection();
    }
    else
    {
        return;
    }
    long i_index;
    wxString s_cid;
    i_index = lv_br->GetFirstSelected();
    do
    {
        s_cid = lv_br->GetItemText(i_index, 0);
        if(wxGetApp().contractbook_lender_change(s_cid, s_name)==1)
        {
             wxLogMessage(lv_br->GetItemText(i_index, 1)+"转借成功");
        }

        i_index = lv_br->GetNextSelected(i_index);
    }
    while(i_index!=-1);

    refresh_list(gr_para.login_user, 2);

}

void contractbook_br_dlg::OnButton2Click(wxCommandEvent& event)
{
    EndDialog(wxID_CANCEL);
}

void contractbook_br_dlg::init_list_header()
{
    wxListItem itemCol;
    itemCol.SetText(_("2d-code"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(0);
    lv_br->InsertColumn(0, itemCol);
    itemCol.SetText(_("合同号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_br->InsertColumn(1, itemCol);
    itemCol.SetText(_("文本序号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(60);
    lv_br->InsertColumn(2, itemCol);
    itemCol.SetText(_("项目名称"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(200);
    lv_br->InsertColumn(3, itemCol);
    itemCol.SetText(_("项目号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_br->InsertColumn(4, itemCol);
    itemCol.SetText(_("状态"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_br->InsertColumn(5, itemCol);
    itemCol.SetText(_("出借人-ID"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(0);
    lv_br->InsertColumn(6, itemCol);
    itemCol.SetText(_("出借人"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(80);
    lv_br->InsertColumn(7, itemCol);
    itemCol.SetText(_("借阅人-id"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(0);
    lv_br->InsertColumn(8, itemCol);
    itemCol.SetText(_("借阅人"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(80);
    lv_br->InsertColumn(9, itemCol);
    itemCol.SetText(_("借阅时间"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(150);
    lv_br->InsertColumn(10, itemCol);
    itemCol.SetText(_("归还人-id"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(0);
    lv_br->InsertColumn(11, itemCol);
    itemCol.SetText(_("归还人"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(80);
    lv_br->InsertColumn(12, itemCol);
    itemCol.SetText(_("归还日期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(150);
    lv_br->InsertColumn(13, itemCol);
    itemCol.SetText(_("备注"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_br->InsertColumn(14, itemCol);
}

void contractbook_br_dlg::refresh_gui()
{
    if(m_mode==0)
          Button_Change->Show(false);
    else
        Button_Change->Show(true);
}

void contractbook_br_dlg::refresh_list(wxString s_case, int i_mode)
{
    lv_br->DeleteAllItems();

    wxString s_sql;

    switch(i_mode)
    {
    case 0:
        s_sql=wxT("select contract_doc_id, status, br_status, item_no,b_user,(select name from s_employee where employee_id=b_user) as b_user_name, b_date,\
             r_user,(select name from s_employee where employee_id=r_user) as r_user_name, r_date, s_user, (select name from s_employee where employee_id=s_user) as s_user_name,\
             remarks,contract_id, project_name,project_id from v_contract_br_log where project_id='")+s_case+wxT("' and status>=0 order by item_no asc;");
        break;
    case 1:
        s_sql=wxT("select contract_doc_id, status, br_status, item_no,b_user,(select name from s_employee where employee_id=b_user) as b_user_name, b_date,\
             r_user,(select name from s_employee where employee_id=r_user) as r_user_name, r_date, s_user, (select name from s_employee where employee_id=s_user) as s_user_name,\
             remarks,contract_id, project_name,project_id from v_contract_br_log where (project_id like '%")+s_case+wxT("%' or contract_id like '%")+s_case+wxT("%') and status>=0 order by project_id, item_no asc;");
        break;
    case 2:
        s_sql=wxT("select contract_doc_id, status, br_status, item_no,b_user,(select name from s_employee where employee_id=b_user) as b_user_name, b_date,\
             r_user,(select name from s_employee where employee_id=r_user) as r_user_name, r_date, s_user, (select name from s_employee where employee_id=s_user) as s_user_name,\
             remarks,contract_id, project_name,project_id from v_contract_br_log where b_user='")+s_case+wxT("' and status=2 order by project_id, item_no asc;");
        break;
    default:
        return;

    }

    wxPostgreSQLresult * res= wxGetApp().app_sql_select(s_sql);

    if (res->Status() != PGRES_TUPLES_OK)
    {
        res->Clear();
        return;
    }

    int i_count = res->GetRowsNumber();

    for(int i=0;i<i_count;i++)
    {
          wxString str = res->GetVal(wxT("contract_doc_id"));
          long tmp = lv_br->InsertItem(i, str );
          lv_br->SetItemData(tmp, i);

          str = res->GetVal(wxT("contract_id"));
          lv_br->SetItem(i,1, str);

          str = res->GetVal(wxT("item_no"));
          lv_br->SetItem(i,2,str);

          str = res->GetVal(wxT("project_name"));
          lv_br->SetItem(i,3, str);

          str = res->GetVal(wxT("project_id"));
          lv_br->SetItem(i, 4, str);

          int i_status = res->GetInt(wxT("status"));
          str=ct_book_status_to_str(i_status);
          lv_br->SetItem(i, 5, str);

          if(i_status==2)
                str= res->GetVal(wxT("s_user"));
          else
                str.Empty();

          if(str.IsEmpty()&&i_status==0)
            str="合同创建";
          else if(i_status==1&&str.IsEmpty())
            str="资料室";
          else if(i_status==3)
          {
             str="档案袋";
          }
          lv_br->SetItem(i, 6, str);

          if (i_status==2)
          {
           str = res->GetVal(wxT("s_user_name"));
          lv_br->SetItem(i, 7, str);

          str = res->GetVal(wxT("b_user"));
          lv_br->SetItem(i, 8, str);

          str = res->GetVal(wxT("b_user_name"));
          lv_br->SetItem(i, 9, str);

          str =  DateToAnsiStr(res->GetDateTime(wxT("b_date")));
          lv_br->SetItem(i, 10, str);

          str = res->GetVal(wxT("r_user"));
          lv_br->SetItem(i, 11, str);

          str = res->GetVal(wxT("r_user_name"));
          lv_br->SetItem(i, 12, str);

          str = DateToAnsiStr(res->GetDateTime(wxT("r_date")));
          lv_br->SetItem(i, 13, str);

          str = res->GetVal(wxT("remarks"));
          lv_br->SetItem(i, 14, str);
          }

          res->MoveNext();
    }

    res->Clear();

}
