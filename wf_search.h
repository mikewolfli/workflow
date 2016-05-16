#ifndef WF_SEARCH_H
#define WF_SEARCH_H

//(*Headers(wf_search)
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class wf_search: public wxDialog
{
	public:

		wf_search(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~wf_search();

		//(*Declarations(wf_search)
		wxButton* Button1;
		wxButton* Button2;
		wxChoice* choice_case;
		wxTextCtrl* tc_search;
		//*)

		int i_choice;
		wxString str_search;

		void set_choice(wxArrayString &a_str);

	protected:

		//(*Identifiers(wf_search)
		static const long ID_CHOICE_SEARCH;
		static const long ID_TEXTCTRL_SEARCH;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(wf_search)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
