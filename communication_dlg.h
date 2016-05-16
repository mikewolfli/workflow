#ifndef COMMUNICATION_DLG_H
#define COMMUNICATION_DLG_H

//(*Headers(communication_dlg)
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class communication_dlg: public wxDialog
{
	public:

		communication_dlg(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~communication_dlg();

		void init_communication(wxString s_id);

		//(*Declarations(communication_dlg)
		wxTextCtrl* tc_return;
		wxButton* Button1;
		wxTextCtrl* tc_content;
		wxButton* Button2;
		wxCheckBox* cb_specmemo;
		wxCheckBox* cb_gad;
		//*)
        wxString m_content;
        wxString m_return;
        bool b_gad;
        bool b_spec;
        int m_mode;

        void enable_control();

	protected:

		//(*Identifiers(communication_dlg)
		static const long ID_CHECKBOX_GAD;
		static const long ID_CHECKBOX_SPEC_MEMO;
		static const long ID_TEXTCTRL_CONTENT;
		static const long ID_TEXTCTRL_RETURN;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(communication_dlg)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)



		DECLARE_EVENT_TABLE()
};

#endif
