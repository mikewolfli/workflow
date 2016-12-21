#include "project_review_panel.h"
#include "wfApp.h"
#include "utils/wf_operator.h"
#include "communication_dlg.h"
#include "review_communication_log.h"
#include "ins_proc_log.h"

//(*InternalHeaders(project_review_panel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(project_review_panel)
const long project_review_panel::ID_BUTTON4 = wxNewId();
const long project_review_panel::ID_BUTTON1 = wxNewId();
const long project_review_panel::ID_BUTTON2 = wxNewId();
const long project_review_panel::ID_BUTTON3 = wxNewId();
const long project_review_panel::idMenu_process = wxNewId();
const long project_review_panel::idMenu_draw_qty = wxNewId();
const long project_review_panel::idMenu_restart_log = wxNewId();
const long project_review_panel::idMenu_Communication_log = wxNewId();
const long project_review_panel::idMenu_pos = wxNewId();
//*)
const long project_review_panel::ID_TREELISTCTRL_TASK_LIST = wxNewId();

BEGIN_EVENT_TABLE(project_review_panel,wxPanel)
	//(*EventTable(project_review_panel)
	//*)
END_EVENT_TABLE()

project_review_panel::project_review_panel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(project_review_panel)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button_Communication = new wxButton(this, ID_BUTTON4, _("评审问题反馈"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	BoxSizer2->Add(Button_Communication, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Finish = new wxButton(this, ID_BUTTON1, _("完成"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button_Finish, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Return = new wxButton(this, ID_BUTTON2, _("退回"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button_Return, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Refresh = new wxButton(this, ID_BUTTON3, _("刷新任务"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer2->Add(Button_Refresh, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_LEFT, 0);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("任务清单"));
	BoxSizer1->Add(StaticBoxSizer1, 5, wxALL|wxEXPAND, 0);
	SetSizer(BoxSizer1);
	mi_process = new wxMenuItem((&menu_review_log), idMenu_process, _("项目评审流程信息(&I)"), _("项目评审流程信息"), wxITEM_NORMAL);
	menu_review_log.Append(mi_process);
	mi_draw_qty = new wxMenuItem((&menu_review_log), idMenu_draw_qty, _("更改图纸套数(&D)"), _("更改图纸套数"), wxITEM_NORMAL);
	menu_review_log.Append(mi_draw_qty);
	mi_review_history = new wxMenuItem((&menu_review_log), idMenu_restart_log, _("重启评审历史(&H)"), _("重启评审历史"), wxITEM_NORMAL);
	menu_review_log.Append(mi_review_history);
	mi_com_log = new wxMenuItem((&menu_review_log), idMenu_Communication_log, _("问题传递log(&L)"), _("问题传递log"), wxITEM_NORMAL);
	menu_review_log.Append(mi_com_log);
	mi_pos = new wxMenuItem((&menu_review_log), idMenu_pos, _("快速定位(&P)\tCtrl+F"), _("快速定位"), wxITEM_NORMAL);
	menu_review_log.Append(mi_pos);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&project_review_panel::OnButton_CommunicationClick);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&project_review_panel::OnButton_FinishClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&project_review_panel::OnButton_ReturnClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&project_review_panel::OnButton_RefreshClick);
	Connect(idMenu_process,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_review_panel::Onmi_processSelected);
	Connect(idMenu_draw_qty,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_review_panel::Onmi_draw_qtySelected);
	Connect(idMenu_restart_log,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_review_panel::Onmi_review_historySelected);
	Connect(idMenu_Communication_log,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_review_panel::Onmi_com_logSelected);
	Connect(idMenu_pos,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_review_panel::Onmi_posSelected);
	//*)

	BuildDataViewCtrl();
    StaticBoxSizer1->Add(tlc_task_list, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0 );
    Layout();

    Connect(ID_TREELISTCTRL_TASK_LIST,wxEVT_COMMAND_TREE_ITEM_MENU,(wxObjectEventFunction)&project_review_panel::OnTreeListCtrlRightClick);
    Connect(ID_TREELISTCTRL_TASK_LIST,wxEVT_COMMAND_TREE_KEY_DOWN ,(wxObjectEventFunction)&project_review_panel::OnChar);

    b_no_check = is_no_check();

    wxString str = wxT(" operator_id = '")+gr_para.login_user+wxT("' and is_active = true and active_status>=1 and action_id = 'AT00000025' and unit_status>=0 and is_latest=true ");
    set_clause(str);
    refresh_list();
}

project_review_panel::~project_review_panel()
{
	//(*Destroy(project_review_panel)
	//*)
}

void project_review_panel::OnTreeListCtrlRightClick(wxTreeEvent& event)
{
        PopupMenu(&menu_review_log, ScreenToClient(wxGetMousePosition()));
}

void project_review_panel::OnButton_RefreshClick(wxCommandEvent& event)
{
    refresh_list();
}

void project_review_panel::BuildDataViewCtrl()
{
    InitImageList();
    tlc_task_list = new wxcode::wxTreeListCtrl(this, ID_TREELISTCTRL_TASK_LIST ,
                                  wxDefaultPosition, wxDefaultSize,
                                  wxTR_DEFAULT_STYLE| wxTR_COLUMN_LINES|wxTR_HIDE_ROOT|wxTR_ROW_LINES|wxTR_MULTIPLE | wxTR_FULL_ROW_HIGHLIGHT);

    tlc_task_list->SetImageList(m_imageList);

    tlc_task_list->AddColumn(_("项目信息"),200,wxALIGN_LEFT,-1,true,false);//0
    tlc_task_list->AddColumn(_("任务ID"),0,wxALIGN_LEFT,-1,false,false);//1
    tlc_task_list->AddColumn(_("台数"),50,wxALIGN_LEFT, -1,true,false );//2
    tlc_task_list->AddColumn(_("要求完成日期"),100,wxALIGN_LEFT, -1,true,false);//3
    tlc_task_list->AddColumn(_("紧急程度"), 60, wxALIGN_LEFT, -1, true, false);//4
    tlc_task_list->AddColumn(_("任务收到时间"), 120, wxALIGN_LEFT,-1, true, false);//5

    tlc_task_list->AddColumn(_("合同负责ID"),0,wxALIGN_LEFT, -1,false,false );//6
    tlc_task_list->AddColumn(_("合同负责"),100,wxALIGN_LEFT, -1,true,false );//7
    tlc_task_list->AddColumn(_("分公司id"),0,wxALIGN_LEFT, -1,false,false);//8
    tlc_task_list->AddColumn(_("分公司"),100,wxALIGN_LEFT, -1,true,false);//9
    tlc_task_list->AddColumn(_("status"),50,wxALIGN_LEFT,-1,true,false);//10
    tlc_task_list->AddColumn(_("任务状态"),70,wxALIGN_LEFT,-1,true,false);//11
    tlc_task_list->AddColumn(_("action_id"),0,wxALIGN_LEFT,-1,false,false);//12
    tlc_task_list->AddColumn(_("图纸套数"),60,wxALIGN_LEFT,-1,true,false); //13
    tlc_task_list->AddColumn(_("备注"),100,wxALIGN_LEFT,-1,true,false); //14
    tlc_task_list->AddColumn(_("交流status"),0,wxALIGN_LEFT,-1,false,false);//15
    tlc_task_list->AddColumn(_("交流状态"),200,wxALIGN_LEFT,-1,true,false);//16
    tlc_task_list->AddColumn(_("flow_ser"),0, wxALIGN_LEFT, -1, false, false); //17
    tlc_task_list->AddColumn(_("紧急程度id"),0, wxALIGN_LEFT, -1, false, false); //18
    tlc_task_list->AddColumn(_("非标等级"),100, wxALIGN_LEFT, -1, true, false);//19

    tlc_task_list->AddRoot (_("评审任务"));
}

void project_review_panel::refresh_list()
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

    wxArrayString array_group = wxGetApp().get_group();


    if(array_group.Index(wxT("G0002")) == wxNOT_FOUND)
        return;

    wxTreeItemId root = tlc_task_list->GetRootItem();
    tlc_task_list->DeleteChildren (root);

    wxString str_sql = wxT("SELECT review_task_id,contract_id,project_name,project_id,require_review_date,res_cm,nonstd_level,\
                           (select name from s_employee where employee_id = res_cm) as res_cm_person,branch_id,urgent_level, start_date,date_trunc('day',start_date) as p_start_date,\
                           (select branch_name_cn from s_branch_info where branch_id = v_task_list4.branch_id) as branch_name, status, wf_status, action_id, wbs_no,lift_no,\
                           elevator_type,project_catalog,flow_ser, review_remarks, review_drawing_qty,unit_status, unit_wf_status,\
                           (select concat(issue_status,'-',issue_content,'-',return_content) from s_review_communication where \
                           review_task_id= v_task_list4.review_task_id and issue_status <=2) as com_context FROM v_task_list4 WHERE ")+cl_clause+wxT(" ORDER BY p_start_date,review_task_id, wbs_no ASC;");

    wxPostgreSQLresult* _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int i_count = _res->GetRowsNumber();

    _res->MoveFirst();

    wxString s_review_task_id, str;
    wxTreeItemId branch_item,leaf_item;
    wxArrayString array_str;
    int i_urgent_level, i_nstd_level;
    for(int i=0; i<i_count; i++)
    {

        if(s_review_task_id != _res->GetVal(wxT("review_task_id")))
        {
            str = _res->GetVal(wxT("contract_id"))+_res->GetVal(wxT("project_name"))+wxT("-")+_res->GetVal(wxT("project_id"));
            s_review_task_id = _res->GetVal(wxT("review_task_id"));
            branch_item = tlc_task_list->AppendItem(root,str);


            tlc_task_list->SetItemText(branch_item,1,s_review_task_id);

            str = DateToStrFormat(_res->GetDateTime(wxT("require_review_date")));
            tlc_task_list->SetItemText(branch_item, 3, str);

            str = _res->GetVal(wxT("res_cm"));
            tlc_task_list->SetItemText(branch_item,6, str);

            str = _res->GetVal(wxT("res_cm_person"));
            tlc_task_list->SetItemText(branch_item,7, str);

            str = _res->GetVal(wxT("branch_id"));
            tlc_task_list->SetItemText(branch_item,8, str);

            str = _res->GetVal(wxT("branch_name"));
            tlc_task_list->SetItemText(branch_item,9, str);

            str = prj_status_to_str(_res->GetInt(wxT("unit_status")));
            tlc_task_list->SetItemText(branch_item,10, str);

            str = _res->GetVal(wxT("unit_wf_status"));
            tlc_task_list->SetItemText(branch_item,11, str);

           str = _res->GetVal(wxT("review_drawing_qty"));
            tlc_task_list->SetItemText(branch_item,13, str);

            str = _res->GetVal(wxT("review_remarks"));
            tlc_task_list->SetItemText(branch_item,14, str);

            str = _res->GetVal(wxT("com_context"));
            int i_review_status = 0;
            if(!str.IsEmpty())
            {
                  array_str = wxStringTokenize(str ,wxT("-"), wxTOKEN_RET_EMPTY_ALL  );
                  i_review_status = StrToInt(array_str.Item(0));
                  if(i_review_status == 1)
                  {
                      str = array_str.Item(1);

                  }

                  if(i_review_status == 2)
                  {
                      str = array_str.Item(2);
                  }

                  str = communication_status_to_str(i_review_status)+wxT(":")+str;

                  array_str.Clear();
            }
            tlc_task_list->SetItemText(branch_item,15, NumToStr(i_review_status));
            tlc_task_list->SetItemText(branch_item,16, str);
            str = _res->GetVal(wxT("flow_ser"));
            tlc_task_list->SetItemText(branch_item,17, str);

        }

        str = _res->GetVal(wxT("wbs_no"));

        leaf_item = tlc_task_list->AppendItem(branch_item,str,-1,-1);

        tlc_task_list->SetItemText(leaf_item,1,s_review_task_id);

        str = _res->GetVal(wxT("lift_no"));
        tlc_task_list->SetItemText(leaf_item,2, str);

        str = _res->GetVal(wxT("elevator_type"));
        tlc_task_list->SetItemText(leaf_item,3, str);

        str = prj_catalog_to_str(_res->GetInt(wxT("project_catalog")));
        tlc_task_list->SetItemText(leaf_item,7, str);

        str = prj_status_to_str(_res->GetInt(wxT("unit_status")));
        tlc_task_list->SetItemText(leaf_item,10, str);
        str = _res->GetVal(wxT("unit_wf_status"));
        tlc_task_list->SetItemText(leaf_item,11, str);

        str = _res->GetVal(wxT("action_id"));
        tlc_task_list->SetItemText(leaf_item,12, str);

        str = _res->GetVal(wxT("flow_ser"));
        tlc_task_list->SetItemText(leaf_item,17, str);

        i_urgent_level = _res->GetInt(wxT("urgent_level"));
        tlc_task_list->SetItemText(leaf_item, 18, NumToStr(i_urgent_level));

        i_nstd_level = _res->GetInt(wxT("nonstd_level"));
        tlc_task_list->SetItemText(leaf_item, 19, nstd_level_to_str(i_nstd_level));

        str = urgent_level_to_str(i_urgent_level);
        tlc_task_list->SetItemText(leaf_item, 4, str);

        str = DateToStrShort(_res->GetDateTime(wxT("start_date")));
        tlc_task_list->SetItemText(leaf_item, 5, str);

        _res->MoveNext();
    }

    _res->Clear();

    refresh_level();
}

void project_review_panel::set_treelist_item_color(wxTreeItemId i_id, int i_temp)
{
    switch(i_temp)
    {
    case 1:
         tlc_task_list->SetItemBackgroundColour(i_id, *wxWHITE);
         break;
    case 2:
        tlc_task_list->SetItemBackgroundColour(i_id, *wxYELLOW);
        break;
    case 3:
        tlc_task_list->SetItemBackgroundColour(i_id, *wxRED);
        break;
    default:
        tlc_task_list->SetItemBackgroundColour(i_id, *wxWHITE);
        break;
    }
}

void project_review_panel::refresh_level()
{
    wxTreeItemId root = tlc_task_list->GetRootItem();

    wxTreeItemIdValue cookie;
    wxTreeItemId item = tlc_task_list->GetFirstChild(root,cookie);

    int i_urgent_level, itemp, i_start_date;

    wxString s_status, s_wf_status, str, s_urgent_level, s_start_date, s_start_date2;
    wxArrayString a_lift_no;
    wxString s_lift_no;
    wxString s_nstd_level;

    while(item.IsOk())
    {
        i_urgent_level=1;
        i_start_date=0;
        s_nstd_level = wxEmptyString;
        int i_count_leaf = tlc_task_list->GetChildrenCount(item);


        int i_review_status = StrToInt(tlc_task_list->GetItemText(item, 15));

        if(i_review_status==1)
        {
            tlc_task_list->SetItemImage(item, 5);
        }else if(i_review_status == 2)
        {
            tlc_task_list->SetItemImage(item, 6);
        }else
            tlc_task_list->SetItemImage(item, -1);

        wxTreeItemIdValue cookie_child;
        wxTreeItemId child_item = tlc_task_list->GetFirstChild(item,cookie_child);
        while(child_item.IsOk())
        {
            itemp = StrToInt(tlc_task_list->GetItemText(child_item, 18));
            s_lift_no = tlc_task_list->GetItemText(child_item, 2);
            a_lift_no.Add(s_lift_no);

            set_treelist_item_color(child_item, itemp);

            if(itemp > i_urgent_level)
                i_urgent_level=itemp;

            str = tlc_task_list->GetItemText(child_item, 10);
            if(!s_status.Contains(str))
            {
                if(s_status.IsEmpty())
                    s_status=str;
                else
                    s_status = s_status+wxT("+")+str;
            }

            str = tlc_task_list->GetItemText(child_item, 11);

            if(!s_wf_status.Contains(str))
            {
                if(s_wf_status.IsEmpty())
                    s_wf_status=str;
                else
                    s_wf_status= s_wf_status+wxT("+")+str;
            }

            str = tlc_task_list->GetItemText(child_item, 4);

            if(!s_urgent_level.Contains(str))
            {
                if(s_urgent_level.IsEmpty())
                    s_urgent_level = str;
                else
                    s_urgent_level = s_urgent_level+wxT("+")+str;
            }

            str = tlc_task_list->GetItemText(child_item, 5);

            if(i_start_date==0)
            {
                s_start_date=str;
            }else if(i_start_date==1)
            {
                s_start_date2 = str;
            }else
            {
                s_start_date2 = compare_time(s_start_date2, str);
            }

            i_start_date++;

            str = tlc_task_list->GetItemText(child_item, 19);
            if(s_nstd_level.IsEmpty())
            {
                s_nstd_level = str;
            }else if(!s_nstd_level.Contains(str))
            {
                s_nstd_level = s_nstd_level+"+"+str;
            }

            child_item = tlc_task_list->GetNextSibling(child_item);
        }

        set_treelist_item_color(item, i_urgent_level);

        if(!s_start_date2.IsEmpty())
             s_start_date = compare_time(s_start_date, s_start_date2, true);

        s_lift_no = Combine_lift_no(a_lift_no);
        tlc_task_list->SetItemText(item, 2, NumToStr(i_count_leaf)+_("台[")+s_lift_no+_("]"));
        a_lift_no.Clear();

        tlc_task_list->SetItemText(item, 4,s_urgent_level);
        tlc_task_list->SetItemText(item, 5, s_start_date);
        tlc_task_list->SetItemText(item, 10,s_status);
        tlc_task_list->SetItemText(item, 11, s_wf_status);
        tlc_task_list->SetItemText(item, 19, s_nstd_level);

        s_urgent_level.Empty();
        s_start_date.Empty();
        s_status.Empty();
        s_wf_status.Empty();
        s_start_date2.Empty();

		item = tlc_task_list->GetNextSibling(item);

    }
}

wxString project_review_panel::compare_time(wxString str1, wxString str2, bool b_ser)
{
    int i_pos1,i_pos2;
    int i_len1, i_len2;

    i_len1 = str1.Length();
    i_len2 = str2.Length();

    wxString str_t1, str_t2;

    i_pos1 = str1.Find(wxT(" "));
    i_pos2= str2.Find(wxT(" "));

    str_t1= str1.Left(i_pos1);
    str_t2 = str2.Left(i_pos2);

    if(str_t1!=str_t2)
    {
        if(b_ser)
            return str1+wxT("~")+str2;
        else
            return str2;
    }

    str_t1=str1.Right(i_len1-i_pos1-1);
    str_t2 = str2.Right(i_len2-i_pos2-1);

    if(str_t1!=str_t2)
    {
        if(b_ser)
            return str1+wxT("~")+str_t2;
        else
            return str2;
    }

    return str1;

}

void project_review_panel::OnButton_CommunicationClick(wxCommandEvent& event)
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

    wxArrayString array_group = wxGetApp().get_group();

    if(array_group.Index(wxT("G0002")) == wxNOT_FOUND)
        return;

    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_task_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_task_list->GetSelections( items );

    if(items.IsEmpty())
    {
        wxLogMessage(_("请选择任务！"));
        return;
    }
    wxString str_status;
    wxString str_task_id;
    wxString str_context, str_temp;


    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item)==root)
        {
            str_status =  tlc_task_list->GetItemText(sel_item, 15);
            str_task_id = tlc_task_list->GetItemText(sel_item, 1);
   //         str_context = tlc_task_list->GetItemText(sel_item, 16);

            if(str_status==wxT("1"))
            {
                wxLogMessage(_("正在等待分公司反馈!"));
                continue;
            }

            if(str_status == wxT("2") || str_status.IsEmpty() || str_status ==wxT("0"))
            {

                if(create_communication(str_task_id, str_status,str_temp ))
                {
                    tlc_task_list->SetItemText(sel_item, 15, str_status);
                    str_context = update_issue_context(wxAtoi(str_status),str_temp);
                    tlc_task_list->SetItemText(sel_item, 16, str_context);
                }

            }

        }
    }

    refresh_level();
}

