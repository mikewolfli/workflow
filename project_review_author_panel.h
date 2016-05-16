#ifndef PROJECT_REVIEW_AUTHOR_PANEL_H
#define PROJECT_REVIEW_AUTHOR_PANEL_H

//(*Headers(project_review_author_panel)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/gbsizer.h>
#include <wx/button.h>
//*)
#include "ctrl/treelistctrl.h"

class project_review_author_panel: public wxPanel
{
	public:

		project_review_author_panel(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~project_review_author_panel();

		//(*Declarations(project_review_author_panel)
		wxMenuItem* mi_showall;
		wxMenuItem* mi_filter;
		wxButton* Button_return_to_start;
		wxMenu menu_filter;
		wxButton* Button_Require;
		wxMenuItem* mi_group_com_log;
		wxMenuItem* mi_process;
		wxButton* button_group;
		wxMenuItem* mi_group_review_history;
		wxMenu menu_check;
		wxButton* Button_Draw_qty;
		wxMenuItem* mi_cancel_no_check;
		wxMenuItem* mi_collapse;
		wxButton* Button_RETURN;
		wxMenuItem* mi_group_pos;
		wxButton* Button_Feedback;
		wxButton* Button_Author;
		wxButton* Button_REFRESH;
		wxMenuItem* mi_no_check;
		wxMenuItem* mi_show_author;
		wxMenuItem* mi_group_process;
		wxMenuItem* mi_pos;
		wxMenuItem* mi_history;
		wxMenuItem* mi_check;
		wxMenuItem* mi_expand;
		wxMenuItem* mi_review;
		wxListView* lv_person;
		wxMenu menu_author;
		wxMenuItem* mi_com_log;
		wxMenuItem* mi_show_all;
		//*)
        void InitImageList();

        void refresh_list();
        void refresh_group_list();

		void set_clause(wxString l_clause)
		{
		    cl_clause = l_clause;
		}

		void set_group_clause(wxString l_clause)
		{
		    cl_group_clause = l_clause;
		}

//		bool update_review_status(const wxArrayString &array_units, int i_status, wxString s_wf_status);
        bool update_review_units_status(const wxString s_task_id, const wxString s_wbs_no, int i_status, wxString s_wf_status);

	protected:

		//(*Identifiers(project_review_author_panel)
		static const long ID_BUTTON_AUTHOR;
		static const long ID_BUTTON_REUEIRE_FINISH;
		static const long ID_BUTTON_DRAW_QTY;
		static const long ID_BUTTON_RETURN;
		static const long ID_BUTTON_RETURN_TO_START;
		static const long ID_BUTTON_FEEDBACK;
		static const long ID_BUTTON_REFRESH;
		static const long ID_BUTTON_GROUP;
		static const long ID_LISTVIEW_PERSON;
		static const long idMenu_Expand;
		static const long idMenu_Collapse;
		static const long idMenu_All;
		static const long idMenu_Author;
		static const long idMenu_Review;
		static const long idMenu_Check;
		static const long idMenu_review;
		static const long idMenu_restart_history;
		static const long idMenu_com_log;
		static const long idMenu_pos;
		static const long idMenu_NoCheck;
		static const long idMenu_Cancel;
		static const long idMenu_filter;
		static const long idMenu_show_all;
		static const long idMenu_group_review;
		static const long idMenu_group_restart_his;
		static const long idMenu_group_com_log;
		static const long idMenu_group_pos;
		//*)
		static const long ID_TREELISTCTRL_TASK_LIST ;
		static const long ID_TREELISTCTRL_GROUP_TASK_LIST ;

	private:

		//(*Handlers(project_review_author_panel)
		void OnButton_AuthorClick(wxCommandEvent& event);
		void OnButton_RETURNClick(wxCommandEvent& event);
		void OnButton_REFRESHClick(wxCommandEvent& event);
		void Onlv_personItemRClick(wxListEvent& event);
		void Onmi_expandSelected(wxCommandEvent& event);
		void Onmi_collapseSelected(wxCommandEvent& event);
		void Onmi_show_allSelected(wxCommandEvent& event);
		void Onmi_show_authorSelected(wxCommandEvent& event);
		void Onmi_reviewSelected(wxCommandEvent& event);
		void Onmi_checkSelected(wxCommandEvent& event);
		void Onmi_no_checkSelected(wxCommandEvent& event);
		void Onmi_cancel_no_checkSelected(wxCommandEvent& event);
		void Onmi_filterSelected(wxCommandEvent& event);
		void Onlv_personItemActivated(wxListEvent& event);
		void Onbutton_groupClick(wxCommandEvent& event);
		void OnButton_FeedbackClick(wxCommandEvent& event);
		void OnButton_RequireClick(wxCommandEvent& event);
		void OnButton_Draw_qtyClick(wxCommandEvent& event);
		void OnButton_return_to_startClick(wxCommandEvent& event);
		void Onmi_com_logSelected(wxCommandEvent& event);
		void Onmi_group_com_logSelected(wxCommandEvent& event);
		void Onmi_showallSelected(wxCommandEvent& event);
		void Onmi_processSelected(wxCommandEvent& event);
		void Onmi_historySelected(wxCommandEvent& event);
		void Onmi_posSelected(wxCommandEvent& event);
		void Onmi_group_processSelected(wxCommandEvent& event);
		void Onmi_group_review_historySelected(wxCommandEvent& event);
		void Onmi_group_posSelected(wxCommandEvent& event);
		//*)

		void OnTaskListRightClick(wxTreeEvent& event);
		void OnGroupTaskListRightClick(wxTreeEvent& event);
		void OnChar(wxTreeEvent& event);

        wxcode::wxTreeListCtrl* tlc_task_list;
		wxcode::wxTreeListCtrl* tlc_group_task_list;

        wxTreeItemId m_pos_id;
		wxString m_search_case;

        wxTreeItemId m_pos_id_group;
		wxString m_search_case_group;


		void BuildDataViewCtrl();
		void init_list_header();
		void refresh_res_list();
		wxString update_res_list(wxString s_operator);
		void refresh_level();
		void refresh_group_level();
		bool update_review_task(const wxString s_task_id, int i_status);

		wxString compare_time(wxString str1, wxString str2, bool b_ser=false);

		void set_treelist_item_color(wxTreeItemId i_id, int i_temp);

		bool update_require_review_finish(wxString s_task_id, wxString s_date);

		wxString get_operator_from_branch(wxString s_branch_id, wxString s_group_id);

		bool update_review_engineer(wxString s_engineer, wxString s_task_id);

		bool update_drawing_qty(wxString s_task_id, wxString s_drawing_qty);

		bool check_review_restart_status(wxString s_instance, int &i_times, int &i_old_status,int &i_status);
		bool cancel_review_workflow(wxString s_task_id, wxString s_instance, int i_old_status, int i_times);
		bool close_cancel_review_task(wxString s_task_id);

		wxArrayString get_steps_info(wxString &s_instance_id, wxString &s_workflow_id, wxString &s_now);
		wxArrayString m_steps;

		wxString update_issue_context(int i_status, wxString str);


		wxString cl_clause, cl_group_clause;


        wxImageList* m_imageList;

		bool create_communication(wxString s_task_id, wxString &s_status, wxString &s_context, bool b_close = false);

		DECLARE_EVENT_TABLE()
};

#endif
