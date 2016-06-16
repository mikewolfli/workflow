#include "wf_workflow_panel.h"

#include "wfApp.h"
#include "nstd_mat_task_list.h"
#include <wx/textdlg.h>
#include "return_log.h"
#include "ins_nonstd_proc_log.h"
#include <wx/choicdlg.h>
#include "evaluate_dlg.h"
#include "nstd_task_author.h"
#include "mydatepicker.h"
#include "datepickerdlg.h"
#include "nstd_task_tree_list.h"

//(*InternalHeaders(wf_workflow_panel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(wf_workflow_panel)
const long wf_workflow_panel::ID_BUTTON_FEEDBACK = wxNewId();
const long wf_workflow_panel::ID_BUTTON_PASS = wxNewId();
const long wf_workflow_panel::ID_BUTTON_HIDE = wxNewId();
const long wf_workflow_panel::ID_BUTTON_DISPLAY_TASKS = wxNewId();
const long wf_workflow_panel::ID_BUTTON_REFRESH = wxNewId();
const long wf_workflow_panel::ID_GRID_TASK = wxNewId();
const long wf_workflow_panel::ID_GRID_GROUP = wxNewId();
const long wf_workflow_panel::idMenu_REMARKS = wxNewId();
const long wf_workflow_panel::idMenu_Units = wxNewId();
const long wf_workflow_panel::IdMenu_MAT_INFO = wxNewId();
const long wf_workflow_panel::idMenu_RETURN = wxNewId();
const long wf_workflow_panel::idMenu_WORKFLOW = wxNewId();
const long wf_workflow_panel::idMenu_Nonstd_draw_require = wxNewId();
const long wf_workflow_panel::idMenu_Group_Filter = wxNewId();
const long wf_workflow_panel::idMenu_Date_filter = wxNewId();
const long wf_workflow_panel::idMenu_task_tree = wxNewId();
//*)

BEGIN_EVENT_TABLE(wf_workflow_panel,wxPanel)
	//(*EventTable(wf_workflow_panel)
	//*)
END_EVENT_TABLE()

