#include "datepickerdlg.h"

//(*InternalHeaders(datepickerdlg)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(datepickerdlg)
const long datepickerdlg::ID_STATICTEXT1 = wxNewId();
const long datepickerdlg::ID_DATEPICKERCTRL1 = wxNewId();
const long datepickerdlg::ID_STATICTEXT2 = wxNewId();
const long datepickerdlg::ID_DATEPICKERCTRL2 = wxNewId();
const long datepickerdlg::ID_CHECKBOX1 = wxNewId();
const long datepickerdlg::ID_CHECKBOX2 = wxNewId();
const long datepickerdlg::ID_BUTTON1 = wxNewId();
const long datepickerdlg::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(datepickerdlg,wxDialog)
	//(*EventTable(datepickerdlg)
	//*)
END_EVENT_TABLE()

datepickerdlg::datepickerdlg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(datepickerdlg)
	wxGridBagSizer* GridBagSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	GridBagSizer1 = new wxGridBagSizer(0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("从"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	GridBagSizer1->Add(StaticText1, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	dp_from = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL1, wxDefaultDateTime, wxDefaultPosition, wxSize(113,21), wxDP_DEFAULT|wxDP_DROPDOWN|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL1"));
	dp_from->Disable();
	GridBagSizer1->Add(dp_from, wxGBPosition(0, 2), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("到"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	GridBagSizer1->Add(StaticText2, wxGBPosition(0, 3), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	dp_to = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL2, wxDefaultDateTime, wxDefaultPosition, wxSize(98,21), wxDP_DEFAULT|wxDP_DROPDOWN|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL2"));
	GridBagSizer1->Add(dp_to, wxGBPosition(0, 5), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cb_from = new wxCheckBox(this, ID_CHECKBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	cb_from->SetValue(false);
	GridBagSizer1->Add(cb_from, wxGBPosition(0, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cb_to = new wxCheckBox(this, ID_CHECKBOX2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	cb_to->SetValue(true);
	GridBagSizer1->Add(cb_to, wxGBPosition(0, 4), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(GridBagSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("确定"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("取消"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&datepickerdlg::Oncb_fromClick);
	Connect(ID_CHECKBOX2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&datepickerdlg::Oncb_toClick);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&datepickerdlg::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&datepickerdlg::OnButton2Click);
	//*)
}

datepickerdlg::~datepickerdlg()
{
	//(*Destroy(datepickerdlg)
	//*)
}


void datepickerdlg::OnButton1Click(wxCommandEvent& event)
{
    b_from = cb_from->IsChecked();
    b_to = cb_to->IsChecked();

    dt_from = dp_from->GetValue();
    dt_to = dp_to->GetValue();

    EndDialog(wxID_OK);
}

void datepickerdlg::OnButton2Click(wxCommandEvent& event)
{
    EndDialog(wxID_CANCEL);
}

void datepickerdlg::Oncb_fromClick(wxCommandEvent& event)
{
    if(cb_from->IsChecked())
        dp_from->Enable(true);
    else
        dp_from->Enable(false);


}

void datepickerdlg::Oncb_toClick(wxCommandEvent& event)
{
    if(cb_to->IsChecked())
        dp_to->Enable(true);
    else
        dp_to->Enable(false);
}
