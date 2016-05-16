#include "nstd_app_unit_list.h"
#include "wfApp.h"

#include <wx/arrimpl.cpp>
//(*InternalHeaders(nstd_app_unit_list)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(nstd_app_unit_list)
const long nstd_app_unit_list::ID_BUTTON_OK = wxNewId();
const long nstd_app_unit_list::ID_BUTTON_CANCEL = wxNewId();
//*)
const long nstd_app_unit_list::ID_TREELISTCTRL_UNIT_LIST = wxNewId();

BEGIN_EVENT_TABLE(nstd_app_unit_list,wxDialog)
	//(*EventTable(nstd_app_unit_list)
	//*)
END_EVENT_TABLE()



nstd_app_unit_list::nstd_app_unit_list(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(nstd_app_unit_list)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX, _T("id"));
	SetClientSize(wxSize(800,300));
	Move(wxDefaultPosition);
	SetMinSize(wxSize(400,300));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("项目清单"));
	BoxSizer1->Add(StaticBoxSizer1, 5, wxALL|wxEXPAND, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON_OK, _("确定"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_OK"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON_CANCEL, _("取消"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CANCEL"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 0);
	SetSizer(BoxSizer1);
	SetSizer(BoxSizer1);
	Layout();

	Connect(ID_BUTTON_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_app_unit_list::OnButton1Click);
	Connect(ID_BUTTON_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_app_unit_list::OnButton2Click);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&nstd_app_unit_list::OnInit);
	//*)

//	b_active = true;
    BuildDataViewCtrl();
    StaticBoxSizer1->Add(tlc_proj_list, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0 );
    Layout();
}

nstd_app_unit_list::~nstd_app_unit_list()
{
	//(*Destroy(nstd_app_unit_list)
	//*)

    delete m_imageList;

    wxTreeItemId root = tlc_proj_list->GetRootItem();
    tlc_proj_list->DeleteChildren (root);
    tlc_proj_list->DeleteRoot();
}


void nstd_app_unit_list::OnInit(wxInitDialogEvent& event)
{
 //   refresh_list();
}

void nstd_app_unit_list::BuildDataViewCtrl()
{
   InitImageList();

    tlc_proj_list = new wxcode::wxTreeListCtrl(this, ID_TREELISTCTRL_UNIT_LIST ,
                                  wxDefaultPosition, wxDefaultSize,
                                  wxTR_DEFAULT_STYLE| wxTR_COLUMN_LINES|wxTR_HIDE_ROOT|wxTR_ROW_LINES|wxTR_MULTIPLE | wxTR_FULL_ROW_HIGHLIGHT);

    tlc_proj_list->SetImageList(m_imageList);


    tlc_proj_list->AddColumn(_("项目信息"),200,wxALIGN_LEFT,-1,true,false);
    tlc_proj_list->AddColumn(_("索引"),0,wxALIGN_LEFT,-1,false,false);
    tlc_proj_list->AddColumn(_("梯号"),50,wxALIGN_LEFT, -1,true,false );
    tlc_proj_list->AddColumn(_("梯型"),100,wxALIGN_LEFT, -1,true,false );
    tlc_proj_list->AddColumn(_("项目类型"),100,wxALIGN_LEFT, -1,true,false );
    tlc_proj_list->AddColumn(_("配置完成日期"),100,wxALIGN_LEFT, -1,true,false);
    tlc_proj_list->AddColumn(_("项目状态"),0,wxALIGN_LEFT,-1,false,false);
    tlc_proj_list->AddColumn(_("是否紧急"),0,wxALIGN_LEFT,-1,false,false);

    tlc_proj_list->AddRoot (_("配置项目"));
}

void nstd_app_unit_list::InitImageList()
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

