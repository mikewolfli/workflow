#include "nstd_mat_muti_level_task_list.h"
#include "wfApp.h"
#include <wx/tokenzr.h>
#include "nstd_task_author.h"

//(*InternalHeaders(nstd_mat_muti_level_task_list)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(nstd_mat_muti_level_task_list)
const long nstd_mat_muti_level_task_list::ID_STATICTEXT1 = wxNewId();
const long nstd_mat_muti_level_task_list::ID_CHECKBOX_FILTER = wxNewId();
const long nstd_mat_muti_level_task_list::ID_BUTTON1 = wxNewId();
const long nstd_mat_muti_level_task_list::ID_BUTTON2 = wxNewId();
const long nstd_mat_muti_level_task_list::IdMenu_Info = wxNewId();
//*)
const long nstd_mat_muti_level_task_list::ID_TREELISTCTRL_TASK_LIST = wxNewId();

BEGIN_EVENT_TABLE(nstd_mat_muti_level_task_list,wxDialog)
	//(*EventTable(nstd_mat_muti_level_task_list)
	//*)
END_EVENT_TABLE()

nstd_mat_muti_level_task_list::nstd_mat_muti_level_task_list(int _receive_mode, wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(nstd_mat_muti_level_task_list)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX, _T("wxID_ANY"));
	SetClientSize(wxSize(1000,700));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("任务清单"));
	BoxSizer1->Add(StaticBoxSizer1, 5, wxALL|wxEXPAND, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("红色:关联项目全部暂停;黄色:关联项目部分暂停;绿色:加急;天蓝色:非本人任务"), wxDefaultPosition, wxSize(466,33), 0, _T("ID_STATICTEXT1"));
	BoxSizer1->Add(StaticText1, 1, wxALL, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	cb_filter = new wxCheckBox(this, ID_CHECKBOX_FILTER, _("含已指定工程师任务"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_FILTER"));
	cb_filter->SetValue(true);
	BoxSizer2->Add(cb_filter, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("确认"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("取消"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	MenuItem1 = new wxMenuItem((&menu_info), IdMenu_Info, _("项目信息(&S)"), _("项目信息"), wxITEM_NORMAL);
	menu_info.Append(MenuItem1);
	SetSizer(BoxSizer1);
	Layout();
	Center();

	Connect(ID_CHECKBOX_FILTER,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&nstd_mat_muti_level_task_list::Oncb_filterClick);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_muti_level_task_list::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_muti_level_task_list::OnButton2Click);
	Connect(IdMenu_Info,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&nstd_mat_muti_level_task_list::OnMenuItem1Selected);
	//*)

	BuildDataViewCtrl();

	m_receive_mode = _receive_mode;

	if(m_receive_mode==2)
	{


        cb_filter->Enable(false);
        Button1->Show(false);

        }

	StaticBoxSizer1->Add(tlc_task_list, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	Layout();

	Connect(ID_TREELISTCTRL_TASK_LIST,wxEVT_TREE_ITEM_RIGHT_CLICK, (wxObjectEventFunction)&nstd_mat_muti_level_task_list::Ontlc_task_listRightClick);
}

nstd_mat_muti_level_task_list::~nstd_mat_muti_level_task_list()
{
	//(*Destroy(nstd_mat_muti_level_task_list)
	//*)
}


void nstd_mat_muti_level_task_list::BuildDataViewCtrl()
{
   tlc_task_list = new wxcode::wxTreeListCtrl(this, ID_TREELISTCTRL_TASK_LIST ,
                                  wxDefaultPosition, wxDefaultSize,
                                  wxTR_DEFAULT_STYLE| wxTR_COLUMN_LINES|wxTR_HIDE_ROOT|wxTR_ROW_LINES| wxTR_FULL_ROW_HIGHLIGHT);

    tlc_task_list->AddColumn(_("非标编号"),100,wxALIGN_LEFT,-1,true,false);
    tlc_task_list->AddColumn(_("项目信息"),200,wxALIGN_LEFT,-1,true,false);
    tlc_task_list->AddColumn(_("物料需求日/起始日期"),150,wxALIGN_LEFT, -1,true,false );
    tlc_task_list->AddColumn(_("图纸需求日/完成日期"),150,wxALIGN_LEFT, -1,true,false );
    tlc_task_list->AddColumn(_("状态"),120,wxALIGN_LEFT, -1,true,false);
    tlc_task_list->AddColumn(_("任务负责人ID"),0,wxALIGN_LEFT,-1,false,false);
    tlc_task_list->AddColumn(_("任务负责人"),80,wxALIGN_LEFT, -1,true,false);
    tlc_task_list->AddColumn(_("非标类别"),100,wxALIGN_LEFT, -1,true,false );
    tlc_task_list->AddColumn(_("非标原因"),150,wxALIGN_LEFT, -1,true,false);
    tlc_task_list->AddColumn(_("分值分布"),80,wxALIGN_LEFT, -1,true,false);
    tlc_task_list->AddColumn(_("非标申请编号"),80,wxALIGN_LEFT, -1,true,false);
    tlc_task_list->AddColumn(_("关联梯"),0,wxALIGN_LEFT,-1,false,false);

    wxTreeItemId root = tlc_task_list->AddRoot (_("任务列表"));
}


void nstd_mat_muti_level_task_list::refresh_list()
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
    wxString str_sql, str_sql1,str_sql2;

    wxTreeItemId root = tlc_task_list->GetRootItem();
    tlc_task_list->DeleteChildren (root);

    if(m_receive_mode==0)
    {

        str_sql1 = wxT("(SELECT index_id, concat(contract_id,' ', project_name,'-',project_id) as project_name, mat_req_date, drawing_req_date, \
                          nonstd_catalog, nonstd_desc,  res_person,(select name from s_employee where employee_id = res_person) as res_person_name, status ,\
                          nonstd_value, link_list from v_task_list2 where action_id = 'AT00000022' and is_active = true and operator_id ='")+gr_para.login_user+wxT("')");



        str_sql2 = wxT("(SELECT index_id, concat(contract_id,' ', project_name,'-',project_id) as project_name, mat_req_date, drawing_req_date, \
                          nonstd_catalog, nonstd_desc,  res_person,(select name from s_employee where employee_id = res_person) as res_person_name, (select status from l_instance_status where instance_id = index_id) as status,\
                          nonstd_value, link_list from  v_nonstd_app_item_task where action_id = 'AT00000022' and \
                          is_active = true AND status =1 AND res_engineer ='")+gr_para.login_user+wxT("')" );

        str_sql = str_sql1 +wxT(" UNION ")+str_sql2 + wxT(" ORDER BY drawing_req_date, index_id ASC;");
    }else if(m_receive_mode==1)
    {
        str_sql1 = wxT("(SELECT index_id, concat(contract_id,' ', project_name,'-',project_id) as project_name, mat_req_date, drawing_req_date, \
                          nonstd_catalog, nonstd_desc,  res_person,(select name from s_employee where employee_id = res_person) as res_person_name, header_status as status,\
                          nonstd_value, link_list from v_nonstd_app_item  WHERE header_status=3 and res_person ='")+gr_para.login_user+wxT("')");


        str_sql2 = wxT("(SELECT index_id, concat(contract_id,' ', project_name,'-',project_id) as project_name, mat_req_date, drawing_req_date, \
                          nonstd_catalog, nonstd_desc,  res_person,(select name from s_employee where employee_id = res_person) as res_person_name, header_status as status,\
                          nonstd_value, link_list from  v_nonstd_app_item_instance  where (header_status=3 or header_status=10) AND res_engineer ='")+gr_para.login_user+wxT("' AND status=1 )" );

        str_sql = str_sql1 +wxT(" UNION ")+str_sql2 + wxT(" ORDER BY drawing_req_date, index_id ASC;");
    }


    wxPostgreSQLresult* _res;
     _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }


    int i_status;

    _res->MoveFirst();

    int i_count = _res->GetRowsNumber();

    wxTreeItemId parent_item;
    wxString str_index_id;
    wxString str_res_person;
    wxString str_link_list;
    for(int i=0;i<i_count;i++)
    {
       str_index_id = _res->GetVal(wxT("index_id"));
       parent_item = tlc_task_list->AppendItem(root, str_index_id);
       tlc_task_list->SetItemText(parent_item,1,_res->GetVal(wxT("project_name")));
       tlc_task_list->SetItemText(parent_item,2,DateToStrFormat(_res->GetDate(wxT("mat_req_date"))));
       tlc_task_list->SetItemText(parent_item,3,DateToStrFormat(_res->GetDate(wxT("drawing_req_date"))));
       tlc_task_list->SetItemText(parent_item,4,nstd_status_to_str(_res->GetInt(wxT("status"))));

       str_res_person= _res->GetVal(wxT("res_person"));



       tlc_task_list->SetItemText(parent_item,5,str_res_person);
       tlc_task_list->SetItemText(parent_item,6,_res->GetVal(wxT("res_person_name")));
       tlc_task_list->SetItemText(parent_item,7,_res->GetVal(wxT("nonstd_catalog")));
       tlc_task_list->SetItemText(parent_item,8,_res->GetVal(wxT("nonstd_desc")));
       tlc_task_list->SetItemText(parent_item,9,_res->GetVal(wxT("nonstd_value")));

       str_link_list = _res->GetVal(wxT("link_list"));
       tlc_task_list->SetItemText(parent_item,11,str_link_list);

       append_tree_leaf(parent_item, str_index_id, str_res_person, str_link_list, cb_filter->IsChecked());
       tlc_task_list->Collapse(parent_item);

       if(str_res_person != gr_para.login_user)
       {
            tlc_task_list->Expand(parent_item);
            tlc_task_list->SetItemBackgroundColour(parent_item, *wxCYAN);
       }else
            tlc_task_list->SetItemBackgroundColour(parent_item, *wxLIGHT_GREY);

       _res->MoveNext();
    }

    _res->Clear();

    refresh_level();
}

void nstd_mat_muti_level_task_list::refresh_level()
{
    wxTreeItemId root = tlc_task_list->GetRootItem();

    wxTreeItemIdValue cookie;
    wxTreeItemId item = tlc_task_list->GetFirstChild(root,cookie);
    wxString str;
    wxArrayString array_units;

    while(item.IsOk())
    {

        str = tlc_task_list->GetItemText(item, 11);

        int i_freeze=0;
        int i_count=0;
        if(str.IsEmpty())
            return;

        array_units = wxStringTokenize(str ,wxT(";"), wxTOKEN_DEFAULT);

        i_count = array_units.GetCount();
        bool b_temp=false;
        bool b_urgent=false;
        for(int i=0;i<i_count;i++)
        {
            if(get_unit_status(array_units.Item(i), b_temp)==4)
                i_freeze+=1;

            if(b_temp)
                b_urgent=true;
        }

        if(i_freeze==i_count && i_count>0)
            tlc_task_list->SetItemBackgroundColour(item, *wxRED);
        else if(i_freeze<i_count && i_freeze>0)
            tlc_task_list->SetItemBackgroundColour(item, *wxYELLOW);
        else if(i_freeze==0 && b_urgent)
            tlc_task_list->SetItemBackgroundColour(item, *wxGREEN);

        item = tlc_task_list->GetNextSibling(item);
    }
}

int nstd_mat_muti_level_task_list::get_unit_status(wxString s_wbs, bool & b_urgent)
{
    wxString s_sql = wxT("select status, is_urgent from s_unit_info where wbs_no ='")+s_wbs+wxT("';");
    wxPostgreSQLresult* _res = wxGetApp().app_sql_select(s_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return -2;
    }

    int i_count = _res->GetRowsNumber();

    if(i_count ==0)
    {
        _res->Clear();
        return -1;
    }

    b_urgent= _res->GetBool(wxT("is_urgent"));

    int i_status= _res->GetInt(wxT("status"));
    return i_status;

}

void nstd_mat_muti_level_task_list::refresh_task_list(wxArrayString & a_members)
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
    wxString str_sql, str_sql1,str_sql2;

    wxTreeItemId root = tlc_task_list->GetRootItem();
    tlc_task_list->DeleteChildren (root);

    int i_count = a_members.GetCount();

    str_sql1= wxT("(SELECT index_id, concat(contract_id,' ', project_name,'-',project_id) as project_name, mat_req_date, drawing_req_date, \
                          nonstd_catalog, nonstd_desc,  res_person,(select name from s_employee where employee_id = res_person) as res_person_name, header_status ,\
                          nonstd_value, link_list from v_nonstd_app_item  WHERE header_status=3  and  (");

    for(int i=0; i<i_count; i++)
    {

        if(i==i_count-1)
             str_sql1 = str_sql1 + wxT(" res_person ='")+a_members.Item(i).Left(8)+wxT("'))");
        else
            str_sql1 = str_sql1 + wxT(" res_person ='")+a_members.Item(i).Left(8)+wxT("' or ");

    }
    str_sql2 = wxT("(SELECT index_id, concat(contract_id,' ', project_name,'-',project_id) as project_name, mat_req_date, drawing_req_date, \
                          nonstd_catalog, nonstd_desc,  res_person,(select name from s_employee where employee_id = res_person) as res_person_name, header_status ,\
                          nonstd_value, link_list from  v_nonstd_app_item_instance  where (header_status=1 or header_status=3 or header_status=10) AND status=1 and (");

   for(int j=0;j<i_count;j++)
   {
       if(j==i_count-1)
        str_sql2=str_sql2+wxT(" res_engineer ='")+a_members.Item(j).Left(8)+wxT("'))" );
       else
        str_sql2 = str_sql2+ wxT(" res_engineer ='")+a_members.Item(j).Left(8)+wxT("' or " );
   }

    str_sql = str_sql1 +wxT(" UNION ")+str_sql2 + wxT(" ORDER BY drawing_req_date, index_id ASC;");


    wxPostgreSQLresult* _res;
     _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }


    int i_status;

    _res->MoveFirst();

    i_count = _res->GetRowsNumber();

    wxTreeItemId parent_item;
    wxString str_index_id;
    wxString str_res_person;
    wxString str_link_list;
    for(int i=0;i<i_count;i++)
    {
       str_index_id = _res->GetVal(wxT("index_id"));
       parent_item = tlc_task_list->AppendItem(root, str_index_id);
       tlc_task_list->SetItemText(parent_item,1,_res->GetVal(wxT("project_name")));
       tlc_task_list->SetItemText(parent_item,2,DateToStrFormat(_res->GetDate(wxT("mat_req_date"))));
       tlc_task_list->SetItemText(parent_item,3,DateToStrFormat(_res->GetDate(wxT("drawing_req_date"))));
       tlc_task_list->SetItemText(parent_item,4,nstd_status_to_str(_res->GetInt(wxT("header_status"))));

       str_res_person= _res->GetVal(wxT("res_person"));



       tlc_task_list->SetItemText(parent_item,5,str_res_person);
       tlc_task_list->SetItemText(parent_item,6,_res->GetVal(wxT("res_person_name")));
       tlc_task_list->SetItemText(parent_item,7,_res->GetVal(wxT("nonstd_catalog")));
       tlc_task_list->SetItemText(parent_item,8,_res->GetVal(wxT("nonstd_desc")));
       tlc_task_list->SetItemText(parent_item,9,_res->GetVal(wxT("nonstd_value")));

       str_link_list = _res->GetVal(wxT("link_list"));
       tlc_task_list->SetItemText(parent_item,11,str_link_list);

       append_tree_leaf(parent_item, str_index_id, str_res_person, str_link_list, cb_filter->IsChecked());

       tlc_task_list->Expand(parent_item);

       if(str_res_person != gr_para.login_user)
       {

            tlc_task_list->SetItemBackgroundColour(parent_item, *wxCYAN);
       }else
            tlc_task_list->SetItemBackgroundColour(parent_item, *wxLIGHT_GREY);

       _res->MoveNext();
    }

    _res->Clear();
    refresh_level();
}

void nstd_mat_muti_level_task_list::refresh_task_list(wxString s_member)
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
    wxString str_sql, str_sql1,str_sql2;

    wxTreeItemId root = tlc_task_list->GetRootItem();
    tlc_task_list->DeleteChildren (root);


    str_sql1= wxT("(SELECT index_id, concat(contract_id,' ', project_name,'-',project_id) as project_name, mat_req_date, drawing_req_date, \
                          nonstd_catalog, nonstd_desc,  res_person,(select name from s_employee where employee_id = res_person) as res_person_name, header_status ,\
                          nonstd_value, link_list from v_nonstd_app_item  WHERE header_status=3 AND  res_person ='")+s_member+wxT("')");

    str_sql2 = wxT("(SELECT index_id, concat(contract_id,' ', project_name,'-',project_id) as project_name, mat_req_date, drawing_req_date, \
                          nonstd_catalog, nonstd_desc,  res_person,(select name from s_employee where employee_id = res_person) as res_person_name, header_status ,\
                          nonstd_value, link_list from  v_nonstd_app_item_instance  where (header_status=1 or header_status=3 or header_status=10) AND status=1 and res_engineer ='")+s_member+wxT("')" );


    str_sql = str_sql1 +wxT(" UNION ")+str_sql2 + wxT(" ORDER BY drawing_req_date, index_id ASC;");


    wxPostgreSQLresult* _res;
     _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }


    int i_status;

    _res->MoveFirst();

    int i_count = _res->GetRowsNumber();

    wxTreeItemId parent_item;
    wxString str_index_id;
    wxString str_res_person;
    wxString str_link_list;
    for(int i=0;i<i_count;i++)
    {
       str_index_id = _res->GetVal(wxT("index_id"));
       parent_item = tlc_task_list->AppendItem(root, str_index_id);
       tlc_task_list->SetItemText(parent_item,1,_res->GetVal(wxT("project_name")));
       tlc_task_list->SetItemText(parent_item,2,DateToStrFormat(_res->GetDate(wxT("mat_req_date"))));
       tlc_task_list->SetItemText(parent_item,3,DateToStrFormat(_res->GetDate(wxT("drawing_req_date"))));
       tlc_task_list->SetItemText(parent_item,4,nstd_status_to_str(_res->GetInt(wxT("header_status"))));

       str_res_person= _res->GetVal(wxT("res_person"));



       tlc_task_list->SetItemText(parent_item,5,str_res_person);
       tlc_task_list->SetItemText(parent_item,6,_res->GetVal(wxT("res_person_name")));
       tlc_task_list->SetItemText(parent_item,7,_res->GetVal(wxT("nonstd_catalog")));
       tlc_task_list->SetItemText(parent_item,8,_res->GetVal(wxT("nonstd_desc")));
       tlc_task_list->SetItemText(parent_item,9,_res->GetVal(wxT("nonstd_value")));

       str_link_list = _res->GetVal(wxT("link_list"));
       tlc_task_list->SetItemText(parent_item,11,str_link_list);

       append_tree_leaf(parent_item, str_index_id, str_res_person, str_link_list, cb_filter->IsChecked());
       tlc_task_list->Expand(parent_item);

       if(str_res_person != gr_para.login_user)
       {
            //tlc_task_list->Expand(parent_item);
            tlc_task_list->SetItemBackgroundColour(parent_item, *wxRED);
       }else
            tlc_task_list->SetItemBackgroundColour(parent_item, *wxLIGHT_GREY);

       _res->MoveNext();
    }

    _res->Clear();
    refresh_level();
}

