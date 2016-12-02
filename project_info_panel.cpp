#include "project_info_panel.h"
#include "wfApp.h"
#include <wx/tokenzr.h>
#include <wx/clipbrd.h>

#include "communication_dlg.h"
#include "review_remarks_dlg.h"
#include "review_communication_log.h"
#include "return_log.h"
#include "ins_proc_log.h"
#include <wx/textdlg.h>
#include "datepickerdlg.h"

//(*InternalHeaders(project_info_panel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(project_info_panel)
const long project_info_panel::ID_BUTTON_FEEDBACK = wxNewId();
const long project_info_panel::ID_BUTTON2 = wxNewId();
const long project_info_panel::ID_BUTTON1 = wxNewId();
const long project_info_panel::ID_BUTTON_GAD_REVISED = wxNewId();
const long project_info_panel::ID_BUTTON3 = wxNewId();
const long project_info_panel::ID_CHOICE_STATUS = wxNewId();
const long project_info_panel::ID_CHOICE_ACTION = wxNewId();
const long project_info_panel::idMenu_communication_log = wxNewId();
const long project_info_panel::idMenu_Return_info = wxNewId();
const long project_info_panel::idMenu_process = wxNewId();
const long project_info_panel::idMenu_Change_res = wxNewId();
const long project_info_panel::idMenu_common = wxNewId();
const long project_info_panel::idMenu_Urgent = wxNewId();
const long project_info_panel::idMenu_Special = wxNewId();
const long project_info_panel::idMenu_remarks = wxNewId();
const long project_info_panel::idMenu_pos_contract = wxNewId();
const long project_info_panel::idMenu_export_start = wxNewId();
const long project_info_panel::idMenu_Review_date = wxNewId();
const long project_info_panel::idMenu_Review_all = wxNewId();
//*)
const long project_info_panel::ID_TREELISTCTRL_TASK_LIST = wxNewId();

BEGIN_EVENT_TABLE(project_info_panel,wxPanel)
	//(*EventTable(project_info_panel)
	//*)
END_EVENT_TABLE()

