/***************************************************************
 * Name:      wfApp.cpp
 * Purpose:   Code for Application Class
 * Author:    mikewolfli (mikewolfli@163.com)
 * Created:   2013-11-21
 * Copyright: mikewolfli (http://mikewolfli.blog.163.com)
 * License:
 **************************************************************/

#include "wfApp.h"
#include "pugixml.hpp"
#include "security/base64.h"
#include <wx/socket.h>
#include "connect_para_dlg.h"
#include "version.h"
#include <wx/tokenzr.h>

#include "wfMain.h"
//(*AppHeaders
#include <wx/image.h>
//*)

IMPLEMENT_APP(wfApp);

para gr_para;
// Global print data, to remember settings during the session
wxPrintData *g_printData = (wxPrintData*) NULL ;

// Global page setup data
wxPageSetupDialogData* g_pageSetupData = (wxPageSetupDialogData*) NULL;


bool wfApp::OnInit()
{
/*
    m_checker = new wxSingleInstanceChecker;
    if ( m_checker->IsAnotherRunning() )
    {
        wxLogError(_("Another program instance is already running, aborting."));
        return false;
    }*/


    if(!read_para()) return false;


    bool b_return;

    do
    {

        conn = new wxPostgreSQL(conn_str, wxConvUTF8);

//   int s_ver;
        if(conn->Status()==CONNECTION_OK)
        {
//        wxMessageBox(wxString(conn->GetHost()));
//      s_ver = conn->ServerVersion();
            b_return= true;
        }
        else
        {

            connect_para_dlg dlg;

            if(dlg.ShowModal() == wxID_OK)
            {
                if(conn)
                  delete conn;
                read_para();
                conn = new wxPostgreSQL(conn_str, wxConvUTF8);

                //   int s_ver;
                if(conn->Status()==CONNECTION_OK)
                {
//        wxMessageBox(wxString(conn->GetHost()));
//      s_ver = conn->ServerVersion();
                    b_return= true;
                }else b_return=false;
            }else
            {
              wxMessageBox(conn->ErrorMessage(),"Connect error:");
               return false;
            }

        }
    }
    while(!b_return);

    if(get_client_version())
    {

        wxExecute(wxT("update.bat"));
        wxExit();
    }

    wxIPV4address addr;
    gr_para.local_pc_name = wxGetFullHostName();
    gr_para.local_user = wxGetUserId();
    gr_para.login_status = false;
    addr.Hostname(gr_para.local_pc_name);
    gr_para.local_ip = addr.IPAddress();
    gr_para.lang_info = wxT("zh_CN");

    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    //*)
    if ( wxsOK )
    {
        g_printData = new wxPrintData;

        g_pageSetupData = new wxPageSetupDialogData;
        (*g_pageSetupData) = *g_printData;

        g_pageSetupData->SetMarginTopLeft(wxPoint(0, 0));
        g_pageSetupData->SetMarginBottomRight(wxPoint(0, 0));


        wfFrame* Frame = new wfFrame(NULL, wxID_ANY);
        Frame->Show();
        SetTopWindow(Frame);
    }
    return wxsOK;

}

int wfApp::OnExit()
{
    if(g_printData!=NULL)
        delete g_printData;
    if(g_pageSetupData!=NULL)
        delete g_pageSetupData;

    int i_way=check_status();
    if(i_way>=1)
        login_log(1);
    if(conn)
    {
        conn->Finish();
        delete conn;
    }

    if(m_checker)
        delete m_checker;

//    ExitProcess(0);

    return 0;
}


bool wfApp::read_para()//read the parameter from the xml file
{

    wxString ldbusr,ldbpwd;
    pugi::xml_document ldoc;
    pugi::xml_node lnode;
    pugi::xml_parse_result result;

    result = ldoc.load_file("config.xml");
    if(result)
    {
        lnode =ldoc.child("connect");
        gr_para.server_host = wxString(lnode.child_value("host"));
        gr_para.server_port = wxString(lnode.child_value("port"));
        gr_para.server_dbname = wxString(lnode.child_value("dbname"));
        ldbusr = wxString(lnode.child_value("dbuser"));
        ldbpwd = wxString(lnode.child_value("dbpwd"));
        ldbpwd = Base64::Decode(ldbpwd);
//       ldbpwd = wxBase64Encode(ldbpwd,ldbpwd.Length());
//       wxMessageBox(ldbpwd);
        conn_str = wxT("host=")+gr_para.server_host +wxT(" port=")+gr_para.server_port+ wxT(" dbname=")+gr_para.server_dbname + wxT(" user=")+ldbusr + wxT(" password=")+ldbpwd;

        lnode = ldoc.child("environment");
        gr_para.threadgap = atoi(lnode.child_value("ThreadGap"));

        return true;
    }
    else return false;

}

