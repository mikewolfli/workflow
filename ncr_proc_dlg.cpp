#include "ncr_proc_dlg.h"
#include "wfApp.h"
#include <wx/tokenzr.h>
#include "nstd_app_item_units.h"
#include "wf_search.h"

//(*InternalHeaders(ncr_proc_dlg)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(ncr_proc_dlg)
const long ncr_proc_dlg::ID_STATICTEXT1 = wxNewId();
const long ncr_proc_dlg::ID_TEXTCTRL_NCRID = wxNewId();
const long ncr_proc_dlg::ID_STATICTEXT2 = wxNewId();
const long ncr_proc_dlg::ID_COMBOBOX_FROM = wxNewId();
const long ncr_proc_dlg::ID_STATICTEXT3 = wxNewId();
const long ncr_proc_dlg::ID_TEXTCTRL_FILEINDEX = wxNewId();
const long ncr_proc_dlg::ID_STATICTEXT4 = wxNewId();
const long ncr_proc_dlg::ID_TEXTCTRL_REL_PROJECT = wxNewId();
const long ncr_proc_dlg::ID_BUTTON_PROJ = wxNewId();
const long ncr_proc_dlg::ID_STATICTEXT5 = wxNewId();
const long ncr_proc_dlg::ID_TEXTCTRL_ISSUE_HEAD = wxNewId();
const long ncr_proc_dlg::ID_STATICTEXT6 = wxNewId();
const long ncr_proc_dlg::ID_TEXTCTRL_UNIT_QTY = wxNewId();
const long ncr_proc_dlg::ID_TEXTCTRL_LIFT_NO = wxNewId();
const long ncr_proc_dlg::ID_STATICTEXT7 = wxNewId();
const long ncr_proc_dlg::ID_TEXTCTRL_ISSUE_DESC = wxNewId();
const long ncr_proc_dlg::ID_STATICTEXT_STATUS = wxNewId();
const long ncr_proc_dlg::ID_TEXTCTRL_PUBLISH_DATE = wxNewId();
const long ncr_proc_dlg::ID_STATICTEXT_PUBLISHER = wxNewId();
const long ncr_proc_dlg::ID_TEXTCTRL_PUBLISHER = wxNewId();
const long ncr_proc_dlg::ID_TEXTCTRL_STATUS = wxNewId();
const long ncr_proc_dlg::ID_STATICTEXT8 = wxNewId();
const long ncr_proc_dlg::ID_CHOICE_GROUP = wxNewId();
const long ncr_proc_dlg::ID_STATICTEXT_RESPONSE = wxNewId();
const long ncr_proc_dlg::ID_TEXTCTRL_FETCH_DATE = wxNewId();
const long ncr_proc_dlg::ID_TEXTCTRL_RES = wxNewId();
const long ncr_proc_dlg::ID_STATICTEXT_RES_BCO = wxNewId();
const long ncr_proc_dlg::ID_TEXTCTRL_RES_BCO = wxNewId();
const long ncr_proc_dlg::ID_STATICTEXT_FEEDBACK_DATE = wxNewId();
const long ncr_proc_dlg::ID_TEXTCTRL_FEEDBACK_DATE = wxNewId();
const long ncr_proc_dlg::ID_STATICTEXT_FEEDBACK_CONTENT = wxNewId();
const long ncr_proc_dlg::ID_TEXTCTRL_FEEDBACK_CONTENT = wxNewId();
const long ncr_proc_dlg::ID_STATICTEXT_RES_PERSON = wxNewId();
const long ncr_proc_dlg::ID_TEXTCTRL_RES_PERON = wxNewId();
const long ncr_proc_dlg::ID_STATICTEXT_RESULT = wxNewId();
const long ncr_proc_dlg::ID_TEXTCTRL_RESULT = wxNewId();
const long ncr_proc_dlg::ID_BUTTON_SAVE = wxNewId();
const long ncr_proc_dlg::ID_BUTTON_RELEASE = wxNewId();
const long ncr_proc_dlg::ID_BUTTON_CLOSE = wxNewId();
const long ncr_proc_dlg::ID_BUTTON_CANCEL = wxNewId();
//*)

BEGIN_EVENT_TABLE(ncr_proc_dlg,wxDialog)
    //(*EventTable(ncr_proc_dlg)
    //*)
END_EVENT_TABLE()

