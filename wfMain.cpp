/***************************************************************
 * Name:      wfMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    mikewolfli (mikewolfli@163.com)
 * Created:   2013-11-21
 * Copyright: mikewolfli (http://mikewolfli.blog.163.com)
 * License:
 **************************************************************/

#include "wfMain.h"
#include <wx/msgdlg.h>

#include <wx/aboutdlg.h>
#include "login_dlg.h"
#include <wx/log.h>
#include <wx/display.h>
#include <wx/imaglist.h>
#include "connect_para_dlg.h"
#include "reset_pwd.h"
#include "wfApp.h"
#include "search_case.h"
#include <curl/curl.h>

#include "version.h"


//(*InternalHeaders(wfFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(wfFrame)
const long wfFrame::idMenuQuit = wxNewId();
const long wfFrame::idMenuNomalV = wxNewId();
const long wfFrame::idMenuReport = wxNewId();
const long wfFrame::idMenuAbout = wxNewId();
const long wfFrame::ID_STATUSBAR1 = wxNewId();
//*)


BEGIN_EVENT_TABLE(wfFrame,wxFrame)
    //(*EventTable(wfFrame)
    //*)
END_EVENT_TABLE()

wfFrame::wfFrame(wxWindow* parent,wxWindowID id)
{

    m_mgr.SetManagedWindow(this);
    this->Maximize(true);
    this->SetMinSize(wxSize(800,600));//set the whole windows min size 800 * 600
    wxDisplay Screen;
    wxRect ClientRect = Screen.GetClientArea();

    // the follow is auto-gnenerated by the wxSmith
    //Initialize(wfFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* mb_main;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    mb_main = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, ID_INVIDIUAL_REVISE_PWD, _("修改密码"), _("修改个人密码"), wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu1, ID_INVIDIUAL_LOGIN, _("登陆"), _("用户登陆"), wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    MenuItem5 = new wxMenuItem(Menu1, ID_INVIDIUAL_LOGOUT, _("注销"), _("用户注销"), wxITEM_NORMAL);
    Menu1->Append(MenuItem5);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    mb_main->Append(Menu1, _("个性化(&F)"));
    Menu3 = new wxMenu();
    MenuItem6 = new wxMenuItem(Menu3, idMenuNomalV, _("&Normal View"), _("正常视图"), wxITEM_CHECK);
    Menu3->Append(MenuItem6);
    MenuItem6->Check(true);
    MenuItem7 = new wxMenuItem(Menu3, idMenuReport, _("报表视图"), _("切换报表视图"), wxITEM_CHECK);
    Menu3->Append(MenuItem7);
    mb_main->Append(Menu3, _("视图(&V)"));
    Menu4 = new wxMenu();
    MenuItem8 = new wxMenuItem(Menu4, ID_WORKFLOW_WF, _("工作流"), _("工作流操作"), wxITEM_NORMAL);
    Menu4->Append(MenuItem8);
    Menu4->AppendSeparator();
    MenuItem9 = new wxMenuItem(Menu4, ID_INSTANCE_UNIT_INFO, _("项目信息"), _("项目录入,修改,启动"), wxITEM_NORMAL);
    Menu4->Append(MenuItem9);
    MenuItem18= new wxMenuItem(Menu4, ID_INSTANCE_UNIT_AUTHORITY, _("项目授权"),_("项目任务分配"),wxITEM_NORMAL);
    Menu4->Append(MenuItem18);
    MenuItem10 = new wxMenuItem(Menu4, ID_INSTANCE_NONSTD_APPLY, _("非标申请"), _("项目非标申请"), wxITEM_NORMAL);
    Menu4->Append(MenuItem10);
    MenuItem11 = new wxMenuItem(Menu4, ID_INSTANCE_NONSTD_DESIGN, _("非标任务分配"), _("非标任务分配"), wxITEM_NORMAL);
    Menu4->Append(MenuItem11);
    MenuItem12 = new wxMenuItem(Menu4, ID_INSTANCE_NONMAT_LIST, _("非标处理"), _("非标处理维护清单"), wxITEM_NORMAL);
    Menu4->Append(MenuItem12);
    mb_main->Append(Menu4, _("工作流(&W)"));
    Menu6 = new wxMenu();
    MenuItem16 = new wxMenuItem(Menu6, ID_GENERATE_ID_COMMON, _("合同评审"), _("合同评审追踪"), wxITEM_NORMAL);
    Menu6->Append(MenuItem16);
    MenuItem17 = new wxMenuItem(Menu6, ID_GENERATE_ID_NSTD_CONF, _("项目配置"), _("项目配置追踪"), wxITEM_NORMAL);
    Menu6->Append(MenuItem17);
    mb_main->Append(Menu6, _("报表(&R)"));
    Menu5 = new wxMenu();
    MenuItem13 = new wxMenuItem(Menu5, ID_SETUP_DATABASE_CONFIGURE, _("数据库管理"), _("数据库管理"), wxITEM_NORMAL);
    Menu5->Append(MenuItem13);
    MenuItem14 = new wxMenuItem(Menu5, ID_SETUP_MAINTAIN_USERS, _("用户维护"), _("用户维护"), wxITEM_NORMAL);
    Menu5->Append(MenuItem14);
    MenuItem15 = new wxMenuItem(Menu5, ID_SETUP_AUTHORITY, _("权限分配"), _("权限分配"), wxITEM_NORMAL);
    Menu5->Append(MenuItem15);
    MenuItem19 = new wxMenuItem(Menu5, ID_SETUP_PARAMETER, _("软件设置"), _("软件设置"), wxITEM_NORMAL);
    Menu5->Append(MenuItem19);
    mb_main->Append(Menu5, _("软件管理(&M)"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    mb_main->Append(Menu2, _("Help"));
    SetMenuBar(mb_main);
    sb_info = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[3] = { -2, -2, -1 };
    int __wxStatusBarStyles_1[3] = { wxSB_FLAT, wxSB_RAISED , wxSB_NORMAL };
    sb_info->SetFieldsCount(3,__wxStatusBarWidths_1);
    sb_info->SetStatusStyles(3,__wxStatusBarStyles_1);
    SetStatusBar(sb_info);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wfFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wfFrame::OnAbout);
    Connect(ID_TOOL_BOX, wxEVT_TB_ITEM_SELECTED, (wxObjectEventFunction)&wfFrame::OnToolBoxItemSelected);
    Connect(ID_INVIDIUAL_LOGOUT, wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wfFrame::OnLogout);
    Connect(ID_AUI_NOTEBOOK, wxEVT_AUINOTEBOOK_PAGE_CHANGED,(wxObjectEventFunction)&wfFrame::OnAuiNotebookPageChanged);
    Connect(ID_THREAD_TIMER, wxEVT_TIMER, (wxObjectEventFunction)&wfFrame::OnThreadTimer);

    tc_log = new wxTextCtrl(this, ID_TEXTCTRL_LOG, wxEmptyString, wxDefaultPosition, wxSize(ClientRect.width,ClientRect.height/20), wxTE_MULTILINE|wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL_LOG"));

    SetIcon(wxICON(wfworkflow));
    SetTitle(_("PEC部门流程软件 ")+AutoVersion::STATUS_SHORT+AutoVersion::FULLVERSION_STRING);
#if wxUSE_LOG
#ifdef __WXMOTIF__
    // For some reason, we get a memcpy crash in wxLogStream::DoLogStream
    // on gcc/wxMotif, if we use wxLogTextCtl. Maybe it's just gcc?
    delete wxLog::SetActiveTarget(new wxLogStderr);
#else
    // set our text control as the log target
    wxLogTextCtrl *logWindow = new wxLogTextCtrl(tc_log);
    delete wxLog::SetActiveTarget(logWindow);
#endif
#endif // wxUSE_LOG

  //  sap_rfc_conn = new Rfc_Communication();
    login_dlg dlg;
    if(dlg.ShowModal()==wxID_OK)
    {
        wxGetApp().login_log(2);
        gr_para.login_status = true;
        wxLogMessage(gr_para.login_user+_("登录 server:")+gr_para.server_host+";port:"+gr_para.server_port+"; database:"+gr_para.server_dbname);
        SetStatusText(gr_para.login_user+_(" 已登录\t")+gr_para.local_ip+"\t"+gr_para.local_pc_name,2);
    }
    else
    {
        gr_para.login_status = false;
        SetStatusText(_("未登录\t")+gr_para.local_ip+"\t"+gr_para.local_pc_name,2);
    }

    SetStatusText(_("红色背景-暂停项目; 绿色背景-加急项目; 黄色背景-精益项目;天蓝色：pre-engineer项目;"), 1);

    m_toolbox = create_toolbox(ClientRect);
    aui_notebook = CreateNotebook(ClientRect);

//layout the aui panel
    m_mgr.AddPane(aui_notebook, wxAuiPaneInfo().Name(wxT("AUI NoteBook"))
                  .CenterPane().PaneBorder(false));

                  SetToolBoxItemSelected(-1);

    m_mgr.AddPane(m_toolbox,wxAuiPaneInfo().Name(wxT("Control Panel"))
                  .Caption(_("功能面板")).Left().Layer(1)
                  .Position(1).CloseButton(true).PinButton(true));

    m_mgr.SetDockSizeConstraint(1.0,0.1);
    m_mgr.AddPane(tc_log, wxAuiPaneInfo().Name(wxT("Operation Log"))
                  .Caption(_("操作记录")).Bottom().Layer(2).Position(1));

    SetToolBoxItemSelected(-1);

    m_mgr.Update();

    tray = new MyTaskBarIcon();
#if defined(__WXOSX__) && wxOSX_USE_COCOA
    m_dockIcon = new MyTaskBarIcon(wxTaskBarIcon::DOCK);
#endif
    tray->SetIcon(wxICON(wfworkflow));

    curl_global_init(CURL_GLOBAL_ALL);
/*
    m_str_query = wxT("SELECT instance_id, concat(project_name,\
                    ' ', lift_no) as task_content FROM v_task_list1 WHERE \
                    is_active = true AND operator_id = '")+gr_para.login_user+wxT("' AND status != '4' ORDER BY instance_id ASC;");

    m_old_array = Get_task_list(m_str_query);*/

  //  m_thread_timer = new wxTimer(this, ID_THREAD_TIMER);
  //  m_thread_timer->Start(gr_para.threadgap*60*1000);
}

wfFrame::~wfFrame()
{
    //(*Destroy(wfFrame)
    //*)

    m_mgr.UnInit();

    curl_global_cleanup();
 //   m_thread_timer->Stop();
 //   m_old_array.Clear();
  //  delete m_thread_timer;
    delete tray;

    wxThread *thread;

    wxGetApp().AppCritSection.Enter();

    // check if we have any threads running first
    const wxArrayThread& threads = wxGetApp().AppThreads;
    size_t count = threads.GetCount();

    if ( count )
    {
        // set the flag for MyThread::OnExit()
        wxGetApp().AppShutdown = true;

        // stop all threads
        while ( ! threads.IsEmpty() )
        {
            thread = threads.Last();

            wxGetApp().AppCritSection.Leave();

            thread->Delete();

            wxGetApp().AppCritSection.Enter();
        }
    }

    wxGetApp().AppCritSection.Leave();

    if ( count )
    {
        // now wait for them to really terminate
        wxGetApp().AppSemaphoreDone.Wait();
    }
    //else: no threads to terminate, no condition to wait for


#if defined(__WXOSX__) && wxOSX_USE_COCOA
    delete m_dockIcon;
#endif
#if wxUSE_LOG
    delete wxLog::SetActiveTarget(NULL);
#endif // wxUSE_LOG

}

void wfFrame::OnQuit(wxCommandEvent& event)
{
    wxCriticalSectionLocker enter(wxGetApp().AppCritSection);

    // AppThreads should always be empty...
    if (wxGetApp().AppThreads.IsEmpty()) {
        Close(true);
    }
    // ... so this check is a little bit superfluously
    else {
        wxGetApp().AppThreads.Empty();
        Close(true);
    }

    event.Skip();
}

void wfFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxAboutDialogInfo info;
    wxDateTime dt = wxDateTime::Today();
    info.SetName(_("workflow"));
    info.SetVersion(wxString(AutoVersion::FULLVERSION_STRING)+wxString(AutoVersion::STATUS));
    info.SetDescription(msg+"\n\t"+"Happy new day - "+DateToAnsiStr(dt));
    info.SetCopyright(_("版权所有 (C) 2014 mikewolfli"));
  //  info.SetWebSite("http://mikewolfli.blog.163.com");
    info.SetWebSite("https://github.com/mikewolfli");
    info.AddDeveloper("mikewolfli");
    wxAboutBox(info);
}

wxAuiNotebook * wfFrame::CreateNotebook(wxRect &r_rect)
{
    wxAuiNotebook* aui_ctrl = new wxAuiNotebook(this, ID_AUI_NOTEBOOK,
            wxDefaultPosition,
            wxSize(r_rect.width*9/10,r_rect.height*19/20),
            wxAUI_NB_TOP | wxAUI_NB_TAB_SPLIT | wxAUI_NB_TAB_MOVE | wxAUI_NB_SCROLL_BUTTONS|wxAUI_NB_WINDOWLIST_BUTTON|wxAUI_NB_CLOSE_ON_ACTIVE_TAB);

//    wxBitmap *b_bitmap= new wxBitmap("./res/toolbar16.jpg",wxBITMAP_TYPE_ANY);
 //   panel_unit_info = new instance_unit_info(aui_ctrl, wxID_ANY);
//    aui_ctrl->AddPage(panel_unit_info,_("项目信息"), false,b_bitmap->GetSubBitmap(wxRect(0,0,16,16)));
    return aui_ctrl;
}

/*
void wfFrame::OnToolBoxTabSelected(wxToolBoxEvent & event)
{

    wxToolBoxTab* new_tab=event.GetTab();

    int i_sel = new_tab->GetSelItemIndex();

    if(i_sel>=0)
    {
 //        wxToolBoxItemArray i_item = new_tab->GetToolItems();
 //        i_item.Item(i_sel).SetSelected(false);
 //        new_tab->SetSelItemIndex(-1);
 //        i_item.Item(i_sel).Invalidate();
           new_tab->SetSelItemIndex(-1);

    }
 //  i_sel = new_tab->GetSelItemIndex();
//    m_toolbox->RefreshTabs();
 //   event.Skip();
}
*/
/*
void wfFrame::auinotebook_addpage()
{

    wxBitmap *b_bitmap= new wxBitmap("./res/toolbar16.jpg",wxBITMAP_TYPE_ANY);
    int i_index;

    i_index = aui_notebook->GetPageIndex(panel_unit_info);
    if(i_index==wxNOT_FOUND)
    {
        panel_unit_info = new instance_unit_info(aui_notebook, wxID_ANY);
        aui_notebook->AddPage(panel_unit_info,_("项目信息"), false, b_bitmap->GetSubBitmap(wxRect(0,0,16,16)));
    }

    i_index = aui_notebook->GetPageIndex(panel_workflow_wf);
    if(i_index==wxNOT_FOUND)
    {
            panel_workflow_wf = new workflow_wf(aui_notebook, wxID_ANY);
            aui_notebook->AddPage(panel_workflow_wf,_("配置工作流"),true,b_bitmap->GetSubBitmap(wxRect(80,0,16,16)));
    }

    i_index = aui_notebook->GetPageIndex(panel_project_author);
    if(i_index==wxNOT_FOUND)
    {
        panel_project_author = new project_author_panel(aui_notebook,wxID_ANY);
        aui_notebook->AddPage(panel_project_author,_("项目授权"),true,b_bitmap->GetSubBitmap(wxRect(16,0,16,16)));
    }

    i_index = aui_notebook->GetPageIndex(panel_nstd_apply);
    if(i_index==wxNOT_FOUND)
    {
        panel_nstd_apply = new nstd_apply_panel(aui_notebook,wxID_ANY);
        aui_notebook->AddPage(panel_nstd_apply,_("非标申请"),true,b_bitmap->GetSubBitmap(wxRect(32,0,16,16)));
    }

    i_index = aui_notebook->GetPageIndex(panel_nstd_mat_apply);
    if(i_index==wxNOT_FOUND)
    {
        panel_nstd_mat_apply = new nstd_mat_apply(aui_notebook,wxID_ANY);
        aui_notebook->AddPage(panel_nstd_mat_apply ,_("非标处理"),true,b_bitmap->GetSubBitmap(wxRect(48,0,16,16)));
    }

    i_index = aui_notebook->GetPageIndex(panel_nstd_workflow);
    if(i_index==wxNOT_FOUND)
    {
        panel_nstd_workflow = new wf_workflow_panel(aui_notebook, wxID_ANY);
        aui_notebook->AddPage(panel_nstd_workflow, _("非标工作流"), true, b_bitmap->GetSubBitmap(wxRect(96,0,16,16)));
    }

    i_index = aui_notebook->GetPageIndex(panel_nstd_author);
    if(i_index == wxNOT_FOUND)
    {
        panel_nstd_author = new nstd_author_panel(aui_notebook, wxID_ANY);
        aui_notebook->AddPage(panel_nstd_author, _("非标任务分配"), true, b_bitmap->GetSubBitmap(wxRect(64,0,16,16)));
    }
}*/

void wfFrame::OnToolBoxItemSelected(wxToolBoxEvent & event)
{
    wxToolBoxItem * tb_item=event.GetItem();
    wxWindowID i_id = tb_item->GetID();
    if(!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆系统,请登陆后在操作"));
        return;
    }


    OnToggleNotebookPanel(i_id);

 //   bool b_all = m_toolbox->GetShowSelectionAlways();
    event.Skip();
}

void wfFrame::OnToggleNotebookPanel(wxWindowID i_id)
{
    wxBitmap *b_bitmap= new wxBitmap("./res/toolbar16.jpg",wxBITMAP_TYPE_ANY);
    connect_para_dlg para_dlg;
    reset_pwd pwd_dlg;
    wxString str_query;

    wxArrayString array_group = wxGetApp().get_group();

    int i_index;
    switch(i_id)
    {
    case  ID_PRJ_REVIEW_INFO:
        i_index = aui_notebook->GetPageIndex(panel_project_info);
        if(i_index==wxNOT_FOUND)
        {
            panel_project_info = new project_info_panel(aui_notebook, wxID_ANY);
            aui_notebook->AddPage(panel_project_info,_("项目信息"),true,b_bitmap->GetSubBitmap(wxRect(0,0,16,16)));

        }else
            aui_notebook->ChangeSelection(i_index);
        break;
    case ID_PRJ_REVIEW_PROC:
        if(gr_para.login_user == wxGetApp().get_leader(wxT("G0002")))
        {
            i_index = aui_notebook->GetPageIndex(panel_project_review_author);
            if(i_index==wxNOT_FOUND)
            {
                 panel_project_review_author = new project_review_author_panel(aui_notebook,wxID_ANY);
                 aui_notebook->AddPage(panel_project_review_author, _("评审授权"),true,b_bitmap->GetSubBitmap(wxRect(16,0,16,16)));
            }else
                aui_notebook->ChangeSelection(i_index);
        }else// if(array_group.Index(wxT("G0002"))!=wxNOT_FOUND)
        {
            i_index = aui_notebook->GetPageIndex(panel_project_review);
            if(i_index==wxNOT_FOUND)
            {
                 panel_project_review = new project_review_panel(aui_notebook,wxID_ANY);
                 aui_notebook->AddPage(panel_project_review, _("合同评审"),true,b_bitmap->GetSubBitmap(wxRect(16,0,16,16)));
            }else
                aui_notebook->ChangeSelection(i_index);
        }

        break;
    case ID_PRJ_PO_CONFIRM:
         i_index = aui_notebook->GetPageIndex(panel_po_confirm);
        if(i_index==wxNOT_FOUND)
        {
            panel_po_confirm = new po_confirm_panel(aui_notebook, wxID_ANY);
            aui_notebook->AddPage(panel_po_confirm,_("PO确认"),true,b_bitmap->GetSubBitmap(wxRect(32,0,16,16)));

        }else
            aui_notebook->ChangeSelection(i_index);
        break;
    case ID_INSTANCE_UNIT_INFO:
        i_index = aui_notebook->GetPageIndex(panel_unit_info);
        if(i_index==wxNOT_FOUND)
        {
            panel_unit_info = new instance_unit_info(aui_notebook, wxID_ANY);
 //           panel_unit_info->set_sap_conn(sap_rfc_conn);
            aui_notebook->AddPage(panel_unit_info,_("合同信息"),true,b_bitmap->GetSubBitmap(wxRect(48,0,16,16)));
        }
        else aui_notebook->ChangeSelection(i_index);
        break;
    case ID_INSTANCE_UNIT_AUTHORITY:
        i_index = aui_notebook->GetPageIndex(panel_project_author);
        if(i_index==wxNOT_FOUND)
        {
            panel_project_author = new project_author_panel(aui_notebook,wxID_ANY);
            aui_notebook->AddPage(panel_project_author,_("项目授权"),true,b_bitmap->GetSubBitmap(wxRect(64,0,16,16)));
        }
        else aui_notebook->ChangeSelection(i_index);
        break;
    case ID_INSTANCE_NONSTD_APPLY:
        i_index = aui_notebook->GetPageIndex(panel_nstd_apply);
        if(i_index==wxNOT_FOUND)
        {
            panel_nstd_apply = new nstd_apply_panel(aui_notebook,wxID_ANY);
            aui_notebook->AddPage(panel_nstd_apply,_("配置非标申请"),true,b_bitmap->GetSubBitmap(wxRect(80,0,16,16)));
        }else aui_notebook->ChangeSelection(i_index);
        break;
    case ID_INSTANCE_NONMAT_LIST:
        i_index = aui_notebook->GetPageIndex(panel_nstd_mat_apply);
        if(i_index==wxNOT_FOUND)
        {
            panel_nstd_mat_apply = new nstd_mat_apply(aui_notebook,wxID_ANY);
            aui_notebook->AddPage(panel_nstd_mat_apply ,_("非标处理"),true,b_bitmap->GetSubBitmap(wxRect(112,0,16,16)));
        }else aui_notebook->ChangeSelection(i_index);
        break;
    case ID_INSTANCE_NONSTD_DESIGN:
        i_index = aui_notebook->GetPageIndex(panel_nstd_author);
        if(i_index == wxNOT_FOUND)
        {
            panel_nstd_author = new nstd_author_panel(aui_notebook, wxID_ANY);
            aui_notebook->AddPage(panel_nstd_author, _("非标任务分配"), true, b_bitmap->GetSubBitmap(wxRect(128,0,16,16)));
        }
        else aui_notebook->ChangeSelection(i_index);
        break;
    case ID_WORKFLOW_WF:
        i_index = aui_notebook->GetPageIndex(panel_workflow_wf);
        if(i_index==wxNOT_FOUND)
        {
            panel_workflow_wf = new workflow_wf(aui_notebook, wxID_ANY);
            aui_notebook->AddPage(panel_workflow_wf,_("配置工作流"),true,b_bitmap->GetSubBitmap(wxRect(144,0,16,16)));
        }
        else aui_notebook->ChangeSelection(i_index);
        break;
    case ID_WORKFLOW_NONSTD:
        i_index = aui_notebook->GetPageIndex(panel_nstd_workflow);
        if(i_index==wxNOT_FOUND)
        {
            panel_nstd_workflow = new wf_workflow_panel(aui_notebook, wxID_ANY);
            aui_notebook->AddPage(panel_nstd_workflow, _("非标工作流"), true, b_bitmap->GetSubBitmap(wxRect(160,0,16,16)));
        }
        else aui_notebook->ChangeSelection(i_index);

        break;
    case ID_PRIVATE_TASK:
        i_index = aui_notebook->GetPageIndex(panel_private_tasks);
        if(i_index==wxNOT_FOUND)
        {
            panel_private_tasks = new private_tasks_panel(aui_notebook, wxID_ANY);
            aui_notebook->AddPage(panel_private_tasks, _("日常任务"), true, b_bitmap->GetSubBitmap(wxRect(176,0,16,16)));
        }
        else aui_notebook->ChangeSelection(i_index);
        break;
    case ID_NCR_LIST:
        i_index = aui_notebook->GetPageIndex(panel_ncr_proc);
        if(i_index == wxNOT_FOUND)
        {
            panel_ncr_proc = new ncr_proc_panel(aui_notebook, wxID_ANY);
            aui_notebook->AddPage(panel_ncr_proc, _("NCR处理"), true, b_bitmap->GetSubBitmap(wxRect(192,0,16,16)));
        }else aui_notebook->ChangeSelection(i_index);
        break;
    case ID_GENERATE_ID_COMMON:
        i_index = aui_notebook->GetPageIndex(panel_info_id_generator);
        if(i_index==wxNOT_FOUND)
        {
            panel_info_id_generator = new info_id_generator_panel(aui_notebook, wxID_ANY);
            aui_notebook->AddPage(panel_info_id_generator,_("资料室相关取号"),true, b_bitmap->GetSubBitmap(wxRect(208,0,16,16)));
        }else aui_notebook->ChangeSelection(i_index);
        break;
    case ID_GENERATE_ID_NSTD_CONF:
        i_index = aui_notebook->GetPageIndex(panel_generated_id_display);
        if(i_index==wxNOT_FOUND)
        {
            panel_generated_id_display = new generated_id_display_panel(aui_notebook, wxID_ANY);
            aui_notebook->AddPage(panel_generated_id_display,_("取号预览"),true, b_bitmap->GetSubBitmap(wxRect(224,0,16,16)));
        }else aui_notebook->ChangeSelection(i_index);
        break;
    case ID_GENERATE_ID_NSTD_DESIGN:
          i_index = aui_notebook->GetPageIndex(panel_ndo_generator);
          if(i_index==wxNOT_FOUND)
          {
              panel_ndo_generator = new ndo_generator_panel(aui_notebook, wxID_ANY);
              aui_notebook->AddPage(panel_ndo_generator, _("非标设计指令取号"),true, b_bitmap->GetSubBitmap(wxRect(250,0,16,16)));
          }else aui_notebook->ChangeSelection(i_index);
          break;
    case ID_SETUP_AUTHORITY:
          break;
    case ID_SETUP_DATABASE_CONFIGURE:
        if(para_dlg.ShowModal()==wxID_OK)
        {
            wxLogMessage(_("系统设置更改成功!"));
        }
//        SetToolBoxItemSelected(-1);
        break;
    case ID_SETUP_MAINTAIN_USERS:

        break;
    case ID_INVIDIUAL_LOGIN:
        break;
    case ID_INVIDIUAL_LOGOUT:
        break;
    case ID_INVIDIUAL_REVISE_PWD:
        if(tab_invidal->GetSelItemIndex() ==2)
        {

            pwd_dlg.ShowModal();



        }
        SetToolBoxItemSelected(-1);
        break;
    case ID_INVIDIUAL_INFO:

        break;
    default:
        break;
    }
}

wxArrayString wfFrame::get_wbs_list(int i_choice, wxString str_case)
{
    wxString str_query;

    switch(i_choice)
    {
    case 0:
        str_query = wxT("SELECT * from s_unit_info WHERE wbs_no ILIKE '%")+str_case+wxT("%' ORDER BY wbs_no ASC;");
        break;
    case 1:
        str_query = wxT("SELECT * from v_unit_info WHERE project_id ILIKE '%")+str_case+wxT("%' ORDER BY wbs_no ASC;");
        break;
    case 2:
        str_query = wxT("SELECT * from v_unit_info WHERE contract_id ILIKE '%")+str_case+wxT("%' ORDER BY wbs_no ASC;");
        break;
    case 3:
        str_query = wxT("SELECT * from v_unit_info WHERE project_name ILIKE '%")+str_case+wxT("%' ORDER BY wbs_no ASC;");
        break;
    default:
        break;
    }

    wxArrayString array_result;
    wxPostgreSQLresult *_res;
    if(str_query.IsEmpty())
       return array_result;

     _res = wxGetApp().app_sql_select(str_query);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        return array_result;
    }

    int i_count = _res->GetRowsNumber();
    _res->MoveFirst();
    for(int i=0;i<i_count; i++)
    {
 //       wxString str = _res->GetVal(wxT("wbs_no"));
        array_result.Add(_res->GetVal(wxT("wbs_no")));
        _res->MoveNext();

    }

    _res->Clear();

    return array_result;

}

