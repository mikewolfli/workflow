#include "nstd_apply_panel.h"
#include "wfApp.h"
#include "add_nstd_app_item.h"
#include "nstd_app_search.h"
#include <wx/tokenzr.h>
#include "nstd_app_item_units.h"
#include "./utils/wf_operator.h"
#include "nstd_mat_task_list.h"
#include "ins_nonstd_proc_log.h"
#include <wx/textdlg.h>

//(*InternalHeaders(nstd_apply_panel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(nstd_apply_panel)
const long nstd_apply_panel::ID_BUTTON_GENERATE = wxNewId();
const long nstd_apply_panel::ID_BUTTON_SUBMIT = wxNewId();
const long nstd_apply_panel::ID_BUTTON_SEARCH = wxNewId();
const long nstd_apply_panel::ID_BUTTON_CLOSE = wxNewId();
const long nstd_apply_panel::ID_BUTTON_CANCEL = wxNewId();
const long nstd_apply_panel::ID_BUTTON_SAVE = wxNewId();
const long nstd_apply_panel::ID_BUTTON_PRINT = wxNewId();
const long nstd_apply_panel::ID_CHECKBOX_MECH = wxNewId();
const long nstd_apply_panel::ID_CHECKBOX_HIGHRISE = wxNewId();
const long nstd_apply_panel::ID_CHECKBOX_ELECT = wxNewId();
const long nstd_apply_panel::ID_TEXTCTRL_STATUS = wxNewId();
const long nstd_apply_panel::ID_BUTTON_BEGIN = wxNewId();
const long nstd_apply_panel::ID_BUTTON_PREVIOUS = wxNewId();
const long nstd_apply_panel::ID_BUTTON_NEXT = wxNewId();
const long nstd_apply_panel::ID_BUTTON_END = wxNewId();
const long nstd_apply_panel::ID_TEXTCTRL_STEP = wxNewId();
const long nstd_apply_panel::ID_STATICTEXT4 = wxNewId();
const long nstd_apply_panel::ID_TEXTCTRL1 = wxNewId();
const long nstd_apply_panel::ID_STATICTEXT2 = wxNewId();
const long nstd_apply_panel::ID_TEXTCTRL2 = wxNewId();
const long nstd_apply_panel::ID_STATICTEXT3 = wxNewId();
const long nstd_apply_panel::ID_TEXTCTRL3 = wxNewId();
const long nstd_apply_panel::ID_STATICTEXT5 = wxNewId();
const long nstd_apply_panel::ID_DATEPICKERCTRL1 = wxNewId();
const long nstd_apply_panel::ID_STATICTEXT7 = wxNewId();
const long nstd_apply_panel::ID_DATEPICKERCTRL_DRAW_REQ = wxNewId();
const long nstd_apply_panel::ID_TEXTCTRL_DESC = wxNewId();
const long nstd_apply_panel::ID_GRID_UNITS = wxNewId();
const long nstd_apply_panel::ID_GRID_NONSTD_LIST = wxNewId();
const long nstd_apply_panel::ID_BUTTON_ADD = wxNewId();
const long nstd_apply_panel::ID_BUTTON_DEL = wxNewId();
const long nstd_apply_panel::ID_BUTTON_REVISE = wxNewId();
const long nstd_apply_panel::ID_BUTTON_UNITS = wxNewId();
const long nstd_apply_panel::ID_TEXTCTRL_QTY = wxNewId();
const long nstd_apply_panel::ID_BUTTON_SHOW_MAT = wxNewId();
const long nstd_apply_panel::ID_BUTTON_WORKFLOW = wxNewId();
const long nstd_apply_panel::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(nstd_apply_panel,wxPanel)
    //(*EventTable(nstd_apply_panel)
    //*)
END_EVENT_TABLE()

