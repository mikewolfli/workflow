#ifndef NSTD_TASK_TREE_LIST_H
#define NSTD_TASK_TREE_LIST_H

//(*Headers(nstd_task_tree_list)
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
#include "ctrl/treelistctrl.h"

class nstd_task_tree_list: public wxDialog
{
	public:

		nstd_task_tree_list(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~nstd_task_tree_list();

		//(*Declarations(nstd_task_tree_list)
		wxButton* Button1;
		//*)

		void init_tree_list(wxArrayString &array_nstd_header);

	protected:

		//(*Identifiers(nstd_task_tree_list)
		static const long ID_BUTTON1;
		//*)
		static const long ID_TREE_TASK_LIST ;

	private:

		//(*Handlers(nstd_task_tree_list)
		void OnButton1Click(wxCommandEvent& event);
		//*)

        void buildtreeheader();

        wxcode::wxTreeListCtrl* tlc_task_list;

		DECLARE_EVENT_TABLE()
};

#endif
