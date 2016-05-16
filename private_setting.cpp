#include "private_setting.h"

//(*InternalHeaders(private_setting)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(private_setting)
//*)

BEGIN_EVENT_TABLE(private_setting,wxDialog)
	//(*EventTable(private_setting)
	//*)
END_EVENT_TABLE()

private_setting::private_setting(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(private_setting)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(393,321));
	Move(wxDefaultPosition);
	//*)
}

private_setting::~private_setting()
{
	//(*Destroy(private_setting)
	//*)
}

