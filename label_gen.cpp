#include "label_gen.h"


label_gen::label_gen()
{
    //ctor

    //init the fixed cell value
    m_fixed_value.init_data();


 //   result_pdf = new wxPdfDocument(-1, table_width+2*table_edge_h, table_height+2*table_edge_v);
    AddFontCJK(wxT("simhei"));
    AddFont(wxT("arial"));
    SetMargins(2,2,2);
    SetAutoPageBreak(false);

}

label_gen::~label_gen()
{
    //dtor
 //   delete result_pdf;
}

void label_gen::get_value( v_value_cell & _s_value)
{
    m_value = _s_value;
}

void label_gen::save_pdf_file(wxString s_path)
{
     if(!s_path.IsEmpty())
     {
           SaveAsFile(s_path);
     }else
     {
         SaveAsFile("./temp/temp.pdf");
     }
}

void label_gen::generate_table()
{
    AddPage(-1, table_width+2*table_edge_h, table_height+2*table_edge_v);
    SetFont(wxT("simhei"), wxT(""), font_height2);
 //   SetCellMargin(0);

    //第一行 表头
    Cell(table_width, head_height ,m_fixed_value.s_head,wxPDF_BORDER_FRAME,0, wxPDF_ALIGN_CENTER);
    Ln();

    //第二行
    SetFont(wxT("simhei"), wxT(""), font_height1);
    Cell(table_width/10, cell_height, m_fixed_value.s_project,wxPDF_BORDER_TOP|wxPDF_BORDER_LEFT|wxPDF_BORDER_BOTTOM,0,wxPDF_ALIGN_LEFT);
    Cell(table_width/2 , cell_height, m_value.s_project_name,wxPDF_BORDER_TOP|wxPDF_BORDER_RIGHT|wxPDF_BORDER_BOTTOM,0,wxPDF_ALIGN_LEFT |wxPDF_ALIGN_JUSTIFY);
    Cell(table_width/10, cell_height, m_fixed_value.s_wbs, wxPDF_BORDER_TOP|wxPDF_BORDER_LEFT|wxPDF_BORDER_BOTTOM, 0, wxPDF_ALIGN_LEFT);
    SetFont(wxT("arial"), wxT(""), font_height1);
    Cell(table_width*3/10 , cell_height, m_value.s_wbs,wxPDF_BORDER_TOP|wxPDF_BORDER_RIGHT|wxPDF_BORDER_BOTTOM,0,wxPDF_ALIGN_LEFT |wxPDF_ALIGN_JUSTIFY);
    Ln();

    //第三行
    SetFont(wxT("simhei"), wxT(""), font_height1);
    Cell(table_width/20, cell_height, m_fixed_value.s_lift_no,wxPDF_BORDER_TOP|wxPDF_BORDER_LEFT|wxPDF_BORDER_BOTTOM,0,wxPDF_ALIGN_LEFT);
    SetFont(wxT("arial"), wxT(""), font_height1);
    Cell(table_width/20, cell_height, m_value.s_lift_no,wxPDF_BORDER_TOP|wxPDF_BORDER_RIGHT|wxPDF_BORDER_BOTTOM,0,wxPDF_ALIGN_LEFT);
    SetFont(wxT("simhei"), wxT(""), font_height1);
    Cell(table_width/5, cell_height, m_fixed_value.s_car_weight,wxPDF_BORDER_TOP|wxPDF_BORDER_LEFT|wxPDF_BORDER_BOTTOM,0,wxPDF_ALIGN_LEFT);
    SetFont(wxT("arial"), wxT(""), font_height1);
    Cell(table_width/10, cell_height, m_value.s_car_weight,wxPDF_BORDER_TOP|wxPDF_BORDER_RIGHT|wxPDF_BORDER_BOTTOM,0,wxPDF_ALIGN_LEFT);
    SetFont(wxT("simhei"), wxT(""), font_height1);
    Cell(table_width*3/20, cell_height, m_fixed_value.s_cwt_weight,wxPDF_BORDER_TOP|wxPDF_BORDER_LEFT|wxPDF_BORDER_BOTTOM,0,wxPDF_ALIGN_LEFT);
    SetFont(wxT("arial"), wxT(""), font_height1);
    Cell(table_width/20, cell_height, m_value.s_cwt_weight,wxPDF_BORDER_TOP|wxPDF_BORDER_RIGHT|wxPDF_BORDER_BOTTOM,0,wxPDF_ALIGN_LEFT);
    SetFont(wxT("simhei"), wxT(""), font_height1);
    Cell(table_width*3/20, cell_height, m_fixed_value.s_dc_weight, wxPDF_BORDER_TOP|wxPDF_BORDER_LEFT|wxPDF_BORDER_BOTTOM ,0,wxPDF_ALIGN_LEFT);
    SetFont(wxT("arial"), wxT(""), font_height1);
    Cell(table_width/10, cell_height, m_value.s_dc_weight,wxPDF_BORDER_TOP|wxPDF_BORDER_RIGHT|wxPDF_BORDER_BOTTOM,0,wxPDF_ALIGN_LEFT);
    SetFont(wxT("simhei"), wxT(""), font_height1);
    Cell(table_width*1/10, cell_height, m_fixed_value.s_rate, wxPDF_BORDER_TOP|wxPDF_BORDER_LEFT|wxPDF_BORDER_BOTTOM ,0,wxPDF_ALIGN_LEFT);
    SetFont(wxT("arial"), wxT(""), font_height1);
    Cell(table_width/20, cell_height, m_value.s_rate, wxPDF_BORDER_TOP|wxPDF_BORDER_RIGHT|wxPDF_BORDER_BOTTOM,0,wxPDF_ALIGN_LEFT);
    Ln();

    //第四行
    SetFont(wxT("simhei"), wxT(""), font_height1);
    Cell(table_width/5, cell_height, m_fixed_value.s_sub_head1, wxPDF_BORDER_FRAME, 0, wxPDF_ALIGN_CENTER);
    Cell(table_width/5, cell_height, m_fixed_value.s_sub_head2, wxPDF_BORDER_FRAME,0, wxPDF_ALIGN_CENTER);
    Cell(table_width/5, cell_height, m_fixed_value.s_sub_head3, wxPDF_BORDER_FRAME,0, wxPDF_ALIGN_CENTER);
    Cell(table_width *3/20, cell_height, m_fixed_value.s_sub_head4, wxPDF_BORDER_FRAME,0, wxPDF_ALIGN_CENTER);
    Cell(table_width /10, cell_height, m_fixed_value.s_sub_head5, wxPDF_BORDER_FRAME,0, wxPDF_ALIGN_CENTER);
    Cell(table_width *3/20, cell_height, m_fixed_value.s_sub_head6, wxPDF_BORDER_FRAME,0, wxPDF_ALIGN_CENTER);
    Ln();

    //第五行
    Cell(table_width/5, cell_height, m_fixed_value.s_balance_block_qty, wxPDF_BORDER_FRAME,0, wxPDF_ALIGN_CENTER);
    SetFont(wxT("arial"), wxT(""), font_height1);
    Cell(table_width/5, cell_height, m_value.s_balance_block_qty, wxPDF_BORDER_FRAME,0, wxPDF_ALIGN_CENTER);
    Cell(table_width/5, cell_height, wxT(""), wxPDF_BORDER_FRAME,0, wxPDF_ALIGN_CENTER);
    Cell(table_width *3/20, cell_height, wxT(""), wxPDF_BORDER_FRAME,0, wxPDF_ALIGN_CENTER);
    Cell(table_width/10, cell_height, wxT(""), wxPDF_BORDER_FRAME,0, wxPDF_ALIGN_CENTER);
    Cell(table_width *3/20, cell_height, wxT(""), wxPDF_BORDER_FRAME,0, wxPDF_ALIGN_CENTER);
    Ln();

    //第六行
    SetFont(wxT("simhei"), wxT(""), font_height1);
    Cell(table_width/5, 13, m_fixed_value.s_sub_head17, wxPDF_BORDER_FRAME, 0, wxPDF_ALIGN_CENTER);
    Cell(table_width/15, cell_height, m_fixed_value.s_sub_head18, wxPDF_BORDER_FRAME, 0, wxPDF_ALIGN_LEFT);
  //  SetFont(wxT("arial"), wxT(""), font_height1);
    Cell(table_width*2/15, cell_height, m_value.s_cwt_block_qty_dc_before, wxPDF_BORDER_FRAME, 0, wxPDF_ALIGN_CENTER);
  //  SetFont(wxT("simhei"), wxT(""), font_height1);
    Cell(table_width/15,cell_height, m_fixed_value.s_sub_head20, wxPDF_BORDER_FRAME, 0, wxPDF_ALIGN_LEFT);
    Cell(table_width*2/15,cell_height, wxT(""),wxPDF_BORDER_FRAME);
    Cell(table_width*3/20,cell_height,wxT(""),wxPDF_BORDER_FRAME);
    Cell(table_width/10,cell_height, wxT(""),wxPDF_BORDER_FRAME);
    Cell(table_width/20, cell_height, m_fixed_value.s_block_material1, wxPDF_BORDER_TOP|wxPDF_BORDER_LEFT,0,wxPDF_ALIGN_LEFT|wxPDF_ALIGN_BOTTOM);
    SetFont(wxT("arial"), wxT(""), font_height1);
    Cell(table_width/10, cell_height, m_value.s_block_material1, wxPDF_BORDER_TOP|wxPDF_BORDER_RIGHT,0,wxPDF_ALIGN_LEFT|wxPDF_ALIGN_BOTTOM);
    Ln();

    //第七行
    SetFont(wxT("simhei"), wxT(""), font_height1);
    Cell(table_width/5, cell_height, wxT(""), wxPDF_BORDER_NONE);
    Cell(table_width/15, cell_height, m_fixed_value.s_sub_head19, wxPDF_BORDER_FRAME, 0, wxPDF_ALIGN_LEFT);
  //  SetFont(wxT("arial"), wxT(""), font_height1);
    Cell(table_width*2/15, cell_height, m_value.s_cwt_block_qty_dc_after, wxPDF_BORDER_FRAME, 0, wxPDF_ALIGN_CENTER);
  //  SetFont(wxT("simhei"), wxT(""), font_height1);
    Cell(table_width/15,cell_height, m_fixed_value.s_sub_head21, wxPDF_BORDER_FRAME, 0, wxPDF_ALIGN_LEFT);
    Cell(table_width*2/15,cell_height, wxT(""),wxPDF_BORDER_FRAME);
    Cell(table_width*3/20,cell_height,wxT(""),wxPDF_BORDER_FRAME);
    Cell(table_width/10,cell_height, wxT(""),wxPDF_BORDER_FRAME);
    Cell(table_width/20, cell_height, m_fixed_value.s_block_material2, wxPDF_BORDER_LEFT|wxPDF_BORDER_BOTTOM,0,wxPDF_ALIGN_LEFT|wxPDF_ALIGN_TOP);
    SetFont(wxT("arial"), wxT(""), font_height1);
    Cell(table_width/10, cell_height, m_value.s_block_material2, wxPDF_BORDER_RIGHT|wxPDF_BORDER_BOTTOM,0,wxPDF_ALIGN_LEFT|wxPDF_ALIGN_TOP);
    Ln();

    //第八行
    SetFont(wxT("simhei"), wxT(""), font_height1);
    Cell(table_width/5, cell_height, m_fixed_value.s_sub_head7, wxPDF_BORDER_FRAME, 0, wxPDF_ALIGN_CENTER);
    Cell(table_width/5, cell_height,m_fixed_value.s_sub_head8, wxPDF_BORDER_FRAME,0, wxPDF_ALIGN_CENTER);
    Cell(table_width/5, cell_height, m_fixed_value.s_sub_head9, wxPDF_BORDER_FRAME,0, wxPDF_ALIGN_CENTER);
    Cell(table_width *3/20, cell_height, m_fixed_value.s_sub_head10, wxPDF_BORDER_FRAME,0, wxPDF_ALIGN_CENTER);
    Cell(table_width /10, cell_height, m_fixed_value.s_sub_head11, wxPDF_BORDER_FRAME,0, wxPDF_ALIGN_CENTER);
    Cell(table_width *3/20, cell_height, wxT(""), wxPDF_BORDER_FRAME,0, wxPDF_ALIGN_CENTER);
    Ln();

    //第九行
    SetFont(wxT("simhei"), wxT(""), font_height1);
    Cell(table_width*3/20, cell_height, m_fixed_value.s_sub_head22, wxPDF_BORDER_LEFT, 0, wxPDF_ALIGN_CENTER );
    Cell(table_width/20, cell_height, m_fixed_value.s_sub_head23, wxPDF_BORDER_FRAME, 0, wxPDF_ALIGN_CENTER);
    SetFont(wxT("arial"), wxT(""), font_height1);
    Cell(table_width/5, cell_height, m_value.s_tm_spring_length_left, wxPDF_BORDER_FRAME, 0, wxPDF_ALIGN_CENTER);
    SetFont(wxT("simhei"), wxT(""), font_height1);
    Cell(table_width/5,cell_height, wxT(""), wxPDF_BORDER_FRAME);
    Cell(table_width*3/20,cell_height,wxT(""),wxPDF_BORDER_FRAME);
    Cell(table_width/10,cell_height, wxT(""),wxPDF_BORDER_FRAME);
    Cell(table_width*3/20, cell_height, wxT("") , wxPDF_BORDER_FRAME);
    Ln();

    //第十行
    Cell(table_width*3/20, cell_height, m_fixed_value.s_sub_head25, wxPDF_BORDER_LEFT, 0, wxPDF_ALIGN_CENTER);
    Cell(table_width/20, cell_height, m_fixed_value.s_sub_head24, wxPDF_BORDER_FRAME, 0, wxPDF_ALIGN_CENTER);
    SetFont(wxT("arial"), wxT(""), font_height1);
    Cell(table_width/5, cell_height, m_value.s_tm_spring_length_right, wxPDF_BORDER_FRAME, 0, wxPDF_ALIGN_CENTER);
    SetFont(wxT("simhei"), wxT(""), font_height1);
    Cell(table_width/5,cell_height, wxT(""), wxPDF_BORDER_FRAME);
    Cell(table_width*3/20,cell_height,wxT(""),wxPDF_BORDER_FRAME);
    Cell(table_width/10,cell_height, wxT(""),wxPDF_BORDER_FRAME);
    Cell(table_width*3/20, cell_height, wxT("") , wxPDF_BORDER_FRAME);
    Ln();

    //第十一行
    Cell(table_width*2/5,cell_height, m_fixed_value.s_sub_head12, wxPDF_BORDER_FRAME,0, wxPDF_ALIGN_CENTER);
    Cell(table_width/20, cell_height ,m_fixed_value.s_buffer_no_car, wxPDF_BORDER_TOP|wxPDF_BORDER_LEFT|wxPDF_BORDER_BOTTOM,0, wxPDF_ALIGN_LEFT);
    SetFont(wxT("arial"), wxT(""), font_height1);
    Cell(table_width/5, cell_height ,m_value.s_buffer_no_car, wxPDF_BORDER_TOP|wxPDF_BORDER_RIGHT|wxPDF_BORDER_BOTTOM,0, wxPDF_ALIGN_LEFT);
    SetFont(wxT("simhei"), wxT(""), font_height1);
    Cell(table_width/20, cell_height,m_fixed_value.s_buffer_no_cwt,wxPDF_BORDER_TOP|wxPDF_BORDER_LEFT|wxPDF_BORDER_BOTTOM, 0,wxPDF_ALIGN_LEFT);
    SetFont(wxT("arial"), wxT(""), font_height1);
    Cell(table_width*3/20, cell_height ,m_value.s_buffer_no_cwt, wxPDF_BORDER_TOP|wxPDF_BORDER_RIGHT|wxPDF_BORDER_BOTTOM,0, wxPDF_ALIGN_LEFT);
    Cell(table_width*3/20,cell_height, wxT(""), wxPDF_BORDER_FRAME);
    Ln();

    //第十二行
    SetFont(wxT("simhei"), wxT(""), font_height1);
    Cell(table_width*2/5,cell_height, m_fixed_value.s_sub_head13, wxPDF_BORDER_FRAME,0, wxPDF_ALIGN_CENTER);
    Cell(table_width/20, cell_height ,m_fixed_value.s_govern_no_car, wxPDF_BORDER_TOP|wxPDF_BORDER_LEFT|wxPDF_BORDER_BOTTOM,0, wxPDF_ALIGN_LEFT);
    SetFont(wxT("arial"), wxT(""), font_height1);
    Cell(table_width/5, cell_height ,m_value.s_govern_no_car, wxPDF_BORDER_TOP|wxPDF_BORDER_RIGHT|wxPDF_BORDER_BOTTOM,0, wxPDF_ALIGN_LEFT);
    SetFont(wxT("simhei"), wxT(""), font_height1);
    Cell(table_width/20, cell_height,m_fixed_value.s_govern_no_cwt,wxPDF_BORDER_TOP|wxPDF_BORDER_LEFT|wxPDF_BORDER_BOTTOM, 0,wxPDF_ALIGN_LEFT);
    SetFont(wxT("arial"), wxT(""), font_height1);
    Cell(table_width*3/20, cell_height ,m_value.s_govern_no_cwt, wxPDF_BORDER_TOP|wxPDF_BORDER_RIGHT|wxPDF_BORDER_BOTTOM,0, wxPDF_ALIGN_LEFT);
    Cell(table_width*3/20,cell_height, wxT(""), wxPDF_BORDER_FRAME);
    Ln();

    //第十三行
    SetFont(wxT("simhei"), wxT(""), font_height1);
    Cell(table_width*2/5,cell_height, m_fixed_value.s_sub_head14, wxPDF_BORDER_FRAME,0, wxPDF_ALIGN_CENTER);
    Cell(table_width/20, cell_height ,m_fixed_value.s_safe_guard_no_car, wxPDF_BORDER_TOP|wxPDF_BORDER_LEFT|wxPDF_BORDER_BOTTOM,0, wxPDF_ALIGN_LEFT);
    SetFont(wxT("arial"), wxT(""), font_height1);
    Cell(table_width/5, cell_height ,m_value.s_safe_guard_no_car, wxPDF_BORDER_TOP|wxPDF_BORDER_RIGHT|wxPDF_BORDER_BOTTOM,0, wxPDF_ALIGN_LEFT);
    SetFont(wxT("simhei"), wxT(""), font_height1);
    Cell(table_width/20, cell_height,m_fixed_value.s_safe_guard_no_cwt, wxPDF_BORDER_TOP|wxPDF_BORDER_LEFT|wxPDF_BORDER_BOTTOM,0,wxPDF_ALIGN_LEFT);
    SetFont(wxT("arial"), wxT(""), font_height1);
    Cell(table_width*3/20, cell_height ,m_value.s_safe_guard_no_cwt, wxPDF_BORDER_TOP|wxPDF_BORDER_RIGHT|wxPDF_BORDER_BOTTOM,0, wxPDF_ALIGN_LEFT);
    Cell(table_width*3/20,cell_height, wxT(""), wxPDF_BORDER_FRAME);
    Ln();

    //第十四行
    SetFont(wxT("simhei"), wxT(""), font_height1);
    Cell(table_width*2/5, cell_height, m_fixed_value.s_sub_head15, wxPDF_BORDER_FRAME, 0, wxPDF_ALIGN_CENTER);
    SetFont(wxT("arial"), wxT(""), font_height1);
    Cell(table_width*9/20, cell_height, m_value.s_mainboard_no, wxPDF_BORDER_FRAME, 0, wxPDF_ALIGN_CENTER);
    Cell(table_width*3/20,cell_height, wxT(""), wxPDF_BORDER_FRAME);
    Ln();

    //第十五行
    SetFont(wxT("simhei"), wxT(""), font_height1);
    Cell(table_width*2/5, cell_height, m_fixed_value.s_sub_head16, wxPDF_BORDER_FRAME, 0, wxPDF_ALIGN_CENTER);
    SetFont(wxT("arial"), wxT(""), font_height1);
    Cell(table_width*9/20, cell_height, m_value.s_tm_no, wxPDF_BORDER_FRAME, 0, wxPDF_ALIGN_CENTER);
    Cell(table_width*3/20,cell_height, wxT(""), wxPDF_BORDER_FRAME);

}


