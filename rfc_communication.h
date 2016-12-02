#ifndef RFC_COMMUNICATION_H
#define RFC_COMMUNICATION_H

#include "sapnwrfc.h"
#include <wx/dynarray.h>

#include <stdio.h>
#include <wx/string.h>
/*
#define OT_CE_MARA_ENTRY_SIZE    535*sizeofR(SAP_UC)
#define MARA_INFO_OT_RETURN_ENTRY_SIZE 552*sizeofR(SAP_UC)
#define IT_CE_MARA_ENTRY_SIZE 22*sizeofR(SAP_UC)
*/
RFC_RC errorHandling(RFC_RC rc, SAP_UC description[], RFC_ERROR_INFO* errorInfo, RFC_CONNECTION_HANDLE connection);

//These are for characters convert.
SAP_UC * stringTosapuc(wxString &str);
wxString sapucTostring(SAP_UC * s_uc, int length=-1);

wxString saprc2string(RFC_RC rc);

wxString wbstosapformat(wxString s_wbs);
wxString  sapwbsconvert(wxString s_sap);
wxString sapmatconvert(wxString s_sap);
wxString sapdateconvert(wxString s_sap);
wxString sapnumconvert(wxString s_sap);
wxString sapdatetimeconvert(wxString s_sap);
//These are for characters convert.

class Str_Line
{
public:
	Str_Line()
	{
		cols = 0;
		num_cols=0;
	}

	Str_Line(int _col_num)
	{
	    num_cols = _col_num;
        if(_col_num >0)
	        cols = new wxString[num_cols];
	}

	~Str_Line()
	{
		if (cols) delete[] cols;
	}

	wxString *cols;
	int num_cols;
};


class Value_Pool
{
public:
	Value_Pool(int initialLines, bool _dic=false);
	~Value_Pool();
	Str_Line *operator[] (int line)
	{
		return Get_Value(line);
	}
	Str_Line *Get_Value(int lineNo);

	Str_Line *Get_Name()
	{
	    return ptr_name;
	}
	void Delete(int lineNo);

	wxString get_value_by_name(wxString str, Str_Line* p_str);
	wxString get_value_by_index(int i_col, Str_Line* p_str);
	int find_col_name(wxString str);
	int Find_row_value(wxString str, int i_col, int i_start=0);
	wxArrayInt find_row_value_array(wxString str, int i_col, int i_start=0);
	int Get_Same_Count(wxString str, int i_col);


	bool is_dict()
	{
	    return is_dic;
	}

	int GetNumOfRows()
	{
	    return num_rows;
	}

private:
    Str_Line * ptr_name;
	Str_Line **ptr_value;
    bool is_dic;
	int num_rows;

};


class Rfc_Communication
{
public:
    Rfc_Communication();
    virtual ~Rfc_Communication();

    RFC_FUNCTION_HANDLE Create_Function(wxString function_name,RFC_FUNCTION_DESC_HANDLE& funhandle_desc);
    RFC_RC fillFunctionParameter(RFC_FUNCTION_DESC_HANDLE funcDesc, RFC_FUNCTION_HANDLE container, wxString v_name, Value_Pool * v_value);
    RFC_RC fillFunctionParameter(RFC_FUNCTION_DESC_HANDLE funcDesc, RFC_FUNCTION_HANDLE container, wxString v_name, wxString s_value);
    RFC_RC RunFunction(RFC_FUNCTION_HANDLE fun_handle);
    RFC_RC DestroyFunction(RFC_FUNCTION_HANDLE fun_handle);
    Value_Pool* GetResult(wxString result_name, RFC_FUNCTION_DESC_HANDLE fun_handle_desc, RFC_FUNCTION_HANDLE fun_handle);
    RFC_RC rfc_connect();
    void rfc_closed();
    bool rfc_check_connect();

    wxString str_result;

protected:
private:

    RFC_CONNECTION_HANDLE connection;
    RFC_ERROR_INFO errorInfo;

    SAP_UC* fillString(wxString str);
    wxString wrapString(SAP_UC * uc,int length =-1, bool rstrip=false);

    RFC_RC lookupMetaData(wxString function_name,RFC_FUNCTION_DESC_HANDLE &funhandle_desc);
    RFC_RC fillVariable(RFCTYPE typ, RFC_FUNCTION_HANDLE container, SAP_UC* cName, Value_Pool * v_value, wxString str, RFC_TYPE_DESC_HANDLE typeDesc);
    RFC_RC fillStructureField(RFC_TYPE_DESC_HANDLE typeDesc, RFC_STRUCTURE_HANDLE container, SAP_UC * name, wxString s_value);
    RFC_RC fillTable(RFC_TYPE_DESC_HANDLE typeDesc, RFC_TABLE_HANDLE container, Value_Pool* value);
    RFC_RC fillField(RFCTYPE typ, DATA_CONTAINER_HANDLE container, SAP_UC* name, wxString s_value);

    Value_Pool* wrapResult(RFC_FUNCTION_DESC_HANDLE functionDescHandle, RFC_FUNCTION_HANDLE functionHandle, wxString varial_name, bool rstrip=false);
    void wrapStructure(RFC_TYPE_DESC_HANDLE typeDesc, RFC_STRUCTURE_HANDLE structHandle, Str_Line* line_value=NULL,bool _withname=false, Str_Line* line_name=NULL, bool rstrip=false);
    Value_Pool* wrapVariable(RFCTYPE typ, RFC_FUNCTION_HANDLE functionHandle, SAP_UC* cName, unsigned int cLen, RFC_TYPE_DESC_HANDLE typeDesc, bool rstrip=false);
    wxString wrapField(RFCTYPE typ, RFC_STRUCTURE_HANDLE functionHandle, SAP_UC* cName, unsigned int cLen, bool rstrip=false);

};

#endif // RFC_COMMUNICATION_H
