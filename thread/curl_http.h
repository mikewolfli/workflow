#ifndef CURL_HTTP_H
#define CURL_HTTP_H

#include <wx/string.h>
#include <memory>
#include <curl/curl.h>
#include <curl/easy.h>
#include "wf_stdafx.h"

#include "wx/jsonval.h"
#include "wx/jsonwriter.h"
#include "wx/jsonreader.h"

class curl_http
{
public:
    curl_http();
    virtual ~curl_http();

    void set_value(wxArrayToDin & a_din)
    {
        a_info=a_din;
    }

    void update_data_into_din();

    wxString GetAnswer() const;

protected:
private:

    wxString build_json_data();
    wxArrayToDin a_info;
    // Members
    CURL*           dg_curl;         // Connection ptr
    CURLcode        dg_result;          // Handle values: CURLE_OK, CURLE_COULDNT_RESOLVE_HOST,
    // CURLE_COULDNT_RESOLVE_PROXY, CURLE_COULDNT_CONNECT
    // CURLE_OPERATION_TIMEDOUT

    wxString        dg_answer;          // Stores server answer

    /*static*/ wxString dg_url;
};

#endif // CURL_HTTP_H
