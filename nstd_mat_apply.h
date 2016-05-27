#ifndef NSTD_MAT_APPLY_H
#define NSTD_MAT_APPLY_H

#include "interface/nstdapptable.h"
#include "utils/wf_operator.h"

//(*Headers(nstd_mat_apply)
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
#include <wx/spinbutt.h>
#include <wx/combobox.h>
//*)

typedef struct s_responsor
{
    wxString s_res_id;
    wxString s_res_name;

    void Clear()
    {
        s_res_id.Empty();
        s_res_name.Empty();
    }
} st_responsor;

class nstd_mat_apply: public wxPanel
{
	public:
		nstd_mat_apply(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize, int _mode=0);
		virtual ~nstd_mat_apply();

		void show_control(bool b_show);
        void show_gui_control();

        bool add_remarks(wxString &str_top_remarks, wxString str_low_remarks, wxString str_header);

        int get_combined_remarks(wxString &str_remarks, wxString &str_no_finish);
        bool update_remarks(wxString str_remarks);

        void refresh_list();
        bool refresh_units_list(wxArrayString &array_sel);
        void refresh_nstd_status();
        void refresh_gui_check();
        void enable_grid(bool b_sure);
        void enable_check(bool b_sure);
        void enable_configure_control(bool b_sure);

        bool check_valid_data_clipboard(wxArrayInt &i_error,wxArrayString &array_rows);

        int paste_data_from_clipboard();

        void Get_Array_Batch();
        void get_low_level_info();
        void init_list_header();
        void refresh_top_gui();
        void refresh_low_gui();
        void add_batch();
        void add_nstd_mat_id();
        bool update_mat_instance(wxString s_index,wxString s_index_mat, wxString s_batch_id, wxString s_alias);
        bool doSave();
 //       void get_nstd_mat_app_id(wxString str_mat_index);
        wxString get_link_wbs(wxArrayString &a_wbs);
        void save_header(wxString s_nstd_app_id,wxString s_link_list);
        void save_item(wxString s_nstd_app_id,wxString s_link_list, wxString s_nstd_catalog);
        void clear_content();

        void remove_batch();
		//(*Declarations(nstd_mat_apply)
		wxStaticText* StaticText10;
		wxStaticText* st_low_nstd_reason;
		wxStaticText* StaticText9;
		wxButton* Button_Unit;
		wxButton* Button_workflow_draw;
		wxButton* Button_Search;
		wxButton* button_change_rel;
		wxButton* Button_Workflow;
		wxButton* Button_Receive;
		wxButton* Button_Low_Rel;
		wxButton* Button_Begin;
		wxTextCtrl* tc_nstd_reason;
		wxButton* Button_drawing;
		wxButton* Button_Add_Batch;
		wxTextCtrl* tc_project_name;
		wxTextCtrl* tc_row;
		wxStaticText* StaticText2;
		wxButton* Button_Clean;
		wxCheckBox* cb_nstd_mat;
		wxButton* Button_Import_Mat;
		wxStaticText* StaticText6;
		wxTextCtrl* tc_batch_id;
		wxDatePickerCtrl* dp_mat_req;
		wxStaticText* st_nstd_engineer;
		wxButton* Button_task_list;
		wxStaticText* StaticText8;
		wxDatePickerCtrl* dp_draw_req;
		wxCheckBox* cb_nstd_drawing;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxButton* Button_Nonstd_Ins_Doc;
		wxButton* Button_CONF_APPLY;
		wxButton* Button_workflow_mat;
		wxButton* Button_Submit;
		wxStaticText* st_low_nstd_feedback;
		wxTextCtrl* tc_remarks;
		wxTextCtrl* tc_mat_status;
		wxButton* Button_Generate;
		wxComboBox* combo_nstd_item_catalog;
		wxButton* Button_Del;
		wxTextCtrl* tc_qty;
		wxButton* Button_Next;
		wxButton* Button_PASS_NSTD;
		nstdappGrid* gd_mat_list;
		wxButton* Button_Same_header;
		wxButton* Button_Low_Confirm;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxStaticText* st_res_person;
		wxButton* Button_Cancel;
		wxTextCtrl* tc_draw_wf_status;
		wxButton* Button_Return;
		wxButton* Button_Previous;
		wxTextCtrl* tc_low_nstd_reason;
		wxButton* Button_End;
		wxDatePickerCtrl* dp_proj_au_date;
		wxTextCtrl* tc_index_id;
		wxTextCtrl* tc_res_person;
		wxSpinButton* spb_batch_id;
		wxButton* Button_Print;
		wxButton* Button_Add;
		wxTextCtrl* tc_mat_wf_status;
		wxTextCtrl* tc_project_id;
		wxButton* Button_Rel_Units;
		wxButton* Button_Rel;
		wxButton* Button_Engineer;
		wxTextCtrl* tc_low_nstd_feedback;
		wxTextCtrl* tc_draw_status;
		wxStaticText* StaticText4;
		wxTextCtrl* tc_nstd_mat_app_id;
		wxTextCtrl* tc_low_status;
		wxTextCtrl* tc_engineer;
		//*)
        wxStaticBox * sb_low_task;
        wxStaticBox * sb_feedback_configure;
        wxStaticBox * sb_att_info;

