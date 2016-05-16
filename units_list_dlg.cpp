#include "units_list_dlg.h"
#include "wfApp.h"
#include "utils/wf_operator.h"
//(*InternalHeaders(units_list_dlg)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(units_list_dlg)
const long units_list_dlg::ID_BUTTON_OK = wxNewId();
const long units_list_dlg::ID_BUTTON_CANCEL = wxNewId();
//*)
const long units_list_dlg::ID_TREELISTCTRL_UNIT_LIST = wxNewId();

BEGIN_EVENT_TABLE(units_list_dlg,wxDialog)
	//(*EventTable(units_list_dlg)
	//*)
END_EVENT_TABLE()

units_list_dlg::units_list_dlg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(units_list_dlg)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX, _T("id"));
	SetClientSize(wxSize(800,400));
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("项目清单"));
	BoxSizer1->Add(StaticBoxSizer1, 5, wxALL|wxEXPAND, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button_ok = new wxButton(this, ID_BUTTON_OK, _("确认"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_OK"));
	BoxSizer2->Add(Button_ok, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button_cancel = new wxButton(this, ID_BUTTON_CANCEL, _("取消"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CANCEL"));
	BoxSizer2->Add(Button_cancel, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL, 0);
	SetSizer(BoxSizer1);
	SetSizer(BoxSizer1);
	Layout();

	Connect(ID_BUTTON_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&units_list_dlg::OnButton_okClick);
	Connect(ID_BUTTON_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&units_list_dlg::OnButton_cancelClick);
	//*)
    BuildDataViewCtrl();
    StaticBoxSizer1->Add(tlc_proj_list, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0 );
    Layout();
}

units_list_dlg::~units_list_dlg()
{
	//(*Destroy(units_list_dlg)
	//*)
}

void units_list_dlg::BuildDataViewCtrl()
{
    tlc_proj_list = new wxcode::wxTreeListCtrl(this, ID_TREELISTCTRL_UNIT_LIST ,
                                  wxDefaultPosition, wxDefaultSize,
                                  wxTR_DEFAULT_STYLE| wxTR_COLUMN_LINES|wxTR_HIDE_ROOT|wxTR_ROW_LINES|wxTR_MULTIPLE | wxTR_FULL_ROW_HIGHLIGHT);

    tlc_proj_list->AddColumn(_("项目信息"),200,wxALIGN_LEFT,-1,true,false);//0
    tlc_proj_list->AddColumn(_("索引"),0,wxALIGN_LEFT,-1,false,false);//1
    tlc_proj_list->AddColumn(_("梯号"),50,wxALIGN_LEFT, -1,true,false );//2
    tlc_proj_list->AddColumn(_("梯型"),100,wxALIGN_LEFT, -1,true,false );//3
    tlc_proj_list->AddColumn(_("项目类型"),100,wxALIGN_LEFT, -1,true,false );//4
    tlc_proj_list->AddColumn(_("配置工程师ID"),0, wxALIGN_LEFT,-1, false, false);//5
    tlc_proj_list->AddColumn(_("配置工程师"),100,wxALIGN_LEFT, -1, true, false);//6
    tlc_proj_list->AddColumn(_("项目状态"),50,wxALIGN_LEFT,-1,true,false);//7
    tlc_proj_list->AddColumn(_("配置完成日期"),100,wxALIGN_LEFT, -1,true,false);//8
    tlc_proj_list->AddColumn(_("发货期"),100,wxALIGN_LEFT, -1, true, false);//9

    tlc_proj_list->AddColumn(_("是否紧急"),50,wxALIGN_LEFT,-1,true,false);//10

    tlc_proj_list->AddRoot (_("配置项目"));
}

void units_list_dlg::refresh_list()
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

    wxString s_sql = wxT("SELECT contract_id, project_name,  wbs_no, project_id, elevator_id, lift_no, status, is_urgent, project_catalog, nonstd_level, req_delivery_date, \
       req_configure_finish, batch_id, elevator_type, (select operator_id from l_proc_act where instance_id=wbs_no and action_id='AT00000004' and workflow_id='WF0002') as operator_id FROM v_unit_info where ")+
       m_clause+wxT(" and status>=1 and status<=8 order by req_configure_finish, batch_id,wbs_no asc;");

    wxPostgreSQLresult* _res = wxGetApp().app_sql_select(s_sql);
    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    wxTreeItemId prj_item,leaf_item;
    wxString s_index,s_batch_id, s_project_name, s_wbs,s_req_finish, s_delivery_date ;
    bool is_urgent;
    int i_type,i_status;

    int irow = _res->GetRowsNumber();
    for(int i = 0; i<irow;i++)
    {
        s_batch_id = _res->GetVal(wxT("batch_id"));
        s_project_name = _res->GetVal(wxT("contract_id"))+wxT(" ")+_res->GetVal(wxT("project_name"));
        s_wbs = _res->GetVal(wxT("wbs_no"));


        if(s_batch_id.IsEmpty())
        {
            if(s_index != _res->GetVal(wxT("project_id")) || s_req_finish != DateToStrFormat(_res->GetDate(wxT("req_configure_finish"))))
            {
                s_index = _res->GetVal(wxT("project_id"));
                prj_item = tlc_proj_list->AppendItem(root, s_project_name);
                tlc_proj_list->SetItemText(prj_item, 1,s_index);
            }

        }else
        {
            if(s_index != s_batch_id)
            {
                s_index = s_batch_id;
                prj_item = tlc_proj_list->AppendItem(root, s_project_name);
                tlc_proj_list->SetItemText(prj_item, 1, _res->GetVal(wxT("project_id")));
            }
        }

        i_type = _res->GetInt(wxT("project_catalog"));
        s_req_finish = DateToStrFormat(_res->GetDate(wxT("req_configure_finish")));
        s_delivery_date = DateToStrFormat(_res->GetDate(wxT("req_delivery_date")));

        is_urgent = _res->GetBool(wxT("is_urgent"));
        i_status = _res->GetInt(wxT("status"));

        leaf_item = tlc_proj_list->AppendItem(prj_item,s_wbs,-1,-1);
        tlc_proj_list->SetItemText(leaf_item, 1, s_index);
        tlc_proj_list->SetItemText(leaf_item, 2, _res->GetVal(wxT("lift_no")));
        tlc_proj_list->SetItemText(leaf_item, 3, _res->GetVal(wxT("elevator_type")));
        tlc_proj_list->SetItemText(leaf_item, 4, prj_catalog_to_str(i_type));
        tlc_proj_list->SetItemText(leaf_item, 5, _res->GetVal(wxT("operator_id")));

        tlc_proj_list->SetItemText(leaf_item, 7, prj_status_to_str(i_status));
        tlc_proj_list->SetItemText(leaf_item, 8, s_req_finish);
        tlc_proj_list->SetItemText(leaf_item, 9, s_delivery_date);
        tlc_proj_list->SetItemText(leaf_item, 10, BoolToY(is_urgent));

        _res->MoveNext();
    }

    refresh_project_level();

    _res->Clear();
}

void units_list_dlg::refresh_project_level()
{
    int i_count;
    wxString str_project_catalog;
    wxString s_engineer,s_operator_id;

    wxTreeItemId root = tlc_proj_list->GetRootItem();

    wxTreeItemIdValue cookie;
    wxTreeItemId item = tlc_proj_list->GetFirstChild(root,cookie);

    while(item.IsOk())
    {
        wxTreeItemIdValue cookie_child;
        wxTreeItemId child_item = tlc_proj_list->GetFirstChild(item,cookie_child);

        while(child_item.IsOk())
        {
            s_operator_id = tlc_proj_list->GetItemText(child_item, 5).Trim();
            if(s_operator_id.IsEmpty())
            {
                child_item = tlc_proj_list->GetNextSibling(child_item);
                continue;
            }

            s_engineer = get_operator_name(s_operator_id);
            tlc_proj_list->SetItemText(child_item, 6,s_engineer);
            child_item = tlc_proj_list->GetNextSibling(child_item);

        }

        i_count = tlc_proj_list->GetChildrenCount(item);

        tlc_proj_list->SetItemText(item, 2, NumToStr(i_count)+_("台"));

        item = tlc_proj_list->GetNextSibling(item);
    }

    tlc_proj_list->ExpandAll(root);
}

bool units_list_dlg::check_one_prj()
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

void units_list_dlg::OnButton_okClick(wxCommandEvent& event)
{
    array_select.Clear();
    array_engineer.Clear();
    wxArrayTreeItemIds items;
    wxTreeItemId root = tlc_proj_list->GetRootItem();

    wxArrayTreeItemIds::iterator iter;
    tlc_proj_list->GetSelections( items );
    wxString str;

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
                if(array_select.Index(str)==wxNOT_FOUND)
                    array_select.Add(str);

                str = tlc_proj_list->GetItemText(child_item, 5);

                if(!str.IsEmpty()&& array_engineer.Index(str)==wxNOT_FOUND)
                {
                    array_engineer.Add(str);
                }

                child_item = tlc_proj_list->GetNextSibling(child_item);
            }
        }
        else
        {
            if(m_proj.IsEmpty())
            {
                wxTreeItemId parent_item = tlc_proj_list->GetItemParent(sel_item);
                m_proj = tlc_proj_list->GetItemText(parent_item, 0);
            }

            str = tlc_proj_list->GetItemText(sel_item, 0);
                if(array_select.Index(str)==wxNOT_FOUND)
                    array_select.Add(str);
            str = tlc_proj_list->GetItemText(sel_item, 5);

            if(!str.IsEmpty()&& array_engineer.Index(str)==wxNOT_FOUND)
            {
                array_engineer.Add(str);
            }
        }

    }

    if(!check_one_prj())
    {
        wxMessageBox(_("一张申请只能对应同一个项目, 请取消其他项目!"),_("信息"), wxOK);
        return;
    }

    if(wxMessageBox(_("确认针这些项目生成SPEC&GAD申请单编号?"),_("确认"),wxYES_NO)==wxYES)
        EndDialog(wxID_OK);
    else EndDialog(wxID_CANCEL);
}

void units_list_dlg::OnButton_cancelClick(wxCommandEvent& event)
{
    EndDialog(wxID_CANCEL);
}
