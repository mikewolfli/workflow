#ifndef REVIEW_REMARKS_DLG_H
#define REVIEW_REMARKS_DLG_H

//(*Headers(review_remarks_dlg)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/gbsizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class review_remarks_dlg: public wxDialog
{
	public:

		review_remarks_dlg(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~review_remarks_dlg();

		//(*Declarations(review_remarks_dlg)
		wxStaticText* StaticText2;
		wxTextCtrl* tc_drawing_qty;
		wxButton* Button1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxButton* Button2;
		wxTextCtrl* tc_res_cm;
		wxTextCtrl* tc_remarks;
		wxButton* Button3;
		wxChoice* choice_urgent_level;
		wxStaticText* StaticText4;
		//*)

		void refresh_control(int i_qty, wxString s_res_cm, wxString s_remarks=wxEmptyString);
		wxString m_remarks;
		wxString m_qty;
		wxString m_res_cm;

		void show_control(bool b_show=true);
		int m_urgent_level;

	protected:

		//(*Identifiers(review_remarks_dlg)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL_DRAWING_QTY;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL_REMARKS;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL_RES_CM;
		static const long ID_BUTTON3;
		static const long ID_STATICTEXT4;
		static const long ID_CHOICE_URGENT_LEVEL;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(review_remarks_dlg)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void Ontc_drawing_qtyText(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
