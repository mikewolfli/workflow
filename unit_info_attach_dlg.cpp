#include "unit_info_attach_dlg.h"
#include "wfApp.h"
//#include <wx/choicdlg.h>
#include "nstd_app_item_units.h"

//(*InternalHeaders(unit_info_attach_dlg)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(unit_info_attach_dlg)
const long unit_info_attach_dlg::ID_STATICTEXT1 = wxNewId();
const long unit_info_attach_dlg::ID_STATICTEXT2 = wxNewId();
const long unit_info_attach_dlg::ID_TEXTCTRL_DC_WEIGHT = wxNewId();
const long unit_info_attach_dlg::ID_TEXTCTRL_CAR_WEIGHT = wxNewId();
const long unit_info_attach_dlg::ID_LISTVIEW_INFO_ATTACH = wxNewId();
const long unit_info_attach_dlg::ID_BUTTON1 = wxNewId();
const long unit_info_attach_dlg::ID_BUTTON3 = wxNewId();
const long unit_info_attach_dlg::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(unit_info_attach_dlg,wxDialog)
	//(*EventTable(unit_info_attach_dlg)
	//*)
END_EVENT_TABLE()

unit_info_attach_dlg::unit_info_attach_dlg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(unit_info_attach_dlg)
	wxGridBagSizer* GridBagSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("基本资料信息"));
	GridBagSizer1 = new wxGridBagSizer(0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("轿厢空重(kg):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	GridBagSizer1->Add(StaticText1, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("预留装潢重量(kg):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	GridBagSizer1->Add(StaticText2, wxGBPosition(0, 2), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_dc_weight = new wxTextCtrl(this, ID_TEXTCTRL_DC_WEIGHT, wxEmptyString, wxDefaultPosition, wxSize(132,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_DC_WEIGHT"));
	GridBagSizer1->Add(tc_dc_weight, wxGBPosition(0, 3), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	tc_carweight = new wxTextCtrl(this, ID_TEXTCTRL_CAR_WEIGHT, wxEmptyString, wxDefaultPosition, wxSize(132,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_CAR_WEIGHT"));
	GridBagSizer1->Add(tc_carweight, wxGBPosition(0, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(GridBagSizer1, 1, wxALL|wxEXPAND, 0);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	lv_attach = new wxListView(this, ID_LISTVIEW_INFO_ATTACH, wxDefaultPosition, wxSize(705,185), wxLC_REPORT|wxLC_SINGLE_SEL, wxDefaultValidator, _T("ID_LISTVIEW_INFO_ATTACH"));
	BoxSizer3->Add(lv_attach, 1, wxALL|wxEXPAND, 0);
	StaticBoxSizer1->Add(BoxSizer3, 4, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(StaticBoxSizer1, 5, wxALL|wxEXPAND, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("保存"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button3 = new wxButton(this, ID_BUTTON3, _("smart copy"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer2->Add(Button3, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("退出"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_TEXTCTRL_DC_WEIGHT,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&unit_info_attach_dlg::Ontc_dc_weightText);
	Connect(ID_TEXTCTRL_CAR_WEIGHT,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&unit_info_attach_dlg::Ontc_carweightText);
	Connect(ID_LISTVIEW_INFO_ATTACH,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&unit_info_attach_dlg::Onlv_attachItemActivated);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&unit_info_attach_dlg::OnButton1Click);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&unit_info_attach_dlg::OnButton3Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&unit_info_attach_dlg::OnButton2Click);
	//*)
	init_header();
	m_litem = 0;
	b_change = false;
	b_edit = true;
}

unit_info_attach_dlg::~unit_info_attach_dlg()
{
	//(*Destroy(unit_info_attach_dlg)
	//*)
}


void unit_info_attach_dlg::OnButton3Click(wxCommandEvent& event)
{

    wxString s_car_weight= tc_carweight->GetValue();

    wxString s_dc_weight = tc_dc_weight->GetValue();

    if(wxAtoi(s_car_weight)<=0)
    {
        wxMessageBox(_("轿厢空重未填写，无法作为源数据COPY!"),_("错误"));
        return;
    }
    wxArrayString a_other = array_wbs;
    a_other.Remove(m_wbs);

    nstd_app_item_units dlg;
    dlg.init_checklistbox(a_other, a_other, false, true);

    if(dlg.ShowModal()==wxID_CANCEL)
       return;

     wxArrayString a_sel = dlg.array_units;
     int i_count = a_sel.GetCount();
     for(int i=0;i<i_count;i++)
    {
         wxString s_wbs = a_sel.Item(i);
         int i_index = find_wbs_in_list(s_wbs);

         lv_attach->SetItem(i_index, 4, s_car_weight);
         lv_attach->SetItem(i_index, 5, s_dc_weight);
    }

/*
    wxMultiChoiceDialog dlg(this, _("smart copy目标梯选择,请选择"),_("选择"),a_other);

    if(dlg.ShowModal()==wxID_CANCEL)
        return;

    wxArrayInt a_sel = dlg.GetSelections();

    if(a_sel.IsEmpty())
        return;

    int i_count = a_sel.GetCount();

    for(int i=0;i<i_count;i++)
    {
         wxString s_wbs = a_other.Item(a_sel.Item(i));
         int i_index = find_wbs_in_list(s_wbs);

         lv_attach->SetItem(i_index, 4, s_car_weight);
         lv_attach->SetItem(i_index, 5, s_dc_weight);
    }*/

    b_change= true;
}

int unit_info_attach_dlg::find_wbs_in_list(wxString s_wbs)
{
    int i_total = lv_attach->GetItemCount();

    for(int i=0;i<i_total;i++)
    {
        if(lv_attach->GetItemText(i,0)==s_wbs)
            return i;
    }

    return -1;
}

void unit_info_attach_dlg::OnButton1Click(wxCommandEvent& event)
{
    wxString str;
    if(!check_item_data_right(str))
    {
        wxMessageBox(str,_("提示"));
        return;
    }

    save_items();
    EndDialog(wxID_OK);
}

void unit_info_attach_dlg::OnButton2Click(wxCommandEvent& event)
{
    wxString str;
    if(b_change&&b_edit)
    {
        if(wxMessageBox(_("内容已经更改，是否需要保存后退出?"),_("确认"),wxYES_NO)==wxYES)
        {
             if(!check_item_data_right(str))
             {
                 wxMessageBox(str,_("提示"));
                 return;
             }

             save_items();
        }
    }
    EndDialog(wxID_CANCEL);
}

bool unit_info_attach_dlg::check_item_data_right(wxString &str)
{
    int i_count = lv_attach->GetItemCount();
    str.Empty();
    bool b_check;

    wxString s_wbs, s_car_weight, s_load;

    for(int i=0;i<i_count;i++)
    {
         s_wbs = lv_attach->GetItemText(i, 0);
         s_car_weight = lv_attach->GetItemText(i, 4);
       //  s_dc_weight = lv_attach->GetItemText(i, 5);
         s_load = lv_attach->GetItemText(i,6);
/*
         if(wxAtoi(s_car_weight)<wxAtoi(s_load))
         {
             str = str+s_wbs+wxT(";");
         }

         if(wxAtoi(s_dc_weight)!=0 && wxAtoi(s_dc_weight)<100)
         {


         }*/

         if(wxAtoi(s_car_weight)<=300)
         {
             str = str+s_wbs+wxT(";");
         }
    }

    if(str.IsEmpty())
        return true;

    else
    {
        str=str+_("轿厢空重有误，其值过小!");
        return false;
    }

}

void unit_info_attach_dlg::refresh_list()
{
     lv_attach->DeleteAllItems();

     wxString str_sql = wxT("select wbs_no, project_name, lift_no, elevator_type,(select load from s_unit_parameter where \
                            wbs_no=v_unit_info.wbs_no) as load, (select speed from s_unit_parameter where wbs_no=v_unit_info.wbs_no) as \
                            speed, (select car_weight from s_unit_info_attach where wbs_no = v_unit_info.wbs_no ) as car_weight, \
                            (select reserve_decoration_weight from s_unit_info_attach  where wbs_no = v_unit_info.wbs_no) as dc_weight from v_unit_info where ");
     int i_count = array_wbs.GetCount();

     if(i_count==0)
        return;

    for(int i=0; i<i_count; i++)
    {
        if(i==0)
            str_sql = str_sql+wxT(" wbs_no ='")+array_wbs.Item(i)+wxT("' ");
        else
            str_sql = str_sql + wxT(" or wbs_no = '")+array_wbs.Item(i)+wxT("' ");

    }

    str_sql = str_sql+ wxT(" order by wbs_no ASC;");


    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
         _res->Clear();
        return;
    }

    int i_rows = _res->GetRowsNumber();

    for(int j=0;j<i_rows;j++)
    {
        wxString str = _res->GetVal(wxT("wbs_no"));

        long tmp = lv_attach->InsertItem(j, str);

        if(j==0&&m_litem==0)
            m_litem = tmp;
        lv_attach->SetItemData(tmp, j);
        str = _res->GetVal(wxT("project_name"));
        lv_attach->SetItem(tmp, 1, str);
        str = _res->GetVal(wxT("lift_no"));
        lv_attach->SetItem(tmp, 2, str);
        str = _res->GetVal(wxT("elevator_type"));
        lv_attach->SetItem(tmp, 3, str);

        int i_temp = _res->GetInt(wxT("car_weight"));
        str = NumToStr(i_temp);
        lv_attach->SetItem(tmp, 4, str);

        i_temp = _res->GetInt(wxT("dc_weight"));
        str = NumToStr(i_temp);
        lv_attach->SetItem(tmp, 5,str);

        i_temp = _res->GetInt(wxT("load"));
        str = NumToStr(i_temp);
        lv_attach->SetItem(tmp, 6,str);

        double d_temp = _res->GetDouble(wxT("speed"));
        str = NumToStr(d_temp);
        lv_attach->SetItem(tmp, 7, str);

//        if(j==0)
 //           lv_attach->SetItemState(tmp, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);

        _res->MoveNext();
    }

    _res->Clear();


    tc_carweight->SetValue(lv_attach->GetItemText(m_litem, 4));
    tc_dc_weight->SetValue(lv_attach->GetItemText(m_litem, 5));
    m_wbs = lv_attach->GetItemText(m_litem,0);
    lv_attach->SetItemState(m_litem, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);
}

void unit_info_attach_dlg::init_header()
{
    wxListItem itemCol;
    itemCol.SetText(_("wbs_no"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_attach->InsertColumn(0, itemCol);
    itemCol.SetText(_("项目名称"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(200);
    lv_attach->InsertColumn(1, itemCol);
    itemCol.SetText(_("梯号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_attach->InsertColumn(2, itemCol);
    itemCol.SetText(_("梯型"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_attach->InsertColumn(3, itemCol);
    itemCol.SetText(_("轿厢空重"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_attach->InsertColumn(4, itemCol);
    itemCol.SetText(_("装潢重量"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lv_attach->InsertColumn(5, itemCol);
    itemCol.SetText(_("载重"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_attach->InsertColumn(6, itemCol);
    itemCol.SetText(_("速度"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lv_attach->InsertColumn(7, itemCol);
}

void unit_info_attach_dlg::Onlv_attachItemActivated(wxListEvent& event)
{
    long li_item = event.GetIndex();
    m_litem = li_item;
    wxString str;
    m_wbs = lv_attach->GetItemText(li_item, 0);

    str = lv_attach->GetItemText(li_item, 4);

    tc_carweight->SetValue(str);

    str = lv_attach->GetItemText(li_item, 5);

    tc_dc_weight->SetValue(str);

    event.Skip();
}

void unit_info_attach_dlg::save_items()
{
    int i_count = lv_attach->GetItemCount();

    wxString s_wbs, s_car_weight, s_dc_weight;

    for(int i=0;i<i_count;i++)
    {
         s_wbs = lv_attach->GetItemText(i, 0);
         s_car_weight = lv_attach->GetItemText(i, 4);
         s_dc_weight = lv_attach->GetItemText(i, 5);
        //s_load = lv_attach->GetItemText(i,6);

         if(wxAtoi(s_car_weight)<=300)
         {
             wxLogMessage(s_wbs+_("轿厢空重有误，数值太小!"));
             continue;
         }

         save_item(s_wbs, s_car_weight, s_dc_weight);
    }
}

bool unit_info_attach_dlg::save_item(wxString s_wbs, wxString s_car_weight, wxString s_dc_weight)
{
    wxString s_sql = wxT("select * from s_unit_info_attach where wbs_no = '")+s_wbs+wxT("';");

    if(wxAtoi(s_car_weight)<=0)
    {
        wxLogMessage(s_wbs+_("轿厢空重未填写完整,不能为0, 数据未更新!"));
        return false;
    }

    if(!wxGetApp().is_have(s_sql))
    {
         s_sql = wxT("INSERT INTO s_unit_info_attach(wbs_no, car_weight,reserve_decoration_weight, modify_date, \
            modify_emp_id, create_date, create_emp_id, is_basic_finish) VALUES ('")+s_wbs+wxT("','")+s_car_weight+wxT("','")+
            s_dc_weight+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+
               DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("',true);");
    }else
    {
        s_sql = wxT("UPDATE s_unit_info_attach SET car_weight='")+s_car_weight+wxT("', reserve_decoration_weight='")+s_dc_weight+wxT("',modify_date = '")+DateToAnsiStr(wxDateTime::Now())+
                               wxT("',modify_emp_id = '")+gr_para.login_user+wxT("', is_basic_finish=true, is_basic_full_finish=false where wbs_no='")+s_wbs+wxT("';");
    }

    return wxGetApp().app_sql_update(s_sql);
}

void unit_info_attach_dlg::Ontc_carweightText(wxCommandEvent& event)
{
    // insert your code here
    //MessageBox(0,"a","a",MB_OK);
    static wxString oldstr="";
    long d;
    if (NULL == tc_carweight)return;
    if (tc_carweight->GetValue().ToLong(&d) || 0== tc_carweight->GetValue().Length() )
    {
        oldstr =tc_carweight->GetValue();

    }
    else
    {
        tc_carweight->SetValue(oldstr);
        tc_carweight->SetInsertionPoint(tc_carweight->GetValue().Length());
    }

    b_change= true;

    lv_attach->SetItem(m_litem,4,tc_carweight->GetValue());
}

void unit_info_attach_dlg::Ontc_dc_weightText(wxCommandEvent& event)
{
 //   tc_dc_weight
    static wxString oldstr="";
    long d;
    if (NULL == tc_dc_weight)return;
    if (tc_dc_weight->GetValue().ToLong(&d) || 0== tc_dc_weight->GetValue().Length() )
    {
        oldstr =tc_dc_weight->GetValue();

    }
    else
    {
        tc_dc_weight->SetValue(oldstr);
        tc_dc_weight->SetInsertionPoint(tc_dc_weight->GetValue().Length());
    }

    b_change = true;
    lv_attach->SetItem(m_litem,5,tc_dc_weight->GetValue());
}

void unit_info_attach_dlg::refresh_control()
{
    tc_carweight->Enable(b_edit);
    tc_dc_weight->Enable(b_edit);

    if(!b_edit)
        b_change =false;


    Button1->Show(b_edit);
    Button3->Show(b_edit);
}
