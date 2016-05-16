#include "mythread.h"
#include "wfMain.h"
#include "prj_hex_result_dlg.h"

MyThread::MyThread(wfFrame* frame,wxArrayString & a_wbs, int i_way) : wxThread(), Thread_rfc_com(new Rfc_Communication)
{
    ThreadFrame = frame;
    array_wbs = a_wbs;
    thread_way = i_way;
    b_run = true;
}

MyThread::~MyThread()
{
    wxCriticalSectionLocker locker(wxGetApp().AppCritSection);

    wxArrayThread& threads = wxGetApp().AppThreads;
    threads.Remove(this);

    if ( threads.IsEmpty() )
    {
        // signal that no threads is waiting

        Thread_rfc_com->rfc_closed();
        if ( wxGetApp().AppShutdown )
        {
            wxGetApp().AppShutdown = false;

            wxGetApp().AppSemaphoreDone.Post();
        }
    }

    array_wbs.Clear();
}

// Thread entry
wxThread::ExitCode MyThread::Entry()
{

    int i_connect_times = 0;

    wxLongLong mils_used, start_mils;

    start_mils = wxGetLocalTimeMillis();



    while(!Thread_rfc_com->rfc_check_connect())
    {
        if(i_connect_times <3)
        {

            Thread_rfc_com->rfc_connect();
            Sleep(1000);
            i_connect_times++;
        }
        else
        {
            wxLogMessage(_("已经尝试")+NumToStr(i_connect_times+1)+_("次连接SAP,均无法登陆,线程终止!"));
            b_run = false;
            return NULL;
        }
    }

    Sleep(1000);


    while (b_run)
    {

        {
            wxCriticalSectionLocker locker(wxGetApp().AppCritSection);

            // If stop button pressed then return immediately
            if ( wxGetApp().AppShutdown )
            {
                b_run = false;
                return NULL;
            }
        }


        if ( TestDestroy() ) break;

        // Main block

        switch(thread_way)
        {
        case 0:
            get_prj_info_from_sap();

            b_run = false;
            break;
        case 1:
            get_prj_basic_info();
            b_run = false;
            break;
        case 2:
            get_prj_info_by_internal_day();
            b_run = false;
            break;
        case 3:
            get_hex_from_sap();
            b_run=false;
        default:
            b_run=false;
            break;

        }


    }
    mils_used = wxGetLocalTimeMillis() - start_mils;

    wxString str_id = wxString::Format("0x%lx",this->GetId());

    wxString str;
    int i_count= array_wbs.GetCount();

    for(int i=0; i<i_count; i++)
    {
        str= str + array_wbs.Item(i)+wxT("\n");
    }

    if(thread_way!=3)
        wxMessageBox(str_id+_("任务完成，耗时:")+NumToStr(mils_used/1000)+_("秒,更新如下项目(")+NumToStr(i_count)+wxT("条记录):\n")+str,_("提示!"),wxOK);

    return NULL;
}

void MyThread::get_prj_info_from_sap()
{
    RFC_FUNCTION_DESC_HANDLE fun_handle_desc;
    RFC_FUNCTION_HANDLE fun_handle;

    wxLogMessage(_("初始化条件..."));

    int i_count = array_wbs.GetCount();

    Value_Pool* v_wbs=new Value_Pool(i_count, true);
    Str_Line * line= v_wbs->Get_Name();
    line->cols= new wxString[1];
    line->num_cols = 1;
    line->cols[0] = "POSID";

    for(int i=0; i<i_count; i++)
    {
        line = v_wbs->Get_Value(i);
        line->num_cols = 1;
        line->cols = new wxString[1];
        line->cols[0] = array_wbs.Item(i);
    }

    wxString  s_plant = wxT("2101");
    Value_Pool * pool_basic;
    Value_Pool * pool_para;

    wxLogMessage(_("SAP正在创建函数..."));
    fun_handle = Thread_rfc_com->Create_Function(wxT("ZAP_PS_PROJECT_INFO"),fun_handle_desc);

    wxLogMessage(_("rfc函数正在填充参数..."));
    Thread_rfc_com->fillFunctionParameter(fun_handle_desc,fun_handle,wxT("CE_WERKS"),s_plant);
    Thread_rfc_com->fillFunctionParameter(fun_handle_desc,fun_handle,wxT("IT_CE_POSID"),v_wbs);

    wxLogMessage(_("rfc函数正在运行函数（ZAP_PS_PROJECT_INFO）..."));
    Thread_rfc_com->RunFunction(fun_handle);

    wxLogMessage(_("SAP正在获取项目基本信息..."));
    pool_basic = Thread_rfc_com->GetResult(wxT("OT_PROJ"),fun_handle_desc,fun_handle);

    wxLogMessage(_("SAP正在获取项目参数..."));
    pool_para = Thread_rfc_com->GetResult(wxT("OT_CONF"), fun_handle_desc, fun_handle);

    wxLogMessage(_("SAP销毁访问函数..."));
    Thread_rfc_com->DestroyFunction(fun_handle);

    if(pool_basic==NULL)
    {
        wxLogMessage("根据条件查询结果为空");

        return;
    }

    wxLogMessage(_("更新本地数据库..."));
    ThreadFrame->update_project_from_sap(array_wbs, pool_basic, pool_para, thread_way);


    if(pool_basic)
        delete pool_basic;

    if(pool_para)
        delete pool_para;
}

