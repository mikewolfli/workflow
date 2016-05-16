#include "review_communication_log.h"
#include "wfApp.h"

//(*InternalHeaders(review_communication_log)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(review_communication_log)
const long review_communication_log::ID_LISTVIEW_LOG = wxNewId();
const long review_communication_log::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(review_communication_log,wxDialog)
	//(*EventTable(review_communication_log)
	//*)
END_EVENT_TABLE()

review_communication_log::review_communication_log(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(review_communication_log)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("评审问题反馈来回信息列表"));
	lv_log = new wxListView(this, ID_LISTVIEW_LOG, wxDefaultPosition, wxSize(844,193), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTVIEW_LOG"));
	StaticBoxSizer1->Add(lv_log, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(StaticBoxSizer1, 5, wxALL|wxEXPAND, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("退出"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&review_communication_log::OnButton1Click);
	//*)
	init_list_header();
}

review_communication_log::~review_communication_log()
{
	//(*Destroy(review_communication_log)
	//*)
}

void review_communication_log::init_list_header()
{
    wxListItem itemCol;
    itemCol.SetText(_("任务ID"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(0);
    lv_log->InsertColumn(0, itemCol);
    itemCol.SetText(_("项目信息"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_log->InsertColumn(1, itemCol);
    itemCol.SetText(_("序号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_log->InsertColumn(2, itemCol);
    itemCol.SetText(_("状态"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_log->InsertColumn(3, itemCol);

    itemCol.SetText(_("GAD"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_log->InsertColumn(4, itemCol);
    itemCol.SetText(_("SPEC MEMO"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(80);
    lv_log->InsertColumn(5, itemCol);
    itemCol.SetText(_("评审工程师"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_log->InsertColumn(6, itemCol);
    itemCol.SetText(_("Issue内容"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(200);
    lv_log->InsertColumn(7, itemCol);
    itemCol.SetText(_("提交时间"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(150);
    lv_log->InsertColumn(8, itemCol);
    itemCol.SetText(_("商务专员"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_log->InsertColumn(9, itemCol);
    itemCol.SetText(_("分公司回复"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(200);
    lv_log->InsertColumn(10, itemCol);
    itemCol.SetText(_("回复时间"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(150);
    lv_log->InsertColumn(11, itemCol);
}

void review_communication_log::OnButton1Click(wxCommandEvent& event)
{
    EndDialog(wxID_CANCEL);
}

void review_communication_log::refresh_list(wxArrayString &a_task_id, wxArrayString & a_info)
{
    if(a_task_id.IsEmpty())
        return;

    int i_count = a_task_id.GetCount();

    wxString s_sql = wxT("select *, (select name from s_employee where employee_id=issue_emp_id) as issue_name, \
                         (select name from s_employee where employee_id = return_emp_id) as return_name from s_review_communication where ");

    for(int i=0;i<i_count;i++)
    {
        if(i == 0)
            s_sql = s_sql + wxT(" review_task_id='")+a_task_id.Item(i)+wxT("' ");
        else
            s_sql = s_sql + wxT(" or review_task_id='")+a_task_id.Item(i)+wxT("' ");
    }

    s_sql = s_sql + wxT(" order by review_task_id, item_no asc;");

    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(s_sql);
    if (_res->Status() != PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }
    int irow = _res->GetRowsNumber();

    wxString str, s_task_id;
    int i_status;
    wxColour back_color;

    for(int j=0;j<irow;j++)
    {
        if(s_task_id!=_res->GetVal(wxT("review_task_id")))
        {
            s_task_id = _res->GetVal(wxT("review_task_id"));


        }

        long tmp = lv_log->InsertItem(j, s_task_id);
        lv_log->SetItemData(tmp, j);



        int i_pos = a_task_id.Index(s_task_id);

        str = a_info.Item(i_pos);

        lv_log->SetItem(tmp, 1, str);

        str =NumToStr(_res->GetInt(wxT("item_no")));
        lv_log->SetItem(tmp, 2, str);

        i_status = _res->GetInt(wxT("issue_status"));

        if(i_status ==1 || i_status ==2)
        {
            back_color = *wxWHITE;
        }else
        {
             back_color = *wxLIGHT_GREY;
        }

        lv_log->SetItemBackgroundColour(tmp, back_color);
        str = communication_status_to_str(i_status);
        lv_log->SetItem(tmp, 3, str);

        str = BoolToY(_res->GetBool(wxT("is_gad")));
        lv_log->SetItem(tmp, 4, str);

        str = BoolToY(_res->GetBool(wxT("is_spec")));
        lv_log->SetItem(tmp, 5, str);

        str = _res->GetVal(wxT("issue_name"));
        lv_log->SetItem(tmp, 6, str);

        str = _res->GetVal(wxT("issue_content"));
        lv_log->SetItem(tmp, 7, str);

        str = DateToAnsiStr(_res->GetDateTime(wxT("issue_date")));
        lv_log->SetItem(tmp, 8, str);

        str=_res->GetVal(wxT("return_name"));
        lv_log->SetItem(tmp, 9, str);

        str = _res->GetVal(wxT("return_content"));
        lv_log->SetItem(tmp, 10, str);

        str = DateToAnsiStr(_res->GetDateTime(wxT("return_date")));
        lv_log->SetItem(tmp, 11, str);

        _res->MoveNext();
    }

}
