#ifndef MYTHREAD_H_INCLUDED
#define MYTHREAD_H_INCLUDED

#include <memory>
#include <wx/thread.h>

#include "rfc_communication.h"
#include "wfApp.h"

class wfFrame;
class MyThread : public wxThread {
public:
    MyThread(wfFrame* frame,wxArrayString & a_wbs, int i_way);
    ~MyThread();
    virtual ExitCode Entry();

    void get_prj_info_from_sap();
    void get_prj_info_by_internal_day();
    void get_prj_basic_info();
    void get_hex_from_sap();

/*
    bool is_should_stop()
    {
        return b_run;
    }*/

private:
    wfFrame*  ThreadFrame;
    std::unique_ptr<Rfc_Communication> Thread_rfc_com;

    wxArrayString array_wbs;
    int thread_way;
    bool b_run;
};



#endif // MYTHREAD_H_INCLUDED
