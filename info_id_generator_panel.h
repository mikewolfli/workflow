#ifndef INFO_ID_GENERATOR_PANEL_H
#define INFO_ID_GENERATOR_PANEL_H

//(*Headers(info_id_generator_panel)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/gbsizer.h>
#include <wx/button.h>
//*)

class info_id_generator_panel: public wxPanel
{
	public:

		info_id_generator_panel(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~info_id_generator_panel();

		//(*Declarations(info_id_generator_panel)
		wxButton* Button_sg_gen;
		wxStaticText* st_sg;
		wxTextCtrl* tc_wb_reason;
		wxTextCtrl* tc_sg_proj;
		wxCheckBox* cb_pu;
		wxCheckBox* cb_psm;
		wxCheckBox* cb_lo;
		wxCheckBox* cb_qm;
		wxTextCtrl* tc_remarks;
		wxCheckBox* cb_co;
		wxTextCtrl* tc_ll;
		wxCheckBox* cb_ie;
		wxButton* Button_sg_info;
		wxStaticText* st_wbsbom;
		wxStaticText* st_ll;
		wxCheckBox* cb_pm;
		wxButton* Button_LL_gen;
		wxButton* Button_wb;
		wxCheckBox* cb_pp;
		wxCheckBox* cb_others;
		//*)

	protected:

		//(*Identifiers(info_id_generator_panel)
		static const long ID_TEXTCTRL_LL;
		static const long ID_BUTTON_LL_GEN;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL_SG_PROJ;
		static const long ID_BUTTON_SG_GEN;
		static const long ID_BUTTON_SG_INFO;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL_WB_REASON;
		static const long ID_BUTTON_WB;
		static const long ID_CHECKBOX_PU;
		static const long ID_CHECKBOX_QM;
		static const long ID_CHECKBOX_IE;
		static const long ID_CHECKBOX_PP;
		static const long ID_CHECKBOX_lo;
		static const long ID_CHECKBOX_PSM;
		static const long ID_CHECKBOX_PM;
		static const long ID_CHECKBOX_CO;
		static const long ID_CHECKBOX_OTHERS;
		static const long ID_TEXTCTRL_REMARKS;
		//*)

	private:

		//(*Handlers(info_id_generator_panel)
		void OnButton_sg_genClick(wxCommandEvent& event);
		void OnButton_sg_infoClick(wxCommandEvent& event);
		void OnButton_LL_genClick(wxCommandEvent& event);
		void OnButton_wbClick(wxCommandEvent& event);
		//*)
		wxString m_sg_links;
		wxString m_operators;


		DECLARE_EVENT_TABLE()
};

#endif
