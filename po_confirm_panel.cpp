#include "po_confirm_panel.h"
#include "wfApp.h"
#include "utils/wf_operator.h"
#include "mydatepicker.h"
#include <wx/choicdlg.h>

//(*InternalHeaders(po_confirm_panel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(po_confirm_panel)
const long po_confirm_panel::ID_BUTTON3 = wxNewId();
const long po_confirm_panel::ID_BUTTON2 = wxNewId();
const long po_confirm_panel::ID_BUTTON_PRICE_LIST = wxNewId();
const long po_confirm_panel::ID_BUTTON_TASK_CHANGE = wxNewId();
const long po_confirm_panel::ID_BUTTON_FILTER = wxNewId();
const long po_confirm_panel::ID_BUTTON4 = wxNewId();
const long po_confirm_panel::ID_BUTTON5 = wxNewId();
const long po_confirm_panel::ID_BUTTON_SPEC2 = wxNewId();
const long po_confirm_panel::ID_BUTTON_POS = wxNewId();
const long po_confirm_panel::ID_BUTTON1 = wxNewId();
const long po_confirm_panel::idMenu_only_private = wxNewId();
const long po_confirm_panel::idMenu_all = wxNewId();
const long po_confirm_panel::idMenu_task_change = wxNewId();
const long po_confirm_panel::idMenu_Pricelist = wxNewId();
//*)
const long po_confirm_panel::ID_TREELISTCTRL_TASK_LIST1 = wxNewId();
const long po_confirm_panel::ID_TREELISTCTRL_TASK_LIST2 = wxNewId();

BEGIN_EVENT_TABLE(po_confirm_panel,wxPanel)
	//(*EventTable(po_confirm_panel)
	//*)
END_EVENT_TABLE()

