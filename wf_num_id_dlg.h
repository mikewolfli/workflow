#ifndef WF_NUM_ID_DLG_H
#define WF_NUM_ID_DLG_H

//(*Headers(wf_num_id_dlg)
#include <wx/sizer.h>
#include <wx/spinctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class wf_num_id_dlg: public wxDialog
{
	public:

		wf_num_id_dlg(int  _init=0, wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~wf_num_id_dlg();

		//(*Declarations(wf_num_id_dlg)
		wxSpinCtrl* sc_num;
		wxButton* Button1;
		wxButton* Button2;
		//*)
		int m_value;

	protected:

		//(*Identifiers(wf_num_id_dlg)
		static const long ID_SPINCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(wf_num_id_dlg)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void Onsc_numChange(wxSpinEvent& event);
		void OnClose(wxCloseEvent& event);
		//*)

		int m_init;

		DECLARE_EVENT_TABLE()
};

#endif