void wfApp::login_log(int i_way)//log the login
{
    wxString lquery;
    switch(i_way)
    {
    case 0:
        lquery = "INSERT INTO l_login_log(employee_id, log_status, login_time, login_ip, login_user, login_pc_name,version_id) VALUES ('"+gr_para.login_user+"', TRUE,'"+ gr_para.login_datetime.Format("%Y-%m-%d %H:%M:%S")+"','"+ gr_para.local_ip +"','"+gr_para.login_user+"','"+gr_para.local_pc_name+"','"+AutoVersion::FULLVERSION_STRING+"');";
        conn->ExecuteVoid(lquery);
        break;
    case 1:
        lquery = "UPDATE l_login_log SET log_status=false, logoff_time='"+ wxDateTime::Now().Format("%Y-%m-%d %H:%M:%S")+"' where employee_id = '"+gr_para.login_user+"' and login_time = '"+gr_para.login_datetime.Format("%Y-%m-%d %H:%M:%S")+"' AND login_pc_name='"+gr_para.local_pc_name+"'";
        conn->ExecuteVoid(lquery);
        break;
    case 2:
           lquery = "UPDATE l_login_log SET log_status=false where employee_id = '"+gr_para.login_user+"' and login_pc_name ='"+gr_para.local_pc_name+"' and log_status = true;";
            conn->ExecuteVoid(lquery);
            break;
    default:
        break;
    }

}

int wfApp::check_status() //check the conn connect status
{
    if(gr_para.login_user.IsEmpty())
        return 0;

    if(conn->Status()==CONNECTION_BAD)
        return -1;

    if(!conn->IsAlive())
        return -1;

    wxPostgreSQLresult *res;
    wxString lquery= "select * from l_login_log where employee_id = '"+gr_para.login_user+"' and log_status = true and login_pc_name = '"+gr_para.local_pc_name+"'";
    res = conn->Execute(lquery);
    if(res->Status()!=PGRES_TUPLES_OK)
    {
        wxMessageBox(res->ErrorMessage(),_("SELECT failed:"));
        res->Clear();
        return -1;
    }

    int irow = res->GetRowsNumber();
    res->Clear();
    return irow;
}


bool wfApp::is_have(wxString lquery)
{
    wxPostgreSQLresult * l_res = conn->Execute(lquery);
    if(l_res->Status() == PGRES_TUPLES_OK)
    {
        int irow = l_res->GetRowsNumber();

        l_res->Clear();
        if(irow >=1)
            return true;
        else
            return false;

    }else
            l_res->Clear();

    return false;
}

void wfApp::clear_login()
{
    gr_para.login_user.Empty();
    gr_para.login_role.Empty();
    gr_para.login_status = false;
    gr_para.login_user_name.Empty();
    gr_para.login_datetime = wxDateTime::Now();
    gr_para.plant.Empty();
}

bool wfApp::add_contract_id(wxString s_proj_id,wxString s_contract_id)
{
    wxString s_sql = wxT("UPDATE s_project_info SET contract_id='")+s_contract_id+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("' where \
                         project_id = '")+s_proj_id+wxT("';");

    return app_sql_update(s_sql);
}


