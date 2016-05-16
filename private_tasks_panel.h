#ifndef PRIVATE_TASKS_PANEL_H
#define PRIVATE_TASKS_PANEL_H

//(*Headers(private_tasks_panel)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/datectrl.h>
#include <wx/panel.h>
#include <wx/dateevt.h>
#include <wx/choice.h>
#include <wx/gbsizer.h>
#include <wx/button.h>
#include <wx/combobox.h>
//*)

class private_tasks_panel: public wxPanel
{
	public:

		private_tasks_panel(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~private_tasks_panel();
		void init_list_view();


		//(*Declarations(private_tasks_panel)
		wxCheckBox* check_self;
		wxButton* button_approve;
		wxStaticText* StaticText2;
		wxStaticText* StaticText6;
		wxTextCtrl* tc_content;
		wxStaticText* StaticText1;
		wxButton* button_delete;
		wxButton* button_clear;
		wxStaticText* StaticText3;
		wxButton* button_submit;
		wxListView* lv_tasks;
		wxButton* button_reset_load;
		wxStaticText* StaticText5;
		wxTextCtrl* tc_res_load;
		wxChoice* choice_filter;
		wxDatePickerCtrl* dt_workday_to;
		wxComboBox* cb_catalog;
		wxButton* button_refresh;
		wxDatePickerCtrl* dt_workday_from;
		wxStaticText* StaticText4;
		wxButton* button_setting;
		//*)

	protected:

		//(*Identifiers(private_tasks_panel)
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX_CATALOG;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL_LOAD;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL_CONTENT;
		static const long ID_BUTTON_SUBMIT;
		static const long ID_BUTTON_CLEAR;
		static const long ID_STATICTEXT5;
		static const long ID_DATEPICKERCTRL_WORKDAY;
		static const long ID_DATEPICKERCTRL_TO;
		static const long ID_STATICTEXT6;
		static const long ID_CHOICE_FILTER;
		static const long ID_BUTTON_APPROVE;
		static const long ID_BUTTON_RESET_LOAD;
		static const long ID_BUTTON_REFRESH;
		static const long ID_BUTTON_SETTING;
		static const long ID_BUTTON_DELETE;
		static const long ID_CHECKBOX_SELF;
		static const long ID_LISTVIEW_TASKS;
		//*)

	private:

		//(*Handlers(private_tasks_panel)
		void Onbutton_submitClick(wxCommandEvent& event);
		void Onbutton_clearClick(wxCommandEvent& event);
		void Onbutton_approveClick(wxCommandEvent& event);
		void Onbutton_deleteClick(wxCommandEvent& event);
		void Onbutton_refreshClick(wxCommandEvent& event);
		void Onbutton_settingClick(wxCommandEvent& event);
		void Onchoice_filterSelect(wxCommandEvent& event);
		void Oncheck_selfClick(wxCommandEvent& event);
		void Onbutton_reset_loadClick(wxCommandEvent& event);
		void Ontc_res_loadText(wxCommandEvent& event);
		//*)

		wxString get_task_id();
		void get_direct_leader();
		wxString m_direct_leader;

		void approve_item(long item);
		void delete_item(long item);

		void clear_submit();
		void refresh_list_view();
		int m_filter;
		bool m_with_self;


		void init_catalog_list();

		DECLARE_EVENT_TABLE()
};

#endif
