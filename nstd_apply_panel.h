#ifndef NSTD_APPLY_PANEL_H
#define NSTD_APPLY_PANEL_H

//(*Headers(nstd_apply_panel)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/datectrl.h>
#include <wx/panel.h>
#include <wx/dateevt.h>
#include <wx/grid.h>
#include <wx/gbsizer.h>
#include <wx/button.h>
//*)

#include "interface/sqlresulttable.h"
#include "interface/nstdapptable.h"
#include "nstd_app_unit_list.h"


class nstd_apply_panel: public wxPanel
{
	public:

		nstd_apply_panel(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~nstd_apply_panel();

		//(*Declarations(nstd_apply_panel)
		wxButton* Button_Show_Mat;
		wxButton* Button_Search;
		sqlResultGrid* gd_unit_list;
		wxButton* button_begin;
		wxButton* Button_Units;
		wxDatePickerCtrl* dp_matreq;
		wxTextCtrl* tc_project_name;
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxButton* button_previous;
		wxButton* Button_Save;
		wxDatePickerCtrl* dp_draw_req;
		wxButton* button_next;
		wxButton* button_end;
		wxStaticText* StaticText3;
		wxTextCtrl* tc_nstd_id;
		wxTextCtrl* tc_nstd_desc;
		wxButton* Button2;
		wxButton* Button_Submit;
		wxButton* Button_Generate;
		wxTextCtrl* tc_qty;
		nstdappGrid* gd_nonstd_list;
		wxCheckBox* cb_highrise;
		wxButton* Button3;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxTextCtrl* tc_status;
		wxButton* Button_WORKFLOW;
		wxButton* Button_Cancel;
		wxCheckBox* cb_mech;
		wxBoxSizer* BoxSizer1;
		wxTextCtrl* tc_step;
		wxButton* Button_Print;
		wxTextCtrl* tc_project_id;
		wxButton* Button_REVISE;
		wxButton* Button_Close;
		wxStaticText* StaticText4;
		wxCheckBox* cb_elect;
		//*)

		void refresh_list();
		void refresh_unit_list(wxArrayString &array_unit);
		void init_list_header();
		void refresh_gui();

		wxString str_unit_header;
		wxString str_nonstd_header;


        wxUniChar booltoch(bool b_value);
        bool inttobool(int i_value);
        void mask_to_check();
        bool doSave();
        bool is_sub_task_created(wxString s_index_id);
	protected:

		//(*Identifiers(nstd_apply_panel)
		static const long ID_BUTTON_GENERATE;
		static const long ID_BUTTON_SUBMIT;
		static const long ID_BUTTON_SEARCH;
		static const long ID_BUTTON_CLOSE;
		static const long ID_BUTTON_CANCEL;
		static const long ID_BUTTON_SAVE;
		static const long ID_BUTTON_PRINT;
		static const long ID_CHECKBOX_MECH;
		static const long ID_CHECKBOX_HIGHRISE;
		static const long ID_CHECKBOX_ELECT;
		static const long ID_TEXTCTRL_STATUS;
		static const long ID_BUTTON_BEGIN;
		static const long ID_BUTTON_PREVIOUS;
		static const long ID_BUTTON_NEXT;
		static const long ID_BUTTON_END;
		static const long ID_TEXTCTRL_STEP;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT5;
		static const long ID_DATEPICKERCTRL1;
		static const long ID_STATICTEXT7;
		static const long ID_DATEPICKERCTRL_DRAW_REQ;
		static const long ID_TEXTCTRL_DESC;
		static const long ID_GRID_UNITS;
		static const long ID_GRID_NONSTD_LIST;
		static const long ID_BUTTON_ADD;
		static const long ID_BUTTON_DEL;
		static const long ID_BUTTON_REVISE;
		static const long ID_BUTTON_UNITS;
		static const long ID_TEXTCTRL_QTY;
		static const long ID_BUTTON_SHOW_MAT;
		static const long ID_BUTTON_WORKFLOW;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(nstd_apply_panel)
		void OnButton_GenerateClick(wxCommandEvent& event);
		void OnButton_SaveClick(wxCommandEvent& event);
		void OnButton_SubmitClick(wxCommandEvent& event);
		void OnButton_SearchClick(wxCommandEvent& event);
		void Oncb_mechClick(wxCommandEvent& event);
		void Oncb_highriseClick(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton_UnitsClick(wxCommandEvent& event);
		void Oncb_electClick(wxCommandEvent& event);
		void Ongd_nonstd_listCellChange(wxGridEvent& event);
		void OnButton_CancelClick(wxCommandEvent& event);
		void Onbutton_beginClick(wxCommandEvent& event);
		void Onbutton_previousClick(wxCommandEvent& event);
		void Onbutton_nextClick(wxCommandEvent& event);
		void Onbutton_endClick(wxCommandEvent& event);
		void OnButton_CloseClick(wxCommandEvent& event);
		void Ongd_nonstd_listCellRightClick(wxGridEvent& event);
		void OnButton_Show_MatClick(wxCommandEvent& event);
		void Ondp_matreqChanged(wxDateEvent& event);
		void Ondp_draw_reqChanged(wxDateEvent& event);
		void Ontc_nstd_descText(wxCommandEvent& event);
		void OnButton_WORKFLOWClick(wxCommandEvent& event);
		void OnButton_REVISEClick(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		//*)

		wxArrayString array_units;
		bool check_grid_input_valid(wxString &error_message);

		void show_control(bool b_show);
		void enable_control(bool b_edit);
		void save_header();
		wxString get_link_wbs(wxArrayString &a_wbs);
		bool check_owner_nstd(wxString s_id);

        wxString m_flow_mask;
		wxString nstd_app_id;
		wxArrayString array_search_result;

		DECLARE_EVENT_TABLE()
};

#endif
