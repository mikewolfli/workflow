#include "wf_stdafx.h"
#include <wx/log.h>

wxArrayString split_string(wxString src, wxString split_main_str, wxString serial_str, wxString individual_str, int unit_length, bool end_str)
{
    wxArrayString dest_str, src_str;
    wxString strtemp,strtemp1,strtemp2, strhead;
    int icount, itemp=0, ipos=0 ,ipos1,itemp1,itemp2,i,j;


    if(split_main_str == serial_str || split_main_str == individual_str && serial_str == individual_str)
    {
        wxLogMessage(_("分割字符不能相同,返回源字符串:")+src);
        dest_str.Add(src);
        return dest_str;
    }
//    src.Trim();

    if(end_str)
        src = src.RemoveLast(split_main_str.Length());

    if(!split_main_str.IsEmpty())
    {
        if(split_main_str.Contains(wxT("\\t")))
            split_main_str.Replace(wxT("\\t"),wxT("\t"));
        if(split_main_str.Contains(wxT("\\r")))
            split_main_str.Replace(wxT("\\r"),wxT("\r"));
        if(split_main_str.Contains(wxT("\\n")))
            split_main_str.Replace(wxT("\\n"),wxT("\n"));
        src_str = wxStringTokenize(src,split_main_str, wxTOKEN_RET_EMPTY_ALL );
    }
    else src_str.Add(src);

    if(unit_length<=0)
        dest_str = src_str;
    else
    {

        ipos=0;
        for(i =0; i< src_str.GetCount(); i++)
        {
            if(!src_str.Item(i).Contains(individual_str)&&!src_str.Item(i).Contains(serial_str))
            {
                if(src_str.Item(i).IsEmpty())
                    continue;
                dest_str.Add(src_str.Item(i));
                continue;
            }


            icount = getstrcount(src_str.Item(i),individual_str)+1;
            strhead=src_str.Item(i).Left(unit_length);

            itemp=unit_length;
            for (j=0; j<icount; j++)
            {
                ipos = src_str.Item(i).find(individual_str,ipos+1);
                if(ipos==wxNOT_FOUND)
                {
                    strtemp = src_str.Item(i).SubString(itemp+1,src_str.Item(i).Length()-1);
                }
                else
                    strtemp = src_str.Item(i).SubString(itemp+1,ipos-1);
                itemp=ipos;

                if(!strtemp.Contains(serial_str))
                {
                    strtemp = strhead + strtemp;
                    dest_str.Add(strtemp);
                }
                else
                {
                    ipos1 = strtemp.find(serial_str,0);
                    strtemp1=strtemp.Left(ipos1);
                    strtemp2=strtemp.Right(strtemp.Length()-ipos1-1);
                    itemp1 = wxAtoi(strtemp1);
                    itemp2 = wxAtoi(strtemp2);
                    for (int i=0; i<itemp2-itemp1+1; i++)
                    {
                        strtemp1=wxString::Format(wxT("%i"),itemp1+i);
                        if(strtemp1.Length()==1)
                            strtemp1=_T("00")+strtemp1;
                        else if(strtemp1.Length()==2)
                            strtemp1=_T("0")+strtemp1;

                        strtemp=strhead+strtemp1;

                        dest_str.Add(strtemp);
                    }

                }
            }

        }
    }
    return dest_str;


}

int nstd_action_to_status(wxString s_action_id)
{
   s_action_id.Remove(0,2);
   int i_action = wxAtoi(s_action_id);

   switch(i_action)
   {
   case 9:
   case 12:
   case 16:
       return 0;
   case 10:
   case 13:
   case 14:
   case 17:
       return 1;
   case 11:
   case 15:
   case 18:
       return 2;
   case 22:
   case 24:
       return 3;
   case 23:
       return 4;
   case 19:
   case 20:
       return 5;
   default:
       break;
   }

   return -1;
}

void clear_dup_array(wxArrayString &arr)
{
     wxArrayString arr_temp = arr;

      arr.Clear();

      int i_count = arr_temp.GetCount();

      for(int i=0;i<i_count;i++)
      {
          wxString str = arr_temp.Item(i);
          if(arr.Index(str)==wxNOT_FOUND)
                arr.Add(str);
      }
}

int getstrcount(wxString str, wxString cf)
{
    int icount= str.Length();
    int istep = cf.Length();
    int istr=0;
    for (int i=0; i<icount-istep+2; i++)
    {
        if(cf==str.Mid(i,istep))
        {
            istr+=1;
        }
    }

    return istr;
}

