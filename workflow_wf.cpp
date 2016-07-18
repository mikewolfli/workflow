#include "workflow_wf.h"
#include <wx/textdlg.h>
#include <wx/bitmap.h>
#include <wx/clipbrd.h>
#include "unit_info_attach_dlg.h"

//(*InternalHeaders(workflow_wf)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "wfApp.h"
#include "return_log.h"
#include "wf_search.h"
#include "ins_proc_log.h"
#include "evaluate_dlg.h"
#include "nstd_mat_task_list.h"
#include "contractbook_br_dlg.h"

//(*IdInit(workflow_wf)
const long workflow_wf::ID_BUTTON_FEEDBACK = wxNewId();
const long workflow_wf::ID_BUTTON_PASS = wxNewId();
const long workflow_wf::ID_BUTTON_SHOWANDHIDE = wxNewId();
const long workflow_wf::ID_BUTTON_REFRESH = wxNewId();
const long workflow_wf::idMenu_Explain = wxNewId();
const long workflow_wf::idMenu_nstd_level = wxNewId();
const long workflow_wf::idMenu_lender_change = wxNewId();
const long workflow_wf::idMenu_contractbook_search = wxNewId();
const long workflow_wf::idMenu_Feedback = wxNewId();
const long workflow_wf::idMenu_Status = wxNewId();
const long workflow_wf::idMenu_SSearch = wxNewId();
const long workflow_wf::idMenu_Nstd = wxNewId();
const long workflow_wf::idMenu_MTList = wxNewId();
const long workflow_wf::idMenu_Car_or_DC_weight = wxNewId();
const long workflow_wf::idMenu_Res_Filter = wxNewId();
//*)
const long workflow_wf::ID_TREELISTCTRL_TASK_LIST = wxNewId();
const long workflow_wf::ID_TREELISTCTRL_GROUP_TASK_LIST = wxNewId();

BEGIN_EVENT_TABLE(workflow_wf,wxPanel)
    //(*EventTable(workflow_wf)

    //*)
END_EVENT_TABLE()

