#ifndef LABEL_GEN_H
#define LBAEL_GEN_H

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/pdfdoc.h"
#include "stdafx.h"

class label_gen : public wxPdfDocument
{
    public:
        label_gen();
        virtual ~label_gen();
        void generate_table();
        void save_pdf_file(wxString s_path=wxEmptyString);
    protected:
    private:
        void get_value(v_value_cell & _s_value);
        v_fixed_cell m_fixed_value;
        v_value_cell m_value;

};
/*
class label_pdf_printout : public wxPrintout
{
public:
    label_pdf_printout(wxPdfDocument * pdf_doc, const wxString& title = wxGetTranslation("Printout"));
    virtual ~label_pdf_printout();

    // wxPrintout virtual functions
    virtual bool OnPrintPage(int page);
    virtual bool HasPage(int page);
    virtual void GetPageInfo(int *minPage, int *maxPage, int *selPageFrom, int *selPageTo);
    virtual bool OnBeginDocument(int startPage, int endPage);
    virtual void OnPreparePrinting();

private:

    /// Renders one page into dc
    void RenderPage(wxDC *dc, int page);

private:

    wxPdfDocument *             m_pdf_doc;
    int                         m_numPages;
    wxArrayInt                  m_pageBreaksStart;
    wxArrayInt                  m_pageBreaksEnd;
    wxArrayInt                  m_pageYOffsets;
    int                         m_marginLeft, m_marginTop, m_marginRight, m_marginBottom;


//    wxDECLARE_NO_COPY_CLASS(label_pdf_printout);
};*/
#endif // LABEL_GEN_H