wxString wfApp::get_ser_no(wxString _table_str, wxString _para_str)
{
    if(!gr_para.login_status|| conn->Status()!= CONNECTION_OK)
        return wxEmptyString;

    wxString result;
    long l_counter;
    int i_step,i_len;
    wxString pre_c,fol_c;

    wxString lquery = wxT("select current_counter, counter_step, pre_char, fol_char, id_len from s_number_counter where table_str = '")+_table_str+wxT("' and table_para_str ='")+_para_str+wxT("'");
    wxPostgreSQLresult * l_res = conn->Execute(lquery);


    if(l_res->Status()!= PGRES_TUPLES_OK)
        return wxEmptyString;

    int irow = l_res->NumRows();
    if(irow<1)
        return wxEmptyString;

    if(irow>1)
    {
        wxLogMessage(_("数据库表中存在重复数据,请核查!"));
        return wxEmptyString;
    }

    l_counter = l_res->GetLong(wxT("current_counter"));
    i_step = l_res->GetInt(wxT("counter_step"));
    i_len = l_res->GetInt(wxT("id_len"));
    pre_c = l_res->GetVal(wxT("pre_char"));
    fol_c = l_res->GetVal(wxT("fol_char"));

    if(!fol_c.IsEmpty())
        result = pre_c + zero_begin(l_counter,i_len) + wxT("-")+ fol_c;
    else
        result = pre_c + zero_begin(l_counter,i_len);

    l_res->Clear();

    bool b_run = true;

    l_counter = l_counter + i_step;


    lquery = wxT("UPDATE s_number_counter SET current_counter = '")+NumToStr(l_counter)+wxT("' WHERE table_str = '")+_table_str+wxT("' and table_para_str ='")+_para_str+wxT("'");

    do
    {
        l_res = conn->Execute(lquery);

        if(l_res->Status() == PGRES_FATAL_ERROR)
            b_run = false;

        l_res->Clear();

    }
    while(!b_run);


    return result;
}

wxString wfApp::get_ser_id(wxString _table_str, wxString _para_str)
{
    if(!gr_para.login_status||conn->Status()!= CONNECTION_OK)
        return wxEmptyString;

    wxString result;
    long l_counter;
    int i_step;
    wxString pre_c,fol_c;

    wxString lquery = wxT("select current_counter, counter_step, pre_char, fol_char from s_number_counter where table_str = '")+_table_str+wxT("' and table_para_str ='")+_para_str+wxT("'");
    wxPostgreSQLresult * l_res = conn->Execute(lquery);


    if(l_res->Status()!= PGRES_TUPLES_OK)
        return wxEmptyString;

    int irow = l_res->NumRows();
    if(irow<1)
        return wxEmptyString;

    if(irow>1)
    {
        wxLogMessage(_("数据库表中存在重复数据,请核查!"));
        return wxEmptyString;
    }

    l_counter = l_res->GetLong(wxT("current_counter"));
    i_step = l_res->GetInt(wxT("counter_step"));
    pre_c = l_res->GetVal(wxT("pre_char"));
    fol_c = l_res->GetVal(wxT("fol_char"));

    if(!fol_c.IsEmpty())
         result = pre_c + NumToStr(l_counter) + wxT("-") + fol_c;
    else
        result = pre_c + NumToStr(l_counter);

    l_res->Clear();

    bool b_run = true;

    l_counter = l_counter + i_step;


    lquery = wxT("UPDATE s_number_counter SET current_counter = '")+NumToStr(l_counter)+wxT("' WHERE table_str = '")+_table_str+wxT("' and table_para_str ='")+_para_str+wxT("'");

    do
    {
        l_res = conn->Execute(lquery);

        if(l_res->Status() == PGRES_FATAL_ERROR)
            b_run = false;

        l_res->Clear();

    }
    while(!b_run);


    return result;

}

wxString wfApp::get_ser_id2(wxString _table_str, wxString _para_str)
{
    if(!gr_para.login_status||conn->Status()!= CONNECTION_OK)
        return wxEmptyString;

    wxString result;
    long l_counter;
    int i_step;
    wxString pre_c,fol_c;

    wxString lquery = wxT("select current_counter, counter_step, pre_char, fol_char from s_number_counter where table_str = '")+_table_str+wxT("' and table_para_str ='")+_para_str+wxT("'");
    wxPostgreSQLresult * l_res = conn->Execute(lquery);


    if(l_res->Status()!= PGRES_TUPLES_OK)
        return wxEmptyString;

    int irow = l_res->NumRows();
    if(irow<1)
        return wxEmptyString;

    if(irow>1)
    {
        wxLogMessage(_("数据库表中存在重复数据,请核查!"));
        return wxEmptyString;
    }

    l_counter = l_res->GetLong(wxT("current_counter"));
    i_step = l_res->GetInt(wxT("counter_step"));
    pre_c = l_res->GetVal(wxT("pre_char"));
    fol_c = l_res->GetVal(wxT("fol_char"));

    if(!fol_c.IsEmpty())
         result = pre_c  + wxT("-") + NumToStr(l_counter)  + fol_c;
    else
        result = pre_c + wxT("-") + NumToStr(l_counter);

    l_res->Clear();

    bool b_run = true;

    l_counter = l_counter + i_step;


    lquery = wxT("UPDATE s_number_counter SET current_counter = '")+NumToStr(l_counter)+wxT("' WHERE table_str = '")+_table_str+wxT("' and table_para_str ='")+_para_str+wxT("'");

    do
    {
        l_res = conn->Execute(lquery);

        if(l_res->Status() == PGRES_FATAL_ERROR)
            b_run = false;

        l_res->Clear();

    }
    while(!b_run);


    return result;

}