workflow_wf::workflow_wf(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(workflow_wf)
    wxStaticBoxSizer* StaticBoxSizer2;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxBoxSizer* BoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("流程操作"));
    Button1 = new wxButton(this, ID_BUTTON_FEEDBACK, _("反馈(退回）"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_FEEDBACK"));
    StaticBoxSizer1->Add(Button1, 1, wxALL|wxEXPAND, 0);
    Button2 = new wxButton(this, ID_BUTTON_PASS, _("完成"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_PASS"));
    StaticBoxSizer1->Add(Button2, 1, wxALL|wxEXPAND, 0);
    Button3 = new wxButton(this, ID_BUTTON_SHOWANDHIDE, _("显示/隐藏组员任务表"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_SHOWANDHIDE"));
    StaticBoxSizer1->Add(Button3, 1, wxALL|wxEXPAND, 0);
    Button4 = new wxButton(this, ID_BUTTON_REFRESH, _("刷新任务"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_REFRESH"));
    StaticBoxSizer1->Add(Button4, 1, wxALL|wxEXPAND, 0);
    BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 0);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("任务清单"));
    BoxSizer1->Add(StaticBoxSizer2, 5, wxALL|wxEXPAND|wxFIXED_MINSIZE, 0);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("团队任务清单"));
    BoxSizer1->Add(StaticBoxSizer3, 5, wxALL|wxEXPAND|wxFIXED_MINSIZE, 0);
    SetSizer(BoxSizer1);
    MenuItem1 = new wxMenuItem((&menu_workflow_popup), idMenu_Explain, _("备注(&R)"), _("工作流说明"), wxITEM_NORMAL);
    menu_workflow_popup.Append(MenuItem1);
    MenuItem8 = new wxMenuItem((&menu_workflow_popup), idMenu_nstd_level, _("更新非标等级(&U)"), _("更新非标等级"), wxITEM_NORMAL);
    menu_workflow_popup.Append(MenuItem8);
    mi_cb_change = new wxMenuItem((&menu_workflow_popup), idMenu_lender_change, _("项目合同转借"), _("项目合同转借"), wxITEM_NORMAL);
    menu_workflow_popup.Append(mi_cb_change);
    mi_contractbook_br_search = new wxMenuItem((&menu_workflow_popup), idMenu_contractbook_search, _("项目合同借阅查询"), _("项目合同借阅查询"), wxITEM_NORMAL);
    menu_workflow_popup.Append(mi_contractbook_br_search);
    menu_workflow_popup.AppendSeparator();
    MenuItem2 = new wxMenuItem((&menu_workflow_popup), idMenu_Feedback, _("显示退回源(&F)\tF"), _("显示谁退回的"), wxITEM_NORMAL);
    menu_workflow_popup.Append(MenuItem2);
    MenuItem3 = new wxMenuItem((&menu_workflow_popup), idMenu_Status, _("工作流查询(&W)\tW"), _("工作流查询"), wxITEM_NORMAL);
    menu_workflow_popup.Append(MenuItem3);
    MenuItem4 = new wxMenuItem((&menu_workflow_popup), idMenu_SSearch, _("工作流条件查询(&C)\tC"), _("工作流条件查询"), wxITEM_NORMAL);
    menu_workflow_popup.Append(MenuItem4);
    menu_workflow_popup.AppendSeparator();
    MenuItem5 = new wxMenuItem((&menu_workflow_popup), idMenu_Nstd, _("显示非标选项(&L)\tL"), _("显示非标选项("), wxITEM_NORMAL);
    menu_workflow_popup.Append(MenuItem5);
    MenuItem6 = new wxMenuItem((&menu_workflow_popup), idMenu_MTList, _("显示非标物料清单(&M)\tM"), _("显示非标物料清单"), wxITEM_NORMAL);
    menu_workflow_popup.Append(MenuItem6);
    menu_workflow_popup.AppendSeparator();
    MenuItem_WEIGHT = new wxMenuItem((&menu_workflow_popup), idMenu_Car_or_DC_weight, _("显示/修改轿厢空重和装潢重量(&D)"), _("显示轿厢空重和装潢重量"), wxITEM_NORMAL);
    menu_workflow_popup.Append(MenuItem_WEIGHT);
    MenuItem7 = new wxMenuItem((&menu_worflow_group_popup), idMenu_Res_Filter, _("按人员筛选(&F)\tF"), _("按人员筛选"), wxITEM_NORMAL);
    menu_worflow_group_popup.Append(MenuItem7);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON_FEEDBACK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workflow_wf::OnButton1Click);
    Connect(ID_BUTTON_PASS,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workflow_wf::OnButton2Click);
    Connect(ID_BUTTON_SHOWANDHIDE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workflow_wf::OnButton3Click);
    Connect(ID_BUTTON_REFRESH,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workflow_wf::OnButton4Click);
    Connect(idMenu_Explain,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&workflow_wf::OnMenuItem1Selected);
    Connect(idMenu_nstd_level,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&workflow_wf::OnMenuItem8Selected);
    Connect(idMenu_lender_change,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&workflow_wf::Onmi_cb_changeSelected);
    Connect(idMenu_contractbook_search,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&workflow_wf::Onmi_contractbook_br_searchSelected);
    Connect(idMenu_Feedback,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&workflow_wf::OnMenuItem2Selected);
    Connect(idMenu_Status,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&workflow_wf::OnMenuItem3Selected);
    Connect(idMenu_SSearch,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&workflow_wf::OnMenuItem4Selected);
    Connect(idMenu_Nstd,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&workflow_wf::OnMenuItem5Selected);
    Connect(idMenu_MTList,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&workflow_wf::OnMenuItem6Selected);
    Connect(idMenu_Car_or_DC_weight,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&workflow_wf::OnMenuItem_WEIGHTSelected);
    Connect(idMenu_Res_Filter,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&workflow_wf::OnMenuItem7Selected);
    //*)
    Connect(ID_TREELISTCTRL_TASK_LIST, wxEVT_TREE_ITEM_RIGHT_CLICK,(wxObjectEventFunction)&workflow_wf::On_task_list_RightClick);
    Connect(ID_TREELISTCTRL_TASK_LIST, wxEVT_TREE_KEY_DOWN,(wxObjectEventFunction)&workflow_wf::OnKeyDown);
    Connect(ID_TREELISTCTRL_GROUP_TASK_LIST, wxEVT_TREE_ITEM_RIGHT_CLICK,(wxObjectEventFunction)&workflow_wf::On_group_task_list_RightClick);

    BuildTreeListCtrl();
    StaticBoxSizer2->Add(tlc_task_list, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    StaticBoxSizer3->Add(tlc_group_task_list, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);

    sb_group_tasks = StaticBoxSizer3->GetStaticBox();

    sizer_group_task = BoxSizer1->GetItem(StaticBoxSizer3);
    sizer_tasks = BoxSizer1->GetItem(StaticBoxSizer2);

    b_show = false;

    int i_count;

    if(gr_para.login_status)
    {
        array_group = wxGetApp().get_group();
        for(int i=0; i<array_group.GetCount(); i++)
        {
            if(wxGetApp().is_leader(array_group.Item(i)))
                array_leader_group.Add(array_group.Item(i));
        }


        array_worker = wxGetApp().get_sub_eng_list(i_count);

        if(array_leader_group.GetCount()!=0||i_count!=0)
        {
            b_show = true;

            sizer_tasks->SetProportion(5);
            sizer_group_task->SetProportion(5);

        }
        else
        {
            Button3->Show(false);
            sizer_tasks->SetProportion(10);
        }
    }

    sb_group_tasks->Show(b_show);
    tlc_group_task_list->Show(b_show);
    refresh_list();
    Layout();
}

workflow_wf::~workflow_wf()
{
    //(*Destroy(workflow_wf)


    //*)
    delete m_imageList;
    wxTreeItemId root = tlc_task_list->GetRootItem();
    tlc_task_list->DeleteChildren (root);
    tlc_task_list->DeleteRoot();

    root = tlc_group_task_list->GetRootItem();
    tlc_group_task_list->DeleteChildren (root);
    tlc_group_task_list->DeleteRoot();

}

void workflow_wf::InitImageList()
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

void workflow_wf::BuildTreeListCtrl()
{
    //initial task list for every one.
    InitImageList();
    tlc_task_list = new wxcode::wxTreeListCtrl(this, ID_TREELISTCTRL_TASK_LIST,
                                  wxDefaultPosition, wxDefaultSize,
                                  wxTR_DEFAULT_STYLE| wxTR_COLUMN_LINES|wxTR_HIDE_ROOT|wxTR_ROW_LINES|wxTR_MULTIPLE | wxTR_FULL_ROW_HIGHLIGHT);

    tlc_task_list->AddColumn(_("项目步骤"),100,wxALIGN_LEFT,-1,true,false);//0
    tlc_task_list->AddColumn(_("WBS NO"),400,wxALIGN_LEFT,-1,true,false);//1
    tlc_task_list->AddColumn(_("任务批次"),0,wxALIGN_LEFT,-1,false,false);//2
    tlc_task_list->AddColumn(_("项目信息"), 100, wxALIGN_LEFT, -1,true,false );//3
    tlc_task_list->AddColumn(_("梯型"),100,wxALIGN_LEFT, -1,true,false );//4
    tlc_task_list->AddColumn(_("配置完成日期"), 100, wxALIGN_LEFT, -1,true,false );//5
    tlc_task_list->AddColumn(_("退回\n任务"), 80, wxALIGN_LEFT, -1,true,false );//6
    tlc_task_list->AddColumn(_("项目状态"), 100, wxALIGN_LEFT, -1,true,false );//7
    tlc_task_list->AddColumn(_("发货期"), 100, wxALIGN_LEFT, -1,true,false );//8
    tlc_task_list->AddColumn(_("非标等级"), 100, wxALIGN_LEFT,-1, true,false);//9
    tlc_task_list->AddColumn(_("特殊标识"), 100, wxALIGN_LEFT, -1, true, false); //18-10
    tlc_task_list->AddColumn(_("备注"), 100, wxALIGN_LEFT, -1,true,false );//10-11
    tlc_task_list->AddColumn(_("工作流ID"), 0, wxALIGN_LEFT, -1,false,false );//11-12
    tlc_task_list->AddColumn(_("工作步ID"), 0, wxALIGN_LEFT, -1,false,false );//12-13
    tlc_task_list->AddColumn(_("紧急项目"), 0, wxALIGN_LEFT, -1,false,false );//13-14
    tlc_task_list->AddColumn(_("退回次数"), 0, wxALIGN_LEFT, -1,false,false );//14-15
    tlc_task_list->AddColumn(_("项目类型"), 0, wxALIGN_LEFT, -1,false,false );//15-16
    tlc_task_list->AddColumn(_("工作步顺序号"), 0, wxALIGN_LEFT, -1,false,false );//16-17
    tlc_task_list->AddColumn(_("标识"),0, wxALIGN_LEFT, -1, false, false);//17-18


    tlc_task_list->AddRoot (_("配置项目"));

    tlc_group_task_list = new wxcode::wxTreeListCtrl(this, ID_TREELISTCTRL_GROUP_TASK_LIST,
                                  wxDefaultPosition, wxDefaultSize,
                                  wxTR_DEFAULT_STYLE| wxTR_COLUMN_LINES|wxTR_HIDE_ROOT|wxTR_ROW_LINES | wxTR_FULL_ROW_HIGHLIGHT);


    tlc_group_task_list->AddColumn(_("项目步骤"),100,wxALIGN_LEFT,-1,true,false);//0
    tlc_group_task_list->AddColumn(_("WBS NO"),400,wxALIGN_LEFT,-1,true,false);//1
    tlc_group_task_list->AddColumn(_("任务批次"),0,wxALIGN_LEFT,-1,false,false);//2
    tlc_group_task_list->AddColumn(_("操作人"),100,wxALIGN_LEFT,-1,true,false);//3
    tlc_group_task_list->AddColumn(_("项目信息"), 100, wxALIGN_LEFT, -1,true,false );//4
    tlc_group_task_list->AddColumn(_("梯型"),100,wxALIGN_LEFT, -1,true,false );//5
    tlc_group_task_list->AddColumn(_("配置完成日期"), 100, wxALIGN_LEFT, -1,true,false );//6
    tlc_group_task_list->AddColumn(_("退回\n任务"), 80, wxALIGN_LEFT, -1,true,false );//7
    tlc_group_task_list->AddColumn(_("项目状态"), 100, wxALIGN_LEFT, -1,true,false );//8
    tlc_group_task_list->AddColumn(_("发货期"), 100, wxALIGN_LEFT, -1,true,false );//9
    tlc_group_task_list->AddColumn(_("非标等级"), 100, wxALIGN_LEFT,-1, true,false);//10
    tlc_group_task_list->AddColumn(_("特殊标识"), 100, wxALIGN_LEFT, -1, true, false);//16-11
    tlc_group_task_list->AddColumn(_("备注"), 100, wxALIGN_LEFT, -1,true,false );//11-12
    tlc_group_task_list->AddColumn(_("工作步ID"), 0, wxALIGN_LEFT, -1,false,false );//12-13
    tlc_group_task_list->AddColumn(_("紧急项目"), 0, wxALIGN_LEFT, -1,false,false );//13-14
    tlc_group_task_list->AddColumn(_("退回次数"), 0, wxALIGN_LEFT, -1,false,false );//14-15
    tlc_group_task_list->AddColumn(_("项目类型"), 0, wxALIGN_LEFT, -1,false,false );//15-16


    tlc_group_task_list->AddRoot (_("配置项目"));

}

void workflow_wf::refresh_list()
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

 /*   old_array.Empty();

    int i_result = tlc_task_list->GetNumberRows();
    for(int i= 0; i<i_result; i++)
    {
        old_array.Add(tlc_task_list->GetCellValue(i,0));
    }
*/
    wxPostgreSQLresult* _res;
    wxString str_query;

    wxTreeItemId root = tlc_task_list->GetRootItem();
    tlc_task_list->DeleteChildren (root);

    str_query = wxT("SELECT  conf_batch_id, instance_id, action_id, workflow_id, action_name, concat(elevator_id,'-',elevator_type) as elevator_type, concat(contract_id, ' ', project_name) as project_name,special_info, \
                    lift_no , req_configure_finish as req_finish_date , is_return, req_delivery_date, nonstd_level, (select doc_desc from s_doc where doc_id = step_desc_id) as doc_desc , workflow_id, status, is_urgent, return_time, project_catalog, flow_ser,flag FROM v_task_list1 WHERE \
                    is_active = true AND operator_id = '")+gr_para.login_user+wxT("' AND (workflow_id = 'WF0002' or workflow_id='WF0006') ORDER BY  req_finish_date, conf_batch_id, action_id, instance_id ASC ;");

//   wxLogMessage(str_query);
    _res = wxGetApp().app_sql_select(str_query);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        return;
    }

    wxString s_wbs, s_index, s_batch_id, s_project_name, s_action_id;
    m_rows = _res->GetRowsNumber();
     _res->MoveFirst();

     wxTreeItemId branch_item,leaf_item;

    for(int i=0;i<m_rows;i++)
    {
        s_batch_id = _res->GetVal(wxT("conf_batch_id"));
        s_wbs = _res->GetVal(wxT("instance_id"));
        s_project_name = _res->GetVal(wxT("project_name"));


        if(s_batch_id.IsEmpty())
        {
            if(s_index != s_wbs.Left(10) || s_action_id != _res->GetVal(wxT("action_id")))
            {
                s_index = s_wbs.Left(10);
                branch_item = tlc_task_list->AppendItem(root, _res->GetVal(wxT("action_name")));
                tlc_task_list->SetItemText(branch_item,2, s_index);
                tlc_task_list->SetItemText(branch_item, 1,s_project_name+"-"+s_index);
 //               tlc_task_list->Expand(branch_item);
            }

        }else
        {
            if(s_index != s_batch_id)
            {
                s_index = s_batch_id;
                branch_item = tlc_task_list->AppendItem(root, _res->GetVal(wxT("action_name")));
                tlc_task_list->SetItemText(branch_item, 2, s_index);
                tlc_task_list->SetItemText(branch_item, 1, s_project_name+"-"+s_wbs.Left(10) );
   //             tlc_task_list->Expand(branch_item);
            }
        }

        s_action_id = _res->GetVal(wxT("action_id"));
        leaf_item = tlc_task_list->AppendItem(branch_item,_res->GetVal(wxT("action_name")),-1,-1);
        tlc_task_list->SetItemText(leaf_item, 1, s_wbs);
        tlc_task_list->SetItemText(leaf_item, 2, s_index);
        tlc_task_list->SetItemText(leaf_item, 3, _res->GetVal(wxT("lift_no")));
        tlc_task_list->SetItemText(leaf_item, 4, _res->GetVal(wxT("elevator_type")));
        tlc_task_list->SetItemText(leaf_item, 5, DateToStrFormat(_res->GetDate(wxT("req_finish_date"))));
        tlc_task_list->SetItemText(leaf_item, 6, BoolToY(_res->GetBool(wxT("is_return"))));
        tlc_task_list->SetItemText(leaf_item, 7, prj_status_to_str(_res->GetInt(wxT("status"))));
        tlc_task_list->SetItemText(leaf_item, 8, DateToStrFormat(_res->GetDate(wxT("req_delivery_date"))));
        tlc_task_list->SetItemText(leaf_item, 9, nstd_level_to_str(_res->GetInt(wxT("nonstd_level"))));
        tlc_task_list->SetItemText(leaf_item, 10, _res->GetVal(wxT("special_info")));
        tlc_task_list->SetItemText(leaf_item, 11, _res->GetVal(wxT("doc_desc")));
        tlc_task_list->SetItemText(leaf_item, 12, _res->GetVal(wxT("workflow_id")));
        tlc_task_list->SetItemText(leaf_item, 13, s_action_id);
        tlc_task_list->SetItemText(leaf_item, 14, BoolToY(_res->GetBool(wxT("is_urgent"))));
        tlc_task_list->SetItemText(leaf_item, 15, _res->GetVal(wxT("return_time")));
        tlc_task_list->SetItemText(leaf_item, 16, _res->GetVal(wxT("project_catalog")));
        tlc_task_list->SetItemText(leaf_item, 17, _res->GetVal(wxT("flow_ser")));
        tlc_task_list->SetItemText(leaf_item, 18, _res->GetVal(wxT("flag")));


        _res->MoveNext();
    }

    _res->Clear();
/*
    new_array.Empty();

    for(int i= 0; i<m_rows; i++)
    {
        new_array.Add(tlc_task_list->GetCellValue(i,0));
    }
*/
    refresh_group(b_show);

    refresh_task_level();
    refresh_group_level(b_show);
}

void workflow_wf::refresh_group(bool b_sh)
{
    if(!b_sh)
        return;

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

    wxTreeItemId root = tlc_group_task_list->GetRootItem();
    tlc_group_task_list->DeleteChildren (root);

    wxPostgreSQLresult* _res;
    wxString str_query1, str_query2;

    int icount = array_leader_group.GetCount();
    if(icount<=0)
        return;

    if(icount>0)
    {
        str_query1 = wxT("SELECT  conf_batch_id, instance_id, action_id, name as operator_name, action_name, concat(elevator_id,'-',elevator_type) as elevator_type, concat(contract_id, ' ', project_name) as project_name,special_info, \
                    lift_no , req_configure_finish as req_finish_date , is_return, req_delivery_date, nonstd_level, (select doc_desc from s_doc where doc_id = step_desc_id) as doc_desc , workflow_id, status, is_urgent, return_time, project_catalog  FROM v_task_list1 WHERE \
                     is_active = true AND operator_id != '")+gr_para.login_user+wxT("' AND group_id = '")+array_leader_group.Item(0)+wxT("' ");

        for(int i=1; i<icount; i++)
        {
            str_query1  = str_query1 + wxT(" OR group_id = '")+array_leader_group.Item(i)+wxT("' ");
        }



        str_query1 = str_query1 + wxT(" ORDER BY  req_finish_date, conf_batch_id, action_id, instance_id ASC ; ");
    }

  /*  if(!array_worker.IsEmpty())
    {
        str_query2 = wxT("(SELECT  conf_batch_id, instance_id, action_id, name as operator_name, action_name, concat(elevator_id,'-',elevator_type) as elevator_type, concat(contract_id, ' ', project_name) as project_name,\
                    lift_no , req_configure_finish as req_finish_date , is_return, req_delivery_date, nonstd_level, (select doc_desc from s_doc where doc_id = step_desc_id) as doc_desc , workflow_id, status, is_urgent, return_time, project_catalog from v_task_list1 where \
                    is_active = true  AND (workflow_id = 'WF0002' or workflow_id='WF0006') and (");

       int  i_row = array_worker.GetCount();

        for(int j=0;j<i_row ;j++)
        {
            if(j==i_row -1)
                str_query2 = str_query2 + wxT("  operator_id='")+array_worker.Item(j).Left(8)+wxT("') ");
            else
               str_query2 = str_query2 + wxT(" operator_id='")+array_worker.Item(j).Left(8)+wxT("' or ");
        }

        str_query2 = str_query2 + wxT(" ORDER BY  req_finish_date, conf_batch_id, action_id, instance_id ASC ) ");

        if(icount<1)
        {
            str_query1 = str_query2;
        }
    }

    if(icount>0 && !array_worker.IsEmpty())
    {
        str_query1=str_query1+wxT(" UNION ")+str_query2;
    }else if(icount<1 && array_worker.IsEmpty())
    {
        return;
    }*/


    _res = wxGetApp().app_sql_select(str_query1);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        return;
    }

    wxString s_wbs, s_index, s_batch_id, s_project_name, s_action_id;
    m_rows = _res->GetRowsNumber();
     _res->MoveFirst();

    wxTreeItemId branch_item,leaf_item;

    for(int i=0;i<m_rows;i++)
    {
        s_batch_id = _res->GetVal(wxT("conf_batch_id"));
        s_wbs = _res->GetVal(wxT("instance_id"));
        s_project_name = _res->GetVal(wxT("project_name"));


        if(s_batch_id.IsEmpty())
        {
            if(s_index != s_wbs.Left(10) || s_action_id != _res->GetVal(wxT("action_id")))
            {
                s_index = s_wbs.Left(10);
                branch_item = tlc_group_task_list->AppendItem(root, _res->GetVal(wxT("action_name")));
                tlc_group_task_list->SetItemText(branch_item,2, s_index);
                tlc_group_task_list->SetItemText(branch_item, 1,s_project_name+"-"+s_index);
 //               tlc_group_task_list->Expand(branch_item);
            }

        }else
        {
            if(s_index != s_batch_id)
            {
                s_index = s_batch_id;
                branch_item = tlc_group_task_list->AppendItem(root, _res->GetVal(wxT("action_name")));
                tlc_group_task_list->SetItemText(branch_item, 2, s_index);
                tlc_group_task_list->SetItemText(branch_item, 1, s_project_name+"-"+s_wbs.Left(10) );
 //               tlc_group_task_list->Expand(branch_item);
            }
        }

        s_action_id = _res->GetVal(wxT("action_id"));
        leaf_item = tlc_group_task_list->AppendItem(branch_item,_res->GetVal(wxT("action_name")),-1,-1);
        tlc_group_task_list->SetItemText(leaf_item, 1, s_wbs);
        tlc_group_task_list->SetItemText(leaf_item, 2, s_index);
        tlc_group_task_list->SetItemText(leaf_item, 3, _res->GetVal(wxT("operator_name")));
        tlc_group_task_list->SetItemText(leaf_item, 4, _res->GetVal(wxT("lift_no")));
        tlc_group_task_list->SetItemText(leaf_item, 5, _res->GetVal(wxT("elevator_type")));
        tlc_group_task_list->SetItemText(leaf_item, 6, DateToStrFormat(_res->GetDate(wxT("req_finish_date"))));
        tlc_group_task_list->SetItemText(leaf_item, 7, BoolToY(_res->GetBool(wxT("is_return"))));
        tlc_group_task_list->SetItemText(leaf_item, 8, prj_status_to_str(_res->GetInt(wxT("status"))));
        tlc_group_task_list->SetItemText(leaf_item, 9, DateToStrFormat(_res->GetDate(wxT("req_delivery_date"))));
        tlc_group_task_list->SetItemText(leaf_item, 10, nstd_level_to_str(_res->GetInt(wxT("nonstd_level"))));
        tlc_group_task_list->SetItemText(leaf_item, 11, _res->GetVal(wxT("special_info")));
        tlc_group_task_list->SetItemText(leaf_item, 12, _res->GetVal(wxT("doc_desc")));
        tlc_group_task_list->SetItemText(leaf_item, 13, s_action_id );
        tlc_group_task_list->SetItemText(leaf_item, 14, BoolToY(_res->GetBool(wxT("is_urgent"))));
        tlc_group_task_list->SetItemText(leaf_item, 15, _res->GetVal(wxT("return_time")));
        tlc_group_task_list->SetItemText(leaf_item, 16, _res->GetVal(wxT("project_catalog")));


        _res->MoveNext();
    }


    _res->Clear();
}

bool workflow_wf::check_prj_info_attach_finished(wxArrayString& a_wbs)
{
    wxString str_sql = wxT("select wbs_no, (select is_basic_finish from s_unit_info_attach where wbs_no = v_unit_info.wbs_no) as \
                           is_finished from v_unit_info where ");

    int i_count = a_wbs.GetCount();

    bool b_pass = true;

    wxArrayString a_no_finish_wbs;

    for(int i=0;i<i_count;i++)
    {
       if(i_count ==1)
         str_sql = str_sql +wxT(" wbs_no='")+a_wbs.Item(i)+wxT("' ");
       else
       {
           if(i==0)
            str_sql = str_sql+wxT(" wbs_no in ('")+a_wbs.Item(i)+wxT("', ");
           else if(i== i_count -1)
             str_sql  = str_sql + wxT("'")+a_wbs.Item(i)+wxT("') ");
           else
            str_sql = str_sql + wxT(" '")+a_wbs.Item(i)+wxT("', ");
       }
    }

    str_sql = str_sql+ wxT(" and elevator_type in ('TE-GL1','TE-GL','TE-Evolution1','RF1','RF2','TE-HP61','TE-Synergy','RF3') order by wbs_no ASC;");

   // wxMessageBox(str_sql ,_(""));
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);


    if(_res->Status()!= PGRES_TUPLES_OK)
    {
         _res->Clear();
        return false;
    }

    int i_rows = _res->GetRowsNumber();
    wxString str;
    bool b_finish;

    bool b_return = true;

    for(int j=0;j<i_rows;j++)
    {
         str = _res->GetVal(wxT("wbs_no"));
         a_no_finish_wbs.Add(str);

         b_finish = _res->GetBool(wxT("is_finished"));

         if(!b_finish)
            b_return =false;

         _res->MoveNext();

    }
    _res->Clear();

    if(!b_return)
    {
         wxLogMessage(_("任务中有相关项目基本参数未填写完整，请在弹出窗口中填写完整后，再继续!"));
        unit_info_attach_dlg dlg;
        dlg.Set_Editable(true);
        dlg.refresh_control();
        dlg.array_wbs = a_no_finish_wbs;

        dlg.refresh_list();

        if(dlg.ShowModal()==wxID_CANCEL)
            return false;
    }

    return true;
}

