#include "rfc_communication.h"

#include <wx/log.h>
#include <wx/msgdlg.h>
#include <wx/fileconf.h>
#include "security/base64.h"
#include "wf_stdafx.h"

RFC_RC errorHandling(RFC_RC rc, SAP_UC description[], RFC_ERROR_INFO* errorInfo, RFC_CONNECTION_HANDLE connection){
//	printfU(cU("%s: %d\n"), description, rc);
//	printfU(cU("%s: %s\n"), errorInfo->key, errorInfo->message);
	// It's better to close the TCP/IP connection cleanly, than to just let the
	// backend get a "Connection reset by peer" error...
    wxString str_key, str_message, caption_rc, caption_description;
    caption_description= sapucTostring(description);
    caption_rc = saprc2string(rc);
    str_key = sapucTostring(errorInfo->key);
    str_message = sapucTostring(errorInfo->message);

//#if wxUSE_LOG
    wxLogMessage(caption_description+wxT(":")+caption_rc+wxT("\n")+str_key+wxT(":")+str_message);
//#else
 //   wxMessageBox(str_key+wxT(":")+str_message, caption_description+wxT(":")+caption_rc);
//#endif // wxUSE_LOG


	return errorInfo->code;
}

wxString wbstosapformat(wxString s_wbs)
{
    wxString str = s_wbs;

    str.Replace(wxT("/"), wxT(""));
    str.Replace(wxT("."), wxT(""));

    str=str+wxT("00");

    return str;
}

wxString sapnumconvert(wxString s_sap)
{
    wxString str = s_sap;
    str.Replace(wxT(","),wxT(""));

    double d_var;

    if(!str.ToDouble(&d_var))
         str=wxEmptyString;

    return str;
}

wxString sapmatconvert(wxString s_sap)
{
    long l_sap= wxAtol(s_sap);

    return NumToStr(l_sap);
}

wxString  sapwbsconvert(wxString s_sap)
{
    if(s_sap.IsEmpty())
          return wxEmptyString;

    wxString s_header = s_sap.Left(1);
    wxString s_prj = s_sap.Mid(1, 8);
    wxString s_unit = s_sap.Mid(9,3);

    return s_header+wxT("/")+s_prj+wxT(".")+s_unit;
}

wxString sapdateconvert(wxString s_sap)
{
    if(s_sap.Length()!=8)
        return s_sap;

    wxString s_year = s_sap.Left(4);
    wxString s_month = s_sap.Mid(4,2);
    wxString s_day = s_sap.Right(2);

    return s_year+wxT("-")+s_month+wxT("-")+s_day;


}

wxString sapdatetimeconvert(wxString s_sap)
{
     if(s_sap == wxT("00000000"))
        return wxEmptyString;

    if(s_sap.Length()!=8)
        return wxEmptyString;

    wxString s_year = s_sap.Left(4);
    wxString s_month = s_sap.Mid(4,2);
    wxString s_day = s_sap.Right(2);

    return s_year+wxT("-")+s_month+wxT("-")+s_day+wxT(" 23:00:00");

}

SAP_UC * stringTosapuc(wxString &str)
{

  RFC_RC rc;
  SAP_UC *sapuc;
  unsigned int sapucSize, resultLen = 0;

  RFC_ERROR_INFO errorInfo;

  const char *cStr = str.mb_str(wxConvUTF8);

  sapucSize = strlen(cStr) + 1;

  sapuc = mallocU(sapucSize);
  memsetU(sapuc, 0, sapucSize);
  rc = RfcUTF8ToSAPUC((RFC_BYTE*)cStr, strlen(cStr), sapuc, &sapucSize, &resultLen, &errorInfo);

  if (rc != RFC_OK) {
    // FIXME: error handling
    errorHandling(rc, cU("string to sap_uc"), &errorInfo, NULL);
    return cU("error");

  }

   return sapuc;


/*
    int len = str.length();

    SAP_UC * ptr;

    int nlen = len*sizeofR(SAP_UC);

    std::wstring wstr;

    wstr = str.ToStdWstring();
    memcpyU (ptr, (SAP_UC*)wstr.c_str(), nlen);

    return ptr;*/
}

