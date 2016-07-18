#include "project_author_panel.h"
#include "wfApp.h"
#include <wx/bitmap.h>
#include "utils/wf_operator.h"
#include "mydatepicker.h"
#include "proj_configure_history.h"
#include "evaluate_dlg.h"

//(*InternalHeaders(project_author_panel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(project_author_panel)
const long project_author_panel::ID_BUTTON1 = wxNewId();
const long project_author_panel::ID_BUTTON_REVIEW = wxNewId();
const long project_author_panel::ID_BUTTON3 = wxNewId();
const long project_author_panel::ID_BUTTON4 = wxNewId();
const long project_author_panel::ID_BUTTON_NSTD_LEVEL = wxNewId();
const long project_author_panel::ID_BUTTON_CHANGE_auth = wxNewId();
const long project_author_panel::ID_BUTTON2 = wxNewId();
const long project_author_panel::ID_LISTCTRL_RESPERSON = wxNewId();
const long project_author_panel::idMenu_Expand = wxNewId();
const long project_author_panel::idMenu_Collapse = wxNewId();
const long project_author_panel::idMenu_Un = wxNewId();
const long project_author_panel::idMenu_Au = wxNewId();
const long project_author_panel::idMenu_Review = wxNewId();
const long project_author_panel::idMenu_Freeze = wxNewId();
const long project_author_panel::idMenu_History = wxNewId();
const long project_author_panel::idMenu_Same = wxNewId();
const long project_author_panel::idMenu_all = wxNewId();
//*)
const long project_author_panel::ID_TREELISTCTRL_PROJ_LIST = wxNewId();

BEGIN_EVENT_TABLE(project_author_panel,wxPanel)
	//(*EventTable(project_author_panel)
	//*)
END_EVENT_TABLE()