void wfFrame::SetToolBoxItemSelected(int i_index)
{
    wxToolBoxTab * sel_tab = m_toolbox->GetSelectedTab();

    if(!sel_tab)
        return;

    int i_sel = sel_tab->GetSelItemIndex();

    if(i_sel<0 && i_index<0)
    {
        return;
    }

    if(i_index<0 && i_sel>=0)
    {
        (*sel_tab)[i_sel]->SetSelected(false);
        (*sel_tab)[i_sel]->Invalidate();
        sel_tab->SetSelItemIndex(i_index);
        sel_tab->GetParent()->Refresh();

        return;
    }

    if(i_sel<0 && i_index>=0)
    {
        (*sel_tab)[i_index]->SetSelected(true);
        (*sel_tab)[i_index]->Invalidate();
    }

    if(i_sel != i_index)
    {
        (*sel_tab)[i_sel]->SetSelected(false);
        (*sel_tab)[i_sel]->Invalidate();

        (*sel_tab)[i_index]->SetSelected(true);
        (*sel_tab)[i_index]->Invalidate();
    }

    sel_tab->SetSelItemIndex(i_index);

    sel_tab->GetParent()->Refresh();
}

void wfFrame::OnAuiNotebookPageChanged(wxAuiNotebookEvent& evt)
{
    wxPanel * p_sel = (wxPanel*)aui_notebook->GetPage(evt.GetSelection());
    int i_index = m_toolbox->GetSelectedTab()->GetSelItemIndex();

    if((project_info_panel*)p_sel == panel_project_info)
    {
        tab_review->SetSelected(true);
        i_index=0;
    }

    if((project_review_author_panel*)p_sel == panel_project_review_author ||
       (project_review_panel*)p_sel == panel_project_review)
    {
        tab_review->SetSelected(true);
        i_index = 1;
    }

    if((po_confirm_panel*)p_sel == panel_po_confirm)
    {
        tab_review->SetSelected(true);
        i_index = 2;
    }

    if((instance_unit_info *)p_sel == panel_unit_info)
    {
        tab_instance->SetSelected(true);
 //       tab_instance->SetSelItemIndex(0);
        i_index = 0;

    }

    if((project_info_panel*)p_sel == panel_project_info)
    {
        tab_review->SetSelected(true);
        i_index=0;
    }

    if((project_review_author_panel*)p_sel == panel_project_review_author ||
        (project_review_panel*)p_sel == panel_project_review)
    {
        tab_review->SetSelected(true);
        i_index = 1;
    }

    if((po_confirm_panel*)p_sel == panel_po_confirm)
    {
        tab_review->SetSelected(true);
        i_index = 2;
    }

    if((workflow_wf *)p_sel == panel_workflow_wf)
    {
        tab_workflow->SetSelected(true);
        i_index = 0;
    }

    if((project_author_panel*)p_sel == panel_project_author)
    {
        tab_instance->SetSelected(true);
        i_index = 1;
//        tab_instance->SetSelItemIndex(1);
    }

    if((nstd_apply_panel *)p_sel == panel_nstd_apply)
    {
        tab_instance->SetSelected(true);
        i_index = 2;
    }

    if((nstd_mat_apply *)p_sel == panel_nstd_mat_apply)
    {
        tab_instance->SetSelected(true);
        i_index = 3;
    }

    if((nstd_author_panel *)p_sel == panel_nstd_author)
    {
         tab_instance->SetSelected(true);
         i_index = 4;
    }

    if((wf_workflow_panel*)p_sel == panel_nstd_workflow)
    {
         tab_workflow->SetSelected(true);
         i_index = 1;
    }

    if((private_tasks_panel*)p_sel == panel_private_tasks)
    {
         tab_workflow->SetSelected(true);
         i_index = 2;
    }

    if((ncr_proc_panel*)p_sel == panel_ncr_proc)
    {
         tab_workflow->SetSelected(true);
         i_index=3;
    }

    if((info_id_generator_panel * )p_sel==panel_info_id_generator)
    {
        tab_report->SetSelected(true);
        i_index = 0;
    }

    if((generated_id_display_panel *)p_sel == panel_generated_id_display)
    {
        tab_report->SetSelected(true);
        i_index = 1;
    }

    if((ndo_generator_panel *)p_sel == panel_ndo_generator)
    {
        tab_report->SetSelected(true);
        i_index = 2;
    }

    SetToolBoxItemSelected(i_index);
    evt.Skip();
}

