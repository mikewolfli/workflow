#ifndef LOGIN_DLG_H
#define LOGIN_DLG_H

//(*Headers(login_dlg)
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class login_dlg: public wxDialog
{
	public:

		login_dlg(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~login_dlg();

		//(*Declarations(login_dlg)
		wxStaticText* st_message;
		wxCheckBox* cb_save;
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxTextCtrl* tc_user;
		wxStaticText* StaticText1;
		wxButton* Button2;
		wxTextCtrl* tc_pwd;
		//*)

	protected:

		//(*Identifiers(login_dlg)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL_USER;
		static const long ID_TEXTCTRL_PWD;
		static const long ID_CHECKBOX_SAVE;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_STATICTEXT3;
		//*)

	private:

		//(*Handlers(login_dlg)
		void OnInit(wxInitDialogEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
