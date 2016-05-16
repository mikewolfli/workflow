/* ttListCtrl.h */
/* Ryan Day, http://www.ryanday.net/ */

#include <wx/timer.h>
#include <wx/tipwin.h>
#include <wx/listctrl.h>

class ttListCtrl : public wxListCtrl
{
private:
   wxString *grid;
   int cols, rows;

public:
   ttListCtrl() { };
   ttListCtrl( wxWindow *parent,
                wxWindowID winid = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxLC_REPORT,
                const wxValidator& validator = wxDefaultValidator,
                const wxString &name = wxListCtrlNameStr)
   {
       cols = rows = 3;
       grid = new wxString[3*3];
       Create(parent, winid, pos, size, style, validator, name);

       Connect(wxEVT_MOTION, wxMouseEventHandler(ttListCtrl::OnMouseMotion));
   }

   int SetTooltip(int row, int col, wxString& tip);
   int GetTooltip(int row, int col, wxString& tip);

   void OnMouseMotion(wxMouseEvent& event);
   void destroyTip(wxTimerEvent& event);
};