        bool get_non_finish_low_task(wxString &s_tasks);
        wxArrayString get_wbs_of_cur_rel_nstd(wxString _flag);


	protected:

		//(*Identifiers(nstd_mat_apply)
		static const long ID_BUTTON_RECEIVE;
		static const long ID_BUTTON_CONF_APPLY;
		static const long ID_BUTTON_TASK_LIST;
		static const long ID_BUTTON_GENERATE;
		static const long ID_BUTTON_ADD_BATCH;
		static const long ID_BUTTON_SEARCH;
		static const long ID_BUTTON_CANCEL;
		static const long ID_BUTTON_CLEAN;
		static const long ID_BUTTON_Print;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT8;
		static const long ID_TEXTCTRL_INDEX_ID;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL_PROJECT_ID;
		static const long ID_TEXTCTRL_NSTD_MAT_APP;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL_PROJECT_NAME;
		static const long ID_BUTTON_REL;
		static const long ID_BUTTON_WORKFLOW;
		static const long ID_BUTTON_NSTD_INS_DOC;
		static const long ID_BUTTON_HEADER;
		static const long ID_STATICTEXT4;
		static const long ID_DATEPICKERCTRL1;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT14;
		static const long ID_DATEPICKERCTRL_DRAW_REQ;
		static const long ID_COMBOBOX_NSTD_ITEM_CATALOG;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		static const long ID_TEXTCTRL_NSTD_REASON;
		static const long ID_TEXTCTRL_BATCH_ID;
		static const long ID_SPINBUTTON_BATCH_ID;
		static const long ID_STATICTEXT9;
		static const long ID_STATICTEXT13;
		static const long ID_TEXTCTRL_RES_PERSON;
		static const long ID_DATEPICKERCTRL_AU_DATE;
		static const long ID_STATICTEXT10;
		static const long ID_TEXTCTRL_NSTD_ENGINEER;
		static const long ID_BUTTON_ENGINEER;
		static const long ID_BUTTON_RETURN;
		static const long ID_TEXTCTRL_LOW_STATUS;
		static const long ID_STATICTEXT11;
		static const long ID_TEXTCTRL_LOW_NSTD_REASON;
		static const long ID_STATICTEXT12;
		static const long ID_TEXTCTRL_LOW_NSTD_FEEDBACK;
		static const long ID_BUTTON_LOW_CONFIRM;
		static const long ID_BUTTON_LOW_REL;
		static const long ID_TEXTCTRL_REMARKS;
		static const long ID_BUTTON_PASS_NSTD;
		static const long ID_CHECKBOX_MAT;
		static const long ID_CHECKBOX_DRAWING;
		static const long ID_TEXTCTRL_MAT_STATUS;
		static const long ID_TEXTCTRL_WF_MAT;
		static const long ID_TEXTCTRL_DRAW_STATUS;
		static const long ID_TEXTCTRL_WF_DRAW;
		static const long ID_BUTTON_SUBMIT_MAT;
		static const long ID_BUTTON_DRAWING;
		static const long ID_BUTTON_WORKFLOW_MAT;
		static const long ID_BUTTON_WORKFLOW_DRAW;
		static const long ID_BUTTON_PREVIOUS;
		static const long ID_TEXTCTRL_QTY;
		static const long ID_BUTTON_NEXT;
		static const long ID_BUTTON_BEGIN;
		static const long ID_BUTTON_END;
		static const long ID_GRID_MAT_LIST;
		static const long ID_BUTTON_IMPORT_MAT;
		static const long ID_BUTTON_ADD;
		static const long ID_BUTTON_DEL;
		static const long ID_TEXTCTRL_ROW;
		static const long ID_BUTTON_CHANGE_RELATION;
		static const long ID_BUTTON_REL_UNTIS;
		static const long ID_BUTTON_UNIT_LIST;
		//*)