project_info_panel::project_info_panel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(project_info_panel)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button_Feedback = new wxButton(this, ID_BUTTON_FEEDBACK, _("分公司问题传递"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_FEEDBACK"));
	BoxSizer2->Add(Button_Feedback, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("评审任务清理"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button2->SetFocus();
	Button2->Hide();
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("立项状态项目启动"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button4 = new wxButton(this, ID_BUTTON_GAD_REVISED, _("SPEC或GAD修改任务启动"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_GAD_REVISED"));
	BoxSizer2->Add(Button4, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button3 = new wxButton(this, ID_BUTTON3, _("刷新任务清单"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer2->Add(Button3, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	choice_status = new wxChoice(this, ID_CHOICE_STATUS, wxDefaultPosition, wxSize(110,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_STATUS"));
	choice_status->SetSelection( choice_status->Append(_("本人工作流内项目")) );
	choice_status->Append(_("其他人的项目(按人选)"));
	choice_status->Append(_("其他人的项目(所有)"));
	choice_status->Append(_("评审完成等待PO的项目"));
	choice_status->Append(_("待排产项目"));
	BoxSizer2->Add(choice_status, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	choice_action = new wxChoice(this, ID_CHOICE_ACTION, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_ACTION"));
	choice_action->SetSelection( choice_action->Append(_("All")) );
	choice_action->Append(_("合同立项"));
	choice_action->Append(_("评审授权"));
	choice_action->Append(_("项目评审"));
	choice_action->Append(_("评审审核"));
	choice_action->Append(_("线下PO确认"));
	choice_action->Append(_("PO确认完成"));
	BoxSizer2->Add(choice_action, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_LEFT, 0);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("评审任务清单"));
	BoxSizer1->Add(StaticBoxSizer1, 6, wxALL|wxEXPAND, 0);
	SetSizer(BoxSizer1);
	MenuItem1 = new wxMenuItem((&menu_review_info), idMenu_communication_log, _("问题传递log(&L)"), _("问题传递log"), wxITEM_NORMAL);
	menu_review_info.Append(MenuItem1);
	MenuItem3 = new wxMenuItem((&menu_review_info), idMenu_Return_info, _("退回信息(&F)"), _("退回信息"), wxITEM_NORMAL);
	menu_review_info.Append(MenuItem3);
	mi_process = new wxMenuItem((&menu_review_info), idMenu_process, _("项目评审流程信息(R)"), _("项目评审流程信息"), wxITEM_NORMAL);
	menu_review_info.Append(mi_process);
	mi_cm_res = new wxMenuItem((&menu_review_info), idMenu_Change_res, _("变更合同商务负责人(&M)"), _("变更合同商务负责人"), wxITEM_NORMAL);
	menu_review_info.Append(mi_cm_res);
	menu_review_info.AppendSeparator();
	mi_common = new wxMenuItem((&menu_review_info), idMenu_common, _("普通级(紧急程度)(&C)"), _("普通级(紧急程度)"), wxITEM_NORMAL);
	menu_review_info.Append(mi_common);
	mi_urgent = new wxMenuItem((&menu_review_info), idMenu_Urgent, _("紧急项目(&U)"), _("紧急项目"), wxITEM_NORMAL);
	menu_review_info.Append(mi_urgent);
	mi_special = new wxMenuItem((&menu_review_info), idMenu_Special, _("特紧急项目(&S)"), _("特紧急项目"), wxITEM_NORMAL);
	menu_review_info.Append(mi_special);
	menu_review_info.AppendSeparator();
	mi_remarks = new wxMenuItem((&menu_review_info), idMenu_remarks, _("备注更新(&R)"), wxEmptyString, wxITEM_NORMAL);
	menu_review_info.Append(mi_remarks);
	menu_review_info.AppendSeparator();
	mi_pos_contract = new wxMenuItem((&menu_review_info), idMenu_pos_contract, _("快速定位(&P)\tCtrl+F"), _("快速定位"), wxITEM_NORMAL);
	menu_review_info.Append(mi_pos_contract);
	menu_review_info.AppendSeparator();
	mi_start = new wxMenuItem((&menu_review_info), idMenu_export_start, _("按项目启动日期搜索(&Q)"), _("按项目启动日期搜索("), wxITEM_NORMAL);
	menu_review_info.Append(mi_start);
	mi_author = new wxMenuItem((&menu_review_info), idMenu_Review_date, _("按评审授权日期搜索(&A)"), _("按评审授权日期搜索"), wxITEM_NORMAL);
	menu_review_info.Append(mi_author);
	mi_review_all = new wxMenuItem((&menu_review_info), idMenu_Review_all, _("所有评审项目记录"), _("所有评审项目记录"), wxITEM_NORMAL);
	menu_review_info.Append(mi_review_all);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON_FEEDBACK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&project_info_panel::OnButton_FeedbackClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&project_info_panel::OnButton2Click);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&project_info_panel::OnButton1Click);
	Connect(ID_BUTTON_GAD_REVISED,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&project_info_panel::OnButton4Click);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&project_info_panel::OnButton3Click);
	Connect(ID_CHOICE_STATUS,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&project_info_panel::Onchoice_statusSelect);
	Connect(ID_CHOICE_ACTION,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&project_info_panel::Onchoice_actionSelect);
	Connect(idMenu_communication_log,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_info_panel::OnMenuItem1Selected);
	Connect(idMenu_Return_info,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_info_panel::OnMenuItem3Selected);
	Connect(idMenu_process,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_info_panel::Onmi_processSelected);
	Connect(idMenu_Change_res,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_info_panel::Onmi_cm_resSelected);
	Connect(idMenu_common,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_info_panel::Onmi_commonSelected);
	Connect(idMenu_Urgent,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_info_panel::Onmi_urgentSelected);
	Connect(idMenu_Special,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_info_panel::Onmi_specialSelected);
	Connect(idMenu_remarks,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_info_panel::Onmi_remarksSelected);
	Connect(idMenu_pos_contract,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_info_panel::Onmi_smart_posSelected);
	Connect(idMenu_export_start,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_info_panel::Onmi_startSelected);
	Connect(idMenu_Review_date,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_info_panel::Onmi_authorSelected);
	Connect(idMenu_Review_all,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&project_info_panel::Onmi_review_allSelected);
	//*)

	BuildDataViewCtrl();
    StaticBoxSizer1->Add(tlc_task_list, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0 );
    Layout();

    Connect(ID_TREELISTCTRL_TASK_LIST,wxEVT_COMMAND_TREE_ITEM_MENU,(wxObjectEventFunction)&project_info_panel::OnTreeListCtrlRightClick);
    Connect(ID_TREELISTCTRL_TASK_LIST,wxEVT_COMMAND_TREE_KEY_DOWN ,(wxObjectEventFunction)&project_info_panel::OnChar);


    wxArrayString array_group = wxGetApp().get_group();
    bool is_leader = false;
    wxString str;

    m_report = 0;

    if(array_group.Index(wxT("G0001"))!=wxNOT_FOUND  )
    {
        Button1->Show(true);
        Button4->Show(true);
        Button_Feedback->Show(true);
        choice_status->Show(true);

        is_leader = wxGetApp().is_leader(wxT("G0001"));
        if(is_leader)
        {
            mi_urgent->Enable(true);
            mi_special->Enable(false);
            mi_cm_res->Enable(true);
        }else
        {
            mi_urgent->Enable(false);
            mi_special->Enable(false);
            mi_cm_res->Enable(false);
        }

        str = wxT(" res_cm = '")+gr_para.login_user+wxT("' and (unit_status =1 or unit_status= 3 )  and is_active=true and active_status>=1 and is_latest=true and is_del=false and status>=0 ");
        set_clause(str);

        choice_action->SetSelection(0);

        set_clause1(wxEmptyString);

        mi_remarks->Enable(true);

        m_report=1;

        refresh_list();


    }else if(array_group.Index(wxT("G0017"))!=wxNOT_FOUND)
    {/*
        Button1->Show(false);
        Button4->Show(false);
        Button_Feedback->Show(false);

        choice_status->Show(true);
        mi_cm_res->Enable(true);

        is_leader = wxGetApp().is_leader(wxT("G0017"));
        if(is_leader)
        {
            mi_urgent->Enable(false);
            mi_special->Enable(true);

        }else
        {
            mi_urgent->Enable(false);
            mi_special->Enable(false);
        }

        str =  wxT("  (unit_status =1 or unit_status = 3 )  and is_active=true and active_status>=1 and is_latest=true  and is_del=false and status>=0 ");
        set_clause(str);
        choice_status->SetSelection(2);

        mi_remarks->Enable(false);

        set_clause1(wxEmptyString);
        m_report=2;

        refresh_list();*/

       Button1->Show(true);
        Button4->Show(true);
        Button_Feedback->Show(true);
        choice_status->Show(true);

        is_leader = wxGetApp().is_leader(wxT("G0001"));
        if(is_leader)
        {
            mi_urgent->Enable(true);
            mi_special->Enable(false);
            mi_cm_res->Enable(true);
        }else
        {
            mi_urgent->Enable(false);
            mi_special->Enable(false);
            mi_cm_res->Enable(false);
        }

        str = wxT(" res_cm = '")+gr_para.login_user+wxT("' and (unit_status =1 or unit_status= 3 )  and is_active=true and active_status>=1 and is_latest=true and is_del=false and status>=0 ");
        set_clause(str);

        choice_action->SetSelection(0);

        set_clause1(wxEmptyString);

        mi_remarks->Enable(true);

        m_report=1;

        refresh_list();

    }else
    {
        Button1->Show(false);
        Button4->Show(false);
        Button_Feedback->Show(false);

        choice_status->Show(false);
        choice_action->Show(false);

        mi_urgent->Enable(false);
        mi_special->Enable(false);
        mi_common->Enable(false);
        mi_remarks->Enable(false);
        mi_cm_res->Enable(false);
    }

    init_excel_head();

}

project_info_panel::~project_info_panel()
{
	//(*Destroy(project_info_panel)
	//*)
}

void project_info_panel::OnTreeListCtrlRightClick(wxTreeEvent& event)
{
  //    PopupMenu(&menu_review_info, event.GetPoint());
      PopupMenu(&menu_review_info, ScreenToClient(wxGetMousePosition()));
}

void project_info_panel::BuildDataViewCtrl()
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

    tlc_task_list->AddColumn(_("非标等级"), 60, wxALIGN_LEFT, -1, true, false);//5

    tlc_task_list->AddColumn(_("合同负责ID"),0,wxALIGN_LEFT, -1,false,false );//6-5
    tlc_task_list->AddColumn(_("合同负责"),100,wxALIGN_LEFT, -1,true,false );//7-6
    tlc_task_list->AddColumn(_("评审负责ID"),0,wxALIGN_LEFT, -1,false,false );//8-7
    tlc_task_list->AddColumn(_("评审负责"),100,wxALIGN_LEFT, -1,true,false );//9-8
    tlc_task_list->AddColumn(_("分公司id"),0,wxALIGN_LEFT, -1,false,false);//10-9
    tlc_task_list->AddColumn(_("分公司"),100,wxALIGN_LEFT, -1,true,false);//11-10
    tlc_task_list->AddColumn(_("status"),50,wxALIGN_LEFT,-1,true,false);//12-11
    tlc_task_list->AddColumn(_("任务状态"),70,wxALIGN_LEFT,-1,true,false);//13-12
    tlc_task_list->AddColumn(_("action_id"),0 ,wxALIGN_LEFT,-1,false,false);//14-13
    tlc_task_list->AddColumn(_("图纸套数"),60,wxALIGN_LEFT,-1,true,false); //15-14
    tlc_task_list->AddColumn(_("备注"),100,wxALIGN_LEFT,-1,true,false); //16-15
    tlc_task_list->AddColumn(_("交流status"),0,wxALIGN_LEFT,-1,false,false);//17-16
    tlc_task_list->AddColumn(_("交流状态"),200,wxALIGN_LEFT,-1,true,false);//18-17
    tlc_task_list->AddColumn(_("紧急程度ID"),0, wxALIGN_LEFT, -1, false, false);//19-18

    wxTreeItemId root = tlc_task_list->AddRoot (_("评审任务"));
}

void project_info_panel::OnButton_FeedbackClick(wxCommandEvent& event)
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

    if(array_group.Index(wxT("G0001")) == wxNOT_FOUND)
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
    wxString str_context;


    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item)==root)
        {
            str_status =  tlc_task_list->GetItemText(sel_item, 17);//16
            str_context =  tlc_task_list->GetItemText(sel_item, 18);//17
            str_task_id = tlc_task_list->GetItemText(sel_item, 1);

            if(str_status.IsEmpty()|| str_status == wxT("0"))
            {
                wxLogMessage(_("评审issue尚未提出!"));
                continue;
            }

            if(str_status==wxT("2"))
            {
                wxLogMessage(_("评审issue分公司已经反馈!"));
                continue;
            }

            if(str_status == wxT("1"))
            {
                communication_dlg dlg;
                dlg.m_mode = 1;
                dlg.enable_control();
                dlg.init_communication(str_task_id);
 //               dlg.b_show=false;
 //               dlg.show_control();
                if(dlg.ShowModal()==wxID_OK)
                {
                    if(update_communication(str_task_id, str_status, dlg.m_return))
                    {
                        tlc_task_list->SetItemText(sel_item, 17, str_status);//16
                        str_context= dlg.m_return;
                        str_context = update_issue_context(wxAtoi(str_status),str_context);
                        tlc_task_list->SetItemText(sel_item, 18, str_context);//17
                    }

                }
            }

        }
    }

    refresh_level();

}

wxString project_info_panel::update_issue_context(int i_status, wxString str)
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

bool project_info_panel::update_communication(wxString s_task_id, wxString &s_status, wxString s_content)
{
    wxString str_sql = wxT("UPDATE s_review_communication SET return_content='")+s_content+wxT("', issue_status= 2,return_date = '")+DateToAnsiStr(wxDateTime::Now())+
                        wxT("',return_emp_id = '")+gr_para.login_user+wxT("' WHERE review_task_id='")+s_task_id+wxT("' and issue_status = '")+s_status+wxT("';");

    str_sql.Replace(wxT("''"),wxT("NULL"));

    bool b_result = wxGetApp().app_sql_update(str_sql);

    if(b_result)
        s_status = wxT("2");

    return b_result;

}

void project_info_panel::OnButton2Click(wxCommandEvent& event)
{
}

void project_info_panel::OnButton1Click(wxCommandEvent& event)
{

    if(!gr_para.login_status)
    {
        wxLogMessage( _("尚未登陆,无法做任何操作!"));
        return;
    }

    if(!wxGetApp().conn->IsAlive())
    {
        wxLogMessage(_("系统连接已断开,请重新连接!"));
        wxGetApp().clear_login();
        return;
    }

    wxArrayString array_group = wxGetApp().get_group();

    if(array_group.Index(wxT("G0001")) == wxNOT_FOUND)
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


    if(wxMessageBox(_("确认重新启动评审授权"),_("确认："),wxOK|wxCANCEL,this)==wxCANCEL)
    {
        return;
    }

    wxString s_task_id,s_project_info, s_action_id,s_wf_status;
    int i_status;

    v_wf_action * t_template=0;

    wf_operator * wf_active=0;

    wf_process * l_proc_act =0;

    v_wf_instance now_step, next_step;

    wxLongLong mils_used, start_mils;

    t_template = get_template_action(wf_str_review);

    wxArrayString array_task_units;
    wxString s_branch_id;
    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item)==root)
        {

            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_task_list->GetFirstChild(sel_item,cookie);

            s_task_id = tlc_task_list->GetItemText(sel_item, 1);
            while(child_item.IsOk())
            {
                wxString s_wbs = tlc_task_list->GetItemText(child_item, 0);

                s_action_id = tlc_task_list->GetItemText(child_item, 14);//13
                i_status = prj_str_to_status(tlc_task_list->GetItemText(child_item, 12));//11
                if(i_status != 1 && i_status !=3)
                {
                    wxLogMessage(_("Unit:")+s_wbs+_("评审任务处于非活动状态，跳过！"));
                    child_item = tlc_task_list->GetNextSibling(child_item);
                    continue;
                }

                if(s_action_id!= wxT("AT00000001"))
                {
                    wxLogMessage(_("Unit:")+s_wbs+_("评审任务工作流未到本人，跳过！"));
                    child_item = tlc_task_list->GetNextSibling(child_item);
                    continue;
                }

                start_mils = wxGetLocalTimeMillis();//事件处理事件统计，起始点。

                wf_active = new wf_operator(s_wbs, wf_str_review, t_template);

                l_proc_act = wf_active->get_current_process();
                l_proc_act->MoveToActive();
                wf_active->Pass_proc(wxEmptyString, wxEmptyString, wxEmptyString, false);

                s_branch_id = tlc_task_list->GetItemText(child_item, 10);
                wxString s_operator = wxGetApp().get_operator_from_branch(s_branch_id, "G0002");
                if(!s_operator.IsEmpty())
                {
                   if(wf_active->Pass_proc(s_operator, "G0002", wxEmptyString, false))
                   {
                       s_wf_status=_("项目评审");
                   }
                }else
                {
                   s_wf_status=_("评审授权");
                }

 //               if(wf_active->update_instance(i_status, s_wf_status))
                if(update_review_units_status(s_task_id, s_wbs, i_status, s_wf_status))
                {


                    mils_used = wxGetLocalTimeMillis() - start_mils;
                    wxLogMessage(_("UNIT:")+s_wbs+_("创建评审任务成功,耗时:")+NumToStr(mils_used)+_("毫秒"));

                }

                l_proc_act=0;
                delete wf_active;

                child_item = tlc_task_list->GetNextSibling(child_item);
            }
        }
    }

    refresh_list();

    delete [] t_template;
}
/*
bool project_info_panel::update_review_status(const wxString s_wbs_no, int i_status, wxString s_wf_status)
{
    wxString str_sql = wxT("UPDATE s_unit_info SET status =")+NumToStr(i_status)+wxT(",wf_status='")+s_wf_status+wxT("',modify_date = '")+DateToAnsiStr(wxDateTime::Now())+
                               wxT("',modify_emp_id = '")+gr_para.login_user+wxT("' WHERE wbs_no='")+s_wbs_no+wxT("';");

    return wxGetApp().app_sql_update(str_sql);
}
*/
bool project_info_panel::update_review_units_status(const wxString s_task_id, const wxString s_wbs_no, int i_status, wxString s_wf_status, int i_restart_times)
{
     wxString str_sql = wxT("UPDATE s_review_units SET unit_status =")+NumToStr(i_status)+wxT(",unit_wf_status='")+s_wf_status+wxT("',restart_times =")+NumToStr(i_restart_times)+wxT(",modify_date = '")+DateToAnsiStr(wxDateTime::Now())+
                               wxT("',modify_emp_id = '")+gr_para.login_user+wxT("' WHERE review_task_id ='")+ s_task_id+wxT("' and wbs_no='")+s_wbs_no+wxT("';");

    return wxGetApp().app_sql_update(str_sql);
}

void project_info_panel::refresh_list()
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

    if(m_report<=0)
        return;

    wxArrayString array_group = wxGetApp().get_group();

/*  逻辑已更改，初始状态已确定是否调用此函数
    if(array_group.Index(wxT("G0001")) == wxNOT_FOUND)
        return;*/

    wxTreeItemId root = tlc_task_list->GetRootItem();
    tlc_task_list->DeleteChildren (root);

    wxString str_sql = wxT("SELECT review_task_id,contract_id,urgent_level, project_name,project_id,require_review_date,res_cm,nonstd_level,\
                           (select name from s_employee where employee_id = res_cm) as res_cm_person,review_engineer, \
                           (select name from s_employee where employee_id = review_engineer) as review_engineer_name, branch_id,\
                           (select branch_name_cn from s_branch_info where branch_id = v_task_list4.branch_id) as branch_name, status, wf_status, action_id, wbs_no,lift_no,\
                           elevator_type,project_catalog,review_remarks, review_drawing_qty,unit_status, unit_wf_status,\
                           (select concat(issue_status,'-',issue_content,'-',return_content) from s_review_communication where \
                           review_task_id= v_task_list4.review_task_id and issue_status <=2) as com_context FROM v_task_list4 WHERE ")+cl_clause+cl_clause1+wxT(" and workflow_id='WF0001' ORDER BY review_task_id, wbs_no ASC;");

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
    int i_review_status;
    int i_urgent_level;
    int i_nstd_level;

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
            tlc_task_list->SetItemText(branch_item,6, str);//5

            str = _res->GetVal(wxT("res_cm_person"));
            tlc_task_list->SetItemText(branch_item,7, str);//6

            str = _res->GetVal(wxT("review_engineer"));
            tlc_task_list->SetItemText(branch_item,8, str);//7

            str = _res->GetVal(wxT("review_engineer_name"));
            tlc_task_list->SetItemText(branch_item,9, str);//8

            str = _res->GetVal(wxT("branch_id"));
            tlc_task_list->SetItemText(branch_item,10, str);//9

            str = _res->GetVal(wxT("branch_name"));
            tlc_task_list->SetItemText(branch_item,11, str);//10


            str = _res->GetVal(wxT("review_drawing_qty"));
            tlc_task_list->SetItemText(branch_item,15, str);//14

            str = _res->GetVal(wxT("review_remarks"));
            tlc_task_list->SetItemText(branch_item,16, str);//15

            str = _res->GetVal(wxT("com_context"));
            i_review_status = 0;
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
            tlc_task_list->SetItemText(branch_item,17, NumToStr(i_review_status));//16
            tlc_task_list->SetItemText(branch_item,18, str);//17
        }

        str = _res->GetVal(wxT("wbs_no"));

        leaf_item = tlc_task_list->AppendItem(branch_item,str,-1,-1);

        tlc_task_list->SetItemText(leaf_item,1,s_review_task_id);

        str = _res->GetVal(wxT("lift_no"));
        tlc_task_list->SetItemText(leaf_item,2, str);

        str = _res->GetVal(wxT("elevator_type"));
        tlc_task_list->SetItemText(leaf_item,3, str);

        i_urgent_level = _res->GetInt(wxT("urgent_level"));
        str = urgent_level_to_str(i_urgent_level);
        tlc_task_list->SetItemText(leaf_item, 4, str);

        i_nstd_level = _res->GetInt(wxT("nonstd_level"));
        str = nstd_level_to_str(i_nstd_level);
        tlc_task_list->SetItemText(leaf_item, 5, str);

        tlc_task_list->SetItemText(leaf_item, 19, NumToStr(i_urgent_level));//18

        str = prj_catalog_to_str(_res->GetInt(wxT("project_catalog")));
        tlc_task_list->SetItemText(leaf_item,7, str);//6

        str = _res->GetVal(wxT("branch_id"));
        tlc_task_list->SetItemText(leaf_item,10, str);//9

        str = prj_status_to_str(_res->GetInt(wxT("unit_status")));
        tlc_task_list->SetItemText(leaf_item,12, str);//11

        str = _res->GetVal(wxT("unit_wf_status"));
        tlc_task_list->SetItemText(leaf_item,13, str);//12

        str = _res->GetVal(wxT("action_id"));
        tlc_task_list->SetItemText(leaf_item,14, str);//13

        _res->MoveNext();
    }

    _res->Clear();

    refresh_level();
}

