#include "nstd_mat_apply.h"
#include "nstd_mat_task_list.h"
#include "wfApp.h"
#include <wx/choicdlg.h>
#include "nstd_app_search.h"
#include "nstd_task_author.h"
#include "nstd_app_item_units.h"
#include <wx/textfile.h>
#include <wx/clipbrd.h>
#include "ins_nonstd_proc_log.h"
#include "nstd_app_unit_list.h"
#include "nstd_mat_muti_level_task_list.h"
#include <wx/choicdlg.h>
#include "configure_mat_list_editor.h"
#include <wx/textdlg.h>
#include "nstd_ins_doc.h"
#include "unit_info_attach_dlg.h"

//(*InternalHeaders(nstd_mat_apply)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(nstd_mat_apply)
const long nstd_mat_apply::ID_BUTTON_RECEIVE = wxNewId();
const long nstd_mat_apply::ID_BUTTON_CONF_APPLY = wxNewId();
const long nstd_mat_apply::ID_BUTTON_TASK_LIST = wxNewId();
const long nstd_mat_apply::ID_BUTTON_GENERATE = wxNewId();
const long nstd_mat_apply::ID_BUTTON_ADD_BATCH = wxNewId();
const long nstd_mat_apply::ID_BUTTON_SEARCH = wxNewId();
const long nstd_mat_apply::ID_BUTTON_CANCEL = wxNewId();
const long nstd_mat_apply::ID_BUTTON_CLEAN = wxNewId();
const long nstd_mat_apply::ID_BUTTON_Print = wxNewId();
const long nstd_mat_apply::ID_STATICTEXT1 = wxNewId();
const long nstd_mat_apply::ID_STATICTEXT8 = wxNewId();
const long nstd_mat_apply::ID_TEXTCTRL_INDEX_ID = wxNewId();
const long nstd_mat_apply::ID_STATICTEXT2 = wxNewId();
const long nstd_mat_apply::ID_TEXTCTRL_PROJECT_ID = wxNewId();
const long nstd_mat_apply::ID_TEXTCTRL_NSTD_MAT_APP = wxNewId();
const long nstd_mat_apply::ID_STATICTEXT3 = wxNewId();
const long nstd_mat_apply::ID_TEXTCTRL_PROJECT_NAME = wxNewId();
const long nstd_mat_apply::ID_BUTTON_REL = wxNewId();
const long nstd_mat_apply::ID_BUTTON_WORKFLOW = wxNewId();
const long nstd_mat_apply::ID_BUTTON_NSTD_INS_DOC = wxNewId();
const long nstd_mat_apply::ID_BUTTON_HEADER = wxNewId();
const long nstd_mat_apply::ID_STATICTEXT4 = wxNewId();
const long nstd_mat_apply::ID_DATEPICKERCTRL1 = wxNewId();
const long nstd_mat_apply::ID_STATICTEXT5 = wxNewId();
const long nstd_mat_apply::ID_STATICTEXT14 = wxNewId();
const long nstd_mat_apply::ID_DATEPICKERCTRL_DRAW_REQ = wxNewId();
const long nstd_mat_apply::ID_COMBOBOX_NSTD_ITEM_CATALOG = wxNewId();
const long nstd_mat_apply::ID_STATICTEXT6 = wxNewId();
const long nstd_mat_apply::ID_STATICTEXT7 = wxNewId();
const long nstd_mat_apply::ID_TEXTCTRL_NSTD_REASON = wxNewId();
const long nstd_mat_apply::ID_TEXTCTRL_BATCH_ID = wxNewId();
const long nstd_mat_apply::ID_SPINBUTTON_BATCH_ID = wxNewId();
const long nstd_mat_apply::ID_STATICTEXT9 = wxNewId();
const long nstd_mat_apply::ID_STATICTEXT13 = wxNewId();
const long nstd_mat_apply::ID_TEXTCTRL_RES_PERSON = wxNewId();
const long nstd_mat_apply::ID_DATEPICKERCTRL_AU_DATE = wxNewId();
const long nstd_mat_apply::ID_STATICTEXT10 = wxNewId();
const long nstd_mat_apply::ID_TEXTCTRL_NSTD_ENGINEER = wxNewId();
const long nstd_mat_apply::ID_BUTTON_ENGINEER = wxNewId();
const long nstd_mat_apply::ID_BUTTON_RETURN = wxNewId();
const long nstd_mat_apply::ID_TEXTCTRL_LOW_STATUS = wxNewId();
const long nstd_mat_apply::ID_STATICTEXT11 = wxNewId();
const long nstd_mat_apply::ID_TEXTCTRL_LOW_NSTD_REASON = wxNewId();
const long nstd_mat_apply::ID_STATICTEXT12 = wxNewId();
const long nstd_mat_apply::ID_TEXTCTRL_LOW_NSTD_FEEDBACK = wxNewId();
const long nstd_mat_apply::ID_BUTTON_LOW_CONFIRM = wxNewId();
const long nstd_mat_apply::ID_BUTTON_LOW_REL = wxNewId();
const long nstd_mat_apply::ID_TEXTCTRL_REMARKS = wxNewId();
const long nstd_mat_apply::ID_BUTTON_PASS_NSTD = wxNewId();
const long nstd_mat_apply::ID_CHECKBOX_MAT = wxNewId();
const long nstd_mat_apply::ID_CHECKBOX_DRAWING = wxNewId();
const long nstd_mat_apply::ID_TEXTCTRL_MAT_STATUS = wxNewId();
const long nstd_mat_apply::ID_TEXTCTRL_WF_MAT = wxNewId();
const long nstd_mat_apply::ID_TEXTCTRL_DRAW_STATUS = wxNewId();
const long nstd_mat_apply::ID_TEXTCTRL_WF_DRAW = wxNewId();
const long nstd_mat_apply::ID_BUTTON_SUBMIT_MAT = wxNewId();
const long nstd_mat_apply::ID_BUTTON_DRAWING = wxNewId();
const long nstd_mat_apply::ID_BUTTON_WORKFLOW_MAT = wxNewId();
const long nstd_mat_apply::ID_BUTTON_WORKFLOW_DRAW = wxNewId();
const long nstd_mat_apply::ID_BUTTON_PREVIOUS = wxNewId();
const long nstd_mat_apply::ID_TEXTCTRL_QTY = wxNewId();
const long nstd_mat_apply::ID_BUTTON_NEXT = wxNewId();
const long nstd_mat_apply::ID_BUTTON_BEGIN = wxNewId();
const long nstd_mat_apply::ID_BUTTON_END = wxNewId();
const long nstd_mat_apply::ID_GRID_MAT_LIST = wxNewId();
const long nstd_mat_apply::ID_BUTTON_IMPORT_MAT = wxNewId();
const long nstd_mat_apply::ID_BUTTON_ADD = wxNewId();
const long nstd_mat_apply::ID_BUTTON_DEL = wxNewId();
const long nstd_mat_apply::ID_TEXTCTRL_ROW = wxNewId();
const long nstd_mat_apply::ID_BUTTON_CHANGE_RELATION = wxNewId();
const long nstd_mat_apply::ID_BUTTON_REL_UNTIS = wxNewId();
const long nstd_mat_apply::ID_BUTTON_UNIT_LIST = wxNewId();
//*)

BEGIN_EVENT_TABLE(nstd_mat_apply,wxPanel)
	//(*EventTable(nstd_mat_apply)
	//*)
END_EVENT_TABLE()

