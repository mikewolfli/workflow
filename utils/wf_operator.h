#ifndef WF_OPERATOR_H
#define WF_OPERATOR_H
#include <wx/wx.h>
#include <wx/string.h>
#include <wx/choicdlg.h>
//#include <wx/dynarray.h>
//#include <wx/arrimpl.cpp>
#include "interface/wxPostgreSQL.h"
#include "wf_stdafx.h"

struct v_wf_action
{
    // template
    wxString s_workflow_id;
    wxString s_action_id;
    wxString s_action_name;//only for template;
    wxString s_pre_action_id;
    wxString s_follow_action_id;
    int i_flow_ser;
    int i_total_flow;
    bool b_is_transit;
    bool b_allow_return;
    int i_action_lead;
    int i_urgent_lead;
    wxString s_action_lead_unit;
    wxString s_operator_id;
    wxString s_group_id;
    bool b_is_assigned;
    wxString s_action_type;
    wxString s_group_catalog;
    bool b_is_evaluate;
    bool b_is_need_eval;
    bool b_is_check;
    int i_join_mode;
    int i_split_mode;
    wxString s_role_id;
    bool is_start;
    bool is_end;

    v_wf_action& operator=(const v_wf_action& other);
};

struct v_wf_transition
{
    wxString item_id;
    wxString s_trans_name;
    wxString s_workflow_id;
    wxString s_input;
    wxString s_output;
    wxString s_desc;
    v_wf_transition& operator=(const v_wf_transition& other);

};

struct v_wf_instance
{
    v_wf_action s_action;
    wxString s_instance_id;
    wxDateTime t_start;
    wxDateTime t_finish;
    bool is_active=true;
    bool is_return=false;
    int return_times;
    bool is_restart=false;
    wxString step_desc;
    wxString s_flag;
    v_wf_instance& operator=(const v_wf_instance& other);
};
/*
WX_DECLARE_OBJARRAY(v_wf_instance, wfInstanceArray);
*/
v_wf_action* get_template_action(wxString str_workflow );
v_wf_action* get_template_action(wxString str_workflow,int &i_count);
v_wf_action get_wf_action(wxString s_action_id, v_wf_action* t_temp, int i_range);
v_wf_action* get_next_action(wxString s_workflow, wxString s_cur_action, int &i_ways);
v_wf_action* get_pre_action(wxString s_workflow, wxString s_cur_action, int &i_ways);
int get_instance_status(wxString s_instance,wxString s_workflow,wxString &s_action_id,wxString &s_wf_status);
bool is_workflow_created(wxString s_instance, wxString s_workflow,int &i_step);
bool delete_status(wxString s_instance_id, wxString s_workflow);
bool delete_all_process(wxString s_instance_id, wxString s_workflow);
int check_is_start_flow(wxString s_instance, wxString s_workflow_id);
wxString get_operator_name(wxString str);

class wf_process
{
public:
    wf_process(const wxString &_workflow, const wxString &_instance, wxString _flag=wxEmptyString);
    ~wf_process()
    {
        if(ser_proc)
            delete [] ser_proc;
    }

    int GetCurrentStep()
    {
        return cr_flow_ser;
    }

    int FindSteps(wxString t_action_id);

    int MoveFirst()
    {
        if(total_step>0) cr_flow_ser = 1;
        else cr_flow_ser = 0;

        return cr_flow_ser;
    }
    int MoveNext();
    int MovePrevious();
    int MoveLast();
    int MoveToActive();
    bool Locate(int i)
    {
        if(i>total_step)
            return false;

        cr_flow_ser = i;

        return true;
    }

    int GetTotalSteps()
    {
        return total_step;
    }

    v_wf_instance get_next_instance_action();
    v_wf_instance get_cur_instance_action();
    v_wf_instance get_previous_instance_action();

    void set_instance(v_wf_instance l_instance)
    {
        ser_proc[cr_flow_ser-1] = l_instance;
    }

    bool is_start()
    {
        return  ser_proc[cr_flow_ser-1].s_action.is_start;
    }

    bool is_end()
    {
        return ser_proc[cr_flow_ser-1].s_action.is_end;
    }


    bool Bof() const
    {
        return (total_step == 0 || cr_flow_ser < 1);
    }
    bool Eof() const
    {
        return (total_step == 0 || cr_flow_ser > total_step);
    }

    void create_step_action(v_wf_action* _template);
    void create_step_action(v_wf_action* _template, int i_total);

private:
    wxString str_instance;
    int cr_flow_ser;
    int total_step;
 //   wfInstanceArray ser_proc;
    v_wf_instance* ser_proc;
};

