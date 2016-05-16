#ifndef PROJ_CONFIGURE_HISTORY_H
#define PROJ_CONFIGURE_HISTORY_H

//(*Headers(proj_configure_history)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

#include "wfApp.h"

class proj_configure_history: public wxDialog
{
	public:

		proj_configure_history(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~proj_configure_history();

		void refresh_list(const wxArrayString &array_wbs, wxString s_flag=wxEmptyString);
		void refresh_now_wbs(const wxArrayString &array_wbs, wxString s_flag=wxEmptyString);
		void refresh_now_prj(const wxArrayString &array_wbs, wxString s_flag=wxEmptyString);
		void init_list_ctrl();

		//(*Declarations(proj_configure_history)
		wxListView* lv_history;
		wxButton* Button1;
		//*)

	protected:

		//(*Identifiers(proj_configure_history)
		static const long ID_LISTVIEW_HISTORY;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(proj_configure_history)
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
