#ifndef NCR_PROC_PANEL_H
#define NCR_PROC_PANEL_H

//(*Headers(ncr_proc_panel)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/choice.h>
#include <wx/button.h>
//*)

#include "interface/wxPostgreSQL.h"

class ncr_proc_panel: public wxPanel
{
	public:

		ncr_proc_panel(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ncr_proc_panel();

		//(*Declarations(ncr_proc_panel)
		wxButton* Button_del;
		wxButton* Button_submit;
		wxListView* lv_ncrs;
		wxButton* Button1;
		wxChoice* choice_filter2;
		wxButton* Button_feedback;
		wxButton* Button_close;
		wxButton* Button_fetch;
		wxButton* Button_change;
		wxButton* Button_create;
		wxButton* Button_ROLL_back;
		wxChoice* choice_filter1;
		//*)

		void refresh_list();
        void init_list_header();
        void show_control();

        void set_filter1(wxString str)
        {
            m_filter1 = str;
        }

        void set_filter2(wxString str)
        {
            m_filter2 = str;
        }



	protected:

		//(*Identifiers(ncr_proc_panel)
		static const long ID_LISTVIEW_NCR_LIST;
		static const long ID_CHOICE_FILTER1;
		static const long ID_CHOICE_FILTER2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON_CREATE;
		static const long ID_BUTTON_SUBMIT;
		static const long ID_BUTTON_CHANGE;
		static const long ID_BUTTON_FETCH;
		static const long ID_BUTTON_FEEDBACK;
		static const long ID_BUTTON_CLOSE;
		static const long ID_BUTTON_DEL;
		static const long ID_BUTTON_ROLLBACK;
		//*)

	private:

		//(*Handlers(ncr_proc_panel)
		void OnButton_createClick(wxCommandEvent& event);
		void OnButton_submitClick(wxCommandEvent& event);
		void OnButton_changeClick(wxCommandEvent& event);
		void OnButton_fetchClick(wxCommandEvent& event);
		void OnButton_feedbackClick(wxCommandEvent& event);
		void OnButton_closeClick(wxCommandEvent& event);
		void OnButton_delClick(wxCommandEvent& event);
		void Onchoice_filter1Select(wxCommandEvent& event);
		void Onchoice_filter2Select(wxCommandEvent& event);
		void Onlv_ncrsItemActivated(wxListEvent& event);
		void OnButton_ROLL_backClick(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		//*)
		wxString m_filter1;
		wxString m_filter2;
		int get_status(wxString s_id);
		wxArrayString array_ncr_group();

		bool get_ncr_group(wxArrayString &a_group_id, wxArrayString &a_group_name);

		bool change_item(long i_item,int i_mode, wxString s_content=wxEmptyString);//0 -发布， 1-领取， 2-变更工作组 3-回复NCR， 4-关闭NCR

		DECLARE_EVENT_TABLE()
};

#endif
