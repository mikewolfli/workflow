#ifndef CONTRACTBOOK_BR_DLG_H
#define CONTRACTBOOK_BR_DLG_H

//(*Headers(contractbook_br_dlg)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class contractbook_br_dlg: public wxDialog
{
	public:

		contractbook_br_dlg(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~contractbook_br_dlg();

		//(*Declarations(contractbook_br_dlg)
		wxButton* Button_Change;
		wxButton* Button2;
		wxListView* lv_br;
		//*)

		void set_mode(int _mode)
		{
		    m_mode=_mode;

		    refresh_gui();
		}

		void refresh_list(wxString s_case, int i_mode=0);

	protected:

		//(*Identifiers(contractbook_br_dlg)
		static const long ID_LISTVIEW_CONTRACTBOOK_BR;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(contractbook_br_dlg)
		void OnButton_ChangeClick(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)
		void init_list_header();
		void refresh_gui();
		int m_mode;

		DECLARE_EVENT_TABLE()
};

#endif
