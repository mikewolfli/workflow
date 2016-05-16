/* Name:        src/wxPostgreSQL.cpp
 * Purpose:     connect to PostgreSQL database.
 * Sever version: 8.3
 * Author:      Trần Ngọc Quân
 * Modified by:
 * Created:     20/10/2010
 * RCS-ID:
 * Copyright:   (c) 2010-2011 wxPostgreSQL team
 * Licence: GPL
 */

#include "wxPostgreSQL.h"

wxPostgreSQL::wxPostgreSQL(wxMBConv &_cnv)
    :conninfo((char *)"")
{
    conv = &_cnv;
//    m_cancelConn = NULL;
    needColQuoting = false;
    this->conn =::PQconnectdb(this->conninfo);
    connstatus = this->Status();

}

wxPostgreSQL::wxPostgreSQL(const wxPostgreSQL& pq, wxMBConv &_cnv)
{
    conv = &_cnv;
    connstatus = this->Status();
}

wxPostgreSQL::wxPostgreSQL(char* const constr, wxMBConv &_cnv)
    :conninfo(constr)
{
    conv = &_cnv;
    needColQuoting = false;
//    m_cancelConn = NULL;
    this->conn =::PQconnectdb(this->conninfo);
    connstatus = this->Status();
}

wxPostgreSQL::wxPostgreSQL(const wxString& constr, wxMBConv &_cnv)
{
 //   m_cancelConn = NULL;
    conv = &_cnv;
    needColQuoting = false;
    int strsize= constr.size();
    if(conninfo)
       delete [] conninfo;
    conninfo= new char[strsize];

    strcpy(conninfo, (const char*)constr.mb_str(wxConvUTF8));
    this->conn =::PQconnectdb(this->conninfo);
    connstatus = this->Status();

    if(connstatus!=CONNECTION_OK)
    {
        if(conninfo)
            delete [] conninfo;
        conninfo= new char[strsize];
        strcpy(conninfo, (const char*)constr.mb_str(wxConvUTF8));

        ::PQfinish(conn);
        this->conn =::PQconnectdb(this->conninfo);
        connstatus = this->Status();
    }
}

wxPostgreSQL::~wxPostgreSQL()
{
//   Close();
    if(connOptions)
       delete connOptions;

    if(conninfo)
       delete [] conninfo;
}

wxPostgreSQL::wxPostgreSQL(const char *pghost,
                           const char *pgport,
                           const char *pgoptions,
                           const char *pgtty,
                           const char *dbName,
                           const char *login,
                           const char *pwd, wxMBConv &_cnv)
{
//    m_cancelConn = NULL;
    //   conv = &wxConvLibc;
    conv = &_cnv;
    needColQuoting = false;

    wxString con_str;
    con_str = wxT("host=")+wxString(pghost)+wxT(" port=")+wxString(pgport)+ wxT(" options=")+wxString(pgoptions)+wxT(" tty=")+wxString(pgtty)+ wxT(" dbname=")+wxString(dbName) + wxT(" user=")+wxString(login)+ wxT(" password=")+ wxString(pwd);
    int strsize= con_str.size();
    delete []conninfo;
    conninfo= new char[strsize];
    strcpy(conninfo, (const char*)con_str.mb_str(*conv));

    this->conn=::PQsetdbLogin(pghost, pgport, pgoptions, pgtty, dbName, login, pwd);
}

wxPostgresPollingStatusType wxPostgreSQL::ConnectPoll()
{
    return::PQconnectPoll(this->conn);
}

char* wxPostgreSQL::ErrorMessage() const
{
    return::PQerrorMessage(this->conn);
}

/*
void wxPostgreSQL::SetConnCancel(void)
{
    wxMutexLocker  lock(m_cancelConnMutex);
    PGcancel      *oldCancelConn = m_cancelConn;

    m_cancelConn = NULL;

    if (oldCancelConn != NULL)
        ::PQfreeCancel(oldCancelConn);

    if (!conn)
        return;

    m_cancelConn = ::PQgetCancel(conn);

}*/

void wxPostgreSQL::Close()
{
    if (this->conn)
    {
//        cancelExecute();
        ::PQfinish(conn);
    }
    this->conn = 0;
}

// Reconnect to the server
bool wxPostgreSQL::Reconnect()
{
    // Close the existing (possibly broken) connection
    Close();

    // Reset any vars that need to be in a defined state before connecting
    needColQuoting = false;

    this->conn =::PQconnectdb(this->conninfo);
    // Attempt the reconnect
    if (Status()!= CONNECTION_OK)
    {
        wxMessageBox(_("Failed to re-establish the connection to the server %s"),_("错误:"));
        connstatus = this->Status();
        return false;
    }

    connstatus = this->Status();
    return true;
}