nstd_mat_apply::nstd_mat_apply(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size, int _mode)
{
	//(*Initialize(nstd_mat_apply)
	wxBoxSizer* BoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxBoxSizer* BoxSizer5;
	wxGridBagSizer* GridBagSizer4;
	wxGridBagSizer* GridBagSizer1;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxGridBagSizer* GridBagSizer2;
	wxBoxSizer* BoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;
	wxStaticBoxSizer* StaticBoxSizer5;
	wxGridBagSizer* GridBagSizer3;

	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	wxFont thisFont(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	SetFont(thisFont);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button_Receive = new wxButton(this, ID_BUTTON_RECEIVE, _("接收非标任务"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_RECEIVE"));
	BoxSizer2->Add(Button_Receive, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_CONF_APPLY = new wxButton(this, ID_BUTTON_CONF_APPLY, _("配置非标申请"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CONF_APPLY"));
	BoxSizer2->Add(Button_CONF_APPLY, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_task_list = new wxButton(this, ID_BUTTON_TASK_LIST, _("组内人员实时任务列表"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_TASK_LIST"));
	BoxSizer2->Add(Button_task_list, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Generate = new wxButton(this, ID_BUTTON_GENERATE, _("生成非标申请(CS,MOD等)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_GENERATE"));
	BoxSizer2->Add(Button_Generate, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Add_Batch = new wxButton(this, ID_BUTTON_ADD_BATCH, _("新增物料申请批次"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_ADD_BATCH"));
	BoxSizer2->Add(Button_Add_Batch, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Search = new wxButton(this, ID_BUTTON_SEARCH, _("申请查询"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_SEARCH"));
	BoxSizer2->Add(Button_Search, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Cancel = new wxButton(this, ID_BUTTON_CANCEL, _("删除批次/分任务"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CANCEL"));
	BoxSizer2->Add(Button_Cancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Clean = new wxButton(this, ID_BUTTON_CLEAN, _("统一后台数据"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CLEAN"));
	Button_Clean->Hide();
	BoxSizer2->Add(Button_Clean, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	Button_Print = new wxButton(this, ID_BUTTON_Print, _("打印物料申请"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_Print"));
	BoxSizer2->Add(Button_Print, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND, 0);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("项次信息"));
	GridBagSizer1 = new wxGridBagSizer(0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("物料申请编号"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	GridBagSizer1->Add(StaticText1, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxEXPAND, 5);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("分任务批号"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	GridBagSizer1->Add(StaticText8, wxGBPosition(0, 1), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_index_id = new wxTextCtrl(this, ID_TEXTCTRL_INDEX_ID, wxEmptyString, wxDefaultPosition, wxSize(80,21), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_INDEX_ID"));
	GridBagSizer1->Add(tc_index_id, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxEXPAND, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("项目编号"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	GridBagSizer1->Add(StaticText2, wxGBPosition(0, 3), wxDefaultSpan, wxALL|wxEXPAND, 5);
	tc_project_id = new wxTextCtrl(this, ID_TEXTCTRL_PROJECT_ID, wxEmptyString, wxDefaultPosition, wxSize(75,24), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_PROJECT_ID"));
	GridBagSizer1->Add(tc_project_id, wxGBPosition(1, 3), wxDefaultSpan, wxALL|wxEXPAND, 5);
	tc_nstd_mat_app_id = new wxTextCtrl(this, ID_TEXTCTRL_NSTD_MAT_APP, wxEmptyString, wxDefaultPosition, wxSize(75,24), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_NSTD_MAT_APP"));
	GridBagSizer1->Add(tc_nstd_mat_app_id, wxGBPosition(1, 2), wxDefaultSpan, wxALL|wxEXPAND, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("项目名称"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	GridBagSizer1->Add(StaticText3, wxGBPosition(0, 4), wxDefaultSpan, wxALL|wxEXPAND, 5);
	tc_project_name = new wxTextCtrl(this, ID_TEXTCTRL_PROJECT_NAME, wxEmptyString, wxDefaultPosition, wxSize(257,25), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_PROJECT_NAME"));
	GridBagSizer1->Add(tc_project_name, wxGBPosition(1, 4), wxDefaultSpan, wxALL|wxEXPAND, 5);
	Button_Rel = new wxButton(this, ID_BUTTON_REL, _("关联项目..."), wxDefaultPosition, wxSize(122,24), 0, wxDefaultValidator, _T("ID_BUTTON_REL"));
	GridBagSizer1->Add(Button_Rel, wxGBPosition(1, 6), wxDefaultSpan, wxALL|wxEXPAND, 5);
	Button_Workflow = new wxButton(this, ID_BUTTON_WORKFLOW, _("显示非标申请工作流"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_WORKFLOW"));
	GridBagSizer1->Add(Button_Workflow, wxGBPosition(0, 6), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Button_Nonstd_Ins_Doc = new wxButton(this, ID_BUTTON_NSTD_INS_DOC, _("非标安装文档设定"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_NSTD_INS_DOC"));
	GridBagSizer1->Add(Button_Nonstd_Ins_Doc, wxGBPosition(0, 7), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Same_header = new wxButton(this, ID_BUTTON_HEADER, _("相关项次信息..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_HEADER"));
	GridBagSizer1->Add(Button_Same_header, wxGBPosition(1, 7), wxDefaultSpan, wxALL|wxEXPAND, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("物料需求日"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	GridBagSizer1->Add(StaticText4, wxGBPosition(2, 0), wxDefaultSpan, wxALL|wxEXPAND, 5);
	dp_mat_req = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL1, wxDefaultDateTime, wxDefaultPosition, wxSize(94,24), wxDP_DEFAULT|wxDP_DROPDOWN|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL1"));
	GridBagSizer1->Add(dp_mat_req, wxGBPosition(3, 0), wxDefaultSpan, wxALL|wxEXPAND, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("图纸需求日"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	GridBagSizer1->Add(StaticText5, wxGBPosition(2, 1), wxDefaultSpan, wxALL|wxEXPAND, 5);
	StaticText10 = new wxStaticText(this, ID_STATICTEXT14, _("项目授权日"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
	GridBagSizer1->Add(StaticText10, wxGBPosition(4, 1), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	dp_draw_req = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL_DRAW_REQ, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL_DRAW_REQ"));
	GridBagSizer1->Add(dp_draw_req, wxGBPosition(3, 1), wxDefaultSpan, wxALL|wxEXPAND, 5);
	combo_nstd_item_catalog = new wxComboBox(this, ID_COMBOBOX_NSTD_ITEM_CATALOG, wxEmptyString, wxDefaultPosition, wxSize(165,22), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_NSTD_ITEM_CATALOG"));
	combo_nstd_item_catalog->Append(_("整梯BOM"));
	combo_nstd_item_catalog->Append(_("人机界面"));
	combo_nstd_item_catalog->Append(_("轿厢"));
	combo_nstd_item_catalog->Append(_("井道部件"));
	combo_nstd_item_catalog->Append(_("控制系统"));
	combo_nstd_item_catalog->Append(_("机房部件"));
	combo_nstd_item_catalog->Append(_("轿厢架"));
	combo_nstd_item_catalog->Append(_("门系统"));
	combo_nstd_item_catalog->Append(_("电缆"));
	combo_nstd_item_catalog->Append(_("对重系统"));
	combo_nstd_item_catalog->Append(_("其他"));
	GridBagSizer1->Add(combo_nstd_item_catalog, wxGBPosition(3, 2), wxGBSpan(1, 2), wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("非标类别"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	GridBagSizer1->Add(StaticText6, wxGBPosition(2, 2), wxGBSpan(1, 2), wxALL|wxEXPAND, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("非标原因"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	GridBagSizer1->Add(StaticText7, wxGBPosition(2, 4), wxDefaultSpan, wxALL|wxEXPAND, 5);
	tc_nstd_reason = new wxTextCtrl(this, ID_TEXTCTRL_NSTD_REASON, wxEmptyString, wxDefaultPosition, wxSize(618,32), wxTE_PROCESS_ENTER|wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL_NSTD_REASON"));
	GridBagSizer1->Add(tc_nstd_reason, wxGBPosition(3, 4), wxGBSpan(2, 4), wxALL|wxEXPAND, 5);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	tc_batch_id = new wxTextCtrl(this, ID_TEXTCTRL_BATCH_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_BATCH_ID"));
	tc_batch_id->SetMinSize(wxSize(-1,-1));
	BoxSizer5->Add(tc_batch_id, 4, wxALL|wxEXPAND, 5);
	spb_batch_id = new wxSpinButton(this, ID_SPINBUTTON_BATCH_ID, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL|wxSP_ARROW_KEYS, _T("ID_SPINBUTTON_BATCH_ID"));
	spb_batch_id->SetRange(0, 100);
	BoxSizer5->Add(spb_batch_id, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	GridBagSizer1->Add(BoxSizer5, wxGBPosition(1, 1), wxDefaultSpan, wxALL|wxEXPAND, 0);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("非标物料申请号"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	GridBagSizer1->Add(StaticText9, wxGBPosition(0, 2), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	st_res_person = new wxStaticText(this, ID_STATICTEXT13, _("非标申请负责人"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
	GridBagSizer1->Add(st_res_person, wxGBPosition(0, 5), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_res_person = new wxTextCtrl(this, ID_TEXTCTRL_RES_PERSON, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_RES_PERSON"));
	GridBagSizer1->Add(tc_res_person, wxGBPosition(1, 5), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	dp_proj_au_date = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL_AU_DATE, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL_AU_DATE"));
	GridBagSizer1->Add(dp_proj_au_date, wxGBPosition(4, 2), wxGBSpan(1, 2), wxALL|wxEXPAND, 5);
	StaticBoxSizer1->Add(GridBagSizer1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 0);
	StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("分任务信息"));
	GridBagSizer4 = new wxGridBagSizer(0, 0);
	st_nstd_engineer = new wxStaticText(this, ID_STATICTEXT10, _("非标工程师"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	GridBagSizer4->Add(st_nstd_engineer, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	tc_engineer = new wxTextCtrl(this, ID_TEXTCTRL_NSTD_ENGINEER, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_NSTD_ENGINEER"));
	GridBagSizer4->Add(tc_engineer, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	Button_Engineer = new wxButton(this, ID_BUTTON_ENGINEER, _("指定非标工程师"), wxDefaultPosition, wxSize(110,23), 0, wxDefaultValidator, _T("ID_BUTTON_ENGINEER"));
	GridBagSizer4->Add(Button_Engineer, wxGBPosition(1, 2), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 3);
	Button_Return = new wxButton(this, ID_BUTTON_RETURN, _("退回任务"), wxDefaultPosition, wxSize(97,23), 0, wxDefaultValidator, _T("ID_BUTTON_RETURN"));
	GridBagSizer4->Add(Button_Return, wxGBPosition(1, 3), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
	tc_low_status = new wxTextCtrl(this, ID_TEXTCTRL_LOW_STATUS, wxEmptyString, wxDefaultPosition, wxSize(54,21), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_LOW_STATUS"));
	GridBagSizer4->Add(tc_low_status, wxGBPosition(1, 1), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	st_low_nstd_reason = new wxStaticText(this, ID_STATICTEXT11, _("分任务非标原因"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	GridBagSizer4->Add(st_low_nstd_reason, wxGBPosition(0, 4), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	tc_low_nstd_reason = new wxTextCtrl(this, ID_TEXTCTRL_LOW_NSTD_REASON, wxEmptyString, wxDefaultPosition, wxSize(188,32), wxTE_PROCESS_ENTER|wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL_LOW_NSTD_REASON"));
	GridBagSizer4->Add(tc_low_nstd_reason, wxGBPosition(1, 4), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 2);
	st_low_nstd_feedback = new wxStaticText(this, ID_STATICTEXT12, _("分任务回复信息"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	GridBagSizer4->Add(st_low_nstd_feedback, wxGBPosition(0, 5), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	tc_low_nstd_feedback = new wxTextCtrl(this, ID_TEXTCTRL_LOW_NSTD_FEEDBACK, wxEmptyString, wxDefaultPosition, wxSize(239,32), wxTE_PROCESS_ENTER|wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL_LOW_NSTD_FEEDBACK"));
	GridBagSizer4->Add(tc_low_nstd_feedback, wxGBPosition(1, 5), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	Button_Low_Confirm = new wxButton(this, ID_BUTTON_LOW_CONFIRM, _("分任务完成确认"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_LOW_CONFIRM"));
	GridBagSizer4->Add(Button_Low_Confirm, wxGBPosition(1, 6), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 3);
	Button_Low_Rel = new wxButton(this, ID_BUTTON_LOW_REL, _("相关分任务信息"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_LOW_REL"));
	GridBagSizer4->Add(Button_Low_Rel, wxGBPosition(1, 7), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 3);
	StaticBoxSizer5->Add(GridBagSizer4, 0, wxALL|wxEXPAND|wxFIXED_MINSIZE, 0);
	BoxSizer1->Add(StaticBoxSizer5, 1, wxALL|wxEXPAND, 0);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("回复配置信息"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer1->AddGrowableCol(2);
	tc_remarks = new wxTextCtrl(this, ID_TEXTCTRL_REMARKS, wxEmptyString, wxDefaultPosition, wxSize(477,32), wxTE_PROCESS_ENTER|wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL_REMARKS"));
	FlexGridSizer1->Add(tc_remarks, 1, wxALL|wxEXPAND, 0);
	Button_PASS_NSTD = new wxButton(this, ID_BUTTON_PASS_NSTD, _("配置信息传递"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_PASS_NSTD"));
	FlexGridSizer1->Add(Button_PASS_NSTD, 1, wxALL|wxEXPAND, 0);
	StaticBoxSizer4->Add(FlexGridSizer1, 0, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(StaticBoxSizer4, 1, wxALL|wxEXPAND, 0);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("附加信息"));
	GridBagSizer2 = new wxGridBagSizer(0, 0);
	GridBagSizer2->AddGrowableRow(5);
	cb_nstd_mat = new wxCheckBox(this, ID_CHECKBOX_MAT, _("需要非标物料号"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_MAT"));
	cb_nstd_mat->SetValue(false);
	GridBagSizer2->Add(cb_nstd_mat, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxEXPAND, 2);
	cb_nstd_drawing = new wxCheckBox(this, ID_CHECKBOX_DRAWING, _("需要非标图纸"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_DRAWING"));
	cb_nstd_drawing->SetValue(false);
	GridBagSizer2->Add(cb_nstd_drawing, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxEXPAND, 2);
	tc_mat_status = new wxTextCtrl(this, ID_TEXTCTRL_MAT_STATUS, wxEmptyString, wxDefaultPosition, wxSize(48,21), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_MAT_STATUS"));
	GridBagSizer2->Add(tc_mat_status, wxGBPosition(0, 1), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	tc_mat_wf_status = new wxTextCtrl(this, ID_TEXTCTRL_WF_MAT, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_WF_MAT"));
	GridBagSizer2->Add(tc_mat_wf_status, wxGBPosition(0, 2), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	tc_draw_status = new wxTextCtrl(this, ID_TEXTCTRL_DRAW_STATUS, wxEmptyString, wxDefaultPosition, wxSize(48,21), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_DRAW_STATUS"));
	GridBagSizer2->Add(tc_draw_status, wxGBPosition(1, 1), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	tc_draw_wf_status = new wxTextCtrl(this, ID_TEXTCTRL_WF_DRAW, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_WF_DRAW"));
	GridBagSizer2->Add(tc_draw_wf_status, wxGBPosition(1, 2), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	Button_Submit = new wxButton(this, ID_BUTTON_SUBMIT_MAT, _("提交非标物料申请"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_SUBMIT_MAT"));
	GridBagSizer2->Add(Button_Submit, wxGBPosition(0, 3), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 3);
	Button_drawing = new wxButton(this, ID_BUTTON_DRAWING, _("提交非标设计申请"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_DRAWING"));
	GridBagSizer2->Add(Button_drawing, wxGBPosition(1, 3), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 3);
	Button_workflow_mat = new wxButton(this, ID_BUTTON_WORKFLOW_MAT, _("显示非标物料工作流"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_WORKFLOW_MAT"));
	GridBagSizer2->Add(Button_workflow_mat, wxGBPosition(0, 4), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 3);
	Button_workflow_draw = new wxButton(this, ID_BUTTON_WORKFLOW_DRAW, _("显示非标设计工作流"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_WORKFLOW_DRAW"));
	GridBagSizer2->Add(Button_workflow_draw, wxGBPosition(1, 4), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 3);
	StaticBoxSizer3->Add(GridBagSizer2, 1, wxALL|wxALIGN_TOP, 0);
	GridBagSizer3 = new wxGridBagSizer(0, 0);
	Button_Previous = new wxButton(this, ID_BUTTON_PREVIOUS, _("<-"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_PREVIOUS"));
	GridBagSizer3->Add(Button_Previous, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxEXPAND, 5);
	tc_qty = new wxTextCtrl(this, ID_TEXTCTRL_QTY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_QTY"));
	GridBagSizer3->Add(tc_qty, wxGBPosition(0, 1), wxGBSpan(1, 2), wxALL|wxEXPAND, 5);
	Button_Next = new wxButton(this, ID_BUTTON_NEXT, _("->"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_NEXT"));
	GridBagSizer3->Add(Button_Next, wxGBPosition(0, 3), wxDefaultSpan, wxALL|wxEXPAND, 5);
	Button_Begin = new wxButton(this, ID_BUTTON_BEGIN, _("<<--"), wxDefaultPosition, wxSize(122,23), 0, wxDefaultValidator, _T("ID_BUTTON_BEGIN"));
	GridBagSizer3->Add(Button_Begin, wxGBPosition(1, 0), wxGBSpan(2, 2), wxALL|wxEXPAND, 5);
	Button_End = new wxButton(this, ID_BUTTON_END, _("-->>"), wxDefaultPosition, wxSize(115,23), 0, wxDefaultValidator, _T("ID_BUTTON_END"));
	GridBagSizer3->Add(Button_End, wxGBPosition(1, 2), wxGBSpan(2, 2), wxALL|wxEXPAND, 5);
	StaticBoxSizer3->Add(GridBagSizer3, 0, wxALL|wxALIGN_TOP, 0);
	BoxSizer1->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND, 0);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("配置物料清单"));
	gd_mat_list = new nstdappGrid(this, ID_GRID_MAT_LIST, wxDefaultPosition, wxSize(1000,-1));
	StaticBoxSizer2->Add(gd_mat_list, 5, wxALL|wxEXPAND, 0);
	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	Button_Import_Mat = new wxButton(this, ID_BUTTON_IMPORT_MAT, _("剪贴板导入清单"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_IMPORT_MAT"));
	BoxSizer4->Add(Button_Import_Mat, 1, wxALL|wxEXPAND, 0);
	Button_Add = new wxButton(this, ID_BUTTON_ADD, _("+"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_ADD"));
	Button_Add->SetMinSize(wxSize(-1,-1));
	BoxSizer4->Add(Button_Add, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 0);
	Button_Del = new wxButton(this, ID_BUTTON_DEL, _("-"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_DEL"));
	Button_Del->SetMinSize(wxSize(-1,-1));
	BoxSizer4->Add(Button_Del, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 0);
	tc_row = new wxTextCtrl(this, ID_TEXTCTRL_ROW, _("1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL_ROW"));
	tc_row->SetMinSize(wxSize(-1,-1));
	BoxSizer4->Add(tc_row, 1, wxALL|wxEXPAND, 0);
	button_change_rel = new wxButton(this, ID_BUTTON_CHANGE_RELATION, _("清单修改"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CHANGE_RELATION"));
	BoxSizer4->Add(button_change_rel, 1, wxALL|wxEXPAND, 0);
	Button_Rel_Units = new wxButton(this, ID_BUTTON_REL_UNTIS, _("批量修改相关梯"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_REL_UNTIS"));
	BoxSizer4->Add(Button_Rel_Units, 1, wxALL|wxEXPAND, 0);
	Button_Unit = new wxButton(this, ID_BUTTON_UNIT_LIST, _("按单梯显示物料清单"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_UNIT_LIST"));
	BoxSizer4->Add(Button_Unit, 1, wxALL|wxEXPAND, 0);
	StaticBoxSizer2->Add(BoxSizer4, 1, wxALL|wxALIGN_TOP, 5);
	BoxSizer1->Add(StaticBoxSizer2, 7, wxALL|wxEXPAND, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON_RECEIVE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_ReceiveClick);
	Connect(ID_BUTTON_CONF_APPLY,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_CONF_APPLYClick);
	Connect(ID_BUTTON_TASK_LIST,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_task_listClick);
	Connect(ID_BUTTON_GENERATE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_GenerateClick);
	Connect(ID_BUTTON_ADD_BATCH,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_Add_BatchClick);
	Connect(ID_BUTTON_SEARCH,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_SearchClick);
	Connect(ID_BUTTON_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_CancelClick);
	Connect(ID_BUTTON_CLEAN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_CleanClick);
	Connect(ID_BUTTON_Print,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_PrintClick);
	Connect(ID_BUTTON_REL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_RelClick);
	Connect(ID_BUTTON_WORKFLOW,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_WorkflowClick);
	Connect(ID_BUTTON_NSTD_INS_DOC,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_Nonstd_Ins_DocClick);
	Connect(ID_BUTTON_HEADER,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_Same_headerClick);
	Connect(ID_DATEPICKERCTRL1,wxEVT_DATE_CHANGED,(wxObjectEventFunction)&nstd_mat_apply::Ondp_mat_reqChanged);
	Connect(ID_DATEPICKERCTRL_DRAW_REQ,wxEVT_DATE_CHANGED,(wxObjectEventFunction)&nstd_mat_apply::Ondp_draw_reqChanged);
	Connect(ID_COMBOBOX_NSTD_ITEM_CATALOG,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&nstd_mat_apply::Oncombo_nstd_item_catalogTextUpdated);
	Connect(ID_TEXTCTRL_NSTD_REASON,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&nstd_mat_apply::Ontc_nstd_reasonTextEnter);
	Connect(ID_SPINBUTTON_BATCH_ID,wxEVT_SCROLL_LINEUP,(wxObjectEventFunction)&nstd_mat_apply::Onspb_batch_idChangeUp);
	Connect(ID_SPINBUTTON_BATCH_ID,wxEVT_SCROLL_LINEDOWN,(wxObjectEventFunction)&nstd_mat_apply::Onspb_batch_idChangeDown);
	Connect(ID_BUTTON_ENGINEER,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_EngineerClick);
	Connect(ID_BUTTON_RETURN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_ReturnClick);
	Connect(ID_TEXTCTRL_LOW_NSTD_REASON,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&nstd_mat_apply::Ontc_low_nstd_reasonTextEnter);
	Connect(ID_TEXTCTRL_LOW_NSTD_FEEDBACK,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&nstd_mat_apply::Ontc_low_nstd_feedbackTextEnter);
	Connect(ID_BUTTON_LOW_CONFIRM,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_Low_ConfirmClick);
	Connect(ID_BUTTON_LOW_REL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_Low_RelClick);
	Connect(ID_TEXTCTRL_REMARKS,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&nstd_mat_apply::Ontc_remarksText);
	Connect(ID_BUTTON_PASS_NSTD,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_PASS_NSTDClick);
	Connect(ID_CHECKBOX_MAT,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::Oncb_nstd_matClick);
	Connect(ID_CHECKBOX_DRAWING,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::Oncb_nstd_drawingClick);
	Connect(ID_BUTTON_SUBMIT_MAT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_SubmitClick);
	Connect(ID_BUTTON_DRAWING,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_drawingClick);
	Connect(ID_BUTTON_WORKFLOW_MAT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_workflow_matClick);
	Connect(ID_BUTTON_WORKFLOW_DRAW,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_workflow_drawClick);
	Connect(ID_BUTTON_PREVIOUS,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_PreviousClick);
	Connect(ID_BUTTON_NEXT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_NextClick);
	Connect(ID_BUTTON_BEGIN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_BeginClick);
	Connect(ID_BUTTON_END,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_EndClick);
	Connect(ID_GRID_MAT_LIST,wxEVT_GRID_SELECT_CELL,(wxObjectEventFunction)&nstd_mat_apply::Ongd_mat_listCellSelect);
	Connect(ID_BUTTON_IMPORT_MAT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_Import_MatClick);
	Connect(ID_BUTTON_ADD,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_AddClick);
	Connect(ID_BUTTON_DEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_DelClick);
	Connect(ID_BUTTON_CHANGE_RELATION,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::Onbutton_change_relClick);
	Connect(ID_BUTTON_REL_UNTIS,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_Rel_UnitsClick);
	Connect(ID_BUTTON_UNIT_LIST,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_mat_apply::OnButton_UnitClick);
	//*)


 //   GridBagSizer1->AddGrowableCol(3);
  //  GridBagSizer2->AddGrowableCol(3);

    sb_low_task = StaticBoxSizer5->GetStaticBox();
    sb_feedback_configure = StaticBoxSizer4->GetStaticBox();
    sb_att_info = StaticBoxSizer3->GetStaticBox();


    m_search_mode = false;
    m_receive_mode=-1;

    m_mat_req = cb_nstd_mat->IsChecked();
    m_draw_req = cb_nstd_drawing->IsChecked();

    m_group = wxGetApp().get_only_group();
    m_design = wxGetApp().is_design(m_group);
    m_cs_mode=false;

   if(m_group == wxT("G0003")||m_group == wxT("G0004")|| m_group == wxT("G0005")||m_group==wxT("G0018"))
    {

        StaticText8->SetLabel(wxT("批次"));
        Button_Generate->SetLabel(wxT("生成非标申请(CS等)"));

        m_use_status = 0;
    }else if(m_group == wxT("G0006")||m_group == wxT("G0007")|| m_group == wxT("G0008"))
    {
        if(_mode==0)
        {
            Button_Generate->SetLabel(wxT("生成非标申请(CS等)"));
            StaticText8->SetLabel(wxT("分任务号"));
            m_use_status = 1;
        }
        else if(_mode==1)
        {
            StaticText8->SetLabel(wxT("批次"));
            Button_Generate->SetLabel(wxT("生成非标申请(CS等)"));
            m_use_status = 0;
        }
    }else if(m_group == wxT("G0013"))
    {
        Button_Generate->SetLabel(wxT("生成非标申请(MOD)"));
        StaticText8->SetLabel(wxT("批次"));
        m_use_status = 4;
    }else
    {
         m_use_status = 0;
    }

    combo_nstd_item_catalog->Enable(false);
    show_gui_control();
    init_list_header();
    show_control(false);
    enable_grid(false);
}

nstd_mat_apply::~nstd_mat_apply()
{
	//(*Destroy(nstd_mat_apply)
	//*)
}


void nstd_mat_apply::OnButton_ReceiveClick(wxCommandEvent& event)
{
   StaticText8->SetLabel(wxT("分任务号"));
   int answer ;

    if(m_design)
    {
        m_receive_mode=1;
    }
    else
    {


        answer = wxMessageBox("非标整梯BOM任务?(否-配置非标申请)", "确认", wxYES_NO | wxCANCEL);

        if(answer == wxCANCEL)
        {
            m_receive_mode=-1;
            return;
        }

        if(answer == wxYES)
            m_receive_mode = 1;
        else
            m_receive_mode = 0;

    }

   nstd_mat_muti_level_task_list dlg(m_receive_mode);
   m_units.Clear();
   m_cs_mode=false;

   combo_nstd_item_catalog->Enable(false);

   dlg.refresh_list();

   if(dlg.ShowModal() == wxID_OK)
    {
        m_units = dlg.m_units;
        m_index_id = dlg.m_index_id;
        m_batch_id = dlg.m_batch_id;
        m_use_status = dlg.m_level;
    }else return;

    show_gui_control();
    array_search_result.Clear();
    show_control(false);
    refresh_top_gui();
    refresh_low_gui();
    refresh_list();
}

void nstd_mat_apply::refresh_nstd_status()
{
    wxString s_action_id,s_wf_status;
    int i_status;
    if(m_mat_req)
    {
          i_status = get_instance_status(m_index_id+wxT("-")+m_batch_id,wf_str_materials,s_action_id,s_wf_status);

          tc_mat_status->SetValue(nstd_status_to_str(i_status));
          tc_mat_wf_status->SetValue(s_wf_status);

          if((m_use_status==0 || m_use_status ==2 || m_use_status == 3 || m_use_status == 4) && m_engineer.s_res_id == gr_para.login_user)
          {

              Button_Submit->Enable(true);
          }
          else Button_Submit->Enable(false);
          Button_workflow_mat->Enable(true);

     }else
     {
        tc_mat_status->Clear();
        tc_mat_wf_status->Clear();
        Button_Submit->Enable(false);
        Button_workflow_mat->Enable(false);

     }

    if(m_draw_req)
    {
          i_status = get_instance_status(m_index_id+wxT("-")+m_batch_id,wf_str_design,s_action_id,s_wf_status);
          tc_draw_status->SetValue(nstd_status_to_str(i_status));
          tc_draw_wf_status->SetValue(s_wf_status);
           if((m_use_status==0 || m_use_status ==2 || m_use_status == 3|| m_use_status == 4) && m_engineer.s_res_id == gr_para.login_user)
              Button_drawing->Enable(true);
           else Button_drawing->Enable(false);
          Button_workflow_draw->Enable(true);

    }else
    {
       tc_draw_status->Clear();
       tc_draw_wf_status->Clear();
       Button_drawing->Enable(false);
       Button_workflow_draw->Enable(false);
    }
}

void nstd_mat_apply::refresh_top_gui()
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
    wxString str_sql = wxT("SELECT contract_id,project_id,project_name,nonstd_catalog,nonstd_desc,remarks, mat_req_date,\
                           drawing_req_date,has_nonstd_mat,has_nonstd_draw,link_list,res_person,(select name from s_employee where employee_id = res_person) as res_person_name \
                           FROM v_nonstd_app_item WHERE index_id = '")+ m_index_id+wxT("';");

    wxPostgreSQLresult* _res;
     _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    if(_res->GetRowsNumber() ==0)
    {
        clear_content();
        _res->Clear();
    }
    else
    {
        tc_index_id->SetValue(m_index_id);
        wxString str = _res->GetVal(wxT("contract_id"))+wxT(" ")+_res->GetVal(wxT("project_name"));
        tc_project_name->SetValue(str);

        m_project_id = _res->GetVal(wxT("project_id"));
        tc_project_id->SetValue(m_project_id);

        str = _res->GetVal(wxT("nonstd_catalog"));
        combo_nstd_item_catalog->SetValue(str);

        str = _res->GetVal(wxT("nonstd_desc"));
        tc_nstd_reason->SetValue(str);


        str = _res->GetVal(wxT("remarks"));

        tc_remarks->SetValue(str);

        wxDateTime dt_temp = _res->GetDate(wxT("mat_req_date"));
        dp_mat_req->SetValue(dt_temp);

        dt_temp = _res->GetDate(wxT("drawing_req_date"));
        dp_draw_req->SetValue(dt_temp);

        if(m_search_mode && m_use_status == 1)
        {
            if(m_project_id == wxT("CS") || m_project_id == wxT("OTHER"))
            {
                m_use_status = 3;
            }
        }

        if(m_project_id == wxT("CS") || m_project_id == wxT("OTHER"))
            m_cs_mode=true;
        else
            m_cs_mode=false;
/*
        if(m_use_status == 0 || m_use_status == 3 || m_use_status ==4)
        {
            m_mat_req = _res->GetBool(wxT("has_nonstd_mat"));
            cb_nstd_mat->SetValue(m_mat_req);

            m_draw_req = _res->GetBool(wxT("has_nonstd_draw"));
            cb_nstd_drawing->SetValue(m_draw_req);
        }*/

        m_res_person.s_res_id = _res->GetVal(wxT("res_person"));
        m_res_person.s_res_name = _res->GetVal(wxT("res_person_name"));

        tc_res_person->SetValue( m_res_person.s_res_name);

        str = _res->GetVal(wxT("link_list"));
        if(!str.IsEmpty())
        {
            m_units = wxStringTokenize(str ,wxT(";"), wxTOKEN_DEFAULT  );

            dp_proj_au_date->SetValue(wxGetApp().get_prj_auth_date(m_units.Item(0)));

        }
        else
        {
            m_units.Clear();
            dp_proj_au_date->SetValue( wxDateTime::Today());
        }

        _res->Clear();

        if(m_use_status !=0 && m_use_status!=4 && m_use_status != 3)
        {
           tc_nstd_reason->Enable(false);
           combo_nstd_item_catalog->Enable(false);
        }
        else
        {
            tc_nstd_reason->Enable(true);
            if(m_use_status == 3 || m_use_status == 4)
               combo_nstd_item_catalog->Enable(false);
            else if(m_group!="G0004")
                combo_nstd_item_catalog->Enable(true);
        }

        Get_Array_Batch();

    }
}

void nstd_mat_apply::refresh_gui_check()
{
    wxString s_action_id, s_wf_status;

    if(m_receive_mode==1)
    {
        m_status =3;
    }else
        m_status = get_instance_status(m_index_id, wf_str_nonstd,s_action_id, s_wf_status);

    if(m_use_status ==0 || m_use_status==3 || m_use_status == 4)
    {
        if(m_res_person.s_res_id == gr_para.login_user&&m_group!="G0004")
        {
           enable_check(true);
           enable_grid(false);
        }else  if(m_group=="G0004")
        {
            if(m_engineer.s_res_id==gr_para.login_user||m_cs_mode)
            {
               enable_check(true);
               enable_grid(true);
            }else
            {
               enable_check(false);
               enable_grid(false);
            }

        }else
        {
            enable_check(false);
            enable_grid(false);
        }

    }
    else if((m_use_status==1 || m_use_status == 2)&& m_status == 3)
    {
        if(s_action_id == wxT("AT00000022")||s_action_id.IsEmpty())
        {
            if(m_engineer.s_res_id == gr_para.login_user && prj_str_to_status(tc_low_status->GetValue())==1)
                enable_check(true);
            else
                enable_check(false);

            if(m_use_status ==2 && m_engineer.s_res_id == gr_para.login_user)
            {

                enable_grid(true);
            }
            else
            {

                enable_grid(false);
            }



        }
        else
        {
            enable_check(false);
            enable_grid(false);

        }
    }else
    {
            enable_check(false);
            enable_grid(false);
    }


}

void nstd_mat_apply::refresh_low_gui()
{
    get_low_level_info();
    refresh_nstd_status();
    refresh_gui_check();
    Layout();
}

void nstd_mat_apply::refresh_list()
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

    if(m_array_batch_id.IsEmpty())
    {
        gd_mat_list->ClearGrid();
        tc_batch_id->Clear();
        m_batch_id.Empty();

 //       enable_grid(false); 配置物料清单与batch无关了。
    }

     wxString str_sql;
    if(m_use_status == 2)
    {
        str_sql = wxT("SELECT index_id,batch_id, sequence, plant, mat_name_cn, mat_id, qty, unit,mat_comment, link_list \
                           FROM l_nonstd_configure_mat_list WHERE index_id = '")+ m_index_id+wxT("' AND batch_id = '")+m_batch_id+wxT("' ORDER BY sequence ASC;");
    }else
    {
        str_sql = wxT("SELECT index_id,batch_id, sequence, plant, mat_name_cn, mat_id, qty, unit,mat_comment, link_list \
                           FROM l_nonstd_configure_mat_list WHERE index_id = '")+ m_index_id+wxT("' ORDER BY batch_id, sequence ASC;");
    }


     wxPostgreSQLresult* _res;
     _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    wxGridUpdateLocker noUpdates(gd_mat_list);
    gd_mat_list->ClearGrid();

//    gd_mat_list->BeginBatch();

    wxString str_table= wxT("l_nonstd_configure_mat_list");
    wxString str_key = wxT("index_id,batch_id,sequence,");
    gd_mat_list->SetTable(new nstdappTable(_res, str_table, str_mat_header,wxT("1111111111"), str_key), true);

    gd_mat_list->Fit();
//    gd_mat_list->EndBatch();
    gd_mat_list->SetColSize(0,0);
    gd_mat_list->SetColSize(1,0);
    gd_mat_list->SetColSize(2,0);
    gd_mat_list->SetColSize(3,0);
    Layout();
    _res->Clear();
}

/*
void nstd_mat_apply::get_nstd_mat_app_id(wxString str_mat_index)
{
   wxString str_sql = wxT("SELECT nstd_mat_app_id FROM l_nonstd_app_item_instance where index_mat_id ='")+str_mat_index+wxT("';");

    wxPostgreSQLresult* _res;
     _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int i_count = _res->GetRowsNumber();

    if(i_count == 0)
    {
        m_nstd_mat_app_id.Clear();
    }else
    {
       _res->MoveFirst();
       m_nstd_mat_app_id = _res->GetVal(wxT("nstd_mat_app_id"));
    }

    tc_nstd_mat_app_id->SetValue(m_nstd_mat_app_id);

    _res->Clear();
}*/

void nstd_mat_apply::Get_Array_Batch()
{
    m_array_batch_id.Clear();
    wxString str_sql = wxT("SELECT batch_id,res_engineer FROM l_nonstd_app_item_instance WHERE index_id = '")+ m_index_id+wxT("' ORDER BY batch_id ASC;");

    wxPostgreSQLresult* _res;
     _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int i_count = _res->GetRowsNumber();
    int i_pos = i_count -1;

    _res->MoveFirst();
    for(int i=0;i<i_count;i++)
    {
       wxString str = _res->GetVal(wxT("batch_id"));
       m_array_batch_id.Add(str);

       if(gr_para.login_user == _res->GetVal(wxT("res_engineer")))
           i_pos = i;

       _res->MoveNext();
    }

     _res->Clear();

    if(i_count == 0)
    {
        m_batch_id.Empty();
        m_array_batch_id.Clear();

    }else
    {
        m_batch_id=m_array_batch_id.Item(i_pos);
    }

     tc_batch_id->SetValue(m_batch_id);

}

void nstd_mat_apply::get_low_level_info()
{

    wxPostgreSQLresult* t_res;
    //wxLogMessage(m_group);
    wxString l_query = wxT("SELECT nstd_mat_app_id,res_engineer,instance_nstd_desc,instance_remarks,status, (select name from s_employee where employee_id = res_engineer) as res_engineer_name, has_nonstd_mat,has_nonstd_draw  FROM l_nonstd_app_item_instance \
                           where index_id = '")+m_index_id+wxT("' AND batch_id = '")+m_batch_id+wxT("';");

    t_res = wxGetApp().app_sql_select(l_query);
    if(t_res->Status()!= PGRES_TUPLES_OK)
    {
        t_res->Clear();
        return;
    }
    int i_count = t_res->GetRowsNumber();

    if(i_count == 0)
    {
        m_nstd_mat_app_id.Empty();
        tc_nstd_mat_app_id->Clear();
        tc_low_nstd_feedback->Clear();
        m_engineer.Clear();
        tc_low_nstd_reason->Clear();
        tc_low_status->Clear();
        tc_engineer->Clear();
        t_res->Clear();
        //2014.08.13更改bool读取位置。
        m_draw_req=false;
        m_mat_req=false;
        cb_nstd_drawing->SetValue(m_draw_req);
        cb_nstd_mat->SetValue(m_mat_req);
        return;
    }

    t_res->MoveFirst();

    wxString str;
    m_nstd_mat_app_id = t_res->GetVal(wxT("nstd_mat_app_id"));
    tc_nstd_mat_app_id->SetValue(m_nstd_mat_app_id);

    int i_status=0;
    if(m_use_status==1 || m_use_status == 2 || m_use_status==0)
    {
        m_engineer.s_res_id = t_res->GetVal(wxT("res_engineer"));
        m_engineer.s_res_name = t_res->GetVal(wxT("res_engineer_name"));
        tc_engineer->SetValue(m_engineer.s_res_name);

        i_status = t_res->GetInt(wxT("status"));
        str = prj_status_to_str(i_status);
        tc_low_status->SetValue(str);

        str = t_res->GetVal(wxT("instance_nstd_desc"));
        tc_low_nstd_reason->SetValue(str);

        str = t_res->GetVal(wxT("instance_remarks"));
        tc_low_nstd_feedback->SetValue(str);
    }

    m_mat_req = t_res->GetBool(wxT("has_nonstd_mat"));
    cb_nstd_mat->SetValue(m_mat_req);

    m_draw_req = t_res->GetBool(wxT("has_nonstd_draw"));
    cb_nstd_drawing->SetValue(m_draw_req);

    t_res->Clear();

    if((m_use_status == 1|| m_use_status==0 ) && m_res_person.s_res_id == gr_para.login_user )
    {
        if(i_status==0 || i_status == -2)
        {
              tc_low_nstd_reason->Enable(true);
              tc_low_nstd_feedback->Enable(false);
              Button_Engineer->Enable(true);
              Button_Return->Enable(false);
              Button_Low_Confirm->Enable(false);
        }else if(i_status == 2)
        {
            tc_low_nstd_reason->Enable(false);
            tc_low_nstd_feedback->Enable(false);
            Button_Engineer->Enable(false);
            Button_Return->Enable(true);
            Button_Low_Confirm->Enable(false);
        }else if(i_status == 5 || i_status ==1)
        {
            tc_low_nstd_reason->Enable(false);
            tc_low_nstd_feedback->Enable(false);
            Button_Engineer->Enable(false);
            Button_Return->Enable(false);
            Button_Low_Confirm->Enable(false);
        }
    }else if((m_use_status == 2 || m_use_status==0 ) && m_engineer.s_res_id == gr_para.login_user)
    {
        if(i_status == 1)
        {
            tc_low_nstd_reason->Enable(false);
            tc_low_nstd_feedback->Enable(true);
            Button_Low_Confirm->Enable(true);
            Button_Return->Enable(true);
            Button_Engineer->Enable(false);
        }else
        {
            tc_low_nstd_reason->Enable(false);
            tc_low_nstd_feedback->Enable(false);
            Button_Low_Confirm->Enable(false);
            Button_Return->Enable(false);
            Button_Engineer->Enable(false);
        }
    }else if(m_use_status==1 || m_use_status== 2 ||  m_use_status==0 )
    {
            tc_low_nstd_reason->Enable(false);
            tc_low_nstd_feedback->Enable(false);
            Button_Engineer->Enable(false);
            Button_Return->Enable(false);
            Button_Low_Confirm->Enable(false);
    }
}

bool nstd_mat_apply::update_mat_instance(wxString s_index,wxString s_index_mat, wxString s_batch_id, wxString s_alias)
{

    wxPostgreSQLresult* t_res;
    wxString l_query = wxT("SELECT * FROM l_nonstd_app_item_instance where index_mat_id = '")+s_index_mat+wxT("';");
    t_res = wxGetApp().app_sql_select(l_query);

    if(t_res->Status()!= PGRES_TUPLES_OK)
    {
        t_res->Clear();
        return false;
    }
    int i_count = t_res->GetRowsNumber();
    bool b_update;

    if(i_count ==0 )
       b_update = false;
    else b_update = true;

    t_res->Clear();


    if(!b_update)
      l_query = wxT("INSERT INTO l_nonstd_app_item_instance (index_id, index_mat_id,batch_id,nstd_mat_app_id, modify_date, modify_emp_id, create_date, create_emp_id)\
                  VALUES ('")+s_index +wxT("', '")+s_index_mat+wxT("','")+s_batch_id+wxT("','")+s_alias+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("');");

    else
    {
              l_query = wxT("UPDATE l_nonstd_app_item_instance SET index_id='")+s_index+wxT("',index_mat_id ='")+s_index_mat+wxT("', batch_id ='")+s_batch_id+wxT("',nstd_mat_app_id='")+s_alias+wxT("', modify_date = '")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id = '")+gr_para.login_user+wxT("' WHERE index_mat_id= '")+s_index_mat+wxT("';");
    }

    l_query.Replace(wxT("''"),wxT("NULL"));
 //   wxLogMessage(l_query);
    return wxGetApp().app_sql_update(l_query);

}

void nstd_mat_apply::OnButton_GenerateClick(wxCommandEvent& event)
{

    StaticText8->SetLabel(wxT("批次"));
    wxString str_group = wxGetApp().get_only_group();

   if(str_group != wxT("G0006") && str_group != wxT("G0007") && str_group != wxT("G0008") && str_group != wxT("G0003")&&str_group != wxT("G0004")&& str_group != wxT("G0005")&& str_group !=wxT("G0013")&& str_group !=wxT("G0018"))
    {
        wxLogMessage(_("您所属的组无此权限!"));
        return;
    }

    int i_choice;
    m_cs_mode=true;
    wxString str_project_id,s_nstd_catalog;
    if(m_use_status == 4)
    {
        str_project_id = wxT("MOD");
        s_nstd_catalog = _("MOD项目");

    }
    else
    {
        wxString _choice[2]=
        {
            _("售后申请"),
            _("工厂其他申请"),
        };
        wxSingleChoiceDialog cdlg(this, _("选择非标申请源?"),_("非标源"),2, _choice);

        m_use_status =3;
        if (cdlg.ShowModal() == wxID_CANCEL)
            return;

        i_choice= cdlg.GetSelection();
        s_nstd_catalog = cdlg.GetStringSelection();
        switch(i_choice)
        {
        case 0:
            str_project_id= wxT("CS");
            break;
        case 1:
            str_project_id = wxT("OTHER");
            break;
        }

    }

    m_cs_mode=true;

    combo_nstd_item_catalog->Enable(false);
    combo_nstd_item_catalog->SetValue(s_nstd_catalog);
    wxString str_nstd_id;
    str_nstd_id = wxGetApp().get_ser_id(wxT("l_nonstd_app_header"), wxT("nonstd_id"));

//cs header
    wxString str_sql = wxT("INSERT INTO l_nonstd_app_header(nonstd_id, project_id, status, mat_req_date, drawing_req_date, modify_date, modify_emp_id, create_date, create_emp_id, flow_mask) \
                  VALUES ('")+str_nstd_id+wxT("','")+str_project_id+wxT("','1','")+ DateToStrFormat(dp_mat_req->GetValue())+wxT(" 23:00:00")+wxT("','")+
                  DateToStrFormat(dp_draw_req->GetValue())+wxT(" 23:00:00")+wxT("','")+DateToAnsiStr(wxDateTime::Now())+
                  wxT("','")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','000');");

    str_sql.Replace(wxT("''"),wxT("NULL"));
    wxGetApp().app_sql_update(str_sql);
//cs item
    str_sql = wxT("INSERT INTO l_nonstd_app_item(index_id, nonstd_id, item_ser, has_nonstd_mat, has_nonstd_draw, modify_date, modify_emp_id, create_date, create_emp_id, remarks,res_person, nonstd_catalog) VALUES ('")+
              str_nstd_id+wxT("-1','")+str_nstd_id+wxT("','1','")+BoolToStr(m_mat_req)+wxT("','")+BoolToStr(m_draw_req)+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+
              gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+tc_remarks->GetValue()+wxT("','")+gr_para.login_user+wxT("','")+ s_nstd_catalog+wxT("');");
    str_sql.Replace(wxT("''"),wxT("NULL"));
    wxGetApp().app_sql_update(str_sql);


    m_index_id = str_nstd_id+wxT("-1");

    show_gui_control();

    array_search_result.Clear();
    show_control(false);
    refresh_top_gui();
    refresh_low_gui();

    //cb_nstd_drawing->Enable(true);
    //cb_nstd_mat->Enable(true);
}

void nstd_mat_apply::Ontc_remarksText(wxCommandEvent& event)
{
    if(m_index_id.IsEmpty())
        return;

    wxString str_sql = wxT("UPDATE l_nonstd_app_item SET modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("', remarks='")+tc_remarks->GetValue()+
                       wxT("' where index_id ='")+m_index_id+wxT("';");
    str_sql.Replace(wxT("''"),wxT("NULL"));
    wxGetApp().app_sql_update(str_sql);
}

void nstd_mat_apply::OnButton_SubmitClick(wxCommandEvent& event)
{
    wxString s_group = wxGetApp().get_only_group();
    if(s_group != wxT("G0006") && s_group != wxT("G0007") && s_group != wxT("G0008")&& s_group != wxT("G0003")&& s_group != wxT("G0004")&&s_group != wxT("G0005")&& s_group != wxT("G0013")&&s_group !=wxT("G0018"))
    {
        wxLogMessage(_("您所属的组无此权限!"));
        return;
    }

    if(m_index_id.IsEmpty())
    {
        wxLogMessage(_("请先选择非标任务!"));
        return;
    }

    if(!m_mat_req)
    {
        wxLogMessage(_("请先勾选物料维护需求!"));
        return;
    }

    wxString str_sql;
 //   wxPostgreSQLresult* _res;
    if(m_mat_req && nstd_str_to_status(tc_mat_status->GetValue())>=1)
    {
        wxLogMessage(_("物料申请已经提交，无法重新提交!"));
        return;
    }


    if(m_batch_id.IsEmpty())
    {
        wxLogMessage(_("请先添加批次，非标设计和非标物料申请必须按批次申请!"));
        return;
    }

    wxString s_action_id,s_wf_status;

    int i_status = get_instance_status(m_index_id, wf_str_nonstd, s_action_id,s_wf_status);

    if(s_action_id == wxT("AT00000023"))
    {
        wxLogMessage(_("非标申请已经回复，无法重新提交!"));
        return;
    }

    if(wxMessageBox(_("确认提交申请?"),_("确认"),wxYES_NO)==wxNO)
        return;



    v_wf_action * t_template=0;

    wf_operator * wf_active=0;

    v_wf_instance now_step, next_step;
    wxString str_operator, str_group;
   // wf_process * l_proc_act =0;

    wxLongLong mils_used, start_mils;

    if(m_mat_req)
    {

        int i_step;
        if(is_workflow_created(m_index_id+wxT("-")+m_batch_id, wf_str_materials,i_step))
        {
            wxLogMessage(_("工作流已经创建过了，退回的工作流，请到非标工作流界面操作"));
            return;

        }

        start_mils = wxGetLocalTimeMillis();
        t_template = get_template_action(wf_str_materials);
        wf_active = new wf_operator(m_index_id+wxT("-")+m_batch_id, wf_str_materials, t_template);
        wf_active->start_proc(wxEmptyString, true , false);

        i_status = nstd_action_to_status(wf_active->get_action_id());
        wf_active->update_instance_one2several(i_status);

        delete wf_active;

        mils_used = wxGetLocalTimeMillis() - start_mils;

        wxLogMessage(m_index_id+wxT("-")+m_batch_id+_("非标物料维护工作流创建完成 耗时:")+NumToStr(mils_used)+_("毫秒"));

        if(t_template)
            delete [] t_template; //事件处理事件统计，截止点。
    }

    refresh_nstd_status();
}

void nstd_mat_apply::OnButton_drawingClick(wxCommandEvent& event)
{
   wxString s_group = wxGetApp().get_only_group();
    if(s_group != wxT("G0006") && s_group != wxT("G0007") && s_group != wxT("G0008")&& s_group != wxT("G0003")&& s_group != wxT("G0004")&&s_group != wxT("G0005")&& s_group != wxT("G0013")&&s_group !=wxT("G0018"))
    {
        wxLogMessage(_("您所属的组无此权限!"));
        return;
    }

    if(m_index_id.IsEmpty())
    {
        wxLogMessage(_("请先选择非标任务!"));
        return;
    }

    if(!m_draw_req)
    {
        wxLogMessage(_("请先勾选非标设计需求!"));
        return;
    }


    wxString str_sql;
    wxPostgreSQLresult* _res;


    if(m_draw_req && nstd_str_to_status(tc_draw_status->GetValue())>=1)
    {
        wxLogMessage(_("非标设计申请已经提交，无法重新提交!"));
        return;
    }

    if(m_batch_id.IsEmpty())
    {
        wxLogMessage(_("请先添加批次，非标设计和非标物料申请必须按批次申请!"));
        return;
    }

    wxString s_action_id,s_wf_status;

    int i_status = get_instance_status(m_index_id, wf_str_nonstd, s_action_id,s_wf_status);

    if(s_action_id == wxT("AT00000023"))
    {
        wxLogMessage(_("非标申请已经回复，无法重新提交!"));
        return;
    }

    if(wxMessageBox(_("确认提交申请?"),_("确认"),wxYES_NO)==wxNO)
        return;



    v_wf_action * t_template=0;

    wf_operator * wf_active=0;

    v_wf_instance now_step, next_step;
    wxString str_operator, str_group;
    wf_process * l_proc_act =0;

    wxLongLong mils_used, start_mils;

    if(m_draw_req)
    {
        int i_step;
        if(is_workflow_created(m_index_id+wxT("-")+m_batch_id, wf_str_design,i_step))
        {
            wxLogMessage(_("工作流已经创建过了，退回的工作流，请到非标工作流界面操作"));
            return;

        }

        start_mils = wxGetLocalTimeMillis();
        t_template = get_template_action(wf_str_design);
        wf_active = new wf_operator(m_index_id+wxT("-")+m_batch_id, wf_str_design, t_template);
        wf_active->start_proc(wxEmptyString, true , false);

        l_proc_act = wf_active->get_current_process();

        l_proc_act->MoveFirst();
        now_step = l_proc_act->get_cur_instance_action();
        now_step.is_active = false;
        now_step.t_finish = wxDateTime::Now();

        if(now_step.s_action.s_operator_id.IsEmpty())
        {
             now_step.s_action.s_operator_id = gr_para.login_user;
        }

        if(now_step.s_action.s_group_id.IsEmpty() || now_step.s_action.s_group_id.Contains(wxT(";")))
        {
            now_step.s_action.s_group_id = wxGetApp().get_only_group();
        }


        wf_active->update_process_status(now_step, true);

        l_proc_act->MoveNext();
        next_step = l_proc_act->get_cur_instance_action();
        next_step.is_active = true;

        if(next_step.s_action.s_action_type == wxT("G") && !next_step.s_action.b_is_assigned)
        {
            str_group = now_step.s_action.s_group_id;
            str_operator = wxGetApp().get_leader(str_group);
        }

        if(next_step.s_action.s_action_type == wxT("P") && !next_step.s_action.b_is_assigned)
        {
            str_group = next_step.s_action.s_group_id;
            str_operator = next_step.s_action.s_operator_id;

        }

        if(next_step.s_action.s_action_type == wxT("P")&& next_step.s_action.b_is_assigned)
        {

            wxArrayString str_group_list;
            str_group = now_step.s_action.s_group_id;


            str_group_list.Add(str_group);
            wxArrayString  s_members = wxGetApp().get_member_in_group(str_group_list);

            wxSingleChoiceDialog cdlg(this, _("请选择操作人员:"),_("操作选择"),s_members);


            if(cdlg.ShowModal() == wxID_OK)
            {
                //                   b_first = false;
            }
            else
            {
                if(wf_active->delete_process())
                {
                    l_proc_act = 0;
                    delete wf_active;
                    if(t_template)
                        delete [] t_template;
                }
                return;
                //                 b_first = true;
            }

            str_operator = cdlg.GetStringSelection();

            int i_pos = str_operator.Find('-');

            str_operator = str_operator.Left(i_pos);


        }
        next_step.s_action.s_operator_id = str_operator;
        next_step.s_action.s_group_id = str_group;

        wf_active->update_process_status(next_step, true);
        l_proc_act->MoveToActive();


        i_status = nstd_action_to_status(wf_active->get_action_id());
        wf_active->update_instance_one2several(i_status);

        l_proc_act = 0;
        delete wf_active;

        mils_used = wxGetLocalTimeMillis() - start_mils;

        wxLogMessage(m_index_id+wxT("-")+m_batch_id+_("非标设计工作流创建完成 耗时:")+NumToStr(mils_used)+_("毫秒"));

        if(t_template)
            delete [] t_template; //事件处理事件统计，截止点。
    }

    refresh_nstd_status();
}

bool nstd_mat_apply::get_non_finish_low_task(wxString &s_tasks)
{
    wxPostgreSQLresult* t_res;
    wxString l_query = wxT("SELECT * FROM l_nonstd_app_item_instance where index_id = '")+m_index_id+wxT("' AND (status ='1' or status = '0');");
    t_res = wxGetApp().app_sql_select(l_query);

    if(t_res->Status()!= PGRES_TUPLES_OK)
    {
        t_res->Clear();
        return true;
    }
    int i_count = t_res->GetRowsNumber();

    wxString str;

    if(i_count ==0)
        return false;

    t_res->MoveFirst();
    for(int i=0;i<i_count;i++)
    {
        str = t_res->GetVal(wxT("index_mat_id"));
        s_tasks = s_tasks + str+wxT("\n");
        t_res->MoveNext();
    }

    t_res->Clear();
    return true;
}

wxArrayString nstd_mat_apply::get_wbs_of_cur_rel_nstd(wxString _flag)
{
    wxArrayString a_wbs;
    wxString s_wbs;
    int i_count;

    int i_pos = m_index_id.Find(wxT("-"));

    wxString s_nstd_id = m_index_id.Left(i_pos);

    wxString s_sql;

    if(_flag==wxT("E"))
    {
         s_sql = wxT(" select wbs_no from s_unit_info where e_nstd_id='")+s_nstd_id+wxT("' and (status=1 or status=3) ;");
    }else
    {
        s_sql = wxT(" select wbs_no from s_unit_info where m_nstd_id='")+s_nstd_id+wxT("' and (status=1 or status=3) ;");
    }

      wxPostgreSQLresult* _res ;

    _res = wxGetApp().app_sql_select(s_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return a_wbs;
    }

    i_count = _res->GetRowsNumber();

    for(int i=0;i<i_count;i++)
    {
        s_wbs = _res->GetVal(wxT("wbs_no"));
        a_wbs.Add(s_wbs);
        _res->MoveNext();
    }

    _res->Clear();

    return a_wbs;


}

void nstd_mat_apply::OnButton_PASS_NSTDClick(wxCommandEvent& event)
{
    wxString s_group = wxGetApp().get_only_group();
    if(s_group != wxT("G0006") && s_group != wxT("G0007") && s_group != wxT("G0008"))
    {
        wxLogMessage(_("您所属的组无此权限!"));
        return;
    }

    if(m_index_id.IsEmpty())
    {
        wxLogMessage(_("请先选择非标任务!"));
        return;
    }

    wxString s_flag, s_wbs;
    wxArrayString a_wbs;

/*
    if(tc_remarks->GetValue().IsEmpty())
    {
        wxLogMessage(_("请在备注内注明，以便配置工程师参考!"));
        tc_remarks->SetFocus();
        return;
    }

    if(m_mat_req && gd_mat_list->GetNumberRows() ==0)
    {
        wxLogMessage(_("请完成配置物料清单!"));
        return;
    }*/

    wxString str_tasks,str_remarks;
    int i_finish= get_combined_remarks(str_remarks,str_tasks);

    tc_remarks->SetValue(str_remarks);

    update_remarks(str_remarks);

    if(i_finish>0)
    {
       wxLogMessage(_("如下项次尚未完成，无法传递给配置:")+str_tasks);
       return;
    }else if(i_finish == -1)
    {
  //    if(wxMessageBox(_("（请确认确实没有非标物料和非标图纸）,确认继续?"),_("确认"),wxYES_NO)==wxNO)
        wxLogMessage(_("即使没有任何非标设计和非标物料申请，亲，请创建一个子任务给自己，备注原因，已方便统计任务。"));
        return;
    }

    wxString s_action_id, s_wf_status;
    int i_status;

    if(m_receive_mode!=1)
    {

        get_instance_status(m_index_id, wf_str_nonstd,s_action_id, s_wf_status);

        if(s_action_id == wxT("AT00000023"))
        {
            wxLogMessage(_("非标申请已经完成确认，无法重复提交!"));
            return;
        }
    }else
    {
        if(s_group==wxT("G0007"))
        {
            s_flag=wxT("E");
        }
        else if(s_group==wxT("G0006")||s_group==wxT("G0008"))
        {
            s_flag =wxT("M");
        }

        a_wbs = get_wbs_of_cur_rel_nstd(s_flag);

        if(a_wbs.IsEmpty())
            return;
    }

    if(wxMessageBox(_("确认提交完成确认，确认后将无法再生成批次和提交非标设计和非标物料?"),_("确认"),wxYES_NO)==wxNO)
        return;


    v_wf_action * t_template=0;

    wf_operator * wf_active=0;
    wf_operator_ex * wf_new_active=0;

    v_wf_instance now_step, next_step;
    wxString str_operator, str_group;
    wf_process * l_proc_act =0;
    wxLongLong mils_used, start_mils;



    if(m_receive_mode!=1)
    {
        start_mils = wxGetLocalTimeMillis();//事件处理事件统计，起始点。
        t_template = get_template_action(wf_str_nonstd);

        wf_active = new wf_operator(m_index_id, wf_str_nonstd, t_template);

        l_proc_act = wf_active->get_current_process();
        /*
        l_proc_act->MoveFirst();
        now_step = l_proc_act->get_cur_instance_action();
        str_group = now_step.s_action.s_group_id;
        str_operator = now_step.s_action.s_operator_id;*/
        l_proc_act->MoveToActive();

// 增加非标配置物料清单的审核后， 如上注释，增加 内容：
        now_step = l_proc_act->get_cur_instance_action();
        str_group = now_step.s_action.s_group_id;

        str_operator = wxGetApp().get_leader(str_group);

        //增加非标配置物料清单的校对后， 如上注释，增加 内容：
        wf_active->Pass_proc(str_operator, str_group,wxEmptyString, false);

        if(!ck_jump_proc())
        {
            l_proc_act->MoveFirst();
            now_step = l_proc_act->get_cur_instance_action();
            str_group = now_step.s_action.s_group_id;
            str_operator = now_step.s_action.s_operator_id;

            l_proc_act->MoveToActive();

            wf_active->Pass_proc(str_operator, str_group,wxEmptyString, false);
        }

        l_proc_act =0;
        i_status = nstd_action_to_status(wf_active->get_action_id());


        wf_active->update_instance_one2several(i_status);


        delete wf_active;

        mils_used = wxGetLocalTimeMillis() - start_mils;

        wxLogMessage(m_index_id+_("非标申请任务完成!  耗时:")+NumToStr(mils_used)+_("毫秒")); //事件处理事件统计，截止点。

    }else
    {
        if(s_flag=="M")
        {

            if(!check_prj_info_attach_finished(a_wbs))
            {
                return;
            }
        }

        t_template = get_template_action(wf_str_new_config);

        int i_wbs = a_wbs.GetCount();
        int i_operator;
        bool b_update=false;

        for(int i=0;i<i_wbs;i++)
        {
            start_mils = wxGetLocalTimeMillis();//事件处理事件统计，起始点。
            s_wbs = a_wbs.Item(i);
            wf_new_active = new wf_operator_ex(s_wbs, wf_str_new_config, t_template, s_flag);

            l_proc_act = wf_new_active->get_current_process();

            l_proc_act->MoveToActive();
            now_step = l_proc_act->get_cur_instance_action();

            if (now_step.s_action.s_operator_id!=gr_para.login_user)
            {
                wxLogMessage("当前步骤非本人所有，无法继续!");
                continue;
            }

            if (!now_step.is_active)
                continue;

            str_group  =  now_step.s_action.s_group_id;

            str_operator = wxGetApp().get_leader(str_group);
            if(wf_new_active->Pass_proc(str_operator, str_group, wxEmptyString, false,s_flag))
                b_update = true;
            l_proc_act = 0;
            delete wf_new_active;

            mils_used = wxGetLocalTimeMillis() - start_mils;
            if(s_flag==wxT("E"))
                wxLogMessage(s_wbs+_("整梯电气BOM完成!  耗时:")+NumToStr(mils_used)+_("毫秒"));
            else
                wxLogMessage(s_wbs+_("整梯机械BOM完成!  耗时:")+NumToStr(mils_used)+_("毫秒"));
        }

        if(b_update)
        {
            int i_pos = m_index_id.Find(wxT("-"));
            wxString s_nstd_id=m_index_id.Left(i_pos);

            wxGetApp().update_new_nstd_config(s_nstd_id, 10);
        }


    }

    if(t_template)
        delete [] t_template;

    tc_remarks->Enable(false);
    Button_PASS_NSTD->Enable(false);
    tc_low_nstd_feedback->Enable(false);
    tc_low_nstd_reason->Enable(false);
    Button_Return->Enable(false);
    enable_grid(false);

}

bool nstd_mat_apply::check_prj_info_attach_finished(wxArrayString& a_wbs)
{
    wxString str_sql = wxT("select wbs_no, (select is_basic_finish from s_unit_info_attach where wbs_no = v_unit_info.wbs_no) as \
                           is_finished from v_unit_info where ");

    int i_count = a_wbs.GetCount();

    bool b_pass = true;

    wxArrayString a_no_finish_wbs;

    for(int i=0;i<i_count;i++)
    {
       if(i_count ==1)
         str_sql = str_sql +wxT(" wbs_no='")+a_wbs.Item(i)+wxT("' ");
       else
       {
           if(i==0)
            str_sql = str_sql+wxT(" wbs_no in ('")+a_wbs.Item(i)+wxT("', ");
           else if(i== i_count -1)
             str_sql  = str_sql + wxT("'")+a_wbs.Item(i)+wxT("') ");
           else
            str_sql = str_sql + wxT(" '")+a_wbs.Item(i)+wxT("', ");
       }
    }

    str_sql = str_sql+ wxT(" and elevator_type in ('TE-GL1','TE-GL','TE-Evolution1','RF1','RF2','TE-HP61','TE-Synergy','RF3') order by wbs_no ASC;");

   // wxMessageBox(str_sql ,_(""));
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);


    if(_res->Status()!= PGRES_TUPLES_OK)
    {
         _res->Clear();
        return false;
    }

    int i_rows = _res->GetRowsNumber();
    wxString str;
    bool b_finish;

    bool b_return = true;

    for(int j=0;j<i_rows;j++)
    {
         str = _res->GetVal(wxT("wbs_no"));
         a_no_finish_wbs.Add(str);

         b_finish = _res->GetBool(wxT("is_finished"));

         if(!b_finish)
            b_return =false;

         _res->MoveNext();

    }
    _res->Clear();

    if(!b_return)
    {
         wxLogMessage(_("任务中有相关项目基本参数未填写完整，请在弹出窗口中填写完整后，再继续!"));
        unit_info_attach_dlg dlg;
        dlg.Set_Editable(true);
        dlg.refresh_control();
        dlg.array_wbs = a_no_finish_wbs;

        dlg.refresh_list();

        if(dlg.ShowModal()==wxID_CANCEL)
            return false;
    }

    return true;
}


bool nstd_mat_apply::ck_jump_proc()
{

     wxString str_sql = wxT("select * from l_nonstd_app_item_instance where index_id = '")+m_index_id+wxT("' order by batch_id ASC;");

     wxPostgreSQLresult * _res= wxGetApp().app_sql_select(str_sql);

     if(_res->Status()!= PGRES_TUPLES_OK)
     {
        return true;
     }

     int i_count = _res->GetRowsNumber();

     if(i_count <=0)
     {
         _res->Clear();

         wxLogMessage(_("尚未分拆任何子任务，无法向后传递!"));

         return true;
     }

     _res->MoveFirst();

     bool b_mat, b_draw;
     for(int i=0;i<i_count;i++)
     {
         b_mat = _res->GetBool(wxT("has_nonstd_mat"));
         b_draw = _res->GetBool(wxT("has_nonstd_draw"));

         if(b_mat || b_draw)
         {

             _res->Clear();

             return false;
         }

         _res->MoveNext();
     }

     _res->Clear();

     return true;

}

void nstd_mat_apply::OnButton_SearchClick(wxCommandEvent& event)
{
    array_search_result.Clear();

    m_search_mode = true;
    nstd_app_search dlg;

    wxArrayString array_choice;

    wxString str;

    str = _("非标物料申请单号");
    array_choice.Add(str);

    str = _("项目WBS号");
    array_choice.Add(str);

    str = _("项目名称");
    array_choice.Add(str);

    str = _("二级分任务号");
    array_choice.Add(str);

    str= _("非标物料申请编号");
    array_choice.Add(str);

    str=_("合同号");
    array_choice.Add(str);

    str = _("本人处理的一级任务");
    array_choice.Add(str);

    str = _("本人处理的二级任务");
    array_choice.Add(str);

    dlg.set_search_case(array_choice);

    int i_choice;
    wxString str_search;
    if(dlg.ShowModal() == wxID_OK)
    {
       i_choice = dlg.i_choice;
       str_search = dlg.str_search;
    }else return;

    wxString str_sql;

    switch(i_choice)
    {
    case  0:
        str_sql = wxT("SELECT index_id FROM l_nonstd_app_item where index_id like '%")+str_search.Upper()+wxT("%'  order by index_id ASC;");
        break;
    case 1:
        str_sql = wxT("SELECT index_id FROM v_nonstd_app_item where project_id like '%")+str_search.Upper()+wxT("%'  order by index_id ASC;");
        break;
    case 2:
        str_sql = wxT("SELECT index_id FROM v_nonstd_app_item where project_name like '%")+str_search+wxT("%'   order by index_id ASC;");
        break;
    case 3:
        str_sql = wxT("select index_id from l_nonstd_app_item_instance where index_mat_id like '%")+str_search.Upper()+wxT("%'  order by index_id ASC;");
        break;
    case 4:
        str_sql = wxT("select index_id from l_nonstd_app_item_instance where nstd_mat_app_id like '%")+str_search.Upper()+wxT("%' order by index_id ASC;");
        break;
    case 5:
        str_sql = wxT("select index_id from v_nonstd_app_item_instance where contract_id = '")+str_search+wxT("' order by index_id ASC;");
        break;

    case 6:
        str_sql = wxT("select index_id from v_nonstd_app_item_instance where res_person='")+gr_para.login_user+wxT("' order by index_id ASC;");
        break;

    case 7:
        str_sql = wxT("select index_id from v_nonstd_app_item_instance where res_engineer='")+gr_para.login_user+wxT("' order by index_id ASC;");
        break;
    default:
        break;
    }

    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int i_count = _res->GetRowsNumber();

    if(i_count ==0)
    {
        _res->Clear();
        return;
    }

    _res->MoveFirst();
    for(int i=0;i<i_count;i++)
    {
        array_search_result.Add(_res->GetVal(wxT("index_id")));
        _res->MoveNext();
    }

    _res->Clear();

    wxString str_step = wxT("1/")+ NumToStr(i_count);

    tc_qty->SetValue(str_step);


   if(m_group == wxT("G0003")||m_group == wxT("G0004")|| m_group == wxT("G0005")||m_group==wxT("G0018"))
    {
        if(m_group==wxT("G0004"))
            StaticText8->SetLabel(wxT("分任务号"));
        else
            StaticText8->SetLabel(wxT("批次"));
        m_use_status = 0;
    }else if(m_group == wxT("G0006")|| m_group == wxT("G0007") ||m_group == wxT("G0008"))
    {
        StaticText8->SetLabel(wxT("分任务号"));
        m_use_status = 1;
    }else if(m_group == wxT("G0013"))
    {
        StaticText8->SetLabel(wxT("批次"));
        m_use_status = 4;
    }

    if(i_choice == 3 && m_use_status ==1)
        m_use_status = 2;

     m_index_id = array_search_result.Item(0);

     refresh_top_gui();


    if(i_count >1)
    {
       show_control(true);
    }else show_control(false);


    refresh_low_gui();
    refresh_list();

    show_gui_control();
    m_search_mode = false;
    m_cs_mode=false;
}

void nstd_mat_apply::OnButton_PrintClick(wxCommandEvent& event)
{
}

void nstd_mat_apply::OnButton_RelClick(wxCommandEvent& event)
{

    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(m_units.IsEmpty())
    {
        wxLogMessage(_("无相关项目units信息!"));
        return;
    }

    nstd_task_author dlg;

    dlg.m_units = m_units;
    dlg.refresh_list();
    dlg.ShowModal();

}

void nstd_mat_apply::OnButton_Same_headerClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(m_index_id.IsEmpty())
    {
        wxLogMessage(_("请先选择相应的非标物料申请!"));
        return;
    }

    int i_pos = m_index_id.Find(wxT("-"));

    wxString s_nstd_app_id = m_index_id.Left(i_pos);
    wxString str_sql;

    nstd_mat_task_list dlg;
    dlg.init_nstd_item_header();
    str_sql = wxT("SELECT index_id, concat(contract_id,' ', project_name,'-',project_id) as project_name, mat_req_date, drawing_req_date, \
                          nonstd_catalog, nonstd_desc, nonstd_value, (select name from s_employee where employee_id = res_person) as engineering,\
                          link_list from v_nonstd_app_item where  nonstd_id='")+s_nstd_app_id+wxT("' order by index_id ASC;");
   dlg.Set_Query(str_sql);
   dlg.refresh_list();
   dlg.show_control(true);
   dlg.m_search_mode = true;
   dlg.ShowModal();

}

void nstd_mat_apply::OnButton_PreviousClick(wxCommandEvent& event)
{

    int i_pos = array_search_result.Index(m_index_id);
    if(i_pos == 0 || i_pos == wxNOT_FOUND || array_search_result.IsEmpty())
        return;

    int i_count = array_search_result.GetCount();

    i_pos--;
    m_index_id = array_search_result.Item(i_pos);
    wxString str=NumToStr(i_pos+1)+wxT("/")+NumToStr(i_count);

    tc_qty->SetValue(str);

/*
    if(m_group == wxT("G0003")||m_group == wxT("G0004")|| m_group == wxT("G0005"))
    {

        StaticText8->SetLabel(wxT("批次"));
        m_use_status = 0;
    }else if(m_group == wxT("G0006")|| m_group == wxT("G0007") ||m_group == wxT("G0008"))
    {
        StaticText8->SetLabel(wxT("分任务号"));
        m_use_status = 1;
    }else if(m_group == wxT("G0013"))
    {
        StaticText8->SetLabel(wxT("批次"));
        m_use_status = 4;
    }*/

    m_search_mode = true;

    if(m_use_status == 3)
        m_use_status=1;
  //  m_use_status =0;
    refresh_top_gui();
    refresh_low_gui();
    refresh_list();

    show_gui_control();
    m_search_mode = false;

}

void nstd_mat_apply::OnButton_NextClick(wxCommandEvent& event)
{
    int i_pos = array_search_result.Index(m_index_id);
    int i_count = array_search_result.GetCount();
    if(i_pos == i_count-1 || i_pos == wxNOT_FOUND || array_search_result.IsEmpty())
        return;

    i_pos++;
    m_index_id = array_search_result.Item(i_pos);
    m_search_mode= true;

    wxString str=NumToStr(i_pos+1)+wxT("/")+NumToStr(i_count);

    tc_qty->SetValue(str);
/*
    if(m_group == wxT("G0003")||m_group == wxT("G0004")|| m_group == wxT("G0005"))
    {

        StaticText8->SetLabel(wxT("批次"));
        m_use_status = 0;
    }else if(m_group == wxT("G0006")|| m_group == wxT("G0007") ||m_group == wxT("G0008"))
    {
        StaticText8->SetLabel(wxT("分任务号"));
        m_use_status = 1;
    }else if(m_group == wxT("G0013"))
    {
        StaticText8->SetLabel(wxT("批次"));
        m_use_status = 4;
    }*/

    m_search_mode = true;

    if(m_use_status == 3)
        m_use_status=1;

 //   m_use_status =0;
    refresh_top_gui();
    refresh_low_gui();
    refresh_list();

    show_gui_control();
    m_search_mode = false;
}

void nstd_mat_apply::OnButton_BeginClick(wxCommandEvent& event)
{
    if(array_search_result.IsEmpty())
        return;

    m_index_id = array_search_result.Item(0);
    m_search_mode= true;

    wxString str=wxT("1/")+NumToStr(array_search_result.GetCount());

    tc_qty->SetValue(str);

/*
   if(m_group == wxT("G0003")||m_group == wxT("G0004")|| m_group == wxT("G0005"))
    {

        StaticText8->SetLabel(wxT("批次"));
        m_use_status = 0;
    }else if(m_group == wxT("G0006")|| m_group == wxT("G0007") ||m_group == wxT("G0008"))
    {
        StaticText8->SetLabel(wxT("分任务号"));
        m_use_status = 1;
    }else if(m_group == wxT("G0013"))
    {
        StaticText8->SetLabel(wxT("批次"));
        m_use_status = 4;
    }*/

 //   m_use_status =0;
    if(m_use_status == 3)
        m_use_status=1;
    refresh_top_gui();
    refresh_low_gui();
    refresh_list();

    show_gui_control();
    m_search_mode = false;

}

void nstd_mat_apply::OnButton_EndClick(wxCommandEvent& event)
{
    if(array_search_result.IsEmpty())
        return;

    int i_count = array_search_result.GetCount();

    m_index_id = array_search_result.Item(i_count-1);
    m_search_mode= true;

    wxString str=NumToStr(i_count)+wxT("/")+NumToStr(i_count);

    tc_qty->SetValue(str);

/*
    if(m_group == wxT("G0003")||m_group == wxT("G0004")|| m_group == wxT("G0005"))
    {

        StaticText8->SetLabel(wxT("批次"));
        m_use_status = 0;
    }else if(m_group == wxT("G0006")|| m_group == wxT("G0007") ||m_group == wxT("G0008"))
    {
        StaticText8->SetLabel(wxT("分任务号"));
        m_use_status = 1;
    }else if(m_group == wxT("G0013"))
    {
        StaticText8->SetLabel(wxT("批次"));
        m_use_status = 4;
    }*/

    if(m_use_status == 3)
        m_use_status=1;
  //  m_use_status =0;
    refresh_top_gui();
    refresh_low_gui();
    refresh_list();

    show_gui_control();
    m_search_mode = false;
}

void nstd_mat_apply::OnButton_AddClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    wxString str_add = tc_row->GetValue();


    if(!str_add.IsNumber())
    {
        if(wxMessageBox(_("请输入数字，无法增加行！"),_("错误"),wxOK)==wxOK)
        {
           wxLogMessage(_("错误:请输入数字，无法增加行!"));
           tc_row->SetValue(wxT("1"));
        }
        return;
    }

    int i_add = wxAtoi(str_add);

    if(i_add<=0)
    {
        if(wxMessageBox(_("请输入大于0的整数，无法增加行！"),_("错误"),wxOK)==wxOK)
        {
           wxLogMessage(_("错误:请输入大于0的整数，无法增加行!"));
           tc_row->SetValue(wxT("1"));
        }
        return;
    }

    int i_row = gd_mat_list->GetNumberRows();

    int i_count = m_units.GetCount();
    wxString str_units;

    for(int j=0;j<i_count;j++)
    {
        str_units = str_units+m_units.Item(j)+wxT(";");
    }

    configure_mat_list_editor dlg;
    for(int i=0; i<i_add;i++)
    {
        dlg.tc_index_id->SetValue(m_index_id);
        dlg.tc_batch_id->SetValue(m_batch_id);
        wxString str;
         int i_seq;
        if(i_row ==0)
            str = wxT("0001");
        else
        {
            i_seq= atoi(gd_mat_list->GetCellValue(i_row-1,2).ToAscii())+1;
            str = zero_begin(i_seq,4);
        }

        dlg.tc_sequence->SetValue(str);

        dlg.init_checklistbox(m_units);

        if(dlg.ShowModal()==wxID_OK)
        {
            nstdappTable * table = gd_mat_list->GetTable();
            table->AppendRows(1);


            cacheLine *line = table->GetLine(i_row);
            if (!line->cols)
                line->cols = new wxString[10];

            table->SetLastRow(i_row);
            line->cols[0] = dlg.m_index_id;
            line->cols[1] = dlg.m_batch_id;
            line->cols[2] = dlg.m_sequence;
            line->cols[3] = gr_para.plant;
            line->cols[4] = dlg.m_mat_desc;
            line->cols[5] = dlg.m_mat_id;
            line->cols[6] = dlg.m_qty;
            line->cols[7] = dlg.m_unit;
            line->cols[8] = dlg.m_comments;
            line->cols[9] = dlg.m_str_units;


            table->StoreLine();

            i_row++;
        }else
           continue;
    }

    gd_mat_list->EnableEditing(true);
}

void nstd_mat_apply::OnButton_DelClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    wxArrayInt array_sel_line = gd_mat_list->GetSelectedRows();
    if(array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }

    if(wxMessageBox(_("确认永久删除选中行?"),_("删除"),wxYES_NO) == wxNO)
        return;

    nstdappTable * table = gd_mat_list->GetTable();
    if(table)
    {
        int i_count = array_sel_line.GetCount();
        for(int i=0;i<i_count;i++)
        {
            table->DeleteRows(array_sel_line.Item(0),1);
            array_sel_line.Clear();
            array_sel_line = gd_mat_list->GetSelectedRows();
        }
    }
}

void nstd_mat_apply::OnButton_Add_BatchClick(wxCommandEvent& event)
{
    wxString str_group = wxGetApp().get_only_group();
    if(str_group != wxT("G0006") && str_group != wxT("G0007") && str_group != wxT("G0008") && str_group != wxT("G0003")&&str_group != wxT("G0004")&& str_group != wxT("G0005") &&str_group != wxT("G0013")&&str_group !=wxT("G0018"))
    {
        wxLogMessage(_("您所属的组无此权限!"));
        return;
    }

    if(m_index_id.IsEmpty())
    {
        wxLogMessage(_("请先选择非标任务!"));
        return;
    }

    wxString s_action_id,s_wf_status;

  //  int i_status = get_instance_status(m_index_id, wf_str_nonstd, s_action_id,s_wf_status);

    if(s_action_id == wxT("AT00000023"))
    {
        wxLogMessage(_("非标申请已经回复，无法申请新的批次!"));
        return;
    }


    if(wxMessageBox(_("确认新增批次?"),_("提示"),wxYES_NO)==wxNO)
       return;


    add_batch();
    refresh_low_gui();
    refresh_nstd_status();
}

void nstd_mat_apply::add_batch( )
{
    if(m_use_status!=2)
    {
        int i_count = m_array_batch_id.GetCount();
        if(i_count == 0)
        {
            m_batch_id = wxT("A");
        }
        else
        {
            m_batch_id = m_array_batch_id.Item(i_count-1);
            m_batch_id = get_english_char(m_batch_id, 1);
        }

        m_array_batch_id.Add(m_batch_id);

        tc_batch_id->SetValue(m_batch_id);
        if(m_use_status == 1)
        {
            tc_low_nstd_reason->SetValue(tc_nstd_reason->GetValue());

    /*        wxString str = tc_low_nstd_reason->GetValue();

            if(str.Trim().IsEmpty())
                return;

            wxString str_sql = wxT("UPDATE l_nonstd_app_item_instance SET modify_emp_id ='")+gr_para.login_user+wxT("',modify_date ='")+DateToAnsiStr(wxDateTime::Now())+wxT("', instance_nstd_desc='")+
                             str+wxT("' where index_id = '")+m_index_id+wxT("' AND batch_id = '")+m_batch_id+wxT("';");
            wxGetApp().app_sql_update(str_sql);*/
        }

    }

    spb_batch_id->Enable(true);

    m_nstd_mat_app_id.Empty();
    tc_nstd_mat_app_id->Clear();

    if(m_group!=wxT("G0004"))
        add_nstd_mat_id();
    else
        add_nstd_mat_id(false);

}

void nstd_mat_apply::add_nstd_mat_id(bool b_check)
{
    if(!m_nstd_mat_app_id.IsEmpty())
        return;

    if(m_use_status !=1&&b_check)
    {
        m_nstd_mat_app_id = wxGetApp().get_ser_id(wxT("l_nonstd_app_item_instance"),wxT("nstd_mat_app_id"));

        tc_nstd_mat_app_id->SetValue(m_nstd_mat_app_id);
    }

    update_mat_instance(m_index_id, m_index_id+wxT("-")+m_batch_id, m_batch_id, m_nstd_mat_app_id);

}

void nstd_mat_apply::init_list_header()
{
    gd_mat_list->CreateGrid(0,10);
    gd_mat_list->SetRowLabelSize(20);
    gd_mat_list->SetColLabelValue(0,_("index_id"));
    gd_mat_list->SetColSize(0,0);

    gd_mat_list->SetColLabelValue(1,_("batch_id"));
    gd_mat_list->SetColSize(1,0);

    gd_mat_list->SetColLabelValue(2,_("序号"));
    gd_mat_list->SetColSize(2,0);

    gd_mat_list->SetColLabelValue(3,_("工厂"));
    gd_mat_list->SetColSize(3,0);

    gd_mat_list->SetColLabelValue(4,_("物料\n名称"));
    gd_mat_list->SetColSize(4,150);

    gd_mat_list->SetColLabelValue(5,_("物料号"));
    gd_mat_list->SetColSize(5,100);


    gd_mat_list->SetColLabelValue(6,_("数量"));
    gd_mat_list->SetColSize(6,50);

    gd_mat_list->SetColLabelValue(7,_("单位"));
    gd_mat_list->SetColSize(7,80);

    gd_mat_list->SetColLabelValue(8,_("BOM备注"));
    gd_mat_list->SetColSize(8,200);

    gd_mat_list->SetColLabelValue(9,_("关联梯"));
    gd_mat_list->SetColSize(9,100);


    for(int i=0; i<10; i++)
    {
        str_mat_header = str_mat_header+gd_mat_list->GetColLabelValue(i)+wxT(";");
    }
}

void nstd_mat_apply::show_control(bool b_show)
{
    tc_qty->Show(b_show);
    Button_Begin->Show(b_show);
    Button_Next->Show(b_show);
    Button_Previous->Show(b_show);
    Button_End->Show(b_show);
}

void nstd_mat_apply::enable_grid(bool b_sure)
{
    tc_row->Enable(b_sure);
    Button_Import_Mat->Enable(b_sure);
    Button_Add->Enable(b_sure);
    Button_Del->Enable(b_sure);
    gd_mat_list->EnableEditing(b_sure);
    button_change_rel->Enable(b_sure);
}


void nstd_mat_apply::enable_check(bool b_sure)
{

    cb_nstd_drawing->Enable(b_sure);
    cb_nstd_mat->Enable(b_sure);

    if(m_mat_req&&b_sure)
       Button_Submit->Enable(true);
    else
       Button_Submit->Enable(false);

    if(m_draw_req&&b_sure)
       Button_drawing->Enable(true);
    else
        Button_drawing->Enable(false);
}

void nstd_mat_apply::Onspb_batch_idChangeUp(wxSpinEvent& event)
{
    int i_pos = m_array_batch_id.Index(m_batch_id);
    int i_count = m_array_batch_id.GetCount();
    if(i_pos == i_count-1 || i_pos == wxNOT_FOUND || m_array_batch_id.IsEmpty())
        return;


    i_pos++;
    m_batch_id = m_array_batch_id.Item(i_pos);

    tc_batch_id->SetValue(m_batch_id);
    refresh_low_gui();
    refresh_list();
}

void nstd_mat_apply::Onspb_batch_idChangeDown(wxSpinEvent& event)
{
    int i_pos = m_array_batch_id.Index(m_batch_id);
    if(i_pos == 0 || i_pos == wxNOT_FOUND || m_array_batch_id.IsEmpty())
        return;

   // int i_count = m_array_batch_id.GetCount();

    i_pos--;
    m_batch_id = m_array_batch_id.Item(i_pos);

    tc_batch_id->SetValue(m_batch_id);
    refresh_low_gui();
    refresh_list();

}

void nstd_mat_apply::Oncb_nstd_matClick(wxCommandEvent& event)
{


    if(m_index_id.IsEmpty())
        return;

    if(!event.IsChecked())
    {
        if(nstd_str_to_status(tc_mat_status->GetValue())>0)
        {
             wxLogMessage(_("非标物料维护已经提交，无法修改!"));
             cb_nstd_mat->SetValue(true);
             m_mat_req = true;
             return;
        }

        if(nstd_str_to_status(tc_mat_status->GetValue())==0)
        {
            if(wxMessageBox(_("此操作会删除已经提交的物料维护流程数据，确认继续？"),_("提示"),wxYES_NO)==wxYES)
            {
                if(delete_all_process(m_index_id+wxT("-")+m_batch_id, wf_str_materials))
                    delete_status(m_index_id+wxT("-")+m_batch_id, wf_str_materials);

                refresh_nstd_status();

            }
            else
            {
                cb_nstd_drawing->SetValue(true);
                m_draw_req = true;
                return;
            }
        }

    }

    m_mat_req = cb_nstd_mat->IsChecked();

    if(m_mat_req && m_batch_id.IsEmpty())
    {
        add_batch();
    }

    add_nstd_mat_id();

    if(m_mat_req)
    {
        Button_workflow_mat->Enable(true);
        Button_Submit->Enable(true);
    }
    else
    {
        Button_Submit->Enable(false);
        Button_workflow_mat->Enable(false);
    }

    wxString str_sql ;

  /*  if(m_use_status ==0 || m_use_status ==3 || m_use_status == 4)
    {
       str_sql= wxT("UPDATE l_nonstd_app_item SET has_nonstd_mat='")+BoolToStr(m_mat_req)+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("' where index_id ='")+m_index_id+wxT("';");
    }else if(m_use_status == 1 || m_use_status ==2)
    {*/
       str_sql= wxT("UPDATE l_nonstd_app_item_instance SET has_nonstd_mat='")+BoolToStr(m_mat_req)+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("' where index_id ='")+m_index_id+wxT("' AND batch_id='")+m_batch_id+wxT("';");
 //   }

    wxGetApp().app_sql_update(str_sql);

}

void nstd_mat_apply::Oncb_nstd_drawingClick(wxCommandEvent& event)
{
    if(m_index_id.IsEmpty())
        return;

   if(!event.IsChecked())
    {
        if(nstd_str_to_status(tc_draw_status->GetValue())>0)
        {
             wxLogMessage(_("非标物料维护已经提交，需后续工程师退回方可操作!"));
             cb_nstd_drawing->SetValue(true);
             m_draw_req = true;
             return;
        }

        if(nstd_str_to_status(tc_draw_status->GetValue())==0)
        {
            if(wxMessageBox(_("此操作会删除已经提交的非标设计流程数据，确认继续？"),_("提示"),wxYES_NO)==wxYES)
            {
                if(delete_all_process(m_index_id+wxT("-")+m_batch_id, wf_str_design))
                    delete_status(m_index_id+wxT("-")+m_batch_id, wf_str_design);

                refresh_nstd_status();

            }
            else
            {
                cb_nstd_drawing->SetValue(true);
                m_draw_req = true;
                return;
            }
        }

    }

    m_draw_req = cb_nstd_drawing->IsChecked();

    if(m_draw_req && m_batch_id.IsEmpty())
    {
        add_batch();
    }

    if(m_nstd_mat_app_id.IsEmpty())
        add_nstd_mat_id();

    if(m_draw_req)
    {
        Button_drawing->Enable(true);
        Button_workflow_draw->Enable(true);
    }
    else
    {
        Button_drawing->Enable(false);
        Button_workflow_draw->Enable(false);

    }

    wxString str_sql;
/*    if(m_use_status ==0 || m_use_status ==3 || m_use_status == 4)
    {
        str_sql = wxT("UPDATE l_nonstd_app_item SET  has_nonstd_draw='")+BoolToStr(m_draw_req)+
                       wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("' where index_id ='")+m_index_id+wxT("';");
    }else if(m_use_status == 1 || m_use_status ==2)
    {*/
       str_sql= wxT("UPDATE l_nonstd_app_item_instance SET has_nonstd_draw='")+BoolToStr(m_draw_req)+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("' where index_id ='")+m_index_id+wxT("' AND batch_id='")+m_batch_id+wxT("';");
  //  }
    wxGetApp().app_sql_update(str_sql);
}

void nstd_mat_apply::Onbutton_change_relClick(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_mat_list->GetSelectedRows();

    if(array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项次，无法后续操作!"));
        return;
    }


    int i_count = array_sel_line.GetCount();

    wxString str_units;
    for(int i=0;i<i_count ;i++)
    {
        str_units = gd_mat_list->GetCellValue(array_sel_line.Item(i),9);

        configure_mat_list_editor dlg;
        dlg.m_index_id = gd_mat_list->GetCellValue(array_sel_line.Item(i),0);
        dlg.m_batch_id = gd_mat_list->GetCellValue(array_sel_line.Item(i),1);
        dlg.m_sequence = gd_mat_list->GetCellValue(array_sel_line.Item(i),2);
        dlg.m_mat_desc = gd_mat_list->GetCellValue(array_sel_line.Item(i),4);
        dlg.m_mat_id = gd_mat_list->GetCellValue(array_sel_line.Item(i),5);
        dlg.m_qty = gd_mat_list->GetCellValue(array_sel_line.Item(i),6);
        dlg.m_unit = gd_mat_list->GetCellValue(array_sel_line.Item(i),7).Upper();
        dlg.m_comments = gd_mat_list->GetCellValue(array_sel_line.Item(i),8);
        dlg.init_ctr_value();

        dlg.init_checklistbox(m_units, str_units);

        if(dlg.ShowModal() == wxID_OK)
        {
            nstdappTable * table = gd_mat_list->GetTable();
            cacheLine *line = table->GetLine(array_sel_line.Item(i));

            table->Set_Saved_Line(array_sel_line.Item(i));
            table->SetLastRow(array_sel_line.Item(i));
            line->cols[4] = dlg.m_mat_desc;
            line->cols[5] = dlg.m_mat_id;
            line->cols[6] = dlg.m_qty;
            line->cols[7] = dlg.m_unit;
            line->cols[8] = dlg.m_comments;
            line->cols[9] = dlg.m_str_units;


            table->StoreLine();
        }else
           continue;

    }
}

void nstd_mat_apply::Ongd_mat_listKeyDown(wxKeyEvent& event)
{
    long key_code = event.GetKeyCode();

    if(!gr_para.login_status)
    {
        return;
    }

    wxString str_group = wxGetApp().get_only_group();
    if(str_group != wxT("G0006") && str_group != wxT("G0007") && str_group != wxT("G0008"))
    {
        return;
    }

    if(m_index_id.IsEmpty())
        return;

    int i_row;
    switch(key_code)
    {
    case WXK_CONTROL_V:
            i_row = paste_data_from_clipboard();
            wxLogMessage(_("共有")+NumToStr(i_row)+_("行内容粘贴成功!"));
        break;
    default:
        break;
    }

    event.Skip();
}


void nstd_mat_apply::OnButton_Import_MatClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    wxString str_group = wxGetApp().get_only_group();
    if(str_group != wxT("G0006") && str_group != wxT("G0007") && str_group != wxT("G0008")&& str_group!=wxT("G0004")&&!m_design)
    {
        wxLogMessage(_("您所属的组无此权限!"));
        return;
    }

    int i_row = paste_data_from_clipboard();

    if(i_row ==0)
        return;

    wxLogMessage(_("共有")+NumToStr(i_row)+_("行内容粘贴成功!"));

}

bool nstd_mat_apply::check_valid_data_clipboard(wxArrayInt &i_error,wxArrayString &array_rows)
{
    int i_row, i_col;
    wxString text, colSep;
    wxArrayString array_cols;
    bool b_result=true;

    if (wxTheClipboard->Open())
    {
        if (wxTheClipboard->IsSupported(wxDF_TEXT))
        {
            wxTextDataObject textData;
            wxTheClipboard->GetData(textData);
            text = textData.GetText();
        }
        else
        {
            wxTheClipboard->Close();
            return false;
        }
        wxTheClipboard->Close();
    }
    else
    {
        return false;
    }

    if(text.IsEmpty())
        return false;

    colSep = wxT("\t");
    array_rows = wxStringTokenize(text,END_OF_LINE, wxTOKEN_DEFAULT );

    i_row = array_rows.GetCount();


    wxString str;

    for(int i = 0;i<i_row;i++)
    {
        array_cols = wxStringTokenize(array_rows.Item(i),colSep, wxTOKEN_RET_EMPTY_ALL );

        i_col = array_cols.GetCount();

        if(i_col < 5)
        {
            b_result = false;
            i_error.Add(i);
        }

        for(int j=0;j<i_col;j++)
        {
                str = array_cols.Item(j);
                str.Replace(wxT("."), wxEmptyString);
                str.Replace(wxT(","),wxEmptyString);
                if(!str.IsNumber()&& (j == 1 || j==2))
                {
                    b_result = false;
                    i_error.Add(i);

                    break;
                }
        }

        array_cols.Clear();
    }


    return b_result;


}

int nstd_mat_apply::paste_data_from_clipboard()
{
    wxArrayInt array_error;
    wxArrayString array_data;

    int i_row,i_error,i_pos,i;


    bool b_result = check_valid_data_clipboard(array_error, array_data);

    if(!b_result && array_error.IsEmpty())
    {
        wxLogMessage(_("剪切板内内容为空，请复制好数据后在操作!"));
        return 0;

    }

    i_error = array_error.GetCount();
    wxString str_error;
    for(i=0;i<i_error;i++)
    {
        i_pos = array_error.Item(i);
        str_error = str_error+ array_data.Item(i_pos)+wxT("\n");
    }
    if(!b_result)
    {
        wxLogMessage(_("如下数据格式错误:\n")+str_error);
        return 0;
    }


    i_row = array_data.GetCount();

    bool b_add;


    if(wxMessageBox(_("请确认是否在现有清单上增加，还是覆盖,(YES-增加; NO-覆盖)"),_("确认"),wxYES_NO)==wxYES)
        b_add= true;
    else b_add = false;

    wxArrayString array_col;

    nstdappTable * table = gd_mat_list->GetTable();

    int i_grid_row = table->GetNumberRows();
    wxString colSep = wxT("\t");
    wxString str_units,str;

    for(int j=0; j<m_units.GetCount(); j++)
    {
        str_units = str_units+m_units.Item(j)+wxT(";");
    }


    if(!b_add)
    {
        if(i_grid_row>i_row)
        {
            int i_add = i_grid_row-i_row;
            table->DeleteRows(i_row-1,i_add);
        }

        for(i=0; i<i_row; i++)
        {
            array_col = wxStringTokenize(array_data.Item(i),colSep, wxTOKEN_RET_EMPTY_ALL );

            cacheLine *line;
            if(i>i_grid_row-1)
            {
                table->AppendRows(1);

                line = table->GetLine(i);
                if (!line->cols)
                    line->cols = new wxString[10];

                line->cols[0] = m_index_id;
                line->cols[1] = m_batch_id;
                line->cols[9] = str_units;

                int i_seq;
                if(i==0)
                    str = wxT("0001");
                else
                {
                    i_seq= atoi(gd_mat_list->GetCellValue(i-1,2).ToAscii())+1;
                    str = zero_begin(i_seq,4);
                }

                line->cols[2] = str;
                line->cols[3] = gr_para.plant;

            }
            else
            {
                line = table->GetLine(i);
                table->Set_Saved_Line(i);

            }

            line->cols[4] = array_col.Item(0);
            line->cols[5] = array_col.Item(1);
            line->cols[6] = array_col.Item(2);
            line->cols[7] = array_col.Item(3);
            line->cols[8] = array_col.Item(4);

            table->SetLastRow(i);
            table->StoreLine();
        }

    }else
    {
       for(i=0; i<i_row; i++)
        {
            array_col = wxStringTokenize(array_data.Item(i),colSep, wxTOKEN_RET_EMPTY_ALL );

            cacheLine *line;
            table->AppendRows(1);

            line = table->GetLine(i_grid_row+i);
            table->SetLastRow(i_grid_row+i);
            if (!line->cols)
                line->cols = new wxString[10];

            line->cols[0] = m_index_id;
            line->cols[1] = m_batch_id;
            line->cols[9] = str_units;


            int i_seq;
            if(i_grid_row+i ==0)
                str = wxT("0001");
            else
            {
                i_seq= atoi(gd_mat_list->GetCellValue(i_grid_row+i-1,2).ToAscii())+1;
                str = zero_begin(i_seq,4);
            }

            line->cols[2] = str;
            line->cols[3] = gr_para.plant;

            line->cols[4] = array_col.Item(0);
            line->cols[5] = array_col.Item(1);
            line->cols[6] = array_col.Item(2);
            line->cols[7] = array_col.Item(3);
            line->cols[8] = array_col.Item(4);
            table->StoreLine();
        }
    }


    return i_row;
}

void nstd_mat_apply::Ongd_mat_listCellSelect(wxGridEvent& event)
{
    nstdappTable * table = gd_mat_list->GetTable();

    bool doSkip = true;

	if (table)
	{
		if (table->LastRow() >= 0)
		{
			if (table->LastRow() != event.GetRow())
			{
				doSkip = doSave();
			}
		}
		else if (gd_mat_list->GetGridCursorRow() != event.GetRow())
		{
		}
	}

	if (doSkip)
		event.Skip();
}

bool nstd_mat_apply::doSave()
{
    gd_mat_list->HideCellEditControl();
    gd_mat_list->SaveEditControlValue();
    gd_mat_list->DisableCellEditControl();

    if (!gd_mat_list->GetTable()->StoreLine())
		return false;

    return true;

}

void nstd_mat_apply::show_gui_control()
{
    switch(m_use_status)
    {
    case 0:

        enable_configure_control(true);

        if(m_design)
        {

            Button_Receive->Show(true);
            Button_task_list->Show(true);
            Button_CONF_APPLY->Show(false);

        }else
        {
            Button_Receive->Show(false);
            Button_task_list->Show(false);
            Button_CONF_APPLY->Show(true);
        }

        Button_Generate->Show(true);

        if((m_group=="G0004")&&!m_cs_mode)
        {
            sb_low_task->Show(true);
            st_nstd_engineer->Show(true);
            st_low_nstd_feedback->Show(true);
            st_low_nstd_reason->Show(true);
            tc_engineer->Show(true);
            tc_low_status->Show(true);
            Button_Engineer->Show(true);
            Button_Return->Show(true);
            tc_low_nstd_feedback->Show(true);
            tc_low_nstd_reason->Show(true);
            Button_Low_Confirm->Show(true);
            Button_Low_Rel->Show(true);

            tc_remarks->Show(true);
            Button_PASS_NSTD->Show(true);
            sb_feedback_configure->Show(true);

            Button_PASS_NSTD->SetLabel("关闭非标处理");
            sb_feedback_configure->SetLabel("非标处理结束");


        }
        else
        {
            sb_low_task->Show(false);
            st_nstd_engineer->Show(false);
            st_low_nstd_feedback->Show(false);
            st_low_nstd_reason->Show(false);
            tc_engineer->Show(false);
            tc_low_status->Show(false);
            Button_Engineer->Show(false);
            Button_Return->Show(false);
            tc_low_nstd_feedback->Show(false);
            tc_low_nstd_reason->Show(false);
            Button_Low_Confirm->Show(false);
            Button_Low_Rel->Show(false);

            tc_remarks->Show(false);
            Button_PASS_NSTD->Show(false);
            sb_feedback_configure->Show(false);
        }


        sb_att_info->Show(true);
        //cb_nstd_drawing->Enable(true);
        //cb_nstd_mat->Enable(true);

        Button_Cancel->Show(true);
  //      Button_Restore->Show(true);
        Button_Unit->Show(false);
        Button_Add_Batch->Show(true);
        Button_Rel_Units->Show(false);
        button_change_rel->Show(false);

        Button_Workflow->Show(false);
        Button_Nonstd_Ins_Doc->Show(false);
        break;
    case 1:

        enable_configure_control(false);
        Button_Receive->Show(true);
        Button_task_list->Show(true);
        Button_Generate->Show(true);
        sb_low_task->Show(true);
        st_nstd_engineer->Show(true);
        st_low_nstd_feedback->Show(true);
        st_low_nstd_reason->Show(true);
        tc_engineer->Show(true);
        tc_low_status->Show(true);
        Button_Engineer->Show(true);
        Button_Return->Show(true);
        tc_low_nstd_feedback->Show(true);
        tc_low_nstd_feedback->Enable(false);

        tc_low_nstd_reason->Show(true);
        tc_low_nstd_reason->Enable(true);

        Button_Low_Confirm->Show(false);
        Button_Low_Rel->Show(true);

        Button_CONF_APPLY->Show(false);

        sb_feedback_configure->Show(true);
        tc_remarks->Show(true);
        Button_PASS_NSTD->Show(true);

        sb_att_info->Show(true);
        cb_nstd_drawing->Enable(false);
        cb_nstd_mat->Enable(false);

        Button_Submit->Enable(false);
        Button_drawing->Enable(false);

        Button_Cancel->Show(true);
  //      Button_Restore->Show(true);
        Button_Unit->Show(true);
        Button_Add_Batch->Show(true);
        Button_Rel_Units->Show(false);
        button_change_rel->Show(false);
        Button_Workflow->Show(true);
        Button_Nonstd_Ins_Doc->Show(false);
        break;

    case 2:
        enable_configure_control(false);
        Button_Receive->Show(true);
        Button_task_list->Show(true);
        Button_Generate->Show(true);
        sb_low_task->Show(true);
        st_nstd_engineer->Show(true);
        st_low_nstd_feedback->Show(true);
        st_low_nstd_reason->Show(true);
        tc_engineer->Show(true);
        tc_low_status->Show(true);
        Button_Engineer->Show(false);
        Button_Return->Show(true);
        tc_low_nstd_feedback->Show(true);
        tc_low_nstd_feedback->Enable(true);

        tc_low_nstd_reason->Show(true);
        tc_low_nstd_reason->Enable(false);

        Button_Low_Confirm->Show(true);
        Button_Low_Rel->Show(true);

        Button_CONF_APPLY->Show(false);

        sb_feedback_configure->Show(false);
        tc_remarks->Show(false);
        Button_PASS_NSTD->Show(false);

        sb_att_info->Show(true);
       // cb_nstd_drawing->Enable(true);
       // cb_nstd_mat->Enable(true);

        Button_Submit->Enable(false);
        Button_drawing->Enable(false);

        Button_Cancel->Show(false);
//        Button_Restore->Show(false);

        Button_Unit->Show(false);
        Button_Add_Batch->Show(false);
         Button_Rel_Units->Show(true);
         button_change_rel->Show(true);
         Button_Nonstd_Ins_Doc->Show(true);

        Button_Workflow->Show(true);
        break;

    case 3:
        enable_configure_control(true);

        Button_Receive->Show(true);
        Button_task_list->Show(true);
        Button_Generate->Show(true);
        sb_low_task->Show(false);
        st_nstd_engineer->Show(false);
        st_low_nstd_feedback->Show(false);
        st_low_nstd_reason->Show(false);
        tc_engineer->Show(false);
        tc_low_status->Show(false);
        Button_Engineer->Show(false);
        Button_Return->Show(false);
        tc_low_nstd_feedback->Show(false);
        tc_low_nstd_reason->Show(false);
        Button_Low_Confirm->Show(false);
        Button_Low_Rel->Show(false);

        Button_CONF_APPLY->Show(false);

        sb_feedback_configure->Show(false);
        tc_remarks->Show(false);
        Button_PASS_NSTD->Show(false);

        sb_att_info->Show(true);
       // cb_nstd_drawing->Enable(true);
       // cb_nstd_mat->Enable(true);

        Button_Cancel->Show(true);
   //     Button_Restore->Show(true);

        Button_Add_Batch->Show(true);

        Button_Unit->Show(false);
         Button_Rel_Units->Show(false);
         button_change_rel->Show(false);
         Button_Nonstd_Ins_Doc->Show(false);

        Button_Workflow->Show(false);
        break;
    case 4:
        enable_configure_control(true);

        Button_Receive->Show(false);
        Button_task_list->Show(false);
        Button_Generate->Show(true);
        sb_low_task->Show(false);
        st_nstd_engineer->Show(false);
        st_low_nstd_feedback->Show(false);
        st_low_nstd_reason->Show(false);
        tc_engineer->Show(false);
        tc_low_status->Show(false);
        Button_Engineer->Show(false);
        Button_Return->Show(false);
        tc_low_nstd_feedback->Show(false);
        tc_low_nstd_reason->Show(false);
        Button_Low_Confirm->Show(false);
        Button_Low_Rel->Show(false);

        Button_CONF_APPLY->Show(false);

        sb_feedback_configure->Show(false);
        tc_remarks->Show(false);
        Button_PASS_NSTD->Show(false);

        sb_att_info->Show(true);
        //cb_nstd_drawing->Enable(true);
        //cb_nstd_mat->Enable(true);

        Button_Cancel->Show(true);
  //      Button_Restore->Show(true);

        Button_Add_Batch->Show(true);

        Button_Unit->Show(false);
         Button_Rel_Units->Show(false);
         button_change_rel->Show(false);
         Button_Nonstd_Ins_Doc->Show(false);

        Button_Workflow->Show(false);
        break;

    default:
        break;
    }

    Layout();
}

void nstd_mat_apply::OnButton_workflow_matClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(m_batch_id.IsEmpty()||m_index_id.IsEmpty())
    {
        wxLogMessage(_("请先选择非标任务和批次!"));
        return;
    }

    wxArrayString array_sel_ins, array_sel_workflow;
    wxString str;

    str = wf_str_materials;
    array_sel_workflow.Add(str);
    array_sel_ins.Add(m_index_id+wxT("-")+m_batch_id);
    ins_nonstd_proc_log ipl_dlg;

    ipl_dlg.Refresh_list_view(array_sel_ins, array_sel_workflow);
    ipl_dlg.ShowModal();
}

void nstd_mat_apply::OnButton_workflow_drawClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(m_batch_id.IsEmpty()||m_index_id.IsEmpty())
    {
        wxLogMessage(_("请先选择非标任务和批次!"));
        return;
    }

    wxArrayString array_sel_ins, array_sel_workflow;
    wxString str;

    str = wf_str_design;
    array_sel_workflow.Add(str);
    array_sel_ins.Add(m_index_id+wxT("-")+m_batch_id);
    ins_nonstd_proc_log ipl_dlg;

    ipl_dlg.Refresh_list_view(array_sel_ins, array_sel_workflow);
    ipl_dlg.ShowModal();

}

void nstd_mat_apply::OnButton_CONF_APPLYClick(wxCommandEvent& event)
{
    wxString _choice[3]=
    {
        _("流程中的项目"),
        _("已经完成的项目"),
        _("EDS项目申请")
    };
    wxSingleChoiceDialog cdlg(this, _("操作选择："),_("项次选择"),3, _choice);

    int  i_active;

    //combo_nstd_item_catalog->Enable(true);

    if(cdlg.ShowModal() == wxID_OK)
    {
        i_active = cdlg.GetSelection();
    }else
        return;

    nstd_app_unit_list dlg_task;
    m_units.Clear();

    bool b_create;
    dlg_task.i_active = i_active;
    wxString s_nstd_catalog;

    if(i_active ==1)
    {
        wxTextEntryDialog tdlg(this,_("请输入WBS NO(支持模糊)"),_("WBS NO"),wxT(""),wxOK | wxCANCEL);

        tdlg.SetTextValidator(wxFILTER_EMPTY );

        if(tdlg.ShowModal() == wxID_OK)
        {
            dlg_task.m_str_unit = tdlg.GetValue();
        }else
            return;
    }else if(i_active==2)
    {
        wxString s_group = wxGetApp().get_only_group();
        if(!wxGetApp().is_eds(s_group))
        {
            wxLogMessage("无此操作权限!");
            return;
        }

        wxTextEntryDialog tdlg(this,_("请输入完整的项目WBS(例E/30021339，不区分大小写)"),_("项目WBS NO"),wxT(""),wxOK | wxCANCEL);
        if(tdlg.ShowModal() == wxID_OK)
        {
            dlg_task.m_str_unit = tdlg.GetValue();
        }else
            return;
    }


    dlg_task.refresh_list();

    if(dlg_task.ShowModal() == wxID_CANCEL)
    {
        return;
    }

    m_units = dlg_task.array_select;
    wxString l_link_list = get_link_wbs(m_units);

    wxString str_sql = wxT("SELECT index_id FROM l_nonstd_app_item where link_list like '%")+l_link_list+wxT("%' AND res_person ='")+gr_para.login_user +wxT("';");


    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int i_count = _res->GetRowsNumber();

    if(i_count == 0)
        b_create = true;
    else b_create = false;

    if(!b_create &&  wxMessageBox(_("您已经创建的申请单中，已经包含所选项目，是否重新创建新的申请?"),_("确认"),wxYES_NO)==wxYES)
    {
        b_create = true;
    }

    if(b_create)
        _res->Clear();

    if(!b_create && i_count>1)
    {
        show_control(true);
    }
    else
    {
        show_control(false);
    }

    if(!b_create)
    {
        m_search_mode = true;
        _res->MoveFirst();
        for(int i=0; i<i_count; i++)
        {
            array_search_result.Add(_res->GetVal(wxT("index_id")));
            _res->MoveNext();
        }

        _res->Clear();

        wxString str_step = wxT("1/")+ NumToStr(i_count);

        tc_qty->SetValue(str_step);

        m_index_id = array_search_result.Item(0);


        refresh_top_gui();
        refresh_low_gui();
        refresh_list();
        m_search_mode = false;
    }
    else
    {
        wxString _choice1[11]=
        {
            _("整梯BOM"),
            _("人机界面"),
            _("轿厢"),
            _("井道部件"),
            _("控制系统"),
            _("机房部件"),
            _("轿厢架"),
            _("门系统"),
            _("电缆"),
            _("对重系统"),
            _("其他")
        };
        wxSingleChoiceDialog ndlg(this, _("请选择非标类别"),_("非标类别"),11, _choice1);

        if(ndlg.ShowModal() == wxID_OK)
        {
            s_nstd_catalog= ndlg.GetStringSelection();
        }

        combo_nstd_item_catalog->SetValue(s_nstd_catalog);

        tc_project_id->SetValue(m_units.Item(0).Left(10));
        tc_project_name->SetValue(dlg_task.m_proj);
        dp_mat_req->SetValue(wxDateTime::Today()+wxDateSpan(0,0,0,2));
        dp_draw_req->SetValue(dlg_task.m_req_finish);
        dp_proj_au_date->SetValue(wxGetApp().get_prj_auth_date(m_units.Item(0)));

        wxString str_serial_id = wxGetApp().get_ser_id(wxT("l_nonstd_app_header"), wxT("nonstd_id"));

        save_header(str_serial_id, l_link_list);

        m_index_id = str_serial_id+wxT("-1");
        array_search_result.Clear();
        save_item(str_serial_id, l_link_list, s_nstd_catalog);

        refresh_top_gui();
        refresh_low_gui();

        refresh_list();
    }
}

void nstd_mat_apply::clear_content()
{
        m_batch_id.Empty();
        m_array_batch_id.Clear();
        m_nstd_mat_app_id.Empty();
        tc_project_id->Clear();
        tc_project_name->Clear();
        tc_batch_id->Clear();
        tc_remarks->Clear();
        tc_nstd_reason->Clear();
        combo_nstd_item_catalog->Clear();
        tc_nstd_mat_app_id->Clear();
}

void nstd_mat_apply::save_header(wxString s_nstd_app_id, wxString s_link_list)
{
    wxString s_contract_id = tc_project_name->GetValue();

    int i_pos = s_contract_id.Find(wxT(" "));
    s_contract_id = s_contract_id.Left(i_pos);
    if(!s_contract_id.IsNumber())
        s_contract_id.Empty();



    wxString str_sql = wxT("INSERT INTO l_nonstd_app_header(nonstd_id, project_id, contract_id, link_list, status, mat_req_date, drawing_req_date, nonstd_desc, modify_date, modify_emp_id, create_date, create_emp_id, flow_mask) \
                  VALUES ('")+s_nstd_app_id+wxT("','")+tc_project_id->GetValue()+wxT("','")+s_contract_id+
                  wxT("','")+s_link_list+wxT("','10','")+ DateToStrFormat(dp_mat_req->GetValue())+wxT(" 23:00:00")+wxT("','")+
                  DateToStrFormat(dp_draw_req->GetValue())+wxT(" 23:00:00")+wxT("','")+tc_nstd_reason->GetValue()+wxT("','")+DateToAnsiStr(wxDateTime::Now())+
                  wxT("','")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','000');");

    str_sql.Replace(wxT("''"),wxT("NULL"));
    wxGetApp().app_sql_update(str_sql);
}

wxString nstd_mat_apply::get_link_wbs(wxArrayString &a_wbs)
{
     wxString link_list;
     if(!a_wbs.IsEmpty())
     {
         int i_count = a_wbs.GetCount();
         for(int i=0;i<i_count;i++)
         {
             link_list = link_list + a_wbs.Item(i).Left(14)+wxT(";");
         }

         return link_list;
     }

     return wxEmptyString;
}

void nstd_mat_apply::save_item(wxString s_nstd_app_id, wxString s_link_list, wxString s_nstd_catalog)
{
    wxString str_sql = wxT("INSERT INTO l_nonstd_app_item(index_id, nonstd_id, item_ser, item_catalog, link_list, nonstd_catalog, nonstd_desc, \
            modify_date, modify_emp_id, create_date, create_emp_id, remarks, res_person) VALUES ('")+m_index_id+wxT("','")+s_nstd_app_id+wxT("','1','C','")+s_link_list+wxT("','")+s_nstd_catalog+wxT("','")+
            tc_nstd_reason->GetValue()+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+
            gr_para.login_user+wxT("','")+tc_remarks->GetValue()+wxT("','")+gr_para.login_user+wxT("');");

 //   wxLogMessage(str_sql);
    str_sql.Replace(wxT("''"),wxT("NULL"));
    wxGetApp().app_sql_update(str_sql);
}

void nstd_mat_apply::Ondp_mat_reqChanged(wxDateEvent& event)
{
    if(m_index_id.IsEmpty())
        return;

    wxString str_mat_req_date = DateToStrFormat(dp_mat_req->GetValue())+ wxT(" 23:00:00");
    wxString str_nstd_app_id;

    int i_pos = m_index_id.Find(wxT("-"));
    str_nstd_app_id=m_index_id.Left(i_pos);

    wxGetApp().update_data_in_database(wxT("mat_req_date"),str_mat_req_date,wxT("l_nonstd_app_header"), wxT("nonstd_id"),str_nstd_app_id);
}

void nstd_mat_apply::Ondp_draw_reqChanged(wxDateEvent& event)
{
    if(m_index_id.IsEmpty())
        return;

    wxString str_draw_req_date = DateToStrFormat(dp_draw_req->GetValue())+ wxT(" 23:00:00");
    wxString str_nstd_app_id;

    int i_pos = m_index_id.Find(wxT("-"));
    str_nstd_app_id=m_index_id.Left(i_pos);

    wxGetApp().update_data_in_database(wxT("drawing_req_date"),str_draw_req_date,wxT("l_nonstd_app_header"), wxT("nonstd_id"),str_nstd_app_id);

}

void nstd_mat_apply::Ontc_nstd_reasonTextEnter(wxCommandEvent& event)
{
    if(m_index_id.IsEmpty())
        return;

    wxGetApp().update_data_in_database(wxT("nonstd_desc"),tc_nstd_reason->GetValue(),wxT("l_nonstd_app_item"), wxT("index_id"),m_index_id);
}

void nstd_mat_apply::enable_configure_control(bool b_sure)
{
     dp_proj_au_date->Enable(false);
     dp_draw_req->Enable(b_sure);
     dp_mat_req->Enable(b_sure);
     tc_nstd_reason->Enable(b_sure);
     tc_remarks->Enable(!b_sure);
     Button_PASS_NSTD->Enable(!b_sure);
     //Button_Engineer->Enable(!b_sure);
}

void nstd_mat_apply::OnButton_EngineerClick(wxCommandEvent& event)
{

    if(m_batch_id.IsEmpty())
    {
       wxLogMessage(_("请先生成批次，在分配指定工程师!"));
       return;
    }

    if(prj_str_to_status(tc_low_status->GetValue())==-1)
    {
        wxLogMessage(_("批次任务已经删除，要分配，请恢复！"));
        return;
    }

    if(m_status !=3 && m_receive_mode!=1&& m_use_status!=0)
    {
        wxLogMessage(_("非标申请非标负责人已经处理完成，子任务无法退回!"));
         return;
    }

    if(!m_engineer.s_res_id.IsEmpty() && prj_str_to_status(tc_low_status->GetValue()) > 0)
    {
        wxLogMessage(_("任务已经分配，要重新分配，需要工程师退回任务!"));
        return;
    }

    wxArrayString str_group_list;

    str_group_list.Add(m_group);

     wxArrayString  s_members = wxGetApp().get_member_in_group(str_group_list );

    wxSingleChoiceDialog cdlg(this, _("请选择操作人员:"),_("操作选择"),s_members);


    if(cdlg.ShowModal() == wxID_OK)
    {
    }
    else
    {
        return;
    }

    wxString s_engineer = cdlg.GetStringSelection();

    int i_pos = s_engineer.Find('-');

    int i_length = s_engineer.Length();

    m_engineer.s_res_id = s_engineer.Left(i_pos);
    m_engineer.s_res_name = s_engineer.Right(i_length-i_pos-1);
    tc_engineer->SetValue(m_engineer.s_res_name);


    wxString l_query = wxT("UPDATE l_nonstd_app_item_instance SET modify_emp_id ='")+gr_para.login_user+wxT("',modify_date ='")+DateToAnsiStr(wxDateTime::Now())+wxT("', res_engineer = '")+m_engineer.s_res_id+wxT("', instance_nstd_desc='")+
                      tc_low_nstd_reason->GetValue()+wxT("', status = '1',ins_start_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("' where index_id = '")+m_index_id+wxT("' AND batch_id = '")+m_batch_id+wxT("';");
    l_query.Replace(wxT("''"),wxT("NULL"));

    wxLogMessage(l_query);
    if(wxGetApp().app_sql_update(l_query))
    {

        refresh_low_gui();

        if(m_engineer.s_res_id == gr_para.login_user)
        {
            tc_low_nstd_feedback->Enable(true);
            Button_Low_Confirm->Show(true);
        }
        else
        {
            tc_low_nstd_feedback->Enable(false);
            Button_Low_Confirm->Show(false);
        }
        Layout();

        wxLogMessage(m_index_id+wxT("-")+m_batch_id+_("任务分配给")+m_engineer.s_res_name+_("成功!"));
    }

}

void nstd_mat_apply::OnButton_Low_ConfirmClick(wxCommandEvent& event)
{
    if(prj_str_to_status(tc_low_status->GetValue())>1)
    {
            wxLogMessage(_("任务已经完成，无需重复确认!"));
            return;
    }

    if(gd_mat_list->GetNumberRows()==0 && tc_low_nstd_feedback->GetValue().IsEmpty()&&!m_mat_req&&!m_draw_req)
    {
            wxLogMessage(_("没有做任何操作前，无法确认完成任务!"));
            return;
    }

    if(m_mat_req && nstd_str_to_status(tc_mat_status->GetValue())==-2)
    {
         wxMessageBox(_("非标物料维护申请尚未提交，请先提交!"),_("提示"));

         wxLogMessage(_("非标物料维护申请尚未提交，请先提交!"));

         return;
    }

    if(m_draw_req && nstd_str_to_status(tc_draw_status->GetValue())==-2)
    {
         wxMessageBox(_("非标设计申请尚未提交，请先提交!"),_("提示"));

         wxLogMessage(_("非标设计申请尚未提交，请先提交!"));

         return;
    }


    if(wxMessageBox(_("确认回复已经完成非标分任务?"),_("提示"),wxYES_NO)==wxNO)
       return;

    wxString str_sql= wxT("UPDATE l_nonstd_app_item_instance SET modify_emp_id ='")+gr_para.login_user+wxT("',modify_date ='")+DateToAnsiStr(wxDateTime::Now())+wxT("', instance_remarks='")+
                      tc_low_nstd_feedback->GetValue()+wxT("', status = '2',ins_finish_date = '")+ DateToAnsiStr(wxDateTime::Now())+wxT("' where index_id = '")+m_index_id+wxT("' AND batch_id = '")+m_batch_id+wxT("';");

    if(wxGetApp().app_sql_update(str_sql))
    {
        active_configure_mat_list();//非标工程师点完成后，配置工程师才能看到物料表。
        refresh_low_gui();
        wxLogMessage(m_index_id+wxT("-")+m_batch_id+_("任务已经完成!"));
    }
}

bool nstd_mat_apply::active_configure_mat_list()//非标工程师点完成后，配置工程师才能看到物料表。
{
    wxString str_sql = wxT("Update l_nonstd_configure_mat_list SET modify_emp_id ='")+gr_para.login_user+wxT("',modify_date ='")+DateToAnsiStr(wxDateTime::Now())+wxT("',is_active = true where index_id = '")+m_index_id+wxT("' and batch_id ='")+m_batch_id+wxT("';");
    return wxGetApp().app_sql_update(str_sql);
}

void nstd_mat_apply::OnButton_Low_RelClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(m_index_id.IsEmpty())
    {
        wxLogMessage(_("请先选择相应的非标物料申请!"));
        return;
    }

    wxString str_sql;

    nstd_mat_task_list dlg;
    dlg.init_nstd_mat_instance_header();
    str_sql = wxT("SELECT index_mat_id, concat(contract_id,' ', project_name,'-',project_id) as project_name, mat_req_date, drawing_req_date, \
                          nonstd_catalog, nonstd_desc, nonstd_value, (select name from s_employee where employee_id = res_person) as res_person,\
                          instance_nstd_desc, (select name from s_employee where employee_id = res_engineer) as res_engineer, status, link_list from v_nonstd_app_item_instance where  index_id='")+m_index_id+wxT("' order by index_mat_id ASC;");
   dlg.Set_Query(str_sql);
   dlg.refresh_list(0);
   dlg.m_search_mode = true;
   dlg.show_control(true);
   dlg.ShowModal();
}

void nstd_mat_apply::OnButton_ReturnClick(wxCommandEvent& event)
{
    wxString str_sql;

    if(m_index_id.IsEmpty())
        return;

    if(m_status !=3 && m_receive_mode!=1&&m_use_status!=0)
    {
        if(wxMessageBox(_("非标申请非标负责人已经处理完成，子任务无法退回!"),_("错误"),wxYES)==wxYES)
             wxLogMessage(_("非标申请非标负责人已经处理完成，子任务无法退回!"));
         return;
    }

    if(m_use_status == 2||(m_use_status==0 && m_design))
    {
        if(prj_str_to_status(tc_low_status->GetValue())==0)
        {
            wxLogMessage(_("批次任务已经退回给负责人，无法再次退回"));
            return;
        }

        if(prj_str_to_status(tc_low_status->GetValue()) > 1)
        {
            wxLogMessage(_("任务已经完成，无法退回!"));
            return;
        }

        if(gd_mat_list->GetNumberRows() >0)
        {
            wxLogMessage(_("已经生成配置物料清单，无法退回!"));
            return;
        }

        if(nstd_str_to_status(tc_mat_status->GetValue())>0 || nstd_str_to_status(tc_draw_status->GetValue())>0)
        {
            wxLogMessage(_("非标物料或非标设计申请均已提交，无法退回!"));
            return;
        }


       if(wxMessageBox(_("确认退回给非标负责人?"),_("提示"),wxYES_NO)==wxNO)
           return;


        str_sql = wxT("UPDATE l_nonstd_app_item_instance SET modify_emp_id ='")+gr_para.login_user+wxT("',modify_date ='")+DateToAnsiStr(wxDateTime::Now())+wxT("', res_engineer = NULL, instance_remarks='")+
                           tc_low_nstd_feedback->GetValue()+wxT("', status = '0',ins_start_date= NULL where index_id = '")+m_index_id+wxT("' AND batch_id = '")+m_batch_id+wxT("';");
        str_sql.Replace(wxT("''"),wxT("NULL"));
        if(wxGetApp().app_sql_update(str_sql))
        {
            refresh_low_gui();
            wxLogMessage(m_index_id+wxT("-")+m_batch_id+_("任务已经退回给")+m_res_person.s_res_name+_("成功!"));
        }
    }

    if(m_use_status == 1||(m_use_status==0 && !m_design))
    {
        if(prj_str_to_status(tc_low_status->GetValue())<0)
        {
            wxLogMessage(_("批次任务已经删除，无法退回"));
            return;
        }

        if(prj_str_to_status(tc_low_status->GetValue()) == 1)
        {
            wxLogMessage(_("任务已经退回，无法再次退回!"));
            return;
        }

       if(prj_str_to_status(tc_low_status->GetValue()) == 5)
        {
            wxLogMessage(_("任务已经关闭，无法退回!"));
            return;
        }


       if(wxMessageBox(_("确认退回给非标工程师?"),_("提示"),wxYES_NO)==wxNO)
          return;

        str_sql = wxT("UPDATE l_nonstd_app_item_instance SET modify_emp_id ='")+gr_para.login_user+wxT("',modify_date ='")+DateToAnsiStr(wxDateTime::Now())+wxT("', status = '1',ins_finish_date= NULL,ins_is_return = true, ins_return_time = ins_return_time+1,ins_last_return_date='")+
                  DateToAnsiStr(wxDateTime::Now())+wxT("' where index_id = '")+m_index_id+wxT("' AND batch_id = '")+m_batch_id+wxT("';");
        str_sql.Replace(wxT("''"),wxT("NULL"));
        if(wxGetApp().app_sql_update(str_sql))
        {
            refresh_low_gui();
            wxLogMessage(m_index_id+wxT("-")+m_batch_id+_("任务已经退回给")+m_res_person.s_res_name+_("成功!"));
        }
    }

}

void nstd_mat_apply::Ontc_low_nstd_reasonTextEnter(wxCommandEvent& event)
{
    wxString str = tc_low_nstd_reason->GetValue();

    if(str.Trim().IsEmpty())
        return;

    wxString str_sql = wxT("UPDATE l_nonstd_app_item_instance SET modify_emp_id ='")+gr_para.login_user+wxT("',modify_date ='")+DateToAnsiStr(wxDateTime::Now())+wxT("', instance_nstd_desc='")+
                       str+wxT("' where index_id = '")+m_index_id+wxT("' AND batch_id = '")+m_batch_id+wxT("';");
    wxGetApp().app_sql_update(str_sql);
}

void nstd_mat_apply::Ontc_low_nstd_feedbackTextEnter(wxCommandEvent& event)
{

    wxString str = tc_low_nstd_feedback->GetValue();

    if(str.Trim().IsEmpty())
        return;

    wxString str_sql = wxT("UPDATE l_nonstd_app_item_instance SET modify_emp_id ='")+gr_para.login_user+wxT("',modify_date ='")+DateToAnsiStr(wxDateTime::Now())+wxT("', instance_remarks='")+
                       str+wxT("' where index_id = '")+m_index_id+wxT("' AND batch_id = '")+m_batch_id+wxT("';");
    wxGetApp().app_sql_update(str_sql);
}

void nstd_mat_apply::OnButton_CancelClick(wxCommandEvent& event)
{
    wxString str_sql;
    if(m_use_status == 0 || m_use_status == 3 || m_use_status == 4 )
    {

        if(m_batch_id.IsEmpty())
        {
            wxLogMessage(_("批次尚未生成！"));
            return;
        }

        if(m_mat_req && nstd_str_to_status(tc_mat_status->GetValue())>0)
        {
            wxLogMessage(_("非标物料已经提交流程，需要后续工程师退回本人,方可删除!"));
            return;
        }

        if(m_draw_req&& nstd_str_to_status(tc_draw_status->GetValue())>0)
        {
            wxLogMessage(_("非标设计已经提交流程，需要后续工程师退回本人,方可删除!"));
            return;
        }

        if(m_mat_req && nstd_str_to_status(tc_mat_status->GetValue())==0)
        {
           if(wxMessageBox(_("此操作会删除已经提交的物料维护流程数据，确认删除？"),_("提示"),wxYES)==wxYES)
           {
                if(delete_all_process(m_index_id+wxT("-")+m_batch_id, wf_str_materials))
                    delete_status(m_index_id+wxT("-")+m_batch_id, wf_str_materials);
            }
           else
            return;
        }

        if(m_draw_req && nstd_str_to_status(tc_draw_status->GetValue())==0)
        {
           if(wxMessageBox(_("此操作会删除已经提交的非标设计流程数据，确认删除？"),_("提示"),wxYES)==wxYES)
           {
                if(delete_all_process(m_index_id+wxT("-")+m_batch_id, wf_str_design))
                    delete_status(m_index_id+wxT("-")+m_batch_id, wf_str_design);
            }
           else
            return;
        }

        if(wxMessageBox(_("操作会彻底删除批次和分任务，确认删除?"),_("确认"),wxYES_NO)==wxNO)
             return;

        str_sql = wxT("DELETE FROM l_nonstd_app_item_instance WHERE index_id = '")+m_index_id+wxT("' and batch_id ='")+m_batch_id+wxT("';");
       if(wxGetApp().app_sql_update(str_sql))
       {
           wxLogMessage(m_batch_id+_("批次/分任务删除成功!"));
           remove_batch();
       }

/*
       str_sql = wxT("UPDATE l_nonstd_app_item_instance SET modify_emp_id ='")+gr_para.login_user+wxT("',modify_date ='")+DateToAnsiStr(wxDateTime::Now())+wxT("', status = '-1' where index_id = '")+m_index_id+wxT("' AND batch_id = '")+m_batch_id+wxT("';");
       if(wxGetApp().app_sql_update(str_sql))
       {
           wxLogMessage(m_batch_id+_("批次/分任务取消成功!"));
       }
*/

    }else if(m_use_status == 1)
    {
        if(!m_engineer.s_res_id.IsEmpty())
        {
            wxLogMessage(_("分任务已经授权给工程师，需要工程师退回方可操作!"));
            return;
        }
/*
        if(prj_str_to_status(tc_low_status->GetValue())== -1)
        {
            wxLogMessage(_("分任务已经取消，不必重复操作!"));
            return;
        }*/

        if(wxMessageBox(_("操作会彻底分任务，确认删除?"),_("确认"),wxYES_NO)==wxNO)
             return;

        str_sql = wxT("DELETE FROM l_nonstd_app_item_instance WHERE index_id = '")+m_index_id+wxT("' and batch_id ='")+m_batch_id+wxT("';");
       if(wxGetApp().app_sql_update(str_sql))
       {
           wxLogMessage(m_batch_id+_("分任务删除成功!"));
           remove_batch();
       }
/*       str_sql = wxT("UPDATE l_nonstd_app_item_instance SET modify_emp_id ='")+gr_para.login_user+wxT("',modify_date ='")+DateToAnsiStr(wxDateTime::Now())+wxT("', status = '-1' where index_id = '")+m_index_id+wxT("' AND batch_id = '")+m_batch_id+wxT("';");
       if(wxGetApp().app_sql_update(str_sql))
       {
           wxLogMessage(m_batch_id+_("分任务取消成功!"));
       }*/

    }


    refresh_low_gui();
}

void nstd_mat_apply::remove_batch()
{
    int i_count = m_array_batch_id.GetCount();

    int i_pos = m_array_batch_id.Index(m_batch_id);

    if(i_pos == i_count -1 && i_count != 1)
    {
        m_array_batch_id.Remove(m_batch_id);
        m_batch_id = m_array_batch_id.Item(i_count-2);

    }else if(i_count == 1)
    {
        m_batch_id.Empty();
        m_array_batch_id.Clear();
    }else
    {
        wxString str = m_batch_id;
        m_batch_id = m_array_batch_id.Item(m_array_batch_id.Index(m_batch_id)+1);
        m_array_batch_id.Remove(str);
    }

    tc_batch_id->SetValue(m_batch_id);

}
/*
void nstd_mat_apply::OnButton_RestoreClick(wxCommandEvent& event)
{
    wxString str_sql;
    if(m_batch_id.IsEmpty())
    {
        wxLogMessage(_("批次尚未生成！"));
        return;
    }

    if(m_use_status == 0 || m_use_status == 3  ||m_use_status ==4)
    {

       if(wxMessageBox(_("确认恢复批次?"),_("提示"),wxYES_NO)==wxNO)
          return;

        str_sql = wxT(" select status from l_nonstd_app_item_instance where index_id = '")+m_index_id+wxT("' AND batch_id = '")+m_batch_id+wxT("';");
        wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);
        if(_res->Status()!= PGRES_TUPLES_OK)
        {
            _res->Clear();
            return;
        }
        int i_count = _res->GetRowsNumber();

        if(i_count ==0)
        {
            _res->Clear();
            return;

        }

        _res->MoveFirst();
        int i_status = _res->GetInt(wxT("status"));

        if(i_status !=-1)
        {
            _res->Clear();
            wxLogMessage(_("此批次没有删除，谈不上恢复!"));
            return;
        }else _res->Clear();

       str_sql = wxT("UPDATE l_nonstd_app_item_instance SET modify_emp_id ='")+gr_para.login_user+wxT("',modify_date ='")+DateToAnsiStr(wxDateTime::Now())+wxT("', status = '0' where index_id = '")+m_index_id+wxT("' AND batch_id = '")+m_batch_id+wxT("';");
       if(wxGetApp().app_sql_update(str_sql))
       {
           wxLogMessage(m_batch_id+_("批次恢复成功!"));
       }

    }
    else if(m_use_status == 1)
    {
        if(prj_str_to_status(tc_low_status->GetValue())!=-1)
        {
            wxLogMessage(_("分任务未取消，谈不上恢复!"));
            return;
        }


      if(wxMessageBox(_("确认恢复分任务?"),_("提示"),wxYES_NO)==wxNO)
         return;

       str_sql = wxT("UPDATE l_nonstd_app_item_instance SET modify_emp_id ='")+gr_para.login_user+wxT("',modify_date ='")+DateToAnsiStr(wxDateTime::Now())+wxT("', status = '0' where index_id = '")+m_index_id+wxT("' AND batch_id = '")+m_batch_id+wxT("';");
       if(wxGetApp().app_sql_update(str_sql))
       {
           wxLogMessage(m_batch_id+_("分任务恢复成功!"));
       }

    }

    refresh_low_gui();

}*/

void nstd_mat_apply::OnButton_UnitClick(wxCommandEvent& event)
{
    if(m_units.IsEmpty() || m_index_id.IsEmpty())
        return;



    nstd_app_item_units dlg;
    wxString str_units;

    dlg.init_checklistbox(m_units, m_units, false);

    if(dlg.ShowModal() == wxID_OK)
    {
        str_units = dlg.m_units;

    }
    else
        return;

    wxArrayString array_sel = wxStringTokenize(str_units ,wxT(";"), wxTOKEN_DEFAULT  );

    if(!refresh_units_list(array_sel))
        return;
}

bool nstd_mat_apply::refresh_units_list(wxArrayString &array_sel)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return false;
    }

    if(!wxGetApp().conn->IsAlive())
    {
        wxLogMessage(_("系统连接已断开,请重新连接!"));
        wxGetApp().clear_login();
        return false;
    }

    int i_count = array_sel.GetCount();
    if(i_count == 0)
        return false;

    wxString str_clause;

    for(int i = 0;i<i_count;i++)
    {
        if(i!=i_count -1)
            str_clause = str_clause + wxT(" link_list like'%")+array_sel.Item(i)+wxT("%' OR ");
        else
            str_clause = str_clause + wxT(" link_list like'%")+array_sel.Item(i)+wxT("%' ");
    }

    wxString str_sql = wxT("SELECT index_id,batch_id, sequence, plant, mat_name_cn, mat_id, qty, unit,mat_comment, link_list \
                           FROM l_nonstd_configure_mat_list WHERE index_id = '")+ m_index_id+wxT("' AND (")+str_clause+wxT(") ORDER BY sequence ASC;");


     wxPostgreSQLresult* _res;
     _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return false;
    }

    wxGridUpdateLocker noUpdates(gd_mat_list);
    gd_mat_list->ClearGrid();

//    gd_mat_list->BeginBatch();

    wxString str_table= wxT("l_nonstd_configure_mat_list");
    wxString str_key = wxT("index_id,batch_id,sequence,");
    gd_mat_list->SetTable(new nstdappTable(_res, str_table, str_mat_header,wxT("0000000000"), str_key), true);

    gd_mat_list->Fit();
//    gd_mat_list->EndBatch();
    gd_mat_list->SetColSize(0,0);
    gd_mat_list->SetColSize(1,0);
    gd_mat_list->SetColSize(2,0);
    gd_mat_list->SetColSize(3,0);
    gd_mat_list->SetColSize(9,0);
    Layout();
    _res->Clear();

    return true;

}
//字符串匹配，比较难写，备注主动合并改为被动读取。
bool nstd_mat_apply::add_remarks(wxString &str_top_remarks, wxString str_low_remarks,wxString str_header)
{
     int  i_pos = str_top_remarks.find(str_header);

     if(i_pos !=wxNOT_FOUND);
     {

     }

     return false;

}

bool nstd_mat_apply::update_remarks(wxString str_remarks)
{
    wxString  str_sql = wxT("UPDATE l_nonstd_app_item SET modify_emp_id ='")+gr_para.login_user+wxT("',modify_date ='")+DateToAnsiStr(wxDateTime::Now())+wxT("', remarks = '")+
                           str_remarks+wxT("' where index_id = '")+m_index_id+wxT("';");
    if(wxGetApp().app_sql_update(str_sql))
    {
        wxLogMessage(m_batch_id+_("批次备注更新成功!"));
        return true;
    }

    return false;
}

int nstd_mat_apply::get_combined_remarks(wxString &str_remarks, wxString &str_no_finish)
{
     wxString str_sql = wxT("SELECT remarks,index_mat_id, res_engineer, (select name from s_employee where employee_id = res_engineer) as engineer_name, status, instance_remarks \
                           FROM v_nonstd_app_item_instance WHERE index_id = '")+ m_index_id+wxT("' AND status != '-1' ORDER BY index_mat_id ASC;");


     wxPostgreSQLresult* _res;
     _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return -1;
    }

    int i_count = _res->GetRowsNumber();

    _res->MoveFirst();

    str_remarks = _res->GetVal(wxT("remarks"));

    int i_confirm =0;
    wxString str_index_mat_id, str_name, str_ins_remarks;
    int i_status;
    int i_pos;
    bool b_find = true;

    for(int i=0;i<i_count;i++)
    {

        i_status = _res->GetInt(wxT("status"));

        str_index_mat_id = _res->GetVal(wxT("index_mat_id"));

        if(b_find)
        {
            i_pos = str_remarks.Find(str_index_mat_id);
        }

        if(i_pos!=wxNOT_FOUND &&b_find)
        {
            str_remarks = str_remarks.Left(i_pos-1);

            b_find = false;
        }

        str_ins_remarks = _res->GetVal(wxT("instance_remarks"));
        str_name = _res->GetVal(wxT("engineer_name"));

        if(i_status == 2)
        {

            if(!str_ins_remarks.Trim().IsEmpty())
            {

                str_name = wxT("[")+str_index_mat_id+wxT(" ")+str_name+wxT("]:");

                if(!str_remarks.Trim().IsEmpty())
                {
                    str_remarks = str_remarks.Trim()+wxT("\n")+str_name+str_ins_remarks+wxT("\n");
                }
                else
                {
                    str_remarks = str_remarks.Trim()+str_name+str_ins_remarks+wxT("\n");
                }
            }

            i_confirm++;
        }
        else if(i_status == 0 || i_status == 1)
        {
            str_no_finish = str_no_finish+str_index_mat_id+wxT("\n");
        }

        _res->MoveNext();

    }

    _res->Clear();

    if(i_confirm == i_count&& i_confirm!=0)
    {
        return 0;
    }else if(i_count==0)
        return -1;
    else return i_count-i_confirm;

}

void nstd_mat_apply::OnButton_Rel_UnitsClick(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_mat_list->GetSelectedRows();

    if(array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项次，无法后续操作!"));
        return;
    }

    if(prj_str_to_status(tc_low_status->GetValue()) ==2)
    {
        wxLogMessage(_("错误:非标申请单已经提交，无法修改!"));
        return;
    }


    int i_count = array_sel_line.GetCount();

    wxString str_units;

    nstd_app_item_units dlg;
    dlg.init_checklistbox(m_units, m_units, false);


    if(dlg.ShowModal() == wxID_OK)
    {
        str_units = dlg.m_units;
    }
    else
        return;

    for(int i=0; i<i_count ; i++)
    {
        nstdappTable * table = gd_mat_list->GetTable();

        cacheLine * line = table->GetLine(array_sel_line.Item(i));
        table->Set_Saved_Line(array_sel_line.Item(i));
        table->SetLastRow(array_sel_line.Item(i));
        line->cols[9] = str_units;

//            table->SetValue(array_sel_line.Item(i),10, str_units);
        //         gd_nonstd_list->SetCellValue(array_sel_line.Item(i),10);
        table->StoreLine();
    }

}

void nstd_mat_apply::OnButton_WorkflowClick(wxCommandEvent& event)
{

    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(m_index_id.IsEmpty())
    {
        wxLogMessage(_("请先选择非标任务!!"));
        return;
    }

    wxArrayString array_sel_workflow, array_sel_ins;
    wxString str;


    str = wf_str_nonstd;
    array_sel_workflow.Add(str);
    array_sel_ins.Add(m_index_id);

    ins_nonstd_proc_log ipl_dlg;

    ipl_dlg.Refresh_list_view(array_sel_ins, array_sel_workflow);
    ipl_dlg.ShowModal();
}

void nstd_mat_apply::OnButton_CleanClick(wxCommandEvent& event)
{
    wxString str_sql = wxT("SELECT index_mat_id from l_nonstd_app_item_instance");

     wxPostgreSQLresult* _res;
     _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int i_count = _res->GetRowsNumber();

    _res->MoveFirst();
    int i_mat=0;
    int i_draw=0;
    for(int i=0;i<i_count;i++)
    {
        wxString str_index_mat_id = _res->GetVal(wxT("index_mat_id"));
        int i_step;

        bool b_check = is_workflow_created(str_index_mat_id, wf_str_materials,i_step);

        str_sql = wxT("UPDATE l_nonstd_app_item_instance SET has_nonstd_mat=")+BoolToStr(b_check)+wxT(" where index_mat_id='")+str_index_mat_id+wxT("';");
        if(wxGetApp().app_sql_update(str_sql))
        {
            i_mat++;
            wxLogMessage(str_index_mat_id+_("非标物料判断更新成功!"));
        }

        b_check = is_workflow_created(str_index_mat_id, wf_str_design, i_step);
        str_sql = wxT("UPDATE l_nonstd_app_item_instance SET has_nonstd_draw=")+BoolToStr(b_check)+wxT(" where index_mat_id='")+str_index_mat_id+wxT("';");
        if(wxGetApp().app_sql_update(str_sql))
        {
            i_draw++;
            wxLogMessage(str_index_mat_id+_("非标设计判断更新成功!"));
        }

        _res->MoveNext();

    }

    _res->Clear();

    wxLogMessage(_("共计更新")+NumToStr(i_count)+_(",非标物料判断更新:")+NumToStr(i_mat)+_("非标设计判断更新:")+NumToStr(i_draw));

}

void nstd_mat_apply::Oncombo_nstd_item_catalogTextUpdated(wxCommandEvent& event)
{
    if(m_index_id.IsEmpty())
        return;

    wxString str_sql = wxT("UPDATE l_nonstd_app_item SET modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("', nonstd_catalog='")+combo_nstd_item_catalog->GetValue()+
                       wxT("' where index_id ='")+m_index_id+wxT("';");
    str_sql.Replace(wxT("''"),wxT("NULL"));
    wxGetApp().app_sql_update(str_sql);
}

void nstd_mat_apply::OnButton_Nonstd_Ins_DocClick(wxCommandEvent& event)
{

    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }

    if(m_units.IsEmpty())
    {
        wxLogMessage(_("无任何关联梯!"));
        return;
    }

    nstd_ins_doc dlg;

    dlg.init_units_list(m_units);

    dlg.ShowModal();
}


void nstd_mat_apply::OnButton_task_listClick(wxCommandEvent& event)
{
    int i_count;
    wxArrayString str_group = wxGetApp().get_group();
    wxArrayString a_team_members = wxGetApp().get_member_in_group(str_group);
    //wxArrayString a_team_members = wxGetApp().get_sub_eng_list(i_count, false);
    i_count = a_team_members.GetCount();

    if(i_count==0)
        return;

   int answer = wxMessageBox("按人员筛选(否-显示全部人员任务)", "确认", wxYES_NO | wxCANCEL);

   if(answer == wxCANCEL)
   {
       return;
   }

   wxString s_member;

    if(answer == wxYES)
    {
        wxSingleChoiceDialog cdlg(this, _("请选择人员:"),_("操作选择"),a_team_members);


        if(cdlg.ShowModal() == wxID_OK)
        {
        }
        else
        {
            return;
        }

        s_member = cdlg.GetStringSelection().Left(8);

        nstd_mat_muti_level_task_list dlg(2);

        combo_nstd_item_catalog->Enable(false);
        dlg.refresh_task_list(s_member);
        dlg.ShowModal();

    }


    if(answer == wxNO)
    {
        nstd_mat_muti_level_task_list dlg(2);

        combo_nstd_item_catalog->Enable(false);
        dlg.refresh_task_list(a_team_members);
        dlg.ShowModal();
    }


}
