#ifndef WXPG_UTILS_H_INCLUDED
#define WXPG_UTILS_H_INCLUDED

#include <libpq-fe.h>
#include <wx/wx.h>
#include <wx/string.h>
#include <stdlib.h>

/*

#ifdef __WXMSW__
// Dynamically loaded PQgetOutResult
typedef PGresult* (*PQGETOUTRESULT)(PGconn*);
extern PQGETOUTRESULT PQiGetOutResult;
#define PQiGetOutResult (PQiGetOutResult)

// Dynamically loaded PQprepareOut
typedef PGresult* (*PQPREPAREOUT)(PGconn*, const char*, const char*, int, const Oid*, const int*);
extern PQPREPAREOUT PQiPrepareOut;
#define PQiPrepareOut (PQiPrepareOut)

// Dynamically loaded PQsendQueryPreparedOut
typedef int (*PQSENDQUERYPREPAREDOUT)(PGconn*, const char*, int, const char *const *, const int *, const int *, int);
extern PQSENDQUERYPREPAREDOUT PQiSendQueryPreparedOut;
#define PQiSendQueryPreparedOut (PQiSendQueryPreparedOut)

#else
#ifdef EDB_LIBPQ
#define PQiGetOutResult PQgetOutResult
#define PQiPrepareOut PQprepareOut
#define PQiSendQueryPreparedOut PQsendQueryPreparedOut
#endif
#endif
*/

// we dont have an appropriate wxLongLong method
#ifdef __WIN32__
#define atolonglong _atoi64
//#define atolonglong atoll
#else
#ifdef __WXMAC__
#define atolonglong(str) strtoll(str, (char **)NULL, 10)
#else
#ifdef __FreeBSD__
#define atolonglong(str) strtoll(str, (char **)NULL, 10)
#else
#define atolonglong atoll
#endif
#endif
#endif

#define PGOID_SCHEMA_CATALOG                11L
#define PGOID_SCHEMA_TOAST                  99L
#define PGOID_SCHEMA_PUBLIC                 2200L

#define PGOID_CLASS_PG_AUTHID               1260L

#define PGOID_TYPE_SERIAL                   -42L
#define PGOID_TYPE_SERIAL8                  -43L
#define PGOID_TYPE_SERIAL2                  -44L
#define PGOID_TYPE_BOOL                     16L
#define PGOID_TYPE_BYTEA                    17L
#define PGOID_TYPE_CHAR                     18L
#define PGOID_TYPE_NAME                     19L
#define PGOID_TYPE_INT8                     20L
#define PGOID_TYPE_INT2                     21L
#define PGOID_TYPE_INT4                     23L
#define PGOID_TYPE_TEXT                     25L
#define PGOID_TYPE_OID                      26L
#define PGOID_TYPE_TID                      27L
#define PGOID_TYPE_XID                      28L
#define PGOID_TYPE_CID                      29L
#define PGOID_TYPE_FLOAT4                   700L
#define PGOID_TYPE_FLOAT8                   701L
#define PGOID_TYPE_MONEY                    790L
#define PGOID_TYPE_CHAR_ARRAY               1002L
#define PGOID_TYPE_TEXT_ARRAY               1009L
#define PGOID_TYPE_BPCHAR_ARRAY             1014L
#define PGOID_TYPE_VARCHAR_ARRAY            1015L
#define PGOID_TYPE_BPCHAR                   1042L
#define PGOID_TYPE_VARCHAR                  1043L
#define PGOID_TYPE_DATE                     1082L
#define PGOID_TYPE_TIME                     1083L
#define PGOID_TYPE_TIMESTAMP                1114L
#define PGOID_TYPE_TIMESTAMP_ARRAY          1115L
#define PGOID_TYPE_TIME_ARRAY               1183L
#define PGOID_TYPE_TIMESTAMPTZ              1184L
#define PGOID_TYPE_TIMESTAMPTZ_ARRAY        1185L
#define PGOID_TYPE_INTERVAL                 1186L
#define PGOID_TYPE_INTERVAL_ARRAY           1187L
#define PGOID_TYPE_NUMERIC_ARRAY            1231L
#define PGOID_TYPE_TIMETZ                   1266L
#define PGOID_TYPE_TIMETZ_ARRAY             1270L
#define PGOID_TYPE_BIT                      1560L
#define PGOID_TYPE_BIT_ARRAY                1561L
#define PGOID_TYPE_VARBIT                   1562L
#define PGOID_TYPE_VARBIT_ARRAY             1563L
#define PGOID_TYPE_NUMERIC                  1700L
#define PGOID_TYPE_CSTRING                  2275L
#define PGOID_TYPE_ANY                      2276L
#define PGOID_TYPE_VOID                     2278L
#define PGOID_TYPE_TRIGGER                  2279L
#define PGOID_TYPE_LANGUAGE_HANDLER         2280L
#define PGOID_TYPE_INTERNAL                 2281L
#define PGOID_TYPE_HANDLER                  3115L


