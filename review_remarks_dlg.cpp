#include "review_remarks_dlg.h"
#include "interface/wxpg_utils.h"
#include "wfApp.h"

//(*InternalHeaders(review_remarks_dlg)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(review_remarks_dlg)
const long review_remarks_dlg::ID_STATICTEXT1 = wxNewId();
const long review_remarks_dlg::ID_TEXTCTRL_DRAWING_QTY = wxNewId();
const long review_remarks_dlg::ID_STATICTEXT2 = wxNewId();
const long review_remarks_dlg::ID_TEXTCTRL_REMARKS = wxNewId();
const long review_remarks_dlg::ID_STATICTEXT3 = wxNewId();
const long review_remarks_dlg::ID_TEXTCTRL_RES_CM = wxNewId();
const long review_remarks_dlg::ID_BUTTON3 = wxNewId();
const long review_remarks_dlg::ID_STATICTEXT4 = wxNewId();
const long review_remarks_dlg::ID_CHOICE_URGENT_LEVEL = wxNewId();
const long review_remarks_dlg::ID_BUTTON1 = wxNewId();
const long review_remarks_dlg::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(review_remarks_dlg,wxDialog)
	//(*EventTable(review_remarks_dlg)
	//*)
END_EVENT_TABLE()

review_remarks_dlg::review_remarks_dlg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(review_remarks_dlg)
	wxGridBagSizer* GridBagSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;

	Create(parent, id, _("评审提示输入"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	GridBagSizer1 = new wxGridBagSizer(0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("图纸套数"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	GridBagSizer1->Add(StaticText1, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	tc_drawing_qty = new wxTextCtrl(this, ID_TEXTCTRL_DRAWING_QTY, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL_DRAWING_QTY"));
	GridBagSizer1->Add(tc_drawing_qty, wxGBPosition(0, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("评审备注"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	GridBagSizer1->Add(StaticText2, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	tc_remarks = new wxTextCtrl(this, ID_TEXTCTRL_REMARKS, wxEmptyString, wxDefaultPosition, wxSize(188,39), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL_REMARKS"));
	GridBagSizer1->Add(tc_remarks, wxGBPosition(1, 1), wxGBSpan(2, 2), wxALL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("商务负责人"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	GridBagSizer1->Add(StaticText3, wxGBPosition(3, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	tc_res_cm = new wxTextCtrl(this, ID_TEXTCTRL_RES_CM, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_RES_CM"));
	GridBagSizer1->Add(tc_res_cm, wxGBPosition(3, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button3 = new wxButton(this, ID_BUTTON3, _("选择"), wxDefaultPosition, wxSize(34,23), 0, wxDefaultValidator, _T("ID_BUTTON3"));
	GridBagSizer1->Add(Button3, wxGBPosition(3, 2), wxDefaultSpan, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("紧急程度"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	GridBagSizer1->Add(StaticText4, wxGBPosition(4, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	choice_urgent_level = new wxChoice(this, ID_CHOICE_URGENT_LEVEL, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_URGENT_LEVEL"));
	choice_urgent_level->SetSelection( choice_urgent_level->Append(_("普通")) );
	choice_urgent_level->Append(_("紧急"));
	choice_urgent_level->Append(_("特紧急"));
	GridBagSizer1->Add(choice_urgent_level, wxGBPosition(4, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(GridBagSizer1, 2, wxALL|wxEXPAND, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("确认"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("取消"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_TEXTCTRL_DRAWING_QTY,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&review_remarks_dlg::Ontc_drawing_qtyText);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&review_remarks_dlg::OnButton3Click);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&review_remarks_dlg::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&review_remarks_dlg::OnButton2Click);
	//*)

	choice_urgent_level->SetSelection(0);
}

review_remarks_dlg::~review_remarks_dlg()
{
	//(*Destroy(review_remarks_dlg)
	//*)
}

void review_remarks_dlg::refresh_control(int i_qty, wxString s_res_cm, wxString s_remarks)
{
    tc_drawing_qty->SetValue(NumToStr(i_qty));
    tc_remarks->SetValue(s_remarks);
    tc_res_cm->SetValue(s_res_cm);
}

void review_remarks_dlg::show_control(bool b_show)
{
    choice_urgent_level->Enable(b_show);
}

void review_remarks_dlg::OnButton1Click(wxCommandEvent& event)
{
    m_qty = tc_drawing_qty->GetValue();
    m_remarks = tc_remarks->GetValue();

    m_res_cm = tc_res_cm->GetValue();

    m_urgent_level = choice_urgent_level->GetSelection()+1;

    if(m_res_cm.IsEmpty())
    {
        wxMessageBox(_("商务负责人不能为空,请点击右侧按钮选择!"));
        return;
    }

    EndDialog(wxID_OK);
}

void review_remarks_dlg::OnButton2Click(wxCommandEvent& event)
{
    EndDialog(wxID_CANCEL);
}

void review_remarks_dlg::Ontc_drawing_qtyText(wxCommandEvent& event)
{
    static wxString oldstr="";
    double d;
    if (NULL == tc_drawing_qty)return;
    if (tc_drawing_qty->GetValue().ToDouble(&d)  ||  0== tc_drawing_qty->GetValue().Length() )
    {
        oldstr =tc_drawing_qty->GetValue();

    }
    else
    {
        tc_drawing_qty->SetValue(oldstr);
        tc_drawing_qty->SetInsertionPoint(tc_drawing_qty->GetValue().Length());
    }
}

void review_remarks_dlg::OnButton3Click(wxCommandEvent& event)
{

    wxArrayString  s_members = wxGetApp().get_member_in_group(wxT("G0001"), true);

    wxSingleChoiceDialog cdlg(this, _("请选择商务负责人:"),_("操作选择"),s_members);

    if(cdlg.ShowModal() == wxID_OK)
    {
        tc_res_cm->SetValue(cdlg.GetStringSelection());
    }
    else
    {
        wxLogMessage(_("未选择商务负责人，操作退出!"));
        return;
    }

}
