#include "info_id_generator_panel.h"
#include "wfApp.h"
#include "wf_search.h"
#include "units_list_dlg.h"

//(*InternalHeaders(info_id_generator_panel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(info_id_generator_panel)
const long info_id_generator_panel::ID_TEXTCTRL_LL = wxNewId();
const long info_id_generator_panel::ID_BUTTON_LL_GEN = wxNewId();
const long info_id_generator_panel::ID_STATICTEXT2 = wxNewId();
const long info_id_generator_panel::ID_TEXTCTRL_SG_PROJ = wxNewId();
const long info_id_generator_panel::ID_BUTTON_SG_GEN = wxNewId();
const long info_id_generator_panel::ID_BUTTON_SG_INFO = wxNewId();
const long info_id_generator_panel::ID_STATICTEXT1 = wxNewId();
const long info_id_generator_panel::ID_STATICTEXT3 = wxNewId();
const long info_id_generator_panel::ID_TEXTCTRL_WB_REASON = wxNewId();
const long info_id_generator_panel::ID_BUTTON_WB = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX_PU = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX_QM = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX_IE = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX_PP = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX_lo = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX_PSM = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX_PM = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX_CO = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX_OTHERS = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX_TCE_MPM = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX_TCE_PM = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX_TCE_DS = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX_NCE_CS = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX_NCE_FQ = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX_NCE_PSM = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX_NCE_PPU = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX_NCE_LO = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX_NCE_CO = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX_NCE_SM = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX_NCE_TM = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX_NCE_EL = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX_NCE_SQE = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX_NCE_OTHER = wxNewId();
const long info_id_generator_panel::ID_STATICTEXT4 = wxNewId();
const long info_id_generator_panel::ID_TEXTCTRL_NCE_FROM = wxNewId();
const long info_id_generator_panel::ID_STATICTEXT5 = wxNewId();
const long info_id_generator_panel::ID_TEXTCTRL_NCE_SUBJECT = wxNewId();
const long info_id_generator_panel::ID_BUTTON1 = wxNewId();
const long info_id_generator_panel::ID_STATICTEXT6 = wxNewId();
const long info_id_generator_panel::ID_TEXTCTRL_NCE_ECO = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX_NCE_PC = wxNewId();
const long info_id_generator_panel::ID_DATEPICKERCTRL1 = wxNewId();
const long info_id_generator_panel::ID_CHECKBOX1 = wxNewId();
const long info_id_generator_panel::ID_STATICTEXT7 = wxNewId();
const long info_id_generator_panel::ID_TEXTCTRL_REMARKS = wxNewId();
//*)

BEGIN_EVENT_TABLE(info_id_generator_panel,wxPanel)
	//(*EventTable(info_id_generator_panel)
	//*)
END_EVENT_TABLE()