/*
void wxPostgreSQL::ResetConnCancel(void)
{
    wxMutexLocker  lock(m_cancelConnMutex);
    PGcancel      *oldCancelConn = m_cancelConn;

    m_cancelConn = NULL;

    if (oldCancelConn != NULL)
        ::PQfreeCancel(oldCancelConn);
}
/*
void wxPostgreSQL::cancelExecute()
{
    char           errbuf[256];
    wxMutexLocker  lock(m_cancelConnMutex);

    if (m_cancelConn)
    {
        PGcancel *cancelConn = m_cancelConn;
        m_cancelConn = NULL;

        if (::PQcancel(cancelConn, errbuf, sizeof(errbuf)))
        {
            wxMessageBox(_("Cancel request sent"),_("取消"));
        }
        else
        {
            wxMessageBox(wxString::Format(_("Could not send cancel request:\n%s"), errbuf), _("取消"));
        }
        ::PQfreeCancel(cancelConn);
    }
}
*/
void wxPostgreSQL::Finish()
{
    ::PQfinish(this->conn);
    return;
}

wxConninfoOption * wxPostgreSQL::ConnDefaults()
{
    return::PQconndefaults();
}

void wxPostgreSQL::ConninfoFree()
{
    ::PQconninfoFree(this->connOptions);
}

int wxPostgreSQL::ResetStart()
{
    return::PQresetStart(this->conn);
}

wxPostgresPollingStatusType wxPostgreSQL::ResetPoll()
{
    return::PQresetPoll(this->conn);
}

wxPostgreSQLresult* wxPostgreSQL::Execute(const char* query)
{

//    SetConnCancel();
    wxResult* res = ::PQexec(this->conn, query);
 //   ResetConnCancel();

    lastResultStatus = ::PQresultStatus(res);
    wxPostgreSQLresult* result;
    if (lastResultStatus == PGRES_TUPLES_OK || lastResultStatus == PGRES_COMMAND_OK)
    {
        result=new wxPostgreSQLresult(res, this, *conv, needColQuoting );
        if(!result)
        {
            wxMessageBox(_("无法创建结果集!"),_("错误"));
            ::PQclear(res);
        }

        return result;
    }
    else
    {

         wxMessageBox(wxString(ErrorMessage(),*conv),_("错误"));
         ::PQclear(res);
    }

    return new wxPostgreSQLresult();



}

wxPostgreSQLresult* wxPostgreSQL::Execute(const wxString& query)
{

 //   int sqlsize= query.size();
 //   char* sql = new char[sqlsize];
 //   strncpy(sql, (const char*)query.mb_str(*conv), sqlsize);
//    SetConnCancel();
    wxResult* res = ::PQexec(this->conn, query.mb_str(*conv));
 //   ResetConnCancel();

    lastResultStatus = ::PQresultStatus(res);

    wxPostgreSQLresult* result;
    if (lastResultStatus == PGRES_TUPLES_OK || lastResultStatus == PGRES_COMMAND_OK)
    {
        result=new wxPostgreSQLresult(res, this, *conv, needColQuoting );
        if(!result)
        {
            wxMessageBox(_("无法创建结果集!"),_("错误"));
            ::PQclear(res);
        }

        return result;
    }
    else
    {
         wxMessageBox(wxString(ErrorMessage(),*conv),_("错误"));
         ::PQclear(res);
    }

    return new wxPostgreSQLresult();


}

//added by mikewolfli
wxString wxPostgreSQL::ExecuteScalar(const wxString &sql)
{
    wxString result;
    if(::PQstatus(this->conn)== CONNECTION_OK)
    {
        PGresult *qres;

//        SetConnCancel();
        qres = ::PQexec(this->conn, sql.mb_str(*conv));
//        ResetConnCancel();

        lastResultStatus = ::PQresultStatus(qres);

        if(lastResultStatus!= PGRES_TUPLES_OK && lastResultStatus!= PGRES_COMMAND_OK)
        {
            ::PQclear(qres);
            wxMessageBox(wxString(::PQresultErrorMessage(qres),*conv),_("错误"));
            return wxEmptyString;
        }

        if(::PQntuples(qres) < 1)
        {
            ::PQclear(qres);
            wxMessageBox(_("没有返回任何数据!"),_("信息"));
            return wxEmptyString;
        }

        result = wxString(::PQgetvalue(qres, 0, 0), *conv);
        ::PQclear(qres);

    }
    return result;
}

