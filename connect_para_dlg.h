#ifndef CONNECT_PARA_DLG_H
#define CONNECT_PARA_DLG_H

//(*Headers(connect_para_dlg)
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class connect_para_dlg: public wxDialog
{
	public:

		connect_para_dlg(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~connect_para_dlg();

		wxString str_error;
		bool bmode;

		//(*Declarations(connect_para_dlg)
		wxTextCtrl* tc_host;
		wxTextCtrl* tc_dbpwd;
		wxStaticText* StaticText2;
		wxTextCtrl* tc_port;
		wxButton* Button1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
//		wxTextCtrl* tc_error;
		wxButton* Button2;
		wxTextCtrl* tc_dbuser;
		wxStaticText* StaticText5;
		wxTextCtrl* tc_dbname;
		wxStaticText* StaticText4;
		//*)

	protected:

		//(*Identifiers(connect_para_dlg)
//		static const long ID_TEXTCTRL_ERROR;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL_HOST;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL_PORT;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL_DBNAME;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL_DBUSER;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL_DBPWD;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(connect_para_dlg)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnInit(wxInitDialogEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
