#include "wf_operator.h"
#include "wfApp.h"


v_wf_action & v_wf_action::operator=(const v_wf_action& other)
{
    if(&other != this)
    {
        s_workflow_id = other.s_workflow_id;
        s_action_id = other.s_action_id;
        s_action_name = other.s_action_name;
        s_pre_action_id = other.s_pre_action_id;
        s_follow_action_id = other.s_follow_action_id;
        i_flow_ser = other.i_flow_ser;
        i_total_flow = other.i_total_flow;
        b_is_transit = other.b_is_transit;
        b_allow_return = other.b_allow_return;
        i_action_lead = other.i_action_lead;
        i_urgent_lead = other.i_urgent_lead;
        s_action_lead_unit = other.s_action_lead_unit;
        s_operator_id = other.s_operator_id;
        s_group_id = other.s_group_id;
        b_is_assigned = other.b_is_assigned;
        s_action_type = other.s_action_type;
        s_group_catalog = other.s_group_catalog;

        b_is_evaluate = other.b_is_evaluate;
        b_is_need_eval = other.b_is_need_eval;
        b_is_check = other.b_is_check;
        i_join_mode = other.i_join_mode;
        i_split_mode = other.i_split_mode;
        s_role_id = other.s_role_id;
        is_start = other.is_start;
        is_end = other.is_end;
    }
    return *this;
}

v_wf_transition& v_wf_transition::operator=(const v_wf_transition& other)
{
    if(&other != this)
    {
        item_id = other.item_id;
        s_trans_name = other.s_trans_name;
        s_workflow_id = other.s_workflow_id;
        s_input = other.s_input;
        s_output = other.s_output;
        s_desc = other.s_desc;
    }

    return *this;
}

v_wf_instance & v_wf_instance::operator=(const v_wf_instance& other)
{
    if(&other != this)
    {

        s_action = other.s_action;
        s_instance_id = other.s_instance_id;


        t_start = other.t_start;
        t_finish = other.t_finish;
        is_active = other.is_active;
        return_times = other.return_times;
        is_restart = other.is_restart;
        step_desc = other.step_desc;
        s_flag = other.s_flag;
    }
    return *this;
}
/*
//wfInstanceArray
WX_DEFINE_OBJARRAY(wfInstanceArray);

int arraycompare(v_wf_instance** arg1, v_wf_instance** arg2)
{
    return ((*arg1)->s_action.i_flow_ser< (*arg2)->s_action.i_flow_ser);
}
*/

v_wf_action* get_template_action(wxString str_workflow)
{
    wxPostgreSQLresult * l_res;
    wxString str_query = wxT("SELECT workflow_id, action_id, action_name, flow_ser, total_flow, pre_action_id, \
       follow_action_id, is_transit, allow_return, action_lead, urgent_lead, \
       action_lead_unit, operator_id, group_id, is_assigned, action_type, \
       group_catalog, is_evaluate, is_need_eval,is_checked, join_mode,split_mode,role_id,is_start,is_end FROM v_process_info WHERE workflow_id ='")+str_workflow+wxT("' AND action_status = 1 ORDER BY flow_ser ASC;");
    l_res = wxGetApp().app_sql_select(str_query);


    if(l_res->Status() != PGRES_TUPLES_OK)
    {
        l_res->Clear();
        return 0;
    }

    int icount = l_res->GetRowsNumber();

    v_wf_action* ser_temp = new v_wf_action[icount];
    v_wf_action wf_temp;
    l_res->MoveFirst();
    for(int i=0; i<icount; i++)
    {
        wf_temp.s_workflow_id = l_res->GetVal(wxT("workflow_id"));
        wf_temp.s_action_id = l_res->GetVal(wxT("action_id"));
        wf_temp.s_action_name = l_res->GetVal(wxT("action_name"));
        wf_temp.i_flow_ser = l_res->GetInt(wxT("flow_ser"));
        wf_temp.i_total_flow = l_res->GetInt(wxT("total_flow"));
        wf_temp.s_pre_action_id = l_res->GetVal(wxT("pre_action_id"));
        wf_temp.s_follow_action_id = l_res->GetVal(wxT("follow_action_id"));
        wf_temp.b_is_transit = l_res->GetBool(wxT("is_transit"));
        wf_temp.b_allow_return = l_res->GetBool(wxT("allow_return"));
        wf_temp.i_action_lead = l_res->GetInt(wxT("action_lead"));
        wf_temp.i_urgent_lead = l_res->GetInt(wxT("urgent_lead"));
        wf_temp.s_action_lead_unit = l_res->GetVal(wxT("action_lead_unit"));
        wf_temp.s_operator_id = l_res->GetVal(wxT("operator_id"));
        wf_temp.s_group_id = l_res->GetVal(wxT("group_id"));
        wf_temp.b_is_assigned = l_res->GetBool(wxT("is_assigned"));
        wf_temp.s_action_type = l_res->GetVal(wxT("action_type"));
        wf_temp.s_group_catalog = l_res->GetVal(wxT("group_catalog"));
        wf_temp.b_is_evaluate = l_res->GetBool(wxT("is_evaluate"));
        wf_temp.b_is_need_eval = l_res->GetBool(wxT("is_need_eval"));
        wf_temp.b_is_check = l_res->GetBool(wxT("is_checked"));
        wf_temp.i_join_mode = l_res->GetInt(wxT("join_mode"));
        wf_temp.i_split_mode = l_res->GetInt(wxT("split_mode"));
        wf_temp.s_role_id = l_res->GetVal(wxT("role_id"));
        wf_temp.is_start = l_res->GetBool(wxT("is_start"));
        wf_temp.is_end = l_res->GetBool(wxT("is_end"));
        ser_temp[i]=wf_temp;
        l_res->MoveNext();
    }

    l_res->Clear();
    return ser_temp;
}

v_wf_action* get_template_action(wxString str_workflow,int &i_count)
{
    wxPostgreSQLresult * l_res;

    i_count =0;
    wxString str_query = wxT("SELECT workflow_id, action_id, action_name, flow_ser, total_flow, pre_action_id, \
       follow_action_id, is_transit, allow_return, action_lead, urgent_lead, \
       action_lead_unit, operator_id, group_id, is_assigned, action_type, \
       group_catalog, is_evaluate, is_need_eval,is_checked, join_mode,split_mode,role_id FROM v_process_info WHERE workflow_id ='")+str_workflow+wxT("' AND action_status = 1 ORDER BY flow_ser ASC;");
    l_res = wxGetApp().app_sql_select(str_query);

    if(l_res->Status() != PGRES_TUPLES_OK)
    {
        l_res->Clear();
        return 0;
    }

    i_count = l_res->GetRowsNumber();

    v_wf_action* ser_temp = new v_wf_action[i_count];
    v_wf_action wf_temp;
    l_res->MoveFirst();
    for(int i=0; i<i_count; i++)
    {
        wf_temp.s_workflow_id = l_res->GetVal(wxT("workflow_id"));
        wf_temp.s_action_id = l_res->GetVal(wxT("action_id"));
        wf_temp.s_action_name = l_res->GetVal(wxT("action_name"));
        wf_temp.i_flow_ser = l_res->GetInt(wxT("flow_ser"));
        wf_temp.i_total_flow = l_res->GetInt(wxT("total_flow"));
        wf_temp.s_pre_action_id = l_res->GetVal(wxT("pre_action_id"));
        wf_temp.s_follow_action_id = l_res->GetVal(wxT("follow_action_id"));
        wf_temp.b_is_transit = l_res->GetBool(wxT("is_transit"));
        wf_temp.b_allow_return = l_res->GetBool(wxT("allow_return"));
        wf_temp.i_action_lead = l_res->GetInt(wxT("action_lead"));
        wf_temp.i_urgent_lead = l_res->GetInt(wxT("urgent_lead"));
        wf_temp.s_action_lead_unit = l_res->GetVal(wxT("action_lead_unit"));
        wf_temp.s_operator_id = l_res->GetVal(wxT("operator_id"));
        wf_temp.s_group_id = l_res->GetVal(wxT("group_id"));
        wf_temp.b_is_assigned = l_res->GetBool(wxT("is_assigned"));
        wf_temp.s_action_type = l_res->GetVal(wxT("action_type"));
        wf_temp.s_group_catalog = l_res->GetVal(wxT("group_catalog"));
        wf_temp.b_is_evaluate = l_res->GetBool(wxT("is_evaluate"));
        wf_temp.b_is_need_eval = l_res->GetBool(wxT("is_need_eval"));
        wf_temp.b_is_check = l_res->GetBool(wxT("is_checked"));
        wf_temp.i_join_mode = l_res->GetInt(wxT("join_mode"));
        wf_temp.i_split_mode = l_res->GetInt(wxT("split_mode"));
        wf_temp.s_role_id = l_res->GetVal(wxT("role_id"));
        ser_temp[i]=wf_temp;
        l_res->MoveNext();
    }

    l_res->Clear();
    return ser_temp;
}

v_wf_action get_wf_action(wxString s_action_id, v_wf_action* t_temp, int i_range)
{
    v_wf_action  a_wf_action;
    for(int i=0; i<i_range; i++)
    {
        if(t_temp[i].s_action_id==s_action_id)
        {
            a_wf_action = t_temp[i];
            return a_wf_action;
        }
    }

    return a_wf_action;
}

v_wf_action* get_next_action(wxString s_workflow, wxString s_cur_action, int &i_ways)
{
    int i_range=0;
    v_wf_action * v_temp = get_template_action(s_workflow,i_range);
    v_wf_action * v_result = NULL;

    wxString s_sql = wxT(" select output from s_transitions where workflow_id='")+s_workflow+wxT("' and input='")+s_cur_action+wxT("';");
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(s_sql);

    if(_res->Status() != PGRES_TUPLES_OK)
    {
        _res->Clear();
        return NULL;
    }

    i_ways = _res->GetRowsNumber();

    if(i_ways==0)
        return NULL;

    v_result =new v_wf_action[i_ways];
    wxString s_action_id;

    for(int i=0; i<i_ways; i++)
    {
        s_action_id= _res->GetVal("output");
        v_result[i] = get_wf_action(s_action_id, v_temp, i_range);

        _res->MoveNext();

    }

    _res->Clear();

    delete [] v_temp;

    return v_result;
}

v_wf_action* get_pre_action(wxString s_workflow, wxString s_cur_action, int &i_ways)
{
    int i_range=0;
    v_wf_action * v_temp = get_template_action(s_workflow,i_range);
    v_wf_action * v_result = NULL;

    wxString s_sql = wxT(" select input from s_transitions where workflow_id='")+s_workflow+wxT("' and output='")+s_cur_action+wxT("';");
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(s_sql);

    if(_res->Status() != PGRES_TUPLES_OK)
    {
        _res->Clear();
        return NULL;
    }

    i_ways = _res->GetRowsNumber();

    if(i_ways==0)
        return NULL;

    v_result =new v_wf_action[i_ways];
    wxString s_action_id;

    for(int i=0; i<i_ways; i++)
    {
        s_action_id= _res->GetVal("input");
        v_result[i] = get_wf_action(s_action_id, v_temp, i_range);

        _res->MoveNext();

    }

    _res->Clear();

    delete [] v_temp;

    return v_result;
}


