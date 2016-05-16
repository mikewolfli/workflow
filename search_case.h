#ifndef SEARCH_CASE_H
#define SEARCH_CASE_H

//(*Headers(search_case)
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class search_case: public wxDialog
{
	public:

		search_case(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~search_case();

		//(*Declarations(search_case)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxTextCtrl* tc_wbs;
		//*)

		wxArrayString GetValue()
		{
		    return array_value;
		}

		bool check_valid_wbs(wxString &s_wbs);

		void set_wbs_check(bool b_check = true)
		{
		    check_wbs = b_check;
		}

	protected:

		//(*Identifiers(search_case)
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		//*)

	private:

		//(*Handlers(search_case)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		//*)
		bool check_wbs;
        wxArrayString array_value;
		DECLARE_EVENT_TABLE()
};

#endif