wxString sapucTostring(SAP_UC * s_ucs, int length)
{
  RFC_RC rc;
  RFC_ERROR_INFO errorInfo;

  wxString str;

  if(length==0)
    return wxEmptyString;

  if(length == -1)
     length = strlenU(s_ucs);


  unsigned int utf8Size = length * 2;
  char *utf8 = (char*) malloc(utf8Size + 1);
  utf8[0] = '\0';

  unsigned int resultLen = 0;
  rc = RfcSAPUCToUTF8(s_ucs, length, (RFC_BYTE*) utf8, &utf8Size, &resultLen, &errorInfo);

  int i=0;

  while (rc != RFC_OK) {
    // TODO: throw wrapError
        if(rc==RFC_BUFFER_TOO_SMALL)
        {
            i+=8;
            utf8Size = (length+i) * 2;
            free(utf8);

            utf8 = (char*) malloc(utf8Size + 1);
            utf8[0] = '\0';
            rc = RfcSAPUCToUTF8(s_ucs, length, (RFC_BYTE*) utf8, &utf8Size, &resultLen, &errorInfo);

        }
        else
        {
            errorHandling(rc, cU("sap uc to string"), &errorInfo, NULL);
            return "error";
        }
  }

  str = wxString(utf8,wxConvUTF8);

  free(utf8);

 // str.Trim();
  return str;
/*
    wxString str;
    int len = strlenU(s_ucs);

    int nlen;

    nlen = len*sizeof(wchar_t);;
    wchar_t *  wptr;
    memcpy(wptr,(wchar_t*)s_ucs, nlen);

    DWORD dwNum = WideCharToMultiByte(CP_OEMCP,NULL,wptr,-1,NULL,0,NULL,FALSE);

    char *psText;
    psText = new char[dwNum];

    WideCharToMultiByte (CP_OEMCP,NULL,wptr,-1,psText,dwNum,NULL,FALSE);
    str = wxString(psText,wxConvUTF8);
    delete [] psText;



    return str;*/

}

wxString saprc2string(RFC_RC rc)
{
    switch(rc)
    {
   case 0:
       return wxT("RFC_OK");
   case 1:						///< Everything O.K. Used by every function
       return wxT("RFC_COMMUNICATION_FAILURE");	///< Error in Network & Communication layer
    case 2:
       return wxT("RFC_LOGON_FAILURE");		///< Unable to logon to SAP system. Invalid password, user locked, etc
    case 3:
       return wxT("RFC_ABAP_RUNTIME_FAILURE");	///< SAP system runtime error (SYSTEM_FAILURE): Shortdump on the backend side
    case 4:
        return wxT("RFC_ABAP_MESSAGE");			///< The called function module raised an E-, A- or X-Message
    case 5:
        return wxT("RFC_ABAP_EXCEPTION");		///< The called function module raised an Exception (RAISE or MESSAGE ... RAISING)
    case 6:
        return wxT("RFC_CLOSED");					///< Connection closed by the other side
    case 7:
        return wxT("RFC_CANCELED");///< No longer used
    case 8:
        return wxT("RFC_TIMEOUT");				///< Time out
    case 9:
        return wxT("RFC_MEMORY_INSUFFICIENT");	///< Memory insufficient
    case 10:
        return wxT("RFC_VERSION_MISMATCH");	///< Version mismatch
    case 11:
        return wxT("RFC_INVALID_PROTOCOL");	///< The received data has an unsupported format
    case 12:
        return wxT("RFC_SERIALIZATION_FAILURE");	///< A problem while serializing or deserializing RFM parameters
    case 13:
        return wxT("RFC_INVALID_HANDLE");		///< An invalid handle was passed to an API call
    case 14:
        return wxT("RFC_RETRY");					///< RfcListenAndDispatch did not receive an RFC request during the timeout period
    case 15:
        return wxT("RFC_EXTERNAL_FAILURE");		///< Error in external custom code. (E.g in the function handlers or tRFC handlers.) Results in SYSTEM_FAILURE
    case 16:
        return wxT("RFC_EXECUTED");				///< Inbound tRFC Call already executed (needs to be returned from RFC_ON_CHECK_TRANSACTION in case the TID is already known)
    case 17:
        return wxT("RFC_NOT_FOUND"); ///< Function or structure definition not found (Metadata API)
    case 18:
        return wxT("RFC_NOT_SUPPORTED");			///< The operation is not supported on that handle
    case 19:
        return wxT("RFC_ILLEGAL_STATE");			///< The operation is not supported on that handle at the current point of time (e.g trying a callback on a server handle, while not in a call)
    case 20:
        return wxT("RFC_INVALID_PARAMETER");		///< An invalid parameter was passed to an API call, (e.g invalid name, type or length)
    case 21:
        return wxT("RFC_CODEPAGE_CONVERSION_FAILURE"); ///< Codepage conversion error
    case 22:
        return wxT("RFC_CONVERSION_FAILURE");	///< Error while converting a parameter to the correct data type
    case 23:
        return wxT("RFC_BUFFER_TOO_SMALL");	///< The given buffer was to small to hold the entire parameter. Data has been truncated.
    case 24:
        return wxT("RFC_TABLE_MOVE_BOF");		///< Trying to move the current position before the first row of the table
    case 25:
        return wxT("RFC_TABLE_MOVE_EOF");		///< Trying to move the current position after the last row of the table
    case 26:
        return wxT("RFC_START_SAPGUI_FAILURE");   ///< Failed to start and attach SAPGUI to the RFC connection
	case 27:
        return wxT("RFC_UNKNOWN_ERROR");
    default:
        return wxT("Unkown result");
    }
}

