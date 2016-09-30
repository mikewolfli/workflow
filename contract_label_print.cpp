#include "contract_label_print.h"
#include "wfApp.h"
#include "wf_search.h"
#include "wf_listview_dlg.h"
#include "wf_num_id_dlg.h"
#include "nstd_app_item_units.h"

#include <wx/printdlg.h>

//(*InternalHeaders(contract_label_print)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(contract_label_print)
const long contract_label_print::ID_BUTTON_ADD = wxNewId();
const long contract_label_print::ID_BUTTON_REMOVE = wxNewId();
const long contract_label_print::ID_BUTTON_PRINT = wxNewId();
const long contract_label_print::ID_BUTTON_PRINT_PREVIEW = wxNewId();
const long contract_label_print::ID_BUTTON_GENERATE = wxNewId();
const long contract_label_print::ID_BUTTON_INPUT_CONTRACT_ID = wxNewId();
const long contract_label_print::ID_BUTTON_EXIT = wxNewId();
const long contract_label_print::ID_LISTVIEW_CONTRACT_LEVEL = wxNewId();
const long contract_label_print::ID_LISTVIEW_UNIT_LEVEL = wxNewId();
const long contract_label_print::idMenu_Catalog = wxNewId();
const long contract_label_print::idMenu_Add_unit = wxNewId();
const long contract_label_print::idMenu_Remove = wxNewId();
const long contract_label_print::idMenu_Delete = wxNewId();
//*)
const long contract_label_print::ID_LABEL_DRAW = wxNewId();

BEGIN_EVENT_TABLE(contract_label_print,wxDialog)
	//(*EventTable(contract_label_print)
	//*)
END_EVENT_TABLE()

