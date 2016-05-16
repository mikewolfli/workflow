#include "ndo_generator_panel.h"
#include "pugixml.hpp"
#include "wfApp.h"

//(*InternalHeaders(ndo_generator_panel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(ndo_generator_panel)
const long ndo_generator_panel::ID_STATICTEXT1 = wxNewId();
const long ndo_generator_panel::ID_COMBOBOX_COMPONENTS_CLASSIFICATION = wxNewId();
const long ndo_generator_panel::ID_STATICTEXT2 = wxNewId();
const long ndo_generator_panel::ID_COMBOBOX_COMPONENTS = wxNewId();
const long ndo_generator_panel::ID_STATICTEXT3 = wxNewId();
const long ndo_generator_panel::ID_TEXTCTRL_ID = wxNewId();
const long ndo_generator_panel::ID_STATICTEXT4 = wxNewId();
const long ndo_generator_panel::ID_TEXTCTRL_FILE_ID = wxNewId();
const long ndo_generator_panel::ID_STATICTEXT5 = wxNewId();
const long ndo_generator_panel::ID_TEXTCTRL_FILE_NAME = wxNewId();
const long ndo_generator_panel::ID_STATICTEXT6 = wxNewId();
const long ndo_generator_panel::ID_TEXTCTRL_REMARKS = wxNewId();
const long ndo_generator_panel::ID_BUTTON_GENERATE = wxNewId();
const long ndo_generator_panel::ID_BUTTON_CLEAR = wxNewId();
//*)

BEGIN_EVENT_TABLE(ndo_generator_panel,wxPanel)
	//(*EventTable(ndo_generator_panel)
	//*)
END_EVENT_TABLE()

