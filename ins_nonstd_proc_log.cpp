#include "ins_nonstd_proc_log.h"

//(*InternalHeaders(ins_nonstd_proc_log)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(ins_nonstd_proc_log)
const long ins_nonstd_proc_log::ID_LISTVIEW_DISPLAY = wxNewId();
const long ins_nonstd_proc_log::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ins_nonstd_proc_log,wxDialog)
	//(*EventTable(ins_nonstd_proc_log)
	//*)
END_EVENT_TABLE()

ins_nonstd_proc_log::ins_nonstd_proc_log(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ins_nonstd_proc_log)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	lv_proc_log = new wxListView(this, ID_LISTVIEW_DISPLAY, wxDefaultPosition, wxSize(663,175), wxLC_REPORT|wxLC_HRULES|wxLC_VRULES, wxDefaultValidator, _T("ID_LISTVIEW_DISPLAY"));
	BoxSizer1->Add(lv_proc_log, 6, wxALL|wxEXPAND, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("退出"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ins_nonstd_proc_log::OnButton1Click);
	//*)

   wxListItem itemCol;

    itemCol.SetText(_("非标编号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log->InsertColumn(0, itemCol);

    itemCol.SetText(_("项目信息"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log->InsertColumn(1, itemCol);

    itemCol.SetText(_("工作流"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log->InsertColumn(2, itemCol);

    itemCol.SetText(_("流程步骤"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log->InsertColumn(3, itemCol);

    itemCol.SetText(_("负责人"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log->InsertColumn(4, itemCol);

    itemCol.SetText(_("收到日期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log->InsertColumn(5, itemCol);

    itemCol.SetText(_("完成日期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log->InsertColumn(6, itemCol);

    itemCol.SetText(_("物料需求日"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log->InsertColumn(7, itemCol);

    itemCol.SetText(_("图纸需求日"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_proc_log->InsertColumn(8, itemCol);
}

ins_nonstd_proc_log::~ins_nonstd_proc_log()
{
	//(*Destroy(ins_nonstd_proc_log)
	//*)
}

void ins_nonstd_proc_log::Refresh_list_view(wxArrayString array_ins_list, wxArrayString array_workflow_id)
{
    if(array_ins_list.IsEmpty())
        return;

    int i_count= array_ins_list.GetCount();
    wxString str_sql1, str_sql2, str_sql;
    wxPostgreSQLresult* _res;

    int i_1=0;
    int i_2=0;

    for(int i = 0; i<i_count; i++)
    {
        wxString str = array_workflow_id.Item(i);
        if(array_workflow_id.Item(i) == wf_str_nonstd)
        {
            i_1++;
            if(i_1==1)
                str_sql1= str_sql1 + wxT("  SELECT instance_id, workflow_id,workflow_name, flow_ser, concat(contract_id,' ', project_name,'-',project_id) as project_info,\
                      is_active, action_name, concat(operator_id,'-',name) as res_person, start_date, \
                      finish_date, mat_req_date, drawing_req_date, action_id from v_task_list2 WHERE (instance_id = '")+array_ins_list.Item(i)+ wxT("' AND workflow_id ='")+array_workflow_id.Item(i)+wxT("') ");
            else
                str_sql1= str_sql1 + wxT(" OR (instance_id = '")+array_ins_list.Item(i)+ wxT("' AND workflow_id = '")+array_workflow_id.Item(i)+wxT("') ");
        }

        if(array_workflow_id.Item(i) == wf_str_design || array_workflow_id.Item(i) == wf_str_materials)
        {
            i_2++;
           if(i_2==1)
                str_sql2= str_sql2 + wxT("  SELECT instance_id, workflow_id,workflow_name, flow_ser, concat(contract_id,' ', project_name,'-',project_id) as project_info,\
                      is_active, action_name, concat(operator_id,'-',name) as res_person, start_date, \
                      finish_date, mat_req_date, drawing_req_date, action_id from v_task_list3 WHERE (instance_id = '")+array_ins_list.Item(i)+ wxT("' AND workflow_id ='")+array_workflow_id.Item(i)+wxT("') ");
            else
                str_sql2= str_sql2 + wxT(" OR (instance_id = '")+array_ins_list.Item(i)+ wxT("' AND workflow_id = '")+array_workflow_id.Item(i)+wxT("') ");

        }
    }



    if(i_1!=0 && i_2 !=0)
    {
        str_sql1 = wxT("(")+ str_sql1 + wxT(" ORDER BY instance_id, workflow_id, flow_ser ASC ) ");
        str_sql2 = wxT("(")+str_sql2+  wxT(" ORDER BY instance_id, workflow_id, flow_ser ASC ) ");
        str_sql = str_sql1+wxT(" UNION ALL ")+ str_sql2 + wxT(";");
    }

    if(i_1!=0 && i_2 ==0)
        str_sql = str_sql1 +wxT(" ORDER BY instance_id, workflow_id, flow_ser ASC ;");

    if(i_2!=0 && i_1 ==0)
        str_sql = str_sql2 +wxT(" ORDER BY instance_id, workflow_id, flow_ser ASC ;");

    _res = wxGetApp().app_sql_select(str_sql);


    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int i_result = _res->GetRowsNumber();

    _res->MoveFirst();
    wxString str_pass, str_workflow_id;
    bool b_active;
    for(int j=0; j<i_result; j++)
    {
        b_active =  _res->GetBool(wxT("is_active"));
        wxColour back_color;
        if(b_active)
        {
            back_color = *wxWHITE;
            str_pass = _res->GetVal(wxT("instance_id"));
            str_workflow_id = _res->GetVal(wxT("workflow_id"));
        }
        else back_color = *wxLIGHT_GREY;

 //       if(str_pass != _res->GetVal(wxT("instance_id")))
  //          str_pass.Empty();

        if(!b_active && str_pass == _res->GetVal(wxT("instance_id"))&& str_workflow_id == _res->GetVal(wxT("workflow_id")))
         {
              _res->MoveNext();
             continue;
         }

        wxString str = _res->GetVal(wxT("instance_id"));
        long tmp = lv_proc_log->InsertItem(j,str);
        lv_proc_log->SetItemData(tmp, j);

        lv_proc_log->SetItemBackgroundColour(tmp, back_color);

        str = _res->GetVal(wxT("project_info"));
        lv_proc_log->SetItem(tmp,1,str);

        str = _res->GetVal(wxT("workflow_name"));
        lv_proc_log->SetItem(tmp,2,str);

        str = _res->GetVal(wxT("action_name"));
        lv_proc_log->SetItem(tmp,3,str);

        str = _res->GetVal(wxT("res_person"));
        lv_proc_log->SetItem(tmp,4,str);

        wxDateTime dt_temp;

        dt_temp = _res->GetDate(wxT("start_date"));
        str = DateToStrFormat(dt_temp);
        lv_proc_log->SetItem(tmp,5,str);

        dt_temp = _res->GetDate(wxT("finish_date"));
        str = DateToStrFormat(dt_temp);
        lv_proc_log->SetItem(tmp,6,str);

        dt_temp = _res->GetDate(wxT("mat_req_date"));
        str = DateToStrFormat(dt_temp);
        lv_proc_log->SetItem(tmp,7,str);

        dt_temp = _res->GetDate(wxT("drawing_req_date"));
        str = DateToStrFormat(dt_temp);
        lv_proc_log->SetItem(tmp,8,str);

        _res->MoveNext();
    }

    _res->Clear();


}

void ins_nonstd_proc_log::OnButton1Click(wxCommandEvent& event)
{
    EndDialog(wxID_OK);
}

void ins_nonstd_proc_log::Refresh_list_view(wxArrayString array_ins_list, wxString s_workflow_id)
{
    if(array_ins_list.IsEmpty())
        return;

    int i_count= array_ins_list.GetCount();
    wxString str_sql1, str_sql2, str_sql;
    wxPostgreSQLresult* _res;

    int i_1=0;
    int i_2=0;

    for(int i = 0; i<i_count; i++)
    {
        if(s_workflow_id == wf_str_nonstd)
        {
            i_1++;
            if(i_1==1)
                str_sql1= str_sql1 + wxT("  SELECT instance_id, workflow_id,workflow_name, flow_ser, concat(contract_id,' ', project_name,'-',project_id) as project_info,\
                      is_active, action_name, concat(operator_id,'-',name) as res_person, start_date, \
                      finish_date, mat_req_date, drawing_req_date, action_id from v_task_list2 WHERE (instance_id = '")+array_ins_list.Item(i)+ wxT("' AND workflow_id ='")+s_workflow_id+wxT("') ");
            else
                str_sql1= str_sql1 + wxT(" OR (instance_id = '")+array_ins_list.Item(i)+ wxT("' AND workflow_id = '")+s_workflow_id+wxT("') ");
        }

        if(s_workflow_id == wf_str_design || s_workflow_id == wf_str_materials)
        {
            i_2++;
           if(i_2==1)
                str_sql2= str_sql2 + wxT("  SELECT instance_id, workflow_id,workflow_name, flow_ser, concat(contract_id,' ', project_name,'-',project_id) as project_info,\
                      is_active, action_name, concat(operator_id,'-',name) as res_person, start_date, \
                      finish_date, mat_req_date, drawing_req_date, action_id from v_task_list3 WHERE (instance_id = '")+array_ins_list.Item(i)+ wxT("' AND workflow_id ='")+s_workflow_id+wxT("') ");
            else
                str_sql2= str_sql2 + wxT(" OR (instance_id = '")+array_ins_list.Item(i)+ wxT("' AND workflow_id = '")+s_workflow_id+wxT("') ");

        }
    }



    if(i_1!=0 && i_2 !=0)
    {
        str_sql1 = wxT("(")+ str_sql1 + wxT(" ORDER BY instance_id, workflow_id, flow_ser ASC ) ");
        str_sql2 = wxT("(")+str_sql2+  wxT(" ORDER BY instance_id, workflow_id, flow_ser ASC ) ");
        str_sql = str_sql1+wxT(" UNION ALL ")+ str_sql2 + wxT(";");
    }

    if(i_1!=0 && i_2 ==0)
        str_sql = str_sql1 +wxT(" ORDER BY instance_id, workflow_id, flow_ser ASC ;");

    if(i_2!=0 && i_1 ==0)
        str_sql = str_sql2 +wxT(" ORDER BY instance_id, workflow_id, flow_ser ASC ;");

    _res = wxGetApp().app_sql_select(str_sql);


    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int i_result = _res->GetRowsNumber();

    _res->MoveFirst();
    wxString str_pass, str_workflow_id;
    bool b_active;
    for(int j=0; j<i_result; j++)
    {
        b_active =  _res->GetBool(wxT("is_active"));
        wxColour back_color;
        if(b_active)
        {
            back_color = *wxWHITE;
            str_pass = _res->GetVal(wxT("instance_id"));
            str_workflow_id = _res->GetVal(wxT("workflow_id"));
        }
        else back_color = *wxLIGHT_GREY;

 //       if(str_pass != _res->GetVal(wxT("instance_id")))
  //          str_pass.Empty();

        if(!b_active && str_pass == _res->GetVal(wxT("instance_id"))&& str_workflow_id == _res->GetVal(wxT("workflow_id")))
        {
            _res->MoveNext();
            continue;
        }

        wxString str = _res->GetVal(wxT("instance_id"));
        long tmp = lv_proc_log->InsertItem(j,str);
        lv_proc_log->SetItemData(tmp, j);

        lv_proc_log->SetItemBackgroundColour(tmp, back_color);

        str = _res->GetVal(wxT("project_info"));
        lv_proc_log->SetItem(tmp,1,str);

        str = _res->GetVal(wxT("workflow_name"));
        lv_proc_log->SetItem(tmp,2,str);

        str = _res->GetVal(wxT("action_name"));
        lv_proc_log->SetItem(tmp,3,str);

        str = _res->GetVal(wxT("res_person"));
        lv_proc_log->SetItem(tmp,4,str);

        wxDateTime dt_temp;

        dt_temp = _res->GetDate(wxT("start_date"));
        str = DateToStrFormat(dt_temp);
        lv_proc_log->SetItem(tmp,5,str);

        dt_temp = _res->GetDate(wxT("finish_date"));
        str = DateToStrFormat(dt_temp);
        lv_proc_log->SetItem(tmp,6,str);

        dt_temp = _res->GetDate(wxT("mat_req_date"));
        str = DateToStrFormat(dt_temp);
        lv_proc_log->SetItem(tmp,7,str);

        dt_temp = _res->GetDate(wxT("drawing_req_date"));
        str = DateToStrFormat(dt_temp);
        lv_proc_log->SetItem(tmp,8,str);

        _res->MoveNext();
    }

    _res->Clear();


}
