#ifndef WORKFLOW_WF_H
#define WORKFLOW_WF_H

//(*Headers(workflow_wf)
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/button.h>
//*)

#include "ctrl/treelistctrl.h"
#include "utils/wf_operator.h"
#include <wx/imaglist.h>
#include "xlslib.h"
using namespace xlslib_core;

class workflow_wf: public wxPanel
{
	public:

		workflow_wf(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~workflow_wf();

		//(*Declarations(workflow_wf)
		wxMenuItem* mi_contractbook_br_search;
		wxMenuItem* MenuItem8;
		wxMenu menu_workflow_popup;
		wxMenuItem* MenuItem7;
		wxButton* Button4;
		wxMenuItem* MenuItem5;
		wxMenuItem* MenuItem2;
		wxButton* Button1;
		wxMenuItem* MenuItem1;
		wxMenu menu_worflow_group_popup;
		wxMenuItem* MenuItem4;
		wxButton* Button2;
		wxMenuItem* MenuItem3;
		wxButton* Button3;
		wxMenuItem* MenuItem6;
		wxMenuItem* MenuItem_WEIGHT;
		wxMenuItem* mi_cb_change;
		wxMenuItem* mi_export_tasks;
		//*)

        void refresh_list();
        void refresh_group(bool b_sh);
        wxArrayString get_wbs_list(int i_choice, wxString str_case);
		void BuildTreeListCtrl();
//        wxArrayString old_array, new_array;
        void set_show(bool b_sure)
        {
            b_show = b_sure;
        }


        wxcode::wxTreeListCtrl* tlc_task_list;
        wxcode::wxTreeListCtrl* tlc_group_task_list;
        int Copy();

        void InitImageList();
        wxImageList* m_imageList;
        void refresh_task_level();
        void refresh_group_level(bool b_sure);
        bool close_finished_nonstd(wxString s_wbs, wxString s_flag);
	protected:

		//(*Identifiers(workflow_wf)
		static const long ID_BUTTON_FEEDBACK;
		static const long ID_BUTTON_PASS;
		static const long ID_BUTTON_SHOWANDHIDE;
		static const long ID_BUTTON_REFRESH;
		static const long idMenu_Explain;
		static const long idMenu_nstd_level;
		static const long idMenu_lender_change;
		static const long idMenu_contractbook_search;
		static const long idMenu_Feedback;
		static const long idMenu_Status;
		static const long idMenu_SSearch;
		static const long idMenu_Nstd;
		static const long idMenu_MTList;
		static const long id_export_task_detail;
		static const long idMenu_Car_or_DC_weight;
		static const long idMenu_Res_Filter;
		//*)
		static const long ID_TREELISTCTRL_TASK_LIST ;
		static const long ID_TREELISTCTRL_GROUP_TASK_LIST ;

	private:

		//(*Handlers(workflow_wf)
		void OnButton3Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton4Click(wxCommandEvent& event);
		void On_task_list_RightClick(wxTreeEvent& event);
		void On_group_task_list_RightClick(wxTreeEvent& event);
		void OnMenuItem1Selected(wxCommandEvent& event);
		void OnMenuItem2Selected(wxCommandEvent& event);
		void OnMenuItem3Selected(wxCommandEvent& event);
		void OnMenuItem4Selected(wxCommandEvent& event);
		void OnKeyDown(wxTreeEvent& event);
		void OnMenuItem5Selected(wxCommandEvent& event);
		void OnMenuItem6Selected(wxCommandEvent& event);
		void OnMenuItem7Selected(wxCommandEvent& event);
		void OnMenuItem8Selected(wxCommandEvent& event);
		void OnMenuItem_WEIGHTSelected(wxCommandEvent& event);
		void Onmi_cb_changeSelected(wxCommandEvent& event);
		void Onmi_contractbook_br_searchSelected(wxCommandEvent& event);
		void Onmi_export_tasksSelected(wxCommandEvent& event);
		//*)

       bool make_evaluate(wf_process * s_process, wxString s_batch_id);

       bool check_other_way(wxString s_instance, wxString s_flag);
       wxArrayString get_other_way(wxString s_lift_type, wxString s_flag);

       wxStaticBox * sb_group_tasks;

       wxSizerItem * sizer_tasks;
       wxSizerItem * sizer_group_task;

       wxArrayString array_group, array_leader_group,array_worker;


       int m_rows;
       wxArrayString m_steps;

       wxArrayString get_steps_info(wxString &s_instance_id, wxString &s_workflow_id, wxString &s_now, wxString _flag=wxEmptyString);
       bool update_nstd_level(wxString s_wbs, int old_status, int new_status);

       bool check_prj_info_attach_finished(wxArrayString& a_wbs);

       bool b_show;

       bool check_contract_br_log(wxString s_wbs, wxString &s_cid);

       void export_excel(wxString s_wbs, worksheet* ws, int i_row);
       void write_head(worksheet* ws);

        wxString str_tasks_header, str_group_tasks_header;
		DECLARE_EVENT_TABLE()
};

#endif