wxString project_review_panel::update_issue_context(int i_status, wxString str)
{
    wxString s_result;

    if(!str.IsEmpty())
    {
        int i_pos = str.Find(wxT(":"));
        int i_len = str.Length();
        if(i_pos!=wxNOT_FOUND)
        {
            s_result = str.Right(i_len-i_pos);
        }

        s_result = communication_status_to_str(i_status)+str;
    }

    return s_result;
}

bool project_review_panel::is_no_check()
{
    bool b_return=false;

    wxString str_sql = wxT("SELECT * FROM s_group_member where group_id = 'G0002' and status = true and employee_id ='")+gr_para.login_user+wxT("';");

    wxPostgreSQLresult * _res =  wxGetApp().app_sql_select(str_sql);

	if (_res->Status()!= PGRES_TUPLES_OK)
	{
		_res->Clear();
		return false;
	}

	int i_count = _res->GetRowsNumber();

	_res->MoveFirst();
	for (int i=0; i<i_count; i++)
	{

		b_return = _res->GetBool(wxT("no_check"));

		_res->MoveNext();
	}
	_res->Clear();

	return b_return;
}

void project_review_panel::OnButton_FinishClick(wxCommandEvent& event)
{
    if (!gr_para.login_status)
	{
		wxLogMessage(_("尚未登陆,无法做任何操作!"));
		return;
	}

	if (!wxGetApp().conn->IsAlive())
	{
		wxLogMessage(_("系统连接已断开,请重新连接!"));
		wxGetApp().clear_login();
		return;
	}

	wxArrayString array_group = wxGetApp().get_group();

	if (array_group.Index(wxT("G0002"))==wxNOT_FOUND)
	{
		return;
	}

	wxArrayTreeItemIds items;
	wxTreeItemId root = tlc_task_list->GetRootItem();

	wxArrayTreeItemIds::iterator iter;
	tlc_task_list->GetSelections( items );

	if (items.IsEmpty())
	{
		wxLogMessage(_("请选择项目！"));
		return;
	}

	wxString s_task_id, s_operator1, s_group1, s_operator2,s_group2, s_action_id, s_com_status;

	if (wxMessageBox(_("所选项目确认已经完成？"),_("完成确认："),wxOK|wxCANCEL,this)==wxCANCEL)
	{
		return;
	}

		v_wf_action * t_template=0;

	wf_operator * wf_active=0;
	wf_process * l_proc_act =0;

    int i_status;
    wxString s_wf_status, s_wbs, s_context,s_branch_id;
	wxLongLong mils_used, start_mils;

    t_template = get_template_action(wf_str_review);

    s_group1 = wxT("G0002");

    s_operator1 = wxGetApp().get_leader(s_group1);

    bool b_update_task_status = false;

	for ( iter = items.begin(); iter<items.end(); iter++)
	{
        wxTreeItemId sel_item = *iter;
        if (tlc_task_list->GetItemParent(sel_item)==root&&sel_item.IsOk())
        {

            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_task_list->GetFirstChild(sel_item,cookie);
            s_task_id = tlc_task_list->GetItemText(sel_item, 1);
            s_com_status = tlc_task_list->GetItemText(sel_item, 15);
            b_update_task_status = true;

            if(s_com_status == wxT("1"))
            {
                wxLogMessage(_("issue分公司尚未回复，评审无法完成!"));
                continue;
            }

            s_branch_id = tlc_task_list->GetItemText(sel_item, 8);

            s_group2 = wxT("G0016");

            s_operator2 = wxGetApp().get_operator_from_branch(s_branch_id, s_group2);

            while(child_item.IsOk())
            {

                s_wbs = tlc_task_list->GetItemText(child_item,0);

                i_status = prj_str_to_status(tlc_task_list->GetItemText(child_item, 10));
                start_mils = wxGetLocalTimeMillis();//事件处理事件统计，起始点。
                wf_active = new wf_operator(s_wbs, wf_str_review, t_template);
                l_proc_act = wf_active->get_current_process();

                l_proc_act->MoveToActive();

                wf_active->Pass_proc(s_operator1, s_group1, wxEmptyString, false);

                s_wf_status = _("评审审核");
                if(b_no_check)
                {

                    l_proc_act->MoveToActive();

                    wf_active->Pass_proc(s_operator2, s_group2, wxEmptyString, false);

                    s_wf_status = _("线下PO确认");

                }

                l_proc_act = 0;

       //         if (wf_active->update_instance(i_status,s_wf_status))
               if(update_review_units_status(s_task_id,s_wbs, i_status, s_wf_status))
                {

                    if(b_no_check && b_update_task_status)
                    {
                        update_review_task(s_task_id, 2);
                        b_update_task_status = false;
                    }
            //        update_review_units_status(s_task_id,s_wbs, i_status, s_wf_status);
                    wxLogMessage(_("项目:")+s_wbs+_("任务:")+s_task_id+_("评审完成!"));
                }

                delete wf_active;

                mils_used = wxGetLocalTimeMillis() - start_mils;

                wxLogMessage(s_task_id+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒")); //事件处理事件统计，截止点。


                child_item = tlc_task_list->GetNextSibling(child_item);
            }

  //          create_communication(s_task_id, s_com_status, s_com_status, true);

            tlc_task_list->DeleteChildren(sel_item);
            tlc_task_list->Delete(sel_item);


        }else
        {
            wxTreeItemId parent_id = tlc_task_list->GetItemParent(sel_item);

            s_task_id = tlc_task_list->GetItemText(parent_id, 1);
            s_com_status = tlc_task_list->GetItemText(parent_id, 15);

            int i_leaf = tlc_task_list->GetChildrenCount(parent_id);

            if(s_com_status == wxT("1")&&i_leaf==1)
            {
                wxLogMessage(_("issue分公司尚未回复，主评审任务无法全部完成!"));
                continue;
            }

            s_branch_id = tlc_task_list->GetItemText(parent_id, 8);

            s_group2 = wxT("G0016");

            s_operator2 = wxGetApp().get_operator_from_branch(s_branch_id, s_group2);


            s_wbs = tlc_task_list->GetItemText(sel_item,0);

            i_status = prj_str_to_status(tlc_task_list->GetItemText(sel_item, 10));
            start_mils = wxGetLocalTimeMillis();//事件处理事件统计，起始点。
            wf_active = new wf_operator(s_wbs, wf_str_review, t_template);
            l_proc_act = wf_active->get_current_process();

            l_proc_act->MoveToActive();

            wf_active->Pass_proc(s_operator1, s_group1, wxEmptyString, false);
            s_wf_status = _("评审审核");
            if(b_no_check)
            {

                l_proc_act->MoveToActive();

                wf_active->Pass_proc(s_operator2, s_group2, wxEmptyString, false);
                 s_wf_status = _("线下PO确认");

            }

            l_proc_act = 0;

     //       if (wf_active->update_instance(i_status,s_wf_status))
            if(update_review_units_status(s_task_id,s_wbs, i_status, s_wf_status))
            {

                if(b_no_check && i_leaf==1)
                {
                    update_review_task(s_task_id, 2);
                }
          //      update_review_units_status(s_task_id,s_wbs, i_status, s_wf_status);

                if(i_leaf==1)
                {
                    wxLogMessage(_("项目:")+s_wbs+_("任务:")+s_task_id+_("评审完成!"));
                }
                else
                {
                    wxLogMessage(_("项目:")+s_wbs+_("评审完成!"));
                }
            }

            delete wf_active;

            mils_used = wxGetLocalTimeMillis() - start_mils;

            tlc_task_list->Delete(sel_item);

            wxLogMessage(s_task_id+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒")); //事件处理事件统计，截止点。

        }
	}

	delete [] t_template;

	refresh_level();

}

/*
bool project_review_panel::update_review_status(const wxArrayString & array_units, int i_status, wxString s_wf_status)
{
	int i_count = array_units.GetCount();
	if (i_count ==0)
		return false;

	wxString str_sql = wxT("UPDATE s_unit_info SET status =")+NumToStr(i_status)+wxT(",wf_status='")+s_wf_status+wxT("',modify_date = '")+DateToAnsiStr(wxDateTime::Now())+
	                   wxT("',modify_emp_id = '")+gr_para.login_user+wxT("' WHERE ");

	for (int i=0; i<i_count; i++)
	{
		if (i==i_count-1)
		{
			str_sql = str_sql + wxT(" wbs_no ='")+array_units.Item(i)+wxT("';");
		}
		else
		{
			str_sql = str_sql + wxT(" wbs_no ='")+array_units.Item(i)+wxT("' OR ");
		}
	}

	return wxGetApp().app_sql_update(str_sql);
}*/

bool project_review_panel::update_review_task(const wxString s_task_id, int i_status)
{
    wxString str_sql = wxT("UPDATE s_review_info SET  modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("',active_status=")+NumToStr(i_status)+wxT(" WHERE \
                        review_task_id='")+s_task_id+wxT("';");
    return wxGetApp().app_sql_update(str_sql);
}

wxArrayString project_review_panel::get_steps_info(wxString & s_instance_id, wxString & s_workflow_id, wxString & s_now)
{
	wxString strSql = wxT("select operator_id, concat(action_id,'-',operator_id) as action_id, concat(action_name,'-', (select name from s_employee where employee_id= operator_id)) as step_info from v_task_list4 where workflow_id = '")+
	                  s_workflow_id+wxT("' and instance_id = '")+ s_instance_id+wxT("' and flow_ser < ")+ s_now+wxT(" and is_latest=true order by flow_ser ASC;");

//    wxLogMessage(strSql);
	wxPostgreSQLresult * _res =  wxGetApp().app_sql_select(strSql);

	wxArrayString array_result;
	if (_res->Status()!= PGRES_TUPLES_OK)
	{
		_res->Clear();
		return array_result;
	}

	int i_count = _res->GetRowsNumber();
	m_steps.Clear();

	wxString str;

	_res->MoveFirst();
	for (int i=0; i<i_count; i++)
	{
		str = _res->GetVal(wxT("action_id"));
		m_steps.Add(str);

		str = _res->GetVal(wxT("step_info"));
		array_result.Add(str);

		_res->MoveNext();
	}
	_res->Clear();

	return array_result;
}

void project_review_panel::OnButton_ReturnClick(wxCommandEvent& event)
{
	if (!gr_para.login_status)
	{
		wxLogMessage(_("尚未登陆,不能进行任何操作!"));
		return;
	}

	wxArrayTreeItemIds items;
	wxTreeItemId root = tlc_task_list->GetRootItem();

	wxArrayTreeItemIds::iterator iter;
	tlc_task_list->GetSelections( items );
	if (items.IsEmpty())
	{
		wxLogMessage(_("尚未选择项目，无法后续操作!"));
		return;
	}

	wxString aim_step;
	v_wf_action * t_template=0;
	wf_operator * wf_active;

	wxTextEntryDialog tdlg(this,_("退回提示输入:"),_("确认退回？"),wxT(""),wxOK | wxCANCEL | wxTE_MULTILINE,wxDefaultPosition );
	wxString str_desc;
	if (tdlg.ShowModal()== wxID_OK)
	{
		str_desc= tdlg.GetValue();
	}
	else return;

	wxLongLong mils_used, start_mils;
	wxString str_task_id, str_workflow_id, str_flow_ser;
	wxArrayString array_steps;

	t_template = get_template_action(wf_str_review);

	int i_status;
	wxString s_wf_status,s_wbs;
	bool b_step = true;

	for ( iter = items.begin(); iter<items.end(); iter++)
	{
		wxTreeItemId sel_item = *iter;
		if (tlc_task_list->GetItemParent(sel_item)==root&&sel_item.IsOk())
		{
            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_task_list->GetFirstChild(sel_item,cookie);

			str_task_id = tlc_task_list->GetItemText(sel_item, 1);
			str_workflow_id = wf_str_review;


            while(child_item.IsOk())
            {
                s_wbs = tlc_task_list->GetItemText(child_item,0);
                i_status = prj_str_to_status(tlc_task_list->GetItemText(child_item, 10));

                if(b_step)
                {
                    str_flow_ser = tlc_task_list->GetItemText(child_item, 17);

                    array_steps = get_steps_info(s_wbs, str_workflow_id, str_flow_ser);

                    if (array_steps.IsEmpty())
                    {
                        wxLogMessage(_("初始步骤无法退回!"));
                        return;
                    }

                    wxSingleChoiceDialog cdlg(this, _("请选择退回到哪一步"),_("退回选择"),array_steps);

                    if (cdlg.ShowModal() == wxID_OK)
                    {
                        int i_sel = cdlg.GetSelection();
                        aim_step = m_steps.Item(i_sel).Left(10);
                        s_wf_status = array_steps.Item(i_sel);
                    }
                    else return;

                    b_step = false;
                }

                start_mils = wxGetLocalTimeMillis();
                wf_active = new wf_operator(s_wbs, str_workflow_id, t_template);
                wf_active->Feed_back(str_desc, aim_step);

                int i_pos = s_wf_status.Find(wxT("-"));

                s_wf_status= s_wf_status.Left(i_pos);

    //            if (wf_active->update_instance(i_status,s_wf_status))
                 if(update_review_units_status(str_task_id,s_wbs, i_status, s_wf_status))
                {

        //            update_review_units_status(str_task_id,s_wbs, i_status, s_wf_status);
                    wxLogMessage(_("项目:")+s_wbs+_("退回评审任务:")+str_task_id+_("成功!"));
                }

                delete wf_active;


                mils_used = wxGetLocalTimeMillis() - start_mils;

                wxLogMessage(s_wbs+_("退回完成!  耗时:")+NumToStr(mils_used)+_("毫秒"));

                child_item = tlc_task_list->GetNextSibling(child_item);
            }

			tlc_task_list->DeleteChildren(sel_item);
			tlc_task_list->Delete(sel_item);
		}
	}

	delete [] t_template;
}

bool project_review_panel::create_communication(wxString s_task_id, wxString &s_status, wxString &s_context, bool b_close)
{
    wxString str_sql;

    if(s_status == wxT("2") || b_close)
    {
        str_sql = wxT("UPDATE s_review_communication SET issue_status= 3 WHERE review_task_id='")+s_task_id+wxT("' and issue_status = '")+s_status+wxT("';");

        str_sql.Replace(wxT("''"),wxT("NULL"));

        if(!wxGetApp().app_sql_update(str_sql))
        {
            return false;
        }else
        {
            s_status = wxT("3");
        }
    }

    if(!b_close)
    {


        str_sql = wxT("select count(*) as count from s_review_communication where review_task_id = '")+s_task_id + wxT("';");

        wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);
        if (_res->Status() != PGRES_TUPLES_OK)
        {
            _res->Clear();
            return false;
        }

        int i_count  = _res->GetInt(wxT("count"));
        i_count = i_count +1;

        _res->Clear();

        communication_dlg dlg;

        dlg.m_mode = 0;

        dlg.enable_control();

   //     dlg.b_show=false;
    //    dlg.show_control();

        if(dlg.ShowModal()==wxID_OK)
        {
//            str_status = wxT("1");
        }
        else
            return false;

        str_sql = wxT("INSERT INTO s_review_communication(review_task_id, item_no, issue_content, issue_status, issue_date, issue_emp_id, is_gad, is_spec) \
               VALUES('")+s_task_id+wxT("',")+NumToStr(i_count)+wxT(",'")+dlg.m_content+wxT("', 1 , '")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+
                  gr_para.login_user+wxT("',")+BoolToStr(dlg.b_gad)+wxT(",")+BoolToStr(dlg.b_spec)+wxT(");");

        str_sql.Replace(wxT("''"),wxT("NULL"));

        bool b_result = wxGetApp().app_sql_update(str_sql);

        if(b_result)
        {
            s_status =wxT("1");
            s_context = dlg.m_content;
        }

        return b_result;
    }

    return true;

}


bool project_review_panel::update_review_units_status(const wxString s_task_id, const wxString s_wbs_no, int i_status, wxString s_wf_status)
{
     wxString str_sql = wxT("UPDATE s_review_units SET unit_status =")+NumToStr(i_status)+wxT(",unit_wf_status='")+s_wf_status+wxT("',modify_date = '")+DateToAnsiStr(wxDateTime::Now())+
                               wxT("',modify_emp_id = '")+gr_para.login_user+wxT("' WHERE review_task_id ='")+ s_task_id+wxT("' and wbs_no ='")+s_wbs_no+wxT("';");

    return wxGetApp().app_sql_update(str_sql);
}

void project_review_panel::InitImageList()
{
    wxBitmap * bitmap = new wxBitmap(wxT("./res/info_icon.jpg"),wxBITMAP_TYPE_JPEG);
    int i_width = bitmap->GetWidth();
    int i_height = bitmap->GetHeight();
    int i_count  = i_width/i_height;

    m_imageList = new wxImageList(16, 16);

    // The order should be the same as for the enum elements.

    for ( int  n = 0; n < i_count; n++ )
    {
        m_imageList->Add(bitmap->GetSubBitmap(wxRect(n*16,0,16,16)));
    }
}

void project_review_panel::Onmi_com_logSelected(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }


    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_task_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_task_list->GetSelections( items );

    if(items.IsEmpty())
    {
        wxLogMessage(_("请选择任务！"));
        return;
    }

    wxArrayString a_task_id, a_info;
    wxString str;

    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item)==root)
        {
            str = tlc_task_list->GetItemText(sel_item, 1);
            if(a_task_id.Index(str)==wxNOT_FOUND)
            {
                a_task_id.Add(str);

                str = tlc_task_list->GetItemText(sel_item, 0);
                a_info.Add(str);

            }

        }else
        {
            wxTreeItemId parent_id = tlc_task_list->GetItemParent(sel_item);

            str = tlc_task_list->GetItemText(parent_id, 1);

            if(a_task_id.Index(str)==wxNOT_FOUND)
            {
                a_task_id.Add(str);

                str = tlc_task_list->GetItemText(parent_id, 0);
                a_info.Add(str);

            }
        }

    }

    review_communication_log l_dlg;

    l_dlg.refresh_list(a_task_id, a_info);

    l_dlg.ShowModal();
}