void workflow_wf::OnButton3Click(wxCommandEvent& event)
{
    if(b_show)
    {
        b_show = false;


        sizer_group_task->Show(b_show);
        sizer_tasks->SetProportion(10);
    }
    else
    {
        b_show = true;


        sizer_tasks->SetProportion(5);
        sizer_group_task->SetProportion(5);

    }

    sb_group_tasks->Show(b_show);
    tlc_group_task_list->Show(b_show);
    Layout();

    refresh_group(b_show);
}

bool workflow_wf::check_other_way(wxString s_instance, wxString s_flag)
{
     wxString s_sql = wxT("select * from l_proc_act where instance_id='")+s_instance+wxT("' and workflow_id='WF0006' and is_active=True and flow_ser<=3 and flag !='")+s_flag+wxT("';");
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

wxArrayString workflow_wf::get_other_way(wxString s_lift_type, wxString s_flag)
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

bool workflow_wf::check_contract_br_log(wxString s_wbs, wxString &s_cid)
{
    s_cid.Empty();
    int i_count;
    wxString s_sql = wxT("select contract_doc_id from s_contract_book_include where wbs_no='")+s_wbs+wxT("' and is_del=false;");
    wxPostgreSQLresult * res=wxGetApp().app_sql_select(s_sql);
    if(res->Status()!= PGRES_TUPLES_OK)
    {
        res->Clear();
    }else
    {
        i_count =  res->GetRowsNumber();

        if(i_count>0)
        {
            s_cid=res->GetVal(wxT("contract_doc_id"));


        }
        res->Clear();
    }

    if(s_cid.IsEmpty())
    {
        s_sql = wxT("select * from v_contract_br_log where project_id ='")+s_wbs.Left(10)+wxT("' and br_status=true and b_user='")+gr_para.login_user+wxT("' order by b_date asc;");
        res=wxGetApp().app_sql_select(s_sql);
        if(res->Status()!= PGRES_TUPLES_OK)
        {
            res->Clear();
            return false;
        }

        int i_count = res->GetRowsNumber();

        if(i_count==0)
        {
            res->Clear();
            return false;
        }

        s_cid = res->GetVal("contract_doc_id");
        res->Clear();
        return true;

    }else
    {
        s_sql = wxT("select count(*) as count from v_contract_br_log where contract_doc_id ='")+s_cid+wxT("' and br_status=true and b_user='")+gr_para.login_user+wxT("' ;");
        res=wxGetApp().app_sql_select(s_sql);
        if(res->Status()!= PGRES_TUPLES_OK)
        {
            res->Clear();
            s_cid.Empty();
            return false;
        }

        i_count = res->GetInt(wxT("count"));

        if(i_count==0)
        {
            s_cid.Empty();
            res->Clear();
            return false;
        }

        res->Clear();

        return true;

    }
}

bool workflow_wf::close_finished_nonstd(wxString s_wbs, wxString s_flag)
{
     wxString s_sql = wxT(" select l_nonstd_app_header.nonstd_id,l_nonstd_app_item.index_id, l_nonstd_app_item_instance.index_mat_id, l_nonstd_app_item_instance.status from \
                              l_nonstd_app_header join l_nonstd_app_item on l_nonstd_app_header.nonstd_id=l_nonstd_app_item.nonstd_id left join l_nonstd_app_item_instance on \
                              l_nonstd_app_item.index_id=l_nonstd_app_item_instance.index_id where l_nonstd_app_item.link_list like '%")+s_wbs+wxT("%' and l_nonstd_app_item.item_catalog='")+s_flag+wxT("' and \
                               l_nonstd_app_header.status>=0 and l_nonstd_app_header.status<10 and l_nonstd_app_item_instance.status>=0 and l_nonstd_app_item.res_person='")+gr_para.login_user+wxT("';");

    wxPostgreSQLresult * res=wxGetApp().app_sql_select(s_sql);
    if(res->Status()!= PGRES_TUPLES_OK)
    {
        res->Clear();
        return false;
    }

    int i_count = res->GetRowsNumber();
    wxString str;
    wxArrayString a_nonstd_id;

    bool b_result = true;

    if(i_count==0)
        return b_result;

    for( int i=0;i<i_count;i++)
    {
        int i_status = res->GetInt(wxT("status"));
        wxString s_nstd=res->GetVal(wxT("nonstd_id"));
        int i_pos = a_nonstd_id.Index(s_nstd);
        if (i_status==2)
        {
            if(i_pos==wxNOT_FOUND)
            {
                a_nonstd_id.Add(s_nstd);
            }

        }else
        {
            wxString s_temp= res->GetVal(wxT("index_id"));
            str=str+s_temp+";";
            b_result=false;

            if(i_pos !=wxNOT_FOUND)
            {
                a_nonstd_id.Remove(s_nstd);
            }
        }

    }

    if(!b_result)
    {
        wxLogMessage(str+"非标处理未完成，请先处理完成后再确认!");
    }else
    {
        int i_close = a_nonstd_id.GetCount();
        for(int i=0;i<i_close;i++)
        {
            wxGetApp().update_new_nstd_config(a_nonstd_id.Item(i), 10);
        }
    }

    return b_result;
}

void workflow_wf::OnButton2Click(wxCommandEvent& event)
{
    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_task_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_task_list->GetSelections( items );
    wxTreeItemId del_item;

    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(items.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }

    /*  wxTextEntryDialog tdlg(this,_("流程提示输入: \n 注意: 取消则是将本步备注传递给下步!"),_("备注"),wxT(""),wxOK |wxCANCEL | wxTE_MULTILINE,wxDefaultPosition );
        wxString str_desc;
        if(tdlg.ShowModal()== wxID_OK)
        {
            b_log_pass = false;
            str_desc= tdlg.GetValue();
        }
        else b_log_pass = true;
    */

    wxLongLong mils_used, start_mils;
    bool b_first = true;
    wxString str_workflow_id, str_instance, str_group, str_operator, str_temp;

    bool b_goto = true;
    bool b_closed = false;
    wxString str_desc=wxEmptyString;
    bool b_log_pass = true;

    v_wf_action * t_template=0;

    wf_operator * wf_active=0;
    wf_operator_ex * wf_new_active=0;

    wf_process * l_proc_act =0;
    int i_status;

    wxString s_index = wxEmptyString;//for evaluate
    v_wf_instance now_step,next_step;

    wxTreeItemId sel_item, child_item;
    wxTreeItemIdValue cookie;
    wxArrayString a_sel_wbs, a_operator, a_flag;
    wxString s_action_id;
    wxString s_flag, s_role,s_lift_type,s_flag_ex, s_cid;
    int i_operator=0;
    int i_flow_ser;

    for( iter = items.begin(); iter<items.end(); iter++)
    {
         sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item)==root)
        {
            child_item = tlc_task_list->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {
               str_temp = tlc_task_list->GetItemText(child_item, 1);
               s_action_id = tlc_task_list->GetItemText(child_item,12);
               a_sel_wbs.Add(str_temp);

               child_item = tlc_task_list->GetNextSibling(child_item);
            }
        }else
        {
               s_action_id = tlc_task_list->GetItemText(sel_item,12);
               str_temp = tlc_task_list->GetItemText(sel_item, 1);
               a_sel_wbs.Add(str_temp);
        }
    }

    if(s_action_id == wxT("AT00000004"))
    {

        if(!check_prj_info_attach_finished(a_sel_wbs))
        {

            return;
        }
    }

    if(wxMessageBox(_("确认所选项目已经完成?"),_("完成确认："),wxOK|wxCANCEL,this)==wxCANCEL)
    {
        return;
    }

    bool b_active=true;

    for( iter = items.begin(); iter<items.end(); iter++)
    {
         sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item)==root)
        {

           child_item = tlc_task_list->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {
                b_active=true;
                a_operator.Clear();
                a_flag.Clear();

                start_mils = wxGetLocalTimeMillis();

                str_instance = tlc_task_list->GetItemText(child_item,1);
                i_status = prj_str_to_status(tlc_task_list->GetItemText(child_item, 7));
                s_flag = tlc_task_list->GetItemText(child_item, 18);
                s_lift_type = tlc_task_list->GetItemText(child_item, 4).Left(9);
                i_flow_ser = StrToInt(tlc_task_list->GetItemText(child_item, 17));

                if(i_status == 4)
                {
                    wxLogMessage(_("项目")+str_instance +_("已经暂停! 无法继续!"));
                    continue;
                }
                else if(i_status== 5)
                {
                    wxLogMessage(_("项目")+str_instance +_("已经关闭! 无法继续!"));
                    continue;
                }

                if(str_workflow_id != tlc_task_list->GetItemText(child_item, 12))//nonstd_level already done.
                {
                    str_workflow_id = tlc_task_list->GetItemText(child_item, 12);//nonstd_level already done.
                    if(t_template)
                        delete [] t_template;
                    t_template = get_template_action(str_workflow_id);
                }

                if(str_workflow_id == wf_str_configure)
                {
                     wf_active = new wf_operator(str_instance, str_workflow_id, t_template);
                     l_proc_act = wf_active->get_current_process();
                }else if(str_workflow_id == wf_str_new_config)
                {
                    if(s_flag.Contains(wxT("+")))
                        s_flag_ex=wxT("E");
                    else
                        s_flag_ex=s_flag;
                    wf_new_active = new wf_operator_ex(str_instance, str_workflow_id, t_template, s_flag_ex);
                    l_proc_act = wf_new_active->get_current_process();
                }

                //for evaluate
                if(s_index != tlc_task_list->GetItemText(child_item, 2))
                {
                    s_index = tlc_task_list->GetItemText(child_item, 2);
                    if(!make_evaluate(l_proc_act, s_index))
                    {
                        if(wf_active)
                             delete wf_active;
                        if(wf_new_active)
                             delete wf_new_active;
                        l_proc_act = 0;
                        return;
                    }

                }
                //for evaluate

                l_proc_act->MoveToActive();
                now_step = l_proc_act->get_cur_instance_action();

                if(now_step.s_action.s_operator_id!=gr_para.login_user)
                {
                    child_item = tlc_task_list->GetNextSibling(child_item);
                    continue;
                }


                if(!now_step.is_active)
                {
                    child_item = tlc_task_list->GetNextSibling(child_item);
                    continue;
                }


                if(l_proc_act->GetCurrentStep() == l_proc_act->GetTotalSteps()&&l_proc_act->GetTotalSteps()!= now_step.s_action.i_total_flow)
                {

                    next_step.s_action = t_template[now_step.s_action.i_flow_ser];
                    next_step.s_instance_id = str_instance;
                }
                else if(l_proc_act->GetCurrentStep() != l_proc_act->GetTotalSteps())
                {
                    next_step = l_proc_act->get_next_instance_action();
                    if(next_step.s_action.i_flow_ser != now_step.s_action.i_flow_ser+1)
                    {
                        next_step.s_action = t_template[now_step.s_action.i_flow_ser];
                        next_step.s_instance_id = str_instance;
                    }
                }

                if(now_step.s_action.i_flow_ser == now_step.s_action.i_total_flow)
                {
                     b_goto = false;
                     b_closed = true;
                }
                else
                {
                    b_goto = true;
                    b_closed =false;
                  }

/*
                if(now_step.s_action.s_action_type == wxT("G")&& now_step.s_action.b_is_assigned)
                {

                    str_group = now_step.s_action.s_group_id;
                    wxArrayString  s_members = wxGetApp().get_member_in_group(str_group);

                    if(b_first)
                    {
                        wxSingleChoiceDialog cdlg(this, _("请选择操作人员:"),_("操作选择"),s_members);

                        if(cdlg.ShowModal() == wxID_OK)
                        {
                            str_operator = cdlg.GetStringSelection();
                        }
                        else
                        {
                            wxLogMessage(_("未选择操作人员，操作退出!"));
                            return;
                        }

                        b_first = false;

                        int i_pos = str_operator.Find('-');

                        str_operator = str_operator.Left(i_pos);

                    }

                    b_goto = false;
                }*/
                if(str_workflow_id==wf_str_configure)
                {
                    if(b_goto)//b_goto控制是否需要移向下一步。
                    {

                        if(next_step.s_action.s_action_type == wxT("G") && !next_step.s_action.b_is_assigned)
                        {
                            str_group = now_step.s_action.s_group_id;
                            str_operator = wxGetApp().get_leader(str_group);
                            b_first = true;
                        }

                        if(next_step.s_action.s_action_type == wxT("P") && !next_step.s_action.b_is_assigned)
                        {
                            str_group = next_step.s_action.s_group_id;
                            str_operator = next_step.s_action.s_operator_id;

                            b_first = true;
                        }

                        if(next_step.s_action.s_action_type == wxT("P")&& next_step.s_action.b_is_assigned)
                        {
                            if(b_first)//b_first控制操作人第一次循环设定。
                            {
                                str_group = next_step.s_action.s_group_id;
                                if(str_group.IsEmpty())
                                    str_group = now_step.s_action.s_group_id;

                                wxArrayString str_group_list;
                                if(str_group.Contains(wxT(";")))
                                {
                                    str_group_list = wxStringTokenize(str_group,wxT(";"), wxTOKEN_DEFAULT );
                                }
                                else
                                    str_group_list.Add(str_group);

                                wxArrayString  s_members = wxGetApp().get_member_in_group(str_group_list, true);

                                wxSingleChoiceDialog cdlg(this, _("请选择操作人员:"),_("操作选择"),s_members);


                                if(cdlg.ShowModal() == wxID_OK)
                                {
                                    //                   b_first = false;
                                }
                                else
                                {
                                    return;
                                    //                 b_first = true;
                                }

                                b_first  = false;

                                str_operator = cdlg.GetStringSelection().Left(8);


//                           int i_pos = str_operator.Find('-');

                                //                          str_operator.Left(i_pos);

                            }
                        }

                        if(next_step.s_action.s_action_type == wxT("G")&& next_step.s_action.b_is_assigned)
                        {
                            str_group = next_step.s_action.s_group_id;
                            if(!str_group.IsEmpty()&&!str_group.Contains(wxT(";")))
                            {
                                str_operator = wxGetApp().get_leader(str_group);
                            }
                            //{后期添加group为空的代码。
                        }

                    }


                    if(wf_active->Pass_proc(str_operator, str_group, str_desc, b_log_pass))
                    {
                        if(i_flow_ser>=2 && i_flow_ser<4)
                        {
                            if(check_contract_br_log(str_instance, s_cid))
                                wxGetApp().contractbook_lender_change(s_cid, str_operator);
                        }

                        if(!b_closed)
                            wf_active->update_instance(i_status, 1);
                        else
                            wf_active->update_instance(5,0);
                    }


                    l_proc_act = 0;

                    if(wf_active)
                        delete wf_active;
                }else if(str_workflow_id == wf_str_new_config)
                {
                    if(now_step.s_action.s_action_id==wxT("AT00000004"))
                    {
                        if(!close_finished_nonstd(str_instance, s_flag))
                        {
                            child_item = tlc_task_list->GetNextSibling(child_item);
                            continue;

                        }
                    }

                    if(b_goto)//b_goto控制是否需要移向下一步。
                    {
                        if(now_step.s_action.i_flow_ser<3)
                        {
                            str_group = now_step.s_action.s_group_id;
                        }
                        else
                            str_group = next_step.s_action.s_group_id;

                         if(now_step.s_action.i_flow_ser!=3)
                         {

                            s_role = next_step.s_action.s_role_id;

                            a_operator = wxGetApp().get_role_member(i_operator, s_role, str_group);

                            if(i_operator<=0)
                            {
                                if(wf_new_active)
                                    delete wf_new_active;
                                continue;
                            }else

                           if(i_operator==1)
                              str_operator = a_operator.Item(0).Left(8);

                            if(now_step.s_action.i_flow_ser==2)
                            {
                                str_operator = wxGetApp().get_leader(str_group);
                                i_operator = 1;
                            }

                            if(i_operator > 1&&b_first)
                            {
                                wxSingleChoiceDialog cdlg(this, _("请选择操作人员:"),_("操作选择"),a_operator);


                                if(cdlg.ShowModal() == wxID_OK)
                                {
                                    //                   b_first = false;
                                }
                                else
                                {
                                    if(wf_new_active)
                                          delete wf_new_active;

                                    return;
                                    //                 b_first = true;
                                }

                                b_first = false;

                                str_operator = cdlg.GetStringSelection().Left(8);
                                b_active = true;
                                if(now_step.s_action.i_flow_ser>=4)
                                {
                                     s_flag = tlc_task_list->GetItemText(child_item, 18);
                                }

                            }


                         }else
                         {
                            s_role = next_step.s_action.s_role_id;

                            a_operator = wxGetApp().get_role_member(i_operator, s_role, str_group);

                            str_operator = a_operator.Item(0).Left(8);
                            b_active = check_other_way(str_instance, s_flag);


                            a_flag = get_other_way(s_lift_type, s_flag);

                            int i_flag = a_flag.GetCount();

                            for(int k=0; k<i_flag; k++)
                            {
                                s_flag = s_flag+wxT("+")+a_flag.Item(k);

                            }



                         }

                    }

                    wf_new_active->Pass_proc(str_operator, str_group, str_desc, b_log_pass,s_flag, b_active);
                    l_proc_act = 0;
                    if(wf_new_active)
                        delete wf_new_active;

                }

                mils_used = wxGetLocalTimeMillis() - start_mils;

                wxLogMessage(str_instance+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒"));

                // tlc_task_list->Delete(child_item);
                del_item = child_item;
                child_item = tlc_task_list->GetNextSibling(child_item);
//               child_item = tlc_task_list->GetNextChild(sel_item,cookie);
                tlc_task_list->Delete(del_item);
                m_rows--;
            }

            if(!tlc_task_list->HasChildren(sel_item))
                tlc_task_list->Delete(sel_item);
        }
        else if(sel_item.IsOk())
        {
            a_operator.Clear();
            a_flag.Clear();

            start_mils = wxGetLocalTimeMillis();

            str_instance = tlc_task_list->GetItemText(sel_item,1);
            i_status = prj_str_to_status(tlc_task_list->GetItemText(sel_item, 7));
            s_flag = tlc_task_list->GetItemText(sel_item, 18);
            s_lift_type = tlc_task_list->GetItemText(sel_item, 4).Left(9);
            i_flow_ser = StrToInt(tlc_task_list->GetItemText(sel_item, 17));
            if(i_status == 4)
            {
                wxLogMessage(_("项目")+str_instance +_("已经暂停! 无法继续!"));
                continue;
            }
            else if(i_status== 5)
            {
                wxLogMessage(_("项目")+str_instance +_("已经关闭! 无法继续!"));
                continue;
            }

            if(str_workflow_id != tlc_task_list->GetItemText(sel_item, 12))//nonstd_level already done.
            {
                str_workflow_id = tlc_task_list->GetItemText(sel_item, 12);//nonstd_level already done.
                if(t_template)
                    delete [] t_template;
                t_template = get_template_action(str_workflow_id);
            }

            if(str_workflow_id == wf_str_configure)
            {
                wf_active = new wf_operator(str_instance, str_workflow_id, t_template);
                l_proc_act = wf_active->get_current_process();
            }
            else if(str_workflow_id == wf_str_new_config)
            {
                if(s_flag.Contains(wxT("+")))
                    s_flag_ex=wxT("E");
                else
                    s_flag_ex=s_flag;
                wf_new_active = new wf_operator_ex(str_instance, str_workflow_id, t_template, s_flag_ex);
                l_proc_act = wf_new_active->get_current_process();
            }

            //for evaluate
            if(s_index != tlc_task_list->GetItemText(sel_item, 2))
            {
                s_index = tlc_task_list->GetItemText(sel_item, 2);
                if(!make_evaluate(l_proc_act, s_index))
                {
                    if(wf_active)
                       delete wf_active;
                    if(wf_new_active)
                        delete wf_new_active;
                    l_proc_act = 0;
                    return;
                }
            }
            //for evaluate

            l_proc_act->MoveToActive();
            now_step = l_proc_act->get_cur_instance_action();

            if(now_step.s_action.s_operator_id!=gr_para.login_user)
                continue;

            if (!now_step.is_active)
                continue;

            if(l_proc_act->GetCurrentStep() == l_proc_act->GetTotalSteps()&&l_proc_act->GetTotalSteps()!= now_step.s_action.i_total_flow)
            {
                next_step.s_action = t_template[now_step.s_action.i_flow_ser];
                next_step.s_instance_id = str_instance;
            }
            else if(l_proc_act->GetCurrentStep() != l_proc_act->GetTotalSteps())
            {
                next_step = l_proc_act->get_next_instance_action();

                if(next_step.s_action.i_flow_ser != now_step.s_action.i_flow_ser+1)
                {
                    next_step.s_action = t_template[now_step.s_action.i_flow_ser];
                    next_step.s_instance_id = str_instance;
                }
            }

            if(now_step.s_action.i_flow_ser == now_step.s_action.i_total_flow)
            {
                b_closed = true;
                b_goto = false;
            }
            else
            {b_goto = true;
               b_closed = false;
            }

/*
            if(now_step.s_action.s_action_type == wxT("G")&& now_step.s_action.b_is_assigned)
            {

                str_group = now_step.s_action.s_group_id;
                wxArrayString  s_members = wxGetApp().get_member_in_group(str_group);

                if(b_first)
                {
                    wxSingleChoiceDialog cdlg(this, _("请选择操作人员:"),_("操作选择"),s_members);

                    if(cdlg.ShowModal() == wxID_OK)
                    {
                        str_operator = cdlg.GetStringSelection();
                    }
                    else
                    {
                        wxLogMessage(_("未选择操作人员，操作退出!"));
                        return;
                    }

                    b_first = false;

                    int i_pos = str_operator.Find('-');

                    str_operator = str_operator.Left(i_pos);

                }

                b_goto = false;
            }*/

            if(str_workflow_id==wf_str_configure)
            {
                if(b_goto)//b_goto控制是否需要移向下一步。
                {

                    if(next_step.s_action.s_action_type == wxT("G") && !next_step.s_action.b_is_assigned)
                    {
                        str_group = now_step.s_action.s_group_id;
                        str_operator = wxGetApp().get_leader(str_group);
                        b_first = true;
                    }

                    if(next_step.s_action.s_action_type == wxT("P") && !next_step.s_action.b_is_assigned)
                    {
                        str_group = next_step.s_action.s_group_id;
                        str_operator = next_step.s_action.s_operator_id;

                        b_first = true;
                    }

                    if(next_step.s_action.s_action_type == wxT("P")&& next_step.s_action.b_is_assigned)
                    {
                        if(b_first)//b_first控制操作人第一次循环设定。
                        {
                            str_group = next_step.s_action.s_group_id;
                            if(str_group.IsEmpty())
                                str_group = now_step.s_action.s_group_id;

                            wxArrayString str_group_list;
                            if(str_group.Contains(wxT(";")))
                            {
                                str_group_list = wxStringTokenize(str_group,wxT(";"), wxTOKEN_DEFAULT );
                            }
                            else
                                str_group_list.Add(str_group);

                            wxArrayString  s_members = wxGetApp().get_member_in_group(str_group_list, true);

                            wxSingleChoiceDialog cdlg(this, _("请选择操作人员:"),_("操作选择"),s_members);


                            if(cdlg.ShowModal() == wxID_OK)
                            {
                                //                   b_first = false;
                            }
                            else
                            {
                                return;
                                //                 b_first = true;
                            }

                            b_first  = false;

                            str_operator = cdlg.GetStringSelection().Left(8);


//                           int i_pos = str_operator.Find('-');

                            //                          str_operator.Left(i_pos);

                        }
                    }

                    if(next_step.s_action.s_action_type == wxT("G")&& next_step.s_action.b_is_assigned)
                    {
                        str_group = next_step.s_action.s_group_id;
                        if(!str_group.IsEmpty()&&!str_group.Contains(wxT(";")))
                        {
                            str_operator = wxGetApp().get_leader(str_group);
                        }
                        //{后期添加group为空的代码。
                    }

                }


                if(wf_active->Pass_proc(str_operator, str_group, str_desc, b_log_pass))
                {
                    if(i_flow_ser>=2 && i_flow_ser<4)
                    {
                        if(check_contract_br_log(str_instance, s_cid))
                            wxGetApp().contractbook_lender_change(s_cid, str_operator);
                    }

                    if(!b_closed)
                        wf_active->update_instance(i_status, 1);
                    else
                        wf_active->update_instance(5,0);

                }


                l_proc_act = 0;

                if(wf_active)
                    delete wf_active;
            }
            else if(str_workflow_id == wf_str_new_config)
            {
                if(now_step.s_action.s_action_id==wxT("AT00000004"))
                {
                    if(!close_finished_nonstd(str_instance, s_flag))
                    {
                        continue;

                    }
                }


                if(b_goto)//b_goto控制是否需要移向下一步。
                {

                        if(now_step.s_action.i_flow_ser<3)
                        {
                            str_group = now_step.s_action.s_group_id;
                        }
                        else
                            str_group = next_step.s_action.s_group_id;

                    if(now_step.s_action.i_flow_ser!=3)
                    {
                        s_role = next_step.s_action.s_role_id;

                        a_operator = wxGetApp().get_role_member(i_operator, s_role, str_group);

                        if(i_operator<=0)
                        {
                            if(wf_new_active)
                                delete wf_new_active;
                            continue;
                        }

                        if(i_operator==1)
                              str_operator = a_operator.Item(0);

                        if(now_step.s_action.i_flow_ser==2)
                        {
                            str_operator = wxGetApp().get_leader(str_group);
                            i_operator = 1;
                        }


                        if(i_operator > 1&&b_first)
                        {
                            wxSingleChoiceDialog cdlg(this, _("请选择操作人员:"),_("操作选择"),a_operator);


                            if(cdlg.ShowModal() == wxID_OK)
                            {
                                //                   b_first = false;
                            }
                            else
                            {
                                if(wf_new_active)
                                    delete wf_new_active;

                                return;
                                //                 b_first = true;
                            }

                            b_first = false;

                            str_operator = cdlg.GetStringSelection().Left(8);
                            b_active = true;
                            if(now_step.s_action.i_flow_ser>=4)
                            {
                                s_flag = tlc_task_list->GetItemText(sel_item, 18);
                            }

                        }
                    }
                    else
                    {
                        s_role = next_step.s_action.s_role_id;

                        a_operator = wxGetApp().get_role_member(i_operator, s_role, str_group);

                        str_operator = a_operator.Item(0).Left(8);

                        b_active = check_other_way(str_instance, s_flag);
                        a_flag = get_other_way(s_lift_type, s_flag);

                        int i_flag = a_flag.GetCount();

                        for(int k=0; k<i_flag; k++)
                        {
                            s_flag = s_flag+wxT("+")+a_flag.Item(k);
                        }


                    }

                }

                wf_new_active->Pass_proc(str_operator, str_group, str_desc, b_log_pass,s_flag, b_active);
                l_proc_act = 0;
                if(wf_new_active)
                    delete wf_new_active;

            }

            mils_used = wxGetLocalTimeMillis() - start_mils;

            wxLogMessage(str_instance+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒"));

            wxTreeItemId parent_item = tlc_task_list->GetItemParent(sel_item);
            tlc_task_list->Delete(sel_item);

            if(tlc_task_list->GetChildrenCount(parent_item)== 0)
                tlc_task_list->Delete(parent_item);

            m_rows--;
        }
    }

    refresh_group(b_show);
}