wxArrayString wfApp::Get_header(wxString _table_str, wxArrayString &_para_str)
{
    wxArrayString str_header;
    wxString lquery;

     str_header.Clear();
    if(!gr_para.login_status|| conn->Status()!= CONNECTION_OK)
        return str_header;

    lquery = wxT("SELECT table_para_str, item_name FROM v_table_parameter WHERE lang_info = '")+gr_para.lang_info+wxT("' AND  table_str = '")+_table_str+wxT("'");

    wxPostgreSQLresult * l_res = conn->Execute(lquery);

    if(l_res->Status()!= PGRES_TUPLES_OK)
    {
        return str_header;
    }

    int irow = l_res->NumRows();

    if(irow <= 0)
        return str_header;

    int icol = _para_str.GetCount();



    for (int i=0;i<icol;i++)
      for(int j=0;j<irow;j++)
      {
          if(_para_str.Item(i)== wxString(l_res->GetValue(j,0),wxConvUTF8))
            str_header.Add(wxString(l_res->GetValue(j,1),wxConvUTF8));
          else
            str_header.Add(wxEmptyString);
      }
    l_res->Clear();
    return str_header;
}

bool wfApp::app_sql_update(wxString &_query)
{
    return conn->ExecuteVoid(_query);
}

wxPostgreSQLresult * wfApp::app_sql_select(wxString & _query)
{
    return conn->Execute(_query);
}

bool wfApp::update_desc(wxString str_id, wxString str_desc, bool b_update)
{
    wxString str_query;

    if(b_update)
    {
        str_query = wxT("UPDATE s_doc SET doc_desc='")+str_desc+wxT("' WHERE doc_id='")+str_id+wxT("';");

    }else
    {
        str_query = wxT("INSERT INTO s_doc (doc_id, doc_desc) VALUES ('")+str_id+wxT("','")+str_desc+wxT("');");
    }


    return conn->ExecuteVoid(str_query);

}

wxString wfApp::get_leader(wxString s_group)
{
    wxString l_query;

    l_query = wxT("SELECT employee_id FROM s_group_member WHERE group_id = '")+s_group+wxT("' AND is_leader = true and status = true;");

    return conn->ExecuteScalar(l_query);

}

wxArrayString wfApp::get_group()
{
    wxPostgreSQLresult *t_res;
    wxArrayString str_groups;
    wxString l_query, str_temp;
    l_query = wxT("SELECT group_id FROM s_group_member WHERE employee_id = '")+gr_para.login_user +wxT("' and status = true;");

    t_res = conn->Execute(l_query);


    if(t_res->Status()!= PGRES_TUPLES_OK)
    {
        return str_groups;
    }

    int icount = t_res->GetRowsNumber();

    t_res->MoveFirst();
    for(int i=0;i<icount;i++)
    {
        str_temp = t_res->GetVal(0);
        str_groups.Add(str_temp);
        t_res->MoveNext();
    }
    t_res->Clear();

    return str_groups;

}

wxString wfApp::get_only_group()
{
    wxArrayString array_group = get_group();
    if(array_group.GetCount() == 1)
    {
        wxString str = array_group.Item(0);
        return array_group.Item(0);
    }

    if(array_group.GetCount() == 0)
    {
        return wxEmptyString;
    }

    return NumToStr(array_group.GetCount());
}