Value_Pool::Value_Pool(int initialLines, bool _dic)
{
    is_dic = _dic;
    ptr_name=NULL;
    ptr_value = NULL;

    num_rows =0;
    if(initialLines == 0)
        return;

    if(is_dic)
        ptr_name = new Str_Line;

    ptr_value = new Str_Line*[initialLines];
    if (ptr_value)
    {
        num_rows = initialLines;
        memset(ptr_value, 0, sizeof(Str_Line *)*num_rows);
    }
    else
    {
        num_rows = 0;
        wxLogError(_("Out of Memory for Value_Pool"));
    }
}



Value_Pool::~Value_Pool()
{
    if (ptr_value)
    {
        while (num_rows--)
        {
            if (ptr_value[num_rows])
                delete ptr_value[num_rows];
        }
        delete[] ptr_value;
    }

    if(ptr_name)
        delete ptr_name;
}

wxString Value_Pool::get_value_by_name(wxString str, Str_Line* p_str)
{
   if(!is_dic)
       return wxEmptyString;

   int i_count = ptr_name->num_cols;
   for(int i=0;i<i_count;i++)
   {
       if(ptr_name->cols[i]==str)
          return p_str->cols[i];
   }

   return wxEmptyString;
}

int Value_Pool::find_col_name(wxString str)
{
    if(!is_dic)
        return -1;

    int i_count = ptr_name->num_cols;
    for(int i=0;i<i_count;i++)
    {
        if(ptr_name->cols[i]==str)
            return  i;
    }

    return -1;
}

int Value_Pool::Find_row_value(wxString str, int i_col, int i_start)
{
    if(num_rows==0)
        return -1;

    Str_Line * line_value;

    if(i_start>=num_rows)
        return -2;

    for(int i=i_start;i<num_rows;i++)
    {
        line_value=Get_Value(i);

        if(line_value->cols[i_col]==str)
            return i;
    }

    return -1;
}

wxArrayInt Value_Pool::find_row_value_array(wxString str, int i_col, int i_start)
{
    wxArrayInt array_int;
    if(num_rows==0)
        return array_int;

    Str_Line * line_value;

    if(i_start>=num_rows)
        return array_int;

    for(int i=i_start;i<num_rows;i++)
    {
        line_value=Get_Value(i);

        if(line_value->cols[i_col]==str)
            array_int.Add(i);
    }

    return array_int;
}

int Value_Pool::Get_Same_Count(wxString str, int i_col)
{
        Str_Line * line_value;

        int i_count =0;
        for(int i=0;i<num_rows;i++)
        {
            line_value = Get_Value(i);
            if(line_value->cols[i_col]==str)
                i_count++;
        }

        return i_count;

}



wxString Value_Pool::get_value_by_index(int i_col, Str_Line* p_str)
{
    if(i_col<= p_str->num_cols&&i_col>0)
        return p_str->cols[i_col];

    return wxEmptyString;
}

void Value_Pool::Delete(int lineNo)
{
    if (ptr_value && lineNo >= 0 && lineNo < num_rows)
    {
#if 1
        if (ptr_value[lineNo])
            delete ptr_value[lineNo];

        if (lineNo < num_rows - 1)
        {
            // beware: overlapping copy
            memmove(ptr_value + lineNo, ptr_value + lineNo + 1, sizeof(Str_Line *) * (num_rows - lineNo - 1));
        }
#else
        Str_Line *c;
        c = ptr_value[0];
        ptr_value[0] = ptr_value[1];
        ptr_value[1] = c;
#endif
        ptr_value[num_rows - 1] = 0;
    }
}


Str_Line *Value_Pool::Get_Value(int lineNo)
{
    if (lineNo < 0) return 0;

    if (lineNo >= num_rows)
    {
        Str_Line **old = ptr_value;
        int oldAnz = num_rows;
        num_rows = lineNo + 100;
        ptr_value = new Str_Line*[num_rows];
        if (!ptr_value)
        {
            num_rows = 0;
            wxLogError(_("Out of Memory for Value_Pool"));
        }
        else
        {
            if (oldAnz)
            {
                memcpy(ptr_value, old, sizeof(Str_Line *)*oldAnz);
                delete[] old;
            }
            memset(ptr_value + oldAnz, 0, num_rows - oldAnz);
        }
    }

    if (lineNo < num_rows)
    {
        if (!ptr_value[lineNo])
            ptr_value[lineNo] = new Str_Line();
        return ptr_value[lineNo];
    }
    return 0;
}

