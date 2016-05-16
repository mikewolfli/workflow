#ifndef NSTD_TASK_AUTHOR_H
#define NSTD_TASK_AUTHOR_H

//(*Headers(nstd_task_author)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

#include "interface/wxPostgreSQL.h"

class nstd_task_author: public wxDialog
{
	public:

		nstd_task_author(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~nstd_task_author();

		//(*Declarations(nstd_task_author)
		wxButton* Button1;
		wxListCtrl* lc_taskinfo;
		//*)

		wxArrayString m_units;
		void init_header();
		void refresh_list();

	protected:

		//(*Identifiers(nstd_task_author)
		static const long ID_LISTCTRL_TASKINFO;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(nstd_task_author)
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
