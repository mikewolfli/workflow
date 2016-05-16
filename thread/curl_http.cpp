#include "curl_http.h"
#include "pugixml.hpp"

//wxString curl_http::dg_url = "http://10.127.160.41:9023/CELabelWebService.asmx/SetSJMutiCELabelData";

curl_http::curl_http()
{

    //ctor

    pugi::xml_document ldoc;
    pugi::xml_node lnode;
    pugi::xml_parse_result result;

    result = ldoc.load_file("config.xml");

    if(result)
    {
        lnode =ldoc.child("din");
        dg_url  = wxString(lnode.child_value("url"));

    }else
         return;

    //wxLogMessage(dg_url);
    dg_curl = curl_easy_init();

}

curl_http::~curl_http()
{
    //dtor

}

size_t write_data(char *ptr, size_t size, size_t nmemb, void *userdata) {
    wxString* stream = static_cast<wxString*>(userdata);
    size_t count = size * nmemb;
    stream->Append(ptr, count);
    return count;
}


void curl_http::update_data_into_din()
{
    struct curl_slist *plist = NULL;
  //  wxString str_result;
  //  long  rsp_code;


    if(dg_curl)
    {
        curl_easy_setopt(dg_curl, CURLOPT_TIMEOUT, 5);

       // curl_easy_setopt(dg_curl, CURLOPT_URL,wxCURL_STRING2BUF(dg_url));
        curl_easy_setopt(dg_curl, CURLOPT_URL,static_cast<const char*> ( dg_url.c_str() ));

        // 设置http发送的内容类型为JSON
        plist = curl_slist_append(plist, "Accept:application/json, text/javascript, */*; q=0.01");
        plist = curl_slist_append(plist, "Accept-Encoding:gzip, deflate");
        plist = curl_slist_append(plist, "Accept-Language:en-US,en;q=0.5");
        plist = curl_slist_append(plist, "Cache-Control:no-cache");
        plist = curl_slist_append(plist, "Connection:keep-alive");
        plist = curl_slist_append(plist, "Content-Type:application/json; charset=utf-8");
        //plist = curl_slist_append(plist, "Host:10.127.160.41:9022");
        plist = curl_slist_append(plist, "Pragma:no-cache");
        //plist = curl_slist_append(plist, "Referer:http://10.127.160.41:9022/");
        plist = curl_slist_append(plist, "User-Agent:Mozilla/5.0 (Windows NT 6.1; rv:39.0) Gecko/20100101 Firefox/39.0");
        plist = curl_slist_append(plist, "X-Requested-With:XMLHttpRequest");

        wxString s_json = build_json_data();

     //   wxLogMessage(s_json);

        dg_answer.Clear();


        if(s_json.IsEmpty())
        {
           curl_slist_free_all(plist);
           curl_easy_cleanup( dg_curl);
           return;

        }


        curl_easy_setopt( dg_curl, CURLOPT_HTTPHEADER, plist);



       curl_easy_setopt( dg_curl, CURLOPT_POSTFIELDS, static_cast<const char*> (s_json.mb_str(wxConvUTF8) ));

       curl_easy_setopt(dg_curl, CURLOPT_WRITEFUNCTION, write_data);
       curl_easy_setopt(dg_curl, CURLOPT_WRITEDATA, &dg_answer);
        dg_result = curl_easy_perform( dg_curl);
    //    dg_result = curl_easy_getinfo(dg_curl, CURLINFO_RESPONSE_CODE, &rsp_code);

       dg_answer.Replace("\\u0027","\"");
       int i_pos = dg_answer.Find(wxT(":"));

       dg_answer.Remove(i_pos+1,1);
       int i_len= dg_answer.Length();
       dg_answer.Remove(i_len-2,1);

       //wxMessageBox(s_json);

        // Check for errors
        if (dg_result != CURLE_OK)
        {
            wxLogMessage("curl_easy_perform() failed:"+wxString(curl_easy_strerror(dg_result),wxConvUTF8));
        }

    //    curl_slist_free_all(plist);
        curl_easy_cleanup( dg_curl);
    }
}

wxString curl_http::GetAnswer() const {
    return dg_answer;
}

