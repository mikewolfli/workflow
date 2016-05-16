#ifndef REVIEW_COMMUNICATION_LOG_H
#define REVIEW_COMMUNICATION_LOG_H

//(*Headers(review_communication_log)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class review_communication_log: public wxDialog
{
	public:

		review_communication_log(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~review_communication_log();

		void refresh_list(wxArrayString &a_task_id, wxArrayString & a_info);

		//(*Declarations(review_communication_log)
		wxButton* Button1;
		wxListView* lv_log;
		//*)

	protected:

		//(*Identifiers(review_communication_log)
		static const long ID_LISTVIEW_LOG;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(review_communication_log)
		void OnButton1Click(wxCommandEvent& event);
		//*)
        void init_list_header();
		DECLARE_EVENT_TABLE()
};

#endif
