#ifndef NSTD_MAT_TASK_LIST_H
#define NSTD_MAT_TASK_LIST_H

//(*Headers(nstd_mat_task_list)
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/grid.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

#include "interface/sqlresulttable.h"
#include "xlslib.h"


using namespace xlslib_core;
#define RECORDCOUNT                65536

class nstd_mat_task_list: public wxDialog
{
	public:

		nstd_mat_task_list(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~nstd_mat_task_list();

		//(*Declarations(nstd_mat_task_list)
		wxMenuItem* MenuItem1;
		wxButton* Button_Export;
		wxButton* Button_OK;
		wxButton* Button_Cancel;
		wxMenu menu_units;
		sqlResultGrid* gd_task_list;
		//*)
        void init_nstd_item_header();
        void init_nstd_mat_header();
        void init_nstd_mat_instance_header();

        void show_control(bool b_show);
        void Set_Query(wxString s_query)
        {
            m_query = s_query;
        }

        void refresh_list(int i_use =1);
        wxString m_index_id;
        wxArrayString m_units;
        bool m_search_mode;


        // only for out to excel
        void get_array_units();
        void init_array_head();

        void label_result(int irow,worksheet* _ws, wxPostgreSQLresult * _res);
        //only for out to excel
	protected:

		//(*Identifiers(nstd_mat_task_list)
		static const long ID_GRID_TASK_LIST;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long IdMenu_Info;
		//*)

	private:

        // only for out to excel
        wxArrayString array_head, array_str, array_alias;
        wxArrayInt array_format;
        wxString get_out_path();
        wxString create_project_folder(wxString s_wbs_no, wxString s_loc);
        void export_excel(wxString s_wbs_no, wxString str_path);
        // only for out to excel

        wxString str_tasks_header;
        wxString m_query;
        int m_use;
		//(*Handlers(nstd_mat_task_list)
		void OnButton_OKClick(wxCommandEvent& event);
		void OnButton_CancelClick(wxCommandEvent& event);
		void OnMenuItem1Selected(wxCommandEvent& event);
		void Ongd_task_listCellRightClick(wxGridEvent& event);
		void OnButton_ExportClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
