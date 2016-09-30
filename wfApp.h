/***************************************************************
 * Name:      wfApp.h
 * Purpose:   Defines Application Class
 * Author:    mikewolfli (mikewolfli@163.com)
 * Created:   2013-11-21
 * Copyright: mikewolfli (http://mikewolfli.blog.163.com)
 * License:
 **************************************************************/

#ifndef WFAPP_H
#define WFAPP_H

#include <wx/app.h>
#include <wx/snglinst.h>
#include "interface/wxPostgreSQL.h"
#include "wf_stdafx.h"

WX_DEFINE_ARRAY_PTR(wxThread *, wxArrayThread);

extern para gr_para;

extern wxPrintData *g_printData;
extern wxPageSetupDialogData* g_pageSetupData;

class wfApp : public wxApp
{
public:
    wfApp() : AppShutdown(false) {}
    virtual bool OnInit();
    virtual int OnExit();

    bool read_para();
    wxPostgreSQL* conn=NULL;

    void login_log(int i_way);
    int check_status();
    void clear_login();
    int contractbook_lender_change(wxString s_cid, wxString s_aim);
    wxString get_ser_no(wxString _table_str, wxString _para_str);
    wxString get_ser_id(wxString _table_str, wxString _para_str);
    bool is_have(wxString lquery);
    wxArrayString Get_header(wxString _table_str, wxArrayString & _para_str);
    bool app_sql_update(wxString &_query);//include insert and update)
    wxPostgreSQLresult * app_sql_select(wxString & _query);
    bool update_desc(wxString str_id, wxString str_desc, bool b_update);
    wxString get_leader(wxString s_group);
    wxArrayString get_group();
    wxString get_only_group();
    bool is_design(wxString s_group);
    bool is_eds(wxString s_group);
    wxArrayString get_member_in_group(wxString str_group, bool with_leader = false);
    wxArrayString get_member_in_group(wxArrayString str_group, bool with_leader =false);
    bool is_leader(wxString s_group);
    bool add_contract_id(wxString s_proj_id,wxString s_contract_id);
    wxArrayString get_role_member(int & i_count, wxString s_role,wxString s_group=wxEmptyString);

    bool change_log(wxString s_table, wxString s_keyword, wxString source_char,wxString source_value, wxString result_value, wxString change_way=wxT("hand"));
    bool update_data_in_database(wxString change_key, wxString change_value, wxString table_name, wxString pri_key, wxString pri_value);

    bool get_client_version();
    bool check_new_config(wxArrayString &a_group, wxArrayString &a_flag,int &i_count, wxString s_lift_type);
    wxArrayString  get_sub_eng_list(int &i_count, bool b_twig=false);
    wxString get_direct_leader(wxString _user);
    bool update_new_nstd_config(wxString s_nstd_id, int i_status);
    wxString get_nstd_from_unit(wxString s_wbs, wxString s_flag);
    wxString get_name(wxString s_id);

    wxDateTime get_prj_auth_date(wxString s_wbs);


    // Critical Section for multi-thread background

    wxCriticalSection   AppCritSection;
    wxSemaphore         AppSemaphoreDone;
    bool                AppShutdown;

    wxArrayThread       AppThreads;

private:
    wxSingleInstanceChecker* m_checker=NULL;
    wxString conn_str;

};

DECLARE_APP(wfApp)
#endif // WFAPP_H
