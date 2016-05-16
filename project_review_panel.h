#ifndef PROJECT_REVIEW_PANEL_H
#define PROJECT_REVIEW_PANEL_H

//(*Headers(project_review_panel)
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/button.h>
//*)

#include "ctrl/treelistctrl.h"

class project_review_panel: public wxPanel
{
	public:

		project_review_panel(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~project_review_panel();

		//(*Declarations(project_review_panel)
		wxButton* Button_Finish;
		wxMenu menu_review_log;
		wxMenuItem* mi_process;
		wxButton* Button_Communication;
		wxMenuItem* mi_review_history;
		wxButton* Button_Return;
		wxMenuItem* mi_pos;
		wxButton* Button_Refresh;
		wxMenuItem* mi_com_log;
		//*)

		void refresh_list();
        void InitImageList();

		void set_clause(wxString l_clause)
		{
		    cl_clause = l_clause;
		}

//		bool update_review_status(const wxArrayString &array_units, int i_status, wxString s_wf_status);
        bool update_review_units_status(const wxString s_task_id, const wxString s_wbs_no, int i_status, wxString s_wf_status);
        bool update_review_task(const wxString s_task_id, int i_status);

	protected:

		//(*Identifiers(project_review_panel)
		static const long ID_BUTTON4;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long idMenu_process;
		static const long idMenu_restart_log;
		static const long idMenu_Communication_log;
		static const long idMenu_pos;
		//*)
		static const long ID_TREELISTCTRL_TASK_LIST ;

	private:

		//(*Handlers(project_review_panel)
		void OnButton_RefreshClick(wxCommandEvent& event);
		void OnButton_CommunicationClick(wxCommandEvent& event);
		void OnButton_FinishClick(wxCommandEvent& event);
		void OnButton_ReturnClick(wxCommandEvent& event);
		void Onmi_com_logSelected(wxCommandEvent& event);
		void Onmi_processSelected(wxCommandEvent& event);
		void Onmi_review_historySelected(wxCommandEvent& event);
		void Onmi_posSelected(wxCommandEvent& event);
		//*)
		void OnChar(wxTreeEvent& event);

		wxcode::wxTreeListCtrl* tlc_task_list;
		void OnTreeListCtrlRightClick(wxTreeEvent& event);

        wxTreeItemId m_pos_id;
		wxString m_search_case;

		wxString compare_time(wxString str1, wxString str2, bool b_ser=false);
		void BuildDataViewCtrl();
		void refresh_level();
        void set_treelist_item_color(wxTreeItemId i_id, int i_temp);
        wxString get_operator_from_branch(wxString s_branch_id, wxString s_group_id);

		wxArrayString get_steps_info(wxString &s_instance_id, wxString &s_workflow_id, wxString &s_now);
		wxArrayString m_steps;
		wxString update_issue_context(int i_status, wxString str);

		bool b_no_check;
		bool is_no_check();

		wxString cl_clause;
        wxImageList* m_imageList;

		bool create_communication(wxString s_task_id, wxString &s_status, wxString &s_context, bool b_close = false);

		DECLARE_EVENT_TABLE()
};

#endif
