#ifndef INSTANCE_UNIT_INFO_H
#define INSTANCE_UNIT_INFO_H

//(*Headers(instance_unit_info)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/grid.h>
#include <wx/button.h>
//*)

//#include "interface/wxPostgreSQL.h"
#include "interface/sqlresulttable.h"
#include "utils/wf_operator.h"
#include "thread/mythread.h"
#include "rfc_communication.h"
#include "thread/curl_thread.h"
#include <wx/print.h>

#define mmtoppix        wxScreenDC().GetPPI().GetWidth() / 25.4
#define mmtoppiy        wxScreenDC().GetPPI().GetHeight() / 25.4

class instance_unit_info: public wxPanel
{
	public:
		instance_unit_info(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~instance_unit_info();

		//(*Declarations(instance_unit_info)
		sqlResultGrid* gd_unit_info;
		wxButton* Button_DEL_project;
		wxListCtrl* lc_project;
		wxMenuItem* mi_cb_lender;
		wxMenuItem* MenuItem8;
		wxMenuItem* mi_delv_mc2_h;
		wxButton* Button_Restore_project;
		wxMenuItem* MenuItem26;
		wxMenuItem* MenuItem7;
		wxMenuItem* mi_proj_name;
		wxButton* Button4;
		wxMenuItem* MenuItem25;
		wxMenuItem* MenuItem5;
		wxMenuItem* MenuItem2;
		wxMenuItem* mi_add_contract_id;
		wxButton* Button1;
		wxMenuItem* mi_delivery_date;
		wxMenuItem* mi_special_info;
		wxMenu menu_unit_info_renew;
		wxMenuItem* mi_urgent;
		wxMenuItem* MenuItem1;
		wxMenuItem* MenuItem4;
		wxMenuItem* MenuItem14;
		wxMenuItem* MenuItem11;
		wxButton* Button_Cal_Basic_Info;
		wxButton* Button_NSTD_SAP_UPDATE;
		wxMenuItem* MenuItem_Weight;
		wxButton* button_sap_by_wbs;
		wxMenuItem* MenuItem15;
		wxMenuItem* MenuItem22;
		wxMenuItem* mi_hex;
		wxMenuItem* MenuItem17;
		wxMenuItem* mi_cb_search;
		wxMenuItem* MenuItem13;
		wxButton* Button_Cancel_project;
		wxMenuItem* MenuItem10;
		wxMenuItem* mi_unit_in_contract;
		wxButton* Button2;
		wxMenuItem* MenuItem12;
		wxMenuItem* MenuItem24;
		wxMenuItem* mi_syc_din;
		wxMenuItem* mi_contract;
		wxButton* Button5;
		wxMenuItem* MenuItem3;
		wxButton* Button3;
		wxButton* button_sap_by_internal;
		wxMenuItem* MenuItem23;
		wxMenu menu_project_filter;
		wxMenuItem* MenuItem_Review;
		wxMenuItem* mi_print_label;
		wxMenuItem* MenuItem_Basic_Info;
		wxMenuItem* mi_search_contract;
		wxMenuItem* MenuItem21;
		wxMenuItem* mi_contract_br_search;
		wxMenuItem* MenuItem16;
		wxMenuItem* mi_Excel_export;
		wxMenuItem* mi_mc2_h;
		wxMenuItem* MenuItem9;
		wxButton* button_cancel_restart;
		wxMenuItem* MenuItem18;
		wxMenuItem* mi_generate_contract;
		wxButton* Button_syc_to_din;
		wxMenuItem* MenuItem19;
		//*)
        wxMenuItem* MenuItem20;

		bool b_refresh;
		void init_list_header();
		void Set_Where_clause(wxString _where)
		{
		    whereClause = _where;
		}

        void refresh_project_list(wxPostgreSQLresult *_res);
		void refresh_list(bool b_attach=false);

		bool update_basic_finish_status(wxString s_wbs, bool _status=false);

		int check_same_lift_no(wxString s_project_id,wxString s_lift_no);
/*
		void set_sap_conn(Rfc_Communication * rfc_conn)
		{
		    sap_rfc_conn = rfc_conn;

		}*/

		int update_restart_status(wxString str_wbs, bool b_up);
		int update_cancel_status(wxString str_wbs);

		wxString str_unit_header;

		void Compress_array(wxPostgreSQLresult * res, wxArrayString & array_sel);
		bool update_nonstd_conf_date(wxString s_wbs, wxDateTime dt_temp);
		wxArrayString array_update_conf;
		void Show_control();
		wxString create_review_struct(wxString s_project,wxString s_res_cm, const wxArrayString &array_wbs, wxArrayString &array_task_units, wxArrayInt array_old_status,int i_urgent_level=1, wxString s_remarks=wxEmptyString, wxString s_qty=_("0"));

//		bool update_review_status(const wxString s_wbs_no, int i_status, wxString s_wf_status);
		bool update_review_units_status(wxString s_task_id, wxString s_unit, int i_status, int i_old_status, wxString s_wf_status, int i_restart_times=1);
        bool check_review_restart_status(wxString s_instance);
        bool update_review_units_latest(wxString s_units, bool b_latest = false);
        int get_restart_times(wxString s_wbs);

        void draw_label(wxDC&dc, int _page);


	protected:

		//(*Identifiers(instance_unit_info)
		static const long ID_LISTCTRL_PROJECT;
		static const long ID_BUTTON_START_REVIEW;
		static const long ID_BUTTON_START_CONFIGURE;
		static const long ID_BUTTON_RESTART;
		static const long ID_BUTTON_CANCEL_RESTART;
		static const long ID_BUTTON_CANCEL_PROJECT;
		static const long ID_BUTTON_RESTORE_PROJECT;
		static const long ID_BUTTON_DEL_PROJECT;
		static const long ID_BUTTON_IMPORT;
		static const long ID_BUTTON_SAP_BY_WBS;
		static const long ID_BUTTON_BY_INTERNAL_DATE;
		static const long ID_BUTTON_NSTD_SAP_UPDATE;
		static const long ID_BUTTON_BASIC_INFO;
		static const long ID_BUTTON_SYC_TO_DIN;
		static const long ID_BUTTON1;
		static const long ID_GRID_UNIT_INFO;
		static const long idMenu_SelAll;
		static const long idMenu_UnSel;
		static const long idMenu_MC2_H;
		static const long idMenu_export_xls;
		static const long idMenu_print_label;
		static const long idMenu_ReviewFlow;
		static const long idMenu_ProcFlow;
		static const long idMenu_Nstd_workflow;
		static const long idMenu_nstd_mat_maintain;
		static const long idMenu_nstd_design;
		static const long idMenu_nonstd_item;
		static const long idMenu_Weight;
		static const long idMenu_in_contract;
		static const long idMenu_hex;
		static const long idMenu_ReqDelv;
		static const long idMenu_ReqFin;
		static const long idMenu_PrjCata;
		static const long idMenu_Urgent;
		static const long idMenu_NonStd;
		static const long idMenu_special_Info;
		static const long idMenu_Update;
		static const long idMenu_unFreezed;
		static const long idMenu_CANRESTART;
		static const long idMenu_generate_contract;
		static const long idMenu_Search_contract;
		static const long idMenu_Contract_id;
		static const long idMenu_contract_br_search;
		static const long idMenu_ContractBook_Search;
		static const long idMenu_Change_Lender;
		static const long idMenu_All;
		static const long idMenu_NSTD_LEVEL;
		static const long idMenu_UnSt;
		static const long idMenu_Motion;
		static const long idMenu_Finish;
		static const long idMenu_Closed;
		static const long idMenu_InDoc;
		static const long idMenu_Freeze;
		static const long idMenu_Cancel;
		static const long idMenu_contract_id;
		static const long idMenu_Prj;
		static const long idMenu_Wbs;
		static const long idMenu_Project_name;
		static const long idMenu_delivery_date;
		static const long idMenu_delv_mc2_h;
		static const long idMenu_Filt_basic_info;
		static const long idMenu_syc_din_units;
		//*)


	private:

		//(*Handlers(instance_unit_info)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void OnButton4Click(wxCommandEvent& event);
		void Onlc_projectItemRClick(wxListEvent& event);
		void Ongd_unit_infoCellRightClick(wxGridEvent& event);
		void OnMenuItem1Selected(wxCommandEvent& event);
		void OnMenuItem2Selected(wxCommandEvent& event);
		void OnMenuItem10Selected(wxCommandEvent& event);
		void OnMenuItem9Selected(wxCommandEvent& event);
		void OnMenuItem11Selected(wxCommandEvent& event);
		void OnMenuItem13Selected(wxCommandEvent& event);
		void OnMenuItem14Selected(wxCommandEvent& event);
		void OnMenuItem3Selected(wxCommandEvent& event);
		void OnMenuItem4Selected(wxCommandEvent& event);
		void OnMenuItem5Selected(wxCommandEvent& event);
		void Onlc_projectItemActivated(wxListEvent& event);
		void OnMenuItem15Selected(wxCommandEvent& event);
		void OnMenuItem17Selected(wxCommandEvent& event);
		void OnMenuItem12Selected(wxCommandEvent& event);
		void OnMenuItem18Selected(wxCommandEvent& event);
		void OnMenuItem6Selected(wxCommandEvent& event);
		void OnMenuItem7Selected(wxCommandEvent& event);
		void OnMenuItem8Selected(wxCommandEvent& event);
		void Onlc_projectBeginDrag(wxListEvent& event);
		void OnMenuItem19Selected(wxCommandEvent& event);
		void OnMenuItem16Selected(wxCommandEvent& event);
		void OnMenuItem20Selected(wxCommandEvent& event);
		void OnButton5Click(wxCommandEvent& event);
		void Onbutton_cancel_restartClick(wxCommandEvent& event);
		void OnMenuItem21Selected(wxCommandEvent& event);
		void OnMenuItem22Selected(wxCommandEvent& event);
		void OnMenuItem23Selected(wxCommandEvent& event);
		void OnMenuItem24Selected(wxCommandEvent& event);
		void OnButton_Cancel_projectClick(wxCommandEvent& event);
		void OnButton_Restore_projectClick(wxCommandEvent& event);
		void OnButton_DEL_projectClick(wxCommandEvent& event);
		void OnMenuItem25Selected(wxCommandEvent& event);
		void OnMenuItem_ReviewSelected(wxCommandEvent& event);
		void OnButton_NSTD_SAP_UPDATEClick(wxCommandEvent& event);
		void OnMenuItem26Selected(wxCommandEvent& event);
		void Onbutton_sap_by_wbsClick(wxCommandEvent& event);
		void Onbutton_sap_by_internalClick(wxCommandEvent& event);
		void OnMenuItem_WeightSelected(wxCommandEvent& event);
		void OnMenuItem_Basic_InfoSelected(wxCommandEvent& event);
		void OnButton_Cal_Basic_InfoClick(wxCommandEvent& event);
		void Onmi_contractSelected(wxCommandEvent& event);
		void Onmi_unit_in_contractSelected(wxCommandEvent& event);
		void Onmi_generate_contractSelected(wxCommandEvent& event);
		void Onmi_search_contractSelected(wxCommandEvent& event);
		void Onmi_add_contract_idSelected(wxCommandEvent& event);
		void Onmi_hexSelected(wxCommandEvent& event);
		void Onmi_delivery_dateSelected(wxCommandEvent& event);
		void Onmi_Excel_exportSelected(wxCommandEvent& event);
		void OnButton_syc_to_dinClick(wxCommandEvent& event);
		void Onmi_syc_dinSelected(wxCommandEvent& event);
		void Onmi_print_labelSelected(wxCommandEvent& event);
		void Onmi_contractbook_searchSelected(wxCommandEvent& event);
		void Onmi_change_lenderSelected(wxCommandEvent& event);
		void Onmi_contract_br_searchSelected(wxCommandEvent& event);
		void Onmi_proj_nameSelected(wxCommandEvent& event);
		void Onmi_special_infoSelected(wxCommandEvent& event);
		void Onmi_mc2_hSelected(wxCommandEvent& event);
		void Onmi_delv_mc2_hSelected(wxCommandEvent& event);
		//*)

		int get_same_project_count(wxString s_project, const wxArrayString s_unit_list);
		bool update_nstd_level(wxString s_wbs, int old_status, int new_status);
		bool refresh_nstd_level(wxString s_wbs, bool b_sap_update=true);
		wxString get_prj_res_person(wxString s_proj_id);
		bool check_g4_group(wxString s_wbs);

		int get_review_status(wxString s_wbs);

		void Create_Folder(wxArrayString a_wbs);
		bool update_contract_book_status(wxString s_wbs, int i_status);
		wxString get_full_prj_info(wxString s_prj);

		wxString m_query;
		wxString whereClause;

		wxArrayString print_array;

		int m_rows;
		bool b_refresh_project;

		bool update_operator(wxString s_task_id, wxString s_operator_id); //更新评审工作流第一步负责人
        void save_file(wxString s_file);

//		Rfc_Communication * sap_rfc_conn;

 //       bool b_sys_basic_info_mode;
		DECLARE_EVENT_TABLE()
};


class LabelPrintout: public wxPrintout
{
 public:
  LabelPrintout(const wxString& name = wxT("Printing"), instance_unit_info *_panel = NULL, int pages=0 );
  ~LabelPrintout();
  bool OnPrintPage(int page);
  bool HasPage(int page);
  bool OnBeginDocument(int startPage, int endPage);
  void GetPageInfo(int *minPage, int *maxPage, int *selPageFrom, int *selPageTo);

   void drawpage(wxDC&dc, int page);


 private:
     int m_NumPages;

     wxString m_Name;

     instance_unit_info *m_panel;

};


#endif