void project_review_panel::Onmi_processSelected(wxCommandEvent& event)
{
   if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }


    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_task_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_task_list->GetSelections( items );

    if(items.IsEmpty())
    {
        wxLogMessage(_("请选择任务！"));
        return;
    }

    wxArrayString a_wbs;
    wxString str;

    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item)==root)
        {
            wxTreeItemIdValue cookie_child;
            wxTreeItemId child_item = tlc_task_list->GetFirstChild(sel_item,cookie_child);
            while(child_item.IsOk())
            {
                str = tlc_task_list->GetItemText(child_item,0);
                if(a_wbs.Index(str)==wxNOT_FOUND)
                {
                    a_wbs.Add(str);
                }

                child_item= tlc_task_list->GetNextSibling(child_item);
            }


        }else
        {

            str = tlc_task_list->GetItemText(sel_item, 0);

            if(a_wbs.Index(str)==wxNOT_FOUND)
            {
                a_wbs.Add(str);
            }
        }

    }

    ins_proc_log ipl_dlg;
    ipl_dlg.init_review_list_header();
    ipl_dlg.Refresh_review_list(a_wbs);
    ipl_dlg.ShowModal();
}

void project_review_panel::Onmi_review_historySelected(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }


    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_task_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_task_list->GetSelections( items );

    if(items.IsEmpty())
    {
        wxLogMessage(_("请选择任务！"));
        return;
    }

    wxArrayString a_wbs;
    wxString str;

    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item)==root)
        {
            wxTreeItemIdValue cookie_child;
            wxTreeItemId child_item = tlc_task_list->GetFirstChild(sel_item,cookie_child);
            while(child_item.IsOk())
            {
                str = tlc_task_list->GetItemText(child_item,0);
                if(a_wbs.Index(str)==wxNOT_FOUND)
                {
                    a_wbs.Add(str);
                }

                child_item= tlc_task_list->GetNextSibling(child_item);
            }


        }else
        {

            str = tlc_task_list->GetItemText(sel_item, 0);

            if(a_wbs.Index(str)==wxNOT_FOUND)
            {
                a_wbs.Add(str);
            }
        }

    }

    ins_proc_log ipl_dlg;
    ipl_dlg.init_review_restart_header();
    ipl_dlg.Refresh_review_history(a_wbs);
    ipl_dlg.ShowModal();
}

