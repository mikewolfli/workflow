#ifndef EVALUATE_DLG_H
#define EVALUATE_DLG_H

//(*Headers(evaluate_dlg)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/gbsizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
#include "interface/wxPostgreSQL.h"

#define conf_workload 1 //1小时一台
#define conf_check_rate 0.2 //0.2*conf_workload
#define conf_review_rate 0.3//0.3*conf_workload
#define conf_complex_nstd 1.3
#define conf_rf2 0.5
#define conf_rf3_or_synergy 0.2

class evaluate_dlg: public wxDialog
{
	public:

		evaluate_dlg(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~evaluate_dlg();

		void get_eval_id();
		bool save_evaluate();
		void init_ctrl();
		bool get_info();
		double get_evalute_value(wxString s_elevator_type, int i_nstd_level);

		//(*Declarations(evaluate_dlg)
		wxStaticText* StaticText9;
		wxTextCtrl* tc_error_points;
		wxStaticText* st_check_eval;
		wxStaticText* StaticText2;
		wxTextCtrl* tc_error_qty;
		wxTextCtrl* tc_eval_value;
		wxStaticText* StaticText6;
		wxStaticText* StaticText8;
		wxTextCtrl* tc_task_info;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxTextCtrl* tc_task;
		wxTextCtrl* tc_evaluator;
		wxStaticText* StaticText5;
		wxButton* Button_OK;
		wxTextCtrl* tc_operator;
		wxStaticText* StaticText7;
		wxButton* Button_Cancel;
		wxTextCtrl* tc_workflow;
		wxTextCtrl* tc_eval_remarks;
		wxStaticText* StaticText4;
		wxTextCtrl* tc_action;
		//*)

		//values
		wxString m_eval_id;
		wxString m_task;
		wxString m_task_desc;
		wxString m_workflow_id;
		wxString m_workflow_name;
		wxString m_action_id;
		wxString m_action_name;
		wxString m_operator_id;
		wxString m_operator_name;
		wxString m_evaluator_id;
		wxString m_evaluator;

		wxString m_check_id;
		wxString m_checker;
		double m_eval_value;
		wxString m_eval_remarks;
		int m_error_qty;
		wxString m_error_point;
		bool m_is_valid;
		wxString m_op_start_date;
		wxString m_op_finish_date;

        int m_status;//0-diy(do it yourself) , 1-checked, 2-evaluate

	protected:

		//(*Identifiers(evaluate_dlg)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL5;
		static const long ID_STATICTEXT6;
		static const long ID_TEXTCTRL6;
		static const long ID_STATICTEXT7;
		static const long ID_TEXTCTRL7;
		static const long ID_STATICTEXT8;
		static const long ID_TEXTCTRL8;
		static const long ID_STATICTEXT9;
		static const long ID_TEXTCTRL9;
		static const long ID_STATICTEXT10;
		static const long ID_TEXTCTRL10;
		static const long ID_STATICTEXT2;
		static const long ID_BUTTON_OK;
		static const long ID_BUTTON_CANCEL;
		//*)

	private:

		//(*Handlers(evaluate_dlg)
		void OnButton_OKClick(wxCommandEvent& event);
		void OnButton_CancelClick(wxCommandEvent& event);
		void Ontc_eval_valueText(wxCommandEvent& event);
		void Ontc_error_qtyText(wxCommandEvent& event);
		void OnInit(wxInitDialogEvent& event);
		//*)

		bool m_b_update;
		wxString m_update;
		DECLARE_EVENT_TABLE()
};

#endif