bool wxPostgreSQL::ExecuteVoid(const wxString &sql)
{
    if(::PQstatus(this->conn)!= CONNECTION_OK)
        return false;
    PGresult * vres;

 //   SetConnCancel();
    vres = ::PQexec(this->conn, sql.mb_str(*conv));
 //   ResetConnCancel();

    lastResultStatus = ::PQresultStatus(vres);

    if(lastResultStatus != PGRES_COMMAND_OK && lastResultStatus != PGRES_TUPLES_OK)
    {
        ::PQclear(vres);
        wxMessageBox(wxString(::PQresultErrorMessage(vres),*conv),_("错误"));
        return false;
    }

    ::PQclear(vres);
    return true;
}
/* Synchronous (blocking) */
void wxPostgreSQL::Reset()
{
    ::PQreset(this->conn);
    return;
}
/* request a cancel structure */
wxPGcancel* wxPostgreSQL::GetCancel()
{
    return::PQgetCancel(this->conn);
}
void wxPostgreSQL::FreeCancel(wxPGcancel *cancel)
{
    ::PQfreeCancel(cancel);
    return;
}
int	wxPostgreSQL::Cancel(wxPGcancel *cancel, char *errbuf, int errbufsize)
{
    return::PQcancel(cancel, errbuf, errbufsize);
}
/* backwards compatible version of Cancel; not thread-safe */
int	wxPostgreSQL::RequestCancel()
{
    return::PQrequestCancel(this->conn);
}
/* Accessor functions for PGconn objects */
char* wxPostgreSQL::GetDatabaseName()
{
    return::PQdb(this->conn);
}
char* wxPostgreSQL::GetUserName()
{
    return::PQuser(this->conn);
}
char* wxPostgreSQL::GetPassword()
{
    return::PQpass(this->conn);
}
char* wxPostgreSQL::GetHost()
{
    return::PQhost(this->conn);
}
char* wxPostgreSQL::GetPort()
{
    return::PQport(this->conn);
}
char* wxPostgreSQL::GetTTY()
{
    return::PQtty(this->conn);
}
char* wxPostgreSQL::Options()
{
    return::PQoptions(this->conn);
}
wxConnStatusType wxPostgreSQL::Status()
{
    return::PQstatus(this->conn);
}
wxPGTransactionStatusType wxPostgreSQL::TransactionStatus()
{
    return::PQtransactionStatus(this->conn);
}
const char* wxPostgreSQL::ParameterStatus(const char* paramName)
{
    return::PQparameterStatus(this->conn,paramName);
}
int	wxPostgreSQL::ProtocolVersion() const
{
    return::PQprotocolVersion(this->conn);
}
int	wxPostgreSQL::ServerVersion() const
{
    return::PQserverVersion(this->conn);
}
int	wxPostgreSQL::Socket()
{
    return::PQsocket(this->conn);
}
int	wxPostgreSQL::BackendPID()
{
    return::PQbackendPID(this->conn);
}
int	wxPostgreSQL::IsNeedsPassword()
{
    return::PQconnectionNeedsPassword(this->conn);
}
int	wxPostgreSQL::IsUsedPassword()
{
    return::PQconnectionUsedPassword(this->conn);
}
int	wxPostgreSQL::GetClientEncoding()
{
    return::PQclientEncoding(this->conn);
}
int	wxPostgreSQL::SetClientEncoding(const char* encoding)
{
    return::PQsetClientEncoding(this->conn, encoding);
}
/* Get the OpenSSL structure associated with a connection. Returns NULL for
     * unencrypted connections or if any other TLS library is in use. */
void* wxPostgreSQL::GetSSL()
{
    return::PQgetssl(this->conn);
}