wxArrayString combine_str(wxArrayString & array_str,wxString split_main_str, wxString serial_str, wxString individual_str, bool ck_sort,bool one_str)
{
    wxArrayString strhead,strresult;
    wxString str1,str2,strtemp;
    strhead = sort_array_string(array_str, ck_sort);
    int i,j,icount,icount_head,k;
    icount = array_str.GetCount();
    icount_head=strhead.GetCount();

    for(i=0; i<icount_head; i++)
    {
        k=0;
        for (j=0; j<icount; j++)
        {
            if(array_str.Item(j).Left(10)==strhead.Item(i))
            {
                if(k==0)
                {
                    str1=array_str.Item(j).Right(3);
                    k++;
                    continue;
                }

                if(serial_str.IsEmpty())
                {
                    //str1=str1+individual_str+array_str.Item(j).Right(3);
                    str1=str1+individual_str+array_str.Item(j);
                    k++;
                    continue;
                }

                k++;
                str2 = array_str.Item(j).Right(3);
                if(wxAtoi(str2)-wxAtoi(str1.Right(3))>1)
                {
                    str1=str1+individual_str+str2;
                    continue;
                }

                strtemp=str1.Right(serial_str.length()+3);
                if(strtemp.Contains(serial_str))
                {
                    str1.RemoveLast(3);
                    str1=str1+str2;
                }
                else
                    str1 = str1+serial_str+str2;

            }

        }

        str1 = strhead.Item(i) + wxT(".") +str1;
        strresult.Add(str1);
    }

    if(one_str)
    {
        strhead.Clear();
        str1 = strresult.Item(0);
        for(i=1; i<icount_head; i++)
        {
            str1=str1+split_main_str+strresult.Item(i);
        }
        strhead.Add(str1);
        return strhead;
    }

    return strresult;
}


int function_sort(wxString &str1, wxString &str2)
{
    return wxAtoi(str2.Right(3))-wxAtoi(str1.Right(3));
}

long wbs_sort(wxString &str1, wxString &str2)
{
    wxString sr1= str1.Upper();
    sr1.Replace(wxT("E/3"),wxT(""));
    sr1.Replace(wxT("."),wxT(""));

    wxString sr2= str2.Upper();
    sr2.Replace(wxT("E/3"),wxT(""));
    sr2.Replace(wxT("."),wxT(""));

    return wxAtol(sr2)-wxAtol(sr1);
}

wxArrayString sort_array_string(wxArrayString &array_str, bool ck_sort)
{
    wxArrayString strhead;

    if(!ck_sort)
    {
        array_str.Sort(function_sort);
        array_str.Sort(true);
    }

    int icount = array_str.GetCount();

    strhead.Add(array_str.Item(0).Left(10));
    for(int i = 1; i<icount; i++)
    {
        if(strhead.Index(array_str.Item(i).Left(10),false,false)== wxNOT_FOUND)
            strhead.Add(array_str.Item(i).Left(10));
    }
    return strhead;
}


wxString qtIdent(const wxString &value, bool b_needquote)
{
    if (value.Length() == 0)
        return value;

    wxString result = value;

    if (b_needquote)
    {
        result.Replace(wxT("\""), wxT("\"\""));
        return wxT("\"") + result + wxT("\"");
    }
    else
        return result;
}


wxString zero_begin(long current_int, int length)
{
    wxString result;

    result= NumToStr(current_int);

    int len = result.Length();

    for(int i=0; i<length-len; i++)
    {
        result=wxT("0")+result;
    }

    return result;
}


wxString get_str_val(wxString str,wxArrayString &_header, wxArrayString &_value)
{
    int ifound = _header.Index(str);
    if(ifound == wxNOT_FOUND)
        return wxEmptyString;

    return _value.Item(ifound);
}

int find_in_array(wxString _str, wxArrayString &_array )
{
      return _array.Index(_str);
}


wxString nstd_status_to_str(int i_status)
{
    wxString str;
    switch(i_status)
    {
       case -1 :
         str =  wxT("DEL");
         break;
       case 0:
         str =  wxT("CRTD");
         break;
       case 1:
          str =  wxT("SUBMIT");
          break;
       case 2:
         str =  wxT("APPROVE");
         break;
       case 3:
         str =  wxT("PROC");
         break;
       case 4:
         str =  wxT("FEEDBACK");
         break;
       case 5:
         str = wxT("PDM-READY");
         break;
       case 6:
         str = wxT("SAP-READY");
         break;
       case 7:
          str = wxT("DOC-READY");
          break;
       case 8:
          str = wxT("ALL-READY");
          break;
       case 10:
         str =  wxT("CLOSED");
         break;
       default:
           str.Empty();
         break;
    }
    return str;
}

