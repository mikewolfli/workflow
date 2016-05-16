#ifndef INS_NONSTD_PROC_LOG_H
#define INS_NONSTD_PROC_LOG_H

//(*Headers(ins_nonstd_proc_log)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

#include "wfApp.h"

class ins_nonstd_proc_log: public wxDialog
{
	public:

		ins_nonstd_proc_log(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ins_nonstd_proc_log();

		//(*Declarations(ins_nonstd_proc_log)
		wxButton* Button1;
		wxListView* lv_proc_log;
		//*)

		void Refresh_list_view(wxArrayString array_ins_list, wxArrayString array_workflow_id);
		void Refresh_list_view(wxArrayString array_ins_list, wxString s_workflow_id);

	protected:

		//(*Identifiers(ins_nonstd_proc_log)
		static const long ID_LISTVIEW_DISPLAY;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(ins_nonstd_proc_log)
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