void nstd_mat_muti_level_task_list::append_tree_leaf(wxTreeItemId &parent_id, wxString str_index_id, wxString &s_res_person, wxString &s_link_list,  bool is_engineer)
{
    wxString str_sql = wxT("select batch_id,nstd_mat_app_id, res_engineer,(select name from s_employee where employee_id=res_engineer) as res_engineer_name,\
                           instance_nstd_desc,status, instance_remarks,ins_start_date,ins_finish_date from l_nonstd_app_item_instance where index_id = '")+str_index_id+wxT("'");

    if(s_res_person != gr_para.login_user)
    {
        str_sql = str_sql + wxT(" AND res_engineer ='")+gr_para.login_user+wxT("' ");
    }

    if(!is_engineer && s_res_person == gr_para.login_user)
    {
        str_sql = str_sql + wxT(" AND res_engineer = NULL ");
    }

    str_sql = str_sql + wxT(" ORDER BY index_mat_id ASC;");

    wxPostgreSQLresult* _res = wxGetApp().app_sql_select(str_sql);
    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int i_count = _res->GetRowsNumber();

    wxTreeItemId leaf_item;
    int i_active=0;
    int i_finish=0;
    int i_status;
    for(int i=0;i<i_count;i++)
    {

        leaf_item = tlc_task_list->AppendItem(parent_id, str_index_id);
        tlc_task_list->SetItemText(leaf_item,1, _res->GetVal(wxT("batch_id")));
        tlc_task_list->SetItemText(leaf_item,2,DateToStrFormat(_res->GetDate(wxT("ins_start_date"))));
        tlc_task_list->SetItemText(leaf_item,3,DateToStrFormat(_res->GetDate(wxT("ins_finish_date"))));
        i_status=_res->GetInt(wxT("status"));
        if (i_status==1 )
            i_active+=1;
        else if (i_status==2)
            i_finish+=1;
        tlc_task_list->SetItemText(leaf_item,4,prj_status_to_str(i_status));
        tlc_task_list->SetItemText(leaf_item,5,_res->GetVal(wxT("res_engineer")));
        tlc_task_list->SetItemText(leaf_item,6,_res->GetVal(wxT("res_engineer_name")));
        tlc_task_list->SetItemText(leaf_item,8,_res->GetVal(wxT("instance_nstd_desc")));
        tlc_task_list->SetItemText(leaf_item,10,_res->GetVal(wxT("nstd_mat_app_id")));
        tlc_task_list->SetItemText(leaf_item, 11, s_link_list);

        _res->MoveNext();
    }

    _res->Clear();
    wxString str = "active:"+NumToStr(i_active)+"; Finish:"+NumToStr(i_finish);
    tlc_task_list->SetItemText(parent_id,4,str);

}