/* Tell libpq whether it needs to initialize OpenSSL */
void wxPostgreSQL::InitSSL(int do_init)
{
    return::PQinitSSL(do_init);
}
wxVerbosity wxPostgreSQL::SetErrorVerbosity(wxVerbosity verbosity)
{
    return::PQsetErrorVerbosity(this->conn, verbosity);
}
/* Enable tracing */
void wxPostgreSQL::Trace(FILE *debug_port)
{
    return::PQtrace(this->conn,debug_port);
}
/* Disable tracing */
void wxPostgreSQL::UnTrace()
{
    return::PQuntrace(this->conn);
}
/* Override default notice handling routines */
wxNoticeReceiver wxPostgreSQL::SetNoticeReceiver(wxNoticeReceiver proc, void *arg)
{
    return::PQsetNoticeReceiver(this->conn, proc, arg);
}
wxNoticeProcessor wxPostgreSQL::SetNoticeProcessor(wxNoticeProcessor proc, void *arg)
{
    return::PQsetNoticeProcessor(this->conn, proc, arg);
}
pgthreadlock_t RegisterThreadLock(pgthreadlock_t newhandler)
{
    return::PQregisterThreadLock(newhandler);
}
/* Flexible synchronous query */
wxPostgreSQLresult* wxPostgreSQL::ExecuteParams(const char *command,
        int nParams,
        const wxOid *paramTypes,
        const char *const * paramValues,
        const int *paramLengths,
        const int *paramFormats,
        int resultFormat)
{
    wxResult* res=::PQexecParams(this->conn,
                                 command,
                                 nParams,
                                 paramTypes,
                                 paramValues,
                                 paramLengths,
                                 paramFormats,
                                 resultFormat);
    wxPostgreSQLresult* result=new wxPostgreSQLresult(res, this, *conv, needColQuoting );
    return result;
}
wxPostgreSQLresult* wxPostgreSQL::Prepare(const char *stmtName,
        const char *query,
        int nParams,
        const wxOid *paramTypes)
{
    wxResult* res=::PQprepare(this->conn,
                              stmtName,
                              query,
                              nParams,
                              paramTypes);
    wxPostgreSQLresult* result=new wxPostgreSQLresult(res, this, *conv, needColQuoting );
    return result;
}
wxPostgreSQLresult* wxPostgreSQL::ExecutePrepared(const char *stmtName,
        int nParams,
        const char *const * paramValues,
        const int *paramLengths,
        const int *paramFormats,
        int resultFormat)
{
    wxResult* res=::PQexecPrepared(this->conn,
                                   stmtName,
                                   nParams,
                                   paramValues,
                                   paramLengths,
                                   paramFormats,
                                   resultFormat);
    wxPostgreSQLresult* result=new wxPostgreSQLresult(res, this, *conv, needColQuoting);
    return result;
}
int	wxPostgreSQL::SendQuery(const char *query)
{
    return::PQsendQuery(this->conn, query);
}
int wxPostgreSQL::SendQueryParams(const char *command,
                                  int nParams,
                                  const wxOid *paramTypes,
                                  const char *const * paramValues,
                                  const int *paramLengths,
                                  const int *paramFormats,
                                  int resultFormat)
{
    return::PQsendQueryParams(this->conn,
                              command,
                              nParams,
                              paramTypes,
                              paramValues,
                              paramLengths,
                              paramFormats,
                              resultFormat);
}
int wxPostgreSQL::SendPrepare(const char *stmtName,
                              const char *query,
                              int nParams,
                              const Oid *paramTypes)
{
    return::PQsendPrepare(this->conn,
                          stmtName,
                          query,
                          nParams,
                          paramTypes);
}
int wxPostgreSQL::SendQueryPrepared(const char *stmtName,
                                    int nParams,
                                    const char *const * paramValues,
                                    const int *paramLengths,
                                    const int *paramFormats,
                                    int resultFormat)
{
    return::PQsendQueryPrepared(this->conn,
                                stmtName,
                                nParams,
                                paramValues,
                                paramLengths,
                                paramFormats,
                                resultFormat);
}
wxPostgreSQLresult* wxPostgreSQL::GetResult()
{
    wxResult* res=::PQgetResult(this->conn);
    wxPostgreSQLresult *result=new wxPostgreSQLresult(res, this, *conv, needColQuoting);
    return result;
}
int	wxPostgreSQL::IsBusy()
{
    return::PQisBusy(this->conn);
}
int	wxPostgreSQL::ConsumeInput()
{
    return::PQconsumeInput(this->conn);
}
wxPGnotify* wxPostgreSQL::Notifies()
{
    return::PQnotifies(this->conn);
}
int	wxPostgreSQL::PutCopyData(const char *buffer, int nbytes)
{
    return::PQputCopyData(this->conn, buffer, nbytes);
}
int	wxPostgreSQL::PutCopyEnd(const char *errormsg)
{
    return::PQputCopyEnd(this->conn, errormsg);
}
int	wxPostgreSQL::GetCopyData(char **buffer, int async)
{
    return::PQgetCopyData(this->conn, buffer, async);
}
int	wxPostgreSQL::Getline(char *string, int length)
{
    return::PQgetline(this->conn, string, length);
}
int wxPostgreSQL::Putline(const char *string)
{
    return::PQputline(this->conn, string);
}
int	wxPostgreSQL::GetlineAsync(char *buffer, int bufsize)
{
    return::PQgetlineAsync(this->conn, buffer, bufsize);
}
int	wxPostgreSQL::PutnBytes(const char *buffer, int nbytes)
{
    return::PQputnbytes(this->conn, buffer, nbytes);
}
int	wxPostgreSQL::EndCopy()
{
    return::PQendcopy(this->conn);
}
int	wxPostgreSQL::SetNonBlocking(int arg)
{
    return::PQsetnonblocking(this->conn, arg);
}
int	wxPostgreSQL::IsNonBlocking()
{
    return::PQisnonblocking(this->conn);
}
int	wxPostgreSQL::IsThreadSafe()
{
    return::PQisthreadsafe();
}
int	wxPostgreSQL::Flush()
{
    return::PQflush(this->conn);
}

