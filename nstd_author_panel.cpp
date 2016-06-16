#include "nstd_author_panel.h"
#include "wfApp.h"
#include "nstd_task_author.h"
#include "ins_nonstd_proc_log.h"

//(*InternalHeaders(nstd_author_panel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(nstd_author_panel)
const long nstd_author_panel::ID_GRID_TASK = wxNewId();
const long nstd_author_panel::ID_BUTTON2 = wxNewId();
const long nstd_author_panel::ID_BUTTON_REFRESH = wxNewId();
const long nstd_author_panel::ID_BUTTON_APPROVE = wxNewId();
const long nstd_author_panel::ID_LISTCTRL_RES = wxNewId();
const long nstd_author_panel::idMenu_INFO = wxNewId();
const long nstd_author_panel::idMenu_WORKFLOW = wxNewId();
//*)

BEGIN_EVENT_TABLE(nstd_author_panel,wxPanel)
	//(*EventTable(nstd_author_panel)
	//*)
END_EVENT_TABLE()

nstd_author_panel::nstd_author_panel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(nstd_author_panel)
	wxStaticBoxSizer* StaticBoxSizer2;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("非标任务清单"));
	gd_task_list = new nstdappGrid(this, ID_GRID_TASK, wxDefaultPosition, wxSize(121,888));
	StaticBoxSizer1->Add(gd_task_list, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(StaticBoxSizer1, 3, wxALL|wxEXPAND, 0);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	Button2 = new wxButton(this, ID_BUTTON2, _("任务授权"), wxDefaultPosition, wxSize(108,40), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button2, 1, wxALL|wxEXPAND, 0);
	Button3 = new wxButton(this, ID_BUTTON_REFRESH, _("刷新"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_REFRESH"));
	BoxSizer2->Add(Button3, 1, wxALL|wxEXPAND, 0);
	Button_APPROVE = new wxButton(this, ID_BUTTON_APPROVE, _("审核通过"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_APPROVE"));
	Button_APPROVE->Hide();
	BoxSizer2->Add(Button_APPROVE, 1, wxALL|wxEXPAND, 0);
	BoxSizer3->Add(BoxSizer2, 1, wxALL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("非标工程师"));
	lc_res = new wxListCtrl(this, ID_LISTCTRL_RES, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_HRULES|wxLC_VRULES, wxDefaultValidator, _T("ID_LISTCTRL_RES"));
	StaticBoxSizer2->Add(lc_res, 1, wxALL|wxEXPAND, 0);
	BoxSizer3->Add(StaticBoxSizer2, 6, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxEXPAND, 0);
	SetSizer(BoxSizer1);
	MenuItem1 = new wxMenuItem((&Task_info), idMenu_INFO, _("任务信息(&I)"), _("任务信息"), wxITEM_NORMAL);
	Task_info.Append(MenuItem1);
	MenuItem2 = new wxMenuItem((&Task_info), idMenu_WORKFLOW, _("显示工作流(&W)"), _("显示工作流"), wxITEM_NORMAL);
	Task_info.Append(MenuItem2);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_GRID_TASK,wxEVT_GRID_CELL_RIGHT_CLICK,(wxObjectEventFunction)&nstd_author_panel::Ongd_task_listCellRightClick);
	Connect(ID_GRID_TASK,wxEVT_GRID_LABEL_RIGHT_CLICK,(wxObjectEventFunction)&nstd_author_panel::Ongd_task_listCellRightClick);
	//Connect(ID_GRID_TASK,wxEVT_GRID_SELECT_CELL,(wxObjectEventFunction)&nstd_author_panel::Ongd_task_listCellChange);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_author_panel::OnButton2Click);
	Connect(ID_BUTTON_REFRESH,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_author_panel::OnButton3Click);
	Connect(ID_BUTTON_APPROVE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_author_panel::OnButton_APPROVEClick);
	Connect(idMenu_INFO,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&nstd_author_panel::OnMenuItem1Selected);
	Connect(idMenu_WORKFLOW,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&nstd_author_panel::OnMenuItem2Selected);
	//*)

	init_list_header();
	refresh_res_list();

	refresh_list();
    enable_control(true);

}

nstd_author_panel::~nstd_author_panel()
{
	//(*Destroy(nstd_author_panel)
	//*)
}


void nstd_author_panel::OnButton2Click(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_task_list->GetSelectedRows();
    if(array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }

    long l_item = -1;
    l_item = lc_res->GetNextItem(l_item,  wxLIST_NEXT_ALL,  wxLIST_STATE_SELECTED);

    wxString s_nstd_app_item_id, s_operator, s_group, s_res;
    wxListItem li_item;
    if(l_item == -1)
    {
        wxLogMessage(_("请选择操作人员！"));
        return;
    }
    else{
        li_item.m_itemId = l_item;

        s_res = lc_res->GetItemText(li_item, 0);
        s_operator = s_res.Left(8);
        s_group = lc_res->GetItemText(li_item, 2);
    }


    if(wxMessageBox(_("所选项目确认授权给")+s_res,_("授权确认："),wxOK|wxCANCEL,this)==wxCANCEL)
    {
        return;
    }

    wxString str_workflow_id, str_temp;

    v_wf_action * t_template=0;

    wf_operator * wf_active=0;

    v_wf_instance now_step, next_step;

    wxLongLong mils_used, start_mils;

    t_template = get_template_action(wf_str_nonstd);

    int i_count = array_sel_line.GetCount();

    for(int i=0; i<i_count; i++)
    {

        s_nstd_app_item_id = gd_task_list->GetCellValue(array_sel_line.Item(i),0);
  /*       wxString s_value = get_num_value(s_nstd_app_item_id);
       wxString s_fill = gd_task_list->GetCellValue(array_sel_line.Item(i),6);

        if(s_fill.IsEmpty()||!s_fill.IsNumber())
        {
            gd_task_list->SetGridCursor(array_sel_line.Item(i),6);

            wxLogMessage("请输入分值分布(数值)!");

            continue;

        }

        if(s_value.IsEmpty() || s_value != s_fill)
        {
            gd_task_list->SetGridCursor(array_sel_line.Item(i),6);


            gd_task_list->GetTable()->SetValue(array_sel_line.Item(i),6,s_fill);
            gd_task_list->GetTable()->StoreLine();

        }*/


        int i_len = s_nstd_app_item_id.Length();
        if(!s_nstd_app_item_id.Right(1).IsNumber())
        {
            s_nstd_app_item_id = s_nstd_app_item_id.Left(i_len-3);
        }

        start_mils = wxGetLocalTimeMillis();//事件处理事件统计，起始点。

        wf_active = new wf_operator(s_nstd_app_item_id, wf_str_nonstd, t_template);

        wf_active->Pass_proc(s_operator, s_group, wxEmptyString, true);

        int i_status = nstd_action_to_status(wf_active->get_action_id());
        wf_active->update_instance_one2several(i_status);

        update_operator(s_operator, s_nstd_app_item_id);

        delete wf_active;

        mils_used = wxGetLocalTimeMillis() - start_mils;

        wxLogMessage(s_nstd_app_item_id+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒")); //事件处理事件统计，截止点。

    }
    refresh_list();
    refresh_res_list();
}

void nstd_author_panel::OnButton3Click(wxCommandEvent& event)
{
   	refresh_res_list();

	refresh_list();
}
/*
wxString nstd_author_panel::get_num_value(wxString s_index_id)
{
    wxString str_sql = wxT("SELECT nonstd_value FROM l_nonstd_app_item WHERE index_id = '")+s_index_id+wxT("';");

    wxPostgreSQLresult* _res;
     _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return wxEmptyString;
    }

    int i_count = _res->GetRowsNumber();

    if(i_count ==0)
    {
        _res->Clear();
        return wxEmptyString;
    }

    _res->MoveFirst();

    wxString str = _res->GetVal(wxT("nonstd_value"));
    _res->Clear();
    return str;
}
*/
void nstd_author_panel::init_list_header()
{
    wxListItem itemCol;
    itemCol.SetText(_("非标工程师"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(150);
    lc_res->InsertColumn(0, itemCol);

    itemCol.SetText(_("任务数"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(60);
    lc_res->InsertColumn(1, itemCol);

    itemCol.SetText(_("组号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(0);
    lc_res->InsertColumn(2, itemCol);

    itemCol.SetText(_("子任务数"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(80);
    lc_res->InsertColumn(3, itemCol);


    if(gd_task_list->GetNumberCols()!=13)
    {
        gd_task_list->CreateGrid(0,13);
        gd_task_list->SetRowLabelSize(20);
        gd_task_list->SetColLabelValue(0,_("非标编号"));
        gd_task_list->SetColSize(0,80);

        gd_task_list->SetColLabelValue(1,_("项目信息"));
        gd_task_list->SetColSize(1,150);

        gd_task_list->SetColLabelValue(2,_("物料\n需求日"));
        gd_task_list->SetColSize(2,80);

        gd_task_list->SetColLabelValue(3,_("图纸\n需求日"));
        gd_task_list->SetColSize(3,80);

        gd_task_list->SetColLabelValue(4,_("非标类别"));
        gd_task_list->SetColSize(4,100);

        gd_task_list->SetColLabelValue(5,_("非标原因"));
        gd_task_list->SetColSize(5,100);

        gd_task_list->SetColLabelValue(6,_("分值分布"));
        gd_task_list->SetColSize(6,0);

        gd_task_list->SetColLabelValue(7,_("非标负责人"));
        gd_task_list->SetColSize(7,100);

        gd_task_list->SetColLabelValue(8,_("备注"));
        gd_task_list->SetColSize(8,0);

        gd_task_list->SetColLabelValue(9, _("工作流ID"));
        gd_task_list->SetColSize(9, 0);

        gd_task_list->SetColLabelValue(10,_("流程步骤ID"));
        gd_task_list->SetColSize(10,0);

        gd_task_list->SetColLabelValue(11,_("关联梯"));
        gd_task_list->SetColSize(11,0);

        gd_task_list->SetColLabelValue(12,_("非标负责人ID"));
        gd_task_list->SetColSize(12,0);

        for(int i=0; i<13; i++)
        {
            str_tasks_header = str_tasks_header + gd_task_list->GetColLabelValue(i)+wxT(";");
        }

    }

}

void nstd_author_panel::refresh_res_list()
{
    lc_res->DeleteAllItems();

    wxString str_group = wxGetApp().get_only_group();
    if(!wxGetApp().is_leader(str_group))
        return;

    wxString strSql = wxT("SELECT concat(employee_id,'-',name) AS res_person, (select count(*) from l_proc_act \
                          where operator_id = employee_id AND is_active=true AND action_id = 'AT00000022') AS task_qty, (select count(*) from l_nonstd_app_item_instance where res_engineer=employee_id and status=1) as sub_task_qty, \
                          group_id FROM v_group_member WHERE group_id = '")+str_group+wxT("' AND plant = '")+gr_para.plant+wxT("' and employee_id !='")+gr_para.login_user+wxT("' and status=true ORDER BY res_person ASC;");
    wxPostgreSQLresult* _res = wxGetApp().app_sql_select(strSql);
  //  wxLogMessage(strSql);

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

        str = _res->GetVal(wxT("task_qty"));
        lc_res->SetItem(tmp,1,str);


        str = _res->GetVal(wxT("group_id"));
        lc_res->SetItem(tmp,2,str);

        str=_res->GetVal(wxT("sub_task_qty"));
        lc_res->SetItem(tmp, 3, str);

        _res->MoveNext();
    }

    _res->Clear();
}

void nstd_author_panel::refresh_list()
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
    wxString strSql = wxT("SELECT index_id, concat(contract_id,' ', project_name,'-',project_id) as project_name, mat_req_date, drawing_req_date, \
                          nonstd_catalog, nonstd_desc, nonstd_value, (select name from s_employee where employee_id = res_person) as engineering,\
                          remarks, workflow_id, action_id, link_list, res_person from v_task_list2 where action_id = 'AT00000011'  and is_active = true and operator_id ='")+gr_para.login_user+wxT("' \
                          order by index_id ASC;");
    wxPostgreSQLresult* _res;
     _res = wxGetApp().app_sql_select(strSql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    gd_task_list->ClearGrid();

//    gd_task_list->BeginBatch();
    wxGridUpdateLocker locker(gd_task_list);
    wxString str_table= wxT("l_nonstd_app_item");
    wxString str_key = wxT("index_id");
    gd_task_list->SetTable(new nstdappTable(_res, str_table, str_tasks_header,wxT("0000001000001"), str_key), true);
    gd_task_list->SetSelectionMode(wxGrid::wxGridSelectRows);
    gd_task_list->Fit();

 //   gd_task_list->EndBatch();
    gd_task_list->SetColSize(6, 0);
    gd_task_list->SetColSize(8,0);
    gd_task_list->SetColSize(9,0);
    gd_task_list->SetColSize(10,0);
    gd_task_list->SetColSize(11,0);
    gd_task_list->SetColSize(12,0);
    Layout();
    _res->Clear();


}

void nstd_author_panel::enable_control(bool b_edit)
{
    gd_task_list->EnableEditing(true);
}

bool nstd_author_panel::update_operator(wxString s_operator, wxString s_instance)
{
   wxString l_query = wxT("UPDATE l_nonstd_app_item SET res_person='")+s_operator+wxT("',modify_emp_id ='")+gr_para.login_user+wxT("',modify_date ='")+DateToAnsiStr(wxDateTime::Now())+wxT("' where index_id = '")+s_instance+wxT("';");
   l_query.Replace(wxT("''"),wxT("NULL"));
   return wxGetApp().app_sql_update(l_query);
}

void nstd_author_panel::Ongd_task_listCellRightClick(wxGridEvent& event)
{
    PopupMenu(&Task_info, event.GetPosition());
}

void nstd_author_panel::OnMenuItem1Selected(wxCommandEvent& event)
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

    wxArrayString array_units;

    for(int i=0;i<i_count;i++)
    {
        wxString str = gd_task_list->GetCellValue(array_sel_line.Item(i),11);

        if(str.IsEmpty())
            continue;

        wxArrayString array_str = wxStringTokenize(str ,wxT(";"), wxTOKEN_DEFAULT  );

        for(int j=0;j<array_str.GetCount();j++)
        {
            if(find_in_array(array_str.Item(j),array_units)==-1)
                  array_units.Add(array_str.Item(j));
        }

        array_str.Clear();
    }

    nstd_task_author dlg;

    dlg.m_units = array_units;
    dlg.refresh_list();
    dlg.ShowModal();

}
/*
void nstd_author_panel::Ongd_task_listCellChange(wxGridEvent& event)
{
    nstdappTable * table = gd_task_list->GetTable();

    bool doSkip = true;

	if (table)
	{
		if (table->LastRow() >= 0)
		{
			if (table->LastRow() != event.GetRow())
			{
				doSkip = doSave();
			}
		}
		else if (gd_task_list->GetGridCursorRow() != event.GetRow())
		{
		}
	}

	if (doSkip)
		event.Skip();
}

bool nstd_author_panel::doSave()
{
    gd_task_list->HideCellEditControl();
    gd_task_list->SaveEditControlValue();
    gd_task_list->DisableCellEditControl();

    if (!gd_task_list->GetTable()->StoreLine())
		return false;

    return true;
}*/


void nstd_author_panel::OnButton_APPROVEClick(wxCommandEvent& event)
{
}


void nstd_author_panel::OnMenuItem2Selected(wxCommandEvent& event)
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

    wxArrayString array_sel_workflow, array_sel_ins;
    wxString str;

    for(int i=0;i<i_count;i++)
    {
        str = wf_str_nonstd;
        array_sel_workflow.Add(str);
        str = gd_task_list->GetCellValue(array_sel_line.Item(i),0);
        array_sel_ins.Add(str);
    }
    array_sel_line.Clear();
    ins_nonstd_proc_log ipl_dlg;

    ipl_dlg.Refresh_list_view(array_sel_ins, array_sel_workflow);
    ipl_dlg.ShowModal();
}