info_id_generator_panel::info_id_generator_panel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(info_id_generator_panel)
	wxStaticBoxSizer* StaticBoxSizer2;
	wxGridBagSizer* GridBagSizer4;
	wxStaticBoxSizer* stb_wb_obj;
	wxGridBagSizer* GridBagSizer1;
	wxGridBagSizer* GridBagSizer2;
	wxBoxSizer* BoxSizer2;
	wxGridSizer* GridSizer1;
	wxStaticBoxSizer* sb_ll;
	wxStaticBoxSizer* stb_wb;
	wxBoxSizer* BoxSizer1;
	wxGridBagSizer* GridBagSizer5;
	wxGridBagSizer* GridBagSizer3;
	wxStaticBoxSizer* sb_spec_gad;
	wxStaticBoxSizer* stb_nce;

	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	sb_ll = new wxStaticBoxSizer(wxHORIZONTAL, this, _("内部联络单取号"));
	GridBagSizer1 = new wxGridBagSizer(0, 0);
	tc_ll = new wxTextCtrl(this, ID_TEXTCTRL_LL, wxEmptyString, wxDefaultPosition, wxSize(301,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL_LL"));
	GridBagSizer1->Add(tc_ll, wxGBPosition(0, 1), wxGBSpan(1, 3), wxALL|wxEXPAND, 5);
	Button_LL_gen = new wxButton(this, ID_BUTTON_LL_GEN, _("生成编号"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_LL_GEN"));
	GridBagSizer1->Add(Button_LL_gen, wxGBPosition(0, 4), wxDefaultSpan, wxALL|wxEXPAND, 5);
	st_ll = new wxStaticText(this, ID_STATICTEXT2, _("主题"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	GridBagSizer1->Add(st_ll, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	sb_ll->Add(GridBagSizer1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer1->Add(sb_ll, 1, wxALL|wxEXPAND, 0);
	sb_spec_gad = new wxStaticBoxSizer(wxHORIZONTAL, this, _("SPEC 和 GAD 更改通知单取号"));
	GridBagSizer2 = new wxGridBagSizer(0, 0);
	tc_sg_proj = new wxTextCtrl(this, ID_TEXTCTRL_SG_PROJ, wxEmptyString, wxDefaultPosition, wxSize(278,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_SG_PROJ"));
	tc_sg_proj->Disable();
	GridBagSizer2->Add(tc_sg_proj, wxGBPosition(0, 1), wxGBSpan(1, 3), wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button_sg_gen = new wxButton(this, ID_BUTTON_SG_GEN, _("生成编号"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_SG_GEN"));
	GridBagSizer2->Add(Button_sg_gen, wxGBPosition(0, 4), wxDefaultSpan, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button_sg_info = new wxButton(this, ID_BUTTON_SG_INFO, _("相关项目"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_SG_INFO"));
	GridBagSizer2->Add(Button_sg_info, wxGBPosition(0, 5), wxDefaultSpan, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	st_sg = new wxStaticText(this, ID_STATICTEXT1, _("更改项目"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	GridBagSizer2->Add(st_sg, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	sb_spec_gad->Add(GridBagSizer2, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(sb_spec_gad, 1, wxALL|wxEXPAND, 0);
	stb_wb = new wxStaticBoxSizer(wxHORIZONTAL, this, _("WBS BOM 更改通知单取号"));
	GridBagSizer3 = new wxGridBagSizer(0, 0);
	st_wbsbom = new wxStaticText(this, ID_STATICTEXT3, _("更改原因"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	GridBagSizer3->Add(st_wbsbom, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	tc_wb_reason = new wxTextCtrl(this, ID_TEXTCTRL_WB_REASON, wxEmptyString, wxDefaultPosition, wxSize(277,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_WB_REASON"));
	GridBagSizer3->Add(tc_wb_reason, wxGBPosition(0, 1), wxGBSpan(1, 3), wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Button_wb = new wxButton(this, ID_BUTTON_WB, _("生成编号"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_WB"));
	GridBagSizer3->Add(Button_wb, wxGBPosition(0, 4), wxDefaultSpan, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	stb_wb_obj = new wxStaticBoxSizer(wxHORIZONTAL, this, _("发放对象"));
	GridSizer1 = new wxGridSizer(2, 6, 0, 0);
	cb_pu = new wxCheckBox(this, ID_CHECKBOX_PU, _("PU"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_PU"));
	cb_pu->SetValue(false);
	GridSizer1->Add(cb_pu, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	cb_qm = new wxCheckBox(this, ID_CHECKBOX_QM, _("QM"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_QM"));
	cb_qm->SetValue(false);
	GridSizer1->Add(cb_qm, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	cb_ie = new wxCheckBox(this, ID_CHECKBOX_IE, _("IE"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_IE"));
	cb_ie->SetValue(false);
	GridSizer1->Add(cb_ie, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	cb_pp = new wxCheckBox(this, ID_CHECKBOX_PP, _("PP"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_PP"));
	cb_pp->SetValue(false);
	GridSizer1->Add(cb_pp, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	cb_lo = new wxCheckBox(this, ID_CHECKBOX_lo, _("LO"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_lo"));
	cb_lo->SetValue(false);
	GridSizer1->Add(cb_lo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	cb_psm = new wxCheckBox(this, ID_CHECKBOX_PSM, _("PSM"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_PSM"));
	cb_psm->SetValue(false);
	GridSizer1->Add(cb_psm, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	cb_pm = new wxCheckBox(this, ID_CHECKBOX_PM, _("PM"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_PM"));
	cb_pm->SetValue(false);
	GridSizer1->Add(cb_pm, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	cb_co = new wxCheckBox(this, ID_CHECKBOX_CO, _("CO"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_CO"));
	cb_co->SetValue(false);
	GridSizer1->Add(cb_co, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	cb_others = new wxCheckBox(this, ID_CHECKBOX_OTHERS, _("Others"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_OTHERS"));
	cb_others->SetValue(false);
	GridSizer1->Add(cb_others, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	stb_wb_obj->Add(GridSizer1, 1, wxALL|wxEXPAND, 0);
	GridBagSizer3->Add(stb_wb_obj, wxGBPosition(1, 0), wxGBSpan(2, 6), wxALL|wxEXPAND, 0);
	stb_wb->Add(GridBagSizer3, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(stb_wb, 2, wxALL|wxEXPAND, 0);
	stb_nce = new wxStaticBoxSizer(wxVERTICAL, this, _("技术变更执行通知单取号"));
	GridBagSizer4 = new wxGridBagSizer(0, 0);
	cb_nce_mpm = new wxCheckBox(this, ID_CHECKBOX_TCE_MPM, _("MPM大项目"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_TCE_MPM"));
	cb_nce_mpm->SetValue(false);
	GridBagSizer4->Add(cb_nce_mpm, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cb_nce_pm = new wxCheckBox(this, ID_CHECKBOX_TCE_PM, _("PM项目管理"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_TCE_PM"));
	cb_nce_pm->SetValue(false);
	GridBagSizer4->Add(cb_nce_pm, wxGBPosition(0, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cb_nce_ds = new wxCheckBox(this, ID_CHECKBOX_TCE_DS, _("DS国内销售"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_TCE_DS"));
	cb_nce_ds->SetValue(false);
	GridBagSizer4->Add(cb_nce_ds, wxGBPosition(0, 2), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cb_nec_cs = new wxCheckBox(this, ID_CHECKBOX_NCE_CS, _("CS售后服务"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_NCE_CS"));
	cb_nec_cs->SetValue(false);
	GridBagSizer4->Add(cb_nec_cs, wxGBPosition(0, 3), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cb_nce_fq = new wxCheckBox(this, ID_CHECKBOX_NCE_FQ, _("FQ工厂质量"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_NCE_FQ"));
	cb_nce_fq->SetValue(false);
	GridBagSizer4->Add(cb_nce_fq, wxGBPosition(0, 4), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cb_nce_psm = new wxCheckBox(this, ID_CHECKBOX_NCE_PSM, _("PSM战略采购"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_NCE_PSM"));
	cb_nce_psm->SetValue(false);
	GridBagSizer4->Add(cb_nce_psm, wxGBPosition(0, 5), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cb_nce_ppu = new wxCheckBox(this, ID_CHECKBOX_NCE_PPU, _("PPU采购"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_NCE_PPU"));
	cb_nce_ppu->SetValue(false);
	GridBagSizer4->Add(cb_nce_ppu, wxGBPosition(0, 6), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cb_nce_lo = new wxCheckBox(this, ID_CHECKBOX_NCE_LO, _("LO物流"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_NCE_LO"));
	cb_nce_lo->SetValue(false);
	GridBagSizer4->Add(cb_nce_lo, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cb_nce_co = new wxCheckBox(this, ID_CHECKBOX_NCE_CO, _("CO成本控制"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_NCE_CO"));
	cb_nce_co->SetValue(false);
	GridBagSizer4->Add(cb_nce_co, wxGBPosition(1, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cb_nce_sm = new wxCheckBox(this, ID_CHECKBOX_NCE_SM, _("SM钣金"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_NCE_SM"));
	cb_nce_sm->SetValue(false);
	GridBagSizer4->Add(cb_nce_sm, wxGBPosition(1, 2), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cb_nce_tm = new wxCheckBox(this, ID_CHECKBOX_NCE_TM, _("TM曳引机"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_NCE_TM"));
	cb_nce_tm->SetValue(false);
	GridBagSizer4->Add(cb_nce_tm, wxGBPosition(1, 3), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cb_nce_el = new wxCheckBox(this, ID_CHECKBOX_NCE_EL, _("EL电气"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_NCE_EL"));
	cb_nce_el->SetValue(false);
	GridBagSizer4->Add(cb_nce_el, wxGBPosition(1, 4), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cb_nce_sqe = new wxCheckBox(this, ID_CHECKBOX_NCE_SQE, _("SQE供应商质量管理"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_NCE_SQE"));
	cb_nce_sqe->SetValue(false);
	GridBagSizer4->Add(cb_nce_sqe, wxGBPosition(1, 5), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cb_nce_other = new wxCheckBox(this, ID_CHECKBOX_NCE_OTHER, _("Others"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_NCE_OTHER"));
	cb_nce_other->SetValue(false);
	GridBagSizer4->Add(cb_nce_other, wxGBPosition(1, 6), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	stb_nce->Add(GridBagSizer4, 2, wxALL|wxEXPAND, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	st_from = new wxStaticText(this, ID_STATICTEXT4, _("From:"), wxDefaultPosition, wxSize(40,13), 0, _T("ID_STATICTEXT4"));
	BoxSizer2->Add(st_from, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	tce_nce_from = new wxTextCtrl(this, ID_TEXTCTRL_NCE_FROM, _("SJ CE松江工厂合同工程部"), wxDefaultPosition, wxSize(268,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_NCE_FROM"));
	BoxSizer2->Add(tce_nce_from, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	stb_nce->Add(BoxSizer2, 1, wxALL|wxALIGN_LEFT, 0);
	GridBagSizer5 = new wxGridBagSizer(0, 0);
	st_nce_subject = new wxStaticText(this, ID_STATICTEXT5, _("主题"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	GridBagSizer5->Add(st_nce_subject, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_nce_subject = new wxTextCtrl(this, ID_TEXTCTRL_NCE_SUBJECT, wxEmptyString, wxDefaultPosition, wxSize(506,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_NCE_SUBJECT"));
	GridBagSizer5->Add(tc_nce_subject, wxGBPosition(0, 1), wxGBSpan(1, 6), wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Button_NCE_gen = new wxButton(this, ID_BUTTON1, _("生成编号"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	GridBagSizer5->Add(Button_NCE_gen, wxGBPosition(0, 7), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	st_nce_eco = new wxStaticText(this, ID_STATICTEXT6, _("相关ECO编号"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	GridBagSizer5->Add(st_nce_eco, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	tc_nce_eco = new wxTextCtrl(this, ID_TEXTCTRL_NCE_ECO, wxEmptyString, wxDefaultPosition, wxSize(127,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_NCE_ECO"));
	GridBagSizer5->Add(tc_nce_eco, wxGBPosition(1, 1), wxGBSpan(1, 2), wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	cb_nce_pc = new wxCheckBox(this, ID_CHECKBOX_NCE_PC, _("需要更改PC(Yes or No)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_NCE_PC"));
	cb_nce_pc->SetValue(false);
	GridBagSizer5->Add(cb_nce_pc, wxGBPosition(1, 3), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	dp_nce_valid = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL1, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL1"));
	GridBagSizer5->Add(dp_nce_valid, wxGBPosition(1, 5), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cb_nce_urgent = new wxCheckBox(this, ID_CHECKBOX1, _("紧急执行"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	cb_nce_urgent->SetValue(false);
	GridBagSizer5->Add(cb_nce_urgent, wxGBPosition(1, 6), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	st_nce_valid = new wxStaticText(this, ID_STATICTEXT7, _("生效日期"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	GridBagSizer5->Add(st_nce_valid, wxGBPosition(1, 4), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	stb_nce->Add(GridBagSizer5, 2, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(stb_nce, 3, wxALL|wxEXPAND, 0);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("备注"));
	tc_remarks = new wxTextCtrl(this, ID_TEXTCTRL_REMARKS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL_REMARKS"));
	StaticBoxSizer2->Add(tc_remarks, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON_LL_GEN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&info_id_generator_panel::OnButton_LL_genClick);
	Connect(ID_BUTTON_SG_GEN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&info_id_generator_panel::OnButton_sg_genClick);
	Connect(ID_BUTTON_SG_INFO,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&info_id_generator_panel::OnButton_sg_infoClick);
	Connect(ID_BUTTON_WB,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&info_id_generator_panel::OnButton_wbClick);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&info_id_generator_panel::OnButton_NCE_genClick);
	//*)

    wxArrayString array_group = wxGetApp().get_group();

    if(array_group.Index(wxT("G0001"))!=wxNOT_FOUND||array_group.Index(wxT("G0017"))!=wxNOT_FOUND||array_group.Index(wxT("G0002"))!=wxNOT_FOUND||array_group.Index(wxT("G0009"))!=wxNOT_FOUND)
    {
        sb_spec_gad->Show(true);
        st_sg->Show(true);
        tc_sg_proj->Show(true);
        Button_sg_gen->Show(true);
        Button_sg_info->Show(true);

    }else
    {
        sb_spec_gad->Show(false);
        st_sg->Show(false);
        tc_sg_proj->Show(false);
        Button_sg_gen->Show(false);
        Button_sg_info->Show(false);
    }

    if(array_group.Index(wxT("G0003"))!=wxNOT_FOUND||array_group.Index(wxT("G0004"))!=wxNOT_FOUND||
       array_group.Index(wxT("G0005"))!=wxNOT_FOUND||array_group.Index(wxT("G0006"))!=wxNOT_FOUND||
       array_group.Index(wxT("G0007"))!=wxNOT_FOUND||array_group.Index(wxT("G0008"))!=wxNOT_FOUND||
       array_group.Index(wxT("G0012"))!=wxNOT_FOUND||array_group.Index(wxT("G0013"))!=wxNOT_FOUND||
       array_group.Index(wxT("G0018"))!=wxNOT_FOUND)
    {
       sb_ll->Show(true);
       st_ll->Show(true);
       tc_ll->Show(true);
       Button_LL_gen->Show(true);
    }else
    {
       sb_ll->Show(false);
       st_ll->Show(false);
       tc_ll->Show(false);
       Button_LL_gen->Show(false);
    }

    if(array_group.Index(wxT("G0003"))!=wxNOT_FOUND||array_group.Index(wxT("G0004"))!=wxNOT_FOUND||
       array_group.Index(wxT("G0005"))!=wxNOT_FOUND||array_group.Index(wxT("G0006"))!=wxNOT_FOUND||
       array_group.Index(wxT("G0007"))!=wxNOT_FOUND||array_group.Index(wxT("G0008"))!=wxNOT_FOUND||
       array_group.Index(wxT("G0013"))!=wxNOT_FOUND||array_group.Index(wxT("G0018"))!=wxNOT_FOUND)
    {
        stb_wb->Show(true);
        stb_wb_obj->Show(true);
        st_wbsbom->Show(true);
        tc_wb_reason->Show(true);
        Button_wb->Show(true);
        cb_pu->Show(true);
        cb_qm->Show(true);
        cb_ie->Show(true);
        cb_pp->Show(true);
        cb_lo->Show(true);
        cb_psm->Show(true);
        cb_pm->Show(true);
        cb_co->Show(true);
        cb_others->Show(true);

    }else
    {
         stb_wb->Show(false);
        stb_wb_obj->Show(false);
        st_wbsbom->Show(false);
        tc_wb_reason->Show(false);
        Button_wb->Show(false);
        cb_pu->Show(false);
        cb_qm->Show(false);
        cb_ie->Show(false);
        cb_pp->Show(false);
        cb_lo->Show(false);
        cb_psm->Show(false);
        cb_pm->Show(false);
        cb_co->Show(false);
        cb_others->Show(false);
    }

    if(array_group.Index(wxT("G0006"))!=wxNOT_FOUND||array_group.Index(wxT("G0007"))!=wxNOT_FOUND||array_group.Index(wxT("G0008"))!=wxNOT_FOUND||array_group.Index(wxT("G0018"))!=wxNOT_FOUND)
    {
        stb_nce->Show(true);
        cb_nce_co->Show(true);
		tc_nce_eco->Show(true);
		cb_nce_tm->Show(true);
		cb_nce_lo->Show(true);
		st_nce_valid->Show(true);
		Button_NCE_gen->Show(true);
		st_nce_subject->Show(true);
		cb_nce_sm->Show(true);
		cb_nce_pc->Show(true);
		tce_nce_from->Show(true);

		cb_nce_fq->Show(true);
		cb_nce_ppu->Show(true);

		cb_nce_ds->Show(true);
		cb_nce_sqe->Show(true);
		cb_nce_mpm->Show(true);
		cb_nce_el->Show(true);
		dp_nce_valid->Show(true);

		cb_nec_cs->Show(true);
		cb_nce_other->Show(true);
		st_nce_eco->Show(true);
		tc_nce_subject->Show(true);

		cb_nce_urgent->Show(true);
		cb_nce_pm->Show(true);
		cb_nce_psm->Show(true);
		st_from->Show(true);
    }else
    {
        stb_nce->Show(false);
        cb_nce_co->Show(false);
		tc_nce_eco->Show(false);
		cb_nce_tm->Show(false);
		cb_nce_lo->Show(false);
		st_nce_valid->Show(false);
		Button_NCE_gen->Show(false);
		st_nce_subject->Show(false);
		cb_nce_sm->Show(false);
		cb_nce_pc->Show(false);
		tce_nce_from->Show(false);

		cb_nce_fq->Show(false);
		cb_nce_ppu->Show(false);

		cb_nce_ds->Show(false);
		cb_nce_sqe->Show(false);
		cb_nce_mpm->Show(false);
		cb_nce_el->Show(false);
		dp_nce_valid->Show(false);

		cb_nec_cs->Show(false);
		cb_nce_other->Show(false);
		st_nce_eco->Show(false);
		tc_nce_subject->Show(false);

		cb_nce_urgent->Show(false);
		cb_nce_pm->Show(false);
		cb_nce_psm->Show(false);
		st_from->Show(false);
    }


    array_group.Clear();
}


info_id_generator_panel::~info_id_generator_panel()
{
	//(*Destroy(info_id_generator_panel)
	//*)
}


void info_id_generator_panel::OnButton_sg_genClick(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    wxString s_content = tc_sg_proj->GetValue();

    if(s_content.IsEmpty())
    {
        wxMessageBox(_("请先填写SPEC&GAD更改项目"),_("提示"));

        Button_sg_info->SetFocus();

        return;
    }
    if(wxMessageBox(_("确认生成SPEC&GAD更改通知单号?"),_("确认"),wxYES_NO)!=wxYES)
    {
        return;
    }

    wxString s_sg_id = wxGetApp().get_ser_id(wxT("l_spec_gad_revised_inform_table"),wxT("asg_id"));

    wxString s_sql = wxT("INSERT INTO l_spec_gad_revised_inform_table(asg_id, asg_content, link_id, res_engineer, apply_person, apply_date, remarks, is_active, is_published) \
    VALUES('")+s_sg_id+wxT("','")+tc_sg_proj->GetValue()+wxT("','")+m_sg_links+wxT("','")+m_operators+wxT("','")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+
    tc_remarks->GetValue()+wxT("',true, false);");

    s_sql.Replace(wxT("''"),wxT("NULL"));

    if(wxGetApp().app_sql_update(s_sql))
    {
        wxMessageBox(_("SPEC&GAD更改通知单号")+s_sg_id);

        wxLogMessage(_("SPEC&GAD更改通知单号:")+s_sg_id);

        wxLogMessage(_("请到取号预览界面查看本人已经生成的SPEC&GAD更改通知单编号列表"));

    }

    m_sg_links.Empty();
    m_operators.Empty();
    tc_sg_proj->Clear();
    tc_sg_proj->Enable(false);
    tc_remarks->Clear();

}

void info_id_generator_panel::OnButton_sg_infoClick(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    wf_search dlg;

    int i_choice;
    wxString s_case;

    if(dlg.ShowModal() == wxID_OK)
    {
        i_choice = dlg.i_choice;
        s_case = dlg.str_search;

    }else
        return;


    wxString str;
    switch(i_choice)
    {
    case 0:
        str=wxT(" wbs_no like '%")+s_case+wxT("%' ");
        break;
    case 1:
        str = wxT(" project_id like '%")+s_case+wxT("%' ");
        break;
    case 2:
        str = wxT(" contract_id = '")+s_case+wxT("' ");
        break;
    case 3:
        str = wxT(" project_name like '%")+s_case+wxT("%' ");
        break;
    default:
        str.Empty();
        break;
    }

    if(str.IsEmpty())
        return;

    units_list_dlg u_dlg;
    u_dlg.set_clause(str);
    u_dlg.refresh_list();

    wxArrayString a_wbs, a_engineer;

    if(u_dlg.ShowModal()==wxID_OK)
    {
        a_wbs = u_dlg.array_select;
        a_engineer = u_dlg.array_engineer;
        str = u_dlg.m_proj;

    }else
      return;

    int i_count = a_engineer.GetCount();
    m_operators.Empty();

    for(int i=0;i<i_count;i++)
    {
        m_operators = m_operators+a_engineer.Item(i)+wxT(";");
    }

    i_count = a_wbs.GetCount();
    m_sg_links.Empty();

    for(int j=0;j<i_count;j++)
    {
        m_sg_links = m_sg_links + a_wbs.Item(j)+wxT(";");
    }

    wxString s_ser = str+wxT(" ")+combine_str(a_wbs, wxT(";"),wxT("~"),wxT(","),true, false).Item(0);

    tc_sg_proj->SetValue(s_ser);
    tc_sg_proj->Enable(true);

}

void info_id_generator_panel::OnButton_LL_genClick(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    wxString s_content = tc_ll->GetValue();

    if(s_content.IsEmpty())
    {
        wxMessageBox(_("请先填写内部联络单主题"),_("提示"));

        tc_ll->SetFocus();

        return;
    }

    if(wxMessageBox(_("确认生成内部联络单号?"),_("确认"),wxYES_NO)!=wxYES)
    {
        return;
    }

    wxString s_ll_id = wxGetApp().get_ser_id(wxT("l_internal_com_table"),wxT("ll_id"));

    wxString s_sql = wxT("INSERT INTO l_internal_com_table(ll_id, ll_content, apply_person, apply_date, remarks, is_active, is_published) \
         VALUES ('")+s_ll_id+wxT("','")+s_content+wxT("','")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+tc_remarks->GetValue()+
         wxT("',true, false);");

    s_sql.Replace(wxT("''"),wxT("NULL"));

    if(wxGetApp().app_sql_update(s_sql))
    {
        wxMessageBox(_("内部联络单号")+s_ll_id);

        wxLogMessage(_("内部联络单号:")+s_ll_id);

        wxLogMessage(_("请到取号预览界面查看本人已经生成的内部联络单编号列表"));

        tc_ll->Clear();
        tc_remarks->Clear();
    }

}

void info_id_generator_panel::OnButton_wbClick(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    wxString s_content = tc_wb_reason->GetValue();

    if(s_content.IsEmpty())
    {
        wxMessageBox(_("请先填写wbs bom更改原因"),_("提示"));

        tc_wb_reason->SetFocus();

        return;
    }

    if(wxMessageBox(_("确认BOM更改单编号?"),_("确认"),wxYES_NO)!=wxYES)
    {
        return;
    }

    bool b_is_pu = cb_pu->IsChecked();
    bool b_is_qm = cb_qm->IsChecked();
    bool b_is_ie = cb_ie->IsChecked();
    bool b_is_pp = cb_pp->IsChecked();
    bool b_is_lo = cb_lo->IsChecked();
    bool b_is_psm = cb_psm->IsChecked();
    bool b_is_pm = cb_pm->IsChecked();
    bool b_is_co = cb_co->IsChecked();
    bool b_is_others = cb_others->IsChecked();

    wxString s_bci_id = wxGetApp().get_ser_id(wxT("l_bom_change_inform_table"),wxT("bci_id"));

    wxString s_sql = wxT("INSERT INTO l_bom_change_inform_table(bci_id, bci_content, apply_person, apply_date, remarks, is_active, is_published, \
                         is_pu, is_qm, is_ie, is_pp, is_lo, is_psm, is_pm, is_co, is_others) \
    VALUES ('")+s_bci_id+wxT("','")+tc_wb_reason->GetValue()+wxT("','")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+tc_remarks->GetValue()+wxT("',true,false,")+
    BoolToStr(b_is_pu)+wxT(",")+BoolToStr(b_is_qm)+wxT(",")+BoolToStr(b_is_ie)+wxT(",")+BoolToStr(b_is_pp)+wxT(",")+BoolToStr(b_is_lo)+wxT(",")+BoolToStr(b_is_psm)+wxT(",")+BoolToStr(b_is_pm)+wxT(",")+
    BoolToStr(b_is_co)+wxT(",")+BoolToStr(b_is_others)+wxT(");");

    s_sql.Replace(wxT("''"),wxT("NULL"));
    if(wxGetApp().app_sql_update(s_sql))
    {
        wxMessageBox(_("BOM更改通知单号")+s_bci_id);

        wxLogMessage(_("BOM更改通知单号:")+s_bci_id);

        wxLogMessage(_("请到取号预览界面查看本人已经生成的BOM更改通知单号列表"));

        tc_wb_reason->Clear();
        tc_remarks->Clear();
        cb_pu->SetValue(false);
        cb_qm->SetValue(false);
        cb_ie->SetValue(false);
        cb_pp->SetValue(false);
        cb_lo->SetValue(false);
        cb_psm->SetValue(false);
        cb_pm->SetValue(false);
        cb_co->SetValue(false);
        cb_others->SetValue(false);
    }
}

void info_id_generator_panel::clear_tcen_ctrl()
{
    cb_nce_other->SetValue(false);
    cb_nce_pm->SetValue(false);;
    cb_nce_ds->SetValue(false);
    cb_nec_cs->SetValue(false);
    cb_nce_fq->SetValue(false);
    cb_nce_psm->SetValue(false);
    cb_nce_ppu->SetValue(false);
    cb_nce_lo->SetValue(false);
    cb_nce_co->SetValue(false);
    cb_nce_sm->SetValue(false);
    cb_nce_tm->SetValue(false);
   cb_nce_el->SetValue(false);
     cb_nce_sqe->SetValue(false);
    cb_nce_other->SetValue(false);
     cb_nce_pc->SetValue(false);
    cb_nce_urgent->SetValue(false);
   tc_nce_eco->Clear();
   tc_nce_subject->Clear();
    tc_remarks->Clear();
    dp_nce_valid->SetValue(wxDateTime::Today());
}

void info_id_generator_panel::OnButton_NCE_genClick(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    bool b_mpm=cb_nce_other->IsChecked();
    bool b_pm = cb_nce_pm->IsChecked();
    bool b_ds = cb_nce_ds->IsChecked();
    bool b_cs = cb_nec_cs->IsChecked();
    bool b_fq= cb_nce_fq->IsChecked();
    bool b_psm = cb_nce_psm->IsChecked();
    bool b_ppu = cb_nce_ppu->IsChecked();
    bool b_lo = cb_nce_lo->IsChecked();
    bool b_co = cb_nce_co->IsChecked();
    bool b_sm = cb_nce_sm->IsChecked();
    bool b_tm = cb_nce_tm->IsChecked();
    bool b_el = cb_nce_el->IsChecked();
    bool b_sqe = cb_nce_sqe->IsChecked();
    bool b_others = cb_nce_other->IsChecked();
    bool b_tcen_pc = cb_nce_pc->IsChecked();
    bool b_urgent = cb_nce_urgent->IsChecked();
    wxString s_from = tce_nce_from->GetValue();
    wxString s_eco = tc_nce_eco->GetValue();
    wxString s_subject = tc_nce_subject->GetValue();
    wxDateTime d_valid = dp_nce_valid->GetValue();
    wxString s_remarks = tc_remarks->GetValue();

    if(d_valid<wxDateTime::Today())
    {
        wxMessageBox(_("生效日期必须大于等于当天!"),_("提示!"));
        dp_nce_valid->SetValue(wxDateTime::Today());
        return;
    }

    if(cb_nce_other->IsChecked()&&s_remarks.IsEmpty())
    {
        wxMessageBox(_("请在备注中补充完整Others的具体信息"),_("提示!"));
        return;
    }

    if(s_subject.IsEmpty())
    {
        wxMessageBox(_("请务必填写主题。"),_("提示!"));
        tc_nce_subject->SetFocus();
        return;
    }

    if(wxMessageBox(_("确认生成技术变更执行通知单号?"),_("确认"),wxYES_NO)!=wxYES)
    {
        return;
    }

    wxString s_tcen_id = get_tcen_id();

    if(s_tcen_id.IsEmpty())
    {
        wxMessageBox(_("生成失败，请重新提交!"),_("提示"));
        return;
    }

    wxString s_sql = wxT("INSERT INTO l_tce_notice(tcen_id, subject, from_sr, eco_no, is_modify_pc, valid_date, is_urgent, is_mpm, is_pm,\
		is_ds, is_cs, is_fq, is_psm, is_lo, is_co, is_sm, is_tm, is_el, is_sqe, is_ppu, is_others, remarks, apply_person,\
		apply_date,is_active, is_published) \
       VALUES ('")+s_tcen_id+wxT("','")+s_subject+wxT("','")+s_from+wxT("','")+s_eco+wxT("',")+BoolToStr(b_tcen_pc)+wxT(",'")+DateToStrFormat(d_valid )+wxT("',")+BoolToStr(b_urgent)+wxT(",")+BoolToStr(b_mpm)+
             wxT(",")+BoolToStr(b_pm)+wxT(",")+BoolToStr(b_ds)+wxT(",")+BoolToStr(b_cs)+wxT(",")+BoolToStr(b_fq)+wxT(",")+BoolToStr(b_psm)+wxT(",")+BoolToStr(b_lo)+wxT(",")+BoolToStr(b_co)+
             wxT(",")+BoolToStr(b_sm)+wxT(",")+BoolToStr(b_tm)+wxT(",")+BoolToStr(b_el)+wxT(",")+BoolToStr(b_sqe)+wxT(",")+BoolToStr(b_ppu)+wxT(",")+BoolToStr(b_others)+wxT(",'")+s_remarks+wxT("','")+
             gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("',true, false);");


    //wxLogMessage(s_sql);
    s_sql.Replace(wxT("''"),wxT("NULL"));

    if(wxGetApp().app_sql_update(s_sql))
    {
        wxMessageBox(_("技术变更执行通知单号")+s_tcen_id);

        wxLogMessage(_("技术变更执行通知单号:")+s_tcen_id);

        wxLogMessage(_("请到取号预览界面查看本人已经生成的技术变更执行通知单号列表"));
        clear_tcen_ctrl();
    }

}

wxString info_id_generator_panel::get_tcen_id()
{
    wxDateTime today = wxDateTime::Today();

    wxString s_pre =DateToYearMonth(today);

    wxString s_sql = wxT("select id_now from s_tcen_id_record where tcen_pre='")+s_pre+wxT("';");

    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(s_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return wxEmptyString;
    }

    int i_count =  _res->GetRowsNumber();
    int i_tcne_id =0;

    if(i_count ==0)
    {
       i_tcne_id= 1;

       s_sql = wxT("INSERT INTO s_tcen_id_record( tcen_pre, id_now) VALUES ('")+s_pre+wxT("',")+NumToStr(i_tcne_id)+wxT(");");
    }else
    {
        i_tcne_id = _res->GetInt(wxT("id_now"))+1;

        s_sql = wxT("UPDATE s_tcen_id_record SET id_now=")+NumToStr(i_tcne_id)+wxT(" where tcen_pre='")+s_pre+wxT("';");
    }

    _res->Clear();

    if(wxGetApp().app_sql_update(s_sql))
    {
        return "TCEN-ECO(tkES)-"+s_pre+zero_begin(i_tcne_id, 3);
    }

    return wxEmptyString;
}
