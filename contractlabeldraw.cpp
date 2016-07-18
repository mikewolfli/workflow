#include "contractlabeldraw.h"
#include <wx/filefn.h>
#include <wx/dir.h>

BEGIN_EVENT_TABLE(ContractLabelDraw, wxScrolledCanvas)
    EVT_PAINT(ContractLabelDraw::OnPaint)
    EVT_ERASE_BACKGROUND(ContractLabelDraw::OnEraseBackground)
END_EVENT_TABLE()

ContractLabelDraw::ContractLabelDraw(wxWindow *parent, wxWindowID winid, const wxPoint &pos, const wxSize &size)
    : wxScrolledCanvas( parent, winid, pos, size, wxSUNKEN_BORDER )
{
    //ctor
    SetBackgroundColour(* wxWHITE);
     bmp_logo.LoadFile(wxT("./res/logo.png"), wxBITMAP_TYPE_PNG);

}

ContractLabelDraw::~ContractLabelDraw()
{
    //dtor
}

void ContractLabelDraw::OnPaint( wxPaintEvent &event )
{
    wxAutoBufferedPaintDC dc(this);
    DoPrepareDC(dc);


    dc.SetPen(*wxBLACK_PEN);
    dc.SetBackground(*wxWHITE_BRUSH);
    dc.Clear();
    Draw(dc);
    dc.SetPen(wxNullPen);

}


void ContractLabelDraw::reset_label(wxArrayLabel &a_label)
{
    array_label = a_label;

    if(array_label.IsEmpty())
        return;

    int n=(int)((array_label.GetCount()-1)/numinpage/2)+1;

    wxSize A4(350,297);

    A4.x = mm2ppix*A4.x;
    A4.y = mm2ppiy*A4.y*n;

    SetVirtualSize(A4); //作为测试，在构造函数里设置了画布的尺寸!
    SetScrollRate(mm2ppix,mm2ppiy*n);
    SetBackgroundStyle(wxBG_STYLE_CUSTOM);
}

/*
void ContractLabelDraw::OnDraw(wxDC & dc)
{
    dc.SetPen(*wxBLACK_PEN);
    dc.SetBackground(*wxWHITE_BRUSH);
    dc.Clear();
    Draw(dc);
    dc.SetPen(wxNullPen);
}*/

void ContractLabelDraw::OnEraseBackground(wxEraseEvent& evt)
{
  //  evt.Skip();
}

void ContractLabelDraw::refresh_panel()
{
    Refresh();
    Update();
}

void ContractLabelDraw::Draw(wxDC&dc)
{
    int i_count = array_label.GetCount();

    if(i_count==0)
    {
        return;
    }
    int i_page=0;


 //   double x_scale= dc.GetPPI().GetWidth()/25.4;
  //  double y_scale = dc.GetPPI().GetHeight()/25.4;

  //  dc.StartPage();

    wxPoint Origin_Point;

    for(int i=0;i<i_count;i++)
    {
        if(i%(numinpage*2)==0&&i!=0)
        {
     //      dc.StartPage();
           i_page++;
        }

        Origin_Point= wxPoint(mm2ppix*(10+(i%10)*33), mm2ppiy*(i_page*250+10));
        draw_one_label(dc, Origin_Point, array_label.Item(i),mm2ppix, mm2ppiy);
/*
        if((i+1)%numinpage==0||((i==i_count-1)&&i_count<numinpage))
        {
            dc.EndPage();
        }*/

    }

}

void ContractLabelDraw::Draw(wxDC&dc, int page)
{
    int i_count=array_label.GetCount();

    int i_start = (page-1)*numinpage;
    int i_end = page*numinpage;

    int i_step=0;


    wxPoint Origin_Point;

    dc.StartPage();

    dc.SetFont(wxFont(font_height1, wxSWISS, wxNORMAL, wxBOLD, false,wxT("TkTypeRegular")));

    wxString str = wxT("page ")+NumToStr(page);
    dc.DrawText(str,mm2ppix*8,mm2ppiy*15);

    while(i_start<i_end && i_start <i_count)
    {
           Origin_Point= wxPoint(mm2ppix*(22+i_step*33), mm2ppiy*35);
           draw_one_label(dc, Origin_Point, array_label.Item(i_start),mm2ppix,mm2ppiy);

           i_start++;
           i_step++;
    }

    dc.EndPage();
}