bool workflow_wf::make_evaluate(wf_process * s_process, wxString s_batch_id)
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

void workflow_wf::OnButton1Click(wxCommandEvent& event)
{
    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_task_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_task_list->GetSelections( items );
    wxTreeItemId del_item;

    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(items.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }

    wxString aim_step;
    v_wf_action * t_template=0;
    wf_operator * wf_active;
    wf_operator_ex *wf_new_active;
    wxString str_desc;

    wxTextEntryDialog tdlg(this,_("退回提示输入:"),_("确认退回？"),wxT(""),wxOK | wxCANCEL | wxTE_MULTILINE,wxDefaultPosition );

    if(tdlg.ShowModal()== wxID_OK)
    {
        str_desc= tdlg.GetValue();
    }
    else return;

    wxLongLong mils_used, start_mils;
    wxString str_instance, str_workflow_id, str_flow_ser;
    wxArrayString array_steps;
    int i_status;
    wxString s_flag,s_flag1,s_flag2,str,s_nstd_id;

    bool b_sel;
    bool b_elect;
    bool b_mach;

    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item)==root)
        {
            b_sel = false;
            b_elect = false;
            b_mach = false;
            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_task_list->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {

                str_instance = tlc_task_list->GetItemText(child_item, 1);
                str_workflow_id = tlc_task_list->GetItemText(child_item, 12);//nonstd_level already done.
                str_flow_ser = tlc_task_list->GetItemText(child_item, 17);//nonstd_level already done.
                i_status = prj_str_to_status(tlc_task_list->GetItemText(child_item, 7));
                s_flag = tlc_task_list->GetItemText(child_item, 18);
                if(!b_sel)
                {
                    if(str_workflow_id == wf_str_configure)
                         array_steps = get_steps_info(str_instance, str_workflow_id, str_flow_ser);

                    if(str_workflow_id == wf_str_new_config)
                        array_steps = get_steps_info(str_instance, str_workflow_id, str_flow_ser, "E");

                    if(array_steps.IsEmpty())
                    {
                        wxLogMessage(_("初始步骤无法退回!"));
                        return;
                    }
                    wxSingleChoiceDialog cdlg(this, _("请选择退回到哪一步"),_("退回选择1"),array_steps);

                    int i_sel;

                    if(cdlg.ShowModal() == wxID_OK)
                    {
                        i_sel = cdlg.GetSelection();
                        aim_step = m_steps.Item(i_sel).Left(10);
                    }
                    else return;

                    if(str_workflow_id == wf_str_new_config && i_sel<3)
                    {
                        array_steps.Clear();

                        str=_("机械");
                        array_steps.Add(str);
                        str=_("电气");
                        array_steps.Add(str);
                        str=_("电气和机械");
                        array_steps.Add(str);
                        wxSingleChoiceDialog cdlg(this, _("请选择退回给那个组"),_("退回选择2"),array_steps);
                        if(cdlg.ShowModal() == wxID_OK)
                        {
                            i_sel = cdlg.GetSelection();
                            if(i_sel==0)
                            {
                                b_mach = true;
                                b_elect=false;
                                }
                            else if(i_sel==1)
                            {
                                b_elect = true;
                                b_mach=false;
                            }
                            else if(i_sel==2)
                            {
                                b_mach=true;
                                b_elect = true;
                            }
                        }
                        else return;
                    }

                    b_sel = true;
                }
                start_mils = wxGetLocalTimeMillis();


                if(str_workflow_id != tlc_task_list->GetItemText(child_item, 12))//nonstd_level already done.
                {
                    str_workflow_id = tlc_task_list->GetItemText(child_item, 12);//nonstd_level already done.
                    if(t_template)
                        delete [] t_template;
                    t_template = get_template_action(str_workflow_id);
                }

                str_instance = tlc_task_list->GetItemText(child_item, 1);
                if(str_workflow_id == wf_str_configure)
                {

                    wf_active = new wf_operator(str_instance, str_workflow_id, t_template);
                    wf_active->Feed_back(str_desc, aim_step);

                    wf_active->update_instance(i_status, 1);
                    delete wf_active;
                }

                if(str_workflow_id == wf_str_new_config)
                {
                    if(s_flag.Contains("+"))
                    {
                        s_flag1=wxT("E");
                        int i_pos = s_flag.Find(s_flag1);

                        if(i_pos==0)
                            s_flag2 = s_flag.Right(1);
                        else if(i_pos==s_flag.Length()-1)
                            s_flag2 = s_flag1.Left(1);
                    }else
                        s_flag1=s_flag2=s_flag;

                    if(b_mach)
                    {

                        wf_new_active = new wf_operator_ex(str_instance,str_workflow_id, t_template, s_flag2);

                        if(wf_new_active->Feed_back(str_desc, aim_step)&& aim_step==wxT("AT00000004"))
                        {
                            s_nstd_id =  wxGetApp().get_nstd_from_unit(str_instance, s_flag2);
                            wxGetApp().update_new_nstd_config(s_nstd_id, 3);
                        }

                        wf_new_active->update_instance(i_status, 1);
                        delete wf_new_active;

                    }

                    if(b_elect)
                    {
                        wf_new_active = new wf_operator_ex(str_instance,str_workflow_id, t_template, s_flag1);

                        if(wf_new_active->Feed_back(str_desc, aim_step)&& aim_step==wxT("AT00000004"))
                        {
                            s_nstd_id =  wxGetApp().get_nstd_from_unit(str_instance, s_flag1);
                            wxGetApp().update_new_nstd_config(s_nstd_id, 3);
                        }

                        wf_new_active->update_instance(i_status, 1);
                        delete wf_new_active;
                    }
                    if(!b_mach && !b_elect)
                    {
                        wf_new_active = new wf_operator_ex(str_instance,str_workflow_id, t_template, s_flag1);

                        if(wf_new_active->Feed_back(str_desc, aim_step)&& aim_step==wxT("AT00000004"))
                        {
                            s_nstd_id =  wxGetApp().get_nstd_from_unit(str_instance, s_flag1);
                            wxGetApp().update_new_nstd_config(s_nstd_id, 3);
                        }

                        wf_new_active->update_instance(i_status, 1);
                        delete wf_new_active;
                    }
                }



                mils_used = wxGetLocalTimeMillis() - start_mils;

                wxLogMessage(str_instance+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒"));

                // tlc_task_list->Delete(child_item);
                del_item = child_item;
                child_item = tlc_task_list->GetNextSibling(child_item);
//               child_item = tlc_task_list->GetNextChild(sel_item,cookie);
                tlc_task_list->Delete(del_item);

                m_rows--;
            }

            if(!tlc_task_list->HasChildren(sel_item))
                tlc_task_list->Delete(sel_item);

            b_sel = false;
        }
        else if(sel_item.IsOk())
        {
            if(str_instance.Left(10) != tlc_task_list->GetItemText(sel_item, 1).Left(10))
                b_sel = false;

            str_instance = tlc_task_list->GetItemText(sel_item, 1);
            str_workflow_id = tlc_task_list->GetItemText(sel_item, 12);//nonstd_level already done.
            str_flow_ser = tlc_task_list->GetItemText(sel_item, 17);//nonstd_level already done.
            i_status = prj_str_to_status(tlc_task_list->GetItemText(sel_item, 7));
            s_flag = tlc_task_list->GetItemText(sel_item, 18);
            if(!b_sel)
            {
                if(str_workflow_id == wf_str_configure)
                    array_steps = get_steps_info(str_instance, str_workflow_id, str_flow_ser);

                if(str_workflow_id == wf_str_new_config)
                    array_steps = get_steps_info(str_instance, str_workflow_id, str_flow_ser, "E");

                if(array_steps.IsEmpty())
                {
                    wxLogMessage(_("初始步骤无法退回!"));
                    return;
                }

                wxSingleChoiceDialog cdlg(this, _("请选择退回到哪一步"),_("退回选择"),array_steps);
                 int i_sel;

                if(cdlg.ShowModal() == wxID_OK)
                {
                    i_sel = cdlg.GetSelection();
                    aim_step = m_steps.Item(i_sel).Left(10);
                }
                else return;

                if(str_workflow_id == wf_str_new_config && i_sel<3)
                {
                    array_steps.Clear();

                    str=_("机械");
                    array_steps.Add(str);
                    str=_("电气");
                    array_steps.Add(str);
                    str=_("电气和机械");
                    array_steps.Add(str);
                    wxSingleChoiceDialog cdlg(this, _("请选择退回给那个组"),_("退回选择2"),array_steps);
                    if(cdlg.ShowModal() == wxID_OK)
                    {
                        i_sel = cdlg.GetSelection();
                        if(i_sel==0)
                            b_mach = true;
                        else if(i_sel==1)
                            b_elect = true;
                        else if(i_sel==2)
                        {
                            b_mach=true;
                            b_elect = true;
                        }
                    }
                    else return;
                }

                b_sel = true;
            }


            start_mils = wxGetLocalTimeMillis();


            if(str_workflow_id != tlc_task_list->GetItemText(sel_item, 12))//nonstd_level already done.
            {
                str_workflow_id = tlc_task_list->GetItemText(sel_item, 12);//nonstd_level already done.
                if(t_template)
                    delete [] t_template;
                t_template = get_template_action(str_workflow_id);
            }

            str_instance = tlc_task_list->GetItemText(sel_item, 1);
            if(str_workflow_id == wf_str_configure)
            {

                wf_active = new wf_operator(str_instance, str_workflow_id, t_template);
                wf_active->Feed_back(str_desc, aim_step);

                wf_active->update_instance(i_status, 1);
                delete wf_active;
            }

            if(str_workflow_id == wf_str_new_config)
            {
                if(s_flag.Contains("+"))
                {
                    s_flag1=wxT("E");
                    int i_pos = s_flag.Find(s_flag1);

                    if(i_pos==0)
                        s_flag2 = s_flag.Right(1);
                    else if(i_pos==s_flag.Length()-1)
                        s_flag2 = s_flag1.Left(1);
                }else
                     s_flag1=s_flag2=s_flag;

                if(b_mach)
                {

                    wf_new_active = new wf_operator_ex(str_instance,str_workflow_id, t_template, s_flag2);
                    if(wf_new_active->Feed_back(str_desc, aim_step)&& aim_step==wxT("AT00000004"))
                    {
                        s_nstd_id =  wxGetApp().get_nstd_from_unit(str_instance, s_flag2);
                        wxGetApp().update_new_nstd_config(s_nstd_id, 3);
                    }

                    wf_new_active->update_instance(i_status, 1);
                    delete wf_new_active;

                }

                if(b_elect)
                {
                    wf_new_active = new wf_operator_ex(str_instance,str_workflow_id, t_template, s_flag1);
                    if(wf_new_active->Feed_back(str_desc, aim_step)&& aim_step==wxT("AT00000004"))
                    {
                        s_nstd_id =  wxGetApp().get_nstd_from_unit(str_instance, s_flag1);
                        wxGetApp().update_new_nstd_config(s_nstd_id, 3);
                    }

                    wf_new_active->update_instance(i_status, 1);
                    delete wf_new_active;
                }

                if(!b_mach && !b_elect)
                {
                    wf_new_active = new wf_operator_ex(str_instance, str_workflow_id, t_template, s_flag1);
                    if(wf_new_active->Feed_back(str_desc, aim_step)&& aim_step==wxT("AT00000004"))
                    {
                        s_nstd_id =  wxGetApp().get_nstd_from_unit(str_instance, s_flag1);
                        wxGetApp().update_new_nstd_config(s_nstd_id, 3);
                    }

                    wf_new_active->update_instance(i_status, 1);
                    delete wf_new_active;
                }
            }


            mils_used = wxGetLocalTimeMillis() - start_mils;

            wxLogMessage(str_instance+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒"));

            wxTreeItemId parent_item = tlc_task_list->GetItemParent(sel_item);
            tlc_task_list->Delete(sel_item);

            if(tlc_task_list->GetChildrenCount(parent_item)== 0)
                tlc_task_list->Delete(parent_item);

            m_rows--;

        }
    }

    refresh_group(b_show);
}

