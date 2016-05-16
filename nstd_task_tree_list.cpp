#include "nstd_task_tree_list.h"
#include "wfApp.h"

//(*InternalHeaders(nstd_task_tree_list)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(nstd_task_tree_list)
const long nstd_task_tree_list::ID_BUTTON1 = wxNewId();
//*)
const long nstd_task_tree_list::ID_TREE_TASK_LIST = wxNewId();

BEGIN_EVENT_TABLE(nstd_task_tree_list,wxDialog)
	//(*EventTable(nstd_task_tree_list)
	//*)
END_EVENT_TABLE()

nstd_task_tree_list::nstd_task_tree_list(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(nstd_task_tree_list)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX, _T("id"));
	SetClientSize(wxSize(800,400));
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("任务清单"));
	BoxSizer1->Add(StaticBoxSizer1, 5, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("退出"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	SetSizer(BoxSizer1);
	Layout();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_task_tree_list::OnButton1Click);
	//*)

	buildtreeheader();
    StaticBoxSizer1->Add(tlc_task_list, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0 );
    Layout();
}

nstd_task_tree_list::~nstd_task_tree_list()
{
	//(*Destroy(nstd_task_tree_list)
	//*)
}


void nstd_task_tree_list::OnButton1Click(wxCommandEvent& event)
{
    EndDialog(wxID_CANCEL);
}

void nstd_task_tree_list::buildtreeheader()
{
   tlc_task_list = new wxcode::wxTreeListCtrl(this, ID_TREE_TASK_LIST  ,
                                  wxDefaultPosition, wxDefaultSize,
                                  wxTR_DEFAULT_STYLE| wxTR_COLUMN_LINES|wxTR_HIDE_ROOT|wxTR_ROW_LINES|wxTR_MULTIPLE | wxTR_FULL_ROW_HIGHLIGHT);
    tlc_task_list->AddColumn(_("任务编号"),100,wxALIGN_LEFT,-1,true,false);//0
    tlc_task_list->AddColumn(_("任务信息"),100,wxALIGN_LEFT, -1,true,false );//1
    tlc_task_list->AddColumn(_("非标物料流程"),100,wxALIGN_LEFT, -1,true,false);//2
    tlc_task_list->AddColumn(_("物料需求日"),100,wxALIGN_LEFT, -1,true,false);//3
    tlc_task_list->AddColumn(_("非标设计流程"),100,wxALIGN_LEFT, -1,true,false );//4
    tlc_task_list->AddColumn(_("图纸需求日"),100,wxALIGN_LEFT, -1,true,false );//5
    tlc_task_list->AddColumn(_("非标类别"),100,wxALIGN_LEFT, -1,true,false );//6
    tlc_task_list->AddColumn(_("非标原因"),100,wxALIGN_LEFT, -1,true,false );//7
    tlc_task_list->AddColumn(_("负责人"),100,wxALIGN_LEFT, -1,true,false );//8
    tlc_task_list->AddColumn(_("任务状态"),100,wxALIGN_LEFT, -1,true,false);//9
    tlc_task_list->AddColumn(_("关联梯"),50,wxALIGN_LEFT,-1,true,false);//10

    tlc_task_list->AddRoot (_("非标任务"));
}

void nstd_task_tree_list::init_tree_list(wxArrayString &array_nstd_header)
{
     int i_count = array_nstd_header.GetCount();

     if(i_count == 0)
        return;

    wxTreeItemId root = tlc_task_list->GetRootItem();
    tlc_task_list->DeleteChildren (root);

    wxString str_sql = wxT("select index_id, index_mat_id, project_name, mat_req_date, drawing_req_date, \
                        nonstd_catalog,nonstd_desc,res_person, link_list,nstd_mat_app_id,has_nonstd_mat, has_nonstd_draw,\
                        instance_nstd_desc,instance_remarks, res_engineer,status,(select name from s_employee where employee_id=res_person)as res_person_name,\
                         (select name from s_employee where employee_id=res_engineer) as res_engineer_name  from v_nonstd_app_item_instance where status >=0 and (");

    for(int i=0;i<i_count; i++)
    {
        if(i==i_count -1)
            str_sql = str_sql + wxT(" index_id = '")+array_nstd_header.Item(i)+wxT("') order by index_id, index_mat_id asc;");
        else
            str_sql = str_sql + wxT(" index_id ='")+array_nstd_header.Item(i)+wxT("' or ");
    }

    wxPostgreSQLresult* _res =  wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int i_row = _res->GetRowsNumber();

    wxString str,str_head;
    wxTreeItemId branch_item,leaf_item;

    wxArrayString arr_result, arr_wbs;

    for(int i=0;i<i_row;i++)
    {
         if(str_head!= _res->GetVal(wxT("index_id")))
         {
             str = _res->GetVal(wxT("index_id"));

             str_head = str;

             branch_item = tlc_task_list->AppendItem(root, str);

             str = _res->GetVal(wxT("project_name"));

             tlc_task_list->SetItemText(branch_item, 1, str);

             str = DateToStrFormat(_res->GetDate(wxT("mat_req_date")));
             tlc_task_list->SetItemText(branch_item, 3, str);

             str = DateToStrFormat(_res->GetDate(wxT("drawing_req_date")));
             tlc_task_list->SetItemText(branch_item, 5, str);

             str = _res->GetVal(wxT("nonstd_catalog"));
             tlc_task_list->SetItemText(branch_item, 6, str);

             str = _res->GetVal(wxT("nonstd_desc"));
             tlc_task_list->SetItemText(branch_item, 7, str);

             str = _res->GetVal(wxT("res_person_name"));
             tlc_task_list->SetItemText(branch_item, 8, str);

             str = _res->GetVal(wxT("link_list"));

             if(!str.IsEmpty())
             {

                 arr_wbs = wxStringTokenize(str ,wxT(";"), wxTOKEN_DEFAULT  );

                 arr_result = combine_str(arr_wbs, wxT(";"),wxT("~"),wxT(","),true, false);

                 str = arr_result.Item(0);

                 arr_wbs.Clear();
                 arr_result.Clear();
             }

             tlc_task_list->SetItemText(branch_item, 10, str);
             tlc_task_list->Expand(branch_item);

        }

         str = _res->GetVal(wxT("index_mat_id"));

         leaf_item = tlc_task_list->AppendItem(branch_item,str,-1,-1);

         str = _res->GetVal(wxT("nstd_mat_app_id"));

         tlc_task_list->SetItemText(leaf_item, 1,str);

         str = BoolToY(_res->GetBool(wxT("has_nonstd_mat")));
         tlc_task_list->SetItemText(leaf_item, 2, str);

         str = BoolToY(_res->GetBool(wxT("has_nonstd_draw")));
         tlc_task_list->SetItemText(leaf_item, 4, str);

         str = _res->GetVal(wxT("instance_nstd_desc"));
         tlc_task_list->SetItemText(leaf_item, 6, str);

         str = _res->GetVal(wxT("instance_remarks"));
         tlc_task_list->SetItemText(leaf_item, 7, str);

         str = _res->GetVal(wxT("res_engineer_name"));
         tlc_task_list->SetItemText(leaf_item, 8, str);

         str =prj_status_to_str(_res->GetInt(wxT("status")));
         tlc_task_list->SetItemText(leaf_item, 9, str);

         _res->MoveNext();

    }

    _res->Clear();

}