bool wfApp::is_eds(wxString s_group)
{
    wxPostgreSQLresult *t_res;
    wxString l_query;
    l_query = wxT("SELECT count(*) as row_num FROM s_group_member WHERE group_id = '")+s_group+wxT("' AND is_eds = true AND employee_id = '")+gr_para.login_user+wxT("' and status = true;");
    t_res = conn->Execute(l_query);


    if(t_res->Status()!= PGRES_TUPLES_OK)
    {
        return false;
    }

    int icount = t_res->GetInt(wxT("row_num"));

    if(icount >=1)
    {
        t_res->Clear();
        return true;
    }
    else
    {
        t_res->Clear();
        return false;
    }
    return false;
}

wxString wfApp::get_operator_from_branch(wxString s_branch_id, wxString s_group_id)
{
    wxString str_sql = "select employee_id from s_cm_branch_rel where branch_id ='"+s_branch_id+wxT("' and \
                        group_id = '")+s_group_id+wxT("' and is_valid = true;");

    wxPostgreSQLresult * _res =  wxGetApp().app_sql_select(str_sql);

	if (_res->Status()!= PGRES_TUPLES_OK)
	{
		_res->Clear();
		return wxEmptyString;
	}

    int i_count = _res->GetRowsNumber();

    wxString str=wxEmptyString;

    if(i_count>0)
    {
        _res->MoveFirst();
        str = _res->GetVal(wxT("employee_id"));

    }

    return str;
}

wxString wfApp::get_branch_id(wxString s_project_id)
{
    wxString str_sql = "select branch_id from  s_project_info where project_id ='"+s_project_id+wxT("';");

    wxPostgreSQLresult * _res =  wxGetApp().app_sql_select(str_sql);

	if (_res->Status()!= PGRES_TUPLES_OK)
	{
		_res->Clear();
		return wxEmptyString;
	}

    int i_count = _res->GetRowsNumber();

    wxString str=wxEmptyString;

    if(i_count>0)
    {
        _res->MoveFirst();
        str = _res->GetVal(wxT("branch_id"));

    }

    return str;
}

bool wfApp::is_design(wxString s_group)
{
    wxPostgreSQLresult *t_res;
    wxString l_query;
    l_query = wxT("SELECT count(*) as row_num FROM s_group_member WHERE group_id = '")+s_group+wxT("' AND is_design = true AND employee_id = '")+gr_para.login_user+wxT("' and status = true;");
    t_res = conn->Execute(l_query);


    if(t_res->Status()!= PGRES_TUPLES_OK)
    {
        return false;
    }

    int icount = t_res->GetInt(wxT("row_num"));

    if(icount >=1)
    {
        t_res->Clear();
        return true;
    }
    else
    {
        t_res->Clear();
        return false;
    }
    return false;
}

bool wfApp::is_leader(wxString s_group)
{

    wxPostgreSQLresult *t_res;
    wxString l_query;
    l_query = wxT("SELECT count(1) as row_num FROM s_group_member WHERE group_id = '")+s_group+wxT("' AND is_leader = true AND employee_id = '")+gr_para.login_user+wxT("' and status = true;");
    t_res = conn->Execute(l_query);

    if(t_res->Status()!= PGRES_TUPLES_OK)
    {
        return false;
    }

    int icount = t_res->GetInt(wxT("row_num"));

    if(icount >=1)
    {
        t_res->Clear();
        return true;
    }
    else
    {
        t_res->Clear();
        return false;
    }
    return false;
}

wxArrayString wfApp::get_member_in_group(wxString str_group, bool with_leader)
{
    wxPostgreSQLresult *t_res;
    wxArrayString str_members;
    wxString l_query, str_temp;
    l_query = wxT("SELECT concat(employee_id,'-',name), is_leader FROM v_group_member WHERE group_id = '")+str_group+wxT("' AND plant = '")+gr_para.plant+wxT("' and status=true;");

    t_res = conn->Execute(l_query);


    if(t_res->Status()!= PGRES_TUPLES_OK)
    {
        return str_members;
    }

    int icount = t_res->GetRowsNumber();

    t_res->MoveFirst();
    for(int i=0;i<icount;i++)
    {
        str_temp = t_res->GetVal(0);

        if(!with_leader && t_res->GetBool(1))
        {
            t_res->MoveNext();
            continue;
        }

        str_members.Add(str_temp);
        t_res->MoveNext();
    }
    t_res->Clear();

    return str_members;

}

