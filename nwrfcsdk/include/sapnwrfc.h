#ifndef SAPNWRFC_H
#define SAPNWRFC_H

#include <stdlib.h>
#include <stdio.h>
#ifndef SAPTYPE_H
#include "sapucx.h"
#endif /* SAPTYPE_H */
#include "sapuc.h"

#ifndef DECL_EXP
#   if defined(SAPonLIN) && defined(GCC_HIDDEN_VISIBILITY)
#     define DECL_EXP __attribute__((visibility("default")))
#   else
#     define DECL_EXP
#   endif
#endif /* DECL_EXP */

#ifndef SAP_API
#ifdef SAPonNT 
#     define SAP_API _stdcall
#else
#     define SAP_API
#endif /* SAPonNT */ 
#endif /* SAP_API */

#ifdef SAPonNT
#pragma warning (disable : 4267)  // disable warning: conversion from 'size_t' to 'const unsigned int'
#endif

#if defined(SAPonOS390) && defined(__XPLINK__) && __CHARSET_LIB == 1
#pragma runopts("FILETAG(AUTOCVT,AUTOTAG)")
#endif  


/* RFC scalar data type mappings */
typedef SAP_UC         RFC_CHAR;     ///< Characters, RFCTYPE_CHAR
typedef RFC_CHAR       RFC_NUM;      ///< Digits, RFCTYPE_NUM          /*SAPUNICODEOK_CHARTYPE*/
typedef SAP_RAW        RFC_BYTE;     ///< Raw data, RFCTYPE_BYTE
typedef SAP_RAW        RFC_BCD;      ///< Packed numbers, RFCTYPE_BCD  /*SAPUNICODEOK_CHARTYPE*/
typedef SAP_RAW        RFC_INT1;     ///< 1 byte integer, RFCTYPE_INT1
typedef short          RFC_INT2;     ///< 2 byte integer, RFCTYPE_INT2
typedef int			   RFC_INT;		 ///< 4 byte integer, RFCTYPE_INT
typedef double         RFC_FLOAT;    ///< Floating point, double precision, RFCTYPE_FLOAT
typedef RFC_CHAR       RFC_DATE[8];  ///< Date, RFCTYPE_DATE (YYYYMMDD)
typedef RFC_CHAR       RFC_TIME[6];  ///< Time, RFCTYPE_TIME (HHMMSS)
typedef DecFloat16     RFC_DECF16;   ///< IEEE 754r decimal floating point, 8 bytes
typedef DecFloat34     RFC_DECF34;   ///< IEEE 754r decimal floating point, 16 bytes


/** \enum _RFCTYPE
 * \ingroup api
 *
 * RFCTYPE is used in field descriptions (#RFC_FIELD_DESC) and parameter descriptions 
 * (#RFC_PARAMETER_DESC) and denotes the ABAP data type of the corresponding field/parameter.
 */
typedef enum _RFCTYPE
{
	RFCTYPE_CHAR   = 0,		///< 1-byte or multibyte character, fixed size, blank padded
	RFCTYPE_DATE   = 1,		///< Date ( YYYYYMMDD )
	RFCTYPE_BCD    = 2,		///< Packed number, any length between 1 and 16 bytes
	RFCTYPE_TIME   = 3,		///< Time (HHMMSS) 
	RFCTYPE_BYTE   = 4,		///< Raw data, binary, fixed length, zero padded.
	RFCTYPE_TABLE   = 5,	///< Internal table
	RFCTYPE_NUM    = 6,		///< Digits, fixed size, leading '0' padded.
	RFCTYPE_FLOAT  = 7,		///< Floating point, double precission
	RFCTYPE_INT    = 8,		///< 4-byte integer
	RFCTYPE_INT2   = 9,		///< 2-byte integer. Obsolete, not directly supported by ABAP/4
	RFCTYPE_INT1   = 10,	///< 1-byte integer, unsigned. Obsolete, not directly supported by ABAP/4
	RFCTYPE_NULL  = 14,		///< Not supported data type.
	RFCTYPE_STRUCTURE = 17,	///< ABAP structure
	RFCTYPE_DECF16  = 23,	///< IEEE 754r decimal floating point, 8 bytes
	RFCTYPE_DECF34  = 24,	///< IEEE 754r decimal floating point, 16 bytes
	RFCTYPE_XMLDATA = 28,	///< No longer used!
	RFCTYPE_STRING = 29,	///< Variable-length, null-terminated string
	RFCTYPE_XSTRING = 30,	///< Variable-length raw string, length in bytes

	_RFCTYPE_max_value		///< the max. value of RFCTYPEs
}RFCTYPE;

/** \enum _RFC_RC
 * \ingroup api
 *
 * RFC return codes used by all functions that do not directly return a handle.
 * Also used as error indicator in the structure #RFC_ERROR_INFO::code.
 */
typedef enum _RFC_RC
{
    RFC_OK,						///< Everything O.K. Used by every function
    RFC_COMMUNICATION_FAILURE,	///< Error in Network & Communication layer
    RFC_LOGON_FAILURE,			///< Unable to logon to SAP system. Invalid password, user locked, etc
    RFC_ABAP_RUNTIME_FAILURE,	///< SAP system runtime error (SYSTEM_FAILURE): Shortdump on the backend side
    RFC_ABAP_MESSAGE,			///< The called function module raised an E-, A- or X-Message
    RFC_ABAP_EXCEPTION,			///< The called function module raised an Exception (RAISE or MESSAGE ... RAISING)
    RFC_CLOSED,					///< Connection closed by the other side
    RFC_CANCELED,				///< No longer used
    RFC_TIMEOUT,				///< Time out
    RFC_MEMORY_INSUFFICIENT,	///< Memory insufficient
    RFC_VERSION_MISMATCH,		///< Version mismatch
    RFC_INVALID_PROTOCOL,		///< The received data has an unsupported format
    RFC_SERIALIZATION_FAILURE,	///< A problem while serializing or deserializing RFM parameters
    RFC_INVALID_HANDLE,			///< An invalid handle was passed to an API call
    RFC_RETRY,					///< RfcListenAndDispatch did not receive an RFC request during the timeout period
    RFC_EXTERNAL_FAILURE,		///< Error in external custom code. (E.g in the function handlers or tRFC handlers.) Results in SYSTEM_FAILURE
    RFC_EXECUTED,				///< Inbound tRFC Call already executed (needs to be returned from RFC_ON_CHECK_TRANSACTION in case the TID is already known)
    RFC_NOT_FOUND,				///< Function or structure definition not found (Metadata API)
    RFC_NOT_SUPPORTED,			///< The operation is not supported on that handle
    RFC_ILLEGAL_STATE,			///< The operation is not supported on that handle at the current point of time (e.g trying a callback on a server handle, while not in a call)
    RFC_INVALID_PARAMETER,		///< An invalid parameter was passed to an API call, (e.g invalid name, type or length)
    RFC_CODEPAGE_CONVERSION_FAILURE, ///< Codepage conversion error
    RFC_CONVERSION_FAILURE,		///< Error while converting a parameter to the correct data type
    RFC_BUFFER_TOO_SMALL,		///< The given buffer was to small to hold the entire parameter. Data has been truncated.
    RFC_TABLE_MOVE_BOF,			///< Trying to move the current position before the first row of the table
    RFC_TABLE_MOVE_EOF,			///< Trying to move the current position after the last row of the table
    RFC_START_SAPGUI_FAILURE,   ///< Failed to start and attach SAPGUI to the RFC connection 
	RFC_UNKNOWN_ERROR			///< "Something" went wrong, but I don't know what...
}RFC_RC;

/** \enum _RFC_ERROR_GROUP
 * \ingroup api
 *
 * Groups several error conditions together, depending on the "layer" to which they belong.
 * Used in the structure #RFC_ERROR_INFO::group.
 */
typedef enum _RFC_ERROR_GROUP
{
    OK,								///< OK
	ABAP_APPLICATION_FAILURE,		///< ABAP Exception raised in ABAP function modules
	ABAP_RUNTIME_FAILURE,			///< ABAP Message raised in ABAP function modules or in ABAP runtime of the backend (e.g Kernel)
    LOGON_FAILURE,					///< Error message raised when logon fails 
	COMMUNICATION_FAILURE,			///< Problems with the network connection (or backend broke down and killed the connection)
	EXTERNAL_RUNTIME_FAILURE,		///< Problems in the RFC runtime of the external program (i.e "this" library)
	EXTERNAL_APPLICATION_FAILURE	///< Problems in the external program (e.g in the external server implementation)
}RFC_ERROR_GROUP;

/** \struct _RFC_ERROR_INFO
 * \ingroup api
 *
 * Used in all functions of the NW RFC library to return detailed information about
 * an error that has just occurred. This can be an error that the communication partner
 * sent back to us, an error that occured in the network layer or operating system,
 * an internal error in the NW RFC library or an error that the application programmer
 * (i.e. you) has committed...
 *
 * Within a server function implementation, the application programmer (you) can return
 * this structure to the RFC library in order to specify the error type & message that
 * you want to send back to the backend.
 */
typedef struct _RFC_ERROR_INFO
{
    RFC_RC code;					///< Error code. Should be the same as the API returns if the API has return type RFC_RC
    RFC_ERROR_GROUP group;          ///< Error group
    SAP_UC key[128];				///< Error key
    SAP_UC message[512];			///< Error message
    SAP_UC abapMsgClass[20+1];		///< ABAP message ID , or class
    SAP_UC abapMsgType[1+1];		///< ABAP message type, e.g. 'E', 'A' or 'X'
    RFC_NUM abapMsgNumber[3 + 1];	///< ABAP message number
    SAP_UC abapMsgV1[50+1];			///< ABAP message details field 1, corresponds to SY-MSGV1 
    SAP_UC abapMsgV2[50+1];			///< ABAP message details field 2, corresponds to SY-MSGV2 
    SAP_UC abapMsgV3[50+1];			///< ABAP message details field 3, corresponds to SY-MSGV3 
    SAP_UC abapMsgV4[50+1];			///< ABAP message details field 4, corresponds to SY-MSGV4 
}RFC_ERROR_INFO;

/** \struct _RFC_ATTRIBUTES
 * \ingroup connection
 *
 * Structure returned by RfcGetConnectionAttributes() giving some
 * information about the partner system on the other side of this RFC connection.
 */
typedef struct _RFC_ATTRIBUTES
{
    SAP_UC dest[64+1];				///< RFC destination
    SAP_UC host[100+1];				///< Own host name
    SAP_UC partnerHost[100+1];		///< Partner host name
    SAP_UC sysNumber[2+1];			///< R/3 system number
    SAP_UC sysId[8+1];				///< R/3 system ID
    SAP_UC client[3+1];				///< Client ("Mandant")
    SAP_UC user[12+1];				///< User
    SAP_UC language[2+1];			///< Language
    SAP_UC trace[1+1];				///< Trace level (0-3)
    SAP_UC isoLanguage[2+1];		///< 2-byte ISO-Language
    SAP_UC codepage[4+1];           ///< Own code page
    SAP_UC partnerCodepage[4+1];	///< Partner code page
    SAP_UC rfcRole[1+1];			///< C/S: RFC Client / RFC Server
    SAP_UC type[1+1];				///< 2/3/E/R: R/2,R/3,Ext,Reg.Ext
    SAP_UC partnerType[1+1];		///< 2/3/E/R: R/2,R/3,Ext,Reg.Ext
    SAP_UC rel[4+1];				///< My system release
    SAP_UC partnerRel[4+1];			///< Partner system release
    SAP_UC kernelRel[4+1];			///< Partner kernel release
    SAP_UC cpicConvId[8 + 1];		///< CPI-C Conversation ID
    SAP_UC progName[128+1];			///< Name of the calling APAB program (report, module pool)
    SAP_UC reserved[86];			///< Reserved for later use
}RFC_ATTRIBUTES, *P_RFC_ATTRIBUTES;


typedef RFC_CHAR RFC_ABAP_NAME[30+1];			///< Name of ABAP function, function parameter or field in a structure. (null-terminated)
typedef RFC_CHAR RFC_PARAMETER_DEFVALUE[30+1];	///< Default value of a function module parameter. (null-terminated)
typedef RFC_CHAR RFC_PARAMETER_TEXT[79+1];		///< Parameter description for a function module parameter. (null-terminated)

typedef struct _RFC_TYPE_DESC_HANDLE {void* handle;} *RFC_TYPE_DESC_HANDLE;			///< Handle to a cached metadata description of a structure or table type.
typedef struct _RFC_FUNCTION_DESC_HANDLE {void* handle;} *RFC_FUNCTION_DESC_HANDLE;	///< Handle to a cached metadata description of a function module.

typedef struct RFC_DATA_CONTAINER {void* handle;} *DATA_CONTAINER_HANDLE;	///< Handle to a general data container (structure, table or function module).
typedef DATA_CONTAINER_HANDLE RFC_STRUCTURE_HANDLE;							///< Handle to a data container for a structure.
typedef DATA_CONTAINER_HANDLE RFC_FUNCTION_HANDLE;							///< Handle to a data container for a function module.
typedef DATA_CONTAINER_HANDLE RFC_TABLE_HANDLE;								///< Handle to a data container for a table.

typedef struct _RFC_CONNECTION_HANDLE {void* handle;} *RFC_CONNECTION_HANDLE;	///< Handle to an RFC connection (client connection or server connection).
typedef struct _RFC_TRANSACTION_HANDLE {void* handle;} *RFC_TRANSACTION_HANDLE;	///< Handle to a data container for a tRFC/qRFC LUW. Can be filled with several RFC_FUNCTION_HANDLEs.

/** \struct _RFC_CONNECTION_PARAMETER
 * \ingroup connection
 *
 * Structure used for connecting to a backend system via RfcOpenConnection() or
 * RfcRegisterServer(). For a list of supported parameters see these two functions.
 */
typedef struct _RFC_CONNECTION_PARAMETER
{
    const SAP_UC * name;
    const SAP_UC * value;
}RFC_CONNECTION_PARAMETER,*P_RFC_CONNECTION_PARAMETER;

/** \struct _RFC_FIELD_DESC
 * \ingroup repository
 *
 * Structure for reading (RfcGetFieldDescByIndex() or RfcGetFieldDescByName())
 * or defining (RfcAddTypeField()) the properties of a field in a structure/table.
 */
