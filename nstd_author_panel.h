#ifndef NSTD_AUTHOR_PANEL_H
#define NSTD_AUTHOR_PANEL_H

//(*Headers(nstd_author_panel)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/grid.h>
#include <wx/button.h>
//*)

#include "interface/nstdapptable.h"
#include "utils/wf_operator.h"

class nstd_author_panel: public wxPanel
{
	public:

		nstd_author_panel(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~nstd_author_panel();

		//(*Declarations(nstd_author_panel)
		wxMenuItem* MenuItem2;
		wxMenuItem* MenuItem1;
		wxButton* Button_APPROVE;
		wxButton* Button2;
		wxButton* Button3;
		wxListCtrl* lc_res;
		wxMenu Task_info;
		nstdappGrid* gd_task_list;
		//*)
		void init_list_header();
		void refresh_res_list();
		wxString str_tasks_header;
		void refresh_list();
		void enable_control(bool b_edit);
        bool doSave();
 //       wxString get_num_value(wxString s_index_id);

        bool update_operator(wxString s_operator, wxString s_instance);
	protected:

		//(*Identifiers(nstd_author_panel)
		static const long ID_GRID_TASK;
		static const long ID_BUTTON2;
		static const long ID_BUTTON_REFRESH;
		static const long ID_BUTTON_APPROVE;
		static const long ID_LISTCTRL_RES;
		static const long idMenu_INFO;
		static const long idMenu_WORKFLOW;
		//*)

	private:

		//(*Handlers(nstd_author_panel)
		void OnButton2Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void Ongd_task_listCellRightClick(wxGridEvent& event);
		void OnMenuItem1Selected(wxCommandEvent& event);
//		void Ongd_task_listCellChange(wxGridEvent& event);
		void OnButton_APPROVEClick(wxCommandEvent& event);
		void OnMenuItem2Selected(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