int nstd_str_to_status(wxString str_status)
{
    if(str_status == wxT("DEL"))
       return -1;

    if(str_status == wxT("CRTD"))
        return 0;


    if(str_status == wxT("SUBMIT"))
        return 1;

    if(str_status == wxT("APPROVE"))
        return 2;


    if(str_status == wxT("PROC"))
        return 3;

    if(str_status == wxT("FEEDBACK"))
        return 4;

    if(str_status == wxT("PDM-READY"))
        return 5;

    if(str_status == wxT("SAP-READY"))
        return 6;

    if(str_status == wxT("DOC-READY"))
        return 7;

    if(str_status == wxT("ALL-READY"))
        return 8;

    if(str_status == wxT("CLOSED"))
        return 10;

    return -2;
}

int nstd_str_to_level(wxString str_status)
{
    if(str_status == wxT("Target STD"))
       return 1;

    if(str_status == wxT("Option STD"))
        return 2;


    if(str_status == wxT("Simple Non-STD"))
        return 3;

    if(str_status == wxT("Complex Non-STD"))
        return 4;


    if(str_status == wxT("Comp-Standard"))
        return 5;

    if(str_status == wxT("Comp-Measurement"))
        return 6;

    if(str_status == wxT("Comp-Configurable"))
        return 7;

    if(str_status == wxT("Design Fault-Qty."))
        return 11;

    if(str_status == wxT("Design Fault-Spec."))
        return 12;

    if(str_status == wxT("Sales Order Fault-Qt"))
        return 13;

    if(str_status == wxT("Sales Order Fault-Sp"))
        return 14;

    if(str_status == wxT("Matl Pick Fault-Qty."))
        return 15;

    if(str_status == wxT("Matl Pick Fault-Spec"))
        return 16;

    if(str_status == wxT("Packing Fault-Qty."))
        return 17;

    if(str_status == wxT("Packing Fault-Spec."))
        return 18;

    if(str_status == wxT("Logistic Fault."))
        return 19;

    if(str_status == wxT("Abnormal in logistic"))
        return  21;

    if(str_status == wxT("ATI or ECR."))
        return 22;

    if(str_status == wxT("Others"))
        return 23;

    return 0;
}

wxString nstd_level_to_str(int i_status)
{
    wxString str;
    switch(i_status)
    {

    case 1:
        str = wxT("Target STD");
        break;
    case 2:
        str = wxT("Option STD");
        break;
    case 3:
        str = wxT("Simple Non-STD");
        break;
    case 4:
        str = wxT("Complex Non-STD");
        break;
    case 5:
        str = wxT("Comp-Standard");
        break;
    case 6:
        str = wxT("Comp-Measurement");
        break;
    case 7:
        str = wxT("Comp-Configurable");
        break;
    case 11:
        str = wxT("Design Fault-Qty.");
        break;
    case 12:
        str = wxT("Design Fault-Spec.");
        break;
    case 13:
        str = wxT("Sales Order Fault-Qt");
        break;
    case 14:
        str = wxT("Sales Order Fault-Sp");
        break;
    case 15:
        str = wxT("Matl Pick Fault-Qty.");
        break;
    case 16:
        str = wxT("Matl Pick Fault-Spec");
        break;
    case 17:
        str = wxT("Packing Fault-Qty.");
        break;
    case 18:
        str = wxT("Packing Fault-Spec.");
        break;
    case 19:
        str = wxT("Logistic Fault.");
        break;
    case 21:
        str = wxT("Abnormal in logistic");
        break;
    case 22:
        str = wxT("ATI or ECR.");
        break;
    case 23:
        str = wxT("Others");
        break;
    default:
        str.Empty();
        break;
    }

    return str;
}

wxString prj_catalog_to_str(int i_prj)
{
    wxString str;
    switch(i_prj)
    {

    case 1:
        str = wxT("Common Project");
        break;
    case 2:
        str = wxT("High-Speed Project");
        break;
    case 3:
        str = wxT("Special Project");
        break;
    case 4:
        str = wxT("Major Project");
        break;
    case 5:
        str = wxT("Pre_engineering");
        break;
    case 6:
        str = wxT("Lean Project");
        break;
    default:
        str.Empty();
        break;
    }

    return str;
}

