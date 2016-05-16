#ifndef NSTD_INS_DOC_H
#define NSTD_INS_DOC_H

//(*Headers(nstd_ins_doc)
#include <wx/sizer.h>
#include <wx/checklst.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class nstd_ins_doc: public wxDialog
{
	public:

		nstd_ins_doc(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~nstd_ins_doc();

		//(*Declarations(nstd_ins_doc)
		wxCheckListBox* clb_unit_list;
		wxButton* Button_Save;
		wxButton* Button_Cancel;
		wxButton* Button_SELECT_ALL;
		//*)

		bool init_units_list(wxArrayString &array_units);

		void save_nstd_ins_doc_status();
		bool save_unit_ins_doc(wxString s_wbs, bool b_status);

	protected:

		//(*Identifiers(nstd_ins_doc)
		static const long ID_CHECKLISTBOX_UNIT_LIST;
		static const long ID_BUTTON_SAVE;
		static const long ID_BUTTON_ALL;
		static const long ID_BUTTON_CANCEL;
		//*)

	private:

		//(*Handlers(nstd_ins_doc)
		void OnButton_SaveClick(wxCommandEvent& event);
		void OnButton_SELECT_ALLClick(wxCommandEvent& event);
		void OnButton_CancelClick(wxCommandEvent& event);
		void Onclb_unit_listToggled(wxCommandEvent& event);
		//*)

        wxArrayInt m_status;
		bool b_change;

		DECLARE_EVENT_TABLE()
};

#endif