class wf_operator
{
public:
    wf_operator(const wxString &_instance, const wxString &_workflow,  v_wf_action* _template);
    ~wf_operator()
    {
        if(wf_proc_act)
            delete wf_proc_act;
        wf_proc_template = 0;
//        if(wf_proc_template)
//            delete [] wf_proc_template;
    }

    bool Feed_pre_back(wxString &str_desc);
    bool Feed_back(wxString &str_desc);
    bool Feed_back(wxString &str_desc, wxString &aim_action_id);
    bool Pass_proc(wxString str_operator, wxString str_group, wxString str_desc, bool b_log_pass);
    bool Pass_proc_g(wxString str_operator, wxString str_group, wxString str_desc, bool b_log_pass);
    bool Pass_proc_s(wxString str_operator, wxString str_group, wxString str_desc, bool b_log_pass);
    int check_act_status();
    wxString get_action_id();
    v_wf_instance get_instance();

    void return_log(wxString s_from, wxString s_to, int i_times, wxDateTime t_from, wxDateTime t_to, wxString p_from, wxString p_to, wxString str_desc);
    void restart_log(int i_times);
    void cancel_log(int i_times);

    bool update_desc(wxString str_id, wxString str_desc, bool b_update);
    bool update_instance(int i_status, int i_choice = 1 );
    bool update_instance(int i_status, wxString &s_wf_status, int i_choice = 1);
    bool update_instance_one2several(int i_status, bool only_wf_status=false);
    int  get_instance_status(wxString &s_wf_status);
    bool update_header_status(int i_status, wxString key_value, wxString key_name, wxString s_table);
    void restart_instance(wxString l_act_id, int i_times);
    void restart_instance(int i_times);
    void restart_instance(int i_times,wxString s_operator, wxString s_group );
    void cancel_restart(int i_times, wxString s_workflow=wf_str_configure);
    void close_instance();

    void restore_task(wxString l_act_id = wxEmptyString);

    void cancel_task(int i_times = 0);
    wxString Get_Desc_id();
    void start_proc(wxString str_desc, bool start_sec, bool b_log_pass=false);
    void start_proc(wxString s_operator, wxString s_group, wxString str_desc=wxEmptyString);
    bool update_process_status(v_wf_instance l_instance, bool b_update);

    bool delete_process();

    wf_process * get_current_process()
    {
         return wf_proc_act;
    }

private:
    wf_process* wf_proc_act;
    v_wf_action* wf_proc_template;
    wxString s_instance;
    wxString s_workflow;
};

class wf_operator_ex
{
public:
    wf_operator_ex(const wxString &_instance, const wxString &_workflow,  v_wf_action* _template, wxString _flag);
    ~wf_operator_ex()
    {
        if(wf_proc_act)
            delete wf_proc_act;
        wf_proc_template = 0;

    }

    bool Feed_back(wxString &str_desc, wxString &aim_action_id);
    bool Pass_proc(wxString str_operator, wxString str_group, wxString str_desc, bool b_log_pass, wxString _flag=wxEmptyString, bool b_active=true );

    wxString get_action_id();
    v_wf_instance get_instance();

    void return_log(wxString s_from, wxString s_to, int i_times, wxDateTime t_from, wxDateTime t_to, wxString p_from, wxString p_to, wxString str_desc);
    void restart_log(int i_times);
    void cancel_log(int i_times);

    bool update_desc(wxString str_id, wxString str_desc, bool b_update);

    bool update_instance(int i_status, int i_choice = 1 );
    bool update_instance(int i_status, wxString &s_wf_status, int i_choice = 1);
    int  get_instance_status(wxString &s_wf_status);

    void restart_instance(int i_times);
    void cancel_restart(int i_times, wxString s_workflow=wf_str_new_config);
    void close_instance();

    void restore_task(wxString l_act_id = wxEmptyString);

    void cancel_task(int i_times = 0);
    wxString Get_Desc_id();
    void start_proc(wxString s_group, wxString str_desc, bool b_log_pass=false);
    bool update_process_status(v_wf_instance l_instance, bool b_update);

    bool delete_process();

    wf_process * get_current_process()
    {
         return wf_proc_act;
    }

private:
    wf_process* wf_proc_act;
    wxString s_flag;
    v_wf_action* wf_proc_template;
    wxString s_instance;
    wxString s_workflow;
};

#endif // WF_OPERATOR_H
