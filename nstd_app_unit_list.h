#ifndef NSTD_APP_UNIT_LIST_H
#define NSTD_APP_UNIT_LIST_H

//(*Headers(nstd_app_unit_list)
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

#include "ctrl/treelistctrl.h"
#include <wx/imaglist.h>

// arrays/maps declarations
//
class nstd_app_unit_list: public wxDialog
{
	public:

		nstd_app_unit_list(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~nstd_app_unit_list();

		//(*Declarations(nstd_app_unit_list)
		wxButton* Button1;
		wxButton* Button2;
		//*)

        wxcode::wxTreeListCtrl* tlc_proj_list;

		void BuildDataViewCtrl();
		void InitImageList();

		wxArrayString array_select;
		wxString m_proj;
		wxDateTime m_req_finish;
		wxDateTime check_min_date(wxString &str1, wxString str2);

		bool b_active;
		wxString m_str_unit;

		void refresh_list();

		bool check_one_prj();

	protected:

		//(*Identifiers(nstd_app_unit_list)
		static const long ID_BUTTON_OK;
		static const long ID_BUTTON_CANCEL;
		//*)
		static const long ID_TREELISTCTRL_UNIT_LIST ;

	private:

		//(*Handlers(nstd_app_unit_list)
		void OnInit(wxInitDialogEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)

        wxImageList* m_imageList;
        void refresh_project_level();

		DECLARE_EVENT_TABLE()
};

#endif