void nstd_app_unit_list::OnButton1Click(wxCommandEvent& event)
{
    array_select.Clear();
    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_proj_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_proj_list->GetSelections( items );
    wxString str;
    wxString str_date, str_temp;

    if(items.IsEmpty())
    {
        wxMessageBox(_("请选择项目！"),_("信息"), wxOK);
        return;
    }

    for( iter = items.begin(); iter<items.end(); iter++)
    {
        wxTreeItemId sel_item = *iter;
        if(tlc_proj_list->GetItemParent(sel_item)==root)
        {
            if(m_proj.IsEmpty())
               m_proj = tlc_proj_list->GetItemText(sel_item, 0);
            wxTreeItemIdValue cookie;
            wxTreeItemId child_item = tlc_proj_list->GetFirstChild(sel_item,cookie);
            while(child_item.IsOk())
            {
                str= tlc_proj_list->GetItemText(child_item, 0);
                str=str+wxT(" ")+tlc_proj_list->GetItemText(child_item, 2);

                str_temp = tlc_proj_list->GetItemText(child_item, 5);
                array_select.Add(str);

                child_item = tlc_proj_list->GetNextSibling(child_item);
            }
        }else
        {
            if(m_proj.IsEmpty())
            {
                wxTreeItemId parent_item = tlc_proj_list->GetItemParent(sel_item);
                m_proj = tlc_proj_list->GetItemText(parent_item, 0);
            }

            str = tlc_proj_list->GetItemText(sel_item, 0);
            str =str +wxT(" ")+tlc_proj_list->GetItemText(sel_item, 2);
            str_temp = tlc_proj_list->GetItemText(sel_item, 5);
            array_select.Add(str);
        }


        if(str_date.IsEmpty()&& !str_temp.IsEmpty())
            str_date = str_temp;

        if(str_date != str_temp)
        {
            check_min_date(str_date, str_temp);
        }

    }

    m_req_finish = StrToDate(str_date);
    if(!check_one_prj())
    {
        wxMessageBox(_("一张非标申请只能对应一个项目, 请取消其他项目!"),_("信息"), wxOK);
        return;
    }

    if(wxMessageBox(_("确认针对此任务生成非标申请?"),_("非标申请确认"),wxYES_NO)==wxYES)
        EndDialog(wxID_OK);
    else EndDialog(wxID_CANCEL);
}

bool nstd_app_unit_list::check_one_prj()
{
   if(array_select.IsEmpty())
       return false;

   int i_count = array_select.GetCount();

   if(i_count==1)
       return true;

   wxString str = array_select.Item(0).Left(10);

   for(int i =1;i<i_count;i++)
   {
       if(array_select.Item(i).Left(10) == str)
          continue;
       else
       {
           return false;
       }
   }

   return true;
}

wxDateTime nstd_app_unit_list::check_min_date(wxString &str1, wxString str2)
{
    wxDateTime dt1,dt2, dt_result;

    dt1 = StrToDate(str1);
    dt2 = StrToDate(str2);

    dt_result = (dt1.IsLaterThan(dt2) ? dt2:dt1);

    str1 = DateToStrFormat(dt_result);

    return dt_result;
}

void nstd_app_unit_list::OnButton2Click(wxCommandEvent& event)
{
    EndDialog(wxID_CANCEL);
}