po_confirm_panel::po_confirm_panel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(po_confirm_panel)
	wxStaticBoxSizer* StaticBoxSizer2;
	wxStaticBoxSizer* sbox_PO_List;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxStaticBoxSizer* sbox_PO_Deal;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	sbox_PO_Deal = new wxStaticBoxSizer(wxVERTICAL, this, _("线下PO处理"));
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button_Confirm1 = new wxButton(this, ID_BUTTON3, _("确认"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer2->Add(Button_Confirm1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Return1 = new wxButton(this, ID_BUTTON2, _("退回"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button_Return1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Change = new wxButton(this, ID_BUTTON_PRICE_LIST, _("计价表收到日期"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_PRICE_LIST"));
	BoxSizer2->Add(Button_Change, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	button_task_change = new wxButton(this, ID_BUTTON_TASK_CHANGE, _("任务转交"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_TASK_CHANGE"));
	BoxSizer2->Add(button_task_change, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Filter = new wxButton(this, ID_BUTTON_FILTER, _("按人员筛选"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_FILTER"));
	BoxSizer2->Add(Button_Filter, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	sbox_PO_Deal->Add(BoxSizer2, 1, wxALL|wxALIGN_LEFT, 5);
	sbox_PO_List = new wxStaticBoxSizer(wxHORIZONTAL, this, _("任务清单"));
	sbox_PO_Deal->Add(sbox_PO_List, 5, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(sbox_PO_Deal, 1, wxALL|wxEXPAND, 0);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, this, _("线上PO处理"));
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	Button_Confirm2 = new wxButton(this, ID_BUTTON4, _("确认"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	BoxSizer3->Add(Button_Confirm2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Return2 = new wxButton(this, ID_BUTTON5, _("退回"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	BoxSizer3->Add(Button_Return2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Spec2 = new wxButton(this, ID_BUTTON_SPEC2, _("特批排产"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_SPEC2"));
	BoxSizer3->Add(Button_Spec2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button_pos = new wxButton(this, ID_BUTTON_POS, _("快速定位(F3)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_POS"));
	BoxSizer3->Add(Button_pos, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Refresh = new wxButton(this, ID_BUTTON1, _("刷新所有任务"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(Button_Refresh, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(BoxSizer3, 1, wxALL|wxALIGN_LEFT, 5);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("任务清单"));
	StaticBoxSizer2->Add(StaticBoxSizer4, 5, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 0);
	SetSizer(BoxSizer1);
	mi_private = new wxMenuItem((&menu_filter), idMenu_only_private, _("只显示本人任务(&M)"), _("只显示本人任务"), wxITEM_CHECK);
	menu_filter.Append(mi_private);
	mi_private->Check(true);
	mi_all = new wxMenuItem((&menu_filter), idMenu_all, _("显示所有人的任务(&A)"), _("显示所有人的任务"), wxITEM_CHECK);
	menu_filter.Append(mi_all);
	MenuItem2 = new wxMenuItem((&menu_offline_PO), idMenu_task_change, _("任务转交(&C)"), _("任务转交"), wxITEM_NORMAL);
	menu_offline_PO.Append(MenuItem2);
	MenuItem1 = new wxMenuItem((&menu_offline_PO), idMenu_Pricelist, _("计价表收到日期(&D)"), _("设定计价表收到日期"), wxITEM_NORMAL);
	menu_offline_PO.Append(MenuItem1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&po_confirm_panel::OnButton_Confirm1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&po_confirm_panel::OnButton_Return1Click);
	Connect(ID_BUTTON_PRICE_LIST,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&po_confirm_panel::OnButton_ChangeClick);
	Connect(ID_BUTTON_TASK_CHANGE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&po_confirm_panel::Onbutton_task_changeClick);
	Connect(ID_BUTTON_FILTER,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&po_confirm_panel::OnButton_FilterClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&po_confirm_panel::OnButton_Confirm2Click);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&po_confirm_panel::OnButton_Return2Click);
	Connect(ID_BUTTON_SPEC2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&po_confirm_panel::OnButton_Spec2Click);
	Connect(ID_BUTTON_POS,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&po_confirm_panel::OnButton_posClick);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&po_confirm_panel::OnButton_RefreshClick);
	Connect(idMenu_only_private,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&po_confirm_panel::OnMenuItem1Selected);
	Connect(idMenu_all,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&po_confirm_panel::OnMenuItem2Selected);
	Connect(idMenu_task_change,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&po_confirm_panel::OnMenuItem1Selected1);
	Connect(idMenu_Pricelist,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&po_confirm_panel::OnMenuItem2Selected1);
	Connect(wxEVT_RIGHT_DOWN,(wxObjectEventFunction)&po_confirm_panel::OnRightDown);
	//*)
	BuildDataViewCtrl();

    sbox_PO_List->Add(tlc_task_list1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0 );
    StaticBoxSizer4->Add(tlc_task_list2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0 );
    Layout();

    Connect(ID_TREELISTCTRL_TASK_LIST1, wxEVT_TREE_ITEM_RIGHT_CLICK, (wxObjectEventFunction)&po_confirm_panel::OnTaskList1RightClick);

 //   Connect(wxEVT_CHAR_HOOK,(wxObjectEventFunction)&po_confirm_panel::OnKeyDown);

   this->connectKeyDownEvent(this);

    wxArrayString array_spec = get_spec_auth_online_po_list(wf_str_review, wxT("AT00000028"));


    if(array_spec.Index(gr_para.login_user) != wxNOT_FOUND)
    {
        b_spec = true;

    }else
    {
        b_spec =false;
    }

    tlc_search=NULL;

    show_offline_po(!b_spec);
    sbox_PO_Deal->Show(!b_spec);
    sbox_PO_List->Show(!b_spec);

    wxString s_leader = wxGetApp().get_leader(wxT("G0016"));

    wxString str1,str2;

    if(s_leader == gr_para.login_user)
    {
          button_task_change->Show(true);
          Button_Filter->Show(true);
          str1 = wxT(" group_id = 'G0016' and is_active=true and active_status>=1 and action_id = 'AT00000027' and unit_status>=0 and is_latest=true ");

          str2 = wxT(" group_id = 'G0016' and is_active=true and active_status>=1 and action_id = 'AT00000028' and unit_status>=0 and is_latest=true ");
    }else
    {
          button_task_change->Show(false);
          Button_Filter->Show(false);
          str1 = wxT(" operator_id ='")+gr_para.login_user+wxT("' and is_active = true and active_status>=1 and action_id = 'AT00000027' and unit_status>=0 and is_latest=true ");

          if(b_spec)
          {
              str2 = wxT(" group_id = 'G0016' and is_active = true and active_status>=1 and action_id = 'AT00000028' and unit_status>=0 and is_latest=true ");
          }else
          {
              str2 = wxT(" operator_id ='")+gr_para.login_user+wxT("' and is_active = true and active_status>=1 and action_id = 'AT00000028' and unit_status>=0 and is_latest=true ");
          }
    }

    set_clause1(str1);
    set_clause2(str2);

    if(b_spec)
    {
        refresh_list2();
    }else
    {
        refresh_list1();
        refresh_list2();
    }

}

po_confirm_panel::~po_confirm_panel()
{
	//(*Destroy(po_confirm_panel)
	//*)
}


void po_confirm_panel::OnTaskList1RightClick(wxTreeEvent& event)
{
    wxString s_leader = wxGetApp().get_leader(wxT("G0016"));
    if(s_leader == gr_para.login_user)
       PopupMenu(&menu_offline_PO, ScreenToClient(wxGetMousePosition()));
}

wxArrayString po_confirm_panel::get_spec_auth_online_po_list(wxString s_workflow_id, wxString s_action_id)
{
    wxArrayString array_str;
    wxString str_sql= wxT("SELECT * from s_spec_auth_process where workflow_id = '")+s_workflow_id+wxT("' and action_id = '")+
                        s_action_id +wxT("' and is_valid = true;");
    wxPostgreSQLresult* _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return array_str;
    }

    int i_count = _res->GetRowsNumber();

    _res->MoveFirst();

    for(int i=0;i<i_count;i++)
    {
        wxString str = _res->GetVal(wxT("employee_id"));
        array_str.Add(str);
        _res->MoveNext();
    }

    return array_str;
}

void po_confirm_panel::show_offline_po(bool b_show)//show control
{
     tlc_task_list1->Show(b_show);
     Button_Confirm1->Show(b_show);
     Button_Return1->Show(b_show);
     Button_Return2->Show(b_show);
     Button_Confirm2->Show(b_show);
     Button_Spec2->Show(!b_show);
}

bool po_confirm_panel::update_can_psn(wxString s_task_id, wxString s_wbs_no, bool b_psn)
{
    wxString str_sql;

    if(b_psn&&(s_task_id.IsEmpty()||s_wbs_no.IsEmpty()))
    {
        return false;
    }

    if(b_psn)
    {
        str_sql= wxT("UPDATE s_review_units SET is_spec_approve=")+BoolToStr(b_psn)+wxT(", approve_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("',\
                       approver='")+gr_para.login_user+wxT("' WHERE review_task_id='")+s_task_id+wxT("' and wbs_no = '")+s_wbs_no+wxT("';");
        wxGetApp().app_sql_update(str_sql);
    }

    str_sql = wxT("UPDATE s_unit_info SET  can_psn=")+BoolToStr(b_psn)+wxT(",modify_date = '")+DateToAnsiStr(wxDateTime::Now())+
                    wxT("',modify_emp_id = '")+gr_para.login_user+wxT("' WHERE wbs_no ='") +s_wbs_no+wxT("'; ");

    return wxGetApp().app_sql_update(str_sql);
}

void po_confirm_panel::refresh_list1()
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


    if(array_group.Index(wxT("G0016")) == wxNOT_FOUND)
        return;


    wxTreeItemId root = tlc_task_list1->GetRootItem();
    tlc_task_list1->DeleteChildren (root);


    wxString str_sql = wxT("SELECT review_task_id,contract_id,project_name,project_id,require_review_date,res_cm,\
                           (select name from s_employee where employee_id = res_cm) as res_cm_person,branch_id,\
                           (select branch_name_cn from s_branch_info where branch_id = v_task_list4.branch_id) as branch_name, unit_status, unit_wf_status, action_id, wbs_no,lift_no,operator_id,\
                           (select name from s_employee where employee_id = operator_id) as operator_name, elevator_type,project_catalog,flow_ser,can_psn,price_list_receive FROM v_task_list4 WHERE ")+
                           cl_clause1+wxT(" ORDER BY review_task_id, wbs_no ASC;");

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

    for(int i=0; i<i_count; i++)
    {

        if(s_review_task_id != _res->GetVal(wxT("review_task_id")))
        {
            str = _res->GetVal(wxT("contract_id"))+_res->GetVal(wxT("project_name"))+wxT("-")+_res->GetVal(wxT("project_id"));
            s_review_task_id = _res->GetVal(wxT("review_task_id"));
            branch_item = tlc_task_list1->AppendItem(root,str);


            tlc_task_list1->SetItemText(branch_item,1,s_review_task_id);

            str = _res->GetVal(wxT("res_cm"));
            tlc_task_list1->SetItemText(branch_item,4, str);

            str = _res->GetVal(wxT("res_cm_person"));
            tlc_task_list1->SetItemText(branch_item,5, str);

            str = _res->GetVal(wxT("operator_id"));
            tlc_task_list1->SetItemText(branch_item,6, str);

            str = _res->GetVal(wxT("operator_name"));
            tlc_task_list1->SetItemText(branch_item,7, str);

            str = _res->GetVal(wxT("branch_id"));
            tlc_task_list1->SetItemText(branch_item,8, str);

            str = _res->GetVal(wxT("branch_name"));
            tlc_task_list1->SetItemText(branch_item,9, str);

            str = prj_status_to_str(_res->GetInt(wxT("unit_status")));
            tlc_task_list1->SetItemText(branch_item,10, str);

            str = _res->GetVal(wxT("unit_wf_status"));
            tlc_task_list1->SetItemText(branch_item,11, str);

 //           str = _res->GetVal(wxT("flow_ser"));
 //           tlc_task_list1->SetItemText(branch_item,13, str);
        }

        str = _res->GetVal(wxT("wbs_no"));

        leaf_item = tlc_task_list1->AppendItem(branch_item,str,-1,-1);

        tlc_task_list1->SetItemText(leaf_item,1,s_review_task_id);

        str = _res->GetVal(wxT("lift_no"));
        tlc_task_list1->SetItemText(leaf_item,2, str);

        str = DateToStrFormat(_res->GetDate(wxT("price_list_receive")));
        tlc_task_list1->SetItemText(leaf_item, 3, str);

        str = _res->GetVal(wxT("elevator_type"));
        tlc_task_list1->SetItemText(leaf_item,9, str);

        str = prj_catalog_to_str(_res->GetInt(wxT("project_catalog")));
        tlc_task_list1->SetItemText(leaf_item,5, str);

        str = _res->GetVal(wxT("operator_id"));
        tlc_task_list1->SetItemText(leaf_item,6, str);

        str = _res->GetVal(wxT("operator_name"));
        tlc_task_list1->SetItemText(leaf_item,7, str);

        str = _res->GetVal(wxT("branch_id"));
        tlc_task_list1->SetItemText(leaf_item,8, str);

        str = prj_status_to_str(_res->GetInt(wxT("unit_status")));
        tlc_task_list1->SetItemText(leaf_item,10, str);

        str = _res->GetVal(wxT("unit_wf_status"));
        tlc_task_list1->SetItemText(leaf_item,11, str);

        str = _res->GetVal(wxT("action_id"));
        tlc_task_list1->SetItemText(leaf_item,12, str);

        str = _res->GetVal(wxT("flow_ser"));
        tlc_task_list1->SetItemText(leaf_item,13, str);

        str = BoolToY(_res->GetBool(wxT("can_psn")));
        tlc_task_list1->SetItemText(leaf_item, 14, str);

        _res->MoveNext();
    }

    _res->Clear();

    refresh_level1();
}

void po_confirm_panel::refresh_list2()
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


    if(array_group.Index(wxT("G0016")) == wxNOT_FOUND&& !b_spec)
        return;


    wxTreeItemId root = tlc_task_list2->GetRootItem();
    tlc_task_list2->DeleteChildren (root);


    wxString str_sql = wxT("SELECT review_task_id,contract_id,project_name,project_id,require_review_date,res_cm,\
                           (select name from s_employee where employee_id = res_cm) as res_cm_person,branch_id,\
                           (select branch_name_cn from s_branch_info where branch_id = v_task_list4.branch_id) as branch_name, unit_status, unit_wf_status, action_id, wbs_no,lift_no,operator_id,\
                           (select name from s_employee where employee_id = operator_id) as operator_name, elevator_type,project_catalog,flow_ser,can_psn,price_list_receive FROM v_task_list4 WHERE ")+
                           cl_clause2+wxT(" ORDER BY review_task_id, wbs_no ASC;");

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

    for(int i=0; i<i_count; i++)
    {

        if(s_review_task_id != _res->GetVal(wxT("review_task_id")))
        {
            str = _res->GetVal(wxT("contract_id"))+_res->GetVal(wxT("project_name"))+wxT("-")+_res->GetVal(wxT("project_id"));
            s_review_task_id = _res->GetVal(wxT("review_task_id"));
            branch_item = tlc_task_list2->AppendItem(root,str);


            tlc_task_list2->SetItemText(branch_item,1,s_review_task_id);

            str = _res->GetVal(wxT("res_cm"));
            tlc_task_list2->SetItemText(branch_item,4, str);

            str = _res->GetVal(wxT("res_cm_person"));
            tlc_task_list2->SetItemText(branch_item,5, str);

            str = _res->GetVal(wxT("operator_id"));
            tlc_task_list2->SetItemText(branch_item,6, str);

            str = _res->GetVal(wxT("operator_name"));
            tlc_task_list2->SetItemText(branch_item,7, str);

            str = _res->GetVal(wxT("branch_id"));
            tlc_task_list2->SetItemText(branch_item,8, str);

            str = _res->GetVal(wxT("branch_name"));
            tlc_task_list2->SetItemText(branch_item,9, str);

            str = prj_status_to_str(_res->GetInt(wxT("unit_status")));
            tlc_task_list2->SetItemText(branch_item,10, str);

            str = _res->GetVal(wxT("unit_wf_status"));
            tlc_task_list2->SetItemText(branch_item,11, str);

//            str = _res->GetVal(wxT("flow_ser"));
 //           tlc_task_list2->SetItemText(branch_item,13, str);
        }

        str = _res->GetVal(wxT("wbs_no"));

        leaf_item = tlc_task_list2->AppendItem(branch_item,str,-1,-1);

        tlc_task_list2->SetItemText(leaf_item,1,s_review_task_id);

        str = _res->GetVal(wxT("lift_no"));
        tlc_task_list2->SetItemText(leaf_item,2, str);

        str = DateToStrFormat(_res->GetDate(wxT("price_list_receive")));
        tlc_task_list2->SetItemText(leaf_item, 3, str);

        str = _res->GetVal(wxT("elevator_type"));
        tlc_task_list2->SetItemText(leaf_item,9, str);

        str = prj_catalog_to_str(_res->GetInt(wxT("project_catalog")));
        tlc_task_list2->SetItemText(leaf_item,5, str);

        str = _res->GetVal(wxT("operator_id"));
        tlc_task_list2->SetItemText(leaf_item,6, str);

        str = _res->GetVal(wxT("operator_name"));
        tlc_task_list2->SetItemText(leaf_item,7, str);

        str = _res->GetVal(wxT("branch_id"));
        tlc_task_list2->SetItemText(leaf_item,8, str);

        str = prj_status_to_str(_res->GetInt(wxT("unit_status")));
        tlc_task_list2->SetItemText(leaf_item,10, str);

        str = _res->GetVal(wxT("unit_wf_status"));
        tlc_task_list2->SetItemText(leaf_item,11, str);

        str = _res->GetVal(wxT("action_id"));
        tlc_task_list1->SetItemText(leaf_item,12, str);

        str = _res->GetVal(wxT("flow_ser"));
        tlc_task_list2->SetItemText(leaf_item,13, str);

        str = BoolToY(_res->GetBool(wxT("can_psn")));
        tlc_task_list2->SetItemText(leaf_item, 14, str);

        _res->MoveNext();
    }

    _res->Clear();

    refresh_level2();
}

void po_confirm_panel::BuildDataViewCtrl()
{
    InitImageList();
    tlc_task_list1 = new wxcode::wxTreeListCtrl(this, ID_TREELISTCTRL_TASK_LIST1 ,
                                  wxDefaultPosition, wxDefaultSize,
                                  wxTR_DEFAULT_STYLE| wxTR_COLUMN_LINES|wxTR_HIDE_ROOT|wxTR_ROW_LINES|wxTR_MULTIPLE | wxTR_FULL_ROW_HIGHLIGHT);

    tlc_task_list1->SetImageList(m_imageList);

    tlc_task_list1->AddColumn(_("项目信息"),200,wxALIGN_LEFT,-1,true,false);//0
    tlc_task_list1->AddColumn(_("任务ID"),0,wxALIGN_LEFT,-1,false,false);//1
    tlc_task_list1->AddColumn(_("台数"),50,wxALIGN_LEFT, -1,true,false );//2
    tlc_task_list1->AddColumn(_("计价表收到日期"),100,wxALIGN_LEFT, -1,true,false);//3
    tlc_task_list1->AddColumn(_("合同负责ID"),0,wxALIGN_LEFT, -1,false,false );//4
    tlc_task_list1->AddColumn(_("合同负责"),100,wxALIGN_LEFT, -1,true,false );//5
    tlc_task_list1->AddColumn(_("operator_id"),0, wxALIGN_LEFT, -1, false,false);//6
    tlc_task_list1->AddColumn(_("任务操作"),100,wxALIGN_LEFT, -1,true,false );//7
    tlc_task_list1->AddColumn(_("分公司id"),0,wxALIGN_LEFT, -1,false,false);//8
    tlc_task_list1->AddColumn(_("分公司"),100,wxALIGN_LEFT, -1,true,false);//9
    tlc_task_list1->AddColumn(_("status"),50,wxALIGN_LEFT,-1,true,false);//10
    tlc_task_list1->AddColumn(_("任务状态"),70,wxALIGN_LEFT,-1,true,false);//11
    tlc_task_list1->AddColumn(_("action_id"),0,wxALIGN_LEFT,-1,false,false);//12
    tlc_task_list1->AddColumn(_("flow_ser"),0, wxALIGN_LEFT, -1, false, false); //13

    tlc_task_list1->AddRoot (_("线下PO确认"));


    tlc_task_list2 = new wxcode::wxTreeListCtrl(this, ID_TREELISTCTRL_TASK_LIST2 ,
                                  wxDefaultPosition, wxDefaultSize,
                                  wxTR_DEFAULT_STYLE| wxTR_COLUMN_LINES|wxTR_HIDE_ROOT|wxTR_ROW_LINES|wxTR_MULTIPLE | wxTR_FULL_ROW_HIGHLIGHT);

    tlc_task_list2->SetImageList(m_imageList);

    tlc_task_list2->AddColumn(_("项目信息"),200,wxALIGN_LEFT,-1,true,false);//0
    tlc_task_list2->AddColumn(_("任务ID"),0,wxALIGN_LEFT,-1,false,false);//1
    tlc_task_list2->AddColumn(_("台数"),50,wxALIGN_LEFT, -1,true,false );//2
    tlc_task_list2->AddColumn(_("计价表收到日期"),100,wxALIGN_LEFT, -1,true,false);//3
    tlc_task_list2->AddColumn(_("合同负责ID"),0,wxALIGN_LEFT, -1,false,false );//4
    tlc_task_list2->AddColumn(_("合同负责"),100,wxALIGN_LEFT, -1,true,false );//5
    tlc_task_list2->AddColumn(_("operator_id"),0, wxALIGN_LEFT, -1, false, false);//6
    tlc_task_list2->AddColumn(_("任务操作"),100,wxALIGN_LEFT, -1,true,false );//7
    tlc_task_list2->AddColumn(_("分公司id"),0,wxALIGN_LEFT, -1,false,false);//8
    tlc_task_list2->AddColumn(_("分公司"),100,wxALIGN_LEFT, -1,true,false);//9
    tlc_task_list2->AddColumn(_("status"),50,wxALIGN_LEFT,-1,true,false);//10
    tlc_task_list2->AddColumn(_("任务状态"),70,wxALIGN_LEFT,-1,true,false);//11
    tlc_task_list2->AddColumn(_("action_id"),0,wxALIGN_LEFT,-1,false,false);//12
    tlc_task_list2->AddColumn(_("flow_ser"),0, wxALIGN_LEFT, -1, false, false); //13
    tlc_task_list2->AddColumn(_("CAN PSN"),0, wxALIGN_LEFT, -1, false, false);//14

    tlc_task_list2->AddRoot (_("线上PO确认"));


}

void po_confirm_panel::refresh_level1()
{
    wxTreeItemId root = tlc_task_list1->GetRootItem();

    wxTreeItemIdValue cookie;
    wxTreeItemId item = tlc_task_list1->GetFirstChild(root,cookie);

    int i_count_fin;

    wxString s_can_psn;
    int i_status;

    wxArrayString a_lift_no;
    wxString s_lift_no;

    while(item.IsOk())
    {
        wxTreeItemIdValue cookie_child;
        wxTreeItemId child_item = tlc_task_list1->GetFirstChild(item,cookie_child);

        int i_count_leaf = tlc_task_list1->GetChildrenCount(item);

        i_count_fin = 0;

        while(child_item.IsOk())
        {
            s_can_psn = tlc_task_list1->GetItemText(child_item, 14);
            i_status =prj_str_to_status(tlc_task_list1->GetItemText(child_item, 10));
            s_lift_no = tlc_task_list1->GetItemText(child_item, 2);
            a_lift_no.Add(s_lift_no);

            if(i_status == 2)
                 tlc_task_list1->SetItemBackgroundColour(child_item, *wxLIGHT_GREY);
            else
                 tlc_task_list1->SetItemBackgroundColour(child_item, *wxWHITE);

            if(s_can_psn == wxT("Y"))
            {
                tlc_task_list1->SetItemImage(child_item, 8);
                i_count_fin++;
            }else
            {
                tlc_task_list1->SetItemImage(child_item, -1);
            }
            child_item = tlc_task_list1->GetNextSibling(child_item);
        }

        if(i_count_fin == i_count_leaf)
        {
            tlc_task_list1->SetItemImage(item, 7);
        }else if(i_count_fin>0)
        {
            tlc_task_list1->SetItemImage(item, 8);
        }

        s_lift_no=Combine_lift_no(a_lift_no);
        tlc_task_list1->SetItemText(item, 2, NumToStr(i_count_leaf)+_("台[")+s_lift_no+_("]"));
        a_lift_no.Clear();

        item = tlc_task_list1->GetNextSibling(item);

    }
}

void po_confirm_panel::refresh_level2()
{
    wxTreeItemId root = tlc_task_list2->GetRootItem();

    wxTreeItemIdValue cookie;
    wxTreeItemId item = tlc_task_list2->GetFirstChild(root,cookie);

    wxString s_can_psn;
    int i_count_fin, i_status;
    wxArrayString a_lift_no;
    wxString s_lift_no;

    while(item.IsOk())
    {
        wxTreeItemIdValue cookie_child;
        wxTreeItemId child_item = tlc_task_list2->GetFirstChild(item,cookie_child);

        int i_count_leaf = tlc_task_list2->GetChildrenCount(item);

        i_count_fin = 0;

        while(child_item.IsOk())
        {
            s_can_psn = tlc_task_list2->GetItemText(child_item, 14);
            i_status =prj_str_to_status(tlc_task_list1->GetItemText(child_item, 10));
            s_lift_no = tlc_task_list2->GetItemText(child_item, 2);
            a_lift_no.Add(s_lift_no);

            if(i_status == 2)
                 tlc_task_list1->SetItemBackgroundColour(child_item, *wxLIGHT_GREY);
            else
                 tlc_task_list1->SetItemBackgroundColour(child_item, *wxWHITE);

            if(s_can_psn == wxT("Y"))
            {
                tlc_task_list2->SetItemImage(child_item, 8);
                i_count_fin++;
            }else
            {
                tlc_task_list2->SetItemImage(child_item, -1);
            }

            child_item = tlc_task_list2->GetNextSibling(child_item);
        }

        if(i_count_fin == i_count_leaf)
        {
            tlc_task_list2->SetItemImage(item, 7);
        }else if(i_count_fin >0)
        {
            tlc_task_list2->SetItemImage(item, 8);
        }

        s_lift_no = Combine_lift_no(a_lift_no);

        tlc_task_list2->SetItemText(item, 2, NumToStr(i_count_leaf)+_("台[")+s_lift_no+_("]"));
        a_lift_no.Clear();

        item = tlc_task_list2->GetNextSibling(item);
    }
}

void po_confirm_panel::OnButton_RefreshClick(wxCommandEvent& event)
{
    if(!b_spec)
       refresh_list1();
    refresh_list2();
}

void po_confirm_panel::OnButton_Return1Click(wxCommandEvent& event)
{
    	if (!gr_para.login_status)
	{
		wxLogMessage(_("尚未登陆,不能进行任何操作!"));
		return;
	}

	wxArrayTreeItemIds items;
	wxTreeItemId root = tlc_task_list1->GetRootItem();

	wxArrayTreeItemIds::iterator iter;
	tlc_task_list1->GetSelections( items );
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
	bool b_step = true;

	t_template = get_template_action(wf_str_review);

	int i_status;
	wxString s_wf_status,s_wbs;

	for ( iter = items.begin(); iter<items.end(); iter++)
	{
		wxTreeItemId sel_item = *iter;
		if (tlc_task_list1->GetItemParent(sel_item)==root&&sel_item.IsOk())
		{
            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_task_list1->GetFirstChild(sel_item,cookie);
            str_task_id = tlc_task_list1->GetItemText(sel_item, 1);
			str_workflow_id = wf_str_review;

            while(child_item.IsOk())
            {
                s_wbs = tlc_task_list1->GetItemText(child_item,0);
                str_flow_ser = tlc_task_list1->GetItemText(child_item, 13);
                i_status = prj_str_to_status(tlc_task_list1->GetItemText(child_item, 10));

                if(b_step)
                {

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
                    }
                    else return;

                    b_step = false;
                }

                start_mils = wxGetLocalTimeMillis();
                wf_active = new wf_operator(s_wbs, str_workflow_id, t_template);
                wf_active->Feed_back(str_desc, aim_step);

                if (wf_active->update_instance(i_status,s_wf_status))
                {
                    update_review_units_status(str_task_id,s_wbs, i_status, s_wf_status);
                    wxLogMessage(_("项目:")+s_wbs+_("退回线下PO确认任务:")+str_task_id+_("成功!"));
                }

                delete wf_active;

                mils_used = wxGetLocalTimeMillis() - start_mils;

                wxLogMessage(s_wbs+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒"));

                child_item = tlc_task_list1->GetNextSibling(child_item);
            }

			tlc_task_list1->DeleteChildren(sel_item);
			tlc_task_list1->Delete(sel_item);
		}
	}

	delete [] t_template;
}

void po_confirm_panel::OnButton_Confirm1Click(wxCommandEvent& event)
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

	if (array_group.Index(wxT("G0016"))==wxNOT_FOUND)
	{
		return;
	}

	wxArrayTreeItemIds items;
	wxTreeItemId root = tlc_task_list1->GetRootItem();

	wxArrayTreeItemIds::iterator iter;
	tlc_task_list1->GetSelections( items );

	if (items.IsEmpty())
	{
		wxLogMessage(_("请选择项目！"));
		return;
	}

	wxString s_task_id, s_operator, s_group, s_action_id;

	if (wxMessageBox(_("所选项目确认已经完成？"),_("完成确认："),wxOK|wxCANCEL,this)==wxCANCEL)
	{
		return;
	}

		v_wf_action * t_template=0;

	wf_operator * wf_active=0;
	wf_process * l_proc_act =0;

    int i_status;
    wxString s_wf_status, s_wbs,s_branch_id;
	wxLongLong mils_used, start_mils;
     v_wf_instance now_step;
     wxString s_price_list;

	t_template = get_template_action(wf_str_review);
	for ( iter = items.begin(); iter<items.end(); iter++)
	{
        wxTreeItemId sel_item = *iter;

        s_task_id = tlc_task_list1->GetItemText(sel_item, 1);
        s_branch_id = tlc_task_list1->GetItemText(sel_item, 8);
        if (tlc_task_list1->GetItemParent(sel_item)==root&&sel_item.IsOk())
        {

            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_task_list1->GetFirstChild(sel_item,cookie);

            while(child_item.IsOk())
            {
                s_wbs = tlc_task_list1->GetItemText(child_item,0);
                i_status = prj_str_to_status(tlc_task_list1->GetItemText(child_item, 10));

                s_price_list = tlc_task_list1->GetItemText(child_item, 3);
                s_operator = tlc_task_list1->GetItemText(child_item, 6);

                if(s_price_list.IsEmpty())
                {
                    if(wxMessageBox(_("请补全计价表收到日期后方可继续!"),_("提示!"),wxOK)==wxOK)
                    {
                        wxLogMessage(_("请补全计价表收到日期后方可继续!"));

                        tlc_task_list1->Expand(sel_item);
                        tlc_task_list1->SelectItem(child_item);
                        return;
                    }
                }

                if(s_operator.IsEmpty())
                {
                    if(wxMessageBox(_("请先指派任务负责人后方可继续!"),_("提示!"),wxOK)==wxOK)
                    {
                        wxLogMessage(_("请先指派任务负责人后方可继续!"));

                        tlc_task_list1->Expand(sel_item);
                        tlc_task_list1->SelectItem(child_item);
                        return;
                    }
                }

                start_mils = wxGetLocalTimeMillis();//事件处理事件统计，起始点。

                wf_active = new wf_operator(s_wbs, wf_str_review, t_template);
                l_proc_act = wf_active->get_current_process();
                l_proc_act->MoveToActive();

                now_step = l_proc_act->get_cur_instance_action();
                s_operator = now_step.s_action.s_operator_id;
                s_group = now_step.s_action.s_group_id;

                wf_active->Pass_proc_s(s_operator, s_group, wxEmptyString, false);
                l_proc_act = 0;

                s_wf_status = _("PO确认完成");

    //            if (wf_active->update_instance(i_status,s_wf_status))
                if(update_review_units_status(s_task_id,s_wbs, i_status, s_wf_status))
                {

    //                update_review_units_status(s_task_id,s_wbs, i_status, s_wf_status);
                    wxLogMessage(_("项目:")+s_wbs+_("任务:")+s_task_id+_("线下PO确认完成!"));
                }

                delete wf_active;

                mils_used = wxGetLocalTimeMillis() - start_mils;

                wxLogMessage(s_wbs+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒")); //事件处理事件统计，截止点。


                child_item = tlc_task_list1->GetNextSibling(child_item);
            }

            tlc_task_list1->DeleteChildren(sel_item);
            tlc_task_list1->Delete(sel_item);

        }else
        {
               s_wbs = tlc_task_list1->GetItemText(sel_item,0);
                i_status = prj_str_to_status(tlc_task_list1->GetItemText(sel_item, 10));
                s_price_list = tlc_task_list1->GetItemText(sel_item, 3);
                s_operator = tlc_task_list1->GetItemText(sel_item, 6);

                if(s_price_list.IsEmpty())
                {
                    if(wxMessageBox(_("请补全计价表收到日期后方可继续!"),_("提示!"),wxOK)==wxID_OK)
                    {
                        wxLogMessage(_("请补全计价表收到日期后方可继续!"));

                        tlc_task_list1->SelectItem(sel_item);
                        return;
                    }
                }

               if(s_operator.IsEmpty())
                {
                    if(wxMessageBox(_("请先指派任务负责人后方可继续!"),_("提示!"),wxOK)==wxOK)
                    {
                        wxLogMessage(_("请先指派任务负责人后方可继续!"));

                        tlc_task_list1->SelectItem(sel_item);
                        return;
                    }
                }

                start_mils = wxGetLocalTimeMillis();//事件处理事件统计，起始点。

                wf_active = new wf_operator(s_wbs, wf_str_review, t_template);
                l_proc_act = wf_active->get_current_process();
                l_proc_act->MoveToActive();

                now_step = l_proc_act->get_cur_instance_action();
                s_operator = now_step.s_action.s_operator_id;
                s_group = now_step.s_action.s_group_id;

                wf_active->Pass_proc_s(s_operator, s_group, wxEmptyString, false);
                l_proc_act = 0;

                s_wf_status = _("PO确认完成");

  //              if (wf_active->update_instance(i_status,s_wf_status))
                if(update_review_units_status(s_task_id,s_wbs, i_status, s_wf_status))
                {

                 //   update_review_units_status(s_task_id,s_wbs, i_status, s_wf_status);
                    wxLogMessage(_("项目:")+s_wbs+_("任务:")+s_task_id+_("线下PO确认完成!"));
                }

                delete wf_active;

                mils_used = wxGetLocalTimeMillis() - start_mils;

                wxLogMessage(s_wbs+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒")); //事件处理事件统计，截止点。
                tlc_task_list1->Delete(sel_item);
        }
	}

	delete [] t_template;

	refresh_list2();

}

int po_confirm_panel::get_unit_status(wxString s_wbs)
{
    wxString s_sql = wxT("select * from s_unit_info where wbs_no='")+s_wbs+wxT("';");
    wxPostgreSQLresult * _res =  wxGetApp().app_sql_select(s_sql);

	if (_res->Status()!= PGRES_TUPLES_OK)
	{
		_res->Clear();
		return 2;
	}

	int i_count = _res->GetRowsNumber();

	if(i_count==0)
    {
        _res->Clear();
        return 2;
    }

	int i_result = _res->GetInt(wxT("status"));

    _res->Clear();

    return i_result;


}

void po_confirm_panel::OnButton_Confirm2Click(wxCommandEvent& event)
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

    if (array_group.Index(wxT("G0016"))==wxNOT_FOUND && !b_spec)
    {
        return;
    }

    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_task_list2->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_task_list2->GetSelections( items );

    if (items.IsEmpty())
    {
        wxLogMessage(_("请选择项目！"));
        return;
    }

    wxString s_task_id, s_operator, s_group, s_action_id,s_branch_id;

    if (wxMessageBox(_("所选项目确认已经完成？"),_("完成确认："),wxOK|wxCANCEL,this)==wxCANCEL)
    {
        return;
    }

    v_wf_action * t_template=0;

    wf_operator * wf_active=0;
    wf_process * l_proc_act =0;

    int i_status,i_unit_status;
    wxString s_wf_status, s_wbs;
    wxLongLong mils_used, start_mils;
    v_wf_instance now_step;
    //bool b_can_psn;
    bool  b_configure_start;

    t_template = get_template_action(wf_str_review);
    for ( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;

        s_task_id = tlc_task_list2->GetItemText(sel_item, 1);
        if (tlc_task_list2->GetItemParent(sel_item)==root&&sel_item.IsOk())
        {

            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_task_list2->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {
                s_wbs = tlc_task_list2->GetItemText(child_item,0);
                i_status = prj_str_to_status(tlc_task_list1->GetItemText(child_item, 10));

                start_mils = wxGetLocalTimeMillis();//事件处理事件统计，起始点。

                wf_active = new wf_operator(s_wbs, wf_str_review, t_template);
                l_proc_act = wf_active->get_current_process();
                l_proc_act->MoveToActive();

                now_step= l_proc_act->get_cur_instance_action();
                s_operator = now_step.s_action.s_operator_id;
                s_group = now_step.s_action.s_group_id;

                wf_active->Pass_proc_s(s_operator, s_group, wxEmptyString, false);

                l_proc_act = 0;

             //   b_can_psn = check_psn(s_wbs);

             //   if(b_can_psn)
                b_configure_start = check_configure_start(s_wbs);

                i_unit_status = get_unit_status(s_wbs);

                if(i_unit_status==1 || i_unit_status==3)
                {
                    if(b_configure_start)
                    {
                        i_status = 2;
                        update_review_units_status(s_task_id,s_wbs, i_status, s_wf_status);
                        wxLogMessage(_("项目:")+s_wbs+_("任务:")+s_task_id+_("线下PO确认完成!"));
                    }
                    else
                    {
                        if (wf_active->update_instance(2, s_wf_status))
                        {
                            i_status = 2;
                            update_review_units_status(s_task_id,s_wbs, i_status, s_wf_status);
                            wxLogMessage(_("项目:")+s_wbs+_("任务:")+s_task_id+_("线下PO确认完成!"));
                        }
                    }


                }else  if(i_unit_status==0)
                {
                         if (wf_active->update_instance(2, s_wf_status))
                        {
                            i_status = 2;
                            update_review_units_status(s_task_id,s_wbs, i_status, s_wf_status);
                            wxLogMessage(_("项目:")+s_wbs+_("任务:")+s_task_id+_("线下PO确认完成!"));
                        }
                }else
                {
                    i_status = 2;
                    update_review_units_status(s_task_id,s_wbs, i_status, s_wf_status);
                    wxLogMessage(_("项目:")+s_wbs+_("任务:")+s_task_id+_("线下PO确认完成!"));
                }

                delete wf_active;

                mils_used = wxGetLocalTimeMillis() - start_mils;

                wxLogMessage(s_wbs+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒")); //事件处理事件统计，截止点。

                child_item = tlc_task_list2->GetNextSibling(child_item);
            }

            tlc_task_list2->DeleteChildren(sel_item);
            tlc_task_list2->Delete(sel_item);
        }
        else
        {
            s_wbs = tlc_task_list2->GetItemText(sel_item,0);
            i_status = prj_str_to_status(tlc_task_list1->GetItemText(sel_item, 10));

            start_mils = wxGetLocalTimeMillis();//事件处理事件统计，起始点。

            wf_active = new wf_operator(s_wbs, wf_str_review, t_template);
            l_proc_act = wf_active->get_current_process();
            l_proc_act->MoveToActive();

            now_step= l_proc_act->get_cur_instance_action();
            s_operator = now_step.s_action.s_operator_id;
            s_group = now_step.s_action.s_group_id;

            wf_active->Pass_proc_s(s_operator, s_group, wxEmptyString, false);

            l_proc_act = 0;

      //      b_can_psn = check_psn(s_wbs);

    //        if(b_can_psn)
            b_configure_start = check_configure_start(s_wbs);
            i_unit_status = get_unit_status(s_wbs);

            if(i_unit_status==1 || i_unit_status==3)
            {
                if(b_configure_start)
                {
                    i_status = 2;
                    update_review_units_status(s_task_id,s_wbs, i_status, s_wf_status);
                    wxLogMessage(_("项目:")+s_wbs+_("任务:")+s_task_id+_("线下PO确认完成!"));
                }
                else
                {
                    if (wf_active->update_instance(2, s_wf_status))
                    {
                        i_status = 2;
                        update_review_units_status(s_task_id,s_wbs, i_status, s_wf_status);
                        wxLogMessage(_("项目:")+s_wbs+_("任务:")+s_task_id+_("线下PO确认完成!"));
                    }
                }


            }
            else  if(i_unit_status==0)
            {
                if (wf_active->update_instance(2, s_wf_status))
                {
                    i_status = 2;
                    update_review_units_status(s_task_id,s_wbs, i_status, s_wf_status);
                    wxLogMessage(_("项目:")+s_wbs+_("任务:")+s_task_id+_("线下PO确认完成!"));
                }
            }
            else
            {
                i_status = 2;
                update_review_units_status(s_task_id,s_wbs, i_status, s_wf_status);
                wxLogMessage(_("项目:")+s_wbs+_("任务:")+s_task_id+_("线下PO确认完成!"));
            }


            delete wf_active;

            mils_used = wxGetLocalTimeMillis() - start_mils;

            wxLogMessage(s_wbs+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒")); //事件处理事件统计，截止点。
            tlc_task_list2->Delete(sel_item);
        }

        if(check_review_task(s_task_id))
        {
            close_review_task(s_task_id);
        }
    }

    refresh_list2();

    delete [] t_template;

}

bool po_confirm_panel::check_psn(const wxString s_wbs)
{
     wxString str_sql = wxT("select * from s_unit_info where wbs_no='")+s_wbs + wxT("';");
     wxPostgreSQLresult * _res =  wxGetApp().app_sql_select(str_sql);

	if (_res->Status()!= PGRES_TUPLES_OK)
	{
		_res->Clear();
		return false;
	}

	 int i_count = _res->GetRowsNumber();

	 if(i_count == 0)
        return false;

     _res->MoveFirst();

     bool b_psn =  _res->GetBool(wxT("can_psn"));

     _res->Clear();

     return b_psn;
}

bool po_confirm_panel::check_configure_start(const wxString s_wbs)
{
    wxString str_sql = wxT("select count(*) as count from l_proc_act where instance_id='")+s_wbs + wxT("' and workflow_id=\
                        '")+wf_str_configure+wxT("';");

      wxPostgreSQLresult * _res =  wxGetApp().app_sql_select(str_sql);

	if (_res->Status()!= PGRES_TUPLES_OK)
	{
		_res->Clear();
		return false;
	}

	_res->MoveFirst();

	int i_count = _res->GetInt(wxT("count"));

	_res->Clear();

	if(i_count >0)
        return true;
    else
        return false;
}

void po_confirm_panel::OnButton_Return2Click(wxCommandEvent& event)
{
    if (!gr_para.login_status)
	{
		wxLogMessage(_("尚未登陆,不能进行任何操作!"));
		return;
	}

	wxArrayTreeItemIds items;
	wxTreeItemId root = tlc_task_list2->GetRootItem();

	wxArrayTreeItemIds::iterator iter;
	tlc_task_list2->GetSelections( items );
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
	bool b_step=true;

	for ( iter = items.begin(); iter<items.end(); iter++)
	{
		wxTreeItemId sel_item = *iter;

		if (tlc_task_list2->GetItemParent(sel_item)==root&&sel_item.IsOk())
		{
            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_task_list2->GetFirstChild(sel_item,cookie);

            str_task_id = tlc_task_list2->GetItemText(sel_item, 1);
            str_workflow_id = wf_str_review;


            while(child_item.IsOk())
            {
                s_wbs = tlc_task_list2->GetItemText(child_item,0);
                i_status = prj_str_to_status(tlc_task_list2->GetItemText(child_item, 10));

                if(b_step )
                {
                    str_flow_ser = tlc_task_list2->GetItemText(child_item, 13);

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
                s_wf_status=s_wf_status.Left(i_pos);

   //             if (wf_active->update_instance(i_status, s_wf_status))
               if(update_review_units_status(str_task_id,s_wbs, i_status, s_wf_status))
                {
           //         update_review_units_status(str_task_id,s_wbs, i_status, s_wf_status);
                    wxLogMessage(_("项目:")+s_wbs+_("退回线下PO确认任务:")+str_task_id+_("成功!"));
                }

                delete wf_active;


                mils_used = wxGetLocalTimeMillis() - start_mils;

                wxLogMessage(s_wbs+_("任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒"));

                child_item = tlc_task_list2->GetNextSibling(child_item);
            }

			tlc_task_list2->DeleteChildren(sel_item);
			tlc_task_list2->Delete(sel_item);
		}
	}

	delete [] t_template;

	refresh_list1();
}

bool po_confirm_panel::check_review_task(const wxString s_task_id)
{
    wxString str_sql = wxT("select * from s_review_units where review_task_id ='")+s_task_id+wxT("' and is_del = false and unit_status>=0 ;");

    wxPostgreSQLresult * _res =  wxGetApp().app_sql_select(str_sql);

	if (_res->Status()!= PGRES_TUPLES_OK)
	{
		_res->Clear();
		return false;
	}

    int i_count = _res->GetRowsNumber();

    if(i_count !=0)
        _res->MoveFirst();

    int i_close=0;
    int i_status;

    for(int i=0;i<i_count;i++)
    {
         i_status = _res->GetInt(wxT("unit_status"));

         if(i_status == 2)
            i_close++;

        _res->MoveNext();
    }

    _res->Clear();

    if(i_count >0 && i_close == i_count)
    {
          return true;
    }

    return false;
}

bool po_confirm_panel::close_review_task(const wxString s_task_id)
{
    wxString str_sql = wxT("UPDATE s_review_info SET  modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("',active_status=0 WHERE \
                        review_task_id='")+s_task_id+wxT("';");
    return wxGetApp().app_sql_update(str_sql);
}


wxString po_confirm_panel::get_operator_from_branch(wxString s_branch_id, wxString s_group_id)
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
/*
bool po_confirm_panel::update_review_status(const wxArrayString & array_units, int i_status, wxString s_wf_status)
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

wxArrayString po_confirm_panel::get_steps_info(wxString & s_instance_id, wxString & s_workflow_id, wxString & s_now)
{
	wxString strSql = wxT("select operator_id, concat(action_id,'-',operator_id) as action_id, concat(action_name,'-', (select name from s_employee where employee_id= operator_id)) as step_info from v_task_list4 where workflow_id = '")+
	                  s_workflow_id+wxT("' and instance_id = '")+ s_instance_id+wxT("' and flow_ser < ")+ s_now+wxT(" and is_latest=true order by flow_ser ASC;");

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

void po_confirm_panel::OnRightDown(wxMouseEvent& event)
{
    wxString s_leader = wxGetApp().get_leader(wxT("G0016"));


    if(s_leader == gr_para.login_user)
    {
         PopupMenu(&menu_filter, ScreenToClient(wxGetMousePosition()));
    }
}

void po_confirm_panel::OnMenuItem1Selected(wxCommandEvent& event)
{
    if (!event.IsChecked())
	{
		mi_private->Check(true);
		return;
	}
    wxString str1,str2;
    str1 = wxT(" operator_id ='")+gr_para.login_user+wxT("' and is_active = true and action_id = 'AT00000027' and unit_status>=0 and is_latest=true ");
    str2 = wxT(" operator_id ='")+gr_para.login_user+wxT("' and is_active = true and action_id = 'AT00000028' and unit_status>=0 and is_latest=true ");
    set_clause1(str1);
    set_clause2(str2);
	refresh_list1();
	refresh_list2();
	mi_private->Check(true);
	mi_all->Check(false);
}

void po_confirm_panel::OnMenuItem2Selected(wxCommandEvent& event)
{
    if (!event.IsChecked())
	{
		mi_all->Check(true);
		return;
	}
    wxString str1,str2;
    str1 = wxT(" group_id = 'G0016' and is_active = true and action_id = 'AT00000027' and unit_status>=0 and is_latest=true ");
    str2 = wxT(" group_id = 'G0016' and is_active = true and action_id = 'AT00000028' and unit_status>=0 and is_latest=true ");
    set_clause1(str1);
    set_clause2(str2);
	refresh_list1();
	refresh_list2();
	mi_private->Check(false);
	mi_all->Check(true);
}

bool po_confirm_panel::update_review_units_status(const wxString s_task_id, const wxString s_wbs_no, int i_status, wxString s_wf_status)
{
     wxString str_sql = wxT("UPDATE s_review_units SET unit_status =")+NumToStr(i_status)+wxT(",unit_wf_status='")+s_wf_status+wxT("',modify_date = '")+DateToAnsiStr(wxDateTime::Now())+
                               wxT("',modify_emp_id = '")+gr_para.login_user+wxT("' WHERE review_task_id ='")+ s_task_id+wxT("' and  wbs_no ='")+s_wbs_no+wxT("';");


    return wxGetApp().app_sql_update(str_sql);
}

void po_confirm_panel::InitImageList()
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


void po_confirm_panel::OnButton_Spec2Click(wxCommandEvent& event)
{
    if (!gr_para.login_status)
	{
		wxLogMessage(_("尚未登陆,不能进行任何操作!"));
		return;
	}

	wxArrayTreeItemIds items;
	wxTreeItemId root = tlc_task_list2->GetRootItem();

	wxArrayTreeItemIds::iterator iter;
	tlc_task_list2->GetSelections( items );
	if (items.IsEmpty())
	{
		wxLogMessage(_("尚未选择项目，无法后续操作!"));
		return;
	}

    if (wxMessageBox(_("所选项目确认可以启动PSN？"),_("确认："),wxOK|wxCANCEL,this)==wxCANCEL)
	{
		return;
	}

	wxString s_wbs;
	wxString s_can_psn;
	wxString s_task_id;

    for ( iter = items.begin(); iter<items.end(); iter++)
	{
		wxTreeItemId sel_item = *iter;
		if (tlc_task_list2->GetItemParent(sel_item)==root)
		{
            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_task_list2->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {
                s_task_id = tlc_task_list2->GetItemText(child_item, 1);
                s_wbs = tlc_task_list2->GetItemText(child_item,0);
                s_can_psn = tlc_task_list2->GetItemText(child_item, 14);

                if(s_can_psn == wxT("Y"))
                {
                    child_item = tlc_task_list2->GetNextSibling(child_item);
                    continue;
                }

                update_can_psn(s_task_id,s_wbs);

                child_item = tlc_task_list2->GetNextSibling(child_item);
            }
		}else
		{
		        s_task_id = tlc_task_list2->GetItemText(sel_item, 1);
                s_wbs = tlc_task_list2->GetItemText(sel_item, 0);
                s_can_psn = tlc_task_list2->GetItemText(sel_item, 14);

                if(s_can_psn == wxT("Y"))
                {
                    continue;
                }

               update_can_psn(s_task_id, s_wbs);
		}
	}


	refresh_list2();

}

void po_confirm_panel::OnButton_ChangeClick(wxCommandEvent& event)
{
    change_price_list();
    refresh_list1();
}

void po_confirm_panel::OnMenuItem2Selected1(wxCommandEvent& event)
{
    change_price_list();
    refresh_list1();
}

void po_confirm_panel::change_price_list()
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_task_list1->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_task_list1->GetSelections( items );
    if (items.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;

    }
    wxString s_date,s_task_id,s_wbs;

    mydatepicker dlg;
    bool b_continue = true;
    if(dlg.ShowModal()==wxID_OK)
    {
        s_date = dlg.GetString();
    }
    else
        return;

    for ( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if (tlc_task_list1->GetItemParent(sel_item)==root)
        {
            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_task_list1->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {
                s_task_id = tlc_task_list1->GetItemText(child_item, 1);
                s_wbs = tlc_task_list1->GetItemText(child_item,0);
                wxString s_old_date = tlc_task_list1->GetItemText(child_item, 14);

                if(!s_old_date.IsEmpty()&&b_continue)
                {
                    if(wxMessageBox(_("确认将计价表收到日期由")+s_old_date+_("变更为:")+s_date,_("确认"),wxYES_NO)==wxYES)
                    {
                        b_continue = true;
                    }
                    else
                    {
                        child_item = tlc_task_list1->GetNextSibling(child_item);
                        b_continue = false;
                        continue;
                    }

                }

                if(!s_old_date.IsEmpty() && !b_continue)
                {
                    child_item = tlc_task_list1->GetNextSibling(child_item);
                    continue;
                }

                if(update_price_list(s_task_id,s_wbs,s_date))
                {
                    wxGetApp().change_log(wxT("s_review_units"),s_wbs+wxT("-")+s_task_id,wxT("price_list_receive"),\
                                          s_old_date, s_date);
                }

                child_item = tlc_task_list1->GetNextSibling(child_item);
            }
        }
        else
        {
            s_task_id = tlc_task_list1->GetItemText(sel_item, 1);
            s_wbs = tlc_task_list1->GetItemText(sel_item, 0);
            wxString s_old_date = tlc_task_list1->GetItemText(sel_item, 14);

            if(!s_old_date.IsEmpty())
            {
                if(wxMessageBox(_("确认将计价表收到日期由")+s_old_date+_("变更为:")+s_date,_("确认"),wxYES_NO)==wxYES)
                {

                }
                else
                {
                    continue;
                }

            }

            b_continue = true;
            if(update_price_list(s_task_id,s_wbs,s_date))
            {
                wxGetApp().change_log(wxT("s_review_units"),s_wbs+wxT("-")+s_task_id,wxT("price_list_receive"),\
                                      s_old_date, s_date);
            }
        }
    }

}

bool po_confirm_panel::update_price_list(wxString s_task_id, wxString s_wbs, wxString s_date)
{
    wxString   str_sql= wxT("UPDATE s_review_units SET price_list_receive='")+s_date+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("',\
                       modify_emp_id='")+gr_para.login_user+wxT("' WHERE review_task_id='")+s_task_id+wxT("' and wbs_no = '")+s_wbs+wxT("';");
    return wxGetApp().app_sql_update(str_sql);
}

void po_confirm_panel::Onbutton_task_changeClick(wxCommandEvent& event)
{
    change_task_operator();
    refresh_list1();
}

void po_confirm_panel::OnMenuItem1Selected1(wxCommandEvent& event)
{
     change_task_operator();
     refresh_list1();
}

void po_confirm_panel::change_task_operator()
{
    if (!gr_para.login_status)
	{
		wxLogMessage(_("尚未登陆,不能进行任何操作!"));
		return;
	}

	wxArrayTreeItemIds items;
	wxTreeItemId root = tlc_task_list1->GetRootItem();

	wxArrayTreeItemIds::iterator iter;
	tlc_task_list1->GetSelections( items );
	if (items.IsEmpty())
	{
		wxLogMessage(_("尚未选择项目，无法后续操作!"));
		return;

	}
    wxString s_operator,s_wbs,s_old_operator,s_workflow,s_action_id;

    wxArrayString  s_members = wxGetApp().get_member_in_group(wxT("G0016"), true);

    wxSingleChoiceDialog cdlg(this, _("请新的操作人员:"),_("操作选择"),s_members);

    if(cdlg.ShowModal() == wxID_OK)
    {
        s_operator = cdlg.GetStringSelection();
    }
    else
    {
        wxLogMessage(_("未选择操作人员，操作退出!"));
        return;
    }

    int i_pos = s_operator.Find('-');

    s_operator = s_operator.Left(i_pos);
    s_workflow = wf_str_review;

    for ( iter = items.begin(); iter<items.end(); iter++)
	{
		wxTreeItemId sel_item = *iter;
		if (tlc_task_list1->GetItemParent(sel_item)==root)
		{
            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_task_list1->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {
                s_wbs = tlc_task_list1->GetItemText(child_item,0);
                s_old_operator = tlc_task_list1->GetItemText(child_item, 6);
                s_action_id = tlc_task_list1->GetItemText(child_item, 12);

                if(s_old_operator == s_operator)
                {
                    child_item = tlc_task_list1->GetNextSibling(child_item);
                    continue;
                }

                if(update_task_operator(s_wbs,s_workflow,s_action_id,s_operator))
                {
                    wxGetApp().change_log(wxT("l_proc_act"),s_wbs+wxT("-")+s_workflow+wxT("-")+s_action_id,wxT("operator_id"),\
                                          s_old_operator,s_operator);
                }

                child_item = tlc_task_list1->GetNextSibling(child_item);
            }
		}else
		{
                s_wbs = tlc_task_list1->GetItemText(sel_item,0);
                s_old_operator = tlc_task_list1->GetItemText(sel_item, 6);
                s_action_id = tlc_task_list1->GetItemText(sel_item, 12);

                if(s_old_operator == s_operator)
                {
                    continue;
                }

                if(update_task_operator(s_wbs,s_workflow,s_action_id,s_operator))
                {
                    wxGetApp().change_log(wxT("l_proc_act"),s_wbs+wxT("-")+s_workflow+wxT("-")+s_action_id,wxT("operator_id"),\
                                          s_old_operator,s_operator);
                }
       }
	}
}

bool po_confirm_panel::update_task_operator(wxString s_instance, wxString s_workflow, wxString s_action_id, wxString s_operator)
{
    wxString str_sql = wxT("UPDATE l_proc_act SET operator_id='")+s_operator+wxT("',modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("' \
                        WHERE instance_id='")+s_instance+wxT("' and  workflow_id='")+s_workflow+wxT("' and action_id='")+s_action_id+wxT("' and is_active = true;");
    return wxGetApp().app_sql_update(str_sql);
}

void po_confirm_panel::OnButton_posClick(wxCommandEvent& event)
{

   if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }

    wxString str;
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

    tlc_task_list2->UnselectAll();

    wxTreeItemId root;

    if(!b_spec)
    {
       tlc_task_list1->UnselectAll();
       tlc_search = tlc_task_list1;
       root = tlc_task_list1->GetRootItem();
       m_pos_id = root;
       m_pos_id = search_in_treelist(tlc_search, m_pos_id,m_search_case,0);

       if(m_pos_id!=root)
           return;
    }

    root = tlc_task_list2->GetRootItem();
    m_pos_id=root;

    tlc_search= tlc_task_list2;

    m_pos_id = search_in_treelist(tlc_search, m_pos_id,m_search_case,0);

    if(m_pos_id==root)
    {
        tlc_search = NULL;
        wxMessageBox(_("所搜项目不在清单中!"),_("提示"),wxOK);
    }
}

void po_confirm_panel::OnKeyDown(wxKeyEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }

   long key_code = event.GetKeyCode();
 //   wxKeyEvent levent = event.GetKeyEvent();

     wxTreeItemId root;

    switch(key_code)
    {
    case WXK_F3:

        if(m_search_case.IsEmpty())
            break;

        if(!tlc_search)
        {
            tlc_search= tlc_task_list1;
            root =tlc_task_list1->GetRootItem();

            m_pos_id=root;

            m_pos_id = search_in_treelist(tlc_search, m_pos_id, m_search_case,0);

            if(m_pos_id!=root)
                return;

            tlc_search=tlc_task_list2;
            root = tlc_task_list2->GetRootItem();
            m_pos_id = root;
            m_pos_id = search_in_treelist(tlc_search, m_pos_id, m_search_case,0);
            if(m_pos_id==root)
            {
                tlc_search = NULL;
                wxMessageBox(_("所搜项目不在清单中!"),_("提示"),wxOK);
            }

        }else if(tlc_search==tlc_task_list1)
        {
                 root = tlc_task_list1->GetRootItem();
                 m_pos_id = search_in_treelist(tlc_search, m_pos_id, m_search_case,0);

            if(m_pos_id!=root)
                return;

            tlc_search=tlc_task_list2;
            root = tlc_task_list2->GetRootItem();
            m_pos_id = root;
            m_pos_id = search_in_treelist(tlc_search, m_pos_id, m_search_case,0);
            if(m_pos_id==root)
            {
                tlc_search = NULL;
                wxMessageBox(_("已经全部搜索完成"),_("提示"),wxOK);
            }
        }else if(tlc_search==tlc_task_list2)
        {
            root = tlc_task_list2->GetRootItem();
            m_pos_id = root;
            m_pos_id = search_in_treelist(tlc_search, m_pos_id, m_search_case,0);
            if(m_pos_id==root)
            {
                tlc_search = NULL;
                wxMessageBox(_("已经全部搜索完成"),_("提示"),wxOK);
            }
        }



        break;
    default:
        break;
    }

    event.Skip();
}

void po_confirm_panel::connectKeyDownEvent(wxWindow* pclComponent)
{
  if(pclComponent)
  {
    pclComponent->Connect(wxID_ANY,
                          wxEVT_KEY_DOWN,
                          wxKeyEventHandler(po_confirm_panel::OnKeyDown),
                          (wxObject*) NULL,
                          this);

    wxWindowListNode* pclNode = pclComponent->GetChildren().GetFirst();
    while(pclNode)
    {
      wxWindow* pclChild = pclNode->GetData();
      this->connectKeyDownEvent(pclChild);

      pclNode = pclNode->GetNext();
    }
  }
}


void po_confirm_panel::OnButton_FilterClick(wxCommandEvent& event)
{
    wxArrayString s_members = wxGetApp().get_member_in_group(wxT("G0016"), true);

    wxString str = wxT("All");
    s_members.Add(str);
    wxString s_user;
    wxString  str1,str2;

    wxSingleChoiceDialog cdlg(this, _("请选择同组人员:"),_("人员选择"),s_members);

    if(cdlg.ShowModal() == wxID_OK)
    {
        s_user = cdlg.GetStringSelection();
    }
    else
    {
        wxLogMessage(_("未选择,取消操作!"));
        return;
    }

    if(s_user!=wxT("All"))
    {
        int i_pos = s_user.Find('-');

        s_user = s_user.Left(i_pos);
        str1 = wxT(" group_id = 'G0016' and is_active=true and active_status>=1 and action_id = 'AT00000027' and unit_status>=0 and is_latest=true and operator_id ='")+s_user+wxT("' ");

        str2 = wxT(" group_id = 'G0016' and is_active=true and active_status>=1 and action_id = 'AT00000028' and unit_status>=0 and is_latest=true and operator_id ='")+s_user+wxT("' ");
    }else
    {
         str1 = wxT(" group_id = 'G0016' and is_active=true and active_status>=1 and action_id = 'AT00000027' and unit_status>=0 and is_latest=true ");

        str2 = wxT(" group_id = 'G0016' and is_active=true and active_status>=1 and action_id = 'AT00000028' and unit_status>=0 and is_latest=true  ");

    }

    set_clause1(str1);
    set_clause2(str2);

    refresh_list1();
    refresh_list2();



}