wf_process::wf_process(const wxString &_workflow, const wxString &_instance, wxString _flag)
{
    //ctor
    cr_flow_ser =0 ;
    str_instance = _instance;

    wxPostgreSQLresult * l_res;
    /*
        wxString str_query = wxT("SELECT instance_id, workflow_id, action_id, flow_ser, total_flow, \
           pre_action_id, follow_action_id, is_transit, allow_return, action_lead, \
           urgent_lead, action_lead_unit, operator_id, group_id, is_assigned, \
           action_type, group_catalog, start_date, finish_date, is_active, \
           return_time, is_restart, step_desc_id FROM l_proc_act WHERE instance_id='")+str_instance+wxT("' AND workflow_id = '")+_workflow+wxT("' ORDER BY flow_ser ASC;");
    */
    wxString str_query;

    if(_flag.IsEmpty())
        str_query = wxT("SELECT * FROM l_proc_act WHERE instance_id='")+str_instance+wxT("' AND workflow_id = '")+_workflow+wxT("' ORDER BY flow_ser ASC;");
    else
        str_query = wxT("SELECT * FROM l_proc_act WHERE instance_id='")+str_instance+wxT("' AND workflow_id = '")+_workflow+wxT("' and flag like '%")+_flag+wxT("%' ORDER BY flow_ser ASC;");

    l_res = wxGetApp().app_sql_select(str_query);

    if(l_res->Status() != PGRES_TUPLES_OK/* || l_res->Status()!= PGRES_COMMAND_OK*/)
    {
        l_res->Clear();
        return;
    }


    total_step = l_res->GetRowsNumber();


    if(total_step==0)
    {
        ser_proc = NULL;
        l_res->Clear();
        return;
    }

    v_wf_instance t_proc;
    ser_proc = new v_wf_instance[total_step];

//    ser_proc.Empty();
    l_res->MoveFirst();
    for(int i=0; i<total_step; i++)
    {
        t_proc.is_active = l_res->GetBool(wxT("is_active"));
        t_proc.is_restart = l_res->GetBool(wxT("is_restart"));
        t_proc.is_return = l_res->GetBool(wxT("is_return"));
        t_proc.return_times = l_res->GetInt(wxT("return_time"));
        t_proc.step_desc = l_res->GetVal(wxT("step_desc_id"));
        t_proc.s_instance_id = l_res->GetVal(wxT("instance_id"));
        t_proc.t_start= l_res->GetDateTime(wxT("start_date"));
        t_proc.t_finish = l_res->GetDateTime(wxT("finish_date"));

        t_proc.s_action.s_workflow_id = l_res->GetVal(wxT("workflow_id"));
        t_proc.s_action.s_action_id = l_res->GetVal(wxT("action_id"));
        t_proc.s_action.i_flow_ser = l_res->GetInt(wxT("flow_ser"));
        t_proc.s_action.i_total_flow = l_res->GetInt(wxT("total_flow"));
        t_proc.s_action.s_pre_action_id = l_res->GetVal(wxT("pre_action_id"));
        t_proc.s_action.s_follow_action_id = l_res->GetVal(wxT("follow_action_id"));
        t_proc.s_action.b_is_transit = l_res->GetBool(wxT("is_transit"));
        t_proc.s_action.b_allow_return = l_res->GetBool(wxT("allow_return"));
        t_proc.s_action.i_action_lead = l_res->GetInt(wxT("action_lead"));
        t_proc.s_action.i_urgent_lead = l_res->GetInt(wxT("urgent_lead"));
        t_proc.s_action.s_action_lead_unit = l_res->GetVal(wxT("action_lead_unit"));
        t_proc.s_action.s_operator_id = l_res->GetVal(wxT("operator_id"));
        t_proc.s_action.s_group_id = l_res->GetVal(wxT("group_id"));
        t_proc.s_action.b_is_assigned = l_res->GetBool(wxT("is_assigned"));
        t_proc.s_action.s_action_type = l_res->GetVal(wxT("action_type"));
        t_proc.s_action.s_group_catalog = l_res->GetVal(wxT("group_catalog"));
        t_proc.s_action.b_is_evaluate = l_res->GetBool(wxT("is_evaluate"));
        t_proc.s_action.b_is_need_eval = l_res->GetBool(wxT("is_need_eval"));
        t_proc.s_action.b_is_check = l_res->GetBool(wxT("is_checked"));
        t_proc.s_action.s_role_id = l_res->GetVal(wxT("role_id"));
        t_proc.s_flag = l_res->GetVal(wxT("flag"));
        t_proc.s_action.is_start = l_res->GetBool(wxT("is_start"));
        t_proc.s_action.is_end = l_res->GetBool(wxT("is_end"));

//       ser_proc.Add(t_proc);
        ser_proc[i] = t_proc;

        l_res->MoveNext();
    }

    cr_flow_ser = total_step;
    l_res->Clear();
    MoveToActive();

}


int wf_process::FindSteps(wxString t_action_id)
{
    for(int i=0; i<total_step; i++)
    {
        if(ser_proc[i].s_action.s_action_id == t_action_id)
        {
            Locate(i+1);
            return i+1;
        }
    }

    return 0;
}

int wf_process::MoveNext()
{
    cr_flow_ser  = cr_flow_ser + 1;
    return cr_flow_ser;
}

int wf_process::MovePrevious()
{
    cr_flow_ser = cr_flow_ser -1;

    return cr_flow_ser;
}

int wf_process::MoveToActive()
{
    if(total_step ==0)
        return 0;

    if(ser_proc[cr_flow_ser-1].is_active==true)
        return cr_flow_ser;

    for(int i=total_step; i>0; i--)
    {
        if(ser_proc[i-1].is_active == true)
        {
            cr_flow_ser = i;
            return cr_flow_ser;
        }
    }

    return -1;
}

int wf_process::MoveLast()
{
    cr_flow_ser = total_step;

    return cr_flow_ser;
}

v_wf_instance wf_process::get_cur_instance_action()
{

    if(cr_flow_ser>=1)
        return ser_proc[cr_flow_ser-1];
}

v_wf_instance wf_process::get_next_instance_action()
{

    if(cr_flow_ser< total_step)
        return ser_proc[cr_flow_ser];
}

v_wf_instance wf_process::get_previous_instance_action()
{
    return ser_proc[cr_flow_ser-2];
}
//
void wf_process::create_step_action(v_wf_action* _template)
{
    total_step = total_step+1;

    v_wf_instance * p_instance = new v_wf_instance[total_step];

    for(int i =0; i<total_step-1; i++)
    {
        p_instance[i] = ser_proc[i];
    }

    if(ser_proc)
        delete [] ser_proc;

    ser_proc = p_instance;
    v_wf_instance t_proc;

    t_proc.s_instance_id = str_instance;
    t_proc.s_action = _template[total_step-1];
    t_proc.t_start = wxDateTime::Now();
    t_proc.is_active = true;
    t_proc.is_restart = false;
    t_proc.is_return = false;
    t_proc.return_times = 0;
    t_proc.step_desc = wxEmptyString;
    ser_proc[total_step-1] = t_proc;
//    ser_proc.Add(t_proc);
    cr_flow_ser = total_step;

}

void wf_process::create_step_action(v_wf_action* _template, int i_total)
{
    total_step = i_total+1;

    v_wf_instance * p_instance = new v_wf_instance[total_step];

    for(int i =0; i<total_step-1; i++)
    {
        p_instance[i] = ser_proc[i];
    }

    if(ser_proc)
        delete [] ser_proc;

    ser_proc = p_instance;
    v_wf_instance t_proc;

    t_proc.s_instance_id = str_instance;
    t_proc.s_action = _template[total_step-1];
    t_proc.t_start = wxDateTime::Now();
    t_proc.is_active = true;
    t_proc.is_restart = false;
    t_proc.is_return = false;
    t_proc.return_times = 0;
    t_proc.step_desc = wxEmptyString;
    ser_proc[total_step-1] = t_proc;
//    ser_proc.Add(t_proc);
    cr_flow_ser = total_step;

}



wf_operator::wf_operator(const wxString &_instance, const wxString &_workflow,  v_wf_action* _template)
{
    s_instance = _instance;
    wf_proc_template = _template;
    s_workflow = _workflow;
//   wf_proc_act =0;

    wf_proc_act = new wf_process(s_workflow, s_instance);

}

bool wf_operator::Feed_back(wxString &str_desc)//feed back , store the aiming action desc in log,
{
    wxString str_from, str_to, str_temp, person_from, person_to;
    bool b_arrive;
    int i_return_times;
    wxDateTime t_from, t_to;

    wf_proc_act->MoveToActive();

    int i_cur_step = wf_proc_act->GetCurrentStep();
    if(i_cur_step <=1)
    {
        wxLogMessage(_("起始步骤， 无法操作!"));
        return false;
    }

    v_wf_instance l_instance = wf_proc_act->get_cur_instance_action();

    if(!l_instance.s_action.b_allow_return)
    {
        wxLogMessage(s_instance + _(":此步骤不允许退回!"));
        return false;

    }

    str_from = l_instance.s_action.s_action_id;


    l_instance.is_active = false;

    t_from = l_instance.t_start;
    person_from = l_instance.s_action.s_operator_id;
    update_process_status(l_instance, true);

    wf_proc_act->MovePrevious();
    l_instance = wf_proc_act->get_cur_instance_action();

    b_arrive = l_instance.s_action.b_is_transit;

    while(b_arrive && l_instance.s_action.i_flow_ser !=1)
    {

        wf_proc_act->MovePrevious();
        l_instance = wf_proc_act->get_cur_instance_action();
        b_arrive = l_instance.s_action.b_is_transit;

    }

    str_to = l_instance.s_action.s_action_id;
    t_to  = l_instance.t_finish;
    person_to = l_instance.s_action.s_operator_id;

    l_instance.is_return= true;
    l_instance.return_times = l_instance.return_times+1;
    i_return_times = l_instance.return_times;

    if(!str_desc.IsEmpty())
    {
        str_temp = Get_Desc_id();
        update_desc(str_temp,str_desc,false);

    }

    return_log(str_from,str_to, i_return_times,t_from, t_to,person_from, person_to, str_temp);

    l_instance.is_active = true;

    if(!str_desc.IsEmpty())
    {
        l_instance.step_desc = str_temp;
    }
    else l_instance.step_desc= wxEmptyString;

    return update_process_status(l_instance, true);
}

