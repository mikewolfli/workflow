#include "proj_configure_history.h"

//(*InternalHeaders(proj_configure_history)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(proj_configure_history)
const long proj_configure_history::ID_LISTVIEW_HISTORY = wxNewId();
const long proj_configure_history::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(proj_configure_history,wxDialog)
	//(*EventTable(proj_configure_history)
	//*)
END_EVENT_TABLE()

proj_configure_history::proj_configure_history(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(proj_configure_history)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("重排产配置历史"));
	lv_history = new wxListView(this, ID_LISTVIEW_HISTORY, wxDefaultPosition, wxSize(785,178), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTVIEW_HISTORY"));
	StaticBoxSizer1->Add(lv_history, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(StaticBoxSizer1, 5, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("确认"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&proj_configure_history::OnButton1Click);
	//*)

	init_list_ctrl();
}

proj_configure_history::~proj_configure_history()
{
	//(*Destroy(proj_configure_history)
	//*)
}

void proj_configure_history::init_list_ctrl()
{
    wxListItem itemCol;
    itemCol.SetText(_("项目号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_history->InsertColumn(0, itemCol);

    itemCol.SetText(_("项目名称"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(200);
    lv_history->InsertColumn(1, itemCol);

    itemCol.SetText(_("梯号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_history->InsertColumn(2, itemCol);

    itemCol.SetText(_("排产次数"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(70);
    lv_history->InsertColumn(3, itemCol);

    itemCol.SetText(_("E/M"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(0);
    lv_history->InsertColumn(4, itemCol);

    itemCol.SetText(_("电气/机械"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(70);
    lv_history->InsertColumn(5, itemCol);

    itemCol.SetText(_("配置工程师ID"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(0);
    lv_history->InsertColumn(6, itemCol);

    itemCol.SetText(_("配置工程师"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_history->InsertColumn(7, itemCol);

    itemCol.SetText(_("收到日期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_history->InsertColumn(8, itemCol);

    itemCol.SetText(_("完成日期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_history->InsertColumn(9, itemCol);

    itemCol.SetText(_("配置状态"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_history->InsertColumn(10, itemCol);

}

void proj_configure_history::OnButton1Click(wxCommandEvent& event)
{
    EndDialog(wxID_OK);
}


void proj_configure_history::refresh_list(const wxArrayString &array_wbs, wxString s_flag)
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

    wxString strSql;
    if(s_flag.IsEmpty())
          strSql = wxT("SELECT instance_id,project_name,lift_no,restart_times,operator_id, name,start_date,finish_date,flag from v_restart_log where \
                          action_id= 'AT00000004' AND ");
    else
        strSql = wxT("SELECT instance_id,project_name,lift_no,restart_times,operator_id, name,start_date,finish_date,flag from v_restart_log where \
                          action_id= 'AT00000004' AND flag like '%")+s_flag+wxT("%' and ");

    int i_count = array_wbs.GetCount();

    wxString s_ex;
    int i;

    if(i_count == 1)
        strSql=strSql+ wxT(" instance_id = '")+array_wbs.Item(0)+wxT("' ");
    else
    {
        for(i=0; i<i_count; i++)
        {
            if(i==0)
            {
                s_ex = wxT(" (instance_id ='")+array_wbs.Item(i)+wxT("' or ");
            }
            else if(i==i_count-1)
            {
                s_ex = s_ex + wxT(" instance_id = '")+array_wbs.Item(i)+wxT("') ");
            }
            else
            {
                s_ex = s_ex + wxT(" instance_id = '")+array_wbs.Item(i)+wxT("' or");
            }
        }
    }

    strSql = strSql+s_ex+wxT(" order by instance_id, restart_times ASC;");

    wxPostgreSQLresult* _res = wxGetApp().app_sql_select(strSql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int irow = _res->GetRowsNumber();

    if(irow ==0)
    {
        _res->Clear();
        return;
    }

    _res->MoveFirst();

    wxString str;

    for(i=0;i<irow;i++)
    {
        str = _res->GetVal(wxT("instance_id"));
        long tmp = lv_history->InsertItem(i,str);

        str = _res->GetVal(wxT("project_name"));
        lv_history->SetItem(tmp,1,str);

        str = _res->GetVal(wxT("lift_no"));
        lv_history->SetItem(tmp,2,str);

        str = _res->GetVal(wxT("restart_times"));
        lv_history->SetItem(tmp,3,str);

        str = _res->GetVal(wxT("flag"));
        lv_history->SetItem(tmp,4,str);

        if(str == wxT("E"))
           lv_history->SetItem(tmp, 5, _("电气"));
        else if(str == wxT("M")||str==wxT("H"))
            lv_history->SetItem(tmp, 5, _("机械"));
        else
            lv_history->SetItem(tmp, 5, _("配置"));

        str = _res->GetVal(wxT("operator_id"));
        lv_history->SetItem(tmp,6,str);

        str = _res->GetVal(wxT("name"));
        lv_history->SetItem(tmp,7,str);

        str = DateToStrFormat(_res->GetDateTime(wxT("start_date")));
        lv_history->SetItem(tmp,8,str);

        str = DateToStrFormat(_res->GetDateTime(wxT("finish_date")));
        lv_history->SetItem(tmp,9,str);

        _res->MoveNext();

    }

    _res->Clear();
}

void proj_configure_history::refresh_now_wbs(const wxArrayString &array_wbs, wxString s_flag)
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

    wxString strSql;
    if(s_flag.IsEmpty())
        strSql = wxT("SELECT instance_id,project_name,lift_no,restart_times,operator_id, name,start_date,finish_date,is_active, flag from v_task_list1 where \
                          action_id= 'AT00000004' AND ");
    else
         strSql = wxT("SELECT instance_id,project_name,lift_no,restart_times,operator_id, name,start_date,finish_date,is_active,flag from v_task_list1 where \
                          action_id= 'AT00000004' AND flag like '%")+s_flag+wxT("%' and ");

    int i_count = array_wbs.GetCount();

    wxString s_ex;
    int i;

    if(i_count == 1)
        strSql=strSql+ wxT(" instance_id = '")+array_wbs.Item(0)+wxT("' ");
    else
    {
        for(i=0; i<i_count; i++)
        {
            if(i==0)
            {
                s_ex = wxT(" (instance_id ='")+array_wbs.Item(i)+wxT("' or ");
            }
            else if(i==i_count-1)
            {
                s_ex = s_ex + wxT(" instance_id = '")+array_wbs.Item(i)+wxT("') ");
            }
            else
            {
                s_ex = s_ex + wxT(" instance_id = '")+array_wbs.Item(i)+wxT("' or");
            }
        }
    }

    strSql = strSql+s_ex+wxT(" order by instance_id ASC;");

    wxPostgreSQLresult* _res = wxGetApp().app_sql_select(strSql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int irow = _res->GetRowsNumber();

    if(irow ==0)
    {
        _res->Clear();
        return;
    }

    _res->MoveFirst();

    wxString str;

    for(i=0;i<irow;i++)
    {
        str = _res->GetVal(wxT("instance_id"));
        long tmp = lv_history->InsertItem(i,str);

        str = _res->GetVal(wxT("project_name"));
        lv_history->SetItem(tmp,1,str);

        str = _res->GetVal(wxT("lift_no"));
        lv_history->SetItem(tmp,2,str);

        str = _res->GetVal(wxT("restart_times"));
        lv_history->SetItem(tmp,3,str);

        str = _res->GetVal(wxT("flag"));
        lv_history->SetItem(tmp,4,str);

        if(str == wxT("E"))
           lv_history->SetItem(tmp, 5, _("电气"));
        else if(str == wxT("M")||str==wxT("H"))
            lv_history->SetItem(tmp, 5, _("机械"));
        else
            lv_history->SetItem(tmp, 5, _("配置"));


        str = _res->GetVal(wxT("operator_id"));
        lv_history->SetItem(tmp,6,str);

        str = _res->GetVal(wxT("name"));
        lv_history->SetItem(tmp,7,str);

        str = DateToStrFormat(_res->GetDateTime(wxT("start_date")));
        lv_history->SetItem(tmp,8,str);

        str = DateToStrFormat(_res->GetDateTime(wxT("finish_date")));
        lv_history->SetItem(tmp,9,str);

        str = BoolToY(_res->GetBool(wxT("is_active")));
        lv_history->SetItem(tmp,10,str);

        _res->MoveNext();

    }

    _res->Clear();
}

void proj_configure_history::refresh_now_prj(const wxArrayString &array_wbs, wxString s_flag)
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

    wxString strSql;
    if(s_flag.IsEmpty())
         strSql = wxT("SELECT instance_id,project_name,lift_no,restart_times,operator_id, name,start_date,finish_date,is_active,flag from v_task_list1 where \
                          action_id= 'AT00000004' AND ");
    else
        strSql = wxT("SELECT instance_id,project_name,lift_no,restart_times,operator_id, name,start_date,finish_date,is_active,flag from v_task_list1 where \
                          action_id= 'AT00000004' AND flag like '%")+s_flag+wxT("%' and ");

    int i_count = array_wbs.GetCount();

    wxString s_ex;
    int i;

    if(i_count == 1)
        strSql=strSql+ wxT(" instance_id like '")+array_wbs.Item(0)+wxT("%' ");
    else
    {
        for(i=0; i<i_count; i++)
        {
            if(i==0)
            {
                s_ex = wxT(" (instance_id like'")+array_wbs.Item(i)+wxT("%' or ");
            }
            else if(i==i_count-1)
            {
                s_ex = s_ex + wxT(" instance_id like '")+array_wbs.Item(i)+wxT("%') ");
            }
            else
            {
                s_ex = s_ex + wxT(" instance_id like '")+array_wbs.Item(i)+wxT("%' or");
            }
        }
    }

    strSql = strSql+s_ex+wxT(" order by instance_id ASC;");

    wxPostgreSQLresult* _res = wxGetApp().app_sql_select(strSql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int irow = _res->GetRowsNumber();

    if(irow ==0)
    {
        _res->Clear();
        return;
    }

    _res->MoveFirst();

    wxString str;

    for(i=0;i<irow;i++)
    {
        str = _res->GetVal(wxT("instance_id"));
        long tmp = lv_history->InsertItem(i,str);

        str = _res->GetVal(wxT("project_name"));
        lv_history->SetItem(tmp,1,str);

        str = _res->GetVal(wxT("lift_no"));
        lv_history->SetItem(tmp,2,str);

        str = _res->GetVal(wxT("restart_times"));
        lv_history->SetItem(tmp,3,str);

                str = _res->GetVal(wxT("flag"));
        lv_history->SetItem(tmp,4,str);

        if(str == wxT("E"))
           lv_history->SetItem(tmp, 5, _("电气"));
        else if(str == wxT("M")||str==wxT("H"))
            lv_history->SetItem(tmp, 5, _("机械"));
        else
            lv_history->SetItem(tmp, 5, _("配置"));

        str = _res->GetVal(wxT("operator_id"));
        lv_history->SetItem(tmp,6,str);

        str = _res->GetVal(wxT("name"));
        lv_history->SetItem(tmp,7,str);

        str = DateToStrFormat(_res->GetDateTime(wxT("start_date")));
        lv_history->SetItem(tmp,8,str);

        str = DateToStrFormat(_res->GetDateTime(wxT("finish_date")));
        lv_history->SetItem(tmp,9,str);

        str = BoolToY(_res->GetBool(wxT("is_active")));
        lv_history->SetItem(tmp,10,str);

        _res->MoveNext();

    }

    _res->Clear();
}
