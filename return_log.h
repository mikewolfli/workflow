#ifndef RETURN_LOG_H
#define RETURN_LOG_H

//(*Headers(return_log)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

#include "wfApp.h"
class return_log: public wxDialog
{
	public:

		return_log(wxWindow* parent=0);
		virtual ~return_log();

		//(*Declarations(return_log)
		wxButton* Button1;
		wxListView* lv_list;
		//*)

		void Refresh_list_view(wxArrayString & array_return, wxArrayString &array_return_time);
		void refresh_list(wxArrayString &a_return, wxString & aim_step);

	protected:

		//(*Identifiers(return_log)
		static const long ID_LISTVIEW1;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(return_log)
		void OnButton1Click(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