bool wf_operator::Feed_pre_back(wxString &str_desc)
{
    wxString str_from, str_to, str_temp, person_from, person_to;
    bool b_arrive;
    int i_return_times;
    wxDateTime t_from, t_to;

    wf_proc_act->MoveToActive();

    int i_cur_step = wf_proc_act->GetCurrentStep();
    if(i_cur_step <=1)
    {
        wxLogMessage(_("起始步骤， 无法操作!"));
        return false;
    }

    v_wf_instance l_instance = wf_proc_act->get_cur_instance_action();

    str_from = l_instance.s_action.s_action_id;


    l_instance.is_active = false;

    t_from = l_instance.t_start;
    person_from = l_instance.s_action.s_operator_id;
    update_process_status(l_instance, true);

    wf_proc_act->MovePrevious();
    l_instance = wf_proc_act->get_cur_instance_action();

    str_to = l_instance.s_action.s_action_id;
    t_to  = l_instance.t_finish;
    person_to = l_instance.s_action.s_operator_id;

    l_instance.is_return= true;
    l_instance.return_times = l_instance.return_times+1;
    i_return_times = l_instance.return_times;

    if(!str_desc.IsEmpty())
    {
        str_temp = Get_Desc_id();
        update_desc(str_temp,str_desc,false);

    }

    return_log(str_from,str_to, i_return_times,t_from, t_to,person_from, person_to, str_temp);

    l_instance.is_active = true;

    if(!str_desc.IsEmpty())
    {
        l_instance.step_desc = str_temp;
    }
    else l_instance.step_desc= wxEmptyString;

    wf_proc_act->set_instance(l_instance);

    return update_process_status(l_instance, true);
}

bool wf_operator::Feed_back(wxString &str_desc, wxString &aim_action_id)
{
    wxString str_from, str_to, str_temp, person_from, person_to;

    int i_return_times;
    wxDateTime t_from, t_to;

    wf_proc_act->MoveToActive();

    int i_cur_step = wf_proc_act->GetCurrentStep();
    if(i_cur_step <=1)
    {
        wxLogMessage(_("起始步骤， 无法操作!"));
        return false;
    }

    v_wf_instance l_instance = wf_proc_act->get_cur_instance_action();

    str_from = l_instance.s_action.s_action_id;

    l_instance.is_active = false;

    t_from = l_instance.t_start;
    person_from = l_instance.s_action.s_operator_id;
    update_process_status(l_instance, true);

    wf_proc_act->MovePrevious();
    l_instance = wf_proc_act->get_cur_instance_action();

    while(l_instance.s_action.s_action_id != aim_action_id)
    {

        wf_proc_act->MovePrevious();
        l_instance = wf_proc_act->get_cur_instance_action();
    }

    t_to  = l_instance.t_finish;
    person_to = l_instance.s_action.s_operator_id;

    l_instance.is_return= true;
    l_instance.return_times = l_instance.return_times+1;
    i_return_times = l_instance.return_times;

    if(!str_desc.IsEmpty())
    {
        str_temp = Get_Desc_id();
        update_desc(str_temp,str_desc,false);

    }

    return_log(str_from, aim_action_id, i_return_times,t_from, t_to,person_from, person_to, str_temp);

    l_instance.is_active = true;

    if(!str_desc.IsEmpty())
    {
        l_instance.step_desc = str_temp;
    }
    else l_instance.step_desc= wxEmptyString;

    wf_proc_act->set_instance(l_instance);

    return update_process_status(l_instance, true);

}

bool wf_operator::Pass_proc(wxString str_operator, wxString str_group, wxString str_desc, bool b_log_pass)
{
    v_wf_instance l_instance;
    l_instance = wf_proc_act->get_cur_instance_action();


    if(l_instance.s_action.i_flow_ser == l_instance.s_action.i_total_flow)
    {
        l_instance.is_active = false;
        l_instance.t_finish = wxDateTime::Now();

        wf_proc_act->set_instance(l_instance);
        update_process_status(l_instance, true);

//       if(l_instance.s_action.s_workflow_id == wf_str_review)
//           return update_instance(2);

        if(l_instance.s_action.s_workflow_id == wf_str_review)
            return true;

        if(l_instance.s_action.s_workflow_id == wf_str_configure)
            return update_instance(5);

        if(l_instance.s_action.s_workflow_id == wf_str_nonstd)
            return update_instance_one2several(10);

        if(l_instance.s_action.s_workflow_id == wf_str_design)
            return update_instance_one2several(10);

        if(l_instance.s_action.s_workflow_id == wf_str_materials)
            return update_instance_one2several(10);
    }
    else
    {
        l_instance.is_active = false;
        l_instance.t_finish = wxDateTime::Now();

        wf_proc_act->set_instance(l_instance);

        update_process_status(l_instance, true);
    }

    if(b_log_pass)
    {
        str_desc = l_instance.step_desc;
    }

    wf_proc_act->MoveNext();

    bool b_new = wf_proc_act->Eof();
    if(b_new)
        wf_proc_act->create_step_action(wf_proc_template);

    l_instance = wf_proc_act->get_cur_instance_action();
    l_instance.is_active = true;

    if(!b_new)
    {
        l_instance.t_start=wxDateTime::Now();
        l_instance.t_finish = wxDateTime::Now();
    }

    if(!str_group.IsEmpty())
    {
        l_instance.s_action.s_group_id = str_group;
    }
    if(!str_operator.IsEmpty())
    {
        l_instance.s_action.s_operator_id = str_operator;
    }



    if(!str_desc.IsEmpty())
    {
        if(!b_log_pass)
        {
            wxString str_temp = Get_Desc_id();
            update_desc(str_temp,str_desc,false);
            l_instance.step_desc = str_temp;
        }
        else l_instance.step_desc = str_desc;
    }
    else l_instance.step_desc= wxEmptyString;

    wf_proc_act->set_instance(l_instance);

    return update_process_status(l_instance, !b_new);
}

bool wf_operator::Pass_proc_s(wxString str_operator, wxString str_group, wxString str_desc, bool b_log_pass)
{
    v_wf_instance l_instance;
    l_instance = wf_proc_act->get_cur_instance_action();


    if(l_instance.s_action.i_flow_ser == l_instance.s_action.i_total_flow)
    {
        l_instance.is_active = false;
        l_instance.t_finish = wxDateTime::Now();
        l_instance.s_action.s_operator_id= gr_para.login_user;//非本人完成

        wf_proc_act->set_instance(l_instance);
        update_process_status(l_instance, true);

//        if(l_instance.s_action.s_workflow_id == wf_str_review)
//            return update_instance(2);

        if(l_instance.s_action.s_workflow_id == wf_str_review)
            return true;

        if(l_instance.s_action.s_workflow_id == wf_str_configure)
            return update_instance(5);

        if(l_instance.s_action.s_workflow_id == wf_str_nonstd)
            return update_instance_one2several(10);

        if(l_instance.s_action.s_workflow_id == wf_str_design)
            return update_instance_one2several(10);

        if(l_instance.s_action.s_workflow_id == wf_str_materials)
            return update_instance_one2several(10);
    }
    else
    {
        l_instance.is_active = false;
        l_instance.t_finish = wxDateTime::Now();
        l_instance.s_action.s_operator_id= gr_para.login_user;//非本人完成

        wf_proc_act->set_instance(l_instance);

        update_process_status(l_instance, true);
    }

    if(b_log_pass)
    {
        str_desc = l_instance.step_desc;
    }

    wf_proc_act->MoveNext();

    bool b_new = wf_proc_act->Eof();
    if(b_new)
        wf_proc_act->create_step_action(wf_proc_template);

    l_instance = wf_proc_act->get_cur_instance_action();
    l_instance.is_active = true;

    if(!b_new)
    {
        l_instance.t_start=wxDateTime::Now();
        l_instance.t_finish = wxDateTime::Now();
    }

    if(!str_group.IsEmpty())
    {
        l_instance.s_action.s_group_id = str_group;
    }
    if(!str_operator.IsEmpty())
    {
        l_instance.s_action.s_operator_id = str_operator;
    }



    if(!str_desc.IsEmpty())
    {
        if(!b_log_pass)
        {
            wxString str_temp = Get_Desc_id();
            update_desc(str_temp,str_desc,false);
            l_instance.step_desc = str_temp;
        }
        else l_instance.step_desc = str_desc;
    }
    else l_instance.step_desc= wxEmptyString;

    wf_proc_act->set_instance(l_instance);

    return update_process_status(l_instance, !b_new);
}

bool wf_operator::Pass_proc_g(wxString str_operator, wxString str_group, wxString str_desc, bool b_log_pass)
{
    v_wf_instance l_instance;
    l_instance = wf_proc_act->get_cur_instance_action();

    if(l_instance.s_action.s_action_type == wxT("G") && l_instance.s_action.b_is_assigned)
    {
//        l_instance.s_action.s_group_id = str_group;
        l_instance.s_action.s_operator_id = str_operator;
        l_instance.s_action.s_action_type  = wxT("P");

        wf_proc_act->set_instance(l_instance);
        return update_process_status(l_instance, true);
    }

    if(l_instance.s_action.i_flow_ser == l_instance.s_action.i_total_flow)
    {
        l_instance.is_active = false;
        l_instance.t_finish = wxDateTime::Now();

        wf_proc_act->set_instance(l_instance);
        update_process_status(l_instance, true);

        if(l_instance.s_action.s_workflow_id == wf_str_review)
            return update_instance_one2several(2);

        if(l_instance.s_action.s_workflow_id == wf_str_configure)
            return update_instance(5);
    }

    l_instance.is_active = false;
    l_instance.t_finish = wxDateTime::Now();

    wf_proc_act->set_instance(l_instance);
    update_process_status(l_instance, true);

    if(b_log_pass)
    {
        str_desc = l_instance.step_desc;
    }

    wf_proc_act->MoveNext();

    bool b_new = wf_proc_act->Eof();
    if(b_new)
        wf_proc_act->create_step_action(wf_proc_template);

    l_instance = wf_proc_act->get_cur_instance_action();
    l_instance.is_active = true;

    /*
        if(l_instance.s_action.s_group_id.IsEmpty() || l_instance.s_action.s_group_id.Contains(wxT(";")))
            l_instance.s_action.s_group_id = str_group;
        if(l_instance.s_action.s_operator_id.IsEmpty())
            l_instance.s_action.s_operator_id = str_operator;
    */

    if(!b_new)
    {
        l_instance.t_start=wxDateTime::Now();
        l_instance.t_finish = wxDateTime::Now();
    }

    if(!str_group.IsEmpty())
        l_instance.s_action.s_group_id = str_group;
    if(!str_operator.IsEmpty())
        l_instance.s_action.s_operator_id = str_operator;

    if(!str_desc.IsEmpty())
    {
        if(!b_log_pass)
        {
            wxString str_temp = Get_Desc_id();
            update_desc(str_temp,str_desc,false);
            l_instance.step_desc = str_temp;
        }
        else l_instance.step_desc = str_desc;
    }
    else l_instance.step_desc= wxEmptyString;

    wf_proc_act->set_instance(l_instance);
    return update_process_status(l_instance, !b_new);

}

