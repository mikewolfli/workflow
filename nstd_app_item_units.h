#ifndef NSTD_APP_ITEM_UNITS_H
#define NSTD_APP_ITEM_UNITS_H

//(*Headers(nstd_app_item_units)
#include <wx/sizer.h>
#include <wx/checklst.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class nstd_app_item_units: public wxDialog
{
	public:

		nstd_app_item_units(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~nstd_app_item_units();

		void init_checklistbox(wxArrayString &array_str, wxArrayString &array_sel, bool b_sel= true, bool b_edit = true);

		//(*Declarations(nstd_app_item_units)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxCheckListBox* clb_units;
		//*)
		wxString m_units;
		wxArrayString array_units;

	protected:

		//(*Identifiers(nstd_app_item_units)
		static const long ID_CHECKLISTBOX1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		//*)

	private:

		//(*Handlers(nstd_app_item_units)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
