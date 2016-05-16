#ifndef PRIVATE_SETTING_H
#define PRIVATE_SETTING_H

//(*Headers(private_setting)
#include <wx/dialog.h>
//*)

class private_setting: public wxDialog
{
	public:

		private_setting(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~private_setting();

		//(*Declarations(private_setting)
		//*)

	protected:

		//(*Identifiers(private_setting)
		//*)

	private:

		//(*Handlers(private_setting)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