nstd_apply_panel::nstd_apply_panel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(nstd_apply_panel)
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* bs_nonstd;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer7;
    wxGridBagSizer* GridBagSizer1;
    wxStaticBoxSizer* sbs_nonstd;
    wxBoxSizer* BoxSizer2;
    wxStaticBoxSizer* sbs_status;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxBoxSizer* BoxSizer3;
    wxStaticBoxSizer* sbs_project;

    Create(parent, wxID_ANY, wxDefaultPosition, wxSize(801,1159), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    Button_Generate = new wxButton(this, ID_BUTTON_GENERATE, _("生成非标申请"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_GENERATE"));
    BoxSizer3->Add(Button_Generate, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Button_Submit = new wxButton(this, ID_BUTTON_SUBMIT, _("提交非标申请"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_SUBMIT"));
    BoxSizer3->Add(Button_Submit, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Button_Search = new wxButton(this, ID_BUTTON_SEARCH, _("非标申请查询"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_SEARCH"));
    BoxSizer3->Add(Button_Search, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Button_Close = new wxButton(this, ID_BUTTON_CLOSE, _("配置信息收到确认"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CLOSE"));
    BoxSizer3->Add(Button_Close, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Button_Cancel = new wxButton(this, ID_BUTTON_CANCEL, _("取消非标申请"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CANCEL"));
    BoxSizer3->Add(Button_Cancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Button_Save = new wxButton(this, ID_BUTTON_SAVE, _("恢复非标申请"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_SAVE"));
    BoxSizer3->Add(Button_Save, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Button_Print = new wxButton(this, ID_BUTTON_PRINT, _("打印非标申请"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_PRINT"));
    BoxSizer3->Add(Button_Print, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer1->Add(BoxSizer3, 1, wxALL|wxEXPAND, 0);
    sbs_status = new wxStaticBoxSizer(wxHORIZONTAL, this, _("非标申请"));
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    cb_mech = new wxCheckBox(this, ID_CHECKBOX_MECH, _("机械组"), wxDefaultPosition, wxSize(79,12), 0, wxDefaultValidator, _T("ID_CHECKBOX_MECH"));
    cb_mech->SetValue(true);
    BoxSizer2->Add(cb_mech, 1, wxALL|wxALIGN_CENTER_VERTICAL, 0);
    cb_highrise = new wxCheckBox(this, ID_CHECKBOX_HIGHRISE, _("高速梯组"), wxDefaultPosition, wxSize(98,13), 0, wxDefaultValidator, _T("ID_CHECKBOX_HIGHRISE"));
    cb_highrise->SetValue(false);
    BoxSizer2->Add(cb_highrise, 1, wxALL|wxALIGN_CENTER_VERTICAL, 0);
    cb_elect = new wxCheckBox(this, ID_CHECKBOX_ELECT, _("电气组"), wxDefaultPosition, wxSize(83,13), 0, wxDefaultValidator, _T("ID_CHECKBOX_ELECT"));
    cb_elect->SetValue(true);
    BoxSizer2->Add(cb_elect, 1, wxALL|wxALIGN_CENTER_VERTICAL, 0);
    sbs_status->Add(BoxSizer2, 1, wxALL|wxEXPAND, 0);
    tc_status = new wxTextCtrl(this, ID_TEXTCTRL_STATUS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL_STATUS"));
    sbs_status->Add(tc_status, 1, wxALL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    button_begin = new wxButton(this, ID_BUTTON_BEGIN, _("<<--"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_BEGIN"));
    BoxSizer4->Add(button_begin, 1, wxALL|wxALIGN_CENTER_VERTICAL, 0);
    button_previous = new wxButton(this, ID_BUTTON_PREVIOUS, _("<-"), wxDefaultPosition, wxSize(60,23), 0, wxDefaultValidator, _T("ID_BUTTON_PREVIOUS"));
    BoxSizer4->Add(button_previous, 1, wxALL|wxALIGN_CENTER_VERTICAL, 0);
    button_next = new wxButton(this, ID_BUTTON_NEXT, _("->"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_NEXT"));
    BoxSizer4->Add(button_next, 1, wxALL|wxALIGN_CENTER_VERTICAL, 0);
    button_end = new wxButton(this, ID_BUTTON_END, _("-->>"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_END"));
    BoxSizer4->Add(button_end, 1, wxALL|wxALIGN_CENTER_VERTICAL, 0);
    sbs_status->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_VERTICAL, 0);
    tc_step = new wxTextCtrl(this, ID_TEXTCTRL_STEP, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL_STEP"));
    tc_step->SetMaxLength(200);
    sbs_status->Add(tc_step, 1, wxALL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer1->Add(sbs_status, 1, wxALL|wxEXPAND, 0);
    sbs_project = new wxStaticBoxSizer(wxVERTICAL, this, _("项目信息"));
    GridBagSizer1 = new wxGridBagSizer(0, 0);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("非标申请编号"), wxDefaultPosition, wxSize(82,13), 0, _T("ID_STATICTEXT4"));
    GridBagSizer1->Add(StaticText4, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    tc_nstd_id = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(97,21), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    GridBagSizer1->Add(tc_nstd_id, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("项目编号"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    GridBagSizer1->Add(StaticText2, wxGBPosition(0, 1), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    tc_project_id = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(104,21), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    GridBagSizer1->Add(tc_project_id, wxGBPosition(1, 1), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("项目名称"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    GridBagSizer1->Add(StaticText3, wxGBPosition(0, 2), wxDefaultSpan, wxALL|wxEXPAND, 5);
    tc_project_name = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(325,21), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    GridBagSizer1->Add(tc_project_name, wxGBPosition(1, 2), wxGBSpan(1, 2), wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("物料需求日"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    GridBagSizer1->Add(StaticText5, wxGBPosition(0, 4), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    dp_matreq = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL1, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL1"));
    GridBagSizer1->Add(dp_matreq, wxGBPosition(1, 4), wxDefaultSpan, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 0);
    StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("图纸需求日"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    GridBagSizer1->Add(StaticText7, wxGBPosition(0, 5), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    dp_draw_req = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL_DRAW_REQ, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL_DRAW_REQ"));
    GridBagSizer1->Add(dp_draw_req, wxGBPosition(1, 5), wxDefaultSpan, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 0);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("备注"));
    tc_nstd_desc = new wxTextCtrl(this, ID_TEXTCTRL_DESC, wxEmptyString, wxDefaultPosition, wxSize(277,34), wxTE_PROCESS_ENTER|wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL_DESC"));
    StaticBoxSizer1->Add(tc_nstd_desc, 1, wxALL|wxEXPAND, 0);
    GridBagSizer1->Add(StaticBoxSizer1, wxGBPosition(0, 7), wxGBSpan(2, 2), wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    sbs_project->Add(GridBagSizer1, 1, wxALL|wxEXPAND, 0);
    BoxSizer1->Add(sbs_project, 1, wxALL|wxEXPAND, 0);
    BoxSizer7 = new wxBoxSizer(wxVERTICAL);
    gd_unit_list = new sqlResultGrid(this, ID_GRID_UNITS, wxDefaultPosition, wxSize(-1,130));
    BoxSizer7->Add(gd_unit_list, 1, wxALL|wxEXPAND, 0);
    sbs_nonstd = new wxStaticBoxSizer(wxHORIZONTAL, this, _("非标信息"));
    bs_nonstd = new wxBoxSizer(wxHORIZONTAL);
    gd_nonstd_list = new nstdappGrid(this, ID_GRID_NONSTD_LIST, wxDefaultPosition, wxSize(800,-1));
    bs_nonstd->Add(gd_nonstd_list, 1, wxALL|wxEXPAND, 0);
    sbs_nonstd->Add(bs_nonstd, 10, wxALL|wxEXPAND, 0);
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    Button1 = new wxButton(this, ID_BUTTON_ADD, _("+"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER, wxDefaultValidator, _T("ID_BUTTON_ADD"));
    BoxSizer5->Add(Button1, 1, wxALL|wxEXPAND, 0);
    Button2 = new wxButton(this, ID_BUTTON_DEL, _("-"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER, wxDefaultValidator, _T("ID_BUTTON_DEL"));
    BoxSizer5->Add(Button2, 1, wxALL|wxEXPAND, 0);
    Button_REVISE = new wxButton(this, ID_BUTTON_REVISE, _("修改非标信息"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_REVISE"));
    BoxSizer5->Add(Button_REVISE, 1, wxALL|wxEXPAND, 0);
    Button_Units = new wxButton(this, ID_BUTTON_UNITS, _("更改关联梯"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_UNITS"));
    BoxSizer5->Add(Button_Units, 1, wxALL|wxEXPAND, 0);
    tc_qty = new wxTextCtrl(this, ID_TEXTCTRL_QTY, _("1"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL_QTY"));
    BoxSizer5->Add(tc_qty, 1, wxALL|wxEXPAND, 0);
    Button_Show_Mat = new wxButton(this, ID_BUTTON_SHOW_MAT, _("显示非标物料配置清单"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_SHOW_MAT"));
    BoxSizer5->Add(Button_Show_Mat, 1, wxALL|wxEXPAND, 0);
    Button_WORKFLOW = new wxButton(this, ID_BUTTON_WORKFLOW, _("显示工作流"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_WORKFLOW"));
    BoxSizer5->Add(Button_WORKFLOW, 1, wxALL|wxEXPAND, 0);
    Button3 = new wxButton(this, ID_BUTTON1, _("已经关闭申请\n激活退回"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer5->Add(Button3, 1, wxALL|wxEXPAND, 0);
    sbs_nonstd->Add(BoxSizer5, 1, wxALL|wxALIGN_TOP, 0);
    BoxSizer7->Add(sbs_nonstd, 3, wxALL|wxEXPAND, 0);
    BoxSizer1->Add(BoxSizer7, 5, wxALL|wxEXPAND, 0);
    SetSizer(BoxSizer1);
    SetSizer(BoxSizer1);
    Layout();

    Connect(ID_BUTTON_GENERATE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_apply_panel::OnButton_GenerateClick);
    Connect(ID_BUTTON_SUBMIT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_apply_panel::OnButton_SubmitClick);
    Connect(ID_BUTTON_SEARCH,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_apply_panel::OnButton_SearchClick);
    Connect(ID_BUTTON_CLOSE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_apply_panel::OnButton_CloseClick);
    Connect(ID_BUTTON_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_apply_panel::OnButton_CancelClick);
    Connect(ID_BUTTON_SAVE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_apply_panel::OnButton_SaveClick);
    Connect(ID_CHECKBOX_MECH,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&nstd_apply_panel::Oncb_mechClick);
    Connect(ID_CHECKBOX_HIGHRISE,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&nstd_apply_panel::Oncb_highriseClick);
    Connect(ID_CHECKBOX_ELECT,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&nstd_apply_panel::Oncb_electClick);
    Connect(ID_BUTTON_BEGIN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_apply_panel::Onbutton_beginClick);
    Connect(ID_BUTTON_PREVIOUS,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_apply_panel::Onbutton_previousClick);
    Connect(ID_BUTTON_NEXT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_apply_panel::Onbutton_nextClick);
    Connect(ID_BUTTON_END,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_apply_panel::Onbutton_endClick);
    Connect(ID_DATEPICKERCTRL1,wxEVT_DATE_CHANGED,(wxObjectEventFunction)&nstd_apply_panel::Ondp_matreqChanged);
    Connect(ID_DATEPICKERCTRL_DRAW_REQ,wxEVT_DATE_CHANGED,(wxObjectEventFunction)&nstd_apply_panel::Ondp_draw_reqChanged);
    Connect(ID_TEXTCTRL_DESC,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&nstd_apply_panel::Ontc_nstd_descText);
    Connect(ID_GRID_NONSTD_LIST,wxEVT_GRID_SELECT_CELL,(wxObjectEventFunction)&nstd_apply_panel::Ongd_nonstd_listCellChange);
    Connect(ID_BUTTON_ADD,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_apply_panel::OnButton1Click);
    Connect(ID_BUTTON_DEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_apply_panel::OnButton2Click);
    Connect(ID_BUTTON_REVISE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_apply_panel::OnButton_REVISEClick);
    Connect(ID_BUTTON_UNITS,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_apply_panel::OnButton_UnitsClick);
    Connect(ID_BUTTON_SHOW_MAT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_apply_panel::OnButton_Show_MatClick);
    Connect(ID_BUTTON_WORKFLOW,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_apply_panel::OnButton_WORKFLOWClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&nstd_apply_panel::OnButton3Click);
    //*)

    init_list_header();
    show_control(false);
    m_flow_mask = wxT("101");
    mask_to_check();
    gd_nonstd_list->EnableEditing(false);
}

nstd_apply_panel::~nstd_apply_panel()
{
    //(*Destroy(nstd_apply_panel)
    //*)
}

void nstd_apply_panel::init_list_header()
{
    //Unit List
    gd_unit_list->CreateGrid(0,15);
    gd_unit_list->SetRowLabelSize(30);
    gd_unit_list->SetColLabelValue(0,_("Unit WBS NO."));
    gd_unit_list->SetColSize(0,100);

    gd_unit_list->SetColLabelValue(1,_("梯型编号"));
    gd_unit_list->SetColSize(1,80);

    gd_unit_list->SetColLabelValue(2,_("梯型"));
    gd_unit_list->SetColSize(2,80);

    gd_unit_list->SetColLabelValue(3,_("项目名称"));
    gd_unit_list->SetColSize(3,200);

    gd_unit_list->SetColLabelValue(4,_("梯号"));
    gd_unit_list->SetColSize(4,50);

    gd_unit_list->SetColLabelValue(5,_("Unit状态"));
    gd_unit_list->SetColSize(5,60);

    gd_unit_list->SetColLabelValue(6,_("Unit\n流程状态"));
    gd_unit_list->SetColSize(6,60);

    gd_unit_list->SetColLabelValue(7,_("是否紧急"));
    gd_unit_list->SetColSize(7,60);

    gd_unit_list->SetColLabelValue(8,_("项目类别"));
    gd_unit_list->SetColSize(8,100);

    gd_unit_list->SetColLabelValue(9,_("非标\n等级"));
    gd_unit_list->SetColSize(9,80);

    gd_unit_list->SetColLabelValue(10,_("发货期"));
    gd_unit_list->SetColSize(10,80);

    gd_unit_list->SetColLabelValue(11,_("配置完成日期"));
    gd_unit_list->SetColSize(11,80);

     gd_unit_list->SetColLabelValue(12,_("特殊标识"));
    gd_unit_list->SetColSize(12,100);

    gd_unit_list->SetColLabelValue(13,_("版本ID"));
    gd_unit_list->SetColSize(13,80);

    gd_unit_list->SetColLabelValue(14,_("备注"));
    gd_unit_list->SetColSize(14,80);

    for(int i=0; i<15; i++)
    {
        str_unit_header = str_unit_header+gd_unit_list->GetColLabelValue(i)+wxT(";");
    }

    //nonstd item list;
    gd_nonstd_list->CreateGrid(0, 11);
    gd_nonstd_list->SetRowLabelSize(30);

    gd_nonstd_list->SetColLabelValue(0,_("index_no"));
    gd_nonstd_list->SetColSize(0,0);

    gd_nonstd_list->SetColLabelValue(1,_("非标申请编号"));
    gd_nonstd_list->SetColSize(1,0);

    gd_nonstd_list->SetColLabelValue(2,_("Item No"));
    gd_nonstd_list->SetColSize(2,0);

    gd_nonstd_list->SetColLabelValue(3,_("电气/机械"));
    gd_nonstd_list->SetColSize(3,80);

    gd_nonstd_list->SetColLabelValue(4,_("非标类别"));
    gd_nonstd_list->SetColSize(4,100);

    gd_nonstd_list->SetColLabelValue(5, _("非标原因"));
    gd_nonstd_list->SetColSize(5, 200);

    gd_nonstd_list->SetColLabelValue(6, _("状态"));
    gd_nonstd_list->SetColSize(6,50);

    gd_nonstd_list->SetColLabelValue(7, _("流程状态"));
    gd_nonstd_list->SetColSize(7, 100);

    gd_nonstd_list->SetColLabelValue(8,_("备注"));
    gd_nonstd_list->SetColSize(8, 200);

    gd_nonstd_list->SetColLabelValue(9,_("非标工程师"));
    gd_nonstd_list->SetColSize(9, 100);

    gd_nonstd_list->SetColLabelValue(10,_("units"));
    gd_nonstd_list->SetColSize(10, 0);
    for(int i=0; i<11; i++)
    {
        str_nonstd_header = str_nonstd_header +gd_nonstd_list->GetColLabelValue(i)+wxT(";");
    }

    gd_unit_list->Fit();
    gd_nonstd_list->Fit();

    Layout();
}

void nstd_apply_panel::OnButton_GenerateClick(wxCommandEvent& event)
{
    wxString _choice[2]=
    {
        _("流程中的项目"),
        _("已经完成的项目"),
    };
    wxSingleChoiceDialog cdlg(this, _("选择负责的项目，已生成非标申请："),_("项目选择"),2, _choice);

    bool b_active;

    if(cdlg.ShowModal() == wxID_OK)
    {
        if(cdlg.GetSelection()== 0)
            b_active = true;
        else b_active = false;
    }
    else
        return;

    nstd_app_unit_list dlg_task;
    array_units.Clear();

    dlg_task.b_active = b_active;

    if(!b_active)
    {
        wxTextEntryDialog tdlg(this,_("请输入WBS NO(支持模糊)"),_("WBS NO"),wxT(""),wxOK | wxCANCEL);

        tdlg.SetTextValidator(wxFILTER_EMPTY );

        if(tdlg.ShowModal() == wxID_OK)
        {
            dlg_task.m_str_unit = tdlg.GetValue();
        }
        else
            return;

        wxTextEntryDialog tdlg1(this,_("请输入生成申请的原因(相应的单号)"),_("申请原因"),wxT(""),wxOK | wxCANCEL);

        tdlg1.SetTextValidator(wxFILTER_EMPTY );

        if(tdlg1.ShowModal() == wxID_OK)
        {
            tc_nstd_desc->SetValue(tdlg1.GetValue());
            wxGetApp().update_data_in_database(wxT("nonstd_desc"),tc_nstd_desc->GetValue(),wxT("l_nonstd_app_header"), wxT("nonstd_id"),nstd_app_id);

        }
        else
            return;
    }

    dlg_task.refresh_list();

    if(dlg_task.ShowModal() == wxID_CANCEL)
    {
        return;
    }

    bool b_create;

    array_units = dlg_task.array_select;
    wxString l_link_list = get_link_wbs(array_units);

    wxString str_sql = wxT("SELECT nonstd_id FROM l_nonstd_app_header where link_list like '%")+l_link_list+wxT("%' AND create_emp_id ='")+gr_para.login_user +wxT("';");


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

    if(b_create)
    {

        m_flow_mask = wxT("101");
        mask_to_check();

        tc_project_id->SetValue(array_units.Item(0).Left(10));
        tc_project_name->SetValue(dlg_task.m_proj);
        dp_matreq->SetValue(wxDateTime::Today()+wxDateSpan(0,0,0,2));

        dp_draw_req->SetValue(dlg_task.m_req_finish);

        tc_nstd_desc->Clear();

        refresh_unit_list(array_units);

        wxString str_serial_id = wxGetApp().get_ser_id(wxT("l_nonstd_app_header"), wxT("nonstd_id"));
        tc_nstd_id->SetValue(str_serial_id);
        tc_status->SetValue(wxT("CRTD"));
        nstd_app_id = tc_nstd_id->GetValue();

        save_header();

        refresh_list();

        array_search_result.Clear();
        show_control(false);
        enable_control(true);
        Layout();
    }
    else
    {
        _res->MoveFirst();
        for(int i=0; i<i_count; i++)
        {
            array_search_result.Add(_res->GetVal(wxT("nonstd_id")));
            _res->MoveNext();
        }

        _res->Clear();

        wxString str_step = wxT("1/")+ NumToStr(i_count);

        tc_step->SetValue(str_step);

        nstd_app_id = array_search_result.Item(0);

        refresh_gui();
        refresh_list();
        refresh_unit_list(array_units);
        Layout();
    }
}

void nstd_apply_panel::refresh_unit_list(wxArrayString &array_unit)
{

    int i_count = array_unit.GetCount();
    wxString str_clause;

    for(int i=0; i<i_count; i++)
    {

        if(i == 0)
            str_clause = wxT(" WHERE wbs_no ='")+array_unit.Item(i).Left(14)+wxT("' ");
        else
            str_clause = str_clause + wxT("OR  wbs_no = '")+array_unit.Item(i).Left(14)+wxT("' ");

    }

    wxPostgreSQLresult* _res;

    wxString str_query = wxT("SELECT wbs_no, elevator_id, elevator_type, project_name, lift_no, status, wf_status, \
                is_urgent, project_catalog, nonstd_level, req_delivery_date, req_configure_finish, special_info, \
                version_id, (select doc_desc from s_doc where doc_id = unit_doc_id) as doc_desc FROM v_unit_info ") + str_clause +wxT(" ORDER BY wbs_no ASC; ");

    _res = wxGetApp().app_sql_select(str_query);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    gd_unit_list->ClearGrid();

//    gd_unit_list->BeginBatch();
    wxGridUpdateLocker locker(gd_unit_list);
    wxString str_table= wxT("s_unit_info");
    gd_unit_list->SetTable(new sqlResultTable(_res, str_table, str_unit_header,0), true);

    gd_unit_list->Fit();
//   gd_unit_list->EndBatch();
    gd_unit_list->SetColSize(13, 300);
    Layout();


    _res->Clear();

}


void nstd_apply_panel::OnButton_SaveClick(wxCommandEvent& event)
{
    if(nstd_str_to_status(tc_status->GetValue())> 0)
    {
        if(wxMessageBox(_("非标申请单已经提交，无法修改!"),_("错误"),wxOK)==wxOK)
            wxLogMessage(_("错误:非标申请单已经提交，无法修改!"));
        return;
    }

    if(nstd_str_to_status(tc_status->GetValue())==-1)
    {
        if(wxMessageBox(_("非标申请单已经删除，确认恢复!"),_("恢复"),wxYES_NO)==wxNO)
            return;

        wxString str_sql = wxT("UPDATE l_nonstd_app_header SET status= '0' WHERE nonstd_id='")+tc_nstd_id->GetValue()+wxT("';");
        if(wxGetApp().app_sql_update(str_sql))
        {
            wxLogMessage(_("非标申请单:")+tc_nstd_id->GetValue()+_("恢复成功!"));

            tc_status->SetValue(_("CRTD"));
            enable_control(true);
        }

    }
    /*
        if(nstd_str_to_status(tc_status->GetValue())== 0)
        {
            wxString str_mat_req_date = DateToStrFormat(dp_matreq->GetValue())+ wxT(" 23:00:00");
            wxString str_draw_req_date = DateToStrFormat(dp_draw_req->GetValue())+ wxT(" 23:00:00");
            wxString str_nstd_desc = tc_nstd_desc->GetValue();

            wxString str_sql = wxT("UPDATE l_nonstd_app_header SET mat_req_date='")+str_mat_req_date+wxT("', drawing_req_date='")+
                               str_draw_req_date+wxT("', nonstd_desc='")+str_nstd_desc+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+
                               wxT("', modify_emp_id='")+gr_para.login_user+wxT("', flow_mask='")+m_flow_mask+wxT("' WHERE nonstd_id='")
                               +tc_nstd_id->GetValue()+wxT("';");


            str_sql.Replace(wxT("''"),wxT("NULL"));
            if(wxGetApp().app_sql_update(str_sql))
            {
                wxLogMessage(_("非标申请:")+tc_nstd_id->GetValue()+_("保存成功!"));
            }
        }
    */
}

void nstd_apply_panel::OnButton_CancelClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(gd_nonstd_list->GetNumberRows() > 0)
    {
        if(wxMessageBox(_("请先删除列表非标条目,否则无法取消此申请!"),_("错误"),wxOK)==wxOK)
            wxLogMessage(_("请先删除列表非标条目,否则无法取消此申请!"));
        return;
    }

    if(wxMessageBox(_("确定取消此非标申请单?"), _("取消"), wxYES_NO)== wxNO)
        return;

    nstdappTable * table = gd_nonstd_list->GetTable();
    if(table)
    {
        int i_count = gd_nonstd_list->GetNumberRows();
        if(i_count >0)
            table->DeleteRows(0, i_count);
    }

    wxString str_sql = wxT("UPDATE l_nonstd_app_header SET status= '-1' WHERE nonstd_id='")+tc_nstd_id->GetValue()+wxT("';");
    if(wxGetApp().app_sql_update(str_sql))
    {
        wxLogMessage(_("非标申请单:")+tc_nstd_id->GetValue()+_("取消成功!"));

        tc_status->SetValue(_("DEL"));
        enable_control(false);
    }
}

void nstd_apply_panel::OnButton_SubmitClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(nstd_app_id.IsEmpty())
    {
        if(wxMessageBox(_("请先选择非标申请单后提交申请!"),_("错误"),wxOK)==wxOK)
            wxLogMessage(_("错误:尚未选择非标申请单，无法提交!"));
        return;
    }

    if(nstd_str_to_status(tc_status->GetValue()) != 0)
    {
        if(wxMessageBox(_("非标申请单已经提交或者已经删除，无法提交!"),_("错误"),wxOK)==wxOK)
            wxLogMessage(_("错误:非标申请单已经提交或者已经删除，无法提交!"));
        return;
    }

    int i_count = gd_nonstd_list->GetNumberRows();
    if(i_count ==0)
    {
        if(wxMessageBox(_("请先添加非标项次，目前无法提交!"),_("提示"),wxOK)==wxOK)
            wxLogMessage(_("提示:请先添加非标项次，目前无法提交!"));
        return;
    }

    wxString err_message;

    if(!check_grid_input_valid(err_message))
    {
        if(wxMessageBox(err_message,_("错误"),wxOK)==wxOK)
            wxLogMessage(err_message);
        return;
    }


    if(wxMessageBox(_("确认提交非标申请?"),_("提交确认："),wxOK|wxCANCEL,this)==wxCANCEL)
    {
        return;
    }

    v_wf_action * t_template = get_template_action(wf_str_nonstd);
    wf_operator * wf_nstd_app=0;
    wxString str_instance;
    wxLongLong mils_used, start_mils;

    for(int i=0; i<i_count; i++)
    {
        str_instance = gd_nonstd_list->GetCellValue(i,0);

        int i_step;
        if(is_workflow_created(str_instance,  wf_str_nonstd,i_step))
        {
            wxLogMessage(str_instance+_("工作流已经创建过了，退回的工作流，请到非标工作流界面操作"));
            return;

        }

        start_mils = wxGetLocalTimeMillis();

        wf_nstd_app = new wf_operator(str_instance, wf_str_nonstd, t_template);
        wf_nstd_app->start_proc(wxEmptyString, true , false);
        wf_nstd_app->update_instance_one2several(1);
        if(i==i_count -1)
        {

            if(wf_nstd_app->update_header_status(1, nstd_app_id, wxT("nonstd_id"), wxT("l_nonstd_app_header")))
                tc_status->SetValue(wxT("SUBMIT"));
        }

        if(wf_nstd_app)
            delete wf_nstd_app;

        mils_used = wxGetLocalTimeMillis() - start_mils;

        wxLogMessage(str_instance+_("非标申请流程创建成功!  耗时:")+NumToStr(mils_used)+_("毫秒"));

    }

    if(t_template)
        delete [] t_template;


    refresh_list();
    enable_control(false);

}

bool nstd_apply_panel::check_grid_input_valid(wxString &error_message)
{
    int i_count = gd_nonstd_list->GetNumberRows();
    wxString str;

    for(int i=0;i<i_count;i++)
    {
        str = gd_nonstd_list->GetCellValue(i, 3).Upper();

        if(str == wxT("E") && m_flow_mask.Right(1) !=wxT("1"))
        {
            error_message = _("列表中出现电气非标，请在非标申请中将电气勾选!");
            return false;
        }

        if(str == wxT("M")&& m_flow_mask.Left(2)!=wxT("10")&&m_flow_mask.Left(2)!=wxT("01"))
        {
            error_message = _("列表中出现机械非标，请在非标申请中将机械或者高速梯勾选!");
            return false;
        }

    }

    return true;
}

bool nstd_apply_panel::check_owner_nstd(wxString s_id)
{
    wxString s_sql = wxT(" select create_emp_id from v_nonstd_app_header where nonstd_id ='")+s_id+wxT("';");
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(s_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return false;
    }

    int i_count = _res->GetRowsNumber();

    if(i_count ==0)
    {
        _res->Clear();
        return false;
    }

    wxString str = _res->GetVal(wxT("create_emp_id"));
    _res->Clear();

    if(str==gr_para.login_user)
        return true;
    else
        return false;

}

void nstd_apply_panel::OnButton_SearchClick(wxCommandEvent& event)
{
    array_search_result.Clear();
    nstd_app_search dlg;
    int i_choice;
    wxString str_search;
    if(dlg.ShowModal() == wxID_OK)
    {
        i_choice = dlg.i_choice;
        str_search = dlg.str_search;
    }
    else return;

    wxString str_sql;
    switch(i_choice)
    {
    case 0:
        str_sql = wxT("SELECT nonstd_id FROM l_nonstd_app_header where status = '0' and create_emp_id ='")+gr_para.login_user+wxT("' order by nonstd_id ASC;");
        break;
    case 1:
        str_sql = wxT("SELECT nonstd_id FROM l_nonstd_app_header where (status between '1' and '8') and create_emp_id ='")+gr_para.login_user+wxT("' order by nonstd_id ASC;");
        break;
    case 2:
        str_sql = wxT("SELECT nonstd_id FROM l_nonstd_app_header where status ='10' and create_emp_id ='")+gr_para.login_user+wxT("' order by nonstd_id ASC;");
        break;
    case 3:
        //str_sql = wxT("SELECT nonstd_id FROM l_nonstd_app_header where nonstd_id like '%")+str_search+wxT("%' and create_emp_id ='")+gr_para.login_user+wxT("' order by nonstd_id ASC;");
        str_sql = wxT("SELECT nonstd_id FROM l_nonstd_app_header where nonstd_id like '%")+str_search+wxT("%' order by nonstd_id ASC;");

        break;
    case  4:
        //str_sql = wxT("SELECT nonstd_id FROM l_nonstd_app_header where project_id like '%")+str_search+wxT("%' and create_emp_id ='")+gr_para.login_user+wxT("' order by nonstd_id ASC;");
        str_sql = wxT("SELECT nonstd_id FROM l_nonstd_app_header where project_id like '%")+str_search+wxT("%'  order by nonstd_id ASC;");
        break;
    case 5:
        //str_sql = wxT("SELECT nonstd_id FROM v_nonstd_app_header where project_name like '%")+str_search+wxT("%' and create_emp_id ='")+gr_para.login_user+wxT("' order by nonstd_id ASC;");
        str_sql = wxT("SELECT nonstd_id FROM v_nonstd_app_header where project_name like '%")+str_search+wxT("%' order by nonstd_id ASC;");
        break;
    case 6:
        //str_sql = wxT("SELECT nonstd_id FROM v_nonstd_app_header where contract_id = '")+str_search+wxT("' and create_emp_id ='")+gr_para.login_user+wxT("' order by nonstd_id ASC;");
        str_sql = wxT("SELECT nonstd_id FROM v_nonstd_app_header where contract_id = '")+str_search+wxT("'  order by nonstd_id ASC;");
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


    if(i_count >1)
    {
        show_control(true);
    }
    else show_control(false);

    _res->MoveFirst();
    for(int i=0; i<i_count; i++)
    {
        array_search_result.Add(_res->GetVal(wxT("nonstd_id")));
        _res->MoveNext();
    }

    _res->Clear();

    wxString str_step = wxT("1/")+ NumToStr(i_count);

    tc_step->SetValue(str_step);

    nstd_app_id = array_search_result.Item(0);

    refresh_gui();
    refresh_list();
    refresh_unit_list(array_units);
    Layout();
}

void nstd_apply_panel::refresh_gui()
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
    wxString str_sql = wxT("SELECT * FROM v_nonstd_app_header WHERE nonstd_id = '")+ nstd_app_id+wxT("';");

    wxPostgreSQLresult* _res;
    _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    tc_nstd_id->SetValue(nstd_app_id);
    m_flow_mask = _res->GetVal(wxT("flow_mask"));
    mask_to_check();

    wxString str_units = _res->GetVal(wxT("link_list"));
    array_units.Clear();
    array_units = wxStringTokenize(str_units ,wxT(";"), wxTOKEN_DEFAULT  );


    wxString s_project_name = _res->GetVal(wxT("contract_id"))+wxT(" ")+_res->GetVal(wxT("project_name"));
    tc_project_id->SetValue(_res->GetVal(wxT("project_id")));
    tc_project_name->SetValue(s_project_name);
    dp_matreq->SetValue(_res->GetDate(wxT("mat_req_date")));
    dp_draw_req->SetValue(_res->GetDate(wxT("drawing_req_date")));

    int i_status = _res->GetInt(wxT("status"));

    tc_status->SetValue(nstd_status_to_str(i_status));

    tc_nstd_desc->SetValue(_res->GetVal(wxT("nonstd_desc")));

    _res->Clear();

    if(i_status !=0)
    {
        enable_control(false);
    }
    else enable_control(true);
}

void nstd_apply_panel::Oncb_mechClick(wxCommandEvent& event)
{
    /*   if(!event.IsChecked())
       {
           cb_mech->SetValue(true);
           return;
       }*/

    if(cb_mech->IsChecked())
        cb_highrise->SetValue(false);

    m_flow_mask.SetChar(0, booltoch(cb_mech->IsChecked()));
    m_flow_mask.SetChar(1, booltoch(cb_highrise->IsChecked()));

    if(nstd_app_id.IsEmpty())
        return;

    wxGetApp().update_data_in_database(wxT("flow_mask"),m_flow_mask,wxT("l_nonstd_app_header"), wxT("nonstd_id"),nstd_app_id);
}

void nstd_apply_panel::Oncb_highriseClick(wxCommandEvent& event)
{
    /*   if(!event.IsChecked())
       {
          cb_highrise->SetValue(true);

          return;
       }*/

    if(cb_highrise->IsChecked())
        cb_mech->SetValue(false);

    m_flow_mask.SetChar(0, booltoch(cb_mech->IsChecked()));
    m_flow_mask.SetChar(1, booltoch(cb_highrise->IsChecked()));

    if(nstd_app_id.IsEmpty())
        return;

    wxGetApp().update_data_in_database(wxT("flow_mask"),m_flow_mask,wxT("l_nonstd_app_header"), wxT("nonstd_id"),nstd_app_id);
}

void nstd_apply_panel::Oncb_electClick(wxCommandEvent& event)
{
    m_flow_mask.SetChar(2, booltoch(cb_elect->IsChecked()));


    if(nstd_app_id.IsEmpty())
        return;


    wxGetApp().update_data_in_database(wxT("flow_mask"),m_flow_mask,wxT("l_nonstd_app_header"), wxT("nonstd_id"),nstd_app_id);
}

void nstd_apply_panel::show_control(bool b_show)
{
    button_begin->Show(b_show);
    button_previous->Show(b_show);
    button_next->Show(b_show);
    button_end->Show(b_show);
    tc_step->Show(b_show);

}

void nstd_apply_panel::enable_control(bool b_edit)
{
    cb_elect->Enable(b_edit);
    cb_mech->Enable(b_edit);
    cb_highrise->Enable(b_edit);
    dp_draw_req->Enable(b_edit);
    tc_nstd_desc->Enable(b_edit);
    gd_nonstd_list->EnableEditing(b_edit);
    tc_qty->Enable(b_edit);
}

void nstd_apply_panel::save_header()
{
    wxString s_contract_id = tc_project_name->GetValue();
    int i_pos = s_contract_id.Find(wxT(" "));
    s_contract_id = s_contract_id.Left(i_pos);
    if(!s_contract_id.IsNumber())
        s_contract_id.Empty();


    wxString l_link_list = get_link_wbs(array_units);
    wxString str_sql = wxT("INSERT INTO l_nonstd_app_header(nonstd_id, project_id, contract_id, link_list, status, mat_req_date, drawing_req_date, nonstd_desc, modify_date, modify_emp_id, create_date, create_emp_id, flow_mask) \
                  VALUES ('")+tc_nstd_id->GetValue()+wxT("','")+tc_project_id->GetValue()+wxT("','")+s_contract_id+
                       wxT("','")+l_link_list+wxT("','")+NumToStr(nstd_str_to_status(tc_status->GetValue()))+wxT("','")+ DateToStrFormat(dp_matreq->GetValue())+wxT(" 23:00:00")+wxT("','")+
                       DateToStrFormat(dp_draw_req->GetValue())+wxT(" 23:00:00")+wxT("','")+tc_nstd_desc->GetValue()+wxT("','")+DateToAnsiStr(wxDateTime::Now())+
                       wxT("','")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+ m_flow_mask+wxT("');");

    str_sql.Replace(wxT("''"),wxT("NULL"));
    wxGetApp().app_sql_update(str_sql);
}

wxString nstd_apply_panel::get_link_wbs(wxArrayString &a_wbs)
{
    wxString link_list;
    if(!a_wbs.IsEmpty())
    {
        int i_count = a_wbs.GetCount();
        for(int i=0; i<i_count; i++)
        {
            link_list = link_list + a_wbs.Item(i).Left(14)+wxT(";");
        }

        return link_list;
    }

    return wxEmptyString;
}


void nstd_apply_panel::OnButton2Click(wxCommandEvent& event)
{

    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    wxArrayInt array_sel_line = gd_nonstd_list->GetSelectedRows();
    if(array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }

    if(nstd_str_to_status(tc_status->GetValue())==-1)
    {
        if(wxMessageBox(_("非标申请单已经删除，无法修改!"),_("错误"),wxOK)==wxOK)
            wxLogMessage(_("错误:非标申请单已经删除，无法修改!"));
        return;
    }

    if(wxMessageBox(_("确认永久删除选中行?"),_("删除"),wxYES_NO) == wxNO)
        return;


    nstdappTable * table = gd_nonstd_list->GetTable();
    if(table)
    {
        int i_count = array_sel_line.GetCount();
        int i_sel=0;
        for(int i=0; i<i_count; i++)
        {
            wxString s_index_id = table->GetValue(array_sel_line.Item(i_sel),0);


            int i_step;
            int i_status = nstd_str_to_status(table->GetValue(array_sel_line.Item(i_sel),6));
            if(is_workflow_created(s_index_id,wf_str_nonstd, i_step) && i_status == 0)
            {
                if(is_sub_task_created(s_index_id))
                {
                    i_sel++;
                    wxMessageBox(_("请通知非标工程师删除分配的分任务后退回!"),_("错误"));
                    wxLogMessage(_("请通知非标工程师删除分配的分任务后退回!"));
                    continue;

                }
                else
                {
                    delete_all_process(s_index_id, wf_str_nonstd);
                    delete_status(s_index_id, wf_str_nonstd);
                }

            }
            else if(is_workflow_created(s_index_id,wf_str_nonstd, i_step) && i_status != 0)
            {
                i_sel++;
                wxMessageBox(_("已经提交流程，无法删除，请通知非标工程师删除分配的分任务后退回!"),_("错误"));
                wxLogMessage(_("已经提交流程，无法删除，请通知非标工程师删除分配的分任务后退回!"));
                continue;
            }

            table->DeleteRows(array_sel_line.Item(i_sel),1);

            array_sel_line.Clear();
            array_sel_line = gd_nonstd_list->GetSelectedRows();

            if(array_sel_line.GetCount() == i_sel)
                break;
        }
    }
}

bool nstd_apply_panel::is_sub_task_created(wxString s_index_id)
{
    wxString str_sql = wxT("select count(*) as count from l_nonstd_app_item_instance where index_id = '")+s_index_id+wxT("';");
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);

    int i_count;
    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        i_count = 0;
        _res->Clear();
        return false;
    }

    _res->MoveFirst();

    i_count = _res->GetInt(wxT("count"));

    if(i_count==0)
        return false;
    else return true;
}

void nstd_apply_panel::OnButton1Click(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(tc_nstd_id->GetValue().IsEmpty())
    {
        if(wxMessageBox(_("未生成非标申请单，无法增加行!"),_("错误"),wxOK)==wxOK)
            wxLogMessage(_("错误:未生成非标申请单，无法增加行!"));
        return;
    }

    if(nstd_str_to_status(tc_status->GetValue())!= 0)
    {
        if(wxMessageBox(_("非标申请已经提交或则已经删除，无法增加行！"),_("错误"),wxOK)==wxOK)
            wxLogMessage(_("错误:非标申请已经提交，无法增加行!"));
        return;
    }

    wxString str_add = tc_qty->GetValue();

    if(!str_add.IsNumber())
    {
        if(wxMessageBox(_("请输入数字，无法增加行！"),_("错误"),wxOK)==wxOK)
        {
            wxLogMessage(_("错误:请输入数字，无法增加行!"));
            tc_qty->SetValue(wxT("1"));
        }
        return;
    }

    int i_add = wxAtoi(str_add);

    if(i_add<=0)
    {
        if(wxMessageBox(_("请输入大于0的整数，无法增加行！"),_("错误"),wxOK)==wxOK)
        {
            wxLogMessage(_("错误:请输入大于0的整数，无法增加行!"));
            tc_qty->SetValue(wxT("1"));
        }
        return;
    }

    int i_row = gd_nonstd_list->GetNumberRows();

    add_nstd_app_item dlg;

    int i_item=0;
    if(i_row !=0)
    {
        i_item = wxAtoi(gd_nonstd_list->GetCellValue(i_row-1, 2));
    }

    i_item+=1;
    nstd_app_id = tc_nstd_id->GetValue();

    dlg.init_checklistbox(array_units);
    dlg.init_catalog_choice(m_flow_mask);
    dlg.set_nstd_app_id(nstd_app_id);
    for(int i=0; i<i_add; i++)
    {

        dlg.tc_nstd_app_index_id->SetValue(nstd_app_id +wxT("-")+NumToStr(i_item));
        dlg.tc_item_no->SetValue(NumToStr(i_item));
        dlg.choice_catalog->SetSelection(-1);
        dlg.combo_nstd_catalog->Clear();
        dlg.tc_nstd_desc->Clear();

        if(dlg.ShowModal()==wxID_OK)
        {
            nstdappTable * table = gd_nonstd_list->GetTable();
            table->AppendRows(1);

            table->SetLastRow(i_row);
            cacheLine *line = table->GetLine(i_row);
            if (!line->cols)
                line->cols = new wxString[11];
            line->cols[0] = dlg.m_index;
            line->cols[1] = dlg.m_nstd_app_id;
            line->cols[2] = dlg.m_item_no;
            line->cols[3] = dlg.m_catalog;
            line->cols[4] = dlg.m_nstd_catalog;
            line->cols[5] = dlg.m_nstd_desc;
            line->cols[6] = NumToStr(nstd_str_to_status(dlg.m_status));
            line->cols[7] = wxEmptyString;
            line->cols[8] = wxEmptyString;
            line->cols[9] = wxEmptyString;
            line->cols[10] = get_link_wbs(dlg.m_array_sel);
            table->StoreLine();

            i_row++;
            i_item++;
        }
        else
            continue;
    }

    gd_nonstd_list->EnableEditing(true);
}

void nstd_apply_panel::refresh_list()
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
    wxString str_sql = wxT("SELECT index_id, nonstd_id, item_ser, item_catalog, nonstd_catalog, nonstd_desc , (select status from l_instance_status where instance_id = index_id and \
                            workflow_id = 'WF0003') as status, (select wf_status from l_instance_status where instance_id = index_id and workflow_id = 'WF0003') as wf_status, remarks, (SELECT name from s_employee where employee_id = res_person) \
                           as res_person, link_list from l_nonstd_app_item WHERE nonstd_id = '")+ nstd_app_id+wxT("' ORDER BY item_ser ASC;");

    wxPostgreSQLresult* _res;
    _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    gd_nonstd_list->ClearGrid();

//    gd_nonstd_list->BeginBatch();
    wxGridUpdateLocker locker(gd_nonstd_list);
    wxString str_table= wxT("l_nonstd_app_item");
    wxString str_key = wxT("index_id");
    gd_nonstd_list->SetTable(new nstdappTable(_res, str_table, str_nonstd_header,wxT("11111100001"), str_key), true);

    gd_nonstd_list->Fit();
//    gd_nonstd_list->EndBatch();
    gd_nonstd_list->SetColSize(0,0);
    gd_nonstd_list->SetColSize(1,0);
    gd_nonstd_list->SetColSize(2,0);
    gd_nonstd_list->SetColSize(10,0);

    Layout();

    _res->Clear();
}

void nstd_apply_panel::OnButton_UnitsClick(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_nonstd_list->GetSelectedRows();

    bool b_edit = true;

    if(nstd_str_to_status(tc_status->GetValue()) != 0)
    {
        wxLogMessage(_("错误:非标申请单已经提交，无法修改!"));
        b_edit = false;
    }

    if(array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }
    bool b_batch=false;

    if(b_edit)
    {
        if(wxMessageBox(_("请选择是按单梯修改还是多梯批次修改(YES-单梯修改)(NO-批次修改)"),_("确认"),wxYES_NO)==wxNO)
            b_batch = true;
        else b_batch = false;
    }


    int i_count = array_sel_line.GetCount();

    wxString str_units;
    wxArrayString array_sel;

    if(b_batch)
    {
        nstd_app_item_units dlg;
        dlg.init_checklistbox(array_units, array_units, false);


        if(dlg.ShowModal() == wxID_OK)
        {
            str_units = dlg.m_units;
        }
        else
            return;
    }

    for(int i=0; i<i_count ; i++)
    {
        if(!b_batch)
        {
            str_units = gd_nonstd_list->GetCellValue(array_sel_line.Item(i),10);

            array_sel = wxStringTokenize(str_units ,wxT(";"), wxTOKEN_DEFAULT  );

            nstd_app_item_units dlg;

            dlg.init_checklistbox(array_units, array_sel,true, b_edit);

            if(dlg.ShowModal() == wxID_OK && b_edit&&!b_batch)
            {
                if(str_units == dlg.m_units)
                    continue;

                str_units = dlg.m_units;

            }
            else
                continue;
        }

        if(b_edit)
        {
            nstdappTable * table = gd_nonstd_list->GetTable();

            cacheLine * line = table->GetLine(array_sel_line.Item(i));
            table->Set_Saved_Line(array_sel_line.Item(i));
            table->SetLastRow(array_sel_line.Item(i));
            line->cols[10] = str_units;

//            table->SetValue(array_sel_line.Item(i),10, str_units);
            //         gd_nonstd_list->SetCellValue(array_sel_line.Item(i),10);
            table->StoreLine();
        }

    }

}

wxUniChar nstd_apply_panel::booltoch(bool b_value)
{
    if(b_value)
        return '1';
    else return '0';
}

bool nstd_apply_panel::inttobool(int i_value)
{
    if(i_value >0)
        return true;
    else return false;
}

void nstd_apply_panel::mask_to_check()
{
    if(m_flow_mask.IsEmpty())
        return;

    cb_mech->SetValue(inttobool(wxAtoi(m_flow_mask.Left(1))));
    cb_highrise->SetValue(inttobool(wxAtoi(m_flow_mask.Mid(1,1))));
    cb_elect->SetValue(inttobool(wxAtoi(m_flow_mask.Mid(2,1))));
}

void nstd_apply_panel::Ongd_nonstd_listCellChange(wxGridEvent& event)
{
    nstdappTable * table = gd_nonstd_list->GetTable();

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
        else if (gd_nonstd_list->GetGridCursorRow() != event.GetRow())
        {
        }
    }

    if (doSkip)
        event.Skip();
}

bool nstd_apply_panel::doSave()
{
    gd_nonstd_list->HideCellEditControl();
    gd_nonstd_list->SaveEditControlValue();
    gd_nonstd_list->DisableCellEditControl();

    if (!gd_nonstd_list->GetTable()->StoreLine())
        return false;

    return true;
}

void nstd_apply_panel::Onbutton_beginClick(wxCommandEvent& event)
{
    int i_pos = array_search_result.Index(nstd_app_id);

    if(i_pos == 0 || i_pos == wxNOT_FOUND || array_search_result.IsEmpty())
        return;

    nstd_app_id = array_search_result.Item(0);

    wxString str_step = wxT("1/")+NumToStr(array_search_result.GetCount());
    tc_step->SetValue(str_step);

    refresh_gui();
    refresh_list();
    refresh_unit_list(array_units);
    Layout();

}

void nstd_apply_panel::Onbutton_previousClick(wxCommandEvent& event)
{

    int i_pos = array_search_result.Index(nstd_app_id);

    if(i_pos == 0 || i_pos == wxNOT_FOUND || array_search_result.IsEmpty())
        return;

    i_pos--;

    wxString str_step = NumToStr(i_pos+1)+wxT("/")+NumToStr(array_search_result.GetCount());
    tc_step->SetValue(str_step);

    nstd_app_id = array_search_result.Item(i_pos);

    refresh_gui();
    refresh_list();
    refresh_unit_list(array_units);
    Layout();
}

void nstd_apply_panel::Onbutton_nextClick(wxCommandEvent& event)
{
    int i_pos = array_search_result.Index(nstd_app_id);
    int i_count = array_search_result.GetCount();

    if(i_pos == i_count-1 || i_pos == wxNOT_FOUND || array_search_result.IsEmpty())
        return;

    i_pos++;

    wxString str_step = NumToStr(i_pos+1)+wxT("/")+NumToStr(array_search_result.GetCount());
    tc_step->SetValue(str_step);

    nstd_app_id = array_search_result.Item(i_pos);

    refresh_gui();
    refresh_list();
    refresh_unit_list(array_units);
    Layout();
}

void nstd_apply_panel::Onbutton_endClick(wxCommandEvent& event)
{

    int i_pos = array_search_result.Index(nstd_app_id);
    int i_count = array_search_result.GetCount();

    if(i_pos == i_count-1 || i_pos == wxNOT_FOUND || array_search_result.IsEmpty())
        return;

    wxString str_step = NumToStr(i_count)+wxT("/")+NumToStr(array_search_result.GetCount());
    tc_step->SetValue(str_step);

    nstd_app_id = array_search_result.Item(i_count-1);

    refresh_gui();
    refresh_list();
    refresh_unit_list(array_units);
    Layout();
}

void nstd_apply_panel::OnButton_CloseClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    int i_count = gd_nonstd_list->GetNumberRows();

    if(nstd_str_to_status(tc_status->GetValue())==10)
    {
        wxLogMessage(_("错误:非标申请已经关闭，请勿重复提交!"));
        return;
    }

    if(i_count ==0)
    {
        wxLogMessage(_("错误:非标申请未包含任何非标项次无法提交!"));
        return;
    }

    if(wxMessageBox(_("确认关闭已经完成的非标申请?"),_("完成确认："),wxOK|wxCANCEL,this)==wxCANCEL)
    {
        return;
    }


    v_wf_action * t_template = get_template_action(wf_str_nonstd);
    wf_operator * wf_nstd_app=0;
    wf_process * l_proc_act =0;
    wxString str_instance;
    wxLongLong mils_used, start_mils;
    v_wf_instance now_step;

    int i_finish=0;

    if(!check_owner_nstd(nstd_app_id))
    {
        wxLogMessage("非本人申请不能确认!");
        return;
    }

    for(int i=0; i<i_count; i++)
    {
        str_instance = gd_nonstd_list->GetCellValue(i,0);
        start_mils = wxGetLocalTimeMillis();

        wf_nstd_app = new wf_operator(str_instance, wf_str_nonstd, t_template);
        l_proc_act = wf_nstd_app->get_current_process();
        l_proc_act->MoveToActive();
        now_step = l_proc_act->get_cur_instance_action();

        if(!now_step.is_active)
        {
            l_proc_act = 0;
            if(wf_nstd_app)
                delete wf_nstd_app;

            i_finish++;

            wxLogMessage(str_instance+_("非标申请流程已经处于关闭状态，无法重复提交"));

        }
        else if(now_step.is_active && now_step.s_action.i_flow_ser== now_step.s_action.i_total_flow)
        {

            wf_nstd_app->Pass_proc(now_step.s_action.s_operator_id, now_step.s_action.s_group_id,wxEmptyString,  false);
            wf_nstd_app->update_instance_one2several(10);
            i_finish++;

            l_proc_act = 0;
            if(wf_nstd_app)
                delete wf_nstd_app;

            mils_used = wxGetLocalTimeMillis() - start_mils;

            wxLogMessage(str_instance+_("非标申请流程结束成功!  耗时:")+NumToStr(mils_used)+_("毫秒"));
        }
        else
        {
            l_proc_act = 0;
            if(wf_nstd_app)
                delete wf_nstd_app;
            mils_used = wxGetLocalTimeMillis() - start_mils;

            wxLogMessage(str_instance+_("非标申请流程仍在非标处理阶段  耗时:")+NumToStr(mils_used)+_("毫秒"));
        }

    }

    if(t_template)
        delete [] t_template;

    if(i_finish == i_count)
    {
        wxString str_sql = wxT("UPDATE l_nonstd_app_header SET status=10 WHERE nonstd_id ='")+nstd_app_id+wxT("';");

        if(wxGetApp().app_sql_update(str_sql));
        tc_status->SetValue(wxT("CLOSED"));
    }

    refresh_list();
    enable_control(false);

}

void nstd_apply_panel::OnButton_Show_MatClick(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_nonstd_list->GetSelectedRows();

    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }

    int i_count = array_sel_line.GetCount();

    wxString str_sql = wxT("select index_id,sequence,stno,mat_id,mat_name_cn, qty, unit, mat_comment, link_list from l_nonstd_configure_mat_list where ");

    for(int i=0; i<i_count; i++)
    {

       if(i==i_count -1)
            str_sql = str_sql + wxT(" index_id = '")+gd_nonstd_list->GetCellValue(array_sel_line.Item(i),0)+wxT("' ");
        else
            str_sql = str_sql + wxT(" index_id = '")+gd_nonstd_list->GetCellValue(array_sel_line.Item(i),0)+wxT("' OR");
    }

    str_sql= str_sql + wxT(" and is_active=true order by index_id,sequence ASC;");//add is _active to let non-std engineer finish the sub-task to be shown to configuration;
    nstd_mat_task_list dlg;
    dlg.init_nstd_mat_header();
    dlg.Set_Query(str_sql);
    dlg.refresh_list();
    dlg.show_control(false);
    dlg.ShowModal();
}

void nstd_apply_panel::Ondp_matreqChanged(wxDateEvent& event)
{

    if(nstd_app_id.IsEmpty())
        return;

    wxString str_mat_req_date = DateToStrFormat(dp_matreq->GetValue())+ wxT(" 23:00:00");

    wxGetApp().update_data_in_database(wxT("mat_req_date"),str_mat_req_date,wxT("l_nonstd_app_header"), wxT("nonstd_id"),nstd_app_id);
}

void nstd_apply_panel::Ondp_draw_reqChanged(wxDateEvent& event)
{
    if(nstd_app_id.IsEmpty())
        return;

    wxString str_draw_req_date = DateToStrFormat(dp_draw_req->GetValue())+ wxT(" 23:00:00");

    wxGetApp().update_data_in_database(wxT("drawing_req_date"),str_draw_req_date,wxT("l_nonstd_app_header"), wxT("nonstd_id"),nstd_app_id);

}

void nstd_apply_panel::Ontc_nstd_descText(wxCommandEvent& event)
{
    if(nstd_app_id.IsEmpty())
        return;

    wxGetApp().update_data_in_database(wxT("nonstd_desc"),tc_nstd_desc->GetValue(),wxT("l_nonstd_app_header"), wxT("nonstd_id"),nstd_app_id);
}

void nstd_apply_panel::OnButton_WORKFLOWClick(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_nonstd_list->GetSelectedRows();

    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    if(array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }

    int i_count = array_sel_line.GetCount();

    wxArrayString array_sel_workflow, array_sel_ins;
    wxString str;

    for(int i=0; i<i_count; i++)
    {
        str = wf_str_nonstd;
        array_sel_workflow.Add(str);
        str = gd_nonstd_list->GetCellValue(array_sel_line.Item(i),0);
        array_sel_ins.Add(str);
    }
    array_sel_line.Clear();
    ins_nonstd_proc_log ipl_dlg;

    ipl_dlg.Refresh_list_view(array_sel_ins, array_sel_workflow);
    ipl_dlg.ShowModal();
}

void nstd_apply_panel::OnButton_REVISEClick(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_nonstd_list->GetSelectedRows();

    bool b_edit = true;

    if(array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }

    int i_count = array_sel_line.GetCount();

    wxString str_units;
    wxArrayString array_sel;

    for(int i=0; i<i_count; i++)
    {
        int i_status = nstd_str_to_status(gd_nonstd_list->GetCellValue(array_sel_line.Item(i),6));
        if(i_status != 0)
        {
            b_edit = false;
        }
        else b_edit = true;

        add_nstd_app_item dlg;

        dlg.enable_control(b_edit);
        dlg.choice_catalog->Enable(false);
        str_units = gd_nonstd_list->GetCellValue(array_sel_line.Item(i),10);
        array_sel = wxStringTokenize(str_units ,wxT(";"), wxTOKEN_DEFAULT  );

        dlg.m_array_sel = array_sel;

        dlg.init_checklistbox(array_units, true);
        dlg.init_catalog_choice(m_flow_mask);
        dlg.set_nstd_app_id(nstd_app_id);
        dlg.init_combobox(gd_nonstd_list->GetCellValue(array_sel_line.Item(i),3));

        dlg.tc_item_no->SetValue(gd_nonstd_list->GetCellValue(array_sel_line.Item(i),2));
        dlg.tc_nstd_app_index_id->SetValue(gd_nonstd_list->GetCellValue(array_sel_line.Item(i),0));
        dlg.choice_catalog->SetSelection(dlg.choice_catalog->FindString(gd_nonstd_list->GetCellValue(array_sel_line.Item(i),3)));
        dlg.combo_nstd_catalog->SetValue(gd_nonstd_list->GetCellValue(array_sel_line.Item(i),4));
        dlg.tc_nstd_desc->SetValue(gd_nonstd_list->GetCellValue(array_sel_line.Item(i),5));
        dlg.tc_status->SetValue(gd_nonstd_list->GetCellValue(array_sel_line.Item(i),6));
        if(dlg.ShowModal()==wxID_OK)
        {
            nstdappTable * table = gd_nonstd_list->GetTable();
            cacheLine *line = table->GetLine(array_sel_line.Item(i));

            table->Set_Saved_Line(array_sel_line.Item(i));
            table->SetLastRow(array_sel_line.Item(i));
//            line->cols[3] = dlg.m_catalog;
            line->cols[4] = dlg.m_nstd_catalog;
            line->cols[5] = dlg.m_nstd_desc;
            line->cols[10] = get_link_wbs(dlg.m_array_sel);
            table->StoreLine();
        }

    }
}

void nstd_apply_panel::OnButton3Click(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_nonstd_list->GetSelectedRows();

    if(array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }


    if(wxMessageBox(_("确认退回所选的非标申请?"),_("确认"),wxYES_NO)==wxNO)
        return;

    int i_count = array_sel_line.GetCount();

    wxString str_units;
    wxArrayString array_sel;
    wxString s_sql;

    wxString s_workflow_id = wxT("WF0003");
    wxString aim_step=wxT("AT00000022");

     v_wf_action * t_template=get_template_action(s_workflow_id);
     wf_operator * wf_active;
     wxString s_desc=_("退回更改处理");

    for(int i=0; i<i_count; i++)
    {
        int i_status = nstd_str_to_status(gd_nonstd_list->GetCellValue(array_sel_line.Item(i),6));
        wxString s_index_no = gd_nonstd_list->GetCellValue(array_sel_line.Item(i),0);
        if(i_status != 4 && i_status!=10)
        {
            wxLogMessage(s_index_no+_("非标申请尚未回复，无法操作!"));
            continue;
        }

        if(i_status==10)
        {
             s_sql = wxT("UPDATE l_proc_act SET is_active=true,  modify_emp_id='")+gr_para.local_user+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("' where instance_id ='")+s_index_no+wxT("' and workflow_id='WF0003' and action_id='AT00000023';");
             if(wxGetApp().app_sql_update(s_sql))
             {
                 s_sql= wxT("UPDATE l_instance_status SET  status=4, modify_emp_id='")+gr_para.local_user+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("' where instance_id ='")+s_index_no+wxT("' and workflow_id='WF0003' and action_id='AT00000023';");
                 if(wxGetApp().app_sql_update(s_sql))
                 {
                     wxGetApp().change_log(wxT("l_instance_status"),s_index_no, wxT("status"),"10","4","by hand");
                 }
             }
        }

        wf_active = new wf_operator(s_index_no, s_workflow_id, t_template);
        wf_active->Feed_back(s_desc, aim_step);

        i_status = nstd_action_to_status(wf_active->get_action_id());
        wf_active->update_instance_one2several(i_status);
        delete wf_active;

    }

    delete [] t_template;

    refresh_list();
}