wxBitmap ContractLabelDraw::generate_qrcode_bitmap(wxString qr_text)
{
     char         szSourceSring[1024];
     char         file_path[1024];

     strncpy(szSourceSring, (const char*)qr_text.ToUTF8(), 1023);

    unsigned int	unWidth, x, y, l, n, unWidthAdjusted, unDataBytes;
    unsigned char*	pRGBData, *pSourceData, *pDestData;
    QRcode*			pQRC;
    FILE*			f;
    wxString  str_path=wxT("./temp/");
    if(!wxDir::Exists(str_path))
         wxMkdir(str_path);

    str_path = str_path +qr_text+wxT(".bmp");
    strncpy(file_path, (const char*)str_path.ToUTF8(), 1023);

    wxBitmap qr_bitmap;


	if (pQRC = QRcode_encodeString(szSourceSring, 0, QR_ECLEVEL_H, QR_MODE_8, 1))
		{
		unWidth = pQRC->width;
		unWidthAdjusted = unWidth * OUT_FILE_PIXEL_PRESCALER * 3;
		if (unWidthAdjusted % 4)
			unWidthAdjusted = (unWidthAdjusted / 4 + 1) * 4;
		unDataBytes = unWidthAdjusted * unWidth * OUT_FILE_PIXEL_PRESCALER;

			// Allocate pixels buffer

		if (!(pRGBData = (unsigned char*)malloc(unDataBytes)))
			{
			wxLogMessage("内存溢出");
			return wxNullBitmap;
			}

			// Preset to white

		memset(pRGBData, 0xff, unDataBytes);


			// Prepare bmp headers

		BITMAPFILEHEADER kFileHeader;
		kFileHeader.bfType = 0x4d42;  // "BM"
		kFileHeader.bfSize =	sizeof(BITMAPFILEHEADER) +
								sizeof(BITMAPINFOHEADER) +
								unDataBytes;
		kFileHeader.bfReserved1 = 0;
		kFileHeader.bfReserved2 = 0;
		kFileHeader.bfOffBits =	sizeof(BITMAPFILEHEADER) +
								sizeof(BITMAPINFOHEADER);

		BITMAPINFOHEADER kInfoHeader;
		kInfoHeader.biSize = sizeof(BITMAPINFOHEADER);
		kInfoHeader.biWidth = unWidth * OUT_FILE_PIXEL_PRESCALER;
		kInfoHeader.biHeight = -((int)unWidth * OUT_FILE_PIXEL_PRESCALER);
		kInfoHeader.biPlanes = 1;
		kInfoHeader.biBitCount = 24;
		kInfoHeader.biCompression = BI_RGB;
		kInfoHeader.biSizeImage = 0;
		kInfoHeader.biXPelsPerMeter = 0;
		kInfoHeader.biYPelsPerMeter = 0;
		kInfoHeader.biClrUsed = 0;
		kInfoHeader.biClrImportant = 0;


			// Convert QrCode bits to bmp pixels

		pSourceData = pQRC->data;
		for(y = 0; y < unWidth; y++)
			{
			pDestData = pRGBData + unWidthAdjusted * y * OUT_FILE_PIXEL_PRESCALER;
			for(x = 0; x < unWidth; x++)
				{
				if (*pSourceData & 1)
					{
					for(l = 0; l < OUT_FILE_PIXEL_PRESCALER; l++)
						{
						for(n = 0; n < OUT_FILE_PIXEL_PRESCALER; n++)
							{
							*(pDestData +		n * 3 + unWidthAdjusted * l) =	PIXEL_COLOR_B;
							*(pDestData + 1 +	n * 3 + unWidthAdjusted * l) =	PIXEL_COLOR_G;
							*(pDestData + 2 +	n * 3 + unWidthAdjusted * l) =	PIXEL_COLOR_R;
							}
						}
					}
				pDestData += 3 * OUT_FILE_PIXEL_PRESCALER;
				pSourceData++;
				}
			}

			// Output the bmp file
        f = fopen(file_path, "wb");
		if (f!=NULL)
			{
			fwrite(&kFileHeader, sizeof(BITMAPFILEHEADER), 1, f);
			fwrite(&kInfoHeader, sizeof(BITMAPINFOHEADER), 1, f);
			fwrite(pRGBData, sizeof(unsigned char), unDataBytes, f);

			fclose(f);
			}
		else
			{
			wxLogMessage("无法打开文件");
			return wxNullBitmap;
			}

			// Free data

		free(pRGBData);
		QRcode_free(pQRC);
		}
	else
		{
		wxLogMessage("返回空白图像d");
		return wxNullBitmap;
		}

    if(!qr_bitmap.LoadFile(str_path, wxBITMAP_TYPE_BMP))
    {
        wxLogMessage(_("载入二维码图像失败!"));
        return wxNullBitmap;
    }

   wxRemoveFile(str_path);

    return qr_bitmap;
}