typedef struct _RFC_FIELD_DESC
{
	RFC_ABAP_NAME	name;		///< Field name, null-terminated string
	RFCTYPE		type;			///< Field data type
    /*SAPUNICODEOK_MIXEDLEN*/
	unsigned	nucLength;		///< Field length in bytes in a 1-byte-per-SAP_CHAR system
    /*SAPUNICODEOK_MIXEDLEN*/
	unsigned	nucOffset;		///< Field offset in bytes in a 1-byte-per-SAP_CHAR system
    /*SAPUNICODEOK_MIXEDLEN*/
	unsigned	ucLength;		///< Field length in bytes in a 2-byte-per-SAP_CHAR system
    /*SAPUNICODEOK_MIXEDLEN*/
	unsigned	ucOffset;		///< Field offset in bytes in a 2-byte-per-SAP_CHAR system
	unsigned    decimals;		///< If the field is of type "packed number" (BCD), this member gives the number of decimals.
	RFC_TYPE_DESC_HANDLE typeDescHandle; ///< Pointer to an RFC_STRUCTURE_DESC structure for the nestesd sub-type if the type field is RFCTYPE_STRUCTURE or RFCTYPE_TABLE */
    void* extendedDescription;	///< Not used by the NW RFC library. This parameter can be used by applications that want to store additional information in the repository (like F4 help values, e.g.).
}RFC_FIELD_DESC,*P_RFC_FIELD_DESC;

/** \enum _RFC_DIRECTION
 * \ingroup repository
 *
 * Used in #RFC_PARAMETER_DESC::direction for specifying the direction of a function module parameter.
 */
typedef enum _RFC_DIRECTION
{
	RFC_IMPORT   = 0x01,					///< Import parameter. This corresponds to ABAP IMPORTING parameter.
	RFC_EXPORT   = 0x02,					///< Export parameter. This corresponds to ABAP EXPORTING parameter.
	RFC_CHANGING = RFC_IMPORT | RFC_EXPORT,	///< Import and export parameter. This corresponds to ABAP CHANGING parameter.
	RFC_TABLES    = 0x04 | RFC_CHANGING		///< Table parameter. This corresponds to ABAP TABLES parameter.
}RFC_DIRECTION;

/** \struct _RFC_PARAMETER_DESC
 * \ingroup repository
 *
 * Structure for reading (RfcGetParameterDescByIndex() or RfcGetParameterDescByName())
 * or defining (RfcAddParameter()) the properties of a parameter in a function module.
 */
typedef struct _RFC_PARAMETER_DESC
{
	RFC_ABAP_NAME	name;		///< Parameter name, null-terminated string
	RFCTYPE		type;			///< Parameter data type
	RFC_DIRECTION direction;	///< Specifies whether the parameter is an input, output or bi-directinal parameter
	unsigned	nucLength;		///< Parameter length in bytes in a 1-byte-per-SAP_CHAR system
	unsigned	ucLength;		///< Parameter length in bytes in a 2-byte-per-SAP_CHAR system
	unsigned    decimals;		///< Gives the number of decimals in case or a packed number (BCD)
	RFC_TYPE_DESC_HANDLE typeDescHandle;	///< Handle to the structure definition in case this parameter is a structure or table
    RFC_PARAMETER_DEFVALUE defaultValue;	///< Default value as defined in SE37
	RFC_PARAMETER_TEXT parameterText;		///< Description text of the parameter as defined in SE37. Null-terminated string.
	RFC_BYTE     optional;		///< Specifies whether this parameter is defined as optional in SE37. 1 is optional, 0 non-optional
    void* extendedDescription;	///< This field can be used by the application programmer (i.e. you) to store arbitrary extra information.
}RFC_PARAMETER_DESC,*P_RFC_PARAMETER_DESC;

/** \struct _RFC_EXCEPTION_DESC
 * \ingroup repository
 *
 * Structure for reading (RfcGetExceptionDescByIndex() or RfcGetExceptionDescByName())
 * or defining (RfcAddException()) the properties of an exception key in a function module.
 */
typedef struct _RFC_EXCEPTION_DESC
{
    SAP_UC key[128];		///< Exception key
    SAP_UC message[512];	///< Error message (exception text as defined in SE37)
} RFC_EXCEPTION_DESC, *P__RFC_EXCEPTION_DESC;


#define RFC_TID_LN 24
typedef SAP_UC RFC_TID[RFC_TID_LN+1];


