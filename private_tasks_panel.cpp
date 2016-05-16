#include "private_tasks_panel.h"
#include "pugixml.hpp"
#include "wfApp.h"
#include <wx/textdlg.h>

//(*InternalHeaders(private_tasks_panel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(private_tasks_panel)
const long private_tasks_panel::ID_STATICTEXT1 = wxNewId();
const long private_tasks_panel::ID_COMBOBOX_CATALOG = wxNewId();
const long private_tasks_panel::ID_STATICTEXT2 = wxNewId();
const long private_tasks_panel::ID_TEXTCTRL_LOAD = wxNewId();
const long private_tasks_panel::ID_STATICTEXT4 = wxNewId();
const long private_tasks_panel::ID_STATICTEXT3 = wxNewId();
const long private_tasks_panel::ID_TEXTCTRL_CONTENT = wxNewId();
const long private_tasks_panel::ID_BUTTON_SUBMIT = wxNewId();
const long private_tasks_panel::ID_BUTTON_CLEAR = wxNewId();
const long private_tasks_panel::ID_STATICTEXT5 = wxNewId();
const long private_tasks_panel::ID_DATEPICKERCTRL_WORKDAY = wxNewId();
const long private_tasks_panel::ID_DATEPICKERCTRL_TO = wxNewId();
const long private_tasks_panel::ID_STATICTEXT6 = wxNewId();
const long private_tasks_panel::ID_CHOICE_FILTER = wxNewId();
const long private_tasks_panel::ID_BUTTON_APPROVE = wxNewId();
const long private_tasks_panel::ID_BUTTON_RESET_LOAD = wxNewId();
const long private_tasks_panel::ID_BUTTON_REFRESH = wxNewId();
const long private_tasks_panel::ID_BUTTON_SETTING = wxNewId();
const long private_tasks_panel::ID_BUTTON_DELETE = wxNewId();
const long private_tasks_panel::ID_CHECKBOX_SELF = wxNewId();
const long private_tasks_panel::ID_LISTVIEW_TASKS = wxNewId();
//*)

BEGIN_EVENT_TABLE(private_tasks_panel,wxPanel)
	//(*EventTable(private_tasks_panel)
	//*)
END_EVENT_TABLE()

