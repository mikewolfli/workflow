#ifndef PROJECT_INFO_PANEL_H
#define PROJECT_INFO_PANEL_H

//(*Headers(project_info_panel)
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/choice.h>
#include <wx/button.h>
//*)
#include "ctrl/treelistctrl.h"
#include <wx/imaglist.h>
#include "utils/wf_operator.h"
#include "xlslib.h"

using namespace xlslib_core;
#define RECORDCOUNT                65536


class project_info_panel: public wxPanel
{
	public:

		project_info_panel(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~project_info_panel();


		void InitImageList();

		//(*Declarations(project_info_panel)
		wxButton* Button4;
		wxMenuItem* mi_special;
		wxChoice* choice_status;
		wxButton* Button1;
		wxMenuItem* mi_cm_res;
		wxMenuItem* mi_process;
		wxMenuItem* mi_urgent;
		wxMenuItem* MenuItem1;
		wxMenuItem* mi_remarks;
		wxButton* Button2;
		wxChoice* choice_action;
		wxMenu menu_review_info;
		wxMenuItem* MenuItem3;
		wxButton* Button3;
		wxButton* Button_Feedback;
		wxMenuItem* mi_author;
		wxMenuItem* mi_common;
		wxMenuItem* mi_pos_contract;
		wxMenuItem* mi_start;
		//*)
		wxcode::wxTreeListCtrl* tlc_task_list;
		wxTreeItemId m_pos_id;
		wxString m_search_case;

		void BuildDataViewCtrl();
        void refresh_list();
		void refresh_level();

		void set_treelist_item_color(wxTreeItemId i_id, int i_temp);
		void set_clause(wxString l_clause)
		{
		    cl_clause = l_clause;
		}

		void set_clause1(wxString l_clause)
		{
		    cl_clause1 = l_clause;
		}

//		bool update_review_status(const wxString s_wbs_no, int i_status, wxString s_wf_status);
		bool update_review_units_status(const wxString s_task_id, const wxString s_wbs_no, int i_status, wxString s_wf_status, int i_restart_times=1);

	protected:

		//(*Identifiers(project_info_panel)
		static const long ID_BUTTON_FEEDBACK;
		static const long ID_BUTTON2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON_GAD_REVISED;
		static const long ID_BUTTON3;
		static const long ID_CHOICE_STATUS;
		static const long ID_CHOICE_ACTION;
		static const long idMenu_communication_log;
		static const long idMenu_Return_info;
		static const long idMenu_process;
		static const long idMenu_Change_res;
		static const long idMenu_common;
		static const long idMenu_Urgent;
		static const long idMenu_Special;
		static const long idMenu_remarks;
		static const long idMenu_pos_contract;
		static const long idMenu_export_start;
		static const long idMenu_Review_date;
		//*)
		static const long ID_TREELISTCTRL_TASK_LIST ;


	private:

		//(*Handlers(project_info_panel)
		void OnButton_FeedbackClick(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void Onchoice_statusSelect(wxCommandEvent& event);
		void OnButton4Click(wxCommandEvent& event);
		void OnMenuItem1Selected(wxCommandEvent& event);
		void OnMenuItem3Selected(wxCommandEvent& event);
		void Onmi_smart_posSelected(wxCommandEvent& event);
		void Onchoice_actionSelect(wxCommandEvent& event);
		void Onmi_commonSelected(wxCommandEvent& event);
		void Onmi_urgentSelected(wxCommandEvent& event);
		void Onmi_specialSelected(wxCommandEvent& event);
		void Onmi_remarksSelected(wxCommandEvent& event);
		void Onmi_processSelected(wxCommandEvent& event);
		//		void Onmi_pos_wbsSelected(wxCommandEvent& event);
		void Onmi_cm_resSelected(wxCommandEvent& event);
		void Onmi_startSelected(wxCommandEvent& event);
		void Onmi_authorSelected(wxCommandEvent& event);
		//*)

		void OnChar(wxTreeEvent& event);
		void OnTreeListCtrlRightClick(wxTreeEvent& event);

		wxString cl_clause;
		wxString cl_clause1;
		wxImageList* m_imageList;

		 int  m_report;


		bool update_communication(wxString s_task_id, wxString &s_status, wxString s_content);
		int update_unit_status(wxString s_wbs);//
        wxString create_review_header(wxString s_res_cm, wxString s_remarks=wxEmptyString, wxString s_qty=_("0"));
        bool create_review_units(wxString s_wbs, wxString s_task_id, int i_old_status, int i_urgent_level);
        int get_same_project_count(wxString s_project, wxArrayString a_wbs);
        int get_restart_times(wxString s_wbs);
        wxString update_issue_context(int i_status, wxString str);
        bool check_subitem_status(wxTreeItemId &i_item);
        wxArrayString array_excel_head;
        void init_excel_head();
        void save_file(wxString s_path, wxPostgreSQLresult* _res);

       int Copy();

        int update_urgent_level(wxString s_task_id, wxString s_wbs, int i_old_level, int i_new_level,wxString s_action_id);

		DECLARE_EVENT_TABLE()
};

#endif