void project_review_panel::Onmi_posSelected(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }

    wxString str;

    m_pos_id = tlc_task_list->GetRootItem();

    wxTextEntryDialog tdlg(this, _("请输入合同号或WBS NO"), _("快速查找"), wxT(""), wxOK | wxCANCEL, wxDefaultPosition);
    if (tdlg.ShowModal() == wxID_OK)
    {
        m_search_case = tdlg.GetValue();
    }
    else
    {
        return;
    }

    if(m_search_case.IsEmpty())
        return;

    m_pos_id = search_in_treelist(tlc_task_list, m_pos_id,m_search_case,0);
}

void project_review_panel::OnChar(wxTreeEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }

   long key_code = event.GetKeyCode();
 //   wxKeyEvent levent = event.GetKeyEvent();

    switch(key_code)
    {
    case WXK_CONTROL_F:

            if(m_search_case.IsEmpty())
                break;
            m_pos_id = search_in_treelist(tlc_task_list, m_pos_id, m_search_case,0);

        break;
    default:
        break;
    }

    event.Skip();
}

void project_review_panel::Onmi_draw_qtySelected(wxCommandEvent& event)
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

    wxArrayString array_group = wxGetApp().get_group();

    if(array_group.Index(wxT("G0002")) == wxNOT_FOUND)
        return;

    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_task_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_task_list->GetSelections( items );

    if(items.IsEmpty())
    {
        wxLogMessage(_("请选择任务！"));
        return;
    }

    wxString str_task_id, str_draw_qty;
    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if (tlc_task_list->GetItemParent(sel_item)==root&&sel_item.IsOk())
        {
            str_task_id = tlc_task_list->GetItemText(sel_item, 1);
            str_draw_qty = tlc_task_list->GetItemText(sel_item, 13);//20150813

            wxTextEntryDialog tdlg(this, _("请输入新的图纸套数"), _("图纸套数变更"), str_draw_qty, wxTextEntryDialogStyle, wxDefaultPosition);
            tdlg.SetTextValidator(wxFILTER_DIGITS);
            if (tdlg.ShowModal() == wxID_CANCEL)
                return;

            str_draw_qty = tdlg.GetValue();

            if(update_drawing_qty(str_task_id, str_draw_qty))
                tlc_task_list->SetItemText(sel_item, 13, str_draw_qty);//20150813
        }
    }
}


bool project_review_panel::update_drawing_qty(wxString s_task_id, wxString s_drawing_qty)
{
    wxString str_sql = wxT("UPDATE s_review_info SET review_drawing_qty =")+s_drawing_qty+wxT(",modify_date = '")+DateToAnsiStr(wxDateTime::Now())+
                       wxT("',modify_emp_id = '")+gr_para.login_user+wxT("' WHERE review_task_id ='")+ s_task_id+wxT("';");

    return wxGetApp().app_sql_update(str_sql);
}