private_tasks_panel::private_tasks_panel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(private_tasks_panel)
	wxStaticBoxSizer* StaticBoxSizer2;
	wxGridBagSizer* GridBagSizer1;
	wxBoxSizer* BoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxDefaultPosition, wxSize(298,258), wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("任务提交"));
	GridBagSizer1 = new wxGridBagSizer(0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("工作类别"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	GridBagSizer1->Add(StaticText1, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cb_catalog = new wxComboBox(this, ID_COMBOBOX_CATALOG, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY|wxCB_DROPDOWN, wxDefaultValidator, _T("ID_COMBOBOX_CATALOG"));
	GridBagSizer1->Add(cb_catalog, wxGBPosition(0, 1), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("工作量"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	GridBagSizer1->Add(StaticText2, wxGBPosition(0, 2), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	tc_res_load = new wxTextCtrl(this, ID_TEXTCTRL_LOAD, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL_LOAD"));
	GridBagSizer1->Add(tc_res_load, wxGBPosition(0, 3), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("小时"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	GridBagSizer1->Add(StaticText4, wxGBPosition(0, 4), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("工作内容"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	GridBagSizer1->Add(StaticText3, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	tc_content = new wxTextCtrl(this, ID_TEXTCTRL_CONTENT, wxEmptyString, wxDefaultPosition, wxSize(315,36), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL_CONTENT"));
	GridBagSizer1->Add(tc_content, wxGBPosition(1, 1), wxGBSpan(2, 8), wxALL|wxEXPAND, 5);
	button_submit = new wxButton(this, ID_BUTTON_SUBMIT, _("提交"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_SUBMIT"));
	GridBagSizer1->Add(button_submit, wxGBPosition(3, 1), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	button_clear = new wxButton(this, ID_BUTTON_CLEAR, _("重填"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CLEAR"));
	GridBagSizer1->Add(button_clear, wxGBPosition(3, 2), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("工作日"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	GridBagSizer1->Add(StaticText5, wxGBPosition(0, 5), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	dt_workday_from = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL_WORKDAY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL_WORKDAY"));
	GridBagSizer1->Add(dt_workday_from, wxGBPosition(0, 6), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	dt_workday_to = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL_TO, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL_TO"));
	GridBagSizer1->Add(dt_workday_to, wxGBPosition(0, 8), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("到"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	GridBagSizer1->Add(StaticText6, wxGBPosition(0, 7), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(GridBagSizer1, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 0);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, this, _("任务清单"));
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("过滤器"));
	choice_filter = new wxChoice(this, ID_CHOICE_FILTER, wxDefaultPosition, wxSize(60,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_FILTER"));
	choice_filter->Append(_("待确认"));
	choice_filter->SetSelection( choice_filter->Append(_("已确认")) );
	choice_filter->Append(_("已删除"));
	StaticBoxSizer3->Add(choice_filter, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer2->Add(StaticBoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	button_approve = new wxButton(this, ID_BUTTON_APPROVE, _("确认"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_APPROVE"));
	BoxSizer2->Add(button_approve, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	button_reset_load = new wxButton(this, ID_BUTTON_RESET_LOAD, _("工作量重置"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_RESET_LOAD"));
	BoxSizer2->Add(button_reset_load, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	button_refresh = new wxButton(this, ID_BUTTON_REFRESH, _("刷新"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_REFRESH"));
	BoxSizer2->Add(button_refresh, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	button_setting = new wxButton(this, ID_BUTTON_SETTING, _("设置"), wxDefaultPosition, wxSize(111,25), 0, wxDefaultValidator, _T("ID_BUTTON_SETTING"));
	button_setting->Hide();
	BoxSizer2->Add(button_setting, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	button_delete = new wxButton(this, ID_BUTTON_DELETE, _("删除"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_DELETE"));
	BoxSizer2->Add(button_delete, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	check_self = new wxCheckBox(this, ID_CHECKBOX_SELF, _("含本人任务"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_SELF"));
	check_self->SetValue(true);
	BoxSizer3->Add(check_self, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(BoxSizer2, 1, wxALL|wxALIGN_LEFT, 0);
	lv_tasks = new wxListView(this, ID_LISTVIEW_TASKS, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTVIEW_TASKS"));
	StaticBoxSizer2->Add(lv_tasks, 5, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(StaticBoxSizer2, 3, wxALL|wxEXPAND, 0);
	SetSizer(BoxSizer1);
	SetSizer(BoxSizer1);
	Layout();

	Connect(ID_TEXTCTRL_LOAD,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&private_tasks_panel::Ontc_res_loadText);
	Connect(ID_BUTTON_SUBMIT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&private_tasks_panel::Onbutton_submitClick);
	Connect(ID_BUTTON_CLEAR,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&private_tasks_panel::Onbutton_clearClick);
	Connect(ID_CHOICE_FILTER,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&private_tasks_panel::Onchoice_filterSelect);
	Connect(ID_BUTTON_APPROVE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&private_tasks_panel::Onbutton_approveClick);
	Connect(ID_BUTTON_RESET_LOAD,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&private_tasks_panel::Onbutton_reset_loadClick);
	Connect(ID_BUTTON_REFRESH,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&private_tasks_panel::Onbutton_refreshClick);
	Connect(ID_BUTTON_SETTING,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&private_tasks_panel::Onbutton_settingClick);
	Connect(ID_BUTTON_DELETE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&private_tasks_panel::Onbutton_deleteClick);
	Connect(ID_CHECKBOX_SELF,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&private_tasks_panel::Oncheck_selfClick);
	//*)

	init_list_view();
	init_catalog_list();
	get_direct_leader();
	m_filter = choice_filter->GetSelection();

	refresh_list_view();
}

private_tasks_panel::~private_tasks_panel()
{
	//(*Destroy(private_tasks_panel)
	//*)
}


void private_tasks_panel::Onbutton_submitClick(wxCommandEvent& event)
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


    if(wxMessageBox(_("确认提交日常工作!"),_("确认"),wxYES_NO)==wxNO)
            return;


    wxString str_task_id = get_task_id();

    wxString str_task_catalog = cb_catalog->GetValue();

    wxString str_res_load = tc_res_load->GetValue();

    wxString str_content = tc_content->GetValue();

    wxString strSql = wxT("INSERT INTO l_daily_task(task_id, task_catalog, task_content, task_status, task_load, \
                          submiter, submit_time, reviewer, review_time, work_date, work_date_to)\
                          VALUES ('")+str_task_id+wxT("','")+str_task_catalog+wxT("','")+str_content+wxT("',1,'")+str_res_load+wxT("','")+
                          gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+m_direct_leader+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+DateToStrFormat(dt_workday_from->GetValue())+wxT("','")+DateToStrFormat(dt_workday_to->GetValue())+wxT("');");
    strSql.Replace(wxT("''"),wxT("NULL"));
    if(wxGetApp().app_sql_update(strSql))
    {
        wxLogMessage(str_task_id+_("任务已经提交，请等待主管确认!"));
        clear_submit();
        refresh_list_view();

    }

}

void private_tasks_panel::init_list_view()
{
    wxListItem itemCol;
    itemCol.SetText(_("任务ID"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_tasks->InsertColumn(0, itemCol);
    itemCol.SetText(_("工作类别"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(80);
    lv_tasks->InsertColumn(1, itemCol);
    itemCol.SetText(_("工作内容"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(400);
    lv_tasks->InsertColumn(2, itemCol);
    itemCol.SetText(_("工作量"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_tasks->InsertColumn(3, itemCol);
    itemCol.SetText(_("计量单位"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_tasks->InsertColumn(4, itemCol);
    itemCol.SetText(_("状态"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_tasks->InsertColumn(5, itemCol);
    itemCol.SetText(_("提交人ID"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(0);
    lv_tasks->InsertColumn(6, itemCol);
    itemCol.SetText(_("提交人"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_tasks->InsertColumn(7, itemCol);
    itemCol.SetText(_("确认人ID"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(0);
    lv_tasks->InsertColumn(8, itemCol);
    itemCol.SetText(_("确认人"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_tasks->InsertColumn(9, itemCol);
    itemCol.SetText(_("from"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_tasks->InsertColumn(10, itemCol);
    itemCol.SetText(_("to"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_tasks->InsertColumn(11, itemCol);
}

void private_tasks_panel::refresh_list_view()
{
    lv_tasks->DeleteAllItems();

    wxString str_sql=wxT("SELECT task_id, task_catalog, task_content, task_status,task_load,review_load,\
                     load_unit,submiter,(select name from s_employee where employee_id = submiter) as submiter_name,\
                     reviewer,(select name from s_employee where employee_id = reviewer) as reviewer_name,work_date,work_date_to from l_daily_task where ");
    switch(m_filter)
    {
    case 0:
        if(check_self->IsShown())
        {
            if(check_self->IsChecked())
                str_sql = str_sql + wxT(" (submiter ='")+gr_para.login_user+wxT("' or reviewer ='")+gr_para.login_user+wxT("') and task_status = 1 ");
            else
                str_sql = str_sql + wxT(" reviewer ='")+gr_para.login_user+wxT("' and task_status =1 ");
        }
        else
        {
             str_sql = str_sql + wxT(" submiter = '")+gr_para.login_user+wxT("' and task_status = 1 ");
        }

        str_sql = str_sql + wxT(" order by submit_time asc;");
        break;
    case 1:
        if(check_self->IsShown())
        {
            if(check_self->IsChecked())
                str_sql = str_sql + wxT(" (submiter ='")+gr_para.login_user+wxT("' or reviewer ='")+gr_para.login_user+wxT("') and task_status = 2  ");
            else
                str_sql = str_sql + wxT(" reviewer ='")+gr_para.login_user+wxT("' and task_status =2  ");
        }
        else
        {
             str_sql = str_sql + wxT(" submiter = '")+gr_para.login_user+wxT("' and task_status = 2 ");
        }

        str_sql = str_sql + wxT(" order by review_time DESC LIMIT 500;");
        break;
    case 2:
        if(check_self->IsShown())
        {
            if(check_self->IsChecked())
                str_sql = str_sql + wxT(" (submiter ='")+gr_para.login_user+wxT("' or reviewer ='")+gr_para.login_user+wxT("') and task_status = -1  ");
            else
                str_sql = str_sql + wxT(" reviewer ='")+gr_para.login_user+wxT("' and task_status =-1  ");
        }
        else
        {
             str_sql = str_sql + wxT(" submiter = '")+gr_para.login_user+wxT("' and task_status = -1 ");
        }

        str_sql = str_sql + wxT(" order by review_time DESC LIMIT 500;");
        break;
    default:
        return;
    }


    wxPostgreSQLresult *_res =wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int i_count = _res->GetRowsNumber();

    if(i_count == 0)
    {
        return;
    }

    for(int i =0;i<i_count;i++)
    {
        wxString str = _res->GetVal(wxT("task_id"));
        long tmp = lv_tasks->InsertItem(i, str);
        lv_tasks->SetItemData(tmp, i);
        str = _res->GetVal(wxT("task_catalog"));
        lv_tasks->SetItem(tmp, 1, str);
        str = _res->GetVal(wxT("task_content"));
        lv_tasks->SetItem(tmp, 2, str);
        str = _res->GetVal(wxT("task_load"));
        lv_tasks->SetItem(tmp, 3, str);
        str = _res->GetVal(wxT("load_unit"));
        lv_tasks->SetItem(tmp, 4, str);
        int i_status = _res->GetInt(wxT("task_status"));
        str = task_int_to_status(i_status);
        lv_tasks->SetItem(tmp, 5, str);
        str = _res->GetVal(wxT("submiter"));
        lv_tasks->SetItem(tmp, 6, str);

        if(str == gr_para.login_user)
             lv_tasks->SetItemBackgroundColour(tmp, *wxGREEN);

        str = _res->GetVal(wxT("submiter_name"));
        lv_tasks->SetItem(tmp, 7, str);
        str = _res->GetVal(wxT("reviewer"));
        lv_tasks->SetItem(tmp, 8, str);
        str = _res->GetVal(wxT("reviewer_name"));
        lv_tasks->SetItem(tmp, 9, str);

        str = DateToStrFormat(_res->GetDate(wxT("work_date")));
        lv_tasks->SetItem(tmp,10, str);

        str = DateToStrFormat(_res->GetDate(wxT("work_date_to")));
        lv_tasks->SetItem(tmp,11, str);

        _res->MoveNext();
    }

    _res->Clear();
}

void private_tasks_panel::approve_item(long item)
{
     wxString str_task_id = lv_tasks->GetItemText(item, 0);
     wxString str_review_load = lv_tasks->GetItemText(item, 3);
     wxString str_submiter = lv_tasks->GetItemText(item, 6);

     wxString str_status = lv_tasks->GetItemText(item, 5);

     if(task_status_to_int(str_status)!=1)
     {
         wxLogMessage(_("不是待确认任务:")+str_task_id);
         return;
     }

     if(str_submiter == gr_para.login_user)
     {
         wxLogMessage(_("自己无权确认自己的任务:")+str_task_id);
         return;
     }


    wxString strSql = wxT("UPDATE l_daily_task SET review_load='")+str_review_load+wxT("', review_time='")+ DateToAnsiStr(wxDateTime::Now())+wxT("', task_status = 2")+
                      wxT(" where task_id = '")+str_task_id+wxT("';");


    if(wxGetApp().app_sql_update(strSql))
    {
        wxLogMessage(_("任任务已经确认完成:")+str_task_id);

    }
}

void private_tasks_panel::delete_item(long item)
{
     wxString str_task_id = lv_tasks->GetItemText(item, 0);

     wxString str_status = lv_tasks->GetItemText(item, 5);

     if(task_status_to_int(str_status)!=1)
     {
         wxLogMessage(_("不是待确认任务:")+str_task_id);
         return;
     }

    wxString strSql = wxT("UPDATE l_daily_task SET task_status = -1,review_time='")+DateToAnsiStr(wxDateTime::Now())+wxT("' where task_id = '")+str_task_id+wxT("';");


    if(wxGetApp().app_sql_update(strSql))
    {
        wxLogMessage(_("此任务已经删除:")+str_task_id);

    }
}

void private_tasks_panel::Onbutton_clearClick(wxCommandEvent& event)
{
    clear_submit();
}

void private_tasks_panel::Onbutton_approveClick(wxCommandEvent& event)
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

    int i_sel = lv_tasks->GetSelectedItemCount();
    if(m_filter!=0 || i_sel==0)
        return;

    if(wxMessageBox(_("确认Approve此任务？"),_("确认"),wxYES_NO)==wxNO)
            return;


    int i_item = lv_tasks->GetFirstSelected();
    for(int i=0;i<i_sel;i++)
    {
        approve_item(i_item);
        i_item = lv_tasks->GetNextSelected(i_item);
    }

    refresh_list_view();
}

void private_tasks_panel::Onbutton_deleteClick(wxCommandEvent& event)
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

    int i_sel = lv_tasks->GetSelectedItemCount();
    if(m_filter!=0 || i_sel==0)
        return;

    if(wxMessageBox(_("确认删除这些任务,无法恢复？"),_("确认"),wxYES_NO)==wxNO)
            return;

    int i_item = lv_tasks->GetFirstSelected();
    for(int i=0;i<i_sel;i++)
    {
        delete_item(i_item);
        i_item = lv_tasks->GetNextSelected(i_item);
    }

    refresh_list_view();

}

void private_tasks_panel::Onbutton_refreshClick(wxCommandEvent& event)
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

    refresh_list_view();
}

void private_tasks_panel::Onbutton_settingClick(wxCommandEvent& event)
{
}

void private_tasks_panel::Onchoice_filterSelect(wxCommandEvent& event)
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

    int i_new = event.GetSelection();

    if(i_new == m_filter)
        return;

    m_filter = i_new;
    refresh_list_view();

    event.Skip();
}

void private_tasks_panel::init_catalog_list()
{
    cb_catalog->Clear();

    pugi::xml_document ldoc;
    pugi::xml_node lnode,litem;
    pugi::xml_parse_result result;

    result = ldoc.load_file("para.xml");
    wxString str_item;

    if(result)
    {
        lnode = ldoc.child("private_task_catalog");

        for(litem = lnode.first_child(); litem; litem = litem.next_sibling())
        {
            str_item = wxString(litem.text().as_string());
            cb_catalog->Append(str_item);
        }

        lnode = ldoc.child("private_filter");

        int i_sel = lnode.child("default").text().as_int();

        choice_filter->SetSelection(i_sel);
    }

}


wxString private_tasks_panel::get_task_id()
{
       return wxGetApp().get_ser_id(wxT("l_daily_task"), wxT("task_id"));
}

void private_tasks_panel::get_direct_leader()
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

    wxString strSql = wxT("select direct_leader,is_twig from s_hierarchy where employee_id = '")+gr_para.login_user+wxT("';");
    wxPostgreSQLresult* _res = wxGetApp().app_sql_select(strSql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        return;
    }

    int i_count = _res->GetRowsNumber();

    if(i_count == 0)
    {
        _res->Clear();
        m_direct_leader.Clear();
        return;

    }

    _res->MoveFirst();
    m_direct_leader = _res->GetVal(wxT("direct_leader"));
    bool b_twig = _res->GetBool(wxT("is_twig"));

    check_self->Show(b_twig);

    _res->Clear();

}

void private_tasks_panel::clear_submit()
{

    cb_catalog->SetValue(wxEmptyString);
    tc_res_load->SetValue("0");
    tc_content->Clear();
}


void private_tasks_panel::Oncheck_selfClick(wxCommandEvent& event)
{
    if(m_filter == 2)
          return;

    refresh_list_view();

}

void private_tasks_panel::Onbutton_reset_loadClick(wxCommandEvent& event)
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

    int i_count = lv_tasks->GetSelectedItemCount();
    if(i_count ==0)
        return;

    if(m_filter!=0)
        return;

    wxTextEntryDialog dlg(this, _("工作量变更"),_("数值"),wxT("1"),wxOK | wxCANCEL,wxDefaultPosition);
    wxString str, str_review;

    dlg.SetTextValidator(wxFILTER_NUMERIC);
    if(dlg.ShowModal()==wxID_OK)
    {

        str = dlg.GetValue();
    }else return;

    int i_item = lv_tasks->GetFirstSelected();
    for(int i=0;i<i_count;i++)
    {
          str_review = lv_tasks->GetItemText(i_item, 6);
          if(str_review==gr_para.login_user)
          {
              wxLogMessage(_("本人提交的Item无法重置工作量:(")+lv_tasks->GetItemText(i_item,0)+wxT(")"));
              i_item = lv_tasks->GetNextSelected(i_item);
              continue;
          }

          lv_tasks->SetItem(i_item,3,str);
          i_item = lv_tasks->GetNextSelected(i_item);
    }

}

void private_tasks_panel::Ontc_res_loadText(wxCommandEvent& event)
{
    static wxString oldstr="";
    double d;
    if (NULL == tc_res_load)return;
    if (tc_res_load->GetValue().ToDouble(&d)  ||  0== tc_res_load->GetValue().Length() )
    {
        oldstr =tc_res_load->GetValue();

    }
    else
    {
        tc_res_load->SetValue(oldstr);
        tc_res_load->SetInsertionPoint(tc_res_load->GetValue().Length());
    }
}
