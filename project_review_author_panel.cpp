#include "project_review_author_panel.h"
#include "wfApp.h"
#include "utils/wf_operator.h"
#include "communication_dlg.h"
#include "mydatepicker.h"
#include "review_communication_log.h"
#include "ins_proc_log.h"

//(*InternalHeaders(project_review_author_panel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(project_review_author_panel)
const long project_review_author_panel::ID_BUTTON_AUTHOR = wxNewId();
const long project_review_author_panel::ID_BUTTON_REUEIRE_FINISH = wxNewId();
const long project_review_author_panel::ID_BUTTON_DRAW_QTY = wxNewId();
const long project_review_author_panel::ID_BUTTON_RETURN = wxNewId();
const long project_review_author_panel::ID_BUTTON_RETURN_TO_START = wxNewId();
const long project_review_author_panel::ID_BUTTON_FEEDBACK = wxNewId();
const long project_review_author_panel::ID_BUTTON_REFRESH = wxNewId();
const long project_review_author_panel::ID_BUTTON_GROUP = wxNewId();
const long project_review_author_panel::ID_LISTVIEW_PERSON = wxNewId();
const long project_review_author_panel::idMenu_Expand = wxNewId();
const long project_review_author_panel::idMenu_Collapse = wxNewId();
const long project_review_author_panel::idMenu_All = wxNewId();
const long project_review_author_panel::idMenu_Author = wxNewId();
const long project_review_author_panel::idMenu_Review = wxNewId();
const long project_review_author_panel::idMenu_Check = wxNewId();
const long project_review_author_panel::idMenu_review = wxNewId();
const long project_review_author_panel::idMenu_restart_history = wxNewId();
const long project_review_author_panel::idMenu_com_log = wxNewId();
const long project_review_author_panel::idMenu_pos = wxNewId();
const long project_review_author_panel::idMenu_NoCheck = wxNewId();
const long project_review_author_panel::idMenu_Cancel = wxNewId();
const long project_review_author_panel::idMenu_filter = wxNewId();
const long project_review_author_panel::idMenu_show_all = wxNewId();
const long project_review_author_panel::idMenu_group_review = wxNewId();
const long project_review_author_panel::idMenu_group_restart_his = wxNewId();
const long project_review_author_panel::idMenu_group_com_log = wxNewId();
const long project_review_author_panel::idMenu_group_pos = wxNewId();
//*)
const long project_review_author_panel::ID_TREELISTCTRL_TASK_LIST = wxNewId();
const long project_review_author_panel::ID_TREELISTCTRL_GROUP_TASK_LIST = wxNewId();

BEGIN_EVENT_TABLE(project_review_author_panel, wxPanel)
    //(*EventTable(project_review_author_panel)
    //*)
END_EVENT_TABLE()

