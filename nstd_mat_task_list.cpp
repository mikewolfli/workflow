#include "nstd_mat_task_list.h"
#include <wx/tokenzr.h>
#include "nstd_task_author.h"
#include "wfApp.h"
#include "pugixml.hpp"
#include "nstd_app_item_units.h"
#include <wx/filefn.h>

//(*InternalHeaders(nstd_mat_task_list)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(nstd_mat_task_list)
const long nstd_mat_task_list::ID_GRID_TASK_LIST = wxNewId();
const long nstd_mat_task_list::ID_BUTTON1 = wxNewId();
const long nstd_mat_task_list::ID_BUTTON2 = wxNewId();
const long nstd_mat_task_list::ID_BUTTON3 = wxNewId();
const long nstd_mat_task_list::IdMenu_Info = wxNewId();
//*)

BEGIN_EVENT_TABLE(nstd_mat_task_list,wxDialog)
	//(*EventTable(nstd_mat_task_list)
	//*)
END_EVENT_TABLE()

nstd_mat_task_list::nstd_mat_task_list(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(nstd_mat_task_list)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("清单"));
	gd_task_list = new sqlResultGrid(this, ID_GRID_TASK_LIST, wxDefaultPosition, wxSize(838,240));
	StaticBoxSizer1->Add(gd_task_list, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer1->Add(StaticBoxSizer1, 8, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button_OK = new wxButton(this, ID_BUTTON1, _("确定"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button_OK, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Cancel = new wxButton(this, ID_BUTTON2, _("取消"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button_Cancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Export = new wxButton(this, ID_BUTTON3, _("导出清单"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer2->Add(Button_Export, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	MenuItem1 = new wxMenuItem((&menu_units), IdMenu_Info, _("项目信息(&S)"), _("项目信息"), wxITEM_NORMAL);
	menu_units.Append(MenuItem1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_GRID_TASK_LIST,wxEVT_GRID_CELL_RIGHT_CLICK,(wxObjectEventFunction)&nstd_mat_task_list::Ongd_task_listCellRightClick);
	Connect(ID_GRID_TASK_LIST,wxEVT_GRID_LABEL_RIGHT_CLICK,(wxObjectEventFunction)&nstd_mat_task_list::Ongd_task_listCellRightClick);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_task_list::OnButton_OKClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_task_list::OnButton_CancelClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_task_list::OnButton_ExportClick);
	Connect(IdMenu_Info,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&nstd_mat_task_list::OnMenuItem1Selected);
	//*)



//	init_list_header();

}

nstd_mat_task_list::~nstd_mat_task_list()
{
	//(*Destroy(nstd_mat_task_list)
	//*)
}


void nstd_mat_task_list::OnButton_OKClick(wxCommandEvent& event)
{
    if(!m_search_mode)
    {
        wxArrayInt array_sel_line = gd_task_list->GetSelectedRows();
        if(array_sel_line.IsEmpty())
        {
            wxMessageBox(_("尚未选择项目，无法后续操作!"), _("提示"), wxOK);
            return;
        }

        if(array_sel_line.GetCount() !=1)
        {
            wxMessageBox(_("一次只能选择一个任务，请取消多余任务"), _("提示"), wxOK);
            gd_task_list->ClearSelection();
            return;
        }

        m_index_id = gd_task_list->GetCellValue(array_sel_line.Item(0), 0);
        wxString str_units_list = gd_task_list->GetCellValue(array_sel_line.Item(0), 8);
        if(!str_units_list.IsEmpty())
            m_units = wxStringTokenize(str_units_list ,wxT(";"), wxTOKEN_DEFAULT  );
        else m_units.Clear();
    }
    EndDialog(wxID_OK);
}

void nstd_mat_task_list::OnButton_CancelClick(wxCommandEvent& event)
{
    EndDialog(wxID_CANCEL);
}

void nstd_mat_task_list::init_nstd_item_header()
{
    int i_cols = gd_task_list->GetNumberCols();
    for(int i=0;i<i_cols ;i++)
    {
        gd_task_list->DeleteCols(i);
    }

    if(gd_task_list->GetNumberCols()!=9)
    {
        gd_task_list->CreateGrid(0,9);
        gd_task_list->SetRowLabelSize(20);
        gd_task_list->SetColLabelValue(0,_("非标编号"));
        gd_task_list->SetColSize(0,80);

        gd_task_list->SetColLabelValue(1,_("项目信息"));
        gd_task_list->SetColSize(1,100);

        gd_task_list->SetColLabelValue(2,_("物料\n需求日"));
        gd_task_list->SetColSize(2,80);

        gd_task_list->SetColLabelValue(3,_("图纸\n需求日"));
        gd_task_list->SetColSize(3,80);

        gd_task_list->SetColLabelValue(4,_("非标类别"));
        gd_task_list->SetColSize(4,80);

        gd_task_list->SetColLabelValue(5,_("非标原因"));
        gd_task_list->SetColSize(5,100);

        gd_task_list->SetColLabelValue(6,_("分值分布"));
        gd_task_list->SetColSize(6,100);

        gd_task_list->SetColLabelValue(7,_("非标负责人"));
        gd_task_list->SetColSize(7,100);


        gd_task_list->SetColLabelValue(8,_("关联梯"));
        gd_task_list->SetColSize(8,0);

        for(int i=0; i<9; i++)
        {
            str_tasks_header = str_tasks_header + gd_task_list->GetColLabelValue(i)+wxT(";");
        }

    }
    m_search_mode = false;
}

void nstd_mat_task_list::init_nstd_mat_instance_header()
{
    if(gd_task_list->GetNumberCols()!=12)
    {
        gd_task_list->CreateGrid(0,12);
        gd_task_list->SetRowLabelSize(20);
        gd_task_list->SetColLabelValue(0,_("非标任务编号"));
        gd_task_list->SetColSize(0,80);

        gd_task_list->SetColLabelValue(1,_("项目信息"));
        gd_task_list->SetColSize(1,100);

        gd_task_list->SetColLabelValue(2,_("物料\n需求日"));
        gd_task_list->SetColSize(2,80);

        gd_task_list->SetColLabelValue(3,_("图纸\n需求日"));
        gd_task_list->SetColSize(3,80);

        gd_task_list->SetColLabelValue(4,_("非标类别"));
        gd_task_list->SetColSize(4,80);

        gd_task_list->SetColLabelValue(5,_("非标原因"));
        gd_task_list->SetColSize(5,100);

        gd_task_list->SetColLabelValue(6,_("分值分布"));
        gd_task_list->SetColSize(6,100);

        gd_task_list->SetColLabelValue(7,_("非标负责人"));
        gd_task_list->SetColSize(7,100);

        gd_task_list->SetColLabelValue(8,_("分任务描述"));
        gd_task_list->SetColSize(8,100);

        gd_task_list->SetColLabelValue(9,_("分任务非标工程师"));
        gd_task_list->SetColSize(9,100);

        gd_task_list->SetColLabelValue(10,_("分任务状态"));
        gd_task_list->SetColSize(10,80);

        gd_task_list->SetColLabelValue(11,_("关联梯"));
        gd_task_list->SetColSize(11,0);

        for(int i=0; i<12; i++)
        {
            str_tasks_header = str_tasks_header + gd_task_list->GetColLabelValue(i)+wxT(";");
        }

    }

}

void nstd_mat_task_list::init_nstd_mat_header()
{
    int i_cols = gd_task_list->GetNumberCols();
    for(int i=0;i<i_cols ;i++)
    {
        gd_task_list->DeleteCols(i);
    }
    m_search_mode = true;

    if(gd_task_list->GetNumberCols()!=9)
    {
        gd_task_list->CreateGrid(0,9);
        gd_task_list->SetRowLabelSize(20);
        gd_task_list->SetColLabelValue(0,_("非标编号"));
        gd_task_list->SetColSize(0,0);

        gd_task_list->SetColLabelValue(1,_("序号"));
        gd_task_list->SetColSize(1,50);

        gd_task_list->SetColLabelValue(2,_("位置号"));
        gd_task_list->SetColSize(2,80);

        gd_task_list->SetColLabelValue(3,_("物料号"));
        gd_task_list->SetColSize(3,80);

        gd_task_list->SetColLabelValue(4,_("物料名称"));
        gd_task_list->SetColSize(4,100);

        gd_task_list->SetColLabelValue(5,_("数量"));
        gd_task_list->SetColSize(5,50);

        gd_task_list->SetColLabelValue(6,_("单位"));
        gd_task_list->SetColSize(6,50);

        gd_task_list->SetColLabelValue(7,_("备注"));
        gd_task_list->SetColSize(7,200);

        gd_task_list->SetColLabelValue(8,_("相关梯号"));
        gd_task_list->SetColSize(8,100);

        for(int i=0; i<9; i++)
        {
            str_tasks_header = str_tasks_header + gd_task_list->GetColLabelValue(i)+wxT(";");
        }

    }

}

void nstd_mat_task_list::refresh_list(int i_use)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }

    if(!wxGetApp().conn->IsAlive())
    {
        wxLogMessage(_("系统连接已断开,请重新连接!"));
        wxGetApp().clear_login();
        return;
    }
 /*   wxString strSql = wxT("SELECT index_id, concat(contract_id,' ', project_name,'-',project_id) as project_name, mat_req_date, drawing_req_date, \
                          nonstd_catalog, nonstd_desc, nonstd_value, (select name from s_employee where employee_id = res_person) as engineering,\
                          link_list from v_task_list2 ") + m_where_clause;*/
                          //where action_id = 'AT00000022' and is_active = true and operator_id ='")+gr_para.login_user+wxT("' \order by index_id ASC;");
    wxPostgreSQLresult* _res;
     _res = wxGetApp().app_sql_select(m_query);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    wxGridUpdateLocker locker(gd_task_list);
    gd_task_list->ClearGrid();

//    gd_task_list->BeginBatch();

    wxString str_table= wxT("l_nonstd_app_item");
    gd_task_list->SetTable(new sqlResultTable(_res, str_table, str_tasks_header, i_use), true);
    gd_task_list->SetSelectionMode(wxGrid::wxGridSelectRows);
    gd_task_list->Fit();

 //   gd_task_list->EndBatch();

    //gd_task_list->SetColSize(8,0);
    Layout();
    _res->Clear();


}

void nstd_mat_task_list::OnMenuItem1Selected(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_task_list->GetSelectedRows();
    if(array_sel_line.IsEmpty())
    {
        wxMessageBox(_("尚未选择项目，无法后续操作!"), _("提示"), wxOK);
        return;
    }


    int i_count = array_sel_line.GetCount();

    wxArrayString array_units;

    for(int i=0;i<i_count;i++)
    {
        wxString str = gd_task_list->GetCellValue(array_sel_line.Item(i),8);

        if(str.IsEmpty())
            continue;

        wxArrayString array_str = wxStringTokenize(str ,wxT(";"), wxTOKEN_DEFAULT  );

        for(int j=0;j<array_str.GetCount();j++)
        {
            if(find_in_array(array_str.Item(j),array_units)==-1)
                array_units.Add(array_str.Item(j));
        }

        array_str.Clear();
    }

    nstd_task_author dlg;

    dlg.m_units = array_units;
    dlg.refresh_list();
    dlg.ShowModal();
}

void nstd_mat_task_list::Ongd_task_listCellRightClick(wxGridEvent& event)
{
    PopupMenu(&menu_units, event.GetPosition());
}

void nstd_mat_task_list::OnButton_ExportClick(wxCommandEvent& event)
{/*
     wxString s_path = get_out_path();

     if(!wxDirExists(s_path))
        wxMkDir(s_path);*/

    wxFileDialog     saveFileDialog(this, _("Save xls file"), "", "",
                                       "xls files (*.xls)|*.xls", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...

    wxString s_path = saveFileDialog.GetPath();

     get_array_units();

     if(m_units.IsEmpty())
     {
         return;
     }

  //   m_units.Sort(function_sort);
   //  m_units.Sort(true);

     wxArrayString array_sel;

    nstd_app_item_units dlg;
    wxString str_units;

    dlg.init_checklistbox(m_units, m_units, false);

    if(dlg.ShowModal() == wxID_OK)
    {
        str_units = dlg.m_units;

    }
    else
        return;

    array_sel = wxStringTokenize(str_units ,wxT(";"), wxTOKEN_DEFAULT  );

    int i_count = array_sel.GetCount();

    if(i_count ==0)
        return;

    //s_path = create_project_folder(array_sel.Item(0),s_path);

    init_array_head();

    for(int i=0;i<i_count;i++)
    {
        export_excel(array_sel.Item(i),s_path);
    }

}

void nstd_mat_task_list::export_excel(wxString s_wbs_no, wxString str_path)
{
    wxString str_sql = wxT("SELECT * FROM  v_nonstd_configure_mat_list where link_list like'%")+s_wbs_no+wxT("%' and status != '-1'");

    wxPostgreSQLresult* _res;
     _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    workbook wb1;
    worksheet* ws = wb1.sheet("Sheet1");

    int i;
    int i_count = _res->GetRowsNumber();

    for(i=0;i<8;i++)
    {
        ws->label(0,i,array_head.Item(i).ToStdString());
        ws->label(1,i,array_alias.Item(i).ToStdWstring());
    }

    for(i=0;i<i_count;i++)
    {
       ws->label(i+2,0, zero_begin(i+1,4).ToStdString());
       label_result(i+2,ws,_res);
       _res->MoveNext();
    }
/*
    wxString s_file = s_wbs_no;

    s_file.Replace(wxT("\\"),wxT(""));
    s_file.Replace(wxT("/"),wxT(""));
    s_file.Replace(wxT("."),wxT("_"));

    s_file = str_path + wxT("\\")+s_file+wxT(".xls");*/

    std::string filename = str_path.ToStdString();
    int error_msg = wb1.Dump(filename);

    if(error_msg == NO_ERRORS)
    {
            wxLogMessage(s_wbs_no+_("物料输出完成!"));
    }

}

void nstd_mat_task_list::show_control(bool b_show)
{
    Button_Cancel->Show(b_show);
    Button_Export->Show(!b_show);
}

// only for bom list out to excel
void nstd_mat_task_list::get_array_units()
{
    m_units.Clear();
    int i_count = gd_task_list->GetNumberRows();

    wxString str;

    for(int i=0;i<i_count;i++)
    {
        str = gd_task_list->GetCellValue(i,8);

        if(str.IsEmpty())
            continue;

        wxArrayString array_str = wxStringTokenize(str ,wxT(";"), wxTOKEN_DEFAULT  );

        for(int j=0;j<array_str.GetCount();j++)
        {
            if(find_in_array(array_str.Item(j),m_units)==-1)
                m_units.Add(array_str.Item(j));
        }

        array_str.Clear();

    }
}

//0-文本， 1-中文文本， 2-数字(int), 3 数字（double) ，4- bool, 5 -date , 6 -公式， 7-超链接
void nstd_mat_task_list::init_array_head()
{
    wxString str_head, str, str_alias;
    int i_format;
    for(int i=0;i<8;i++)
    {
       switch(i)
       {
     case 0:
          str_head = _("Sequence");
          str = wxT("sequence");
          str_alias = wxT("序 号\n（必须4位数字）");
          i_format = 0;
          break;
     case 1:
          str_head = _("St. No.");
          str=wxT("stno");
          str_alias = wxT("位置号\n（必填）");
          i_format = 0;
          break;
     case 2:
          str_head = _("English Part Name");
          str= wxT("mat_name_en");
          str_alias = wxT("英       文      名      称 ");
          i_format = 0;
          break;
     case 3:
          str_head = _("Chinese Part Name");
          str = wxT("mat_name_cn");
          str_alias = wxT("中       文       名       称");
          i_format = 1;
          break;
     case 4:
          str_head = _("Part No.");
          str =  wxT("mat_id");
          str_alias = wxT("物      号\n（必填）");
          i_format = 0;
          break;
     case 5:
          str_head = _("Total");
          str = wxT("qty");
          str_alias = wxT("数 量\n（必填）");
          i_format = 1;
          break;
     case 6:
          str_head = _("Unit");
          str = wxT("unit");
          i_format = 0;
          break;
     case 7:
          str_head = _("BOM Remarks");
          str = wxT("mat_comment");
          str_alias = wxT("BOM    备      注\n（需要备注的必填）");
          i_format = 1;
          break;
     default:
          str_head.Empty();
          str.Empty();
          str_alias.Empty();
          i_format = 0;
          break;

       }
       array_head.Add(str_head);
       array_str.Add(str);
       array_alias.Add(str_alias);
       array_format.Add(i_format);
    }
}

void nstd_mat_task_list::label_result(int irow,worksheet* _ws, wxPostgreSQLresult * _res)
{
    for(int i = 1; i<8;i++)
    {
      if(array_format.Item(i)== 0)
        {
             _ws->label(irow, i, _res->GetVal(array_str.Item(i)).ToStdString());
        }

        if(array_format.Item(i)== 1)
        {
            _ws->label(irow,i, _res->GetVal(array_str.Item(i)).ToStdWstring());
        }

        if(array_format.Item(i) == 2)
        {
            _ws->number(irow,i,atoi(_res->GetVal(array_str.Item(i)).ToAscii()));
        }


        if(array_format.Item(i) == 3)
        {
            _ws->number(irow,i,StrToDouble(_res->GetVal(array_str.Item(i))));
        }

        if(array_format.Item(i) == 5)
        {
            _ws->label(irow,i, _res->GetVal(array_str.Item(i)).ToStdString());
        }
    }
}

wxString nstd_mat_task_list::get_out_path()
{
    pugi::xml_document m_doc;
    pugi::xml_node ld_node;
    pugi::xml_parse_result result;

    wxString s_result;
    result = m_doc.load_file("config.xml");
    if (result)
    {
        pugi::xml_node ld_node = m_doc.child("export");
        s_result = wxString(ld_node.child_value("configuredBOM"),wxConvUTF8);
    }
    else
    {
        s_result=wxT("C:\\export_nstd\\");
    }

    return s_result;

}

wxString nstd_mat_task_list::create_project_folder(wxString s_wbs_no, wxString s_loc)
{
    wxString s_folder;

    wxString str_sql = wxT("SELECT concat(contract_id,'-', project_name,'-',project_id) as project_name from v_unit_info where wbs_no = '")+s_wbs_no+wxT("';");

    wxPostgreSQLresult* _res;
     _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return wxEmptyString;
    }

    int i_count = _res->GetRowsNumber();

    if(i_count ==0)
    {
        _res->Clear();
        return wxEmptyString;
    }

    _res->MoveFirst();
    s_folder = _res->GetVal(wxT("project_name"));
    _res->Clear();

    s_folder.Replace(wxT("/"),wxT(""));
    s_folder.Replace(wxT("\\"),wxT(""));
    s_folder.Replace(wxT("."),wxT("_"));

    s_folder = s_loc+s_folder;

    if(!wxDirExists(s_folder))
        wxMkDir(s_folder);

    return s_folder;
}
