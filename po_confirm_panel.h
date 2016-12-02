#ifndef PO_CONFIRM_PANEL_H
#define PO_CONFIRM_PANEL_H

//(*Headers(po_confirm_panel)
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/button.h>
//*)

#include "ctrl/treelistctrl.h"

class po_confirm_panel: public wxPanel
{
	public:

		po_confirm_panel(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~po_confirm_panel();

		//(*Declarations(po_confirm_panel)
		wxButton* Button_Change;
		wxMenu menu_filter;
		wxMenuItem* MenuItem2;
		wxMenuItem* MenuItem1;
		wxButton* Button_Confirm2;
		wxMenuItem* mi_private;
		wxMenuItem* mi_all;
		wxButton* button_task_change;
		wxButton* Button_Filter;
		wxMenu menu_offline_PO;
		wxButton* Button_pos;
		wxButton* Button_Return1;
		wxButton* Button_Spec2;
		wxButton* Button_Return2;
		wxButton* Button_Refresh;
		wxButton* Button_Confirm1;
		//*)

		void refresh_list1();
		void refresh_list2();
        void InitImageList();

		void set_clause1(wxString l_clause)
		{
		    cl_clause1 = l_clause;
		}

        void set_clause2(wxString l_clause)
		{
		    cl_clause2 = l_clause;
		}

//		bool update_review_status(const wxArrayString &array_units, int i_status, wxString s_wf_status);
        bool update_review_units_status(const wxString s_task_id, const wxString s_wbs_no, int i_status, wxString s_wf_status);
        bool update_can_psn(wxString s_task_id, wxString s_wbs_no, bool b_psn=true);
        bool check_review_task(const wxString s_task_id);
        bool close_review_task(const wxString s_task_id);
        bool check_psn(const wxString s_wbs);
        bool check_configure_start(const wxString s_wbs);

	protected:

		//(*Identifiers(po_confirm_panel)
		static const long ID_BUTTON3;
		static const long ID_BUTTON2;
		static const long ID_BUTTON_PRICE_LIST;
		static const long ID_BUTTON_TASK_CHANGE;
		static const long ID_BUTTON_FILTER;
		static const long ID_BUTTON4;
		static const long ID_BUTTON5;
		static const long ID_BUTTON_SPEC2;
		static const long ID_BUTTON_POS;
		static const long ID_BUTTON1;
		static const long idMenu_only_private;
		static const long idMenu_all;
		static const long idMenu_task_change;
		static const long idMenu_Pricelist;
		//*)
		static const long ID_TREELISTCTRL_TASK_LIST1;
		static const long ID_TREELISTCTRL_TASK_LIST2;

	private:

		//(*Handlers(po_confirm_panel)
		void OnButton_Confirm2Click(wxCommandEvent& event);
		void OnButton_Return2Click(wxCommandEvent& event);
		void OnButton_RefreshClick(wxCommandEvent& event);
		void OnButton_Return1Click(wxCommandEvent& event);
		void OnButton_Confirm1Click(wxCommandEvent& event);
		void OnRightDown(wxMouseEvent& event);
		void OnMenuItem1Selected(wxCommandEvent& event);
		void OnMenuItem2Selected(wxCommandEvent& event);
		void OnButton_Spec2Click(wxCommandEvent& event);
		void OnButton_ChangeClick(wxCommandEvent& event);
		void OnMenuItem1Selected1(wxCommandEvent& event);
		void OnMenuItem2Selected1(wxCommandEvent& event);
		void Onbutton_task_changeClick(wxCommandEvent& event);
		void OnButton_posClick(wxCommandEvent& event);
		void OnKeyDown(wxKeyEvent& event);
		void OnButton_FilterClick(wxCommandEvent& event);
		//*)
		void connectKeyDownEvent(wxWindow* pclComponent);

		void OnTaskList1RightClick(wxTreeEvent& event);
		wxcode::wxTreeListCtrl* tlc_task_list1;
		wxcode::wxTreeListCtrl* tlc_task_list2;

		wxcode::wxTreeListCtrl* tlc_search;
        wxTreeItemId m_pos_id;
		wxString m_search_case;

		void change_price_list();
		bool update_price_list(wxString s_task_id, wxString s_wbs, wxString s_date);

		void change_task_operator();
		bool update_task_operator(wxString s_instance, wxString s_workflow, wxString s_action_id, wxString s_operator);

		void BuildDataViewCtrl();
		void refresh_level1();
		void refresh_level2();

		void show_offline_po(bool b_show);//show control

		wxArrayString get_spec_auth_online_po_list(wxString s_workflow_id, wxString s_action_id);
		bool b_spec;

        int get_unit_status(wxString s_wbs);

		wxArrayString get_steps_info(wxString &s_instance_id, wxString &s_workflow_id, wxString &s_now);
		wxArrayString m_steps;
        wxImageList* m_imageList;

		wxString cl_clause1, cl_clause2;

		DECLARE_EVENT_TABLE()
};

#endif
