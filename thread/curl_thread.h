#ifndef CURL_THREAD_H
#define CURL_THREAD_H
#include <wx/thread.h>
#include "curl_http.h"

#include "wfApp.h"

class wfFrame;
class curl_thread : public wxThread{
public:
    curl_thread(wfFrame* frame,wxArrayToDin & a_ToDIn);
    ~curl_thread();
    virtual ExitCode Entry();



private:
    wfFrame*  ThreadFrame;
    std::unique_ptr<curl_http> threadcurl;

    wxArrayToDin a_info;
};

#endif // CURL_THREAD_H