wxToolBox * wfFrame::create_toolbox(wxRect &r_rect)
{
    // add toolbox and initialize the tab in the toolbox
    wxToolBox* tb_toolbox=  new wxToolBox(this, // parent window
                                          ID_TOOL_BOX,    // window ID
                                          wxDefaultPosition,      // position
                                          wxSize(r_rect.width/10,r_rect.height*19/20),        // size
                                          wxNO_BORDER     // style
                                         );
    tb_toolbox->SetShowSelectionAlways(false);
//get imagelist from jpg files.
    tb_toolbox->CreateItemImageList("./res/toolbox48.jpg",48,48,false);
    tb_toolbox->CreateTabImageList("./res/tab16.jpg",16,16,false);

    tab_review = new wxToolBoxTab(_("合同评审"));
    tab_instance = new wxToolBoxTab(_("实例"));
    tab_workflow = new wxToolBoxTab(_("工作流"));
    tab_report = new wxToolBoxTab(_("取号器"));
    tab_setup = new wxToolBoxTab(_("软件设置"));
    tab_invidal = new wxToolBoxTab(_("个性化"));

    tb_toolbox->AddTab(tab_review);
    tab_review->SetImageIndex(0);
    tb_toolbox->AddTab(tab_instance);
    tab_instance->SetImageIndex(1);
    tb_toolbox->AddTab(tab_workflow);
    tab_workflow->SetImageIndex(2);
    tb_toolbox->AddTab(tab_report);
    tab_report->SetImageIndex(3);
    tb_toolbox->AddTab(tab_setup);
    tab_setup->SetImageIndex(4);
    tb_toolbox->AddTab(tab_invidal);
    tab_invidal->SetImageIndex(5);


//    tab_workflow->SetSelected(true);

    tb_toolbox->SetItemsTransparent(true);
    tb_toolbox->SetSelectedItemTransparent(false);
    tb_toolbox->SetTabHeight(22);
    tb_toolbox->SetItemHeight(70);
    tb_toolbox->SetItemSpacing(2);
    tb_toolbox->SetTabSpacing(0);
//    tb_toolbox->SetBackgroundColour(wxColour(35, 42, 68));

    tb_toolbox->SetItemNormalColour(wxColour(35, 42, 68));
    tb_toolbox->SetItemHoverColour(wxColour(79, 95, 121));
    tb_toolbox->SetItemSelectedColour(wxColour(146, 151, 164));
    tb_toolbox->SetTabNormalColour(wxColour(170, 170, 170));
    tb_toolbox->SetTabSelectedColour(wxColour(236, 233, 216));
    tb_toolbox->SetButtonNormalColour(wxColour(170, 170, 170));

    tb_toolbox->SetItemTextColour(*wxBLACK);

    wxFont font(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Courier New"));
    tb_toolbox->SetItemNormalFont(font);
    tb_toolbox->SetItemHoverFont(font);
    font.SetWeight(wxFONTWEIGHT_BOLD);
    tb_toolbox->SetItemHoverFont(font);
    tb_toolbox->SetStyle(wxTB_STYLE_THUMBNAILS);


//add items in toolbox
    wxToolBoxItem tb_item;
    wxWindowID i_id;
    for (int i=0; i<21; i++)
    {
        i_id = ID_PRJ_REVIEW_INFO+i;
        tb_item.SetID(i_id);
        tb_item.SetImageIndex(i);
        switch(i_id)
        {
        case ID_PRJ_REVIEW_INFO:
            tb_item.SetCaption(_("合同信息"));
            tab_review->AddItem(tb_item);
            break;
        case ID_PRJ_REVIEW_PROC:
            tb_item.SetCaption(_("合同评审"));
            tab_review->AddItem(tb_item);
            break;
        case ID_PRJ_PO_CONFIRM:
            tb_item.SetCaption(_("PO确认"));
            tab_review->AddItem(tb_item);
            break;
        case ID_INSTANCE_UNIT_INFO:
            tb_item.SetCaption(_("项目信息"));
            tab_instance->AddItem(tb_item);
            break;
        case ID_INSTANCE_UNIT_AUTHORITY:
            tb_item.SetCaption(_("项目授权"));
            tab_instance->AddItem(tb_item);
            break;
        case ID_INSTANCE_NONSTD_APPLY:
            tb_item.SetCaption(_("配置非标申请"));
            tab_instance->AddItem(tb_item);
            break;
        case ID_INSTANCE_NONMAT_LIST:
            tb_item.SetCaption(_("非标处理"));
            tab_instance->AddItem(tb_item);
            break;
        case ID_INSTANCE_NONSTD_DESIGN:
            tb_item.SetCaption(_("非标任务分配"));
            tab_instance->AddItem(tb_item);
            break;
        case ID_WORKFLOW_WF:
            tb_item.SetCaption(_("配置工作流"));
            tab_workflow->AddItem(tb_item);
            break;

        case ID_WORKFLOW_NONSTD:
            tb_item.SetCaption(_("非标工作流"));
            tab_workflow->AddItem(tb_item);
            break;
        case ID_PRIVATE_TASK:
            tb_item.SetCaption(_("日常任务"));
            tab_workflow->AddItem(tb_item);
            break;
        case ID_NCR_LIST:
            tb_item.SetCaption(_("NCR处理"));
            tab_workflow->AddItem(tb_item);
            break;
        case ID_GENERATE_ID_COMMON:
            tb_item.SetCaption(_("资料室相关取号"));
            tab_report->AddItem(tb_item);
            break;
        case ID_GENERATE_ID_NSTD_CONF:
            tb_item.SetCaption(_("取号预览"));
            tab_report->AddItem(tb_item);
            break;
        case ID_GENERATE_ID_NSTD_DESIGN:
            tb_item.SetCaption(_("非标设计指令取号"));
            tab_report->AddItem(tb_item);
            break;
        case ID_SETUP_AUTHORITY:
            tb_item.SetCaption(_("权限分配"));
            tab_setup->AddItem(tb_item);
            break;
        case ID_SETUP_DATABASE_CONFIGURE:
            tb_item.SetCaption(_("数据库设置"));
            tab_setup->AddItem(tb_item);
            break;
        case ID_SETUP_MAINTAIN_USERS:
            tb_item.SetCaption(_("用户维护"));
            tab_setup->AddItem(tb_item);
            break;
        case ID_INVIDIUAL_LOGIN:
            tb_item.SetCaption(_("登陆"));
            tab_invidal->AddItem(tb_item);
            break;
        case ID_INVIDIUAL_LOGOUT:
            tb_item.SetCaption(_("注销"));
            tab_invidal->AddItem(tb_item);
            break;
        case ID_INVIDIUAL_REVISE_PWD:
            tb_item.SetCaption(_("密码修改"));
            tab_invidal->AddItem(tb_item);
            break;
        case ID_INVIDIUAL_INFO:
            tb_item.SetCaption(_("info"));
            tab_invidal->AddItem(tb_item);
            break;
        default:
            break;
        }
    }



    return tb_toolbox;
//set workflow item open when software is opened initially.
//    tab_workflow->SetSelected(true);
//    tab_workflow->SetSelItemIndex(1);

}

void wfFrame::OnLogout()
{

}

void wfFrame::OnThreadTimer(wxTimerEvent& event)
{
    if(!gr_para.login_status)
    {
        return;
    }
    if( !wxGetApp().conn->IsAlive())
    {
        if(!wxGetApp().conn->Reconnect())
            return;
    }

    wxArrayString array_dif,array2;

 //   tray->ShowBalloon(_("任务清单"), _("test"), 800000);

    array2 = Get_task_list(m_str_query);

    if(m_old_array == array2)
    {
        array2.Empty();
        return;
    }

    array_dif = Compare_Array(m_old_array, array2);
 //   tray->display_message(_("任务清单"), _("test"), 800000);
    if(!array_dif.IsEmpty())
    {
        int i_count = array_dif.GetCount();
        wxString str;

        str= wxT("新增:")+NumToStr(i_count)+wxT("个任务");
        for(int i= 0; i<i_count; i++)
        {
            str = str+wxT("\n")+array_dif.Item(i);
        }

 //       tray->display_message(_("任务清单"), str, 600000);
           tray->ShowBalloon(_("任务清单"), str, 15000);
           Refresh_List();

    }

    array_dif.Clear();
    m_old_array.Clear();
    m_old_array = array2;
    array2.Clear();

}

wxArrayString wfFrame::Compare_Array(wxArrayString &array1, wxArrayString & array2)
{
    wxArrayString array_result;
    bool b_true;

    int i_count1 = array1.GetCount();
    int i_count2 = array2.GetCount();

    for(int i=0;i<i_count2;i++)
    {
        if(array1.IsEmpty())
            return array2;

        b_true = false;
        for(int j=0;j<i_count1;j++)
        {
            if(array2.Item(i)== array1.Item(j))
            {
                b_true = true;
                break;
            }

        }
        if(!b_true)
            array_result.Add(array2.Item(i));
    }

    return array_result;
}


wxArrayString wfFrame::Get_task_list(wxString str_query)
{

    wxPostgreSQLresult* _res;
    wxArrayString array_result;
    if(!gr_para.login_status)
    {
        return array_result;
    }

    _res = wxGetApp().app_sql_select(str_query);


    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        return array_result;
    }

    int irows = _res->GetRowsNumber();

    array_result.Empty();
    _res->MoveFirst();
    for(int i=0;i<irows;i++)
    {
       wxString str = _res->GetVal(wxT("instance_id"));
       array_result.Add(str);
       _res->MoveNext();
    }

    _res->Clear();
    return array_result;

}