int ContractLabelDraw::get_pages()
{
    int i_count = array_label.GetCount();

    if(i_count==0)
        return 0;

    return (int)((i_count-1)/numinpage)+1;
}


void ContractLabelDraw::draw_one_label(wxDC &dc , wxPoint &s_point, s_contract_label &_label,double x_scale, double y_scale)
{
    dc.DrawRectangle(s_point, wxSize(x_scale*33, y_scale*227));

    wxMemoryDC dcMem;

    wxBitmap bmp_qr;



    wxSize bmp;
    if(bmp_logo.IsOk())
    {
       dcMem.SelectObject(bmp_logo);

        bmp = bmp_logo.GetSize();

        dc.StretchBlit(s_point.x+x_scale*6.6, s_point.y+y_scale*0.5, x_scale*20, y_scale*15,
                    &dcMem, 0, 0, bmp.GetWidth(), bmp.GetHeight(),wxCOPY, false);

        dcMem.SelectObject( wxNullBitmap );
    }

    dc.SetFont(wxFont(font_height1, wxSWISS, wxNORMAL, wxBOLD, false,wxT("TkTypeRegular")));

    wxSize text_size;
    if(_label.s_project_catalog==wxT("Major Project"))
    {
         text_size = dc.GetTextExtent(_label.s_project_catalog);
         dc.DrawText(_label.s_project_catalog, s_point.x+(x_scale*33-text_size.GetWidth())/2, s_point.y+y_scale*15);

    }


    wxBitmap qr_bimap = generate_qrcode_bitmap(_label.s_label_id);

    if(qr_bimap.IsOk())
    {
        dcMem.SelectObject(qr_bimap);

        bmp = qr_bimap.GetSize();

        dc.StretchBlit(s_point.x+x_scale*6.5, s_point.y+y_scale*21, y_scale*20, y_scale*20,
                       &dcMem, 0, 0, bmp.GetWidth(), bmp.GetHeight(),wxCOPY, false);

        dcMem.SelectObject( wxNullBitmap );
    }

    wxString str= wxT("NO.")+_label.s_project_id;
    dc.DrawRotatedText(str, s_point.x+x_scale*30, s_point.y+y_scale*80, -90);

    _label.s_project_name.Replace(wxT("-"),wxT("|"));
    int i_len=_label.s_project_name.Length();

    int i;
    str.Empty();
    wxString str_test1,str_test2;
    for(i=0; i<i_len; i++)
    {
        if(i==i_len-1)
        {
            str=str+_label.s_project_name.Right(1);
        }
        else
        {
            if(i+1<i_len)
            {
                str_test1=_label.s_project_name.Mid(i,1);
                str_test2 = _label.s_project_name.Mid(i+1,1);

                if((str_test1.IsNumber()||is_char(str_test1))&&str_test2.IsNumber())
                {
                    str=str+ _label.s_project_name.Mid(i,1);
                    continue;
                }


            }
            str=str+_label.s_project_name.Mid(i,1)+wxT("\n");
        }

    }

    dc.SetFont(wxFont(font_height2, wxSWISS, wxNORMAL, wxBOLD, false,wxT("宋体")));
    text_size= dc.GetMultiLineTextExtent(str);
    int i_height=text_size.GetHeight();

    wxString str1,str2;
    int i_left,i_right;


    if(i_height>y_scale*110)
    {
        str.Empty();

        i_left = (int)(i_len*y_scale*110/i_height);

        str = _label.s_project_name.Left(i_left);

        for(i=0; i<i_left; i++)
        {
            if(i==i_left-1)
            {
                str1=str1+str.Right(1);
            }
            else
            {

                if(i+1<i_left)
                {
                    str_test1=str.Mid(i,1);
                    str_test2 = str.Mid(i+1,1);

                    if((str_test1.IsNumber()||is_char(str_test1))&&str_test2.IsNumber())
                    {
                        str1=str1+str.Mid(i,1);
                        continue;
                    }


                }
                str1=str1+str.Mid(i,1)+wxT("\n");
            }

        }

        str = _label.s_project_name.Right(i_len-i_left);

        for(i=0; i<i_len-i_left; i++)
        {
            if(i==i_len-i_left-1)
            {
                str2=str2+str.Right(1);
            }
            else
            {
               if(i+1<i_len-i_left)
                {
                    str_test1=str.Mid(i,1);
                    str_test2 = str.Mid(i+1,1);

                    if((str_test1.IsNumber()||is_char(str_test1))&&str_test2.IsNumber())
                    {
                        str1=str1+str.Mid(i,1);

                        continue;
                    }


                }
                str2 = str2+str.Mid(i,1)+wxT("\n");
            }
        }

        text_size = dc.GetMultiLineTextExtent(str2);
        i_height = text_size.GetHeight();
    //    dc.DrawText(str2,s_point.x+x_scale*3,s_point.y+y_scale*45);
        dc.DrawText(str1,s_point.x+x_scale*12, s_point.y+y_scale*45);
        dc.DrawText(str2,s_point.x+x_scale*3,s_point.y+y_scale*100-i_height/2);

    }
    else
    {
        i_height = dc.GetTextExtent(str).GetWidth();
        dc.DrawText(str,s_point.x+x_scale*6,s_point.y+y_scale*100-i_height/2);
    }
  /*  i_left=17;

    if(i_len>i_left)
    {
        str.Empty();


        str = _label.s_project_name.Right(i_len-i_left);

        for(i=0; i<i_left; i++)
        {
            if(i==i_left-1)
            {
                str1=str1+_label.s_project_name.Right(1);
            }
            else
            {
                str1=str1+_label.s_project_name.Mid(i,1)+wxT("\n");
            }

        }

        for(i=0; i<i_len-i_left; i++)
        {
            if(i==i_len-i_left-1)
            {
                str2=str2+str.Right(1);
            }
            else
            {
                str2 = str2+str.Mid(i,1)+wxT("\n");
            }
        }

        dc.DrawText(str1,s_point.x+x_scale*3,s_point.y+y_scale*45);
        dc.DrawText(str2,s_point.x+x_scale*12, s_point.y+y_scale*45);

    }
    else
    {
        i_height = dc.GetTextExtent(str).GetWidth();
        dc.DrawText(str,s_point.x+x_scale*6,s_point.y+y_scale*100-i_height/2);
    }
*/

    if(_label.s_contract_id.IsEmpty())
    {
        wxLogMessage(_("请尽快补全合同号"));
    }else
    {
        dc.SetFont(wxFont(font_height3, wxSWISS, wxNORMAL, wxBOLD, false,wxT("TkTypeRegular")));

        text_size= dc.GetTextExtent(_label.s_contract_id);
        dc.DrawText(_label.s_contract_id, s_point.x+(x_scale*33-text_size.GetWidth())/2,s_point.y+y_scale*155);
    }

    if(StrToInt(_label.s_item_id)>=2)
    {
        dc.SetFont(wxFont(font_height3, wxSWISS, wxNORMAL, wxBOLD, false,wxT("TkTypeRegular")));
        str=wxT("(")+_label.s_item_id+wxT(")");

        text_size = dc.GetTextExtent(str);

        dc.DrawText(str, s_point.x+(x_scale*33-text_size.GetWidth())/2,s_point.y+y_scale*165);
    }
}



