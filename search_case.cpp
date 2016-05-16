#include "search_case.h"

#include <wx/clipbrd.h>
#include <wx/msgdlg.h>
#include <wx/log.h>

//(*InternalHeaders(search_case)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(search_case)
const long search_case::ID_TEXTCTRL1 = wxNewId();
const long search_case::ID_BUTTON1 = wxNewId();
const long search_case::ID_BUTTON2 = wxNewId();
const long search_case::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(search_case,wxDialog)
	//(*EventTable(search_case)
	//*)
END_EVENT_TABLE()

search_case::search_case(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(search_case)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(281,221));
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	tc_wbs = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(214,146), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer1->Add(tc_wbs, 4, wxALL|wxEXPAND, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("确定"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	Button2 = new wxButton(this, ID_BUTTON2, _("粘贴"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	Button3 = new wxButton(this, ID_BUTTON3, _("取消"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer2->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 0);
	SetSizer(BoxSizer1);
	SetSizer(BoxSizer1);
	Layout();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&search_case::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&search_case::OnButton2Click);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&search_case::OnButton3Click);
	//*)
	check_wbs = false;
}

search_case::~search_case()
{
	//(*Destroy(search_case)
	//*)
}


void search_case::OnButton1Click(wxCommandEvent& event)
{
    int i_lines = tc_wbs->GetNumberOfLines();
    wxString str;

    if(i_lines==0 || tc_wbs->GetValue().Trim().IsEmpty())
    {
        wxMessageBox(_("列表不能为空"),_("条件窗口"), wxOK, this);
        return;
    }
    array_value.Clear();
    for(int i = 0; i<i_lines;i++)
    {
        str = tc_wbs->GetLineText(i).Trim().Upper();

        if(str.IsEmpty())
            continue;

        if(check_wbs)
        {
            if(!check_valid_wbs(str))
            {
               wxLogMessage(str+_("WBS no 格式不正确，请核查后重新拷贝"),_("报错"),wxOK,this);
                continue;
            }
        }

        if(!str.IsEmpty())
            array_value.Add(str);
    }

    EndDialog(wxID_OK);
}

void search_case::OnButton2Click(wxCommandEvent& event)
{
    if (wxTheClipboard->Open())
    {
        if (wxTheClipboard->IsSupported( wxDF_TEXT ))
        {
            wxTextDataObject data;
            wxTheClipboard->GetData(data);

            wxString str = data.GetText().Upper();
            tc_wbs->SetValue(str);
        }
        wxTheClipboard->Close();
    }
}

bool search_case::check_valid_wbs(wxString &s_wbs)
{
    wxString str = s_wbs.Upper();


    str.Replace(wxT("\\"),wxT("/"));


    if(str.Left(1).Upper()!=wxT("E"))
    {
        str = wxT("E")+str;
    }

    int i_pos = str.Find(wxT("/"));
    if(i_pos ==wxNOT_FOUND)
    {
        str.insert(1,wxT("/"));
    }

    i_pos = str.Find(wxT("."));
    int i_length = str.Length();
    wxString s_trail,s_head;

    if(i_pos ==wxNOT_FOUND)
    {
        if(i_length<=10)
            return false;

        if(i_length>13)
            return  false;

        s_head = str.Left(10);
         s_trail = str.Right(i_length-10);
        str = s_head+wxT(".")+s_trail;
        i_pos = 10;
        i_length = str.Length();

    }

    s_head = str.Left(i_pos);
    s_trail = str.Right(i_length-i_pos-1);

    if(s_head.Length()<10)
        return false;

    int i_trail = s_trail.Length();

    if(i_trail>3)
    {
        s_trail= s_trail.Left(3);
        i_trail = 3;
    }

    if(s_trail.Find(wxT("."))!=wxNOT_FOUND)
        return false;

    if(s_trail.Length()>6)
        return  false;

    for(int i=0;i<3-i_trail;i++)
    {
        s_trail = wxT("0")+s_trail;
    }

    str = s_head+wxT(".")+s_trail;

    s_wbs = str;

    return true;
}

void search_case::OnButton3Click(wxCommandEvent& event)
{
    array_value.Clear();
    EndDialog(wxID_CANCEL);
}