project_review_author_panel::project_review_author_panel(wxWindow * parent, wxWindowID id, const wxPoint & pos, const wxSize & size)
{
    //(*Initialize(project_review_author_panel)
    wxStaticBoxSizer* sbox_author;
    wxGridBagSizer* GridBagSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer1;
    wxStaticBoxSizer* sb_group;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    GridBagSizer1 = new wxGridBagSizer(0, 0);
    sbox_author = new wxStaticBoxSizer(wxHORIZONTAL, this, _("待授权任务清单"));
    GridBagSizer1->Add(sbox_author, wxGBPosition(0, 0), wxGBSpan(6, 6), wxALL|wxEXPAND, 0);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    Button_Author = new wxButton(this, ID_BUTTON_AUTHOR, _("授权/评审/审核"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_AUTHOR"));
    BoxSizer2->Add(Button_Author, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    Button_Require = new wxButton(this, ID_BUTTON_REUEIRE_FINISH, _("设置评审完成日"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_REUEIRE_FINISH"));
    BoxSizer2->Add(Button_Require, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    Button_Draw_qty = new wxButton(this, ID_BUTTON_DRAW_QTY, _("变更图纸套数"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_DRAW_QTY"));
    BoxSizer2->Add(Button_Draw_qty, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    Button_RETURN = new wxButton(this, ID_BUTTON_RETURN, _("任务退回"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_RETURN"));
    BoxSizer2->Add(Button_RETURN, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    Button_return_to_start = new wxButton(this, ID_BUTTON_RETURN_TO_START, _("退回到待启动状态"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_RETURN_TO_START"));
    Button_return_to_start->Hide();
    BoxSizer2->Add(Button_return_to_start, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    Button_Feedback = new wxButton(this, ID_BUTTON_FEEDBACK, _("问题反馈"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_FEEDBACK"));
    BoxSizer2->Add(Button_Feedback, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    Button_REFRESH = new wxButton(this, ID_BUTTON_REFRESH, _("刷新任务列表"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_REFRESH"));
    BoxSizer2->Add(Button_REFRESH, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    button_group = new wxButton(this, ID_BUTTON_GROUP, _("组员评审任务(全显)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_GROUP"));
    BoxSizer2->Add(button_group, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    GridBagSizer1->Add(BoxSizer2, wxGBPosition(0, 6), wxDefaultSpan, wxALL|wxALIGN_TOP, 0);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("组员列表"));
    lv_person = new wxListView(this, ID_LISTVIEW_PERSON, wxDefaultPosition, wxSize(185,224), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTVIEW_PERSON"));
    StaticBoxSizer1->Add(lv_person, 1, wxALL|wxEXPAND, 0);
    GridBagSizer1->Add(StaticBoxSizer1, wxGBPosition(0, 7), wxGBSpan(6, 2), wxALL|wxEXPAND, 0);
    BoxSizer1->Add(GridBagSizer1, 2, wxALL|wxEXPAND, 0);
    sb_group = new wxStaticBoxSizer(wxHORIZONTAL, this, _("组员任务清单"));
    BoxSizer1->Add(sb_group, 1, wxALL|wxEXPAND, 0);
    SetSizer(BoxSizer1);
    mi_expand = new wxMenuItem((&menu_author), idMenu_Expand, _("全部展开(&E)"), _("项目展开"), wxITEM_NORMAL);
    menu_author.Append(mi_expand);
    mi_collapse = new wxMenuItem((&menu_author), idMenu_Collapse, _("全部收起(&C)"), _("项目收起"), wxITEM_NORMAL);
    menu_author.Append(mi_collapse);
    menu_author.AppendSeparator();
    mi_show_all = new wxMenuItem((&menu_author), idMenu_All, _("显示全部任务(&A)"), _("显示全部任务"), wxITEM_CHECK);
    menu_author.Append(mi_show_all);
    mi_show_all->Check(true);
    mi_show_author = new wxMenuItem((&menu_author), idMenu_Author, _("仅显示待授权(&W)"), _("仅显示待授权"), wxITEM_CHECK);
    menu_author.Append(mi_show_author);
    mi_review = new wxMenuItem((&menu_author), idMenu_Review, _("仅显示待评审(&R)"), _("仅显示待评审项目"), wxITEM_CHECK);
    menu_author.Append(mi_review);
    mi_check = new wxMenuItem((&menu_author), idMenu_Check, _("仅显示待审核(&H)"), _("仅显示待审核项目"), wxITEM_CHECK);
    menu_author.Append(mi_check);
    menu_author.AppendSeparator();
    mi_process = new wxMenuItem((&menu_author), idMenu_review, _("项目评审流程信息(&I)"), _("项目评审流程信息"), wxITEM_NORMAL);
    menu_author.Append(mi_process);
    mi_history = new wxMenuItem((&menu_author), idMenu_restart_history, _("重启评审历史(&T)"), _("重启评审历史"), wxITEM_NORMAL);
    menu_author.Append(mi_history);
    mi_com_log = new wxMenuItem((&menu_author), idMenu_com_log, _("问题传递log(&L)"), _("问题传递log"), wxITEM_NORMAL);
    menu_author.Append(mi_com_log);
    mi_pos = new wxMenuItem((&menu_author), idMenu_pos, _("快速定位(&P)\tCtrl+F"), _("快速定位-合同号或WBSNO"), wxITEM_NORMAL);
    menu_author.Append(mi_pos);
    mi_no_check = new wxMenuItem((&menu_check), idMenu_NoCheck, _("免审设置(&N)"), _("免审设置"), wxITEM_NORMAL);
    menu_check.Append(mi_no_check);
    mi_cancel_no_check = new wxMenuItem((&menu_check), idMenu_Cancel, _("取消免审(&C)"), _("取消免审"), wxITEM_NORMAL);
    menu_check.Append(mi_cancel_no_check);
    menu_filter.AppendSeparator();
    mi_filter = new wxMenuItem((&menu_filter), idMenu_filter, _("按组员筛选(&F)"), _("按组员筛选显示项目"), wxITEM_NORMAL);
    menu_filter.Append(mi_filter);
    mi_showall = new wxMenuItem((&menu_filter), idMenu_show_all, _("所有组员任务(&A)"), _("所有组员任务"), wxITEM_NORMAL);
    menu_filter.Append(mi_showall);
    menu_filter.AppendSeparator();
    mi_group_process = new wxMenuItem((&menu_filter), idMenu_group_review, _("项目评审流程信息(&I)"), _("项目评审流程信息"), wxITEM_NORMAL);
    menu_filter.Append(mi_group_process);
    mi_group_review_history = new wxMenuItem((&menu_filter), idMenu_group_restart_his, _("重启评审历史(&H)"), _("重启评审历史"), wxITEM_NORMAL);
    menu_filter.Append(mi_group_review_history);
    mi_group_com_log = new wxMenuItem((&menu_filter), idMenu_group_com_log, _("问题传递log(&L)"), _("问题传递log"), wxITEM_NORMAL);
    menu_filter.Append(mi_group_com_log);
    mi_group_pos = new wxMenuItem((&menu_filter), idMenu_group_pos, _("快速定位(&P)\tCtrl+D"), _("快速定位"), wxITEM_NORMAL);
    menu_filter.Append(mi_group_pos);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON_AUTHOR,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&project_review_author_panel::OnButton_AuthorClick);
    Connect(ID_BUTTON_REUEIRE_FINISH,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&project_review_author_panel::OnButton_RequireClick);
    Connect(ID_BUTTON_DRAW_QTY,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&project_review_author_panel::OnButton_Draw_qtyClick);
    Connect(ID_BUTTON_RETURN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&project_review_author_panel::OnButton_RETURNClick);
    Connect(ID_BUTTON_RETURN_TO_START,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&project_review_author_panel::OnButton_return_to_startClick);
    Connect(ID_BUTTON_FEEDBACK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&project_review_author_panel::OnButton_FeedbackClick);
    Connect(ID_BUTTON_REFRESH,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&project_review_author_panel::OnButton_REFRESHClick);
    Connect(ID_BUTTON_GROUP,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&project_review_author_panel::Onbutton_groupClick);
    Connect(ID_LISTVIEW_PERSON,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&project_review_author_panel::Onlv_personItemActivated);
    Connect(ID_LISTVIEW_PERSON,wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK,(wxObjectEventFunction)&project_review_author_panel::Onlv_personItemRClick);
    Connect(idMenu_Expand,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_review_author_panel::Onmi_expandSelected);
    Connect(idMenu_Collapse,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_review_author_panel::Onmi_collapseSelected);
    Connect(idMenu_All,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_review_author_panel::Onmi_show_allSelected);
    Connect(idMenu_Author,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_review_author_panel::Onmi_show_authorSelected);
    Connect(idMenu_Review,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_review_author_panel::Onmi_reviewSelected);
    Connect(idMenu_Check,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_review_author_panel::Onmi_checkSelected);
    Connect(idMenu_review,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_review_author_panel::Onmi_processSelected);
    Connect(idMenu_restart_history,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_review_author_panel::Onmi_historySelected);
    Connect(idMenu_com_log,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_review_author_panel::Onmi_com_logSelected);
    Connect(idMenu_pos,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_review_author_panel::Onmi_posSelected);
    Connect(idMenu_NoCheck,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_review_author_panel::Onmi_no_checkSelected);
    Connect(idMenu_Cancel,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_review_author_panel::Onmi_cancel_no_checkSelected);
    Connect(idMenu_filter,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_review_author_panel::Onmi_filterSelected);
    Connect(idMenu_show_all,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_review_author_panel::Onmi_showallSelected);
    Connect(idMenu_group_review,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_review_author_panel::Onmi_group_processSelected);
    Connect(idMenu_group_restart_his,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_review_author_panel::Onmi_group_review_historySelected);
    Connect(idMenu_group_com_log,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_review_author_panel::Onmi_group_com_logSelected);
    Connect(idMenu_group_pos,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_review_author_panel::Onmi_group_posSelected);
    //*)
    init_list_header();
    refresh_res_list();
    GridBagSizer1->AddGrowableCol(5);
//   GridBagSizer1->AddGrowableCol(7);
    GridBagSizer1->AddGrowableRow(4);
    BuildDataViewCtrl();
    sbox_author->Add(tlc_task_list, 1, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 0);
    sb_group->Add(tlc_group_task_list, 1, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 0);
    Layout();

    Connect(ID_TREELISTCTRL_TASK_LIST, wxEVT_TREE_ITEM_MENU, (wxObjectEventFunction)&project_review_author_panel::OnTaskListRightClick);
    Connect(ID_TREELISTCTRL_GROUP_TASK_LIST, wxEVT_TREE_ITEM_MENU, (wxObjectEventFunction)&project_review_author_panel::OnGroupTaskListRightClick);
    Connect(ID_TREELISTCTRL_TASK_LIST,wxEVT_COMMAND_TREE_KEY_DOWN ,(wxObjectEventFunction)&project_review_author_panel::OnChar);
    Connect(ID_TREELISTCTRL_GROUP_TASK_LIST,wxEVT_COMMAND_TREE_KEY_DOWN ,(wxObjectEventFunction)&project_review_author_panel::OnChar);

//    wxString str = wxT(" operator_id = '") + gr_para.login_user + wxT("' and is_active = true and active_status>=1 and action_id = 'AT00000002' ");
    wxString str = wxT(" operator_id = '") + gr_para.login_user + wxT("' and is_active = true and (action_id = 'AT00000002' OR action_id ='AT00000025' OR action_id='AT00000026') and unit_status>=0 and is_latest=true ");
    set_clause(str);
    refresh_list();
    str = wxT(" is_active = true and active_status>=1 and (action_id = 'AT00000025' or action_id = 'AT00000026') and unit_status>=0 and is_latest=true ");
    set_group_clause(str);
    refresh_group_list();
}

project_review_author_panel::~project_review_author_panel()
{
    //(*Destroy(project_review_author_panel)
    //*)
}

void project_review_author_panel::BuildDataViewCtrl()
{
    InitImageList();
    tlc_task_list = new wxcode::wxTreeListCtrl(this, ID_TREELISTCTRL_TASK_LIST ,
            wxDefaultPosition, wxDefaultSize,
            wxTR_DEFAULT_STYLE | wxTR_COLUMN_LINES | wxTR_HIDE_ROOT | wxTR_ROW_LINES | wxTR_MULTIPLE | wxTR_FULL_ROW_HIGHLIGHT);
    tlc_task_list->SetImageList(m_imageList);

    tlc_task_list->AddColumn(_("项目信息"), 300, wxALIGN_LEFT, -1, true, false); //0
    tlc_task_list->AddColumn(_("任务ID"), 0, wxALIGN_LEFT, -1, false, false); //1
    tlc_task_list->AddColumn(_("台数"), 50, wxALIGN_LEFT, -1, true, false); //2
    tlc_task_list->AddColumn(_("图纸套数"),60,wxALIGN_LEFT,-1,true,false); //15- 3
    tlc_task_list->AddColumn(_("要求完成日期"), 100, wxALIGN_LEFT, -1, true, false); //3-4
    tlc_task_list->AddColumn(_("紧急程度"), 60, wxALIGN_LEFT, -1, true, false);//4-5
    tlc_task_list->AddColumn(_("任务收到时间"), 120, wxALIGN_LEFT,-1, true, false);//5-6

    tlc_task_list->AddColumn(_("合同负责ID"), 0, wxALIGN_LEFT, -1, false, false); //6-7
    tlc_task_list->AddColumn(_("合同负责"), 100, wxALIGN_LEFT, -1, true, false); //7-8
    tlc_task_list->AddColumn(_("评审负责ID"), 0, wxALIGN_LEFT, -1, false, false); //8-9
    tlc_task_list->AddColumn(_("评审负责"), 100, wxALIGN_LEFT, -1, true, false); //9-10
    tlc_task_list->AddColumn(_("分公司id"), 0, wxALIGN_LEFT, -1, false, false); //10-11
    tlc_task_list->AddColumn(_("分公司"), 100, wxALIGN_LEFT, -1, true, false); //11-12
    tlc_task_list->AddColumn(_("status"), 50, wxALIGN_LEFT, -1, true, false); //12-13
    tlc_task_list->AddColumn(_("任务状态"), 70, wxALIGN_LEFT, -1, true, false); //13-14
    tlc_task_list->AddColumn(_("action_id"), 0, wxALIGN_LEFT, -1, false, false); //14-15


    tlc_task_list->AddColumn(_("备注"),100,wxALIGN_LEFT,-1,true,false); //16
    tlc_task_list->AddColumn(_("交流status"), 0, wxALIGN_LEFT, -1, false, false); //17
    tlc_task_list->AddColumn(_("交流状态"), 200, wxALIGN_LEFT, -1, true, false); //18
    tlc_task_list->AddColumn(_("flow_ser"),0, wxALIGN_LEFT, -1, false, false); //19
    tlc_task_list->AddColumn(_("紧急程度id"),0, wxALIGN_LEFT, -1, false, false); //20
    tlc_task_list->AddRoot(_("评审任务"));


    tlc_group_task_list = new wxcode::wxTreeListCtrl(this, ID_TREELISTCTRL_GROUP_TASK_LIST ,
            wxDefaultPosition, wxDefaultSize,
            wxTR_DEFAULT_STYLE | wxTR_COLUMN_LINES | wxTR_HIDE_ROOT | wxTR_ROW_LINES | wxTR_MULTIPLE | wxTR_FULL_ROW_HIGHLIGHT);
    tlc_group_task_list->SetImageList(m_imageList);

    tlc_group_task_list->AddColumn(_("项目信息"), 300, wxALIGN_LEFT, -1, true, false); //0
    tlc_group_task_list->AddColumn(_("任务ID"), 0, wxALIGN_LEFT, -1, false, false); //1
    tlc_group_task_list->AddColumn(_("台数"), 50, wxALIGN_LEFT, -1, true, false); //2

     tlc_group_task_list->AddColumn(_("图纸套数"),60,wxALIGN_LEFT,-1,true,false); //15-3
    tlc_group_task_list->AddColumn(_("要求完成日期"), 100, wxALIGN_LEFT, -1, true, false); //3-4

    tlc_group_task_list->AddColumn(_("紧急程度"), 60, wxALIGN_LEFT, -1, true, false);//4-5
    tlc_group_task_list->AddColumn(_("任务收到时间"), 120, wxALIGN_LEFT,-1, true, false);//5-6

    tlc_group_task_list->AddColumn(_("合同负责ID"), 0, wxALIGN_LEFT, -1, false, false); //6-7
    tlc_group_task_list->AddColumn(_("合同负责"), 100, wxALIGN_LEFT, -1, true, false); //7-8
    tlc_group_task_list->AddColumn(_("评审负责ID"), 0, wxALIGN_LEFT, -1, false, false); //8-9
    tlc_group_task_list->AddColumn(_("评审负责"), 100, wxALIGN_LEFT, -1, true, false); //9-10
    tlc_group_task_list->AddColumn(_("分公司id"), 0, wxALIGN_LEFT, -1, false, false); //10-11
    tlc_group_task_list->AddColumn(_("分公司"), 100, wxALIGN_LEFT, -1, true, false); //11-12
    tlc_group_task_list->AddColumn(_("status"), 50, wxALIGN_LEFT, -1, true, false); //12-13
    tlc_group_task_list->AddColumn(_("任务状态"), 70, wxALIGN_LEFT, -1, true, false); //13-14
    tlc_group_task_list->AddColumn(_("action_id"), 0, wxALIGN_LEFT, -1, false, false); //14-15

    tlc_group_task_list->AddColumn(_("备注"),100,wxALIGN_LEFT,-1,true,false); //16
    tlc_group_task_list->AddColumn(_("交流status"), 0, wxALIGN_LEFT, -1, false, false); //17
    tlc_group_task_list->AddColumn(_("交流状态"), 200, wxALIGN_LEFT, -1, true, false); //18
    tlc_group_task_list->AddColumn(_("紧急程度id"),0, wxALIGN_LEFT, -1, false, false); //19
    tlc_group_task_list->AddRoot(_("评审任务"));
}

void project_review_author_panel::init_list_header()
{
    wxListItem itemCol;
    itemCol.SetText(_("工程师ID"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(0);
    lv_person->InsertColumn(0, itemCol);
    itemCol.SetText(_("评审工程师"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(80);
    lv_person->InsertColumn(1, itemCol);
    itemCol.SetText(_("分配任务数"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(80);
    lv_person->InsertColumn(2, itemCol);
    itemCol.SetText(_("是否免审"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(80);
    lv_person->InsertColumn(3, itemCol);
}

void project_review_author_panel::refresh_res_list()
{
    lv_person->DeleteAllItems();
    wxString strSql = wxT("SELECT employee_id, name ,  group_id, no_check FROM v_group_member WHERE group_id = 'G0002' AND plant = '") + gr_para.plant + wxT("' and status=true ORDER BY employee_id ASC;");
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(strSql);
    if (_res->Status() != PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }
    int irow = _res->GetRowsNumber();
    _res->MoveFirst();

    wxString str, s_operator;
    for (int i = 0; i < irow; i++)
    {
        s_operator= _res->GetVal(wxT("employee_id"));
        long tmp = lv_person->InsertItem(i, s_operator);
        lv_person->SetItemData(tmp, i);
        str = _res->GetVal(wxT("name"));
        lv_person->SetItem(tmp, 1, str);
//        str = _res->GetVal(wxT("task_qty"));
         str = update_res_list(s_operator);

         lv_person->SetItem(tmp, 2, str);
        str = BoolToY(_res->GetBool(wxT("no_check")));
        lv_person->SetItem(tmp, 3, str);
        _res->MoveNext();
    }
    _res->Clear();
}

wxString project_review_author_panel::update_res_list(wxString s_operator)
{
    wxString str;
    wxString strSql = wxT("select DISTINCT review_task_id,review_drawing_qty from v_task_list4 where operator_id = '")+s_operator+wxT("' AND is_active=true AND active_status>=1 AND action_id = 'AT00000025' and unit_status>=0 and is_latest=true ");
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(strSql);
    if (_res->Status() != PGRES_TUPLES_OK)
    {
        _res->Clear();
        return wxT("0(0)");
    }

    int i_row = _res->GetRowsNumber();

    int i_draw=0;

    for(int i=0;i<i_row;i++)
    {
        i_draw = i_draw + _res->GetInt(wxT("review_drawing_qty"));
        _res->MoveNext();
    }

    _res->Clear();

    str = NumToStr(i_row)+wxT("(")+NumToStr(i_draw)+wxT(")");

    return str;
}

void project_review_author_panel::OnButton_AuthorClick(wxCommandEvent & event)
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

    wxString s_task_id, s_operator, s_group, s_branch_action_id, s_leaf_action_id;


    if (wxMessageBox(_("操作确认！"),_("确认"),wxOK|wxCANCEL,this)==wxCANCEL)
    {
        return;
    }

    v_wf_action * t_template=0;

    wf_operator * wf_active=0;
    wf_process * l_proc_act =0;

    int i_status;
    wxString s_wf_status, s_wbs,str_head, str_date, str;
    wxLongLong mils_used, start_mils;
    bool b_update_review_eng=false;
    bool b_update_review_status = false;
    bool b_refresh_group=false;

    t_template = get_template_action(wf_str_review);

    for ( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if (tlc_task_list->GetItemParent(sel_item)==root&&sel_item.IsOk())
        {

            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_task_list->GetFirstChild(sel_item,cookie);
            str_head = tlc_task_list->GetItemText(sel_item, 0);
            s_task_id = tlc_task_list->GetItemText(sel_item, 1);
            s_branch_action_id = tlc_task_list->GetItemText(sel_item, 15);//20150813
            str_date = tlc_task_list->GetItemText(sel_item,4);//20150813

            b_update_review_eng = true;
            b_update_review_status = true;
            wxString s_branch_id;

            if(s_branch_action_id==wxT("AT00000002"))
            {

                if(str_date.IsEmpty())
                {
                    if(wxMessageBox(str_head+_(": 请先设置评审要求完成日期，否则不能授权!"),_("提示"),wxOK)==wxOK)
                        wxLogMessage(str_head+_(": 请先设置评审要求完成日期，否则不能授权!"));

                    continue;
                }

                long l_item = -1;
                l_item = lv_person->GetNextItem(l_item,  wxLIST_NEXT_ALL,  wxLIST_STATE_SELECTED);

                if (l_item == -1)
                {
                    wxLogMessage(_("请选择操作人员！"));
                    delete [] t_template;
                    return;
                }
                else
                {
                    s_operator = lv_person->GetItemText(l_item, 0);
                    s_group = wxT("G0002");
                }
            }

            if(s_branch_action_id==wxT("AT00000025"))
            {
                wxString s_issue_status = tlc_task_list->GetItemText(sel_item, 17);

                if(s_issue_status == wxT("1"))
                {
                    wxLogMessage(_("项目:")+str_head+_("任务:")+s_task_id+_("正在等待分公司回复,无法确认完成"));
                    continue;
                }
   //             create_communication(s_task_id,  s_issue_status, str, true);

            }

            s_branch_id = tlc_task_list->GetItemText(sel_item, 11);//20150813

            while(child_item.IsOk())
            {
                s_wbs = tlc_task_list->GetItemText(child_item,0);
                s_leaf_action_id = tlc_task_list->GetItemText(child_item, 15);//20150813
                i_status = prj_str_to_status(tlc_task_list->GetItemText(child_item, 13));//20150813

                if (s_leaf_action_id == wxT("AT00000002"))
                {
                    start_mils = wxGetLocalTimeMillis();//事件处理事件统计，起始点。

                    wf_active = new wf_operator(s_wbs, wf_str_review, t_template);
                    wf_active->Pass_proc(s_operator, s_group, wxEmptyString, false);

                    s_wf_status = _("项目评审");

   //                 if (wf_active->update_instance(i_status, s_wf_status))
                    if(update_review_units_status(s_task_id,s_wbs, i_status, s_wf_status))
                    {
                        if(b_update_review_eng)
                        {
                            update_review_engineer(s_operator,s_task_id);
                            b_update_review_eng = false;
                        }
  //                      update_review_units_status(s_task_id,s_wbs, i_status, s_wf_status);
                        wxLogMessage(_("项目:")+s_wbs+_("任务:")+s_task_id+_("授权成功!"));
                    }

                    delete wf_active;

                    mils_used = wxGetLocalTimeMillis() - start_mils;

                    wxLogMessage(s_task_id+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒")); //事件处理事件统计，截止点。
                    b_refresh_group = true;

                }

                if(s_leaf_action_id == wxT("AT00000025"))
                {

                    start_mils = wxGetLocalTimeMillis();//事件处理事件统计，起始点。

                    s_group = wxT("G0002");

                    s_operator = wxGetApp().get_leader(s_group);
                    wf_active = new wf_operator(s_wbs, wf_str_review, t_template);
                    l_proc_act = wf_active->get_current_process();

                    l_proc_act->MoveToActive();

                    wf_active->Pass_proc(s_operator, s_group, wxEmptyString, false);

                    s_group = wxT("G0016");

                    s_operator = get_operator_from_branch(s_branch_id, s_group);
                    l_proc_act->MoveToActive();

                    wf_active->Pass_proc(s_operator, s_group, wxEmptyString, false);

                    l_proc_act = 0;

                    s_wf_status=_("线下PO确认");

     //               if (wf_active->update_instance(i_status,s_wf_status))
                    if(update_review_units_status(s_task_id,s_wbs, i_status, s_wf_status))
                    {
                        if(b_update_review_status)
                        {
                            update_review_task(s_task_id, 2);
                            b_update_review_status = false;
                        }
       //                 update_review_units_status(s_task_id,s_wbs, i_status, s_wf_status);
                        wxLogMessage(_("项目:")+s_wbs+_("任务:")+s_task_id+_("评审完成!"));
                    }

                    delete wf_active;

                    mils_used = wxGetLocalTimeMillis() - start_mils;

                    wxLogMessage(s_task_id+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒")); //事件处理事件统计，截止点。
                    b_refresh_group = true;

                }

                if(s_leaf_action_id == wxT("AT00000026"))
                {

                    start_mils = wxGetLocalTimeMillis();//事件处理事件统计，起始点。

                    s_group = wxT("G0016");

                    s_operator = get_operator_from_branch(s_branch_id, s_group);

                    wf_active = new wf_operator(s_wbs, wf_str_review, t_template);
                    l_proc_act = wf_active->get_current_process();
                    l_proc_act->MoveToActive();

                    wf_active->Pass_proc(s_operator, s_group, wxEmptyString, false);

                    l_proc_act = 0;

                    s_wf_status=_("线下PO确认");

    //                if (wf_active->update_instance(i_status,s_wf_status))
                    if(update_review_units_status(s_task_id,s_wbs, i_status, s_wf_status))
                    {
                        if(b_update_review_status)
                        {
                            update_review_task(s_task_id, 2);
                            b_update_review_status = false;
                        }
           //             update_review_units_status(s_task_id,s_wbs, i_status, s_wf_status);
                        wxLogMessage(_("项目:")+s_wbs+_("任务:")+s_task_id+_("评审核查完成!"));
                    }

                    delete wf_active;

                    mils_used = wxGetLocalTimeMillis() - start_mils;

                    wxLogMessage(s_task_id+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒")); //事件处理事件统计，截止点。
                    b_refresh_group = false;

                }


                child_item = tlc_task_list->GetNextSibling(child_item);
            }

           if(b_refresh_group)
              refresh_group_list();

            tlc_task_list->DeleteChildren(sel_item);
            tlc_task_list->Delete(sel_item);

        }else
        {

        }
    }


    refresh_res_list();
    delete [] t_template;
}

bool project_review_author_panel::update_review_engineer(wxString s_engineer, wxString s_task_id)
{
    wxString str_sql = wxT(" UPDATE s_review_info SET review_engineer='")+s_engineer+wxT("' , modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("' \
                            where review_task_id ='")+s_task_id+wxT("' and active_status>=1;");
    return wxGetApp().app_sql_update(str_sql);
}

wxString project_review_author_panel::get_operator_from_branch(wxString s_branch_id, wxString s_group_id)
{
    wxString str_sql = "select employee_id from s_cm_branch_rel where branch_id ='"+s_branch_id+wxT("' and \
                        group_id = '")+s_group_id+wxT("';");

    wxPostgreSQLresult * _res =  wxGetApp().app_sql_select(str_sql);

    if (_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return wxEmptyString;
    }

    int i_count = _res->GetRowsNumber();

    wxString str=wxEmptyString;

    if(i_count>0)
    {
        _res->MoveFirst();
        str = _res->GetVal(wxT("employee_id"));

    }

    return str;
}

void project_review_author_panel::OnButton_RETURNClick(wxCommandEvent & event)
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
    wxString str_task_id, str_workflow_id, str_flow_ser,str_head;
    wxArrayString array_steps;

    t_template = get_template_action(wf_str_review);

 //   int i_count =0;
    int i_status;
    wxString s_wf_status,s_wbs;

    for ( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if (tlc_task_list->GetItemParent(sel_item)==root&&sel_item.IsOk())
        {
            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_task_list->GetFirstChild(sel_item,cookie);

            bool b_step = true;


            str_task_id = tlc_task_list->GetItemText(sel_item, 1);
            str_workflow_id = wf_str_review;

            str_head = tlc_task_list->GetItemText(sel_item, 0);


            while(child_item.IsOk())
            {
                s_wbs = tlc_task_list->GetItemText(child_item,0);
                i_status = prj_str_to_status(tlc_task_list->GetItemText(child_item, 13));//20150813


                if(b_step)
                {
                    str_flow_ser = tlc_task_list->GetItemText(child_item, 19);
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
                    array_steps.Clear();
                }

                start_mils = wxGetLocalTimeMillis();
                wf_active = new wf_operator(s_wbs, str_workflow_id, t_template);
                wf_active->Feed_back(str_desc, aim_step);

                int i_pos = s_wf_status.Find(wxT("-"));

                s_wf_status= s_wf_status.Left(i_pos);


    //            if (wf_active->update_instance(i_status, s_wf_status))
                 if(update_review_units_status(str_task_id,s_wbs, i_status, s_wf_status))
                {
       //             update_review_units_status(str_task_id,s_wbs, i_status, s_wf_status);
                    wxLogMessage(_("项目:")+s_wbs+_("退回评审任务:")+str_task_id+_("成功!"));
                }


                delete wf_active;


                mils_used = wxGetLocalTimeMillis() - start_mils;

                wxLogMessage(str_task_id+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒"));

                child_item = tlc_task_list->GetNextSibling(child_item);
            }



            tlc_task_list->DeleteChildren(sel_item);
            tlc_task_list->Delete(sel_item);
        }
    }

    delete [] t_template;

}
/*
bool project_review_author_panel::update_review_status(const wxArrayString & array_units, int i_status, wxString s_wf_status)
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

wxArrayString project_review_author_panel::get_steps_info(wxString & s_instance_id, wxString & s_workflow_id, wxString & s_now)
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

void project_review_author_panel::OnButton_REFRESHClick(wxCommandEvent & event)
{
    refresh_list();
    refresh_res_list();
    refresh_group_list();
}

wxString project_review_author_panel::update_issue_context(int i_status, wxString str)
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

void project_review_author_panel::refresh_list()
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
    if (array_group.Index(wxT("G0002")) == wxNOT_FOUND)
        return;
    wxTreeItemId root = tlc_task_list->GetRootItem();
    tlc_task_list->DeleteChildren(root);
    wxString str_sql = wxT("SELECT review_task_id,contract_id,project_name,project_id,require_review_date,res_cm,\
                           (select name from s_employee where employee_id = res_cm) as res_cm_person,review_engineer,urgent_level, start_date, date_trunc('day',start_date) as p_start_date,\
                           (select name from s_employee where employee_id = review_engineer) as review_engineer_name, branch_id,\
                           (select branch_name_cn from s_branch_info where branch_id = v_task_list4.branch_id) as branch_name,status, wf_status, action_id, wbs_no,lift_no,\
                           elevator_type,project_catalog,flow_ser, review_remarks, review_drawing_qty,unit_status, unit_wf_status,\
                           (select concat(issue_status,'-',issue_content,'-',return_content) from s_review_communication where \
                           review_task_id= v_task_list4.review_task_id and issue_status <=2) as com_context FROM v_task_list4 WHERE ") + cl_clause + wxT(" ORDER BY p_start_date, review_task_id, wbs_no ASC;");

    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);
    if (_res->Status() != PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int i_count = _res->GetRowsNumber();
    _res->MoveFirst();
    wxString s_review_task_id, str;
    wxTreeItemId branch_item, leaf_item;
    wxArrayString array_str;
    int i_urgent_level;
    for (int i = 0; i < i_count; i++)
    {
        if (s_review_task_id != _res->GetVal(wxT("review_task_id")))
        {
            str = _res->GetVal(wxT("contract_id")) + _res->GetVal(wxT("project_name")) + wxT("-") + _res->GetVal(wxT("project_id"));
            s_review_task_id = _res->GetVal(wxT("review_task_id"));
            branch_item = tlc_task_list->AppendItem(root, str);
            tlc_task_list->SetItemText(branch_item, 1, s_review_task_id);
            str = DateToStrFormat(_res->GetDateTime(wxT("require_review_date")));
            tlc_task_list->SetItemText(branch_item, 4, str);//20150813
            str = _res->GetVal(wxT("res_cm"));
            tlc_task_list->SetItemText(branch_item, 7, str);//20150813
            str = _res->GetVal(wxT("res_cm_person"));
            tlc_task_list->SetItemText(branch_item, 8, str);//20150813
            str = _res->GetVal(wxT("review_engineer"));
            tlc_task_list->SetItemText(branch_item, 9, str);//20150813
            str = _res->GetVal(wxT("review_engineer_name"));
            tlc_task_list->SetItemText(branch_item, 10, str);//20150813
            str = _res->GetVal(wxT("branch_id"));
            tlc_task_list->SetItemText(branch_item, 11, str);//20150813
            str = _res->GetVal(wxT("branch_name"));
            tlc_task_list->SetItemText(branch_item, 12, str);
            str = prj_status_to_str(_res->GetInt(wxT("unit_status")));
            tlc_task_list->SetItemText(branch_item,13, str);//20150813
            str = _res->GetVal(wxT("unit_wf_status"));
            tlc_task_list->SetItemText(branch_item, 14, str);//20150813
            str = _res->GetVal(wxT("action_id"));
            tlc_task_list->SetItemText(branch_item, 15, str);//20150813

            str = _res->GetVal(wxT("review_drawing_qty"));
            tlc_task_list->SetItemText(branch_item,3, str);

            str = _res->GetVal(wxT("review_remarks"));
            tlc_task_list->SetItemText(branch_item,16, str);

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
            tlc_task_list->SetItemText(branch_item,17, NumToStr(i_review_status));
            tlc_task_list->SetItemText(branch_item,18, str);
        }
        str = _res->GetVal(wxT("wbs_no"));
        leaf_item = tlc_task_list->AppendItem(branch_item, str, -1, -1);
        tlc_task_list->SetItemText(leaf_item, 1, s_review_task_id);
        str = _res->GetVal(wxT("lift_no"));
        tlc_task_list->SetItemText(leaf_item, 2, str);
        str = _res->GetVal(wxT("elevator_type"));
        tlc_task_list->SetItemText(leaf_item, 4, str);//20150813
        str = prj_catalog_to_str(_res->GetInt(wxT("project_catalog")));
        tlc_task_list->SetItemText(leaf_item, 8, str);//20150813

        str = prj_status_to_str(_res->GetInt(wxT("unit_status")));
        tlc_task_list->SetItemText(leaf_item,13, str);//20150813

        str = _res->GetVal(wxT("unit_wf_status"));
        tlc_task_list->SetItemText(leaf_item,14, str);//20150813

        str = _res->GetVal(wxT("action_id"));
        tlc_task_list->SetItemText(leaf_item, 15, str);//20150813

        str = _res->GetVal(wxT("flow_ser"));
        tlc_task_list->SetItemText(leaf_item, 19, str);

        i_urgent_level = _res->GetInt(wxT("urgent_level"));
        tlc_task_list->SetItemText(leaf_item, 20, NumToStr(i_urgent_level));

        str = urgent_level_to_str(i_urgent_level);
        tlc_task_list->SetItemText(leaf_item, 5, str);//20150813

        str = DateToStrShort(_res->GetDateTime(wxT("start_date")));
        tlc_task_list->SetItemText(leaf_item, 6, str);//20150813

        _res->MoveNext();
    }
    _res->Clear();
    refresh_level();
}

void project_review_author_panel::set_treelist_item_color(wxTreeItemId i_id, int i_temp)
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

wxString project_review_author_panel::compare_time(wxString str1, wxString str2, bool b_ser)
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

void project_review_author_panel::refresh_level()
{
    wxTreeItemId root = tlc_task_list->GetRootItem();
    wxTreeItemIdValue cookie;
    wxTreeItemId item = tlc_task_list->GetFirstChild(root, cookie);

    int i_urgent_level, itemp, i_start_date;

    wxArrayString a_lift_no;
    wxString s_lift_no;

    wxString s_status, s_wf_status, str, s_urgent_level, s_start_date, s_start_date2;
    while (item.IsOk())
    {
        i_urgent_level=1;
        i_start_date=0;
        int i_count_leaf = tlc_task_list->GetChildrenCount(item);


        int i_review_status = StrToInt(tlc_task_list->GetItemText(item, 17));

        if(i_review_status==1)
        {
            tlc_task_list->SetItemImage(item, 6);//20150813
        }
        else if(i_review_status == 2)
        {
            tlc_task_list->SetItemImage(item, 7);//20150813
        }
        else
            tlc_task_list->SetItemImage(item, -1);

        wxTreeItemIdValue cookie_child;
        wxTreeItemId child_item = tlc_task_list->GetFirstChild(item,cookie_child);
        while(child_item.IsOk())
        {
            itemp = StrToInt(tlc_task_list->GetItemText(child_item, 20));
            s_lift_no = tlc_task_list->GetItemText(child_item, 2);//20150813
            a_lift_no.Add(s_lift_no);

            set_treelist_item_color(child_item, itemp);

            if(itemp > i_urgent_level)
                i_urgent_level=itemp;

            str = tlc_task_list->GetItemText(child_item, 13);//20150813
            if(!s_status.Contains(str))
            {
                if(s_status.IsEmpty())
                    s_status=str;
                else
                    s_status = s_status+wxT("+")+str;
            }

            str = tlc_task_list->GetItemText(child_item, 14);//20150813

            if(!s_wf_status.Contains(str))
            {
                if(s_wf_status.IsEmpty())
                    s_wf_status=str;
                else
                    s_wf_status= s_wf_status+wxT("+")+str;
            }

            str = tlc_task_list->GetItemText(child_item, 5);//20150813

            if(!s_urgent_level.Contains(str))
            {
                if(s_urgent_level.IsEmpty())
                    s_urgent_level = str;
                else
                    s_urgent_level = s_urgent_level+wxT("+")+str;
            }

            str = tlc_task_list->GetItemText(child_item, 6);//20150813

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
            child_item = tlc_task_list->GetNextSibling(child_item);
        }

        set_treelist_item_color(item, i_urgent_level);

        if(!s_start_date2.IsEmpty())
             s_start_date = compare_time(s_start_date, s_start_date2, true);

        s_lift_no = Combine_lift_no(a_lift_no);
         tlc_task_list->SetItemText(item, 2, NumToStr(i_count_leaf) + _("台[")+s_lift_no+_("]"));
         a_lift_no.Clear();

        tlc_task_list->SetItemText(item, 5,s_urgent_level);//20150813
        tlc_task_list->SetItemText(item, 6, s_start_date);//20150813
        tlc_task_list->SetItemText(item, 13,s_status);//20150813
        tlc_task_list->SetItemText(item, 14, s_wf_status);//20150813

        s_urgent_level.Empty();
        s_start_date.Empty();
        s_status.Empty();
        s_wf_status.Empty();
        s_start_date2.Empty();

        item = tlc_task_list->GetNextSibling(item);
    }
}

void project_review_author_panel::refresh_group_list()
{
    wxTreeItemId root = tlc_group_task_list->GetRootItem();
    tlc_group_task_list->DeleteChildren(root);
    wxString str_sql = wxT("SELECT review_task_id,contract_id,project_name,project_id,require_review_date,res_cm,\
                           (select name from s_employee where employee_id = res_cm) as res_cm_person,operator_id, \
                           (select name from s_employee where employee_id = operator_id) as review_engineer, branch_id,urgent_level, start_date,date_trunc('day',start_date) as p_start_date, \
                           (select branch_name_cn from s_branch_info where branch_id = v_task_list4.branch_id) as branch_name, status, wf_status, action_id, wbs_no,lift_no,\
                           elevator_type,project_catalog, review_remarks, review_drawing_qty,unit_status, unit_wf_status,\
                           (select concat(issue_status,'-',issue_content,'-',return_content) from s_review_communication where \
                           review_task_id= v_task_list4.review_task_id and issue_status <=2) as com_context FROM v_task_list4 WHERE ") + cl_group_clause + wxT(" ORDER BY p_start_date,review_task_id, wbs_no ASC;");
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);
    if (_res->Status() != PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }
    int i_count = _res->GetRowsNumber();
    _res->MoveFirst();
    wxString s_review_task_id, str;
    wxTreeItemId branch_item, leaf_item;
    int i_urgent_level;

    wxArrayString array_str;
    for (int i = 0; i < i_count; i++)
    {
        if (s_review_task_id != _res->GetVal(wxT("review_task_id")))
        {
            str = _res->GetVal(wxT("contract_id")) + _res->GetVal(wxT("project_name")) + wxT("-") + _res->GetVal(wxT("project_id"));
            s_review_task_id = _res->GetVal(wxT("review_task_id"));
            branch_item = tlc_group_task_list->AppendItem(root, str);
            tlc_group_task_list->SetItemText(branch_item, 1, s_review_task_id);
            str = DateToStrFormat(_res->GetDateTime(wxT("require_review_date")));
            tlc_group_task_list->SetItemText(branch_item, 4, str);//20150813
            str = _res->GetVal(wxT("res_cm"));
            tlc_group_task_list->SetItemText(branch_item, 7, str);//20150813
            str = _res->GetVal(wxT("res_cm_person"));
            tlc_group_task_list->SetItemText(branch_item, 8, str);//20150813
            str = _res->GetVal(wxT("operator_id"));
            tlc_group_task_list->SetItemText(branch_item, 9, str);//20150813
            str = _res->GetVal(wxT("review_engineer"));
            tlc_group_task_list->SetItemText(branch_item, 10, str);//20150813
            str = _res->GetVal(wxT("branch_id"));
            tlc_group_task_list->SetItemText(branch_item, 11, str);//20150813
            str = _res->GetVal(wxT("branch_name"));
            tlc_group_task_list->SetItemText(branch_item, 12, str);//20150813
            str = prj_status_to_str(_res->GetInt(wxT("unit_status")));
            tlc_group_task_list->SetItemText(branch_item, 13, str);//20150813
            str = _res->GetVal(wxT("unit_wf_status"));
            tlc_group_task_list->SetItemText(branch_item, 14, str);//20150813

            str = _res->GetVal(wxT("review_drawing_qty"));
            tlc_group_task_list->SetItemText(branch_item,3, str);//20150813

            str = _res->GetVal(wxT("review_remarks"));
            tlc_group_task_list->SetItemText(branch_item,16, str);

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
            tlc_group_task_list->SetItemText(branch_item,17, NumToStr(i_review_status));
            tlc_group_task_list->SetItemText(branch_item,18, str);
        }
        str = _res->GetVal(wxT("wbs_no"));
        leaf_item = tlc_group_task_list->AppendItem(branch_item, str, -1, -1);
        tlc_group_task_list->SetItemText(leaf_item, 1, s_review_task_id);
        str = _res->GetVal(wxT("lift_no"));
        tlc_group_task_list->SetItemText(leaf_item, 2, str);
        str = _res->GetVal(wxT("elevator_type"));
        tlc_group_task_list->SetItemText(leaf_item, 4, str);//20150813
        str = prj_catalog_to_str(_res->GetInt(wxT("project_catalog")));
        tlc_group_task_list->SetItemText(leaf_item, 8, str);//20150813

        str = prj_status_to_str(_res->GetInt(wxT("unit_status")));
        tlc_group_task_list->SetItemText(leaf_item,13, str);//20150813

        str = _res->GetVal(wxT("unit_wf_status"));
        tlc_group_task_list->SetItemText(leaf_item,14, str);//20150813

        str = _res->GetVal(wxT("action_id"));
        tlc_group_task_list->SetItemText(leaf_item, 15, str);//20150813

        i_urgent_level = _res->GetInt(wxT("urgent_level"));
        tlc_group_task_list->SetItemText(leaf_item, 19, NumToStr(i_urgent_level));

        str = urgent_level_to_str(i_urgent_level);
        tlc_group_task_list->SetItemText(leaf_item, 5, str);//20150813

        str = DateToStrShort(_res->GetDateTime(wxT("start_date")));
        tlc_group_task_list->SetItemText(leaf_item, 6, str);//20150813

        _res->MoveNext();
    }
    _res->Clear();
    refresh_group_level();
}

void project_review_author_panel::refresh_group_level()
{
    wxTreeItemId root = tlc_group_task_list->GetRootItem();
    wxTreeItemIdValue cookie;
    wxTreeItemId item = tlc_group_task_list->GetFirstChild(root, cookie);

    int i_urgent_level, itemp, i_start_date;

    wxString s_status, s_wf_status, str, s_urgent_level, s_start_date, s_start_date2;
    wxArrayString a_lift_no;
    wxString s_lift_no;

    while (item.IsOk())
    {

        i_urgent_level=1;
        i_start_date=0;


        int i_count_leaf = tlc_group_task_list->GetChildrenCount(item);


        int i_review_status = StrToInt(tlc_group_task_list->GetItemText(item, 17));

        if(i_review_status==1)
        {
            tlc_group_task_list->SetItemImage(item, 5);
        }
        else if(i_review_status == 2)
        {
            tlc_group_task_list->SetItemImage(item, 6);
        }
        else
            tlc_group_task_list->SetItemImage(item, -1);

        wxTreeItemIdValue cookie_child;
        wxTreeItemId child_item = tlc_group_task_list->GetFirstChild(item, cookie_child);
       while(child_item.IsOk())
        {
            itemp = StrToInt(tlc_group_task_list->GetItemText(child_item, 19));
            s_lift_no = tlc_group_task_list->GetItemText(child_item, 2);
            a_lift_no.Add(s_lift_no);

            set_treelist_item_color(child_item, itemp);

            if(itemp > i_urgent_level)
                i_urgent_level=itemp;

            str = tlc_group_task_list->GetItemText(child_item, 13);//20150813
            if(!s_status.Contains(str))
            {
                if(s_status.IsEmpty())
                    s_status=str;
                else
                    s_status = s_status+wxT("+")+str;
            }

            str = tlc_group_task_list->GetItemText(child_item, 14);//20150813

            if(!s_wf_status.Contains(str))
            {
                if(s_wf_status.IsEmpty())
                    s_wf_status=str;
                else
                    s_wf_status= s_wf_status+wxT("+")+str;
            }

            str = tlc_group_task_list->GetItemText(child_item, 5);//20150813

            if(!s_urgent_level.Contains(str))
            {
                if(s_urgent_level.IsEmpty())
                    s_urgent_level = str;
                else
                    s_urgent_level = s_urgent_level+wxT("+")+str;
            }

            str = tlc_group_task_list->GetItemText(child_item, 6);//20150813

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
            child_item = tlc_group_task_list->GetNextSibling(child_item);
        }

        set_treelist_item_color(item, i_urgent_level);

        if(!s_start_date2.IsEmpty())
             s_start_date = compare_time(s_start_date, s_start_date2, true);

            s_lift_no = Combine_lift_no(a_lift_no);

        tlc_group_task_list->SetItemText(item, 2, NumToStr(i_count_leaf) + _("台[")+s_lift_no+_("]"));
        a_lift_no.Clear();

        tlc_group_task_list->SetItemText(item, 5,s_urgent_level);//20150813
        tlc_group_task_list->SetItemText(item, 6, s_start_date);//20150813
        tlc_group_task_list->SetItemText(item, 13,s_status);//20150813
        tlc_group_task_list->SetItemText(item, 14, s_wf_status);//20150813

        s_urgent_level.Empty();
        s_start_date.Empty();
        s_status.Empty();
        s_wf_status.Empty();
        s_start_date2.Empty();


        item = tlc_group_task_list->GetNextSibling(item);
    }
}

void project_review_author_panel::Onlv_personItemRClick(wxListEvent & event)
{
    PopupMenu(&menu_check, ScreenToClient(wxGetMousePosition()));
}

void project_review_author_panel::OnTaskListRightClick(wxTreeEvent & event)
{
      PopupMenu(&menu_author, ScreenToClient(wxGetMousePosition()));
}

void project_review_author_panel::OnGroupTaskListRightClick(wxTreeEvent& event)
{
      PopupMenu(&menu_filter, ScreenToClient(wxGetMousePosition()));
}

void project_review_author_panel::Onmi_expandSelected(wxCommandEvent & event)
{
    wxTreeItemId root = tlc_task_list->GetRootItem();
    tlc_task_list->ExpandAll(root);
}

void project_review_author_panel::Onmi_collapseSelected(wxCommandEvent & event)
{
    wxTreeItemId root = tlc_task_list->GetRootItem();
    wxTreeItemIdValue cookie;
    wxTreeItemId item = tlc_task_list->GetFirstChild(root, cookie);
    while (item.IsOk())
    {
        tlc_task_list->Collapse(item);
        item = tlc_task_list->GetNextSibling(item);
    }
}

void project_review_author_panel::Onmi_show_allSelected(wxCommandEvent & event)
{
    if (!event.IsChecked())
    {
        mi_show_all->Check(true);
        return;
    }
    wxString strSql = wxT(" operator_id = '") + gr_para.login_user + wxT("' and is_active = true and (action_id = 'AT00000002' OR action_id ='AT00000025' OR action_id='AT00000026') and unit_status>=0 and is_latest=true ");
    set_clause(strSql);
    refresh_list();
    mi_show_all->Check(true);
    mi_show_author->Check(false);
    mi_check->Check(false);
    mi_review->Check(false);
}

void project_review_author_panel::Onmi_show_authorSelected(wxCommandEvent & event)
{
    if (!event.IsChecked())
    {
        mi_show_author->Check(true);
        return;
    }
    wxString strSql = wxT(" operator_id = '") + gr_para.login_user + wxT("' and is_active = true and action_id = 'AT00000002' and unit_status>=0 and is_latest=true  ");
    set_clause(strSql);
    refresh_list();
    mi_show_all->Check(false);
    mi_show_author->Check(true);
    mi_check->Check(false);
    mi_review->Check(false);
}

void project_review_author_panel::Onmi_reviewSelected(wxCommandEvent & event)
{
    if (!event.IsChecked())
    {
        mi_review->Check(true);
        return;
    }
    wxString strSql = wxT(" operator_id = '") + gr_para.login_user + wxT("' and is_active = true and action_id ='AT00000025' and unit_status>=0 and is_latest=true ");
    set_clause(strSql);
    refresh_list();
    mi_show_all->Check(false);
    mi_show_author->Check(false);
    mi_check->Check(false);
    mi_review->Check(true);
}

void project_review_author_panel::Onmi_checkSelected(wxCommandEvent & event)
{
    if (!event.IsChecked())
    {
        mi_check->Check(true);
        return;
    }
    wxString strSql = wxT(" operator_id = '") + gr_para.login_user + wxT("' and is_active = true and  action_id='AT00000026' and unit_status>=0 and is_latest=true ");
    set_clause(strSql);
    refresh_list();
    mi_show_all->Check(false);
    mi_show_author->Check(false);
    mi_check->Check(true);
    mi_review->Check(false);
}

void project_review_author_panel::Onmi_no_checkSelected(wxCommandEvent & event)
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


    long l_item = -1;
    l_item = lv_person->GetNextItem(l_item,  wxLIST_NEXT_ALL,  wxLIST_STATE_SELECTED);

    if (l_item == -1)
    {
        wxLogMessage(_("请选择操作人员！"));
        return;
    }

    wxString s_engineer = lv_person->GetItemText(l_item,0);

    wxString s_name = lv_person->GetItemText(l_item, 1);

    wxString s_status = lv_person->GetItemText(l_item, 4);//20150813

    if (s_status==wxT("Y"))
    {
        wxLogMessage(_("本身就是免审，无需设置!"));
        return;
    }


    wxString str_sql = wxT("UPDATE s_group_member SET no_check =true ,modify_date = '")+DateToAnsiStr(wxDateTime::Now())+wxT("',modify_emp_id = '")+
                       gr_para.login_user+wxT("' WHERE employee_id ='")+s_engineer+wxT("' and group_id='G0002';");

    if (wxGetApp().app_sql_update(str_sql))
    {
        wxLogMessage(_("评审工程师:")+s_name+_("已经成功设置成免审!"));
    }

    refresh_res_list();
}

void project_review_author_panel::Onmi_cancel_no_checkSelected(wxCommandEvent & event)
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


    long l_item = -1;
    l_item = lv_person->GetNextItem(l_item,  wxLIST_NEXT_ALL,  wxLIST_STATE_SELECTED);

    if (l_item == -1)
    {
        wxLogMessage(_("请选择操作人员！"));
        return;
    }

    wxString s_engineer = lv_person->GetItemText(l_item,0);

    wxString s_name = lv_person->GetItemText(l_item, 1);

    wxString s_status = lv_person->GetItemText(l_item, 4);//20150813

    if (s_status.IsEmpty())
    {
        wxLogMessage(_("本身就是非免审，无需取消!"));
        return;
    }


    if (s_engineer == gr_para.login_user)
    {
        wxLogMessage(_("评审负责人无法取消免审!"));
        return;
    }


    wxString str_sql = wxT("UPDATE s_group_member SET no_check =false ,modify_date = '")+DateToAnsiStr(wxDateTime::Now())+wxT("',modify_emp_id = '")+
                       gr_para.login_user+wxT("' WHERE employee_id ='")+s_engineer+wxT("' and group_id='G0002';");

    if (wxGetApp().app_sql_update(str_sql))
    {
        wxLogMessage(_("评审工程师:")+s_name+_("已经成功取消免审!"));
    }

    refresh_res_list();
}

void project_review_author_panel::Onmi_filterSelected(wxCommandEvent & event)
{
    wxString str_group,str_user;
    str_group = wxGetApp().get_only_group();
    wxArrayString  s_members = wxGetApp().get_member_in_group(str_group);

/*
    wxTreeItemId root = tlc_task_list->GetRootItem();
    if(tlc_group_task_list->GetChildrenCount(root)==0)
        return;*/

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

    wxString str = wxT(" is_active = true and active_status>=1 and action_id = 'AT00000025' and operator_id ='") + str_user + wxT("' and unit_status>=0  and is_latest=true");
    set_group_clause(str);
    refresh_group_list();
}

void project_review_author_panel::Onlv_personItemActivated(wxListEvent & event)
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
    wxListItem li_item = event.GetItem();
    li_item.m_col = 0;
    wxString s_engineer = li_item.GetText();
    wxString str = wxT(" is_active = true and active_status>=1 and action_id = 'AT00000025' and operator_id ='") + s_engineer + wxT("' and unit_status>=0 and is_latest=true ");
    set_group_clause(str);
    refresh_group_list();
}

void project_review_author_panel::Onbutton_groupClick(wxCommandEvent & event)
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
    wxString str = wxT(" is_active = true and (action_id = 'AT00000025' or action_id = 'AT00000026') ");
    set_group_clause(str);
    refresh_group_list();
}

bool project_review_author_panel::update_review_task(const wxString s_task_id, int i_status)
{
    wxString str_sql = wxT("UPDATE s_review_info SET  modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("',active_status=")+NumToStr(i_status)+wxT(" WHERE \
                        review_task_id='")+s_task_id+wxT("';");
    return wxGetApp().app_sql_update(str_sql);
}

void project_review_author_panel::OnButton_FeedbackClick(wxCommandEvent & event)
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
    wxString str_action_id;
    wxString str_engineer;
    wxString str_context;

 //   communication_dlg dlg;

    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item)==root)
        {
            str_status =  tlc_task_list->GetItemText(sel_item, 17);
            str_context = tlc_task_list->GetItemText(sel_item, 18);
            str_task_id = tlc_task_list->GetItemText(sel_item, 1);
            str_action_id = tlc_task_list->GetItemText(sel_item, 15);//20150813
            str_engineer = tlc_task_list->GetItemText(sel_item, 9);//20150813


            if(str_action_id != wxT("AT00000025")&&str_engineer.IsEmpty())
            {
                wxLogMessage(_("评审任务尚未授权,无法提交issue!"));
                continue;
            }


            if(str_status==wxT("1"))
            {
                wxLogMessage(_("正在等待分公司反馈!"));
                continue;
            }

            if(str_status == wxT("2") || str_status.IsEmpty())
            {

                if(create_communication(str_task_id, str_status, str_context))
                {
                    tlc_task_list->SetItemText(sel_item, 17, str_status);
                    str_context = update_issue_context(wxAtoi(str_status),str_context);
                    tlc_task_list->SetItemText(sel_item, 18, str_context);

                }

            }

        }
    }

    refresh_level();
}

bool project_review_author_panel::create_communication(wxString s_task_id, wxString &s_status, wxString &s_context, bool b_close)
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


//        dlg.b_show=false;
 //       dlg.show_control();

        if(dlg.ShowModal()==wxID_OK)
        {
//           str_status = wxT("1");
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
            s_status = wxT("1");
            s_context = dlg.m_content;
        }

        return b_result;
    }

    return true;

}

void project_review_author_panel::InitImageList()
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

bool project_review_author_panel::update_review_units_status(const wxString s_task_id, const wxString s_wbs_no, int i_status, wxString s_wf_status)
{

    wxString str_sql = wxT("UPDATE s_review_units SET unit_status =")+NumToStr(i_status)+wxT(",unit_wf_status='")+s_wf_status+wxT("',modify_date = '")+DateToAnsiStr(wxDateTime::Now())+
                       wxT("',modify_emp_id = '")+gr_para.login_user+wxT("' WHERE review_task_id ='")+ s_task_id+wxT("' and  wbs_no ='")+s_wbs_no+wxT("';");


    return wxGetApp().app_sql_update(str_sql);
}

void project_review_author_panel::OnButton_RequireClick(wxCommandEvent& event)
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

    if(!mi_show_author->IsCheck())
    {
        wxMessageBox(_("请右键切换到待授权界面,设置评审要求完成日期!"),_("提示"),wxOK);
        wxLogMessage(_("请右键切换到待授权界面,设置评审要求完成日期!"));
        return;
    }

    mydatepicker dlg;

    wxString s_date,s_date_ex;

    if(dlg.ShowModal()==wxID_OK)
    {
        s_date = dlg.GetString();
    }else
        return;

    s_date_ex = s_date + wxT(" 23:00:00");

    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_task_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_task_list->GetSelections( items );

    if(items.IsEmpty())
    {
        wxLogMessage(_("请选择任务！"));
        return;
    }

    wxString str_task_id;


    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if (tlc_task_list->GetItemParent(sel_item)==root&&sel_item.IsOk())
        {
             str_task_id = tlc_task_list->GetItemText(sel_item, 1);

             if(update_require_review_finish(str_task_id, s_date_ex))
                tlc_task_list->SetItemText(sel_item, 4, s_date);//20150813
        }
    }

}

bool project_review_author_panel::update_require_review_finish(wxString s_task_id, wxString s_date)
{
    wxString str_sql = wxT("UPDATE s_review_info SET require_review_date ='")+s_date+wxT("',modify_date = '")+DateToAnsiStr(wxDateTime::Now())+
                       wxT("',modify_emp_id = '")+gr_para.login_user+wxT("' WHERE review_task_id ='")+ s_task_id+wxT("';");

    return wxGetApp().app_sql_update(str_sql);
}

void project_review_author_panel::OnButton_Draw_qtyClick(wxCommandEvent& event)
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
            str_draw_qty = tlc_task_list->GetItemText(sel_item, 3);//20150813

            wxTextEntryDialog tdlg(this, _("请输入新的图纸套数"), _("图纸套数变更"), str_draw_qty, wxTextEntryDialogStyle, wxDefaultPosition);
            tdlg.SetTextValidator(wxFILTER_DIGITS);
            if (tdlg.ShowModal() == wxID_CANCEL)
                return;

            str_draw_qty = tdlg.GetValue();

            if(update_drawing_qty(str_task_id, str_draw_qty))
                tlc_task_list->SetItemText(sel_item, 3, str_draw_qty);//20150813
        }
    }


}

bool project_review_author_panel::update_drawing_qty(wxString s_task_id, wxString s_drawing_qty)
{
    wxString str_sql = wxT("UPDATE s_review_info SET review_drawing_qty =")+s_drawing_qty+wxT(",modify_date = '")+DateToAnsiStr(wxDateTime::Now())+
                       wxT("',modify_emp_id = '")+gr_para.login_user+wxT("' WHERE review_task_id ='")+ s_task_id+wxT("';");

    return wxGetApp().app_sql_update(str_sql);
}

void project_review_author_panel::OnButton_return_to_startClick(wxCommandEvent& event)
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
    wxString s_action_id;
    if (items.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }


    if(wxMessageBox(_("确认退回到待启动状态?"),_("确认"),wxYES_NO)!=wxYES)
    {
        return;
    }

    wxString str_task_id,s_wbs;

    int i_status, i_old_status, i_times;

    for ( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if (tlc_task_list->GetItemParent(sel_item)==root&&sel_item.IsOk())
        {
            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_task_list->GetFirstChild(sel_item,cookie);


            str_task_id = tlc_task_list->GetItemText(sel_item, 1);

            while(child_item.IsOk())
            {
                s_wbs = tlc_task_list->GetItemText(child_item,0);
                s_action_id = tlc_task_list->GetItemText(child_item, 15);//20150813

                if(s_action_id!= wxT("AT00000002"))
                {
                    wxLogMessage(_("仅待授权状态的项目可以退回到待启动状态!"));
                    wxLogMessage(s_wbs+_("已经授权，无法退回到待启动状态!"));
                    child_item = tlc_task_list->GetNextSibling(child_item);
                    continue;
                }

                check_review_restart_status(s_wbs,i_times,i_old_status,i_status);
                if(cancel_review_workflow(str_task_id, s_wbs, i_old_status, i_times-1))
                {
                    wxLogMessage(_("项目:")+s_wbs+_("退回到待启动状态成功!"));
                }


                child_item = tlc_task_list->GetNextSibling(child_item);
            }

            if(close_cancel_review_task(str_task_id))
                tlc_task_list->DeleteChildren(sel_item);
            tlc_task_list->Delete(sel_item);
        }
    }
}


bool project_review_author_panel::check_review_restart_status(wxString s_instance, int &i_times, int &i_old_status,int &i_status)
{
    bool b_active=false;

    wxString str_sql = wxT("select count(*) as count from s_review_units where wbs_no = '")+s_instance +wxT("' and is_del = false and unit_status<>-1 and unit_status<>-2; ");

    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return false;
    }

    i_times = _res->GetInt(wxT("count"));

    _res->Clear();

    if(i_times >1)
        b_active = true;

    str_sql = wxT("select unit_old_status, unit_status from s_review_units where wbs_no = '")+s_instance+wxT("' and is_del=false and is_latest=true;");
    _res = wxGetApp().app_sql_select(str_sql);
    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return false;
    }

    int i_count =_res->GetRowsNumber();

    if(i_count >0)
    {
        i_old_status = _res->GetInt(wxT("unit_old_status"));
        i_status = _res->GetInt(wxT("unit_status"));
    }else
    {
        i_old_status = 0;
        i_status = -1;
    }


    return b_active;
}

bool project_review_author_panel::cancel_review_workflow(wxString s_task_id, wxString s_instance, int i_old_status,int i_times)
{
    bool b_sus=true;
    v_wf_action * t_template=NULL;
    wf_operator * wf_review;

    if(i_old_status !=0 && i_times>0)
    {
        t_template = get_template_action(wf_str_review);
        wf_review = new wf_operator(s_instance, wf_str_review, t_template);
        wf_review->cancel_restart(i_times,wf_str_review);
        wf_review->update_instance(i_old_status);
        delete wf_review;
        wf_review = NULL;
    }

    if (t_template)
        delete [] t_template;

    wxString s_sql = wxT("UPDATE s_review_units SET is_del=true, modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+
    wxT("' where review_task_id='")+s_task_id+wxT("' and wbs_no ='")+s_instance+wxT("';");

    b_sus = wxGetApp().app_sql_update(s_sql);

  //  s_sql = wxT("UPDATE s_unit_info SET status =")+NumToStr(i_old_status)+wxT(" ,modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+
  //  wxT("' where wbs_no='")+s_instance+wxT("';");

  //  return b_sus&&wxGetApp().app_sql_update(s_sql);
  return b_sus;
}

bool project_review_author_panel::close_cancel_review_task(wxString s_task_id)
{
    wxString s_sql = wxT("SELECT count(*) as count from s_review_units where review_task_id='")+s_task_id+wxT("' and is_del=false;");
    wxPostgreSQLresult* _res = wxGetApp().app_sql_select(s_sql);
    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return false;
    }

    int i_count = _res->GetInt(wxT("count"));

    _res->Clear();

    if(i_count >0)
    {

        return false;
    }

    s_sql = wxT("UPDATE s_review_info SET active_status=-1 where review_task_id='")+s_task_id+wxT("';");

    return wxGetApp().app_sql_update(s_sql);
}

void project_review_author_panel::Onmi_com_logSelected(wxCommandEvent& event)
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

void project_review_author_panel::Onmi_group_com_logSelected(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }


    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_group_task_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_group_task_list->GetSelections( items );

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
        if(tlc_group_task_list->GetItemParent(sel_item)==root)
        {
            str = tlc_group_task_list->GetItemText(sel_item, 1);
            if(a_task_id.Index(str)==wxNOT_FOUND)
            {
                a_task_id.Add(str);

                str = tlc_group_task_list->GetItemText(sel_item, 0);
                a_info.Add(str);

            }

        }else
        {
            wxTreeItemId parent_id = tlc_group_task_list->GetItemParent(sel_item);

            str = tlc_group_task_list->GetItemText(parent_id, 1);

            if(a_task_id.Index(str)==wxNOT_FOUND)
            {
                a_task_id.Add(str);

                str = tlc_group_task_list->GetItemText(parent_id, 0);
                a_info.Add(str);

            }
        }

    }

    review_communication_log l_dlg;

    l_dlg.refresh_list(a_task_id, a_info);

    l_dlg.ShowModal();
}

void project_review_author_panel::Onmi_showallSelected(wxCommandEvent& event)
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
    wxString str = wxT(" is_active = true and (action_id = 'AT00000025' or action_id = 'AT00000026') ");
    set_group_clause(str);
    refresh_group_list();
}

void project_review_author_panel::Onmi_processSelected(wxCommandEvent& event)
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

void project_review_author_panel::Onmi_historySelected(wxCommandEvent& event)
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

void project_review_author_panel::Onmi_posSelected(wxCommandEvent& event)
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

void project_review_author_panel::Onmi_group_processSelected(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }


    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_group_task_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_group_task_list->GetSelections( items );

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
        if(tlc_group_task_list->GetItemParent(sel_item)==root)
        {
            wxTreeItemIdValue cookie_child;
            wxTreeItemId child_item = tlc_group_task_list->GetFirstChild(sel_item,cookie_child);
            while(child_item.IsOk())
            {
                str = tlc_group_task_list->GetItemText(child_item,0);
                if(a_wbs.Index(str)==wxNOT_FOUND)
                {
                    a_wbs.Add(str);
                }

                child_item= tlc_group_task_list->GetNextSibling(child_item);
            }


        }else
        {

            str = tlc_group_task_list->GetItemText(sel_item, 0);

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

void project_review_author_panel::Onmi_group_review_historySelected(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }


    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_group_task_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_group_task_list->GetSelections( items );

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
        if(tlc_group_task_list->GetItemParent(sel_item)==root)
        {
            wxTreeItemIdValue cookie_child;
            wxTreeItemId child_item = tlc_group_task_list->GetFirstChild(sel_item,cookie_child);
            while(child_item.IsOk())
            {
                str = tlc_group_task_list->GetItemText(child_item,0);
                if(a_wbs.Index(str)==wxNOT_FOUND)
                {
                    a_wbs.Add(str);
                }

                child_item= tlc_group_task_list->GetNextSibling(child_item);
            }


        }else
        {

            str = tlc_group_task_list->GetItemText(sel_item, 0);

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

void project_review_author_panel::Onmi_group_posSelected(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }

    wxString str;

    m_pos_id_group = tlc_group_task_list->GetRootItem();

    wxTextEntryDialog tdlg(this, _("请输入合同号或WBS NO"), _("组员任务快速查找"), wxT(""), wxOK | wxCANCEL, wxDefaultPosition);
    if (tdlg.ShowModal() == wxID_OK)
    {
        m_search_case_group = tdlg.GetValue();
    }
    else
    {
        return;
    }

    if(m_search_case_group.IsEmpty())
        return;

    m_pos_id_group = search_in_treelist(tlc_group_task_list, m_pos_id_group,m_search_case_group,0);
}

void project_review_author_panel::OnChar(wxTreeEvent& event)
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

    case WXK_CONTROL_D:
          if(m_search_case_group.IsEmpty())
            break;
          m_pos_id_group = search_in_treelist(tlc_group_task_list,m_pos_id_group, m_search_case_group,0);
    default:
        break;
    }

    event.Skip();

}
