#include "generated_id_display_panel.h"
#include "wfApp.h"
#include "utils/wf_operator.h"

//(*InternalHeaders(generated_id_display_panel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(generated_id_display_panel)
const long generated_id_display_panel::ID_CHOICE_GEN_CATALOG = wxNewId();
const long generated_id_display_panel::ID_BUTTON_REFRESH = wxNewId();
const long generated_id_display_panel::ID_TEXTCTRL_SEARCH_TEXT = wxNewId();
const long generated_id_display_panel::ID_BUTTON_SEARCH = wxNewId();
const long generated_id_display_panel::ID_CHOICE_FILTER = wxNewId();
const long generated_id_display_panel::ID_BUTTON_RESTORE = wxNewId();
const long generated_id_display_panel::ID_BUTTON_SEND = wxNewId();
const long generated_id_display_panel::ID_BUTTON_CANCEL = wxNewId();
const long generated_id_display_panel::ID_LISTVIEW_LIST = wxNewId();
//*)

BEGIN_EVENT_TABLE(generated_id_display_panel,wxPanel)
	//(*EventTable(generated_id_display_panel)
	//*)
END_EVENT_TABLE()

generated_id_display_panel::generated_id_display_panel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(generated_id_display_panel)
	wxGridBagSizer* GridBagSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("操作区"));
	GridBagSizer1 = new wxGridBagSizer(0, 0);
	Choice_catalog = new wxChoice(this, ID_CHOICE_GEN_CATALOG, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_GEN_CATALOG"));
	Choice_catalog->Append(_("内部联络单"));
	Choice_catalog->Append(_("Spec&GAD更改通知单"));
	Choice_catalog->Append(_("WBS BOM更改通知单"));
	Choice_catalog->Append(_("非标设计指令"));
	Choice_catalog->Append(_("技术变更执行通知单"));
	GridBagSizer1->Add(Choice_catalog, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button_refresh = new wxButton(this, ID_BUTTON_REFRESH, _("刷新单据"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_REFRESH"));
	GridBagSizer1->Add(Button_refresh, wxGBPosition(0, 2), wxDefaultSpan, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	tc_search = new wxTextCtrl(this, ID_TEXTCTRL_SEARCH_TEXT, wxEmptyString, wxDefaultPosition, wxSize(138,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_SEARCH_TEXT"));
	GridBagSizer1->Add(tc_search, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Search = new wxButton(this, ID_BUTTON_SEARCH, _("查询"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_SEARCH"));
	GridBagSizer1->Add(Button_Search, wxGBPosition(1, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Choice_filter = new wxChoice(this, ID_CHOICE_FILTER, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_FILTER"));
	Choice_filter->SetSelection( Choice_filter->Append(_("新生成")) );
	Choice_filter->Append(_("已发放"));
	Choice_filter->Append(_("已取消"));
	GridBagSizer1->Add(Choice_filter, wxGBPosition(1, 2), wxDefaultSpan, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Restore = new wxButton(this, ID_BUTTON_RESTORE, _("恢复单据"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_RESTORE"));
	GridBagSizer1->Add(Button_Restore, wxGBPosition(1, 3), wxDefaultSpan, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button_send = new wxButton(this, ID_BUTTON_SEND, _("发放"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_SEND"));
	GridBagSizer1->Add(Button_send, wxGBPosition(0, 1), wxDefaultSpan, wxALL|wxEXPAND, 5);
	Button_cancel = new wxButton(this, ID_BUTTON_CANCEL, _("取消单据"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CANCEL"));
	GridBagSizer1->Add(Button_cancel, wxGBPosition(0, 3), wxDefaultSpan, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(GridBagSizer1, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	lv_list = new wxListView(this, ID_LISTVIEW_LIST, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTVIEW_LIST"));
	BoxSizer2->Add(lv_list, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(BoxSizer2, 5, wxALL|wxEXPAND, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_CHOICE_GEN_CATALOG,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&generated_id_display_panel::OnChoice_catalogSelect);
	Connect(ID_BUTTON_REFRESH,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&generated_id_display_panel::OnButton_refreshClick);
	Connect(ID_BUTTON_SEARCH,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&generated_id_display_panel::OnButton_SearchClick);
	Connect(ID_CHOICE_FILTER,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&generated_id_display_panel::OnChoice_filterSelect);
	Connect(ID_BUTTON_RESTORE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&generated_id_display_panel::OnButton_RestoreClick);
	Connect(ID_BUTTON_SEND,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&generated_id_display_panel::OnButton_sendClick);
	Connect(ID_BUTTON_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&generated_id_display_panel::OnButton_cancelClick);
	//*)

    wxArrayString array_group = wxGetApp().get_group();

    if(array_group.Index(wxT("G0011"))!=wxNOT_FOUND)
    {
        Button_cancel->Show(true);
        Button_Restore->Show(true);
        Button_send->Show(true);
        Choice_filter->Show(true);

        b_info=true;
    }else
    {
        Button_cancel->Show(false);
        Button_Restore->Show(false);
        Choice_filter->Show(true);
        Button_send->Show(false);
        b_info=false;

    }

    m_mode = Choice_catalog->GetSelection();
    m_sel = Choice_filter->GetSelection();

    init_list_header();


    if(b_info)
    {
        switch(m_sel)
        {
        case 0:
            m_clause1 = wxT(" is_published = false and is_active =true ");
            Button_send->Enable(true);
            Button_Restore->Enable(false);
            Button_cancel->Enable(true);
            break;
        case 1:
            m_clause1 = wxT(" is_published = true  and is_active = true ");
            Button_send->Enable(false);
            Button_Restore->Enable(false);
            Button_cancel->Enable(true);
            break;
        case 2:
            m_clause1 = wxT(" is_active =false ");
            Button_send->Enable(false);
            Button_cancel->Enable(false);
            Button_Restore->Enable(true);
            break;

        default:
            Button_send->Enable(false);
            Button_Restore->Enable(false);
            Button_cancel->Enable(true);
            m_clause1 = wxT(" is_active =true ");
            break;
        }

    }
    else
    {

        m_clause1 = wxT(" is_active=true ");
        m_clause2 = wxT(" apply_person='")+gr_para.login_user+wxT("' ");

         wxArrayString a_member=get_group_member_of_leader(array_group);

         int i_count = a_member.GetCount();

         for(int i=0;i<i_count;i++)
         {
             m_clause2 = m_clause2+wxT(" or apply_person='")+a_member.Item(i)+wxT("' ");
         }
    }

    if(!m_clause1.IsEmpty()&&!m_clause2.IsEmpty())
    {
        m_clause= m_clause1+ wxT(" and (")+m_clause2+wxT(") ");
    }else
    {
        m_clause=m_clause1+m_clause2;
    }


    m_clause_att = wxEmptyString;
    refresh_list();
}
generated_id_display_panel::~generated_id_display_panel()
{
    //(*Destroy(generated_id_display_panel)
    //*)
}

wxArrayString generated_id_display_panel::get_group_member_of_leader(wxArrayString a_group)
{
    if(a_group.IsEmpty())
        return a_group;

    wxArrayString  a_member, a_temp;

    int i_count = a_group.GetCount();

    for(int i=0;i<i_count;i++)
    {
        wxString s_group = a_group.Item(i);

        if(wxGetApp().is_leader(s_group))
           {
                a_temp= wxGetApp().get_member_in_group(s_group);

                int i_sub=a_temp.GetCount();

                for(int j=0;j<i_sub;j++)
                {
                    a_member.Add(a_temp.Item(j).Left(8));
                }

                a_temp.Clear();

           }
    }

    return a_member;
}


void generated_id_display_panel::init_list_header()
{

 //   lv_list->DeleteAllItems();
    lv_list->DeleteAllColumns();

    wxListItem itemCol;

    switch(m_mode)
    {
    case 0:
        itemCol.SetText(_("内联单号"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(100);
        lv_list->InsertColumn(0,itemCol);

        itemCol.SetText(_("主题"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(400);
        lv_list->InsertColumn(1,itemCol);

        itemCol.SetText(_("申请人"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(50);
        lv_list->InsertColumn(2, itemCol);

        itemCol.SetText(_("申请日期"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(80);
        lv_list->InsertColumn(3, itemCol);


        itemCol.SetText(_("是否已发布"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(0);
        lv_list->InsertColumn(4,itemCol);

        itemCol.SetText(_("取消状态"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(0);
        lv_list->InsertColumn(5, itemCol);

        itemCol.SetText(_("发布人"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(50);
        lv_list->InsertColumn(6, itemCol);

        itemCol.SetText(_("发布日期"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(80);
        lv_list->InsertColumn(7,itemCol);

        itemCol.SetText(_("备注"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(100);
        lv_list->InsertColumn(8, itemCol);

        break;
    case 1:
        itemCol.SetText(_("ASG号码"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(100);
        lv_list->InsertColumn(0,itemCol);

        itemCol.SetText(_("更改项目"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(400);
        lv_list->InsertColumn(1, itemCol);

        itemCol.SetText(_("申请人"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(50);
        lv_list->InsertColumn(2, itemCol);

        itemCol.SetText(_("申请日期"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(80);
        lv_list->InsertColumn(3, itemCol);

        itemCol.SetText(_("配置负责人"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(100);
        lv_list->InsertColumn(4, itemCol);


        itemCol.SetText(_("是否已发布"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(0);
        lv_list->InsertColumn(5,itemCol);

        itemCol.SetText(_("关联梯"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(0);
        lv_list->InsertColumn(6,itemCol);

        itemCol.SetText(_("取消状态"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(0);
        lv_list->InsertColumn(7, itemCol);

        itemCol.SetText(_("发布人"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(50);
        lv_list->InsertColumn(8, itemCol);

        itemCol.SetText(_("发布日期"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(80);
        lv_list->InsertColumn(9,itemCol);

        itemCol.SetText(_("备注"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(50);
        lv_list->InsertColumn(10, itemCol);
        break;
    case 2:
       itemCol.SetText(_("BOM更改单号"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(100);
        lv_list->InsertColumn(0,itemCol);

        itemCol.SetText(_("更改原因"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(400);
        lv_list->InsertColumn(1, itemCol);

        itemCol.SetText(_("申请人"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(50);
        lv_list->InsertColumn(2, itemCol);

        itemCol.SetText(_("申请日期"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(80);
        lv_list->InsertColumn(3, itemCol);


        itemCol.SetText(_("是否已发布"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(0);
        lv_list->InsertColumn(4,itemCol);

        itemCol.SetText(_("取消状态"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(0);
        lv_list->InsertColumn(5, itemCol);

        itemCol.SetText(_("发布人"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(50);
        lv_list->InsertColumn(6, itemCol);

        itemCol.SetText(_("发布日期"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(80);
        lv_list->InsertColumn(7,itemCol);

        itemCol.SetText(_("PU"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(20);
        lv_list->InsertColumn(8,itemCol);

        itemCol.SetText(_("QM"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(20);
        lv_list->InsertColumn(9,itemCol);

        itemCol.SetText(_("IE"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(20);
        lv_list->InsertColumn(10,itemCol);

        itemCol.SetText(_("PP"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(20);
        lv_list->InsertColumn(11,itemCol);

        itemCol.SetText(_("LO"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(20);
        lv_list->InsertColumn(12,itemCol);

        itemCol.SetText(_("PSM"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(20);
        lv_list->InsertColumn(13,itemCol);

        itemCol.SetText(_("PM"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(20);
        lv_list->InsertColumn(14,itemCol);

        itemCol.SetText(_("CO"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(20);
        lv_list->InsertColumn(15,itemCol);

        itemCol.SetText(_("OHTERS"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(20);
        lv_list->InsertColumn(16,itemCol);

        itemCol.SetText(_("备注"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(50);
        lv_list->InsertColumn(17, itemCol);
        break;
    case 3:
        itemCol.SetText(_("非标设计指令"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(150);
        lv_list->InsertColumn(0,itemCol);

        itemCol.SetText(_("文件名称"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(200);
        lv_list->InsertColumn(1,itemCol);

        itemCol.SetText(_("文件号"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(100);
        lv_list->InsertColumn(2,itemCol);

        itemCol.SetText(_("责任人ID"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(0);
        lv_list->InsertColumn(3,itemCol);

        itemCol.SetText(_("责任人"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(80);
        lv_list->InsertColumn(4,itemCol);


        itemCol.SetText(_("责任主管ID"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(0);
        lv_list->InsertColumn(5,itemCol);

        itemCol.SetText(_("责任主管"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(80);
        lv_list->InsertColumn(6,itemCol);

        itemCol.SetText(_("项目经理ID"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(0);
        lv_list->InsertColumn(7,itemCol);

        itemCol.SetText(_("项目经理"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(80);
        lv_list->InsertColumn(8,itemCol);

        itemCol.SetText(_("申请日期"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(100);
        lv_list->InsertColumn(9, itemCol);


        itemCol.SetText(_("是否已发布"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(0);
        lv_list->InsertColumn(10,itemCol);

        itemCol.SetText(_("取消状态"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(0);
        lv_list->InsertColumn(11, itemCol);

        itemCol.SetText(_("发布人"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(80);
        lv_list->InsertColumn(12, itemCol);

        itemCol.SetText(_("发布日期"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(100);
        lv_list->InsertColumn(13,itemCol);


        itemCol.SetText(_("备注"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(300);
        lv_list->InsertColumn(14,itemCol);
        break;
    case 4:
        itemCol.SetText(_("技术变更执行通知单号"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(150);
        lv_list->InsertColumn(0,itemCol);

        itemCol.SetText(_("主题"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(200);
        lv_list->InsertColumn(1, itemCol);

        itemCol.SetText(_("相关ECO号码"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(100);
        lv_list->InsertColumn(2, itemCol);

        itemCol.SetText(_("生效日期"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(100);
        lv_list->InsertColumn(3, itemCol);

        itemCol.SetText(_("更改PC"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(100);
        lv_list->InsertColumn(4, itemCol);

        itemCol.SetText(_("紧急执行"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(100);
        lv_list->InsertColumn(5, itemCol);

        itemCol.SetText(_("申请人"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(50);
        lv_list->InsertColumn(6, itemCol);

        itemCol.SetText(_("申请日期"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(80);
        lv_list->InsertColumn(7, itemCol);


        itemCol.SetText(_("是否已发布"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(0);
        lv_list->InsertColumn(8,itemCol);

        itemCol.SetText(_("取消状态"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(0);
        lv_list->InsertColumn(9, itemCol);

        itemCol.SetText(_("发布人"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(50);
        lv_list->InsertColumn(10, itemCol);

        itemCol.SetText(_("发布日期"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(80);
        lv_list->InsertColumn(11,itemCol);

        itemCol.SetText(_("from 自"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(50);
        lv_list->InsertColumn(12,itemCol);

        itemCol.SetText(_("MPM"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(30);
        lv_list->InsertColumn(13,itemCol);

        itemCol.SetText(_("PM"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(30);
        lv_list->InsertColumn(14,itemCol);

        itemCol.SetText(_("DS"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(30);
        lv_list->InsertColumn(15,itemCol);

        itemCol.SetText(_("CS"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(30);
        lv_list->InsertColumn(16,itemCol);

        itemCol.SetText(_("FQ"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(30);
        lv_list->InsertColumn(17,itemCol);

        itemCol.SetText(_("PSM"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(30);
        lv_list->InsertColumn(18,itemCol);

        itemCol.SetText(_("PPU"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(30);
        lv_list->InsertColumn(19,itemCol);

        itemCol.SetText(_("LO"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(30);
        lv_list->InsertColumn(20,itemCol);

        itemCol.SetText(_("CO"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(30);
        lv_list->InsertColumn(21,itemCol);

        itemCol.SetText(_("SM"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(30);
        lv_list->InsertColumn(22,itemCol);

        itemCol.SetText(_("TM"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(30);
        lv_list->InsertColumn(23,itemCol);

        itemCol.SetText(_("EL"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(30);
        lv_list->InsertColumn(24,itemCol);

        itemCol.SetText(_("SQE"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(30);
        lv_list->InsertColumn(25,itemCol);

        itemCol.SetText(_("OHTERS"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(30);
        lv_list->InsertColumn(26,itemCol);

        itemCol.SetText(_("备注"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(50);
        lv_list->InsertColumn(27, itemCol);
        break;
    default:
        break;

    }

}

void generated_id_display_panel::refresh_list()
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

    wxString s_sql,str, s_res_name, s_person;
    wxPostgreSQLresult* _res;
    int i_count,i;
    long tmp;

    int i_num;

    wxArrayString array_res;

    lv_list->DeleteAllItems();

    switch(m_mode)
    {
    case 0:
        s_sql = wxT("SELECT ll_id, ll_content, apply_person, apply_date, remarks, publisher, publish_date, is_active, is_published , \
                     (select name from s_employee where employee_id = apply_person) as apply_name, (select name from s_employee where employee_id =publisher)as publish_name \
                 FROM l_internal_com_table where ")+m_clause+m_clause_att+wxT(" order by ll_id asc;");
        _res = wxGetApp().app_sql_select(s_sql);


        if(_res->Status()!= PGRES_TUPLES_OK)
        {
            _res->Clear();
            return;
        }

        i_count = _res->GetRowsNumber();

        for(i=0;i<i_count;i++)
        {
             str=_res->GetVal(wxT("ll_id"));

             tmp = lv_list->InsertItem(i, str);

             str = _res->GetVal(wxT("ll_content"));

             lv_list->SetItem(tmp, 1, str);

             str = _res->GetVal(wxT("apply_name"));
             lv_list->SetItem(tmp, 2, str);

             str = DateToStrFormat(_res->GetDateTime(wxT("apply_date")));
             lv_list->SetItem(tmp, 3, str);

             str = BoolToY(_res->GetBool(wxT("is_published")));
             lv_list->SetItem(tmp, 4, str);

             str = BoolToY(_res->GetBool(wxT("is_active")));
             lv_list->SetItem(tmp, 5, str);

             str = _res->GetVal(wxT("publish_name"));
             lv_list->SetItem(tmp, 6, str);

             str = DateToStrFormat(_res->GetDateTime(wxT("publish_date")));
             lv_list->SetItem(tmp, 7, str);

             str = _res->GetVal(wxT("remarks"));
             lv_list->SetItem(tmp, 8, str);

             _res->MoveNext();

        }
        _res->Clear();
        break;

    case 1:
        s_sql = wxT("SELECT asg_id, asg_content, link_id, res_engineer, apply_person, apply_date,remarks, publisher, publish_date, is_active, is_published, \
                  (select name from s_employee where employee_id = apply_person) as apply_name, (select name from s_employee where employee_id =publisher)as publish_name \
                  FROM l_spec_gad_revised_inform_table where ")+m_clause+m_clause_att+wxT(" order by asg_id asc;");
       _res = wxGetApp().app_sql_select(s_sql);

        if(_res->Status()!= PGRES_TUPLES_OK)
        {
            _res->Clear();
            return;
        }

        i_count = _res->GetRowsNumber();

        for(i=0;i<i_count;i++)
        {
             str=_res->GetVal(wxT("asg_id"));

             tmp = lv_list->InsertItem(i, str);

             str = _res->GetVal(wxT("asg_content"));
             lv_list->SetItem(tmp, 1, str);

            str = _res->GetVal(wxT("apply_name"));
             lv_list->SetItem(tmp, 2, str);

             str = DateToStrFormat(_res->GetDateTime(wxT("apply_date")));
             lv_list->SetItem(tmp, 3, str);

             str = _res->GetVal(wxT("res_engineer"));

             if(!str.IsEmpty())
             {
                 array_res = wxStringTokenize(str ,wxT(";"), wxTOKEN_DEFAULT  );

                 i_num = array_res.GetCount();

                 for(int i=0;i<i_num;i++)
                 {
                     s_person = array_res.Item(i);
                      s_res_name = get_operator_name(s_person);

                      str.Replace(s_person, s_res_name);


                 }

                 str.RemoveLast();
             }

             lv_list->SetItem(tmp, 4, str);

             str = BoolToY(_res->GetBool(wxT("is_published")));
             lv_list->SetItem(tmp, 5, str);

             str = _res->GetVal(wxT("link_id"));
             lv_list->SetItem(tmp, 6, str);

             str = BoolToY(_res->GetBool(wxT("is_active")));
             lv_list->SetItem(tmp, 7, str);

             str = _res->GetVal(wxT("publish_name"));
             lv_list->SetItem(tmp, 8, str);

             str = DateToStrFormat(_res->GetDateTime(wxT("publish_date")));
             lv_list->SetItem(tmp, 9, str);

             str = _res->GetVal(wxT("remarks"));
             lv_list->SetItem(tmp, 10, str);

             _res->MoveNext();

          }
          _res->Clear();

          break;
    case 2:
        s_sql = wxT("SELECT bci_id, bci_content, apply_person, apply_date, remarks, publisher,publish_date, is_active, is_published, \
                is_pu, is_qm, is_ie, is_pp, is_lo, is_psm, is_pm, is_co, is_others,  \
                 (select name from s_employee where employee_id = apply_person) as apply_name, (select name from s_employee where employee_id =publisher)as publish_name \
                 FROM l_bom_change_inform_table where ")+m_clause+m_clause_att+wxT(" order by bci_id asc;");
        _res = wxGetApp().app_sql_select(s_sql);

        if(_res->Status()!= PGRES_TUPLES_OK)
        {
            _res->Clear();
            return;
        }

        i_count = _res->GetRowsNumber();
        for(i=0;i<i_count;i++)
        {
             str=_res->GetVal(wxT("bci_id"));

             tmp = lv_list->InsertItem(i, str);

             str = _res->GetVal(wxT("bci_content"));
             lv_list->SetItem(tmp, 1, str);

             str = _res->GetVal(wxT("apply_name"));
             lv_list->SetItem(tmp, 2, str);

             str = DateToStrFormat(_res->GetDateTime(wxT("apply_date")));
             lv_list->SetItem(tmp, 3, str);

             str = BoolToY(_res->GetBool(wxT("is_published")));
             lv_list->SetItem(tmp, 4, str);

             str = BoolToY(_res->GetBool(wxT("is_active")));
             lv_list->SetItem(tmp, 5, str);

             str = _res->GetVal(wxT("publish_name"));
             lv_list->SetItem(tmp, 6, str);

             str = DateToStrFormat(_res->GetDateTime(wxT("publish_date")));
             lv_list->SetItem(tmp, 7, str);

             str = BoolToY(_res->GetBool(_("is_pu")));
             lv_list->SetItem(tmp, 8, str);

             str = BoolToY(_res->GetBool(_("is_qm")));
             lv_list->SetItem(tmp, 9, str);

             str = BoolToY(_res->GetBool(_("is_ie")));
             lv_list->SetItem(tmp, 10, str);

             str = BoolToY(_res->GetBool(_("is_pp")));
             lv_list->SetItem(tmp, 11, str);

             str = BoolToY(_res->GetBool(_("is_lo")));
             lv_list->SetItem(tmp, 12, str);

             str = BoolToY(_res->GetBool(_("is_psm")));
             lv_list->SetItem(tmp, 13, str);

             str = BoolToY(_res->GetBool(_("is_pm")));
             lv_list->SetItem(tmp, 14, str);

             str = BoolToY(_res->GetBool(_("is_co")));
             lv_list->SetItem(tmp, 15, str);

             str = BoolToY(_res->GetBool(_("is_others")));
             lv_list->SetItem(tmp, 16, str);

             str = _res->GetVal(_("remarks"));
             lv_list->SetItem(tmp, 17, str);

             _res->MoveNext();
        }

        _res->Clear();

        break;
    case 3:
        s_sql = wxT("SELECT ndo_id,file_name, file_id, apply_person, (select name from s_employee where employee_id=apply_person) as applier, \
                    res_supervior, (select name from s_employee where employee_id=res_supervior) as res_supervior_person,prj_manager, \
                    (select name from s_employee where employee_id=prj_manager) as prj_manager_name, apply_date, is_published, is_active,\
                    publisher,(select  name from s_employee where employee_id = publisher) as publish_name, act_publish_date, remarks \
                 FROM s_nstd_design_order where ")+m_clause+m_clause_att+wxT(" order by ndo_id asc;");
        _res = wxGetApp().app_sql_select(s_sql);

        if(_res->Status()!= PGRES_TUPLES_OK)
        {
            _res->Clear();
            return;
        }

        i_count = _res->GetRowsNumber();
        for(i=0;i<i_count;i++)
        {
             str=_res->GetVal(wxT("ndo_id"));

             tmp = lv_list->InsertItem(i, str);

             str = _res->GetVal(wxT("file_name"));
             lv_list->SetItem(tmp, 1, str);

             str = _res->GetVal(wxT("file_id"));
             lv_list->SetItem(tmp, 2, str);

             str = _res->GetVal(wxT("apply_person"));
             lv_list->SetItem(tmp, 3, str);

             str = _res->GetVal(wxT("applier"));
             lv_list->SetItem(tmp, 4, str);

             str = _res->GetVal(wxT("res_supervior"));
             lv_list->SetItem(tmp, 5, str);

             str = _res->GetVal(wxT("res_supervior_person"));
             lv_list->SetItem(tmp, 6, str);

             str = _res->GetVal(wxT("prj_manager"));
             lv_list->SetItem(tmp, 7, str);

             str = _res->GetVal(wxT("prj_manager_name"));
             lv_list->SetItem(tmp, 8, str);

             str = DateToStrFormat(_res->GetDateTime(wxT("apply_date")));
             lv_list->SetItem(tmp, 9, str);

             str = BoolToY(_res->GetBool(_("is_published")));
             lv_list->SetItem(tmp, 10, str);

             str = BoolToY(_res->GetBool(_("is_active")));
             lv_list->SetItem(tmp, 11, str);

             str = _res->GetVal(wxT("publisher"));
             lv_list->SetItem(tmp, 12, str);

             str = DateToStrFormat(_res->GetDateTime(wxT("act_publish_date")));
             lv_list->SetItem(tmp, 13, str);

             str = _res->GetVal(wxT("remarks"));
             lv_list->SetItem(tmp, 14, str);

             _res->MoveNext();
        }

        _res->Clear();
        break;

    case 4:
        s_sql = wxT("SELECT tcen_id, subject, from_sr, eco_no, is_modify_pc, valid_date, \
                is_urgent, is_mpm, is_pm, is_ds, is_cs, is_fq, is_psm, is_lo, is_co, is_sm, is_tm, is_el, is_sqe, is_ppu, is_others, remarks, \
               apply_person, apply_date, publisher, publish_date, is_active, \
               is_published,(select name from s_employee where employee_id = apply_person) as apply_name, (select name from s_employee where employee_id =publisher)as publish_name \
                FROM l_tce_notice where ")+m_clause+m_clause_att+wxT(" order by tcen_id asc;");
        _res = wxGetApp().app_sql_select(s_sql);

        if(_res->Status()!= PGRES_TUPLES_OK)
        {
            _res->Clear();
            return;
        }

        i_count = _res->GetRowsNumber();
        for(i=0;i<i_count;i++)
        {
             str=_res->GetVal(wxT("tcen_id"));

             tmp = lv_list->InsertItem(i, str);

             str = _res->GetVal(wxT("subject"));
             lv_list->SetItem(tmp, 1, str);

             str = _res->GetVal(wxT("eco_no"));
             lv_list->SetItem(tmp, 2, str);

             str = DateToStrFormat(_res->GetDate(wxT("valid_date")));
             lv_list->SetItem(tmp, 3, str);

             str = BoolToY(_res->GetBool(wxT("is_modify_pc")));
             lv_list->SetItem(tmp, 4, str);

             str = BoolToY(_res->GetBool(wxT("is_urgent")));
             lv_list->SetItem(tmp, 5, str);

            str = _res->GetVal(wxT("apply_name"));
             lv_list->SetItem(tmp, 6, str);

             str = DateToStrFormat(_res->GetDateTime(wxT("apply_date")));
             lv_list->SetItem(tmp, 7, str);

             str = BoolToY(_res->GetBool(wxT("is_published")));
             lv_list->SetItem(tmp, 8, str);

             str = BoolToY(_res->GetBool(wxT("is_active")));
             lv_list->SetItem(tmp, 9, str);

             str = _res->GetVal(wxT("publish_name"));
             lv_list->SetItem(tmp, 10, str);

             str = DateToStrFormat(_res->GetDateTime(wxT("publish_date")));
             lv_list->SetItem(tmp, 11, str);

            str = _res->GetVal(wxT("from_sr"));
             lv_list->SetItem(tmp, 12, str);

             str = BoolToY(_res->GetBool(_("is_mpm")));
             lv_list->SetItem(tmp, 13, str);

             str = BoolToY(_res->GetBool(_("is_pm")));
             lv_list->SetItem(tmp, 14, str);

             str = BoolToY(_res->GetBool(_("is_ds")));
             lv_list->SetItem(tmp, 15, str);

             str = BoolToY(_res->GetBool(_("is_cs")));
             lv_list->SetItem(tmp, 16, str);

             str = BoolToY(_res->GetBool(_("is_fq")));
             lv_list->SetItem(tmp, 17, str);

             str = BoolToY(_res->GetBool(_("is_psm")));
             lv_list->SetItem(tmp, 18, str);

             str = BoolToY(_res->GetBool(_("is_ppu")));
             lv_list->SetItem(tmp, 19, str);

             str = BoolToY(_res->GetBool(_("is_lo")));
             lv_list->SetItem(tmp, 20, str);

             str = BoolToY(_res->GetBool(_("is_co")));
             lv_list->SetItem(tmp, 21, str);

             str = BoolToY(_res->GetBool(_("is_sm")));
             lv_list->SetItem(tmp, 22, str);

             str = BoolToY(_res->GetBool(_("is_tm")));
             lv_list->SetItem(tmp, 23, str);

             str = BoolToY(_res->GetBool(_("is_el")));
             lv_list->SetItem(tmp, 24, str);

             str = BoolToY(_res->GetBool(_("is_sqe")));
             lv_list->SetItem(tmp, 25, str);

             str = BoolToY(_res->GetBool(_("is_others")));
             lv_list->SetItem(tmp, 26, str);

             str = _res->GetVal(_("remarks"));
             lv_list->SetItem(tmp, 27, str);

             _res->MoveNext();
        }

        _res->Clear();

        break;
    default:
        break;

    }
 //   wxLogMessage(s_sql);
}


void generated_id_display_panel::OnChoice_filterSelect(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxMessageBox(_("尚未登陆,无法做任何操作!"),_("信息"), wxOK);
        return;
    }

    if(event.GetSelection() == m_sel)
        return;

    m_sel = Choice_filter->GetSelection();

    switch(m_sel)
    {
    case 0:
        m_clause1 = wxT(" is_published = false and is_active =true ");
        Button_send->Enable(true);
        Button_Restore->Enable(false);
        Button_cancel->Enable(true);
        break;
    case 1:
        m_clause1 = wxT(" is_published = true  and is_active = true ");
        Button_send->Enable(false);
        Button_Restore->Enable(false);
        Button_cancel->Enable(true);
        break;
    case 2:
        m_clause1 = wxT(" is_active =false ");
        Button_send->Enable(false);
        Button_cancel->Enable(false);
        Button_Restore->Enable(true);
        break;
    default:
        Button_send->Enable(false);
        Button_Restore->Enable(false);
        Button_cancel->Enable(true);
        m_clause1 = wxT(" is_active =true ");
        break;
    }

    init_list_header();
    if(!m_clause1.IsEmpty()&&!m_clause2.IsEmpty())
    {
        m_clause= m_clause1+ wxT(" and (")+m_clause2+wxT(") ");
    }else
    {
        m_clause=m_clause1+m_clause2;
    }

    refresh_list();

}

void generated_id_display_panel::OnChoice_catalogSelect(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxMessageBox(_("尚未登陆,无法做任何操作!"),_("信息"), wxOK);
        return;
    }

    if(event.GetSelection() == m_mode)
        return;

    m_mode = Choice_catalog->GetSelection();

    wxArrayString array_group = wxGetApp().get_group();

    if(b_info)
    {
        switch(m_sel)
        {
          case 0:
            m_clause1 = wxT(" is_published = false and is_active =true ");
            break;
          case 1:
            m_clause1 = wxT(" is_published = true  and is_active = true ");
            break;
          case 2:
            m_clause1 = wxT(" is_active =false ");
            break;
          default:
            m_clause1 = wxT(" is_active =true ");
            break;
        }

    }else
    {
         m_clause1=wxT(" is_active=true ");
         m_clause2 = wxT(" apply_person='")+gr_para.login_user+wxT("' ");

         wxArrayString a_member=get_group_member_of_leader(array_group);

         int i_count = a_member.GetCount();

         for(int i=0;i<i_count;i++)
         {
             m_clause2 = m_clause2+wxT(" or apply_person='")+a_member.Item(i)+wxT("' ");
         }
    }

    init_list_header();

    if(!m_clause1.IsEmpty()&&!m_clause2.IsEmpty())
    {
        m_clause= m_clause1+ wxT(" and (")+m_clause2+wxT(") ");
    }else
    {
        m_clause=m_clause1+m_clause2;
    }

    refresh_list();

}


void generated_id_display_panel::OnButton_sendClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxMessageBox(_("尚未登陆,无法做任何操作!"),_("信息"), wxOK);
        return;
    }

    int i_sel = lv_list->GetSelectedItemCount();
    if(i_sel==0)
        return;

    if(wxMessageBox(_("确认这些通知单已经发放？"),_("确认"),wxYES_NO)==wxNO)
            return;

    int i_item = lv_list->GetFirstSelected();

    for(int i=0;i<i_sel;i++)
    {
        change_item(i_item, 1);
        i_item = lv_list->GetNextSelected(i_item);
    }

    refresh_list();

}

bool generated_id_display_panel::change_item(long i_item, int i_mode)
{
    wxString s_id = lv_list->GetItemText(i_item, 0);

    wxString s_table,s_key_word, s_char, s_old_value, s_new_value;

    wxString s_sql_start, s_sql_end , s_sql_mid;

    switch(m_mode)
    {
    case 0:
        s_table = wxT("l_internal_com_table");
        s_key_word = wxT("ll_id");

        s_sql_start = wxT("UPDATE l_internal_com_table SET ");
        s_sql_end = wxT(" where ll_id='")+s_id+wxT("' ");
        break;
    case 1:
        s_sql_start = wxT("UPDATE l_spec_gad_revised_inform_table SET ");
        s_sql_end = wxT(" where asg_id ='")+s_id+wxT("' ");

        s_table = wxT("l_spec_gad_revised_inform_table");
        s_key_word = wxT("asg_id");
        break;
    case 2:
        s_sql_start = wxT("UPDATE l_bom_change_inform_table SET ");
        s_sql_end  = wxT(" where bci_id='")+s_id+wxT("' ");

        s_table = wxT("l_bom_change_inform_table");
        s_key_word = wxT("bci_id");
        break;
    case 3:
        /*
        s_sql_start = wxT("UPDATE s_nstd_design_order SET ");
        s_sql_end = wxT(" where ndo_id = '")+s_id+wxT("' ");
        s_table = wxT("s_nstd_design_order");
        s_key_word = wxT("ndo_id");
        */
        break;
    case 4:
         s_sql_start = wxT("UPDATE l_tce_notice SET ");
         s_sql_end = wxT(" where tcen_id = '")+s_id+wxT("' ");

         s_table = wxT("l_tce_notice");
         s_key_word = wxT("tcen_id");
        break;
    default:
        break;
    }

    s_char = wxT("is_active");
    switch(i_mode)
    {
    case 0:
        s_sql_mid= wxT(" is_active=false ");

        s_old_value = wxT("true");
        s_new_value = wxT("false");
        break;
    case 1:
        s_sql_mid = wxT(" is_published=true, publisher='")+gr_para.login_user+wxT("', publish_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("' ");
        break;
    case 2:
        s_sql_mid = wxT(" is_active=true ");

        s_old_value = wxT("false");
        s_new_value = wxT("true");

        break;

    default:
        break;

    }

    wxString s_sql = s_sql_start+s_sql_mid+s_sql_end;

    if(s_sql.IsEmpty())
        return false;

    bool b_result;

    b_result = wxGetApp().app_sql_update(s_sql);

    if(b_result)
    {
        switch(i_mode)
        {
    case 0:
    case 2:

            wxGetApp().change_log(s_table, s_key_word, s_char, s_old_value, s_new_value, wxT("hand"));
            break;

        default:
            break;
        }

    }

    return b_result;

}

void generated_id_display_panel::OnButton_cancelClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxMessageBox(_("尚未登陆,无法做任何操作!"),_("信息"), wxOK);
        return;
    }

    int i_sel = lv_list->GetSelectedItemCount();
    if(i_sel==0)
        return;

    if(wxMessageBox(_("确认取消选中的通知单？"),_("确认"),wxYES_NO)==wxNO)
            return;

    int i_item = lv_list->GetFirstSelected();

    for(int i=0;i<i_sel;i++)
    {
        change_item(i_item, 0);
        i_item = lv_list->GetNextSelected(i_item);
    }

    refresh_list();
}

void generated_id_display_panel::OnButton_refreshClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxMessageBox(_("尚未登陆,无法做任何操作!"),_("信息"), wxOK);
        return;
    }

    refresh_list();
}

void generated_id_display_panel::OnButton_SearchClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxMessageBox(_("尚未登陆,无法做任何操作!"),_("信息"), wxOK);
        return;
    }

    if(tc_search->GetValue().IsEmpty())
    {
        wxMessageBox(_("请输入查询内容。"));
        tc_search->SetFocus();
        return;
    }

    switch(m_mode)
    {
    case 0:
        m_clause_att = wxT(" and ll_content like '%")+tc_search->GetValue()+wxT("%' ");
        break;
    case 1:
        m_clause_att = wxT(" and asg_content like '%")+tc_search->GetValue()+wxT("%' ");
        break;
    case 2:
         m_clause_att = wxT(" and bci_content like '%")+tc_search->GetValue()+wxT("%' ");
         break;
    case 3:
        break;
    case 4:
        m_clause_att = wxT(" and eco_no like '%")+tc_search->GetValue()+wxT("%' ");
        break;
    default:
        break;
    }

    refresh_list();

    m_clause_att.Empty();
}

void generated_id_display_panel::OnButton_RestoreClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxMessageBox(_("尚未登陆,无法做任何操作!"),_("信息"), wxOK);
        return;
    }

    int i_sel = lv_list->GetSelectedItemCount();
    if(i_sel==0)
        return;

    if(wxMessageBox(_("确认恢复已经取消的通知单？"),_("确认"),wxYES_NO)==wxNO)
            return;

    int i_item = lv_list->GetFirstSelected();

    for(int i=0;i<i_sel;i++)
    {
        change_item(i_item, 2);
        i_item = lv_list->GetNextSelected(i_item);
    }

    refresh_list();
}