contract_label_print::contract_label_print(int _mode, wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(contract_label_print)
	wxStaticBoxSizer* StaticBoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxBoxSizer* BoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxGridSizer* GridSizer1;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, wxID_ANY, _("合同标签操作"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, this, _("操作按钮"));
	GridSizer1 = new wxGridSizer(4, 2, 0, 0);
	Button_ADD = new wxButton(this, ID_BUTTON_ADD, _("新增标签合同"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_ADD"));
	GridSizer1->Add(Button_ADD, 1, wxALL, 5);
	Button_Remove = new wxButton(this, ID_BUTTON_REMOVE, _("移除标签合同"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_REMOVE"));
	GridSizer1->Add(Button_Remove, 1, wxALL, 5);
	Button_Print = new wxButton(this, ID_BUTTON_PRINT, _("打印标签"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_PRINT"));
	GridSizer1->Add(Button_Print, 1, wxALL, 5);
	Button_Print_Preview = new wxButton(this, ID_BUTTON_PRINT_PREVIEW, _("打印预览"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_PRINT_PREVIEW"));
	GridSizer1->Add(Button_Print_Preview, 1, wxALL, 5);
	Button_Generate = new wxButton(this, ID_BUTTON_GENERATE, _("生成合同文档"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_GENERATE"));
	GridSizer1->Add(Button_Generate, 1, wxALL, 5);
	Button_contract_id = new wxButton(this, ID_BUTTON_INPUT_CONTRACT_ID, _("补全合同号"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_INPUT_CONTRACT_ID"));
	GridSizer1->Add(Button_contract_id, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Exit = new wxButton(this, ID_BUTTON_EXIT, _("退出"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_EXIT"));
	GridSizer1->Add(Button_Exit, 1, wxALL, 5);
	StaticBoxSizer2->Add(GridSizer1, 1, wxALL|wxEXPAND, 0);
	BoxSizer2->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 0);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("标签合同"));
	lv_contract = new wxListView(this, ID_LISTVIEW_CONTRACT_LEVEL, wxDefaultPosition, wxSize(153,80), wxLC_REPORT|wxLC_SINGLE_SEL, wxDefaultValidator, _T("ID_LISTVIEW_CONTRACT_LEVEL"));
	StaticBoxSizer3->Add(lv_contract, 1, wxALL|wxEXPAND, 0);
	BoxSizer2->Add(StaticBoxSizer3, 3, wxALL|wxEXPAND, 0);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("合同内包含梯"));
	lv_wbs = new wxListView(this, ID_LISTVIEW_UNIT_LEVEL, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTVIEW_UNIT_LEVEL"));
	StaticBoxSizer4->Add(lv_wbs, 1, wxALL|wxEXPAND, 0);
	BoxSizer2->Add(StaticBoxSizer4, 2, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 0);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("标签预览"));
	BoxSizer1->Add(StaticBoxSizer1, 3, wxALL|wxEXPAND, 0);
	SetSizer(BoxSizer1);
	mi_catalog_switch = new wxMenuItem((&menu_contract), idMenu_Catalog, _("Major Project(&S)"), _("项目类型切换"), wxITEM_CHECK);
	menu_contract.Append(mi_catalog_switch);
	menu_contract.AppendSeparator();
	mi_add_unit = new wxMenuItem((&menu_contract), idMenu_Add_unit, _("加入新梯(&A)"), _("加入新梯"), wxITEM_NORMAL);
	menu_contract.Append(mi_add_unit);
	mi_remove_unit = new wxMenuItem((&menu_contract), idMenu_Remove, _("移除已有梯(&R)"), _("移除已有梯"), wxITEM_NORMAL);
	menu_contract.Append(mi_remove_unit);
	menu_contract.AppendSeparator();
	mi_del_doc = new wxMenuItem((&menu_contract), idMenu_Delete, _("删除合同文档(&D)"), _("删除合同文档"), wxITEM_NORMAL);
	menu_contract.Append(mi_del_doc);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON_ADD,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&contract_label_print::OnButton_ADDClick);
	Connect(ID_BUTTON_REMOVE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&contract_label_print::OnButton_RemoveClick);
	Connect(ID_BUTTON_PRINT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&contract_label_print::OnButton_PrintClick);
	Connect(ID_BUTTON_PRINT_PREVIEW,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&contract_label_print::OnButton_Print_PreviewClick);
	Connect(ID_BUTTON_GENERATE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&contract_label_print::OnButton_GenerateClick);
	Connect(ID_BUTTON_INPUT_CONTRACT_ID,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&contract_label_print::OnButton_contract_idClick);
	Connect(ID_BUTTON_EXIT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&contract_label_print::OnButton_ExitClick);
	Connect(ID_LISTVIEW_CONTRACT_LEVEL,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&contract_label_print::Onlv_contractItemSelect);
	Connect(ID_LISTVIEW_CONTRACT_LEVEL,wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK,(wxObjectEventFunction)&contract_label_print::Onlv_contractItemRClick);
	Connect(idMenu_Catalog,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&contract_label_print::Onmi_catalog_switchSelected);
	Connect(idMenu_Add_unit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&contract_label_print::Onmi_add_unitSelected);
	Connect(idMenu_Remove,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&contract_label_print::Onmi_remove_unitSelected);
	Connect(idMenu_Delete,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&contract_label_print::Onmi_del_docSelected);
	//*)

	init_doc_header();
	init_unit_list();

	m_mode = _mode;

    // You could set an initial paper size here
//    g_printData->SetPaperId(wxPAPER_LETTER); // for Americans
    g_printData->SetPaperId(wxPAPER_A4);    // for everyone else

 //   g_pageSetupData = new wxPageSetupDialogData;
    // copy over initial paper size from print record
//    (*g_pageSetupData) = *g_printData;
    // Set some initial page margins in mm.
 //   g_pageSetupData->SetMarginTopLeft(wxPoint(0, 0));
  //  g_pageSetupData->SetMarginBottomRight(wxPoint(0, 0));



    switch(m_mode)
    {
    case 0:
        Button_ADD->Show(true);
        Button_Remove->Show(true);
        Button_Print->Show(true);
        Button_Print_Preview->Show(true);
        Button_Generate->Show(true);
        Button_contract_id->Show(true);

        scavas_label_draw = new ContractLabelDraw(this, ID_LABEL_DRAW, wxDefaultPosition, wxDefaultSize);
       StaticBoxSizer1->Add(scavas_label_draw, 1, wxALL|wxEXPAND, 0);

        break;
    case 1:
        Button_ADD->Show(true);
        Button_Remove->Show(true);
        Button_Print->Show(false);
        Button_Print_Preview->Show(false);
        Button_Generate->Show(false);
        Button_contract_id->Show(true);
        break;
    case 2:
        Button_ADD->Show(false);
        Button_Remove->Show(false);
        Button_Print->Show(false);
        Button_Print_Preview->Show(false);
        Button_Generate->Show(false);
        Button_contract_id->Show(true);
        break;
    default:
        Button_ADD->Show(false);
        Button_Remove->Show(false);
        Button_Print->Show(false);
        Button_Print_Preview->Show(false);
        Button_Generate->Show(false);
        Button_contract_id->Show(true);
        break;

    }

    Layout();
}

contract_label_print::~contract_label_print()
{
	//(*Destroy(contract_label_print)
	//*)

}

void contract_label_print::init_doc_header()
{
    wxListItem itemCol;
    itemCol.SetText(_("合同号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_contract->InsertColumn(0, itemCol);
    itemCol.SetText(_("文档号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(0);
    lv_contract->InsertColumn(1, itemCol);
    itemCol.SetText(_("Item No."));
    itemCol.SetImage(-1);
    itemCol.SetWidth(60);
    lv_contract->InsertColumn(2, itemCol);
    itemCol.SetText(_("项目号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(80);
    lv_contract->InsertColumn(3, itemCol);
    itemCol.SetText(_("项目类型"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_contract->InsertColumn(4, itemCol);
    itemCol.SetText(_("项目名称"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(300);
    lv_contract->InsertColumn(5, itemCol);
    itemCol.SetText(_("分公司"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(300);
    lv_contract->InsertColumn(6, itemCol);
    itemCol.SetText(_("prject catalog"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(0);
    lv_contract->InsertColumn(7, itemCol);

}

void contract_label_print::init_unit_list()
{
    wxListItem itemCol;
    itemCol.SetText(_("WBS NO"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_wbs->InsertColumn(0, itemCol);
    itemCol.SetText(_("梯号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_wbs->InsertColumn(1, itemCol);
    itemCol.SetText(_("项目类型"));
    itemCol.SetWidth(80);
    lv_wbs->InsertColumn(2, itemCol);
    itemCol.SetText(_("梯型编号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_wbs->InsertColumn(3, itemCol);
    itemCol.SetText(_("梯型"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_wbs->InsertColumn(4, itemCol);
}

void contract_label_print::refresh_doc_list()
{
    wxArrayLabel a_label_item;
    s_contract_label sc_label;
    wxString s_sql;
    int i_count = array_label.GetCount();

    lv_contract->DeleteAllItems();

    if(i_count >0)
    {

        s_sql = wxT("SELECT * FROM v_contract_book_header where ");
        for (int i=0; i<i_count; i++)
        {
            if( i==i_count-1)
                s_sql = s_sql + wxT(" contract_doc_id='")+array_label.Item(i)+wxT("' ");
            else
                s_sql = s_sql + wxT(" contract_doc_id='")+array_label.Item(i)+wxT("' or");
        }

        s_sql = s_sql +wxT(" and status>=0 order by project_id, item_no asc;");

        wxPostgreSQLresult * _res = wxGetApp().app_sql_select(s_sql);

        if(_res->Status()!= PGRES_TUPLES_OK)
        {
            _res->Clear();
            return;
        }

        int i_row = _res->GetRowsNumber();

        for(int j=0;j<i_row;j++)
        {
            sc_label.s_label_id = _res->GetVal(wxT("contract_doc_id"));
            sc_label.s_contract_id = _res->GetVal(wxT("contract_id"));
            sc_label.s_item_id = _res->GetVal(wxT("item_no"));
            sc_label.s_project_id = _res->GetVal(wxT("project_id"));
            sc_label.s_project_name = _res->GetVal(wxT("project_name"));

            int i_catalog = _res->GetInt(wxT("project_catalog"));
            sc_label.s_project_catalog = prj_catalog_to_str(i_catalog);

            a_label_item.Add(sc_label);

            long tmp = lv_contract->InsertItem(j, sc_label.s_contract_id );
            lv_contract->SetItemData(tmp, j);

            lv_contract->SetItem(tmp, 1, sc_label.s_label_id);
            lv_contract->SetItem(tmp, 2, sc_label.s_item_id);
            lv_contract->SetItem(tmp, 5, sc_label.s_project_name);
            lv_contract->SetItem(tmp, 3, sc_label.s_project_id);
            lv_contract->SetItem(tmp, 4, sc_label.s_project_catalog);
            lv_contract->SetItem(tmp, 6, _res->GetVal(wxT("branch_name")));
            lv_contract->SetItem(tmp, 7, NumToStr(i_catalog));


            _res->MoveNext();
        }

        _res->Clear();

    }

    if(scavas_label_draw)
    {
        scavas_label_draw->reset_label(a_label_item);
        scavas_label_draw->refresh_panel();
    }

}

void contract_label_print::refresh_units_list(wxString s_contract_label_id)
{
    lv_wbs->DeleteAllItems();
    wxString s_sql = wxT("select * from v_contract_book_include where contract_doc_id='")+s_contract_label_id+wxT("' and is_del=false order by wbs_no ASC;");
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(s_sql);
    wxString str;

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return ;
    }

    int i_count = _res->GetRowsNumber();

    if(i_count==0)
    {
        _res->Clear();
        return;
    }

    for(int i=0;i<i_count;i++)
    {

         str= _res->GetVal(wxT("wbs_no"));

        long tmp = lv_wbs->InsertItem(i, str);
        lv_wbs->SetItemData(tmp, i);

        str = _res->GetVal(wxT("lift_no"));
        lv_wbs->SetItem(tmp, 1, str);

        int i_catalog= _res->GetInt(wxT("project_catalog"));

        str = prj_catalog_to_str(i_catalog);
        lv_wbs->SetItem(tmp, 2, str);

        str = _res->GetVal(wxT("elevator_id"));
        lv_wbs->SetItem(tmp, 3, str);

        str = _res->GetVal(wxT("elevator_type"));
        lv_wbs->SetItem(tmp, 4, str);

        _res->MoveNext();
    }

    _res->Clear();
}

void contract_label_print::Onlv_contractItemSelect(wxListEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }


    long li_item = event.GetSelection();
    wxString s_label_id = lv_contract->GetItemText(li_item, 1);
    refresh_units_list(s_label_id);
}

void contract_label_print::OnButton_ADDClick(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }


     wxArrayString a_str;

     wxString str;

     str = _("合同号");
     a_str.Add(str);
     str=_("项目WBS号");
     a_str.Add(str);
     str=_("项目名称");
     a_str.Add(str);

     wf_search dlg;

     dlg.set_choice(a_str);
     int i_choice;
     wxString s_case;

     if(dlg.ShowModal()==wxID_OK)
     {
        i_choice = dlg.i_choice;
        s_case = dlg.str_search;
     }else
         return;

    wxString s_sql = wxT("SELECT contract_id, contract_doc_id,item_no,project_id,project_catalog,project_name, branch_name from v_contract_book_header where ");
    switch(i_choice)
    {
    case 0:
        s_sql= s_sql+wxT(" contract_id = '")+s_case+wxT("' ");
        break;
    case 1:
        s_sql = s_sql +wxT(" project_id like '%")+s_case + wxT("%' ");
        break;
    case 2:
        s_sql = s_sql +wxT(" project_name like '%")+s_case+wxT("%' ");
        break;
    default:
        s_sql= s_sql+wxT(" contract_id = '")+s_case+wxT("' ");
        break;
    }

    s_sql = s_sql+wxT(" and status>=0 order by project_id, item_no asc;");

    wf_listview_dlg lv_dlg(0);
    lv_dlg.init_list_header();
    lv_dlg.refresh_list(s_sql);
    wxArrayString a_sel;
    if(lv_dlg.ShowModal()==wxID_OK)
    {
        a_sel=lv_dlg.array_sel;

        int i_sel = a_sel.GetCount();

        for(int i=0;i<i_sel;i++)
        {
            str = a_sel.Item(i);

            if(array_label.Index(str)==wxNOT_FOUND)
                array_label.Add(str);

        }

        refresh_doc_list();


    }
}

void contract_label_print::OnButton_PrintClick(wxCommandEvent& event)
{
        if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }


    wxPrintDialogData printDialogData(* g_printData);

    wxPrinter printer(& printDialogData);
    MyPrintout printout(_T("标签打印"), scavas_label_draw);
    if (!printer.Print(this, &printout, true /*prompt*/))
    {
        if (wxPrinter::GetLastError() == wxPRINTER_ERROR)
            wxMessageBox(_T("There was a problem printing.\nPerhaps your current printer is not set correctly?"), _T("Printing"), wxOK);
        else
            wxMessageBox(_T("You canceled printing"), _T("Printing"), wxOK);
    }
    else
    {
        (*g_printData) = printer.GetPrintDialogData().GetPrintData();
    }
}

void contract_label_print::OnButton_Print_PreviewClick(wxCommandEvent& event)
{
        if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }


    wxPrintDialogData printDialogData(* g_printData);

    wxPrintPreview *preview = new wxPrintPreview(new MyPrintout(_("打印预览"),scavas_label_draw),new MyPrintout(_("打印预览"),scavas_label_draw), &printDialogData);
    if (!preview->Ok())
    {
        delete preview;

        wxMessageBox(_T("There was a problem previewing.\nPerhaps your current printer is not set correctly?"), _T("Previewing"), wxOK);
        return;
    }

    wxPreviewFrame *frame = new wxPreviewFrame(preview, this, _T("标签打印预览"), wxPoint(100, 100), wxSize(600, 650));
    frame->Centre(wxBOTH);
    frame->Initialize();
    frame->Show();
}

void contract_label_print::OnButton_ExitClick(wxCommandEvent& event)
{
    EndDialog(wxID_CANCEL);
}

void contract_label_print::OnButton_RemoveClick(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }


    int i_count = lv_contract->GetSelectedItemCount();

    long l_item = -1;
    l_item = lv_contract->GetNextItem(l_item,  wxLIST_NEXT_ALL,  wxLIST_STATE_SELECTED);

    while(l_item>=0)
    {
         wxString str= lv_contract->GetItemText(l_item, 1);
         array_label.Remove(str);
         lv_contract->DeleteItem(l_item);
         l_item = lv_contract->GetNextItem(l_item,  wxLIST_NEXT_ALL,  wxLIST_STATE_SELECTED);
    }

    if(i_count!=0)
    {
        refresh_doc_list();
    }
}
/*
void contract_label_print::show_control()
{



    switch(m_mode)
    {
    case 0:
        Button_ADD->Show(true);
        Button_Remove->Show(true);
        Button_Print->Show(true);
        Button_Print_Preview->Show(true);
        Button_Generate->Show(true);
        Button_contract_id->Show(true);


        break;
    case 1:
        Button_ADD->Show(true);
        Button_Remove->Show(true);
        Button_Print->Show(false);
        Button_Print_Preview->Show(false);
        Button_Generate->Show(false);
        Button_contract_id->Show(true);
        break;
    case 2:
        Button_ADD->Show(false);
        Button_Remove->Show(false);
        Button_Print->Show(false);
        Button_Print_Preview->Show(false);
        Button_Generate->Show(false);
        Button_contract_id->Show(true);
        break;
    default:
        Button_ADD->Show(false);
        Button_Remove->Show(false);
        Button_Print->Show(false);
        Button_Print_Preview->Show(false);
        Button_Generate->Show(false);
        Button_contract_id->Show(true);
        break;

    }

}*/

void contract_label_print::OnButton_contract_idClick(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }


    int i_count = lv_contract->GetSelectedItemCount();

    long l_item = -1;

    l_item = lv_contract->GetNextItem(l_item,  wxLIST_NEXT_ALL,  wxLIST_STATE_SELECTED);


    while(l_item>=0)
    {
        wxString s_contract = lv_contract->GetItemText(l_item, 0);
        if(!s_contract.IsEmpty())
        {
            l_item = lv_contract->GetNextItem(l_item,  wxLIST_NEXT_ALL,  wxLIST_STATE_SELECTED);
            continue;
        }

        wxString s_project_id= lv_contract->GetItemText(l_item, 3);
        wxString s_project_name = lv_contract->GetItemText(l_item, 5);


        wxTextEntryDialog tdlg(this, s_project_name+_(":对应合同号"), s_project_id,wxEmptyString, wxOK|wxCANCEL);
        tdlg.SetTextValidator(wxFILTER_DIGITS );

        if(tdlg.ShowModal() == wxID_OK)
        {
            s_contract = tdlg.GetValue();
            lv_contract->SetItem(l_item, 0, s_contract);
            wxGetApp().add_contract_id(s_project_id, s_contract);
        }

        l_item = lv_contract->GetNextItem(l_item,  wxLIST_NEXT_ALL,  wxLIST_STATE_SELECTED);

    }

    if(i_count!=0)
        refresh_doc_list();

}

void contract_label_print::OnButton_GenerateClick(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }


    wxArrayString a_str;

     wxString str;

     str = _("合同号");
     a_str.Add(str);
     str=_("项目WBS号");
     a_str.Add(str);
     str=_("项目名称");
     a_str.Add(str);

     wf_search dlg;

     dlg.set_choice(a_str);
     int i_choice;
     wxString s_case;

     if(dlg.ShowModal()==wxID_OK)
     {
        i_choice = dlg.i_choice;
        s_case = dlg.str_search;
     }else
         return;


    wxString s_sql = wxT("SELECT project_id, contract_id, project_name, plant, branch_name from s_project_info where ");
    switch(i_choice)
    {
    case 0:
        s_sql= s_sql+wxT(" contract_id = '")+s_case+wxT("' ");
        break;
    case 1:
        s_sql = s_sql +wxT(" project_id like '%")+s_case + wxT("%' ");
        break;
    case 2:
        s_sql = s_sql +wxT(" project_name like '%")+s_case+wxT("%' ");
        break;
    default:
        s_sql= s_sql+wxT(" contract_id = '")+s_case+wxT("' ");
        break;
    }

    s_sql = s_sql+wxT(" order by project_id asc;");

    wf_listview_dlg lv_dlg(1);
    lv_dlg.init_list_header();
    lv_dlg.refresh_list(s_sql);
    wxArrayString a_sel, a_project, a_contract;

    int i_pos, i_len;
    if(lv_dlg.ShowModal()==wxID_OK)
    {
        a_sel=lv_dlg.array_sel;

        int i_sel = a_sel.GetCount();

        for(int i=0;i<i_sel;i++)
        {
            str = a_sel.Item(i);

            i_len = str.Length();

            i_pos = str.Find(wxT("-"));

            a_project.Add(str.Left(i_pos));

            if(i_len==i_pos+1)
                a_contract.Add(wxEmptyString);
            else
                a_contract.Add(str.Right(i_len-i_pos-1));

        }

        generate_doc(a_project, a_contract);

    }
}

void  contract_label_print::generate_doc(wxArrayString &a_project,wxArrayString &a_contract_id)
{
     int i_count = a_project.GetCount();
     if(i_count==0)
        return ;

     wxString str, s_label, s_item_id;

     wxString s_sql =  wxT("INSERT INTO s_contract_book_header(contract_doc_id, project_id, item_no, modify_date, modify_emp_id, create_date, create_emp_id) \
        VALUES ");

     for(int i=0;i<i_count;i++)
     {
          str = a_project.Item(i);
          int i_item_id = get_item_no_of_doc(str)+1;

          wf_num_id_dlg ndlg(i_item_id);
          if(ndlg.ShowModal()==wxID_CANCEL)
            return;
          s_item_id = NumToStr(ndlg.m_value);
          s_label= generate_doc_id(str);
          a_contract_id.Item(i);

          array_label.Add(s_label);


          s_sql= s_sql+wxT(" ('")+s_label+wxT("','")+str+wxT("','")+s_item_id+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+
                    gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("'),");
     }

     s_sql.RemoveLast(1);
     s_sql=s_sql+wxT(";");

     if(wxGetApp().app_sql_update(s_sql))
        refresh_doc_list();

}

int contract_label_print::get_item_no_of_doc(wxString &s_project)
{
    wxString s_sql = wxT("select max(item_no) as item_id from s_contract_book_header where project_id='")+s_project+wxT("' and status>=0;");

    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(s_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return 0;
    }

    int i_count = _res->GetRowsNumber();

    if(i_count==0)
    {
        _res->Clear();
        return 0;
    }


    int i_result = _res->GetInt(wxT("item_id"));
    _res->Clear();

    return i_result;

}

wxString contract_label_print::generate_doc_id(wxString &s_project)
{
    return wxGetApp().get_ser_no(wxT("s_contract_book_header"),wxT("contract_doc_id"));
}

void contract_label_print::Onmi_catalog_switchSelected(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }


    int i_catalog,i_old_catalog;

    long l_item = -1;
    l_item = lv_contract->GetNextItem(l_item,  wxLIST_NEXT_ALL,  wxLIST_STATE_SELECTED);

    i_old_catalog = StrToInt(lv_contract->GetItemText(l_item, 7));

    if(event.IsChecked())
    {
        i_catalog = 4;
        mi_catalog_switch->Check(true);

    }else
    {
        i_catalog = 0;
        mi_catalog_switch->Check(false);
    }

    lv_contract->SetItem(l_item, 4, prj_catalog_to_str(i_catalog));

    lv_contract->SetItem(l_item,7,NumToStr(i_catalog));

    wxString s_label_id = lv_contract->GetItemText(l_item, 1);

     wxString s_sql = wxT("UPDATE s_contract_book_header SET modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("', project_catalog='")+NumToStr(i_catalog)+wxT("' where contract_doc_id ='")+
                       s_label_id+wxT("';");

     if(wxGetApp().app_sql_update(s_sql))
     {
          wxGetApp().change_log(wxT("s_contract_book_header"), s_label_id, wxT("project_catalog"), NumToStr(i_old_catalog),NumToStr(i_catalog));
          refresh_doc_list();
     }
}

void contract_label_print::Onlv_contractItemRClick(wxListEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }


    long l_item = -1;
    l_item = lv_contract->GetNextItem(l_item,  wxLIST_NEXT_ALL,  wxLIST_STATE_SELECTED);

    int i_catalog =  StrToInt(lv_contract->GetItemText(l_item, 7));

    if(i_catalog==4)
        mi_catalog_switch->Check(true);
    else
        mi_catalog_switch->Check(false);

    PopupMenu(&menu_contract, ScreenToClient(wxGetMousePosition()));
}

void contract_label_print::Onmi_add_unitSelected(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    long l_item = -1;

    l_item = lv_contract->GetNextItem(l_item,  wxLIST_NEXT_ALL,  wxLIST_STATE_SELECTED);


    if(l_item==-1)
    {
        wxMessageBox(_("请选择一个文档后再进行此操作"),_("确认"));
        return;
    }

    wxString s_doc_id = lv_contract->GetItemText(l_item, 1);
    wxString s_project_id = lv_contract->GetItemText(l_item,3 );

    if(wxMessageBox(_("此操作将向此文档中增加相关的梯台信息,\n所列的梯台均未关联任何文档。\n是否继续"),_("确认"),wxYES_NO)!=wxYES)
    {
        return;
    }

    wxString s_sql = wxT("select * from s_unit_info where project_id='")+s_project_id+wxT("' and status>=0 and wbs_no not in (select wbs_no from v_contract_book_include where project_id='")+s_project_id+wxT("' and is_del=false) order by wbs_no asc;");

    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(s_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }
    int i_count =_res->GetRowsNumber();

    if(i_count==0)
    {
        _res->Clear();
        return;
    }

    wxArrayString array_str;
    wxString str;
    for(int i=0;i<i_count;i++)
    {
        str = _res->GetVal(wxT("wbs_no"))+wxT("-[")+_res->GetVal(wxT("lift_no"))+wxT("]-")+prj_catalog_to_str(_res->GetInt(wxT("project_catalog")));
        array_str.Add(str);

       _res->MoveNext();
    }
    _res->Clear();

    nstd_app_item_units dlg;
    dlg.init_checklistbox(array_str,array_str);

    wxArrayString array_sel;

    if(dlg.ShowModal()==wxID_OK)
    {
        array_sel = dlg.array_units;
    }else
        return;

    if(array_sel.IsEmpty())
        return;


    wxString s_batch_id =  wxDateTime::Today().Format("%Y%m%d");


    s_sql = wxT("INSERT INTO s_contract_book_include(contract_doc_id, wbs_no,is_del,modify_date, modify_emp_id, create_date, create_emp_id,insert_batch_id) VALUES ");

    i_count = array_sel.GetCount();
    int i_pos;

    for(int j=0;j<i_count;j++)
    {
        str = array_sel.Item(j);

        i_pos = str.Find(wxT("-"));
        str=str.Left(i_pos);

        if(j==i_count-1)
            s_sql = s_sql+wxT("('")+s_doc_id+wxT("','")+str+wxT("',false,'")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+
                     s_batch_id+wxT("');");
        else
            s_sql =s_sql+wxT("('")+s_doc_id+wxT("','")+str+wxT("',false,'")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+
                     s_batch_id+wxT("'),");

    }
  //  wxMessageBox(s_sql);

    if(wxGetApp().app_sql_update(s_sql))
    {
        refresh_units_list(s_doc_id);
    }
}

void contract_label_print::Onmi_remove_unitSelected(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    long l_item = -1;

    l_item = lv_contract->GetNextItem(l_item,  wxLIST_NEXT_ALL,  wxLIST_STATE_SELECTED);

    if(l_item==-1)
    {
        wxMessageBox(_("请选择一个文档后再进行此操作"),_("确认"));
        return;
    }

    if(wxMessageBox(_("此操作将永久删除此文档中选择的梯台信息,是否继续"),_("确认"),wxYES_NO)!=wxYES)
    {
        return;
    }


    wxString s_doc_id = lv_contract->GetItemText(l_item, 1);

    wxArrayString array_str;

    wxString s_sql = wxT("select * from v_contract_book_include where contract_doc_id='")+s_doc_id+wxT("' and is_del=false");

    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(s_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int i_count = _res->GetRowsNumber();

    wxString str;

    for(int i=0;i<i_count;i++)
    {
        str = _res->GetVal(wxT("wbs_no"))+wxT("-[")+_res->GetVal(wxT("lift_no"))+wxT("]");

        array_str.Add(str);
        _res->MoveNext();
    }

    _res->Clear();

    nstd_app_item_units dlg;
    dlg.init_checklistbox(array_str,array_str, false);

    wxArrayString array_sel;

    if(dlg.ShowModal()==wxID_OK)
    {
        array_sel = dlg.array_units;
    }else
        return;

    if(array_sel.IsEmpty())
        return;


    s_sql = wxT("UPDATE s_contract_book_include SET is_del=true, modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("' WHERE contract_doc_id='")+s_doc_id+wxT("' and (");

    i_count = array_sel.GetCount();

    int i_pos;

    for(int j=0;j<i_count;j++)
    {
        str = array_sel.Item(j);
        i_pos = str.Find(wxT("-"));

        str= str.Left(i_pos);
        if(j==i_count-1)
        {
            s_sql = s_sql + wxT(" wbs_no='")+str+wxT("' )");
        }else
        {
             s_sql = s_sql + wxT(" wbs_no ='")+str+wxT("' or ");
        }
    }

    if(wxGetApp().app_sql_update(s_sql))
    {
        refresh_units_list(s_doc_id);
    }

}

void contract_label_print::Onmi_del_docSelected(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(wxMessageBox(_("此操作将永久删除此文档记录,是否继续"),_("确认"),wxYES_NO)!=wxYES)
    {
        return;
    }

    long l_item = -1;

    int i_count = lv_contract->GetSelectedItemCount();
    l_item = lv_contract->GetNextItem(l_item,  wxLIST_NEXT_ALL,  wxLIST_STATE_SELECTED);
    wxString s_sql;

    wxString s_sql_header = wxT("UPDATE s_contract_book_header SET status=-1,modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("' WHERE ");
    wxString s_sql_unit_header = wxT("UPDATE s_contract_book_include SET is_del=true, modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("' WHERE is_del=false and ");
    while(l_item>=0)
    {
          wxString s_doc_id= lv_contract->GetItemText(l_item, 1);

          wxString s_sql_tail=wxT("  contract_doc_id ='")+s_doc_id+wxT("';");
          s_sql = s_sql_header+s_sql_tail;

          if(wxGetApp().app_sql_update(s_sql))
          {
                s_sql = s_sql_unit_header+s_sql_tail;

                array_label.Remove(s_doc_id);
                lv_contract->DeleteItem(l_item);
                wxGetApp().app_sql_update(s_sql);

                wxLogMessage(s_doc_id+_("文档删除成功!"));
          }



          l_item = lv_contract->GetNextItem(l_item,  wxLIST_NEXT_ALL,  wxLIST_STATE_SELECTED);

    }

    if(i_count!=0)
    {
         refresh_doc_list();
    }

}