Rfc_Communication::Rfc_Communication()
{
    //ctor
    connection = NULL;
   // rfc_connect();

}

Rfc_Communication::~Rfc_Communication()
{
    //dtor
    rfc_closed();

}

bool Rfc_Communication::rfc_check_connect()
{
    if(connection==NULL)
        return false;

    return true;
}

RFC_RC Rfc_Communication::lookupMetaData(wxString function_name,RFC_FUNCTION_DESC_HANDLE &funhandle_desc)
{

//	printfU(cU("Caching DDIC metadata..."));
    wxLogMessage(_("Caching DDIC metadata..."));

    SAP_UC * sap_function_name = stringTosapuc(function_name);

	funhandle_desc = RfcGetFunctionDesc(connection, sap_function_name, &errorInfo);
	if (funhandle_desc == NULL) goto end;

	end: wxLogMessage(_("...done"));
	    //printfU(cU("  ...done\n"));
	return errorInfo.code;
}

RFC_RC Rfc_Communication::rfc_connect()
{
    RFC_RC rc = RFC_OK;
    RFC_CONNECTION_PARAMETER loginParams[6];

    wxFileConfig *config = new wxFileConfig(
                wxEmptyString,
                wxEmptyString,wxGetCwd()+"\\loginparams.ini",
                wxEmptyString,
                wxCONFIG_USE_LOCAL_FILE
    );

    wxString s_ahost,s_sysnr, s_user, s_passwd, s_client, s_lang,str;

    config->Read(wxT("ashost"),&s_ahost);
    config->Read(wxT("sysnr"), &s_sysnr);
    config->Read(wxT("user"),&str);
    s_user = Base64::Decode(str);
    config->Read(wxT("passwd"),&str);
    s_passwd = Base64::Decode(str);
    config->Read(wxT("client"),&s_client);
    config->Read(wxT("lang"),&s_lang);
    wxLogMessage(s_user+":"+s_passwd);

    loginParams[0].name = cU("ashost"); loginParams[0].value = stringTosapuc(s_ahost);
	loginParams[1].name = cU("sysnr");	loginParams[1].value = stringTosapuc(s_sysnr);
	loginParams[2].name = cU("user");	loginParams[2].value = stringTosapuc(s_user);
	loginParams[3].name = cU("passwd");	loginParams[3].value = stringTosapuc(s_passwd);
	loginParams[4].name = cU("client");	loginParams[4].value = stringTosapuc(s_client);
	loginParams[5].name = cU("lang");	loginParams[5].value = stringTosapuc(s_lang);

/*
	loginParams[0].name = cU("ashost");	loginParams[0].value = cU("10.126.1.55");
	loginParams[1].name = cU("sysnr");	loginParams[1].value = cU("00");
	loginParams[2].name = cU("user");	loginParams[2].value = cU("10256603");
	loginParams[3].name = cU("passwd");	loginParams[3].value = cU("2980728617SAP**");
	loginParams[4].name = cU("client");	loginParams[4].value = cU("110");
	loginParams[5].name = cU("lang");	loginParams[5].value = cU("EN");*/

	wxLogMessage(_("登陆SAP..."));

    connection = RfcOpenConnection(loginParams, 6, &errorInfo);

	if (connection == NULL)
    {
        errorHandling(rc, cU("Error during logon"), &errorInfo, NULL);
        return errorInfo.code;
    }
    wxLogMessage(_(" SAP登陆成功"));

    return RFC_OK;
}

void Rfc_Communication::rfc_closed()
{
    if(rfc_check_connect())
         RfcCloseConnection(connection, &errorInfo);
    connection = NULL;
}

Value_Pool* Rfc_Communication::GetResult(wxString result_name, RFC_FUNCTION_DESC_HANDLE fun_handle_desc, RFC_FUNCTION_HANDLE fun_handle)
{
      Value_Pool * pool_result = NULL;

      pool_result = wrapResult(fun_handle_desc,fun_handle, result_name, true);

      return pool_result;
}

RFC_FUNCTION_HANDLE Rfc_Communication::Create_Function(wxString function_name,RFC_FUNCTION_DESC_HANDLE& funhandle_desc)
{
    RFC_FUNCTION_HANDLE func_handle;
    RFC_RC rc = RFC_OK;

    rc = lookupMetaData(function_name,funhandle_desc);
	if (rc != RFC_OK)
    {
        errorHandling(rc, cU("Error during metadata lookup"), &errorInfo, connection);
        return NULL;
    }

    func_handle = RfcCreateFunction(funhandle_desc, &errorInfo);

    return func_handle;
}