wxArrayString wfApp::get_member_in_group(wxArrayString str_group, bool with_leader)
{
    int i_count = str_group.GetCount();

    wxPostgreSQLresult *t_res;
    wxArrayString str_members;
    wxString l_query, str_temp;
    l_query = wxT("SELECT concat(employee_id,'-',name)as employee , is_leader FROM v_group_member WHERE plant = '")+gr_para.plant+wxT("'AND group_id = '")+str_group.Item(0)+ wxT("'  and status =true  ");
    for(int i =1;i<i_count;i++)
    {
        l_query = l_query + wxT(" OR group_id = '")+str_group.Item(i)+wxT("' ");
    }

    l_query = l_query+wxT(";");

    t_res = conn->Execute(l_query);


    if(t_res->Status()!= PGRES_TUPLES_OK)
    {
        return str_members;
    }

    int icount = t_res->GetRowsNumber();

    t_res->MoveFirst();
    for(int i=0;i<icount;i++)
    {
        str_temp = t_res->GetVal(0);

        if(!with_leader && t_res->GetBool(1))
        {
            t_res->MoveNext();
            continue;
        }

        str_members.Add(str_temp);
        t_res->MoveNext();
    }
    t_res->Clear();

    return str_members;
}

bool wfApp::change_log(wxString s_table, wxString s_keyword, wxString source_char,wxString source_value, wxString result_value, wxString change_way)
{
    wxString str_query;

    str_query = wxT("INSERT INTO l_change_log(table_str, key_word, source_char, source_value, result_value, \
            modify_person, modify_date, change_way) VALUES ('")+s_table+wxT("','")+s_keyword+wxT("','")+source_char+wxT("','")
            +source_value+wxT("','")+result_value+wxT("','")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+change_way+wxT("');");


    return conn->ExecuteVoid(str_query);

}

bool wfApp::update_data_in_database(wxString change_key, wxString change_value, wxString table_name, wxString pri_key, wxString pri_value)
{
    wxString str_query;
    str_query = wxT("UPDATE  ")+table_name+ wxT(" SET ")+change_key+wxT("='")+change_value+wxT("' , modify_date='")+DateToAnsiStr(wxDateTime::Now())+
                           wxT("', modify_emp_id='")+gr_para.login_user+wxT("' WHERE ")+pri_key+wxT("='")+pri_value+wxT("';");
    str_query.Replace(wxT("''"),wxT("NULL"));
    return conn->ExecuteVoid(str_query);
}

bool wfApp::get_client_version()
{
    wxString str_query;

    str_query = wxT("SELECT * FROM client_version WHERE is_current = true;");
    wxPostgreSQLresult *_res = conn->Execute(str_query);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return false;
    }

    int i_count = _res->GetRowsNumber();

    if(i_count == 0)
    {
        _res->Clear();
        return false;
    }

    _res->MoveFirst();

    wxString str_version = _res->GetVal(wxT("vesion_id"));
    wxString str_desc = _res->GetVal(wxT("change_log"));


    _res->Clear();

    wxArrayString arr_version = wxStringTokenize(str_version, wxT("."),wxTOKEN_RET_EMPTY_ALL );

    long l_major,l_minor,l_build,l_revision;

    int i_len = arr_version.GetCount();

    if(i_len<4)
    {
        for(int i=0;i<4-i_len;i++)
        {
            arr_version.Add(wxT("0"));
        }
    }

    arr_version.Item(0).ToLong(&l_major);
    arr_version.Item(1).ToLong(&l_minor);
    arr_version.Item(2).ToLong(&l_build);
    arr_version.Item(3).ToLong(&l_revision);

    if(l_major<AutoVersion::MAJOR)
        return false;

    if(l_major==AutoVersion::MAJOR&&l_minor<AutoVersion::MINOR)
        return false;

    if(l_major == AutoVersion::MAJOR&&l_minor == AutoVersion::MINOR && l_build<AutoVersion::BUILD)
        return false;

    if(l_major == AutoVersion::MAJOR&&l_minor==AutoVersion::MINOR&&l_build==AutoVersion::BUILD&&l_revision<=AutoVersion::REVISION)
        return false;

    if(wxMessageBox(_("版本由")+wxString(AutoVersion::FULLVERSION_STRING)+_("更新为")+str_version+
                    _(",更新内容:\n")+str_desc,_("版本更新"),wxYES_NO)==wxYES)
    {
        return true;
    }else
    {
        return false;
    }
}