void MyThread::get_prj_info_by_internal_day()
{
    //internal day mode  array_wbs has 2 data one is from date ,one is to date;
    RFC_FUNCTION_DESC_HANDLE fun_handle_desc;
    RFC_FUNCTION_HANDLE fun_handle;

    wxLogMessage(_("初始化条件..."));
    wxString  s_plant = wxT("2101");
    wxString str;

    Value_Pool * pool_basic;
    Value_Pool * pool_para;

    wxLogMessage(_("SAP正在创建函数..."));
    fun_handle = Thread_rfc_com->Create_Function(wxT("ZAP_PS_PROJECT_INFO"),fun_handle_desc);

    wxLogMessage(_("rfc函数正在填充参数..."));
    // wxMessageBox(array_wbs.Item(0)+array_wbs.Item(1));
    Thread_rfc_com->fillFunctionParameter(fun_handle_desc,fun_handle,wxT("CE_WERKS"),s_plant);
    Thread_rfc_com->fillFunctionParameter(fun_handle_desc,fun_handle,wxT("CE_START_DATE"),array_wbs.Item(0));
    Thread_rfc_com->fillFunctionParameter(fun_handle_desc,fun_handle,wxT("CE_END_DATE"),array_wbs.Item(1));

    wxLogMessage(_("rfc函数正在运行函数（ZAP_PS_PROJECT_INFO）..."));
    Thread_rfc_com->RunFunction(fun_handle);

    wxLogMessage(_("SAP正在获取项目基本信息..."));
    pool_basic = Thread_rfc_com->GetResult(wxT("OT_PROJ"),fun_handle_desc,fun_handle);

    wxLogMessage(_("SAP正在获取项目参数..."));
    pool_para = Thread_rfc_com->GetResult(wxT("OT_CONF"), fun_handle_desc, fun_handle);

    wxLogMessage(_("SAP销毁访问函数..."));
    Thread_rfc_com->DestroyFunction(fun_handle);

    array_wbs.Clear();

    if(pool_basic==NULL)
    {
        wxLogMessage("根据条件查询结果为空");

        return;
    }

    wxLogMessage(_("更新本地数据库..."));
    int i_count = pool_basic->GetNumOfRows();

    if(i_count<=0)
        return;

    for(int i=0; i<i_count; i++)
    {
        Str_Line* line = pool_basic->Get_Value(i);

        str = line->cols[2];

        str = sapwbsconvert(str);

        if(str.Left(1).Upper()!=wxT("E"))
            continue;

        array_wbs.Add(str);
    }


    ThreadFrame->update_project_from_sap(array_wbs, pool_basic, pool_para, thread_way);

    if(pool_basic)
        delete pool_basic;

    if(pool_para)
        delete pool_para;

}