void nstd_app_unit_list::refresh_list()
{
     if(!gr_para.login_status)
    {
        wxMessageBox(_("尚未登陆,无法做任何操作!"),_("信息"), wxOK);
        return;
    }

    if(!wxGetApp().conn->IsAlive())
    {
        wxMessageBox(_("系统连接已断开,请重新连接!"),_("信息"), wxOK);
        wxGetApp().clear_login();
        return;
    }


    wxTreeItemId root = tlc_proj_list->GetRootItem();
    tlc_proj_list->DeleteChildren (root);

    wxString strSql;

    if(b_active)
     {
          strSql = wxT("SELECT conf_batch_id, concat(contract_id,' ', project_name) as project_name, project_id,\
                         instance_id as wbs_no, lift_no, elevator_type, project_catalog, req_configure_finish, \
                         status, is_urgent from v_task_list1 WHERE action_id = 'AT00000004' \
                         AND is_active = true AND operator_id = '")+gr_para.login_user+ wxT("' AND (status ='1' OR status = '3' ) ORDER BY req_configure_finish, conf_batch_id, instance_id ASC ; ");
    }else
    {
       strSql = wxT("SELECT conf_batch_id, concat(contract_id,' ', project_name) as project_name, project_id,\
                         instance_id as wbs_no, lift_no, elevator_type, project_catalog, req_configure_finish, \
                         status, is_urgent from v_task_list1 WHERE action_id = 'AT00000004' \
                         AND is_active = false AND operator_id = '")+gr_para.login_user+ wxT("' AND status !='4' AND  status != '-1' AND instance_id like'%")+m_str_unit.Upper()+wxT("%' ORDER BY req_configure_finish, conf_batch_id, instance_id ASC ; ");

    }
    wxPostgreSQLresult* _res = wxGetApp().app_sql_select(strSql);
    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int irow = _res->GetRowsNumber();
    int i_status;
    bool is_urgent;

    wxString s_index, s_project_name, s_wbs, s_lift_id, s_elevator_type, s_project_type, s_req_finish, s_res_person, s_batch_id;

    wxTreeItemId prj_item,leaf_item;
    int i_type;

    _res->MoveFirst();

    for(int i = 0; i<irow;i++)
    {
        s_batch_id = _res->GetVal(wxT("conf_batch_id"));
        s_project_name = _res->GetVal(wxT("project_name"));
        s_wbs = _res->GetVal(wxT("wbs_no"));


        if(s_batch_id.IsEmpty())
        {
            if(s_index != _res->GetVal(wxT("project_id")) || s_req_finish != DateToStrFormat(_res->GetDate(wxT("req_configure_finish"))))
            {
                s_index = _res->GetVal(wxT("project_id"));
                prj_item = tlc_proj_list->AppendItem(root, s_project_name);
                tlc_proj_list->SetItemText(prj_item, 1,s_index);
 //               tlc_proj_list->Expand(prj_item);
            }

        }else
        {
            if(s_index != s_batch_id)
            {
                s_index = s_batch_id;
                prj_item = tlc_proj_list->AppendItem(root, s_project_name);
                tlc_proj_list->SetItemText(prj_item, 1, _res->GetVal(wxT("project_id")));
   //             tlc_proj_list->Expand(prj_item);
            }
        }


        s_lift_id = _res->GetVal(wxT("lift_no"));
        s_elevator_type = _res->GetVal(wxT("elevator_type"));
        i_type = _res->GetInt(wxT("project_catalog"));
        s_project_type = prj_catalog_to_str(i_type);

        s_req_finish = DateToStrFormat(_res->GetDate(wxT("req_configure_finish")));

        is_urgent = _res->GetBool(wxT("is_urgent"));
        i_status = _res->GetInt(wxT("status"));

        leaf_item = tlc_proj_list->AppendItem(prj_item,s_wbs,-1,-1);
        tlc_proj_list->SetItemText(leaf_item, 1, s_index);
        tlc_proj_list->SetItemText(leaf_item, 2, s_lift_id);
        tlc_proj_list->SetItemText(leaf_item, 3, s_elevator_type);
        tlc_proj_list->SetItemText(leaf_item, 4, s_project_type);
        tlc_proj_list->SetItemText(leaf_item, 5, s_req_finish);
        tlc_proj_list->SetItemText(leaf_item, 6, NumToStr(i_status));
        tlc_proj_list->SetItemText(leaf_item, 7, BoolToStr(is_urgent));

        _res->MoveNext();
    }

    refresh_project_level();
 //   tlc_proj_list->Expand(root);
    _res->Clear();


}


void nstd_app_unit_list::refresh_project_level()
{
    int i_count_urgent;
    int i_count_pre;
    int i_count_lean;
    int i_count;
    wxString str_project_catalog;

    wxTreeItemId root = tlc_proj_list->GetRootItem();

    wxTreeItemIdValue cookie;
    wxTreeItemId item = tlc_proj_list->GetFirstChild(root,cookie);

    while(item.IsOk())
    {
        wxTreeItemIdValue cookie_child;
        wxTreeItemId child_item = tlc_proj_list->GetFirstChild(item,cookie_child);
        i_count_urgent = 0;
        i_count_pre = 0;
        i_count_lean = 0;

        while(child_item.IsOk())
        {
            str_project_catalog=  tlc_proj_list->GetItemText(child_item,4);
            if(str_project_catalog == _("Lean Project"))
            {
                tlc_proj_list->SetItemBackgroundColour(child_item,  *wxYELLOW);
                i_count_lean++;
            }else if(str_project_catalog == _("Pre-engineering"))
            {
                tlc_proj_list->SetItemBackgroundColour(child_item,  *wxCYAN);
                i_count_pre++;
            }
            else if(tlc_proj_list->GetItemText(child_item,7)==wxT("true"))
            {
                tlc_proj_list->SetItemBackgroundColour(child_item, *wxGREEN);
                i_count_urgent++;
            }else tlc_proj_list->SetItemBackgroundColour(child_item, *wxWHITE);

            child_item = tlc_proj_list->GetNextSibling(child_item);

        }

        i_count = tlc_proj_list->GetChildrenCount(item);
        if(i_count_lean == i_count )
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

        tlc_proj_list->SetItemText(item, 2, NumToStr(i_count)+_("台"));

        item = tlc_proj_list->GetNextSibling(item);
    }

    tlc_proj_list->ExpandAll(root);
}