wxArrayString workflow_wf::get_steps_info(wxString &s_instance_id, wxString &s_workflow_id, wxString &s_now, wxString _flag)
{
    wxString strSql;

    if(_flag.IsEmpty())
        strSql= wxT("select concat(action_id,'-',operator_id) as action_id, concat(action_name,'-', name) as step_info from v_task_list1 where workflow_id = '")+
                   s_workflow_id+wxT("' and instance_id = '")+ s_instance_id+wxT("' and flow_ser < ")+ s_now+wxT(" order by flow_ser ASC;");
    else
        strSql= wxT("select action_id, action_name as step_info from v_task_list1 where workflow_id = '")+
                   s_workflow_id+wxT("' and instance_id = '")+ s_instance_id+wxT("' and flow_ser < ")+ s_now+wxT(" and flag like '%")+_flag+wxT("%' order by flow_ser ASC;");

//    wxLogMessage(strSql);
    wxPostgreSQLresult* _res =  wxGetApp().app_sql_select(strSql);

    wxArrayString array_result;
    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return array_result;
    }

    int i_count = _res->GetRowsNumber();
    m_steps.Clear();

    wxString str;

    _res->MoveFirst();
    for(int i=0;i<i_count;i++)
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

void workflow_wf::refresh_task_level()
{
    int i_count_freeze;
    int i_count_urgent;
    int i_count_pre;
    int i_count_lean;
    int i_count;

    wxString str_nonstd_level;

    wxTreeItemId root = tlc_task_list->GetRootItem();

    wxTreeItemIdValue cookie;
    wxTreeItemId item = tlc_task_list->GetFirstChild(root,cookie);
    wxString str_group, str_date, str_type, str_project_catalog,str, s_special_info;
    wxArrayString a_group;

    while(item.IsOk())
    {
        s_special_info=wxEmptyString;
        wxTreeItemIdValue cookie_child;
        wxTreeItemId child_item = tlc_task_list->GetFirstChild(item,cookie_child);
        str_group.Empty();
        i_count_freeze = 0;
        i_count_urgent = 0;
        i_count_pre = 0;
        i_count_lean = 0;
        str_date.Empty();
        str_type.Empty();

        wxDateTime dt_temp;

        str_date = wxT("2200-12-31");
        dt_temp = StrToDate(str_date);

        a_group.Clear();


        while(child_item.IsOk())
        {

            str_project_catalog=  tlc_task_list->GetItemText(child_item,16);//nonstd_level already done.
            int i_project_catalog = wxAtoi(str_project_catalog);
            str = tlc_task_list->GetItemText(child_item, 9);
            if(!str_nonstd_level.Contains(str))
            {
                if(str_nonstd_level.IsEmpty())
                    str_nonstd_level=str;
                else
                    str_nonstd_level = str_nonstd_level+wxT("+")+str;
            }

            str_group = tlc_task_list->GetItemText(child_item,3);
            a_group.Add(str_group);

            str_date = tlc_task_list->GetItemText(child_item, 5);
            if(dt_temp.IsLaterThan(StrToDate(str_date))&& !str_date.IsEmpty())
            {
                dt_temp = StrToDate(str_date);
            }

            str_type = tlc_task_list->GetItemText(child_item, 4);
            int i_pos = str_type.Find("-");
            str_type = str_type.Right(str_type.Length()-i_pos-1);

            if(prj_str_to_status(tlc_task_list->GetItemText(child_item,7))== 4)
            {
                tlc_task_list->SetItemBackgroundColour(child_item, *wxRED);
                i_count_freeze++;
            }else if(i_project_catalog == 6)
            {
                tlc_task_list->SetItemBackgroundColour(child_item,  *wxYELLOW);
                i_count_lean++;
            }else if(i_project_catalog == 5)
            {
                tlc_task_list->SetItemBackgroundColour(child_item,  *wxCYAN);
                i_count_pre++;
            }
            else if(tlc_task_list->GetItemText(child_item,14)==wxT("Y"))//nonstd_level already done.
            {
                tlc_task_list->SetItemBackgroundColour(child_item, *wxGREEN);
                i_count_urgent++;
            }else tlc_task_list->SetItemBackgroundColour(child_item, *wxWHITE);

            if(!s_special_info.Contains(tlc_task_list->GetItemText(child_item, 10)))
            {
                if(s_special_info.IsEmpty())
                {
                    s_special_info = tlc_task_list->GetItemText(child_item, 10);
                }else
                {
                    s_special_info = s_special_info+wxT("+")+tlc_task_list->GetItemText(child_item, 10);
                }
            }



            child_item = tlc_task_list->GetNextSibling(child_item);

        }

        tlc_task_list->SetItemText(item, 9, str_nonstd_level);
        str_nonstd_level.Clear();

        str_date = DateToStrFormat(dt_temp);

        i_count = tlc_task_list->GetChildrenCount(item);
        if(i_count_freeze == i_count)
            tlc_task_list->SetItemBackgroundColour(item, *wxRED);
        else if(i_count_freeze !=0)
            tlc_task_list->SetItemImage(item,0, 0);
        else if(i_count_lean == i_count )
               tlc_task_list->SetItemBackgroundColour(item, *wxYELLOW);
        else if(i_count_lean !=0)
              tlc_task_list->SetItemImage(item,0,4);
        else if(i_count_pre == i_count )
               tlc_task_list->SetItemBackgroundColour(item, *wxCYAN);
        else if(i_count_lean !=0)
              tlc_task_list->SetItemImage(item,0,3);
        else if(i_count_urgent == i_count)
            tlc_task_list->SetItemBackgroundColour(item, *wxGREEN);
        else if(i_count_urgent !=0)
            tlc_task_list->SetItemImage(item,0,2);
        else
        {
            tlc_task_list->SetItemBackgroundColour(item, *wxWHITE);
            tlc_task_list->SetItemImage(item,0,-1);
        }

        str_group = Combine_lift_no(a_group);

        tlc_task_list->SetItemText(item, 3, str_group);
        tlc_task_list->SetItemText(item, 4, str_type+wxT("*")+NumToStr(i_count)+_("台"));
        tlc_task_list->SetItemText(item, 5, str_date);
         tlc_task_list->SetItemText(item, 10, s_special_info);

        item = tlc_task_list->GetNextSibling(item);
    }

}