int wf_operator::check_act_status()
{
    return wf_proc_act->GetCurrentStep();
}

bool wf_operator::update_instance_one2several(int i_status, bool only_wf_status)
{
    v_wf_instance l_instance = wf_proc_act->get_cur_instance_action();
    wxPostgreSQLresult* t_res;
    wxString l_query = wxT("SELECT * FROM l_instance_status where instance_id = '")+l_instance.s_instance_id+wxT("' and workflow_id = '")+
                       l_instance.s_action.s_workflow_id+wxT("';");
    t_res = wxGetApp().app_sql_select(l_query);

    if(t_res->Status()!= PGRES_TUPLES_OK)
    {
        t_res->Clear();
        return false;
    }
    int i_count = t_res->GetRowsNumber();
    bool b_update;

    if(i_count ==0 )
        b_update = false;
    else b_update = true;

    t_res->Clear();

    wxString str_wf_status;
    l_query = wxT("SELECT action_name FROM s_action_info WHERE action_id = '")+l_instance.s_action.s_action_id +wxT("';");
    t_res = wxGetApp().app_sql_select(l_query);

    if(t_res->Status()!= PGRES_TUPLES_OK)
    {
        t_res->Clear();
        return false;
    }

    t_res->MoveFirst();
    str_wf_status = t_res->GetVal(wxT("action_name"));
    t_res->Clear();

    if(!b_update)
        l_query = wxT("INSERT INTO l_instance_status(instance_id, workflow_id, action_id, status, wf_status, modify_date, modify_emp_id, create_date, create_emp_id)\
                  VALUES ('")+l_instance.s_instance_id +wxT("', '")+l_instance.s_action.s_workflow_id+wxT("','")+l_instance.s_action.s_action_id+wxT("','")+
                  NumToStr(i_status)+wxT("','")+str_wf_status+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("');");

    else
    {
        if(only_wf_status)
        {
            l_query = wxT("UPDATE l_instance_status SET  wf_status ='")+str_wf_status+wxT("',action_id ='")+l_instance.s_action.s_action_id+
                      wxT("', modify_date = '")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id = '")+gr_para.login_user+wxT("' WHERE instance_id= '")+l_instance.s_instance_id+wxT("' AND workflow_id = '")+
                      l_instance.s_action.s_workflow_id+wxT("';");
        }
        else
        {
            l_query = wxT("UPDATE l_instance_status SET status ='")+NumToStr(i_status)+wxT("', wf_status ='")+str_wf_status+wxT("',action_id ='")+l_instance.s_action.s_action_id+
                      wxT("', modify_date = '")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id = '")+gr_para.login_user+wxT("' WHERE instance_id= '")+l_instance.s_instance_id+wxT("' AND workflow_id = '")+
                      l_instance.s_action.s_workflow_id+wxT("';");
        }
    }

    return wxGetApp().app_sql_update(l_query);
}

int  wf_operator::get_instance_status(wxString &s_wf_status)
{

    v_wf_instance l_instance = wf_proc_act->get_cur_instance_action();
    wxPostgreSQLresult* t_res;
    wxString l_query = wxT("SELECT * FROM l_instance_status where instance_id = '")+l_instance.s_instance_id+wxT("' and workflow_id = '")+
                       l_instance.s_action.s_workflow_id+wxT("';");
    t_res = wxGetApp().app_sql_select(l_query);

    if(t_res->Status()!= PGRES_TUPLES_OK)
    {
        t_res->Clear();
        return false;
    }
    int i_count = t_res->GetRowsNumber();

    if(i_count == 0)
        return -2;

    t_res->MoveFirst();

    int i_status = t_res->GetInt(wxT("status"));
    s_wf_status = t_res->GetVal(wxT("wf_status"));
    return i_status;
}

bool wf_operator::update_instance(int i_status,int i_choice)
{
    wxPostgreSQLresult* t_res;
    wxString l_query = wxT("SELECT * FROM s_workflow_instance WHERE workflow_id = '")+s_workflow+wxT("';");
    t_res = wxGetApp().app_sql_select(l_query);

    if(t_res->Status()!= PGRES_TUPLES_OK)
    {
        t_res->Clear();
        return false;
    }

    int i_count = t_res->GetRowsNumber();

    wxString str_table, str_table_para;
    if(i_count != 1)
    {
        t_res->Clear();
        return false;
    }
    t_res->MoveFirst();

    str_table = t_res->GetVal(wxT("table_str"));
    str_table_para = t_res->GetVal(wxT("table_para_str"));

    t_res->Clear();

    wxString str_wf_status;

    if(i_choice >=1)
    {
        v_wf_instance l_instance = wf_proc_act->get_cur_instance_action();


        l_query = wxT("SELECT action_name FROM s_action_info WHERE action_id = '")+l_instance.s_action.s_action_id +wxT("';");
        t_res = wxGetApp().app_sql_select(l_query);

        if(t_res->Status()!= PGRES_TUPLES_OK)
        {
            t_res->Clear();
            return false;
        }

        t_res->MoveFirst();
        str_wf_status = t_res->GetVal(wxT("action_name"));
        t_res->Clear();
    }

    if(i_choice == 2)
        l_query = wxT("UPDATE ")+str_table+ wxT(" SET  wf_status ='")+str_wf_status+wxT("', modify_date = '")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id = '")+gr_para.login_user+wxT("' WHERE ")+str_table_para +wxT("= '")+s_instance+wxT("';");
    else if(i_choice == 1)
        l_query = wxT("UPDATE ")+str_table+ wxT(" SET  status = '")+NumToStr(i_status)+wxT("', wf_status ='")+str_wf_status+wxT("', modify_date = '")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id = '")+gr_para.login_user+wxT("' WHERE ")+str_table_para +wxT("= '")+s_instance+wxT("';");
    else if(i_choice == 0)
        l_query = wxT("UPDATE ")+str_table+ wxT(" SET  status = '")+NumToStr(i_status)+wxT("', modify_date = '")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id = '")+gr_para.login_user+wxT("' WHERE ")+str_table_para +wxT("= '")+s_instance+wxT("';");

    return wxGetApp().app_sql_update(l_query);
}

bool wf_operator::update_instance(int i_status, wxString &s_wf_status, int i_choice)
{
    wxPostgreSQLresult* t_res;
    wxString l_query = wxT("SELECT * FROM s_workflow_instance WHERE workflow_id = '")+s_workflow+wxT("';");
    t_res = wxGetApp().app_sql_select(l_query);

    if(t_res->Status()!= PGRES_TUPLES_OK)
    {
        t_res->Clear();
        return false;
    }

    int i_count = t_res->GetRowsNumber();

    wxString str_table, str_table_para;
    if(i_count != 1)
    {
        t_res->Clear();
        return false;
    }
    t_res->MoveFirst();

    str_table = t_res->GetVal(wxT("table_str"));
    str_table_para = t_res->GetVal(wxT("table_para_str"));

    t_res->Clear();

    if(i_choice >=1)
    {


        v_wf_instance l_instance = wf_proc_act->get_cur_instance_action();

        l_query = wxT("SELECT action_name FROM s_action_info WHERE action_id = '")+l_instance.s_action.s_action_id +wxT("';");
        t_res = wxGetApp().app_sql_select(l_query);

        if(t_res->Status()!= PGRES_TUPLES_OK)
        {
            t_res->Clear();
            return false;
        }

        t_res->MoveFirst();
        s_wf_status = t_res->GetVal(wxT("action_name"));
        t_res->Clear();
    }

    if(i_choice == 2)
        l_query = wxT("UPDATE ")+str_table+ wxT(" SET  wf_status ='")+s_wf_status+wxT("', modify_date = '")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id = '")+gr_para.login_user+wxT("' WHERE ")+str_table_para +wxT("= '")+s_instance+wxT("';");
    else if(i_choice == 1)
        l_query = wxT("UPDATE ")+str_table+ wxT(" SET  status = '")+NumToStr(i_status)+wxT("', wf_status ='")+s_wf_status+wxT("', modify_date = '")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id = '")+gr_para.login_user+wxT("' WHERE ")+str_table_para +wxT("= '")+s_instance+wxT("';");
    else if(i_choice == 0)
        l_query = wxT("UPDATE ")+str_table+ wxT(" SET  status = '")+NumToStr(i_status)+wxT("', modify_date = '")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id = '")+gr_para.login_user+wxT("' WHERE ")+str_table_para +wxT("= '")+s_instance+wxT("';");


    return wxGetApp().app_sql_update(l_query);
}

void wf_operator::restore_task(wxString l_act_id)
{
    int i_step = 0;
    if(!l_act_id.IsEmpty())
    {
        i_step = wf_proc_act->FindSteps(l_act_id);
    }

    if(i_step == 0)
    {
        wf_proc_act->MoveFirst();
    }

    v_wf_instance l_instance = wf_proc_act->get_cur_instance_action();
    l_instance.is_active = true;
    l_instance.t_start = wxDateTime::Now();
    l_instance.t_finish = wxDateTime::Now();

    update_process_status(l_instance, true);
}

void wf_operator::restart_instance(wxString l_act_id, int i_times)
{
    restart_log(i_times);

    int i_step = wf_proc_act->FindSteps(l_act_id);

    wf_proc_act->MoveFirst();

    for(int i=0; i<i_step; i++)
    {
        v_wf_instance l_instance = wf_proc_act->get_cur_instance_action();

        if(i==i_step-1)
        {
            l_instance.is_active = true;
        }
        else
            l_instance.is_active = false;

        l_instance.is_restart = true;
        l_instance.t_start = wxDateTime::Now();

        if(i!=i_step-1)
            l_instance.t_finish = wxDateTime::Now();

        update_process_status(l_instance, true);
        wf_proc_act->MoveNext();
    }

    wf_proc_act->MovePrevious();
}

void wf_operator::restart_instance(int i_times)
{
    restart_log(i_times);
    wf_proc_act->MoveFirst();

    v_wf_instance l_instance = wf_proc_act->get_cur_instance_action();


    l_instance.is_active = true;
    l_instance.is_restart = true;
    l_instance.t_start = wxDateTime::Now();
//   l_instance.t_finish =  wxDateTime::Now();

    update_process_status(l_instance, true);
}

void wf_operator::close_instance()
{
    if(wf_proc_act->MoveToActive()<=0)
        return;

    v_wf_instance l_instance = wf_proc_act->get_cur_instance_action();
    l_instance.is_active = false;
    l_instance.t_finish =  wxDateTime::Now();

    update_process_status(l_instance, true);
}

