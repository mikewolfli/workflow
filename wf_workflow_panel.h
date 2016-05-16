#ifndef WF_WORKFLOW_PANEL_H
#define WF_WORKFLOW_PANEL_H

//(*Headers(wf_workflow_panel)
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/grid.h>
#include <wx/button.h>
//*)

#include "interface/sqlresulttable.h"
#include "utils/wf_operator.h"

class wf_workflow_panel: public wxPanel
{
	public:

		wf_workflow_panel(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~wf_workflow_panel();

		//(*Declarations(wf_workflow_panel)
		wxMenuItem* MenuItem_RETURN;
		wxButton* Button4;
		wxMenuItem* MenuItem5;
		wxMenuItem* MenuItem2;
		wxMenuItem* MenuItem_REMARKS;
		wxButton* Button1;
		wxMenuItem* MenuItem1;
		wxButton* Button_DISPLAY;
		wxMenuItem* MenuItem4;
		wxMenu menu_group;
		wxButton* Button2;
		wxMenuItem* MenuItem3;
		sqlResultGrid* gd_group_task_list;
		wxButton* Button3;
		wxMenuItem* MenuItem6;
		wxMenu menu_attach;
		wxMenuItem* MenuItem_WORKFLOW;
		sqlResultGrid* gd_task_list;
		//*)

        void refresh_list();
        void refresh_group(bool b_sh);
		void init_list_header();
		bool update_operator(wxString s_operator, wxString s_instance);

		wxArrayString get_unit_list(wxString str_task_id, wxString str_workflow);

        void set_show(bool b_sure)
        {
            b_show = b_sure;
        }

	protected:

		//(*Identifiers(wf_workflow_panel)
		static const long ID_BUTTON_FEEDBACK;
		static const long ID_BUTTON_PASS;
		static const long ID_BUTTON_HIDE;
		static const long ID_BUTTON_DISPLAY_TASKS;
		static const long ID_BUTTON_REFRESH;
		static const long ID_GRID_TASK;
		static const long ID_GRID_GROUP;
		static const long idMenu_REMARKS;
		static const long idMenu_Units;
		static const long IdMenu_MAT_INFO;
		static const long idMenu_RETURN;
		static const long idMenu_WORKFLOW;
		static const long idMenu_Nonstd_draw_require;
		static const long idMenu_Group_Filter;
		static const long idMenu_Date_filter;
		static const long idMenu_task_tree;
		//*)

	private:

		//(*Handlers(wf_workflow_panel)
		void OnButton2Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void OnButton4Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void Ongd_task_listCellRightClick(wxGridEvent& event);
		void Ongd_group_task_listCellRightClick(wxGridEvent& event);
		void OnMenuItem1Selected(wxCommandEvent& event);
		void OnMenuItem_REMARKSSelected(wxCommandEvent& event);
		void OnMenuItem_RETURNSelected(wxCommandEvent& event);
		void OnMenuItem_WORKFLOWSelected(wxCommandEvent& event);
		void OnMenuItem2Selected(wxCommandEvent& event);
		void OnMenuItem3Selected(wxCommandEvent& event);
		void OnMenuItem4Selected(wxCommandEvent& event);
		void OnMenuItem5Selected(wxCommandEvent& event);
		void OnMenuItem6Selected(wxCommandEvent& event);
		void OnButton_DISPLAYClick(wxCommandEvent& event);
		//*)

		bool make_evaluate(wf_process * s_process);
		bool check_sub_task(wxString s_instance);
		bool update_require_drawing(wxString s_task_id, wxString s_date);

       wxStaticBox * sb_group_tasks;
       wxStaticBox * sb_tasks;

       wxSizerItem * sizer_tasks;
       wxSizerItem * sizer_group_task;

       wxArrayString array_group, array_leader_group;


       int m_rows;

       bool b_show,b_task_show;
       wxArrayString m_steps;
       wxArrayString get_steps_info(wxString &s_instance_id, wxString &s_workflow_id, wxString &s_now);

        wxString str_tasks_header, str_group_tasks_header;

		DECLARE_EVENT_TABLE()
};

#endif
