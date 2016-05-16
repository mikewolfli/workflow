#ifndef CONFIGURE_MAT_LIST_EDITOR_H
#define CONFIGURE_MAT_LIST_EDITOR_H

//(*Headers(configure_mat_list_editor)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checklst.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class configure_mat_list_editor: public wxDialog
{
	public:

		configure_mat_list_editor(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~configure_mat_list_editor();

		//(*Declarations(configure_mat_list_editor)
		wxTextCtrl* tc_sequence;
		wxTextCtrl* tc_mat_id;
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxChoice* ch_unit;
		wxStaticText* StaticText6;
		wxTextCtrl* tc_batch_id;
		wxStaticText* StaticText8;
		wxCheckListBox* clb_units_list;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxButton* Button2;
		wxTextCtrl* tc_qty;
		wxButton* Button3;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxTextCtrl* tc_index_id;
		wxTextCtrl* tc_comment;
		wxStaticText* StaticText4;
		wxTextCtrl* tc_mat_desc;
		//*)

		wxString m_index_id,m_batch_id, m_mat_id, m_sequence, m_mat_desc,m_qty,m_unit,m_comments, m_str_units;
        void init_checklistbox(wxArrayString &array_str, wxString s_sel=wxEmptyString);
        void init_ctr_value();
	protected:

		//(*Identifiers(configure_mat_list_editor)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL_INDEX_ID;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTR_BATCH_ID;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL_SEQUENCE;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL_MAT_ID;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL_MAT_DESC;
		static const long ID_STATICTEXT6;
		static const long ID_TEXTCTRL_QTY;
		static const long ID_STATICTEXT7;
		static const long ID_CHOICE_UNIT;
		static const long ID_STATICTEXT8;
		static const long ID_TEXTCTRL_COMMENT;
		static const long ID_CHECKLISTBOX_UNITS_LIST;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		//*)

	private:

		//(*Handlers(configure_mat_list_editor)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void Ontc_qtyText(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
