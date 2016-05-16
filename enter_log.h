#ifndef ENTER_LOG_H
#define ENTER_LOG_H

//(*Headers(enter_log)
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class enter_log: public wxDialog
{
	public:

		enter_log(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~enter_log();

		//(*Declarations(enter_log)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxTextCtrl* tc_log;
		//*)

	protected:

		//(*Identifiers(enter_log)
		static const long ID_TEXTCTRL_LOG;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		//*)

	private:

		//(*Handlers(enter_log)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
