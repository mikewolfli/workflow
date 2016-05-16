#ifndef NSTD_REASON_LIST_H
#define NSTD_REASON_LIST_H

//(*Headers(nstd_reason_list)
#include <wx/sizer.h>
#include <wx/checklst.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class nstd_reason_list: public wxDialog
{
	public:

		nstd_reason_list(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~nstd_reason_list();

		void init_checklistbox(wxArrayString &array_str);

		//(*Declarations(nstd_reason_list)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxCheckListBox* clb_reason;
		//*)
		wxString m_reason;

	protected:

		//(*Identifiers(nstd_reason_list)
		static const long ID_CHECKLISTBOX1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		//*)

	private:

		//(*Handlers(nstd_reason_list)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