void wf_operator::cancel_task(int i_times)
{
    if(i_times > 0)
        cancel_log(i_times);


    int i_step = wf_proc_act->MoveToActive();//程序自动bug

    if(i_step<=0)
        return;

    v_wf_instance l_instance;
    l_instance = wf_proc_act->get_cur_instance_action();

    l_instance.is_active = false;

    update_process_status(l_instance, true);

}

void wf_operator::cancel_restart(int i_times, wxString s_workflow)
{
    wf_proc_act->MoveFirst();

    v_wf_instance l_instance = wf_proc_act->get_cur_instance_action();

    wxString str_sql = wxT("SELECT * FROM l_restart_log where instance_id = '")+l_instance.s_instance_id+wxT("' AND \
                            workflow_id = '")+s_workflow+wxT("' AND restart_times = '")+NumToStr(i_times+1)+wxT("' order by flow_ser ASC;");
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        return;
    }

    _res->MoveFirst();

    bool b_loop = true;
    do
    {

        if(l_instance.is_active)
            b_loop = false;

        l_instance.is_active = false;
        l_instance.is_restart = false;
        l_instance.t_start = _res->GetDateTime(wxT("start_date"));
        l_instance.t_finish = _res->GetDateTime(wxT("finish_date"));
        l_instance.s_action.s_operator_id = _res->GetVal(wxT("operator_id"));
        l_instance.s_action.s_group_id = _res->GetVal(wxT("group_id"));

        update_process_status(l_instance, true);

        _res->MoveNext();

        wf_proc_act->MoveNext();
        l_instance = wf_proc_act->get_cur_instance_action();

    }
    while(b_loop);

    _res->Clear();

    str_sql = wxT("DELETE FROM l_restart_log WHERE instance_id = '")+l_instance.s_instance_id+wxT("' AND \
                    workflow_id = 'WF0002' AND restart_times = '")+NumToStr(i_times+1)+wxT("';");

    wxGetApp().app_sql_update(str_sql);

}


wxString wf_operator::Get_Desc_id()
{
    return wxGetApp().get_ser_no(wxT("s_doc"),wxT("doc_id"));
}

bool wf_operator::update_desc(wxString str_id, wxString str_desc, bool b_update)
{
    return wxGetApp().update_desc(str_id, str_desc, b_update);
}

void wf_operator::start_proc(wxString str_desc, bool start_sec, bool b_log_pass)//start_sec表示启动后激活第二步操作。
{
    if(wf_proc_act->GetCurrentStep()!=0)
        return;

    wf_proc_act->create_step_action(wf_proc_template);
    v_wf_instance l_instance;
    wxString str_group, str_operator;
    l_instance = wf_proc_act->get_cur_instance_action();
    if(start_sec)
    {
        l_instance.is_active = false;
        l_instance.t_finish = wxDateTime::Now();
        l_instance.s_action.s_operator_id = gr_para.login_user;
        if(l_instance.s_action.s_group_id.IsEmpty()|| l_instance.s_action.s_group_id.Contains(wxT(";")) )
            l_instance.s_action.s_group_id = wxGetApp().get_only_group();

        str_group = l_instance.s_action.s_group_id;
    }
    else
    {
        if(!str_desc.IsEmpty())
        {
            if(!b_log_pass)
            {
                wxString str_temp = Get_Desc_id();
                update_desc(str_temp,str_desc,false);
                l_instance.step_desc = str_temp;
            }
            else l_instance.step_desc = str_desc;
        }
        else l_instance.step_desc= wxEmptyString;
    }
    update_process_status(l_instance, false);

    if(start_sec)
    {
        wf_proc_act->create_step_action(wf_proc_template);
        l_instance = wf_proc_act->get_cur_instance_action();
        if(!str_desc.IsEmpty())
        {
            if(!b_log_pass)
            {
                wxString str_temp = Get_Desc_id();
                update_desc(str_temp,str_desc,false);
                l_instance.step_desc = str_temp;
            }
            else l_instance.step_desc = str_desc;
        }
        else l_instance.step_desc= wxEmptyString;

        if(l_instance.s_action.s_action_type == wxT("G") && l_instance.s_action.b_is_assigned)
        {
            str_operator = wxGetApp().get_leader(l_instance.s_action.s_group_id);

            l_instance.s_action.s_operator_id = str_operator;
            l_instance.is_active = true;

        }

        if(l_instance.s_action.s_action_type == wxT("G") && !l_instance.s_action.b_is_assigned)
        {
            str_operator = wxGetApp().get_leader(str_group);
            l_instance.s_action.s_operator_id = str_operator;
            l_instance.is_active = true;
            l_instance.s_action.s_group_id = str_group;

        }
        /*
                if(l_instance.s_action.s_action_type == wxT("P") && l_instance.s_action.b_is_assigned)
                {
                    wxArrayString str_group_list;
                    if(str_group.Contains(wxT(";")) || str_group.IsEmpty())
                    {
                        str_group =  wxGetApp().get_only_group();

                    }

                    str_group_list.Add(str_group);
                    wxArrayString  s_members = wxGetApp().get_member_in_group(str_group_list);

                    wxSingleChoiceDialog cdlg(this, _("请选择操作人员:"),_("操作选择"),s_members);


                    if(cdlg.ShowModal() == wxID_OK)
                    {
                        //                   b_first = false;
                    }
                    else
                    {
                        return;
                        //                 b_first = true;
                    }

                    str_operator = cdlg.GetStringSelection();

                    int i_pos = str_operator.Find('-');

                    str_operator = str_operator.Left(i_pos);


                    l_instance.s_action.s_operator_id = str_operator;
                    l_instance.is_active = true;
                    l_instance.s_action.s_group_id = str_group;

                }*/
        update_process_status(l_instance, false);
    }
}

bool wf_operator::delete_process() // when process is just created, status is not created.
{
    wf_proc_act->MoveFirst();
    if(wf_proc_act->GetCurrentStep() == 0)
        return true;


    v_wf_instance l_instance = wf_proc_act->get_cur_instance_action();

    wxString str_sql = wxT("DELETE FROM l_proc_act WHERE instance_id='")+l_instance.s_instance_id+wxT("' AND workflow_id ='")+l_instance.s_action.s_workflow_id+wxT("';");

    return wxGetApp().app_sql_update(str_sql);
}


bool wf_operator::update_process_status(v_wf_instance l_instance, bool b_update)
{
    wxString str_query;

    if(b_update)
    {
        str_query= wxT("UPDATE l_proc_act SET operator_id='")+l_instance.s_action.s_operator_id+
                   wxT("', group_id='")+l_instance.s_action.s_group_id+wxT("', action_type ='")+l_instance.s_action.s_action_type+wxT("', start_date='")+DateToAnsiStr(l_instance.t_start)+
                   wxT("', finish_date='")+DateToAnsiStr(l_instance.t_finish)+wxT("', is_active='")+BoolToStr(l_instance.is_active)+
                   wxT("', is_return='")+BoolToStr(l_instance.is_return)+wxT("', return_time='")+NumToStr(l_instance.return_times)+wxT("', is_restart='")+BoolToStr(l_instance.is_restart)+
                   wxT("', step_desc_id='")+l_instance.step_desc+wxT("',modify_date = '")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id = '")+gr_para.login_user+wxT("' WHERE instance_id='")+s_instance+wxT("' AND workflow_id ='")+s_workflow+
                   wxT("' AND action_id = '")+l_instance.s_action.s_action_id+wxT("';");
    }
    else
    {
        str_query = wxT("INSERT INTO l_proc_act(instance_id, workflow_id, action_id, flow_ser, total_flow, \
            pre_action_id, follow_action_id, is_transit, allow_return, action_lead, urgent_lead, action_lead_unit, operator_id, group_id, is_assigned, \
            action_type, group_catalog, start_date, finish_date, is_active, is_return, return_time, is_restart, step_desc_id, modify_date, modify_emp_id, create_date, create_emp_id,is_evaluate,is_need_eval, is_checked) \
            VALUES ('")+s_instance+wxT("','")+s_workflow+wxT("','")+ l_instance.s_action.s_action_id+wxT("','")+NumToStr(l_instance.s_action.i_flow_ser)+wxT("','")+NumToStr(l_instance.s_action.i_total_flow)+
                    wxT("','")+l_instance.s_action.s_pre_action_id+wxT("','")+l_instance.s_action.s_follow_action_id+wxT("','")+
                    BoolToStr(l_instance.s_action.b_is_transit)+wxT("','")+BoolToStr(l_instance.s_action.b_allow_return)+wxT("','")+
                    NumToStr(l_instance.s_action.i_action_lead)+wxT("','")+NumToStr(l_instance.s_action.i_urgent_lead)+wxT("','")+
                    l_instance.s_action.s_action_lead_unit+wxT("','")+l_instance.s_action.s_operator_id+wxT("','")+l_instance.s_action.s_group_id+wxT("','")+
                    BoolToStr(l_instance.s_action.b_is_assigned)+wxT("','")+l_instance.s_action.s_action_type+wxT("','")+l_instance.s_action.s_group_catalog+wxT("','")+
                    DateToAnsiStr(l_instance.t_start)+wxT("','")+DateToAnsiStr(l_instance.t_finish)+wxT("','")+
                    BoolToStr(l_instance.is_active)+wxT("','")+BoolToStr(l_instance.is_return)+wxT("','")+NumToStr(l_instance.return_times)+wxT("','")+BoolToStr(l_instance.is_restart)+wxT("','")+
                    l_instance.step_desc+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+
                    gr_para.login_user+wxT("','")+ BoolToStr(l_instance.s_action.b_is_evaluate)+wxT("','")+BoolToStr(l_instance.s_action.b_is_need_eval)+wxT("','")+BoolToStr(l_instance.s_action.b_is_check)+wxT("');");
    }
    str_query.Replace(wxT("''"),wxT("NULL"));

    return wxGetApp().app_sql_update(str_query);
}

void wf_operator::return_log(wxString s_from, wxString s_to, int i_times, wxDateTime t_from, wxDateTime t_to, wxString p_from, wxString p_to, wxString str_desc)
{
    wxString l_query;
//    v_wf_instance l_instance = wf_proc_act->get_cur_instance_action();
    l_query = wxT("INSERT INTO l_return_log (instance_id, from_action, to_action, from_start_date, to_finish_date, return_date, return_time_log, rep_doc_id,from_person, to_person)\
    VALUES ('")+s_instance+wxT("','")+s_from +wxT("','")+s_to + wxT("','")+ DateToAnsiStr(t_from)+wxT("','")+DateToAnsiStr(t_to)+
              wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+NumToStr(i_times)+wxT("','")+str_desc+wxT("','")+p_from+wxT("','")+p_to+wxT("');");
    l_query.Replace(wxT("''"),wxT("NULL"));

    wxGetApp().app_sql_update(l_query);
}