void nstd_mat_muti_level_task_list::OnButton1Click(wxCommandEvent& event)
{
    wxTreeItemId  sel_item = tlc_task_list->GetSelection();

    if(!sel_item.IsOk())
    {
        wxMessageBox(_("尚未选择项次，请至少选择一项任务!"), _("提示"), wxOK);
        return;
    }

    wxTreeItemId root = tlc_task_list->GetRootItem();

    if(tlc_task_list->GetItemParent(sel_item)==root)
        m_level = 1;
    else
        m_level = 2;

    wxString str_res_person = tlc_task_list->GetItemText(sel_item, 5);

    if(str_res_person != gr_para.login_user && m_level ==1)
    {
        wxMessageBox(_("此一级任务并非有阁下负责，请另选一项次!"), _("错误"), wxOK);
        tlc_task_list->Unselect();
        return;
    }

    m_index_id = tlc_task_list->GetItemText(sel_item, 0);

    if(m_level == 2)
        m_batch_id = tlc_task_list->GetItemText(sel_item, 1);
    else
        m_batch_id.Empty();

    wxString str_units_list = tlc_task_list->GetItemText(sel_item, 11);

    if(!str_units_list.IsEmpty())
        m_units = wxStringTokenize(str_units_list ,wxT(";"), wxTOKEN_DEFAULT  );
    else m_units.Clear();

    EndDialog(wxID_OK);
}