RFC_RC Rfc_Communication::RunFunction(RFC_FUNCTION_HANDLE fun_handle)
{
    RFC_RC rc = RFC_OK;
	rc = RfcInvoke(connection, fun_handle, &errorInfo);
	if (rc != RFC_OK)
    {
        errorHandling(rc, cU("Error while calling Function"), &errorInfo, connection);
    }

    return rc;
}

RFC_RC Rfc_Communication::DestroyFunction(RFC_FUNCTION_HANDLE fun_handle)
{
    RFC_RC rc = RFC_OK;
	rc = RfcDestroyFunction(fun_handle, &errorInfo);
	if (rc != RFC_OK)
    {
        errorHandling(rc, cU("Error while Destroy Function "), &errorInfo, connection);
    }

    return rc;
}

SAP_UC* Rfc_Communication::fillString(wxString str)
{
    return stringTosapuc(str);
}

wxString Rfc_Communication::wrapString(SAP_UC * uc,int length, bool rstrip)
{
    wxString str;

    str = sapucTostring(uc,length);

    if(rstrip)
        str.Trim();

    return str;
}

RFC_RC Rfc_Communication::fillFunctionParameter(RFC_FUNCTION_DESC_HANDLE funcDesc, RFC_FUNCTION_HANDLE container, wxString v_name, Value_Pool * v_value)
{
    RFC_RC rc;
    RFC_PARAMETER_DESC param_Desc;
    SAP_UC *cName;

    if(v_name.IsEmpty())
    {
        Str_Line * line_name = v_value->Get_Name();
        Str_Line * line_value = v_value->Get_Value(0);

        int i_col = line_name->num_cols;

        for(int i=0; i<i_col; i++)
        {
            cName = fillString(line_name->cols[i]);
            rc = RfcGetParameterDescByName(funcDesc, cName, &param_Desc, &errorInfo);
            free(cName);

            if(rc != RFC_OK)
            {
                errorHandling(rc, cU("RfcGetParameterDescByName"),&errorInfo, connection);

                return rc;
            }

            rc=fillVariable(param_Desc.type,container,param_Desc.name,NULL, line_value->cols[i], param_Desc.typeDescHandle);

            if(rc != RFC_OK)
            {
                errorHandling(rc, cU("fillvariable"),&errorInfo, connection);

                return rc;
            }
        }

    }else
    {
        cName = fillString(v_name);
        rc = RfcGetParameterDescByName(funcDesc, cName, &param_Desc, &errorInfo);
        free(cName);

        if(rc != RFC_OK)
        {
            errorHandling(rc, cU("RfcGetParameterDescByName"),&errorInfo, connection);

            return rc;
        }

        rc = fillVariable(param_Desc.type,container,param_Desc.name,v_value, wxEmptyString, param_Desc.typeDescHandle);
    }

    return rc;
}

RFC_RC Rfc_Communication::fillFunctionParameter(RFC_FUNCTION_DESC_HANDLE funcDesc, RFC_FUNCTION_HANDLE container, wxString v_name, wxString s_value)
{
    RFC_RC rc;
    RFC_PARAMETER_DESC param_Desc;
    SAP_UC *cName;
    cName = fillString(v_name);
    rc = RfcGetParameterDescByName(funcDesc, cName, &param_Desc, &errorInfo);
    free(cName);

    if(rc != RFC_OK)
    {
        errorHandling(rc, cU("RfcGetParameterDescByName"),&errorInfo, connection);

        return rc;
    }

    rc = fillVariable(param_Desc.type,container,param_Desc.name,NULL, s_value, param_Desc.typeDescHandle);

    return rc;

}

RFC_RC Rfc_Communication::fillVariable(RFCTYPE typ, RFC_FUNCTION_HANDLE container, SAP_UC* cName, Value_Pool* v_value,wxString str, RFC_TYPE_DESC_HANDLE typeDesc)
{
    RFC_RC rc;
    RFC_ERROR_INFO errorInfo;
    RFC_STRUCTURE_HANDLE s_struct;
    RFC_TABLE_HANDLE table;
    SAP_UC* uc_Name;
    SAP_UC* uc_value;
    Str_Line * p_value;

    switch(typ)
    {
    case RFCTYPE_STRUCTURE:
    {
        rc = RfcGetStructure(container, cName, &s_struct, &errorInfo);
        if(rc != RFC_OK)
        {
            break;
        }

        Str_Line * p_name = v_value->Get_Name();
        Str_Line * p_value = v_value->Get_Value(0);

        int i_count = p_name->num_cols;

        for(int i=0; i<i_count; i++)
        {
            uc_Name  = fillString(p_name->cols[i]);
            uc_value = fillString(p_value->cols[i]);

            fillStructureField(typeDesc, s_struct, uc_Name, uc_value);
            free(uc_Name);
            free(uc_value);
        }
        break;
    }
    case RFCTYPE_TABLE:
    {
        rc = RfcGetTable(container, cName, &table, &errorInfo);
        if(rc != RFC_OK)
        {
            break;
        }

        fillTable(typeDesc, table, v_value);

        break;
    }
    case RFCTYPE_CHAR:
    case RFCTYPE_STRING:
    case RFCTYPE_NUM:
    case RFCTYPE_DATE:
    case RFCTYPE_TIME:
    {
        rc = fillField(typ, container, cName, str);

        break;
    }
    default:
        rc = RFC_UNKNOWN_ERROR;
    }

 //   delete v_value;
    return rc;
}