void project_info_panel::set_treelist_item_color(wxTreeItemId i_id, int i_temp)
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

void project_info_panel::refresh_level()
{
    wxTreeItemId root = tlc_task_list->GetRootItem();

    wxString s_status, s_wf_status, str, s_urgent_level;

    wxTreeItemIdValue cookie;
    wxTreeItemId item = tlc_task_list->GetFirstChild(root,cookie);
    int i_action;
    int i_urgent_level, itemp;

    wxArrayString a_lift_no;
    wxString s_lift_no;
    wxString s_nstd_level;

    while(item.IsOk())
    {
        wxTreeItemIdValue cookie_child;
        wxTreeItemId child_item = tlc_task_list->GetFirstChild(item,cookie_child);

        i_urgent_level=1;

        i_action=0;


        int i_review_status = StrToInt(tlc_task_list->GetItemText(item, 17));//16
        if(i_review_status==1)
        {
            tlc_task_list->SetItemImage(item, 5);
        }else if(i_review_status == 2)
        {
            tlc_task_list->SetItemImage(item, 6);
        }else
            tlc_task_list->SetItemImage(item, -1);

        s_nstd_level = wxEmptyString;

        while(child_item.IsOk())
        {
            wxString s_action_id = tlc_task_list->GetItemText(child_item,14);//13
            str = tlc_task_list->GetItemText(child_item, 12);//11

            itemp = StrToInt(tlc_task_list->GetItemText(child_item, 19));//18

            s_lift_no = tlc_task_list->GetItemText(child_item, 2);
            a_lift_no.Add(s_lift_no);

            set_treelist_item_color(child_item, itemp);

            if(itemp > i_urgent_level)
                i_urgent_level=itemp;

            if(!s_status.Contains(str))
            {
                if(s_status.IsEmpty())
                    s_status=str;
                else
                    s_status = s_status+wxT("+")+str;
            }

            str = tlc_task_list->GetItemText(child_item, 13);//12


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

            if(s_action_id == wxT("AT00000001"))
            {

                tlc_task_list->SetItemBackgroundColour(child_item, *wxGREEN);
                i_action++;
            }

            str = tlc_task_list->GetItemText(child_item, 5);
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

        int i_count_leaf = tlc_task_list->GetChildrenCount(item);

        if(i_action == i_count_leaf && i_urgent_level==1)
            tlc_task_list->SetItemBackgroundColour(item, *wxGREEN);
        else if(i_action >0&&i_urgent_level==1)
            tlc_task_list->SetItemBackgroundColour(item, *wxCYAN );


        s_lift_no = Combine_lift_no(a_lift_no);

        tlc_task_list->SetItemText(item, 5, s_nstd_level);
        tlc_task_list->SetItemText(item, 2, NumToStr(i_count_leaf)+_("台[")+s_lift_no+_("]"));

        a_lift_no.Clear();


        tlc_task_list->SetItemText(item, 12, s_status);//11
        tlc_task_list->SetItemText(item, 13, s_wf_status);//12
        tlc_task_list->SetItemText(item, 4, s_urgent_level);

        s_status.Empty();
        s_wf_status.Empty();
        s_urgent_level.Empty();

        item = tlc_task_list->GetNextSibling(item);

    }
}


void project_info_panel::OnButton3Click(wxCommandEvent& event)
{
    refresh_list();
}


void project_info_panel::InitImageList()
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

void project_info_panel::Onchoice_statusSelect(wxCommandEvent& event)
{
    int i_sel = event.GetSelection();
    int i_pos;
    wxArrayString  s_members;

    wxString str, s_user;

   wxSingleChoiceDialog *cdlg;

    switch(i_sel)
    {
    case 0:
        str = wxT(" res_cm = '")+gr_para.login_user+wxT("' and (unit_status =1 or unit_status = 3 )  and is_active=true and active_status>=1 and is_latest=true ");
        mi_remarks->Enable(true);
        break;
    case 1:
         s_members = wxGetApp().get_member_in_group(wxT("G0001"), true);
         cdlg= new wxSingleChoiceDialog(this, _("请选择商务人员:"),_("人员选择"),s_members);

        if(cdlg->ShowModal() == wxID_OK)
        {
            s_user = cdlg->GetStringSelection();
        }
        else
        {
            wxLogMessage(_("未选择,取消操作!"));
            return;
        }

        i_pos = s_user.Find('-');

        s_user = s_user.Left(i_pos);

        if(s_user==gr_para.login_user)
            mi_remarks->Enable(true);
        else
            mi_remarks->Enable(false);
        str = wxT(" res_cm = '")+s_user+wxT("' and (unit_status =1 or unit_status = 3 )  and is_active=true and active_status>=1 and is_latest=true ");
        break;
    case 2:
        if(m_report==2)
            str = wxT("  (unit_status =1 or unit_status = 3 )  and is_active=true and active_status>=1 and is_latest=true ");
        else
            str = wxT(" res_cm != '")+gr_para.login_user+wxT("' and (unit_status =1 or unit_status = 3 )  and is_active=true and active_status>=1 and is_latest=true ");
        mi_remarks->Enable(false);
        break;
    case 3:
        mi_remarks->Enable(false);
        str = wxT(" ((unit_status =1 and is_active=true) or (unit_status = 3 and is_active=true)) and active_status=2 and is_latest=true ");
        break;
    case 4:
        mi_remarks->Enable(false);
        str = wxT(" ((is_latest = true  and ((unit_status =1 and is_active=true and  can_psn = true) or (unit_status = 3 and is_active=true and can_psn = true))) or (status>=0 and status<8 and unit_status = 2 and is_latest= true )) and flow_ser=6 ");
        break;
    default:
        mi_remarks->Enable(false);
        return;
    }
    set_clause(str);
    refresh_list();
}


void project_info_panel::OnButton4Click(wxCommandEvent& event)
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

    if(array_group.Index(wxT("G0001")) == wxNOT_FOUND)
        return;

    if(choice_status->GetSelection()==3)
    {
        wxMessageBox(_("待排产项目模式，无法进行此操作，请到项目界面重启评审,或切换模式!"),_("提示"));
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


    if(wxMessageBox(_("GAD修改任务(unit级)启动会导致正在进行的流程终止，并重新启动评审。\n是否确认启动?"),_("确认"),wxOK|wxCANCEL,this)==wxCANCEL)
    {
        return;
    }

    wxArrayString array_wbs;
    wxLongLong mils_used, start_mils;
    wxString str, s_action_id;

    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item)==root)
        {
            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_task_list->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {
                  str = tlc_task_list->GetItemText(child_item,0);
                  s_action_id = tlc_task_list->GetItemText(child_item, 14);//13
                  if(s_action_id == wxT("AT00000001") )
                  {
                      wxLogMessage(str+_("项目立项状态，无法进行此操作，请点击立项状态项目启动!"));
                      child_item = tlc_task_list->GetNextSibling(child_item);
                      continue;
                  }

                  if(s_action_id == wxT("AT00000002"))
                  {
                      wxLogMessage(str+_("项目正在授权，未分配给评审工程师，GAD更改可直接通知授权人更改图纸套数!"));
                      child_item = tlc_task_list->GetNextSibling(child_item);
                      continue;
                  }

                  if(array_wbs.Index(str)==wxNOT_FOUND)
                     array_wbs.Add(str);
                  child_item = tlc_task_list->GetNextSibling(child_item);
            }
        }
        else if(sel_item.IsOk())
        {
            str = tlc_task_list->GetItemText(sel_item,0);

            s_action_id = tlc_task_list->GetItemText(sel_item, 14);//13
            if(s_action_id == wxT("AT00000001") )
            {
                wxLogMessage(str+_("项目立项状态，无法进行此操作，请点击立项状态项目启动!"));
                continue;
            }

            if(s_action_id == wxT("AT00000002"))
            {
                wxLogMessage(str+_("项目正在授权，未分配给评审工程师，GAD更改可直接通知授权人更改图纸套数!"));
                continue;
            }

            if(array_wbs.Index(str)==wxNOT_FOUND)
                array_wbs.Add(str);
        }
    }

    if(array_wbs.IsEmpty())
        return;

    array_wbs.Sort(wbs_sort);

    int i_count = array_wbs.GetCount();

    wxString s_project,s_wbs, s_task_id, s_wf_status;
    int i_pos, i_qty;
    review_remarks_dlg tdlg;
    wxString str_desc, str_drawing_qty, str_res_cm;
    int i_urgent_level;
    bool b_same_prj= true;

    v_wf_action * t_template = get_template_action(wf_str_review);
    wf_operator * wf_review = 0;
    wxString s_branch_id;

    for(int i=0;i<i_count;i++)
    {
        start_mils = wxGetLocalTimeMillis();
         s_wbs= array_wbs.Item(i);
        int i_old_status;

         if(s_project!= s_wbs.Left(10))
         {
             b_same_prj = true;
             s_project = s_wbs.Left(10);
             if(!b_same_prj)
                  continue;

            i_qty = get_same_project_count(s_project, array_wbs);

            tdlg.show_control(false);

            tdlg.refresh_control(i_qty,gr_para.login_user+wxT("-")+gr_para.login_user_name,_("项目GAD修改!"));

            if (tdlg.ShowModal() == wxID_OK)
            {
                str_desc = tdlg.m_remarks;
                str_drawing_qty = tdlg.m_qty;
                str_res_cm = tdlg.m_res_cm;
                i_urgent_level = tdlg.m_urgent_level;

            }
            else
            {
                b_same_prj = false;
                continue;
            }


            int i_pos = str_res_cm.Find(wxT("-"));
            str_res_cm = str_res_cm.Left(i_pos);


            s_task_id = create_review_header(str_res_cm, str_desc, str_drawing_qty);

         }

         if(!b_same_prj)
            continue;

        i_old_status = update_unit_status(s_wbs);

        create_review_units(s_wbs, s_task_id, i_old_status, i_urgent_level);

        int i_restart_times=0;

        wf_review = new wf_operator(s_wbs, wf_str_review, t_template);
        wf_review->close_instance();

        i_restart_times = get_restart_times(s_wbs);

        wf_review->restart_instance(wxT("AT00000002"),i_restart_times-1);

        if(!b_same_prj)
        {
            s_branch_id = wxGetApp().get_branch_id(s_project);
        }

        wxString s_operator;
        if(!s_branch_id.IsEmpty())
        {
            s_operator= wxGetApp().get_operator_from_branch( s_branch_id, "G0002");
            if(!s_operator.IsEmpty())
            {
                if(wf_review->Pass_proc(s_operator, "G0002", wxEmptyString, false))
                {
                    s_wf_status=_("项目评审");
                }
            }
            else
            {
                s_wf_status=_("评审授权");
            }

        }
        else
        {
            s_wf_status=_("评审授权");

        }

        //s_wf_status = _("评审授权");

   //     if(wf_review->update_instance(3,s_wf_status))
        if(update_review_units_status(s_task_id, s_wbs,3,s_wf_status, i_restart_times))
        {
            mils_used = wxGetLocalTimeMillis() - start_mils;
            wxLogMessage(_("项目:")+s_wbs+_("GAD修改重建评审任务成功,耗时:")+NumToStr(mils_used)+wxT("!"));
        }

        delete wf_review;

    }

    refresh_list();

    delete [] t_template;

}

