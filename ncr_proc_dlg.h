#ifndef NCR_PROC_DLG_H
#define NCR_PROC_DLG_H

//(*Headers(ncr_proc_dlg)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/gbsizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/combobox.h>
//*)

#include "interface/wxPostgreSQL.h"

class ncr_proc_dlg: public wxDialog
{
	public:

		ncr_proc_dlg(int _mode, wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ncr_proc_dlg();

		//(*Declarations(ncr_proc_dlg)
		wxStaticText* st_res_bco;
		wxTextCtrl* tc_issue_desc;
		wxButton* Button_cancel;
		wxStaticText* st_res_peron;
		wxButton* Button_save;
		wxStaticText* st_publisher;
		wxStaticText* StaticText2;
		wxStaticText* StaticText6;
		wxTextCtrl* tc_content;
		wxButton* Button_proj;
		wxStaticText* StaticText8;
		wxTextCtrl* tc_fileindex;
		wxTextCtrl* tc_res_eng;
		wxButton* Button_close;
		wxStaticText* StaticText1;
		wxTextCtrl* tc_issue_head;
		wxStaticText* StaticText3;
		wxStaticText* st_status;
		wxTextCtrl* tc_feedback_date;
		wxTextCtrl* tc_fetch_date;
		wxTextCtrl* tc_publisher;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxTextCtrl* tc_status;
		wxStaticText* st_result;
		wxTextCtrl* tc_lift_no;
		wxTextCtrl* tc_ncrid;
		wxTextCtrl* tc_rel_proj;
		wxComboBox* cb_fromdep;
		wxChoice* Choice_group;
		wxStaticText* st_response;
		wxTextCtrl* tc_res_person;
		wxTextCtrl* tc_res_bco;
		wxTextCtrl* tc_publish_date;
		wxButton* Button_release;
		wxTextCtrl* tc_result;
		wxStaticText* st_feedback_content;
		wxStaticText* StaticText4;
		wxStaticText* st_feedback_date;
		wxTextCtrl* tc_unit_qty;
		//*)

		//参数列表
		wxString m_id;
        wxString m_ncr_id;
        wxString m_rel_wbs;
        wxString m_res_project;
        wxArrayString array_wbs;
        wxString m_lift_no;
        wxString m_file_index;
        wxString m_from_dep;
        wxString m_issue_desc;
        wxString m_issue_head;
        int m_lift_qty;
        int m_status;
        wxString m_res_by;
        wxString m_publish_by;
        wxString m_publish_date;
        wxString m_res_group;
        wxString m_fetch_date;
        wxString m_res_bco;
        wxString m_fb_content;
        wxString m_fb_date;
        wxString m_issue_res;
        wxString m_issue_result;
        wxArrayString array_group;
        wxArrayString array_group_name;
        void init_ctrl_value();


	protected:

		//(*Identifiers(ncr_proc_dlg)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL_NCRID;
		static const long ID_STATICTEXT2;
		static const long ID_COMBOBOX_FROM;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL_FILEINDEX;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL_REL_PROJECT;
		static const long ID_BUTTON_PROJ;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL_ISSUE_HEAD;
		static const long ID_STATICTEXT6;
		static const long ID_TEXTCTRL_UNIT_QTY;
		static const long ID_TEXTCTRL_LIFT_NO;
		static const long ID_STATICTEXT7;
		static const long ID_TEXTCTRL_ISSUE_DESC;
		static const long ID_STATICTEXT_STATUS;
		static const long ID_TEXTCTRL_PUBLISH_DATE;
		static const long ID_STATICTEXT_PUBLISHER;
		static const long ID_TEXTCTRL_PUBLISHER;
		static const long ID_TEXTCTRL_STATUS;
		static const long ID_STATICTEXT8;
		static const long ID_CHOICE_GROUP;
		static const long ID_STATICTEXT_RESPONSE;
		static const long ID_TEXTCTRL_FETCH_DATE;
		static const long ID_TEXTCTRL_RES;
		static const long ID_STATICTEXT_RES_BCO;
		static const long ID_TEXTCTRL_RES_BCO;
		static const long ID_STATICTEXT_FEEDBACK_DATE;
		static const long ID_TEXTCTRL_FEEDBACK_DATE;
		static const long ID_STATICTEXT_FEEDBACK_CONTENT;
		static const long ID_TEXTCTRL_FEEDBACK_CONTENT;
		static const long ID_STATICTEXT_RES_PERSON;
		static const long ID_TEXTCTRL_RES_PERON;
		static const long ID_STATICTEXT_RESULT;
		static const long ID_TEXTCTRL_RESULT;
		static const long ID_BUTTON_SAVE;
		static const long ID_BUTTON_RELEASE;
		static const long ID_BUTTON_CLOSE;
		static const long ID_BUTTON_CANCEL;
		//*)

	private:

		//(*Handlers(ncr_proc_dlg)
		void OnButton_cancelClick(wxCommandEvent& event);
		void OnButton_closeClick(wxCommandEvent& event);
		void OnButton_saveClick(wxCommandEvent& event);
		void OnButton_releaseClick(wxCommandEvent& event);
		void OnButton_projClick(wxCommandEvent& event);
		//*)

		int m_mode;
		void show_control();
		wxString m_prj_head;

		wxString parse_rel_project(wxString s_wbs);
		wxString get_project_info(wxArrayString &a_wbs);
		bool get_ncr_group(wxArrayString &a_group_id, wxArrayString &a_group_name);
		bool update_ncr_data();
		bool update_ncr_data_ex();
		void get_data();

		void init_res_group();

		DECLARE_EVENT_TABLE()
};

#endif
