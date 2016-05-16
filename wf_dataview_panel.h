#ifndef WF_DATAVIEW_PANEL_H
#define WF_DATAVIEW_PANEL_H

//(*Headers(wf_dataview_panel)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
//*)

#include "./ctrl/wfdataviewstore.h"
#include <wx/dataview.h>

class wf_dataview_panel: public wxPanel
{
	public:

		wf_dataview_panel(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~wf_dataview_panel();

		//(*Declarations(wf_dataview_panel)
		wxStaticText* StaticText1;
		wxTextCtrl* tc_qty;
		wxStaticBitmap* stb_logo;
		//*)

		wxDataViewCtrl * dvc_units;
		wxObjectDataPtr<wxDataViewTreeModel> m_units_model;

		void BuildDataViewCtrl();
		void Refresh_Dataview();

	protected:

		//(*Identifiers(wf_dataview_panel)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL_QTY;
		static const long ID_STATICBITMAP1_LOGO;
		//*)

	private:

		//(*Handlers(wf_dataview_panel)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