int project_info_panel::get_restart_times(wxString s_wbs)
{
    wxString str_sql = wxT("select count(*) as count from s_review_units where wbs_no = '")+s_wbs +wxT("' and is_del = false and  unit_status<>-2 and unit_status<>-1;");

    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return -1;
    }

    int i_restart_times = _res->GetInt(wxT("count"));

    _res->Clear();
    return  i_restart_times;
}

int project_info_panel::get_same_project_count(wxString s_project, wxArrayString a_wbs)
{
    int i_count = a_wbs.GetCount();
    int i_same=0;

    for(int i=0;i<i_count;i++)
    {
        if(a_wbs.Item(i).Contains(s_project))
            i_same++;
    }

    return i_same;
}

int project_info_panel::update_unit_status(wxString s_wbs)
{
    wxString str_sql = wxT("select unit_status, unit_old_status from s_review_units where wbs_no = '")+s_wbs+wxT("' and is_latest=true and unit_status>=0;");
    wxPostgreSQLresult* _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return 0;
    }

    int i_count = _res->GetRowsNumber();
    int i_status,i_old_status;

    if(i_count==0)
    {

        i_old_status =0;
        return 0;
    }

    i_old_status = _res->GetInt(wxT("unit_old_status"));
    i_status = _res->GetInt(wxT("unit_status"));

    _res->Clear();

    if(i_status==0 || i_status ==1 || i_status ==3)
    {
         str_sql = wxT("UPDATE s_review_units SET  unit_status=-3, is_latest=false,modify_date = '")+DateToAnsiStr(wxDateTime::Now())+
                               wxT("',modify_emp_id = '")+gr_para.login_user+wxT("' WHERE wbs_no='")+s_wbs+wxT("' and is_latest=true and unit_status>=0;");
    }else
    {
         str_sql = wxT("UPDATE s_review_units SET is_latest=false,modify_date = '")+DateToAnsiStr(wxDateTime::Now())+
                               wxT("',modify_emp_id = '")+gr_para.login_user+wxT("' WHERE wbs_no='")+s_wbs+wxT("' and is_latest=true and unit_status>=0;");
    }

    if(wxGetApp().app_sql_update(str_sql))
        return i_old_status;

    return -1;
}