wf_workflow_panel::wf_workflow_panel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(wf_workflow_panel)
	wxStaticBoxSizer* StaticBoxSizer2;
	wxStaticBoxSizer* sbs_group;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("流程操作"));
	Button1 = new wxButton(this, ID_BUTTON_FEEDBACK, _("退回"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_FEEDBACK"));
	StaticBoxSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON_PASS, _("完成"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_PASS"));
	StaticBoxSizer1->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button3 = new wxButton(this, ID_BUTTON_HIDE, _("显示/隐藏组员任务表"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_HIDE"));
	StaticBoxSizer1->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_DISPLAY = new wxButton(this, ID_BUTTON_DISPLAY_TASKS, _("显示/隐藏任务表"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_DISPLAY_TASKS"));
	StaticBoxSizer1->Add(Button_DISPLAY, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button4 = new wxButton(this, ID_BUTTON_REFRESH, _("刷新任务"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_REFRESH"));
	StaticBoxSizer1->Add(Button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 0);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("任务清单"));
	gd_task_list = new sqlResultGrid(this, ID_GRID_TASK, wxDefaultPosition, wxDefaultSize);
	StaticBoxSizer2->Add(gd_task_list, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(StaticBoxSizer2, 5, wxALL|wxEXPAND, 0);
	sbs_group = new wxStaticBoxSizer(wxHORIZONTAL, this, _("团队任务清单"));
	gd_group_task_list = new sqlResultGrid(this, ID_GRID_GROUP, wxDefaultPosition, wxDefaultSize);
	sbs_group->Add(gd_group_task_list, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(sbs_group, 5, wxALL|wxEXPAND, 0);
	SetSizer(BoxSizer1);
	MenuItem_REMARKS = new wxMenuItem((&menu_attach), idMenu_REMARKS, _("备注信息(&R)"), _("备注信息"), wxITEM_NORMAL);
	menu_attach.Append(MenuItem_REMARKS);
	menu_attach.AppendSeparator();
	MenuItem3 = new wxMenuItem((&menu_attach), idMenu_Units, _("相关项目(&U)"), _("显示相关项目"), wxITEM_NORMAL);
	menu_attach.Append(MenuItem3);
	MenuItem1 = new wxMenuItem((&menu_attach), IdMenu_MAT_INFO, _("显示配置物料清单(&M)\tM"), _("显示配置物料清单"), wxITEM_NORMAL);
	menu_attach.Append(MenuItem1);
	MenuItem_RETURN = new wxMenuItem((&menu_attach), idMenu_RETURN, _("显示退回源(&F)\tF"), _("显示退回源"), wxITEM_NORMAL);
	menu_attach.Append(MenuItem_RETURN);
	MenuItem_WORKFLOW = new wxMenuItem((&menu_attach), idMenu_WORKFLOW, _("显示工作流(&W)\tW"), _("显示工作流"), wxITEM_NORMAL);
	menu_attach.Append(MenuItem_WORKFLOW);
	menu_attach.AppendSeparator();
	MenuItem4 = new wxMenuItem((&menu_attach), idMenu_Nonstd_draw_require, _("更新非标图纸需求日(&D)"), _("更新非标图纸需求日"), wxITEM_NORMAL);
	menu_attach.Append(MenuItem4);
	MenuItem2 = new wxMenuItem((&menu_group), idMenu_Group_Filter, _("按人员筛选(&F)\tF"), _("按人员筛选"), wxITEM_NORMAL);
	menu_group.Append(MenuItem2);
	MenuItem5 = new wxMenuItem((&menu_group), idMenu_Date_filter, _("按日期筛选(&D)"), _("按日期筛选"), wxITEM_NORMAL);
	menu_group.Append(MenuItem5);
	MenuItem6 = new wxMenuItem((&menu_group), idMenu_task_tree, _("显示任务树(&T)"), wxEmptyString, wxITEM_NORMAL);
	menu_group.Append(MenuItem6);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON_FEEDBACK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wf_workflow_panel::OnButton1Click);
	Connect(ID_BUTTON_PASS,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wf_workflow_panel::OnButton2Click);
	Connect(ID_BUTTON_HIDE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wf_workflow_panel::OnButton3Click);
	Connect(ID_BUTTON_DISPLAY_TASKS,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wf_workflow_panel::OnButton_DISPLAYClick);
	Connect(ID_BUTTON_REFRESH,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wf_workflow_panel::OnButton4Click);
	Connect(ID_GRID_TASK,wxEVT_GRID_CELL_RIGHT_CLICK,(wxObjectEventFunction)&wf_workflow_panel::Ongd_task_listCellRightClick);
	Connect(ID_GRID_TASK,wxEVT_GRID_LABEL_RIGHT_CLICK,(wxObjectEventFunction)&wf_workflow_panel::Ongd_task_listCellRightClick);
	Connect(ID_GRID_GROUP,wxEVT_GRID_CELL_RIGHT_CLICK,(wxObjectEventFunction)&wf_workflow_panel::Ongd_group_task_listCellRightClick);
	Connect(ID_GRID_GROUP,wxEVT_GRID_LABEL_RIGHT_CLICK,(wxObjectEventFunction)&wf_workflow_panel::Ongd_group_task_listCellRightClick);
	Connect(idMenu_REMARKS,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wf_workflow_panel::OnMenuItem_REMARKSSelected);
	Connect(idMenu_Units,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wf_workflow_panel::OnMenuItem3Selected);
	Connect(IdMenu_MAT_INFO,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wf_workflow_panel::OnMenuItem1Selected);
	Connect(idMenu_RETURN,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wf_workflow_panel::OnMenuItem_RETURNSelected);
	Connect(idMenu_WORKFLOW,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wf_workflow_panel::OnMenuItem_WORKFLOWSelected);
	Connect(idMenu_Nonstd_draw_require,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wf_workflow_panel::OnMenuItem4Selected);
	Connect(idMenu_Group_Filter,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wf_workflow_panel::OnMenuItem2Selected);
	Connect(idMenu_Date_filter,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wf_workflow_panel::OnMenuItem5Selected);
	Connect(idMenu_task_tree,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wf_workflow_panel::OnMenuItem6Selected);
	//*)


    sb_group_tasks = sbs_group->GetStaticBox();
    sb_tasks = StaticBoxSizer2->GetStaticBox();

    sizer_group_task = BoxSizer1->GetItem(sbs_group);
    sizer_tasks = BoxSizer1->GetItem(StaticBoxSizer2);

    b_show = false;
    b_task_show=true;

    if(gr_para.login_status)
    {
        array_group = wxGetApp().get_group();
        for(int i=0; i<array_group.GetCount(); i++)
        {
            if(wxGetApp().is_leader(array_group.Item(i)))
                array_leader_group.Add(array_group.Item(i));
        }

        if(array_leader_group.GetCount()!=0)
        {
            b_show = true;

            sizer_tasks->SetProportion(5);
            sizer_group_task->SetProportion(5);

        }
        else
        {
            Button3->Show(false);
            Button_DISPLAY->Show(false);
            sizer_tasks->SetProportion(10);
        }
    }

    sb_group_tasks->Show(b_show);
    gd_group_task_list->Show(b_show);
    init_list_header();
    refresh_list();
    Layout();
}

wf_workflow_panel::~wf_workflow_panel()
{
	//(*Destroy(wf_workflow_panel)
	//*)
}

void wf_workflow_panel::OnButton1Click(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_task_list->GetSelectedRows();

    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项次，无法后续操作!"));
        return;
    }

    wxTextEntryDialog tdlg(this,_("退回提示输入:"),_("确认退回？"),wxT(""),wxOK | wxCANCEL | wxTE_MULTILINE,wxDefaultPosition );
    wxString str_desc, str_workflow_id, str_instance, str_action_id, str_flow_ser;
    if(tdlg.ShowModal()== wxID_OK)
    {
        str_desc= tdlg.GetValue();
    }else return;

    int i_count = array_sel_line.GetCount();

    v_wf_action * t_template=0;

    wxLongLong mils_used, start_mils;
    wf_operator * wf_active;

    bool b_sel = false;
    wxArrayString array_steps;
    wxString aim_step;

    for(int i=0; i<i_count; i++)
    {
        if(str_workflow_id != gd_task_list->GetCellValue(array_sel_line.Item(i),13))
        {
            str_workflow_id = gd_task_list->GetCellValue(array_sel_line.Item(i),13);
            if(t_template)
                delete [] t_template;
            t_template = get_template_action(str_workflow_id);
        }

        str_instance = gd_task_list->GetCellValue(array_sel_line.Item(i),1);
        if(str_action_id != gd_task_list->GetCellValue(array_sel_line.Item(i), 14))
        {
            str_action_id = gd_task_list->GetCellValue(array_sel_line.Item(i), 14);
            b_sel = false;
        }

        if(str_action_id == wxT("AT00000022") && check_sub_task(str_instance))
        {
            wxLogMessage(str_instance+ _(": 请到非标处理界面删除分任务后，再到此处退回!"));

            continue;
        }

        str_flow_ser = gd_task_list->GetCellValue(array_sel_line.Item(i), 19);

        if(!b_sel)
        {
            array_steps = get_steps_info(str_instance, str_workflow_id, str_flow_ser);

            if(array_steps.IsEmpty())
            {
                wxLogMessage(_("初始步骤无法退回!"));
                return;
            }
            wxSingleChoiceDialog cdlg(this, _("请选择退回到哪一步"),_("退回选择"),array_steps);

            if(cdlg.ShowModal() == wxID_OK)
            {
                int i_sel = cdlg.GetSelection();
                aim_step = m_steps.Item(i_sel).Left(10);
            }
            else return;

            b_sel = true;
        }

        start_mils = wxGetLocalTimeMillis();
        wf_active = new wf_operator(str_instance, str_workflow_id, t_template);
        wf_active->Feed_back(str_desc, aim_step);

        int i_status = nstd_action_to_status(wf_active->get_action_id());
        wf_active->update_instance_one2several(i_status);
        delete wf_active;

        if(str_action_id == wxT("AT00000011"))
        {
            update_operator(wxEmptyString, str_instance);
        }

        mils_used = wxGetLocalTimeMillis() - start_mils;

        wxLogMessage(str_instance+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒"));
    }

    refresh_list();
}

bool wf_workflow_panel::check_sub_task(wxString s_instance)
{
    wxString str_sql = wxT("select * from l_nonstd_app_item_instance where index_id='")+s_instance+wxT("';");
    wxPostgreSQLresult * _res=wxGetApp().app_sql_select(str_sql);

     if(_res->Status()!= PGRES_TUPLES_OK)
     {
        _res->Clear();
        return false;
     }

     int i_count = _res->GetRowsNumber();

     if(i_count >=1)
     {
         _res->Clear();
         return true;
     }else
     {
         _res->Clear();
         return false;
     }

}

void wf_workflow_panel::OnButton2Click(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_task_list->GetSelectedRows();
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项次，无法后续操作!"));
        return;
    }

    if(wxMessageBox(_("确认所选项次已经完成？"),_("完成确认："),wxOK|wxCANCEL,this)==wxCANCEL)
    {
        return;
    }

    int i_count = array_sel_line.GetCount();
    wxString str_workflow_id, str_instance, str_group, str_operator, str_temp, str_flow_mask, str_action_id, str_catalog;

    v_wf_action * t_template=0;

    wf_operator * wf_active=0;

    wf_process * l_proc_act =0;
    v_wf_instance now_step, next_step;

    wxLongLong mils_used, start_mils;

    bool b_goto = true;
    bool b_first = true;
    bool b_closed = false;
    for(int i=0; i<i_count; i++)
    {
        str_instance = gd_task_list->GetCellValue(array_sel_line.Item(i),1);

        str_action_id = gd_task_list->GetCellValue(array_sel_line.Item(i), 14);
        str_catalog = gd_task_list->GetCellValue(array_sel_line.Item(i), 15);
        str_flow_mask = gd_task_list->GetCellValue(array_sel_line.Item(i), 16);

        start_mils = wxGetLocalTimeMillis();
        if(str_workflow_id != gd_task_list->GetCellValue(array_sel_line.Item(i),13))
        {
            str_workflow_id = gd_task_list->GetCellValue(array_sel_line.Item(i),13);
            if(t_template)
                delete [] t_template;
            t_template = get_template_action(str_workflow_id);
        }


        wf_active = new wf_operator(str_instance, str_workflow_id, t_template);

        l_proc_act = wf_active->get_current_process();


        //for evaluate
        if(!make_evaluate(l_proc_act))
        {
            delete wf_active;
            l_proc_act = 0;
            continue;
        }

        l_proc_act->MoveToActive();

        //for evaluate

        if(str_action_id == wxT("AT00000022"))
        {
            if(wxMessageBox(_("工作流内无法操作此步骤，请到非标处理界面完成操作!"),_("提示"),wxOK)==wxOK)
                wxLogMessage(_("非标工作流界面无法操作此步骤!"));

            delete wf_active;
            l_proc_act = 0;

            continue;
        }

        if(str_action_id == wxT("AT00000010"))
        {
             if(str_catalog.Upper()== wxT("E"))
             {
                 str_group = wxT("G0007");

             }

             if(str_catalog.Upper() == wxT("M"))
             {
                 if(str_flow_mask.Left(2)==wxT("10"))
                    str_group = wxT("G0006");
                 else if(str_flow_mask.Left(2) == wxT("01"))
                    str_group = wxT("G0008");
                 else return;
             }

             str_operator = wxGetApp().get_leader(str_group);

        }else if(str_action_id == wxT("AT00000024"))
        {
 //           l_proc_act = wf_active->get_current_process();
            l_proc_act->MoveFirst();
            now_step = l_proc_act->get_cur_instance_action();
            str_group = now_step.s_action.s_group_id;
            str_operator = now_step.s_action.s_operator_id;

            l_proc_act->MoveToActive();
 //           l_proc_act =0;
        }
        else
        {
//            l_proc_act = wf_active->get_current_process();
            l_proc_act->MoveToActive();
            now_step = l_proc_act->get_cur_instance_action();

            if(now_step.s_action.s_operator_id!=gr_para.login_user && now_step.is_active)
                return;

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
            {
                b_goto = false;
                b_closed = true;
            }
            else
            {
                b_goto = true;
                b_closed = false;
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
                            return;
                            //                 b_first = true;
                        }

                        b_first  = false;

                        str_operator = cdlg.GetStringSelection();


                        int i_pos = str_operator.Find('-');

                        str_operator = str_operator.Left(i_pos);

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

 //           l_proc_act = 0;
        }


        wf_active->Pass_proc(str_operator, str_group, wxEmptyString, false);

        l_proc_act = 0;
        if(!b_closed)
        {
           int i_status = nstd_action_to_status(wf_active->get_action_id());
           wf_active->update_instance_one2several(i_status);
        }else
           wf_active->update_instance_one2several(10);
        delete wf_active;

        if(str_action_id == wxT("AT00000011"))
        {
            update_operator(str_operator, str_instance);
        }
//       b_first = true;

        mils_used = wxGetLocalTimeMillis() - start_mils;

        wxLogMessage(str_instance+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒"));
    }

    refresh_list();

}

bool wf_workflow_panel::make_evaluate(wf_process * s_process)
{
     v_wf_instance active_step, eval_step;

     s_process->MoveToActive();

     active_step = s_process->get_cur_instance_action();

     if(!active_step.s_action.b_is_evaluate&&!active_step.s_action.b_is_check)
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
     dlg.m_task = eval_step.s_instance_id;

     if(eval_step.s_action.s_workflow_id == wf_str_materials)
        dlg.m_eval_value = 1;

     if(eval_step.s_action.s_workflow_id == wf_str_design)
        dlg.m_eval_value = 4;

     if(eval_step.s_action.s_workflow_id == wf_str_nonstd)
        dlg.m_eval_value = 1;

     if(eval_step.s_action.s_workflow_id == wf_str_configure)
        dlg.m_eval_value = 8;


     if(dlg.ShowModal() == wxID_CANCEL)
         return false;

     return true;
}

bool wf_workflow_panel::update_operator(wxString s_operator, wxString s_instance)
{
   wxString l_query = wxT("UPDATE l_nonstd_app_item SET res_person='")+s_operator+wxT("',modify_emp_id ='")+gr_para.login_user+wxT("',modify_date ='")+DateToAnsiStr(wxDateTime::Now())+wxT("' where index_id = '")+s_instance+wxT("';");
   l_query.Replace(wxT("''"),wxT("NULL"));
   return wxGetApp().app_sql_update(l_query);
}

void wf_workflow_panel::OnButton3Click(wxCommandEvent& event)
{
    if(b_show)
    {
        b_show = false;


        sizer_group_task->Show(b_show);
        if(b_task_show)
              sizer_tasks->SetProportion(10);
    }
    else
    {
        b_show = true;

        if(b_task_show)
        {
             sizer_tasks->SetProportion(5);
             sizer_group_task->SetProportion(5);
        }else
             sizer_group_task->SetProportion(10);

    }

    sb_group_tasks->Show(b_show);
    gd_group_task_list->Show(b_show);


    refresh_group(b_show);
    Layout();
}

void wf_workflow_panel::OnButton4Click(wxCommandEvent& event)
{
    refresh_list();
}

void wf_workflow_panel::init_list_header()
{
    if(gd_task_list->GetNumberCols()!=20)
    {
        gd_task_list->CreateGrid(0,20);
        gd_task_list->SetRowLabelSize(20);
        gd_task_list->SetColLabelValue(0,_("任务"));
        gd_task_list->SetColSize(0,80);

        gd_task_list->SetColLabelValue(1,_("非标编号"));
        gd_task_list->SetColSize(1,100);


        gd_task_list->SetColLabelValue(2,_("非标物料编号"));
        gd_task_list->SetColSize(2,100);

        gd_task_list->SetColLabelValue(3,_("项目信息"));
        gd_task_list->SetColSize(3,100);

        gd_task_list->SetColLabelValue(4,_("状态"));
        gd_task_list->SetColSize(4,50);

        gd_task_list->SetColLabelValue(5, _("是否\n退回"));
        gd_task_list->SetColSize(5,50);

        gd_task_list->SetColLabelValue(6,_("物料需求日"));
        gd_task_list->SetColSize(6,100);

        gd_task_list->SetColLabelValue(7,_("图纸需求日"));
        gd_task_list->SetColSize(7,100);


        gd_task_list->SetColLabelValue(8,_("非标类别"));
        gd_task_list->SetColSize(8,80);

        gd_task_list->SetColLabelValue(9,_("非标原因"));
        gd_task_list->SetColSize(9,100);

        gd_task_list->SetColLabelValue(10,_("非标负责人ID"));
        gd_task_list->SetColSize(10,0);

        gd_task_list->SetColLabelValue(11,_("非标负责人"));
        gd_task_list->SetColSize(11,80);

        gd_task_list->SetColLabelValue(12,_("备注"));
        gd_task_list->SetColSize(12,100);

        gd_task_list->SetColLabelValue(13, _("工作流ID"));
        gd_task_list->SetColSize(13, 0);

        gd_task_list->SetColLabelValue(14,_("流程步骤ID"));
        gd_task_list->SetColSize(14,0);

        gd_task_list->SetColLabelValue(15,_("类别"));
        gd_task_list->SetColSize(15,0);

        gd_task_list->SetColLabelValue(16,_("非标掩码"));
        gd_task_list->SetColSize(16,0);

        gd_task_list->SetColLabelValue(17,_("退回次数"));
        gd_task_list->SetColSize(17,0);

        gd_task_list->SetColLabelValue(18,_("流程备注"));
        gd_task_list->SetColSize(18,100);

        gd_task_list->SetColLabelValue(19,_("工作步顺序号"));
        gd_task_list->SetColSize(19,0);

        for(int i=0; i<20; i++)
        {
            str_tasks_header = str_tasks_header + gd_task_list->GetColLabelValue(i)+wxT(";");
        }

    }

    if(gd_group_task_list->GetNumberCols()!=14)
    {
        gd_group_task_list->CreateGrid(0,14);
        gd_group_task_list->SetRowLabelSize(30);
        gd_group_task_list->SetColLabelValue(0,_("任务"));
        gd_group_task_list->SetColSize(0,80);

        gd_group_task_list->SetColLabelValue(1,_("非标编号"));
        gd_group_task_list->SetColSize(1,100);

        gd_group_task_list->SetColLabelValue(2,_("非标物料编号"));
        gd_group_task_list->SetColSize(2,100);

        gd_group_task_list->SetColLabelValue(3,_("操作人"));
        gd_group_task_list->SetColSize(3,100);

        gd_group_task_list->SetColLabelValue(4,_("项目信息"));
        gd_group_task_list->SetColSize(4,100);

        gd_group_task_list->SetColLabelValue(5,_("状态"));
        gd_group_task_list->SetColSize(5,50);

        gd_group_task_list->SetColLabelValue(6,_("是否\n退回"));
        gd_group_task_list->SetColSize(6,50);

        gd_group_task_list->SetColLabelValue(7,_("物料需求日"));
        gd_group_task_list->SetColSize(7,100);

        gd_group_task_list->SetColLabelValue(8,_("图纸需求日"));
        gd_group_task_list->SetColSize(8,100);

        gd_group_task_list->SetColLabelValue(9,_("非标类别"));
        gd_group_task_list->SetColSize(9,80);

        gd_group_task_list->SetColLabelValue(10,_("非标原因"));
        gd_group_task_list->SetColSize(10,100);

        gd_group_task_list->SetColLabelValue(11,_("非标负责人"));
        gd_group_task_list->SetColSize(11,80);

        gd_group_task_list->SetColLabelValue(12,_("备注"));
        gd_group_task_list->SetColSize(12,100);

        gd_group_task_list->SetColLabelValue(13,_("流程备注"));
        gd_group_task_list->SetColSize(13,100);


        for(int i=0; i<14; i++)
        {
            str_group_tasks_header = str_group_tasks_header + gd_group_task_list->GetColLabelValue(i)+wxT(";");
        }
    }

}

void wf_workflow_panel::refresh_list()
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

    wxPostgreSQLresult* _res;
    wxString str_query;

    str_query = wxT("(SELECT action_name, instance_id,(select nstd_mat_app_id from l_nonstd_app_item_instance where index_mat_id = instance_id) as  nstd_mat_app_id, concat(contract_id,' ', project_name,'-',project_id) as task_info, status, is_return, mat_req_date, drawing_req_date, nonstd_catalog,nonstd_desc, \
                     res_person, (select name from s_employee where employee_id = res_person) as res_name, remarks,  workflow_id, action_id ,  item_catalog,  flow_mask, return_time, (select doc_desc from s_doc where doc_id = step_desc_id) as doc_desc, \
                     flow_ser from v_task_list2 WHERE is_active = true AND operator_id = '")+gr_para.login_user+wxT("' ORDER BY  instance_id ASC )");

    str_query = str_query + wxT(" UNION ALL ")+wxT(" (SELECT action_name, instance_id,nstd_mat_app_id,concat(contract_id,' ', project_name,'-',project_id) as task_info, status, is_return, mat_req_date, drawing_req_date, nonstd_catalog,nonstd_desc, \
                     res_person, (select name from s_employee where employee_id = res_person) as res_name, remarks,  workflow_id, action_id ,  item_catalog,  flow_mask, return_time, (select doc_desc from s_doc where doc_id = step_desc_id) as doc_desc, \
                     flow_ser from v_task_list3 WHERE is_active = true AND operator_id = '")+gr_para.login_user+wxT("' ORDER BY  instance_id ASC ) ;");
//    wxLogMessage(str_query);
    _res = wxGetApp().app_sql_select(str_query);


    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        return;
    }

    m_rows = _res->GetRowsNumber();

//    gd_task_list->BeginBatch();

    wxGridUpdateLocker locker(gd_task_list);
    wxString str_table= wxT("l_proc_act");

    gd_task_list->SetTable(new sqlResultTable(_res, str_table, str_tasks_header,1), true);
    gd_task_list->SetSelectionMode(wxGrid::wxGridSelectRows);

    gd_task_list->Fit();
    gd_task_list->ForceRefresh();
 //   gd_task_list->EndBatch();
    gd_task_list->HideCol(10);
    gd_task_list->HideCol(13);
    gd_task_list->HideCol(14);
    gd_task_list->HideCol(15);
    gd_task_list->HideCol(16);
    gd_task_list->HideCol(17);
    gd_task_list->HideCol(19);

 //   gd_task_list->AutoSize();

    _res->Clear();

    refresh_group(b_show);
    Layout();

}

void wf_workflow_panel::refresh_group(bool b_sh)
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

    wxPostgreSQLresult* _res;
    wxString str_query1, str_query2;

    int icount = array_leader_group.GetCount();
    str_query1 = wxT("(SELECT action_name, instance_id,(select nstd_mat_app_id from l_nonstd_app_item_instance where index_mat_id = instance_id) as  nstd_mat_app_id, name, concat(contract_id,' ', project_name,'-',project_id) as task_info, status,is_return, mat_req_date, drawing_req_date, nonstd_catalog,nonstd_desc, \
                     (select name from s_employee where employee_id = res_person) as res_name, remarks, (select doc_desc from s_doc where doc_id = step_desc_id) as doc_desc  from v_task_list2 WHERE is_active = true AND operator_id != '")+gr_para.login_user+
                     wxT("' AND group_id = '")+array_leader_group.Item(0)+wxT("'  ");

    for(int i=1; i<icount; i++)
    {
        str_query1  = str_query1 + wxT(" OR group_id = '")+array_leader_group.Item(i)+wxT("' ");
    }

    str_query1 = str_query1 + wxT(" ORDER BY instance_id ASC )");

    str_query2 = str_query1;

    str_query2.Replace(wxT("v_task_list2"), wxT("v_task_list3"));

    wxString str_query = str_query1+ wxT(" UNION ALL ")+str_query2+wxT(";");

    _res = wxGetApp().app_sql_select(str_query);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        return;
    }

//    gd_group_task_list->BeginBatch();


    wxGridUpdateLocker locker(gd_group_task_list);
    wxString str_table= wxT("l_proc_act");
    gd_group_task_list->SetTable(new sqlResultTable(_res, str_table, str_group_tasks_header,1 ), true);
    gd_group_task_list->SetSelectionMode(wxGrid::wxGridSelectRows);
    gd_group_task_list->EnableEditing(false);
    gd_group_task_list->Fit();
    gd_group_task_list->ForceRefresh();
  //  gd_group_task_list->EndBatch();

    _res->Clear();


}

void wf_workflow_panel::Ongd_task_listCellRightClick(wxGridEvent& event)
{
    PopupMenu(&menu_attach, ScreenToClient(wxGetMousePosition()));
}

void wf_workflow_panel::OnMenuItem1Selected(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_task_list->GetSelectedRows();

    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }

    int i_count = array_sel_line.GetCount();

    wxString str_sql = wxT("select index_id,sequence,stno,mat_id,mat_name_cn, qty, unit, mat_comment, link_list from l_nonstd_configure_mat_list where ");

    int i_valid=0;
    for(int i=0;i<i_count;i++)
    {
        if(gd_task_list->GetCellValue(array_sel_line.Item(i),13) == wf_str_nonstd)
        {
           str_sql = str_sql + wxT(" index_id = '")+gd_task_list->GetCellValue(array_sel_line.Item(i),1)+wxT("' OR");
           i_valid++;
        }
    }

    if(i_valid==0)
    {
        wxLogMessage("你所选择的项次均不是非标申请工作流，请重新选择!");
        gd_task_list->ClearSelection();
        return;
    }

    str_sql.RemoveLast(2);
    str_sql= str_sql + wxT(" and is_active=true order by index_id,sequence ASC;");
    nstd_mat_task_list dlg;
    dlg.init_nstd_mat_header();
    dlg.Set_Query(str_sql);
    dlg.refresh_list();
    dlg.show_control(false);
    dlg.ShowModal();
}

void wf_workflow_panel::OnMenuItem_REMARKSSelected(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_task_list->GetSelectedRows();
    int i_count = array_sel_line.GetCount();

    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(i_count==0)
    {
        wxLogMessage(_("尚未选择项次，无法后续操作!"));
        return;
    }

    wxString s_instance,str_sql,str_desc, s_workflow;
    wxTextEntryDialog tdlg(this,_("备注说明输入:"),_("备注"),wxT(""),wxOK | wxCANCEL | wxTE_MULTILINE,wxDefaultPosition );
    if(tdlg.ShowModal()== wxID_OK)
    {
        str_desc= tdlg.GetValue();
    }else return;

    if(str_desc.IsEmpty())
        return;

    wxString str_id = wxGetApp().get_ser_no(wxT("s_doc"),wxT("doc_id"));
    wxGetApp().update_desc(str_id,str_desc,false);

    for(int i=0;i<i_count;i++)
    {
       s_instance = gd_task_list->GetCellValue(array_sel_line.Item(i),1);
       s_workflow = gd_task_list->GetCellValue(array_sel_line.Item(i),13);
       str_sql = wxT("UPDATE l_proc_act SET step_desc_id= '")+str_id+wxT("' WHERE instance_id='")+s_instance+wxT("' AND \
              operator_id = '")+gr_para.login_user+wxT("' AND is_active = true AND workflow_id = '")+s_workflow+wxT("';");
       if(wxGetApp().app_sql_update(str_sql))
              gd_task_list->SetCellValue(array_sel_line.Item(i),17,str_desc);

    }

    refresh_group(b_show);

}

void wf_workflow_panel::OnMenuItem_RETURNSelected(wxCommandEvent& event)
{

    wxArrayInt array_sel_line = gd_task_list->GetSelectedRows();
    int i_count = array_sel_line.GetCount();

    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(i_count==0)
    {
        wxLogMessage(_("尚未选择项次，无法后续操作!"));
        return;
    }

     wxArrayString array_return, array_return_time;

     wxString str;
     for(int i=0;i<i_count;i++)
     {
         if(gd_task_list->GetCellValue(array_sel_line.Item(i),5)==wxT("Y"))
         {
             str = gd_task_list->GetCellValue(array_sel_line.Item(i),1);
             array_return.Add(str);

             str = gd_task_list->GetCellValue(array_sel_line.Item(i),17);
             array_return_time.Add(str);
         }
     }

    if(array_return.IsEmpty())
    {
        wxLogMessage(_("无退回记录!"));
        return;
    }

    return_log return_log_dlg;

    return_log_dlg.Refresh_list_view(array_return,array_return_time);
    return_log_dlg.ShowModal();

}

void wf_workflow_panel::OnMenuItem_WORKFLOWSelected(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_task_list->GetSelectedRows();
    int i_count = array_sel_line.GetCount();

    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(i_count==0)
    {
        wxLogMessage(_("尚未选择项次，无法后续操作!"));
        return;
    }

    wxArrayString array_sel_ins, array_sel_workflow;
    wxString str;

    for(int i =0;i<i_count;i++)
    {
        str = gd_task_list->GetCellValue(array_sel_line.Item(i), 1);
        array_sel_ins.Add(str);

        str = gd_task_list->GetCellValue(array_sel_line.Item(i),13);
        array_sel_workflow.Add(str);
    }

    ins_nonstd_proc_log ipl_dlg;

    ipl_dlg.Refresh_list_view(array_sel_ins, array_sel_workflow);
    ipl_dlg.ShowModal();
}

wxArrayString wf_workflow_panel::get_steps_info(wxString &s_instance_id, wxString &s_workflow_id, wxString &s_now)
{

     wxString strSql;
    if(s_workflow_id == wf_str_nonstd)
        strSql = wxT("select concat(action_id,'-',operator_id) as action_id, concat(action_name,'-', name) as step_info from v_task_list2 where workflow_id = '")+
                   s_workflow_id+wxT("' and instance_id = '")+ s_instance_id+wxT("' and flow_ser < ")+ s_now+wxT(" order by flow_ser ASC;");

    if(s_workflow_id == wf_str_design || s_workflow_id == wf_str_materials)
        strSql = wxT("select concat(action_id,'-',operator_id) as action_id, concat(action_name,'-', name) as step_info from v_task_list3 where workflow_id = '")+
                   s_workflow_id+wxT("' and instance_id = '")+ s_instance_id+wxT("' and flow_ser < ")+ s_now+wxT(" order by flow_ser ASC;");

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

void wf_workflow_panel::OnMenuItem2Selected(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    wxString str_group,str_user;
    str_group = wxGetApp().get_only_group();
    wxArrayString  s_members = wxGetApp().get_member_in_group(str_group);

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


    wxPostgreSQLresult* _res;
    wxString str_query1, str_query2;

    int icount = array_leader_group.GetCount();
    str_query1 = wxT("(SELECT action_name, instance_id,(select nstd_mat_app_id from l_nonstd_app_item_instance where index_mat_id = instance_id) as  nstd_mat_app_id, name, concat(contract_id,' ', project_name,'-',project_id) as task_info, status,is_return, mat_req_date, drawing_req_date, nonstd_catalog,nonstd_desc, \
                     (select name from s_employee where employee_id = res_person) as res_name, remarks, (select doc_desc from s_doc where doc_id = step_desc_id) as doc_desc  from v_task_list2 WHERE is_active = true AND operator_id = '")+str_user+
                     wxT("' ");

    for(int i=1; i<icount; i++)
    {
        str_query1  = str_query1 + wxT(" OR group_id = '")+array_leader_group.Item(i)+wxT("' ");
    }

    str_query1 = str_query1 + wxT(" ORDER BY instance_id ASC )");

    str_query2 = str_query1;

    str_query2.Replace(wxT("v_task_list2"), wxT("v_task_list3"));

    wxString str_query = str_query1+ wxT(" UNION ALL ")+str_query2+wxT(";");

    _res = wxGetApp().app_sql_select(str_query);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        return;
    }

//    gd_group_task_list->BeginBatch();
    wxGridUpdateLocker locker(gd_group_task_list);
    wxString str_table= wxT("l_proc_act");
    gd_group_task_list->SetTable(new sqlResultTable(_res, str_table, str_group_tasks_header,1 ), true);
    gd_group_task_list->EnableEditing(false);
    gd_group_task_list->Fit();
    gd_group_task_list->ForceRefresh();
  //  gd_group_task_list->EndBatch();

    _res->Clear();

    Layout();


}

void wf_workflow_panel::Ongd_group_task_listCellRightClick(wxGridEvent& event)
{
    PopupMenu(&menu_group, ScreenToClient(wxGetMousePosition()));
}

void wf_workflow_panel::OnMenuItem3Selected(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    wxArrayInt array_sel_line = gd_task_list->GetSelectedRows();
    int i_count = array_sel_line.GetCount();


    if(i_count==0)
    {
        wxLogMessage(_("尚未选择项次，无法后续操作!"));
        return;
    }

    wxArrayString array_units, array_str;
    wxString str_instance_id, str_workflow,str;

    for(int i =0;i<i_count;i++)
    {
        str_instance_id = gd_task_list->GetCellValue(array_sel_line.Item(i), 1);

        str_workflow = gd_task_list->GetCellValue(array_sel_line.Item(i),13);

        array_str = get_unit_list(str_instance_id, str_workflow);
        i_count = array_str.GetCount();

        for(int i=0;i<i_count;i++)
        {
             str = array_str.Item(i);
             if(array_units.Index(str)== wxNOT_FOUND)
                array_units.Add(str);
        }

        array_str.Clear();
    }

    nstd_task_author dlg;

    dlg.m_units = array_units;
    dlg.refresh_list();
    array_units.Clear();
    dlg.ShowModal();
}

wxArrayString wf_workflow_panel::get_unit_list(wxString str_task_id, wxString str_workflow)
{
    wxArrayString array_units;
    wxString str;

    if(str_workflow.IsEmpty())
         return array_units;

    if(str_workflow == wxT("WF0004")||str_workflow == wxT("WF0005"))
    {
        str_task_id.RemoveLast(2);

    }

    wxString str_sql = wxT("select link_list from l_nonstd_app_item where index_id = ")+str_task_id+wxT("'; ");
    wxPostgreSQLresult* _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return array_units;
    }

    int i_count = _res->GetRowsNumber();

    if(i_count >0)
    {
        _res->MoveFirst();
        str = _res->GetVal(wxT("link_list"));

        if(str.IsEmpty())
            return array_units;

        array_units = wxStringTokenize(str ,wxT(";"), wxTOKEN_RET_EMPTY  );

    }

    return array_units;

}

void wf_workflow_panel::OnMenuItem4Selected(wxCommandEvent& event)
{


    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    wxString s_group = wxGetApp().get_only_group();

   if(s_group != wxT("G0003")&&s_group != wxT("G0004")&& s_group != wxT("G0005"))
    {
        wxLogMessage(_("只有配置组才有权限修改此日期!"));
        return;
    }

    wxArrayInt array_sel_line = gd_task_list->GetSelectedRows();
    int i_count = array_sel_line.GetCount();

    if(i_count==0)
    {
        wxLogMessage(_("尚未选择项次，无法后续操作!"));
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

    wxString s_nonstd_id,s_nonstd_index_id, s_old_date, s_action_id;
    for(int i=0;i<i_count; i++)
    {
         s_action_id = gd_task_list->GetCellValue(array_sel_line.Item(i),14);
         s_nonstd_index_id = gd_task_list->GetCellValue(array_sel_line.Item(i),1);

         if(s_action_id != wxT("AT00000009"))
         {
             wxLogMessage(_("非标申请起始步时，才能更改需求日期, 此任务号无法更改:")+s_nonstd_id);
             continue;
         }
         s_old_date = gd_task_list->GetCellValue(array_sel_line.Item(i),7);

         s_old_date = s_old_date + wxT(" 23:00:00");



         int i_pos = s_nonstd_index_id.Find(wxT("-"));

         s_nonstd_id = s_nonstd_index_id.Left(i_pos);

         if(update_require_drawing(s_nonstd_id, s_date_ex))
         {
                wxGetApp().change_log(wxT("l_nonstd_app_header"),s_nonstd_id, wxT("drawing_req_date"), s_old_date, s_date_ex);
                wxLogMessage(s_nonstd_index_id+_("非标设计需求日变更成功!"));

                gd_task_list->SetCellValue(array_sel_line.Item(i),7, s_date);
         }
    }


}

bool wf_workflow_panel::update_require_drawing(wxString s_task_id, wxString s_date)
{
    wxString str_sql = wxT("UPDATE l_nonstd_app_header SET drawing_req_date='")+s_date+wxT("',modify_date = '")+DateToAnsiStr(wxDateTime::Now())+
                       wxT("',modify_emp_id = '")+gr_para.login_user+wxT("' WHERE nonstd_id ='")+ s_task_id+wxT("';");

    return wxGetApp().app_sql_update(str_sql);
}

void wf_workflow_panel::OnMenuItem5Selected(wxCommandEvent& event)//按日期筛选
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    datepickerdlg dlg;

    if(dlg.ShowModal()==wxID_CANCEL)
    {
        return;
    }

    bool b_from = dlg.b_from;
    bool b_to = dlg.b_to;

    wxDateTime dt_from,dt_to;

    if(b_from)
        dt_from = dlg.dt_from;

    if(b_to)
        dt_to = dlg.dt_to;

    wxString str_sql1, str_sql2, str_sql;

    wxString s_time = wxT(" 23:00:00");

    str_sql1 = wxT("(SELECT action_name, instance_id,(select nstd_mat_app_id from l_nonstd_app_item_instance where index_mat_id = instance_id) as  nstd_mat_app_id, name, concat(contract_id,' ', project_name,'-',project_id) as task_info, status,is_return, mat_req_date, drawing_req_date, nonstd_catalog,nonstd_desc, \
                     (select name from s_employee where employee_id = res_person) as res_name, remarks, (select doc_desc from s_doc where doc_id = step_desc_id) as doc_desc  from v_task_list2 WHERE is_active = true AND operator_id != '")+gr_para.login_user+
                     wxT("' AND group_id = '")+array_leader_group.Item(0)+wxT("'  ");

    if(b_from && b_to)
        str_sql1 = str_sql1 + wxT("and drawing_req_date <='")+DateToStrFormat(dt_to)+s_time+wxT("' and drawing_req_date >='")+DateToStrFormat(dt_from)+s_time+wxT("' ");

    if(b_from && !b_to)
        str_sql1 = str_sql1 + wxT("and drawing_req_date >='")+DateToStrFormat(dt_from)+s_time+wxT("' ");

    if(!b_from && b_to)
        str_sql1 = str_sql1 + wxT("and drawing_req_date <='")+DateToStrFormat(dt_to)+s_time+wxT("' ");

    str_sql1 = str_sql1 + wxT(" order by drawing_req_date, instance_id ASC) ");

    str_sql2 = str_sql1;

    str_sql2.Replace(wxT("v_task_list2"), wxT("v_task_list3"));

    str_sql = str_sql1 + wxT(" union all ")+ str_sql2 +wxT(";");

    wxPostgreSQLresult* _res;

    _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        return;
    }

//    gd_group_task_list->BeginBatch();
    wxGridUpdateLocker locker(gd_group_task_list);
    wxString str_table= wxT("l_proc_act");
    gd_group_task_list->SetTable(new sqlResultTable(_res, str_table, str_group_tasks_header,1 ), true);
    gd_group_task_list->EnableEditing(false);
    gd_group_task_list->Fit();
    gd_group_task_list->ForceRefresh();
  //  gd_group_task_list->EndBatch();

    _res->Clear();
    Layout();
}

void wf_workflow_panel::OnMenuItem6Selected(wxCommandEvent& event)//显示任务树。
{
    wxArrayInt array_sel_line = gd_group_task_list->GetSelectedRows();

    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }

    int i_count = array_sel_line.GetCount();

    wxArrayString array_task_list;
    wxString s_nstd_id,str;
    int i_pos;

    for(int i=0;i<i_count;i++)
    {
          s_nstd_id = gd_group_task_list->GetCellValue(array_sel_line.Item(i), 1);
          if(s_nstd_id.Freq('-')==2)
          {

               i_pos = s_nstd_id.Find('-',true);
               str= s_nstd_id.Left(i_pos);

               if(array_task_list.Index(str) != wxNOT_FOUND)
                    continue;

               array_task_list.Add(str);

          }else
            {
                 if(array_task_list.Index(s_nstd_id)!=wxNOT_FOUND)
                    continue;
                 array_task_list.Add(s_nstd_id);
            }
    }

    nstd_task_tree_list dlg;

    dlg.init_tree_list(array_task_list);
    dlg.ShowModal();

}

void wf_workflow_panel::OnButton_DISPLAYClick(wxCommandEvent& event)
{
    if(b_task_show)
    {
        b_task_show = false;


        sizer_tasks->Show(b_task_show);
        if(b_show)
              sizer_group_task->SetProportion(10);
    }
    else
    {
        b_task_show = true;

        if(b_show)
        {
            sizer_tasks->SetProportion(5);
            sizer_group_task->SetProportion(5);

        }else
        {
            sizer_tasks->SetProportion(10);
        }
    }

    sb_tasks->Show(b_task_show);
    gd_task_list->Show(b_task_show);

    Layout();
}