void wf_operator::restart_log(int i_times)
{
    int i_count = wf_proc_act->GetTotalSteps();
    v_wf_instance l_instance;
    wxString l_query;

    wf_proc_act->MoveFirst();
    l_query = wxT("INSERT INTO l_restart_log (instance_id, workflow_id, action_id, flow_ser, \
            total_flow, start_date, finish_date, group_id, operator_id, res_desc_id, restart_times) VALUES ");
    for(int i = 0; i<i_count; i++)
    {
        l_instance = wf_proc_act->get_cur_instance_action();
        l_query = l_query +wxT("('")+s_instance+wxT("','")+
                  s_workflow+wxT("','")+l_instance.s_action.s_action_id+wxT("','")+NumToStr(l_instance.s_action.i_flow_ser)+
                  wxT("','")+NumToStr(l_instance.s_action.i_total_flow)+wxT("','")+
                  DateToAnsiStr(l_instance.t_start)+wxT("','")+DateToAnsiStr(l_instance.t_finish)+
                  wxT("','")+l_instance.s_action.s_group_id+wxT("','")+
                  l_instance.s_action.s_operator_id+wxT("','")+l_instance.step_desc+ wxT("','")+NumToStr(i_times)+
                  wxT("'),");

        if(l_instance.is_active==true)
            break;

        wf_proc_act->MoveNext();
    }

    l_query.Replace(wxT("''"),wxT("NULL"));
    l_query.RemoveLast();
    l_query = l_query+wxT(";");
//   wxLogMessage(l_query);

    wxGetApp().app_sql_select(l_query);
}

void wf_operator::cancel_log(int i_times)
{
    int i_count = wf_proc_act->GetTotalSteps();

    if(i_count==0)
        return;

    v_wf_instance l_instance;
    wxString l_query;

    wf_proc_act->MoveFirst();
    l_query = wxT("INSERT INTO l_cancel_log (instance_id, workflow_id, action_id, flow_ser, \
            total_flow, start_date, finish_date, group_id, operator_id, res_desc_id, cancel_times) VALUES ");
    for(int i = 0; i<i_count; i++)
    {
        l_instance = wf_proc_act->get_cur_instance_action();
        l_query = l_query +wxT("('")+s_instance+wxT("','")+
                  s_workflow+wxT("','")+l_instance.s_action.s_action_id+wxT("','")+NumToStr(l_instance.s_action.i_flow_ser)+
                  wxT("','")+NumToStr(l_instance.s_action.i_total_flow)+wxT("','")+
                  DateToAnsiStr(l_instance.t_start)+wxT("','")+DateToAnsiStr(l_instance.t_finish)+
                  wxT("','")+l_instance.s_action.s_group_id+wxT("','")+
                  l_instance.s_action.s_operator_id+wxT("','")+l_instance.step_desc+ wxT("','")+NumToStr(i_times)+
                  wxT("'),");
        wf_proc_act->MoveNext();
    }

    l_query.Replace(wxT("''"),wxT("NULL"));
    l_query.RemoveLast();
    l_query = l_query+wxT(";");
//   wxLogMessage(l_query);
    wxGetApp().app_sql_select(l_query);
}


wxString wf_operator::get_action_id()
{
    return wf_proc_act->get_cur_instance_action().s_action.s_action_id;
}

v_wf_instance wf_operator::get_instance()
{
    return wf_proc_act->get_cur_instance_action();
}

bool wf_operator::update_header_status(int i_status, wxString key_value, wxString key_name, wxString s_table)
{
    wxString str_sql = wxT("UPDATE ") + s_table +wxT(" SET status= '")+NumToStr(i_status)+wxT("', modify_emp_id='")+
                       gr_para.login_user+wxT("', modify_date ='")+ DateToAnsiStr(wxDateTime::Now())+ wxT("' where ")+key_name+wxT(" = '")+key_value+wxT("';");
    return wxGetApp().app_sql_update(str_sql);
}

int get_instance_status(wxString s_instance,wxString s_workflow,wxString &s_action_id,wxString &s_wf_status)
{
    wxString str_sql = wxT("SELECT * FROM l_instance_status WHERE instance_id = '")+ s_instance+wxT("' and workflow_id = '")+s_workflow+wxT("';");
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return -2;
    }

    if(_res->GetRowsNumber() == 0)
    {
        _res->Clear();
        s_wf_status.Empty();
        return -2;
    }

    int i_status = _res->GetInt(wxT("status"));

    s_wf_status = _res->GetVal(wxT("wf_status"));

    s_action_id = _res->GetVal(wxT("action_id"));

    _res->Clear();

    return i_status;
}

bool is_workflow_created(wxString s_instance, wxString s_workflow, int &i_step)
{

    wxString str_sql = wxT("SELECT count(*) as count FROM l_proc_act WHERE instance_id = '")+ s_instance+wxT("' and workflow_id = '")+s_workflow+wxT("';");
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        i_step = 0;
        _res->Clear();
        return false;
    }

    _res->MoveFirst();

    i_step = _res->GetInt(wxT("count"));

    if(i_step==0)
        return false;
    else return true;


}

bool delete_all_process(wxString s_instance_id, wxString s_workflow)
{

    wxString str_sql = wxT("DELETE FROM l_proc_act WHERE instance_id='")+s_instance_id+wxT("' AND workflow_id ='")+s_workflow+wxT("';");

    return wxGetApp().app_sql_update(str_sql);
}

bool delete_status(wxString s_instance_id, wxString s_workflow)
{
    wxString str_sql = wxT("DELETE FROM l_instance_status WHERE instance_id='")+s_instance_id+wxT("' AND workflow_id ='")+s_workflow+wxT("';");
    return wxGetApp().app_sql_update(str_sql);
}
////-1报错，0-无工作流，1-有且激活状态，2-有,但完成关闭，3-有，但未完成就关闭了。
int check_is_start_flow(wxString s_instance, wxString s_workflow_id)
{
    wxString str_sql = wxT("select instance_id, workflow_id, action_id, flow_ser, total_flow, is_active  from l_proc_act where instance_id='")+s_instance+ wxT("' and workflow_id=\
                        '")+s_workflow_id+wxT("' order by flow_ser DESC;");

    wxPostgreSQLresult * _res =  wxGetApp().app_sql_select(str_sql);

    if (_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return -1;
    }

    bool b_active;

    int i_count = _res->GetRowsNumber();

    if(i_count ==0)
    {
        _res->Clear();
        return 0;
    }

    _res->MoveFirst();

    int i_total = _res->GetInt(wxT("total_flow"));

    for(int i=0; i<i_count; i++)
    {
        b_active = _res->GetBool(wxT("is_active"));

        if(b_active)
        {
            _res->Clear();
            return 1;
        }
    }

    _res->Clear();

    if(!b_active)
    {
        if(i_total<=i_count)
            return 2;
        else if(i_total > i_count)
            return 3;

    }

    return 0;

}

wxString get_operator_name(wxString str)
{
    wxString s_sql = wxT("SELECT name from s_employee where employee_id ='")+str+wxT("';");
    wxPostgreSQLresult* _res = wxGetApp().app_sql_select(s_sql);
    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return wxEmptyString;
    }

    int i_rows = _res->GetRowsNumber();

    wxString s_result=wxEmptyString;

    if(i_rows>0)
    {
        s_result = _res->GetVal(wxT("name"));
    }

    _res->Clear();

    return s_result;

}



wf_operator_ex::wf_operator_ex(const wxString &_instance, const wxString &_workflow,  v_wf_action* _template, wxString _flag)
{
    s_flag = _flag;
    if(_flag.IsEmpty())
    {
        wxLogMessage(_("电气/机械标志不允许为空"));
        return;
    }
    s_instance = _instance;
    wf_proc_template = _template;
    s_workflow = _workflow;

    wf_proc_act = new wf_process(s_workflow, s_instance, s_flag);
}

bool wf_operator_ex::Pass_proc(wxString str_operator, wxString str_group, wxString str_desc, bool b_log_pass, wxString _flag, bool b_active)
{
    v_wf_instance l_instance;
    l_instance = wf_proc_act->get_cur_instance_action();

    int now_flow_ser,next_flow_ser;

    now_flow_ser = l_instance.s_action.i_flow_ser;

    if(l_instance.s_action.is_end)
    {
        l_instance.is_active = false;
        l_instance.t_finish = wxDateTime::Now();

        wf_proc_act->set_instance(l_instance);
        update_process_status(l_instance, true);



        if(l_instance.s_action.s_workflow_id == wf_str_configure|| l_instance.s_action.s_workflow_id== wf_str_new_config)
            return update_instance(5);

    }
    else
    {
        l_instance.is_active = false;
        l_instance.t_finish = wxDateTime::Now();

        wf_proc_act->set_instance(l_instance);

        update_process_status(l_instance, true);
    }

    if(b_log_pass)
    {
        str_desc = l_instance.step_desc;
    }

    wf_proc_act->MoveNext();

    bool b_new=wf_proc_act->Eof();

    if(!b_new)
    {
         l_instance = wf_proc_act->get_cur_instance_action();
         next_flow_ser = l_instance.s_action.i_flow_ser;

         if(next_flow_ser != now_flow_ser+1)
         {
             b_new = true;
             wf_proc_act->create_step_action(wf_proc_template, now_flow_ser);
         }

    }else
        wf_proc_act->create_step_action(wf_proc_template);

    l_instance = wf_proc_act->get_cur_instance_action();

    l_instance.is_active = b_active;

    if(!b_new)
    {
        l_instance.t_start=wxDateTime::Now();
        l_instance.t_finish = wxDateTime::Now();
    }

    if(_flag.IsEmpty())
        l_instance.s_flag = s_flag;
    else
    {
        if(!l_instance.s_flag.Contains("+"))
             l_instance.s_flag = _flag;
    }


    if(!str_group.IsEmpty())
    {
        l_instance.s_action.s_group_id = str_group;
    }
    if(!str_operator.IsEmpty())
    {
        l_instance.s_action.s_operator_id = str_operator;
    }



    if(!str_desc.IsEmpty())
    {
        if(!b_log_pass)
        {
            wxString str_temp = Get_Desc_id();
            update_desc(str_temp,str_desc,false);
            l_instance.step_desc = str_temp;
        }
        else l_instance.step_desc = str_desc;
    }
    else l_instance.step_desc= wxEmptyString;

    wf_proc_act->set_instance(l_instance);

    return update_process_status(l_instance, !b_new);
}


