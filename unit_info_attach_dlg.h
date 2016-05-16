#ifndef UNIT_INFO_ATTACH_DLG_H
#define UNIT_INFO_ATTACH_DLG_H

//(*Headers(unit_info_attach_dlg)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/gbsizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class unit_info_attach_dlg: public wxDialog
{
	public:

		unit_info_attach_dlg(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~unit_info_attach_dlg();
		void refresh_list();

		void Set_Editable(bool b_e)
		{
		    b_edit = b_e;
		}

		void refresh_control();

		wxArrayString array_wbs;

		//(*Declarations(unit_info_attach_dlg)
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxStaticText* StaticText1;
		wxButton* Button2;
		wxTextCtrl* tc_carweight;
		wxListView* lv_attach;
		wxButton* Button3;
		wxTextCtrl* tc_dc_weight;
		//*)

	protected:

		//(*Identifiers(unit_info_attach_dlg)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL_DC_WEIGHT;
		static const long ID_TEXTCTRL_CAR_WEIGHT;
		static const long ID_LISTVIEW_INFO_ATTACH;
		static const long ID_BUTTON1;
		static const long ID_BUTTON3;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(unit_info_attach_dlg)
		void OnButton3Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void Onlv_attachItemActivated(wxListEvent& event);
		void Ontc_carweightText(wxCommandEvent& event);
		void Ontc_dc_weightText(wxCommandEvent& event);
		//*)

		wxString m_wbs;
		bool b_change;

		void init_header();
		long m_litem;
		bool save_item(wxString s_wbs, wxString s_car_weight, wxString s_dc_weight);
		int find_wbs_in_list(wxString s_wbs);
		bool check_item_data_right(wxString &str);

		bool b_edit;

		void save_items();


		DECLARE_EVENT_TABLE()
};

#endif