ndo_generator_panel::ndo_generator_panel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ndo_generator_panel)
	wxGridBagSizer* GridBagSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("填写信息"));
	GridBagSizer1 = new wxGridBagSizer(0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("组分类"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	GridBagSizer1->Add(StaticText1, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbb_comp_cli = new wxComboBox(this, ID_COMBOBOX_COMPONENTS_CLASSIFICATION, wxEmptyString, wxDefaultPosition, wxSize(487,21), 0, 0, wxCB_READONLY|wxCB_DROPDOWN, wxDefaultValidator, _T("ID_COMBOBOX_COMPONENTS_CLASSIFICATION"));
	GridBagSizer1->Add(cbb_comp_cli, wxGBPosition(0, 1), wxGBSpan(1, 4), wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("部件"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	GridBagSizer1->Add(StaticText2, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cbb_components = new wxComboBox(this, ID_COMBOBOX_COMPONENTS, wxEmptyString, wxDefaultPosition, wxSize(484,21), 0, 0, wxCB_READONLY|wxCB_DROPDOWN, wxDefaultValidator, _T("ID_COMBOBOX_COMPONENTS"));
	GridBagSizer1->Add(cbb_components, wxGBPosition(1, 1), wxGBSpan(1, 4), wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("非标指令"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	GridBagSizer1->Add(StaticText3, wxGBPosition(2, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_id = new wxTextCtrl(this, ID_TEXTCTRL_ID, wxEmptyString, wxDefaultPosition, wxSize(202,21), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_ID"));
	GridBagSizer1->Add(tc_id, wxGBPosition(2, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("文件号"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	GridBagSizer1->Add(StaticText4, wxGBPosition(2, 2), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_file_id = new wxTextCtrl(this, ID_TEXTCTRL_FILE_ID, wxEmptyString, wxDefaultPosition, wxSize(230,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_FILE_ID"));
	GridBagSizer1->Add(tc_file_id, wxGBPosition(2, 3), wxGBSpan(1, 2), wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("文件名称"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	GridBagSizer1->Add(StaticText5, wxGBPosition(3, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_file_name = new wxTextCtrl(this, ID_TEXTCTRL_FILE_NAME, wxEmptyString, wxDefaultPosition, wxSize(486,47), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL_FILE_NAME"));
	GridBagSizer1->Add(tc_file_name, wxGBPosition(3, 1), wxGBSpan(2, 4), wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("备注"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	GridBagSizer1->Add(StaticText6, wxGBPosition(5, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_remarks = new wxTextCtrl(this, ID_TEXTCTRL_REMARKS, wxEmptyString, wxDefaultPosition, wxSize(484,34), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL_REMARKS"));
	GridBagSizer1->Add(tc_remarks, wxGBPosition(5, 1), wxGBSpan(2, 4), wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(GridBagSizer1, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(StaticBoxSizer1, 4, wxALL|wxEXPAND, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button_generator = new wxButton(this, ID_BUTTON_GENERATE, _("指令生成"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_GENERATE"));
	BoxSizer2->Add(Button_generator, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Clear = new wxButton(this, ID_BUTTON_CLEAR, _("清空"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CLEAR"));
	BoxSizer2->Add(Button_Clear, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_LEFT, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_COMBOBOX_COMPONENTS_CLASSIFICATION,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&ndo_generator_panel::Oncbb_comp_cliSelected);
	Connect(ID_BUTTON_GENERATE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ndo_generator_panel::OnButton_generatorClick);
	Connect(ID_BUTTON_CLEAR,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ndo_generator_panel::OnButton_ClearClick);
	//*)

    init_ccb_cli();
}

ndo_generator_panel::~ndo_generator_panel()
{
	//(*Destroy(ndo_generator_panel)
	//*)
}


void ndo_generator_panel::OnButton_generatorClick(wxCommandEvent& event)
{
    	if (!gr_para.login_status)
	{
		wxLogMessage(_("尚未登陆,不能进行任何操作!"));
		return;
	}

    wxArrayString array_group = wxGetApp().get_group();
    wxString str;

    if(array_group.Index(wxT("G0006"))==wxNOT_FOUND&&array_group.Index(wxT("G0007"))==wxNOT_FOUND)
    {
        wxLogMessage(_("此功能仅非标组有权限使用，其他人员无权使用"));
        return;
    }

    if(cbb_comp_cli->GetSelection()==wxNOT_FOUND)
    {
        wxLogMessage(_("请无比选择组分类，否则无法生成ID号"));
        return;
    }

    if(!tc_id->IsEmpty())
    {
        wxLogMessage(_("请先清空原来ID后，再生成新ID"));
        return;
    }

    wxString  s_pos = cbb_comp_cli->GetValue().Left(2);

    wxString s_prefix = wxT("NDO-")+s_pos;
    int i_serial = get_serial(s_prefix)+1;

    wxString s_ndo_id = s_prefix+wxT("-")+wxDateTime::Today().Format(wxT("%Y%m%d"))+wxT("-")+zero_begin(i_serial, 3);
    wxString s_direct_leader = get_direct_leader();
    wxString s_file_name = tc_file_name->GetValue();
    wxString s_file_id = tc_file_id->GetValue();

    wxString s_sql = wxT("INSERT INTO s_nstd_design_order(ndo_id, components_classification, nid_components, file_name, file_id, apply_person, res_supervior, apply_date, remarks) VALUES ('")+s_ndo_id+wxT("','")+
                         cbb_comp_cli->GetValue()+wxT("', '")+cbb_components->GetValue()+wxT("','")+s_file_name+wxT("','")+s_file_id+wxT("','")+gr_para.login_user+wxT("','")+s_direct_leader+wxT("','")+DateToAnsiStr(wxDateTime::Now())+
                          wxT("','")+tc_remarks->GetValue()+wxT("');");
    if(wxGetApp().app_sql_update(s_sql))
    {
        tc_id->SetValue(s_ndo_id);
        wxLogMessage(_("非标设计指令号获取成功:")+s_ndo_id);
    }

}

int ndo_generator_panel::get_serial(wxString s_prefix)
{
    wxString s_sql = wxT("SELECT count(*) as count  FROM s_nstd_design_order where ndo_id like '")+s_prefix+wxT("%';");

    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(s_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return 0;
    }

    int i_rel = _res->GetInt(wxT("count"));

    _res->Clear();

    return i_rel;
}

wxString ndo_generator_panel::get_direct_leader()
{
    wxString s_sql = wxT("SELECT *  FROM s_hierarchy where employee_id= '")+gr_para.login_user+wxT("';");

    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(s_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return wxEmptyString;
    }

    int i_count = _res->GetRowsNumber();

    if(i_count==0)
        return wxEmptyString;

    wxString str = _res->GetVal(wxT("direct_leader"));

    _res->Clear();

    return str;
}

void ndo_generator_panel::OnButton_ClearClick(wxCommandEvent& event)
{
    tc_id->Clear();
  //  cbb_comp_cli->SetSelection(-1);
  //  cbb_components->SetSelection(-1);
  //  tc_file_id->Clear();
  //  tc_file_name->Clear();
}

void  ndo_generator_panel::init_ccb_cli()
{
    pugi::xml_document m_doc;
    pugi::xml_node lnode, litem;
    pugi::xml_node lbranch;
    pugi::xml_parse_result result;

    wxString s_pos, s_name, str;

    result = m_doc.load_file("sjce_design.xml");
    if (result)
    {
        lnode = m_doc.child("groups");

        for(litem=lnode.first_child(); litem ;litem=litem.next_sibling())
        {

            if(wxString(litem.attribute("lang").value())==wxT("cn"))
                break;
        }

         if(litem==NULL)
         {
             return;
         }


        for(lbranch=litem.first_child();lbranch;lbranch=lbranch.next_sibling())
        {
            s_pos = wxString(lbranch.attribute("pos").value());
            s_name = wxString(lbranch.attribute("name").value());

            str= s_pos + wxT(" ")+s_name;

            cbb_comp_cli->Append(str);

        }

    }
    else
    {
        wxLogMessage(_("初始化控件失败!"));
    }


    return ;

}

void  ndo_generator_panel::init_ccb_components(wxString s_pos)
{
    pugi::xml_document m_doc;
    pugi::xml_node lnode, litem;
    pugi::xml_node lbranch, lleaf;
    pugi::xml_parse_result result;

    wxString spos,s_nid, s_name, str;
    cbb_components->Clear();

    result = m_doc.load_file("sjce_design.xml");
    if (result)
    {
        lnode = m_doc.child("groups");

        for(litem=lnode.first_child(); litem ;litem=litem.next_sibling())
        {

            if(wxString(litem.attribute("lang").value())==wxT("cn"))
                break;
        }

         if(litem==NULL)
         {
             return;
         }


        for(lbranch=litem.first_child();lbranch;lbranch=lbranch.next_sibling())
        {
            spos = wxString(lbranch.attribute("pos").value());
            if(spos==s_pos)
                break;
        }

        for(lleaf=lbranch.first_child();lleaf;lleaf=lleaf.next_sibling())
        {
            s_nid = wxString(lleaf.attribute("nid").value());
            s_name = wxString(lleaf.text().as_string());

            str = s_nid+wxT(" ")+s_name;

            cbb_components->Append(str);

        }

    }
    else
    {
        wxLogMessage(_("初始化控件失败!"));
    }


    return ;
}

void ndo_generator_panel::Oncbb_comp_cliSelected(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        return;
    }

    wxString s_pos = cbb_comp_cli->GetValue();

    s_pos = s_pos.Left(2);

    init_ccb_components(s_pos);

}
