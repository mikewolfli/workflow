#include "configure_mat_list_editor.h"
#include <wx/tokenzr.h>
#include <wx/msgdlg.h>

//(*InternalHeaders(configure_mat_list_editor)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(configure_mat_list_editor)
const long configure_mat_list_editor::ID_STATICTEXT1 = wxNewId();
const long configure_mat_list_editor::ID_TEXTCTRL_INDEX_ID = wxNewId();
const long configure_mat_list_editor::ID_STATICTEXT2 = wxNewId();
const long configure_mat_list_editor::ID_TEXTCTR_BATCH_ID = wxNewId();
const long configure_mat_list_editor::ID_STATICTEXT3 = wxNewId();
const long configure_mat_list_editor::ID_TEXTCTRL_SEQUENCE = wxNewId();
const long configure_mat_list_editor::ID_STATICTEXT4 = wxNewId();
const long configure_mat_list_editor::ID_TEXTCTRL_MAT_ID = wxNewId();
const long configure_mat_list_editor::ID_STATICTEXT5 = wxNewId();
const long configure_mat_list_editor::ID_TEXTCTRL_MAT_DESC = wxNewId();
const long configure_mat_list_editor::ID_STATICTEXT6 = wxNewId();
const long configure_mat_list_editor::ID_TEXTCTRL_QTY = wxNewId();
const long configure_mat_list_editor::ID_STATICTEXT7 = wxNewId();
const long configure_mat_list_editor::ID_CHOICE_UNIT = wxNewId();
const long configure_mat_list_editor::ID_STATICTEXT8 = wxNewId();
const long configure_mat_list_editor::ID_TEXTCTRL_COMMENT = wxNewId();
const long configure_mat_list_editor::ID_CHECKLISTBOX_UNITS_LIST = wxNewId();
const long configure_mat_list_editor::ID_BUTTON1 = wxNewId();
const long configure_mat_list_editor::ID_BUTTON2 = wxNewId();
const long configure_mat_list_editor::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(configure_mat_list_editor,wxDialog)
	//(*EventTable(configure_mat_list_editor)
	//*)
END_EVENT_TABLE()

