#ifndef NSTD_MAT_MUTI_LEVEL_TASK_LIST_H
#define NSTD_MAT_MUTI_LEVEL_TASK_LIST_H

//(*Headers(nstd_mat_muti_level_task_list)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

#include "interface/sqlresulttable.h"
#include "ctrl/treelistctrl.h"

class nstd_mat_muti_level_task_list: public wxDialog
{
	public:

		nstd_mat_muti_level_task_list(int _receive_mode, wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~nstd_mat_muti_level_task_list();

		//(*Declarations(nstd_mat_muti_level_task_list)
		wxButton* Button1;
		wxMenuItem* MenuItem1;
		wxStaticText* StaticText1;
		wxButton* Button2;
		wxCheckBox* cb_filter;
		wxMenu menu_info;
		//*)

		wxcode::wxTreeListCtrl* tlc_task_list;

		void BuildDataViewCtrl();

        wxString m_index_id, m_batch_id;
        wxArrayString m_units;
        int m_level;

        void refresh_list();
        void refresh_task_list(wxArrayString & a_members);
        void refresh_task_list(wxString s_member);
        void refresh_level();
        int get_unit_status(wxString s_wbs, bool & b_urgent);

        void append_tree_leaf(wxTreeItemId &parent_id, wxString str_index_id, wxString &s_res_person, wxString &s_link_list, bool is_engineer=true);

	protected:

		//(*Identifiers(nstd_mat_muti_level_task_list)
		static const long ID_STATICTEXT1;
		static const long ID_CHECKBOX_FILTER;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long IdMenu_Info;
		//*)
		static const long ID_TREELISTCTRL_TASK_LIST ;

	private:

		//(*Handlers(nstd_mat_muti_level_task_list)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnMenuItem1Selected(wxCommandEvent& event);
		void Ontlc_task_listRightClick(wxTreeEvent& event);
		void Oncb_filterClick(wxCommandEvent& event);
		//*)

		int m_receive_mode;

		DECLARE_EVENT_TABLE()
};

#endif