// These constants come from pgsql/src/include/catalog/pg_trigger.h
#define TRIGGER_TYPE_ROW				(1 << 0)
#define TRIGGER_TYPE_BEFORE				(1 << 1)
#define TRIGGER_TYPE_INSERT				(1 << 2)
#define TRIGGER_TYPE_DELETE				(1 << 3)
#define TRIGGER_TYPE_UPDATE				(1 << 4)
#define TRIGGER_TYPE_TRUNCATE			(1 << 5)
#define TRIGGER_TYPE_INSTEAD			(1 << 6)

typedef ConnStatusType wxConnStatusType;
typedef PostgresPollingStatusType wxPostgresPollingStatusType;
typedef ExecStatusType	wxExecStatusType;
typedef PGTransactionStatusType	wxPGTransactionStatusType;
typedef PGVerbosity	wxVerbosity;
typedef PGconn	wxPGconn;
typedef PGresult	wxResult;
typedef PGcancel	wxPGcancel;
typedef PGnotify	wxPGnotify;
typedef PQprintOpt	wxPrintOpt;
typedef PQconninfoOption wxConninfoOption;
typedef PQArgBlock wxArgBlock;
typedef PQnoticeReceiver wxNoticeReceiver;
typedef PQnoticeProcessor wxNoticeProcessor;
typedef pgthreadlock_t wxpgthreadlock_t;
typedef Oid wxOid;

typedef enum
{
    PGTYPCLASS_NUMERIC = 1,
    PGTYPCLASS_BOOL,
    PGTYPCLASS_STRING,
    PGTYPCLASS_DATE,
    PGTYPCLASS_OTHER
} pgTypClass;

enum
{
    PGCONN_OK = CONNECTION_OK,
    PGCONN_BAD = CONNECTION_BAD,
    PGCONN_REFUSED,
    PGCONN_DNSERR,
    PGCONN_ABORTED,     // connect user aborted
    PGCONN_BROKEN,       // tcp/pipe broken
    PGCONN_SSHTUNNEL_ERROR
};

// Conversions
wxString BoolToStr(bool value);         // english; used for config values
wxString DateToAnsiStr(const wxDateTime &datetime);
wxString DateToStrFormat(const wxDateTime &datetime);
wxString DateToStrShort(const wxDateTime &datetime);

bool StrToBool(const wxString &value);  // english
long StrToLong(const wxString &value);
int StrToInt(const wxString &value);
double StrToDouble(const wxString &value);
wxLongLong StrToLongLong(const wxString &value);
wxDateTime StrToDateTime(const wxString &value);
wxOid StrToOid(const wxString &value);
wxDateTime StrToDate(const wxString &value);

wxString generate_spaces(int length);

// nls aware
wxString BoolToYesNo(bool value);
wxString BoolToY(bool value);
wxString NumToStr(int value);
wxString NumToStr(long value);
wxString NumToStr(double value);
wxString NumToStr(wxOid value);
wxString NumToStr(wxLongLong value);
wxString DateToStr(const wxDateTime &datetime);

#endif // WXPG_UTILS_H_INCLUDED
