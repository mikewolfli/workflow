#include "evaluate_dlg.h"
#include "wfApp.h"

//(*InternalHeaders(evaluate_dlg)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(evaluate_dlg)
const long evaluate_dlg::ID_STATICTEXT1 = wxNewId();
const long evaluate_dlg::ID_TEXTCTRL1 = wxNewId();
const long evaluate_dlg::ID_TEXTCTRL2 = wxNewId();
const long evaluate_dlg::ID_STATICTEXT3 = wxNewId();
const long evaluate_dlg::ID_TEXTCTRL3 = wxNewId();
const long evaluate_dlg::ID_STATICTEXT4 = wxNewId();
const long evaluate_dlg::ID_TEXTCTRL4 = wxNewId();
const long evaluate_dlg::ID_STATICTEXT5 = wxNewId();
const long evaluate_dlg::ID_TEXTCTRL5 = wxNewId();
const long evaluate_dlg::ID_STATICTEXT6 = wxNewId();
const long evaluate_dlg::ID_TEXTCTRL6 = wxNewId();
const long evaluate_dlg::ID_STATICTEXT7 = wxNewId();
const long evaluate_dlg::ID_TEXTCTRL7 = wxNewId();
const long evaluate_dlg::ID_STATICTEXT8 = wxNewId();
const long evaluate_dlg::ID_TEXTCTRL8 = wxNewId();
const long evaluate_dlg::ID_STATICTEXT9 = wxNewId();
const long evaluate_dlg::ID_TEXTCTRL9 = wxNewId();
const long evaluate_dlg::ID_STATICTEXT10 = wxNewId();
const long evaluate_dlg::ID_TEXTCTRL10 = wxNewId();
const long evaluate_dlg::ID_STATICTEXT2 = wxNewId();
const long evaluate_dlg::ID_BUTTON_OK = wxNewId();
const long evaluate_dlg::ID_BUTTON_CANCEL = wxNewId();
//*)

BEGIN_EVENT_TABLE(evaluate_dlg,wxDialog)
	//(*EventTable(evaluate_dlg)
	//*)
END_EVENT_TABLE()