#ifdef __cplusplus
extern "C"
{
#endif
	typedef RFC_RC (SAP_API* RFC_SERVER_FUNCTION)(RFC_CONNECTION_HANDLE rfcHandle, RFC_FUNCTION_HANDLE funcHandle, RFC_ERROR_INFO* errorInfo);
	typedef RFC_RC (SAP_API* RFC_ON_CHECK_TRANSACTION)(RFC_CONNECTION_HANDLE rfcHandle, SAP_UC const *tid);
	typedef RFC_RC (SAP_API* RFC_ON_COMMIT_TRANSACTION)(RFC_CONNECTION_HANDLE rfcHandle, SAP_UC const *tid);
	typedef RFC_RC (SAP_API* RFC_ON_ROLLBACK_TRANSACTION)(RFC_CONNECTION_HANDLE rfcHandle, SAP_UC const *tid);
	typedef RFC_RC (SAP_API* RFC_ON_CONFIRM_TRANSACTION)(RFC_CONNECTION_HANDLE rfcHandle, SAP_UC const *tid);
	typedef RFC_RC (SAP_API* RFC_FUNC_DESC_CALLBACK)(SAP_UC const *functionName, RFC_ATTRIBUTES rfcAttributes, RFC_FUNCTION_DESC_HANDLE *funcDescHandle);
    typedef RFC_RC (SAP_API* RFC_PM_CALLBACK)(RFC_CONNECTION_HANDLE rfcHandle, SAP_UC const *functionName, SAP_RAW *eppBuffer, size_t eppBufferSize, size_t *eppLength); 


    /* ***********************************************************************/
    /*                                                                       */
    /*  General API & Utilities                                              */
    /*                                                                       */
    /* ***********************************************************************/

	/**
	 * \brief  Initialization of internal variables
	 * \ingroup general
	 *
	 * Sets up the internal state of the sapnwrfc library and initially reads
	 * and evaluates the sapnwrfc.ini file. In case the content or location of
	 * the sapnwrfc.ini file changes lateron, reload it via RfcReloadIniFile().
	 * %RfcInit() no longer needs to be called explicitly. The RFC library does
	 * this automatically on DLL load.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcInit(void);

	/**
	 * \brief  Get information about currently loaded sapnwrfc library.
	 * \ingroup general
	 *
	 * Fills the provided unsigneds with the SAP release values, e.g. *majorVersion = 7,
	 * *minorVersion = 10, *patchLevel = 42.
	 * \out *majorVersion 
	 * \out *minorVersion 
	 * \out *patchLevel 
	 * \return Version information in string format.
	 * \warning Don't free the returned SAP_UC pointer, it's static memory...
	 */
	DECL_EXP const SAP_UC* SAP_API RfcGetVersion(unsigned* majorVersion, unsigned* minorVersion, unsigned* patchLevel);

	/**
	 * \brief  Sets the directory in which to search for the sapnwrfc.ini file.
	 * \ingroup general
	 *
	 * By default the sapnwrfc library searches for the sapnwrfc.ini in the current
	 * working directory of the process. If you want to keep it in a different directory,
	 * use this function to tell the sapnwrfc library about the new path.
	 * \note After you have changed the directory, the NW RFC lib automatically loads
	 * the contents of the new sapnwrfc.ini file from that directory.
	 *
	 * \in *pathName The full (absolute) path of the directory, in which the sapnwrfc
	 * library should look for the sapnwrfc.ini file. A path relativ to the current
	 * working directory of the process also works.
	 * \out *errorInfo Detail information in case anything goes wrong.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcSetIniPath(const SAP_UC* pathName, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Loads the contents of the sapnwrfc.ini file into memory.
	 * \ingroup general
	 *
	 * Searches the directory given by RfcSetIniPath() (or the current working directory)
	 * for the file sapnwrfc.ini and loads its contents into memory.
	 *
	 * \out *errorInfo Detail information in case anything goes wrong. Note: if a file
	 * with the name sapnwrfc.ini does not exist in the given directory, this is not
	 * considered an error! Default settings are used in this case.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcReloadIniFile(RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Sets the current trace level of the specified RFC connection or destination to the new value.
	 * \ingroup general
	 *
	 * \note If both of connection and destination are NULL, this function sets the "global"
	 * trace level. See below.
     * \in connection A handle to a currently open RFC connection (client or server connection).
	 * The new trace level will be effective immediately.
     * \in *destination Null-terminated string specifying a client or server destination as defined
	 * via a DEST=... entry in sapnwrfc.ini. The new trace level will be used for new connections
	 * to that destination opened after the %RfcSetTraceLevel() call. Already existing connections to
	 * that destination will not be effected.
     * \in traceLevel The new trace level. Must be between 0 and 3. The meaning of those four values
	 * is as follows:
	 * - 0: Off. Only severe errors are logged to the dev_rfc.trc file.
	 * - 1: Brief. All API calls (except for the setter and getter functions) and important attributes
	 *      like codepages, RFC headers, logon parameters are traced. Trace is written to a file named
	 *      rfc&lt;pid&gt;.trc or rfc&lt;pid&gt;_&lt;tid&gt;.trc, depending on whether tracing is done
	 *      on a "per-process" basis or a "per-thread" basis. &lt;pid&gt; is the current process ID,
	 *      &lt;tid&gt; the current thread ID.
	 * - 2: Verbose. In addition to 1, the values of the "scalar" RFC parameters as well as the contents
	 *      of the network containers are traced. Scalar parameters are primitive types (CHAR, INT, FLOAT, etc)
	 *      and flat structures.
	 * - 3: Full. In addition to 2 the contents of nested structures and tables as well as all API calls
	 *      of setter and getter functions are traced.
	 * \out *errorInfo Detail information in case the specified connection or destination does not exist.
	 * \return RFC_OK, RFC_INVALID_HANDLE or RFC_INVALID_PARAMETER
	 *
	 * \note In general RFC trace can be activated/deactivated in 6 different ways:
	 * - By setting the parameter RFC_TRACE=[0|1|2|3] in the DEFAULT section of the sapnwrfc.ini file.
	 *   This value applies to all destinations, for which no explicit trace level has been set.
	 *   ("Global" trace level.)
	 * - By setting the parameter TRACE=[0|1|2|3] in a specific destination section of sapnwrfc.ini.
	 *   it applies to that destination only and overrules the "global" trace level from the DEFAULT section.
	 * - By setting the environment variable RFC_TRACE=[0|1|2|3]. This overrules the setting from the
	 *   DEFAULT section of sapnwrfc.ini.
	 * - Via %RfcSetTraceLevel(). If connection and destination are NULL, this function sets the global
	 *   trace level and overrules the value from the DEFAULT section of sapnwrfc.ini as well as the environment
	 *   variable RFC_TRACE. If connection is non-NULL, it sets the trace level for the current connection only,
	 *   and if destination is non-NULL, it sets the trace level for that destination, overruling the value from
	 *   this destination's section in the sapnwrfc.ini file.
	 * - By passing a {name=TRACE, value=[0|1|2|3]} pair in the RFC_CONNECTION_PARAMETER array used in
	 *   RfcOpenConnection(), RfcRegisterServer() or RfcStartServer(). If that RFC_CONNECTION_PARAMETER array
	 *   also contains a {name=DEST, value=...} pair, the trace parameter from the array overrules the value
	 *   from this destination's sapnwrfc.ini section.
	 * - In case the program is a server program: by activating the trace flag for the corresponding destination
	 *   in SM59. The trace setting on backend side is then "inherited" by the external side.
	 *
	 * \note For more information on trace settings see the sample sapnwrfc.ini file contained in the demo folder.
	 */
	DECL_EXP RFC_RC SAP_API RfcSetTraceLevel(RFC_CONNECTION_HANDLE connection, SAP_UC* destination, unsigned traceLevel, RFC_ERROR_INFO* errorInfo);

    /**
     * \brief  Converts data in UTF-8 format to SAP_UC strings.
     * \ingroup general
     * 
     * \in *utf8 Pointer to UTF-8 data to be converted
     * \in utf8Length Number of bytes to convert
     * \out *sapuc Pre-allocated output buffer, which will receive the result. Output will be null-terminated.
     * \inout *sapucSize Needs to be filled with the size of the given output buffer in SAP_UC characters.
	 * If the given buffer turns out to be too small (return code RFC_BUFFER_TOO_SMALL), it will be filled
	 * with the required buffer size that would be necessary to convert the given input data.
     * \out *resultLength If the output buffer was large enough, resultLength will be filled with the
	 * length of the output string in SAP_UC characters.
     * \out *errorInfo Will be filled with additional error information in case of an error.
     * \return RFC_RC
     */
    DECL_EXP RFC_RC SAP_API RfcUTF8ToSAPUC(const RFC_BYTE *utf8, unsigned utf8Length,  SAP_UC *sapuc,  unsigned *sapucSize, unsigned *resultLength, RFC_ERROR_INFO *errorInfo);

	/**
	 * \brief  Converts data in SAP_UC format to UTF-8 format
	 * \ingroup general
	 * 
	 * \in *sapuc Pointer to SAP_UC data to be converted
	 * \in sapucLength Number of characters to convert
	 * \out *utf8 Pre-allocated output buffer, which will receive the result. Output will be null-terminated.
	 * \inout *utf8Size Needs to be filled with the size of the given output buffer in bytes.
	 * If the given buffer turns out to be too small (return code RFC_BUFFER_TOO_SMALL), it will be filled
	 * with the required buffer size that would be necessary to convert the given input data.
	 * \out *resultLength If the output buffer was large enough, resultLength will be filled with the
	 * length of the output string in bytes.
	 * \out *errorInfo Will be filled with additional error information in case of an error.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcSAPUCToUTF8(const SAP_UC *sapuc,  unsigned sapucLength, RFC_BYTE *utf8, unsigned *utf8Size,  unsigned *resultLength, RFC_ERROR_INFO *errorInfo);

    /**
     * \brief  Converts an RFC_RC return code to a human readable string for logging purposes.
     * \ingroup general
     * 
     * \in rc Return code to covert to string
     * \return String representation of the return code
	 * \warning Don't free the returned SAP_UC pointer -- its's static memory...
     */
    DECL_EXP const SAP_UC* SAP_API RfcGetRcAsString(RFC_RC rc);

    /**
     * \brief  Converts an RFCTYPE data type indicator to a human readable string for logging purposes.
     * \ingroup general
     * 
     * \in type Data type indicator to convert
     * \return String representation of the type
	 * \warning Don't free the returned SAP_UC pointer -- its's static memory...
     */
    DECL_EXP const SAP_UC* SAP_API RfcGetTypeAsString(RFCTYPE type);

    /**
     * \brief  Converts an RFC_DIRECTION direction indicator to a human readable string for logging purposes.
     * \ingroup general
     * 
     * \in direction Direction indicator to convert
     * \return String representation of the direction
	 * \warning Don't free the returned SAP_UC pointer -- its's static memory...
     */
    DECL_EXP const SAP_UC* SAP_API RfcGetDirectionAsString(RFC_DIRECTION direction);


    /* ***********************************************************************/
    /*                                                                       */
    /*  Connection related API                                               */
    /*                                                                       */
    /* ***********************************************************************/

	/**
	 * \brief  Opens an RFC client connection for invoking ABAP function modules in an R/3 backend.
	 * \ingroup connection
	 *
	 * Opens a client connection to an SAP System. The connectionParams may contain the following name-value pairs:
	 * - client, user, passwd, lang, trace
	 *
	 * and additionally one of
	 * -# Direct application server logon: ashost, sysnr.
	 * -# Logon with load balancing: mshost, msserv, sysid, group.\n
	 *    msserv is needed only, if the service of the message server is
	 *    not defined as sapms<SYSID> in /etc/services.
	 *
	 * When logging on with SNC, user&passwd are to be replaced by
	 * - snc_qop, snc_myname, snc_partnername and optionally snc_lib.
	 *
	 * (If snc_lib is not specified, the RFC library uses the "global" GSS library
	 * defined via environment variable SNC_LIB.)
	 *
	 * When logging on with SSO Ticket, you can use mysapsso2 instead of user&passwd.
	 * The old SSO format (mysapsso) is no longer supported.
	 *
	 * Alternatively the connection parameters can be defined in the config file
	 * sapnwrfc.ini. In this case you just pass the parameter dest=... and all
	 * parameters that are missing in the sapnwrfc.ini entry into %RfcOpenConnection().
	 *
	 * For a complete list of logon parameters to be used in connectionParams as well as in the
	 * sapnwrfc.ini file, see the sample sapnwrfc.ini file in the SDK's demo folder.
	 *
	 * If the logon was ok, %RfcOpenConnection() returns a client connection handle, which can be used in RfcInvoke().
	 * Otherwise the return value is NULL and errorInfo contains a detailed error description.
	 * errorInfo->code will be one of:
	 * - RFC_INVALID_PARAMETER			One of the connectionParams was invalid
	 * - RFC_COMMUNICATION_FAILURE		Something is wrong with the network or network settings
	 * - RFC_LOGON_FAILURE				Invalid user/password/ticket/certificate
	 * - RFC_ABAP_RUNTIME_FAILURE		Something is wrong with the R/3 backend
	 * - RFC_MEMORY_INSUFFICIENT		A malloc failed when trying to allocate a temporary buffer
	 *
	 * 
	 * \in *connectionParams An array of RFC_CONNECTION_PARAMETERs with the names as described above
	 * and the values as necessary in your landscape.
	 * \in paramCount Number of parameters in the above array.
	 * \out *errorInfo Returns more error details, if the connect attempt fails.
	 * \return A handle to an RFC client connection that can be used for invoking ABAP function modules in the backend.
	 */
	DECL_EXP RFC_CONNECTION_HANDLE SAP_API RfcOpenConnection(RFC_CONNECTION_PARAMETER const * connectionParams, unsigned paramCount, RFC_ERROR_INFO* errorInfo);

	/** \brief  Registers a server connection at an SAP gateway.
	 * \ingroup connection
	 *
	 * The connectionParams may contain the following name-value pairs:
	 * - gwhost, gwserv, program_id, trace, and the parameters for SNC communication as in RfcOpenConnection().
	 *
	 * Program_id corresponds to an RFC destination in SM59 of type "T" in registration mode.
	 *
	 * For a complete list of logon parameters to be used in connectionParams as well as in the
	 * sapnwrfc.ini file, see the sample sapnwrfc.ini file in the SDK's demo folder.
	 *
	 * If the connection registration was ok, %RfcRegisterServer() returns a server connection handle, which can
	 * be used in RfcListenAndDispatch().
	 * Otherwise the return value is NULL and errorInfo contains information similar to the RfcOpenConnection() case.
	 *
	 * 
	 * \in *connectionParams An array of RFC_CONNECTION_PARAMETERs with the names as described above
	 * and the values as necessary in your landscape.
	 * \in paramCount Number of parameters in the above array.
	 * \out *errorInfo Returns more error details, if the connect attempt fails.
	 * \return A handle to an RFC server connection that can be used for listening for function module requests from the backend.
	 */
	DECL_EXP RFC_CONNECTION_HANDLE SAP_API RfcRegisterServer(RFC_CONNECTION_PARAMETER const * connectionParams, unsigned paramCount, RFC_ERROR_INFO* errorInfo);

	/** \brief  Allows a program to be used as an RFC server which is started by the backend on demand.
	 * \ingroup connection
	 *
	 * This API needs to be called, if the server program is to be started by the R/3 application server.
	 * (RFC destination in SM59 of type "T" in startup mode.)
	 * argc and argv are the inputs of the mainU function. The R/3 application server passes the correct command line to
	 * the program, when starting it up, so you only need to forward these two parameters to %RfcStartServer().
	 * connectionParams is optional and is only needed, if you want to add additional logon parameters to the
	 * ones coming from the command line, e.g for activating trace.
	 *
	 * Like RfcRegisterServer(), the function returns a server connection handle that can be used in RfcListenAndDispatch().
	 * The mechanism of this kind of RFC destination thus works as follows:
	 * -# The R/3 application server opens a telnet connection to the host, where your server program is located, and
	 *    starts the program with the necessary logon parameters. (Or creates a child process, if the startup
	 *    method is "Start on application server".)
	 * -# Your server program calls RfcStartServer, which opens an RFC connection back to the R/3 system.
	 * -# The R/3 system then makes the function call over that RFC connection.
	 *
	 * The main differences of "startup mode" compared to the "registration mode" are:
	 * - Advantage: no logon parameters need to be maintained in the server program. (Unless you want to open
	 *   an additional client connection for looking up function module metadata (RFC_FUNCTION_DESC_HANDLEs) in the
	 *   R/3 DDIC.) 
	 * - Disadvantage: every single function call creates a new process and a telnet connection in addition to
	 *   the actual RFC connection.
	 *
	 * 
	 * \in argc From mainU() (command line supplied by backend)
	 * \in **argv From mainU() (command line supplied by backend)
	 * \in *connectionParams May optionally contain additional logon parameters
	 * \in paramCount Length of the connection parameter array above
	 * \out *errorInfo Returns more error details, if the connect attempt fails.
	 * \return A handle to an RFC server connection that can be used for listening for function module requests from the backend.
	 */
	DECL_EXP RFC_CONNECTION_HANDLE SAP_API RfcStartServer(int argc, SAP_UC **argv, RFC_CONNECTION_PARAMETER const * connectionParams, unsigned paramCount, RFC_ERROR_INFO* errorInfo);

	/** \brief  Closes an RFC connection
	 * \ingroup connection
	 * 
	 * Can be used to close client connections as well as server connections, when they are no longer needed.
	 *
	 *
	 * \in rfcHandle Connection to be closed
	 * \out *errorInfo Error details in case closing the connection fails. (Can usually be ignored...)
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcCloseConnection(RFC_CONNECTION_HANDLE rfcHandle, RFC_ERROR_INFO* errorInfo);

	/** \brief  RFC_RC SAP_API RfcResetServerContext
	 * \ingroup connection
	 * 
	 * Resets the SAP server context ("user context / ABAP session context") associated with the given client
	 * connection, but does not close the connection.
	 *
	 * 
	 * \in rfcHandle The client connection, whose server context is to be reset.
	 * \out *errorInfo Error details in case resetting the server context fails. (Better close the connection in that case.)
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcResetServerContext(RFC_CONNECTION_HANDLE rfcHandle, RFC_ERROR_INFO* errorInfo);

	/** \brief  Ping the remote communication partner through the passed connection handle.
	 * \ingroup connection
	 *
	 * Sends a ping to the backend in order to check, whether the connection is still alive.
	 * Can be used on both, client connections as well as server connections.
	 * \warning Do not use inside a server function implementation.
	 *
	 *
	 * \in rfcHandle The connection to check
	 * \out *errorInfo More error details in case the connection is broken.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcPing(RFC_CONNECTION_HANDLE rfcHandle, RFC_ERROR_INFO* errorInfo);

	/** \brief  Returns details about the current client or server connection.
	 * \ingroup connection
	 *
	 * See documentation of RFC_ATTRIBUTES.
	 *
	 * 
	 * \in rfcHandle RFC connection
	 * \out *attr Information about the current connection and the communication partner on the other side.
	 * \out *errorInfo Additional error information (e.g. connection already closed).
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcGetConnectionAttributes(RFC_CONNECTION_HANDLE rfcHandle, RFC_ATTRIBUTES *attr, RFC_ERROR_INFO* errorInfo);

	/** \brief  Gets the partner's SSO2 ticket, if any.
	 * \ingroup connection
	 * 
	 *  Can be used only with a server connection inside the implementation of a server function.
	 *
	 * 
	 * \in rfcHandle RFC server connection
	 * \out *ssoTicket Pre-allocated buffer, which will receive the backend user's SSO2 ticket (signed user information in base64 format)
	 * \inout *length Needs to be filled with the buffer length of ssoTicket. The return value will be the string
	 * length of the returned ticket (if buffer was large enough) or the required buffer size (if RFC_BUFFER_TOO_SMALL).
	 * \out *errorInfo More error details in case there is no ticket.
	 * \return RFC_RC
	 * \warning 
	 */
	DECL_EXP RFC_RC SAP_API RfcGetPartnerSSOTicket(RFC_CONNECTION_HANDLE rfcHandle, SAP_UC *ssoTicket, unsigned *length, RFC_ERROR_INFO* errorInfo);

	/** \brief  Gets the partner's SNC name, if any. 
	 * \ingroup connection
	 * 
	 * 
	 * \in rfcHandle RFC client or server connection
	 * \out *sncName Pre-allocated buffer, which will receive the backend user's SNC name (null-terminated string).
	 * \in length Size of the pre-allocated buffer. This information is coming from the GSS library, therefore
	 * unfortunately the feature of assigning the used/required length to an output parameter is not possible in this case.
	 * The maximum length of an SNC name is 256.
	 * \out *errorInfo More error details in case SNC is not active.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcGetPartnerSNCName(RFC_CONNECTION_HANDLE rfcHandle, SAP_UC *sncName, unsigned length, RFC_ERROR_INFO* errorInfo);

	/** \brief  Gets partner's SNC key, if any.
	 * \ingroup connection
	 * 
	 * 
	 * \in rfcHandle RFC client or server connection
	 * \out *sncKey Pre-allocated buffer, which will receive the backend user's SNC key.
	 * \inout *length Needs to be filled with the buffer length of ssoTicket. The return value will be the byte
	 * length of the returned key (if buffer was large enough). Unfortunately in case of RFC_BUFFER_TOO_SMALL
	 * the required size is not returned by the GSS library.
	 * The maximum length of an SNC key is 1024.
	 * \out *errorInfo More error details in case SNC is not active.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcGetPartnerSNCKey(RFC_CONNECTION_HANDLE rfcHandle, SAP_RAW *sncKey, unsigned *length, RFC_ERROR_INFO* errorInfo);

	/** \brief  Converts SNC name to SNC key.
	 * \ingroup connection
	 * 
	 * 
	 * \in *sncLib Optional: file name of the GSS library to be used for the conversion. If not specified, the
	 * "global" GSS library (environment variable SNC_LIB) will be used.
	 * \in *sncName Null-terminated SNC name to be converted.
	 * \out *sncKey Pre-allocated buffer, which will receive the corresponding SNC key.
	 * \inout *keyLength Needs to be filled with the buffer length of sncKey. The return value will be byte length
	 * of the SNC key (if buffer was large enough). Unfortunately in case of RFC_BUFFER_TOO_SMALL
	 * the required size is not returned by the GSS library.
	 * The maximum length of an SNC key is 1024.
	 * \out *errorInfo More error details in case something goes wrong.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcSNCNameToKey(SAP_UC const *sncLib, SAP_UC const *sncName, SAP_RAW *sncKey, unsigned *keyLength, RFC_ERROR_INFO* errorInfo);

	/** \brief  Converts SNC key to SNC name.
	 * \ingroup connection
	 * 
	 * 
	 * \in *sncLib Optional: file name of the GSS library to be used for the conversion. If not specified, the
	 * "global" GSS library (environment variable SNC_LIB) will be used.
	 * \in *sncKey SNC key to be converted.
	 * \in keyLength Byte length of the given SNC key
	 * \out *sncName Pre-allocated buffer, which will receive the corresponding (null-terminated) SNC name.
	 * \in nameLength Size of the given sncName buffer. (The maximum length of an SNC name is 256.)
	 * \out *errorInfo More error details in case something goes wrong.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcSNCKeyToName(SAP_UC const *sncLib, SAP_RAW const *sncKey, unsigned keyLength ,SAP_UC *sncName, unsigned nameLength, RFC_ERROR_INFO* errorInfo);


	/** \brief  Listens on a server connection handle and waits for incoming RFC calls from the R/3 system.
	 * \ingroup connection
	 * 
	 * The mechanism for dispatching incoming function calls works as follows:
	 * First %RfcListenAndDispatch() checks, whether for the current combination of R/3 SystemID and function
	 * module name a callback function has been installed via RfcInstallServerFunction(). If not, it checks,
	 * whether a callback function for SystemID=NULL has been installed via RfcInstallServerFunction().If not,
	 * it checks, whether a global callback function has been installed via RfcInstallGenericServerFunction().
	 *
	 * If a callback function has been found, the RFC call will be dispatched to that function for processing,
	 * and %RfcListenAndDispatch() returns the return code of the callback function.
	 * Otherwise %RfcListenAndDispatch() returns a SYSTEM_FAILURE to the R/3 backend and the return code
	 * RFC_NOT_FOUND to the caller.
	 *
	 * In general the return codes of %RfcListenAndDispatch() have the following meaning:
	 * - RFC_OK\n		A function call was processed successfully.
	 * - RFC_RETRY\n	No function call came in within the specified timeout period. ("timeout" is given in seconds.)
	 * - RFC_ABAP_EXCEPTION\n	A function call was processed and ended with a defined ABAP Exception, which has
	 *					been returned to the backend.
	 *
	 * In the above three cases "rfcHandle" is still open and can be used to listen for the next request.
	 *
	 * - RFC_ABAP_MESSAGE\n	A function call was started to be processed, but was aborted with an ABAP A-, E- or X-Message.
	 *				The message parameters have been returned to the backend (and can be evaluated there via
	 *				the sy-msgid, sy-msgtype, sy-msgno, sy-msgv1, ..., sy-msgv4 parameters).
	 * - RFC_EXTERNAL_FAILURE\n	A function call was started to be processed, but was aborted with a "SYSTEM_FAILURE",
	 *				which has been returned to the backend.
	 * - RFC_COMMUNICATION_FAILURE\n	The connection broke down while processing the function call. No response
	 *				has been sent to the backend.
	 * - RFC_CLOSED\n	The connection has been closed by the backend side (SMGW, SM04). No response
	 *				has been sent to the backend.
	 * - RFC_NOT_FOUND\n	No handler has been found for the current function module name. A SYSTEM_FAILURE has
	 *				been returned to the R/3 backend.
	 *
	 * In these five cases the connection has been closed, so the "rfcHandle" needs to be refreshed via RfcRegisterServer.
	 *
	 * - RFC_INVALID_HANDLE\n	"rfcHandle" is invalid or points to a connection that has already been closed.
	 *
	 * 
	 * \in rfcHandle Server connection on which to listen for incoming requests.
	 * \in timeout Number of seconds to wait for an incoming request.
	 * \out *errorInfo Additional error information.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcListenAndDispatch (RFC_CONNECTION_HANDLE rfcHandle, int timeout, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Executes a function module in the backend system.
	 * \ingroup connection
	 *
	 * The return codes have the following meaning:
	 * - RFC_OK\n		The function call was executed successfully.
	 * - RFC_ABAP_EXCEPTION\n	The function call was executed and ended with a defined ABAP Exception. The key of the
	 *					exception can be obtained from errorInfo->key.
	 *
	 * In the above two cases "rfcHandle" is still open and can be used to execute further function call.
	 *
	 * - RFC_ABAP_MESSAGE\n	The function call was started to be processed, but was aborted with an ABAP Message.
	 *				The message parameters can be obtained from errorInfo->abapMsgClass, errorInfo->abapMsgType,
	 *				errorInfo->abapMsgNumber, errorInfo->abapMsgV1, ..., errorInfo->abapMsgV4.
	 * - RFC_ABAP_RUNTIME_FAILURE\n	The function call was started to be processed, but was aborted with a SYSTEM_FAILURE
	 *				(e.g division by zero, unhandled exception, etc in the backend system).
	 *				Details can be obtained from errorInfo->message.
	 * - RFC_COMMUNICATION_FAILURE\n	The connection broke down while processing the function call.
	 *				Details can be obtained from errorInfo->message.
	 *
	 * In these three cases the connection has been closed, so the "rfcHandle" needs to be refreshed via RfcOpenConnection.
	 *
	 * - RFC_INVALID_HANDLE\n	"rfcHandle" is invalid or points to a connection that has already been closed.
	 *
	 * 
	 * \in rfcHandle Client connection over which to execute the function module.
	 * \inout funcHandle Data container containing the input data for the function module.
	 * %RfcInvoke() will write the FM's output data into this container.
	 * \out *errorInfo Additional error information.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcInvoke(RFC_CONNECTION_HANDLE rfcHandle, RFC_FUNCTION_HANDLE funcHandle, RFC_ERROR_INFO* errorInfo);


    /* ***********************************************************************/
    /*                                                                       */
    /*  Transaction (tRFC & qRFC) API                                        */
    /*                                                                       */
    /* ***********************************************************************/

	/**
	 * \brief  Retrieves a unique 24-digit transaction ID from the backend.
	 * \ingroup transaction
	 * 
	 * 
	 * \in rfcHandle Client connection to a backend.
	 * \out tid Will be filled with the transaction ID.
	 * \out *errorInfo Error information in case there is a problem with the connection.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcGetTransactionID(RFC_CONNECTION_HANDLE rfcHandle, RFC_TID tid, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Creates a container for executing a (multi-step) transactional call.
	 * \ingroup transaction
	 * 
	 * If queueName is NULL, tRFC will be used, otherwise qRFC. Use RfcInvokeInTransaction() to
	 * add one (or more) function modules to the transactional call. When sending this transactional
	 * call to the backend via RfcSubmitTransaction(), the backend will then treat
	 * all function modules in the RFC_TRANSACTION_HANDLE as one LUW.
	 *
	 * \in rfcHandle Client connection to the backend, into which you want to send this tRFC/qRFC LUW.
	 * \in tid A unique 24 character ID.
	 * \in *queueName For tRFC set this to NULL, for qRFC specify the name of a qRFC inbound queue in the backend.
	 * \out *errorInfo Error information in case there is a problem with the connection.
	 * \return A data container that can be filled with several function modules.
	 */
	DECL_EXP RFC_TRANSACTION_HANDLE SAP_API RfcCreateTransaction(RFC_CONNECTION_HANDLE rfcHandle, RFC_TID tid, SAP_UC const *queueName, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Adds a function module call to a transaction. Can be used multiple times on one tHandle.
	 * \ingroup transaction
	 * 
	 * \in tHandle A transaction handle created via RfcCreateTransaction().
	 * \in funcHandle An RFC_FUNCTION_HANDLE, whose IMPORTING, CHANGING and TABLES parameters have been filled.
	 * \note that tRFC/qRFC calls have no return values, so the EXPORTING parameters of this function handle will
	 * not be filled, nor will the changes to the CHANGING/TABLES parameters be returned.
	 * \out *errorInfo Actually there is nothing that can go wrong here except for invalid handles and out of memory.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcInvokeInTransaction(RFC_TRANSACTION_HANDLE tHandle, RFC_FUNCTION_HANDLE funcHandle, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Executes the entire LUW in the backend system as an "atomic unit".
	 * \ingroup transaction
	 * 
	 * This step can be repeated until it finally succeeds (RFC_OK). The transaction handling in the backend
	 * system protects against duplicates (until you remove the TID from the backend's status tables using
	 * RfcConfirmTransaction()).
	 * 
	 * 
	 * \in tHandle A transaction handle filled with one or several function modules.
	 * \out *errorInfo Additional error information in case anything goes wrong.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcSubmitTransaction(RFC_TRANSACTION_HANDLE tHandle, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Removes the TID contained in the RFC_TRANSACTION_HANDLE from the backend's ARFCRSTATE table.
	 * \ingroup transaction
	 * 
	 * After RfcSubmitTransaction() has finally succeeded, call %RfcConfirmTransaction() to clean up the
	 * transaction handling table in the backend.
	 * \warning Attention: after this call, the backend is no longer protected against this TID. So another
	 * RfcSubmitTransaction() with the same transaction handle would result in a duplicate.
	 *
	 * 
	 * \in tHandle A transaction handle that has successfully been submitted.
	 * \out *errorInfo Additional error information in case of a network problem.
	 * \warning You may retry the Confirm step, if you get an error here, but do not retry the Submit step!
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcConfirmTransaction(RFC_TRANSACTION_HANDLE tHandle, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Releases the memory of the transaction container.
	 * \ingroup transaction
	 * 
	 * 
	 * \in tHandle A transaction handle that is no longer needed.
	 * \out *errorInfo Not much that can go wrong here...
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcDestroyTransaction(RFC_TRANSACTION_HANDLE tHandle, RFC_ERROR_INFO* errorInfo);


    /* ***********************************************************************/
    /*                                                                       */
    /*  Installation of Callback Functions for RFC Servers                   */
    /*                                                                       */
    /* ***********************************************************************/

	/**
	 * \brief  Installs a callback function of type RFC_SERVER_FUNCTION, which will be triggered when a request for
	 * the function module corresponding to funcDescHandle comes in from the R/3 system corresponding to sysId.
	 * \ingroup installer
	 *
	 * If you pass NULL as "sysId", the serverFunction will be used for calls from any backend system.
	 * 
	 * The main inputs of RFC_SERVER_FUNCTION are as follows:
	 * - RFC_CONNECTION_HANDLE\n		A connection handle, which can be used to query logon information about
	 *						the current (backend) user or to make callbacks into the backend.
	 * - RFC_FUNCTION_HANDLE\n			A data container that represents the current function call. Read the importing
	 *						parameters, which came from the backend, from this container via the RfcGetX functions and
	 *						write the exporting parameters, which are to be returned to the backend, into this container
	 *						using the RfcSetX functions.\n
	 *						The memory of that container is automatically released by the RFC Runtime after the
	 *						RFC_SERVER_FUNCTION returns.
	 * - RFC_ERROR_INFO*\n			If you want to return an ABAP Exception or ABAP Message to the backend, fill the
	 *						parameters of that container and return RFC_ABAP_EXCEPTION or RFC_ABAP_MESSAGE from
	 *						your RFC_SERVER_FUNCTION implementation.\n
	 *						If you want to return a SYSTEM_FAILURE to the backend, fill the message parameter of
	 *						this container and return RFC_EXTERNAL_FAILURE from your RFC_SERVER_FUNCTION implementation.
	 * If your RFC_SERVER_FUNCTION implementation processed the function call successfully, you should return RFC_OK.
	 *
	 * 
	 * \inout *sysId System ID of the R/3 system, for which this function module implementation shall be used.
	 * If you set this to NULL, this server function will be used for calls from all backends, for whose SysID no
	 * explicit server function has been installed.
	 *
	 *
	 * \in *sysId The System ID of the backend for which this server function is to be used, or NULL in case the
	 * function can be used for calls from all systems.
	 * \in funcDescHandle A function description giving the name of the function module and its parameters.
	 * \in serverFunction Pointer to a C function of type RFC_SERVER_FUNCTION.
	 * \out *errorInfo Not much that can go wrong here.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcInstallServerFunction(SAP_UC const *sysId, RFC_FUNCTION_DESC_HANDLE funcDescHandle, RFC_SERVER_FUNCTION serverFunction, RFC_ERROR_INFO* errorInfo);

    /**
     * \brief  Installs a generic callback function of type RFC_SERVER_FUNCTION together with a callback
	 * function of type RFC_FUNC_DESC_CALLBACK for obtaining the metadata description of unknown function modules.
     * \ingroup installer
     * 
	 * The RFC Runtime calls the callback function RFC_SERVER_FUNCTION, if it receives a function call, for whose
	 * function module name no matching callback function has been installed via RfcInstallServerFunction()
	 * (neither for the current system ID nor for SysID=NULL).
	 *
	 * In addition to the handler function you need to provide a second callback function: RFC_FUNC_DESC_CALLBACK.
	 * The RFC runtime calls it to obtain an RFC_FUNCTION_DESC_HANDLE for the current function module from you.
	 * So this function either needs to return hardcoded meta data or needs to be able to perform a DDIC lookup
	 * using a valid client connection and RfcGetFunctionDesc(). If your implementation of RFC_FUNC_DESC_CALLBACK
	 * is not able to provide a function description for the current function module name, it should return RFC_NOT_FOUND.
	 * The RFC runtime will then notify the backend, that this function module cannot be processed by your
	 * RFC server.
	 *
     * 
     * \in serverFunction A pointer to a function that can handle "all" function modules.
     * \in funcDescProvider A pointer to a function that can provide metadata descriptions of "all" function modules.
     * \out *errorInfo Again not much that can go wrong at this point.
     * \return 
     */
    DECL_EXP RFC_RC SAP_API RfcInstallGenericServerFunction(RFC_SERVER_FUNCTION serverFunction, RFC_FUNC_DESC_CALLBACK funcDescProvider, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Installs the necessary callback function for being able to process incoming tRFC/qRFC calls.
	 * \ingroup installer
	 * 
	 * These functions need to be implemented by you and will be used by the RFC runtime in the following way:
	 * -# The RFC_ON_CHECK_TRANSACTION function is called when a local transaction is starting. Since a transactional 
	 *    RFC call can be issued many times by the client system, the function is responsible for storing the transaction ID
	 *    in permanent storage. The return value should be one of the following:
	 *    - RFC_OK\n		Transaction ID stored, transaction can be started.
	 *    - RFC_EXECUTED\n	This transaction has already been processed successfully in an earlier attempt. Skip the execution now.
	 *    - RFC_EXTERNAL_FAILURE\n Currently unable to access my permanent storage. Raise an exception in the sending system, so
	 *						that the sending system will try to resend the transaction at a later time.
	 * -# The next step will be the execution of the RFC_SERVER_FUNCTIONs for all function modules contained in the LUW.
	 * -# If one of the RFC_SERVER_FUNCTION implementations returns an error code, RFC_ON_ROLLBACK_TRANSACTION is called.
	 *    Here you should roll back all the work of all the previous RFC_SERVER_FUNCTIONs. (The easiest way is to do
	 *    a database ROLLBACK WORK here.)\n
	 *    If all RFC_SERVER_FUNCTIONs complete successfully, RFC_ON_COMMIT_TRANSACTION is called at the end.
	 *    Persist all the changes here (e.g. do a COMMIT WORK).\n
	 *    Note: Normally you'll only have "one-function-module LUWs", e.g. IDocs. In this case the RFC_SERVER_FUNCTION
	 *    can already commit/rollback its own work, before returning RFC_OK or an error code. So the two functions
	 *    RFC_ON_ROLLBACK_TRANSACTION and RFC_ON_COMMIT_TRANSACTION can be empty in this case.
	 * -# In the end RFC_ON_CONFIRM_TRANSACTION will be called. All information stored about that transaction can now be
	 *    discarded by the server, as it no longer needs to protect itself against duplicates.
	 *    In general this function can be used to delete the transaction ID from permanent storage.
	 *
	 * If you pass NULL as "sysId", the transaction handlers will be used for tRFC calls from any backend system,
	 * for which no explicit handlers have been installed.
	 *
	 * 
	 * \in *sysId System ID of the SAP system for which to use this set of transaction handlers, or NULL.
	 * \in onCheckFunction Pointer to a function of type RFC_ON_CHECK_TRANSACTION.
	 * \in onCommitFunction Pointer to a function of type RFC_ON_COMMIT_TRANSACTION.
	 * \in onRollbackFunction Pointer to a function of type RFC_ON_ROLLBACK_TRANSACTION.
	 * \in onConfirmFunction Pointer to a function of type RFC_ON_CONFIRM_TRANSACTION.
	 * \out *errorInfo Additional information, in case the handlers could not be installed.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcInstallTransactionHandlers (SAP_UC const *sysId, RFC_ON_CHECK_TRANSACTION onCheckFunction,
                                              RFC_ON_COMMIT_TRANSACTION onCommitFunction, RFC_ON_ROLLBACK_TRANSACTION onRollbackFunction,
                                              RFC_ON_CONFIRM_TRANSACTION onConfirmFunction, RFC_ERROR_INFO* errorInfo);

   	DECL_EXP RFC_RC SAP_API RfcInstallPassportManager (RFC_PM_CALLBACK onClientCallStart,
                                              RFC_PM_CALLBACK onClientCallEnd,
                                              RFC_PM_CALLBACK onServerCallStart, 
                                              RFC_PM_CALLBACK onServerCallEnd, RFC_ERROR_INFO* errorInfo);


    /* ***********************************************************************/
    /*                                                                       */
    /*  Data container API (Function modules, structures & tables)           */
    /*                                                                       */
    /* ***********************************************************************/

    /**
     * \brief  Creates a data container that can be used to execute function calls in the backend via RfcInvoke().
     * \ingroup container
     * 
	 * The importing parameters can be set using the RfcSetX functions. After the RfcInvoke() call returned
	 * successfully, the exporting parameters can be read from this data container via the RfcGetX functions.
	 *
     * 
     * \in funcDescHandle Metadata description ("blueprint") for the data container to be created.
     * \out *errorInfo Error information in case the parameters are incorrect or there's not enough memory.
     * \return A handle to the function module container.
     */
    DECL_EXP RFC_FUNCTION_HANDLE SAP_API RfcCreateFunction(RFC_FUNCTION_DESC_HANDLE funcDescHandle, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Releases all memory used by the data container.
	 * \ingroup container
	 * 
	 * \warning Be careful: if you have obtained a handle to a structure (RFC_STRUCTURE_HANDLE) or
	 * table parameter (RFC_TABLE_HANDLE) from that function module, that handle will be invalid afterwards,
	 * as that memory will be released as well!
	 *
	 * 
	 * \in funcHandle Data container to release.
	 * \out *errorInfo Not much that can go wrong here.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcDestroyFunction(RFC_FUNCTION_HANDLE funcHandle, RFC_ERROR_INFO* errorInfo);

    /**
     * \brief  Allows to deactivate certain parameters in the function module interface.
     * \ingroup container
     * 
	 * This is particularly useful for BAPIs which have many large tables, in which you are not interested.
	 * Deactivate those and leave only those tables active, in which you are interested. This reduces
	 * network traffic and memory consumption in your application considerably.
	 *
	 * \note This functionality can be used for input and output parameters. If the parameter is an input,
	 * no data for that parameter will be sent to the backend. If it's an output, the backend will be
	 * informed not to return data for that parameter. 
     * 
     * \in funcHandle A function module data container.
     * \in *paramName The name of a parameter of this function module.
     * \in isActive 1 = activate, 0 = deactivate.
     * \out *errorInfo Error information in case something goes wrong (e.g. a parameter of that name does not exist).
     * \return RFC_RC
     */
    DECL_EXP RFC_RC SAP_API RfcSetParameterActive(RFC_FUNCTION_HANDLE funcHandle, SAP_UC const* paramName, int isActive, RFC_ERROR_INFO* errorInfo);

    /**
     * \brief  Query whether a parameter is active.
     * \ingroup container
     * 
     * Useful for example in a server function implementation: Before creating a large table,
	 * you may want to check, whether the client (the backend system), has requested that table at all.
     * 
     * \in funcHandle A function module data container (usually handed to your server function from the RFC library).
     * \in *paramName The name of a parameter of this function module.
     * \out *isActive 1 = is active, 0 = is not active.
     * \out *errorInfo Error information in case something goes wrong (e.g. a parameter of that name does not exist).
     * \return RFC_RC
     */
    DECL_EXP RFC_RC SAP_API RfcIsParameterActive(RFC_FUNCTION_HANDLE funcHandle, SAP_UC const* paramName, int *isActive, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Creates a data container for a structure.
	 * \ingroup container
	 * 
	 * 
	 * \in typeDescHandle The metadata description (blueprint) for the structure to be created.
	 * \out *errorInfo Error information in case the parameters are incorrect or there's not enough memory.
	 * \return A handle to the structure.
	 */
	DECL_EXP RFC_STRUCTURE_HANDLE SAP_API RfcCreateStructure(RFC_TYPE_DESC_HANDLE typeDescHandle, RFC_ERROR_INFO* errorInfo);

    /**
     * \brief  Clones a sructure including the data in it.
     * \ingroup container
     * 
     * 
     * \in srcStructureHandle The structure to clone.
     * \out *errorInfo Not enough memory?
     * \return A handle to the newly created copy of the input structure.
     */
    DECL_EXP RFC_STRUCTURE_HANDLE SAP_API RfcCloneStructure(RFC_STRUCTURE_HANDLE srcStructureHandle, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Releases all memory for a particular structure
	 * \ingroup container
	 * 
	 * \warning Do not call this function on structures, which you have obtained from another data container
	 * (e.g. a function module) via RfcGetStructure(). In that case the memory will be released, when the
	 * parent container will be destroyed. If you destroy a child structure separately, you will get a
	 * segmentation fault, when the parent structure is destroyed!
	 * 
	 * \in structHandle Structure to release.
	 * \out *errorInfo Not much that can go wrong here.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcDestroyStructure(RFC_STRUCTURE_HANDLE structHandle, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Creates a data container for a table.
	 * \ingroup container
	 * 
	 * 
	 * \in typeDescHandle The metadata description (blueprint) for the line type of the table to be created.
	 * \out *errorInfo More details in case there was an invalid parameter or not enough memory.
	 * \return The freshly created table.
	 */
	DECL_EXP RFC_TABLE_HANDLE SAP_API RfcCreateTable(RFC_TYPE_DESC_HANDLE typeDescHandle, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Clones a table including all the data in it. (Use with care...)
	 * \ingroup container
	 * 
	 * 
	 * \in srcTableHandle The table to duplicate.
	 * \out *errorInfo In case there is not enough memory.
	 * \return A handle to the cloned table.
	 */
	DECL_EXP RFC_TABLE_HANDLE SAP_API RfcCloneTable(RFC_TABLE_HANDLE srcTableHandle, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Releases the memory of a table and all its lines.
	 * \ingroup container
	 * 
	 * \warning Be careful: if you still have a reference to a certain table line (an RFC_STRUCTURE_HANDLE you got
	 * from RfcGetCurrentRow()/RfcAppendNewRow()/RfcInsertNewRow()), this handle will be invalid after RfcDestroyTable!
	 * Using a handle to a table line after the table has been destroyed, will lead to a segmentation fault.
	 * 
	 * \in tableHandle The table to release.
	 * \out *errorInfo Nothing can go wrong here...
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcDestroyTable(RFC_TABLE_HANDLE tableHandle, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Returns the table row, on which the "table cursor" is currently positioned.
	 * \ingroup container
	 * 
	 * \note that the rows are numbered from 0 to n-1, not from 1 to n, as it's done in ABAP.
	 * 
	 * \in tableHandle The table to read data from.
	 * \out *errorInfo If the table cursor is not on a valid position.
	 * \return A handle to the current row.
	 * \warning Do not destroy the returned RFC_STRUCTURE_HANDLE.
	 */
	DECL_EXP RFC_STRUCTURE_HANDLE SAP_API RfcGetCurrentRow(RFC_TABLE_HANDLE tableHandle, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Appends a new empty row at the end of the table and moves the table cursor to that row.
	 * \ingroup container
	 * 
	 * 
	 * \in tableHandle The table to enlarge.
	 * \out *errorInfo More information in case of errors (e.g. not enough memory).
	 * \return A handle to the newly created row.
	 */
	DECL_EXP RFC_STRUCTURE_HANDLE SAP_API RfcAppendNewRow(RFC_TABLE_HANDLE tableHandle, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Inserts a new empty row at the current position of the table cursor.
	 * \ingroup container
	 *
	 * The row, on which the table cursor is currently positioned, and all following rows are moved
	 * one index "down". E.g. if the table currently has rows nos 0 - n-1 and the cursor points to row i,
	 * then the rows i - n-1 are moved to positions i+1 - n, and the new row is inserted at position i.
	 * 
	 * 
	 * \in tableHandle The table to enlarge.
	 * \out *errorInfo More information in case of errors (e.g. not enough memory).
	 * \return A handle to the newly created row.
	 */
	DECL_EXP RFC_STRUCTURE_HANDLE SAP_API RfcInsertNewRow(RFC_TABLE_HANDLE tableHandle, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Appends an existing row to the end of the table and moves the table cursor to that row.
	 * \ingroup container
	 * 
	 * 
	 * \in tableHandle The table to enlarge.
	 * \in structHandle The row to append to the table.
	 * \out *errorInfo More information in case something goes wrong (e.g. the line types of the table and the structure don't match).
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcAppendRow(RFC_TABLE_HANDLE tableHandle, RFC_STRUCTURE_HANDLE structHandle, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Inserts an existing row at the current position of the table cursor.
	 * \ingroup container
	 * 
	 * The row, on which the table cursor is currently positioned, and all following rows are moved
	 * one index "down". E.g. if the table currently has rows nos 0 - n-1 and the cursor points to row i,
	 * then the rows i - n-1 are moved to positions i+1 - n, and the given row is inserted at position i.
	 * 
	 * 
	 * \in tableHandle The table to enlarge.
	 * \in structHandle The row to insert into the table.
	 * \out *errorInfo More information in case something goes wrong (e.g. the line types of the table and the structure don't match).
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcInsertRow(RFC_TABLE_HANDLE tableHandle, RFC_STRUCTURE_HANDLE structHandle, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Deletes the row, on which the table cursor is currently positioned.
	 * \ingroup container
	 *
	 * If the row cursor is currently at an index i between 0 - n-2, then row i will be deleted and the
	 * rows i+1 - n-1 will be moved on index "up", e.g. will now be rows i - n-2. The table cursor will
	 * remain fixed at index i.\n
	 * If the cursor is currently on the last row (n-1), then that row will be deleted, all other position
	 * will remain unchanged, and the table cursor will move up to n-2 (the new last row of the table).
	 *
	 * 
	 * \in tableHandle The table from which to delete a row.
	 * \out *errorInfo Error information in case the table cursor is not on a valid position.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcDeleteCurrentRow(RFC_TABLE_HANDLE tableHandle, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Deletes all rows from the table.
	 * \ingroup container
	 * 
	 * 
	 * \in tableHandle The table to clear.
	 * \out *errorInfo Not much that can go wrong here (except an invalid table handle).
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcDeleteAllRows(RFC_TABLE_HANDLE tableHandle, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Positions the table cursor at the first row (or at index "-1", if the table is empty).
	 * \ingroup container
	 * 
	 * 
	 * \in tableHandle A table.
	 * \out *errorInfo Not much that can go wrong here (except an invalid table handle).
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcMoveToFirstRow(RFC_TABLE_HANDLE tableHandle, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Positions the table cursor at the last row (or at index "-1", if the table is empty).
	 * \ingroup container
	 * 
	 * 
	 * \in tableHandle A table.
	 * \out *errorInfo Not much that can go wrong here (except an invalid table handle).
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcMoveToLastRow(RFC_TABLE_HANDLE tableHandle, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Increments the table cursor by one.
	 * \ingroup container
	 * 
	 * 
	 * \in tableHandle A table.
	 * \out *errorInfo Not much that can go wrong here (except an invalid table handle).
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcMoveToNextRow(RFC_TABLE_HANDLE tableHandle, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Decrements the table cursor by one.
	 * \ingroup container
	 * 
	 * 
	 * \in tableHandle A table.
	 * \out *errorInfo Not much that can go wrong here (except an invalid table handle).
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcMoveToPreviousRow(RFC_TABLE_HANDLE tableHandle, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Sets the table cursor to a specific index.
	 * \ingroup container
	 * 
	 * 
	 * \in tableHandle A table.
	 * \in index The index to which to move the cursor.
	 * \out *errorInfo Index out of bounds or invalid table handle.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcMoveTo(RFC_TABLE_HANDLE tableHandle, unsigned index, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Returns the number of rows in a table.
	 * \ingroup container
	 * 
	 * 
	 * \in tableHandle A table.
	 * \out *rowCount The number of rows in the table.
	 * \out *errorInfo Not much that can go wrong.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcGetRowCount(RFC_TABLE_HANDLE tableHandle, unsigned* rowCount, RFC_ERROR_INFO* errorInfo);



    /* ****************************************************************************
     *
     *  API for accessing the fields of a data container
     *
	 * API for reading the exporting parameters of an RFC_FUNCTION_HANDLE in the
	 * client case, the importing parameters of an RFC_FUNCTION_HANDLE in the
	 * server case and the fields of an RFC_STRUCTURE_HANDLE or RFC_TABLE_HANDLE.
     * ****************************************************************************/

	/**
	 * \brief  Returns the value of the specified field as char array.
	 * \ingroup container
	 * 
     * The charBuffer will be filled with a string representation of the given field. The remaining
     * places in the buffer will be filled with trailing spaces. In case the buffer is too small,
     * the function will return RFC_BUFFER_TOO_SMALL. The result will not be null-terminated.
	 *
     * The field specified by name needs to be of one of the following data types. If the field
	 * has one of the listed non-char-like data types, the RFC library will convert the field value
	 * to string format. Example:\n
	 * If "name" specifies a field of type INT4 with the value 4711 and charBuffer is an SAP_CHAR[10],
	 * then the buffer will be filled as follows: "4711      ".
	 *
     * \note If the target field has type BYTE or XSTRING, the bytes will be
     * converted to a hex encoded string representation.
	 *
     * - RFCTYPE_CHAR
     * - RFCTYPE_STRING
     * - RFCTYPE_NUM
     * - RFCTYPE_DATE
     * - RFCTYPE_TIME
     * - RFCTYPE_INTx
     * - RFCTYPE_FLOAT
     * - RFCTYPE_BCD
     * - RFCTYPE_DECFxx
     * - RFCTYPE_BYTE
     * - RFCTYPE_XSTRING
	 *
	 *
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field.
	 * \out *charBuffer A pre-allocated buffer, which will receive the (converted) field value.
	 * \in bufferLength Size of the buffer in RFC_CHARs.
	 * \out *errorInfo Field doesn't exist, cannot be converted to char, etc.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcGetChars(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, RFC_CHAR *charBuffer, unsigned bufferLength, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Returns the value of the specified field as num-char array (digits only).
	 * \ingroup container
	 * 
     * The charBuffer will be filled with a string representation of the field (from right to left).
     * The remaining places in the buffer will be filled with leading zero digits. In case
     * the buffer is too small, the function will return RFC_BUFFER_TOO_SMALL. The result is not
	 * null-terminated.
	 *
	 * The field specified by name needs to be of one of the following data types. If the field
	 * has one of the listed non-char-like data types, the RFC library will convert the field value
	 * to string format. Example:\n
	 * If "name" specifies a field of type INT4 with the value 4711 and charBuffer is an SAP_CHAR[10],
	 * then the buffer will be filled as follows: "0000004711".
     *
     * - RFCTYPE_CHAR
     * - RFCTYPE_STRING
     * - RFCTYPE_NUM
     * - RFCTYPE_DATE
     * - RFCTYPE_TIME
     * - RFCTYPE_INTx
     * 
	 * 
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field.
	 * \out *charBuffer A pre-allocated buffer, which will receive the (converted) field value.
	 * \in bufferLength Size of the buffer in RFC_CHARs.
	 * \out *errorInfo Field doesn't exist, cannot be converted to numc, etc.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcGetNum(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, RFC_NUM *charBuffer, unsigned bufferLength, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Reads a DATE field.
	 * \ingroup container
	 * 
	 * 
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to read. The field must be of type RFCTYPE_DATE.
	 * \out emptyDate An RFC_DATE object, which will receive the field value.
	 * \out *errorInfo More information in case something goes wrong.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcGetDate(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, RFC_DATE emptyDate, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Reads a TIME field.
	 * \ingroup container
	 * 
	 * 
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to read. The field must be of type RFCTYPE_TIME.
	 * \out emptyTime An RFC_TIME object, which will receive the field value.
	 * \out *errorInfo More information in case something goes wrong.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcGetTime(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, RFC_TIME emptyTime, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Returns the value of the specified field as null-terminated string.
	 * \ingroup container
     *
     * The charBuffer will be filled with a null-terminated string representation of the field value.
     * In case the buffer is too small, e.g. no place for string termination, the function will
     * return RFC_BUFFER_TOO_SMALL. stringLength contains the number of written characters, or the
     * required number of characters in case RFC_BUFFER_TOO_SMALL was thrown.
	 * The result will be null-terminated.
	 *
	 * The field specified by name needs to be of one of the following data types. If the field
	 * has one of the listed non-char-like data types, the RFC library will convert the field value
	 * to string format. Example:\n
	 * If "name" specifies a field of type INT4 with the value 4711 and stringBuffer is an SAP_UC[10],
	 * then the buffer will be filled as follows: "4711\0xxxxx". (x: left unchanged.)
     *
     * \note If the target field has type BYTE or XSTRING, the bytes will be
     * converted to a hex encoded string representation.
	 *
     * - RFCTYPE_CHAR
     * - RFCTYPE_STRING
     * - RFCTYPE_NUM
     * - RFCTYPE_DATE
     * - RFCTYPE_TIME
     * - RFCTYPE_INTx
     * - RFCTYPE_FLOAT
     * - RFCTYPE_BCD
     * - RFCTYPE_DECFxx
     * - RFCTYPE_BYTE
     * - RFCTYPE_XSTRING
	 *
	 *
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to read.
	 * \out *stringBuffer Pre-allocated buffer, which will receive the (converted) field value.
	 * \in bufferLength Size of the buffer in SAP_UC.
	 * \out *stringLength Always returns the string's length, no matter whether the stringBuffer had
	 * been large enough or not. (Note that if you want to try again after an RFC_BUFFER_TOO_SMALL,
	 * you need to make the stringBuffer at least *stringLength + 1 in order to account for the termnating null.)
	 * \out *errorInfo More information in case the field does not exist or a conversion fails.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcGetString(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, SAP_UC *stringBuffer, unsigned bufferLength, unsigned* stringLength, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Returns the value of the specified field as byte array.
	 * \ingroup container
	 *
     * Should mainly be used with fields of type RAW (RFCTYPE_BYTE), but also works with
	 * a number of other data types. In case of numerical data types it simply gives the
	 * binary representation of the value, in case of character data types it gives the
	 * UTF-16 representation (little endian/big endian, depending on the host platform).
     * In case the buffer is too small, the function will return RFC_BUFFER_TOO_SMALL.
     * In case the buffer is longer than the field, it will be filled with 0x00 values.
	 * Example: The field is of type INT4 and contains the value 4711, byteBuffer is an SAP_RAW[10].
	 * Then the buffer will be filled as follows: 67 12 00 00 00 00 00 00 00 00 (little endian system)
	 * or 00 00 12 67 00 00 00 00 00 00 (big endian system).
	 *
     * The field specified by name needs to be of one of the following data types:
     * - RFCTYPE_BYTE
     * - RFCTYPE_XSTRING
     * - RFCTYPE_CHAR
     * - RFCTYPE_NUM
     * - RFCTYPE_DATE
     * - RFCTYPE_TIME
     * - RFCTYPE_INTx
     * - RFCTYPE_FLOAT
     * - RFCTYPE_BCD
     * - RFCTYPE_DECFxx
     * 
	 * 
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to read.
	 * \out *byteBuffer Pre-allocated buffer, which will receive the (converted) field value.
	 * \in bufferLength Size of the buffer in bytes.
	 * \out *errorInfo More information in case the field does not exist or a conversion fails.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcGetBytes(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, SAP_RAW *byteBuffer, unsigned bufferLength, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Returns the value of the specified field as byte array.
	 * \ingroup container
     *
     * In case the buffer is too small, the function will return RFC_BUFFER_TOO_SMALL.
     * xstringLength contains the number of written bytes, or the required number of bytes
     * in case of RFC_BUFFER_TOO_SMALL.
     * The remaining buffer won't be changed.
	 * 
	 * Example: The field is of type INT4 and contains the value 4711, byteBuffer is an SAP_RAW[10].
	 * Then the buffer will be filled as follows: 67 12 00 00 x x x x x x (little endian system)
	 * or 00 00 12 67 x x x x x x (big endian system). (x: unchanged) In both cases *xstringLength
	 * will be 4.
	 * 
     * The field specified by name needs to be of one of the following data types:
     * - RFCTYPE_BYTE
     * - RFCTYPE_XSTRING
     * - RFCTYPE_CHAR
     * - RFCTYPE_NUM
     * - RFCTYPE_DATE
     * - RFCTYPE_TIME
     * - RFCTYPE_INTx
     * - RFCTYPE_FLOAT
     * - RFCTYPE_BCD
     * - RFCTYPE_DECFxx
	 * 
	 * 
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to read.
	 * \out *byteBuffer Pre-allocated buffer, which will receive the (converted) field value.
	 * \in bufferLength Size of the buffer in bytes.
	 * \out *xstringLength Byte length of the result (in both cases, no matter whether the byteBuffer had
	 * been large enough or not).
	 * \out *errorInfo More information in case the field does not exist or a conversion fails.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcGetXString(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, SAP_RAW *byteBuffer, unsigned bufferLength, unsigned* xstringLength, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Returns the value of the specified field as RFC_INT (signed).
	 * \ingroup container
     *
     * If the field is a character type, an "atoi-like" conversion is performed. If the field is of type
	 * RFCTYPE_BYTE/RFCTYPE_XSTRING, this function interpretes the bytes in big-endian byte order when
     * converting them to int. Note that in this case the byte length of the field value must not exceed 4!
	 * 
     * The field specified by name needs to be of one of the following data types:
     * - RFCTYPE_INT
     * - RFCTYPE_INT2
     * - RFCTYPE_INT1
     * - RFCTYPE_BYTE     is interpreted as big endian sequence of an int
     * - RFCTYPE_XSTRING  is interpreted as big endian sequence of an int
     * - RFCTYPE_CHAR
     * - RFCTYPE_NUM
     * - RFCTYPE_STRING
	 * 
	 * 
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to read.
	 * \out *value The (converted) integer value.
	 * \out *errorInfo More information in case the field does not exist or a conversion fails.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcGetInt(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, RFC_INT  *value, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Returns the value of a field as an unsigned one byte integer.
	 * \ingroup container
	 *
	 * The current field value must not be bigger than 255, otherwise you'll get an
	 * RFC_CONVERSION_ERROR. If the field is of type RFCTYPE_BYTE/RFCTYPE_XSTRING, the field length must be 1 byte.
	 *
     * The field specified by name needs to be of one of the following data types:
     * - RFCTYPE_INT
     * - RFCTYPE_INT2
     * - RFCTYPE_INT1
     * - RFCTYPE_BYTE
     * - RFCTYPE_XSTRING
	 * 
	 * 
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to read.
	 * \out *value The (converted) integer value.
	 * \out *errorInfo More information in case the field does not exist or a conversion fails.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcGetInt1(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, RFC_INT1 *value, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Returns the field value as a signed two byte integer.
	 * \ingroup container
	 *
	 * The current field value must not be between -32768 and 32767, otherwise you'll get an
	 * RFC_CONVERSION_ERROR. If the field is of type RFCTYPE_BYTE/RFCTYPE_XSTRING, the field length must be 1 or 2 bytes.
	 *
     * The field specified by name needs to be of one of the following data types:
     * - RFCTYPE_INT
     * - RFCTYPE_INT2
     * - RFCTYPE_INT1
     * - RFCTYPE_BYTE     is interpreted as big endian sequence of a short
     * - RFCTYPE_XSTRING  is interpreted as big endian sequence of a short
	 * 
	 * 
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to read.
	 * \out *value The (converted) integer value.
	 * \out *errorInfo More information in case the field does not exist or a conversion fails.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcGetInt2(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, RFC_INT2 *value, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Returns the value of the given field as an RFC_FLOAT.
	 * \ingroup container
	 * 
     * The field specified by name needs to be of one of the following data types:
     * - RFCTYPE_FLOAT
     * - RFCTYPE_BCD
	 * 
	 * 
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to read.
	 * \out *value The floating point value.
	 * \out *errorInfo More information in case the field does not exist or a conversion fails.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcGetFloat(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, RFC_FLOAT *value, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Returns the field as an 8 byte IEEE 754r decimal floating point.
	 * \ingroup container
	 *
	 * See the header sapdecf.h for how to work with RFC_DECF16 objects. If the field has a binary
	 * data type, its field length needs to be 8 bytes.
	 *
     * The field specified by name needs to be of one of the following data types:
     * - RFCTYPE_DECF16
     * - RFCTYPE_DECF34
     * - RFCTYPE_FLOAT
     * - RFCTYPE_BCD
     * - RFCTYPE_INT
     * - RFCTYPE_INT2
     * - RFCTYPE_INT1
     * - RFCTYPE_CHAR
     * - RFCTYPE_NUM
     * - RFCTYPE_STRING
     * - RFCTYPE_BYTE     is interpreted as IEEE 754r format
     * - RFCTYPE_XSTRING  is interpreted as IEEE 754r format
	 * 
	 * 
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to read.
	 * \out *value The (converted) decimal floating point value.
	 * \out *errorInfo More information in case the field does not exist or a conversion fails.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcGetDecF16(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, RFC_DECF16 *value, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Returns the field as a 16 byte IEEE 754r decimal floating point.
	 * \ingroup container
	 *
	 * See the header sapdecf.h for how to work with RFC_DECF16 objects. If the field has a binary
	 * data type, its field length needs to be 16 bytes.
	 *
     * The field specified by name needs to be of one of the following data types:
     * - RFCTYPE_DECF16
     * - RFCTYPE_DECF34
     * - RFCTYPE_FLOAT
     * - RFCTYPE_BCD
     * - RFCTYPE_INT
     * - RFCTYPE_INT2
     * - RFCTYPE_INT1
     * - RFCTYPE_CHAR
     * - RFCTYPE_NUM
     * - RFCTYPE_STRING
     * - RFCTYPE_BYTE     is interpreted as IEEE 754r format
     * - RFCTYPE_XSTRING  is interpreted as IEEE 754r format
	 * 
	 * 
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to read.
	 * \out *value The (converted) decimal floating point value.
	 * \out *errorInfo More information in case the field does not exist or a conversion fails.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcGetDecF34(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, RFC_DECF34 *value, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Returns a handle to a structure.
	 * \ingroup container
	 *
	 * The field specified by name must be of type RFCTYPE_STRUCTURE. If that field has not yet
	 * been accessed/filled previously, a new empty structure is created from the metadata of the
	 * parent data container ("dataHandle") and returned.
	 * \warning The memory of that data container will be released, when the parent container gets
	 * destroyed. So don't destroy the returned structure handle, nor continue to use it, after the
	 * parent has been destroyed!
	 * 
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to read.
	 * \out *structHandle A handle to the sub-structure.
	 * \out *errorInfo Field does not exist, is of wrong type or out of memory.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcGetStructure(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, RFC_STRUCTURE_HANDLE* structHandle, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Returns a handle to a structure.
	 * \ingroup container
	 *
	 * The field specified by name must be of type RFCTYPE_TABLE. If that field has not yet
	 * been accessed/filled previously, a new empty structure is created from the metadata of the
	 * parent data container ("dataHandle") and returned.
	 * \warning The memory of that data container will be released, when the parent container gets
	 * destroyed. So don't destroy the returned table handle, nor continue to use it, after the
	 * parent has been destroyed!
	 * 
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to read.
	 * \out *tableHandle A handle to the sub-table.
	 * \out *errorInfo Field does not exist, is of wrong type or out of memory.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcGetTable    (DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, RFC_TABLE_HANDLE* tableHandle, RFC_ERROR_INFO* errorInfo);

	/* , so an appropriately sized
	 * buffer can be allocated before reading the value.
	 */
	/**
	 * \brief  Returns the length of the value of a STRING or XSTRING parameter.
	 * \ingroup container
	 *
	 * The field specified by name must be of type RFCTYPE_STRING or RFCTYPE_XSTRING. If that field is
	 * of type STRING, the returned length is measured in characters, otherwise in bytes.
	 * 
	 * 
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of a STRING or XSTRING field.
	 * \out *stringLength Length of the current field value.
	 * \out *errorInfo Wrong field type?
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcGetStringLength(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, unsigned* stringLength, RFC_ERROR_INFO* errorInfo);



	/* *****************************************************************************
	 *
	 * API for setting the importing parameters of an RFC_FUNCTION_HANDLE in the
	 * client case, the exporting parameters of an RFC_FUNCTION_HANDLE in the server
	 * case and the subfields of an RFC_STRUCTURE_HANDLE or RFC_TABLE_HANDLE.
	 *
	 *******************************************************************************/

	/**
	 * \brief  Sets the given char value (charValue/valueLength) into the field.
	 * \ingroup container
     *
     * The field specified by name needs to be of one of the following data types:
     * - RFCTYPE_CHAR
     * - RFCTYPE_STRING
     * - RFCTYPE_NUM
     * - RFCTYPE_DATE
     * - RFCTYPE_TIME
     * - RFCTYPE_INTx
     * - RFCTYPE_FLOAT
     * - RFCTYPE_BCD
     * - RFCTYPE_DECFxx
     * - RFCTYPE_BYTE
     * - RFCTYPE_XSTRING
     * \note If the target field is a numerical type, the RFC library tries to convert the string
	 * to a number. If the target field has type BYTE or XSTRING, the char value will be interpreted as
     * hex encoded string representation of the bytes. Its length needs to be even in that case.\n
	 * Example: the 8 characters "CAFEBABE" will be converted to 4 bytes 0xCA 0xFE 0xBA 0xBE.
	 *
	 * If the value cannot be converted to the desired target type, RFC_CONVERSION_ERROR will be
	 * returned.
	 * 
	 * 
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to set.
	 * \in *charValue The characters to write into the field.
	 * \in valueLength The number of characters to read from charValue.
	 * \out *errorInfo More information in case the field does not exist or a conversion fails.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcSetChars(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, const RFC_CHAR *charValue, unsigned valueLength, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Sets the value of a NUMC field.
	 * \ingroup container
	 * 
	 * The target field needs to be of type RFCTYPE_NUM.
	 *
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to set.
	 * \in *charValue The digits [0..9] to write into the field.
	 * \in valueLength The number of characters to read from charValue.
	 * \out *errorInfo More information in case the field does not exist or the parameter value is invalid.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcSetNum(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, const RFC_NUM *charValue, unsigned valueLength, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Sets the given string value (stringValue/valueLength) into the field.
	 * \ingroup container
     *
     * The field specified by name needs to be of one of the following data types:
     * - RFCTYPE_CHAR
     * - RFCTYPE_STRING
     * - RFCTYPE_NUM
     * - RFCTYPE_DATE
     * - RFCTYPE_TIME
     * - RFCTYPE_INTx
     * - RFCTYPE_FLOAT
     * - RFCTYPE_BCD
     * - RFCTYPE_DECFxx
     * - RFCTYPE_BYTE
     * - RFCTYPE_XSTRING
     * \note If the target field is a numerical type, the RFC library tries to convert the string
	 * to a number. If the target field has type BYTE or XSTRING, the char value will be interpreted as
     * hex encoded string representation of the bytes. Its length needs to be even in that case.\n
	 * Example: the 8 characters "CAFEBABE" will be converted to 4 bytes 0xCA 0xFE 0xBA 0xBE.
	 *
	 * If the value cannot be converted to the desired target type, RFC_CONVERSION_ERROR will be
	 * returned.
	 * 
	 * 
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to set.
	 * \in *stringValue The characters to write into the field.
	 * \in valueLength The number of characters to read from stringValue.
	 * \out *errorInfo More information in case the field does not exist or a conversion fails.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcSetString(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, const SAP_UC *stringValue, unsigned valueLength, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Sets the value of a DATE field.
	 * \ingroup container
	 * 
	 * The target field needs to be of type RFCTYPE_DATE.
	 *
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to set.
	 * \in date The date value to write into the field.
	 * \out *errorInfo Is the field not of type DATE?
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcSetDate(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, const RFC_DATE date, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Sets the value of a TIME field.
	 * \ingroup container
	 * 
	 * The target field needs to be of type RFCTYPE_TIME.
	 *
	 *
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to set.
	 * \in time The time value to write into the field.
	 * \out *errorInfo Is the field not of type TIME?
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcSetTime(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, const RFC_TIME time, RFC_ERROR_INFO* errorInfo);


	/**
	 * \brief  Sets the given byte value (byteValue/valueLength) into the field.
	 * \ingroup container
     *
     * The field specified by name needs to be of one of the following data types:
     * - RFCTYPE_BYTE
     * - RFCTYPE_XSTRING
     * - RFCTYPE_CHAR
     * - RFCTYPE_STRING
     * - RFCTYPE_INTx
     * - RFCTYPE_FLOAT
     * - RFCTYPE_BCD
     * - RFCTYPE_DECFxx
     * \note: If the target field has type CHAR or STRING the byte value
     * will be stored as a hex representation of the bytes.\n
     * If the target field has a numerical type, the byte value will be
     * assigned only if the given valueLength matches the field length.
	 * In order to use this feature, you need to know exactly what you are doing...
	 * E.g. when setting 8 bytes into an RFC_FLOAT field, you need to understand the
	 * IEEE floating point format. Better only use this function for setting RAW fields.
	 * 
	 * 
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to set.
	 * \in *byteValue The byte value to write into the field.
	 * \in valueLength The number of bytes to use from byteValue.
	 * \out *errorInfo More information in case the field does not exist or a conversion fails.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcSetBytes(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, const SAP_RAW *byteValue, unsigned valueLength, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Sets the given byte value (byteValue/valueLength) into the field.
	 * \ingroup container
     *
     * The field specified by name needs to be of one of the following data types:
     * - RFCTYPE_BYTE
     * - RFCTYPE_XSTRING
     * - RFCTYPE_CHAR
     * - RFCTYPE_STRING
     * - RFCTYPE_INTx
     * - RFCTYPE_FLOAT
     * - RFCTYPE_BCD
     * - RFCTYPE_DECFxx
     * \note: If the target field has type CHAR or STRING the byte value
     * will be stored as a hex representation of the bytes.\n
     * If the target field has a numerical type, the byte value will be
     * assigned only if the given valueLength matches the field length.
	 * In order to use this feature, you need to know exactly what you are doing...
	 * E.g. when setting 8 bytes into an RFC_FLOAT field, you need to understand the
	 * IEEE floating point format. Better only use this function for setting RAW fields.
	 * 
	 * 
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to set.
	 * \in *byteValue The byte value to write into the field.
	 * \in valueLength The number of bytes to use from byteValue.
	 * \out *errorInfo More information in case the field does not exist or a conversion fails.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcSetXString(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, const SAP_RAW *byteValue, unsigned valueLength, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Sets the value of an INT4 field.
	 * \ingroup container
	 * 
	 * The target field needs to be of type RFCTYPE_INT.
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to set.
	 * \in value The int value to set.
	 * \out *errorInfo Field does not exist or is not of type INT4?
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcSetInt(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, const RFC_INT  value, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Sets the value of an INT1 field.
	 * \ingroup container
	 * 
	 * The target field needs to be of type RFCTYPE_INT1.
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to set.
	 * \in value The int value to set.
	 * \out *errorInfo Field does not exist or is not of type INT1?
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcSetInt1(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, const RFC_INT1 value, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Sets the value of an INT2 field.
	 * \ingroup container
	 * 
	 * The target field needs to be of type RFCTYPE_INT2.
	 *
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to set.
	 * \in value The int value to set.
	 * \out *errorInfo Field does not exist or is not of type INT2?
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcSetInt2(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, const RFC_INT2 value, RFC_ERROR_INFO* errorInfo);


	/**
	 * \brief  Sets a floating point field.
	 * \ingroup container
	 *
	 * The field specified by name needs to be of one of the following data types:
     * - RFCTYPE_FLOAT
     * - RFCTYPE_BCD
     * - RFCTYPE_CHAR
     * - RFCTYPE_STRING
     * - RFCTYPE_NUM
     * - RFCTYPE_DECF16
     * - RFCTYPE_DECF34
	 * \note If the target field is CHAR or STRING, the value will be converted to a string in
	 * scientific notation. If it is NUMC, it will be truncated to the next integer.
	 * 
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to set.
	 * \in value The double value to set.
	 * \out *errorInfo Field does not exist or is not of a supported type?
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcSetFloat(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, const RFC_FLOAT value, RFC_ERROR_INFO* errorInfo);


	/**
	 * \brief  Sets the value of an 8 byte decfloat object into a field.
	 * \ingroup container
	 * 
	 * The field specified by name needs to be of one of the following data types:
     * - RFCTYPE_DECF16
     * - RFCTYPE_DECF34
     * - RFCTYPE_FLOAT
     * - RFCTYPE_BCD
     * - RFCTYPE_INT
     * - RFCTYPE_INT2
     * - RFCTYPE_INT1
     * - RFCTYPE_CHAR
     * - RFCTYPE_NUM
     * - RFCTYPE_STRING
     * - RFCTYPE_BYTE     Needs to be 8 byte long.
     * - RFCTYPE_XSTRING
	 * \note If the target field is CHAR or STRING, the value will be converted to a string in
	 * scientific notation. If it is NUMC, it will be truncated to the next integer.
	 * 
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to set.
	 * \in value The decfloat value to set.
	 * \out *errorInfo Field does not exist or is not of a supported type?
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcSetDecF16(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, const RFC_DECF16 value, RFC_ERROR_INFO* errorInfo);


	/**
	 * \brief  Sets the value of a 16 byte decfloat object into a field.
	 * \ingroup container
	 * 
	 * The field specified by name needs to be of one of the following data types:
     * - RFCTYPE_DECF16
     * - RFCTYPE_DECF34
     * - RFCTYPE_FLOAT
     * - RFCTYPE_BCD
     * - RFCTYPE_INT
     * - RFCTYPE_INT2
     * - RFCTYPE_INT1
     * - RFCTYPE_CHAR
     * - RFCTYPE_NUM
     * - RFCTYPE_STRING
     * - RFCTYPE_BYTE     Needs to be 8 byte long.
     * - RFCTYPE_XSTRING
	 * \note If the target field is CHAR or STRING, the value will be converted to a string in
	 * scientific notation. If it is NUMC, it will be truncated to the next integer.
	 * 
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to set.
	 * \in value The decfloat value to set.
	 * \out *errorInfo Field does not exist or is not of a supported type?
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcSetDecF34   (DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, const RFC_DECF34 value, RFC_ERROR_INFO* errorInfo);


	/**
	 * \brief  Copies the given structure into the target structure of the parent container.
	 * \ingroup container
	 *
	 * The target field needs to be of type RFCTYPE_STRUCTURE.
	 *
	 * \note If you want to avoid the copy operation, use RfcGetStructure() and set the subfields here,
	 * instead of the sequence RfcCreateStructure()/ setting the subfields/ #RfcSetStructure().
	 *
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to set.
	 * \in value The structure to copy.
	 * \out *errorInfo Out of memory, field does not exist or is not of type RFCTYPE_STRUCTURE?
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcSetStructure(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, const RFC_STRUCTURE_HANDLE value, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Copies the given table into the target table of the parent container.
	 * \ingroup container
	 *
	 * The target field needs to be of type RFCTYPE_TABLE.
	 *
	 * \note If you want to avoid the copy operation, use RfcGetTable() and set the subfields here,
	 * instead of the sequence RfcCreateTable()/ setting the subfields/ #RfcSetTable().
	 *
	 * \in dataHandle A data container (function handle, structure handle or table handle). If dataHandle
	 * is a table handle, the function will read the field value of the current row.
	 * \in *name The name of the field to set.
	 * \in value The table to copy.
	 * \out *errorInfo Field does not exist or is not of type RFCTYPE_TABLE?
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcSetTable(DATA_CONTAINER_HANDLE dataHandle, SAP_UC const* name, const RFC_TABLE_HANDLE value, RFC_ERROR_INFO* errorInfo);

	/**
     * \brief  Returns the metadata description for the given function module.
     * \ingroup container
     * 
     * 
     * \in funcHandle A function module.
     * \out *errorInfo Can't possibly go wrong...
     * \return The metadata description that had been used when creating the function module container.
     */
    DECL_EXP RFC_FUNCTION_DESC_HANDLE SAP_API RfcDescribeFunction(RFC_FUNCTION_HANDLE funcHandle, RFC_ERROR_INFO* errorInfo);
    
    /**
     * \brief  Returns the metadata description of the given structure or table (RFC_STRUCTURE_HANDLE or RFC_TABLE_HANDLE).
     * \ingroup container
     * 
     * 
     * \in dataHandle A structure or table.
     * \out *errorInfo Can't possibly go wrong...
     * \return The type description of the given structure (in case dataHandle is a structure), or the
	 * type description of the table line type (in case dataHandle is a table).
     */
    DECL_EXP RFC_TYPE_DESC_HANDLE SAP_API RfcDescribeType(DATA_CONTAINER_HANDLE dataHandle, RFC_ERROR_INFO* errorInfo);


    /* ************************************************************************/
    /*                                                                       */
    /*  Metadata and Repository API                                          */
    /*                                                                       */
    /* ************************************************************************/
	
    /* 1. Repository API */

	/**
	 * \brief  Returns the function description that is valid for the system to which rfcHandle points to.
	 * \ingroup repository
	 * 
     * If the function description is already in the repository cache for that system ID, it will be 
	 * returned immediately (from the cache), otherwise it will be looked up in the system's DDIC using
	 * the rfcHandle. The result from the DDIC lookup will then be placed into the cache for later use.
	 *
	 * The RFC Runtime maintains a cache for every R/3 System ID, as the meta data could be different
	 * from R/3 release to R/3 release.
     * This is the main API that should be used.
	 * 
	 * \in rfcHandle Open client connection to the R/3 System, for which you need the function module description.
	 * \in *funcName Name of the function module to look up.
	 * \out *errorInfo More error details in case something goes wrong.
	 * \return The metadata description of the given function module.
	 */
	DECL_EXP RFC_FUNCTION_DESC_HANDLE SAP_API RfcGetFunctionDesc(RFC_CONNECTION_HANDLE rfcHandle, SAP_UC const * funcName, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Looks for a cached function description. 
	 * \ingroup repository
	 * 
     * This API should be used with care and is only for special scenarios, for example:
	 * 1. You know for sure, that a function description has already been cached via RfcGetFunctionDesc(),
	 *    and don't want to open an extra rfcHandle that will never be used.
	 *    In this case simply use the SAP System ID as the repositoryID.
	 * 2. You have created a hard-coded repository via RfcAddFunctionDesc(), which contains function modules
	 *    that do not exist in the backend's DDIC.
     * 
     * If repositoryID is NULL, the "default repository" is used.
	 * 
	 * \in *repositoryID System ID of R/3 System, for which this function module description has been cached,
	 * or NULL in case you want to look for it in the default repository.
	 * \in *funcName Name of the function module.
	 * \out *errorInfo Requested function name not in cache?
	 * \return The requested function description.
	 */
	DECL_EXP RFC_FUNCTION_DESC_HANDLE SAP_API RfcGetCachedFunctionDesc(SAP_UC const * repositoryID, SAP_UC const * funcName, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Adds a function description to the cache for the specified R/3 System.
	 * \ingroup repository
     * 
     * This API should be used with care and is only for special scenarios, e.g. if you want to
	 * write an RFC server that offers function modules, which do not exist in the R/3 system's DDIC.
     * If repositoryID is NULL, the description is added to the "default repository".
	 * 
	 * 
	 * \in *repositoryID System ID of R/3 System, to whose cache you want to add the function description,
	 * or NULL for the default repository.
	 * \in funcDesc The function description.
	 * \out *errorInfo Not much that can go wrong here.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcAddFunctionDesc(SAP_UC const * repositoryID, RFC_FUNCTION_DESC_HANDLE funcDesc, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Returns the structure description that is valid for the system to which rfcHandle points to.
	 * \ingroup repository
	 * 
     * If the structure description is already in the repository cache for that system ID, it will be 
	 * returned immediately (from the cache), otherwise it will be looked up in the system's DDIC using
	 * the rfcHandle. The result from the DDIC lookup will then be placed into the cache for later use.
	 *
	 * The RFC Runtime maintains a cache for every R/3 System ID, as the meta data could be different
	 * from R/3 release to R/3 release.
	 * \note Normally it should not be necessary to lookup separate structure descriptions. They are
	 * already looked up as part of the function module, in which they are used.
	 * 
	 * \in rfcHandle Open client connection to the R/3 System, for which you need the structure description.
	 * \in *typeName Name of a DDIC structure or table.
	 * \out *errorInfo More error details in case something goes wrong.
	 * \return The metadata description of the given structure/table.
	 */
	DECL_EXP RFC_TYPE_DESC_HANDLE SAP_API RfcGetTypeDesc(RFC_CONNECTION_HANDLE rfcHandle, SAP_UC const * typeName, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Looks for a cached structure/table description. 
	 * \ingroup repository
	 *
	 * Similar to RfcGetTypeDesc(), but it only looks into the cache. Again it should almost never
	 * be necessary to get a metadata description of a single structure.
	 * 
	 * \in *repositoryID System ID of R/3 System, for which this type description has been cached,
	 * or NULL in case you want to look for it in the default repository.
	 * \in *typeName Name of the DDIC structure/table.
	 * \out *errorInfo Requested type name not in cache?
	 * \return The requested type description.
	 */
	DECL_EXP RFC_TYPE_DESC_HANDLE SAP_API RfcGetCachedTypeDesc(SAP_UC const * repositoryID, SAP_UC const * typeName, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Adds a type description to the cache.
	 * \ingroup repository
	 * 
	 * 
	 * \in *repositoryID System ID of R/3 System, to whose cache you want to add the type description,
	 * or NULL for the default repository.
	 * \in typeHandle The type description.
	 * \out *errorInfo Not much that can go wrong here.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcAddTypeDesc(SAP_UC const * repositoryID, RFC_TYPE_DESC_HANDLE typeHandle, RFC_ERROR_INFO* errorInfo);

    /* 2. Metadata API */
    /* 2.1. Metadata API for structure descriptions */

    /**
     * \brief  Creates an empty type description with the given name.
     * \ingroup structure
     *
     * API for creating hard-coded metadata descriptions, e.g. for function modules that
     * don't exist in the R/3 backend.
     * Add field descriptions to the type description using RfcAddTypeField() and at the end
	 * set the total byte length of the structure using RfcSetTypeLength().
	 * \warning It is not easy to get the total length right, as you also need to take
	 * alignment bytes into account...
	 *
     * Finished type defintions can then be used for creating data containers (RfcCreateStructure()
	 * or RfcCreateTable()) and for adding field/table descriptions to a function module description
	 * (in RFC_PARAMETER_DESCs in RfcAddParameter()).
     * 
     * \in *name An (arbitrary) name for the type.
     * \out *errorInfo Not enough memory?
     * \return The new type description.
     */
    DECL_EXP RFC_TYPE_DESC_HANDLE SAP_API RfcCreateTypeDesc(SAP_UC const* name, RFC_ERROR_INFO* errorInfo);

    /*
     * 
     * After the handle was used, any modifications are forbidden.
     */
    /**
     * \brief  Adds a new field to the type description.
     * \ingroup structure
	 *
     * \note After a type description has been used (e.g. via RfcCreateStructure(), RfcCreateTable() or
	 * RfcAddTypeDesc()), it can no longer be modified!
     * 
     * \in typeHandle 
     * \in *fieldDescr 
     * \out *errorInfo 
     * \return RFC_RC
     */
	DECL_EXP RFC_RC SAP_API RfcAddTypeField(RFC_TYPE_DESC_HANDLE typeHandle, const RFC_FIELD_DESC* fieldDescr, RFC_ERROR_INFO* errorInfo);

	/**
     * \brief  Sets the total byte length of the type description.
     * \ingroup structure
     * 
	 * Before a type description can be used, this function needs to be called.
	 * The RFC library does not automatically calculate the correct length based on
	 * the fields that have been added, because this task is non-trivial and possibly
	 * platform dependend. (Especially if the structure contains sub-structures.)\n
	 * For integer and floating point types the correct alignments need to be taken into
	 * account (start address divisible by 4 or 8), fixed sub-structures are inlined,
	 * complex structures are referenced by an 8-byte pointer, etc. In general you will need
	 * to do a bit of trial and error, before you get it right.\n
	 * If you really need more details/tips for the process of hardcoding metadata, see
	 * this <A HREF="http://www.sappro.com/archive/Volume_10_(2008)/Issue_02_(March_and_April)/V10I2A5.cfm">
	 * article</A>.
     * 
     * \in typeHandle The type description.
     * \in nucByteLength Total byte length of the structure in a non-Unicode system (1 byte per CHAR).
     * \in ucByteLength Total byte length of the structure in a Unicode system (2 bytes per CHAR).
     * \out *errorInfo The function returns an error, if the given byte lengths are smaller than
	 * the sum of all field lengths, or if the nucByteLength is smaller than the ucByteLength.
     * \return RFC_RC
     */
	DECL_EXP RFC_RC SAP_API RfcSetTypeLength(RFC_TYPE_DESC_HANDLE typeHandle, unsigned nucByteLength, unsigned ucByteLength, RFC_ERROR_INFO* errorInfo);

	/**
     * \brief  Returns the name of the type.
     * \ingroup structure
     * 
     * 
     * \in typeHandle The type description.
     * \out bufferForName Will receive the null-terminated DDIC name of the structure definition.
     * \out *errorInfo Should always return successfully...
     * \return RFC_RC
     */
	DECL_EXP RFC_RC SAP_API RfcGetTypeName(RFC_TYPE_DESC_HANDLE typeHandle, RFC_ABAP_NAME bufferForName, RFC_ERROR_INFO* errorInfo);

	/**
     * \brief  Returns the number of fields in a structure definition.
     * \ingroup structure
     * 
     * 
     * \in typeHandle The type description.
     * \out *count The number of (direct) fields of this structure.
     * \out *errorInfo Should always return successfully...
     * \return RFC_RC
     */
	DECL_EXP RFC_RC SAP_API RfcGetFieldCount(RFC_TYPE_DESC_HANDLE typeHandle, unsigned* count, RFC_ERROR_INFO* errorInfo);

    /**
     * \brief  Reads the field description of the structure's ith field.
     * \ingroup structure
     *
	 * Useful mostly when looping over the fields of a structure.
     * 
     * \in typeHandle The type description.
     * \in index The index of the field you are interested in.
     * \out *fieldDescr Will be filled with field's description.
     * \out *errorInfo Index out of bounds?
     * \return RFC_RC
     */
    DECL_EXP RFC_RC SAP_API RfcGetFieldDescByIndex(RFC_TYPE_DESC_HANDLE typeHandle, unsigned index, RFC_FIELD_DESC* fieldDescr, RFC_ERROR_INFO* errorInfo);

    /**
     * \brief  Reads the field description of a field given by name.
     * \ingroup structure
     * 
     * 
     * \in typeHandle The type description.
     * \in *name The name of the field of interest.
     * \out *fieldDescr Will be filled with field's description.
     * \out *errorInfo No such field?
     * \return RFC_RC
     */
    DECL_EXP RFC_RC SAP_API RfcGetFieldDescByName(RFC_TYPE_DESC_HANDLE typeHandle, SAP_UC const* name, RFC_FIELD_DESC* fieldDescr, RFC_ERROR_INFO* errorInfo);

    /**
     * \brief  Returns the total byte length of a structure definition.
     * \ingroup structure
     * 
     * 
     * \in typeHandle The type description.
     * \out nucByteLength Total byte length in a non-Unicode system.
     * \out ucByteLength Total byte length in a Unicode system.
     * \out *errorInfo Should always return successfully.
     * \return RFC_RC
     */
    DECL_EXP RFC_RC SAP_API RfcGetTypeLength(RFC_TYPE_DESC_HANDLE typeHandle, unsigned* nucByteLength, unsigned* ucByteLength, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Deletes the type description and releases the allocated resources.
	 * \ingroup structure
     * 
     * Only descriptions, which are not stored in a repository cache and not used by the application, can be deleted.
     * Deleting a cached description will cause an error, and deleting a description that is still in use, will lead
     * to a crash.
	 * 
	 * 
	 * \inout typeHandle The type description to be deleted.
	 * \out *errorInfo 
	 * \return 
	 */
	DECL_EXP RFC_RC SAP_API RfcDestroyTypeDesc(RFC_TYPE_DESC_HANDLE typeHandle, RFC_ERROR_INFO *errorInfo);



    /* 2.2. Metadata API for function descriptions */

    /**
     * \brief  Creates an empty function description with the given name.
     * \ingroup function
	 *
     * Add parameter descriptions and exception descriptions to the new RFC_FUNCTION_DESC_HANDLE
	 * via RfcAddParameter() and RfcAddException().\n
     * 
     * 
     * \in *name The name of the function module.
     * \out *errorInfo Probably not enough memory left?!
     * \return An empty function description that can be used for constructing hard-coded metadata.
     */
    DECL_EXP RFC_FUNCTION_DESC_HANDLE SAP_API RfcCreateFunctionDesc(SAP_UC const* name, RFC_ERROR_INFO* errorInfo);

    /**
     * \brief  Returns a function module's DDIC name.
     * \ingroup function
     * 
     * 
     * \in funcDesc The function module description.
     * \out bufferForName Will receive the function module's DDIC name.
     * \out *errorInfo Should always return successfully.
     * \return RFC_RC
     */
    DECL_EXP RFC_RC SAP_API RfcGetFunctionName(RFC_FUNCTION_DESC_HANDLE funcDesc, RFC_ABAP_NAME bufferForName, RFC_ERROR_INFO* errorInfo);

    /**
     * \brief  Adds a new parameter (IMPORTING, EXPORTING, CHANGING, TABLES) to the function description.
     * \ingroup function
     * 
	 * \note After the function description has been used via RfcCreateFunction() or RfcAddFunctionDesc(),
	 * it can no longer be modified!
     * 
     * \in funcDesc The function module description.
     * \in *paramDescr Metadata description of the new parameter.
     * \out *errorInfo More details in case something goes wrong.
     * \return RFC_RC
     */
    DECL_EXP RFC_RC SAP_API RfcAddParameter(RFC_FUNCTION_DESC_HANDLE funcDesc, const RFC_PARAMETER_DESC* paramDescr, RFC_ERROR_INFO* errorInfo);

    /**
     * \brief  Returns the number of parameters in the function module definition.
     * \ingroup function
     * 
     * 
     * \in funcDesc The function module's metadata description.
     * \out *count The number of parameters (IMPORTING, EXPORTING, CHANGING, TABLES).
     * \out *errorInfo Nothing can go wrong here.
     * \return RFC_RC
     */
    DECL_EXP RFC_RC SAP_API RfcGetParameterCount(RFC_FUNCTION_DESC_HANDLE funcDesc, unsigned* count, RFC_ERROR_INFO* errorInfo);

    /**
     * \brief  Reads the metadata description of the function module's ith parameter.
     * \ingroup function
	 *
     * \note Mostly be useful when looping over all parameters of a function module.
     * 
     * \in funcDesc The function module's metadata description.
     * \in index The index of the parameter to describe.
     * \out *paramDesc Metadata description of the specified parameter.
     * \out *errorInfo Index out of bounds?
     * \return RFC_RC
     */
    DECL_EXP RFC_RC SAP_API RfcGetParameterDescByIndex(RFC_FUNCTION_DESC_HANDLE funcDesc, unsigned index, RFC_PARAMETER_DESC* paramDesc, RFC_ERROR_INFO* errorInfo);

    /**
     * \brief  Reads the metadata description of a function module parameter given by name.
     * \ingroup function
     * 
     * 
     * \in funcDesc The function module's metadata description.
     * \in *name The name of the parameter to describe.
     * \out *paramDesc Metadata description of the specified parameter.
     * \out *errorInfo No such parameter?
     * \return RFC_RC
     */
    DECL_EXP RFC_RC SAP_API RfcGetParameterDescByName(RFC_FUNCTION_DESC_HANDLE funcDesc, SAP_UC const* name, RFC_PARAMETER_DESC* paramDesc, RFC_ERROR_INFO* errorInfo);

    /**
     * \brief  Adds a new ABAP Exception to the function description.
     * \ingroup function
     * 
	 * \note After the function description has been used via RfcCreateFunction() or RfcAddFunctionDesc(),
	 * it can no longer be modified!
     * 
     * 
     * \in funcDesc The function module's metadata description.
     * \in *excDesc The description of the exception to add.
     * \out *errorInfo Not much that can go wrong here.
     * \return RFC_RC
     */
    DECL_EXP RFC_RC SAP_API RfcAddException(RFC_FUNCTION_DESC_HANDLE funcDesc, const RFC_EXCEPTION_DESC* excDesc, RFC_ERROR_INFO* errorInfo);

    /**
     * \brief  Returns the number of ABAP Exceptions of the function module.
     * \ingroup function
     * 
     * 
     * \in funcDesc The function module's metadata description.
     * \out *count The number of the function module's ABAP Exceptions.
     * \out *errorInfo Not much that can go wrong here.
     * \return RFC_RC
     */
    DECL_EXP RFC_RC SAP_API RfcGetExceptionCount(RFC_FUNCTION_DESC_HANDLE funcDesc, unsigned* count, RFC_ERROR_INFO* errorInfo);

    /**
     * \brief  Reads the metadata description of the function module's ith ABAP Exception.
     * \ingroup function
     * 
     * 
     * \in funcDesc The function module's metadata description.
     * \in index The index of the exception to describe.
     * \out *excDesc The ABAP Exception's metadata description.
     * \out *errorInfo Index out of bounds?
     * \return RFC_RC
     */
    DECL_EXP RFC_RC SAP_API RfcGetExceptionDescByIndex(RFC_FUNCTION_DESC_HANDLE funcDesc, unsigned index, RFC_EXCEPTION_DESC* excDesc, RFC_ERROR_INFO* errorInfo);

	/**
     * \brief  Reads the metadata description of a function module's ABAP Exception given by name.
     * \ingroup function
     * 
     * 
     * \in funcDesc The function module's metadata description.
     * \in *name The name of the exception to describe.
     * \out *excDesc The ABAP Exception's metadata description.
     * \out *errorInfo No such ABAP Exception?
     * \return RFC_RC
     */
    DECL_EXP RFC_RC SAP_API RfcGetExceptionDescByName(RFC_FUNCTION_DESC_HANDLE funcDesc, SAP_UC const* name, RFC_EXCEPTION_DESC* excDesc, RFC_ERROR_INFO* errorInfo);

	/**
	 * \brief  Enables this function module for the basXML serialization format.
	 * \ingroup function
	 *
	 * R/3 Systems from kernel release 7.10 on support a new serialization format: basXML (binary ABAP serialization).
	 * Calling #RfcEnableBASXML() allows the RFC library to transport this function module's data via the
	 * basXML format, if the target backend supports it.
	 * 
	 * \in funcDesc The function module's metadata description.
	 * \out *errorInfo Should always return successfully.
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcEnableBASXML(RFC_FUNCTION_DESC_HANDLE funcDesc, RFC_ERROR_INFO* errorInfo);

    /**
     * \brief  Returns whether this function module has been enabled for basXML.
     * \ingroup function
	 *
     * See RfcEnableBASXML()
     * 
     * \in funcDesc The function module's metadata description.
     * \out *isEnabled 0 = false, 1 = true.
     * \out *errorInfo Should always return successfully.
     * \return RFC_RC
     */
    DECL_EXP RFC_RC SAP_API RfcIsBASXMLSupported(RFC_FUNCTION_DESC_HANDLE funcDesc, int* isEnabled, RFC_ERROR_INFO* errorInfo);


	/**
	 * \brief  Deletes the function description and releases the allocated resources.
	 * \ingroup function
     * 
     * Only descriptions, which are not stored in a repository cache and not used by the application, can be deleted.
     * Deleting a cached description will cause an error, and deleting a description that is still in use, will lead
     * to a crash.
	 * 
	 * 
	 * \in funcDesc A function description.
	 * \out *errorInfo Should always return successfully...
	 * \return RFC_RC
	 */
	DECL_EXP RFC_RC SAP_API RfcDestroyFunctionDesc(RFC_FUNCTION_DESC_HANDLE funcDesc, RFC_ERROR_INFO *errorInfo);

#ifdef __cplusplus
}
#endif /*cplusplus*/

#endif