wxString project_info_panel::create_review_header(wxString s_res_cm,wxString s_remarks, wxString s_qty)
{
      wxString s_task_id;
      s_task_id = wxGetApp().get_ser_id(wxT("s_review_info"),wxT("review_task_id"));

      wxString str_sql = wxT("INSERT INTO s_review_info(review_task_id, res_cm, modify_date, modify_emp_id, create_date, create_emp_id, review_remarks, review_drawing_qty ) \
               VALUES ('")+s_task_id+wxT("','")+s_res_cm+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+
               DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+s_remarks+wxT("',")+s_qty+wxT(");");

      if(wxGetApp().app_sql_update(str_sql))
      {
          return s_task_id;
      }
      return wxEmptyString;
}


bool project_info_panel::create_review_units(wxString s_wbs, wxString s_task_id, int i_old_status, int i_urgent_level)
{
    wxString str_sql = wxT("INSERT INTO s_review_units ( review_task_id, wbs_no, modify_date, modify_emp_id, create_date, create_emp_id, unit_old_status, unit_status, unit_wf_status, urgent_level) VALUES ('")+
                         s_task_id+wxT("','")+s_wbs+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+
                       DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+NumToStr(i_old_status)+wxT("',3,'评审授权', ")+NumToStr(i_urgent_level)+wxT(");");

     return wxGetApp().app_sql_update(str_sql);
}

void project_info_panel::OnMenuItem1Selected(wxCommandEvent& event)
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

void project_info_panel::OnMenuItem3Selected(wxCommandEvent& event)
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

    wxArrayString a_task_id;

    wxString str;

    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item) == root)
        {
            wxTreeItemIdValue cookie_child;
            wxTreeItemId child_item = tlc_task_list->GetFirstChild(sel_item,cookie_child);

            while(child_item.IsOk())
            {

                str = tlc_task_list->GetItemText(child_item, 0);
                if(a_task_id.Index(str)==wxNOT_FOUND)
                {
                    a_task_id.Add(str);
                }

                child_item = tlc_task_list->GetNextSibling(child_item);
            }

        }
        else
        {

            str = tlc_task_list->GetItemText(sel_item, 0);

            if(a_task_id.Index(str)==wxNOT_FOUND)
            {
                a_task_id.Add(str);
            }
        }

    }

    return_log l_dlg;

    str =wxT("AT00000001");

    l_dlg.refresh_list(a_task_id, str);

    l_dlg.ShowModal();
}

void project_info_panel::Onchoice_actionSelect(wxCommandEvent& event)
{
    int i_sel = event.GetSelection();
    wxString str;

    switch(i_sel)
    {
    case 0:
        str= wxEmptyString;
        break;
    case 1:
        str = wxT(" and action_id ='AT00000001' ");
        break;
    case 2:
        str = wxT(" and action_id = 'AT00000002' ");
        break;
    case 3:
        str = wxT(" and action_id = 'AT00000025' ");
        break;
    case 4:
        str = wxT(" and action_id = 'AT00000026' ");
        break;
    case 5:
        str = wxT(" and action_id = 'AT00000027' ");
        break;
    case 6:
        str = wxT(" and action_id = 'AT00000028' ");
        break;
    default:
        str = wxEmptyString;
        break;
    }

    set_clause1(str);
    refresh_list();
}