wxPostgreSQLresult* wxPostgreSQL::fn(int fnid,
                                     int *result_buf,
                                     int *result_len,
                                     int result_is_int,
                                     const wxArgBlock *args,
                                     int nargs)
{
    wxResult* res=::PQfn(this->conn,
                         fnid,
                         result_buf,
                         result_len,
                         result_is_int,
                         args,
                         nargs);
    wxPostgreSQLresult* result=new wxPostgreSQLresult(res, this, *conv, needColQuoting);
    return result;
}
wxPostgreSQLresult* wxPostgreSQL::DescribePrepared(const char *stmt)
{
    wxResult* res=::PQdescribePrepared(this->conn, stmt);
    wxPostgreSQLresult* result=new wxPostgreSQLresult(res, this, *conv, needColQuoting);
    return result;
}
wxPostgreSQLresult* wxPostgreSQL::DescribePortal(const char *portal)
{
    wxResult* res=::PQdescribePortal(this->conn, portal);
    wxPostgreSQLresult* result=new wxPostgreSQLresult(res, this, *conv, needColQuoting);
    return result;
}
int	wxPostgreSQL::SendDescribePrepared(const char *stmt)
{
    return::PQsendDescribePrepared(this->conn, stmt);
}
int	wxPostgreSQL::SendDescribePortal(const char *portal)
{
    return::PQsendDescribePortal(this->conn, portal);
}
void wxPostgreSQL::FreeMemory(void *ptr)
{
    return::PQfreemem(ptr);
}
wxPostgreSQLresult* wxPostgreSQL::MakeEmptyResult(ExecStatusType status)
{
    wxResult* res=::PQmakeEmptyPGresult(this->conn, status);
    wxPostgreSQLresult* result=new wxPostgreSQLresult(res, this, *conv, needColQuoting);
    return result;
}
size_t wxPostgreSQL::EscapeStringConn(char *to, const char *from, size_t length, int *error)
{
    return::PQescapeStringConn(this->conn, to, from, length, error);
}
unsigned char* wxPostgreSQL::EscapeByteaConn(const unsigned char *from, size_t from_length, size_t *to_length)
{
    return::PQescapeByteaConn(this->conn, from, from_length, to_length);
}
unsigned char* wxPostgreSQL::EscapeBytea(const unsigned char *from, size_t from_length,size_t *to_length)
{
    return::PQescapeBytea(from, from_length, to_length);
}
unsigned char* wxPostgreSQL::UnescapeBytea(const unsigned char *strtext, size_t *retbuflen)
{
    return::PQunescapeBytea(strtext, retbuflen);
}
size_t wxPostgreSQL::EscapeString(char *to, const char *from, size_t length)
{
    return::PQescapeString(to, from, length);
}
/* Large-object access routines */
int	wxPostgreSQL::lo_open(wxOid lobjId, int mode)
{
    return::lo_open(this->conn, lobjId, mode);
}
int	wxPostgreSQL::lo_close(int fd)
{
    return::lo_close(this->conn, fd);
}
int	wxPostgreSQL::lo_read(int fd, char *buf, size_t len)
{
    return::lo_read(this->conn, fd, buf, len);
}
int	wxPostgreSQL::lo_write(int fd, const char *buf, size_t len)
{
    return::lo_write(this->conn, fd, buf, len);
}
int	wxPostgreSQL::lo_lseek(int fd, int offset, int whence)
{
    return::lo_lseek(this->conn, fd, offset, whence);
}
wxOid wxPostgreSQL::lo_creat(int mode)
{
    return::lo_creat(this->conn, mode);
}
wxOid wxPostgreSQL::lo_create(wxOid lobjId)
{
    return::lo_create(this->conn, lobjId);
}
int	wxPostgreSQL::lo_tell(int fd)
{
    return::lo_tell(this->conn, fd);
}
int	wxPostgreSQL::lo_truncate(int fd, size_t len)
{
    return::lo_truncate(this->conn, fd, len);
}
int	wxPostgreSQL::lo_unlink(wxOid lobjId)
{
    return::lo_unlink(this->conn, lobjId);
}
wxOid wxPostgreSQL::lo_import(const char *filename)
{
    return::lo_import(this->conn, filename);
}
int	wxPostgreSQL::lo_export(wxOid lobjId, const char *filename)
{
    return::lo_export(this->conn, lobjId, filename);
}
int	wxPostgreSQL::mblen(const char *s, int encoding)
{
    return::PQmblen(s, encoding);
}
int	wxPostgreSQL::dsplen(const char *s, int encoding)
{
    return::PQdsplen(s, encoding);
}
int	wxPostgreSQL::env2encoding()
{
    return::PQenv2encoding();
}
char* wxPostgreSQL::EncryptPassword(const char *passwd, const char *user)
{
    return::PQencryptPassword(passwd, user);
}
int	wxPostgreSQL::char2encoding(const char *name)
{
    return::pg_char_to_encoding(name);
}
const char* wxPostgreSQL::encoding2char(int encoding)
{
    return::pg_encoding_to_char(encoding);
}
int	wxPostgreSQL::valid_server_encoding_id(int encoding)
{
    return::pg_valid_server_encoding_id(encoding);
}

bool wxPostgreSQL::IsAlive()
{
    if(Status()!=CONNECTION_OK)
    {
        if (conn)
        {
            ::PQfinish(conn);
            conn = 0;
            connstatus=PGCONN_BROKEN;
        }
        return false;
    }

    PGresult *qryRes = ::PQexec(conn, "SELECT 1;");
    lastResultStatus = ::PQresultStatus(qryRes);
    if (lastResultStatus != PGRES_TUPLES_OK)
    {
        ::PQclear(qryRes);
        qryRes = ::PQexec(conn, "ROLLBACK TRANSACTION; SELECT 1;");
        lastResultStatus = ::PQresultStatus(qryRes);
    }
    PQclear(qryRes);

    // Check for errors
    if (lastResultStatus != PGRES_TUPLES_OK)
    {
        ::PQfinish(conn);
        conn = 0;
        connstatus=PGCONN_BROKEN;
        return false;
    }

    return true;
}