RFC_RC Rfc_Communication::fillStructureField(RFC_TYPE_DESC_HANDLE typeDesc, RFC_STRUCTURE_HANDLE container, SAP_UC* name, wxString s_value)
{
    RFC_RC rc;
    RFC_ERROR_INFO errorInfo;
    RFC_STRUCTURE_HANDLE s_struct;
    RFC_FIELD_DESC fieldDesc;

    rc = RfcGetFieldDescByName(typeDesc, name, &fieldDesc, &errorInfo);

    if(rc != RFC_OK)
    {
        errorHandling(rc, cU("RfcGetFieldDescByName"), &errorInfo, NULL);
        return rc;
    }

    rc = fillField(fieldDesc.type, container, fieldDesc.name, s_value);

    return rc;
}

RFC_RC Rfc_Communication::fillField(RFCTYPE typ, DATA_CONTAINER_HANDLE container, SAP_UC* cName, wxString s_value)
{
    RFC_RC rc;
    RFC_ERROR_INFO errorInfo;
    RFC_STRUCTURE_HANDLE s_struct;
    RFC_TABLE_HANDLE table;
    SAP_UC * uc_value;
    switch(typ)
    {
    case RFCTYPE_CHAR:
    {
        uc_value = fillString(s_value);
        rc = RfcSetChars(container, cName, uc_value, strlenU(uc_value), &errorInfo);
        free(uc_value);
        break;
    }
    case RFCTYPE_STRING:
    {
        uc_value = fillString(s_value);
        rc = RfcSetString(container, cName, uc_value, strlenU(uc_value), &errorInfo);
        free(uc_value);
        break;
    }
    case RFCTYPE_NUM:
    {
        uc_value = fillString(s_value);
        rc = RfcSetNum(container, cName, uc_value, strlenU(uc_value), &errorInfo);
        free(uc_value);
        break;
    }
    case RFCTYPE_DATE:
    {
        uc_value = fillString(s_value);
        rc = RfcSetDate(container, cName, uc_value, &errorInfo);
        free(uc_value);
        break;
    }
    case RFCTYPE_TIME:
    {
        uc_value = fillString(s_value);
        rc = RfcSetTime(container, cName, uc_value, &errorInfo);
        free(uc_value);
        break;
    }
    default:
        rc = RFC_UNKNOWN_ERROR;
    }

    return rc;
}

RFC_RC Rfc_Communication::fillTable(RFC_TYPE_DESC_HANDLE typeDesc, RFC_TABLE_HANDLE container, Value_Pool* value)
{
    RFC_ERROR_INFO errorInfo;
    RFC_STRUCTURE_HANDLE lineHandle;
    RFC_RC rc;

    Str_Line * p_name = value->Get_Name();
    int i_col = p_name->num_cols;
    int i_row = value->GetNumOfRows();

    SAP_UC* uc_Name;

    for(int i=0; i<i_row; i++)
    {
        lineHandle = RfcAppendNewRow(container, &errorInfo);
        if(lineHandle==NULL)
        {
            rc = RFC_INVALID_HANDLE;
            return rc;
        }

        Str_Line * p_value = value->Get_Value(i);
        for(int j=0; j<i_col; j++)
        {
            uc_Name = fillString(p_name->cols[j]);
            rc = fillStructureField(typeDesc, lineHandle, uc_Name, p_value->cols[j]);
            free(uc_Name);
        }

    }
    return rc;
}

Value_Pool* Rfc_Communication::wrapResult(RFC_FUNCTION_DESC_HANDLE functionDescHandle, RFC_FUNCTION_HANDLE functionHandle,wxString varial_name, bool rstrip)
{
  RFC_PARAMETER_DESC paramDesc;

  Value_Pool * result_value = NULL;
  RFC_RC rc= RFC_OK;
  rc= RfcGetParameterDescByName(functionDescHandle,stringTosapuc(varial_name),&paramDesc,&errorInfo);

  if(rc!=RFC_OK)
  {
        errorHandling(rc, cU("RfcGetParameterDescByName"),&errorInfo, connection);
        return NULL;
  }

  result_value = wrapVariable(paramDesc.type, functionHandle, paramDesc.name, paramDesc.nucLength, paramDesc.typeDescHandle, rstrip);
  return result_value;
}