int project_info_panel::update_urgent_level(wxString s_task_id, wxString s_wbs, int i_old_level, int i_new_level, wxString s_action_id)
{
    if(s_action_id!= wxT("AT00000001") && s_action_id!= wxT("AT00000002")&& s_action_id!=wxT("AT00000025")&&s_action_id!=wxT("AT00000026"))
    {
        wxLogMessage(s_wbs+_("已经评审完成，无需再设定紧急程度!"));
        return 0;
    }

    if(i_old_level==i_new_level)
    {
        wxLogMessage(s_wbs+_("前后紧急程度相同，无需更改!"));
        return 0;
    }

    wxString s_sql = wxT("UPDATE s_review_units SET modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("', \
        urgent_level=")+NumToStr(i_new_level)+wxT(" where  review_task_id='")+s_task_id+wxT("' and wbs_no='")+s_wbs+wxT("' and is_latest=true and unit_status>=0;");


    bool b_return = wxGetApp().app_sql_update(s_sql);

    if(b_return)
    {
        wxGetApp().change_log(wxT("s_review_untis"),s_task_id+wxT("-")+s_wbs, wxT("urgent_level"),NumToStr(i_old_level),NumToStr(i_new_level));
        return 1;

    }

    return -1;
}

void project_info_panel::Onmi_commonSelected(wxCommandEvent& event)
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

    wxString s_wbs,s_task_id,s_action_id;
    int i_urgent_level;

    if(wxMessageBox(_("确认将选中的项目紧急程度切换为普通?"),_("提示"),wxYES_NO)==wxNO)
         return;

    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item) == root)
        {
            wxTreeItemIdValue cookie_child;
            wxTreeItemId child_item = tlc_task_list->GetFirstChild(sel_item,cookie_child);

            while(child_item.IsOk())
            {

                s_wbs = tlc_task_list->GetItemText(child_item, 0);
                s_task_id = tlc_task_list->GetItemText(child_item, 1);
                i_urgent_level= StrToInt(tlc_task_list->GetItemText(child_item, 19));//18
                s_action_id = tlc_task_list->GetItemText(child_item, 14);//13
                if(update_urgent_level(s_task_id, s_wbs, i_urgent_level, 1,s_action_id)==1)
                {

                    tlc_task_list->SetItemText(child_item, 4,_("普通"));
                    tlc_task_list->SetItemText(child_item, 19, wxT("1"));//18
                }

                child_item = tlc_task_list->GetNextSibling(child_item);
            }

        }
        else
        {

            s_wbs = tlc_task_list->GetItemText(sel_item, 0);
            s_task_id = tlc_task_list->GetItemText(sel_item, 1);
            i_urgent_level= StrToInt(tlc_task_list->GetItemText(sel_item, 19));//18

            s_action_id = tlc_task_list->GetItemText(sel_item, 14);//13
            if(update_urgent_level(s_task_id, s_wbs, i_urgent_level, 1, s_action_id)==1)
                tlc_task_list->SetItemText(sel_item, 19, wxT("1"));//18
        }

    }

    refresh_level();
}

void project_info_panel::Onmi_urgentSelected(wxCommandEvent& event)
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

    wxString s_wbs,s_task_id, s_action_id;
    int i_urgent_level;

    if(wxMessageBox(_("确认将选中的项目紧急程度切换为紧急?"),_("提示"),wxYES_NO)==wxNO)
         return;

    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item) == root)
        {
            wxTreeItemIdValue cookie_child;
            wxTreeItemId child_item = tlc_task_list->GetFirstChild(sel_item,cookie_child);

            while(child_item.IsOk())
            {

                s_wbs = tlc_task_list->GetItemText(child_item, 0);
                s_task_id = tlc_task_list->GetItemText(child_item, 1);
                i_urgent_level= StrToInt(tlc_task_list->GetItemText(child_item, 19));//18
                s_action_id = tlc_task_list->GetItemText(child_item, 14);//13
                if(update_urgent_level(s_task_id, s_wbs, i_urgent_level, 2, s_action_id)==1)
                {

                    tlc_task_list->SetItemText(child_item, 4,_("紧急"));
                    tlc_task_list->SetItemText(child_item, 19, wxT("2"));//18
                }

                child_item = tlc_task_list->GetNextSibling(child_item);
            }

        }
        else
        {

            s_wbs = tlc_task_list->GetItemText(sel_item, 0);
            s_task_id = tlc_task_list->GetItemText(sel_item, 1);
            i_urgent_level= StrToInt(tlc_task_list->GetItemText(sel_item, 19));//18
            s_action_id = tlc_task_list->GetItemText(sel_item, 14);//13
            if(update_urgent_level(s_task_id, s_wbs, i_urgent_level, 2, s_action_id)==1)
                tlc_task_list->SetItemText(sel_item, 19, wxT("2"));//18
        }

    }

    refresh_level();
}

void project_info_panel::Onmi_specialSelected(wxCommandEvent& event)
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

    wxString s_wbs,s_task_id, s_action_id;
    int i_urgent_level;

    if(wxMessageBox(_("确认将选中的项目紧急程度切换为 特紧急?"),_("提示"),wxYES_NO)==wxNO)
         return;

    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item) == root)
        {
            wxTreeItemIdValue cookie_child;
            wxTreeItemId child_item = tlc_task_list->GetFirstChild(sel_item,cookie_child);

            while(child_item.IsOk())
            {

                s_wbs = tlc_task_list->GetItemText(child_item, 0);
                s_task_id = tlc_task_list->GetItemText(child_item, 1);
                i_urgent_level= StrToInt(tlc_task_list->GetItemText(child_item, 19));//18
                s_action_id = tlc_task_list->GetItemText(child_item, 14);//13
                if(update_urgent_level(s_task_id, s_wbs, i_urgent_level, 3,s_action_id)==1)
                {

                    tlc_task_list->SetItemText(child_item, 4,_("特紧急"));
                    tlc_task_list->SetItemText(child_item, 19, wxT("3"));//18
                }

                child_item = tlc_task_list->GetNextSibling(child_item);
            }

        }
        else
        {

            s_wbs = tlc_task_list->GetItemText(sel_item, 0);
            s_task_id = tlc_task_list->GetItemText(sel_item, 1);
            i_urgent_level= StrToInt(tlc_task_list->GetItemText(sel_item, 19));//18
            s_action_id = tlc_task_list->GetItemText(sel_item, 14);//13
            if(update_urgent_level(s_task_id, s_wbs, i_urgent_level, 3, s_action_id)==1)
                tlc_task_list->SetItemText(sel_item, 19, wxT("3"));//18
        }

    }

    refresh_level();
}

void project_info_panel::Onmi_remarksSelected(wxCommandEvent& event)
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

    wxString s_remarks,s_old_remarks, s_sql, s_task_id;

    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item) == root)
        {
            s_old_remarks= tlc_task_list->GetItemText(sel_item, 16);//15
            s_task_id = tlc_task_list->GetItemText(sel_item, 1);

            wxTextEntryDialog tdlg(this, _("确认修改当前备注")+s_old_remarks, _("备注"), wxT(""), wxOK | wxCANCEL | wxTE_MULTILINE, wxDefaultPosition);
            if (tdlg.ShowModal() == wxID_OK)
            {
                s_remarks = tdlg.GetValue();
            }
            else
            {
                continue;
            }

            s_sql = wxT("UPDATE s_review_info SET modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("',  review_remarks='")+s_remarks+wxT("' where review_task_id='")+s_task_id+wxT("';");
            if(wxGetApp().app_sql_update(s_sql))
            {
                tlc_task_list->SetItemText(sel_item, 16, s_remarks);//15
                wxGetApp().change_log(wxT("s_review_info"), s_task_id, wxT("review_remarks"), s_old_remarks, s_remarks);

            }


        }

    }

}


void project_info_panel::Onmi_smart_posSelected(wxCommandEvent& event)
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

void project_info_panel::Onmi_processSelected(wxCommandEvent& event)
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
/*
void project_info_panel::Onmi_pos_wbsSelected(wxCommandEvent& event)
{
       if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }

    wxString str;

    wxTextEntryDialog tdlg(this, _("请输入WBS NO"), _("按WBS NO查找"), wxT(""), wxOK | wxCANCEL, wxDefaultPosition);
    if (tdlg.ShowModal() == wxID_OK)
    {
        str = tdlg.GetValue();
    }
    else
    {
        return;
    }

    if(str.IsEmpty())
        return;

    m_pos_id = search_in_treelist(tlc_task_list, m_pos_id,str,0);
}*/

void project_info_panel::OnChar(wxTreeEvent& event)
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
    case WXK_CONTROL_C:
         Copy();
         break;
    default:
        break;
    }

    event.Skip();
}

