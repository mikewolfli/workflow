#include "wf_listview_dlg.h"
#include "wfApp.h"

//(*InternalHeaders(wf_listview_dlg)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(wf_listview_dlg)
const long wf_listview_dlg::ID_LISTVIEW1 = wxNewId();
const long wf_listview_dlg::ID_BUTTON1 = wxNewId();
const long wf_listview_dlg::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wf_listview_dlg,wxDialog)
	//(*EventTable(wf_listview_dlg)
	//*)
END_EVENT_TABLE()

wf_listview_dlg::wf_listview_dlg(int _mode, wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(wf_listview_dlg)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("清单"));
	lv_list = new wxListView(this, ID_LISTVIEW1, wxDefaultPosition, wxSize(511,212), wxLC_REPORT|wxLC_HRULES|wxLC_VRULES, wxDefaultValidator, _T("ID_LISTVIEW1"));
	StaticBoxSizer1->Add(lv_list, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(StaticBoxSizer1, 5, wxALL|wxEXPAND, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("确定"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("取消"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wf_listview_dlg::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wf_listview_dlg::OnButton2Click);
	//*)

	m_mode = _mode;
}

wf_listview_dlg::~wf_listview_dlg()
{
	//(*Destroy(wf_listview_dlg)
	//*)
}


void wf_listview_dlg::OnButton2Click(wxCommandEvent& event)
{
    EndDialog(wxID_CANCEL);
}

void wf_listview_dlg::OnButton1Click(wxCommandEvent& event)
{
    array_sel.Clear();

    int i_count = lv_list->GetSelectedItemCount();

    if(i_count==0)
    {
        wxMessageBox(_("请选择所需条目"), _("提示"));
        return;
    }

    wxString str;

    long l_item = -1;
    l_item = lv_list->GetNextItem(l_item,  wxLIST_NEXT_ALL,  wxLIST_STATE_SELECTED);

    switch(m_mode)
    {
    case 0:
        while(l_item>=0)
        {
            str = lv_list->GetItemText(l_item, 1);
            array_sel.Add(str);

            l_item = lv_list->GetNextItem(l_item,  wxLIST_NEXT_ALL,  wxLIST_STATE_SELECTED);
        }
        break;
    case 1:
        while(l_item>=0)
        {
            str = lv_list->GetItemText(l_item, 0)+wxT("-")+lv_list->GetItemText(l_item, 1);
            array_sel.Add(str);
            l_item = lv_list->GetNextItem(l_item,  wxLIST_NEXT_ALL,  wxLIST_STATE_SELECTED);
        }
        break;
    default:
        break;
    }


    EndDialog(wxID_OK);
}

void wf_listview_dlg::init_list_header()
{
    wxListItem itemCol;
    switch(m_mode)
    {
    case 0:
        itemCol.SetText(_("合同号"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(100);
        lv_list->InsertColumn(0, itemCol);
        itemCol.SetText(_("文档号"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(0);
        lv_list->InsertColumn(1, itemCol);
        itemCol.SetText(_("Item No."));
        itemCol.SetImage(-1);
        itemCol.SetWidth(60);
        lv_list->InsertColumn(2, itemCol);
        itemCol.SetText(_("项目号"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(80);
        lv_list->InsertColumn(3, itemCol);
        itemCol.SetText(_("项目类型"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(100);
        lv_list->InsertColumn(4, itemCol);
        itemCol.SetText(_("项目名称"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(300);
        lv_list->InsertColumn(5, itemCol);
        itemCol.SetText(_("分公司"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(300);
        lv_list->InsertColumn(6, itemCol);
        break;
    case 1:

        itemCol.SetText(_("项目号"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(100);
        lv_list->InsertColumn(0, itemCol);
        itemCol.SetText(_("合同号"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(80);
        lv_list->InsertColumn(1, itemCol);
        itemCol.SetText(_("项目名称"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(300);
        lv_list->InsertColumn(2, itemCol);
        itemCol.SetText(_("工厂"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(50);
        lv_list->InsertColumn(3, itemCol);
        itemCol.SetText(_("分公司"));
        itemCol.SetImage(-1);
        itemCol.SetWidth(300);
        lv_list->InsertColumn(4, itemCol);
        break;

    default:
        break;
    }
}

void wf_listview_dlg::refresh_list(wxString s_sql)
{
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(s_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return ;
    }

    int i_count = _res->GetRowsNumber();
    int i_field = _res->GetNumberFields();
    long tmp ;

    for(int i=0;i<i_count;i++)
    {
        for(int j=0;j<i_field;j++)
        {
            wxString s_head = _res->ColName(j);
            wxString str;

            if(s_head == wxT("project_catalog"))
                 str= prj_catalog_to_str(_res->GetInt(j));
            else
                str = _res->GetVal(j);

            if(j==0)
            {
                   tmp = lv_list->InsertItem(i, str );
                   lv_list->SetItemData(tmp, i);
            }else
            {
                   lv_list->SetItem(tmp, j, str);
            }

        }
        _res->MoveNext();
    }
}
