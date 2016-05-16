#ifndef WF_LISTVIEW_DLG_H
#define WF_LISTVIEW_DLG_H

//(*Headers(wf_listview_dlg)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class wf_listview_dlg: public wxDialog
{
	public:

		wf_listview_dlg(int _mode=0, wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~wf_listview_dlg();

		//(*Declarations(wf_listview_dlg)
		wxButton* Button1;
		wxButton* Button2;
		wxListView* lv_list;
		//*)

		void init_list_header();
		void refresh_list(wxString s_sql);

		wxArrayString array_sel;

	protected:

		//(*Identifiers(wf_listview_dlg)
		static const long ID_LISTVIEW1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(wf_listview_dlg)
		void OnButton2Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		//*)

		int m_mode;

		DECLARE_EVENT_TABLE()
};

#endif
