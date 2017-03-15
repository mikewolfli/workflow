/***************************************************************
 * Name:      wfMain.h
 * Purpose:   Defines Application Frame
 * Author:    mikewolfli (mikewolfli@163.com)
 * Created:   2013-11-21
 * Copyright: mikewolfli (http://mikewolfli.blog.163.com)
 * License:
 **************************************************************/

#ifndef WFMAIN_H
#define WFMAIN_H

//(*Headers(wfFrame)
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

#include <wx/wxToolBox/wxToolBox.h>
#include <wx/aui/aui.h>
#include "wf_stdafx.h"
#include "instance_unit_info.h"
#include "interface/wxPostgreSQL.h"
#include "workflow_wf.h"
#include "project_author_panel.h"
#include <wx/timer.h>
#include <wx/taskbar.h>
#include "ctrl/TaskBarBaloon.h"
#include "ins_proc_log.h"
#include "nstd_apply_panel.h"
#include "wf_workflow_panel.h"
#include "nstd_author_panel.h"
#include "nstd_mat_apply.h"
#include "private_tasks_panel.h"
#include "project_info_panel.h"
#include "project_review_author_panel.h"
#include "project_review_panel.h"
#include "po_confirm_panel.h"
#include "rfc_communication.h"
#include "info_id_generator_panel.h"
#include "generated_id_display_panel.h"
#include "ndo_generator_panel.h"
#include "ncr_proc_panel.h"
#include "nstd_nocan_panel.h"

extern   para gr_para;

class MyTaskBarIcon: public wxTaskBarIcon
{
public:
#if defined(__WXOSX__) && wxOSX_USE_COCOA
    MyTaskBarIcon(wxTaskBarIconType iconType = wxTBI_DEFAULT_TYPE)
    :   wxTaskBarIcon(iconType)
#else
    MyTaskBarIcon()
#endif
    {}

    /*
        void OnLeftButtonDClick(wxTaskBarIconEvent&);
        void OnMenuRestore(wxCommandEvent&);
        void OnMenuExit(wxCommandEvent&);
        void OnMenuSetNewIcon(wxCommandEvent&);
        void OnMenuSetOldIcon(wxCommandEvent&);
           void OnMenuCheckmark(wxCommandEvent&);
           void OnMenuUICheckmark(wxUpdateUIEvent&);
        void OnMenuSub(wxCommandEvent&);
        virtual wxMenu *CreatePopupMenu();*/

//    void display_message(wxString str_title,wxString str_message, long i_timer);

//    TaskBarBaloon *tbb;

  //  DECLARE_EVENT_TABLE()
};

class wfFrame: public wxFrame
{
public:

    wfFrame(wxWindow* parent,wxWindowID id = -1);
    virtual ~wfFrame();

    void OnThreadTimer(wxTimerEvent& event);


    void Refresh_List();
    wxArrayString Get_task_list(wxString str_query);
    wxArrayString Compare_Array(wxArrayString &array1, wxArrayString & array2);

    wxArrayString m_old_array;
    wxString m_str_query;

    /* update project info from sAP
     *
    */
    bool update_project_from_sap(wxArrayString&array_thread_wbs,Value_Pool * pool_basic, Value_Pool* pool_para, int i_way);
 //   bool init_select_case();


    bool Cal_prj_basic_info(wxString s_wbs, Value_Pool* p_value, wxArraySupport& array_support);
    s_sap_hex_info Cal_prj_weight_hex_info(wxString s_wbs, Value_Pool* p_value, wxArraySupport& array_support);

    wxArrayString get_traction_string(int i_cat);


 //   wxArraySupport get_basic_info_support(); //由如下函数取代
    wxArraySupport get_basic_info_support(wxArrayString a_rp);
    bool update_prj_basic_info(s_basic_info v_basic_info, bool b_full_finish);

    bool check_basic_info_for_array(wxArrayString arr_wbs);
    bool update_sync_din(wxArrayToDin& a_info,  bool b_success);

protected:

    MyTaskBarIcon *tray;
#if defined(__WXCOCOA__)
    MyTaskBarIcon   *m_dockIcon;
#endif
private:

    //(*Handlers(wfFrame)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    //*)

    //(*Identifiers(wfFrame)
    static const long idMenuQuit;
    static const long idMenuNomalV;
    static const long idMenuReport;
    static const long idMenuAbout;
    static const long ID_STATUSBAR1;
    //*)

    //(*Declarations(wfFrame)
    wxMenuItem* MenuItem8;
    wxMenuItem* MenuItem7;
    wxMenuItem* MenuItem5;
    wxMenuItem* MenuItem18;
    wxMenu* Menu3;
    wxMenuItem* MenuItem4;
    wxMenuItem* MenuItem14;
    wxMenuItem* MenuItem11;
    wxMenuItem* MenuItem15;
    wxMenuItem* MenuItem17;
    wxMenuItem* MenuItem13;
    wxStatusBar* sb_info;
    wxMenuItem* MenuItem10;
    wxMenuItem* MenuItem12;
    wxMenuItem* MenuItem3;
    wxMenuItem* MenuItem6;
    wxMenuItem* MenuItem16;
    wxMenuItem* MenuItem19;
    wxMenu* Menu6;
    wxMenuItem* MenuItem9;
    wxMenu* Menu5;
    wxMenu* Menu4;
    //*)

//   wxTimer * m_thread_timer;


