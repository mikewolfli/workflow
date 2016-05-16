#ifndef UNITS_LIST_DLG_H
#define UNITS_LIST_DLG_H

//(*Headers(units_list_dlg)
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

#include "ctrl/treelistctrl.h"

class units_list_dlg: public wxDialog
{
	public:

		units_list_dlg(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~units_list_dlg();

		//(*Declarations(units_list_dlg)
		wxButton* Button_cancel;
		wxButton* Button_ok;
		//*)

        wxcode::wxTreeListCtrl* tlc_proj_list;
        void refresh_list();

		void BuildDataViewCtrl();

		wxArrayString array_select;
		wxArrayString array_engineer;
		wxString m_proj;

		void set_clause(wxString s_clause)
		{
		    m_clause = s_clause;
		}
	protected:

		//(*Identifiers(units_list_dlg)
		static const long ID_BUTTON_OK;
		static const long ID_BUTTON_CANCEL;
		//*)
		static const long ID_TREELISTCTRL_UNIT_LIST ;

	private:

		//(*Handlers(units_list_dlg)
		void OnButton_okClick(wxCommandEvent& event);
		void OnButton_cancelClick(wxCommandEvent& event);
		//*)

        void refresh_project_level();



        bool check_one_prj();

        wxString m_clause;

		DECLARE_EVENT_TABLE()
};

#endif
