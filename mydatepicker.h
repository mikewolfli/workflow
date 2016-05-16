#ifndef MYDATEPICKER_H
#define MYDATEPICKER_H

//(*Headers(mydatepicker)
#include <wx/sizer.h>
#include <wx/calctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class mydatepicker: public wxDialog
{
	public:

		mydatepicker(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~mydatepicker();

		//(*Declarations(mydatepicker)
		wxButton* Button1;
		wxButton* Button2;
		wxCalendarCtrl* cctr_date;
		//*)
		wxString GetString()
		{
		    return m_value;
		}

		wxDateTime GetDate()
		{
		    return m_date_value;
		}

	protected:

		//(*Identifiers(mydatepicker)
		static const long ID_CALENDARCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(mydatepicker)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)
		wxString  m_value;
		wxDateTime m_date_value;

		DECLARE_EVENT_TABLE()
};

#endif
