#ifndef GENERATED_ID_DISPLAY_PANEL_H
#define GENERATED_ID_DISPLAY_PANEL_H

//(*Headers(generated_id_display_panel)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/choice.h>
#include <wx/gbsizer.h>
#include <wx/button.h>
//*)

class generated_id_display_panel: public wxPanel
{
	public:

		generated_id_display_panel(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~generated_id_display_panel();

		void init_list_header();

        void refresh_list();

		//(*Declarations(generated_id_display_panel)
		wxButton* Button_Search;
		wxButton* Button_cancel;
		wxButton* Button_send;
		wxChoice* Choice_filter;
		wxChoice* Choice_catalog;
		wxButton* Button_refresh;
		wxButton* Button_Restore;
		wxTextCtrl* tc_search;
		wxListView* lv_list;
		//*)

	protected:

		//(*Identifiers(generated_id_display_panel)
		static const long ID_CHOICE_GEN_CATALOG;
		static const long ID_BUTTON_REFRESH;
		static const long ID_TEXTCTRL_SEARCH_TEXT;
		static const long ID_BUTTON_SEARCH;
		static const long ID_CHOICE_FILTER;
		static const long ID_BUTTON_RESTORE;
		static const long ID_BUTTON_SEND;
		static const long ID_BUTTON_CANCEL;
		static const long ID_LISTVIEW_LIST;
		//*)

	private:

		//(*Handlers(generated_id_display_panel)
		void OnButton_sendClick(wxCommandEvent& event);
		void OnButton_cancelClick(wxCommandEvent& event);
		void OnButton_refreshClick(wxCommandEvent& event);
		void OnChoice_catalogSelect(wxCommandEvent& event);
		void OnButton_SearchClick(wxCommandEvent& event);
		void OnButton_RestoreClick(wxCommandEvent& event);
		void OnChoice_filterSelect(wxCommandEvent& event);
		//*)

		int m_mode;
		wxString m_clause1,m_clause2, m_clause;


		wxString m_clause_att;
		int m_sel;
		bool change_item(long i_item, int i_mode);//0-cancel, 1-send, 2-restore

        wxArrayString get_group_member_of_leader(wxArrayString a_group);

        bool b_info;//true 资料室人员登陆， false 其他人员登陆
		DECLARE_EVENT_TABLE()
};

#endif