void workflow_wf::refresh_group_level(bool b_sure)
{
    if(!b_sure)
        return;

        int i_count_freeze;
    int i_count_urgent;
    int i_count_pre;
    int i_count_lean;
    int i_count;

    wxTreeItemId root = tlc_group_task_list->GetRootItem();

    wxString str_nonstd_level;
    wxTreeItemIdValue cookie;
    wxTreeItemId item = tlc_group_task_list->GetFirstChild(root,cookie);
    wxString str_group, str_date, str_operator, str_type, str_project_catalog,str,s_special_info;
    wxArrayString a_group;

    while(item.IsOk())
    {
        s_special_info=wxEmptyString;
        wxTreeItemIdValue cookie_child;
        wxTreeItemId child_item = tlc_group_task_list->GetFirstChild(item,cookie_child);
        str_group.Empty();
        i_count_freeze = 0;
        i_count_urgent = 0;
        i_count_pre = 0;
        i_count_lean = 0;
        a_group.Clear();

        while(child_item.IsOk())
        {

            str_project_catalog=  tlc_group_task_list->GetItemText(child_item,16);//nonstd_level already done.
            int i_project_catalog = wxAtoi(str_project_catalog);

            str=tlc_group_task_list->GetItemText(child_item, 10);

            if(!str_nonstd_level.Contains(str))
            {
                if(str_nonstd_level.IsEmpty())
                    str_nonstd_level=str;
                else
                    str_nonstd_level=str_nonstd_level+wxT("+")+str;
            }

            str_group = tlc_group_task_list->GetItemText(child_item,4);
            a_group.Add(str_group);

            str_date = tlc_group_task_list->GetItemText(child_item, 6);
            str_operator = tlc_group_task_list->GetItemText(child_item, 3);
            str_type = tlc_group_task_list->GetItemText(child_item, 5);
            int i_pos = str_type.Find("-");
            str_type = str_type.Right(str_type.Length()-i_pos-1);


            if(prj_str_to_status(tlc_group_task_list->GetItemText(child_item,8))== 4)
            {
                tlc_group_task_list->SetItemBackgroundColour(child_item, *wxRED);
                i_count_freeze++;
            }else if(i_project_catalog == 6)
            {
                tlc_group_task_list->SetItemBackgroundColour(child_item,  *wxYELLOW);
                i_count_lean++;
            }else if(i_project_catalog == 5)
            {
                tlc_group_task_list->SetItemBackgroundColour(child_item,  *wxCYAN);
                i_count_pre++;
            }
            else if(tlc_group_task_list->GetItemText(child_item,14)==wxT("Y"))//nonstd_level already done.
            {
                tlc_group_task_list->SetItemBackgroundColour(child_item, *wxGREEN);
                i_count_urgent++;
            }else tlc_group_task_list->SetItemBackgroundColour(child_item, *wxWHITE);

            if(!s_special_info.Contains(tlc_group_task_list->GetItemText(child_item, 11)))
            {
                if(s_special_info.IsEmpty())
                {
                    s_special_info = tlc_group_task_list->GetItemText(child_item, 11);
                }else
                {
                    s_special_info = s_special_info+wxT("+")+tlc_group_task_list->GetItemText(child_item, 11);
                }
            }

            child_item = tlc_group_task_list->GetNextSibling(child_item);

        }

        tlc_group_task_list->SetItemText(item, 10, str_nonstd_level);
        str_nonstd_level.Clear();

        i_count = tlc_group_task_list->GetChildrenCount(item);
        if(i_count_freeze == i_count)
            tlc_group_task_list->SetItemBackgroundColour(item, *wxRED);
        else if(i_count_freeze !=0)
            tlc_group_task_list->SetItemImage(item,0, 0);
        else if(i_count_lean == i_count )
               tlc_group_task_list->SetItemBackgroundColour(item, *wxYELLOW);
        else if(i_count_lean !=0)
              tlc_group_task_list->SetItemImage(item,0,4);
        else if(i_count_pre == i_count )
               tlc_group_task_list->SetItemBackgroundColour(item, *wxCYAN);
        else if(i_count_lean !=0)
              tlc_group_task_list->SetItemImage(item,0,3);
        else if(i_count_urgent == i_count)
            tlc_group_task_list->SetItemBackgroundColour(item, *wxGREEN);
        else if(i_count_urgent !=0)
            tlc_group_task_list->SetItemImage(item,0,2);
        else
        {
            tlc_group_task_list->SetItemBackgroundColour(item, *wxWHITE);
            tlc_group_task_list->SetItemImage(item,0,-1);
        }

        str_group = Combine_lift_no(a_group);

        tlc_group_task_list->SetItemText(item, 4, str_group);
        tlc_group_task_list->SetItemText(item, 6, str_date);
        tlc_group_task_list->SetItemText(item, 5, str_type+wxT("*")+NumToStr(i_count)+_("台"));
        tlc_group_task_list->SetItemText(item, 3, str_operator);
        tlc_group_task_list->SetItemText(item, 11, s_special_info);

        item = tlc_group_task_list->GetNextSibling(item);
    }

}
/*
wxString workflow_wf::feed_back_workflow(wxTreeItemId &ti_item, wxString &aim_step, wxString &s_desc)
{
    wxString str_workflow_id, str_instance;
    v_wf_action * t_template=0;
    wf_operator * wf_active;

    if(str_workflow_id != tlc_task_list->GetItemText(ti_item, 10))
    {
        str_workflow_id = tlc_task_list->GetItemText(ti_item, 10);
        if(t_template)
            delete [] t_template;
        t_template = get_template_action(str_workflow_id);
    }

    str_instance = tlc_task_list->GetItemText(ti_item, 1);
    wf_active = new wf_operator(str_instance, str_workflow_id, t_template);
    wf_active->Feed_back(s_desc, aim_step);

    wf_active->update_instance(1, 1);
    delete wf_active;

    return str_instance;

}*/

/*
wxString workflow_wf::pass_proc_workflow(wxTreeItemId &ti_item, bool &b_first, wxString )
{

    wxString str_workflow_id, str_instance, str_group, str_operator, str_temp;

    bool b_goto = true;
    wxString str_desc=wxEmptyString;
    bool b_log_pass = true;

    v_wf_action * t_template=0;

    wf_operator * wf_active=0;

    wf_process * l_proc_act =0;
    v_wf_instance now_step, next_step;

    str_instance = tlc_task_list->GetItemText(ti_item,1);
    int i_status = prj_str_to_status(tlc_task_list->GetItemText(ti_item, 7));
    if(i_status == 4)
    {
        wxLogMessage(_("项目")+str_instance +_("已经暂停! 无法继续!"));
        return wxEmptyString;
    }
    else if(i_status== 5)
    {
        wxLogMessage(_("项目")+str_instance +_("已经关闭! 无法继续!"));
        return wxEmptyString;
    }

    if(str_workflow_id != tlc_task_list->GetItemText(ti_item, 10))
    {
        str_workflow_id = tlc_task_list->GetItemText(ti_item, 10);
        if(t_template)
            delete [] t_template;
        t_template = get_template_action(str_workflow_id);
    }

    wf_active = new wf_operator(str_instance, str_workflow_id, t_template);
    l_proc_act = wf_active->get_current_process();
    l_proc_act->MoveToActive();
    now_step = l_proc_act->get_cur_instance_action();

    if(now_step.s_action.s_operator_id!=gr_para.login_user && now_step.is_active)
        return wxEmptyString;

    if(l_proc_act->GetCurrentStep() == l_proc_act->GetTotalSteps()&&l_proc_act->GetTotalSteps()!= now_step.s_action.i_total_flow)
    {
        next_step.s_action = t_template[now_step.s_action.i_flow_ser];
        next_step.s_instance_id = str_instance;
    }
    else if(l_proc_act->GetCurrentStep() != l_proc_act->GetTotalSteps())
    {
        next_step = l_proc_act->get_next_instance_action();
    }

    if(now_step.s_action.i_flow_ser == now_step.s_action.i_total_flow)
        b_goto = false;
    else b_goto = true;


    if(now_step.s_action.s_action_type == wxT("G")&& now_step.s_action.b_is_assigned)
    {

        str_group = now_step.s_action.s_group_id;
        wxArrayString  s_members = wxGetApp().get_member_in_group(str_group);

        if(b_first)
        {
            wxSingleChoiceDialog cdlg(this, _("请选择操作人员:"),_("操作选择"),s_members);

            if(cdlg.ShowModal() == wxID_OK)
            {
                str_operator = cdlg.GetStringSelection();
            }
            else
            {
                wxLogMessage(_("未选择操作人员，操作退出!"));
                return wxEmptyString;
            }

            b_first = false;

            int i_pos = str_operator.Find('-');

            str_operator = str_operator.Left(i_pos);

        }

        b_goto = false;
    }

    if(b_goto)//b_goto控制是否需要移向下一步。
    {

        if(next_step.s_action.s_action_type == wxT("G") && !next_step.s_action.b_is_assigned)
        {
            str_group = now_step.s_action.s_group_id;
            str_operator = wxGetApp().get_leader(str_group);
            b_first = true;
        }

        if(next_step.s_action.s_action_type == wxT("P") && !next_step.s_action.b_is_assigned)
        {
            str_group = next_step.s_action.s_group_id;
            str_operator = next_step.s_action.s_operator_id;

            b_first = true;
        }

        if(next_step.s_action.s_action_type == wxT("P")&& next_step.s_action.b_is_assigned)
        {
            if(b_first)//b_first控制操作人第一次循环设定。
            {
                str_group = next_step.s_action.s_group_id;
                if(str_group.IsEmpty())
                    str_group = now_step.s_action.s_group_id;

                wxArrayString str_group_list;
                if(str_group.Contains(wxT(";")))
                {
                    str_group_list = wxStringTokenize(str_group,wxT(";"), wxTOKEN_DEFAULT );
                }
                else
                    str_group_list.Add(str_group);

                wxArrayString  s_members = wxGetApp().get_member_in_group(str_group_list);

                wxSingleChoiceDialog cdlg(this, _("请选择操作人员:"),_("操作选择"),s_members);


                if(cdlg.ShowModal() == wxID_OK)
                {
                    //                   b_first = false;
                }
                else
                {
                    return wxEmptyString;
                    //                 b_first = true;
                }

                b_first  = false;

                str_operator = cdlg.GetStringSelection().Left(8);


                int i_pos = str_operator.Find('-');

                str_operator.Left(i_pos);

            }
        }

        if(next_step.s_action.s_action_type == wxT("G")&& next_step.s_action.b_is_assigned)
        {
            str_group = next_step.s_action.s_group_id;
            if(!str_group.IsEmpty())
            {
                str_operator = wxGetApp().get_leader(str_group);
            }
            //{后期添加group为空的代码。
        }
    }

    l_proc_act = 0;
    wf_active->Pass_proc(str_operator, str_group, str_desc, b_log_pass);

    wf_active->update_instance(1, 1);


    delete wf_active;

    return str_instance;
//       b_first = true;

}

*/
void workflow_wf::OnButton4Click(wxCommandEvent& event)
{

    refresh_list();
}