project_author_panel::project_author_panel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(project_author_panel)
	wxStaticBoxSizer* StaticBoxSizer2;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("项目清单"));
	BoxSizer1->Add(StaticBoxSizer1, 5, wxALL|wxEXPAND, 0);
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("项目授权"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
	Button_Review = new wxButton(this, ID_BUTTON_REVIEW, _("项目审核"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_REVIEW"));
	BoxSizer2->Add(Button_Review, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button3 = new wxButton(this, ID_BUTTON3, _("变更配置完成日期"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer2->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button4 = new wxButton(this, ID_BUTTON4, _("审核退回"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	BoxSizer2->Add(Button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Nstd_level = new wxButton(this, ID_BUTTON_NSTD_LEVEL, _("更新非标等级"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_NSTD_LEVEL"));
	BoxSizer2->Add(Button_Nstd_level, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_AUTH = new wxButton(this, ID_BUTTON_CHANGE_auth, _("授权变更"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CHANGE_auth"));
	BoxSizer2->Add(Button_AUTH, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("刷新项目"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_TOP, 0);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("配置工程师"));
	lc_res = new wxListCtrl(this, ID_LISTCTRL_RESPERSON, wxDefaultPosition, wxSize(157,139), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_HRULES|wxLC_VRULES, wxDefaultValidator, _T("ID_LISTCTRL_RESPERSON"));
	StaticBoxSizer2->Add(lc_res, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(StaticBoxSizer2, 2, wxALL|wxEXPAND, 0);
	SetSizer(BoxSizer1);
	MenuItem1 = new wxMenuItem((&menu_authority), idMenu_Expand, _("全部展开(&E)"), _("项目展开"), wxITEM_NORMAL);
	menu_authority.Append(MenuItem1);
	MenuItem2 = new wxMenuItem((&menu_authority), idMenu_Collapse, _("全部收起(&C)"), _("项目全部收起"), wxITEM_NORMAL);
	menu_authority.Append(MenuItem2);
	menu_authority.AppendSeparator();
	MenuItem3 = new wxMenuItem((&menu_authority), idMenu_Un, _("显示未授权(&U)"), _("只显示未授权项目"), wxITEM_CHECK);
	menu_authority.Append(MenuItem3);
	MenuItem3->Check(true);
	MenuItem4 = new wxMenuItem((&menu_authority), idMenu_Au, _("显示已授权(&A)"), _("只显示已授权配置中的项目"), wxITEM_CHECK);
	menu_authority.Append(MenuItem4);
	mi_review = new wxMenuItem((&menu_authority), idMenu_Review, _("显示待审核(&R)"), _("显示待审核"), wxITEM_CHECK);
	menu_authority.Append(mi_review);
	MenuItem5 = new wxMenuItem((&menu_authority), idMenu_Freeze, _("含暂停项目(&F)"), _("项目含已暂停项目"), wxITEM_CHECK);
	menu_authority.Append(MenuItem5);
	menu_authority.AppendSeparator();
	MenuItem6 = new wxMenuItem((&menu_authority), idMenu_History, _("显示配置历史(&H)"), _("重排产项目显示配置历史"), wxITEM_NORMAL);
	menu_authority.Append(MenuItem6);
	MenuItem7 = new wxMenuItem((&menu_authority), idMenu_Same, _("同一项目其他配置情况(&S)"), _("同一项目其他配置情况"), wxITEM_NORMAL);
	menu_authority.Append(MenuItem7);
	MenuItem8 = new wxMenuItem((&menu_authority), idMenu_all, _("项目下所有梯配置情况(&T)"), _("项目下所有梯配置情况"), wxITEM_NORMAL);
	menu_authority.Append(MenuItem8);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&project_author_panel::OnButton1Click);
	Connect(ID_BUTTON_REVIEW,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&project_author_panel::OnButton_ReviewClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&project_author_panel::OnButton3Click);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&project_author_panel::OnButton4Click);
	Connect(ID_BUTTON_NSTD_LEVEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&project_author_panel::OnButton_Nstd_levelClick);
	Connect(ID_BUTTON_CHANGE_auth,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&project_author_panel::OnButton_AUTHClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&project_author_panel::OnButton2Click);
	Connect(ID_LISTCTRL_RESPERSON,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&project_author_panel::Onlc_resItemActivated);
	Connect(idMenu_Expand,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_author_panel::OnMenuItem1Selected);
	Connect(idMenu_Collapse,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_author_panel::OnMenuItem2Selected);
	Connect(idMenu_Un,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_author_panel::OnMenuItem3Selected);
	Connect(idMenu_Au,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_author_panel::OnMenuItem4Selected);
	Connect(idMenu_Review,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_author_panel::Onmi_reviewSelected);
	Connect(idMenu_Freeze,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_author_panel::OnMenuItem5Selected);
	Connect(idMenu_History,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_author_panel::OnMenuItem6Selected);
	Connect(idMenu_Same,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_author_panel::OnMenuItem7Selected);
	Connect(idMenu_all,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_author_panel::OnMenuItem8Selected);
	Connect(wxEVT_PAINT,(wxObjectEventFunction)&project_author_panel::OnPaint);
	//*)

    init_list_header();

    BuildDataViewCtrl();
    StaticBoxSizer1->Add(tlc_proj_list, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0 );
    Layout();

    Connect(ID_TREELISTCTRL_PROJ_LIST,wxEVT_COMMAND_TREE_ITEM_MENU,(wxObjectEventFunction)&project_author_panel::OnTreeListCtrlRightClick);


    m_group= wxGetApp().get_only_group();

    m_leader = wxGetApp().is_leader(m_group);

    if(m_leader&&(m_group=="G0006"||m_group=="G0007"||m_group=="G0008"))
    {
        Button4->Show(true);
        mi_review->Enable(true);
 //       Button1->SetLabel(_("项目授权"));
        Button_Review->Show(false);
        Button4->Show(false);
        refresh_new_res_list(m_group);
        Button_AUTH->Show(false);
    }else if(m_leader && m_group == "G0014")
    {
        Button4->Show(false);
  //      Button1->SetLabel(_("项目授权"));
        Button_Review->Show(false);
        mi_review->Enable(false);
        Button_AUTH->Show(true);

        refresh_res_list("CF");
    }
    else if (m_leader && m_group=="G0004")
    {
        Button4->Show(false);
  //      Button1->SetLabel(_("项目授权"));
        Button_Review->Show(false);
        mi_review->Enable(true);
        Button_AUTH->Show(true);

        refresh_res_list("CFM");

    }else
    {
        MenuItem3->Enable(false);
        MenuItem4->Enable(false);
        mi_review->Enable(false);
        MenuItem5->Enable(false);
        Button_AUTH->Show(false);
        return;
    }


    m_case = 0;

    str_freeze.Empty();

    wxString strSql = wxT("SELECT  concat(contract_id,' ', project_name) as project_name, project_id,\
                         instance_id as wbs_no, lift_no, elevator_id, elevator_type, project_catalog, action_id, action_name, req_configure_finish, special_info, \
                         (SELECT concat(employee_id,'-',name) from s_employee WHERE employee_id = operator_id) as operator, status, is_urgent, nonstd_level,conf_batch_id from v_task_list1 WHERE action_id = 'AT00000003' \
                         AND is_active = true AND operator_id = '")+gr_para.login_user+ wxT("' ");

    Set_Clause(strSql);

    str_freeze = wxT(" AND status != '4' ");

    refresh_list();

}

project_author_panel::~project_author_panel()
{
	//(*Destroy(project_author_panel)
	//*)
/*	if(!m_project_model->IsBlank())
        m_project_model->DeleteAllItems();*/
    delete m_imageList;

    wxTreeItemId root = tlc_proj_list->GetRootItem();
    tlc_proj_list->DeleteChildren (root);
    tlc_proj_list->DeleteRoot();
}

void project_author_panel::InitImageList()
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

void project_author_panel::BuildDataViewCtrl()
{
    InitImageList();

    tlc_proj_list = new wxcode::wxTreeListCtrl(this, ID_TREELISTCTRL_PROJ_LIST ,
                                  wxDefaultPosition, wxDefaultSize,
                                  wxTR_DEFAULT_STYLE| wxTR_COLUMN_LINES|wxTR_HIDE_ROOT|wxTR_ROW_LINES|wxTR_MULTIPLE | wxTR_FULL_ROW_HIGHLIGHT);

    tlc_proj_list->SetImageList(m_imageList);


    tlc_proj_list->AddColumn(_("项目信息"),200,wxALIGN_LEFT,-1,true,false);//0
    tlc_proj_list->AddColumn(_("索引"),0,wxALIGN_LEFT,-1,false,false);//1
    tlc_proj_list->AddColumn(_("梯号"),50,wxALIGN_LEFT, -1,true,false );//2
    tlc_proj_list->AddColumn(_("梯型"),100,wxALIGN_LEFT, -1,true,false );//3
    tlc_proj_list->AddColumn(_("项目类型"),100,wxALIGN_LEFT, -1,true,false );//4

    tlc_proj_list->AddColumn(_("action_id"), 0, wxALIGN_LEFT, -1,false, false);//5
    tlc_proj_list->AddColumn(_("任务状态"), 60, wxALIGN_LEFT, -1, true, false);//6

    tlc_proj_list->AddColumn(_("配置完成日期"),100,wxALIGN_LEFT, -1,true,false);//7-5
    tlc_proj_list->AddColumn(_("负责人"),100,wxALIGN_LEFT, -1,true,false);//8-6
    tlc_proj_list->AddColumn(_("项目状态"),70,wxALIGN_LEFT,-1,true,false);//9-7
    tlc_proj_list->AddColumn(_("是否紧急"),0,wxALIGN_LEFT,-1,false,false);//10-8
    tlc_proj_list->AddColumn(_("非标等级"),100,wxALIGN_LEFT,-1,true,false);//11-9
    tlc_proj_list->AddColumn(_("梯型ID"),0,wxALIGN_LEFT,-1,false,false);//12
    tlc_proj_list->AddColumn(_("任务批次"), 0, wxALIGN_LEFT, -1, false, false);//13
    tlc_proj_list->AddColumn(_("特殊标识"), 100, wxALIGN_LEFT, -1, true, false); //14

    wxTreeItemId root = tlc_proj_list->AddRoot (_("配置项目"));
}

void project_author_panel::init_list_header()
{
    wxListItem itemCol;
    itemCol.SetText(_("配置工程师"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lc_res->InsertColumn(0, itemCol);

    itemCol.SetText(_("分配梯数"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(80);
    lc_res->InsertColumn(1, itemCol);

    itemCol.SetText(_("配置组"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lc_res->InsertColumn(2, itemCol);

    itemCol.SetText(_("组号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(0);
    lc_res->InsertColumn(3, itemCol);
}

void project_author_panel::refresh_list()
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


    wxTreeItemId root = tlc_proj_list->GetRootItem();
    tlc_proj_list->DeleteChildren (root);


    wxString strSql = where_clause + str_freeze +  wxT(" ORDER BY req_configure_finish,instance_id,project_catalog, elevator_type ASC ;");

    //wxLogMessage(strSql);
    wxPostgreSQLresult* _res = wxGetApp().app_sql_select(strSql);

 //   wxSleep(10);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int irow = _res->GetRowsNumber();
    int i_status;
    bool is_urgent;

    wxString l_index, s_project_name, s_wbs, s_lift_id, s_elevator_type, s_project_type, s_req_finish, s_res_person,s_action_id, s_action_name, s_lifttype_id, s_index, s_special_info;

    wxTreeItemId prj_item,leaf_item;
    int i_type;

    _res->MoveFirst();


    for(int i = 0; i<irow;i++)
    {
        s_project_name = _res->GetVal(wxT("project_name"));
        s_index=_res->GetVal(wxT("conf_batch_id"));

        if(_res->GetVal(wxT("project_id")) != l_index || s_req_finish != DateToStrFormat(_res->GetDate(wxT("req_configure_finish"))) || s_elevator_type != _res->GetVal(wxT("elevator_type"))|| i_type != _res->GetInt(wxT("project_catalog"))|| s_action_id !=_res->GetVal(wxT("action_id")))
        {
            l_index = _res->GetVal(wxT("project_id"));
            prj_item = tlc_proj_list->AppendItem(root,s_project_name+"-"+l_index);
            tlc_proj_list->SetItemText(prj_item,1,l_index);
            tlc_proj_list->SetItemText(prj_item, 13, s_index);

        }

        s_wbs = _res->GetVal(wxT("wbs_no"));
        s_lift_id = _res->GetVal(wxT("lift_no"));
        s_elevator_type = _res->GetVal(wxT("elevator_type"));
        i_type = _res->GetInt(wxT("project_catalog"));
        s_project_type = prj_catalog_to_str(i_type);
        s_action_id = _res->GetVal(wxT("action_id"));
        s_action_name = _res->GetVal(wxT("action_name"));

        s_req_finish = DateToStrFormat(_res->GetDate(wxT("req_configure_finish")));
        if(m_case!=0)
            s_res_person = _res->GetVal(wxT("operator"));
        else s_res_person = wxEmptyString;

        is_urgent = _res->GetBool(wxT("is_urgent"));
        i_status = _res->GetInt(wxT("status"));

        s_lifttype_id = _res->GetVal(wxT("elevator_id"));
        s_special_info= _res->GetVal(wxT("special_info"));
/*
        if(i_status == 4)
             leaf_item = tlc_proj_list->AppendItem(prj_item,wxEmptyString,0,0);
        else if(is_urgent)
             leaf_item = tlc_proj_list->AppendItem(prj_item,wxEmptyString,2,2);
        else
             leaf_item = tlc_proj_list->AppendItem(prj_item,wxEmptyString,-1,-1);
*/
        leaf_item = tlc_proj_list->AppendItem(prj_item,s_wbs,-1,-1);
        tlc_proj_list->SetItemText(leaf_item, 1, l_index);
//        tlc_proj_list->SetItemText(leaf_item, 0, s_wbs);
        tlc_proj_list->SetItemText(leaf_item, 2, s_lift_id);
        tlc_proj_list->SetItemText(leaf_item, 3, s_elevator_type);
        tlc_proj_list->SetItemText(leaf_item, 4, s_project_type);
        tlc_proj_list->SetItemText(leaf_item, 5, s_action_id);
        tlc_proj_list->SetItemText(leaf_item, 6, s_action_name);
        tlc_proj_list->SetItemText(leaf_item, 7, s_req_finish);
        tlc_proj_list->SetItemText(leaf_item, 8, s_res_person);
        tlc_proj_list->SetItemText(leaf_item, 9, prj_status_to_str(i_status));
        tlc_proj_list->SetItemText(leaf_item, 10, BoolToStr(is_urgent));
        tlc_proj_list->SetItemText(leaf_item, 11, nstd_level_to_str(_res->GetInt(wxT("nonstd_level"))));
        tlc_proj_list->SetItemText(leaf_item, 12, s_lifttype_id);
        tlc_proj_list->SetItemText(leaf_item, 13, s_index);
        tlc_proj_list->SetItemText(leaf_item, 14, s_special_info);

        _res->MoveNext();
    }

    refresh_project_level();
 //   tlc_proj_list->Expand(root);
    _res->Clear();

}

bool project_author_panel::make_evaluate(wf_process * s_process, wxString s_batch_id)
{
     v_wf_instance active_step, eval_step;

     s_process->MoveToActive();

     active_step = s_process->get_cur_instance_action();

     if(!active_step.s_action.b_is_evaluate && !active_step.s_action.b_is_check)
        return true;

     bool  b_move;
     int i_step;

     do{
        i_step = s_process->MovePrevious();

        if(i_step == 0)
            return true;

        eval_step = s_process->get_cur_instance_action();

        if(eval_step.s_action.b_is_evaluate)
            return true;
/*
        if(eval_step.s_action.b_is_evaluate&&active_step.s_action.b_is_evaluate)
            return true;

        if(eval_step.s_action.b_is_check && active_step.s_action.b_is_check)
            return true;*/

        if(eval_step.s_action.b_is_need_eval)
            b_move = false;
        else
            b_move = true;

     }while(b_move);

     evaluate_dlg dlg;

     if(active_step.s_action.b_is_evaluate)
     {
        dlg.m_evaluator_id = active_step.s_action.s_operator_id;
        dlg.m_status = 2;
     }

     if(active_step.s_action.b_is_check)
     {
        dlg.m_check_id = active_step.s_action.s_operator_id;
        dlg.m_status = 1;
     }

     dlg.m_action_id = eval_step.s_action.s_action_id;
     dlg.m_workflow_id = eval_step.s_action.s_workflow_id;
     dlg.m_operator_id = eval_step.s_action.s_operator_id;

     dlg.m_op_start_date = DateToAnsiStr(eval_step.t_start);
     dlg.m_op_finish_date = DateToAnsiStr(eval_step.t_finish);
     dlg.m_task = s_batch_id;

     if(dlg.ShowModal() == wxID_CANCEL)
        return false;

     return true;


}

 void project_author_panel::refresh_project_level()
 {

    int i_count_freeze;
    int i_count_urgent;
    int i_count_pre;
    int i_count_lean;
    int i_count;

    wxTreeItemId root = tlc_proj_list->GetRootItem();
    wxString str_nonstd_level;

    wxTreeItemIdValue cookie;
    wxTreeItemId item = tlc_proj_list->GetFirstChild(root,cookie);
    wxString str_group, str_date, str_operator, str_type, str_project_catalog,str_status,str, str_action_name;
    wxString s_special_info;
     wxArrayString a_lift_no;

    while(item.IsOk())
    {
        s_special_info=wxEmptyString;
        wxTreeItemIdValue cookie_child;
        wxTreeItemId child_item = tlc_proj_list->GetFirstChild(item,cookie_child);
        str_group.Empty();
        i_count_freeze = 0;
        i_count_urgent = 0;
        i_count_pre = 0;
        i_count_lean = 0;
        str_operator.Empty();
        a_lift_no.Clear();
        str_action_name.Empty();

        while(child_item.IsOk())
        {

            str = tlc_proj_list->GetItemText(child_item, 11);
            if(!str_nonstd_level.Contains(str))
            {
                if(str_nonstd_level.IsEmpty())
                    str_nonstd_level=str;
                else
                    str_nonstd_level=str_nonstd_level+wxT("+")+str;
            }


            str_group = tlc_proj_list->GetItemText(child_item,2);
            a_lift_no.Add(str_group);

            if(!str_operator.Contains(tlc_proj_list->GetItemText(child_item,8 ))&& m_case==1)
                str_operator= str_operator+wxT(";")+tlc_proj_list->GetItemText(child_item,8 );

            str_project_catalog=  tlc_proj_list->GetItemText(child_item,4);
            str_date = tlc_proj_list->GetItemText(child_item, 7);
            str_type = tlc_proj_list->GetItemText(child_item, 3);
            str_status = tlc_proj_list->GetItemText(child_item,9);
            str_action_name = tlc_proj_list->GetItemText(child_item, 6);


            if(prj_str_to_status(tlc_proj_list->GetItemText(child_item,9))==4)
            {
                tlc_proj_list->SetItemBackgroundColour(child_item, *wxRED);
                i_count_freeze++;
            }else if(str_project_catalog == _("Lean Project"))
            {
                tlc_proj_list->SetItemBackgroundColour(child_item,  *wxYELLOW);
                i_count_lean++;
            }else if(str_project_catalog == _("Pre-engineering"))
            {
                tlc_proj_list->SetItemBackgroundColour(child_item,  *wxCYAN);
                i_count_pre++;
            }
            else if(tlc_proj_list->GetItemText(child_item,10)==wxT("true"))
            {
                tlc_proj_list->SetItemBackgroundColour(child_item, *wxGREEN);
                i_count_urgent++;
            }else tlc_proj_list->SetItemBackgroundColour(child_item, *wxWHITE);

            if(!s_special_info.Contains(tlc_proj_list->GetItemText(child_item, 14)))
            {
                if(s_special_info.IsEmpty())
                {
                    s_special_info = tlc_proj_list->GetItemText(child_item, 14);
                }else
                {
                    s_special_info = s_special_info+wxT("+")+tlc_proj_list->GetItemText(child_item, 14);
                }
            }

            child_item = tlc_proj_list->GetNextSibling(child_item);

        }

        str_group = Combine_lift_no(a_lift_no);



        tlc_proj_list->SetItemText(item, 11, str_nonstd_level);
        str_nonstd_level.Clear();

        i_count = tlc_proj_list->GetChildrenCount(item);
        if(i_count_freeze == i_count)
            tlc_proj_list->SetItemBackgroundColour(item, *wxRED);
        else if(i_count_freeze !=0)
            tlc_proj_list->SetItemImage(item,0, 0);
        else if(i_count_lean == i_count )
               tlc_proj_list->SetItemBackgroundColour(item, *wxYELLOW);
        else if(i_count_lean !=0)
              tlc_proj_list->SetItemImage(item,0,4);
        else if(i_count_pre == i_count )
               tlc_proj_list->SetItemBackgroundColour(item, *wxCYAN);
        else if(i_count_lean !=0)
              tlc_proj_list->SetItemImage(item,0,3);
        else if(i_count_urgent == i_count)
            tlc_proj_list->SetItemBackgroundColour(item, *wxGREEN);
        else if(i_count_urgent !=0)
            tlc_proj_list->SetItemImage(item,0,2);
        else
        {
            tlc_proj_list->SetItemBackgroundColour(item, *wxWHITE);
            tlc_proj_list->SetItemImage(item,0,-1);
        }

        tlc_proj_list->SetItemText(item, 2, str_group);
        tlc_proj_list->SetItemText(item, 3, str_type+wxT("*")+NumToStr(i_count)+_("台"));
        tlc_proj_list->SetItemText(item, 4, str_project_catalog);
        tlc_proj_list->SetItemText(item, 6, str_action_name);
        tlc_proj_list->SetItemText(item, 7, str_date);
        tlc_proj_list->SetItemText(item, 9, str_status);
        tlc_proj_list->SetItemText(item, 14, s_special_info);
        if(m_case!=0)
        {
           str_operator.Remove(0,1);
           tlc_proj_list->SetItemText(item, 8, str_operator);
        }

        item = tlc_proj_list->GetNextSibling(item);
    }
 }

void project_author_panel::refresh_new_res_list(wxString s_group)
{
    lc_res->DeleteAllItems();

    wxString strSql = wxT("SELECT concat(employee_id,'-',name) AS res_person, (select count(*) from l_proc_act \
                          where operator_id = employee_id AND is_active=true AND action_id = 'AT00000004') AS proj_qty, \
                          group_name, group_id FROM v_group_role WHERE group_id = '")+s_group+wxT("'  AND plant = '")+gr_para.plant+wxT("' and status=true  and role_id='R2' ORDER BY group_name ,res_person ASC;");
    wxPostgreSQLresult* _res = wxGetApp().app_sql_select(strSql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        return;
    }

    int irow = _res->GetRowsNumber();

    _res->MoveFirst();
    for(int i=0; i<irow; i++)
    {
        wxString str = _res->GetVal(wxT("res_person"));
        long tmp = lc_res->InsertItem(i,str);
        lc_res->SetItemData(tmp, i);

        str = _res->GetVal(wxT("proj_qty"));
        lc_res->SetItem(tmp,1,str);

        str = _res->GetVal(wxT("group_name"));
        lc_res->SetItem(tmp,2,str);

        str = _res->GetVal(wxT("group_id"));
        lc_res->SetItem(tmp,3,str);
        _res->MoveNext();
    }

    _res->Clear();
}

void project_author_panel::refresh_res_list(wxString s_group_cata)
{
    lc_res->DeleteAllItems();

    wxString strSql = wxT("SELECT concat(employee_id,'-',name) AS res_person, (select count(*) from l_proc_act \
                          where operator_id = employee_id AND is_active=true AND action_id = 'AT00000004') AS proj_qty, \
                          group_name, group_id FROM v_group_member WHERE group_catalog like '%")+s_group_cata+wxT("%' AND plant = '")+gr_para.plant+wxT("' and status=true ORDER BY group_name ,res_person ASC;");
    wxPostgreSQLresult* _res = wxGetApp().app_sql_select(strSql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        return;
    }

    int irow = _res->GetRowsNumber();

    _res->MoveFirst();
    for(int i=0; i<irow; i++)
    {
        wxString str = _res->GetVal(wxT("res_person"));
        long tmp = lc_res->InsertItem(i,str);
        lc_res->SetItemData(tmp, i);

        str = _res->GetVal(wxT("proj_qty"));
        lc_res->SetItem(tmp,1,str);

        str = _res->GetVal(wxT("group_name"));
        lc_res->SetItem(tmp,2,str);

        str = _res->GetVal(wxT("group_id"));
        lc_res->SetItem(tmp,3,str);
        _res->MoveNext();
    }

    _res->Clear();
}

void project_author_panel::OnButton1Click(wxCommandEvent& event)
{
    if(!m_leader)
        return;

    wxString s_flag=wxEmptyString;

    bool b_way=false;

    if(m_group==wxT("G0007"))
    {
        s_flag=wxT("E");
        b_way = true;
    }
    else if(m_group==wxT("G0006")||m_group==wxT("G0008"))
    {
         s_flag =wxT("M");
         b_way = true;
    }

    if(m_case==1)
    {
        wxLogMessage(_("目前阁下停留在已授权项目列表状态，无法操作，请切换到待授权项目状态"));
        return;
    }


    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_proj_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_proj_list->GetSelections( items );

    wxString str_batch_att = wxDateTime::Now().Format("%Y%m%d%H%M%S");
    wxString str_batch_id;
    if(items.IsEmpty())
    {
        wxLogMessage(_("请选择项目！"));
        return;
    }

    wxString s_wbs, s_operator, s_group, s_res;

    long l_item = -1;
    l_item = lc_res->GetNextItem(l_item,  wxLIST_NEXT_ALL,  wxLIST_STATE_SELECTED);

    if(l_item == -1)
    {
        wxLogMessage(_("请选择操作人员！"));
        return;
    }
    else{

        s_res = lc_res->GetItemText(l_item, 0);
        s_operator = s_res.Left(8);
        s_group = lc_res->GetItemText(l_item, 3);
    }

     if(wxMessageBox(_("所选项目确认授权给")+s_res,_("授权确认："),wxOK|wxCANCEL,this)==wxCANCEL)
    {
        return;
    }


    wxString str_workflow_id, str_temp;


    wf_operator * wf_active=0;
    wf_operator_ex *wf_new_active=0;

    v_wf_instance now_step, next_step;


    wxLongLong mils_used, start_mils;
    int i_status;

    v_wf_action *t_template = get_template_action(wf_str_configure);
    v_wf_action * t_new_template = get_template_action(wf_str_new_config);

    wxTreeItemId del_item;
    wxString s_mat_req, s_lift_type, s_catalog, s_link_list, s_nstd_id;

    wxArrayString a_wbs, a_lift_type, a_catalog, a_mat_req;

    bool b_root = true;

    for( iter = items.begin(); iter<items.end(); iter++)
    {

        wxTreeItemId sel_item = *iter;

        if(tlc_proj_list->GetItemParent(sel_item)==root)
        {
            if(b_way)
            {
                s_nstd_id = wxGetApp().get_ser_id(wxT("l_nonstd_app_header"), wxT("nonstd_id"));
            }

            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_proj_list->GetFirstChild(sel_item,cookie);
            s_link_list.Empty();
            while(child_item.IsOk())
            {

                if(prj_str_to_status(tlc_proj_list->GetItemText(child_item, 9))==4)
                {
                    child_item = tlc_proj_list->GetNextSibling(child_item);
                    continue;
                }

                start_mils = wxGetLocalTimeMillis();//事件处理事件统计，起始点。

                i_status = prj_str_to_status(tlc_proj_list->GetItemText(child_item,9));
                s_wbs = tlc_proj_list->GetItemText(child_item, 0);

                if(s_link_list.IsEmpty())
                {
                    s_link_list = s_wbs;
                }else
                {
                    s_link_list = s_link_list+wxT(";")+s_wbs;
                }

                if(i_status==4)
                {
                    wxLogMessage(s_wbs+_("已经暂停，无法操作!"));
                    continue;
                }

                if(b_way)
                {
                    wf_new_active = new wf_operator_ex(s_wbs, wf_str_new_config,t_new_template, s_flag);

                    wf_new_active->Pass_proc(s_operator, s_group, wxEmptyString, true);

                    wf_new_active->update_instance(i_status);

                    update_unit_nstd_id(s_wbs, s_nstd_id, s_flag);


                    delete wf_new_active;

                }
                else
                {


                    wf_active = new wf_operator(s_wbs, wf_str_configure, t_template);

                    wf_active->Pass_proc(s_operator, s_group, wxEmptyString, true);

                    wf_active->update_instance(i_status);
                    delete wf_active;

                }


                mils_used = wxGetLocalTimeMillis() - start_mils;

                wxLogMessage(s_wbs+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒")); //事件处理事件统计，截止点。

                del_item = child_item;
                child_item = tlc_proj_list->GetNextSibling(child_item);
                tlc_proj_list->Delete(del_item);

                str_batch_id = s_wbs.Left(10)+wxT("-")+str_batch_att;

                build_batch_id(str_batch_id,s_wbs);

            }

           if(!tlc_proj_list->HasChildren(sel_item))
           {
                if(b_way)
                {
                     save_header(s_nstd_id, s_link_list);
                     save_item(s_nstd_id, s_link_list, s_flag, s_operator);
                }

                tlc_proj_list->Delete(sel_item);

           }
        }else if(sel_item.IsOk())
        {


                if(prj_str_to_status(tlc_proj_list->GetItemText(sel_item, 9))==4)
                {
                    continue;
                }


                wxTreeItemId parent_item = tlc_proj_list->GetItemParent(sel_item);

                if(tlc_proj_list->IsSelected(parent_item))
                {
                     continue;
                }

                start_mils = wxGetLocalTimeMillis();//事件处理事件统计，起始点。

              b_root = false;
              s_wbs = tlc_proj_list->GetItemText(sel_item, 0);
              s_lift_type = tlc_proj_list->GetItemText(sel_item, 3);
              s_catalog = tlc_proj_list->GetItemText(sel_item, 4);
              s_mat_req = tlc_proj_list->GetItemText(sel_item, 7);

                i_status = prj_str_to_status(tlc_proj_list->GetItemText(sel_item,9));

                if(i_status==4)
                {
                    wxLogMessage(s_wbs+_("已经暂停，无法操作!"));
                    continue;
                }


                if(b_way)
                {
                    a_wbs.Add(s_wbs);
                    a_lift_type.Add(s_lift_type);
                    a_catalog.Add(s_catalog);
                    a_mat_req.Add(s_mat_req);

                    wf_new_active = new wf_operator_ex(s_wbs, wf_str_new_config,t_new_template, s_flag);

                    wf_new_active->Pass_proc(s_operator, s_group, wxEmptyString, true);

                    wf_new_active->update_instance(i_status);

                    delete wf_new_active;

                }
                else
                {

                    wf_active = new wf_operator(s_wbs, wf_str_configure, t_template);

                    wf_active->Pass_proc(s_operator, s_group, wxEmptyString, true);

                    wf_active->update_instance(i_status);

                    delete wf_active;
                }


                mils_used = wxGetLocalTimeMillis() - start_mils;

                wxLogMessage(s_wbs+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒")); //事件处理事件统计，截止点。



                tlc_proj_list->Delete(sel_item);

                if(tlc_proj_list->GetChildrenCount(parent_item)== 0)
                    tlc_proj_list->Delete(parent_item);

                str_batch_id = s_wbs.Left(10)+wxT("-")+str_batch_att;

                build_batch_id(str_batch_id,s_wbs);


        }

    }

    if(b_way&&!b_root)
    {
        create_nstd_task(a_wbs, a_lift_type, a_catalog, a_mat_req, s_flag, s_operator);
    }

    if(t_template)
        delete  [] t_template;

    if(t_new_template)
        delete []  t_new_template;

    if(m_leader&&(m_group=="G0006"||m_group=="G0007"||m_group=="G0008"))
    {
        refresh_new_res_list(m_group);
    }else if(m_leader && m_group == "G0014")
        refresh_res_list("CF");
    else if (m_leader && m_group=="G0004")
        refresh_res_list("CFM");
    else
        return;

    refresh_list();
}

void project_author_panel::OnButton_ReviewClick(wxCommandEvent& event)
{
    if(!m_leader)
        return;

    if(m_case!=2)
    {
        wxMessageBox(_("目前阁下没有切换到项目审核状态，无法操作，请切换到项目审核状态"),_("提示"));
        return;
    }

    wxString s_flag=wxEmptyString;

    bool b_way=false;

    if(m_group==wxT("G0007"))
    {
        s_flag=wxT("E");
        b_way = true;
    }
    else if(m_group==wxT("G0006")||m_group==wxT("G0008"))
    {
         s_flag =wxT("M");
         b_way = true;
    }else
        b_way=false;

    if(b_way)
    {
        pass_proc_new(s_flag);
    }else
    {
        pass_proc();
    }
}

void project_author_panel::pass_proc_new(wxString s_flag)
{

    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_proj_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_proj_list->GetSelections( items );

    if(items.IsEmpty())
    {
        wxLogMessage(_("请选择项目！"));
        return;
    }

    wxTreeItemId sel_item, child_item;
    wxTreeItemIdValue cookie;
    wxTreeItemId del_item;

    wxArrayString a_operator, a_flag;
    wxLongLong mils_used, start_mils;
    wxString s_wbs,s_lift_type,s_flag_ex;
    wxString s_group, s_operator, s_role, s_index;

    wf_process * l_proc_act =0;

    v_wf_instance now_step, next_step;
    bool b_active;

    v_wf_action * t_new_template=get_template_action(wf_str_new_config);
    wf_operator_ex * wf_new_active=0;

    for(iter=items.begin();iter<items.end();iter++)
    {
        sel_item = *iter;

        if(tlc_proj_list->GetItemParent(sel_item)==root)
        {
           child_item = tlc_proj_list->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {
                b_active=true;
                a_operator.Clear();
                a_flag.Clear();

                s_wbs = tlc_proj_list->GetItemText(child_item, 0);

                s_lift_type = tlc_proj_list->GetItemText(child_item, 12);

                start_mils = wxGetLocalTimeMillis();

                wf_new_active = new wf_operator_ex(s_wbs, wf_str_new_config, t_new_template, s_flag);

                l_proc_act = wf_new_active->get_current_process();

                l_proc_act->MoveToActive();
                now_step = l_proc_act->get_cur_instance_action();

                if(now_step.s_action.s_operator_id!=gr_para.login_user && now_step.is_active)
                {

                    child_item = tlc_proj_list->GetNextSibling(child_item);
                    continue;
                }

                if(l_proc_act->GetCurrentStep() == l_proc_act->GetTotalSteps()&&l_proc_act->GetTotalSteps()!= now_step.s_action.i_total_flow)
                {

                    next_step.s_action = t_new_template[now_step.s_action.i_flow_ser];
                    next_step.s_instance_id = s_wbs;
                }
                else if(l_proc_act->GetCurrentStep() != l_proc_act->GetTotalSteps())
                {
                    next_step = l_proc_act->get_next_instance_action();
                    if(next_step.s_action.i_flow_ser != now_step.s_action.i_flow_ser+1)
                    {
                        next_step.s_action = t_new_template[now_step.s_action.i_flow_ser];
                        next_step.s_instance_id = s_wbs;
                    }
                }

                s_group = next_step.s_action.s_group_id;
                s_operator = next_step.s_action.s_operator_id;
                s_role = next_step.s_action.s_role_id;


                b_active = check_other_way(s_wbs, s_flag);

                a_flag = get_other_way(s_lift_type, s_flag);
                s_flag_ex = s_flag;

                int i_flag = a_flag.GetCount();

                for(int k=0; k<i_flag; k++)
                {
                    s_flag_ex = s_flag_ex+wxT("+")+a_flag.Item(k);
                }


                wf_new_active->Pass_proc(s_operator, s_group, wxEmptyString, false,s_flag_ex, b_active);
                l_proc_act = 0;
                if(wf_new_active)
                    delete wf_new_active;

                del_item = child_item;
                child_item = tlc_proj_list->GetNextSibling(child_item);
//
                tlc_proj_list->Delete(del_item);

                if(tlc_proj_list->GetChildrenCount(sel_item)==0)
                    tlc_proj_list->Delete(sel_item);

                mils_used = wxGetLocalTimeMillis() - start_mils;

                wxLogMessage(s_wbs+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒"));
            }
        }else if(sel_item.IsOk())
        {
            b_active=true;
            a_operator.Clear();
            a_flag.Clear();

            s_wbs = tlc_proj_list->GetItemText(sel_item, 0);
            s_lift_type = tlc_proj_list->GetItemText(sel_item, 12);

            start_mils = wxGetLocalTimeMillis();

            wf_new_active = new wf_operator_ex(s_wbs, wf_str_new_config, t_new_template, s_flag);
            l_proc_act = wf_new_active->get_current_process();
            l_proc_act->MoveToActive();
            now_step = l_proc_act->get_cur_instance_action();
            next_step = l_proc_act->get_next_instance_action();
            if(now_step.s_action.s_operator_id!=gr_para.login_user && now_step.is_active)
            {

                continue;
            }

            if(next_step.s_action.i_flow_ser != now_step.s_action.i_flow_ser+1)
            {
                next_step.s_action = t_new_template[now_step.s_action.i_flow_ser];
                next_step.s_instance_id = s_wbs;
            }
            s_group = next_step.s_action.s_group_id;
            s_operator = next_step.s_action.s_operator_id;
            s_role = next_step.s_action.s_role_id;

            b_active = check_other_way(s_wbs, s_flag);

            a_flag = get_other_way(s_lift_type, s_flag);

            int i_flag = a_flag.GetCount();

            s_flag_ex = s_flag;
            for(int k=0; k<i_flag; k++)
            {
                s_flag_ex = s_flag_ex+wxT("+")+a_flag.Item(k);

            }

            wf_new_active->Pass_proc(s_operator, s_group, wxEmptyString, false,s_flag_ex, b_active);
            l_proc_act = 0;
            if(wf_new_active)
                delete wf_new_active;

            mils_used = wxGetLocalTimeMillis() - start_mils;

            wxLogMessage(s_wbs+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒"));

            wxTreeItemId parent_item = tlc_proj_list->GetItemParent(sel_item);
            tlc_proj_list->Delete(sel_item);

            if(tlc_proj_list->GetChildrenCount(parent_item)== 0)
               tlc_proj_list->Delete(parent_item);
        }
    }

    delete [] t_new_template;
}

void project_author_panel::pass_proc()
{
    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_proj_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_proj_list->GetSelections( items );

    if(items.IsEmpty())
    {
        wxLogMessage(_("请选择项目！"));
        return;
    }

    wxTreeItemId sel_item, child_item;
    wxTreeItemIdValue cookie;
    wxTreeItemId del_item;

    wxArrayString a_operator, a_flag;
    wxLongLong mils_used, start_mils;
    wxString s_wbs,s_lift_type,s_flag_ex;
    wxString s_group, s_operator, s_role, s_index;

    wf_process * l_proc_act =0;

    v_wf_instance now_step, next_step;
    bool b_active;

    v_wf_action * t_template=get_template_action(wf_str_configure);
    wf_operator* wf_active=0;

    for(iter=items.begin();iter<items.end();iter++)
    {
        sel_item = *iter;

        if(tlc_proj_list->GetItemParent(sel_item)==root)
        {
           child_item = tlc_proj_list->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {
                b_active=true;
                a_operator.Clear();
                a_flag.Clear();

                s_wbs = tlc_proj_list->GetItemText(child_item, 0);

                s_lift_type = tlc_proj_list->GetItemText(child_item, 12);

                start_mils = wxGetLocalTimeMillis();

                wf_active = new wf_operator(s_wbs, wf_str_configure, t_template);

                l_proc_act = wf_active->get_current_process();

                if(s_index != tlc_proj_list->GetItemText(child_item, 13))
                {
                    s_index = tlc_proj_list->GetItemText(child_item, 13);
                    if(!make_evaluate(l_proc_act, s_index))
                    {
                        if(wf_active)
                             delete wf_active;

                        l_proc_act = 0;
                        return;
                    }

                }

                l_proc_act->MoveToActive();
                now_step = l_proc_act->get_cur_instance_action();

                if(now_step.s_action.s_operator_id!=gr_para.login_user && now_step.is_active)
                {
                    child_item = tlc_proj_list->GetNextSibling(child_item);
                    continue;
                }


                if(!now_step.is_active)
               {
                    child_item = tlc_proj_list->GetNextSibling(child_item);
                    continue;
                }

                if(l_proc_act->GetCurrentStep() == l_proc_act->GetTotalSteps()&&l_proc_act->GetTotalSteps()!= now_step.s_action.i_total_flow)
                {

                    next_step.s_action = t_template[now_step.s_action.i_flow_ser];
                    next_step.s_instance_id = s_wbs;
                }
                else if(l_proc_act->GetCurrentStep() != l_proc_act->GetTotalSteps())
                {
                    next_step = l_proc_act->get_next_instance_action();
                    if(next_step.s_action.i_flow_ser != now_step.s_action.i_flow_ser+1)
                    {
                        next_step.s_action = t_template[now_step.s_action.i_flow_ser];
                        next_step.s_instance_id = s_wbs;
                    }
                }

                s_group = next_step.s_action.s_group_id;
                s_operator = next_step.s_action.s_operator_id;

                wf_active->Pass_proc(s_operator, s_group, wxEmptyString, false);
                l_proc_act = 0;
                if(wf_active)
                    delete wf_active;

                del_item = child_item;
                child_item = tlc_proj_list->GetNextSibling(child_item);
//
                tlc_proj_list->Delete(del_item);

                if(tlc_proj_list->GetChildrenCount(sel_item)==0)
                    tlc_proj_list->Delete(sel_item);

                mils_used = wxGetLocalTimeMillis() - start_mils;

                wxLogMessage(s_wbs+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒"));
            }
        }else if(sel_item.IsOk())
        {
            b_active=true;
            a_operator.Clear();
            a_flag.Clear();

            s_wbs = tlc_proj_list->GetItemText(sel_item, 0);
            s_lift_type = tlc_proj_list->GetItemText(sel_item, 12);

            start_mils = wxGetLocalTimeMillis();

            wf_active = new wf_operator(s_wbs, wf_str_configure, t_template);
            l_proc_act = wf_active->get_current_process();

            if(s_index != tlc_proj_list->GetItemText(sel_item, 13))
            {
                s_index = tlc_proj_list->GetItemText(sel_item, 13);
                if(!make_evaluate(l_proc_act, s_index))
                {
                    if(wf_active)
                        delete wf_active;

                    l_proc_act = 0;
                    return;
                }

            }

            l_proc_act->MoveToActive();
            now_step = l_proc_act->get_cur_instance_action();
            next_step = l_proc_act->get_next_instance_action();

            if(now_step.s_action.s_operator_id!=gr_para.login_user && now_step.is_active)
            {
                continue;
            }


            if(!now_step.is_active)
            {
                continue;
            }

            if(next_step.s_action.i_flow_ser != now_step.s_action.i_flow_ser+1)
            {
                next_step.s_action = t_template[now_step.s_action.i_flow_ser];
                next_step.s_instance_id = s_wbs;
            }
            s_group = next_step.s_action.s_group_id;
            s_operator = next_step.s_action.s_operator_id;

            wf_active->Pass_proc(s_operator, s_group, wxEmptyString, false);
            l_proc_act = 0;
            if(wf_active)
                delete wf_active;

            mils_used = wxGetLocalTimeMillis() - start_mils;

            wxLogMessage(s_wbs+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒"));

            wxTreeItemId parent_item = tlc_proj_list->GetItemParent(sel_item);
            tlc_proj_list->Delete(sel_item);

            if(tlc_proj_list->GetChildrenCount(parent_item)== 0)
               tlc_proj_list->Delete(parent_item);
        }
    }

    delete [] t_template;
}

bool project_author_panel::check_other_way(wxString s_instance, wxString s_flag)
{
     wxString s_sql = wxT("select * from l_proc_act where instance_id='")+s_instance+wxT("' and workflow_id='WF0006' AND is_active=true and flow_ser<=3 and flag !='")+s_flag+wxT("';");
    wxPostgreSQLresult* _res = wxGetApp().app_sql_select(s_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return false;
    }

    int i_count = _res->GetRowsNumber();

    _res->Clear();

    if(i_count <1)
        return true;
    else
        return false;

}

wxArrayString project_author_panel::get_other_way(wxString s_lift_type, wxString s_flag)
{

    wxString s_sql = wxT("select mode from s_flow_unit_list where elevator_type_id = '")+s_lift_type+wxT("' and mode !='")+s_flag+wxT("';");

    wxArrayString a_result ;
    wxString str;

    wxPostgreSQLresult* _res = wxGetApp().app_sql_select(s_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return a_result;
    }

    int i_count = _res->GetRowsNumber();

    for(int i=0;i<i_count;i++)
    {
        str = _res->GetVal(wxT("mode"));
        a_result.Add(str);
        _res->MoveNext();
    }

    _res->Clear();
    return a_result;

}

bool project_author_panel::update_unit_nstd_id(wxString s_wbs, wxString s_nstd_id, wxString s_flag)
{
    wxString s_sql;

    if(s_flag == wxT("E"))
    {
        s_sql = wxT("UPDATE s_unit_info SET e_nstd_id='")+s_nstd_id+wxT("' where wbs_no ='")+s_wbs+wxT("';");
    }else
    {
        s_sql = wxT("UPDATE s_unit_info SET m_nstd_id='")+s_nstd_id+wxT("' where wbs_no ='")+s_wbs+wxT("';");
    }

    return wxGetApp().app_sql_update(s_sql);
}

void project_author_panel::create_nstd_task(wxArrayString & a_wbs, wxArrayString &a_lift_type, wxArrayString &a_catalog, wxArrayString &a_mat_req,wxString s_item_catalog, wxString s_responsor)
{
    int i_count= a_wbs.GetCount();

    if(i_count==0)
        return;

    wxString s_nstd_id, s_link_list;
    wxArrayString a_nstd_id, a_link_list;
    wxString s_wbs,s_mat_req, s_lift_type, s_catalog, s_project_id;

    s_wbs = a_wbs.Item(0);
    s_project_id=s_wbs.Left(10);

    s_lift_type=a_lift_type.Item(0);
    s_mat_req=a_mat_req.Item(0);
    s_catalog = a_catalog.Item(0);

    s_link_list = s_wbs;

    if(i_count==1)
    {
        s_nstd_id = wxGetApp().get_ser_id(wxT("l_nonstd_app_header"), wxT("nonstd_id"));

        a_nstd_id.Add(s_nstd_id);

        a_link_list.Add(s_link_list);
        update_unit_nstd_id(s_wbs, s_nstd_id, s_item_catalog);
    }

    for(int i=1;i<i_count;i++)
    {
        s_wbs=a_wbs.Item(i);

         if(s_project_id!=s_wbs.Left(10)||s_lift_type!=a_lift_type.Item(i)||s_mat_req!=a_mat_req.Item(i)||s_catalog!=a_catalog.Item(i))
         {
             if(s_project_id!=s_wbs.Left(10))
                s_project_id=s_wbs.Left(10);

             s_lift_type=a_lift_type.Item(i);
             s_mat_req=a_mat_req.Item(i);
             s_catalog = a_catalog.Item(i);


            s_nstd_id = wxGetApp().get_ser_id(wxT("l_nonstd_app_header"), wxT("nonstd_id"));

            update_unit_nstd_id(s_wbs, s_nstd_id, s_item_catalog);

            a_nstd_id.Add(s_nstd_id);

            a_link_list.Add(s_link_list);

            s_link_list = s_wbs;


         }else
         {

            s_link_list = s_link_list+wxT(";")+s_wbs;

         }

         if(i==i_count-1)
         {
            s_nstd_id = wxGetApp().get_ser_id(wxT("l_nonstd_app_header"), wxT("nonstd_id"));
             update_unit_nstd_id(s_wbs, s_nstd_id, s_item_catalog);

            a_nstd_id.Add(s_nstd_id);

            a_link_list.Add(s_link_list);
         }
    }

    i_count = a_nstd_id.GetCount();

    for(int j=0;j<i_count;j++)
    {
        save_header(a_nstd_id.Item(j),a_link_list.Item(j));
        save_item(a_nstd_id.Item(j),a_link_list.Item(j), s_item_catalog, s_responsor);
    }

}

bool project_author_panel::build_batch_id(wxString &batch_id, wxString &str_wbs)
{
   wxString str_sql = wxT("UPDATE s_unit_info SET conf_batch_id='")+batch_id+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+
                      wxT("', modify_emp_id='")+gr_para.login_user+wxT("' WHERE wbs_no = '")+str_wbs+wxT("';");

    return wxGetApp().app_sql_update(str_sql);

}

void project_author_panel::OnTreeListCtrlRightClick(wxTreeEvent& event)
{
   PopupMenu(&menu_authority, event.GetPoint());
}

void project_author_panel::OnPaint(wxPaintEvent& event)
{
}

void project_author_panel::OnMenuItem1Selected(wxCommandEvent& event)
{
    wxTreeItemId root = tlc_proj_list->GetRootItem();
    tlc_proj_list->ExpandAll(root);
}

void project_author_panel::OnMenuItem2Selected(wxCommandEvent& event)
{
    wxTreeItemId root = tlc_proj_list->GetRootItem();

    wxTreeItemIdValue cookie;
    wxTreeItemId item = tlc_proj_list->GetFirstChild(root,cookie);

    while(item.IsOk())
    {
        tlc_proj_list->Collapse(item);
        item = tlc_proj_list->GetNextSibling(item);
    }

}

void project_author_panel::OnMenuItem3Selected(wxCommandEvent& event)
{
    if(!event.IsChecked())
    {
        MenuItem3->Check(true);
        return;
    }

 //   Button1->SetLabel(_("项目授权"));
     Button1->Show(true);
     Button4->Show(false);
     Button_Review->Show(false);
     Button_AUTH->Enable(true);

    m_case = 0;
    wxString strSql = wxT("SELECT  concat(contract_id,' ', project_name) as project_name, project_id,\
                         instance_id as wbs_no, lift_no,elevator_id, elevator_type, project_catalog,action_id, action_name, req_configure_finish, special_info, \
                         (SELECT concat(operator_id,'-',name) from s_employee WHERE employee_id = operator_id) as operator, status, is_urgent,nonstd_level,conf_batch_id  from v_task_list1 WHERE action_id = 'AT00000003' \
                         AND is_active = true AND operator_id = '")+gr_para.login_user+ wxT("' ");
    Set_Clause(strSql);
    refresh_list();
    MenuItem3->Check(true);
    MenuItem4->Check(false);
    mi_review->Check(false);
}

void project_author_panel::OnMenuItem4Selected(wxCommandEvent& event)
{
    if(!event.IsChecked())
    {
        MenuItem4->Check(true);
        return;
    }

 //   Button1->SetLabel(_("项目授权"));
    Button1->Show(true);
    Button4->Show(false);
     Button_Review->Show(false);
     Button_AUTH->Enable(false);
    m_case=1;
    wxString strSql;

    if(m_leader&&(m_group=="G0006"||m_group=="G0007"||m_group=="G0008"))
    {
            strSql = wxT("SELECT  concat(contract_id,' ', project_name) as project_name, project_id,\
                         instance_id as wbs_no, lift_no,elevator_id, elevator_type, project_catalog,action_id, action_name, req_configure_finish, special_info, \
                         (SELECT concat(employee_id,'-',name) from s_employee WHERE employee_id = operator_id) as operator, status, is_urgent,nonstd_level,conf_batch_id  from v_task_list1 WHERE action_id = 'AT00000004' \
                         AND is_active = true and group_id='")+m_group+wxT("' ");
    }else if(m_leader && (m_group == "G0014" || m_group=="G0004"))
            strSql = wxT("SELECT  concat(contract_id,' ', project_name) as project_name, project_id,\
                         instance_id as wbs_no, lift_no, elevator_id,elevator_type, project_catalog,action_id, action_name, req_configure_finish, special_info, \
                         (SELECT concat(employee_id,'-',name) from s_employee WHERE employee_id = operator_id) as operator, status, is_urgent,nonstd_level,conf_batch_id  from v_task_list1 WHERE action_id = 'AT00000004' \
                         AND is_active = true ");
    else
        return;

 //   wxLogMessage(strSql);
    Set_Clause(strSql);
    refresh_list();

    MenuItem3->Check(false);
    MenuItem4->Check(true);
    mi_review->Check(false);
//    b_case = true;
}
/*
wxArrayString project_author_panel::get_array()
{
    wxTreeItemId root = tlc_proj_list->GetRootItem();

    wxTreeItemIdValue cookie;
    wxTreeItemId item = tlc_proj_list->GetFirstChild(root,cookie);
    wxArrayString  str_array;

    while(item.IsOk())
    {
        wxTreeItemIdValue cookie_child;
        wxTreeItemId child_item = tlc_proj_list->GetFirstChild(item,cookie_child);

        while(child_item.IsOk())
        {
            str_array.Add(tlc_proj_list->GetItemText(child_item,0));

            child_item = tlc_proj_list->GetNextSibling(child_item);

        }

        item = tlc_proj_list->GetNextSibling(item);
    }

    return str_array;
}
*/
void project_author_panel::OnMenuItem5Selected(wxCommandEvent& event)
{
    if(event.IsChecked())
     {
         MenuItem5->Check(true);
         str_freeze.Empty();

     }else
     {
         MenuItem5->Check(false);
         str_freeze = wxT("  AND status != '4' ");
     }

     refresh_list();
}

void project_author_panel::OnButton2Click(wxCommandEvent& event)
{
/*
    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_proj_list->GetRootItem();

    if(wxGetApp().get_group().Item(0) != wxT("G0014"))
        return;
    wxArrayTreeItemIds::iterator iter;
    tlc_proj_list->GetSelections( items );

    wxString s_wbs, s_source, s_result,s_str, s_status, str_sql;

    wxLongLong mils_used, start_mils;

    if(wxMessageBox(_("注意此操作将暂停选中项目，状态仅CM能够更改，是否继续？"),_("暂停项目:"),wxYES_NO,this)!=wxYES)
        return;

    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_proj_list->GetItemParent(sel_item)==root)
        {
            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_proj_list->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {
                start_mils = wxGetLocalTimeMillis();//事件处理事件统计，起始点。

                s_wbs = tlc_proj_list->GetItemText(child_item, 0);
                if(prj_str_to_status(tlc_proj_list->GetItemText(child_item, 7))==4)
                {
                    continue;

                }else
                {
                    s_status = wxT("暂停");
                    s_source = wxT("ACTIVE");
                    s_result = wxT("FREEZED");
                    s_str = wxT("4");
                    str_sql = wxT("UPDATE s_unit_info SET status = '4' WHERE wbs_no='")+s_wbs+wxT("';");
                }

                if(wxGetApp().app_sql_update(str_sql))
                {
                    wxLogMessage(s_wbs + _("unit")+s_source + _("成功"));
                    tlc_proj_list->SetItemText(child_item,7, prj_str_to_status(strtonum(s_str)));
                    wxGetApp().change_log(wxT("s_unit_info"),s_wbs, wxT("status "), s_source, s_result, wxT("hand"));
                }

                mils_used = wxGetLocalTimeMillis() - start_mils;

                wxLogMessage(s_wbs+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒")); //事件处理事件统计，截止点。


                child_item = tlc_proj_list->GetNextSibling(child_item);
            }

        }else
        {
                start_mils = wxGetLocalTimeMillis();//事件处理事件统计，起始点。

                s_wbs = tlc_proj_list->GetItemText(sel_item, 0);
                if(tlc_proj_list->GetItemText(sel_item, 7)==wxT("4"))
                {
                    continue;

                }else
                {
                    s_status = wxT("暂停");
                    s_source = wxT("ACTIVE");
                    s_result = wxT("FREEZED");
                    s_str = wxT("4");
                    str_sql = wxT("UPDATE s_unit_info SET status = '4' WHERE wbs_no='")+s_wbs+wxT("';");
                }

                if(wxGetApp().app_sql_update(str_sql))
                {
                    wxLogMessage(s_wbs + _("unit")+s_source + _("成功"));
                    tlc_proj_list->SetItemText(sel_item,7, s_str);
                    wxGetApp().change_log(wxT("s_unit_info"),s_wbs, wxT("status "), s_source, s_result, wxT("hand"));
                }


                mils_used = wxGetLocalTimeMillis() - start_mils;

                wxLogMessage(s_wbs+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒")); //事件处理事件统计，截止点。

        }

    }*/


    if(m_leader&&(m_group=="G0006"||m_group=="G0007"||m_group=="G0008"))
    {
        refresh_list();
        refresh_new_res_list(m_group);
    }else if(m_leader && m_group == "G0014")
    {
        refresh_list();
        refresh_res_list("CF");
    }
    else if(m_leader && m_group=="G0004")
    {
        refresh_list();
        refresh_res_list("CFM");
    }
    else
        return;
}

void project_author_panel::OnButton3Click(wxCommandEvent& event)
{

    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_proj_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_proj_list->GetSelections( items );

    if(items.IsEmpty())
    {
        wxLogMessage(_("请选择项目！"));
        return;
    }


    wxString s_wbs, s_source, str_sql,str_date,s_date;

    wxLongLong mils_used, start_mils;

    if(wxMessageBox(_("注意此操作将更改要求配置完成日期，是否继续？"),_("配置完成日期修改:"),wxYES_NO,this)!=wxYES)
        return;

    mydatepicker ddlg;
    if(ddlg.ShowModal()== wxID_OK)
    {
        str_date = ddlg.GetString();
        s_date = str_date+wxT(" 23:00:00");
    }else return;


    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_proj_list->GetItemParent(sel_item)==root)
        {
            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_proj_list->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {
                start_mils = wxGetLocalTimeMillis();//事件处理事件统计，起始点。

                s_wbs = tlc_proj_list->GetItemText(child_item, 0);
                s_source = tlc_proj_list->GetItemText(child_item, 7);
                if(!s_source.IsEmpty())
                    s_source= s_source+wxT(" 23:00:00");

                if(prj_str_to_status(tlc_proj_list->GetItemText(child_item, 9))==4)
                {
                    continue;

                }else
                {
                    str_sql =  wxT("UPDATE s_unit_info SET req_configure_finish ='")+s_date+wxT("' WHERE wbs_no='")+s_wbs+wxT("';");
                }

                if(wxGetApp().app_sql_update(str_sql))
                {
                    wxLogMessage(s_wbs + _("unit更改配置完成日期成功"));
                    tlc_proj_list->SetItemText(child_item,7, str_date);
                    wxGetApp().change_log(wxT("s_unit_info"),s_wbs, wxT("req_configure_finish "), s_source, s_date, wxT("hand"));

                    update_nonstd_conf_date(s_wbs,StrToDateTime(s_date));
                }

                mils_used = wxGetLocalTimeMillis() - start_mils;

                wxLogMessage(s_wbs+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒")); //事件处理事件统计，截止点。


                child_item = tlc_proj_list->GetNextSibling(child_item);
            }

        }else
        {
                start_mils = wxGetLocalTimeMillis();//事件处理事件统计，起始点。

                s_wbs = tlc_proj_list->GetItemText(sel_item, 0);
                s_source = tlc_proj_list->GetItemText(sel_item, 7);
                if(!s_source.IsEmpty())
                    s_source= s_source+wxT(" 23:00:00");

                if(prj_str_to_status(tlc_proj_list->GetItemText(sel_item, 9))==4)
                {
                    continue;

                }else
                {
                    str_sql =  wxT("UPDATE s_unit_info SET req_configure_finish ='")+s_date+wxT("' WHERE wbs_no='")+s_wbs+wxT("';");
                }

                if(wxGetApp().app_sql_update(str_sql))
                {
                    wxLogMessage(s_wbs + _("unit更改配置完成日期成功"));
                    tlc_proj_list->SetItemText(sel_item,7, str_date);
                    wxGetApp().change_log(wxT("s_unit_info"),s_wbs, wxT("req_configure_finish "), s_source, s_date, wxT("hand"));

                    update_nonstd_conf_date(s_wbs,StrToDateTime(s_date));
                }


                mils_used = wxGetLocalTimeMillis() - start_mils;

                wxLogMessage(s_wbs+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒")); //事件处理事件统计，截止点。
        }


    }

    array_update_conf.Clear();
    refresh_list();
    refresh_project_level();
}

void project_author_panel::Onlc_resItemActivated(wxListEvent& event)
{


    wxListItem li_item = event.GetItem();
    li_item.m_col = 0;
    wxString s_operator = li_item.GetText().Left(8);

    m_case = 1;
    wxString strSql = wxT("SELECT  concat(contract_id,' ', project_name) as project_name, project_id, special_info, \
                         instance_id as wbs_no, lift_no, elevator_id,elevator_type, project_catalog,  action_id, action_name, req_configure_finish, \
                         (SELECT concat(employee_id,'-',name) from s_employee WHERE employee_id = operator_id) as operator, status, is_urgent, nonstd_level from v_task_list1 WHERE action_id = 'AT00000004' \
                         AND is_active = true AND operator_id = '")+s_operator+wxT("' ");
 //   wxLogMessage(strSql);
    Set_Clause(strSql);
    refresh_list();

    MenuItem3->Check(false);
    MenuItem4->Check(true);

}

void project_author_panel::OnMenuItem6Selected(wxCommandEvent& event)
{
    wxString s_wbs;
    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_proj_list->GetRootItem();

    if(!m_leader||(m_group!="G0006"&&m_group!="G0007"&& m_group!="G0008"&&m_group!="G0014"))
        return;

    wxArrayTreeItemIds::iterator iter;
    tlc_proj_list->GetSelections( items );

    wxArrayString array_wbs;

    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_proj_list->GetItemParent(sel_item)==root)
        {
            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_proj_list->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {

                if(prj_str_to_status(tlc_proj_list->GetItemText(child_item, 9))!=3)
                {
                    child_item = tlc_proj_list->GetNextSibling(child_item);
                    continue;
                }


                s_wbs = tlc_proj_list->GetItemText(child_item, 0);
                array_wbs.Add(s_wbs);

                child_item = tlc_proj_list->GetNextSibling(child_item);

            }

        }else if(sel_item.IsOk())
        {
                if(prj_str_to_status(tlc_proj_list->GetItemText(sel_item, 9))!=3)
                {
                    continue;
                }

                s_wbs = tlc_proj_list->GetItemText(sel_item, 0);
                array_wbs.Add(s_wbs);
        }

    }

    if(array_wbs.IsEmpty())
        return;

    proj_configure_history dlg;

    dlg.refresh_list(array_wbs);

    dlg.ShowModal();

    array_wbs.Clear();

}

bool project_author_panel::update_nonstd_conf_date(wxString s_wbs, wxDateTime dt_temp)
{
    wxString str_sql = wxT("SELECT * FROM l_nonstd_app_header where link_list like '%")+s_wbs+wxT("%' and (status = 0 or status =1) ;");


    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return false;
    }


    int i_count = _res->GetRowsNumber();

    if(i_count == 0)
    {
        _res->Clear();
        return false;
    }

    wxString s_app_id;

    _res->MoveFirst();

    for(int i=0;i<i_count;i++)
    {
        s_app_id = _res->GetVal(wxT("nonstd_id"));
        if(array_update_conf.Index(s_app_id)!=wxNOT_FOUND)
        {
            _res->MoveNext();
            continue;
        }

        array_update_conf.Add(s_app_id);

        int i_status = _res->GetInt(wxT("status"));

        if(i_status ==-1)
        {
            _res->MoveNext();
            continue;
        }

        wxDateTime dt_now = _res->GetDateTime(wxT("drawing_req_date"));

        if(dt_temp.IsEarlierThan(wxDateTime::Now()))
        {
            _res->MoveNext();
            continue;
        }

        str_sql = wxT("UPDATE l_nonstd_app_header SET drawing_req_date='")+DateToAnsiStr(dt_temp)+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+
                wxT("', modify_emp_id='")+gr_para.login_user+wxT("' where nonstd_id ='")+s_app_id+wxT("';");

        if (wxGetApp().app_sql_update(str_sql))
        {
                wxLogMessage(_("非标：") + s_app_id + _("图纸要求日期变更为:") + DateToStrFormat(dt_temp) + _("成功!"));
                wxGetApp().change_log(wxT("l_nonstd_app_header"), s_app_id, wxT("drawing_req_date"), DateToAnsiStr(dt_now), DateToAnsiStr(dt_temp), wxT("hand"));
        }

        _res->MoveNext();

    }

    _res->Clear();


}

void project_author_panel::OnMenuItem7Selected(wxCommandEvent& event)
{
    wxString s_project,s_wbs;
    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_proj_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_proj_list->GetSelections( items );

    wxArrayString array_project,array_wbs;

    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_proj_list->GetItemParent(sel_item)==root)
        {
            s_project = tlc_proj_list->GetItemText(sel_item, 1);
            if(array_project.Index(s_project)==wxNOT_FOUND)
                array_project.Add(s_project);
            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_proj_list->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {
                s_wbs = tlc_proj_list->GetItemText(child_item, 0);
                if(array_wbs.Index(s_wbs)==wxNOT_FOUND)
                    array_wbs.Add(s_wbs);
                child_item = tlc_proj_list->GetNextSibling(child_item);
            }

        }else if(sel_item.IsOk())
        {
                s_wbs = tlc_proj_list->GetItemText(sel_item,0);
                if(array_wbs.Index(s_wbs)==wxNOT_FOUND)
                    array_wbs.Add(s_wbs);

                wxTreeItemId parent_item = tlc_proj_list->GetItemParent(sel_item);
                s_project = tlc_proj_list->GetItemText(parent_item, 1);
                if(array_project.Index(s_project)== wxNOT_FOUND)
                   array_project.Add(s_project);
        }

    }

    if(array_project.IsEmpty())
        return;


    array_wbs = get_same_in_process(array_project,array_wbs);

    array_project.Clear();
    if(array_wbs.IsEmpty())
        return;

    proj_configure_history dlg;

    dlg.refresh_now_wbs(array_wbs);

    dlg.ShowModal();


    array_wbs.Clear();
}

wxArrayString project_author_panel::get_same_in_process(wxArrayString &array_prj, wxArrayString &array_now_wbs)
{
    wxArrayString array_same;
    wxString s_wbs;

    wxString str_sql = wxT("select wbs_no from s_unit_info where status >0 and ");
    int i_count = array_prj.GetCount();

    if(i_count == 1)
    {
        str_sql = str_sql + wxT(" project_id = '")+array_prj.Item(0)+wxT("' ");
    }else
    {

    for(int i=0;i<i_count;i++)
    {
        if(i==0)
        {
            str_sql = str_sql + wxT(" (project_id = '")+array_prj.Item(i)+wxT("' or ");
        }else if(i==i_count-1)
        {
            str_sql = str_sql + wxT(" project_id ='")+array_prj.Item(i)+wxT("' )");

        }else
        {
            str_sql = str_sql +wxT(" project_id = '")+array_prj.Item(i)+wxT("' or ");
        }
    }
    }

    wxPostgreSQLresult* _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return array_same;
    }

    int irow = _res->GetRowsNumber();

    for(int j=0;j<irow;j++)
    {
        s_wbs = _res->GetVal(wxT("wbs_no"));

        if(array_now_wbs.Index(s_wbs)==wxNOT_FOUND)
            array_same.Add(s_wbs);

        _res->MoveNext();
    }

    _res->Clear();
    array_now_wbs.Clear();

    return array_same;
}

void project_author_panel::OnMenuItem8Selected(wxCommandEvent& event)
{
   wxString s_project;
    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_proj_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_proj_list->GetSelections( items );

    wxArrayString array_project;

    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_proj_list->GetItemParent(sel_item)==root)
        {
            s_project = tlc_proj_list->GetItemText(sel_item, 1);
            if(array_project.Index(s_project)==wxNOT_FOUND)
                array_project.Add(s_project);

        }else if(sel_item.IsOk())
        {
                wxTreeItemId parent_item = tlc_proj_list->GetItemParent(sel_item);
                s_project = tlc_proj_list->GetItemText(parent_item, 1);
                if(array_project.Index(s_project)== wxNOT_FOUND)
                   array_project.Add(s_project);
        }

    }

    if(array_project.IsEmpty())
        return;

    proj_configure_history dlg;

    dlg.refresh_now_prj(array_project);

    dlg.ShowModal();


    array_project.Clear();
}

void project_author_panel::OnButton_Nstd_levelClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_proj_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_proj_list->GetSelections( items );
    wxTreeItemId del_item;

    if(items.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }

    if(wxMessageBox(_("确认变更所选项目的非标等级"),_("确认："),wxOK|wxCANCEL,this)==wxCANCEL)
    {
        return;
    }

    wxString _choice[4] =
    {
 //       _("Target STD"),
        _("Option STD"),
        _("Simple Non-STD"),
        _("Complex Non-STD"),
        _("Comp-Standard")//,
 //       _("Comp-Measurement"),
 //       _("Comp-Configurable")
    };
    wxSingleChoiceDialog cdlg(this, _("请选择非标等级?"), _("非标等级选择:"), 4, _choice);
    if (cdlg.ShowModal() == wxID_CANCEL)
        return;
    int i_nstd_level = nstd_str_to_level(cdlg.GetStringSelection());
    wxString str,str_wbs;
    int i_old_nstd_level;

    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_proj_list->GetItemParent(sel_item)==root)
        {
            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_proj_list->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {
                str=tlc_proj_list->GetItemText(child_item,11);
                str_wbs = tlc_proj_list->GetItemText(child_item, 0);
                i_old_nstd_level = nstd_str_to_level(str);

                if(i_nstd_level== i_old_nstd_level)
                {
                    child_item = tlc_proj_list->GetNextSibling(child_item);
                    wxLogMessage(str_wbs+_("非标等级本来就是:")+nstd_level_to_str(i_nstd_level)+_("，无需更新!"));
                    continue;
                }

                if(update_nstd_level(str_wbs, i_old_nstd_level, i_nstd_level))
                {
                    tlc_proj_list->SetItemText(child_item,11, nstd_level_to_str(i_nstd_level));

                    wxLogMessage(str_wbs+_("非标等级更新为:")+nstd_level_to_str(i_nstd_level)+_(", 成功!"));
                }

                child_item = tlc_proj_list->GetNextSibling(child_item);

            }
        }else
        {
                str=tlc_proj_list->GetItemText(sel_item,11);
                str_wbs = tlc_proj_list->GetItemText(sel_item, 0);
                i_old_nstd_level = nstd_str_to_level(str);

                if(i_nstd_level== i_old_nstd_level)
                {
                    wxLogMessage(str_wbs+_("非标等级本来就是:")+nstd_level_to_str(i_nstd_level)+_("，无需更新!"));
                    continue;
                }

                if(update_nstd_level(str_wbs, i_old_nstd_level, i_nstd_level))
                {
                    tlc_proj_list->SetItemText(sel_item,11, nstd_level_to_str(i_nstd_level));
                    wxLogMessage(str_wbs+_("非标等级更新为:")+nstd_level_to_str(i_nstd_level)+_(", 成功!"));
                }

        }
    }
    refresh_project_level();
}

bool project_author_panel::update_nstd_level(wxString s_wbs, int old_status, int new_status)
{
    wxString str_sql = wxT("select count(*) as count from s_unit_nstd_level where wbs_no = '")+s_wbs+wxT("';");
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return false;
    }

    int i_count = _res->GetInt(wxT("count"));


    _res->Clear();

    if(i_count == 0)
    {
        str_sql = wxT("INSERT INTO s_unit_nstd_level(wbs_no, nonstd_level_pre, is_sap_update, modify_date, modify_emp_id, create_date, create_emp_id) VALUES (\
                      '")+s_wbs+wxT("', '")+NumToStr(old_status)+wxT("',false,'")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+
                      DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("');");

    }else
    {
        str_sql = wxT("UPDATE s_unit_nstd_level SET nonstd_level_pre='")+NumToStr(old_status)+wxT("', is_sap_update=false, modify_date='")+DateToAnsiStr(wxDateTime::Now())+
                  wxT("',modify_emp_id='")+gr_para.login_user+wxT("' where wbs_no = '")+s_wbs+wxT("';");
    }

    if(!wxGetApp().app_sql_update(str_sql))
        return false;

    str_sql = wxT("UPDATE s_unit_info SET nonstd_level='")+NumToStr(new_status)+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+
                  wxT("',modify_emp_id='")+gr_para.login_user+wxT("' where wbs_no = '")+s_wbs+wxT("';");

    if(wxGetApp().app_sql_update(str_sql))
    {
        wxGetApp().change_log(wxT("s_unit_info"),s_wbs,wxT("nonstd_level"),NumToStr(old_status),NumToStr(new_status));
        return true;
    }

    return false;

}

void project_author_panel::OnButton4Click(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(m_case!=2)
    {
        wxLogMessage(_("目前阁下停留在非审核项目状态，无法操作，请切换到项目审核状态"));
        return;
    }

    wxString s_flag=wxEmptyString;

    bool b_way=false;

    if(m_group==wxT("G0007"))
    {
        s_flag=wxT("E");
        b_way = true;
    }
    else if(m_group==wxT("G0006")||m_group==wxT("G0008"))
    {
         s_flag =wxT("M");
         b_way = true;
    }else if(m_group == wxT("G0004"))
    {
        b_way=false;

    }else
    {
        wxLogMessage(_("此功能仅向机械，电气，高速梯非标组提供!"));
        return;
    }

    if(b_way)
    {
        feed_back_new(s_flag);
    }else
    {
        feed_back();
    }


}

void project_author_panel::feed_back_new(wxString s_flag)
{

    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_proj_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_proj_list->GetSelections( items );

    if(items.IsEmpty())
    {
        wxLogMessage(_("请选择项目！"));
        return;
    }


    wxTextEntryDialog tdlg(this,_("退回提示输入:"),_("确认退回给工程师？"),wxT(""),wxOK | wxCANCEL | wxTE_MULTILINE,wxDefaultPosition );
    wxString str_desc;
    if(tdlg.ShowModal()== wxID_OK)
    {
        str_desc= tdlg.GetValue();
    }
    else return;

    wxLongLong mils_used, start_mils;
    wxString s_instance;

    v_wf_action * t_template = get_template_action(wf_str_new_config);
    wf_operator_ex * wf_new_active=0;

    wxTreeItemId del_item;

    wxString s_action_id=wxT("AT00000004");

    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_proj_list->GetItemParent(sel_item)==root)
        {

            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_proj_list->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {
                start_mils = wxGetLocalTimeMillis();

                s_instance = tlc_proj_list->GetItemText(child_item, 0);
                wf_new_active = new wf_operator_ex(s_instance,wf_str_new_config, t_template, s_flag);
                if(wf_new_active->Feed_back(str_desc, s_action_id))
                {
                    update_unit_nstd_status(s_instance, 3, s_flag);
                }

                delete wf_new_active;
                mils_used = wxGetLocalTimeMillis() - start_mils;

                wxLogMessage(s_instance+_("任务已退回!  耗时:")+NumToStr(mils_used)+_("毫秒"));

                // tlc_proj_list->Delete(child_item);
                del_item = child_item;
                child_item = tlc_proj_list->GetNextSibling(child_item);
//               child_item = tlc_proj_list->GetNextChild(sel_item,cookie);
                tlc_proj_list->Delete(del_item);

            }

            if(!tlc_proj_list->HasChildren(sel_item))
                tlc_proj_list->Delete(sel_item);
        }
        else if(sel_item.IsOk())
        {
            wxTreeItemId parent_item = tlc_proj_list->GetItemParent(sel_item);

            if(tlc_proj_list->IsSelected(parent_item))
                continue;


            start_mils = wxGetLocalTimeMillis();

            s_instance = tlc_proj_list->GetItemText(sel_item, 0);
            wf_new_active = new wf_operator_ex(s_instance,wf_str_new_config, t_template, s_flag);
            if(wf_new_active->Feed_back(str_desc, s_action_id))
            {
                update_unit_nstd_status(s_instance, 3, s_flag);
            }

            delete wf_new_active;

            mils_used = wxGetLocalTimeMillis() - start_mils;

            wxLogMessage(s_instance+_("任务已退回!  耗时:")+NumToStr(mils_used)+_("毫秒"));


            tlc_proj_list->Delete(sel_item);

            if(tlc_proj_list->GetChildrenCount(parent_item)== 0)
                tlc_proj_list->Delete(parent_item);

        }
    }
}

void project_author_panel::feed_back()
{
    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_proj_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_proj_list->GetSelections( items );

    if(items.IsEmpty())
    {
        wxLogMessage(_("请选择项目！"));
        return;
    }


    wxTextEntryDialog tdlg(this,_("退回提示输入:"),_("确认退回给工程师？"),wxT(""),wxOK | wxCANCEL | wxTE_MULTILINE,wxDefaultPosition );
    wxString str_desc;
    if(tdlg.ShowModal()== wxID_OK)
    {
        str_desc= tdlg.GetValue();
    }
    else return;

    wxLongLong mils_used, start_mils;
    wxString s_instance;

    v_wf_action * t_template = get_template_action(wf_str_configure);
    wf_operator* wf_active=0;

    wxTreeItemId del_item;

    wxString s_action_id=wxT("AT00000004");

    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_proj_list->GetItemParent(sel_item)==root)
        {

            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_proj_list->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {
                start_mils = wxGetLocalTimeMillis();

                s_instance = tlc_proj_list->GetItemText(child_item, 0);
                wf_active = new wf_operator(s_instance,wf_str_configure, t_template);
                wf_active->Feed_back(str_desc, s_action_id);

                delete wf_active;
                mils_used = wxGetLocalTimeMillis() - start_mils;

                wxLogMessage(s_instance+_("任务已退回!  耗时:")+NumToStr(mils_used)+_("毫秒"));

                // tlc_proj_list->Delete(child_item);
                del_item = child_item;
                child_item = tlc_proj_list->GetNextSibling(child_item);
//               child_item = tlc_proj_list->GetNextChild(sel_item,cookie);
                tlc_proj_list->Delete(del_item);

            }

            if(!tlc_proj_list->HasChildren(sel_item))
                tlc_proj_list->Delete(sel_item);
        }
        else if(sel_item.IsOk())
        {
            wxTreeItemId parent_item = tlc_proj_list->GetItemParent(sel_item);

            if(tlc_proj_list->IsSelected(parent_item))
                continue;


            start_mils = wxGetLocalTimeMillis();

            s_instance = tlc_proj_list->GetItemText(sel_item, 0);
            wf_active = new wf_operator(s_instance, wf_str_configure, t_template);
            wf_active->Feed_back(str_desc, s_action_id);

            delete wf_active;

            mils_used = wxGetLocalTimeMillis() - start_mils;

            wxLogMessage(s_instance+_("任务已退回!  耗时:")+NumToStr(mils_used)+_("毫秒"));


            tlc_proj_list->Delete(sel_item);

            if(tlc_proj_list->GetChildrenCount(parent_item)== 0)
                tlc_proj_list->Delete(parent_item);

        }
    }
}

bool project_author_panel::update_unit_nstd_status(wxString s_wbs, int i_status, wxString s_flag)
{
    wxString s_sql = wxT(" select e_nstd_id, m_nstd_id from s_unit_info where wbs_no = '")+s_wbs+wxT("';");
    wxPostgreSQLresult *_res = wxGetApp().app_sql_select(s_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return false;
    }

    int i_count = _res->GetRowsNumber();

    if(i_count==0)
    {
        _res->Clear();
        return false;
    }

    wxString s_nstd_id;

    if(s_flag==wxT("E"))
    {
        s_nstd_id = _res->GetVal(wxT("e_nstd_id"));
    }else
    {
        s_nstd_id = _res->GetVal(wxT("m_nstd_id"));
    }

    _res->Clear();

    s_sql = wxT("UPDATE l_nonstd_app_header SET status =")+NumToStr(i_status)+wxT(" where nonstd_id='")+s_nstd_id+wxT("';");

    return wxGetApp().app_sql_update(s_sql);
}

void project_author_panel::Onmi_reviewSelected(wxCommandEvent& event)
{
    if(!event.IsChecked())
    {
        mi_review->Check(true);
        return;
    }

 //   Button1->SetLabel(_("项目审核"));
     Button1->Show(false);
     Button_Review->Show(true);
     Button4->Show(true);
     Layout();

    m_case =2;
    wxString strSql;


    strSql = wxT("SELECT  concat(contract_id,' ', project_name) as project_name, project_id,\
                         instance_id as wbs_no, lift_no, elevator_id, elevator_type, project_catalog,action_id, action_name, req_configure_finish, special_info, \
                         (SELECT concat(employee_id,'-',name) from s_employee WHERE employee_id = operator_id) as operator, status, is_urgent,nonstd_level,conf_batch_id  from v_task_list1 WHERE action_id = 'AT00000006' \
                         AND is_active = true and operator_id='")+gr_para.login_user+wxT("' ");// and workflow_id='WF0006' ");



    //wxLogMessage(strSql);
    Set_Clause(strSql);
    refresh_list();

    MenuItem3->Check(false);
    MenuItem4->Check(false);
    mi_review->Check(true);
}

void project_author_panel::save_header(wxString s_nstd_app_id,wxString s_link_list)
{

    wxString s_wbs_no = s_link_list.Left(14);
    wxString str_sql;

    str_sql = wxT(" select * from  v_unit_info where wbs_no ='")+s_wbs_no+wxT("';");
    wxPostgreSQLresult* _res = wxGetApp().app_sql_select(str_sql);


    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int i_count = _res->GetRowsNumber();

    if(i_count==0)
    {
        _res->Clear();
        return;
    }

    wxString  s_contract_id = _res->GetVal(wxT("contract_id"));
    wxDateTime d_mat_req = wxDateTime::Today()+wxDateSpan(0,0,0,2);

    wxString s_drawing_req_date = _res->GetVal(wxT("req_configure_finish"));

    _res->Clear();


    str_sql = wxT("INSERT INTO l_nonstd_app_header(nonstd_id, project_id, contract_id, link_list, status, mat_req_date, drawing_req_date, nonstd_desc, modify_date, modify_emp_id, create_date, create_emp_id, flow_mask) \
                  VALUES ('")+s_nstd_app_id+wxT("','")+s_link_list.Left(10)+wxT("','")+s_contract_id+
                  wxT("','")+s_link_list+wxT("','3','")+ DateToStrFormat(d_mat_req) + wxT(" 23:00:00")+wxT("','")+
                  s_drawing_req_date+wxT("','整梯BOM','")+DateToAnsiStr(wxDateTime::Now())+
                  wxT("','")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','000');");

    str_sql.Replace(wxT("''"),wxT("NULL"));
    wxGetApp().app_sql_update(str_sql);
}

void project_author_panel::save_item(wxString s_nstd_app_id,wxString s_link_list, wxString s_item_catalog, wxString s_responsor)
{
    wxString s_nstd_catalog;

    if(s_item_catalog.Upper()==wxT("E"))
        s_nstd_catalog=_("电气整梯BOM");
    else
        s_nstd_catalog = _("机械整梯BOM");

    wxString str_sql = wxT("INSERT INTO l_nonstd_app_item(index_id, nonstd_id, item_ser, item_catalog, link_list, nonstd_catalog, nonstd_desc, \
            modify_date, modify_emp_id, create_date, create_emp_id, res_person) VALUES ('")+s_nstd_app_id+wxT("-1','")+s_nstd_app_id+wxT("','1','")+s_item_catalog+wxT("','")+s_link_list+wxT("','")+s_nstd_catalog+wxT("','','")+
            DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+
            gr_para.login_user+wxT("','")+s_responsor+wxT("');");

 //   wxLogMessage(str_sql);
    str_sql.Replace(wxT("''"),wxT("NULL"));
    wxGetApp().app_sql_update(str_sql);
}


void project_author_panel::OnButton_AUTHClick(wxCommandEvent& event)
{
    if(!m_leader)
        return;

    if(m_case==1)
    {
        wxLogMessage(_("目前阁下停留在已授权项目列表状态，无法操作，请切换到待授权项目状态"));
        return;
    }

    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_proj_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_proj_list->GetSelections( items );

    if(items.IsEmpty())
    {
        wxLogMessage(_("请选择项目！"));
        return;
    }


    wxString s_wbs, s_sql;

    wxString s_own_group = wxGetApp().get_only_group();

    wxString s_aim_operator, s_aim_group;

    if(s_own_group==wxT("G0014"))
    {
        s_aim_group=wxT("G0004");
        s_aim_operator= wxGetApp().get_leader(s_aim_group);
    }else if(s_own_group==wxT("G0004"))
    {
        s_aim_group=wxT("G0014");
        s_aim_operator= wxGetApp().get_leader(s_aim_group);
    }else
        return;


    if(wxMessageBox(_("授权人更改为:")+wxGetApp().get_name(s_aim_operator),_("此操作变更授权人，是否继续？"),wxYES_NO,this)!=wxYES)
        return;

    wxTreeItemId del_item;

    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_proj_list->GetItemParent(sel_item)==root)
        {
            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_proj_list->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {
                bool b_del=false;
                s_wbs = tlc_proj_list->GetItemText(child_item, 0);
                s_sql=wxT("UPDATE l_proc_act SET operator_id='")+s_aim_operator+wxT("', group_id='")+s_aim_group+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("' where \
                              instance_id='")+s_wbs+wxT("' and workflow_id='WF0002' AND action_id='AT00000003' and is_active=true;")  ;
                if (wxGetApp().app_sql_update(s_sql))
                {
                    wxLogMessage(s_wbs+":授权人成功变更为:"+wxGetApp().get_name(s_aim_operator)+":成功!");
                    wxGetApp().change_log("l_proc_act",s_wbs+"-AT00000003","operator_id",gr_para.login_user,s_aim_operator,"by hand");
                    //wxGetApp().change_log("l_proc_act",s_wbs+"-AT00000003","group_id",s_own_group,s_aim_group,"by hand");
                    del_item = child_item;
                    b_del=true;
                }else
                {
                    wxLogMessage(s_wbs+"变更授权人失败!");
                }

                child_item = tlc_proj_list->GetNextSibling(child_item);

                if(b_del)
                    tlc_proj_list->Delete(del_item);

            }

            if(tlc_proj_list->GetChildrenCount(sel_item)== 0)
                tlc_proj_list->Delete(sel_item);

        }else
        {

                s_wbs = tlc_proj_list->GetItemText(sel_item, 0);
                wxTreeItemId parent_item = tlc_proj_list->GetItemParent(sel_item);

                s_sql=wxT("UPDATE l_proc_act SET operator_id='")+s_aim_operator+wxT("', group_id='")+s_aim_group+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("' where \
                              instance_id='")+s_wbs+wxT("' and workflow_id='WF0002' AND action_id='AT00000003' and is_active=true;")  ;
            if (wxGetApp().app_sql_update(s_sql))
            {
                wxLogMessage(s_wbs+":授权人成功变更为:"+wxGetApp().get_name(s_aim_operator)+":成功!");
                wxGetApp().change_log("l_proc_act",s_wbs+"-AT00000003","operator_id",gr_para.login_user,s_aim_operator,"by hand");
                //wxGetApp().change_log("l_proc_act",s_wbs+"-AT00000003","group_id",s_own_group,s_aim_group,"by hand");

                tlc_proj_list->Delete(sel_item);

                if(tlc_proj_list->GetChildrenCount(parent_item)== 0)
                    tlc_proj_list->Delete(parent_item);
            }
            else
            {
                wxLogMessage(s_wbs+"变更授权人失败!");
            }
        }
    }


}

