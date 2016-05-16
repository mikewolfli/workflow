
/* ttListCtrl.cpp */
/* Ryan Day, http://www.ryanday.net/ */

#include "ttListCtrl.h"

int ttListCtrl::SetTooltip(int row, int col, wxString& tip)
{
   int i, j;

   if( (row >= rows) || (col >= cols) )
   {
	   wxString* tmp = grid;
	   grid = new wxString[(row+5) * (col+5)];

       for(i=0;i<rows;i++)
          for(j=0;j<cols;j++)
             grid[(i*cols)+j].Printf(wxT("%s"), tmp[(i*cols)+j]);
       delete[] tmp;
       rows = row+5;
       cols = col+5;
   }
   grid[(row*cols)+col].Printf(wxT("%s"),tip);
}

int ttListCtrl::GetTooltip(int row, int col, wxString& tip)
{
   if( &grid[(row*cols)+col] != NULL )
      tip.Printf(wxT("%s"), grid[(row*cols)+col]);
}

void ttListCtrl::OnMouseMotion(wxMouseEvent& event)
{
   ttListCtrl* o = (ttListCtrl*)event.GetEventObject();
   if( o == NULL ) return;
   int id = event.GetEventType();
   int count = o->GetColumnCount();
   long row=-1, col=-1;
   int flags=0, i=0, totalWidth=0, tmpWidth=0;
   wxPoint pt;
   wxTipWindow* tipWin;
   wxTimer* killTip;
   wxString toolTip;

   if( id != wxEVT_MOTION )
	   return;

   pt = event.GetPosition();
   row = o->HitTest(pt, flags);
   for(i=0;i<count;i++)
   {
       tmpWidth = o->GetColumnWidth(i);
       totalWidth += tmpWidth;
       if( pt.x < totalWidth )
       {
    	   col = i;
    	   break;
       }
   }

   if( row > -1 && col > -1)
	   o->GetTooltip(row, col, toolTip);

   if( toolTip.Length() > 0 )
   {
      tipWin = new wxTipWindow(o,toolTip);
      //Bind(wxTimerEvent, Monitor::destroyTip, wxID_ANY, wxID_ANY, q);
      SetClientData(tipWin);
      Connect(wxEVT_TIMER, wxTimerEventHandler(ttListCtrl::destroyTip), NULL, this);
      killTip = new wxTimer(this, wxID_ANY);
      killTip->Start(1000, true);
   }
}

void ttListCtrl::destroyTip(wxTimerEvent& event)
{
   wxTipWindow *obj = (wxTipWindow*)GetClientData();
   if( obj ) obj->Destroy();
}