void workflow_wf::On_task_list_RightClick(wxTreeEvent& event)
{
    PopupMenu(&menu_workflow_popup, ScreenToClient(wxGetMousePosition()));
}

void workflow_wf::On_group_task_list_RightClick(wxTreeEvent& event)
{
    PopupMenu(&menu_worflow_group_popup, ScreenToClient(wxGetMousePosition()));
}

void workflow_wf::OnMenuItem1Selected(wxCommandEvent& event)//mikewolfli
{
    wxTreeItemId root = tlc_task_list->GetRootItem();
    wxString s_wbs,str_sql,str_desc;

    wxArrayTreeItemIds items;
    wxArrayTreeItemIds::iterator iter;
    tlc_task_list->GetSelections( items );

    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(items.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }

    wxTextEntryDialog tdlg(this,_("备注说明输入:"),_("备注"),wxT(""),wxOK | wxCANCEL | wxTE_MULTILINE,wxDefaultPosition );
    if(tdlg.ShowModal()== wxID_OK)
    {
        str_desc= tdlg.GetValue();
    }else return;

    if(str_desc.IsEmpty())
        return;

//   int i_count = items.GetCount();

    wxString str_id = wxGetApp().get_ser_no(wxT("s_doc"),wxT("doc_id"));
    wxGetApp().update_desc(str_id,str_desc,false);

    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item)==root)
        {
            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_task_list->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {
              s_wbs = tlc_task_list->GetItemText(child_item, 1);
              str_sql = wxT("UPDATE l_proc_act SET step_desc_id= '")+str_id+wxT("' WHERE instance_id='")+s_wbs+wxT("' AND \
              operator_id = '")+gr_para.login_user+wxT("' AND is_active = true;");
               if(wxGetApp().app_sql_update(str_sql))
                  tlc_task_list->SetItemText(child_item, 8, str_desc);

               child_item = tlc_task_list->GetNextSibling(child_item);



            }
        }else
        {

              s_wbs = tlc_task_list->GetItemText(sel_item, 1);
              str_sql = wxT("UPDATE l_proc_act SET step_desc_id= '")+str_id+wxT("' WHERE instance_id='")+s_wbs+wxT("' AND \
              operator_id = '")+gr_para.login_user+wxT("' AND is_active = true;");
               if(wxGetApp().app_sql_update(str_sql))
                  tlc_task_list->SetItemText(sel_item, 8, str_desc);


        }
    }

    refresh_group(b_show);
}

void workflow_wf::OnMenuItem2Selected(wxCommandEvent& event)
{

    wxTreeItemId root = tlc_task_list->GetRootItem();
    wxArrayTreeItemIds items;
    wxArrayTreeItemIds::iterator iter;
    tlc_task_list->GetSelections( items );

    wxArrayString array_return, array_return_time;

    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(items.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }

 //   int i_sel = items.GetCount();
    wxString str;
    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item)==root)
        {

            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_task_list->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {
                if(tlc_task_list->GetItemText(child_item,6)==wxT("Y"))
                {
                    str = tlc_task_list->GetItemText(child_item,1);
                    array_return.Add(str);

                    str = tlc_task_list->GetItemText(child_item, 15);//nonstd_level already done.
                    array_return_time.Add(str);
                }
                child_item = tlc_task_list->GetNextSibling(child_item);
            }
        }
        else{
                if(tlc_task_list->GetItemText(sel_item,6)==wxT("Y"))
                {
                    str = tlc_task_list->GetItemText(sel_item,1);
                    array_return.Add(str);

                    str = tlc_task_list->GetItemText(sel_item, 15);//nonstd_level already done.
                    array_return_time.Add(str);
                }

        }
    }
    items.Clear();

    if(array_return.IsEmpty())
    {
        wxLogMessage(_("无退回记录!"));
        return;
    }

    return_log return_log_dlg;

    return_log_dlg.Refresh_list_view(array_return,array_return_time);
    return_log_dlg.ShowModal();

}


void workflow_wf::OnMenuItem3Selected(wxCommandEvent& event)
{
    wxTreeItemId root = tlc_task_list->GetRootItem();
    wxArrayTreeItemIds items;
    wxArrayTreeItemIds::iterator iter;
    tlc_task_list->GetSelections( items );

    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(items.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }

    wxArrayString array_sel_wbs;
    wxString str_temp;
    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item)==root)
        {

            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_task_list->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {
                  str_temp = tlc_task_list->GetItemText(child_item,1).Upper().Trim();
                  array_sel_wbs.Add(str_temp);

                  child_item = tlc_task_list->GetNextSibling(child_item);
            }
        }else
        {
                str_temp = tlc_task_list->GetItemText(sel_item, 1).Upper().Trim();
                array_sel_wbs.Add(str_temp);
        }
    }

    ins_proc_log ipl_dlg;

    ipl_dlg.init_conf_list_header();

    ipl_dlg.Refresh_list_view(array_sel_wbs);
    ipl_dlg.ShowModal();
}

void workflow_wf::OnMenuItem4Selected(wxCommandEvent& event)
{
    wf_search dlg_search;
    wxArrayString array_result;
    ins_proc_log *ipl_dlg;
    if(dlg_search.ShowModal()== wxID_OK)
    {
            array_result= get_wbs_list(dlg_search.i_choice,dlg_search.str_search);

            if(array_result.IsEmpty())
            {
                wxLogMessage(_("请核查条件，无返回结果！"));
                return;
            }
            ipl_dlg = new ins_proc_log();

            ipl_dlg->init_conf_list_header();
            ipl_dlg->Refresh_list_view(array_result);
            if(ipl_dlg->ShowModal()==wxID_OK)
            {
                ipl_dlg->Destroy();
            }
    }
}

wxArrayString workflow_wf::get_wbs_list(int i_choice, wxString str_case)
{
    wxString str_query;

    switch(i_choice)
    {
    case 0:
        str_query = wxT("SELECT * from s_unit_info WHERE wbs_no ILIKE '%")+str_case+wxT("%' ORDER BY wbs_no ASC;");
        break;
    case 1:
        str_query = wxT("SELECT * from v_unit_info WHERE project_id ILIKE '%")+str_case+wxT("%' ORDER BY wbs_no ASC;");
        break;
    case 2:
        str_query = wxT("SELECT * from v_unit_info WHERE contract_id ILIKE '%")+str_case+wxT("%' ORDER BY wbs_no ASC;");
        break;
    case 3:
        str_query = wxT("SELECT * from v_unit_info WHERE project_name ILIKE '%")+str_case+wxT("%' ORDER BY wbs_no ASC;");
        break;
    default:
        break;
    }

    wxArrayString array_result;
    wxPostgreSQLresult *_res;
    if(str_query.IsEmpty())
       return array_result;

     _res = wxGetApp().app_sql_select(str_query);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        return array_result;
    }

    int i_count = _res->GetRowsNumber();
    _res->MoveFirst();
    for(int i=0;i<i_count; i++)
    {
 //       wxString str = _res->GetVal(wxT("wbs_no"));
        array_result.Add(_res->GetVal(wxT("wbs_no")));
        _res->MoveNext();

    }

    _res->Clear();

    return array_result;

}

void workflow_wf::OnKeyDown(wxTreeEvent& event)
{
    long key_code = event.GetKeyCode();
 //   wxKeyEvent levent = event.GetKeyEvent();

    switch(key_code)
    {
    case WXK_CONTROL_C:
              Copy();
        break;
    default:
        break;
    }

    event.Skip();
}

int workflow_wf::Copy()
{
	wxString str;
	int copied = 0;

    wxTreeItemId root = tlc_task_list->GetRootItem();
    wxArrayTreeItemIds items;
    wxArrayTreeItemIds::iterator iter;
    tlc_task_list->GetSelections( items );
    wxString s_wbsno, s_projec_name, s_step_desc, s_lift_type, s_lift_type_no, s_lift_no,s_req_finish, s_desc, s_project_no, s_status, s_special_info;

/*
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(items.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }*/
   int i_pos, i_len;
   for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item)==root)
        {
            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_task_list->GetFirstChild(sel_item,cookie);
            s_projec_name = tlc_task_list->GetItemText(sel_item, 1);
            i_pos = s_projec_name.Find("-");
            i_len = s_projec_name.Length();
            s_project_no = s_projec_name.Right(i_len-i_pos-1);
            s_projec_name = s_projec_name.Left(i_pos);
            while(child_item.IsOk())
            {
                  s_wbsno = tlc_task_list->GetItemText(child_item, 1);
                  s_lift_type_no = tlc_task_list->GetItemText(child_item, 4);
                  i_pos = s_lift_type_no.Find("-");
                  s_lift_type = s_lift_type_no.Right(s_lift_type_no.Length()-i_pos-1);
                  s_lift_type_no = s_lift_type_no.Left(9);

                  s_step_desc = tlc_task_list->GetItemText(child_item, 0);
                  s_lift_no = tlc_task_list->GetItemText(child_item, 3);
                  s_req_finish = tlc_task_list->GetItemText(child_item, 5);
                  s_special_info =tlc_task_list->GetItemText(child_item, 10);
                  s_desc = tlc_task_list->GetItemText(child_item, 11);//nonstd_level already done.
                  s_status = tlc_task_list->GetItemText(child_item, 7);

                  str = str + s_step_desc+wxT("\t")+s_project_no+wxT("\t")+s_wbsno+wxT("\t")+s_lift_type_no+wxT("\t")+s_lift_type+wxT("\t")+
                        s_projec_name+wxT("\t")+s_lift_no+wxT("\t")+s_req_finish+wxT("\t")+s_desc+wxT("\t")+s_status+END_OF_LINE;
                  copied++;

                  child_item = tlc_task_list->GetNextSibling(child_item);
            }
        }else
        {
                wxTreeItemId parent_id;
                parent_id = tlc_task_list->GetItemParent(sel_item);
                s_projec_name = tlc_task_list->GetItemText(parent_id, 1);
                i_pos = s_projec_name.Find("-");
                 i_len = s_projec_name.Length();
                 s_project_no = s_projec_name.Right(i_len-i_pos-1);
                 s_projec_name = s_projec_name.Left(i_pos);

                   s_wbsno = tlc_task_list->GetItemText(sel_item, 1);
                  s_lift_type_no = tlc_task_list->GetItemText(sel_item, 4);
                  i_pos = s_lift_type_no.Find("-");
                  s_lift_type = s_lift_type_no.Right(s_lift_type_no.Length()-i_pos-1);
                  s_lift_type_no = s_lift_type_no.Left(9);

                  s_step_desc = tlc_task_list->GetItemText(sel_item, 0);
                  s_lift_no = tlc_task_list->GetItemText(sel_item, 3);
                  s_req_finish = tlc_task_list->GetItemText(sel_item, 5);
                  s_special_info = tlc_task_list->GetItemText(sel_item, 10);
                  s_desc = tlc_task_list->GetItemText(sel_item, 11);//nonstd_level already done.
                  s_status = tlc_task_list->GetItemText(sel_item, 7);

                  str = str + s_step_desc+wxT("\t")+s_project_no+wxT("\t")+s_wbsno+wxT("\t")+s_lift_type_no+wxT("\t")+s_lift_type+wxT("\t")+
                  s_projec_name+wxT("\t")+s_lift_no+wxT("\t")+s_req_finish+wxT("\t")+s_special_info+wxT("\t")+s_desc+wxT("\t")+s_status+END_OF_LINE;
                  copied++;
        }
    }

    if (copied && wxTheClipboard->Open())
	{
		wxTheClipboard->SetData(new wxTextDataObject(str));
		wxTheClipboard->Close();
	}
	else
	{
		copied = 0;
	}

	return copied;
}

