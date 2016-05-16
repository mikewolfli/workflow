#ifndef CONTRACT_LABEL_PRINT_H
#define CONTRACT_LABEL_PRINT_H


//(*Headers(contract_label_print)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
#include "contractlabeldraw.h"
#include <wx/cmndata.h>


class contract_label_print: public wxDialog
{
	public:

		contract_label_print(int _mode, wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~contract_label_print();

		//(*Declarations(contract_label_print)
		wxMenuItem* mi_del_doc;
		wxButton* Button_Print_Preview;
		wxMenuItem* mi_catalog_switch;
		wxButton* Button_Exit;
		wxListView* lv_wbs;
		wxListView* lv_contract;
		wxButton* Button_Generate;
		wxMenu menu_contract;
		wxButton* Button_Print;
		wxMenuItem* mi_remove_unit;
		wxMenuItem* mi_add_unit;
		wxButton* Button_ADD;
		wxButton* Button_Remove;
		wxButton* Button_contract_id;
		//*)
        ContractLabelDraw* scavas_label_draw = NULL;
        void generate_doc(wxArrayString &a_project, wxArrayString &a_contract_id);
        int get_item_no_of_doc(wxString &s_project);
        wxString generate_doc_id(wxString &s_project);
        void refresh_doc_list();
        void refresh_units_list(wxString s_contract_label_id);



   //     void show_control();

	protected:

		//(*Identifiers(contract_label_print)
		static const long ID_BUTTON_ADD;
		static const long ID_BUTTON_REMOVE;
		static const long ID_BUTTON_PRINT;
		static const long ID_BUTTON_PRINT_PREVIEW;
		static const long ID_BUTTON_GENERATE;
		static const long ID_BUTTON_INPUT_CONTRACT_ID;
		static const long ID_BUTTON_EXIT;
		static const long ID_LISTVIEW_CONTRACT_LEVEL;
		static const long ID_LISTVIEW_UNIT_LEVEL;
		static const long idMenu_Catalog;
		static const long idMenu_Add_unit;
		static const long idMenu_Remove;
		static const long idMenu_Delete;
		//*)
		static const long ID_LABEL_DRAW;

	private:



		//(*Handlers(contract_label_print)
		void Onlv_contractItemSelect(wxListEvent& event);
		void OnButton_ADDClick(wxCommandEvent& event);
		void OnButton_PrintClick(wxCommandEvent& event);
		void OnButton_Print_PreviewClick(wxCommandEvent& event);
		void OnButton_ExitClick(wxCommandEvent& event);
		void OnButton_RemoveClick(wxCommandEvent& event);
		void OnButton_contract_idClick(wxCommandEvent& event);
		void OnButton_GenerateClick(wxCommandEvent& event);
		void Onmi_catalog_switchSelected(wxCommandEvent& event);
		void Onlv_contractItemRClick(wxListEvent& event);
		void Onmi_add_unitSelected(wxCommandEvent& event);
		void Onmi_remove_unitSelected(wxCommandEvent& event);
		void Onmi_del_docSelected(wxCommandEvent& event);
		//*)

        int m_mode;//0 default , 1-search mode;
        void init_doc_header();
        void init_unit_list();
        wxArrayString array_label;

		DECLARE_EVENT_TABLE()
};


#endif
