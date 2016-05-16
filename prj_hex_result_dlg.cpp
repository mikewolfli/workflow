
#include <wx/filedlg.h>

#include "prj_hex_result_dlg.h"
#include "xlslib.h"

using namespace xlslib_core;
//(*InternalHeaders(prj_hex_result_dlg)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(prj_hex_result_dlg)
const long prj_hex_result_dlg::ID_LISTVIEW_LIST = wxNewId();
const long prj_hex_result_dlg::ID_BUTTON_OK = wxNewId();
const long prj_hex_result_dlg::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(prj_hex_result_dlg,wxDialog)
	//(*EventTable(prj_hex_result_dlg)
	//*)
END_EVENT_TABLE()

prj_hex_result_dlg::prj_hex_result_dlg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(prj_hex_result_dlg)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("列表"));
	lv_list = new wxListView(this, ID_LISTVIEW_LIST, wxDefaultPosition, wxSize(598,234), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTVIEW_LIST"));
	StaticBoxSizer1->Add(lv_list, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(StaticBoxSizer1, 5, wxALL|wxEXPAND, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON_OK, _("确定"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_OK"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("导出"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&prj_hex_result_dlg::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&prj_hex_result_dlg::OnButton2Click);
	//*)
	init_list_head();
}

prj_hex_result_dlg::~prj_hex_result_dlg()
{
	//(*Destroy(prj_hex_result_dlg)
	//*)
	array_hex.Clear();
}


void prj_hex_result_dlg::OnButton1Click(wxCommandEvent& event)
{
    EndDialog(wxID_OK);
}

void prj_hex_result_dlg::OnButton2Click(wxCommandEvent& event)
{
    int i_count = lv_list->GetItemCount();

    if(i_count==0)
    {
        wxLogMessage(_("表格内无任何内容，无法输出!"));
        return;
    }

    wxFileDialog     saveFileDialog(this, _("Save xls file"), "", "",
                                       "xls files (*.xls)|*.xls", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...

    wxString str_file = saveFileDialog.GetPath();

    save_file(str_file);

}

void prj_hex_result_dlg::init_list_head()
{
    wxListItem itemCol;

    itemCol.SetText(_("WBS NO"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_list->InsertColumn(0, itemCol);
    itemCol.SetText(_("随行电缆\n物号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_list->InsertColumn(1, itemCol);
    itemCol.SetText(_("随行电缆描述"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(200);
    lv_list->InsertColumn(2, itemCol);
    itemCol.SetText(_("随行电缆\n单重HEX"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_list->InsertColumn(3, itemCol);
    itemCol.SetText(_("钢丝绳物号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_list->InsertColumn(4, itemCol);
    itemCol.SetText(_("钢丝绳描述"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(200);
    lv_list->InsertColumn(5, itemCol);
    itemCol.SetText(_("钢丝绳\n单重HEX"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_list->InsertColumn(6, itemCol);
    itemCol.SetText(_("补偿链物号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_list->InsertColumn(7, itemCol);
    itemCol.SetText(_("补偿链描述"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(200);
    lv_list->InsertColumn(8, itemCol);
    itemCol.SetText(_("补偿链\n单重HEX"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_list->InsertColumn(9, itemCol);

    wxString str = _("WBS NO");
    array_head.Add(str);

    str=_("随行电缆物号");
    array_head.Add(str);

    str = _("随行电缆描述");
    array_head.Add(str);

    str = _("随行电缆单重HEX");
    array_head.Add(str);

    str = _("钢丝绳物号");
    array_head.Add(str);

    str = _("钢丝绳描述");
    array_head.Add(str);

    str=_("钢丝绳单重HEX");
    array_head.Add(str);

     str =_("补偿链物号");
     array_head.Add(str);

     str = _("补偿链描述");
     array_head.Add(str);

     str = _("补偿链单重HEX");
     array_head.Add(str);
}

void prj_hex_result_dlg::refresh_list()
{
    if(array_hex.IsEmpty())
        return;

    int i_count = array_hex.GetCount();

    for(int i=0; i<i_count; i++)
    {
        s_sap_hex_info s_hex=array_hex.Item(i);
        long  tmp = lv_list->InsertItem(i, s_hex.s_wbs);
        lv_list->SetItemData(tmp, i);

        lv_list->SetItem(tmp, 1, s_hex.s_tc_mat);

        lv_list->SetItem(tmp, 2, s_hex.s_tc_mat_name);
        lv_list->SetItem(tmp, 3, s_hex.s_tc_hex);

        lv_list->SetItem(tmp, 4, s_hex.s_rope_mat);
        lv_list->SetItem(tmp, 5, s_hex.s_rope_name);
        lv_list->SetItem(tmp, 6, s_hex.s_rope_hex);

        lv_list->SetItem(tmp, 7, s_hex.s_cchain_mat);
        lv_list->SetItem(tmp, 8, s_hex.s_cchain_name);
        lv_list->SetItem(tmp, 9, s_hex.s_cchain_hex);
    }

}

void prj_hex_result_dlg::save_file(wxString s_file)
{
    int i_count = lv_list->GetItemCount();

    int i_col = array_head.GetCount();

    wxListItem li_item;
    wxString str;

    workbook wb1;
    worksheet* ws = wb1.sheet("Sheet1");
    int i,j;

    for(i=0;i<i_col;i++)
    {
        str = array_head.Item(i);
        ws->label(0,i,str.ToStdWstring());
    }

    long l_item;

    for(i=0;i<i_count;i++)
    {
        for(j=0;j<i_col;j++)
        {
            str = lv_list->GetItemText(i,j);

            ws->label(i+1,j,str.ToStdWstring());
        }
    }

    std::string filename = s_file.ToStdString();
    int error_msg = wb1.Dump(filename);

    if(error_msg == NO_ERRORS)
    {
           wxMessageBox(_("导出完成!"),_("提示"));
    }
}
