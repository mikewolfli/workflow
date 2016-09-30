#include "ins_proc_log.h"

//(*InternalHeaders(ins_proc_log)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(ins_proc_log)
const long ins_proc_log::ID_LISTVIEW_DISPLAY = wxNewId();
const long ins_proc_log::ID_LISTVIEW_DISPLAY1 = wxNewId();
const long ins_proc_log::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ins_proc_log,wxDialog)
	//(*EventTable(ins_proc_log)
	//*)
	EVT_CLOSE(ins_proc_log::OnClose)
END_EVENT_TABLE()

ins_proc_log::ins_proc_log(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ins_proc_log)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;

	Create(parent, id, _("项目流转状态"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("id"));
	SetClientSize(wxSize(800,400));
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	lv_proc_log = new wxListView(this, ID_LISTVIEW_DISPLAY, wxDefaultPosition, wxSize(579,211), wxLC_REPORT|wxLC_HRULES|wxLC_VRULES, wxDefaultValidator, _T("ID_LISTVIEW_DISPLAY"));
	BoxSizer1->Add(lv_proc_log, 10, wxALL|wxEXPAND, 0);
	lv_proc_log1 = new wxListView(this, ID_LISTVIEW_DISPLAY1, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_LISTVIEW_DISPLAY1"));
	BoxSizer1->Add(lv_proc_log1, 10, wxALL|wxEXPAND, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("退出"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	SetSizer(BoxSizer1);
	Layout();
	Center();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ins_proc_log::OnButton1Click);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&ins_proc_log::OnClose);
	//*)

}

ins_proc_log::~ins_proc_log()
{
	//(*Destroy(ins_proc_log)
	//*)
//	array_wbs.Clear();
//	Destroy();
}

void ins_proc_log::init_conf_list_header()
{

    lv_proc_log->DeleteAllColumns();
    wxListItem itemCol;

    itemCol.SetText(_("Wbs No"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log->InsertColumn(0, itemCol);

    itemCol.SetText(_("项目名称"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log->InsertColumn(1, itemCol);

    itemCol.SetText(_("梯号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_proc_log->InsertColumn(2, itemCol);

    itemCol.SetText(_("流程步骤"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log->InsertColumn(3, itemCol);

    itemCol.SetText(_("负责人"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log->InsertColumn(4, itemCol);

    itemCol.SetText(_("收到日期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(150);
    lv_proc_log->InsertColumn(5, itemCol);

    itemCol.SetText(_("完成日期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(150);
    lv_proc_log->InsertColumn(6, itemCol);

    itemCol.SetText(_("配置完成日期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log->InsertColumn(7, itemCol);

    itemCol.SetText(_("发货期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log->InsertColumn(8, itemCol);


    lv_proc_log1->DeleteAllColumns();


    itemCol.SetText(_("Wbs No"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log1->InsertColumn(0, itemCol);

    itemCol.SetText(_("项目名称"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log1->InsertColumn(1, itemCol);

    itemCol.SetText(_("梯号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_proc_log1->InsertColumn(2, itemCol);

    itemCol.SetText(_("流程步骤"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log1->InsertColumn(3, itemCol);

    itemCol.SetText(_("负责人"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log1->InsertColumn(4, itemCol);

    itemCol.SetText(_("收到日期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(150);
    lv_proc_log1->InsertColumn(5, itemCol);

    itemCol.SetText(_("完成日期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(150);
    lv_proc_log1->InsertColumn(6, itemCol);

    itemCol.SetText(_("配置完成日期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log1->InsertColumn(7, itemCol);

    itemCol.SetText(_("发货期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log1->InsertColumn(8, itemCol);
}

void ins_proc_log::init_review_list_header()
{
    lv_proc_log1->Show(false);
    lv_proc_log->DeleteAllColumns();
    wxListItem itemCol;

    itemCol.SetText(_("Wbs No"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log->InsertColumn(0, itemCol);

    itemCol.SetText(_("项目名称"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log->InsertColumn(1, itemCol);

    itemCol.SetText(_("梯号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_proc_log->InsertColumn(2, itemCol);

    itemCol.SetText(_("流程步骤"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log->InsertColumn(3, itemCol);

    itemCol.SetText(_("负责人"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log->InsertColumn(4, itemCol);

    itemCol.SetText(_("收到日期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(150);
    lv_proc_log->InsertColumn(5, itemCol);

    itemCol.SetText(_("完成日期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(150);
    lv_proc_log->InsertColumn(6, itemCol);

    itemCol.SetText(_("要求评审完成日期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(150);
    lv_proc_log->InsertColumn(7, itemCol);

    itemCol.SetText(_("价格表收到日期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(150);
    lv_proc_log->InsertColumn(8, itemCol);

}

void ins_proc_log::init_review_restart_header()
{

    lv_proc_log1->Show(false);
    lv_proc_log->DeleteAllColumns();
    wxListItem itemCol;

    itemCol.SetText(_("任务号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(60);
    lv_proc_log->InsertColumn(0, itemCol);


    itemCol.SetText(_("WBS NO"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log->InsertColumn(1, itemCol);

    itemCol.SetText(_("项目名称"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log->InsertColumn(2, itemCol);

    itemCol.SetText(_("梯号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_proc_log->InsertColumn(3, itemCol);

    itemCol.SetText(_("任务图纸套数"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(150);
    lv_proc_log->InsertColumn(4, itemCol);

    itemCol.SetText(_("重启次数"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(150);
    lv_proc_log->InsertColumn(5, itemCol);

    itemCol.SetText(_("流程步骤"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log->InsertColumn(6, itemCol);

    itemCol.SetText(_("负责人"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log->InsertColumn(7, itemCol);

    itemCol.SetText(_("收到日期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(150);
    lv_proc_log->InsertColumn(8, itemCol);

    itemCol.SetText(_("完成日期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(150);
    lv_proc_log->InsertColumn(9, itemCol);

    itemCol.SetText(_("要求评审完成日期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(150);
    lv_proc_log->InsertColumn(10, itemCol);

    itemCol.SetText(_("价格表收到日期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(150);
    lv_proc_log->InsertColumn(11, itemCol);

}

void ins_proc_log::Refresh_review_history(wxArrayString & array_wbs_list)
{
  if(array_wbs_list.IsEmpty())
        return;

    int i_count= array_wbs_list.GetCount();
    wxString str_sql,s_wbs;
    wxPostgreSQLresult* _res;
    bool b_toggle= true;



 //   lv_proc_log->DeleteAllItems();

    str_sql = wxT("SELECT review_task_id, wbs_no, workflow_id,flow_ser,project_name , lift_no, action_id,operator_id,price_list_receive,  \
                     (select concat(employee_id, '-', name) from s_employee where employee_id=operator_id) as res_person, start_date, \
                      finish_date, require_review_date, (select action_name from s_action_info where action_id=v_review_restart_log.action_id) as action_name , project_catalog, restart_times, \
                      review_drawing_qty from v_review_restart_log ");
    for(int i = 0; i<i_count; i++)
    {
        if(i==0)
            str_sql= str_sql + wxT(" WHERE (wbs_no = '")+array_wbs_list.Item(i)+ wxT("' ");
        else
            str_sql= str_sql + wxT(" OR wbs_no = '")+array_wbs_list.Item(i)+ wxT("' ");
    }

    str_sql = str_sql + wxT(") and workflow_id='")+wf_str_review+wxT("' and unit_status<>-1 and unit_status<>-2 ORDER BY wbs_no,review_task_id, flow_ser,restart_times ASC;");
//    wxMessageBox(str_sql, _("test"),wxOK);
    _res = wxGetApp().app_sql_select(str_sql);


    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        return;
    }

    int i_result = _res->GetRowsNumber();

    bool b_active;
    _res->MoveFirst();
    for(int j=0; j<i_result; j++)
    {

         wxColour back_color;


        wxString str = _res->GetVal(wxT("review_task_id"));
        long tmp = lv_proc_log->InsertItem(j,str);
        lv_proc_log->SetItemData(tmp, j);



        str = _res->GetVal(wxT("wbs_no"));

        if(s_wbs!=str)
        {
            b_toggle=!b_toggle;
            s_wbs=str;
        }
        lv_proc_log->SetItem(tmp,1,str);

        if(b_toggle)
            back_color = *wxWHITE;
        else back_color = *wxLIGHT_GREY;
        lv_proc_log->SetItemBackgroundColour(tmp, back_color);

        str = _res->GetVal(wxT("project_name"));
        lv_proc_log->SetItem(tmp,2,str);

        str = _res->GetVal(wxT("lift_no"));
        lv_proc_log->SetItem(tmp,3,str);

        str =NumToStr(_res->GetInt(wxT("review_drawing_qty")));
        lv_proc_log->SetItem(tmp,4,str);

        str =NumToStr(_res->GetInt(wxT("restart_times")));
        lv_proc_log->SetItem(tmp,5,str);

        str = _res->GetVal(wxT("action_name"));
        lv_proc_log->SetItem(tmp,6,str);

        str = _res->GetVal(wxT("res_person"));
        if(str==wxT("-"))
            str.Empty();
        lv_proc_log->SetItem(tmp,7,str);

        wxDateTime dt_temp;

        dt_temp = _res->GetDateTime(wxT("start_date"));
        str = DateToAnsiStr(dt_temp);
        lv_proc_log->SetItem(tmp,8,str);

        dt_temp = _res->GetDateTime(wxT("finish_date"));
        str = DateToAnsiStr(dt_temp);
        lv_proc_log->SetItem(tmp,9,str);

        dt_temp = _res->GetDate(wxT("require_review_date"));
        str = DateToStrFormat(dt_temp);
        lv_proc_log->SetItem(tmp,10,str);

        dt_temp = _res->GetDate(wxT("price_list_receive"));
        str = DateToStrFormat(dt_temp);
        lv_proc_log->SetItem(tmp,11,str);

        _res->MoveNext();
    }

    _res->Clear();
}

void ins_proc_log::Refresh_list_view(wxArrayString & array_wbs_list, wxString _flag, int _mode)
{
    if(array_wbs_list.IsEmpty())
        return;

    int i_count= array_wbs_list.GetCount();
    wxString str_sql;
    wxPostgreSQLresult* _res;

    wxListView *lv_listview;

    if(_mode==0)
        lv_listview = lv_proc_log;

    if(_mode==1)
        lv_listview = lv_proc_log1;

 //   lv_listview->DeleteAllItems();

    str_sql = wxT("SELECT instance_id, workflow_id,flow_ser, is_urgent, \
                      status, is_active, project_name , lift_no, action_name,\
                       concat(operator_id,'-',name) as res_person, start_date, \
                      finish_date, req_configure_finish, req_delivery_date, action_id , project_catalog\
                      from v_task_list1 ");
    for(int i = 0; i<i_count; i++)
    {
        if(i==0)
            str_sql= str_sql + wxT(" WHERE (instance_id = '")+array_wbs_list.Item(i)+ wxT("' ");
        else
            str_sql= str_sql + wxT(" OR instance_id = '")+array_wbs_list.Item(i)+ wxT("' ");
    }

    if(_flag.IsEmpty())
    {
       lv_proc_log1->Show(false);
       str_sql = str_sql + wxT(") and (workflow_id='WF0002' OR workflow_id='WF0006') ORDER BY instance_id, workflow_id, flow_ser ASC;");
    }
    else
       str_sql = str_sql + wxT(") and (workflow_id='WF0002' OR workflow_id='WF0006') and flag like'%")+_flag+wxT("%'  ORDER BY instance_id, workflow_id, flow_ser ASC;");
//    wxMessageBox(str_sql, _("test"),wxOK);
    _res = wxGetApp().app_sql_select(str_sql);


    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        return;
    }

    int i_result = _res->GetRowsNumber();

    wxString str_pass;
    bool b_active;
    _res->MoveFirst();
    for(int j=0; j<i_result; j++)
    {
        b_active =  _res->GetBool(wxT("is_active"));
        wxColour back_color;
        if(_res->GetInt(wxT("status"))== 4 )
            back_color = *wxRED;
        else if(_res->GetInt(wxT("project_catalog"))==5)
            back_color = *wxCYAN;
        else if(_res->GetInt(wxT("project_catalog"))==6)
            back_color = *wxYELLOW;
        else if(_res->GetBool(wxT("is_urgent")))
            back_color = *wxGREEN;
        else if(b_active)
            back_color = *wxWHITE;
        else back_color = *wxLIGHT_GREY;

        if(b_active)
            str_pass = _res->GetVal(wxT("instance_id"));

        if(!b_active && str_pass == _res->GetVal(wxT("instance_id")))
        {
             _res->MoveNext();
             continue;
        }


        wxString str = _res->GetVal(wxT("instance_id"));
        long tmp = lv_listview->InsertItem(j,str);
        lv_listview->SetItemData(tmp, j);

        lv_listview->SetItemBackgroundColour(tmp, back_color);

        str = _res->GetVal(wxT("project_name"));
        lv_listview->SetItem(tmp,1,str);

        str = _res->GetVal(wxT("lift_no"));
        lv_listview->SetItem(tmp,2,str);

        str = _res->GetVal(wxT("action_name"));
        lv_listview->SetItem(tmp,3,str);

        str = _res->GetVal(wxT("res_person"));
        lv_listview->SetItem(tmp,4,str);

        wxDateTime dt_temp;

        dt_temp = _res->GetDateTime(wxT("start_date"));
        str = DateToAnsiStr(dt_temp);
        lv_listview->SetItem(tmp,5,str);

        dt_temp = _res->GetDateTime(wxT("finish_date"));
        if(!b_active)
        {
            str = DateToAnsiStr(dt_temp);

        }else str.Empty();

        lv_listview->SetItem(tmp,6,str);

        dt_temp = _res->GetDate(wxT("req_configure_finish"));
        str = DateToStrFormat(dt_temp);
        lv_listview->SetItem(tmp,7,str);

        dt_temp = _res->GetDate(wxT("req_delivery_date"));
        str = DateToStrFormat(dt_temp);
        lv_listview->SetItem(tmp,8,str);

        _res->MoveNext();
    }

    _res->Clear();

}


void ins_proc_log::Refresh_review_list(wxArrayString & array_wbs_list)
{
   if(array_wbs_list.IsEmpty())
        return;

    int i_count= array_wbs_list.GetCount();
    wxString str_sql;
    wxPostgreSQLresult* _res;

 //   lv_proc_log->DeleteAllItems();

    str_sql = wxT("SELECT instance_id, workflow_id,flow_ser, is_urgent, \
                      status, is_active, project_name , lift_no, action_name,operator_id,price_list_receive, \
                     (select concat(employee_id, '-', name) from s_employee where employee_id=operator_id) as res_person, start_date, \
                      finish_date, require_review_date, action_id , project_catalog\
                      from v_task_list4 ");
    for(int i = 0; i<i_count; i++)
    {
        if(i==0)
            str_sql= str_sql + wxT(" WHERE (instance_id = '")+array_wbs_list.Item(i)+ wxT("' ");
        else
            str_sql= str_sql + wxT(" OR instance_id = '")+array_wbs_list.Item(i)+ wxT("' ");
    }

    str_sql = str_sql + wxT(") and workflow_id='")+wf_str_review+wxT("' and is_latest=true ORDER BY instance_id, flow_ser ASC;");
//    wxMessageBox(str_sql, _("test"),wxOK);
    _res = wxGetApp().app_sql_select(str_sql);


    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        return;
    }

    int i_result = _res->GetRowsNumber();

    wxString str_pass;
    bool b_active;
    _res->MoveFirst();
    for(int j=0; j<i_result; j++)
    {
        b_active =  _res->GetBool(wxT("is_active"));
        wxColour back_color;

        if(b_active)
            back_color = *wxWHITE;
        else back_color = *wxLIGHT_GREY;

        if(b_active)
            str_pass = _res->GetVal(wxT("instance_id"));

        if(!b_active && str_pass == _res->GetVal(wxT("instance_id")))
        {
            _res->MoveNext();
            continue;
        }


        wxString str = _res->GetVal(wxT("instance_id"));
        long tmp = lv_proc_log->InsertItem(j,str);
        lv_proc_log->SetItemData(tmp, j);

        lv_proc_log->SetItemBackgroundColour(tmp, back_color);

        str = _res->GetVal(wxT("project_name"));
        lv_proc_log->SetItem(tmp,1,str);

        str = _res->GetVal(wxT("lift_no"));
        lv_proc_log->SetItem(tmp,2,str);

        str = _res->GetVal(wxT("action_name"));
        lv_proc_log->SetItem(tmp,3,str);

        str = _res->GetVal(wxT("res_person"));
        if(str==wxT("-"))
            str.Empty();
        lv_proc_log->SetItem(tmp,4,str);

        wxDateTime dt_temp;

        dt_temp = _res->GetDateTime(wxT("start_date"));
        str = DateToAnsiStr(dt_temp);
        lv_proc_log->SetItem(tmp,5,str);

        dt_temp = _res->GetDateTime(wxT("finish_date"));

        if(!b_active)
           str = DateToAnsiStr(dt_temp);
        else str.Empty();
        lv_proc_log->SetItem(tmp,6,str);

        dt_temp = _res->GetDate(wxT("require_review_date"));
        str = DateToStrFormat(dt_temp);
        lv_proc_log->SetItem(tmp,7,str);

        dt_temp = _res->GetDate(wxT("price_list_receive"));
        str = DateToStrFormat(dt_temp);
        lv_proc_log->SetItem(tmp,8,str);

        _res->MoveNext();
    }

    _res->Clear();
}


void ins_proc_log::OnClose(wxCloseEvent& event)
{
      EndDialog(wxID_OK);
 //     Close();
 //     Destroy();
}


void ins_proc_log::OnButton1Click(wxCommandEvent& event)
{
     EndDialog(wxID_OK);
 //  ::PostMessage((HWND__ *)this->GetHandle(),WM_CLOSE,0,0);

}
