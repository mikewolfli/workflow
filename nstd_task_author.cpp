#include "nstd_task_author.h"
#include "wfApp.h"


//(*InternalHeaders(nstd_task_author)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(nstd_task_author)
const long nstd_task_author::ID_LISTCTRL_TASKINFO = wxNewId();
const long nstd_task_author::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(nstd_task_author,wxDialog)
	//(*EventTable(nstd_task_author)
	//*)
END_EVENT_TABLE()

nstd_task_author::nstd_task_author(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(nstd_task_author)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("任务信息"));
	lc_taskinfo = new wxListCtrl(this, ID_LISTCTRL_TASKINFO, wxDefaultPosition, wxSize(841,144), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL_TASKINFO"));
	StaticBoxSizer1->Add(lc_taskinfo, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer1->Add(StaticBoxSizer1, 5, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("确定"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_task_author::OnButton1Click);
	//*)

	init_header();
}

nstd_task_author::~nstd_task_author()
{
	//(*Destroy(nstd_task_author)
	//*)
}

void nstd_task_author::init_header()
{
    wxListItem itemCol;
    itemCol.SetText(_("wbs no"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lc_taskinfo->InsertColumn(0, itemCol);

    itemCol.SetText(_("项目名称"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(200);
    lc_taskinfo->InsertColumn(1, itemCol);

    itemCol.SetText(_("梯号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(60);
    lc_taskinfo->InsertColumn(2, itemCol);

    itemCol.SetText(_("梯型"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(80);
    lc_taskinfo->InsertColumn(3, itemCol);

    itemCol.SetText(_("载重"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(80);
    lc_taskinfo->InsertColumn(4, itemCol);

    itemCol.SetText(_("速度"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(80);
    lc_taskinfo->InsertColumn(5, itemCol);

    itemCol.SetText(_("状态"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(80);
    lc_taskinfo->InsertColumn(6, itemCol);

    itemCol.SetText(_("特殊标识"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lc_taskinfo->InsertColumn(7, itemCol);
}

void nstd_task_author::OnButton1Click(wxCommandEvent& event)
{
    EndDialog(wxID_OK);
}

void nstd_task_author::refresh_list()
{
    if(m_units.IsEmpty())
        return;

    wxString str_sql = wxT("select wbs_no, concat(contract_id,' ', project_name) as project_name, lift_no, elevator_type, load, speed, status, special_info FROM v_unit_info_parameter where ");

    int i_count = m_units.GetCount();

    for(int i=0;i<i_count;i++)
    {
        if(i==i_count -1)
           str_sql = str_sql + wxT(" wbs_no = '")+m_units.Item(i)+wxT("' order by wbs_no ASC;");
        else
            str_sql = str_sql +wxT("wbs_no = '")+m_units.Item(i)+wxT("' or ");
    }

    wxPostgreSQLresult* _res = wxGetApp().app_sql_select(str_sql);
  //  wxLogMessage(strSql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int irow = _res->GetRowsNumber();

    for(int i=0; i<irow; i++)
    {
        wxString str = _res->GetVal(wxT("wbs_no"));
        long tmp = lc_taskinfo->InsertItem(i,str);
        lc_taskinfo->SetItemData(tmp, i);

        str = _res->GetVal(wxT("project_name"));
        lc_taskinfo->SetItem(tmp,1,str);

        str = _res->GetVal(wxT("lift_no"));
        lc_taskinfo->SetItem(tmp,2,str);

        str = _res->GetVal(wxT("elevator_type"));
        lc_taskinfo->SetItem(tmp,3,str);

        str = _res->GetVal(wxT("load"));
        lc_taskinfo->SetItem(tmp,4,str);

        str = _res->GetVal(wxT("speed"));
        lc_taskinfo->SetItem(tmp,5,str);

        int i_status = _res->GetInt(wxT("status"));

        str = prj_status_to_str(i_status);
        lc_taskinfo->SetItem(tmp,6,str);

        if (i_status==4)
            lc_taskinfo->SetItemBackgroundColour(tmp, *wxRED);

        str = _res->GetVal(wxT("special_info"));
        lc_taskinfo->SetItem(tmp, 7, str);


        _res->MoveNext();
    }

}
