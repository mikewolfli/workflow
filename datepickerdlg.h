#ifndef DATEPICKERDLG_H
#define DATEPICKERDLG_H

//(*Headers(datepickerdlg)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/checkbox.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/gbsizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class datepickerdlg: public wxDialog
{
	public:

		datepickerdlg(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~datepickerdlg();

		//(*Declarations(datepickerdlg)
		wxDatePickerCtrl* dp_to;
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxCheckBox* cb_to;
		wxStaticText* StaticText1;
		wxButton* Button2;
		wxDatePickerCtrl* dp_from;
		wxCheckBox* cb_from;
		//*)

		bool b_from,b_to;

		wxDateTime dt_from;
		wxDateTime dt_to;

	protected:

		//(*Identifiers(datepickerdlg)
		static const long ID_STATICTEXT1;
		static const long ID_DATEPICKERCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_DATEPICKERCTRL2;
		static const long ID_CHECKBOX1;
		static const long ID_CHECKBOX2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(datepickerdlg)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void Oncb_fromClick(wxCommandEvent& event);
		void Oncb_toClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