Value_Pool* Rfc_Communication::wrapVariable(RFCTYPE typ, RFC_FUNCTION_HANDLE functionHandle, SAP_UC* cName, unsigned int cLen, RFC_TYPE_DESC_HANDLE typeDesc, bool rstrip)
{
    Value_Pool * resultValue = NULL;
    RFC_RC rc = RFC_OK;
    RFC_ERROR_INFO errorInfo;
    RFC_STRUCTURE_HANDLE structHandle;
    Str_Line * line_value;
    Str_Line * line_name;


  switch(typ) {
    case RFCTYPE_STRUCTURE:
        resultValue = new Value_Pool(1, true);
      rc = RfcGetStructure(functionHandle, cName, &structHandle, &errorInfo);
      if (rc != RFC_OK) {
        break;
      }
      line_name = resultValue->Get_Name();
      line_value = resultValue->Get_Value(0);
      wrapStructure(typeDesc, structHandle,line_value, true, line_name, rstrip);
      break;
    case RFCTYPE_TABLE: {
      RFC_TABLE_HANDLE tableHandle;
      rc = RfcGetTable(functionHandle, cName, &tableHandle, &errorInfo);

      if (rc != RFC_OK) {
        break;
      }

      //RFC_FIELD_DESC fieldDesc;
      unsigned int rowCount;
      rc = RfcGetRowCount(tableHandle, &rowCount, &errorInfo);

      if(rowCount == 0)
        break;

      resultValue = new Value_Pool(rowCount, true);

      line_name = resultValue->Get_Name();
      for (unsigned int i=0; i < rowCount; i++) {
        RfcMoveTo(tableHandle, i, NULL);
        structHandle = RfcGetCurrentRow(tableHandle, NULL);
        line_value = resultValue->Get_Value(i);
        if(i==0)
        {
            wrapStructure(typeDesc, structHandle,line_value,true, line_name, rstrip);

        }else
            wrapStructure(typeDesc, structHandle,line_value, false, NULL, rstrip);
      }


      break;
    }
    case RFCTYPE_CHAR:
    case RFCTYPE_STRING:
    case RFCTYPE_NUM:
    case RFCTYPE_BYTE:
    case RFCTYPE_XSTRING:
    case RFCTYPE_BCD:  // fall through; BCD also just mapped to js float type
    case RFCTYPE_FLOAT:
    case RFCTYPE_INT:
    case RFCTYPE_INT1:
    case RFCTYPE_INT2:
    case RFCTYPE_DATE:
    case RFCTYPE_TIME:
        {
            resultValue = new Value_Pool(1,true);
            line_name = resultValue->Get_Name();

            if(!line_name)
                line_name = new Str_Line;
            line_name->cols = new wxString[1];
            line_name->num_cols = 1;
            line_name->cols[0] = sapucTostring(cName);


            line_value = resultValue->Get_Value(0);
            if(!line_value)
                line_value = new Str_Line;
            line_value->num_cols = 1;
            line_value->cols = new wxString[1];
            line_value->cols[0]  = wrapField(typ, functionHandle, cName, cLen,rstrip);

      break;
    }
    default:
      resultValue = NULL;
      // raise RfcException('Unknown RFC type %d when wrapping %s' % (typ, wrapString(cName)))
      break;
  }

  return resultValue;


}

void Rfc_Communication::wrapStructure(RFC_TYPE_DESC_HANDLE typeDesc, RFC_STRUCTURE_HANDLE structHandle,Str_Line* line_value, bool _withname, Str_Line* line_name, bool rstrip)
{
    RFC_RC rc;
    RFC_ERROR_INFO errorInfo;
    RFC_FIELD_DESC fieldDesc;
    unsigned int fieldCount;
    rc = RfcGetFieldCount(typeDesc, &fieldCount, &errorInfo);

    if (rc != RFC_OK)
    {
        //FIXME: error
    }

    if(_withname)
    {   if(!line_name)
             line_name = new Str_Line;
        line_name->cols = new wxString[fieldCount];
        line_name->num_cols = fieldCount;
    }
    if(!line_value)
        line_value =new Str_Line;
    line_value->cols = new wxString[fieldCount];
    line_value->num_cols = fieldCount;

    for (unsigned int i = 0; i < fieldCount; i++)
    {
        rc = RfcGetFieldDescByIndex(typeDesc, i, &fieldDesc, &errorInfo);
        if (rc != RFC_OK)
        {
            // FIXME: error handling
        }
        if(_withname)
        {
            line_name->cols[i] = sapucTostring(fieldDesc.name);

        }
        line_value->cols[i] = wrapField(fieldDesc.type, structHandle, fieldDesc.name, fieldDesc.nucLength, rstrip);
    }

    return;
}