int  wf_operator_ex::get_instance_status(wxString &s_wf_status)
{

    v_wf_instance l_instance = wf_proc_act->get_cur_instance_action();
    wxPostgreSQLresult* t_res;
    wxString l_query = wxT("SELECT * FROM l_instance_status where instance_id = '")+l_instance.s_instance_id+wxT("' and workflow_id = '")+
                       l_instance.s_action.s_workflow_id+wxT("';");
    t_res = wxGetApp().app_sql_select(l_query);

    if(t_res->Status()!= PGRES_TUPLES_OK)
    {
        t_res->Clear();
        return false;
    }
    int i_count = t_res->GetRowsNumber();

    if(i_count == 0)
        return -2;

    t_res->MoveFirst();

    int i_status = t_res->GetInt(wxT("status"));
    s_wf_status = t_res->GetVal(wxT("wf_status"));
    return i_status;
}


bool wf_operator_ex::update_instance(int i_status,int i_choice)
{
    wxPostgreSQLresult* t_res;
    wxString l_query = wxT("SELECT * FROM s_workflow_instance WHERE workflow_id = '")+s_workflow+wxT("';");
    t_res = wxGetApp().app_sql_select(l_query);

    if(t_res->Status()!= PGRES_TUPLES_OK)
    {
        t_res->Clear();
        return false;
    }

    int i_count = t_res->GetRowsNumber();

    wxString str_table, str_table_para;
    if(i_count != 1)
    {
        t_res->Clear();
        return false;
    }
    t_res->MoveFirst();

    str_table = t_res->GetVal(wxT("table_str"));
    str_table_para = t_res->GetVal(wxT("table_para_str"));

    t_res->Clear();

    wxString str_wf_status;

    if(i_choice >=1)
    {
        v_wf_instance l_instance = wf_proc_act->get_cur_instance_action();


        l_query = wxT("SELECT action_name FROM s_action_info WHERE action_id = '")+l_instance.s_action.s_action_id +wxT("';");
        t_res = wxGetApp().app_sql_select(l_query);

        if(t_res->Status()!= PGRES_TUPLES_OK)
        {
            t_res->Clear();
            return false;
        }

        t_res->MoveFirst();
        str_wf_status = t_res->GetVal(wxT("action_name"));
        t_res->Clear();
    }

    if(i_choice == 2)
        l_query = wxT("UPDATE ")+str_table+ wxT(" SET  wf_status ='")+str_wf_status+wxT("', modify_date = '")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id = '")+gr_para.login_user+wxT("' WHERE ")+str_table_para +wxT("= '")+s_instance+wxT("';");
    else if(i_choice == 1)
        l_query = wxT("UPDATE ")+str_table+ wxT(" SET  status = '")+NumToStr(i_status)+wxT("', wf_status ='")+str_wf_status+wxT("', modify_date = '")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id = '")+gr_para.login_user+wxT("' WHERE ")+str_table_para +wxT("= '")+s_instance+wxT("';");
    else if(i_choice == 0)
        l_query = wxT("UPDATE ")+str_table+ wxT(" SET  status = '")+NumToStr(i_status)+wxT("', modify_date = '")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id = '")+gr_para.login_user+wxT("' WHERE ")+str_table_para +wxT("= '")+s_instance+wxT("';");


    return wxGetApp().app_sql_update(l_query);
}

bool wf_operator_ex::update_instance(int i_status, wxString &s_wf_status, int i_choice)
{
    wxPostgreSQLresult* t_res;
    wxString l_query = wxT("SELECT * FROM s_workflow_instance WHERE workflow_id = '")+s_workflow+wxT("';");
    t_res = wxGetApp().app_sql_select(l_query);

    if(t_res->Status()!= PGRES_TUPLES_OK)
    {
        t_res->Clear();
        return false;
    }

    int i_count = t_res->GetRowsNumber();

    wxString str_table, str_table_para;
    if(i_count != 1)
    {
        t_res->Clear();
        return false;
    }
    t_res->MoveFirst();

    str_table = t_res->GetVal(wxT("table_str"));
    str_table_para = t_res->GetVal(wxT("table_para_str"));

    t_res->Clear();

    if(i_choice >=1)
    {


        v_wf_instance l_instance = wf_proc_act->get_cur_instance_action();

        l_query = wxT("SELECT action_name FROM s_action_info WHERE action_id = '")+l_instance.s_action.s_action_id +wxT("';");
        t_res = wxGetApp().app_sql_select(l_query);

        if(t_res->Status()!= PGRES_TUPLES_OK)
        {
            t_res->Clear();
            return false;
        }

        t_res->MoveFirst();
        s_wf_status = t_res->GetVal(wxT("action_name"));
        t_res->Clear();
    }

    if(i_choice == 2)
        l_query = wxT("UPDATE ")+str_table+ wxT(" SET  wf_status ='")+s_wf_status+wxT("', modify_date = '")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id = '")+gr_para.login_user+wxT("' WHERE ")+str_table_para +wxT("= '")+s_instance+wxT("';");
    else if(i_choice == 1)
        l_query = wxT("UPDATE ")+str_table+ wxT(" SET  status = '")+NumToStr(i_status)+wxT("', wf_status ='")+s_wf_status+wxT("', modify_date = '")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id = '")+gr_para.login_user+wxT("' WHERE ")+str_table_para +wxT("= '")+s_instance+wxT("';");
    else if(i_choice == 0)
        l_query = wxT("UPDATE ")+str_table+ wxT(" SET  status = '")+NumToStr(i_status)+wxT("', modify_date = '")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id = '")+gr_para.login_user+wxT("' WHERE ")+str_table_para +wxT("= '")+s_instance+wxT("';");


    return wxGetApp().app_sql_update(l_query);
}

void wf_operator_ex::restore_task(wxString l_act_id)
{
    int i_step = 0;
    if(!l_act_id.IsEmpty())
    {
        i_step = wf_proc_act->FindSteps(l_act_id);
    }

    if(i_step == 0)
    {
        wf_proc_act->MoveFirst();
    }

    v_wf_instance l_instance = wf_proc_act->get_cur_instance_action();
    l_instance.is_active = true;
    l_instance.t_start = wxDateTime::Now();
    l_instance.t_finish = wxDateTime::Now();

    update_process_status(l_instance, true);
}


void wf_operator_ex::restart_instance(int i_times)
{
    restart_log(i_times);
    wf_proc_act->MoveFirst();

    v_wf_instance l_instance = wf_proc_act->get_cur_instance_action();


    l_instance.is_active = true;
    l_instance.is_restart = true;
    l_instance.t_start = wxDateTime::Now();
//   l_instance.t_finish =  wxDateTime::Now();

    update_process_status(l_instance, true);
}

void wf_operator_ex::close_instance()
{
 //   if(wf_proc_act->MoveToActive()<=0)
  //      return;
    while(wf_proc_act->MoveToActive()>0)
    {
        v_wf_instance l_instance = wf_proc_act->get_cur_instance_action();
        l_instance.is_active = false;
        l_instance.t_finish =  wxDateTime::Now();

        update_process_status(l_instance, true);
    }
}

void wf_operator_ex::cancel_task(int i_times)
{
    if(i_times > 0)
        cancel_log(i_times);

    int i_step = wf_proc_act->MoveToActive();
    v_wf_instance l_instance;

    if(i_step > 0)
    {
        l_instance = wf_proc_act->get_cur_instance_action();
        l_instance.is_active = false;

        update_process_status(l_instance, true);
    }

}

void wf_operator_ex::cancel_restart(int i_times, wxString s_workflow)
{
    wf_proc_act->MoveFirst();

    v_wf_instance l_instance = wf_proc_act->get_cur_instance_action();

    wxString str_sql = wxT("SELECT * FROM l_restart_log where instance_id = '")+l_instance.s_instance_id+wxT("' AND \
                            workflow_id = '")+s_workflow+wxT("' AND restart_times = '")+NumToStr(i_times+1)+wxT("' and flag like '%")+s_flag+wxT("%' order by flow_ser ASC;");
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        return;
    }

    _res->MoveFirst();

    bool b_loop = true;
    do
    {

        if(l_instance.is_active)
            b_loop = false;

        l_instance.is_active = false;
        l_instance.is_restart = false;
        l_instance.t_start = _res->GetDateTime(wxT("start_date"));
        l_instance.t_finish = _res->GetDateTime(wxT("finish_date"));
        l_instance.s_action.s_operator_id = _res->GetVal(wxT("operator_id"));
        l_instance.s_action.s_group_id = _res->GetVal(wxT("group_id"));
        l_instance.s_flag = _res->GetVal(wxT("flag"));

        update_process_status(l_instance, true);

        _res->MoveNext();

        wf_proc_act->MoveNext();
        l_instance = wf_proc_act->get_cur_instance_action();

    }
    while(b_loop);

    _res->Clear();

    str_sql = wxT("DELETE FROM l_restart_log WHERE instance_id = '")+l_instance.s_instance_id+wxT("' AND \
                    workflow_id = '")+s_workflow+wxT("' AND restart_times = '")+NumToStr(i_times+1)+wxT("';");

    wxGetApp().app_sql_update(str_sql);

}


wxString wf_operator_ex::Get_Desc_id()
{
    return wxGetApp().get_ser_no(wxT("s_doc"),wxT("doc_id"));
}

bool wf_operator_ex::update_desc(wxString str_id, wxString str_desc, bool b_update)
{
    return wxGetApp().update_desc(str_id, str_desc, b_update);
}

void wf_operator_ex::start_proc(wxString s_group, wxString str_desc, bool b_log_pass)
{
    if(wf_proc_act->GetCurrentStep()!=0)
        return;

    wf_proc_act->create_step_action(wf_proc_template);
    v_wf_instance l_instance;

    l_instance = wf_proc_act->get_cur_instance_action();

    l_instance.is_active = true;
    l_instance.s_action.s_group_id = s_group;
    wxString s_operator;
    int i_count;
    wxArrayString a_operator = wxGetApp().get_role_member(i_count, l_instance.s_action.s_role_id, s_group);

    if(i_count >1)
    {
        wxSingleChoiceDialog cdlg(NULL, _("请选择操作人员:"),_("操作选择"),a_operator);

        if(cdlg.ShowModal() == wxID_OK)
        {
            //                   b_first = false;
        }
        else
        {
            return;
            //                 b_first = true;
        }

        s_operator = cdlg.GetStringSelection().Left(8);
    }
    else if(i_count==1)
    {
        s_operator = a_operator.Item(0).Left(8);
    }
    else
        return;


    l_instance.s_action.s_operator_id = s_operator;
    l_instance.s_flag = s_flag;


    if(!str_desc.IsEmpty())
    {
        if(!b_log_pass)
        {
            wxString str_temp = Get_Desc_id();
            update_desc(str_temp,str_desc,false);
            l_instance.step_desc = str_temp;
        }
        else l_instance.step_desc = str_desc;
    }
    else l_instance.step_desc= wxEmptyString;

    update_process_status(l_instance, false);

}