char* wxstring2char(wxString str)
{
    int nlen = str.Length()+1;

    char *chr= new  char [nlen];
    strncpy(chr, (const char*)str.mb_str(wxConvUTF8), nlen-1);
  //   memcpy(chr,(const char*)str.mb_str(wxConvUTF8), nlen);
  // char *  chr = (const_cast<char*>((const char*)str.mb_str()));
    return chr;
}

wxString char2wxstring(char* ch)
{
    return wxString(ch, wxConvUTF8);
}

wxString Combine_lift_no(wxArrayString& a_lift_no)
{
    int i_count =a_lift_no.GetCount();

    wxString s_result;

    wxArrayString a_head, a_fol;

    wxString s_head, s_fol;

    for(int i=0;i<i_count;i++)
    {
        if(a_lift_no.Item(i).Right(1)==wxT("*"))
            a_lift_no.Item(i).RemoveLast(1);

        if(!sub_lift_no_str(a_lift_no.Item(i), s_head,s_fol))
              s_head=s_fol=a_lift_no.Item(i);

        a_head.Add(s_head);
        a_fol.Add(s_fol);
    }

    wxString str, s_lift_no,s_start,s_end,s_end_before;
    int i_step=0;

    s_lift_no=a_lift_no.Item(0);
    str=a_head.Item(0);
    s_start = a_fol.Item(0);


    for(int i=1;i<i_count;i++)
    {
        if(a_head.Item(i)==a_lift_no.Item(i))
        {
            s_lift_no=s_lift_no+wxT(",")+a_lift_no.Item(i);
            continue;
        }

        if(str==a_head.Item(i))
        {
            i_step++;


            s_end=a_fol.Item(i);

            if(wxAtoi(a_fol.Item(i))-wxAtoi(s_start)==i_step)
            {

                s_end_before=s_end;
                if(i==i_count-1)
                {
                    if(i_step>1)
                        s_lift_no=s_lift_no+wxT("~")+s_end;
                    else
                        s_lift_no=s_lift_no+wxT(",")+str+s_end;
                }

            }
            else
            {

                if(i_step==1)
                    s_lift_no=s_lift_no+wxT(",")+str+s_end;
                else
                    s_lift_no = s_lift_no+wxT("~")+s_end_before+wxT(",")+s_head+s_end;

                s_start=a_fol.Item(i);
                i_step = 0;


            }

        }else
        {

            i_step=0;
            str=a_head.Item(i);
            s_start= a_fol.Item(i);

            s_lift_no=s_lift_no+wxT(",")+str+s_start;

        }
    }

    a_head.Clear();
    a_fol.Clear();
    return s_lift_no;
}

bool sub_lift_no_str(wxString lift_no, wxString &s_head, wxString &s_fol)
{

    if(lift_no.IsEmpty())
    {
        return  false;
    }

    int i_len =lift_no.Length();

    if(i_len==1)
    {
        return false;
    }

    wxString str1, str2;

    s_head.Empty();
    s_fol.Empty();


    if(lift_no.Left(1).IsNumber())
    {
        return false;
    }

    int i,j;


    for(i=0;i<i_len-1;i++)
    {
        str1=lift_no.Mid(i,1);
        str2 = lift_no.Mid(i+1,1);
        if(!str1.IsNumber()&&str2.IsNumber())
        {
            str1=lift_no.Left(i+1);
            str2 = lift_no.Right(i_len-i-1);

            for(j=0; j<i_len-i-1; j++)
            {
                if(str2.Mid(j,1).IsNumber())
                    continue;
                else
                    return false;
            }

            s_head=str1;
            s_fol=str2;
            break;
        }

    }

    return true;
}

wxString Int2Hex(wxString line)
{
    int i_string = StrToInt(line);
    int i_len = line.Length();
     char  c_hex[i_len+1];

   //  wxMessageBox(NumToStr(i_string));
     itoa(i_string, c_hex, 16);

     wxString out,str;
      str = wxString(c_hex);
     str =  str.Upper();
     i_len = str.Length();

    int i_count;
    if(i_len%2==0)
        i_count =i_len/2;
    else
    {
        str= wxT("0")+str;
        i_count = (int)(i_len/2)+1;
    }

    for(int j=i_count-1;j>=0;j--)
    {
        out = out+ str.Mid(2*j,2)+wxT(" ");
    }
    return out;

}