MyPrintout::MyPrintout(const wxString& name, ContractLabelDraw *draw_panel)
{
    m_drawpanel=draw_panel;
    m_Name = name;
    m_NumPages = m_drawpanel->get_pages();



}

MyPrintout::~MyPrintout()
{
    m_drawpanel=NULL;
}

bool MyPrintout::OnPrintPage(int page)
{
    wxDC *dc = GetDC();
    if (dc)
    {
        if(page<=m_NumPages)
        {
            drawpage(*dc, page);
       //     MapScreenSizeToPage();

        }



        return true;
    }
    else
        return false;
}

bool MyPrintout::HasPage(int page)
{
    return (page>0 && page<=m_NumPages);
}

bool MyPrintout::OnBeginDocument(int startPage, int endPage)
{
    if (!wxPrintout::OnBeginDocument(startPage, endPage))
        return false;

    return true;
}

void MyPrintout::GetPageInfo(int *minPage, int *maxPage, int *selPageFrom, int *selPageTo)
{
    *minPage = 1;
    *maxPage = m_NumPages;
    *selPageFrom = 1;
    *selPageTo = m_NumPages;
}

void MyPrintout::drawpage(wxDC&dc, int page)
{

    wxCoord maxX = 210*mm2ppix;
    wxCoord maxY = 297*mm2ppiy;

  //  dc.SetUserScale(x_scale, y_scale);

    FitThisSizeToPageMargins(wxSize(maxX, maxY), *g_pageSetupData);
    wxRect fitRect = GetLogicalPageMarginsRect(*g_pageSetupData);
 //   FitThisSizeToPage(wxSize(maxX, maxY));
  //  wxRect fitRect = GetLogicalPageRect();

    wxCoord xoff = (fitRect.width - maxX) / 2;
    wxCoord yoff = (fitRect.height - maxY) / 2;
    OffsetLogicalOrigin(xoff, yoff);


    m_drawpanel->Draw(dc,page);
}