bool wf_operator_ex::delete_process() // when process is just created, status is not created.
{
    wf_proc_act->MoveFirst();
    if(wf_proc_act->GetCurrentStep() == 0)
        return true;


    v_wf_instance l_instance = wf_proc_act->get_cur_instance_action();

    wxString str_sql = wxT("DELETE FROM l_proc_act WHERE instance_id='")+l_instance.s_instance_id+wxT("' AND workflow_id ='")+l_instance.s_action.s_workflow_id+wxT("';");

    return wxGetApp().app_sql_update(str_sql);
}


bool wf_operator_ex::update_process_status(v_wf_instance l_instance, bool b_update)
{
    wxString str_query;

    if(b_update)
    {
        str_query= wxT("UPDATE l_proc_act SET operator_id='")+l_instance.s_action.s_operator_id+
                   wxT("', group_id='")+l_instance.s_action.s_group_id+wxT("', action_type ='")+l_instance.s_action.s_action_type+wxT("', start_date='")+DateToAnsiStr(l_instance.t_start)+
                   wxT("', finish_date='")+DateToAnsiStr(l_instance.t_finish)+wxT("', is_active='")+BoolToStr(l_instance.is_active)+
                   wxT("', is_return='")+BoolToStr(l_instance.is_return)+wxT("', return_time='")+NumToStr(l_instance.return_times)+wxT("', is_restart='")+BoolToStr(l_instance.is_restart)+
                   wxT("', step_desc_id='")+l_instance.step_desc+wxT("',modify_date = '")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id = '")+gr_para.login_user+wxT("',flag = '")+l_instance.s_flag +wxT("' WHERE instance_id='")+s_instance+wxT("' AND workflow_id ='")+s_workflow+
                   wxT("' AND action_id = '")+l_instance.s_action.s_action_id+wxT("' and flag like '%")+l_instance.s_flag+wxT("%';");
    }
    else
    {
        str_query = wxT("INSERT INTO l_proc_act(instance_id, workflow_id, action_id, flow_ser, total_flow, \
            pre_action_id, follow_action_id, is_transit, allow_return, action_lead, urgent_lead, action_lead_unit, operator_id, group_id, is_assigned, \
            action_type, group_catalog, start_date, finish_date, is_active, is_return, return_time, is_restart, step_desc_id, modify_date, modify_emp_id, create_date, create_emp_id,is_evaluate,is_need_eval, is_checked, join_mode, split_mode,role_id,flag,is_start,is_end) \
            VALUES ('")+s_instance+wxT("','")+s_workflow+wxT("','")+ l_instance.s_action.s_action_id+wxT("','")+NumToStr(l_instance.s_action.i_flow_ser)+wxT("','")+NumToStr(l_instance.s_action.i_total_flow)+
                    wxT("','")+l_instance.s_action.s_pre_action_id+wxT("','")+l_instance.s_action.s_follow_action_id+wxT("','")+
                    BoolToStr(l_instance.s_action.b_is_transit)+wxT("','")+BoolToStr(l_instance.s_action.b_allow_return)+wxT("','")+
                    NumToStr(l_instance.s_action.i_action_lead)+wxT("','")+NumToStr(l_instance.s_action.i_urgent_lead)+wxT("','")+
                    l_instance.s_action.s_action_lead_unit+wxT("','")+l_instance.s_action.s_operator_id+wxT("','")+l_instance.s_action.s_group_id+wxT("','")+
                    BoolToStr(l_instance.s_action.b_is_assigned)+wxT("','")+l_instance.s_action.s_action_type+wxT("','")+l_instance.s_action.s_group_catalog+wxT("','")+
                    DateToAnsiStr(l_instance.t_start)+wxT("','")+DateToAnsiStr(l_instance.t_finish)+wxT("','")+
                    BoolToStr(l_instance.is_active)+wxT("','")+BoolToStr(l_instance.is_return)+wxT("','")+NumToStr(l_instance.return_times)+wxT("','")+BoolToStr(l_instance.is_restart)+wxT("','")+
                    l_instance.step_desc+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+
                    gr_para.login_user+wxT("','")+ BoolToStr(l_instance.s_action.b_is_evaluate)+wxT("','")+BoolToStr(l_instance.s_action.b_is_need_eval)+wxT("','")+BoolToStr(l_instance.s_action.b_is_check)+wxT("','")+NumToStr(l_instance.s_action.i_join_mode)+
                    wxT("','")+NumToStr(l_instance.s_action.i_split_mode)+wxT("','")+l_instance.s_action.s_role_id+wxT("','")+l_instance.s_flag+wxT("',")+BoolToStr(l_instance.s_action.is_start)+wxT(",")+BoolToStr(l_instance.s_action.is_end)+(");");
    }
    str_query.Replace(wxT("''"),wxT("NULL"));

    return wxGetApp().app_sql_update(str_query);
}

void wf_operator_ex::return_log(wxString s_from, wxString s_to, int i_times, wxDateTime t_from, wxDateTime t_to, wxString p_from, wxString p_to, wxString str_desc)
{
    wxString l_query;
//    v_wf_instance l_instance = wf_proc_act->get_cur_instance_action();
    l_query = wxT("INSERT INTO l_return_log (instance_id, from_action, to_action, from_start_date, to_finish_date, return_date, return_time_log, rep_doc_id,from_person, to_person)\
    VALUES ('")+s_instance+wxT("','")+s_from +wxT("','")+s_to + wxT("','")+ DateToAnsiStr(t_from)+wxT("','")+DateToAnsiStr(t_to)+
              wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+NumToStr(i_times)+wxT("','")+str_desc+wxT("','")+p_from+wxT("','")+p_to+wxT("');");
    l_query.Replace(wxT("''"),wxT("NULL"));

    wxGetApp().app_sql_update(l_query);
}

void wf_operator_ex::restart_log(int i_times)
{
    int i_count = wf_proc_act->GetTotalSteps();
    v_wf_instance l_instance;
    wxString l_query;

    wf_proc_act->MoveFirst();
    l_query = wxT("INSERT INTO l_restart_log (instance_id, workflow_id, action_id, flow_ser, \
            total_flow, start_date, finish_date, group_id, operator_id, res_desc_id, restart_times, flag) VALUES ");
    for(int i = 0; i<i_count; i++)
    {
        l_instance = wf_proc_act->get_cur_instance_action();
        l_query = l_query +wxT("('")+s_instance+wxT("','")+
                  s_workflow+wxT("','")+l_instance.s_action.s_action_id+wxT("','")+NumToStr(l_instance.s_action.i_flow_ser)+
                  wxT("','")+NumToStr(l_instance.s_action.i_total_flow)+wxT("','")+
                  DateToAnsiStr(l_instance.t_start)+wxT("','")+DateToAnsiStr(l_instance.t_finish)+
                  wxT("','")+l_instance.s_action.s_group_id+wxT("','")+
                  l_instance.s_action.s_operator_id+wxT("','")+l_instance.step_desc+ wxT("','")+NumToStr(i_times)+wxT("','")+l_instance.s_flag+
                  wxT("'),");

        if(l_instance.is_active==true)
            break;

        wf_proc_act->MoveNext();
    }

    l_query.Replace(wxT("''"),wxT("NULL"));
    l_query.RemoveLast();
    l_query = l_query+wxT(";");
//   wxLogMessage(l_query);

    wxGetApp().app_sql_select(l_query);
}

void wf_operator_ex::cancel_log(int i_times)
{
    int i_count = wf_proc_act->GetTotalSteps();
    v_wf_instance l_instance;
    wxString l_query;

    wf_proc_act->MoveFirst();
    l_query = wxT("INSERT INTO l_cancel_log (instance_id, workflow_id, action_id, flow_ser, \
            total_flow, start_date, finish_date, group_id, operator_id, res_desc_id, cancel_times, flag ) VALUES ");
    for(int i = 0; i<i_count; i++)
    {
        l_instance = wf_proc_act->get_cur_instance_action();
        l_query = l_query +wxT("('")+s_instance+wxT("','")+
                  s_workflow+wxT("','")+l_instance.s_action.s_action_id+wxT("','")+NumToStr(l_instance.s_action.i_flow_ser)+
                  wxT("','")+NumToStr(l_instance.s_action.i_total_flow)+wxT("','")+
                  DateToAnsiStr(l_instance.t_start)+wxT("','")+DateToAnsiStr(l_instance.t_finish)+
                  wxT("','")+l_instance.s_action.s_group_id+wxT("','")+
                  l_instance.s_action.s_operator_id+wxT("','")+l_instance.step_desc+ wxT("','")+NumToStr(i_times)+wxT("','")+l_instance.s_flag+
                  wxT("'),");
        wf_proc_act->MoveNext();
    }

    l_query.Replace(wxT("''"),wxT("NULL"));
    l_query.RemoveLast();
    l_query = l_query+wxT(";");
//   wxLogMessage(l_query);

    wxGetApp().app_sql_select(l_query);
}


wxString wf_operator_ex::get_action_id()
{
    return wf_proc_act->get_cur_instance_action().s_action.s_action_id;
}

v_wf_instance wf_operator_ex::get_instance()
{
    return wf_proc_act->get_cur_instance_action();
}


bool wf_operator_ex::Feed_back(wxString &str_desc, wxString &aim_action_id)
{
    wxString str_from, str_to, str_temp, person_from, person_to;

    int i_return_times;
    wxDateTime t_from, t_to;

    wf_proc_act->MoveToActive();

    int i_cur_step = wf_proc_act->GetCurrentStep();
    if(i_cur_step <=1)
    {
        wxLogMessage(_("起始步骤， 无法操作!"));
        return false;
    }

    v_wf_instance l_instance = wf_proc_act->get_cur_instance_action();

    str_from = l_instance.s_action.s_action_id;

    l_instance.is_active = false;

    t_from = l_instance.t_start;
    person_from = l_instance.s_action.s_operator_id;
    update_process_status(l_instance, true);

    wf_proc_act->MovePrevious();
    l_instance = wf_proc_act->get_cur_instance_action();

    while(l_instance.s_action.s_action_id != aim_action_id)
    {

        wf_proc_act->MovePrevious();
        l_instance = wf_proc_act->get_cur_instance_action();
    }

    t_to  = l_instance.t_finish;
    person_to = l_instance.s_action.s_operator_id;

    l_instance.is_return= true;
    l_instance.return_times = l_instance.return_times+1;
    i_return_times = l_instance.return_times;

    if(!str_desc.IsEmpty())
    {
        str_temp = Get_Desc_id();
        update_desc(str_temp,str_desc,false);

    }

    return_log(str_from, aim_action_id, i_return_times,t_from, t_to,person_from, person_to, str_temp);

    l_instance.is_active = true;

    if(!str_desc.IsEmpty())
    {
        l_instance.step_desc = str_temp;
    }
    else l_instance.step_desc= wxEmptyString;

    wf_proc_act->set_instance(l_instance);

    return update_process_status(l_instance, true);

}

