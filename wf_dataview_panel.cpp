#include "wf_dataview_panel.h"
#include "wfApp.h"

//(*InternalHeaders(wf_dataview_panel)
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//(*IdInit(wf_dataview_panel)
const long wf_dataview_panel::ID_STATICTEXT1 = wxNewId();
const long wf_dataview_panel::ID_TEXTCTRL_QTY = wxNewId();
const long wf_dataview_panel::ID_STATICBITMAP1_LOGO = wxNewId();
//*)

BEGIN_EVENT_TABLE(wf_dataview_panel,wxPanel)
	//(*EventTable(wf_dataview_panel)
	//*)
END_EVENT_TABLE()

wf_dataview_panel::wf_dataview_panel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(wf_dataview_panel)
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("配置项目总台数"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer4->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	tc_qty = new wxTextCtrl(this, ID_TEXTCTRL_QTY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_QTY"));
	BoxSizer4->Add(tc_qty, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	stb_logo = new wxStaticBitmap(this, ID_STATICBITMAP1_LOGO, wxBitmap(wxImage(_T(".\\res\\logo.jpg"))), wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICBITMAP1_LOGO"));
	BoxSizer5->Add(stb_logo, 1, wxALL|wxSHAPED|wxALIGN_RIGHT|wxALIGN_TOP, 0);
	BoxSizer2->Add(BoxSizer5, 1, wxALL|wxALIGN_RIGHT|wxALIGN_TOP, 0);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer1->Add(BoxSizer3, 10, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)

    BuildDataViewCtrl();
    BoxSizer3->Add(dvc_units, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0 );

    Layout();

}

wf_dataview_panel::~wf_dataview_panel()
{
	//(*Destroy(wf_dataview_panel)
	//*)
}

void wf_dataview_panel::BuildDataViewCtrl()
{
    dvc_units = new wxDataViewCtrl( this, wxID_ANY, wxDefaultPosition,wxDefaultSize, wxDV_HORIZ_RULES | wxDV_VERT_RULES);
    m_units_model = new wxDataViewTreeModel;

    dvc_units->AssociateModel( m_units_model.get() );

    wxDataViewTextRenderer *tr =
                new wxDataViewTextRenderer( "string", wxDATAVIEW_CELL_INERT );
    wxDataViewColumn *column0 =
             new wxDataViewColumn( _("WBS NO"), tr, 0, 100, wxALIGN_LEFT,
    wxDATAVIEW_COL_SORTABLE | wxDATAVIEW_COL_RESIZABLE );
    dvc_units->AppendColumn( column0 );
#if 0
    // Call this and sorting is enabled
    // immediatly upon start up.
    column0->SetAsSortKey();
#endif


    // column 1 of the view control:

    tr = new wxDataViewTextRenderer( "string", wxDATAVIEW_CELL_INERT );
    wxDataViewColumn *column1 =
             new wxDataViewColumn( _("项目名称"), tr, 1, 300, wxALIGN_LEFT,
    wxDATAVIEW_COL_SORTABLE | wxDATAVIEW_COL_REORDERABLE |
    wxDATAVIEW_COL_RESIZABLE );
    column1->SetMinWidth(300); // this column can't be resized to be smaller
    dvc_units->AppendColumn( column1 );

    // column 2 of the view control:

    tr = new wxDataViewTextRenderer( "string", wxDATAVIEW_CELL_INERT);
    wxDataViewColumn *column2 =
             new wxDataViewColumn( _("梯号"), tr, 2, 100, wxALIGN_LEFT,
    wxDATAVIEW_COL_SORTABLE | wxDATAVIEW_COL_REORDERABLE |
    wxDATAVIEW_COL_RESIZABLE );
    column2->SetMinWidth(100); // this column can't be resized to be smaller
    dvc_units->AppendColumn( column2 );

    // column 3 of the view control:
    tr = new wxDataViewTextRenderer( "string", wxDATAVIEW_CELL_INERT );
    wxDataViewColumn *column3=
            new wxDataViewColumn( _("梯型"), tr, 3, 100, wxALIGN_LEFT,
    wxDATAVIEW_COL_SORTABLE | wxDATAVIEW_COL_REORDERABLE |
    wxDATAVIEW_COL_RESIZABLE );
    column3->SetMinWidth(100); // this column can't be resized to be smaller
    dvc_units->AppendColumn( column3 );

    // column 4 of the view control:
    tr = new wxDataViewTextRenderer( "string", wxDATAVIEW_CELL_INERT );
    wxDataViewColumn *column4 =
           new wxDataViewColumn( _("项目类型"), tr, 4, 150, wxALIGN_LEFT,
    wxDATAVIEW_COL_SORTABLE | wxDATAVIEW_COL_REORDERABLE |
    wxDATAVIEW_COL_RESIZABLE );
    column4->SetMinWidth(150); // this column can't be resized to be smaller
    dvc_units->AppendColumn( column4 );

    // column 5 of the view control:
    tr = new wxDataViewTextRenderer( "string", wxDATAVIEW_CELL_INERT );
    wxDataViewColumn *column5 =
         new wxDataViewColumn( _("要求配置完成日期"), tr, 5, 150, wxALIGN_LEFT,
    wxDATAVIEW_COL_SORTABLE | wxDATAVIEW_COL_REORDERABLE );
    column5->SetMinWidth(150); // this column can't be resized to be smaller
    dvc_units->AppendColumn( column5 );

    // column 6 of the view control:
    tr = new wxDataViewTextRenderer( "string", wxDATAVIEW_CELL_INERT );
    wxDataViewColumn *column6 =
          new wxDataViewColumn( _("项目状况"), tr, 6, 150, wxALIGN_LEFT,
    wxDATAVIEW_COL_SORTABLE | wxDATAVIEW_COL_REORDERABLE |
    wxDATAVIEW_COL_RESIZABLE );
    column6->SetMinWidth(150); // this column can't be resized to be smaller
    dvc_units->AppendColumn( column6 );

    // column 7 of the view control:
    tr = new wxDataViewTextRenderer( "string", wxDATAVIEW_CELL_INERT );
    wxDataViewColumn *column7 =
          new wxDataViewColumn( _("责任工程师"), tr, 7, 150, wxALIGN_LEFT,
    wxDATAVIEW_COL_SORTABLE | wxDATAVIEW_COL_REORDERABLE |
    wxDATAVIEW_COL_RESIZABLE );
    column7->SetMinWidth(150); // this column can't be resized to be smaller
    dvc_units->AppendColumn( column7 );

    // column 8 of the view control:

    dvc_units->AppendProgressColumn(_("流程进度"), 8);

    Refresh_Dataview();
}

void wf_dataview_panel::Refresh_Dataview()
{

    if(!wxGetApp().conn->IsAlive())
    {
        wxMessageBox(_("系统连接已断开,请重新连接!"), _("错误"), wxOK);
        return;
    }


    wxString str_sql = wxT("SELECT instance_id, concat(contract_id, ' ', project_name) as project_name, lift_no, \
                           elevator_type, project_catalog, req_configure_finish, action_name, name, ceil(flow_ser*100/total_flow) as ins_progress from v_task_list1 \
                           WHERE (status = '1' or status = '3')  AND is_active = true ORDER BY req_configure_finish, instance_id ASC; ");

    m_units_model->DeleteAllItems();

    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int i_count = _res->GetRowsNumber();

    tc_qty->SetValue(NumToStr(i_count));

    int i_col = _res->GetNumberFields();
    wxString str_index;

    wfTreeModelNode *_branch = NULL;

    wxDataViewItem  dv_item;
    wxVariant v_temp;
    _res->MoveFirst();
    for(int i=0;i<i_count;i++)
    {
         if(str_index != _res->GetVal(wxT("instance_id")).Left(10))
         {
             if(_branch)
                 dvc_units->Expand(wxDataViewItem((void *)_branch));
             _branch = m_units_model->AddToRoot(_res);
         }

          m_units_model->AddToNode(_branch,_res);

         _res->MoveNext();

    }

 //   dvc_units->Expand(m_units_model->get_root())

    _res->Clear();
}