/* ***********************wxPostgreSQLresult*****************************/
wxPostgreSQLresult::wxPostgreSQLresult()
    :conv(wxConvUTF8)
{
    conn = 0;
    res = 0;
    nCols = 0;
    nRows = 0;
    pos = 0;
    needColQuoting = false;
}
wxPostgreSQLresult::wxPostgreSQLresult(wxResult* newres, wxPostgreSQL *newconn, wxMBConv &cnv, bool needColQt)
    :conv(cnv)
{
    res = newres;
    conn = newconn;
    needColQuoting = needColQt;


    // Make sure we have tuples
    if (Status() != PGRES_TUPLES_OK)
    {
        nCols = 0;
        nRows = 0;
        pos = 0;
    }
    else
    {
        nCols = GetNumberFields();
        for (int x = 0; x < nCols + 1; x++)
        {
            colTypes.Add(wxT(""));
            colFullTypes.Add(wxT(""));
            colClasses.Add(0);
        }

        nRows = GetRowsNumber();
        MoveFirst();
    }
}

wxPostgreSQLresult::~wxPostgreSQLresult()
{
//    Clear();
    this->res = 0;
}

wxExecStatusType wxPostgreSQLresult::Status()
{
    return ::PQresultStatus(this->res);
}

void wxPostgreSQLresult::Clear()
{
    ::PQclear(this->res);
}

char* wxPostgreSQLresult::StatusMessage(wxExecStatusType status)
{
    return::PQresStatus(status);
}
char* wxPostgreSQLresult::ErrorMessage()
{
    return::PQresultErrorMessage(this->res);
}
char* wxPostgreSQLresult::ErrorFieldMessage(int fieldcode)
{
    return::PQresultErrorField(this->res, fieldcode);
}
//Return number row
int	wxPostgreSQLresult::GetRowsNumber()
{
    return ::PQntuples(this->res);
}

int	wxPostgreSQLresult::GetNumberFields()
{
    return ::PQnfields(this->res);
}
int	wxPostgreSQLresult::IsBinary()
{
    return::PQbinaryTuples(this->res);
}
char* wxPostgreSQLresult::FieldName(int field_num)
{
    return ::PQfname(this->res,field_num);
}
int	wxPostgreSQLresult::FieldNumber(const char *field_name)
{
    return::PQfnumber(this->res, field_name);
}
wxOid wxPostgreSQLresult::FieldTable(int field_num)
{
    return::PQftable(this->res, field_num);
}
int	wxPostgreSQLresult::FieldTableColumn(int field_num)
{
    return::PQftablecol(this->res, field_num);
}
int	wxPostgreSQLresult::FieldFormat(int field_num)
{
    return::PQfformat(this->res, field_num);
}
wxOid wxPostgreSQLresult::FieldType(int field_num)
{
    return::PQftype(this->res, field_num);
}
int	wxPostgreSQLresult::FieldSize(int field_num)
{
    return::PQfsize(this->res, field_num);
}
int	wxPostgreSQLresult::FieldModifier(int field_num)
{
    return::PQfmod(this->res, field_num);
}
char* wxPostgreSQLresult::CommandStatus()
{
    return::PQcmdStatus(this->res);
}
char* wxPostgreSQLresult::OidStatus()
{
    return::PQoidStatus(this->res);
}
wxOid wxPostgreSQLresult::OidValue()
{
    return::PQoidValue(this->res);
}
char* wxPostgreSQLresult::CommandNumberRows()
{
    return::PQcmdTuples(this->res);
}
char* wxPostgreSQLresult::GetValue(int tup_num, int field_num)
{
    return ::PQgetvalue(this->res, tup_num, field_num);
}
int	wxPostgreSQLresult::GetLength(int tup_num, int field_num)
{
    return::PQgetlength(this->res, tup_num, field_num);
}
int	wxPostgreSQLresult::IsNull(int tup_num, int field_num)
{
    return::PQgetisnull(this->res, tup_num, field_num);
}
int	wxPostgreSQLresult::NumberParams()
{
    return::PQnparams(this->res);
}
wxOid wxPostgreSQLresult::ParamType(int param_num)
{
    return::PQparamtype(this->res, param_num);
}
void wxPostgreSQLresult::Print(FILE *fout,
                               const wxPrintOpt *ps)
{
    ::PQprint(fout, this->res, ps);
    return;
}
void wxPostgreSQLresult::DisplayRows(FILE *fp,		/* where to send the output */
                                     int fillAlign,	/* pad the fields with spaces */
                                     const char *fieldSep,	/* field separator */
                                     int printHeader,	/* display headers? */
                                     int quiet)
{
    ::PQdisplayTuples(this->res, fp, fillAlign, fieldSep, printHeader, quiet);
    return;
}
void wxPostgreSQLresult::PrintRows(FILE *fout,		/* output stream */
                                   int printAttName, /* print attribute names */
                                   int terseOutput,	/* delimiter bars */
                                   int width)		/* width of column, if 0, use variable width */
{
    ::PQprintTuples(this->res, fout, printAttName, terseOutput, width);
    return;
}

//added by mikewolfli  according to pgadmin 1.18.1
wxOid wxPostgreSQLresult::ColTypeOID(const int col) const
{
    wxASSERT(col < nCols && col >= 0);

    return ::PQftype(this->res,col);
}

