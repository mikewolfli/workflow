#ifndef INS_PROC_LOG_H
#define INS_PROC_LOG_H

//(*Headers(ins_proc_log)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
#include "wfApp.h"

class ins_proc_log: public wxDialog
{
	public:
		ins_proc_log(wxWindow* parent = 0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ins_proc_log();

		//(*Declarations(ins_proc_log)
		wxListView* lv_proc_log1;
		wxButton* Button1;
		wxListView* lv_proc_log;
		//*)

		void Refresh_list_view(wxArrayString & array_wbs_list, wxString _flag=wxEmptyString, int _mode=0);
		void Refresh_review_list(wxArrayString & array_wbs_list);
		void init_conf_list_header();
		void init_review_list_header();

		void init_review_restart_header();
		void Refresh_review_history(wxArrayString & array_wbs_list);

	protected:

		//(*Identifiers(ins_proc_log)
		static const long ID_LISTVIEW_DISPLAY;
		static const long ID_LISTVIEW_DISPLAY1;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(ins_proc_log)
        void OnClose(wxCloseEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