    wxAuiManager m_mgr;
    wxToolBox *m_toolbox;
    wxTextCtrl *tc_log;
    wxPostgreSQLresult *res;
    wxAuiNotebook * CreateNotebook(wxRect &r_rect);
    wxAuiNotebook * aui_notebook;
    wxToolBoxTab * tab_review;
    wxToolBoxTab * tab_instance;
    wxToolBoxTab * tab_workflow;
    wxToolBoxTab * tab_report;
    wxToolBoxTab * tab_setup;
    wxToolBoxTab * tab_invidal;
    instance_unit_info *panel_unit_info;
    workflow_wf * panel_workflow_wf;
    project_author_panel * panel_project_author;
    nstd_apply_panel * panel_nstd_apply;
    wf_workflow_panel *panel_nstd_workflow;
    nstd_author_panel * panel_nstd_author;
    nstd_mat_apply * panel_nstd_mat_apply;
    private_tasks_panel* panel_private_tasks;
    project_info_panel * panel_project_info;
    project_review_author_panel * panel_project_review_author;
    project_review_panel * panel_project_review;
    info_id_generator_panel *panel_info_id_generator;
    generated_id_display_panel* panel_generated_id_display;
    po_confirm_panel * panel_po_confirm;
    ndo_generator_panel* panel_ndo_generator;
    ncr_proc_panel * panel_ncr_proc;
    nstd_nocan_panel * panel_nstd_nocan;
  //  Rfc_Communication * sap_rfc_conn;

    void OnToolBoxItemSelected(wxToolBoxEvent & event);
    void OnToggleNotebookPanel(wxWindowID i_id);
    wxToolBox * create_toolbox(wxRect &r_rect);
//    void auinotebook_addpage();
    void OnLogout();
    void OnAuiNotebookPageChanged(wxAuiNotebookEvent& evt);
    void SetToolBoxItemSelected(int i_index);
    void show_about();



    wxArrayString get_wbs_list(int i_choice, wxString str_case);
    /*
       for update wbs info from sap
    */

    bool update_project_unit_info(wxString str, Str_Line* line_value, Str_Line* line_header, int i_way=0);
    bool update_project_parameter(wxString str, Value_Pool* p_value);
    wxString get_value_from_line(wxString s_header, Str_Line* line_value, Str_Line* line_header);
    int prj_catalog_convert_sap(wxString sap_str);
    int nstd_level_convert_sap(wxString sap_str);
    wxString get_value_from_pool(int i_case_col, int i_result_col, wxString str, Value_Pool* p_pool);
    bool update_prj_para_fields(wxString str, Value_Pool* p_value);

    wxArraySupport get_same_act_arry(wxArraySupport & array_support, wxString str);

    wxString find_str_in_wbs_bom(int i_case_col,int i_result_col,wxArrayInt &array_range, Value_Pool* p_value, wxArraySupport &array_str);

    int get_tc_hex_by_wbs_bom(s_sap_hex_info &_value_hex,int i_mat_col,int i_qty_col,int i_name_col, wxArrayInt &array_range, Value_Pool* p_value, wxArraySupport &array_str);
    int get_rope_hex_by_wbs_bom(s_sap_hex_info &_value_hex,int i_mat_col,int i_qty_col,int i_name_col, wxArrayInt &array_range, Value_Pool* p_value, wxArraySupport &array_str);
    int get_cc_hex_by_wbs_bom(s_sap_hex_info &_value_hex,int i_mat_col,int i_qty_col,int i_name_col, wxArrayInt &array_range, Value_Pool* p_value, wxArraySupport &array_str);

    int get_dc_weight(wxString str);
    bool check_traction_spring(wxArrayInt a_index, wxArrayString a_trac, Value_Pool* p_value, int i_name_col, int i_remarks_col);

    int get_index_of_cwt_blocks(wxString &str, wxArrayBlocks & arr_blocks);
    Value_Pool * get_same_value_pool(wxString str, int i_col, Value_Pool* p_result);
    bool update_nonstd_conf_date(wxArrayString&a_nstd, wxArrayString&a_link, wxArrayString &a_now);
    bool get_nonstd_array(wxString s_wbs, wxArrayString&a_nstd, wxArrayString&a_link, wxArrayString &a_now);


    wxArrayBlocks get_cwt_blocks_info(int i_case_col,int i_result_col,wxArrayInt &array_range, Value_Pool* p_value, wxArraySupport &array_str);

    DECLARE_EVENT_TABLE()
};

#endif // WFMAIN_H

