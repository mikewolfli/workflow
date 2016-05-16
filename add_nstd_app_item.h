#ifndef ADD_NSTD_APP_ITEM_H
#define ADD_NSTD_APP_ITEM_H

//(*Headers(add_nstd_app_item)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checklst.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/combobox.h>
//*)

class add_nstd_app_item: public wxDialog
{
	public:

		add_nstd_app_item(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~add_nstd_app_item();

		//(*Declarations(add_nstd_app_item)
		wxTextCtrl* tc_item_no;
		wxButton* Button1;
		wxChoice* choice_catalog;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxTextCtrl* tc_nstd_desc;
		wxButton* Button2;
		wxComboBox* combo_nstd_catalog;
		wxButton* Button3;
		wxButton* button_nstd_reason;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxTextCtrl* tc_status;
		wxTextCtrl* tc_nstd_app_index_id;
		wxCheckListBox* clb_units;
		wxStaticText* StaticText4;
		//*)

		wxString m_index;
		wxString m_item_no;
		wxString m_catalog;
		wxString m_nstd_app_id;
		wxString m_nstd_catalog;
		wxString m_nstd_desc;
		wxString m_status;
		wxArrayString m_array_sel;

        void init_combobox(wxString str);
        void init_catalog_choice(wxString str);
        void init_checklistbox(wxArrayString & array_str, bool b_sel=false);
        void set_nstd_app_id(wxString str)
        {
            m_nstd_app_id = str;
        }
        void append_sub_list(wxString str);
        void enable_control(bool b_edit);


	protected:

		//(*Identifiers(add_nstd_app_item)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL_INDEX;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL_ITEM_NO;
		static const long ID_STATICTEXT4;
		static const long ID_CHOICE_CATALOG;
		static const long ID_STATICTEXT5;
		static const long ID_COMBOBOX_NSTD_CATALOG;
		static const long ID_BUTTON_NSTD_REASON;
		static const long ID_TEXTCTRL_NSTD_DESC;
		static const long ID_STATICTEXT7;
		static const long ID_TEXTCTRL_STATUS;
		static const long ID_CHECKLISTBOX_UNITS;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		//*)

	private:

		//(*Handlers(add_nstd_app_item)
		void OnButton2Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void Onchoice_catalogSelect(wxCommandEvent& event);
		void OnInit(wxInitDialogEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void Onbutton_nstd_reasonClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