int prj_str_to_catalog(wxString str_catalog)
{
    if(str_catalog == wxT("Common Project"))
       return 1;

    if(str_catalog == wxT("High-Speed Project"))
       return 2;

    if(str_catalog == wxT("Special Project"))
       return 3;


    if(str_catalog == wxT("Major Project"))
       return 4;

    if(str_catalog == wxT("Pre_engineering"))
       return 5;

    if(str_catalog == wxT("Lean Project"))
       return 6;

    return -1;
}


wxString prj_status_to_str(int i_prj)
{
    wxString str;
    switch(i_prj)
    {
       case -3:
           str = wxT("Revised");
           break;
       case -2:
          str = wxT("DEL");
          break;
       case -1 :
         str =  wxT("CANCEL");
         break;
       case 0:
         str =  wxT("CRTD");
         break;
       case 1:
         str =  wxT("ACTIVE");
         break;
       case 2:
          str =  wxT("FININISH");
          break;
       case 3:
         str =  wxT("RESTART");
         break;
       case 4:
         str =  wxT("FREEZED");
         break;
       case 5:
         str = wxT("CLOSED");
         break;
       case 6:
         str = wxT("RELEASED");
         break;
       case 7:
         str = wxT("PART FINISH");
         break;
       case 8:
         str = wxT("DELIVERIED");
         break;
       default:
           str.Empty();
         break;
    }
    return str;

}

wxString ncr_status_to_str(int i_ncr)
{
    wxString str;
    switch(i_ncr)
    {
    case -1:
        str = _("已删除");
        break;
    case 0:
        str = _("新建");
        break;
    case 1:
        str = _("等待处理");
        break;
    case 2:
        str = _("处理中");
        break;
    case 3:
        str = _("已回复");
        break;
    case 4:
        str = _("已关闭");
        break;
    default:
        str.Empty();
        break;
    }
    return str;

}

int ncr_str_to_status(wxString s_status)
{
    if(s_status == _("已删除"))
        return -1;

    if(s_status  == _("新建"))
        return  0;

    if(s_status == _("等待处理"))
        return  1;

     if(s_status == _("处理中"))
         return 2;

     if(s_status == _("已回复"))
         return 3;

     if(s_status == _("已关闭"))
         return 4;
}

int prj_str_to_status(wxString str_status)
{
    if(str_status == wxT("Revised"))//for 评审GAD更改。
        return -3;

    if(str_status == wxT("DEL"))
        return -2;

    if(str_status == wxT("CANCEL"))
       return -1;

    if(str_status == wxT("CRTD"))
        return 0;

    if(str_status == wxT("ACTIVE"))
        return 1;

    if(str_status == wxT("FININISH"))
        return 2;

    if(str_status == wxT("RESTART"))
        return 3;

    if(str_status == wxT("FREEZED"))
        return 4;

    if(str_status == wxT("CLOSED"))
        return 5;

    if(str_status == wxT("RELEASED"))
        return 6;

    if(str_status == wxT("PART FINISH"));
        return 7;

    if(str_status == wxT("DELIVERIED"));
       return 8;

    return -2;

}

wxString ct_book_status_to_str( int i_ct)
{
    wxString str;
    switch(i_ct)
    {
       case -1 :
         str =  _("删除");
         break;
       case 0:
       case 1:
         str =  wxT("在架");
          break;
       case 2:
         str =  _("借阅");
         break;
       case 3:
         str =  _("归档");
         break;
       case 4:
         str= _("销毁");
         break;

       default:
           str.Empty();
         break;
    }
    return str;

}

int ct_book_int_to_status(wxString s_status)
{
   if(s_status == _("删除"))
       return -1;

    if(s_status == _("创建"))
        return 0;


    if(s_status == _("在架"))
        return 1;

    if(s_status == _("借阅"))
        return 2;

    if(s_status==_("归档"))
       return 3;

    if(s_status==_("销毁"))
       return 4;

    return -1;
}

wxString communication_status_to_str(int i_status)
{
    wxString str;
    switch(i_status)
    {
       case -1 :
         str =  _("已删除");
         break;
      case 0:
         str =  wxT("关闭");
          break;
       case 1:
         str =  _("等待答复");
         break;
       case 2:
       case 3:
         str =  _("已答复");
         break;
         break;

       default:
           str.Empty();
         break;
    }
    return str;

}