wxString Rfc_Communication::wrapField(RFCTYPE typ, RFC_STRUCTURE_HANDLE functionHandle, SAP_UC* cName, unsigned int cLen, bool rstrip)
{
    wxString resultValue;

    RFC_RC rc = RFC_OK;
    RFC_ERROR_INFO errorInfo;
    switch(typ)
    {

    case RFCTYPE_CHAR:
    {
        RFC_CHAR* charValue = mallocU(cLen);
        rc = RfcGetChars(functionHandle, cName, charValue, cLen, &errorInfo);
        if (rc != RFC_OK)
        {
            break;
        }

        resultValue = wrapString(charValue, cLen,  rstrip);
        free(charValue);
        break;
    }
    case RFCTYPE_STRING:
    {
        unsigned int resultLen = 0, strLen = 0;
        RfcGetStringLength(functionHandle, cName, &strLen, &errorInfo);
        SAP_UC* stringValue = mallocU(strLen+1);
        rc = RfcGetString(functionHandle, cName, stringValue, strLen+1, &resultLen, &errorInfo);
        if (rc != RFC_OK)
        {
            break;
        }
        resultValue = wrapString(stringValue);
        free(stringValue);
        break;
    }
    case RFCTYPE_NUM:
    {
        RFC_NUM* numValue = mallocU(cLen);
        rc = RfcGetNum(functionHandle, cName, numValue, cLen, &errorInfo);
        if (rc != RFC_OK)
        {
            free(numValue);
            break;
        }
        resultValue = wrapString(numValue, cLen);
        free(numValue);
        break;
    }
   case RFCTYPE_BYTE: {
      SAP_RAW* byteValue = (SAP_RAW*) malloc(cLen);
      rc = RfcGetBytes(functionHandle, cName, byteValue, cLen, &errorInfo);
      if (rc != RFC_OK) {
        free(byteValue);
        break;
      }
      resultValue = wxString(reinterpret_cast<const char*>(byteValue));
      free(byteValue);
      break;
    }
    case RFCTYPE_XSTRING: {
      SAP_RAW* byteValue;
      unsigned int strLen, resultLen;
      rc = RfcGetStringLength(functionHandle, cName, &strLen, &errorInfo);
      byteValue = (SAP_RAW*) malloc(strLen+1);
      byteValue[strLen] = '\0';
      rc = RfcGetXString(functionHandle, cName, byteValue, strLen, &resultLen, &errorInfo);
      if (rc != RFC_OK) {
        free(byteValue);
        break;
      }
      resultValue = wxString(reinterpret_cast<const char*>(byteValue));
      free(byteValue);
      break;
    }
    case RFCTYPE_BCD:  // fall through; BCD also just mapped to js float type
    case RFCTYPE_FLOAT: {
      RFC_FLOAT floatValue;
      rc = RfcGetFloat(functionHandle, cName, &floatValue, &errorInfo);
      resultValue = NumToStr(floatValue);
      break;
    }
    case RFCTYPE_INT: {
      RFC_INT intValue;
      rc = RfcGetInt(functionHandle, cName, &intValue, &errorInfo);
      if (rc != RFC_OK) {
        break;
      }
      resultValue = NumToStr(intValue);
      break;
    }
    case RFCTYPE_INT1: {
      RFC_INT1 int1Value;
      rc = RfcGetInt1(functionHandle, cName, &int1Value, &errorInfo);
      if (rc != RFC_OK) {
        break;
      }
      resultValue = NumToStr(int1Value);
      break;
    }
    case RFCTYPE_INT2: {
      RFC_INT2 int2Value;
      rc = RfcGetInt2(functionHandle, cName, &int2Value, &errorInfo);
      if (rc != RFC_OK) {
        break;
      }
      resultValue = NumToStr(int2Value);
      break;
    }
    case RFCTYPE_DATE:
    {
        RFC_DATE dateValue;
        rc = RfcGetDate(functionHandle, cName, dateValue, &errorInfo);
        if (rc != RFC_OK)
        {
            break;
        }
        resultValue = wrapString(dateValue,8);
        break;
    }
    case RFCTYPE_TIME:
    {
        RFC_TIME timeValue;
        rc = RfcGetTime(functionHandle, cName, timeValue, &errorInfo);
        if (rc != RFC_OK)
        {
            break;
        }
        resultValue = wrapString(timeValue,6);  // FIXME: use v8::Date object
        break;
    }
    default:
        resultValue = wxEmptyString;
        // raise RfcException('Unknown RFC type %d when wrapping %s' % (typ, wrapString(cName)))
        break;

    }

    return resultValue;
}