void MyThread::get_prj_basic_info()
{
    RFC_FUNCTION_DESC_HANDLE fun_handle_desc;
    RFC_FUNCTION_HANDLE fun_handle;

    wxLogMessage(_("初始化条件..."));

    wxArrayString a_support;
    wxString str;
    str=wxT("0760");
    a_support.Add(str);
    str=wxT("0360");
    a_support.Add(str);
    str = wxT("0440");
    a_support.Add(str);


    wxArraySupport array_support = ThreadFrame->get_basic_info_support(a_support);

    int i_count = array_wbs.GetCount();

    Value_Pool* v_wbs=new Value_Pool(1, true);
    Str_Line * line= v_wbs->Get_Name();
    line->cols= new wxString[2];
    line->num_cols = 2;
    line->cols[0] = "POSID";
    line->cols[1] =  "MATNR";

    wxString  s_plant = wxT("2101");
    Value_Pool * pool_wbs_bom;

    s_basic_info value_basic_info;

    line = v_wbs->Get_Value(0);
    line->num_cols = 2;
    if(!line->cols)
        line->cols = new wxString[2];

    for(int i=0; i<i_count; i++)
    {
        line->cols[0] = array_wbs.Item(i);
        line->cols[1] = wxEmptyString;

        wxLogMessage(_("SAP正在创建函数..."));
        fun_handle = Thread_rfc_com->Create_Function(wxT("ZAP_PS_WBSBOM_INFO"),fun_handle_desc);

        wxLogMessage(_("rfc函数正在填充参数..."));

        Thread_rfc_com->fillFunctionParameter(fun_handle_desc,fun_handle,wxT("IT_CE_WBSBOM"),v_wbs);
        Thread_rfc_com->fillFunctionParameter(fun_handle_desc,fun_handle,wxT("CE_WERKS"),s_plant);

        wxLogMessage(_("rfc函数正在运行函数（ZAP_PS_WBSBOM_INFO）..."));
        Thread_rfc_com->RunFunction(fun_handle);

        wxLogMessage(_("SAP正在获取项目基本信息...-")+array_wbs.Item(i));
        pool_wbs_bom = Thread_rfc_com->GetResult(wxT("OT_WBSBOM"),fun_handle_desc,fun_handle);

        wxLogMessage(_("SAP销毁访问函数..."));
        Thread_rfc_com->DestroyFunction(fun_handle);

        if(pool_wbs_bom==NULL)
        {
            wxLogMessage("根据条件查询结果为空");

            return;
        }

        wxLogMessage(_("开始计算项目基本信息..."));
        if(ThreadFrame->Cal_prj_basic_info(array_wbs.Item(i),pool_wbs_bom, array_support))
        {
            wxLogMessage(array_wbs.Item(i)+_("更新项目基本信息成功."));
        }

        if(pool_wbs_bom)
            delete pool_wbs_bom;
    }

    ThreadFrame->check_basic_info_for_array(array_wbs);
}

void MyThread::get_hex_from_sap()
{
    RFC_FUNCTION_DESC_HANDLE fun_handle_desc;
    RFC_FUNCTION_HANDLE fun_handle;

    wxLogMessage(_("初始化条件..."));

    wxArrayString a_support;
    wxString str;
    str=wxT("0670");
    a_support.Add(str);
    str=wxT("0750");
    a_support.Add(str);
    str = wxT("0450");
    a_support.Add(str);

    wxArraySupport array_support = ThreadFrame->get_basic_info_support(a_support);

    int i_count = array_wbs.GetCount();

    Value_Pool* v_wbs=new Value_Pool(1, true);
    Str_Line * line= v_wbs->Get_Name();
    line->cols= new wxString[2];
    line->num_cols = 2;
    line->cols[0] = "POSID";
    line->cols[1] =  "MATNR";

    wxString  s_plant = wxT("2101");
    Value_Pool * pool_wbs_bom;

    s_sap_hex_info value_hex_info;
    wxArrayHex array_hex;

    line = v_wbs->Get_Value(0);
    line->num_cols = 2;
    if(!line->cols)
        line->cols = new wxString[2];

    for(int i=0; i<i_count; i++)
    {
        line->cols[0] = array_wbs.Item(i);
        line->cols[1] = wxEmptyString;

        wxLogMessage(_("SAP正在创建函数..."));
        fun_handle = Thread_rfc_com->Create_Function(wxT("ZAP_PS_WBSBOM_INFO"),fun_handle_desc);

        wxLogMessage(_("rfc函数正在填充参数..."));

        Thread_rfc_com->fillFunctionParameter(fun_handle_desc,fun_handle,wxT("IT_CE_WBSBOM"),v_wbs);
        Thread_rfc_com->fillFunctionParameter(fun_handle_desc,fun_handle,wxT("CE_WERKS"),s_plant);

        wxLogMessage(_("rfc函数正在运行函数（ZAP_PS_WBSBOM_INFO）..."));
        Thread_rfc_com->RunFunction(fun_handle);

        wxLogMessage(_("SAP正在获取项目基本信息...-")+array_wbs.Item(i));
        pool_wbs_bom = Thread_rfc_com->GetResult(wxT("OT_WBSBOM"),fun_handle_desc,fun_handle);

        wxLogMessage(_("SAP销毁访问函数..."));
        Thread_rfc_com->DestroyFunction(fun_handle);

        if(pool_wbs_bom==NULL)
        {
            wxLogMessage(_("根据条件查询结果为空"));

            return;
        }

        wxLogMessage(_("开始获取随行电缆|曳引钢丝绳|补偿链单重HEX值..."));
        value_hex_info =  ThreadFrame->Cal_prj_weight_hex_info(array_wbs.Item(i),pool_wbs_bom, array_support);
        array_hex.Add(value_hex_info);

        wxLogMessage(array_wbs.Item(i)+_("计算完成"));

        if(pool_wbs_bom)
            delete pool_wbs_bom;
    }

    prj_hex_result_dlg dlg;
    dlg.set_refresh_list(array_hex);

    dlg.refresh_list();

    if(dlg.ShowModal()==wxID_OK)
        return;

}