wxString curl_http::build_json_data()
{
    int i_count = a_info.GetCount();

    if(i_count==0)
        return wxEmptyString;

    wxJSONValue root;

    for(int i=0; i<i_count; i++)
    {
 /*       str= str+wxT("{'TransactionID':")+NumToStr(i+1)+wxT(",'WBSNo':'")+a_info.Item(i).s_wbs_no+wxT("','ProjectName':'")+
                a_info.Item(i).s_project_name+wxT("','CarWeight':")+NumToStr(a_info.Item(i).i_car_weight)+wxT(",'CwtFrameWeight':")+
                NumToStr(a_info.Item(i).i_cwt_frame_weight)+wxT(",'ReserveDecorationWeight':")+NumToStr(a_info.Item(i).i_reservedocoration_weight)+wxT(",'BalanceRate':")+
                NumToStr(a_info.Item(i).d_balance_rate)+wxT(",'ConfBalanceBlockQty':")+NumToStr(a_info.Item(i).i_conf_balance_block_qty)+wxT(",'CwtBlockQtyBeforeDc':")+
                NumToStr(a_info.Item(i).i_cwt_blockqty_before_dc)+wxT(",'CwtBlockQtyAfterDc':")+NumToStr(a_info.Item(i).i_cwt_blockqty_after_dc)+wxT(",'CwtBlockQtyMat1':")+
                NumToStr(a_info.Item(i).i_cwt_blockqty_mat1)+wxT(",'CwtBlockQtyMat2':")+NumToStr(a_info.Item(i).i_cwt_blockqty_mat2)+wxT(",'CwtBlockQty':")+
                NumToStr(a_info.Item(i).i_cwt_blockqty)+wxT("}");*/
        wxJSONValue items;

        wxString s_project_name = a_info.Item(i).s_project_name;

   /*     wchar_t * wc_str= const_cast<wchar_t*>(s_project_name.wc_str());

        int i_count=s_project_name.Length();

        wxString str;
        for(int j=0;j<i_count;j++)
        {
           str=str+str.Format("\\u%04x", wc_str[j]);
        }*/
   //     wxMessageBox(str,s_project_name);

        items["TransactionID"]=i+1;
        items["WBSNo"]=a_info.Item(i).s_wbs_no;
        items["ProjectName"]=s_project_name;
        items["ElevatorNo"]=a_info.Item(i).s_lift_no;
        items["CarWeight"]=a_info.Item(i).i_car_weight;
        items["CwtFrameWeight"]=a_info.Item(i).i_cwt_frame_weight;
        items["ReserveDecorationWeight"]=a_info.Item(i).i_reservedocoration_weight;
        items["CarBalanceBlockQty"]=a_info.Item(i).i_conf_balance_block_qty;
        items["CarWeightBlockQty"]=a_info.Item(i).i_cwt_blockqty;
        items["BalanceRate"]=a_info.Item(i).d_balance_rate;
        items["CwtBlockQtyBeforeDc"]=a_info.Item(i).i_cwt_blockqty_before_dc;
        items["CwtBlockQtyAfterDc"]=a_info.Item(i).i_cwt_blockqty_after_dc;
        items["CwtBlockQtyMat1"]=a_info.Item(i).i_cwt_blockqty_mat1;
        items["CwtBlockQtyMat2"]=a_info.Item(i).i_cwt_blockqty_mat2;

        if(a_info.Item(i).b_has_governor)
            items["GovernorSafeGearHasValueFlag"]=wxT("1");
        else
            items["GovernorSafeGearHasValueFlag"]=wxT("0");

        if(a_info.Item(i).b_has_spring)
            items["TmBrakeSpringHasValueFlag"]=wxT("1");
        else
            items["TmBrakeSpringHasValueFlag"]=wxT("0");


        root["Json"].Append(items);

     //   wxLogMessage(BoolToStr(a_info.Item(i).b_has_governor));

 /*       if(i!=i_count-1)
            str=str+wxT(",");
        else
            continue;*/
    }

    wxString str;
    wxJSONWriter writer(wxJSONWRITER_NONE);
    writer.Write(root,str);

    //str = str+wxT("]}");
    //wxLogMessage(str);
    return str;
}