int communication_str_to_status(wxString str_status)
{
    if(str_status == _("已删除"))
       return -1;

    if(str_status == _("等待分公司答复"))
        return 1;


    if(str_status == _("分公司已答复"))
        return 2;

    if(str_status == _("关闭"))
        return 0;

    return -1;
}

wxString urgent_level_to_str(int i_level)
{
    wxString str;
    switch(i_level)
    {
    case 1:
        str = _("普通");
        break;
    case 2:
        str = _("紧急");
        break;
    case 3:
        str = _("特紧急");
        break;
    default:
        str = _("普通");
        break;

    }

    return str;
}

int urgent_str_to_level(wxString s_level)
{
    if(s_level == _("普通"))
      return 1;

    if(s_level ==_("紧急"))
      return 2;

    if(s_level== _("特紧急"))
      return 3;

    return 1;
}


int prj_str_to_nstd_level(wxString str_level)
{

    if(str_level == wxT("Complete Standard"))
        return 1;

    if(str_level == wxT("Option Standard"))
        return 2;

    if(str_level == wxT("Standard Configuration Without PC"))
        return 3;

    if(str_level == wxT("Simple Non-Standard"))
        return 4;

    if(str_level == wxT("Complex Non-Standard"))
        return 5;

    return 0;

}

wxString get_english_char(wxString str, int i_step,bool is_front, bool is_upper)
{
    wxString char_table = wxT("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    wxString str_resutl;

    int i_pos = char_table.Find(str);

    if(i_pos == wxNOT_FOUND)
        return wxEmptyString;

    if(is_front)
    {
        if(i_pos + i_step >=26)
            return wxEmptyString;

        str_resutl =  char_table.Mid(i_pos+i_step, 1);
    }else
     {
         if(i_pos - i_step <0)
            return wxEmptyString;

         str_resutl = char_table.Mid(i_pos-i_step, 1);
     }

     if(is_upper)
        str_resutl.Upper();
     else
        str_resutl.Lower();

     return str_resutl;
}


bool is_char(wxString s_char)
{
    wxString char_table = wxT("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    int i_pos = char_table.Find(s_char.Upper());

    if(i_pos == wxNOT_FOUND)
        return false;
    else
         return true;
}

int task_status_to_int(wxString s_task_status)
{
    if(s_task_status == wxT("CRTD"))
        return 0;

    if(s_task_status == wxT("Approved"))
        return 2;

    if(s_task_status == wxT("Need Approve"))
        return 1;

    if(s_task_status == wxT("DEL"))
        return -1;

    return 0;
}

wxString task_int_to_status(int i_status)
{
   switch(i_status)
   {
   case 0:
       return wxT("CRTD");
   case 1:
       return wxT("Need Approve");
   case 2:
       return wxT("Approved");
   case -1:
       return wxT("DEL");
   default:
       return wxEmptyString;
   }

}


s_basic_info& s_basic_info::operator=(const s_basic_info& other)
{
    if(&other != this)
    {
        s_project_name = other.s_project_name;
        s_balance_block_qty = other.s_balance_block_qty;
 /*
        s_tm_spring_length_left = other.s_tm_spring_length_left;
        s_tm_spring_length_right = other.s_tm_spring_length_right;
        s_mainboard_no = other.s_mainboard_no;
        s_buffer_no_car = other.s_buffer_no_car;
        s_buffer_no_cwt = other.s_buffer_no_cwt;
        s_govern_no_car = other.s_govern_no_car;
        s_govern_no_cwt = other.s_govern_no_cwt;
        s_safe_guard_no_car = other.s_safe_guard_no_car;
        s_safe_guard_no_cwt = other.s_safe_guard_no_cwt;
        s_tm_no = other.s_tm_no;*/

        s_cwt_block_qty_dc_before = other.s_cwt_block_qty_dc_before;
        s_cwt_block_qty_dc_after = other.s_cwt_block_qty_dc_after;
        s_wbs = other.s_wbs;
        s_lift_no = other.s_lift_no;
        s_cwt_weight = other.s_cwt_weight;
        s_dc_weight = other.s_dc_weight;
        s_rate = other.s_rate;

        s_car_weight = other.s_car_weight;
        s_block_material1 = other.s_block_material1;
        s_block_material2 = other.s_block_material2;
        b_has_governor = other.b_has_governor;
        b_has_spring = other.b_has_spring;
    }

     return *this;
}

s_sap_hex_info& s_sap_hex_info::operator=(const  s_sap_hex_info& other)
{
    if(&other != this)
    {
        s_wbs=other.s_wbs;

        s_tc_mat=other.s_tc_mat;
        s_tc_mat_name = other.s_tc_mat_name;
        s_tc_hex = other.s_tc_hex;

        s_cchain_mat = other.s_cchain_mat;
        s_cchain_name = other.s_cchain_name;
        s_cchain_hex = other.s_cchain_hex;

        s_rope_mat = other.s_rope_mat;
        s_rope_name = other.s_rope_name;
        s_rope_hex = other.s_rope_hex;
    }

    return *this;
}

void s_basic_info::Clear()
{
        s_project_name.Clear();
         s_balance_block_qty.Clear();
       s_cwt_block_qty_dc_before.Clear();
        s_cwt_block_qty_dc_after.Clear();
     /*    s_tm_spring_length_left.Clear();
        s_tm_spring_length_right.Clear();
        s_mainboard_no.Clear();
        s_buffer_no_car.Clear();
        s_buffer_no_cwt.Clear();
        s_govern_no_car.Clear();
        s_govern_no_cwt.Clear();
        s_safe_guard_no_car.Clear();
        s_safe_guard_no_cwt.Clear();
        s_tm_no.Clear();*/

        s_wbs.Clear();
        s_lift_no.Clear();
        s_cwt_weight.Clear();
        s_dc_weight.Clear();
  //      s_rate.Clear();

        s_car_weight.Clear();
        s_block_material1.Clear();
        s_block_material2.Clear();
        b_has_governor=false;
        b_has_spring = false;
}

bool s_basic_info::check_info_finish(wxString &str, bool b_basic_finish )
{
    bool b_finish;
    str.Empty();

    if(b_basic_finish)
    {
        if(s_car_weight.IsEmpty() || s_car_weight==wxT("0"))
        {
            str=str+wxT("轿厢空重;");
        }
    }

    if(s_cwt_weight.IsEmpty() || s_cwt_weight==wxT("0"))
    {
        str=str+wxT("对重架重量;");
    }


    if(s_cwt_block_qty_dc_before.IsEmpty() || s_cwt_block_qty_dc_before==wxT("0"))
    {
        str=str+wxT("装潢前对重块数量;");
    }

    if(s_cwt_block_qty_dc_after.IsEmpty() || s_cwt_block_qty_dc_after==wxT("0"))
    {
        str=str+wxT("装潢后对重块数量;");
    }

    if((s_block_material1.IsEmpty()&&s_block_material2.IsEmpty())||(s_block_material1==wxT("0")&&s_block_material2==wxT("0"))||
         (s_block_material1.IsEmpty()&&s_block_material2==wxT("0"))||(s_block_material1==wxT("0")&&s_block_material2.IsEmpty()))
    {
        str=str+wxT("备注中对重块数量;");
    }

    str.Trim();

    if(str.IsEmpty())
        return true;
    else
        return false;
}



wxTreeItemId search_in_treelist(wxcode::wxTreeListCtrl* tl_ctrl, wxTreeItemId start_id, wxString s_case,int case_col)
{
     wxTreeItemId root = tl_ctrl->GetRootItem();

     tl_ctrl->UnselectAll();

     wxTreeItemId end_id,item_id,parent_id;
     wxString str;
     wxTreeItemIdValue cookie_value;

    if(!start_id.IsOk()||start_id ==root)
        start_id=root;
    else
    {

        parent_id=tl_ctrl->GetItemParent(start_id);

        if(parent_id!=root)
            tl_ctrl->Collapse(parent_id);
    }

     item_id = tl_ctrl->GetNext(start_id);

     if(!item_id.IsOk())
     {
         item_id = tl_ctrl->GetFirstChild(root, cookie_value);
     }

     while(end_id!=item_id)
     {
          if(!item_id.IsOk())
          {
              item_id = tl_ctrl->GetFirstChild(root, cookie_value);
          }
          str = tl_ctrl->GetItemText(item_id, case_col);

          if(str.Contains(s_case))
          {
              tl_ctrl->SelectItem(item_id);

              parent_id = tl_ctrl->GetItemParent(item_id);

              if(parent_id!=root)
              {
                  tl_ctrl->Expand(parent_id);
              }

              tl_ctrl->ScrollTo(item_id);

              return item_id;
          }

          item_id= tl_ctrl->GetNext(item_id);

     }


     return root;

}


#include <wx/arrimpl.cpp>
WX_DEFINE_OBJARRAY(wxArrayValue);
//WX_DEFINE_EXPORTED_OBJARRAY(wxArrayValue);
int arraycompare(s_basic_info** arg1, s_basic_info** arg2)
{
    wxString s_arg1 = (*arg1)->s_wbs;
    wxString s_arg2 = (*arg2)->s_wbs;
    s_arg1.Replace(wxT("E/"),wxT(""));
    s_arg2.Replace(wxT("E/"),wxT(""));
    s_arg1.Replace(wxT("."),wxT(""));
    s_arg2.Replace(wxT("."),wxT(""));

    return (wxAtol(s_arg1)< wxAtol(s_arg2));
}

WX_DEFINE_OBJARRAY(wxArraySupport);
int arraycompare(s_basic_info_support** arg1, s_basic_info_support** arg2)
{
    wxString s_arg1 = (*arg1)->s_act;
    wxString s_arg2 = (*arg2)->s_act;

    return (wxAtoi(s_arg1)<wxAtoi(s_arg2));
}

WX_DEFINE_OBJARRAY(wxArrayBlocks);
int arraycompare(s_cwt_block_info** arg1, s_cwt_block_info** arg2)
{
    wxString s_arg1 = (*arg1)->s_mat_no;
    wxString s_arg2 = (*arg2)->s_mat_no;

    return (wxAtoi(s_arg1)<wxAtoi(s_arg2));
}

WX_DEFINE_OBJARRAY(wxArrayLabel);
int arraycompare(s_contract_label** arg1, s_contract_label** arg2)
{
    wxString s_arg1 = (*arg1)->s_contract_id;
    wxString s_arg2 = (*arg2)->s_contract_id;

    return (wxAtoi(s_arg1)<wxAtoi(s_arg2));
}


s_contract_label& s_contract_label::operator=(const s_contract_label& other)
{
    if(&other!=this)
    {
          s_contract_id = other.s_contract_id;
          s_label_id = other.s_label_id;
          s_project_catalog  = other.s_project_catalog;
          s_project_id=other.s_project_id;
          s_project_name = other.s_project_name;
          s_contract_id = other.s_contract_id;

    }

    return *this;
}

s_json_data_to_din& s_json_data_to_din::operator=(const s_json_data_to_din& other)
{
    if(&other!=this)
    {
        s_wbs_no=other.s_wbs_no;
        s_project_name = other.s_project_name;
        i_car_weight = other.i_car_weight;
        i_cwt_frame_weight = other.i_cwt_frame_weight;
        i_reservedocoration_weight = other.i_reservedocoration_weight;
        d_balance_rate = other.d_balance_rate;
        i_conf_balance_block_qty = other.i_conf_balance_block_qty;
        i_cwt_blockqty_before_dc = other.i_cwt_blockqty_before_dc;
        i_cwt_blockqty_after_dc = other.i_cwt_blockqty_after_dc;
        i_cwt_blockqty_mat1 = other.i_cwt_blockqty_mat1;
        i_cwt_blockqty_mat2 = other.i_cwt_blockqty_mat2;
        i_cwt_blockqty = other.i_cwt_blockqty;
        is_success = other.is_success;
        b_has_governor = other.b_has_governor;
        s_lift_no = other.s_lift_no;
    }

    return *this;
}

WX_DEFINE_OBJARRAY(wxArrayHex);
//WX_DEFINE_EXPORTED_OBJARRAY(wxArrayValue);
int arraycompare(s_sap_hex_info** arg1, s_sap_hex_info** arg2)
{
    wxString s_arg1 = (*arg1)->s_wbs;
    wxString s_arg2 = (*arg2)->s_wbs;
    s_arg1.Replace(wxT("E/"),wxT(""));
    s_arg2.Replace(wxT("E/"),wxT(""));
    s_arg1.Replace(wxT("."),wxT(""));
    s_arg2.Replace(wxT("."),wxT(""));

    return (wxAtol(s_arg1)< wxAtol(s_arg2));
}

WX_DEFINE_OBJARRAY(wxArrayToDin);
int arraycompare(s_json_data_to_din** arg1, s_json_data_to_din** arg2)
{
    wxString s_arg1 = (*arg1)->s_wbs_no;
    wxString s_arg2 = (*arg2)->s_wbs_no;
    s_arg1.Replace(wxT("E/"),wxT(""));
    s_arg2.Replace(wxT("E/"),wxT(""));
    s_arg1.Replace(wxT("."),wxT(""));
    s_arg2.Replace(wxT("."),wxT(""));

    return (wxAtol(s_arg1)< wxAtol(s_arg2));
}