wxArrayString wfApp::get_role_member(int &i_count, wxString s_role,wxString s_group)
{
    wxArrayString a_member;

    wxString s_sql, str;

    if(s_group.IsEmpty())
    {
        s_sql = wxT(" select concat(employee_id,'-',name) as employee_name from s_role_member where role_id='")+s_role+wxT("' and is_active=true; ");
    }else
    {
        s_sql = wxT(" select concat(employee_id,'-',name) as employee_name from v_group_role where role_id='")+s_role+wxT("' and group_id='")+s_group+wxT("' and is_active=true and status=true;");
    }

    wxPostgreSQLresult * res = app_sql_select(s_sql);


    if(res->Status()!= PGRES_TUPLES_OK)
    {
        return a_member;
    }

    i_count = res->GetRowsNumber();

    for(int i=0;i<i_count;i++)
    {
        str = res->GetVal(wxT("employee_name"));
        a_member.Add(str);

        res->MoveNext();
    }

    res->Clear();

    return a_member;
}

 bool wfApp::update_new_nstd_config(wxString s_nstd_id, int i_status)
 {
     wxString s_sql = wxT("UPDATE l_nonstd_app_header SET status =")+NumToStr(i_status)+wxT(" ,modify_date='")+DateToAnsiStr(wxDateTime::Now())+
                           wxT("', modify_emp_id='")+gr_para.login_user+wxT("' where nonstd_id='")+s_nstd_id+wxT("';");
     return app_sql_update(s_sql);
 }

 wxDateTime wfApp::get_prj_auth_date(wxString s_wbs)
 {
     wxString s_sql = wxT("select finish_date, group_id from l_proc_act where instance_id='")+s_wbs+wxT("' and action_id='AT00000003';");

     wxPostgreSQLresult * res = app_sql_select(s_sql);


    wxArrayString a_group = get_group();

    if(a_group.IsEmpty())
        return wxDateTime::Today();

    if(res->Status()!= PGRES_TUPLES_OK)
    {
        return wxDateTime::Today();
    }

    int i_count = res->GetRowsNumber();

    if(i_count==0)
    {
        return wxDateTime::Today();
    }else if (i_count==1)
        return res->GetDate(wxT("finish_date"));
    else
    {
        int i_group = a_group.GetCount();
        res->MoveFirst();
        for(int i=0;i<i_count;i++)
        {
            for(int j=0;j<i_group;j++)
            {
                if(res->GetVal(wxT("group_id"))==a_group.Item(j))
                   return res->GetDate(wxT("finish_date"));
            }
            res->MoveNext();

        }

        return wxDateTime::Today();
    }
 }

wxString wfApp::get_nstd_from_unit(wxString s_wbs, wxString s_flag)
{
    wxString s_sql, str;
    if(s_flag==wxT("E"))
         s_sql = wxT("select e_nstd_id from s_unit_info where wbs_no ='")+s_wbs+wxT("';");
    else
        s_sql = wxT(" select m_nstd_id from s_unit_info where wbs_no='")+s_wbs+wxT("';");

    wxPostgreSQLresult *_res= app_sql_select(s_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return wxEmptyString;
    }

    int i_count = _res->GetRowsNumber();

    if(i_count==0)
    {
        _res->Clear();
        return wxEmptyString;
    }

    if(s_flag==wxT("E"))
    {
        str = _res->GetVal(wxT("e_nstd_id"));
        _res->Clear();
        return str;
    }else
    {
        str = _res->GetVal(wxT("m_nstd_id"));
        _res->Clear();
        return str;
    }
}

wxArrayString  wfApp::get_sub_eng_list(int &i_count,bool b_twig)
{
    wxArrayString a_member;

    wxString s_sql, str;
    i_count =0;

    s_sql = wxT(" select concat(employee_id,'-',name) as employee from v_hierarchy where direct_leader ='")+gr_para.login_user+wxT("' and is_twig=")+BoolToStr(b_twig)+wxT(";");

    wxPostgreSQLresult * res = app_sql_select(s_sql);


    if(res->Status()!= PGRES_TUPLES_OK)
    {
        res->Clear();
        return a_member;
    }

    i_count = res->GetRowsNumber();

    for(int i=0;i<i_count;i++)
    {
        str = res->GetVal(wxT("employee"));
        a_member.Add(str);

        res->MoveNext();
    }

    res->Clear();

    return a_member;

}

