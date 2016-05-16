#ifndef CONTRACTLABELDRAW_H
#define CONTRACTLABELDRAW_H

#include <wx/wx.h>
#include "wf_stdafx.h"

//generate qrcode and save as bmp file
#include <string.h>
#include <errno.h>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <wchar.h>
#include <wx/dcbuffer.h>

#include "qrencode.h"

#define OUT_FILE_PIXEL_PRESCALER	8											// Prescaler (number of pixels in bmp file for each QRCode pixel, on each dimension)

#define PIXEL_COLOR_R				0											// Color of bmp pixels
#define PIXEL_COLOR_G				0
#define PIXEL_COLOR_B				0

#define font_height1   14
#define font_height2   18
#define font_height3    28
#define font_height4   24
#define mm2ppix        wxScreenDC().GetPPI().GetWidth() / 25
#define mm2ppiy        wxScreenDC().GetPPI().GetHeight() / 25
#define numinpage   5


	// BMP defines

typedef unsigned short	WORD;
typedef unsigned long	DWORD;
typedef signed long		LONG;
/*
#define BI_RGB			0L


typedef struct
	{
	WORD    bfType;
	DWORD   bfSize;
	WORD    bfReserved1;
	WORD    bfReserved2;
	DWORD   bfOffBits;
	} BITMAPFILEHEADER;

typedef struct
	{
	DWORD      biSize;
	LONG       biWidth;
	LONG       biHeight;
	WORD       biPlanes;
	WORD       biBitCount;
	DWORD      biCompression;
	DWORD      biSizeImage;
	LONG       biXPelsPerMeter;
	LONG       biYPelsPerMeter;
	DWORD      biClrUsed;
	DWORD      biClrImportant;
	} BITMAPINFOHEADER;
*/

//generate qrcode and save as bmp file

class ContractLabelDraw : public wxScrolledCanvas
{
    public:
        ContractLabelDraw(wxWindow *parent, wxWindowID winid, const wxPoint &pos, const wxSize &size);
        virtual ~ContractLabelDraw();

       void OnPaint( wxPaintEvent &event );
//       virtual void OnDraw(wxDC& dc);
        void OnEraseBackground(wxEraseEvent& evt);

        void refresh_panel();

        void Draw(wxDC&dc);
        void Draw(wxDC&dc, int page);

        int get_pages();

        void reset_label(wxArrayLabel &a_label);

    protected:
    private:

        void draw_one_label(wxDC &dc , wxPoint &s_point, s_contract_label &_label,double x_scale=1.0, double y_scale=1.0);

        wxBitmap generate_qrcode_bitmap(wxString qr_text);

        wxBitmap bmp_logo;


        wxArrayLabel array_label;

    DECLARE_EVENT_TABLE()
};


class MyPrintout: public wxPrintout
{
 public:
  MyPrintout(const wxString& name = wxT("Printing"), ContractLabelDraw *draw_panel = NULL);
  ~MyPrintout();
  bool OnPrintPage(int page);
  bool HasPage(int page);
  bool OnBeginDocument(int startPage, int endPage);
  void GetPageInfo(int *minPage, int *maxPage, int *selPageFrom, int *selPageTo);

   void drawpage(wxDC&dc, int page);


 private:
    int m_NumPages;

     ContractLabelDraw *m_drawpanel;
     wxString m_Name;

};


#endif // CONTRACTLABELDRAW_H
