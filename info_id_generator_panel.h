#ifndef INFO_ID_GENERATOR_PANEL_H
#define INFO_ID_GENERATOR_PANEL_H

//(*Headers(info_id_generator_panel)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/datectrl.h>
#include <wx/panel.h>
#include <wx/dateevt.h>
#include <wx/gbsizer.h>
#include <wx/button.h>
//*)

class info_id_generator_panel: public wxPanel
{
	public:

		info_id_generator_panel(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~info_id_generator_panel();

		//(*Declarations(info_id_generator_panel)
		wxCheckBox* cb_nce_pm;
		wxCheckBox* cb_nce_co;
		wxTextCtrl* tc_nce_eco;
		wxButton* Button_sg_gen;
		wxCheckBox* cb_nce_tm;
		wxStaticText* st_sg;
		wxCheckBox* cb_nce_lo;
		wxTextCtrl* tc_wb_reason;
		wxTextCtrl* tc_sg_proj;
		wxStaticText* st_nce_valid;
		wxButton* Button_NCE_gen;
		wxStaticText* st_nce_subject;
		wxCheckBox* cb_nce_ds;
		wxCheckBox* cb_nce_sm;
		wxCheckBox* cb_nce_pc;
		wxTextCtrl* tce_nce_from;
		wxCheckBox* cb_pu;
		wxCheckBox* cb_psm;
		wxCheckBox* cb_nce_fq;
		wxCheckBox* cb_lo;
		wxCheckBox* cb_nce_ppu;
		wxCheckBox* cb_qm;
		wxTextCtrl* tc_nce_subject;
		wxTextCtrl* tc_remarks;
		wxCheckBox* cb_nce_mpm;
		wxCheckBox* cb_nce_sqe;
		wxCheckBox* cb_co;
		wxTextCtrl* tc_ll;
		wxCheckBox* cb_nce_el;
		wxCheckBox* cb_ie;
		wxDatePickerCtrl* dp_nce_valid;
		wxButton* Button_sg_info;
		wxCheckBox* cb_nec_cs;
		wxCheckBox* cb_nce_other;
		wxStaticText* st_wbsbom;
		wxStaticText* st_nce_eco;
		wxStaticText* st_ll;
		wxCheckBox* cb_pm;
		wxCheckBox* cb_nce_urgent;
		wxButton* Button_LL_gen;
		wxButton* Button_wb;
		wxCheckBox* cb_nce_psm;
		wxCheckBox* cb_pp;
		wxCheckBox* cb_others;
		wxStaticText* st_from;
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
		static const long ID_CHECKBOX_TCE_MPM;
		static const long ID_CHECKBOX_TCE_PM;
		static const long ID_CHECKBOX_TCE_DS;
		static const long ID_CHECKBOX_NCE_CS;
		static const long ID_CHECKBOX_NCE_FQ;
		static const long ID_CHECKBOX_NCE_PSM;
		static const long ID_CHECKBOX_NCE_PPU;
		static const long ID_CHECKBOX_NCE_LO;
		static const long ID_CHECKBOX_NCE_CO;
		static const long ID_CHECKBOX_NCE_SM;
		static const long ID_CHECKBOX_NCE_TM;
		static const long ID_CHECKBOX_NCE_EL;
		static const long ID_CHECKBOX_NCE_SQE;
		static const long ID_CHECKBOX_NCE_OTHER;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL_NCE_FROM;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL_NCE_SUBJECT;
		static const long ID_BUTTON1;
		static const long ID_STATICTEXT6;
		static const long ID_TEXTCTRL_NCE_ECO;
		static const long ID_CHECKBOX_NCE_PC;
		static const long ID_DATEPICKERCTRL1;
		static const long ID_CHECKBOX1;
		static const long ID_STATICTEXT7;
		static const long ID_TEXTCTRL_REMARKS;
		//*)

		wxString get_tcen_id();
		void clear_tcen_ctrl();

	private:

		//(*Handlers(info_id_generator_panel)
		void OnButton_sg_genClick(wxCommandEvent& event);
		void OnButton_sg_infoClick(wxCommandEvent& event);
		void OnButton_LL_genClick(wxCommandEvent& event);
		void OnButton_wbClick(wxCommandEvent& event);
		void OnButton_NCE_genClick(wxCommandEvent& event);
		//*)
		wxString m_sg_links;
		wxString m_operators;


		DECLARE_EVENT_TABLE()
};

#endif