void workflow_wf::OnMenuItem5Selected(wxCommandEvent& event)
{
    wxTreeItemId root = tlc_task_list->GetRootItem();
    wxArrayTreeItemIds items;
    wxArrayTreeItemIds::iterator iter;
    tlc_task_list->GetSelections( items );

    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(items.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }

    wxArrayString array_sel_wbs;
    wxString str_temp;

    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item)==root)
        {

            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_task_list->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {
                  str_temp = tlc_task_list->GetItemText(child_item,1).Upper().Trim();
                  array_sel_wbs.Add(str_temp);

                  child_item = tlc_task_list->GetNextSibling(child_item);
            }
        }else
        {
                str_temp = tlc_task_list->GetItemText(sel_item, 1).Upper().Trim();
                array_sel_wbs.Add(str_temp);
        }
    }

    int i_sel = array_sel_wbs.GetCount();
    wxString str_clause;
    for (int i = 0; i < i_sel; i++)
    {
        if (i == i_sel - 1)
        {
            str_clause = str_clause + wxT(" link_list like'%") + array_sel_wbs.Item(i) + wxT("%' ");
        }
        else
        {
            str_clause = str_clause + wxT(" link_list like'%") + array_sel_wbs.Item(i) + wxT("%' or ");
        }
    }

    wxString str_sql;
    nstd_mat_task_list dlg;
    dlg.init_nstd_mat_instance_header();
    str_sql = wxT("SELECT index_mat_id, concat(contract_id,' ', project_name,'-',project_id) as project_name, mat_req_date, drawing_req_date, \
                          nonstd_catalog, nonstd_desc, nonstd_value, (select name from s_employee where employee_id = res_person) as res_person,\
                          instance_nstd_desc, instance_remarks, (select name from s_employee where employee_id = res_engineer) as res_engineer, status, link_list from v_nonstd_app_item_instance where  ") + str_clause + wxT(" order by index_id ASC;");
    dlg.Set_Query(str_sql);
    dlg.refresh_list(0);

    dlg.m_search_mode = true;
    dlg.show_control(false);
    dlg.ShowModal();

}

void workflow_wf::OnMenuItem6Selected(wxCommandEvent& event)
{
    wxTreeItemId root = tlc_task_list->GetRootItem();
    wxArrayTreeItemIds items;
    wxArrayTreeItemIds::iterator iter;
    tlc_task_list->GetSelections( items );

    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(items.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }

    wxArrayString array_sel_wbs;
    wxString str_temp;

    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item)==root)
        {

            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_task_list->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {
                  str_temp = tlc_task_list->GetItemText(child_item,1).Upper().Trim();
                  array_sel_wbs.Add(str_temp);

                  child_item = tlc_task_list->GetNextSibling(child_item);
            }
        }else
        {
                str_temp = tlc_task_list->GetItemText(sel_item, 1).Upper().Trim();
                array_sel_wbs.Add(str_temp);
        }
    }

    int i_count = array_sel_wbs.GetCount();

    wxString str_sql = wxT("select index_id,sequence,stno,mat_id,mat_name_cn, qty, unit, mat_comment, link_list from l_nonstd_configure_mat_list where ");

    for(int i=0;i<i_count;i++)
    {

          if(i==i_count -1)
             str_sql = str_sql + wxT(" link_list like '%")+array_sel_wbs.Item(i)+wxT("%' ");
          else
            str_sql = str_sql + wxT(" link_list like '%")+array_sel_wbs.Item(i)+wxT("%' OR");
    }

    str_sql= str_sql + wxT(" and is_active=true order by index_id,sequence ASC;");//add is _active to let non-std engineer finish the sub-task to be shown to configuration;
    nstd_mat_task_list dlg;
    dlg.m_search_mode = true;
    dlg.show_control(false);
    dlg.init_nstd_mat_header();
    dlg.Set_Query(str_sql);
    dlg.refresh_list();
    dlg.show_control(false);
    dlg.ShowModal();
}

void workflow_wf::OnMenuItem7Selected(wxCommandEvent& event)
{
    wxString str_group,str_user;
    wxArrayString  s_members;

    int icount = array_leader_group.GetCount();

    if(icount<1)
        s_members = array_worker;
    else
    {
        str_group = wxGetApp().get_only_group();
        s_members = wxGetApp().get_member_in_group(str_group);
    }

    wxSingleChoiceDialog cdlg(this, _("请选择人员:"),_("筛选选择"),s_members);

    if(cdlg.ShowModal() == wxID_OK)
    {
        str_user = cdlg.GetStringSelection();
    }
    else
    {
        wxLogMessage(_("未选择人员，操作退出!"));
        return;
    }

    str_user = str_user.Left(8);

    wxTreeItemId root = tlc_group_task_list->GetRootItem();
    tlc_group_task_list->DeleteChildren (root);

    wxPostgreSQLresult* _res;
    wxString str_query;

    str_query = wxT("SELECT  conf_batch_id, instance_id, action_id, name as operator_name, action_name, concat(elevator_id,'-',elevator_type) as elevator_type, concat(contract_id, ' ', project_name) as project_name,special_info, \
                    lift_no , req_configure_finish as req_finish_date , is_return, req_delivery_date, (select doc_desc from s_doc where doc_id = step_desc_id) as doc_desc , workflow_id, status, is_urgent, return_time, project_catalog  FROM v_task_list1 WHERE \
                    is_active = true AND operator_id = '")+str_user+ wxT("'  AND  (workflow_id='WF0002' OR workflow_id='WF0006')  ");


    str_query = str_query + wxT(" ORDER BY  req_finish_date, conf_batch_id, action_id, instance_id ASC ;");

    _res = wxGetApp().app_sql_select(str_query);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        return;
    }

    wxString s_wbs, s_index, s_batch_id, s_project_name, s_action_id;
    m_rows = _res->GetRowsNumber();
     _res->MoveFirst();

    wxTreeItemId branch_item,leaf_item;

    for(int i=0;i<m_rows;i++)
    {
        s_batch_id = _res->GetVal(wxT("conf_batch_id"));
        s_wbs = _res->GetVal(wxT("instance_id"));
        s_project_name = _res->GetVal(wxT("project_name"));


        if(s_batch_id.IsEmpty())
        {
            if(s_index != s_wbs.Left(10) || s_action_id != _res->GetVal(wxT("action_id")))
            {
                s_index = s_wbs.Left(10);
                branch_item = tlc_group_task_list->AppendItem(root, _res->GetVal(wxT("action_name")));
                tlc_group_task_list->SetItemText(branch_item,2, s_index);
                tlc_group_task_list->SetItemText(branch_item, 1,s_project_name+"-"+s_index);
 //               tlc_group_task_list->Expand(branch_item);
            }

        }else
        {
            if(s_index != s_batch_id)
            {
                s_index = s_batch_id;
                branch_item = tlc_group_task_list->AppendItem(root, _res->GetVal(wxT("action_name")));
                tlc_group_task_list->SetItemText(branch_item, 2, s_index);
                tlc_group_task_list->SetItemText(branch_item, 1, s_project_name+"-"+s_wbs.Left(10) );
 //               tlc_group_task_list->Expand(branch_item);
            }
        }

        s_action_id = _res->GetVal(wxT("action_id"));
        leaf_item = tlc_group_task_list->AppendItem(branch_item,_res->GetVal(wxT("action_name")),-1,-1);
        tlc_group_task_list->SetItemText(leaf_item, 1, s_wbs);
        tlc_group_task_list->SetItemText(leaf_item, 2, s_index);
        tlc_group_task_list->SetItemText(leaf_item, 3, _res->GetVal(wxT("operator_name")));
        tlc_group_task_list->SetItemText(leaf_item, 4, _res->GetVal(wxT("lift_no")));
        tlc_group_task_list->SetItemText(leaf_item, 5, _res->GetVal(wxT("elevator_type")));
        tlc_group_task_list->SetItemText(leaf_item, 6, DateToStrFormat(_res->GetDate(wxT("req_finish_date"))));
        tlc_group_task_list->SetItemText(leaf_item, 7, BoolToY(_res->GetBool(wxT("is_return"))));
        tlc_group_task_list->SetItemText(leaf_item, 8, prj_status_to_str(_res->GetInt(wxT("status"))));
        tlc_group_task_list->SetItemText(leaf_item, 9, DateToStrFormat(_res->GetDate(wxT("req_delivery_date"))));
        tlc_group_task_list->SetItemText(leaf_item, 10, _res->GetVal(wxT("special_info")));
        tlc_group_task_list->SetItemText(leaf_item, 11, _res->GetVal(wxT("doc_desc")));
        tlc_group_task_list->SetItemText(leaf_item, 12, s_action_id );
        tlc_group_task_list->SetItemText(leaf_item, 13, BoolToY(_res->GetBool(wxT("is_urgent"))));
        tlc_group_task_list->SetItemText(leaf_item, 14, _res->GetVal(wxT("return_time")));
        tlc_group_task_list->SetItemText(leaf_item, 15, _res->GetVal(wxT("project_catalog")));

        _res->MoveNext();
    }


    _res->Clear();

    refresh_group_level(true);


}

void workflow_wf::OnMenuItem8Selected(wxCommandEvent& event)
{

    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    wxString str_group = wxGetApp().get_only_group();

    if(str_group !=wxT("G0003")&&str_group!=wxT("G0004")&&str_group!=wxT("G0005"))
        return;

    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_task_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_task_list->GetSelections( items );
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
  //      _("Comp-Measurement"),
   //     _("Comp-Configurable")
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
        if(tlc_task_list->GetItemParent(sel_item)==root)
        {
            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_task_list->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {
                str=tlc_task_list->GetItemText(child_item,9);
                str_wbs = tlc_task_list->GetItemText(child_item, 1);
                i_old_nstd_level = nstd_str_to_level(str);

                if(i_nstd_level== i_old_nstd_level)
                {
                    child_item = tlc_task_list->GetNextSibling(child_item);
                    wxLogMessage(str_wbs+_("非标等级本来就是:")+nstd_level_to_str(i_nstd_level)+_("，无需更新!"));
                    continue;
                }

                if(update_nstd_level(str_wbs, i_old_nstd_level, i_nstd_level))
                {
                    tlc_task_list->SetItemText(child_item,9, nstd_level_to_str(i_nstd_level));

                    wxLogMessage(str_wbs+_("非标等级更新为:")+nstd_level_to_str(i_nstd_level)+_(", 成功!"));
                }

                child_item = tlc_task_list->GetNextSibling(child_item);

            }
        }else
        {
                str=tlc_task_list->GetItemText(sel_item,9);
                str_wbs = tlc_task_list->GetItemText(sel_item, 1);
                i_old_nstd_level = nstd_str_to_level(str);

                if(i_nstd_level== i_old_nstd_level)
                {
                    wxLogMessage(str_wbs+_("非标等级本来就是:")+nstd_level_to_str(i_nstd_level)+_("，无需更新!"));
                    continue;
                }

                if(update_nstd_level(str_wbs, i_old_nstd_level, i_nstd_level))
                {
                    tlc_task_list->SetItemText(sel_item,9, nstd_level_to_str(i_nstd_level));
                    wxLogMessage(str_wbs+_("非标等级更新为:")+nstd_level_to_str(i_nstd_level)+_(", 成功!"));
                }

        }
    }
    refresh_task_level();

}

bool workflow_wf::update_nstd_level(wxString s_wbs, int old_status, int new_status)
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

void workflow_wf::OnMenuItem_WEIGHTSelected(wxCommandEvent& event)
{

    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_task_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_task_list->GetSelections( items );

    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(items.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }
    wxTreeItemId sel_item, child_item;
    wxTreeItemIdValue cookie;
    wxArrayString a_sel_wbs;
    wxString s_action_id, str_temp;

    for( iter = items.begin(); iter<items.end(); iter++)
    {
         sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item)==root)
        {
            child_item = tlc_task_list->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {
               str_temp = tlc_task_list->GetItemText(child_item, 1);
               s_action_id = tlc_task_list->GetItemText(child_item,13);
               a_sel_wbs.Add(str_temp);

               child_item = tlc_task_list->GetNextSibling(child_item);
            }
        }else
        {
               s_action_id = tlc_task_list->GetItemText(sel_item,13);
               str_temp = tlc_task_list->GetItemText(sel_item, 1);
               a_sel_wbs.Add(str_temp);
        }
    }

    unit_info_attach_dlg dlg;

    if(s_action_id == wxT("AT00000004")|| s_action_id == wxT("AT00000005")||s_action_id==wxT("AT00000006"))
    {
        dlg.Set_Editable(true);
        dlg.refresh_control();
        dlg.array_wbs = a_sel_wbs;

        dlg.refresh_list();

        dlg.ShowModal();
    }else
    {
         dlg.Set_Editable(false);
        dlg.refresh_control();
        dlg.array_wbs = a_sel_wbs;

        dlg.refresh_list();

        dlg.ShowModal();
    }

}

void workflow_wf::Onmi_cb_changeSelected(wxCommandEvent& event)
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

    contractbook_br_dlg dlg;
    dlg.set_mode(1);
    dlg.refresh_list(gr_para.login_user, 2);
    dlg.ShowModal();
}

void workflow_wf::Onmi_contractbook_br_searchSelected(wxCommandEvent& event)
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
    wxTextEntryDialog tdlg(this, _("请输入合同号或WBS NO"), _("项目合同借阅查询"),wxT(""), wxTextEntryDialogStyle, wxDefaultPosition);
    tdlg.SetTextValidator(wxFILTER_EMPTY);

    if (tdlg.ShowModal() == wxID_CANCEL)
        return;

    wxString s_case = tdlg.GetValue();

    contractbook_br_dlg dlg;
    dlg.set_mode(0);
    dlg.refresh_list(s_case, 1);
    dlg.ShowModal();
}