int project_info_panel::Copy()
{
    wxString str;
	int copied = 0;

    wxTreeItemId root = tlc_task_list->GetRootItem();
    wxArrayTreeItemIds items;
    wxArrayTreeItemIds::iterator iter;
    tlc_task_list->GetSelections( items );
    wxString s_task_id, s_wbsno, s_projec_name, s_lift_type, s_urgent_level, s_lift_no,s_req_finish, s_cm_res,s_review_res, s_branch, s_status, s_wf_status/*,s_remarks,  s_com_context*/;

   int i_pos;
   for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item)==root)
        {
            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_task_list->GetFirstChild(sel_item,cookie);
            s_projec_name = tlc_task_list->GetItemText(sel_item, 0);
            i_pos = s_projec_name.Find("-");
            s_projec_name = s_projec_name.Left(i_pos);
            s_req_finish = tlc_task_list->GetItemText(sel_item, 3);

            s_cm_res = tlc_task_list->GetItemText(sel_item, 7);//6
            s_review_res = tlc_task_list->GetItemText(sel_item, 9);//8
            s_branch = tlc_task_list->GetItemText(sel_item, 11);//10
       //     s_remarks = tlc_task_list->GetItemText(sel_item, 16);//15
         //   s_com_context=tlc_task_list->GetItemText(sel_item, 18);//17

            while(child_item.IsOk())
            {
                 s_task_id = tlc_task_list->GetItemText(child_item, 1);
                  s_wbsno = tlc_task_list->GetItemText(child_item, 0);
                  s_lift_type = tlc_task_list->GetItemText(child_item, 2);
                  s_lift_no = tlc_task_list->GetItemText(child_item, 3);
                  s_urgent_level = tlc_task_list->GetItemText(child_item, 4);
                  s_status = tlc_task_list->GetItemText(child_item, 12);//11
                  s_wf_status = tlc_task_list->GetItemText(child_item, 13);//12


                  str = str + s_task_id+wxT("\t")+s_wbsno+wxT("\t")+s_projec_name+wxT("\t")+s_lift_no+wxT("\t")+s_lift_type+wxT("\t")+
                        s_req_finish+wxT("\t")+s_urgent_level+wxT("\t")+s_cm_res+wxT("\t")+s_review_res+wxT("\t")+s_branch+wxT("\t")+
                        s_status+wxT("\t")+s_wf_status/*+wxT("\t")+s_remarks+wxT("\t")+s_com_context*/+END_OF_LINE;
                  copied++;

                  child_item = tlc_task_list->GetNextSibling(child_item);
            }
        }else
        {
                 wxTreeItemId parent_id;
                 parent_id = tlc_task_list->GetItemParent(sel_item);
                 s_projec_name = tlc_task_list->GetItemText(parent_id, 0);
                 i_pos = s_projec_name.Find("-");
                 s_projec_name = s_projec_name.Left(i_pos);
                 s_req_finish = tlc_task_list->GetItemText(parent_id, 3);

                 s_cm_res = tlc_task_list->GetItemText(parent_id, 7);//6
                 s_review_res = tlc_task_list->GetItemText(parent_id, 9);//8
                 s_branch = tlc_task_list->GetItemText(parent_id, 11);//10
        //         s_remarks = tlc_task_list->GetItemText(parent_id, 16);//15
         //         s_com_context=tlc_task_list->GetItemText(parent_id, 18);//17

                 s_task_id = tlc_task_list->GetItemText(sel_item, 1);
                  s_wbsno = tlc_task_list->GetItemText(sel_item, 0);
                  s_lift_type = tlc_task_list->GetItemText(sel_item, 2);
                  s_lift_no = tlc_task_list->GetItemText(sel_item, 3);
                  s_urgent_level = tlc_task_list->GetItemText(sel_item, 4);
                  s_status = tlc_task_list->GetItemText(sel_item, 12);//11
                  s_wf_status = tlc_task_list->GetItemText(sel_item, 13);//12


                  str = str + s_task_id+wxT("\t")+s_wbsno+wxT("\t")+s_projec_name+wxT("\t")+s_lift_no+wxT("\t")+s_lift_type+wxT("\t")+
                        s_req_finish+wxT("\t")+s_urgent_level+wxT("\t")+s_cm_res+wxT("\t")+s_review_res+wxT("\t")+s_branch+wxT("\t")+
                        s_status+wxT("\t")+s_wf_status/*+wxT("\t")+s_remarks+wxT("\t")+s_com_context*/+END_OF_LINE;
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


void project_info_panel::Onmi_cm_resSelected(wxCommandEvent& event)
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

    wxString s_wbs,s_task_id;
    wxArrayString s_members;
    wxString s_user,s_old_user, s_sql,s_user_name;

    s_members = wxGetApp().get_member_in_group(wxT("G0001"), true);

    wxSingleChoiceDialog cdlg(this, _("请选择新的项目商务负责人:"),_("人员选择"),s_members);

    if(cdlg.ShowModal() == wxID_OK)
    {
        s_user = cdlg.GetStringSelection();
    }
    else
    {
        wxLogMessage(_("未选择,取消操作!"));
        return;
    }

    int i_pos = s_user.Find('-');

    s_user_name = s_user.Right(s_user.Length()-i_pos-1);

    s_user = s_user.Left(i_pos);


   for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_task_list->GetItemParent(sel_item)==root)
        {

            wxTreeItemIdValue cookie_child;

            s_task_id=tlc_task_list->GetItemText(sel_item, 1);

            s_old_user = tlc_task_list->GetItemText(sel_item, 6);//5

            if(check_subitem_status(sel_item))
            {
                   s_sql = wxT("UPDATE s_review_info SET res_cm='")+s_user+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("' where review_task_id='")+s_task_id+wxT("';");
                  if( wxGetApp().app_sql_update(s_sql))
                  {
                       wxGetApp().change_log(wxT("s_review_info"),s_task_id,wxT("res_cm"),s_old_user,s_user,wxT("by hand"));
                       tlc_task_list->SetItemText(sel_item, 6,s_user);//5
                       tlc_task_list->SetItemText(sel_item, 7, s_user_name);//6
                       wxLogMessage(s_task_id+_("变更商务负责人")+s_user_name+wxT("成功!"));
                  }

            }else
            {
                wxLogMessage(s_task_id+tlc_task_list->GetItemText(sel_item, 0)+_("已经分配评审任务，请退回后在操作!"));
                continue;
            }

            wxTreeItemId child_item = tlc_task_list->GetFirstChild(sel_item,cookie_child);
            while(child_item.IsOk())
            {
                s_wbs = tlc_task_list->GetItemText(child_item,0);

                s_sql= wxT("UPDATE l_proc_acT SET operator_id='")+s_user+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("' where instance_id='")+s_wbs+wxT("' and workflow_id='WF0001' AND action_id='AT00000001';");

                wxGetApp().app_sql_update(s_sql);
                child_item= tlc_task_list->GetNextSibling(child_item);
            }

        }else
        {
             wxLogMessage(_("此修改必须选择第一层才能修改."));
        }

    }
}

bool project_info_panel::check_subitem_status(wxTreeItemId &i_item)
{
    wxTreeItemIdValue cookie_child;
    wxTreeItemId child_item = tlc_task_list->GetFirstChild(i_item,cookie_child);

    wxString s_action_id;

    while(child_item.IsOk())
    {
        s_action_id = tlc_task_list->GetItemText(child_item,14);//13
        if(s_action_id==wxT("AT00000001")||s_action_id==wxT("AT00000002"))
        {
             return true;
        }

        child_item= tlc_task_list->GetNextSibling(child_item);
    }

    return false;

}

void project_info_panel::Onmi_startSelected(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }


    wxString str;

    datepickerdlg dlg;

    if(dlg.ShowModal()==wxID_CANCEL)
    {
        return;
    }

    bool b_from = dlg.b_from;
    bool b_to = dlg.b_to;
    wxDateTime dt_from, dt_to;

    wxString s_time = wxT(" 23:00:00");

    if(b_from )
        dt_from = dlg.dt_from;

    if(b_to)
        dt_to = dlg.dt_to;

    wxFileDialog     saveFileDialog(this, _("Save xls file"), "", "",
                                       "xls files (*.xls)|*.xls", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea..

    wxString s_sql = wxT("select review_task_id,review_drawing_qty,contract_id, project_name, instance_id, elevator_id,(select elevator_type from s_elevator_type_define where elevator_type_id= elevator_id) as elevator_type,lift_no, flow_ser, nonstd_level,branch_id,\
                         res_cm, action_id, (select name from s_employee where employee_id=res_cm) as res_cm_name, start_date, review_engineer , (select name from s_employee where employee_id=review_engineer) as review_engineer_name,(select  branch_name_cn from s_branch_info where branch_id=v_task_list4.branch_id) as branch_name,\
                         finish_date,is_active, (select issue_date from s_review_communication where review_task_id=v_task_list4.review_task_id and issue_status>=0 and issue_status<3) as issue_date from v_task_list4 where workflow_id='WF0001' AND flow_ser<=4 and is_latest=true and is_del=false and status>=0 ");

    if(b_from && b_to)
        s_sql = s_sql + wxT(" and start_date >='")+DateToStrFormat(dt_from)+s_time+wxT("' and start_date<='")+DateToStrFormat(dt_to)+s_time+wxT("' ");

    if (b_from && !b_to)
        s_sql = s_sql + wxT(" and start_date >='")+DateToStrFormat(dt_from)+s_time+wxT("' ");

    if (!b_from && b_to)
        s_sql = s_sql + wxT(" and start_date <='")+DateToStrFormat(dt_to)+s_time+wxT("' ");

    s_sql = s_sql +wxT(" order by instance_id, flow_ser Asc;");

    wxPostgreSQLresult* _res;

    _res = wxGetApp().app_sql_select(s_sql);


    wxString str_file = saveFileDialog.GetPath();

    save_file(str_file, _res);
}