void wfFrame::Refresh_List()
{
    if(wxGetApp().conn->IsAlive())
        return;

    wxPanel * p_sel = (wxPanel*)aui_notebook->GetCurrentPage();
    if((workflow_wf *)p_sel == panel_workflow_wf)
    {
 //       wxGridEvent evt;
 //       wxGetApp().AddPendingEvent(evt);
 //       panel_workflow_wf->set_show(true);
        panel_workflow_wf->refresh_list();
    }
/*
    if((instance_unit_info *)p_sel == panel_unit_info)
    {d
//        wxGridEvent evt;
 //       wxGetApp().AddPendingEvent(evt);
 //       panel_unit_info->b_refresh = true;
        panel_unit_info->refresh_list();
 //       panel_unit_info->b_refresh= false;
    }
*/
    if((project_author_panel *)p_sel == panel_project_author)
    {
//        wxNotifyEvent evt(wxNewEventType(), ID_TREELIST_CTRL);
 //       wxGetApp().AddPendingEvent(evt);
  //      panel_project_author->b_case= true;

        if(panel_project_author->m_case!=0)
        {

           panel_project_author->m_case=0 ;
           wxLogMessage(_("没有任何操作，系统自动切换显示未分配项目!"));
           if(!panel_project_author->MenuItem3->IsChecked())
              panel_project_author->MenuItem3->Check(true);

           if(panel_project_author->MenuItem4->IsChecked())
              panel_project_author->MenuItem4->Check(false);

            wxString strSql = wxT("SELECT  concat(contract_id,' ', project_name) as project_name, project_id,\
                         instance_id as wbs_no, lift_no, elevator_type, project_catalog, req_configure_finish, \
                         (SELECT concat(employee_id,'-',name) from s_employee WHERE employee_id = operator_id) as operator, status, is_urgent from v_task_list1 WHERE action_id = 'AT00000003' \
                         AND is_active = true AND operator_id = '")+gr_para.login_user+ wxT("' ORDER BY req_configure_finish,instance_id,elevator_type ASC ;");
             panel_project_author->Set_Clause(strSql);

        }

        panel_project_author->refresh_list();
    }


}
/*
void MyTaskBarIcon::display_message(wxString str_title,wxString str_message, long i_timer)
{
    TaskBarBaloon *tbb=new TaskBarBaloon(str_title, str_message);
    tbb->showBaloon(i_timer);
}
*/
/*
bool wfFrame::init_select_case()
{
    search_case tdlg;
    tdlg.set_wbs_check(true);
    array_thread_wbs.Clear();

    if(tdlg.ShowModal()==wxID_OK)
    {
        array_thread_wbs = tdlg.GetValue();

    }else
       return false;

    if(array_thread_wbs.IsEmpty())
        return false;

    return true;
}
*/

bool wfFrame::update_project_from_sap(wxArrayString&array_thread_wbs, Value_Pool * pool_basic, Value_Pool* pool_para, int i_way)
{

     int i_count = array_thread_wbs.GetCount();
    if(pool_basic->GetNumOfRows()==0)
    {
        wxLogMessage(_("SAP系统内无相关资料."));

        return false;

    }

    wxString s_wbs, s_project;
    Str_Line* line_header;

    line_header = pool_basic->Get_Name();

/*
    int i_cols = line_header->num_cols;
    wxString str;
    for(int k=0;k<i_cols;k++)
    {
        str=str+line_header->cols[k]+wxT("\n");

    }
//测试
    wxMessageBox(str,_(""));*/

    for(int j=0;j<i_count;j++)
    {
         s_wbs = array_thread_wbs.Item(j);

         if(s_wbs.Left(1).Upper()!=wxT("E"))
         {
            continue;
        }

         int i_col = pool_basic->find_col_name(wxT("POSID"));


         int i_row_pos = pool_basic->Find_row_value(wbstosapformat(s_wbs),i_col);

         if(i_row_pos==-1)
         {
             wxLogMessage(_("SAP系统中无此WBS相关信息:")+s_wbs);
             continue;
         }

        Str_Line * line = pool_basic->Get_Value(i_row_pos);

        if(update_project_unit_info(s_wbs,line, line_header,i_way))
        {

            wxLogMessage(s_wbs+_("更新表头和unit信息成功!"));
            Value_Pool * pool_wbs_para = get_same_value_pool(s_wbs,0, pool_para);
            if(!pool_wbs_para)
            {
                 wxLogMessage(_("SAP系统中无此WBS参数信息:")+s_wbs);
                 continue;
            }

            if(update_project_parameter(s_wbs, pool_wbs_para))
            {
                wxLogMessage(s_wbs+_("更新参数信息成功!"));
            }else
            {
                wxLogMessage(s_wbs+_("更新参数信息失败!"));
                return false;
            }
/*
            if(update_prj_para_fields(s_wbs, pool_wbs_para))
            {
                wxLogMessage(s_wbs+_("同步参数表成功!"));
            }
            else
            {
                wxLogMessage(s_wbs+_("同步参数表失败!"));
                return false;
            }*/

            if(pool_wbs_para)
                delete pool_wbs_para;

            pool_wbs_para=NULL;

            wxLogMessage(_("项目信息更新完成:")+s_wbs);
        }

    }

    return true;

}


