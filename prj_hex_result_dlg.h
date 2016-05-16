#ifndef PRJ_HEX_RESULT_DLG_H
#define PRJ_HEX_RESULT_DLG_H

//(*Headers(prj_hex_result_dlg)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
#include "wf_stdafx.h"

class prj_hex_result_dlg: public wxDialog
{
	public:

		prj_hex_result_dlg(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~prj_hex_result_dlg();

		//(*Declarations(prj_hex_result_dlg)
		wxButton* Button1;
		wxButton* Button2;
		wxListView* lv_list;
		//*)
		void set_refresh_list(wxArrayHex &_a_hex)
		{
		    array_hex = _a_hex;
		}

		void refresh_list();


	protected:

		//(*Identifiers(prj_hex_result_dlg)
		static const long ID_LISTVIEW_LIST;
		static const long ID_BUTTON_OK;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(prj_hex_result_dlg)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)
		void init_list_head();
		void save_file(wxString s_file);

		wxArrayHex array_hex;
		wxArrayString array_head;

		DECLARE_EVENT_TABLE()
};

#endif