void nstd_mat_muti_level_task_list::OnButton2Click(wxCommandEvent& event)
{

    EndDialog(wxID_CANCEL);
}

void nstd_mat_muti_level_task_list::OnMenuItem1Selected(wxCommandEvent& event)
{
    wxTreeItemId  sel_item = tlc_task_list->GetSelection();
    if(!sel_item.IsOk())
    {
        wxMessageBox(_("请务必选择一个项次!"), _("提示"), wxOK);
        return;
    }

    wxString str;
    wxArrayString array_units;

    str = tlc_task_list->GetItemText(sel_item, 11);

    if(str.IsEmpty())
         return;

    array_units = wxStringTokenize(str ,wxT(";"), wxTOKEN_DEFAULT  );

    nstd_task_author dlg;

    dlg.m_units = array_units;
    dlg.refresh_list();
    dlg.ShowModal();

}

void nstd_mat_muti_level_task_list::Ontlc_task_listRightClick(wxTreeEvent& event)
{
    PopupMenu(&menu_info, event.GetPoint());
}


void nstd_mat_muti_level_task_list::Oncb_filterClick(wxCommandEvent& event)
{
    wxTreeItemId root = tlc_task_list->GetRootItem();

    wxTreeItemIdValue cookie;
    wxTreeItemId child_item = tlc_task_list->GetFirstChild(root,cookie);

    wxString str_index_id;
    wxString str_res_person;
    wxString str_link_list;

    while(child_item.IsOk())
    {
        tlc_task_list->DeleteChildren(child_item);

        str_index_id = tlc_task_list->GetItemText(child_item, 0);

        str_res_person = tlc_task_list->GetItemText(child_item, 5);

        str_link_list = tlc_task_list->GetItemText(child_item, 11);

        append_tree_leaf(child_item, str_index_id, str_res_person,str_link_list, cb_filter->IsChecked());

        child_item = tlc_task_list->GetNextSibling(child_item);
    }

}
