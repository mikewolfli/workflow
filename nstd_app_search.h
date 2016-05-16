#ifndef NSTD_APP_SEARCH_H
#define NSTD_APP_SEARCH_H

//(*Headers(nstd_app_search)
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class nstd_app_search: public wxDialog
{
	public:

		nstd_app_search(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~nstd_app_search();

		void set_search_case(wxArrayString & array_str);

		//(*Declarations(nstd_app_search)
		wxChoice* choice_select;
		wxButton* Button1;
		wxButton* Button2;
		wxTextCtrl* tc_value;
		//*)

		int i_choice;
		wxString str_search;

	protected:

		//(*Identifiers(nstd_app_search)
		static const long ID_CHOICE_SELECT;
		static const long ID_TEXTCTRL_VALUE;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(nstd_app_search)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