void project_info_panel::Onmi_authorSelected(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }


    wxString str;

    datepickerdlg dlg;

    if(dlg.ShowModal()==wxID_CANCEL)
    {
        return;
    }

    bool b_from = dlg.b_from;
    bool b_to = dlg.b_to;
    wxDateTime dt_from, dt_to;

    wxString s_time = wxT(" 23:00:00");

    if(b_from )
        dt_from = dlg.dt_from;

    if(b_to)
        dt_to = dlg.dt_to;

    wxFileDialog     saveFileDialog(this, _("Save xls file"), "", "",
                                       "xls files (*.xls)|*.xls", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...


    wxString s_sql = wxT("select review_task_id,review_drawing_qty,contract_id, project_name, instance_id, elevator_id,(select elevator_type from s_elevator_type_define where elevator_type_id= elevator_id) as elevator_type,lift_no,flow_ser, nonstd_level,branch_id,\
                         res_cm, action_id,(select name from s_employee where employee_id=res_cm) as res_cm_name, start_date, review_engineer , (select name from s_employee where employee_id=review_engineer) as review_engineer_name, (select  branch_name_cn from s_branch_info where branch_id=v_task_list4.branch_id) as branch_name,\
                         finish_date,is_active, (select issue_date from s_review_communication where review_task_id=v_task_list4.review_task_id and issue_status>=0 and issue_status<3) as issue_date from v_task_list4 where workflow_id='WF0001' AND flow_ser<=4 and is_latest=true and is_del=false and status>=0 ");

    if(b_from && b_to)
        s_sql = s_sql + wxT(" and finish_date >='")+DateToStrFormat(dt_from)+s_time+wxT("' and finish_date<='")+DateToStrFormat(dt_to)+s_time+wxT("' ");

    if (b_from && !b_to)
        s_sql = s_sql + wxT(" and finish_date>='")+DateToStrFormat(dt_from)+s_time+wxT("' ");

    if (!b_from && b_to)
        s_sql = s_sql + wxT(" and finish_date<='")+DateToStrFormat(dt_to)+s_time+wxT("' ");

    s_sql = s_sql +wxT(" order by instance_id, flow_ser Asc;");

    wxPostgreSQLresult* _res;

    _res = wxGetApp().app_sql_select(s_sql);


    wxString str_file = saveFileDialog.GetPath();

    save_file(str_file, _res);

    _res->Clear();

}

void project_info_panel::save_file(wxString s_path, wxPostgreSQLresult* _res)
{
    int i_count =  _res->GetRowsNumber();
    int i_col = array_excel_head.GetCount();

    if(i_count==0)
    {
        wxLogMessage("结果记录为0");
        return;
    }


    wxString str;
    workbook wb1;
    worksheet* ws = wb1.sheet("Sheet1");

    int i;

    for (i=0;i<i_col;i++)
    {
         ws->label(0,i,array_excel_head.Item(i).ToStdWstring());
    }

    _res->MoveFirst();
    wxString s_wbs_no, s_action;
    bool b_active = false;
    bool b_continue = false;
     i=0;
     wxDateTime d_finish,d_start;
    for(int  j=0;j<i_count;j++)
    {

        if(s_wbs_no != _res->GetVal(wxT("instance_id")))
        {
            b_continue=false;
            s_wbs_no = _res->GetVal(wxT("instance_id"));
            str = _res->GetVal(wxT("review_task_id"));
            ws->label(i+1, 0, str.ToStdString());
            str = NumToStr(_res->GetInt(wxT("review_drawing_qty")));
            ws->label(i+1, 1, str.ToStdString());
            str = _res->GetVal(wxT("contract_id"));
            ws->label(i+1, 2, str.ToStdString());
            str = _res->GetVal(wxT("project_name"));
            ws->label(i+1, 3, str.ToStdWstring());

            ws->label(i+1, 4, s_wbs_no.ToStdString());
            str = _res->GetVal(wxT("elevator_id"));
            ws->label(i+1, 5, str.ToStdString());
            str = _res->GetVal(wxT("elevator_type"));
            ws->label(i+1, 6, str.ToStdString());
            str = _res->GetVal(wxT("lift_no"));
            ws->label(i+1, 7, str.ToStdWstring());
            str = _res->GetVal(wxT("res_cm_name"));
            ws->label(i+1, 8, str.ToStdWstring());

            str = nstd_level_to_str(_res->GetInt(wxT("nonstd_level")));
            ws->label(i+1, 14, str.ToStdString());

            str = _res->GetVal(wxT("branch_name"));
            ws->label(i+1, 15, str.ToStdWstring());

            i+=1;
        }

        b_active = _res->GetBool(wxT("is_active"));

        if(b_continue)
        {
            _res->MoveNext();
            continue;
        }else
            b_continue = b_active;

        s_action = _res->GetVal(wxT("action_id"));
        d_start = _res->GetDateTime(wxT("start_date"));

        if(s_action=="AT00000002")
        {
            str =DateToAnsiStr(d_start);
            ws->label(i+1, 9, str.ToStdString());
        }

        if(s_action=="AT00000025")
        {
            str = DateToAnsiStr(d_start);
            ws->label(i+1, 11, str.ToStdString());
            str  = _res->GetVal(wxT("review_engineer_name"));
            ws->label(i+1, 10, str.ToStdWstring());
        }

        if (d_start <= _res->GetDateTime(wxT("issue_date")) and s_action=="AT00000025")
        {
                str = DateToAnsiStr(_res->GetDateTime(wxT("issue_date")));
                ws->label(i+1, 12, str.ToStdString());
        }

        d_finish = _res->GetDateTime(wxT("finish_date"));


        if(s_action=="AT00000026"&& !b_active)
        {
            str = DateToAnsiStr(d_finish);
            ws->label(i+1, 13, str.ToStdString());
        }


        _res->MoveNext();
    }

    std::string filename = s_path.ToStdString();
    int error_msg = wb1.Dump(filename);

    if(error_msg == NO_ERRORS)
    {
           wxMessageBox(_("导出完成!"),_("提示"));
    }
}

void project_info_panel::init_excel_head()
{
    wxString str;

    str = "任务号";
    array_excel_head.Add(str);
    str ="图纸套数";
    array_excel_head.Add(str);
    str = "合同号";
    array_excel_head.Add(str);
    str = "项目名称";
    array_excel_head.Add(str);
    str = "WBS NO";
    array_excel_head.Add(str);
    str = "梯型编号";
    array_excel_head.Add(str);
    str = "梯型";
    array_excel_head.Add(str);
    str = "梯号";
    array_excel_head.Add(str);
    str = "商务负责人";
    array_excel_head.Add(str);
    str = "启动评审日期";
    array_excel_head.Add(str);
    str = "评审工程师";
    array_excel_head.Add(str);
    str="评审授权日期";
    array_excel_head.Add(str);
    str = "最新一次评审反馈时间";
    array_excel_head.Add(str);
    str = "评审完成日期";
    array_excel_head.Add(str);
    str = "非标等级";
    array_excel_head.Add(str);
    str = "分公司";
    array_excel_head.Add(str);

}

void project_info_panel::Onmi_review_allSelected(wxCommandEvent& event)
{
   if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    wxString str;


    wxFileDialog     saveFileDialog(this, _("Save xls file"), "", "",
                                       "xls files (*.xls)|*.xls", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea..

    wxString s_sql = wxT("select review_task_id,review_drawing_qty,contract_id, project_name, instance_id, elevator_id,(select elevator_type from s_elevator_type_define where elevator_type_id= elevator_id) as elevator_type,lift_no, flow_ser, nonstd_level,branch_id,\
                         res_cm, action_id, (select name from s_employee where employee_id=res_cm) as res_cm_name, start_date, review_engineer , (select name from s_employee where employee_id=review_engineer) as review_engineer_name, (select  branch_name_cn from s_branch_info where branch_id=v_task_list4.branch_id) as branch_name,\
                         finish_date,is_active, (select issue_date from s_review_communication where review_task_id=v_task_list4.review_task_id and issue_status>=0 and issue_status<3) as issue_date from v_task_list4 where workflow_id='WF0001' AND flow_ser<=4 and is_latest=true and is_del=false and status>=0 ");


    s_sql = s_sql +wxT(" order by instance_id, flow_ser Asc;");

    wxPostgreSQLresult* _res;

    _res = wxGetApp().app_sql_select(s_sql);


    wxString str_file = saveFileDialog.GetPath();

    save_file(str_file, _res);
}