bool wfApp::check_is_highspeed(wxString s_wbs)
{
    wxString s_sql = wxT("select speed from s_unit_parameter where wbs_no='")+s_wbs+wxT("';");
    wxPostgreSQLresult * res = app_sql_select(s_sql);

    if(res->Status()!= PGRES_TUPLES_OK)
    {
        res->Clear();
        return false;
    }

    int i_count =  res->GetRowsNumber();

    if(i_count==0)
    {
        res->Clear();
        return false;
    }

    double f_speed = res->GetDouble(wxT("speed"));

    if(f_speed >= 3.0)
    {
        res->Clear();
        return true;
    }else
    {
        res->Clear();
        return false;
    }

}

bool wfApp::check_new_config(wxArrayString &a_group, wxArrayString &a_flag,int &i_count, wxString s_lift_type, wxString &s_att_case)
{
    wxString s_sql = wxT("select * from s_flow_unit_list where elevator_type_id='")+s_lift_type+wxT("' AND is_nonstd=True;");
    wxPostgreSQLresult * res = app_sql_select(s_sql);

    a_flag.Clear();
    a_group.Clear();

    i_count =0;

    if(res->Status()!= PGRES_TUPLES_OK)
    {
        res->Clear();
        return false;
    }

    i_count = res->GetRowsNumber();

    if(i_count ==0)
    {
        res->Clear();
        return false;
    }

    wxString str;

    for(int i=0;i<i_count;i++)
    {
         str = res->GetVal(wxT("mode"));
         a_flag.Add(str);

         str = res->GetVal(wxT("group_id"));
         a_group.Add(str);

         s_att_case = res->GetVal(wxT("att_case"));

         res->MoveNext();
    }

    res->Clear();

    return true;

}

wxString wfApp::get_name(wxString s_id)
{
    wxString s_sql = wxT(" select name from s_employee where employee_id='")+s_id+wxT("';");
    wxPostgreSQLresult * res = app_sql_select(s_sql);
    if(res->Status()!= PGRES_TUPLES_OK)
    {
        res->Clear();
        return wxEmptyString;
    }

    int i_count = res->GetRowsNumber();

    if (i_count==0)
    {
        res->Clear();
        return wxEmptyString;
    }

    wxString str=wxEmptyString;

    if(i_count !=0)
    {
        str = res->GetVal(wxT("name"));
    }

    res->Clear();

    return str;

}

wxString wfApp::get_direct_leader(wxString _user)
{
    wxString s_sql = wxT("select direct_leader from s_hierarchy where employee_id = '")+_user+wxT("';");
    wxPostgreSQLresult * res = app_sql_select(s_sql);
    if(res->Status()!= PGRES_TUPLES_OK)
    {
        res->Clear();
        return wxEmptyString;
    }

    int i_count = res->GetRowsNumber();

    wxString str=wxEmptyString;

    if(i_count !=0)
    {
        str = res->GetVal(wxT("direct_leader"));
    }

    res->Clear();

    return str;

}

int wfApp::contractbook_lender_change(wxString s_cid, wxString s_aim)//-1 失败， 0-不在本人手上， 1-转借成功， 2-已经转借
{
    wxString s_sql=wxT("select count(*) as count from s_contract_br_log where b_user='")+gr_para.login_user+wxT("' and contract_doc_id='")+s_cid+wxT("' and br_status=true;");
    wxPostgreSQLresult * res = app_sql_select(s_sql);
    if(res->Status()!= PGRES_TUPLES_OK)
    {
        res->Clear();
        return -1;
    }

    int i_count = res->GetInt("count");

    if(i_count==0)
        return 2;

    res->Clear();

    s_sql = wxT(" UPDATE s_contract_br_log SET br_status=false, remarks='转借->")+s_aim+wxT("' where contract_doc_id='")+s_cid+wxT("' and br_status=true;");
    bool b_result=app_sql_update(s_sql);

    if(!b_result)
        return -1;

    s_sql = wxT("INSERT INTO s_contract_br_log(contract_doc_id, br_status, b_user, b_date, remarks, s_user) VALUES ('")+s_cid+wxT("',true,'")+
             s_aim.Left(8)+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','转借','")+gr_para.login_user+wxT("');");

    b_result=app_sql_update(s_sql);

    if(!b_result)
        return 0;


    return 1;
}