ncr_proc_dlg::ncr_proc_dlg(int _mode, wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(ncr_proc_dlg)
    wxGridBagSizer* GridBagSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    SetClientSize(wxDefaultSize);
    Move(wxDefaultPosition);
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("NCR内容"));
    GridBagSizer1 = new wxGridBagSizer(0, 0);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("NCR单号"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    GridBagSizer1->Add(StaticText1, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    tc_ncrid = new wxTextCtrl(this, ID_TEXTCTRL_NCRID, wxEmptyString, wxDefaultPosition, wxSize(129,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_NCRID"));
    GridBagSizer1->Add(tc_ncrid, wxGBPosition(0, 1), wxGBSpan(1, 2), wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("来源部门"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    GridBagSizer1->Add(StaticText2, wxGBPosition(0, 3), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    cb_fromdep = new wxComboBox(this, ID_COMBOBOX_FROM, wxEmptyString, wxDefaultPosition, wxSize(171,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_FROM"));
    cb_fromdep->Append(_("CS"));
    cb_fromdep->Append(_("QM"));
    GridBagSizer1->Add(cb_fromdep, wxGBPosition(0, 4), wxGBSpan(1, 2), wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("文件索引"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    GridBagSizer1->Add(StaticText3, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    tc_fileindex = new wxTextCtrl(this, ID_TEXTCTRL_FILEINDEX, wxEmptyString, wxDefaultPosition, wxSize(369,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_FILEINDEX"));
    GridBagSizer1->Add(tc_fileindex, wxGBPosition(1, 1), wxGBSpan(1, 5), wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("相关项目"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    GridBagSizer1->Add(StaticText4, wxGBPosition(2, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    tc_rel_proj = new wxTextCtrl(this, ID_TEXTCTRL_REL_PROJECT, wxEmptyString, wxDefaultPosition, wxSize(314,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_REL_PROJECT"));
    GridBagSizer1->Add(tc_rel_proj, wxGBPosition(2, 1), wxGBSpan(1, 4), wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Button_proj = new wxButton(this, ID_BUTTON_PROJ, _("..."), wxDefaultPosition, wxSize(31,23), 0, wxDefaultValidator, _T("ID_BUTTON_PROJ"));
    GridBagSizer1->Add(Button_proj, wxGBPosition(2, 5), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("问题概述"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    GridBagSizer1->Add(StaticText5, wxGBPosition(3, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    tc_issue_head = new wxTextCtrl(this, ID_TEXTCTRL_ISSUE_HEAD, wxEmptyString, wxDefaultPosition, wxSize(129,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_ISSUE_HEAD"));
    GridBagSizer1->Add(tc_issue_head, wxGBPosition(3, 1), wxGBSpan(1, 2), wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("梯号/台数"), wxDefaultPosition, wxSize(61,13), 0, _T("ID_STATICTEXT6"));
    GridBagSizer1->Add(StaticText6, wxGBPosition(3, 3), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    tc_unit_qty = new wxTextCtrl(this, ID_TEXTCTRL_UNIT_QTY, wxEmptyString, wxDefaultPosition, wxSize(42,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_UNIT_QTY"));
    GridBagSizer1->Add(tc_unit_qty, wxGBPosition(3, 5), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    tc_lift_no = new wxTextCtrl(this, ID_TEXTCTRL_LIFT_NO, wxEmptyString, wxDefaultPosition, wxSize(112,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_LIFT_NO"));
    GridBagSizer1->Add(tc_lift_no, wxGBPosition(3, 4), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("问题描述"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    GridBagSizer1->Add(StaticText7, wxGBPosition(4, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    tc_issue_desc = new wxTextCtrl(this, ID_TEXTCTRL_ISSUE_DESC, wxEmptyString, wxDefaultPosition, wxSize(377,47), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL_ISSUE_DESC"));
    GridBagSizer1->Add(tc_issue_desc, wxGBPosition(4, 1), wxGBSpan(2, 5), wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    st_status = new wxStaticText(this, ID_STATICTEXT_STATUS, _("NCR状态"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_STATUS"));
    GridBagSizer1->Add(st_status, wxGBPosition(6, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    tc_publish_date = new wxTextCtrl(this, ID_TEXTCTRL_PUBLISH_DATE, wxEmptyString, wxDefaultPosition, wxSize(103,21), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_PUBLISH_DATE"));
    GridBagSizer1->Add(tc_publish_date, wxGBPosition(6, 4), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    st_publisher = new wxStaticText(this, ID_STATICTEXT_PUBLISHER, _("发布信息"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_PUBLISHER"));
    GridBagSizer1->Add(st_publisher, wxGBPosition(6, 3), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    tc_publisher = new wxTextCtrl(this, ID_TEXTCTRL_PUBLISHER, wxEmptyString, wxDefaultPosition, wxSize(58,21), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_PUBLISHER"));
    GridBagSizer1->Add(tc_publisher, wxGBPosition(6, 5), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    tc_status = new wxTextCtrl(this, ID_TEXTCTRL_STATUS, wxEmptyString, wxDefaultPosition, wxSize(125,21), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_STATUS"));
    GridBagSizer1->Add(tc_status, wxGBPosition(6, 1), wxGBSpan(1, 2), wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("反馈组"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    GridBagSizer1->Add(StaticText8, wxGBPosition(7, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Choice_group = new wxChoice(this, ID_CHOICE_GROUP, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_GROUP"));
    GridBagSizer1->Add(Choice_group, wxGBPosition(7, 1), wxGBSpan(1, 2), wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    st_response = new wxStaticText(this, ID_STATICTEXT_RESPONSE, _("负责信息"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_RESPONSE"));
    GridBagSizer1->Add(st_response, wxGBPosition(7, 3), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    tc_fetch_date = new wxTextCtrl(this, ID_TEXTCTRL_FETCH_DATE, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_FETCH_DATE"));
    GridBagSizer1->Add(tc_fetch_date, wxGBPosition(7, 4), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    tc_res_eng = new wxTextCtrl(this, ID_TEXTCTRL_RES, wxEmptyString, wxDefaultPosition, wxSize(59,21), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_RES"));
    GridBagSizer1->Add(tc_res_eng, wxGBPosition(7, 5), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    st_res_bco = new wxStaticText(this, ID_STATICTEXT_RES_BCO, _("关联\n更改单"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_RES_BCO"));
    GridBagSizer1->Add(st_res_bco, wxGBPosition(8, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    tc_res_bco = new wxTextCtrl(this, ID_TEXTCTRL_RES_BCO, wxEmptyString, wxDefaultPosition, wxSize(125,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_RES_BCO"));
    GridBagSizer1->Add(tc_res_bco, wxGBPosition(8, 1), wxGBSpan(1, 2), wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    st_feedback_date = new wxStaticText(this, ID_STATICTEXT_FEEDBACK_DATE, _("回复日期"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_FEEDBACK_DATE"));
    GridBagSizer1->Add(st_feedback_date, wxGBPosition(8, 3), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    tc_feedback_date = new wxTextCtrl(this, ID_TEXTCTRL_FEEDBACK_DATE, wxEmptyString, wxDefaultPosition, wxSize(101,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_FEEDBACK_DATE"));
    GridBagSizer1->Add(tc_feedback_date, wxGBPosition(8, 4), wxGBSpan(1, 2), wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    st_feedback_content = new wxStaticText(this, ID_STATICTEXT_FEEDBACK_CONTENT, _("回复内容"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_FEEDBACK_CONTENT"));
    GridBagSizer1->Add(st_feedback_content, wxGBPosition(9, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    tc_content = new wxTextCtrl(this, ID_TEXTCTRL_FEEDBACK_CONTENT, wxEmptyString, wxDefaultPosition, wxSize(369,48), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL_FEEDBACK_CONTENT"));
    GridBagSizer1->Add(tc_content, wxGBPosition(9, 1), wxGBSpan(2, 5), wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    st_res_peron = new wxStaticText(this, ID_STATICTEXT_RES_PERSON, _("问题\n责任人"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_RES_PERSON"));
    GridBagSizer1->Add(st_res_peron, wxGBPosition(11, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    tc_res_person = new wxTextCtrl(this, ID_TEXTCTRL_RES_PERON, wxEmptyString, wxDefaultPosition, wxSize(89,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_RES_PERON"));
    GridBagSizer1->Add(tc_res_person, wxGBPosition(11, 1), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    st_result = new wxStaticText(this, ID_STATICTEXT_RESULT, _("结果\n分析"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_RESULT"));
    GridBagSizer1->Add(st_result, wxGBPosition(11, 2), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    tc_result = new wxTextCtrl(this, ID_TEXTCTRL_RESULT, wxEmptyString, wxDefaultPosition, wxSize(230,52), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL_RESULT"));
    GridBagSizer1->Add(tc_result, wxGBPosition(11, 3), wxGBSpan(2, 3), wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(GridBagSizer1, 1, wxALL|wxEXPAND, 0);
    BoxSizer1->Add(StaticBoxSizer1, 9, wxALL|wxEXPAND, 0);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    Button_save = new wxButton(this, ID_BUTTON_SAVE, _("保存"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_SAVE"));
    BoxSizer2->Add(Button_save, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button_release = new wxButton(this, ID_BUTTON_RELEASE, _("保存并发布"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_RELEASE"));
    BoxSizer2->Add(Button_release, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button_close = new wxButton(this, ID_BUTTON_CLOSE, _("NCR关闭"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CLOSE"));
    BoxSizer2->Add(Button_close, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button_cancel = new wxButton(this, ID_BUTTON_CANCEL, _("退出"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CANCEL"));
    BoxSizer2->Add(Button_cancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 0);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON_PROJ,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ncr_proc_dlg::OnButton_projClick);
    Connect(ID_BUTTON_SAVE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ncr_proc_dlg::OnButton_saveClick);
    Connect(ID_BUTTON_RELEASE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ncr_proc_dlg::OnButton_releaseClick);
    Connect(ID_BUTTON_CLOSE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ncr_proc_dlg::OnButton_closeClick);
    Connect(ID_BUTTON_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ncr_proc_dlg::OnButton_cancelClick);
    //*)

    m_mode=_mode;
    show_control();
    get_ncr_group(array_group,array_group_name);

    Choice_group->Set(array_group_name);

}

ncr_proc_dlg::~ncr_proc_dlg()
{
    //(*Destroy(ncr_proc_dlg)
    //*)
}


void ncr_proc_dlg::OnButton_cancelClick(wxCommandEvent& event)
{
    EndDialog(wxID_CANCEL);
}

void ncr_proc_dlg::OnButton_closeClick(wxCommandEvent& event)
{
   EndDialog(wxID_CANCEL);
}

void ncr_proc_dlg::OnButton_saveClick(wxCommandEvent& event)
{
    update_ncr_data();

    EndDialog(wxID_OK);
}

void ncr_proc_dlg::OnButton_releaseClick(wxCommandEvent& event)
{
    update_ncr_data_ex();
    EndDialog(wxID_OK);
}

bool ncr_proc_dlg::update_ncr_data()
{
    wxString s_sql;

    get_data();

    switch(m_mode)
    {
  case 0:
      if(m_id.IsEmpty())
           s_sql = wxT("INSERT INTO s_ncr_data (ncr_id, rel_wbs, res_project, lift_no, file_index, from_dep, \
             issue_desc, issue_head, issue_status, lift_qty, res_group, create_by, create_date, modify_by, modify_date, publish_by, publish_date)\
    VALUES ('")+m_ncr_id+wxT("','")+m_rel_wbs+wxT("','")+m_res_project+wxT("','")+m_lift_no+wxT("','")+m_file_index+wxT("','")+m_from_dep+wxT("','")+
           m_issue_desc+wxT("','")+m_issue_head+wxT("',0,'")+NumToStr(m_lift_qty)+wxT("','")+
           m_res_group+wxT("','")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+
          wxT("', '")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("');");
        else
             s_sql = wxT("UPDATE s_ncr_data SET ncr_id='")+m_ncr_id+wxT("', rel_wbs='")+m_rel_wbs+wxT("', res_project='")+m_res_project+wxT("', lift_no='")+
             m_lift_no+wxT("', file_index='")+m_file_index+wxT("',from_dep='")+m_from_dep+wxT("', issue_desc='")+m_issue_desc+wxT("', issue_head='")+m_issue_head+
             wxT("', lift_qty='")+NumToStr(m_lift_qty)+wxT("', res_group='")+m_res_group+wxT("', modify_by='")+gr_para.login_user+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("' where id='")+m_id+wxT("';");
        break;
  case 2:
      s_sql = wxT("UPDATE s_ncr_data SET res_bco='")+m_res_bco+wxT("', fb_content='")+m_fb_content+wxT("', issue_res='")+m_issue_res+wxT("', modify_by='")+gr_para.login_user+wxT(", modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("' where id='")+m_id+wxT("';");
      break;
  case 4:
       s_sql = wxT("UPDATE s_ncr_data SET issue_result='")+m_issue_result+wxT("', modify_by='")+gr_para.login_user+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("' where id='")+m_id+wxT("';");
       break;
  default:
        s_sql.Empty();
        break;
   }

   if(s_sql.IsEmpty())
      return false;

   return wxGetApp().app_sql_update(s_sql);

}

bool ncr_proc_dlg::update_ncr_data_ex()
{
    wxString s_sql;

    get_data();

    switch(m_mode)
    {
  case 0:
      if(m_id.IsEmpty())
           s_sql = wxT("INSERT INTO s_ncr_data (ncr_id, rel_wbs, res_project, lift_no, file_index, from_dep, \
             issue_desc, issue_head, issue_status, lift_qty, res_group, create_by, create_date, modify_by, modify_date, publish_by, publish_date)\
    VALUES ('")+m_ncr_id+wxT("','")+m_rel_wbs+wxT("','")+m_res_project+wxT("','")+m_lift_no+wxT("','")+m_file_index+wxT("','")+m_from_dep+wxT("','")+
           m_issue_desc+wxT("','")+m_issue_head+wxT("',1,'")+NumToStr(m_lift_qty)+wxT("','")+
           m_res_group+wxT("','")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+
           wxT("', '")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("');");
        else
             s_sql = wxT("UPDATE s_ncr_data SET ncr_id='")+m_ncr_id+wxT("', rel_wbs='")+m_rel_wbs+wxT("', res_project='")+m_res_project+wxT("', lift_no='")+
             m_lift_no+wxT("', file_index='")+m_file_index+wxT("',from_dep='")+m_from_dep+wxT("', issue_desc='")+m_issue_desc+wxT("', issue_head='")+m_issue_head+
             wxT("', lift_qty='")+NumToStr(m_lift_qty)+wxT("', res_group='")+m_res_group+wxT("', modify_by='")+gr_para.login_user+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', issue_status=1, publish_by='")+
             gr_para.login_user+wxT("',publish_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("' where id='")+m_id+wxT("';");
        break;
  case 2:
      s_sql = wxT("UPDATE s_ncr_data SET res_bco='")+m_res_bco+wxT("', fb_content='")+m_fb_content+wxT("', issue_res='")+m_issue_res+wxT("', modify_by='")+gr_para.login_user+wxT(", modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', issue_status=3,\
                fb_date= '")+DateToAnsiStr(wxDateTime::Now())+wxT("' where id='")+m_id+wxT("';");
      break;
  case 4:
       s_sql = wxT("UPDATE s_ncr_data SET issue_status=5, issue_result='")+m_issue_result+wxT("', modify_by='")+gr_para.login_user+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("' where id='")+m_id+wxT("';");
       break;
  default:
       return false;
   }

 //  wxLogMessage(s_sql);

   return wxGetApp().app_sql_update(s_sql);

}

bool  ncr_proc_dlg::get_ncr_group(wxArrayString &a_group_id, wxArrayString &a_group_name)
{
    wxString s_sql =wxT("select distinct group_id, group_name from v_group_member where is_ncr=true;");

    a_group_id.Clear();
    a_group_name.Clear();

    wxPostgreSQLresult *_res = wxGetApp().app_sql_select(s_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return false;
    }

    int i_count = _res->GetRowsNumber();

    wxString str;

    for(int i=0; i<i_count; i++)
    {
        str = _res->GetVal(wxT("group_id"));
        a_group_id.Add(str);

        str = _res->GetVal(wxT("group_name"));
        a_group_name.Add(str);

        _res->MoveNext();
    }

    _res->Clear();


}

void ncr_proc_dlg::get_data()
{
    m_ncr_id = tc_ncrid->GetValue();
    m_from_dep =cb_fromdep->GetValue();
    m_file_index = tc_fileindex->GetValue();

    m_file_index.Replace(wxT("'"),wxT("\'"));
    if(m_rel_wbs.IsEmpty())
    {
        m_res_project=tc_rel_proj->GetValue();
        m_lift_no  = tc_lift_no->GetValue();
        m_lift_qty = StrToInt(tc_unit_qty->GetValue());
    }

    m_issue_head = tc_issue_head->GetValue();
    m_issue_desc = tc_issue_desc->GetValue();

    m_issue_desc.Replace(wxT("'"),wxT("\'"));

    int i_group = Choice_group->GetSelection();
    if(i_group!=wxNOT_FOUND)
         m_res_group = array_group.Item(i_group);
     else
        m_res_group.Empty();
    m_res_bco = tc_res_bco->GetValue();
    m_fb_content = tc_content->GetValue();
    m_fb_content.Replace(wxT("'"),wxT("\'"));
    m_issue_res = tc_res_person->GetValue();
    m_issue_result = tc_result->GetValue();

    m_issue_result.Replace(wxT("'"),wxT("\'"));


}

void ncr_proc_dlg::init_ctrl_value()
{
    tc_ncrid->SetValue(m_ncr_id);

    cb_fromdep->SetValue(m_from_dep);
    tc_fileindex->SetValue(m_file_index);

    if(m_rel_wbs.IsEmpty())
        tc_rel_proj->Clear();
    else
    {
        tc_rel_proj->SetValue(parse_rel_project(m_rel_wbs));

    }

    tc_issue_head->SetValue(m_issue_head);
    tc_issue_desc->SetValue(m_issue_desc);

    tc_unit_qty->SetValue(NumToStr(m_lift_qty));
    tc_lift_no->SetValue(m_lift_no);

    tc_status->SetValue(ncr_status_to_str(m_status));
    tc_publisher->SetValue(m_publish_by);
    tc_publish_date->SetValue(m_publish_date);
    Choice_group->SetStringSelection(m_res_group);
    tc_res_eng->SetValue(m_res_by);
    tc_fetch_date->SetValue(m_fetch_date);
    tc_res_bco->SetValue(m_res_bco);
    tc_feedback_date->SetValue(m_fb_date);

    tc_content->SetValue(m_fb_content);
    tc_res_person->SetValue(m_issue_res);
    tc_result->SetValue(m_issue_result);

}

void ncr_proc_dlg::show_control()
{
    switch(m_mode)
    {
    case 0://初始状态-提交NCR状态 本人
        tc_ncrid->Enable(true);
        cb_fromdep->Enable(true);
        tc_fileindex->Enable(true);
        tc_rel_proj->Enable(true);
        Button_proj->Enable(true);
        tc_issue_head->Enable(true);
        tc_unit_qty->Enable(true);
        tc_lift_no->Enable(true);
        tc_issue_desc->Enable(true);
        tc_status->Enable(false);
        tc_publisher->Enable(false);
        tc_publish_date->Enable(false);
        tc_res_eng->Show(false);
        tc_fetch_date->Show(false);
        st_response->Show(false);
        st_res_bco->Show(false);
        tc_res_bco->Show(false);
        st_feedback_date->Show(false);
        tc_feedback_date->Show(false);
        st_feedback_content->Show(false);
        tc_content->Show(false);
        st_res_peron->Show(false);
        tc_res_person->Show(false);
        st_result->Show(false);
        tc_result->Show(false);
        Button_close->Show(false);
        Button_save->Show(true);
        Button_release->Show(true);
        Choice_group->Enable(true);

        break;
    case 1://CRTD状态，release状态 非本人
        tc_ncrid->Enable(false);
        cb_fromdep->Enable(false);
        tc_fileindex->Enable(false);
        tc_rel_proj->Enable(false);
        Button_proj->Enable(false);
        tc_issue_head->Enable(false);
        tc_unit_qty->Enable(false);
        tc_lift_no->Enable(false);
        tc_issue_desc->Enable(false);
        tc_status->Enable(false);
        tc_publisher->Enable(false);
        tc_publish_date->Enable(false);
        tc_res_eng->Show(false);
        tc_fetch_date->Show(false);
        st_response->Show(false);
        st_res_bco->Show(false);
        tc_res_bco->Show(false);
        st_feedback_date->Show(false);
        tc_feedback_date->Show(false);
        st_feedback_content->Show(false);
        tc_content->Show(false);
        st_res_peron->Show(false);
        tc_res_person->Show(false);
        st_result->Show(false);
        tc_result->Show(false);
        Button_close->Show(false);
        Button_save->Show(false);
        Button_release->Show(false);
        Choice_group->Enable(false);

        break;
    case 2://领用状态 本人
        tc_ncrid->Enable(false);
        cb_fromdep->Enable(false);
        tc_fileindex->Enable(false);
        tc_rel_proj->Enable(false);
        Button_proj->Enable(false);
        tc_issue_head->Enable(false);
        tc_unit_qty->Enable(false);
        tc_lift_no->Enable(false);
        tc_issue_desc->Enable(false);
        tc_status->Enable(false);
        tc_publisher->Enable(false);
        tc_publish_date->Enable(false);
        tc_res_eng->Show(true);
        tc_res_eng->Enable(false);
        tc_fetch_date->Show(true);
        tc_fetch_date->Enable(false);
        st_response->Show(true);
        st_res_bco->Show(true);
        tc_res_bco->Show(true);
        st_feedback_date->Show(true);
        tc_feedback_date->Show(true);
        tc_feedback_date->Enable(false);
        st_feedback_content->Show(true);
        tc_content->Show(true);
        st_res_peron->Show(true);
        tc_res_person->Show(true);
        tc_res_person->Enable(true);
        st_result->Show(false);
        tc_result->Show(false);
        Button_close->Show(false);
        Button_save->Show(true);
        Button_release->Show(true);
        Button_save->SetLabel(_("保存"));
        Button_release->SetLabel(_("保存并反馈"));

        tc_content->SetValidator(wxTextValidator(wxFILTER_EMPTY ));
        break;
    case 3://领用状态非本人，
        tc_ncrid->Enable(false);
        cb_fromdep->Enable(false);
        tc_fileindex->Enable(false);
        tc_rel_proj->Enable(false);
        Button_proj->Enable(false);
        tc_issue_head->Enable(false);
        tc_unit_qty->Enable(false);
        tc_lift_no->Enable(false);
        tc_issue_desc->Enable(false);
        tc_status->Enable(false);
        tc_publisher->Enable(false);
        tc_publish_date->Enable(false);
        tc_res_eng->Show(true);
        tc_res_eng->Enable(false);
        tc_fetch_date->Show(true);
        tc_fetch_date->Enable(false);
        st_response->Show(true);
        st_res_bco->Show(true);
        tc_res_bco->Show(true);
        tc_res_bco->Enable(false);
        st_feedback_date->Show(true);
        tc_feedback_date->Show(true);
        tc_feedback_date->Enable(false);
        st_feedback_content->Show(true);
        tc_content->Show(true);
        tc_content->Enable(false);
        st_res_peron->Show(true);
        tc_res_person->Show(true);
        tc_res_person->Enable(false);
        st_result->Show(false);
        tc_result->Show(false);
        Button_close->Show(false);
        Button_save->Show(false);
        Button_release->Show(false);
        break;
    case 4://已回复状态，本人
        tc_ncrid->Enable(false);
        cb_fromdep->Enable(false);
        tc_fileindex->Enable(false);
        tc_rel_proj->Enable(false);
        Button_proj->Enable(false);
        tc_issue_head->Enable(false);
        tc_unit_qty->Enable(false);
        tc_lift_no->Enable(false);
        tc_issue_desc->Enable(false);
        tc_status->Enable(false);
        tc_publisher->Enable(false);
        tc_publish_date->Enable(false);
        tc_res_eng->Show(true);
        tc_res_eng->Enable(false);
        tc_fetch_date->Show(true);
        tc_fetch_date->Enable(false);
        st_response->Show(true);
        st_res_bco->Show(true);
        tc_res_bco->Show(true);
        tc_res_bco->Enable(false);
        st_feedback_date->Show(true);
        tc_feedback_date->Show(true);
        tc_feedback_date->Enable(false);
        st_feedback_content->Show(true);
        tc_content->Show(true);
        tc_content->Enable(false);
        st_res_peron->Show(true);
        tc_res_person->Show(true);
        tc_res_person->Enable(false);
        st_result->Show(true);
        tc_result->Show(true);
        tc_result->Enable(true);
        Button_close->Show(true);
        Button_save->Show(true);
        Button_release->Show(false);
        Button_release->SetLabel(_("保存关闭"));
        tc_result->SetValidator(wxTextValidator(wxFILTER_EMPTY ));
        break;
    case  5://已关闭，或回复状态非本人
        tc_ncrid->Enable(false);
        cb_fromdep->Enable(false);
        tc_fileindex->Enable(false);
        tc_rel_proj->Enable(false);
        Button_proj->Enable(false);
        tc_issue_head->Enable(false);
        tc_unit_qty->Enable(false);
        tc_lift_no->Enable(false);
        tc_issue_desc->Enable(false);
        tc_status->Enable(false);
        tc_publisher->Enable(false);
        tc_publish_date->Enable(false);
        tc_res_eng->Show(true);
        tc_res_eng->Enable(false);
        tc_fetch_date->Show(true);
        tc_fetch_date->Enable(false);
        st_response->Show(true);
        st_res_bco->Show(true);
        tc_res_bco->Show(true);
        tc_res_bco->Enable(false);
        st_feedback_date->Show(true);
        tc_feedback_date->Show(true);
        tc_feedback_date->Enable(false);
        st_feedback_content->Show(true);
        tc_content->Show(true);
        tc_content->Enable(false);
        st_res_peron->Show(true);
        tc_res_person->Show(true);
        tc_res_person->Enable(false);
        st_result->Show(true);
        tc_result->Show(true);
        tc_result->Enable(false);
        Button_close->Show(false);
        Button_save->Show(false);
        Button_release->Show(false);
        break;
    default:
        tc_ncrid->Enable(false);
        cb_fromdep->Enable(false);
        tc_fileindex->Enable(false);
        tc_rel_proj->Enable(false);
        Button_proj->Enable(false);
        tc_issue_head->Enable(false);
        tc_unit_qty->Enable(false);
        tc_lift_no->Enable(false);
        tc_issue_desc->Enable(false);
        tc_status->Enable(false);
        tc_publisher->Enable(false);
        tc_publish_date->Enable(false);
        tc_res_eng->Show(true);
        tc_res_eng->Enable(false);
        tc_fetch_date->Show(true);
        tc_fetch_date->Enable(false);
        st_response->Show(true);
        st_res_bco->Show(true);
        tc_res_bco->Show(true);
        tc_res_bco->Enable(false);
        st_feedback_date->Show(true);
        tc_feedback_date->Show(true);
        tc_feedback_date->Enable(false);
        st_feedback_content->Show(true);
        tc_content->Show(true);
        tc_content->Enable(false);
        st_res_peron->Show(true);
        tc_res_person->Show(true);
        tc_res_person->Enable(false);
        st_result->Show(true);
        tc_result->Show(true);
        tc_result->Enable(false);
        Button_close->Show(false);
        Button_save->Show(false);
        Button_release->Show(false);
        break;

    }

    Layout();

}

void ncr_proc_dlg::init_res_group()
{
    wxString s_sql = wxT(" select * from s_group where group_catalog='CF' OR group_catalog ='NSTD';");
    wxPostgreSQLresult * _res= wxGetApp().app_sql_select(s_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int i_count = _res->GetRowsNumber();

    wxString str;
    array_group.Clear();
    array_group_name.Clear();

    for(int i=0; i<i_count; i++)
    {
        str = _res->GetVal(wxT("group_id"));
        array_group.Add(str);

        str = _res->GetVal(wxT("group_name"));
        array_group_name.Add(str);
        _res->MoveNext();
    }


    _res->Clear();

    Choice_group->Set(array_group_name);
}

wxString ncr_proc_dlg::parse_rel_project(wxString s_wbs)
{
    array_wbs = wxStringTokenize(s_wbs,wxT(";"), wxTOKEN_DEFAULT  );

    if(array_wbs.IsEmpty())
        return wxEmptyString;

    return get_project_info(array_wbs);

}

wxString ncr_proc_dlg::get_project_info(wxArrayString &a_wbs)
{
    m_res_project = a_wbs.Item(0).Left(10);

    wxArrayString a_rel_wbs =  combine_str(a_wbs, wxT(";"),wxT("~"),wxT(","),true, false);

    wxString s_sql = wxT("select concat( contract_id, ' ', project_name) as project_info from s_project_info where project_id='")+m_res_project+wxT("';");
    wxPostgreSQLresult *_res=wxGetApp().app_sql_select(s_sql);
    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return wxEmptyString;
    }

    if(_res->GetRowsNumber()==0)
    {
        _res->Clear();
        return wxEmptyString;
    }

    m_prj_head = _res->GetVal(wxT("project_info"));


    if(!a_rel_wbs.IsEmpty())
        return m_prj_head+wxT(" ")+a_rel_wbs.Item(0);

    return wxEmptyString;



}

void ncr_proc_dlg::OnButton_projClick(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    wxPostgreSQLresult *_res;
    wxString s_sql ;
    wxArrayString a_str;
    wxString str;

    if(m_mode == 0 || m_mode==1)
    {
        if(array_wbs.IsEmpty())
        {

            str = _("合同号");
            a_str.Add(str);
            str=_("项目WBS号");
            a_str.Add(str);
            str=_("项目名称");
            a_str.Add(str);

            wf_search fdlg;

            fdlg.set_choice(a_str);
            int i_choice;
            wxString s_case;

            if(fdlg.ShowModal()==wxID_OK)
            {
                i_choice =fdlg.i_choice;
                s_case = fdlg.str_search;
            }
            else
                return;

            s_sql = wxT("SELECT concat(contract_id,'-',project_name) as project_info, concat(wbs_no,'-',lift_no) as wbs_info from v_unit_info  where ");
            switch(i_choice)
            {
            case 0:
                s_sql= s_sql+wxT(" contract_id = '")+s_case+wxT("' ");
                break;
            case 1:
                s_sql = s_sql +wxT(" project_id like '%")+s_case + wxT("%' ");
                break;
            case 2:
                s_sql = s_sql +wxT(" project_name like '%")+s_case+wxT("%' ");
                break;
            default:
                s_sql= s_sql+wxT(" contract_id = '")+s_case+wxT("' ");
                break;
            }

            a_str.Clear();

            s_sql = s_sql+wxT(" and status>=6 order by wbs_no asc;");

            _res=wxGetApp().app_sql_select(s_sql);

            if(_res->Status()!= PGRES_TUPLES_OK)
            {
                _res->Clear();
                return;
            }
            int i_count =_res->GetRowsNumber();

            if(i_count==0)
            {
                _res->Clear();
                return;
            }

            for(int i=0; i<i_count; i++)
            {
                m_prj_head = _res->GetVal(wxT("project_info"));

                str =_res->GetVal(wxT("wbs_info"));

                a_str.Add(str);
                _res->MoveNext();
            }

            _res->Clear();

            nstd_app_item_units dlg;
            dlg.init_checklistbox(a_str,a_str);
            dlg.SetTitle(m_prj_head);

            a_str.Clear();

            if(dlg.ShowModal()==wxID_OK)
            {
                array_wbs = dlg.array_units;
            }
            else
                return;


            m_lift_qty = array_wbs .GetCount();

            wxArrayString a_lift_no;
            int i_pos;
            wxString s_temp;

            m_rel_wbs.Empty();

            for(int i=0;i<m_lift_qty;i++)
            {
                  s_temp = array_wbs.Item(i);
                  i_pos = s_temp.Find(wxT("-"));
                  str =  s_temp.Right(s_temp.Length()-i_pos-1);
                  a_lift_no.Add(str);
                  m_rel_wbs=m_rel_wbs+s_temp.Left(i_pos)+wxT(";");

            }
            m_rel_wbs.RemoveLast(1);

            m_lift_no = Combine_lift_no(a_lift_no);

            a_lift_no.Clear();

            tc_rel_proj->SetValue(parse_rel_project(m_rel_wbs));
            tc_unit_qty->SetValue(NumToStr(m_lift_qty));
            tc_lift_no->SetValue(m_lift_no);

        }
        else
        {
             int i_count = array_wbs.GetCount();


              s_sql = wxT("SELECT concat(contract_id,'-',project_name) as project_info, concat(wbs_no,'-',lift_no) as wbs_info from v_unit_info  where project_id ='")+array_wbs.Item(0).Left(10)+wxT("' and status>=6 order by wbs_no asc;");

              _res= wxGetApp().app_sql_select(s_sql);

            if(_res->Status()!= PGRES_TUPLES_OK)
            {
                _res->Clear();
                return;
            }
            i_count =_res->GetRowsNumber();

            if(i_count==0)
            {
                _res->Clear();
                return;
            }

            for(int i=0; i<i_count; i++)
            {
                m_prj_head = _res->GetVal(wxT("project_info"));

                str =_res->GetVal(wxT("wbs_info"));

                a_str.Add(str);
                _res->MoveNext();
            }

            _res->Clear();

            nstd_app_item_units dlg;
            dlg.init_checklistbox(a_str,array_wbs);
            dlg.SetTitle(m_prj_head);

            a_str.Clear();

            if(dlg.ShowModal()==wxID_OK)
            {
                array_wbs.Clear();
                array_wbs = dlg.array_units;
            }
            else
                return;

            m_lift_qty = array_wbs .GetCount();

            wxArrayString a_lift_no;
            int i_pos;
            wxString s_temp;
            m_rel_wbs.Empty();

            for(int i=0;i<m_lift_qty;i++)
            {
                  s_temp = array_wbs .Item(i);
                  i_pos = s_temp.Find(wxT("-"));
                  str =  s_temp.Right(s_temp.Length()-i_pos-1);
                  a_lift_no.Add(str);
                  m_rel_wbs=m_rel_wbs+s_temp.Left(i_pos)+wxT(";");

            }
            m_rel_wbs.RemoveLast(1);

            m_lift_no = Combine_lift_no(a_lift_no);

            a_lift_no.Clear();

            tc_rel_proj->SetValue(parse_rel_project(m_rel_wbs));
            tc_unit_qty->SetValue(NumToStr(m_lift_qty));
            tc_lift_no->SetValue(m_lift_no);

        }
    }else
    {
        if(array_wbs.IsEmpty())
             return;

        int i_count = array_wbs.GetCount();

         s_sql = wxT("SELECT concat(contract_id,'-',project_name) as project_info, concat(wbs_no,'-',lift_no) as wbs_info from v_unit_info  where ");

         for(int i=0;i<i_count;i++)
         {
             if(i==i_count-1)
                s_sql = s_sql+wxT(" wbs_no='")+array_wbs.Item(i)+wxT("' ;");
             else
                s_sql = s_sql +wxT(" wbs_no='")+array_wbs.Item(i)+wxT("' and ");
         }

              _res= wxGetApp().app_sql_select(s_sql);

            if(_res->Status()!= PGRES_TUPLES_OK)
            {
                _res->Clear();
                return;
            }
            i_count =_res->GetRowsNumber();

            if(i_count==0)
            {
                _res->Clear();
                return;
            }

            for(int i=0; i<i_count; i++)
            {
                m_prj_head = _res->GetVal(wxT("project_info"));

                str =_res->GetVal(wxT("wbs_info"));

                a_str.Add(str);
                _res->MoveNext();
            }

            _res->Clear();

            nstd_app_item_units dlg;
            dlg.init_checklistbox(a_str,array_wbs,true, false);
            dlg.SetTitle(m_prj_head);

            a_str.Clear();

            dlg.ShowModal();
    }

}
