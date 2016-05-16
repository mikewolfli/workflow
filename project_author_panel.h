#ifndef PROJECT_AUTHOR_PANEL_H
#define PROJECT_AUTHOR_PANEL_H

//(*Headers(project_author_panel)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/button.h>
//*)

#include "ctrl/treelistctrl.h"
#include <wx/imaglist.h>

class project_author_panel: public wxPanel
{
	public:

		project_author_panel(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~project_author_panel();

		//(*Declarations(project_author_panel)
		wxMenuItem* MenuItem8;
		wxButton* Button_Nstd_level;
		wxMenuItem* MenuItem7;
		wxButton* Button4;
		wxMenuItem* MenuItem5;
		wxMenuItem* MenuItem2;
		wxButton* Button1;
		wxMenuItem* MenuItem1;
		wxMenuItem* MenuItem4;
		wxButton* Button2;
		wxMenuItem* MenuItem3;
		wxButton* Button_Review;
		wxButton* Button3;
		wxMenuItem* MenuItem6;
		wxListCtrl* lc_res;
		wxMenu menu_authority;
		wxMenuItem* mi_review;
		//*)
		wxcode::wxTreeListCtrl* tlc_proj_list;

		void BuildDataViewCtrl();
		void init_list_header();
		void refresh_list();
		void refresh_res_list();

		void refresh_new_res_list(wxString s_group);


		void Set_Clause(wxString strquery)
		{
		    where_clause = strquery;
		}


		void InitImageList();

 //       wxArrayString old_array, new_array;

 //       wxArrayString get_array();
        int m_case ;//0 ：默认，只读取未分配的任务， 1： 已经分配的任务：2 -待审核的任务
        wxString str_freeze;
	protected:

		//(*Identifiers(project_author_panel)
		static const long ID_BUTTON1;
		static const long ID_BUTTON_REVIEW;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_BUTTON_NSTD_LEVEL;
		static const long ID_BUTTON2;
		static const long ID_LISTCTRL_RESPERSON;
		static const long idMenu_Expand;
		static const long idMenu_Collapse;
		static const long idMenu_Un;
		static const long idMenu_Au;
		static const long idMenu_Review;
		static const long idMenu_Freeze;
		static const long idMenu_History;
		static const long idMenu_Same;
		static const long idMenu_all;
		//*)
		static const long ID_TREELISTCTRL_PROJ_LIST ;

	private:

		//(*Handlers(project_author_panel)
		void OnButton1Click(wxCommandEvent& event);
		void OnPaint(wxPaintEvent& event);
		void OnMenuItem1Selected(wxCommandEvent& event);
		void OnMenuItem2Selected(wxCommandEvent& event);
		void OnMenuItem3Selected(wxCommandEvent& event);
		void OnMenuItem4Selected(wxCommandEvent& event);
		void OnMenuItem5Selected(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void Onlc_resItemActivated(wxListEvent& event);
		void OnButton_SAVEClick(wxCommandEvent& event);
		void OnMenuItem6Selected(wxCommandEvent& event);
		void OnMenuItem7Selected(wxCommandEvent& event);
		void OnMenuItem8Selected(wxCommandEvent& event);
		void OnButton_Nstd_levelClick(wxCommandEvent& event);
		void OnButton4Click(wxCommandEvent& event);
		void Onmi_reviewSelected(wxCommandEvent& event);
		void OnButton_ReviewClick(wxCommandEvent& event);
		//*)
		void OnTreeListCtrlRightClick(wxTreeEvent& event);
		bool update_nonstd_conf_date(wxString s_wbs, wxDateTime dt_temp);
		wxArrayString array_update_conf;
		wxArrayString get_same_in_process(wxArrayString &array_prj, wxArrayString &array_now_wbs);


//        wxObjectDataPtr<MyProjectTreeModel> m_project_model;//replace wxdataviewctrl with wxtreelistctrl

        // other data:

        void create_nstd_task(wxArrayString & a_wbs, wxArrayString &a_lift_type, wxArrayString &a_catalog, wxArrayString &a_mat_req,wxString s_item_catalog, wxString s_responsor);

        void save_header(wxString s_nstd_app_id,wxString s_link_list);
        void save_item(wxString s_nstd_app_id,wxString s_link_list, wxString s_item_catalog, wxString s_responsor);

        wxImageList* m_imageList;
        void refresh_project_level();
        bool build_batch_id(wxString &batch_id, wxString &str_wbs);
        bool update_nstd_level(wxString s_wbs, int old_status, int new_status);

        bool update_unit_nstd_id(wxString s_wbs, wxString s_nstd_id, wxString s_flag);
        bool update_unit_nstd_status(wxString s_wbs, int i_status, wxString s_flag);

       bool check_other_way(wxString s_instance, wxString s_flag);
       wxArrayString get_other_way(wxString s_lift_type, wxString s_flag);

        wxString where_clause;

        wxString m_group;
        bool m_leader;


		DECLARE_EVENT_TABLE()
};

#endif
