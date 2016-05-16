#ifndef NDO_GENERATOR_PANEL_H
#define NDO_GENERATOR_PANEL_H

//(*Headers(ndo_generator_panel)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/gbsizer.h>
#include <wx/button.h>
#include <wx/combobox.h>
//*)

class ndo_generator_panel: public wxPanel
{
	public:

		ndo_generator_panel(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ndo_generator_panel();

		//(*Declarations(ndo_generator_panel)
		wxTextCtrl* tc_id;
		wxStaticText* StaticText2;
		wxStaticText* StaticText6;
		wxComboBox* cbb_comp_cli;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxTextCtrl* tc_remarks;
		wxTextCtrl* tc_file_id;
		wxTextCtrl* tc_file_name;
		wxStaticText* StaticText5;
		wxButton* Button_generator;
		wxButton* Button_Clear;
		wxStaticText* StaticText4;
		wxComboBox* cbb_components;
		//*)

	protected:

		//(*Identifiers(ndo_generator_panel)
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX_COMPONENTS_CLASSIFICATION;
		static const long ID_STATICTEXT2;
		static const long ID_COMBOBOX_COMPONENTS;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL_ID;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL_FILE_ID;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL_FILE_NAME;
		static const long ID_STATICTEXT6;
		static const long ID_TEXTCTRL_REMARKS;
		static const long ID_BUTTON_GENERATE;
		static const long ID_BUTTON_CLEAR;
		//*)

	private:

	     void  init_ccb_cli();
	     void  init_ccb_components(wxString s_pos);

		//(*Handlers(ndo_generator_panel)
		void OnButton_generatorClick(wxCommandEvent& event);
		void OnButton_ClearClick(wxCommandEvent& event);
		void Oncbb_comp_cliSelected(wxCommandEvent& event);
		//*)
		int get_serial(wxString s_prefix);
		wxString get_direct_leader();

		DECLARE_EVENT_TABLE()
};

#endif