evaluate_dlg::evaluate_dlg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(evaluate_dlg)
	wxGridBagSizer* GridBagSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;

	Create(parent, id, _("任务考核"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	GridBagSizer1 = new wxGridBagSizer(0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("任务"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	GridBagSizer1->Add(StaticText1, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_task = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(194,21), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	GridBagSizer1->Add(tc_task, wxGBPosition(0, 1), wxGBSpan(1, 2), wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	tc_task_info = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(225,38), wxTE_MULTILINE|wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	GridBagSizer1->Add(tc_task_info, wxGBPosition(0, 3), wxGBSpan(2, 2), wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("工作量"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	GridBagSizer1->Add(StaticText3, wxGBPosition(2, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_eval_value = new wxTextCtrl(this, ID_TEXTCTRL3, _("8"), wxDefaultPosition, wxSize(127,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	GridBagSizer1->Add(tc_eval_value, wxGBPosition(2, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("工作流"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	GridBagSizer1->Add(StaticText4, wxGBPosition(2, 3), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_workflow = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxSize(156,21), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	GridBagSizer1->Add(tc_workflow, wxGBPosition(2, 4), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("工作量说明"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	GridBagSizer1->Add(StaticText5, wxGBPosition(3, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_eval_remarks = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxSize(197,55), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	GridBagSizer1->Add(tc_eval_remarks, wxGBPosition(3, 1), wxGBSpan(2, 2), wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("工作步"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	GridBagSizer1->Add(StaticText6, wxGBPosition(3, 3), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_action = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxSize(153,21), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	GridBagSizer1->Add(tc_action, wxGBPosition(3, 4), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("错误数量"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	GridBagSizer1->Add(StaticText7, wxGBPosition(5, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_error_qty = new wxTextCtrl(this, ID_TEXTCTRL7, _("0"), wxDefaultPosition, wxSize(129,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	GridBagSizer1->Add(tc_error_qty, wxGBPosition(5, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("操作人"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	GridBagSizer1->Add(StaticText8, wxGBPosition(4, 3), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_operator = new wxTextCtrl(this, ID_TEXTCTRL8, wxEmptyString, wxDefaultPosition, wxSize(154,21), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL8"));
	GridBagSizer1->Add(tc_operator, wxGBPosition(4, 4), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("错误说明"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	GridBagSizer1->Add(StaticText9, wxGBPosition(6, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_error_points = new wxTextCtrl(this, ID_TEXTCTRL9, wxEmptyString, wxDefaultPosition, wxSize(195,49), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL9"));
	GridBagSizer1->Add(tc_error_points, wxGBPosition(6, 1), wxGBSpan(2, 2), wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	st_check_eval = new wxStaticText(this, ID_STATICTEXT10, _("考评人"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	GridBagSizer1->Add(st_check_eval, wxGBPosition(5, 3), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	tc_evaluator = new wxTextCtrl(this, ID_TEXTCTRL10, wxEmptyString, wxDefaultPosition, wxSize(155,21), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL10"));
	GridBagSizer1->Add(tc_evaluator, wxGBPosition(5, 4), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("小时"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	GridBagSizer1->Add(StaticText2, wxGBPosition(2, 2), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(GridBagSizer1, 7, wxALL|wxEXPAND, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button_OK = new wxButton(this, ID_BUTTON_OK, _("确认"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_OK"));
	BoxSizer2->Add(Button_OK, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Cancel = new wxButton(this, ID_BUTTON_CANCEL, _("取消"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CANCEL"));
	BoxSizer2->Add(Button_Cancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&evaluate_dlg::Ontc_eval_valueText);
	Connect(ID_TEXTCTRL7,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&evaluate_dlg::Ontc_error_qtyText);
	Connect(ID_BUTTON_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&evaluate_dlg::OnButton_OKClick);
	Connect(ID_BUTTON_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&evaluate_dlg::OnButton_CancelClick);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&evaluate_dlg::OnInit);
	//*)

}

evaluate_dlg::~evaluate_dlg()
{
	//(*Destroy(evaluate_dlg)
	//*)
}

void evaluate_dlg::get_eval_id()
{
    m_eval_id = wxGetApp().get_ser_no(wxT("l_evaluation_instance"), wxT("eval_id"));
}

void evaluate_dlg::init_ctrl()
{
    m_b_update = get_info();
    tc_operator->SetValue(m_operator_name);
    tc_workflow->SetValue(m_workflow_name);
    tc_action->SetValue(m_action_name);
    tc_evaluator->SetValue(m_evaluator);
    tc_eval_value->SetValue(NumToStr(m_eval_value));

    if(m_workflow_id == wxT("WF0002"))
       tc_task->SetValue(m_task.Left(10));
    else
       tc_task->SetValue(m_task);
}

bool evaluate_dlg::get_info()
{
     wxPostgreSQLresult * _res;

     bool b_update = false;
     int i_count;

     //workflow_name;
     wxString str_sql;

     str_sql = wxT("SELECT * from l_evaluation_instance WHERE task_id ='")+m_task+wxT("' and action_id ='")+m_action_id+wxT("' and op_finish_date='")+m_op_finish_date
                 +wxT("' and is_valid = true;");

    _res =wxGetApp().app_sql_select(str_sql);

     if(_res->Status()!= PGRES_TUPLES_OK)
     {
         _res->Clear();
        return false;
     }

     i_count = _res->GetRowsNumber();

     if(i_count >=1)
     {
         _res->MoveFirst();
         b_update = true;

         tc_task_info->SetValue(_res->GetVal(wxT("task_desc")));

         m_eval_value = _res->GetDouble(wxT("eval_value"));
         tc_eval_value->SetValue(NumToStr(m_eval_value));

         tc_eval_remarks->SetValue(_res->GetVal(wxT("eval_remarks")));

         tc_error_qty->SetValue(_res->GetVal(wxT("error_qty")));

         tc_error_points->SetValue(_res->GetVal(wxT("error_point")));

         m_update = _res->GetVal(wxT("eval_id"));

         m_check_id = _res->GetVal(wxT("check_id"));

     }

     _res->Clear();

      str_sql = wxT("select workflow_name from s_workflow_info where workflow_id = '")+m_workflow_id+wxT("';");

     _res =wxGetApp().app_sql_select(str_sql);

     if(_res->Status()!= PGRES_TUPLES_OK)
     {
        _res->Clear();
        return false;
     }

     i_count = _res->GetRowsNumber();

     if(i_count > 0)
     {
         _res->MoveFirst();
         m_workflow_name = _res->GetVal(0);
     }else
         m_workflow_name.Empty();

     _res->Clear();

     //action name;

     str_sql = wxT("select action_name from s_action_info where action_id = '")+m_action_id+wxT("';");

     _res =wxGetApp().app_sql_select(str_sql);

     if(_res->Status()!= PGRES_TUPLES_OK)
     {
        _res->Clear();
        return false;
     }

     i_count = _res->GetRowsNumber();

     if(i_count > 0)
     {
         _res->MoveFirst();
         m_action_name = _res->GetVal(0);
     }else
         m_action_name.Empty();

     _res->Clear();

     //operator and evaluator or checker

     str_sql = wxT("select name from s_employee where employee_id = '")+m_operator_id+wxT("';");

     _res =wxGetApp().app_sql_select(str_sql);

     if(_res->Status()!= PGRES_TUPLES_OK)
     {
        _res->Clear();
        return false;
     }

     i_count = _res->GetRowsNumber();

     if(i_count > 0)
     {
         _res->MoveFirst();
         m_operator_name = _res->GetVal(0);
     }else
         m_operator_name.Empty();

     _res->Clear();

    if(m_status == 1||(m_status==2 && !m_check_id.IsEmpty()))
    {
        str_sql = wxT("select name from s_employee where employee_id = '")+m_check_id+wxT("';");
        st_check_eval->SetLabel(_("核查人"));
    }else
    {
        str_sql = wxT("select name from s_employee where employee_id = '")+m_evaluator_id+wxT("';");
        st_check_eval->SetLabel(_("考评人"));
    }

    _res =wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return false;
    }

    i_count = _res->GetRowsNumber();

    if(i_count > 0)
    {
        _res->MoveFirst();
        m_evaluator = _res->GetVal(0);
    }
    else
        m_evaluator.Empty();

    _res->Clear();


    if((b_update&&m_status==1)||(b_update&&m_status==2&&m_check_id.IsEmpty()))
    {
        return true;
    }

    //task desc (workflow_id = 'WF0002',项目名称+: wbs no list;
    if(m_workflow_id == wxT("WF0002"))
    {
        m_eval_value =0.0;
        str_sql = wxT("select * from v_unit_info where batch_id='")+m_task+wxT("' ORDER BY wbs_no ASC;");

        _res =wxGetApp().app_sql_select(str_sql);

        wxString str_head, str_unit, str_elevator_type;

        int i_nstd_level;

        wxArrayString arr_str,arr_result;

        if(_res->Status()!= PGRES_TUPLES_OK)
        {
           _res->Clear();
            return false;
        }

        i_count = _res->GetRowsNumber();

        if(i_count >0)
        {
            _res->MoveFirst();
            str_head = _res->GetVal(wxT("project_name"));
            str_unit = _res->GetVal(wxT("wbs_no"));
            arr_str.Add(str_unit);

            m_task_desc = str_head + wxT(":")+str_unit + wxT(";");

            str_elevator_type = _res->GetVal(wxT("elevator_type"));
            i_nstd_level = _res->GetInt(wxT("nonstd_level"));

            m_eval_value = m_eval_value+ get_evalute_value(str_elevator_type, i_nstd_level);

            for(int i=1; i<i_count; i++)
            {
                _res->MoveNext();
                str_unit = _res->GetVal(wxT("wbs_no"));
                arr_str.Add(str_unit);
                m_task_desc = m_task_desc+str_unit+wxT(";");

                str_elevator_type = _res->GetVal(wxT("elevator_type"));
                i_nstd_level = _res->GetInt(wxT("nonstd_level"));

                m_eval_value = m_eval_value+ get_evalute_value(str_elevator_type, i_nstd_level);
            }

            if(!arr_str.IsEmpty())
            {
                // for display
                arr_result = combine_str(arr_str, wxT(";"),wxT("~"),wxT(","),true, false);
                tc_task_info->SetValue(str_head+wxT(" ")+NumToStr(arr_str.GetCount())+wxT("台:")+arr_result.Item(0));

                arr_result.Clear();
                 // for store in database
                arr_result = combine_str(arr_str, wxT(";"),wxEmptyString,wxT(","),true, false);
                m_task_desc = str_head + wxT(":")+arr_result.Item(0);
            }

        }
        else
        {
            m_task_desc.Empty();
            tc_task_info->SetValue(m_task_desc);
        }

        arr_str.Clear();
        arr_result.Clear();
        _res->Clear();
    }
    else if(m_workflow_id == wxT("WF0003"))
    {
        str_sql = wxT("select concat(nonstd_catalog,': ', nonstd_desc) as task_info from l_nonstd_app_item where index_id ='")+m_task+wxT("';");
        _res =wxGetApp().app_sql_select(str_sql);

        if(_res->Status()!= PGRES_TUPLES_OK)
        {
                    _res->Clear();
            return false;
        }

        i_count = _res->GetRowsNumber();
        if(i_count > 0)
        {
            _res->MoveFirst();
            m_task_desc = _res->GetVal(wxT("task_info"));

        }
        else
        {
            m_task_desc.Empty();

        }
         tc_task_info->SetValue(m_task_desc);
        _res->Clear();
    }else
    {

        str_sql = wxT("select concat(nonstd_catalog,': ', nonstd_desc,':', instance_remarks) as task_info from v_nonstd_app_item_instance where index_mat_id ='")+m_task+wxT("';");
        _res =wxGetApp().app_sql_select(str_sql);

        if(_res->Status()!= PGRES_TUPLES_OK)
        {
          _res->Clear();
          return false;
        }

        i_count = _res->GetRowsNumber();
        if(i_count > 0)
        {
            _res->MoveFirst();
            m_task_desc = _res->GetVal(wxT("task_info"));

        }
        else
        {
            m_task_desc.Empty();

        }
        tc_task_info->SetValue(m_task_desc);
        _res->Clear();
    }

    return false;
}

double evaluate_dlg::get_evalute_value(wxString s_elevator_type, int i_nstd_level)
{
     double d_value = 0.0;

     if(s_elevator_type == wxT("RF2"))
        d_value = d_value  + conf_workload* conf_rf2;
     else if(s_elevator_type == wxT("RF3") ||s_elevator_type == wxT("synergy") || s_elevator_type == wxT("TE-Synergy"))
        d_value = d_value + conf_rf3_or_synergy * conf_workload;
     else if(i_nstd_level == 4)
            d_value = d_value + conf_workload * conf_complex_nstd;
    else d_value  = d_value +conf_workload;

     return d_value;

}

void evaluate_dlg::OnButton_OKClick(wxCommandEvent& event)
{
    if(m_status ==1 || (m_status==2 && m_check_id.IsEmpty()))
         get_eval_id();
//    m_task = tc_task->GetValue();

  /*  if(m_action_id != wxT("WF0002"))
         m_task_desc = tc_task_info->GetValue();*/
    wxString str = tc_eval_value->GetValue();
    str.ToDouble(&m_eval_value);
    m_eval_remarks = tc_eval_remarks->GetValue();
    m_error_qty = wxAtoi(tc_error_qty->GetValue());
    m_error_point = tc_error_points->GetValue();

    if(m_eval_value <= 0.0)
    {
         if(wxMessageBox(_("工作量不能为0!"),_("提示"),wxOK)==wxOK)
            return;
    }

    if(m_error_qty != 0 && m_error_point.IsEmpty())
    {
         if(wxMessageBox(_("错误点不能为空!"),_("提示"),wxOK)==wxOK)
            return;
    }

    save_evaluate();
    EndDialog(wxID_OK);
}

void evaluate_dlg::OnButton_CancelClick(wxCommandEvent& event)
{
    EndDialog(wxID_CANCEL);
}

bool evaluate_dlg::save_evaluate()
{
    wxString str_sql;

    if(m_b_update)
    {
        str_sql = wxT("UPDATE l_evaluation_instance SET is_valid=false, modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("' where eval_id = '")+m_update+wxT("';");
        wxGetApp().app_sql_update(str_sql);
    }


    if(m_status == 1)
    {
        str_sql = wxT("INSERT INTO l_evaluation_instance(eval_id, task_id, task_desc, workflow_id, action_id,\
            operator_id, op_start_date, op_finish_date, eval_value, eval_remarks, error_qty, error_point , is_valid, modify_date, modify_emp_id, create_date, create_emp_id, check_id)\
            VALUES ('")+m_eval_id +wxT("','")+m_task+wxT("','")+m_task_desc+wxT("','")+m_workflow_id+wxT("','")+m_action_id+wxT("','")+
        m_operator_id+wxT("','")+m_op_start_date+wxT("','")+m_op_finish_date+wxT("','")+NumToStr(m_eval_value)+wxT("','")+m_eval_remarks+wxT("','")+
        NumToStr(m_error_qty)+wxT("','")+m_error_point+wxT("', true, '")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+m_check_id+wxT("');");

    }
    else if(m_status == 2 && m_check_id.IsEmpty())
    {
        str_sql = wxT("INSERT INTO l_evaluation_instance(eval_id, task_id, task_desc, workflow_id, action_id,\
            operator_id, op_start_date, op_finish_date, evaluator_id, eval_value, eval_remarks, error_qty, error_point , is_valid, modify_date, modify_emp_id, create_date, create_emp_id)\
            VALUES ('")+m_eval_id +wxT("','")+m_task+wxT("','")+m_task_desc+wxT("','")+m_workflow_id+wxT("','")+m_action_id+wxT("','")+
        m_operator_id+wxT("','")+m_op_start_date+wxT("','")+m_op_finish_date+wxT("','")+m_evaluator_id+wxT("','")+NumToStr(m_eval_value)+wxT("','")+m_eval_remarks+wxT("','")+
        NumToStr(m_error_qty)+wxT("','")+m_error_point+wxT("', true, '")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("');");
    }
    else
    {
        str_sql = wxT("UPDATE l_evaluation_instance SET evaluator_id='")+m_evaluator_id+wxT("', eval_value='")+NumToStr(m_eval_value)+
        wxT("', eval_remarks='")+m_eval_remarks+wxT("', error_qty='")+NumToStr(m_error_qty)+wxT("', error_point='")+m_error_point+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+
        wxT("', modify_emp_id='")+gr_para.login_user+wxT("' WHERE eval_id = '")+m_update+wxT("';");
    }

    str_sql.Replace("''", "NULL");
    return wxGetApp().app_sql_update(str_sql);
}


void evaluate_dlg::Ontc_eval_valueText(wxCommandEvent& event)
{
    static wxString oldstr="";
    double d;
    if (NULL == tc_eval_value)return;
    if (tc_eval_value->GetValue().ToDouble(&d)  ||  0== tc_eval_value->GetValue().Length() )
    {
        oldstr =tc_eval_value->GetValue();

    }
    else
    {
        tc_eval_value->SetValue(oldstr);
        tc_eval_value->SetInsertionPoint(tc_eval_value->GetValue().Length());
    }
}

void evaluate_dlg::Ontc_error_qtyText(wxCommandEvent& event)
{
    static wxString oldstr="";
    long d;
    if (NULL == tc_error_points)return;
    if (tc_error_points->GetValue().ToLong(&d)  ||  0== tc_error_points->GetValue().Length() )
    {
        oldstr =tc_error_points->GetValue();

    }
    else
    {
        tc_error_points->SetValue(oldstr);
        tc_error_points->SetInsertionPoint(tc_error_points->GetValue().Length());
    }
}

void evaluate_dlg::OnInit(wxInitDialogEvent& event)
{
        init_ctrl();
}
