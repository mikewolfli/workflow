#ifndef CF_TASK_LIST_H
#define CF_TASK_LIST_H

//(*Headers(cf_task_list)
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class cf_task_list: public wxDialog
{
	public:

		cf_task_list(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~cf_task_list();

		//(*Declarations(cf_task_list)
		wxButton* Button1;
		wxButton* Button2;
		//*)

	protected:

		//(*Identifiers(cf_task_list)
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(cf_task_list)
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