configure_mat_list_editor::configure_mat_list_editor(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(configure_mat_list_editor)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	FlexGridSizer1 = new wxFlexGridSizer(15, 2, 0, 0);
	FlexGridSizer1->AddGrowableCol(1);
	FlexGridSizer1->AddGrowableRow(1);
	FlexGridSizer1->AddGrowableRow(3);
	FlexGridSizer1->AddGrowableRow(5);
	FlexGridSizer1->AddGrowableRow(7);
	FlexGridSizer1->AddGrowableRow(9);
	FlexGridSizer1->AddGrowableRow(11);
	FlexGridSizer1->AddGrowableRow(13);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("非标申请号"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_index_id = new wxTextCtrl(this, ID_TEXTCTRL_INDEX_ID, wxEmptyString, wxDefaultPosition, wxSize(130,-1), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_INDEX_ID"));
	FlexGridSizer1->Add(tc_index_id, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("任务批号"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_batch_id = new wxTextCtrl(this, ID_TEXTCTR_BATCH_ID, wxEmptyString, wxDefaultPosition, wxSize(130,-1), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTR_BATCH_ID"));
	FlexGridSizer1->Add(tc_batch_id, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("序号"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_sequence = new wxTextCtrl(this, ID_TEXTCTRL_SEQUENCE, wxEmptyString, wxDefaultPosition, wxSize(130,21), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_SEQUENCE"));
	FlexGridSizer1->Add(tc_sequence, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("物料号"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_mat_id = new wxTextCtrl(this, ID_TEXTCTRL_MAT_ID, wxEmptyString, wxDefaultPosition, wxSize(130,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_MAT_ID"));
	FlexGridSizer1->Add(tc_mat_id, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("物料描述"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer1->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_mat_desc = new wxTextCtrl(this, ID_TEXTCTRL_MAT_DESC, wxEmptyString, wxDefaultPosition, wxSize(130,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_MAT_DESC"));
	FlexGridSizer1->Add(tc_mat_desc, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("数量"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer1->Add(StaticText6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_qty = new wxTextCtrl(this, ID_TEXTCTRL_QTY, _("依项目需求"), wxDefaultPosition, wxSize(130,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_QTY"));
	FlexGridSizer1->Add(tc_qty, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("单位"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer1->Add(StaticText7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	ch_unit = new wxChoice(this, ID_CHOICE_UNIT, wxDefaultPosition, wxSize(130,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_UNIT"));
	ch_unit->SetSelection( ch_unit->Append(_("PC")) );
	ch_unit->Append(_("SET"));
	ch_unit->Append(_("M"));
	FlexGridSizer1->Add(ch_unit, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("备注"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	FlexGridSizer1->Add(StaticText8, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_comment = new wxTextCtrl(this, ID_TEXTCTRL_COMMENT, wxEmptyString, wxDefaultPosition, wxSize(130,63), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL_COMMENT"));
	FlexGridSizer1->Add(tc_comment, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(FlexGridSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("梯号"));
	clb_units_list = new wxCheckListBox(this, ID_CHECKLISTBOX_UNITS_LIST, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHECKLISTBOX_UNITS_LIST"));
	StaticBoxSizer1->Add(clb_units_list, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer2->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer1->Add(BoxSizer2, 10, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("确定"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("取消"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button3 = new wxButton(this, ID_BUTTON3, _("全选/取消全选"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer3->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&configure_mat_list_editor::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&configure_mat_list_editor::OnButton2Click);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&configure_mat_list_editor::OnButton3Click);
	//*)
}

configure_mat_list_editor::~configure_mat_list_editor()
{
	//(*Destroy(configure_mat_list_editor)
	//*)
}


void configure_mat_list_editor::OnButton1Click(wxCommandEvent& event)
{
    m_index_id = tc_index_id->GetValue();
    m_batch_id = tc_batch_id->GetValue();
    m_sequence = tc_sequence->GetValue();
    m_mat_id = tc_mat_id->GetValue();
    m_mat_desc = tc_mat_desc->GetValue();
    int i_sel= ch_unit->GetSelection();
    m_unit = ch_unit->GetString(i_sel);
    m_qty = tc_qty->GetValue();
    m_comments = tc_comment->GetValue();

    if(m_mat_id.IsEmpty())
    {
         if(wxMessageBox(_("请务必填写物料号!"),_("信息"),wxOK)==wxOK)
            return;
    }

    if(m_mat_desc.IsEmpty())
    {
          if(wxMessageBox(_("请务必填写物料描述!"),_("信息"),wxOK)==wxOK)
            return;
    }

    if(m_qty.IsEmpty())
    {
           if(wxMessageBox(_("请务必填写物料数量!"),_("信息"),wxOK)==wxOK)
            return;
    }

    wxArrayInt array_icheck;
    wxString str;
    int i_count = clb_units_list->GetCheckedItems(array_icheck);
    if(i_count==0)
    {
        if(wxMessageBox(_("请务必选择关联梯号!"),_("信息"),wxOK)==wxOK)
            return;
    }

    m_str_units.Empty();
    for(int i =0;i<i_count;i++)
    {
       str = clb_units_list->GetString(array_icheck.Item(i));
       m_str_units = m_str_units+str+wxT(";");
    }

    EndDialog(wxID_OK);
}

void configure_mat_list_editor::OnButton2Click(wxCommandEvent& event)
{
    EndDialog(wxID_CANCEL);
}

void configure_mat_list_editor::OnButton3Click(wxCommandEvent& event)
{
    int i_count = clb_units_list->GetCount();

    bool b_check = !clb_units_list->IsChecked(0);

    for(int i=0;i<i_count; i++)
    {
       clb_units_list->Check(i,b_check);
    }
}

void configure_mat_list_editor::Ontc_qtyText(wxCommandEvent& event)
{
    static wxString oldstr="";
    double d;
    if (NULL == tc_qty)return;
    if (tc_qty->GetValue().ToDouble(&d) || 0== tc_qty->GetValue().Length() )
    {
        oldstr =tc_qty->GetValue();

    }
    else
    {
        tc_qty->SetValue(oldstr);
        tc_qty->SetInsertionPoint(tc_qty->GetValue().Length());
    }
}

void configure_mat_list_editor::init_checklistbox(wxArrayString &array_str, wxString s_sel)
{
    clb_units_list->Append(array_str);

    if(!s_sel.IsEmpty())
    {
        wxArrayString array_sel = wxStringTokenize(s_sel ,wxT(";"), wxTOKEN_DEFAULT  );

        int i_row = array_sel.GetCount();
        int i_count = array_str.GetCount();

        for(int i=0; i<i_row; i++)
        {
            for(int j=0; j<i_count; j++)
            {
                if(array_str.Item(j)==array_sel.Item(i))
                    clb_units_list->Check(j,true);

            }
        }

    }

}

void configure_mat_list_editor::init_ctr_value()
{
    tc_batch_id->SetValue(m_batch_id);
    tc_index_id->SetValue(m_index_id);
    tc_sequence->SetValue(m_sequence);
    tc_mat_id->SetValue(m_mat_id);
    tc_mat_desc->SetValue(m_mat_desc);
    if(m_qty.IsEmpty())
        m_qty=wxT("1");
    tc_qty->SetValue(m_qty);

    int i_pos = ch_unit->FindString(m_unit);

    ch_unit->SetSelection(i_pos);

    tc_comment->SetValue(m_comments);

}
