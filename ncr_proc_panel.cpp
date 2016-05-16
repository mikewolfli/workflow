#include "ncr_proc_panel.h"
#include "ncr_proc_dlg.h"
#include "wfApp.h"
#include <wx/textdlg.h>
#include <wx/choicdlg.h>

//(*InternalHeaders(ncr_proc_panel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(ncr_proc_panel)
const long ncr_proc_panel::ID_LISTVIEW_NCR_LIST = wxNewId();
const long ncr_proc_panel::ID_CHOICE_FILTER1 = wxNewId();
const long ncr_proc_panel::ID_CHOICE_FILTER2 = wxNewId();
const long ncr_proc_panel::ID_BUTTON1 = wxNewId();
const long ncr_proc_panel::ID_BUTTON_CREATE = wxNewId();
const long ncr_proc_panel::ID_BUTTON_SUBMIT = wxNewId();
const long ncr_proc_panel::ID_BUTTON_CHANGE = wxNewId();
const long ncr_proc_panel::ID_BUTTON_FETCH = wxNewId();
const long ncr_proc_panel::ID_BUTTON_FEEDBACK = wxNewId();
const long ncr_proc_panel::ID_BUTTON_CLOSE = wxNewId();
const long ncr_proc_panel::ID_BUTTON_DEL = wxNewId();
const long ncr_proc_panel::ID_BUTTON_ROLLBACK = wxNewId();
//*)

BEGIN_EVENT_TABLE(ncr_proc_panel,wxPanel)
	//(*EventTable(ncr_proc_panel)
	//*)
END_EVENT_TABLE()