long wxPostgreSQLresult::ColTypeMod(const int col) const
{
    wxASSERT(col < nCols && col >= 0);

    return ::PQfmod(this->res,col);
}


long wxPostgreSQLresult::GetInsertedCount() const
{
    char *cnt = ::PQcmdTuples(this->res);
    if (!*cnt)
        return -1;
    else
        return atol(cnt);
}


pgTypClass wxPostgreSQLresult::ColTypClass(const int col) const
{
	wxASSERT(col < nCols && col >= 0);

	if (colClasses[col] != 0)
		return (pgTypClass)colClasses[col];

	wxString typoid = ExecuteScalar(
	                      wxT("SELECT CASE WHEN typbasetype=0 THEN oid else typbasetype END AS basetype\n")
	                      wxT("  FROM pg_type WHERE oid=") + NumToStr(ColTypeOID(col)));

	switch (StrToLong(typoid))
	{
		case PGOID_TYPE_BOOL:
			colClasses[col] = PGTYPCLASS_BOOL;
			break;
		case PGOID_TYPE_INT8:
		case PGOID_TYPE_INT2:
		case PGOID_TYPE_INT4:
		case PGOID_TYPE_OID:
		case PGOID_TYPE_XID:
		case PGOID_TYPE_TID:
		case PGOID_TYPE_CID:
		case PGOID_TYPE_FLOAT4:
		case PGOID_TYPE_FLOAT8:
		case PGOID_TYPE_MONEY:
		case PGOID_TYPE_BIT:
		case PGOID_TYPE_NUMERIC:
			colClasses[col] = PGTYPCLASS_NUMERIC;
			break;
		case PGOID_TYPE_BYTEA:
		case PGOID_TYPE_CHAR:
		case PGOID_TYPE_NAME:
		case PGOID_TYPE_TEXT:
		case PGOID_TYPE_VARCHAR:
			colClasses[col] = PGTYPCLASS_STRING;
			break;
		case PGOID_TYPE_TIMESTAMP:
		case PGOID_TYPE_TIMESTAMPTZ:
		case PGOID_TYPE_TIME:
		case PGOID_TYPE_TIMETZ:
		case PGOID_TYPE_INTERVAL:
			colClasses[col] = PGTYPCLASS_DATE;
			break;
		default:
			colClasses[col] = PGTYPCLASS_OTHER;
			break;
	}

	return (pgTypClass)colClasses[col];
}


wxString wxPostgreSQLresult::ColType(const int col) const
{
	wxASSERT(col < nCols && col >= 0);

	if (!colTypes[col].IsEmpty())
		return colTypes[col];

	wxString szSQL, szResult;
	szSQL.Printf(wxT("SELECT format_type(oid,NULL) as typname FROM pg_type WHERE oid = %d"), (int)ColTypeOID(col));
	szResult = ExecuteScalar(szSQL);
	colTypes[col] = szResult;

	return szResult;
}

wxString wxPostgreSQLresult::ColFullType(const int col) const
{
	wxASSERT(col < nCols && col >= 0);

	if (!colFullTypes[col].IsEmpty())
		return colFullTypes[col];

	wxString szSQL, szResult;
	szSQL.Printf(wxT("SELECT format_type(oid,%d) as typname FROM pg_type WHERE oid = %d"), (int)ColTypeMod(col), (int)ColTypeOID(col));
	szResult = ExecuteScalar(szSQL);
	colFullTypes[col] = szResult;

	return szResult;
}


int wxPostgreSQLresult::ColScale(const int col) const
{
    wxASSERT(col < nCols && col >= 0);

    // TODO
    return 0;
}
wxString wxPostgreSQLresult::ColName(const int col) const
{
    wxASSERT(col < nCols && col >= 0);

    return wxString(::PQfname(this->res, col), conv);
}


int wxPostgreSQLresult::ColNumber(const wxString &colname) const
{
    int col;

    if (needColQuoting)
    {
        wxString quotedColName = colname;
        quotedColName.Replace(wxT("\""), wxT("\"\""));
        col = ::PQfnumber(this->res, (wxT("\"") + quotedColName + wxT("\"")).mb_str(conv));
    }
    else
        col = ::PQfnumber(this->res, colname.mb_str(conv));

    if (col < 0)
    {
        wxLogError(_("Column not found in wxPostgreSQLresult: %s"), colname.c_str());
    }
    return col;
}

bool wxPostgreSQLresult::HasColumn(const wxString &colname) const
{
    if (needColQuoting)
    {
        wxString quotedColName = colname;
        quotedColName.Replace(wxT("\""), wxT("\"\""));
        return (::PQfnumber(this->res, (wxT("\"") + quotedColName + wxT("\"")).mb_str(conv)) < 0 ? false : true);
    }
    else
        return (::PQfnumber(this->res, colname.mb_str(conv)) < 0 ? false : true);

}

