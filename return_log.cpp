#include "return_log.h"
//(*InternalHeaders(return_log)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(return_log)
const long return_log::ID_LISTVIEW1 = wxNewId();
const long return_log::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(return_log,wxDialog)
	//(*EventTable(return_log)
	//*)
END_EVENT_TABLE()

return_log::return_log(wxWindow* parent)
{
	//(*Initialize(return_log)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxCLOSE_BOX|wxMAXIMIZE_BOX, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	lv_list = new wxListView(this, ID_LISTVIEW1, wxDefaultPosition, wxSize(901,180), wxLC_REPORT|wxLC_HRULES|wxLC_VRULES|wxALWAYS_SHOW_SB, wxDefaultValidator, _T("ID_LISTVIEW1"));
	BoxSizer2->Add(lv_list, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(BoxSizer2, 5, wxALL|wxEXPAND, 0);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("退出"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(Button1, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&return_log::OnButton1Click);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&return_log::OnClose);
	//*)

	    wxListItem itemCol;
/*    itemCol.SetText(_("合同号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(80);
    lv_proc_log->InsertColumn(0, itemCol);*/

    itemCol.SetText(_("实例ID"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_list->InsertColumn(0, itemCol);

    itemCol.SetText(_("退回步骤"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_list->InsertColumn(1, itemCol);

    itemCol.SetText(_("退回人员"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_list->InsertColumn(2, itemCol);

    itemCol.SetText(_("退回日期"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(150);
    lv_list->InsertColumn(3, itemCol);

    itemCol.SetText(_("退回次数"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_list->InsertColumn(4, itemCol);

    itemCol.SetText(_("退回说明"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(200);
    lv_list->InsertColumn(5, itemCol);

}

return_log::~return_log()
{
	//(*Destroy(return_log)
	//*)
}


void return_log::OnButton1Click(wxCommandEvent& event)
{
    EndDialog(wxID_OK);
}

void return_log::OnClose(wxCloseEvent& event)
{
    EndDialog(wxID_OK);
}

void return_log::Refresh_list_view(wxArrayString & array_return, wxArrayString &array_return_time)
{
    wxString str_sql;
    wxPostgreSQLresult* _res;
    str_sql = wxT("SELECT instance_id, from_action,  return_time_log, (select name from s_employee where employee_id = from_person) as name, rep_doc_id, (SELECT action_name from s_action_info where action_id = from_action) as action_name,\
                   return_date, (select doc_desc from s_doc where doc_id = rep_doc_id) as doc_desc from l_return_log WHERE (instance_id = '")+array_return.Item(0)+wxT("' AND return_time_log = '")+
                   array_return_time.Item(0)+ wxT("')  ");

    int i_count = array_return.GetCount();

    for(int i = 1; i<i_count;i++)
    {
        str_sql = str_sql+wxT(" OR (instance_id = '")+array_return.Item(i)+wxT("' AND return_time_log = '")+array_return_time.Item(i)+ wxT("') ");
    }

    str_sql = str_sql +wxT(" ORDER BY instance_id, return_time_log ASC;");

    _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int i_result = _res->GetRowsNumber();

    _res->MoveFirst();

    for(int j=0; j<i_result; j++)
    {
        wxString str = _res->GetVal(wxT("instance_id"));
        long tmp = lv_list->InsertItem(j,str);
        lv_list->SetItemData(tmp, j);

        str = _res->GetVal(wxT("action_name"));
        lv_list->SetItem(tmp,1,str);

        str = _res->GetVal(wxT("name"));
        lv_list->SetItem(tmp,2,str);

        wxDateTime dt_temp;

        dt_temp = _res->GetDateTime(wxT("return_date"));
        str = DateToAnsiStr(dt_temp);
        lv_list->SetItem(tmp,3,str);


        int i_time  = _res->GetInt(wxT("return_time_log"));
        str = NumToStr(i_time);
        lv_list->SetItem(tmp,4,str);

        str = _res->GetVal(wxT("doc_desc"));
        lv_list->SetItem(tmp,5,str);

        _res->MoveNext();
    }


    _res->Clear();

}

void return_log::refresh_list(wxArrayString &a_return, wxString & aim_step)
{
   wxString str_sql;
    wxPostgreSQLresult* _res;
    str_sql = wxT("SELECT instance_id, from_action,  return_time_log, (select name from s_employee where employee_id = from_person) as name, rep_doc_id, (SELECT action_name from s_action_info where action_id = from_action) as action_name,\
                   return_date, (select doc_desc from s_doc where doc_id = rep_doc_id) as doc_desc from l_return_log WHERE to_action='")+aim_step+wxT("' and ");

    int i_count = a_return.GetCount();
    for(int i=0;i<i_count;i++)
    {
        if(i==0)
        {
            str_sql = str_sql +wxT(" (instance_id = '")+a_return.Item(i)+wxT("' ");

        }else if(i==i_count-1)
        {
             str_sql = str_sql +wxT(" or instance_id ='")+a_return.Item(i)+wxT("') ");
        }else
        {
            str_sql = str_sql + wxT(" or instance_id ='")+a_return.Item(i)+wxT("' ");
        }

        if(i_count==1)
            str_sql= str_sql +wxT(" ) ");
    }

    str_sql = str_sql +wxT(" ORDER BY instance_id, return_time_log ASC;");

    _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int i_result = _res->GetRowsNumber();

    _res->MoveFirst();

    bool b_change = true;

    wxString s_instance_id, str;

    for(int j=0; j<i_result; j++)
    {
        if(s_instance_id!=_res->GetVal(wxT("instance_id")))
        {
            s_instance_id=_res->GetVal(wxT("instance_id"));
            b_change = !b_change;
        }

        long tmp = lv_list->InsertItem(j,s_instance_id);
        lv_list->SetItemData(tmp, j);

        if(b_change)
            lv_list->SetItemBackgroundColour(tmp, *wxWHITE);
        else
            lv_list->SetItemBackgroundColour(tmp, *wxLIGHT_GREY);

        str = _res->GetVal(wxT("action_name"));
        lv_list->SetItem(tmp,1,str);

        str = _res->GetVal(wxT("name"));
        lv_list->SetItem(tmp,2,str);

        wxDateTime dt_temp;

        dt_temp = _res->GetDateTime(wxT("return_date"));
        str = DateToAnsiStr(dt_temp);
        lv_list->SetItem(tmp,3,str);


        int i_time  = _res->GetInt(wxT("return_time_log"));
        str = NumToStr(i_time);
        lv_list->SetItem(tmp,4,str);

        str = _res->GetVal(wxT("doc_desc"));
        lv_list->SetItem(tmp,5,str);

        _res->MoveNext();
    }


    _res->Clear();
}