ncr_proc_panel::ncr_proc_panel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ncr_proc_panel)
	wxStaticBoxSizer* StaticBoxSizer2;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("NCR清单"));
	lv_ncrs = new wxListView(this, ID_LISTVIEW_NCR_LIST, wxDefaultPosition, wxSize(800,800), wxLC_REPORT|wxLC_SINGLE_SEL, wxDefaultValidator, _T("ID_LISTVIEW_NCR_LIST"));
	StaticBoxSizer1->Add(lv_ncrs, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(StaticBoxSizer1, 8, wxALL|wxEXPAND, 0);
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, this, _("filter"));
	choice_filter1 = new wxChoice(this, ID_CHOICE_FILTER1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_FILTER1"));
	choice_filter1->Append(_("活动状态NCR"));
	choice_filter1->Append(_("已领取NCR"));
	choice_filter1->Append(_("未领取NCR"));
	choice_filter1->Append(_("已回复NCR"));
	choice_filter1->Append(_("已关闭NCR"));
	StaticBoxSizer2->Add(choice_filter1, 1, wxALL|wxEXPAND, 5);
	choice_filter2 = new wxChoice(this, ID_CHOICE_FILTER2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_FILTER2"));
	choice_filter2->Append(_("ALL"));
	choice_filter2->Append(_("本人领取的NCR"));
	choice_filter2->Append(_("本组负责的NCR"));
	choice_filter2->Append(_("按组筛选"));
	choice_filter2->Append(_("按负责人筛选"));
	StaticBoxSizer2->Add(choice_filter2, 1, wxALL|wxEXPAND, 5);
	BoxSizer2->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 0);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("刷新列表"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(Button1, 1, wxALL|wxEXPAND, 5);
	Button_create = new wxButton(this, ID_BUTTON_CREATE, _("创建NCR"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CREATE"));
	BoxSizer3->Add(Button_create, 1, wxALL|wxEXPAND, 5);
	Button_submit = new wxButton(this, ID_BUTTON_SUBMIT, _("发布NCR"), wxDefaultPosition, wxSize(108,32), 0, wxDefaultValidator, _T("ID_BUTTON_SUBMIT"));
	BoxSizer3->Add(Button_submit, 1, wxALL|wxEXPAND, 5);
	Button_change = new wxButton(this, ID_BUTTON_CHANGE, _("变更责任组"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CHANGE"));
	BoxSizer3->Add(Button_change, 1, wxALL|wxEXPAND, 5);
	Button_fetch = new wxButton(this, ID_BUTTON_FETCH, _("领取NCR"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_FETCH"));
	BoxSizer3->Add(Button_fetch, 1, wxALL|wxEXPAND, 5);
	Button_feedback = new wxButton(this, ID_BUTTON_FEEDBACK, _("NCR回复"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_FEEDBACK"));
	BoxSizer3->Add(Button_feedback, 1, wxALL|wxEXPAND, 5);
	Button_close = new wxButton(this, ID_BUTTON_CLOSE, _("关闭NCR"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CLOSE"));
	BoxSizer3->Add(Button_close, 1, wxALL|wxEXPAND, 5);
	Button_del = new wxButton(this, ID_BUTTON_DEL, _("删除NCR"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_DEL"));
	BoxSizer3->Add(Button_del, 1, wxALL|wxEXPAND, 5);
	Button_ROLL_back = new wxButton(this, ID_BUTTON_ROLLBACK, _("回退NCR"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_ROLLBACK"));
	Button_ROLL_back->SetDefault();
	BoxSizer3->Add(Button_ROLL_back, 1, wxALL|wxEXPAND, 5);
	BoxSizer2->Add(BoxSizer3, 8, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_LISTVIEW_NCR_LIST,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&ncr_proc_panel::Onlv_ncrsItemActivated);
	Connect(ID_CHOICE_FILTER1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&ncr_proc_panel::Onchoice_filter1Select);
	Connect(ID_CHOICE_FILTER2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&ncr_proc_panel::Onchoice_filter2Select);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ncr_proc_panel::OnButton1Click);
	Connect(ID_BUTTON_CREATE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ncr_proc_panel::OnButton_createClick);
	Connect(ID_BUTTON_SUBMIT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ncr_proc_panel::OnButton_submitClick);
	Connect(ID_BUTTON_CHANGE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ncr_proc_panel::OnButton_changeClick);
	Connect(ID_BUTTON_FETCH,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ncr_proc_panel::OnButton_fetchClick);
	Connect(ID_BUTTON_FEEDBACK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ncr_proc_panel::OnButton_feedbackClick);
	Connect(ID_BUTTON_CLOSE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ncr_proc_panel::OnButton_closeClick);
	Connect(ID_BUTTON_DEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ncr_proc_panel::OnButton_delClick);
	Connect(ID_BUTTON_ROLLBACK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ncr_proc_panel::OnButton_ROLL_backClick);
	//*)

	init_list_header();
	choice_filter1->SetSelection(0);
	choice_filter2->SetSelection(0);
	show_control();
	Layout();


	m_filter1 = wxT(" issue_status >=0 and issue_status<4 ");
	m_filter2 = wxEmptyString;

	refresh_list();
}

ncr_proc_panel::~ncr_proc_panel()
{
	//(*Destroy(ncr_proc_panel)
	//*)
}

void ncr_proc_panel::init_list_header()
{
    wxListItem itemCol;


    itemCol.SetText(_("id"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(0);
    lv_ncrs->InsertColumn(0, itemCol);
    itemCol.SetText(_("NCR单号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(0);
    lv_ncrs->InsertColumn(1, itemCol);
    itemCol.SetText(_("相关WBS NO."));
    itemCol.SetImage(-1);
    itemCol.SetWidth(0);
    lv_ncrs->InsertColumn(2, itemCol);
    itemCol.SetText(_("相关项目信息"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_ncrs->InsertColumn(3, itemCol);
    itemCol.SetText(_("梯号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_ncrs->InsertColumn(4, itemCol);
    itemCol.SetText(_("涉梯数量"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_ncrs->InsertColumn(5, itemCol);
    itemCol.SetText(_("文件索引"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(200);
    lv_ncrs->InsertColumn(6, itemCol);
    itemCol.SetText(_("来源部门"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_ncrs->InsertColumn(7, itemCol);
    itemCol.SetText(_("问题概叙"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_ncrs->InsertColumn(8, itemCol);
    itemCol.SetText(_("问题描叙"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(200);
    lv_ncrs->InsertColumn(9, itemCol);
    itemCol.SetText(_("问题状态"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_ncrs->InsertColumn(10, itemCol);
    itemCol.SetText(_("NCR反馈组ID"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(0);
    lv_ncrs->InsertColumn(11, itemCol);
    itemCol.SetText(_("NCR反馈组"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_ncrs->InsertColumn(12, itemCol);
    itemCol.SetText(_("反馈人ID"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(0);
    lv_ncrs->InsertColumn(13, itemCol);
    itemCol.SetText(_("反馈人"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_ncrs->InsertColumn(14, itemCol);
    itemCol.SetText(_("领取日期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_ncrs->InsertColumn(15, itemCol);
    itemCol.SetText(_("发布人ID"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(0);
    lv_ncrs->InsertColumn(16, itemCol);
    itemCol.SetText(_("发布人"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_ncrs->InsertColumn(17, itemCol);
    itemCol.SetText(_("发布日期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_ncrs->InsertColumn(18, itemCol);
    itemCol.SetText(_("关联更改单"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_ncrs->InsertColumn(19, itemCol);
    itemCol.SetText(_("反馈内容"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(200);
    lv_ncrs->InsertColumn(20, itemCol);
    itemCol.SetText(_("反馈日期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_ncrs->InsertColumn(21, itemCol);
    itemCol.SetText(_("问题分析"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_ncrs->InsertColumn(22, itemCol);
    itemCol.SetText(_("问题责任人"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_ncrs->InsertColumn(23, itemCol);

}

void ncr_proc_panel::show_control()
{
    if(gr_para.login_role!= wxT("ADMIN"))
    {
        Button_create->Show(false);
        Button_close->Show(false);
        Button_del->Show(false);
        Button_submit->Show(false);
    }else
    {
        Button_feedback->Show(false);
        Button_fetch->Show(false);

        return;
    }

    wxString s_sql = wxT(" SELECT * from s_group_member where is_ncr=true and status=true and employee_id='")+gr_para.login_user+wxT("';");
    wxPostgreSQLresult *_res= wxGetApp().app_sql_select(s_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        Button_change->Show(false);
        Button_close->Show(false);
        Button_create->Show(false);
        Button_del->Show(false);
        Button_feedback->Show(false);
        Button_fetch->Show(false);
        Button_submit->Show(false);
        return;

    }

    int i_count=_res->GetRowsNumber();

    if(i_count==0)
    {
        Button_change->Show(false);
        Button_close->Show(false);
        Button_create->Show(false);
        Button_del->Show(false);
        Button_feedback->Show(false);
        Button_fetch->Show(false);
        Button_submit->Show(false);
        _res->Clear();
        return;
    }

    for(int i=0; i<i_count; i++)
    {

        if( _res->GetBool(wxT("is_ncr")))
        {
            _res->Clear();

            return;
        }
        _res->MoveNext();
    }

    _res->Clear();


    Button_change->Show(false);
    Button_close->Show(false);
    Button_create->Show(false);
    Button_del->Show(false);
    Button_feedback->Show(false);
    Button_fetch->Show(false);
    Button_submit->Show(false);


}

int ncr_proc_panel::get_status(wxString s_id)
{
    wxString s_sql = wxT("select issue_status from  s_ncr_data where id='")+s_id+wxT("';");
    wxPostgreSQLresult *_res= wxGetApp().app_sql_select(s_sql);
    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return -1;
    }

    int i_count=_res->GetRowsNumber();

    if(i_count==0)
    {
        _res->Clear();
        return 0;
    }

    int i_status = _res->GetInt(wxT("issue_status"));

    return i_status;

}

void ncr_proc_panel::refresh_list()
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }

    if(!wxGetApp().conn->IsAlive())
    {
        wxLogMessage(_("系统连接已断开,请重新连接!"));
        wxGetApp().clear_login();
        return;
    }

    lv_ncrs->DeleteAllItems();

    wxString s_sql = wxT("SELECT id, ncr_id, rel_wbs, res_project,(select contract_id from s_project_info where project_id=res_project) as contract_id,(select project_name from s_project_info where project_id=res_project) as project_name, lift_no, file_index, from_dep, issue_desc, issue_head, issue_status, lift_qty, publish_by, publish_date, \
       res_by, fetch_date, res_bco, fb_content, fb_date, issue_res, issue_result, res_group, create_by, create_date, (select name from s_employee where employee_id=publish_by) as publisher,\
       (select name from s_employee where employee_id=res_by) as res_eng, (select  group_name from s_group where group_id=res_group) as group_name FROM s_ncr_data where ")+ m_filter1 +m_filter2+wxT(" order by publish_date asc;");

    wxPostgreSQLresult *_res=wxGetApp().app_sql_select(s_sql);


    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int i_count = _res->GetRowsNumber();

    wxString str;
    long tmp;

    for(int i=0;i<i_count;i++)
    {
        str= _res->GetVal(wxT("id"));
         tmp = lv_ncrs->InsertItem(i, str);

         str = _res->GetVal(wxT("ncr_id"));
        lv_ncrs->SetItem(tmp, 1, str);

        str = _res->GetVal(wxT("rel_wbs"));
        lv_ncrs->SetItem(tmp, 2, str);

        str =_res->GetVal(wxT("contract_id"))+wxT(" ")+_res->GetVal(wxT("project_name"))+wxT("-")+_res->GetVal(wxT("res_project"));
        lv_ncrs->SetItem(tmp, 3, str);

        str = _res->GetVal(wxT("lift_no"));
        lv_ncrs->SetItem(tmp, 4, str);

        str = NumToStr(_res->GetInt(wxT("lift_qty")));
        lv_ncrs->SetItem(tmp, 5, str);

        str = _res->GetVal(wxT("file_index"));
        lv_ncrs->SetItem(tmp, 6, str);

        str = _res->GetVal(wxT("from_dep"));
        lv_ncrs->SetItem(tmp, 7, str);

        str = _res->GetVal(wxT("issue_head"));
        lv_ncrs->SetItem(tmp, 8, str);

        str = _res->GetVal(wxT("issue_desc"));
        lv_ncrs->SetItem(tmp, 9, str);

        str = ncr_status_to_str(_res->GetInt(wxT("issue_status")));
        lv_ncrs->SetItem(tmp, 10, str);

        str = _res->GetVal(wxT("res_group"));
        lv_ncrs->SetItem(tmp, 11, str);

        str = _res->GetVal(wxT("group_name"));
        lv_ncrs->SetItem(tmp, 12, str);

        str = _res->GetVal(wxT("res_by"));
        lv_ncrs->SetItem(tmp, 13, str);

        str = _res->GetVal(wxT("res_eng"));
        lv_ncrs->SetItem(tmp, 14, str);

        str =DateToStrShort(_res->GetDateTime(wxT("fetch_date")));
        lv_ncrs->SetItem(tmp, 15, str);

        str = _res->GetVal(wxT("publish_by"));
        lv_ncrs->SetItem(tmp, 16, str);

        str = _res->GetVal(wxT("publisher"));
        lv_ncrs->SetItem(tmp, 17, str);

        str = DateToStrShort(_res->GetDateTime(wxT("publish_date")));
        lv_ncrs->SetItem(tmp, 18, str);

        str = _res->GetVal(wxT("res_bco"));
        lv_ncrs->SetItem(tmp, 19, str);

        str = _res->GetVal(wxT("fb_content"));
        lv_ncrs->SetItem(tmp, 20, str);

        str = DateToStrShort(_res->GetDateTime(wxT("fb_date")));
        lv_ncrs->SetItem(tmp, 21, str);

        str = _res->GetVal(wxT("issue_result"));
        lv_ncrs->SetItem(tmp, 22, str);

        str = _res->GetVal(wxT("issue_res"));
        lv_ncrs->SetItem(tmp, 23, str);

        _res->MoveNext();
    }

    _res->Clear();

}

void ncr_proc_panel::OnButton_createClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }

    if(!wxGetApp().conn->IsAlive())
    {
        wxLogMessage(_("系统连接已断开,请重新连接!"));
        wxGetApp().clear_login();
        return;
    }

   ncr_proc_dlg dlg(0);

   if(dlg.ShowModal()==wxID_CANCEL)
        return;

   refresh_list();

}

void ncr_proc_panel::OnButton_submitClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }

    if(!wxGetApp().conn->IsAlive())
    {
        wxLogMessage(_("系统连接已断开,请重新连接!"));
        wxGetApp().clear_login();
        return;
    }

    int i_sel = lv_ncrs->GetSelectedItemCount();

    if(i_sel==0)
        return;

    int i_item = lv_ncrs->GetFirstSelected();

   if(wxMessageBox(_("确认提交选中NCR?"),_("提交"),wxYES_NO)==wxNO)
         return;

    for(int i=0;i<i_sel;i++)
    {
        wxString s_id = lv_ncrs->GetItemText(i_item, 0);
        wxString s_ncr_id = lv_ncrs->GetItemText(i_item, 1);
       int i_status = get_status(s_id);

       if(i_status !=0)
       {
           wxLogMessage(wxT("NCR:")+s_ncr_id+_("已经提交，无需再次提交!"));
           continue;
       }

       if(change_item(i_item, 0))
       {
           wxLogMessage(wxT("NCR:")+s_ncr_id+_("提交完成 !"));
       }

       i_item = lv_ncrs->GetNextSelected(i_item);

    }

    refresh_list();

}

void ncr_proc_panel::OnButton_changeClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }

    if(!wxGetApp().conn->IsAlive())
    {
        wxLogMessage(_("系统连接已断开,请重新连接!"));
        wxGetApp().clear_login();
        return;
    }

    int i_sel = lv_ncrs->GetSelectedItemCount();

    if(i_sel==0)
        return;

    int i_item = lv_ncrs->GetFirstSelected();
    wxString s_content;
    wxArrayString a_group_id, a_group_name;

    if(!get_ncr_group(a_group_id,a_group_name))
        return;

    wxString s_group = lv_ncrs->GetItemText(i_item,12 );

    wxSingleChoiceDialog dlg(this, _("请确认变更所选NCR所属回复组!"),_("组选择"), a_group_name);
    int i_choice;

    wxString s_group_id;

    int i_init= a_group_name.Index(s_group);
    dlg.SetSelection(i_init);

    if(dlg.ShowModal()==wxID_OK)
    {
         i_choice=dlg.GetSelection();

        s_content = a_group_id.Item(i_choice)+wxT("-")+a_group_name.Item(i_choice);
    }else
       return;

    for(int i=0;i<i_sel;i++)
    {
        wxString s_id = lv_ncrs->GetItemText(i_item, 0);
        wxString s_ncr_id = lv_ncrs->GetItemText(i_item, 1);

        int i_status = get_status(s_id);

        if(i_status > 1 && i_status<0)
        {
            wxLogMessage("NCR :"+s_ncr_id+wxT("已经被工程师领取，无法变更组!"));
            continue;
        }
        wxString s_old = lv_ncrs->GetItemText(i_item, 11);
        s_group_id= a_group_id.Item(i_choice);

        if(s_old == s_group_id)
            continue;

        if(change_item(i_item, 2, s_content))
        {

             wxGetApp().change_log(wxT("s_ncr_data"),s_id,wxT("res_group"),s_old, s_group_id,"hand");
             wxLogMessage(_("NCR:")+s_ncr_id+_("变更组成功!"));
        }

        i_item = lv_ncrs->GetNextSelected(i_item);
    }
}

bool  ncr_proc_panel::get_ncr_group(wxArrayString &a_group_id, wxArrayString &a_group_name)
{
    wxString s_sql =wxT("select distinct group_id, group_name from v_group_member where is_ncr=true;");

    a_group_id.Clear();
    a_group_name.Clear();

    wxPostgreSQLresult *_res = wxGetApp().app_sql_select(s_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return false;
    }

    int i_count = _res->GetRowsNumber();

    wxString str;

    for(int i=0;i<i_count;i++)
    {
        str = _res->GetVal(wxT("group_id"));
        a_group_id.Add(str);

        str = _res->GetVal(wxT("group_name"));
        a_group_name.Add(str);

        _res->MoveNext();
    }

    _res->Clear();


}

bool ncr_proc_panel::change_item(long i_item,int i_mode, wxString s_content)//0 -发布， 1-领取， 2-变更工作组 3-回复NCR， 4-关闭NCR
{
    wxString s_sql,s_group_id, s_group_name;

    wxString s_id = lv_ncrs->GetItemText(i_item, 0);
    int i_pos,i_len;

    if(i_mode==2 && s_content.IsEmpty())
        return false;

    switch(i_mode)
    {
    case -1:
                 s_sql = wxT("UPDATE s_ncr_data SET issue_status=-1,  modify_by = '")+gr_para.login_user+wxT("',modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("' where id='")+s_id+wxT("';");
                 break;
    case  0:
         s_sql = wxT("UPDATE s_ncr_data SET issue_status=1, publish_by='")+gr_para.login_user+wxT("', publish_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_by = '")+gr_para.login_user+wxT("',modify_date='")+DateToAnsiStr(wxDateTime::Now())+
                 wxT("' where id='")+s_id+wxT("';");
                 break;
    case 1:
         s_sql = wxT("UPDATE s_ncr_data SET issue_status=2,res_by='")+gr_para.login_user+wxT("', fetch_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_by = '")+gr_para.login_user+wxT("',modify_date='")+DateToAnsiStr(wxDateTime::Now())+
                 wxT("' where id='")+s_id+wxT("';");
                 break;
    case 2:
        i_pos = s_content.Find(wxT("-"));
        i_len = s_content.Length();
        s_group_id = s_content.Left(i_pos);
        s_group_name = s_content.Right(i_len-i_pos-1);
        s_sql = wxT("UPDATE s_ncr_data set res_group='")+s_group_id +wxT("', modify_by = '")+gr_para.login_user+wxT("',modify_date='")+DateToAnsiStr(wxDateTime::Now())+
                 wxT("' where id='")+s_id+wxT("';");
       break;
    case 3:
  /*      wxTextEntryDialog dlg(this, _("反馈信息输入"), _("反馈"), wxT(""), wxOK | wxCANCEL | wxTE_MULTILINE, wxDefaultPosition);
        if(dlg.ShowModal()==wxID_OK)
        {
            s_content = dlg.GetValue();
        }else
           return false;*/

        s_sql = wxT("UPDATE s_ncr_data SET  issue_status=3, fb_content='")+s_content+wxT("' , fb_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_by = '")+gr_para.login_user+wxT("',modify_date='")+DateToAnsiStr(wxDateTime::Now())+
                 wxT("' where id='")+s_id+wxT("';");
                 break;
    case 4:
        s_sql = wxT("UPDATE s_ncr_data SET issue_status=4, issue_result='")+s_content+wxT("', modify_by = '")+gr_para.login_user+wxT("',modify_date='")+DateToAnsiStr(wxDateTime::Now())+
                 wxT("' where id='")+s_id+wxT("';");
                 break;
    default:
        return false;

    }

    if(i_mode==2)
    {
        if(wxGetApp().app_sql_update(s_sql))
        {
            lv_ncrs->SetItem(i_item, 11, s_group_id);
            lv_ncrs->SetItem(i_item, 12, s_group_name);

            return true;
        }else
            return false;
    }
    else
        return wxGetApp().app_sql_update(s_sql);

}

void ncr_proc_panel::OnButton_fetchClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }

    if(!wxGetApp().conn->IsAlive())
    {
        wxLogMessage(_("系统连接已断开,请重新连接!"));
        wxGetApp().clear_login();
        return;
    }

    int i_sel = lv_ncrs->GetSelectedItemCount();

    if(i_sel==0)
        return;

    int i_item = lv_ncrs->GetFirstSelected();

   if(wxMessageBox(_("确认领取NCR?"),_("领取"),wxYES_NO)==wxNO)
         return;

   for(int i=0;i<i_sel;i++)
    {
        wxString s_id = lv_ncrs->GetItemText(i_item, 0);
        wxString s_ncr_id = lv_ncrs->GetItemText(i_item, 1);
       int i_status = get_status(s_id);

       if(i_status<1)
       {
           wxLogMessage(wxT("NCR:")+s_ncr_id+_("已经尚未提交，无法领取!"));
           continue;
       }

       if(i_status>=2)
       {
            wxLogMessage(wxT("NCR:")+s_ncr_id+_("已经已经领取!"));
           continue;
       }

       if(change_item(i_item, 1))
       {
           wxLogMessage(wxT("NCR:")+s_ncr_id+_("已经领用!"));
       }

       i_item = lv_ncrs->GetNextSelected(i_item);

    }

    refresh_list();
}

void ncr_proc_panel::OnButton_feedbackClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }

    if(!wxGetApp().conn->IsAlive())
    {
        wxLogMessage(_("系统连接已断开,请重新连接!"));
        wxGetApp().clear_login();
        return;
    }

        int i_sel = lv_ncrs->GetSelectedItemCount();

    if(i_sel==0)
        return;

    int i_item = lv_ncrs->GetFirstSelected();
    wxString s_content;


   for(int i=0;i<i_sel;i++)
    {
        wxString s_id = lv_ncrs->GetItemText(i_item, 0);
        wxString s_ncr_id = lv_ncrs->GetItemText(i_item, 1);
        wxString s_file_index=lv_ncrs->GetItemText(i_item, 6);
        s_content= lv_ncrs->GetItemText(i_item, 20);
       int i_status = get_status(s_id);

       if(i_status<2)
       {
           wxLogMessage(wxT("NCR:")+s_ncr_id+_("已经尚未领用, 无法反馈!"));
           continue;
       }

       if(i_status>=3)
       {
            wxLogMessage(wxT("NCR:")+s_ncr_id+_("已经回复，无法反复提交!"));
           continue;
       }

       wxTextEntryDialog dlg(this, _("请输入反馈内容")+s_ncr_id, s_file_index, s_content, wxTextEntryDialogStyle, wxDefaultPosition);
       dlg.SetTextValidator(wxFILTER_EMPTY);

       if(dlg.ShowModal()==wxID_CANCEL)
           continue;

       s_content =dlg.GetValue();

       if(change_item(i_item, 3, s_content))
       {
           wxLogMessage(wxT("NCR:")+s_ncr_id+_("反馈完成 !"));
       }

       i_item = lv_ncrs->GetNextSelected(i_item);

    }

    refresh_list();

}

void ncr_proc_panel::OnButton_closeClick(wxCommandEvent& event)
{

    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }

    if(!wxGetApp().conn->IsAlive())
    {
        wxLogMessage(_("系统连接已断开,请重新连接!"));
        wxGetApp().clear_login();
        return;
    }

    int i_sel = lv_ncrs->GetSelectedItemCount();

    if(i_sel==0)
        return;

    int i_item = lv_ncrs->GetFirstSelected();
    wxString s_content;


   for(int i=0;i<i_sel;i++)
    {
        wxString s_id = lv_ncrs->GetItemText(i_item, 0);
        wxString s_ncr_id = lv_ncrs->GetItemText(i_item, 1);
        wxString s_file_index=lv_ncrs->GetItemText(i_item, 6);
        s_content = lv_ncrs->GetItemText(i_item, 22);
       int i_status = get_status(s_id);

       if(i_status<3)
       {
           wxLogMessage(wxT("NCR:")+s_ncr_id+_("已经尚未反馈，无法关闭!"));
           continue;
       }

       if(i_status>=4)
       {
            wxLogMessage(wxT("NCR:")+s_ncr_id+_("已经关闭，无法多次关闭!"));
           continue;
       }

       wxTextEntryDialog dlg(this, _("请输入分析结果")+s_ncr_id, s_file_index, s_content, wxTextEntryDialogStyle, wxDefaultPosition);

       if(dlg.ShowModal()==wxCANCEL)
           continue;

       wxString s_content =dlg.GetValue();

       if(change_item(i_item, 4, s_content))
       {
           wxLogMessage(wxT("NCR:")+s_ncr_id+_("已经关闭 !"));
       }

       i_item = lv_ncrs->GetNextSelected(i_item);

    }

    refresh_list();
}

void ncr_proc_panel::OnButton_delClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }

    if(!wxGetApp().conn->IsAlive())
    {
        wxLogMessage(_("系统连接已断开,请重新连接!"));
        wxGetApp().clear_login();
        return;
    }

    int i_sel = lv_ncrs->GetSelectedItemCount();

    if(i_sel==0)
        return;

    int i_item = lv_ncrs->GetFirstSelected();

   if(wxMessageBox(_("确认删除NCR?"),_("删除"),wxYES_NO)==wxNO)
         return;

   for(int i=0;i<i_sel;i++)
    {
        wxString s_id = lv_ncrs->GetItemText(i_item, 0);
        wxString s_ncr_id = lv_ncrs->GetItemText(i_item, 1);
       int i_status = get_status(s_id);

       if(i_status>1)
       {
           wxLogMessage(wxT("NCR:")+s_ncr_id+_("已经被领用，无法删除!"));
           continue;
       }

       if(i_status<0)
       {
            wxLogMessage(wxT("NCR:")+s_ncr_id+_("已经删除!"));
           continue;
       }

       if(change_item(i_item, -1))
       {
           wxLogMessage(wxT("NCR:")+s_ncr_id+_("删除完成 !"));
       }

       i_item = lv_ncrs->GetNextSelected(i_item);

    }

    refresh_list();
}

void ncr_proc_panel::Onchoice_filter1Select(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }

    if(!wxGetApp().conn->IsAlive())
    {
        wxLogMessage(_("系统连接已断开,请重新连接!"));
        wxGetApp().clear_login();
        return;
    }

    switch(event.GetSelection())
    {
    case 0:
        m_filter1 = wxT(" issue_status>=0 and issue_status<4 ");
        break;
    case 1:
        m_filter1= wxT(" issue_status=2 ");
        break;
    case 2:
        m_filter1 = wxT(" issue_status=1 ");
        break;
    case 3:
        m_filter1  = wxT(" issue_status=3 ");
        break;
    case 4:
        m_filter1 = wxT(" issue_status=4 ");
        break;
    default :
        m_filter1.Empty();
        break;

    }
    refresh_list();
}

void ncr_proc_panel::Onchoice_filter2Select(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }

    if(!wxGetApp().conn->IsAlive())
    {
        wxLogMessage(_("系统连接已断开,请重新连接!"));
        wxGetApp().clear_login();
        return;
    }

    wxString s_group;
    wxPostgreSQLresult *_res;
    wxString s_sql;
    int i_count;
    if(event.GetSelection()==0)
        m_filter2.Empty();

    if(event.GetSelection()==1)
        m_filter2 = wxT(" and res_by ='")+gr_para.login_user+wxT("' ");

    if(event.GetSelection()==2)
    {
        s_sql = wxT("select group_id from s_group_member where employee_id='")+gr_para.login_user+wxT("' and is_ncr=true;");
        _res =  wxGetApp().app_sql_select(s_sql);
        if(_res->Status()!= PGRES_TUPLES_OK)
        {
            _res->Clear();
            m_filter2.Empty();
            return;
        }

        i_count=_res->GetRowsNumber();

        if(i_count==0)
        {
            _res->Clear();
            m_filter2.Empty();
            return ;
        }

        for(int i=0;i<i_count;i++)
        {
             m_filter2 = wxT(" and res_group='")+_res->GetVal(wxT("group_id"))+wxT("' ");
             _res->MoveNext();

        }
        _res->Clear();

    }

    if(event.GetSelection() == 3)
    {
        wxArrayString a_group;

        s_sql = wxT(" select distinct concat(group_id,'-',group_name) as group_info from v_group_member where is_ncr=true order by group_info asc;");
        _res=wxGetApp().app_sql_select(s_sql);
        if(_res->Status()!= PGRES_TUPLES_OK)
        {
            _res->Clear();
            m_filter2.Empty();
            return;
        }

        i_count = _res->GetRowsNumber();

        if(i_count==0)
        {
            m_filter2.Empty();
            return;
        }

        for(int i=0;i<i_count;i++)
        {
            s_group= _res->GetVal(wxT("group_info"));
            a_group.Add(s_group);
            _res->MoveNext();
        }
        _res->Clear();

        wxSingleChoiceDialog dlg(this, _("请选择组"),_("组选择"), a_group);

        a_group.Clear();

        if(dlg.ShowModal()==wxID_OK)
        {
            s_group=dlg.GetStringSelection();

            int i_pos = s_group.Find(wxT("-"));
            s_group=s_group.Left(i_pos);

            m_filter2 = wxT(" and res_group = '")+s_group+wxT("' ");
        }else
        {
            m_filter2.Empty();
            return;
        }

    }

    if(event.GetSelection()==4)
    {
        wxArrayString a_res;

        s_sql = wxT("select distinct concat(employee_id, '-', name) as res_eng from v_group_member where is_ncr=true;");
        _res=wxGetApp().app_sql_select(s_sql);
        if(_res->Status()!= PGRES_TUPLES_OK)
        {
            _res->Clear();
            m_filter2.Empty();
            return;
        }

        i_count = _res->GetRowsNumber();

        if(i_count==0)
        {
            m_filter2.Empty();
            return;
        }

        for(int i=0;i<i_count;i++)
        {
            s_group = _res->GetVal(wxT("res_eng"));
            a_res.Add(s_group);
            _res->MoveNext();
        }

        _res->Clear();

        wxSingleChoiceDialog dlg(this, _("请选择回复人员"),_("人员选择"), a_res);

        a_res.Clear();

        if(dlg.ShowModal()==wxID_OK)
        {
            s_group=dlg.GetStringSelection();

            int i_pos = s_group.Find(wxT("-"));
            s_group=s_group.Left(i_pos);

            m_filter2 = wxT(" and res_by = '")+s_group+wxT("' ");
        }else
        {
            m_filter2.Empty();
            return;
        }
    }

    refresh_list();

}

void ncr_proc_panel::Onlv_ncrsItemActivated(wxListEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }

    if(!wxGetApp().conn->IsAlive())
    {
        wxLogMessage(_("系统连接已断开,请重新连接!"));
        wxGetApp().clear_login();
        return;
    }

    int i_sel = lv_ncrs->GetSelectedItemCount();

    if(i_sel==0)
        return;

    int i_item = lv_ncrs->GetFirstSelected();

    wxString s_id = lv_ncrs->GetItemText(i_item, 0);
    wxString s_ncr_id = lv_ncrs->GetItemText(i_item, 1);
    int i_status = get_status(s_id);

    wxString s_publish_by = lv_ncrs->GetItemText(i_item, 16);
    wxString s_res_by = lv_ncrs->GetItemText(i_item, 13);

    ncr_proc_dlg * dlg;

    if(i_status==0)
    {
        if(gr_para.login_user==s_publish_by)
            dlg = new ncr_proc_dlg(0);
        else
            dlg = new ncr_proc_dlg(1);
    }else if(i_status==1)
    {
         dlg = new ncr_proc_dlg(1);
    }else if(i_status==2)
    {
         if(gr_para.login_user==s_res_by)
             dlg = new ncr_proc_dlg(2);
         else
            dlg = new ncr_proc_dlg(3);
    }else if(i_status==3)
    {
         if(gr_para.login_user==s_publish_by)
            dlg = new ncr_proc_dlg(4);
         else
            dlg = new ncr_proc_dlg(5);
    }else
    {
         dlg = new ncr_proc_dlg(5);
    }

    dlg->m_rel_wbs = lv_ncrs->GetItemText(i_item, 2);
    dlg->m_ncr_id = s_ncr_id;
    dlg->m_id = s_id;
    dlg->m_res_project = lv_ncrs->GetItemText(i_item, 3);
    dlg->m_lift_no = lv_ncrs->GetItemText(i_item, 4);
    dlg->m_lift_qty = StrToInt(lv_ncrs->GetItemText(i_item, 5));
    dlg->m_file_index = lv_ncrs->GetItemText(i_item, 6);
    dlg->m_from_dep = lv_ncrs->GetItemText(i_item, 7);
    dlg->m_issue_head = lv_ncrs->GetItemText(i_item, 8);
    dlg->m_issue_desc = lv_ncrs->GetItemText(i_item, 9);
    dlg->m_status = i_status;
    dlg->m_res_group = lv_ncrs->GetItemText(i_item, 12);
    dlg->m_res_by = lv_ncrs->GetItemText(i_item, 14);
    dlg->m_fetch_date = lv_ncrs->GetItemText(i_item, 15);
    dlg->m_publish_by = lv_ncrs->GetItemText(i_item, 17);
    dlg->m_publish_date = lv_ncrs->GetItemText(i_item, 18);
    dlg->m_res_bco = lv_ncrs->GetItemText(i_item, 19);
    dlg->m_fb_content = lv_ncrs->GetItemText(i_item, 20);
    dlg->m_fb_date = lv_ncrs->GetItemText(i_item, 21);
    dlg->m_issue_result = lv_ncrs->GetItemText(i_item, 22);
    dlg->m_issue_res = lv_ncrs->GetItemText(i_item, 23);

    dlg->init_ctrl_value();

    if(dlg->ShowModal()==wxID_OK)
    {
        refresh_list();
    }
}

void ncr_proc_panel::OnButton_ROLL_backClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }

    if(!wxGetApp().conn->IsAlive())
    {
        wxLogMessage(_("系统连接已断开,请重新连接!"));
        wxGetApp().clear_login();
        return;
    }

    int i_sel = lv_ncrs->GetSelectedItemCount();

    if(i_sel==0)
        return;

    int i_item = lv_ncrs->GetFirstSelected();

   if(wxMessageBox(_("确认回滚NCR状态?"),_("回滚"),wxYES_NO)==wxNO)
         return;

    wxString s_sql, s_operator;

   for(int i=0;i<i_sel;i++)
    {
        wxString s_id = lv_ncrs->GetItemText(i_item, 0);
        wxString s_ncr_id = lv_ncrs->GetItemText(i_item, 1);
       int i_status = get_status(s_id);


       if(i_status==-1)
       {
           wxLogMessage(s_ncr_id+_("已经删除，删除状态的NCR无法回滚"));
       }

       if(i_status == 0)
       {
           wxLogMessage(s_ncr_id+_("初始状态, 回退不了，亲，已经没路了."));
       }

       if(i_status == 4 || i_status==3)
       {
            s_operator = lv_ncrs->GetItemText(i_item, 16);

            if(gr_para.login_user == s_operator)
            {

                s_sql = wxT("UPDATE s_ncr_data SET issue_status=")+NumToStr(i_status-1)+wxT(", modify_by='")+gr_para.local_user+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("' where id='")+s_id+wxT("';");
                if(wxGetApp().app_sql_update(s_sql))
                {
                    wxGetApp().change_log("s_ncr_data",s_id ,"issue_status",NumToStr(i_status),NumToStr(i_status-1),"by hand");
                    wxLogMessage(s_ncr_id+_("回退成功"));
                }
            }else
            {
                wxLogMessage(s_ncr_id+_("发布人不是阁下，无法回滚。"));
            }
       }

      if(i_status == 2)
      {
           s_operator = lv_ncrs->GetItemText(i_item, 13);
           if(gr_para.login_user == s_operator)
           {
                  s_sql =wxT("update s_ncr_data set issue_status=1, res_by=NULL, fetch_date=NULL, modify_by='")+gr_para.local_user+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("' where id='")+s_id+wxT("';");
                 if(wxGetApp().app_sql_update(s_sql))
                 {
                     wxGetApp().change_log("s_ncr_data", s_id,"rel_by", s_operator, "NULL","by hand");
                     wxGetApp().change_log("s_ncr_data",s_id ,"issue_status","2","1","by hand");
                     wxLogMessage(s_ncr_id+_("已经回退任务池"));

                 }
           }else
           {
                wxLogMessage(s_ncr_id+_("领用人不是阁下，无法回滚。"));

           }
      }

      if(i_status==1)
      {
          s_operator = lv_ncrs->GetItemText(i_item, 16);

            if(gr_para.login_user == s_operator)
            {

                s_sql =wxT("UPDATE s_ncr_data SET issue_status=0, modify_by='")+gr_para.local_user+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("' where id='")+s_id+wxT("';");
                if(wxGetApp().app_sql_update(s_sql))
                {
                    wxGetApp().change_log("s_ncr_data",s_id ,"issue_status","1","0","by hand");
                    wxLogMessage(s_ncr_id+_("收回成功"));
                }
            }else
            {
                wxLogMessage(s_ncr_id+_("发布人不是阁下，无法收回。"));
            }
      }

       i_item = lv_ncrs->GetNextSelected(i_item);

    }

    refresh_list();
}

void ncr_proc_panel::OnButton1Click(wxCommandEvent& event)
{
        if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }

    if(!wxGetApp().conn->IsAlive())
    {
        wxLogMessage(_("系统连接已断开,请重新连接!"));
        wxGetApp().clear_login();
        return;
    }

    refresh_list();
}
