#include "curl_thread.h"
#include "wfMain.h"

//for curl thread

curl_thread::curl_thread(wfFrame* frame,wxArrayToDin & a_ToDIn):
    wxThread(), threadcurl(new curl_http), ThreadFrame(frame)
{
    a_info = a_ToDIn;

}

curl_thread::~curl_thread()
{
    wxCriticalSectionLocker locker(wxGetApp().AppCritSection);

    wxArrayThread& threads = wxGetApp().AppThreads;
    threads.Remove(this);

    if ( threads.IsEmpty() )
    {
        // signal that no threads is waiting


        if ( wxGetApp().AppShutdown )
        {
            wxGetApp().AppShutdown = false;

            wxGetApp().AppSemaphoreDone.Post();
        }
    }

    a_info.Clear();
}

wxThread::ExitCode curl_thread::Entry()
{
    {
        wxCriticalSectionLocker locker(wxGetApp().AppCritSection);

        // If stop button pressed then return immediately
        if ( wxGetApp().AppShutdown )
            return NULL;
    }


    threadcurl->set_value(a_info);
    wxLogMessage(_("开始向DIN系统写入..."));
    threadcurl->update_data_into_din();

    wxString str= threadcurl->GetAnswer();

    wxJSONValue root;

    wxJSONReader reader;
    reader.Parse(str, &root);

    if(root["d"]["Status"].AsString()==wxT("1"))
    {
        ThreadFrame->update_sync_din(a_info, true);

        wxMessageBox(_("同步完成"),_("提示"));

        return NULL;

    }

        ThreadFrame->update_sync_din(a_info, false);

        wxMessageBox(_("同步失败:")+root["d"]["ErrorMsg"].AsString(),_("提示"));

        wxMessageBox(_("同步失败:")+str,_("提示"));
        return NULL;

}