Value_Pool * wfFrame::get_same_value_pool(wxString str, int i_col, Value_Pool* p_result)
{
    wxString s_wbs=wbstosapformat(str);

    if(p_result==NULL)
        return NULL;

    int i_row = p_result->Get_Same_Count(s_wbs, i_col);

    int i_count = p_result->GetNumOfRows();

    if(i_row==0)
        return NULL;

    Value_Pool * p_value = new Value_Pool(i_row);
    Str_Line * line;
    Str_Line * line_value;

    int j=0;
    for(int i=0;i<i_count;i++)
    {
        line = p_result->Get_Value(i);
        if(line->cols[i_col]==s_wbs)
        {
            line_value = p_value->Get_Value(j);

            int i_value_col = line->num_cols;
            line_value->cols = new wxString[i_value_col];
            line_value->num_cols = i_value_col;
            for(int k=0;k<i_value_col;k++)
            {
                line_value->cols[k]= line->cols[k];
            }

            j++;
        }

    }

    return p_value;
}

bool wfFrame::update_project_unit_info(wxString str, Str_Line* line_value, Str_Line* line_header, int i_way)
{
    int i_pos = str.Find(wxT("."));
    wxString s_project_id = str.Left(i_pos);
    wxString str_sql = wxT("SELECT * FROM s_project_info WHERE project_id = '") + s_project_id + wxT("';");

    wxString s_status;
    s_status = NumToStr(i_way);

    wxString s_project_name = get_value_from_line(wxT("POST1"),line_value,line_header).Trim();

    if (!wxGetApp().is_have(str_sql))
    {
        str_sql = wxT("INSERT INTO s_project_info (project_id, project_name, plant, branch_name, modify_date, modify_emp_id, create_date, create_emp_id, branch_id) VALUES ('") +
        s_project_id + wxT("','") + get_value_from_line(wxT("POST1"),line_value,line_header).Trim() + wxT("','") +
        gr_para.plant + wxT("','") +get_value_from_line(wxT("NAME1"),line_value,line_header).Trim()+ wxT("','") +
        DateToAnsiStr(wxDateTime::Now()) + wxT("','") +
        gr_para.login_user + wxT("','") + DateToAnsiStr(wxDateTime::Now()) + wxT("','") +
        gr_para.login_user+ wxT("','")+sapmatconvert(get_value_from_line(wxT("KUNNR"),line_value,line_header).Trim())+wxT("');");
        str_sql.Replace(wxT("''"), wxT("NULL"));
    }else
    {
        if(s_project_name.IsEmpty()|| s_project_name==wxT("error"))
                str_sql = wxT("UPDATE s_project_info SET  plant='")+gr_para.plant+wxT("', branch_name='")+get_value_from_line(wxT("NAME1"),line_value,line_header).Trim()+wxT("', \
                modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("', branch_id='")+
                sapmatconvert(get_value_from_line(wxT("KUNNR"),line_value,line_header).Trim())+wxT("' WHERE project_id = '")+s_project_id+wxT("';");

        else
        str_sql = wxT("UPDATE s_project_info SET project_name='")+get_value_from_line(wxT("POST1"),line_value,line_header).Trim()+wxT("', \
                 plant='")+gr_para.plant+wxT("', branch_name='")+get_value_from_line(wxT("NAME1"),line_value,line_header).Trim()+wxT("', \
                modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("', branch_id='")+
                sapmatconvert(get_value_from_line(wxT("KUNNR"),line_value,line_header).Trim())+wxT("' WHERE project_id = '")+s_project_id+wxT("';");

        str_sql.Replace(wxT("''"), wxT("NULL"));


    }

    if(wxGetApp().app_sql_update(str_sql))
    {
        wxLogMessage(s_project_id+_("项目信息更新成功"));
    }else
    {
         wxLogMessage(s_project_id+_("项目信息更新失败"));
        return false;
    }

    str_sql = wxT("SELECT * FROM s_unit_info WHERE wbs_no = '") + str + wxT("'");

    wxString s_req_delivery_date = get_value_from_line(wxT("PURFIND1"),line_value,line_header).Trim();

    if(!s_req_delivery_date.IsEmpty())
        s_req_delivery_date = sapdatetimeconvert(s_req_delivery_date);

    wxString s_req_configure_finish = get_value_from_line(wxT("CONFFINPD"),line_value,line_header).Trim();
    if(!s_req_configure_finish.IsEmpty())
        s_req_configure_finish = sapdatetimeconvert(s_req_configure_finish);

    int i_prj_catalog = prj_catalog_convert_sap(get_value_from_line(wxT("Z_AP_PROJCLAS"),line_value,line_header).Trim());
    int i_nstd_level = nstd_level_convert_sap(get_value_from_line(wxT("VKAUS"),line_value,line_header).Trim());

     wxString s_mat = get_value_from_line(wxT("MATNR"),line_value,line_header).Trim();
    if (!wxGetApp().is_have(str_sql))
    {
        str_sql = wxT("INSERT INTO s_unit_info ( wbs_no, project_id, elevator_id, lift_no, status,  req_delivery_date, req_configure_finish,project_catalog, nonstd_level, modify_date, modify_emp_id, create_date, create_emp_id) VALUES ('") +
        str + wxT("','") +s_project_id + wxT("','") +sapmatconvert(s_mat)+wxT("','") +
        get_value_from_line(wxT("USR01"),line_value,line_header).Trim() + wxT("',") + s_status + wxT(",'") +
        s_req_delivery_date + wxT("','") + s_req_configure_finish + wxT("',") +
        NumToStr(i_prj_catalog)+ wxT(",") + NumToStr(i_nstd_level)+ wxT(",'") +
        DateToAnsiStr(wxDateTime::Now()) + wxT("','") +
        gr_para.login_user + wxT("','") + DateToAnsiStr(wxDateTime::Now()) + wxT("','") +
        gr_para.login_user +wxT("' );");

        str_sql.Replace(wxT("''"), wxT("NULL"));

    }else
    {
        str_sql= wxT("UPDATE s_unit_info SET elevator_id = '")+sapmatconvert(s_mat)+
        wxT("',lift_no = '")+get_value_from_line(wxT("USR01"),line_value,line_header).Trim()+
        wxT("',req_delivery_date = '")+s_req_delivery_date+
        wxT("',req_configure_finish = '")+s_req_configure_finish+
        wxT("',project_catalog = ")+NumToStr(i_prj_catalog)+
        wxT(",nonstd_level = ")+NumToStr(i_nstd_level)+
        wxT(",modify_date = '")+DateToAnsiStr(wxDateTime::Now()) +
        wxT("',modify_emp_id = '")+gr_para.login_user+wxT("' WHERE wbs_no ='")+str+wxT("';");
        str_sql.Replace(wxT("''"), wxT("NULL"));


    }

 //   wxMessageBox(str_sql);
    if(wxGetApp().app_sql_update(str_sql))
    {
        wxLogMessage(str+_("Unit信息更新成功!"));
    }else
    {
        wxLogMessage(str+_("Unit信息更新失败!"));
        return false;
    }

    return true;

}

bool wfFrame::update_project_parameter(wxString str, Value_Pool* p_value)
{
     wxString str_sql = wxT("select * from s_unit_parameter where wbs_no='")+str+wxT("';");
     wxString s_project_id;
     int i_pos  = str.Find(wxT("."));
     s_project_id = str.Left(i_pos);


     wxString s_load = sapnumconvert(get_value_from_pool(1, 4, wxT("TC002"),p_value));
     wxString s_speed = sapnumconvert(get_value_from_pool(1, 4, wxT("TC003"), p_value));
     wxString s_control_sys = get_value_from_pool(1, 4, wxT("MF003"),p_value);
     wxString s_car_width = sapnumconvert(get_value_from_pool(1, 4, wxT("TC016"),p_value));
     wxString s_car_depth = sapnumconvert(get_value_from_pool(1, 4, wxT("TC017"),p_value));
     wxString s_car_height = sapnumconvert(get_value_from_pool(1, 4, wxT("TC018"), p_value));
     wxString s_open_type = get_value_from_pool(1, 4, wxT("TC036"), p_value);
     wxString s_car_door_type = get_value_from_pool(1, 4, wxT("TC035"), p_value);
     wxString s_landing_door_type = get_value_from_pool(1,4, wxT("TC041"), p_value);
     bool b_is_through = StrToBool(get_value_from_pool(1,4, wxT("TC019"), p_value));
     wxString s_door_width = sapnumconvert(get_value_from_pool(1,4, wxT("TC037"),p_value));
     wxString s_door_height = sapnumconvert(get_value_from_pool(1,4, wxT("TC038"), p_value));
     wxString s_travel_height = sapnumconvert(get_value_from_pool(1,4, wxT("TC004"),p_value));
     wxString s_floors =  sapnumconvert(get_value_from_pool(1,4, wxT("TC006"), p_value));
     wxString s_stops = sapnumconvert(get_value_from_pool(1,4, wxT("TC005"), p_value));

    if(!wxGetApp().is_have(str_sql))
    {
        str_sql =  wxT("INSERT INTO s_unit_parameter(\
                   wbs_no, project_id, load, speed, control_sys, car_width, car_depth, \
                   car_height, open_type, car_door_type, landing_door_type, is_through, \
                   door_width, door_height, travel_height, floors, stops,  \
                    modify_date, modify_emp_id, create_date, create_emp_id)\
                    VALUES ('") + str + wxT("','") +s_project_id + wxT("','") + s_load + wxT("','") +
        s_speed + wxT("','") + s_control_sys + wxT("','") +s_car_width+ wxT("','") + s_car_depth+ wxT("','") +
        s_car_height+ wxT("','") + s_open_type+ wxT("','") +
        s_car_door_type+ wxT("','") + s_landing_door_type+ wxT("','") +
        BoolToStr(b_is_through) + wxT("','") + s_door_width + wxT("','") +
        s_door_height+ wxT("','") + s_travel_height+ wxT("','") +
        s_floors + wxT("','") + s_stops+ wxT("','") +
        DateToAnsiStr(wxDateTime::Now())  + wxT("','") + gr_para.login_user + wxT("','") + DateToAnsiStr(wxDateTime::Now()) + wxT("','") +
        gr_para.login_user + wxT("' )");
        str_sql.Replace(wxT("''"), wxT("NULL"));

    }
    else
    {
        str_sql= wxT("UPDATE s_unit_parameter SET load='")+s_load+wxT("',speed = '")+
        s_speed+wxT("',control_sys='")+s_control_sys+wxT("',car_width='")+
        s_car_width+wxT("',car_depth='")+ s_car_depth+wxT("',car_height='")+
        s_car_height+wxT("',open_type='")+ s_open_type+wxT("',car_door_type='")+
        s_car_door_type+wxT("',is_through='")+BoolToStr(b_is_through)+wxT("',door_width='")+s_door_width+wxT("',door_height='")+
        s_door_height+wxT("',travel_height='")+s_travel_height+wxT("',floors='")+
        s_floors+wxT("', stops='")+s_stops+
        wxT("',modify_date = '")+DateToAnsiStr(wxDateTime::Now()) +
        wxT("',modify_emp_id = '")+gr_para.login_user+wxT("' WHERE wbs_no ='")+
        str+wxT("';");
        str_sql.Replace(wxT("''"), wxT("NULL"));
    }

 //   wxMessageBox(str_sql);

    if(!wxGetApp().app_sql_update(str_sql))
            return false;

    return true;
}

bool wfFrame::update_prj_para_fields(wxString str, Value_Pool* p_value)
{
    wxString str_sql = wxT("select * from s_unit_para_fields where wbs_no='")+str+wxT("';");

    int i_rows = p_value->GetNumOfRows();

    if(i_rows==0)
        return false;

    Str_Line * line;

    if(!wxGetApp().is_have(str_sql))
    {
        str_sql = wxT("INSERT INTO s_unit_para_fields( wbs_no, field_name, field_value, modify_date, modify_emp_id, create_date, create_emp_id) VALUES ");
        for(int i=0;i<i_rows;i++)
        {
            line = p_value->Get_Value(i);
            if(i==i_rows-1)
            {
                str_sql = str_sql+wxT("('")+str+wxT("','")+line->cols[1]+wxT("','")+line->cols[4]+wxT("','")+DateToAnsiStr(wxDateTime::Now())  + wxT("','") + gr_para.login_user + wxT("','") +
                DateToAnsiStr(wxDateTime::Now()) + wxT("','") +gr_para.login_user + wxT("' );");
            }else
            {
                 str_sql = str_sql+wxT("('")+str+wxT("','")+line->cols[1]+wxT("','")+line->cols[4]+wxT("','")+DateToAnsiStr(wxDateTime::Now())  + wxT("','") + gr_para.login_user + wxT("','") +
                DateToAnsiStr(wxDateTime::Now()) + wxT("','") +gr_para.login_user + wxT("' ),");
            }
        }

        str_sql.Replace(wxT("''"), wxT("NULL"));



    }else
    {

          for(int j=0;j<i_rows;j++)
          {
               line = p_value->Get_Value(j);

               if(j==i_rows-1)
               {
                str_sql = wxT("UPDATE s_unit_para_fields SET field_value='")+line->cols[4]+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user +
                wxT("' WHERE wbs_no='")+str+wxT("' and field_name='")+line->cols[2]+wxT("';");
               }else
               {
                str_sql = wxT("UPDATE s_unit_para_fields SET field_value='")+line->cols[4]+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user +
               wxT("' WHERE wbs_no='")+str+wxT("' and field_name='")+line->cols[2]+wxT("'; \n");

               }

          }
    }

        if(wxGetApp().app_sql_update(str_sql))
        {
            wxLogMessage(str+_("同步参数列表成功"));
        }else
        {
            wxLogMessage(str+_("同步参数列表失败"));
            return false;
        }


    return true;

}

wxString wfFrame::get_value_from_pool(int i_case_col, int i_result_col, wxString str, Value_Pool* p_pool)
{
    int i_rows = p_pool->GetNumOfRows();

    wxString s_result;

    Str_Line* line;

    for(int i=0;i<i_rows;i++)
    {
         line=p_pool->Get_Value(i);

         if(line->cols[i_case_col]==str)
             return line->cols[i_result_col];

    }

    return wxEmptyString;
}

int wfFrame::prj_catalog_convert_sap(wxString sap_str)
{
     if(sap_str.IsEmpty())
          return 1;

     int i_sap = wxAtoi(sap_str);

     switch(i_sap)
     {
     case 1:
        return 4;
     case 2:
        return 1;
     case 3:
        return 3;
     case 4:
        return 5;
     case 5:
        return 6;
     case 6:
        return 2;
     default:
        return 1;
     }

}

int wfFrame::nstd_level_convert_sap(wxString sap_str)
{
     if(sap_str.IsEmpty())
        return 3;

     if(sap_str==wxT("YA1")) // Target STD
         return 1;
     if(sap_str==wxT("YA2")) //Option STD
         return 2;
     if(sap_str==wxT("YA3")) //Simple Non-STD
         return 3;
     if(sap_str==wxT("YA4")) //Complex Non-STD
         return 4;
     if(sap_str==wxT("YA5")) //Comp-Standard
        return 5;
     if(sap_str==wxT("YA6"))//Comp-Measurement
        return 6;
     if(sap_str==wxT("YA7")) //Comp-Configurable
        return 7;
     if(sap_str==wxT("RA1"))//Design Fault-Qty
       return 11;
     if(sap_str==wxT("RA2"))//Design Fault-Spec  12
        return 12;
     if(sap_str==wxT("RA3"))//Sales Order Fault-Qt 13
        return 13;
     if(sap_str==wxT("RA4"))//Sales Order Fault-Sp 14
        return 14;
     if(sap_str==wxT("RA5"))//Matl Pick Fault-Qty 15
        return 15;
     if(sap_str==wxT("RA6"))//Matl Pick Fault-Spec 16
        return 16;
     if(sap_str==wxT("RA7"))//Packing Fault-Qty 17
        return 17;
     if(sap_str==wxT("RA8"))//Packing Fault-Spec 18
        return 18;
     if(sap_str==wxT("RA9"))//Logistic Fault 19
        return 19;
     if(sap_str==wxT("RB1"))//Abnormal in logistic
        return 21;
     if(sap_str ==wxT("RB2"))//TI or ECR 22
        return 22;
     if(sap_str==wxT("RB3")) //Others 23
        return 23;
}

wxString wfFrame::get_value_from_line(wxString s_header, Str_Line* line_value, Str_Line* line_header)
{
    int i_cols = line_header->num_cols;
    int i_pos=-1;

    for(int i=0;i<i_cols;i++)
    {
        if(line_header->cols[i]==s_header)
        {
            i_pos = i;
        }
    }

    wxString str;
    if(i_pos==-1)
        return wxEmptyString;

    str = line_value->cols[i_pos];

    return str;


}

wxArrayString wfFrame::get_traction_string(int i_cat)
{
    wxArrayString a_list;

    wxString s_sql = wxT("select traction_name from s_traction_spring_info where catagory =")+NumToStr(i_cat)+wxT(";");
    wxPostgreSQLresult *res = wxGetApp().app_sql_select(s_sql);
    if(res->Status()!= PGRES_TUPLES_OK)
    {
        res->Clear();
        return a_list;
    }

    wxString str;

    int i_count = res->GetRowsNumber();

    for(int i=0;i<i_count;i++)
    {
        str = res->GetVal(wxT("traction_name"));
        a_list.Add(str);
        res->MoveNext();
    }
    res->Clear();
    return a_list;
}

bool wfFrame::check_traction_spring(wxArrayInt a_index, wxArrayString a_trac, Value_Pool* p_value, int i_name_col, int i_remarks_col)
{
    int x_count = a_index.GetCount();
    int y_count = a_trac.GetCount();
    if(x_count==0)
    {
        wxLogMessage(_("wbs bom缺少曳引机，请核查BOM"));
    }else
    {
        for(int x=0; x<x_count;x++)
        {
            Str_Line * line = p_value->Get_Value(a_index.Item(x));

            for(int y=0;y<y_count;y++)
            {
                wxString str = a_trac.Item(y).Lower();
                wxString s_name=line->cols[i_name_col];
                wxString s_remarks= line->cols[i_remarks_col];

                if(s_name.Contains("箱") || s_name.Lower().Contains("box"))
                      continue;

                if(s_name.Lower().Contains(str) || s_remarks.Lower().Contains(str))
                    return false;

            }
        }
    }

    return true;

}

bool wfFrame::Cal_prj_basic_info(wxString s_wbs, Value_Pool* p_value, wxArraySupport& array_support)
{
    s_basic_info  value_basic_info;
    wxArraySupport array_sel_support;

    bool b_full_basic=true;
    int i_dc_weight = get_dc_weight(s_wbs);

    if(i_dc_weight<0)
        b_full_basic= false;

    wxLogMessage(_("计算对重框架重量...-")+s_wbs);
    array_sel_support = get_same_act_arry(array_support, wxT("0360"));

    int i_rows = p_value->GetNumOfRows();

    int i_count = array_sel_support.GetCount();
    int i_pos;

    wxString str;
/*
    Str_Line * l_name = p_value->Get_Name();

    int i_name = l_name->num_cols;

    for(int f=0;f<i_name;f++)
    {
        str= str+l_name->cols[f]+wxT(";");
    }

    wxMessageBox(str);*/
    int i_mat_col = p_value->find_col_name(wxT("MATNR_I"));
    int i_act_col = p_value->find_col_name(wxT("VORNR"));
    int i_qty_col = p_value->find_col_name(wxT("NOMNG"));
    int i_name_col = p_value->find_col_name(wxT("MAKTX_ZH"));
    int i_remarks_col = p_value->find_col_name(wxT("POTX1"));

    //wxMessageBox(NumToStr(i_mat_col)+wxT(";")+NumToStr(i_act_col)+wxT(";")+NumToStr(i_qty_col)+wxT(";")+NumToStr(i_name_col));
    wxArrayInt array_index = p_value->find_row_value_array(wxT("0010"),i_act_col);
    wxArrayString a_traction=get_traction_string(1);

    value_basic_info.b_has_spring = check_traction_spring(array_index, a_traction, p_value, i_name_col, i_remarks_col);
    a_traction.Clear();
    array_index.Clear();

    array_index = p_value->find_row_value_array(wxT("0360"),i_act_col);

    if(!array_index.IsEmpty())
         str  = find_str_in_wbs_bom(i_mat_col,i_qty_col, array_index, p_value, array_sel_support);
    else
    {
        b_full_basic = false;
        wxLogMessage(_("WBS bom缺少对重框架，请核查BOM"));
        str = wxT("0");
    }


    if(str.IsEmpty())
    {
        b_full_basic = false;
        value_basic_info.s_cwt_weight = wxT("0");
        wxLogMessage(_("请联系管理员将此项目")+s_wbs+wxT("的对重框架的重量信息添加到数据库!"));
    }else
    {
        i_pos = str.Find(wxT("."));
        if(i_pos!=wxNOT_FOUND)
           str = str.Left(i_pos);
        value_basic_info.s_cwt_weight =  str;
    }

    array_sel_support.Clear();
    array_index.Clear();

    Str_Line * line;

    wxLogMessage(_("查找平衡块数量...-")+s_wbs);

    int i_find_index = p_value->Find_row_value(wxT("0440"),i_act_col);

    if(i_find_index<0)
    {
        wxLogMessage(s_wbs+_("此项目未配置平衡块!"));
        value_basic_info.s_balance_block_qty = wxT("0");
    }else
    {
        line = p_value->Get_Value(i_find_index);
        value_basic_info.s_balance_block_qty = p_value->get_value_by_index(i_qty_col, line);
        line = NULL;
    }

    wxLogMessage(_("查找对重块数量...-")+s_wbs);
 //   wxLogMessage(_("装潢后"));


    array_sel_support = get_same_act_arry(array_support,wxT("0760"));
    array_index = p_value->find_row_value_array(wxT("0760"),i_act_col);

    wxArrayBlocks st_blocks = get_cwt_blocks_info(i_mat_col,i_qty_col,array_index, p_value, array_sel_support);

    int i_qty_mat1, i_qty_mat2, i_block_dc_after, i_block_dc_before;
    i_qty_mat1=i_qty_mat2=i_block_dc_after=i_block_dc_before = 0;

    double d_weight=0.0;
    double d_temp;
    if(st_blocks.IsEmpty())
    {
        wxLogMessage(s_wbs+_("请尽快将项目的对重块信息提供给管理员，更新信息库!"));

        value_basic_info.s_block_material1=wxT("0");
        value_basic_info.s_block_material2= wxT("0");
        value_basic_info.s_cwt_block_qty_dc_after=wxT("0");
        value_basic_info.s_cwt_block_qty_dc_before=wxT("0");
        b_full_basic = false;
    }else
    {
        int i_blocks =st_blocks.GetCount();

        for(int i=0;i<i_blocks;i++)
        {
            str= st_blocks.Item(i).s_para1;
            d_temp = wxAtof(st_blocks.Item(i).s_weight);
                if(d_weight < d_temp)
                    d_weight = d_temp;

             if(str == wxT("CM"))
             {
                 i_qty_mat2 = i_qty_mat2+wxAtoi(st_blocks.Item(i).s_qty);


             }else if(str == wxT("CI"))
             {
                 i_qty_mat1 = i_qty_mat1 +wxAtoi(st_blocks.Item(i).s_qty);
             }else
             {
                 i_qty_mat2 = i_qty_mat2+wxAtoi(st_blocks.Item(i).s_qty);
             }

         }

         i_block_dc_after = i_qty_mat1 + i_qty_mat2;

         i_block_dc_before = wxAtoi(NumToStr(i_block_dc_after-i_dc_weight/d_weight));
    }

    array_sel_support.Clear();
    array_index.Clear();
    st_blocks.Clear();

    value_basic_info.s_wbs = s_wbs;

    value_basic_info.s_block_material1 = NumToStr(i_qty_mat1);
    value_basic_info.s_block_material2 = NumToStr(i_qty_mat2);
    value_basic_info.s_cwt_block_qty_dc_after = NumToStr(i_block_dc_after);
    value_basic_info.s_cwt_block_qty_dc_before = NumToStr(i_block_dc_before);

    wxLogMessage(_("查找对重块数量计算完成-")+s_wbs);

    wxLogMessage(_("判断对重侧限速器")+s_wbs);

    array_index = p_value->find_row_value_array(wxT("0460"),i_act_col);


    if(array_index.IsEmpty())
    {
        wxLogMessage(_("项目中缺少限速器组件,请核查BOM!")+s_wbs);
        value_basic_info.b_has_governor=false;
    }else
    {
         int i_sel = array_index.GetCount();
         int i_gonvern=0;
         for(int i=0;i<i_sel;i++)
         {
             line = p_value->Get_Value(array_index.Item(i));
             wxString s_name = line->cols[i_name_col];
             wxString s_qty;

             if(s_name.Find(_("附件"))!=wxNOT_FOUND)
                    continue;

             if(s_name.Find(_("限速器"))!=wxNOT_FOUND)
             {
                   s_qty=line->cols[i_qty_col];

                   i_gonvern=i_gonvern+StrToInt(s_qty);
             }

         }

         if(i_gonvern>2)
             value_basic_info.b_has_governor=true;
         else
            value_basic_info.b_has_governor=false;

         line=NULL;

    }

     wxLogMessage(_("判断对重限速器完成-")+s_wbs);

    return update_prj_basic_info(value_basic_info, b_full_basic);
}

s_sap_hex_info wfFrame::Cal_prj_weight_hex_info(wxString s_wbs, Value_Pool* p_value, wxArraySupport& array_support)
{
    s_sap_hex_info value_hex_info;
    value_hex_info.s_wbs = s_wbs;

    wxArraySupport array_sel_support;
    wxString str;

    array_sel_support = get_same_act_arry(array_support, wxT("0670"));


    int i_rows = p_value->GetNumOfRows();

    int i_count = array_sel_support.GetCount();

    int i_mat_col = p_value->find_col_name(wxT("MATNR_I"));
    int i_act_col = p_value->find_col_name(wxT("VORNR"));
    int i_qty_col = p_value->find_col_name(wxT("NOMNG"));
    int i_name_col = p_value->find_col_name(wxT("MAKTX_ZH"));

    wxLogMessage(s_wbs+_("正在获取随行电缆的单位重信息..."));

    wxArrayInt array_index = p_value->find_row_value_array(wxT("0670"),i_act_col);


    int i_result= get_tc_hex_by_wbs_bom(value_hex_info, i_mat_col,i_qty_col, i_name_col, array_index, p_value, array_sel_support);

    if(i_result<0)
    {
        wxLogMessage(_("WBS bom缺少随行电缆，请核查BOM"));

    }

    array_index.Clear();
    array_sel_support.Clear();

     wxLogMessage(s_wbs+_("正在获取钢丝绳的单位重信息..."));

    array_sel_support  = get_same_act_arry(array_support, wxT("0750"));
    array_index= p_value->find_row_value_array(wxT("0750"),i_act_col);

    i_result= get_rope_hex_by_wbs_bom(value_hex_info, i_mat_col,i_qty_col, i_name_col, array_index, p_value, array_sel_support);

    if(i_result<=0)
    {
        wxLogMessage(_("WBS bom缺少钢丝绳，请核查BOM"));

    }

    array_index.Clear();
    array_sel_support.Clear();

     wxLogMessage(s_wbs+_("正在获取补偿链的单位重信息..."));

    array_sel_support = get_same_act_arry(array_support, wxT("0450"));
    array_index = p_value->find_row_value_array(wxT("0450"),i_act_col);

    i_result= get_cc_hex_by_wbs_bom(value_hex_info, i_mat_col,i_qty_col, i_name_col, array_index, p_value, array_sel_support);

    if(i_result==0)
    {
        wxLogMessage(_("WBS bom无补偿链"));

    }
    array_index.Clear();
    array_sel_support.Clear();

    return value_hex_info;
}

int wfFrame::get_tc_hex_by_wbs_bom(s_sap_hex_info &_value_hex,int i_mat_col,int i_qty_col,int i_name_col, wxArrayInt &array_range, Value_Pool* p_value, wxArraySupport &array_str)
{
   int i_count = array_str.GetCount();
   int i_rows = array_range.GetCount();

    Str_Line * line;

    int i, j;

    wxString s_mat_no, s_mat_name, s_hex;

    int i_index =-1;



    for(j=0; j<i_rows; j++)
    {
        line = p_value->Get_Value(array_range.Item(j));
        s_mat_no = line->cols[i_mat_col];
        s_mat_name = line->cols[i_name_col];

        for(i=0; i<i_count; i++)
        {
            if(s_mat_no  == array_str.Item(i).s_mat_no)
            {

                s_hex = NumToStr(array_str.Item(i).d_weight);


                _value_hex.s_tc_mat = array_str.Item(i).s_mat_no;
                _value_hex.s_tc_mat_name = s_mat_name;

                _value_hex.s_tc_hex=Int2Hex(s_hex);


                return 1;
            }


        }
        if(s_mat_name.Contains(_("随行电缆"))&&!s_mat_name.Contains(_("保护装置"))&&!s_mat_name.Contains(_("端头插件")))
        {
   //         wxMessageBox("test");
            _value_hex.s_tc_mat = s_mat_no;
            _value_hex.s_tc_mat_name = s_mat_name;

            _value_hex.s_tc_hex=wxT("NULL");
            i_index = 0;
        }
    }


    return i_index;
}

int wfFrame::get_rope_hex_by_wbs_bom(s_sap_hex_info &_value_hex,int i_mat_col,int i_qty_col,int i_name_col, wxArrayInt &array_range, Value_Pool* p_value, wxArraySupport &array_str)
{
   int i_count = array_str.GetCount();
   int i_rows = array_range.GetCount();

    Str_Line * line;

    int i, j;

    wxString s_mat_no, s_mat_name, s_hex, s_qty;
    double d_qty;

    bool b_get=false;

    int i_index =-1;
    int i_max=-1;

    for(j=0; j<i_rows; j++)
    {
        line = p_value->Get_Value(array_range.Item(j));
        s_qty = line->cols[i_qty_col];

        s_qty = sapnumconvert(s_qty);
        if(d_qty<StrToDouble(s_qty))
        {
            i_max=j;
            d_qty = StrToDouble(s_qty);
        }
    }

    line = p_value->Get_Value(array_range.Item(i_max));
    s_mat_name = line->cols[i_name_col];
    s_mat_no = line->cols[i_mat_col];

    i_index++;

    for(i=0;i<i_count;i++)
    {
     //   wxMessageBox(array_str.Item(i).s_mat_no+array_str.Item(i).s_para1, s_mat_no);

        if((s_mat_no == array_str.Item(i).s_mat_no) && (array_str.Item(i).s_para1!=wxT("CC")))
        {
            s_hex = NumToStr(array_str.Item(i).d_weight);

            _value_hex.s_rope_mat=s_mat_no;
            _value_hex.s_rope_name = s_mat_name;
            _value_hex.s_rope_hex =Int2Hex(s_hex);
            b_get=true;
            i_index++;

        }else if(s_mat_no == array_str.Item(i).s_mat_no&&array_str.Item(i).s_para1==wxT("CC"))
        {
            s_hex = NumToStr(array_str.Item(i).d_weight);

            _value_hex.s_cchain_mat=s_mat_no;
            _value_hex.s_cchain_name = s_mat_name;
            _value_hex.s_cchain_hex =Int2Hex(s_hex);
            i_index++;
        }

    }

    if(!b_get)
    {

        _value_hex.s_rope_mat=s_mat_no;
        _value_hex.s_rope_name = s_mat_name;
        _value_hex.s_rope_hex=_("NULL");

    }

    return i_index;

}
int wfFrame::get_cc_hex_by_wbs_bom(s_sap_hex_info &_value_hex,int i_mat_col,int i_qty_col,int i_name_col, wxArrayInt &array_range, Value_Pool* p_value, wxArraySupport &array_str)
{
   int i_count = array_str.GetCount();
   int i_rows = array_range.GetCount();


   if(i_rows==0)
   {
       _value_hex.s_cchain_mat=wxT("无");
       return 0;
   }

    Str_Line * line;

    int i, j;

    wxString s_mat_no, s_mat_name, s_hex,s_qty;
    double d_qty=0.00;
    int i_max;

    bool b_get = false;

    int i_index =0;

    for(j=0; j<i_rows; j++)
    {
        line = p_value->Get_Value(array_range.Item(j));
        s_qty = line->cols[i_qty_col];

        s_qty = sapnumconvert(s_qty);


        if(d_qty<StrToDouble(s_qty))
        {
            i_max=j;
            d_qty = StrToDouble(s_qty);
            s_mat_name = line->cols[i_name_col];
            s_mat_no = line->cols[i_mat_col];

            continue;
        }

        if(d_qty==StrToDouble(s_qty)&&d_qty>10.00)
        {
            i_index=2;

        }
    }

    if(d_qty<10.00)
    {
       _value_hex.s_cchain_mat=wxT("无");
       return -1;
    }else


    for(i=0; i<i_count; i++)
    {
        if(s_mat_no == array_str.Item(i).s_mat_no)
        {
            s_hex = NumToStr(array_str.Item(i).d_weight);

            _value_hex.s_cchain_mat=s_mat_no;
            _value_hex.s_cchain_name = s_mat_name;
            _value_hex.s_cchain_hex =Int2Hex(s_hex);
            b_get=true;

        }


        if(i_index!=2)
                i_index=1;
    }

    if(!b_get)
    {

        _value_hex.s_cchain_mat=s_mat_no;
        _value_hex.s_cchain_name = s_mat_name;
        _value_hex.s_cchain_hex=_("NULL");

    }


    return i_index;
}

bool wfFrame::update_prj_basic_info(s_basic_info v_basic_info, bool b_full_finish)
{
    wxString s_sql = wxT("select * from s_unit_info_attach where wbs_no = '")+v_basic_info.s_wbs+wxT("';");
    if(wxGetApp().is_have(s_sql))
    {
        s_sql = wxT("UPDATE s_unit_info_attach SET cwt_frame_weight='")+v_basic_info.s_cwt_weight+wxT("',conf_balance_block_qty='")+
               v_basic_info.s_balance_block_qty+wxT("', cwt_block_qty_before_dc='")+v_basic_info.s_cwt_block_qty_dc_before+wxT("',cwt_block_qty_after_dc='")+
               v_basic_info.s_cwt_block_qty_dc_after+wxT("', cwt_block_qty_mat1='")+v_basic_info.s_block_material1+wxT("', cwt_block_qty_mat2='")+
               v_basic_info.s_block_material2+wxT("',modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("', is_basic_full_finish=")+
               BoolToStr(b_full_finish)+wxT(",has_governor=")+BoolToStr(v_basic_info.b_has_governor)+wxT(",has_spring=")+BoolToStr(v_basic_info.b_has_spring)+wxT(",is_sync_din_latest=false where wbs_no='")+v_basic_info.s_wbs+wxT("';");
    }else
    {
        s_sql = wxT("INSERT INTO s_unit_info_attach(wbs_no, cwt_frame_weight,  conf_balance_block_qty, cwt_block_qty_before_dc, \
            cwt_block_qty_after_dc, cwt_block_qty_mat1, cwt_block_qty_mat2, modify_date, modify_emp_id, create_date, create_emp_id, is_basic_finish, is_basic_full_finish,is_sync_din_latest,has_governor,has_spring) \
           VALUES ('")+v_basic_info.s_wbs+wxT("','")+v_basic_info.s_cwt_weight+wxT("','")+v_basic_info.s_balance_block_qty+wxT("','")+
           v_basic_info.s_cwt_block_qty_dc_before+wxT("','")+v_basic_info.s_cwt_block_qty_dc_after+wxT("','")+v_basic_info.s_block_material1+wxT("','")+
           v_basic_info.s_block_material2+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+
           gr_para.login_user+wxT("',false,")+BoolToStr(b_full_finish)+wxT(", false,")+BoolToStr(v_basic_info.b_has_governor)+wxT(",")+BoolToStr(v_basic_info.b_has_spring)+wxT(");");
    }

    s_sql.Replace(wxT("''"),wxT("NULL"));

    return wxGetApp().app_sql_update(s_sql);

}

bool wfFrame::check_basic_info_for_array(wxArrayString arr_wbs)
{
   int i_count = arr_wbs.GetCount();
   wxString s_error, str;

   s_basic_info s_value;

   wxPostgreSQLresult * _res;

   wxString s_sql;

    for(int i=0; i<i_count; i++)
    {
        s_sql = wxT("SELECT * FROM s_unit_info_attach where wbs_no='")+arr_wbs.Item(i)+wxT("';");

        _res = wxGetApp().app_sql_select(s_sql);

        if (_res->Status() != PGRES_TUPLES_OK)
        {
            _res->Clear();
            continue;
        }

        int i_row = _res->GetRowsNumber();

        if(i_row==0)
        {
            str  = arr_wbs.Item(i)+_(":基本信息未创建\n");
            s_error = s_error+str;
            _res->Clear();

            continue;
        }

        s_value.s_wbs=arr_wbs.Item(i);
        s_value.s_car_weight = _res->GetVal(wxT("car_weight"));

        s_value.s_dc_weight = _res->GetVal(wxT("reserve_decoration_weight"));
        s_value.s_cwt_weight = _res->GetVal(wxT("cwt_frame_weight"));
        s_value.s_rate = _res->GetVal(wxT("balance_rate"));
        s_value.s_balance_block_qty = _res->GetVal(wxT("conf_balance_block_qty"));
        s_value.s_cwt_block_qty_dc_before = _res->GetVal(wxT("cwt_block_qty_before_dc"));
        s_value.s_cwt_block_qty_dc_after = _res->GetVal(wxT("cwt_block_qty_after_dc"));
        s_value.s_block_material1 = _res->GetVal(wxT("cwt_block_qty_mat1"));
        s_value.s_block_material2 = _res->GetVal(wxT("cwt_block_qty_mat2"));

        if(!s_value.check_info_finish(str))
            s_error = s_error+s_value.s_wbs+wxT(":")+str+wxT("\n");

        _res->Clear();
    }

    if(!s_error.IsEmpty())
    {
        wxMessageBox(s_error, _("提示"));
        wxLogMessage(s_error);
    }

    return true;

}
/*
wxArraySupport wfFrame::get_basic_info_support()
{
    wxArraySupport array_support;
    s_basic_info_support s_basic;
    wxString s_sql = wxT(" select * from s_mat_for_basic_info");
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(s_sql);
    if (_res->Status() != PGRES_TUPLES_OK)
    {
        _res->Clear();
        return array_support;
    }

    int i_count = _res->GetRowsNumber();

    array_support.Clear();

    for(int i=0;i<i_count;i++)
    {
        s_basic.s_mat_no = _res->GetVal(wxT("mat_no"));

        s_basic.s_act = _res->GetVal(wxT("activity"));

        s_basic.s_para1 = _res->GetVal(wxT("mat_para1"));

        s_basic.d_weight = _res->GetDouble(wxT("mat_weight"));

        array_support.Add(s_basic);
        _res->MoveNext();
    }
    _res->Clear();

    return array_support;
}*/


wxArraySupport wfFrame::get_basic_info_support(wxArrayString a_rp)
{
    wxArraySupport array_support;
    s_basic_info_support s_basic;
    wxString s_sql = wxT(" select * from s_mat_for_basic_info ");
    if(a_rp.IsEmpty())
        s_sql=s_sql+wxT(";");
    else
    {
        int i_rp = a_rp.GetCount();
        s_sql= s_sql+wxT(" where ");
        for(int j=0;j<i_rp;j++)
        {
            if(j==i_rp-1)
                s_sql = s_sql+wxT(" activity = '")+a_rp.Item(j)+wxT("' ;");
            else
                s_sql = s_sql+wxT(" activity= '")+a_rp.Item(j)+wxT("' or ");
        }
    }
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(s_sql);
    if (_res->Status() != PGRES_TUPLES_OK)
    {
        _res->Clear();
        return array_support;
    }

    int i_count = _res->GetRowsNumber();

    array_support.Clear();

    for(int i=0;i<i_count;i++)
    {
        s_basic.s_mat_no = _res->GetVal(wxT("mat_no"));

        s_basic.s_act = _res->GetVal(wxT("activity"));

        s_basic.s_para1 = _res->GetVal(wxT("mat_para1"));

        s_basic.d_weight = _res->GetDouble(wxT("mat_weight"));

        array_support.Add(s_basic);
        _res->MoveNext();
    }
    _res->Clear();

    return array_support;
}

wxArraySupport wfFrame::get_same_act_arry(wxArraySupport & array_support, wxString str)
{
    wxArraySupport array_select;

    int i_count = array_support.GetCount();
    s_basic_info_support s_basic;

    for(int i=0;i<i_count;i++)
    {
        if(array_support.Item(i).s_act == str)
            array_select.Add(array_support.Item(i));
    }

    return array_select;
}


wxString wfFrame::find_str_in_wbs_bom(int i_case_col,int i_result_col,wxArrayInt &array_range, Value_Pool* p_value, wxArraySupport &array_str)
{
    int i_count = array_str.GetCount();
    int i_rows = array_range.GetCount();

    Str_Line * line;

    int i, j;
    int i_index = -1;

    wxString str;
    for(i=0;i<i_count;i++)
    {
        for(j=0;j<i_rows;j++)
        {
            line = p_value->Get_Value(array_range.Item(j));
            str = line->cols[i_case_col];


            if(str == array_str.Item(i).s_mat_no)
            {
                str = NumToStr(array_str.Item(i).d_weight);
                return str;
            }

        }
    }

    return wxEmptyString;
}

wxArrayBlocks wfFrame::get_cwt_blocks_info(int i_case_col,int i_result_col,wxArrayInt &array_range, Value_Pool* p_value, wxArraySupport &array_str)
{
    int i_count = array_str.GetCount();
    int i_rows = array_range.GetCount();

    wxArrayBlocks array_result;

    Str_Line * line;

    int i, j;
    int i_index = -1;

    wxString str;

    s_cwt_block_info st_blocks;

    for(i=0;i<i_count;i++)
    {
        for(j=0;j<i_rows;j++)
        {
            line = p_value->Get_Value(array_range.Item(j));

            str = line->cols[i_case_col];

            if(str == array_str.Item(i).s_mat_no)
            {
                st_blocks.s_mat_no=str;
                st_blocks.s_qty = line->cols[i_result_col];
                st_blocks.s_weight = NumToStr(array_str.Item(i).d_weight);
                st_blocks.s_para1 = array_str.Item(i).s_para1;

                i_index = get_index_of_cwt_blocks(str,array_result);

                if(i_index==-1)
                    array_result.Add(st_blocks);
                else
                {
                    array_result.Item(i_index).s_qty = NumToStr(wxAtoi(array_result.Item(i_index).s_qty)+wxAtoi(line->cols[i_result_col]));
                }

          }

        }
    }

    return array_result;
}


int wfFrame::get_dc_weight(wxString str)
{
    wxString s_sql = wxT(" select reserve_decoration_weight from s_unit_info_attach where wbs_no ='")+str+wxT("';");
    wxPostgreSQLresult *    _res = wxGetApp().app_sql_select(s_sql);
    if (_res->Status() != PGRES_TUPLES_OK)
    {
        _res->Clear();
        return -2;
    }

    int i_count = _res->GetRowsNumber();

    if(i_count ==0)
    {
        _res->Clear();
        return -1;
    }

    int i_weight = _res->GetInt(wxT("reserve_decoration_weight"));

    _res->Clear();

    return i_weight;

}

int wfFrame::get_index_of_cwt_blocks(wxString &str, wxArrayBlocks & arr_blocks)
{

    int i_count = arr_blocks.GetCount();

    for(int i=0;i<i_count;i++)
    {
        if(arr_blocks.Item(i).s_mat_no == str)
            return i;
    }

    return -1;
}

bool wfFrame::update_sync_din(wxArrayToDin& a_info, bool b_success)
{
    int i_count = a_info.GetCount();
    if(i_count==0)
        return true;

    int i;

    wxString s_sql;

    if(b_success)
    {

        s_sql = wxT("UPDATE s_unit_info_attach SET  is_sync_din_latest=true WHERE ");

        for(i=0; i<i_count; i++)
        {
            a_info.Item(i).is_success=true;
            if(i==i_count-1)
                s_sql=s_sql+ wxT(" wbs_no='")+a_info.Item(i).s_wbs_no+wxT("' ;");
            else
                s_sql=s_sql+ wxT(" wbs_no='")+a_info.Item(i).s_wbs_no+wxT("' or ");
        }

        wxGetApp().app_sql_update(s_sql);
    }

    s_sql= wxT("INSERT INTO s_sync_to_din(wbs_no, project_name, car_weight, cwt_frame_weight, reserve_decoration_weight, \
            balance_rate, conf_balance_block_qty, cwt_block_qty_before_dc, cwt_block_qty_after_dc, cwt_block_qty_mat1, cwt_block_qty_mat2, \
            sync_operator, sync_time, success_info, has_governor, has_spring) VALUES ");

   for (i=0;i<i_count;i++)
   {
       int i_success;
       if(a_info.Item(i).is_success)
           i_success=1;
       else
           i_success=2;

       s_sql=s_sql+wxT("('")+a_info.Item(i).s_wbs_no+wxT("','")+a_info.Item(i).s_project_name+wxT("','")+NumToStr(a_info.Item(i).i_car_weight)+wxT("','")+
                 NumToStr(a_info.Item(i).i_cwt_frame_weight)+wxT("','")+NumToStr(a_info.Item(i).i_reservedocoration_weight)+wxT("','")+
                 NumToStr(a_info.Item(i).d_balance_rate)+wxT("','")+NumToStr(a_info.Item(i).i_conf_balance_block_qty)+wxT("','")+NumToStr(a_info.Item(i).i_cwt_blockqty_before_dc)+wxT("','")+
                 NumToStr(a_info.Item(i).i_cwt_blockqty_after_dc)+wxT("','")+NumToStr(a_info.Item(i).i_cwt_blockqty_mat1)+wxT("','")+NumToStr(a_info.Item(i).i_cwt_blockqty_mat2)+wxT("','")+
                gr_para.login_user+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+NumToStr(i_success)+wxT("',")+BoolToStr(a_info.Item(i).b_has_governor)+wxT(",")+BoolToStr(a_info.Item(i).b_has_spring)+wxT(")");
        if(i==i_count-1)
            s_sql=s_sql+wxT(";");
        else
            s_sql=s_sql+wxT(",");
   }
   return wxGetApp().app_sql_update(s_sql);
}