char *wxPostgreSQLresult::GetCharPtr(const int col) const
{
    wxASSERT(col < nCols && col >= 0);

    return ::PQgetvalue(this->res, pos - 1, col);
}

char *wxPostgreSQLresult::GetCharPtr(const wxString &col) const
{
    return ::PQgetvalue(this->res, pos - 1, ColNumber(col));
}


wxString wxPostgreSQLresult::GetVal(const int col) const
{
    wxASSERT(col < nCols && col >= 0);

    return wxString(GetCharPtr(col), conv);
}


wxString wxPostgreSQLresult::GetVal(const wxString &colname) const
{
    return GetVal(ColNumber(colname));
}


long wxPostgreSQLresult::GetLong(const int col) const
{
    wxASSERT(col < nCols && col >= 0);

    char *c = ::PQgetvalue(this->res, pos - 1, col);
    if (c)
        return atol(c);
    else
        return 0;
}


long wxPostgreSQLresult::GetLong(const wxString &col) const
{
    char *c = ::PQgetvalue(this->res, pos - 1, ColNumber(col));
    if (c)
        return atol(c);
    else
        return 0;
}

int wxPostgreSQLresult::GetInt(const int col) const
{
    wxASSERT(col < nCols && col >= 0);

    char *c = ::PQgetvalue(this->res, pos - 1, col);
    if (c)
        return atoi(c);
    else
        return 0;
}


int wxPostgreSQLresult::GetInt(const wxString &col) const
{
    char *c = ::PQgetvalue(this->res, pos - 1, ColNumber(col));
    if (c)
        return atoi(c);
    else
        return 0;
}

bool wxPostgreSQLresult::GetBool(const int col) const
{
    wxASSERT(col < nCols && col >= 0);

    char *c = ::PQgetvalue(this->res, pos - 1, col);
    if (c)
    {
        if (*c == 't' || *c == '1' || !strcmp(c, "on"))
            return true;
    }
    return false;
}


bool wxPostgreSQLresult::GetBool(const wxString &col) const
{
    return GetBool(ColNumber(col));
}


wxDateTime wxPostgreSQLresult::GetDateTime(const int col) const
{
    wxASSERT(col < nCols && col >= 0);

    wxDateTime dt;
    wxString str = GetVal(col);
    /* This hasn't just been used. ( Is not infinity ) */
    if (!str.IsEmpty())
        dt.ParseDateTime(str);
    return dt;
}


wxDateTime wxPostgreSQLresult::GetDateTime(const wxString &col) const
{
    return GetDateTime(ColNumber(col));
}


wxDateTime wxPostgreSQLresult::GetDate(const int col) const
{
    wxASSERT(col < nCols && col >= 0);

    wxDateTime dt;
    wxString str = GetVal(col);
    /* This hasn't just been used. ( Is not infinity ) */
    if (!str.IsEmpty())
        dt.ParseDate(str);
    return dt;
}


wxDateTime wxPostgreSQLresult::GetDate(const wxString &col) const
{
    return GetDate(ColNumber(col));
}


double wxPostgreSQLresult::GetDouble(const int col) const
{
    wxASSERT(col < nCols && col >= 0);

    return StrToDouble(GetVal(col));
}


double wxPostgreSQLresult::GetDouble(const wxString &col) const
{
    return GetDouble(ColNumber(col));
}


wxULongLong wxPostgreSQLresult::GetLongLong(const int col) const
{
    wxASSERT(col < nCols && col >= 0);

    char *c = PQgetvalue(res, pos - 1, col);
    if (c)
        return atolonglong(c);
    else
        return 0;
}

wxULongLong wxPostgreSQLresult::GetLongLong(const wxString &col) const
{
    return GetLongLong(ColNumber(col));
}


wxOid wxPostgreSQLresult::GetOid(const int col) const
{
    wxASSERT(col < nCols && col >= 0);

    char *c = ::PQgetvalue(this->res, pos - 1, col);
    if (c)
        return (wxOid)strtoul(c, 0, 10);
    else
        return 0;
}


wxOid wxPostgreSQLresult::GetOid(const wxString &col) const
{
    return GetOid(ColNumber(col));
}

wxString wxPostgreSQLresult::ExecuteScalar(const wxString &sql) const
{
    return conn->ExecuteScalar(sql);
}



//////////////////////////////////////////////////////////////////

wxPgResultIterator::wxPgResultIterator(wxPostgreSQL *conn, const wxString &qry)
{
    set = conn->Execute(qry);
    first = true;
}


wxPgResultIterator::wxPgResultIterator(wxPostgreSQLresult *s)
{
    set = s;
    first = true;
}


wxPgResultIterator::~wxPgResultIterator()
{
    if (set)
        delete set;
}


bool wxPgResultIterator::RowsLeft()
{
    if (!set)
        return false;

    if (first)
    {
        if (!set->NumRows())
            return false;
        first = false;
    }
    else
        set->MoveNext();

    return !set->Eof();
}


bool wxPgResultIterator::MovePrev()
{
    if (!set)
        return false;

    set->MovePrevious();
    return true;
}


//added by mikewolfli  according to pgadmin 1.18.1