	private:

		//(*Handlers(nstd_mat_apply)
		void OnButton_ReceiveClick(wxCommandEvent& event);
		void OnButton_GenerateClick(wxCommandEvent& event);
		void OnButton_SubmitClick(wxCommandEvent& event);
		void OnButton_SearchClick(wxCommandEvent& event);
		void OnButton_PrintClick(wxCommandEvent& event);
		void OnButton_RelClick(wxCommandEvent& event);
		void OnButton_Same_headerClick(wxCommandEvent& event);
		void OnButton_PreviousClick(wxCommandEvent& event);
		void OnButton_NextClick(wxCommandEvent& event);
		void OnButton_BeginClick(wxCommandEvent& event);
		void OnButton_EndClick(wxCommandEvent& event);
		void OnButton_AddClick(wxCommandEvent& event);
		void OnButton_DelClick(wxCommandEvent& event);
		void OnButton_Add_BatchClick(wxCommandEvent& event);
		void Onspb_batch_idChangeUp(wxSpinEvent& event);
		void Onspb_batch_idChangeDown(wxSpinEvent& event);
		void Oncb_nstd_matClick(wxCommandEvent& event);
		void Oncb_nstd_drawingClick(wxCommandEvent& event);
		void Onbutton_change_relClick(wxCommandEvent& event);
		void Ongd_mat_listKeyDown(wxKeyEvent& event);
		void OnButton_PASS_NSTDClick(wxCommandEvent& event);
		void OnButton_Import_MatClick(wxCommandEvent& event);
		void Ontc_remarksText(wxCommandEvent& event);
		void Ongd_mat_listCellSelect(wxGridEvent& event);
		void OnButton_drawingClick(wxCommandEvent& event);
		void OnButton_workflow_matClick(wxCommandEvent& event);
		void OnButton_workflow_drawClick(wxCommandEvent& event);
		void OnButton_CONF_APPLYClick(wxCommandEvent& event);
		void Ondp_mat_reqChanged(wxDateEvent& event);
		void Ondp_draw_reqChanged(wxDateEvent& event);
		void Ontc_nstd_reasonTextEnter(wxCommandEvent& event);
		void OnButton_EngineerClick(wxCommandEvent& event);
		void OnButton_Low_ConfirmClick(wxCommandEvent& event);
		void OnButton_Low_RelClick(wxCommandEvent& event);
		void OnButton_ReturnClick(wxCommandEvent& event);
		void Ontc_low_nstd_reasonTextEnter(wxCommandEvent& event);
		void Ontc_low_nstd_feedbackTextEnter(wxCommandEvent& event);
		void OnButton_CancelClick(wxCommandEvent& event);
		//		void OnButton_RestoreClick(wxCommandEvent& event);
		void OnButton_UnitClick(wxCommandEvent& event);
		void OnButton_Rel_UnitsClick(wxCommandEvent& event);
		void OnButton_WorkflowClick(wxCommandEvent& event);
		void OnButton_CleanClick(wxCommandEvent& event);
		void Oncombo_nstd_item_catalogTextUpdated(wxCommandEvent& event);
		void OnButton_Nonstd_Ins_DocClick(wxCommandEvent& event);
		void OnButton_task_listClick(wxCommandEvent& event);
		//*)

		bool ck_jump_proc();
		bool active_configure_mat_list();


		wxString str_mat_header,m_group,m_project_id;
		bool  m_search_mode;
		int  m_use_status; //操作方式1 接受1级分配， 2 接受再分配 0 配置生成, 3 CS操作。
		int m_status;
		int m_receive_mode; //true - 整梯BOM任务，false -非整梯非标任务;
		st_responsor m_engineer;
		st_responsor m_res_person;
		wxString m_index_id,m_batch_id,m_nstd_mat_app_id;
        wxArrayString m_units, m_array_batch_id;
        wxArrayString array_search_result;
        bool m_mat_req, m_draw_req;

		DECLARE_EVENT_TABLE()
};

#endif
