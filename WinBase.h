/************************************************************************
*                                                                       *
*   winbase.h -- This module defines the 32-Bit Windows Base APIs       *
*                                                                       *
*   Copyright (c) Microsoft Corp. All rights reserved.                  *
*                                                                       *
************************************************************************/
#ifndef _WINBASE_
#define _WINBASE_


#if _MSC_VER > 1000
#pragma once
#endif

#ifdef _MAC
#include <macwin32.h>
#endif 

//

//

#if !defined(_ADVAPI32_)
#define WINADVAPI DECLSPEC_IMPORT
#else
#define WINADVAPI
#endif

#if !defined(_KERNEL32_)
#define WINBASEAPI DECLSPEC_IMPORT
#else
#define WINBASEAPI
#endif

#if !defined(_ZAWPROXY_)
#define ZAWPROXYAPI DECLSPEC_IMPORT
#else
#define ZAWPROXYAPI
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Compatibility macros
 */

#define DefineHandleTable(w)            ((w),TRUE)
#define LimitEmsPages(dw)
#define SetSwapAreaSize(w)              (w)
#define LockSegment(w)                  GlobalFix((HANDLE)(w))
#define UnlockSegment(w)                GlobalUnfix((HANDLE)(w))
#define GetCurrentTime()                GetTickCount()

#define Yield()

#define INVALID_HANDLE_VALUE ((HANDLE)(LONG_PTR)-1)
#define INVALID_FILE_SIZE ((DWORD)0xFFFFFFFF)
#define INVALID_SET_FILE_POINTER ((DWORD)-1)
#define INVALID_FILE_ATTRIBUTES ((DWORD)-1)

#define FILE_BEGIN           0
#define FILE_CURRENT         1
#define FILE_END             2

#define TIME_ZONE_ID_INVALID ((DWORD)0xFFFFFFFF)

#define WAIT_FAILED ((DWORD)0xFFFFFFFF)
#define WAIT_OBJECT_0       ((STATUS_WAIT_0 ) + 0 )

#define WAIT_ABANDONED         ((STATUS_ABANDONED_WAIT_0 ) + 0 )
#define WAIT_ABANDONED_0       ((STATUS_ABANDONED_WAIT_0 ) + 0 )

#define WAIT_IO_COMPLETION                  STATUS_USER_APC
#define STILL_ACTIVE                        STATUS_PENDING
#define EXCEPTION_ACCESS_VIOLATION          STATUS_ACCESS_VIOLATION
#define EXCEPTION_DATATYPE_MISALIGNMENT     STATUS_DATATYPE_MISALIGNMENT
#define EXCEPTION_BREAKPOINT                STATUS_BREAKPOINT
#define EXCEPTION_SINGLE_STEP               STATUS_SINGLE_STEP
#define EXCEPTION_ARRAY_BOUNDS_EXCEEDED     STATUS_ARRAY_BOUNDS_EXCEEDED
#define EXCEPTION_FLT_DENORMAL_OPERAND      STATUS_FLOAT_DENORMAL_OPERAND
#define EXCEPTION_FLT_DIVIDE_BY_ZERO        STATUS_FLOAT_DIVIDE_BY_ZERO
#define EXCEPTION_FLT_INEXACT_RESULT        STATUS_FLOAT_INEXACT_RESULT
#define EXCEPTION_FLT_INVALID_OPERATION     STATUS_FLOAT_INVALID_OPERATION
#define EXCEPTION_FLT_OVERFLOW              STATUS_FLOAT_OVERFLOW
#define EXCEPTION_FLT_STACK_CHECK           STATUS_FLOAT_STACK_CHECK
#define EXCEPTION_FLT_UNDERFLOW             STATUS_FLOAT_UNDERFLOW
#define EXCEPTION_INT_DIVIDE_BY_ZERO        STATUS_INTEGER_DIVIDE_BY_ZERO
#define EXCEPTION_INT_OVERFLOW              STATUS_INTEGER_OVERFLOW
#define EXCEPTION_PRIV_INSTRUCTION          STATUS_PRIVILEGED_INSTRUCTION
#define EXCEPTION_IN_PAGE_ERROR             STATUS_IN_PAGE_ERROR
#define EXCEPTION_ILLEGAL_INSTRUCTION       STATUS_ILLEGAL_INSTRUCTION
#define EXCEPTION_NONCONTINUABLE_EXCEPTION  STATUS_NONCONTINUABLE_EXCEPTION
#define EXCEPTION_STACK_OVERFLOW            STATUS_STACK_OVERFLOW
#define EXCEPTION_INVALID_DISPOSITION       STATUS_INVALID_DISPOSITION
#define EXCEPTION_GUARD_PAGE                STATUS_GUARD_PAGE_VIOLATION
#define EXCEPTION_INVALID_HANDLE            STATUS_INVALID_HANDLE
#define CONTROL_C_EXIT                      STATUS_CONTROL_C_EXIT
#define MoveMemory RtlMoveMemory
#define CopyMemory RtlCopyMemory
#define FillMemory RtlFillMemory
#define ZeroMemory RtlZeroMemory
#define SecureZeroMemory RtlSecureZeroMemory

//


//

#define FILE_FLAG_WRITE_THROUGH         0x80000000
#define FILE_FLAG_OVERLAPPED            0x40000000
#define FILE_FLAG_NO_BUFFERING          0x20000000
#define FILE_FLAG_RANDOM_ACCESS         0x10000000
#define FILE_FLAG_SEQUENTIAL_SCAN       0x08000000
#define FILE_FLAG_DELETE_ON_CLOSE       0x04000000
#define FILE_FLAG_BACKUP_SEMANTICS      0x02000000
#define FILE_FLAG_POSIX_SEMANTICS       0x01000000
#define FILE_FLAG_OPEN_REPARSE_POINT    0x00200000
#define FILE_FLAG_OPEN_NO_RECALL        0x00100000
#define FILE_FLAG_FIRST_PIPE_INSTANCE   0x00080000

#define CREATE_NEW          1
#define CREATE_ALWAYS       2
#define OPEN_EXISTING       3
#define OPEN_ALWAYS         4
#define TRUNCATE_EXISTING   5

#if(_WIN32_WINNT >= 0x0400)
//

//

#define PROGRESS_CONTINUE   0
#define PROGRESS_CANCEL     1
#define PROGRESS_STOP       2
#define PROGRESS_QUIET      3

//

//

#define CALLBACK_CHUNK_FINISHED         0x00000000
#define CALLBACK_STREAM_SWITCH          0x00000001

//

//

#define COPY_FILE_FAIL_IF_EXISTS              0x00000001
#define COPY_FILE_RESTARTABLE                 0x00000002
#define COPY_FILE_OPEN_SOURCE_FOR_WRITE       0x00000004
#define COPY_FILE_ALLOW_DECRYPTED_DESTINATION 0x00000008
#endif 

#if (_WIN32_WINNT >= 0x0500)
//

//

#define REPLACEFILE_WRITE_THROUGH       0x00000001
#define REPLACEFILE_IGNORE_MERGE_ERRORS 0x00000002

#endif 

//

//


//

//

#define PIPE_ACCESS_INBOUND         0x00000001
#define PIPE_ACCESS_OUTBOUND        0x00000002
#define PIPE_ACCESS_DUPLEX          0x00000003

//

//

#define PIPE_CLIENT_END             0x00000000
#define PIPE_SERVER_END             0x00000001

//

//

#define PIPE_WAIT                   0x00000000
#define PIPE_NOWAIT                 0x00000001
#define PIPE_READMODE_BYTE          0x00000000
#define PIPE_READMODE_MESSAGE       0x00000002
#define PIPE_TYPE_BYTE              0x00000000
#define PIPE_TYPE_MESSAGE           0x00000004

//

//

#define PIPE_UNLIMITED_INSTANCES    255

//


//

#define SECURITY_ANONYMOUS          ( SecurityAnonymous      << 16 )
#define SECURITY_IDENTIFICATION     ( SecurityIdentification << 16 )
#define SECURITY_IMPERSONATION      ( SecurityImpersonation  << 16 )
#define SECURITY_DELEGATION         ( SecurityDelegation     << 16 )

#define SECURITY_CONTEXT_TRACKING  0x00040000
#define SECURITY_EFFECTIVE_ONLY    0x00080000

#define SECURITY_SQOS_PRESENT      0x00100000
#define SECURITY_VALID_SQOS_FLAGS  0x001F0000

//

//

typedef struct _OVERLAPPED {
    ULONG_PTR Internal;
    ULONG_PTR InternalHigh;
    union {
        struct {
            DWORD Offset;
            DWORD OffsetHigh;
        };

        PVOID Pointer;
    };

    HANDLE  hEvent;
} OVERLAPPED, *LPOVERLAPPED;

typedef struct _SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

typedef struct _PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD dwProcessId;
    DWORD dwThreadId;
} PROCESS_INFORMATION, *PPROCESS_INFORMATION, *LPPROCESS_INFORMATION;

//

//


#ifndef _FILETIME_
#define _FILETIME_
typedef struct _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
} FILETIME, *PFILETIME, *LPFILETIME;
#endif

//

//


typedef struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME, *LPSYSTEMTIME;


typedef DWORD (WINAPI *PTHREAD_START_ROUTINE)(
    LPVOID lpThreadParameter
    );
typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;

#if(_WIN32_WINNT >= 0x0400)
typedef VOID (WINAPI *PFIBER_START_ROUTINE)(
    LPVOID lpFiberParameter
    );
typedef PFIBER_START_ROUTINE LPFIBER_START_ROUTINE;
#endif 

typedef RTL_CRITICAL_SECTION CRITICAL_SECTION;
typedef PRTL_CRITICAL_SECTION PCRITICAL_SECTION;
typedef PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;

typedef RTL_CRITICAL_SECTION_DEBUG CRITICAL_SECTION_DEBUG;
typedef PRTL_CRITICAL_SECTION_DEBUG PCRITICAL_SECTION_DEBUG;
typedef PRTL_CRITICAL_SECTION_DEBUG LPCRITICAL_SECTION_DEBUG;

#if defined(_X86_)
typedef PLDT_ENTRY LPLDT_ENTRY;
#else
typedef LPVOID LPLDT_ENTRY;
#endif

#define MUTEX_MODIFY_STATE MUTANT_QUERY_STATE
#define MUTEX_ALL_ACCESS MUTANT_ALL_ACCESS

//

//

#define SP_SERIALCOMM    ((DWORD)0x00000001)

//

//

#define PST_UNSPECIFIED      ((DWORD)0x00000000)
#define PST_RS232            ((DWORD)0x00000001)
#define PST_PARALLELPORT     ((DWORD)0x00000002)
#define PST_RS422            ((DWORD)0x00000003)
#define PST_RS423            ((DWORD)0x00000004)
#define PST_RS449            ((DWORD)0x00000005)
#define PST_MODEM            ((DWORD)0x00000006)
#define PST_FAX              ((DWORD)0x00000021)
#define PST_SCANNER          ((DWORD)0x00000022)
#define PST_NETWORK_BRIDGE   ((DWORD)0x00000100)
#define PST_LAT              ((DWORD)0x00000101)
#define PST_TCPIP_TELNET     ((DWORD)0x00000102)
#define PST_X25              ((DWORD)0x00000103)


//

//

#define PCF_DTRDSR        ((DWORD)0x0001)
#define PCF_RTSCTS        ((DWORD)0x0002)
#define PCF_RLSD          ((DWORD)0x0004)
#define PCF_PARITY_CHECK  ((DWORD)0x0008)
#define PCF_XONXOFF       ((DWORD)0x0010)
#define PCF_SETXCHAR      ((DWORD)0x0020)
#define PCF_TOTALTIMEOUTS ((DWORD)0x0040)
#define PCF_INTTIMEOUTS   ((DWORD)0x0080)
#define PCF_SPECIALCHARS  ((DWORD)0x0100)
#define PCF_16BITMODE     ((DWORD)0x0200)

//

//

#define SP_PARITY         ((DWORD)0x0001)
#define SP_BAUD           ((DWORD)0x0002)
#define SP_DATABITS       ((DWORD)0x0004)
#define SP_STOPBITS       ((DWORD)0x0008)
#define SP_HANDSHAKING    ((DWORD)0x0010)
#define SP_PARITY_CHECK   ((DWORD)0x0020)
#define SP_RLSD           ((DWORD)0x0040)

//

//

#define BAUD_075          ((DWORD)0x00000001)
#define BAUD_110          ((DWORD)0x00000002)
#define BAUD_134_5        ((DWORD)0x00000004)
#define BAUD_150          ((DWORD)0x00000008)
#define BAUD_300          ((DWORD)0x00000010)
#define BAUD_600          ((DWORD)0x00000020)
#define BAUD_1200         ((DWORD)0x00000040)
#define BAUD_1800         ((DWORD)0x00000080)
#define BAUD_2400         ((DWORD)0x00000100)
#define BAUD_4800         ((DWORD)0x00000200)
#define BAUD_7200         ((DWORD)0x00000400)
#define BAUD_9600         ((DWORD)0x00000800)
#define BAUD_14400        ((DWORD)0x00001000)
#define BAUD_19200        ((DWORD)0x00002000)
#define BAUD_38400        ((DWORD)0x00004000)
#define BAUD_56K          ((DWORD)0x00008000)
#define BAUD_128K         ((DWORD)0x00010000)
#define BAUD_115200       ((DWORD)0x00020000)
#define BAUD_57600        ((DWORD)0x00040000)
#define BAUD_USER         ((DWORD)0x10000000)

//

//

#define DATABITS_5        ((WORD)0x0001)
#define DATABITS_6        ((WORD)0x0002)
#define DATABITS_7        ((WORD)0x0004)
#define DATABITS_8        ((WORD)0x0008)
#define DATABITS_16       ((WORD)0x0010)
#define DATABITS_16X      ((WORD)0x0020)

//

//

#define STOPBITS_10       ((WORD)0x0001)
#define STOPBITS_15       ((WORD)0x0002)
#define STOPBITS_20       ((WORD)0x0004)
#define PARITY_NONE       ((WORD)0x0100)
#define PARITY_ODD        ((WORD)0x0200)
#define PARITY_EVEN       ((WORD)0x0400)
#define PARITY_MARK       ((WORD)0x0800)
#define PARITY_SPACE      ((WORD)0x1000)

typedef struct _COMMPROP {
    WORD wPacketLength;
    WORD wPacketVersion;
    DWORD dwServiceMask;
    DWORD dwReserved1;
    DWORD dwMaxTxQueue;
    DWORD dwMaxRxQueue;
    DWORD dwMaxBaud;
    DWORD dwProvSubType;
    DWORD dwProvCapabilities;
    DWORD dwSettableParams;
    DWORD dwSettableBaud;
    WORD wSettableData;
    WORD wSettableStopParity;
    DWORD dwCurrentTxQueue;
    DWORD dwCurrentRxQueue;
    DWORD dwProvSpec1;
    DWORD dwProvSpec2;
    WCHAR wcProvChar[1];
} COMMPROP,*LPCOMMPROP;

//


//
#define COMMPROP_INITIALIZED ((DWORD)0xE73CF52E)

typedef struct _COMSTAT {
    DWORD fCtsHold : 1;
    DWORD fDsrHold : 1;
    DWORD fRlsdHold : 1;
    DWORD fXoffHold : 1;
    DWORD fXoffSent : 1;
    DWORD fEof : 1;
    DWORD fTxim : 1;
    DWORD fReserved : 25;
    DWORD cbInQue;
    DWORD cbOutQue;
} COMSTAT, *LPCOMSTAT;

//

//
#define DTR_CONTROL_DISABLE    0x00
#define DTR_CONTROL_ENABLE     0x01
#define DTR_CONTROL_HANDSHAKE  0x02

//

//
#define RTS_CONTROL_DISABLE    0x00
#define RTS_CONTROL_ENABLE     0x01
#define RTS_CONTROL_HANDSHAKE  0x02
#define RTS_CONTROL_TOGGLE     0x03

typedef struct _DCB {
    DWORD DCBlength;      
    DWORD BaudRate;       
    DWORD fBinary: 1;     
    DWORD fParity: 1;     
    DWORD fOutxCtsFlow:1; 
    DWORD fOutxDsrFlow:1; 
    DWORD fDtrControl:2;  
    DWORD fDsrSensitivity:1; 
    DWORD fTXContinueOnXoff: 1; 
    DWORD fOutX: 1;       
    DWORD fInX: 1;        
    DWORD fErrorChar: 1;  
    DWORD fNull: 1;       
    DWORD fRtsControl:2;  
    DWORD fAbortOnError:1; 
    DWORD fDummy2:17;     
    WORD wReserved;       
    WORD XonLim;          
    WORD XoffLim;         
    BYTE ByteSize;        
    BYTE Parity;          
    BYTE StopBits;        
    char XonChar;         
    char XoffChar;        
    char ErrorChar;       
    char EofChar;         
    char EvtChar;         
    WORD wReserved1;      
} DCB, *LPDCB;

typedef struct _COMMTIMEOUTS {
    DWORD ReadIntervalTimeout;          
    DWORD ReadTotalTimeoutMultiplier;   
    DWORD ReadTotalTimeoutConstant;     
    DWORD WriteTotalTimeoutMultiplier;  
    DWORD WriteTotalTimeoutConstant;    
} COMMTIMEOUTS,*LPCOMMTIMEOUTS;

typedef struct _COMMCONFIG {
    DWORD dwSize;               
    WORD wVersion;              
    WORD wReserved;             
    DCB dcb;                    
    DWORD dwProviderSubType;    /* ordinal value for identifying
                                   provider-defined data structure format*/
    DWORD dwProviderOffset;     /* Specifies the offset of provider specific
                                   data field in bytes from the start */
    DWORD dwProviderSize;       
    WCHAR wcProviderData[1];    
} COMMCONFIG,*LPCOMMCONFIG;

typedef struct _SYSTEM_INFO {
    union {
        DWORD dwOemId;          
        struct {
            WORD wProcessorArchitecture;
            WORD wReserved;
        };
    };
    DWORD dwPageSize;
    LPVOID lpMinimumApplicationAddress;
    LPVOID lpMaximumApplicationAddress;
    DWORD_PTR dwActiveProcessorMask;
    DWORD dwNumberOfProcessors;
    DWORD dwProcessorType;
    DWORD dwAllocationGranularity;
    WORD wProcessorLevel;
    WORD wProcessorRevision;
} SYSTEM_INFO, *LPSYSTEM_INFO;

//
//


#define FreeModule(hLibModule) FreeLibrary((hLibModule))
#define MakeProcInstance(lpProc,hInstance) (lpProc)
#define FreeProcInstance(lpProc) (lpProc)


#define GMEM_FIXED          0x0000
#define GMEM_MOVEABLE       0x0002
#define GMEM_NOCOMPACT      0x0010
#define GMEM_NODISCARD      0x0020
#define GMEM_ZEROINIT       0x0040
#define GMEM_MODIFY         0x0080
#define GMEM_DISCARDABLE    0x0100
#define GMEM_NOT_BANKED     0x1000
#define GMEM_SHARE          0x2000
#define GMEM_DDESHARE       0x2000
#define GMEM_NOTIFY         0x4000
#define GMEM_LOWER          GMEM_NOT_BANKED
#define GMEM_VALID_FLAGS    0x7F72
#define GMEM_INVALID_HANDLE 0x8000

#define GHND                (GMEM_MOVEABLE | GMEM_ZEROINIT)
#define GPTR                (GMEM_FIXED | GMEM_ZEROINIT)

#define GlobalLRUNewest( h )    ((HANDLE)(h))
#define GlobalLRUOldest( h )    ((HANDLE)(h))
#define GlobalDiscard( h )      GlobalReAlloc( (h), 0, GMEM_MOVEABLE )


#define GMEM_DISCARDED      0x4000
#define GMEM_LOCKCOUNT      0x00FF

typedef struct _MEMORYSTATUS {
    DWORD dwLength;
    DWORD dwMemoryLoad;
    SIZE_T dwTotalPhys;
    SIZE_T dwAvailPhys;
    SIZE_T dwTotalPageFile;
    SIZE_T dwAvailPageFile;
    SIZE_T dwTotalVirtual;
    SIZE_T dwAvailVirtual;
} MEMORYSTATUS, *LPMEMORYSTATUS;


#define LMEM_FIXED          0x0000
#define LMEM_MOVEABLE       0x0002
#define LMEM_NOCOMPACT      0x0010
#define LMEM_NODISCARD      0x0020
#define LMEM_ZEROINIT       0x0040
#define LMEM_MODIFY         0x0080
#define LMEM_DISCARDABLE    0x0F00
#define LMEM_VALID_FLAGS    0x0F72
#define LMEM_INVALID_HANDLE 0x8000

#define LHND                (LMEM_MOVEABLE | LMEM_ZEROINIT)
#define LPTR                (LMEM_FIXED | LMEM_ZEROINIT)

#define NONZEROLHND         (LMEM_MOVEABLE)
#define NONZEROLPTR         (LMEM_FIXED)

#define LocalDiscard( h )   LocalReAlloc( (h), 0, LMEM_MOVEABLE )


#define LMEM_DISCARDED      0x4000
#define LMEM_LOCKCOUNT      0x00FF

//

//

#define DEBUG_PROCESS                     0x00000001
#define DEBUG_ONLY_THIS_PROCESS           0x00000002

#define CREATE_SUSPENDED                  0x00000004

#define DETACHED_PROCESS                  0x00000008

#define CREATE_NEW_CONSOLE                0x00000010

#define NORMAL_PRIORITY_CLASS             0x00000020
#define IDLE_PRIORITY_CLASS               0x00000040
#define HIGH_PRIORITY_CLASS               0x00000080
#define REALTIME_PRIORITY_CLASS           0x00000100

#define CREATE_NEW_PROCESS_GROUP          0x00000200
#define CREATE_UNICODE_ENVIRONMENT        0x00000400

#define CREATE_SEPARATE_WOW_VDM           0x00000800
#define CREATE_SHARED_WOW_VDM             0x00001000
#define CREATE_FORCEDOS                   0x00002000

#define BELOW_NORMAL_PRIORITY_CLASS       0x00004000
#define ABOVE_NORMAL_PRIORITY_CLASS       0x00008000
#define STACK_SIZE_PARAM_IS_A_RESERVATION 0x00010000

#define CREATE_BREAKAWAY_FROM_JOB         0x01000000
#define CREATE_PRESERVE_CODE_AUTHZ_LEVEL  0x02000000

#define CREATE_DEFAULT_ERROR_MODE         0x04000000
#define CREATE_NO_WINDOW                  0x08000000

#define PROFILE_USER                      0x10000000
#define PROFILE_KERNEL                    0x20000000
#define PROFILE_SERVER                    0x40000000

#define CREATE_IGNORE_SYSTEM_DEFAULT      0x80000000

#define THREAD_PRIORITY_LOWEST          THREAD_BASE_PRIORITY_MIN
#define THREAD_PRIORITY_BELOW_NORMAL    (THREAD_PRIORITY_LOWEST+1)
#define THREAD_PRIORITY_NORMAL          0
#define THREAD_PRIORITY_HIGHEST         THREAD_BASE_PRIORITY_MAX
#define THREAD_PRIORITY_ABOVE_NORMAL    (THREAD_PRIORITY_HIGHEST-1)
#define THREAD_PRIORITY_ERROR_RETURN    (MAXLONG)

#define THREAD_PRIORITY_TIME_CRITICAL   THREAD_BASE_PRIORITY_LOWRT
#define THREAD_PRIORITY_IDLE            THREAD_BASE_PRIORITY_IDLE

//

//
#define EXCEPTION_DEBUG_EVENT       1
#define CREATE_THREAD_DEBUG_EVENT   2
#define CREATE_PROCESS_DEBUG_EVENT  3
#define EXIT_THREAD_DEBUG_EVENT     4
#define EXIT_PROCESS_DEBUG_EVENT    5
#define LOAD_DLL_DEBUG_EVENT        6
#define UNLOAD_DLL_DEBUG_EVENT      7
#define OUTPUT_DEBUG_STRING_EVENT   8
#define RIP_EVENT                   9

typedef struct _EXCEPTION_DEBUG_INFO {
    EXCEPTION_RECORD ExceptionRecord;
    DWORD dwFirstChance;
} EXCEPTION_DEBUG_INFO, *LPEXCEPTION_DEBUG_INFO;

typedef struct _CREATE_THREAD_DEBUG_INFO {
    HANDLE hThread;
    LPVOID lpThreadLocalBase;
    LPTHREAD_START_ROUTINE lpStartAddress;
} CREATE_THREAD_DEBUG_INFO, *LPCREATE_THREAD_DEBUG_INFO;

typedef struct _CREATE_PROCESS_DEBUG_INFO {
    HANDLE hFile;
    HANDLE hProcess;
    HANDLE hThread;
    LPVOID lpBaseOfImage;
    DWORD dwDebugInfoFileOffset;
    DWORD nDebugInfoSize;
    LPVOID lpThreadLocalBase;
    LPTHREAD_START_ROUTINE lpStartAddress;
    LPVOID lpImageName;
    WORD fUnicode;
} CREATE_PROCESS_DEBUG_INFO, *LPCREATE_PROCESS_DEBUG_INFO;

typedef struct _EXIT_THREAD_DEBUG_INFO {
    DWORD dwExitCode;
} EXIT_THREAD_DEBUG_INFO, *LPEXIT_THREAD_DEBUG_INFO;

typedef struct _EXIT_PROCESS_DEBUG_INFO {
    DWORD dwExitCode;
} EXIT_PROCESS_DEBUG_INFO, *LPEXIT_PROCESS_DEBUG_INFO;

typedef struct _LOAD_DLL_DEBUG_INFO {
    HANDLE hFile;
    LPVOID lpBaseOfDll;
    DWORD dwDebugInfoFileOffset;
    DWORD nDebugInfoSize;
    LPVOID lpImageName;
    WORD fUnicode;
} LOAD_DLL_DEBUG_INFO, *LPLOAD_DLL_DEBUG_INFO;

typedef struct _UNLOAD_DLL_DEBUG_INFO {
    LPVOID lpBaseOfDll;
} UNLOAD_DLL_DEBUG_INFO, *LPUNLOAD_DLL_DEBUG_INFO;

typedef struct _OUTPUT_DEBUG_STRING_INFO {
    LPSTR lpDebugStringData;
    WORD fUnicode;
    WORD nDebugStringLength;
} OUTPUT_DEBUG_STRING_INFO, *LPOUTPUT_DEBUG_STRING_INFO;

typedef struct _RIP_INFO {
    DWORD dwError;
    DWORD dwType;
} RIP_INFO, *LPRIP_INFO;


typedef struct _DEBUG_EVENT {
    DWORD dwDebugEventCode;
    DWORD dwProcessId;
    DWORD dwThreadId;
    union {
        EXCEPTION_DEBUG_INFO Exception;
        CREATE_THREAD_DEBUG_INFO CreateThread;
        CREATE_PROCESS_DEBUG_INFO CreateProcessInfo;
        EXIT_THREAD_DEBUG_INFO ExitThread;
        EXIT_PROCESS_DEBUG_INFO ExitProcess;
        LOAD_DLL_DEBUG_INFO LoadDll;
        UNLOAD_DLL_DEBUG_INFO UnloadDll;
        OUTPUT_DEBUG_STRING_INFO DebugString;
        RIP_INFO RipInfo;
    } u;
} DEBUG_EVENT, *LPDEBUG_EVENT;

#if !defined(MIDL_PASS)
typedef PCONTEXT LPCONTEXT;
typedef PEXCEPTION_RECORD LPEXCEPTION_RECORD;
typedef PEXCEPTION_POINTERS LPEXCEPTION_POINTERS;
#endif

#define DRIVE_UNKNOWN     0
#define DRIVE_NO_ROOT_DIR 1
#define DRIVE_REMOVABLE   2
#define DRIVE_FIXED       3
#define DRIVE_REMOTE      4
#define DRIVE_CDROM       5
#define DRIVE_RAMDISK     6


#ifndef _MAC
#define GetFreeSpace(w)                 (0x100000L)
#else
WINBASEAPI DWORD WINAPI GetFreeSpace(UINT);
#endif


#define FILE_TYPE_UNKNOWN   0x0000
#define FILE_TYPE_DISK      0x0001
#define FILE_TYPE_CHAR      0x0002
#define FILE_TYPE_PIPE      0x0003
#define FILE_TYPE_REMOTE    0x8000


#define STD_INPUT_HANDLE    ((DWORD)-10)
#define STD_OUTPUT_HANDLE   ((DWORD)-11)
#define STD_ERROR_HANDLE    ((DWORD)-12)

#define NOPARITY            0
#define ODDPARITY           1
#define EVENPARITY          2
#define MARKPARITY          3
#define SPACEPARITY         4

#define ONESTOPBIT          0
#define ONE5STOPBITS        1
#define TWOSTOPBITS         2

#define IGNORE              0       
#define INFINITE            0xFFFFFFFF  

//

//

#define CBR_110             110
#define CBR_300             300
#define CBR_600             600
#define CBR_1200            1200
#define CBR_2400            2400
#define CBR_4800            4800
#define CBR_9600            9600
#define CBR_14400           14400
#define CBR_19200           19200
#define CBR_38400           38400
#define CBR_56000           56000
#define CBR_57600           57600
#define CBR_115200          115200
#define CBR_128000          128000
#define CBR_256000          256000

//

//

#define CE_RXOVER           0x0001  
#define CE_OVERRUN          0x0002  
#define CE_RXPARITY         0x0004  
#define CE_FRAME            0x0008  
#define CE_BREAK            0x0010  
#define CE_TXFULL           0x0100  
#define CE_PTO              0x0200  
#define CE_IOE              0x0400  
#define CE_DNS              0x0800  
#define CE_OOP              0x1000  
#define CE_MODE             0x8000  

#define IE_BADID            (-1)    
#define IE_OPEN             (-2)    
#define IE_NOPEN            (-3)    
#define IE_MEMORY           (-4)    
#define IE_DEFAULT          (-5)    
#define IE_HARDWARE         (-10)   
#define IE_BYTESIZE         (-11)   
#define IE_BAUDRATE         (-12)   

//

//

#define EV_RXCHAR           0x0001  
#define EV_RXFLAG           0x0002  
#define EV_TXEMPTY          0x0004  
#define EV_CTS              0x0008  
#define EV_DSR              0x0010  
#define EV_RLSD             0x0020  
#define EV_BREAK            0x0040  
#define EV_ERR              0x0080  
#define EV_RING             0x0100  
#define EV_PERR             0x0200  
#define EV_RX80FULL         0x0400  
#define EV_EVENT1           0x0800  
#define EV_EVENT2           0x1000  

//

//

#define SETXOFF             1       
#define SETXON              2       
#define SETRTS              3       
#define CLRRTS              4       
#define SETDTR              5       
#define CLRDTR              6       
#define RESETDEV            7       
#define SETBREAK            8       
#define CLRBREAK            9       

//

//
#define PURGE_TXABORT       0x0001  
#define PURGE_RXABORT       0x0002  
#define PURGE_TXCLEAR       0x0004  
#define PURGE_RXCLEAR       0x0008  

#define LPTx                0x80    

//

//
#define MS_CTS_ON           ((DWORD)0x0010)
#define MS_DSR_ON           ((DWORD)0x0020)
#define MS_RING_ON          ((DWORD)0x0040)
#define MS_RLSD_ON          ((DWORD)0x0080)

//

//

#define S_QUEUEEMPTY        0
#define S_THRESHOLD         1
#define S_ALLTHRESHOLD      2

//

//

#define S_NORMAL      0
#define S_LEGATO      1
#define S_STACCATO    2

//

//

#define S_PERIOD512   0     
#define S_PERIOD1024  1     
#define S_PERIOD2048  2     
#define S_PERIODVOICE 3     
#define S_WHITE512    4     
#define S_WHITE1024   5     
#define S_WHITE2048   6     
#define S_WHITEVOICE  7     

#define S_SERDVNA     (-1)  
#define S_SEROFM      (-2)  
#define S_SERMACT     (-3)  
#define S_SERQFUL     (-4)  
#define S_SERBDNT     (-5)  
#define S_SERDLN      (-6)  
#define S_SERDCC      (-7)  
#define S_SERDTP      (-8)  
#define S_SERDVL      (-9)  
#define S_SERDMD      (-10) 
#define S_SERDSH      (-11) 
#define S_SERDPT      (-12) 
#define S_SERDFQ      (-13) 
#define S_SERDDR      (-14) 
#define S_SERDSR      (-15) 
#define S_SERDST      (-16) 

#define NMPWAIT_WAIT_FOREVER            0xffffffff
#define NMPWAIT_NOWAIT                  0x00000001
#define NMPWAIT_USE_DEFAULT_WAIT        0x00000000

#define FS_CASE_IS_PRESERVED            FILE_CASE_PRESERVED_NAMES
#define FS_CASE_SENSITIVE               FILE_CASE_SENSITIVE_SEARCH
#define FS_UNICODE_STORED_ON_DISK       FILE_UNICODE_ON_DISK
#define FS_PERSISTENT_ACLS              FILE_PERSISTENT_ACLS
#define FS_VOL_IS_COMPRESSED            FILE_VOLUME_IS_COMPRESSED
#define FS_FILE_COMPRESSION             FILE_FILE_COMPRESSION
#define FS_FILE_ENCRYPTION              FILE_SUPPORTS_ENCRYPTION






#define FILE_MAP_COPY       SECTION_QUERY
#define FILE_MAP_WRITE      SECTION_MAP_WRITE
#define FILE_MAP_READ       SECTION_MAP_READ
#define FILE_MAP_ALL_ACCESS SECTION_ALL_ACCESS

#define OF_READ             0x00000000
#define OF_WRITE            0x00000001
#define OF_READWRITE        0x00000002
#define OF_SHARE_COMPAT     0x00000000
#define OF_SHARE_EXCLUSIVE  0x00000010
#define OF_SHARE_DENY_WRITE 0x00000020
#define OF_SHARE_DENY_READ  0x00000030
#define OF_SHARE_DENY_NONE  0x00000040
#define OF_PARSE            0x00000100
#define OF_DELETE           0x00000200
#define OF_VERIFY           0x00000400
#define OF_CANCEL           0x00000800
#define OF_CREATE           0x00001000
#define OF_PROMPT           0x00002000
#define OF_EXIST            0x00004000
#define OF_REOPEN           0x00008000

#define OFS_MAXPATHNAME 128
typedef struct _OFSTRUCT {
    BYTE cBytes;
    BYTE fFixedDisk;
    WORD nErrCode;
    WORD Reserved1;
    WORD Reserved2;
    CHAR szPathName[OFS_MAXPATHNAME];
} OFSTRUCT, *LPOFSTRUCT, *POFSTRUCT;


#ifndef NOWINBASEINTERLOCK

#ifndef _NTOS_

#if defined(_M_IA64) && !defined(RC_INVOKED)

#define InterlockedIncrement _InterlockedIncrement
#define InterlockedDecrement _InterlockedDecrement
#define InterlockedExchange _InterlockedExchange
#define InterlockedExchangeAdd _InterlockedExchangeAdd
#define InterlockedCompareExchange _InterlockedCompareExchange
#define InterlockedExchangePointer _InterlockedExchangePointer
#define InterlockedCompareExchangePointer _InterlockedCompareExchangePointer

#define InterlockedIncrement64 _InterlockedIncrement64
#define InterlockedDecrement64 _InterlockedDecrement64
#define InterlockedExchange64 _InterlockedExchange64
#define InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#define InterlockedCompareExchange64 _InterlockedCompareExchange64


LONGLONG
__cdecl
InterlockedIncrement64(
    IN OUT LONGLONG volatile *Addend
    );

LONGLONG
__cdecl
InterlockedDecrement64(
    IN OUT LONGLONG volatile *Addend
    );

LONGLONG
__cdecl
InterlockedExchange64(
    IN OUT LONGLONG volatile *Target,
    IN LONGLONG Value
    );

LONGLONG
__cdecl
InterlockedExchangeAdd64(
    IN OUT LONGLONG volatile *Addend,
    IN LONGLONG Value
    );

LONGLONG
__cdecl
InterlockedCompareExchange64 (
    IN OUT LONGLONG volatile *Destination,
    IN LONGLONG ExChange,
    IN LONGLONG Comperand
    );

LONG
__cdecl
InterlockedIncrement(
    IN OUT LONG volatile *lpAddend
    );

LONG
__cdecl
InterlockedDecrement(
    IN OUT LONG volatile *lpAddend
    );

LONG
__cdecl
InterlockedExchange(
    IN OUT LONG volatile *Target,
    IN LONG Value
    );

LONG
__cdecl
InterlockedExchangeAdd(
    IN OUT LONG volatile *Addend,
    IN LONG Value
    );

LONG
__cdecl
InterlockedCompareExchange (
    IN OUT LONG volatile *Destination,
    IN LONG ExChange,
    IN LONG Comperand
    );

PVOID
__cdecl
InterlockedExchangePointer(
    IN OUT PVOID volatile *Target,
    IN PVOID Value
    );

PVOID
__cdecl
InterlockedCompareExchangePointer (
    IN OUT PVOID volatile *Destination,
    IN PVOID ExChange,
    IN PVOID Comperand
    );

#if !defined(MIDL_PASS)

#if !defined (InterlockedAnd64)

#define InterlockedAnd64 InterlockedAnd64_Inline

LONGLONG
FORCEINLINE
InterlockedAnd64_Inline (
    IN OUT LONGLONG volatile *Destination,
    IN LONGLONG Value
    )
{
    LONGLONG Old;

    do {
        Old = *Destination;
    } while (InterlockedCompareExchange64(Destination,
                                          Old & Value,
                                          Old) != Old);

    return Old;
}

#endif

#if !defined (InterlockedOr64)

#define InterlockedOr64 InterlockedOr64_Inline

LONGLONG
FORCEINLINE
InterlockedOr64_Inline (
    IN OUT LONGLONG volatile *Destination,
    IN LONGLONG Value
    )
{
    LONGLONG Old;

    do {
        Old = *Destination;
    } while (InterlockedCompareExchange64(Destination,
                                          Old | Value,
                                          Old) != Old);

    return Old;
}

#endif

#if !defined (InterlockedXor64)

#define InterlockedXor64 InterlockedXor64_Inline

LONGLONG
FORCEINLINE
InterlockedXor64_Inline (
    IN OUT LONGLONG volatile *Destination,
    IN LONGLONG Value
    )
{
    LONGLONG Old;

    do {
        Old = *Destination;
    } while (InterlockedCompareExchange64(Destination,
                                          Old ^ Value,
                                          Old) != Old);

    return Old;
}

#endif

#endif

#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)
#pragma intrinsic(_InterlockedExchange)
#pragma intrinsic(_InterlockedExchangeAdd)
#pragma intrinsic(_InterlockedCompareExchange)
#pragma intrinsic(_InterlockedExchangePointer)
#pragma intrinsic(_InterlockedCompareExchangePointer)
#pragma intrinsic(_InterlockedIncrement64)
#pragma intrinsic(_InterlockedDecrement64)
#pragma intrinsic(_InterlockedExchange64)
#pragma intrinsic(_InterlockedCompareExchange64)
#pragma intrinsic(_InterlockedExchangeAdd64)


#elif defined(_M_AMD64) && !defined(RC_INVOKED)

#define InterlockedIncrement _InterlockedIncrement
#define InterlockedDecrement _InterlockedDecrement
#define InterlockedExchange _InterlockedExchange
#define InterlockedExchangeAdd _InterlockedExchangeAdd
#define InterlockedCompareExchange _InterlockedCompareExchange
#define InterlockedExchangePointer _InterlockedExchangePointer
#define InterlockedCompareExchangePointer _InterlockedCompareExchangePointer
#define InterlockedAnd64 _InterlockedAnd64
#define InterlockedOr64 _InterlockedOr64
#define InterlockedXor64 _InterlockedXor64
#define InterlockedIncrement64 _InterlockedIncrement64
#define InterlockedDecrement64 _InterlockedDecrement64
#define InterlockedExchange64 _InterlockedExchange64
#define InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#define InterlockedCompareExchange64 _InterlockedCompareExchange64


LONG
InterlockedIncrement(
    IN OUT LONG volatile *Addend
    );

LONG
InterlockedDecrement(
    IN OUT LONG volatile *Addend
    );

LONG
InterlockedExchange(
    IN OUT LONG volatile *Target,
    IN LONG Value
    );

LONG
InterlockedExchangeAdd(
    IN OUT LONG volatile *Addend,
    IN LONG Value
    );

LONG
InterlockedCompareExchange (
    IN OUT LONG volatile *Destination,
    IN LONG ExChange,
    IN LONG Comperand
    );

PVOID
InterlockedCompareExchangePointer (
    IN OUT PVOID volatile *Destination,
    IN PVOID Exchange,
    IN PVOID Comperand
    );

PVOID
InterlockedExchangePointer(
    IN OUT PVOID volatile *Target,
    IN PVOID Value
    );

LONG64
InterlockedAnd64 (
    IN OUT LONG64 volatile *Destination,
    IN LONG64 Value
    );

LONG64
InterlockedOr64 (
    IN OUT LONG64 volatile *Destination,
    IN LONG64 Value
    );

LONG64
InterlockedXor64 (
    IN OUT LONG64 volatile *Destination,
    IN LONG64 Value
    );

LONG64
InterlockedIncrement64(
    IN OUT LONG64 volatile *Addend
    );

LONG64
InterlockedDecrement64(
    IN OUT LONG64 volatile *Addend
    );

LONG64
InterlockedExchange64(
    IN OUT LONG64 volatile *Target,
    IN LONG64 Value
    );

LONG64
InterlockedExchangeAdd64(
    IN OUT LONG64 volatile *Addend,
    IN LONG64 Value
    );

LONG64
InterlockedCompareExchange64 (
    IN OUT LONG64 volatile *Destination,
    IN LONG64 ExChange,
    IN LONG64 Comperand
    );


#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)
#pragma intrinsic(_InterlockedExchange)
#pragma intrinsic(_InterlockedExchangeAdd)
#pragma intrinsic(_InterlockedCompareExchange)
#pragma intrinsic(_InterlockedExchangePointer)
#pragma intrinsic(_InterlockedCompareExchangePointer)

#else           

WINBASEAPI
LONG
WINAPI
InterlockedIncrement(
    IN OUT LONG volatile *lpAddend
    );

WINBASEAPI
LONG
WINAPI
InterlockedDecrement(
    IN OUT LONG volatile *lpAddend
    );

WINBASEAPI
LONG
WINAPI
InterlockedExchange(
    IN OUT LONG volatile *Target,
    IN LONG Value
    );

#define InterlockedExchangePointer(Target, Value) \
    (PVOID)InterlockedExchange((PLONG)(Target), (LONG)(Value))

WINBASEAPI
LONG
WINAPI
InterlockedExchangeAdd(
    IN OUT LONG volatile *Addend,
    IN LONG Value
    );

WINBASEAPI
LONG
WINAPI
InterlockedCompareExchange (
    IN OUT LONG volatile *Destination,
    IN LONG Exchange,
    IN LONG Comperand
    );


WINBASEAPI
LONGLONG
WINAPI
InterlockedCompareExchange64 (
    IN OUT LONGLONG volatile *Destination,
    IN LONGLONG Exchange,
    IN LONGLONG Comperand
    );

#if !defined(MIDL_PASS)

LONGLONG
FORCEINLINE
InterlockedAnd64 (
    IN OUT LONGLONG volatile *Destination,
    IN LONGLONG Value
    )
{
    LONGLONG Old;

    do {
        Old = *Destination;
    } while (InterlockedCompareExchange64(Destination,
                                          Old & Value,
                                          Old) != Old);

    return Old;
}

LONGLONG
FORCEINLINE
InterlockedOr64 (
    IN OUT LONGLONG volatile *Destination,
    IN LONGLONG Value
    )
{
    LONGLONG Old;

    do {
        Old = *Destination;
    } while (InterlockedCompareExchange64(Destination,
                                          Old | Value,
                                          Old) != Old);

    return Old;
}

LONGLONG
FORCEINLINE
InterlockedXor64 (
    IN OUT LONGLONG volatile *Destination,
    IN LONGLONG Value
    )
{
    LONGLONG Old;

    do {
        Old = *Destination;
    } while (InterlockedCompareExchange64(Destination,
                                          Old ^ Value,
                                          Old) != Old);

    return Old;
}

LONGLONG
FORCEINLINE
InterlockedIncrement64(
    IN OUT LONGLONG volatile *Addend
    )
{
    LONGLONG Old;

    do {
        Old = *Addend;
    } while (InterlockedCompareExchange64(Addend,
                                          Old + 1,
                                          Old) != Old);

    return Old + 1;
}

LONGLONG
FORCEINLINE
InterlockedDecrement64(
    IN OUT LONGLONG volatile *Addend
    )
{
    LONGLONG Old;

    do {
        Old = *Addend;
    } while (InterlockedCompareExchange64(Addend,
                                          Old - 1,
                                          Old) != Old);

    return Old - 1;
}

LONGLONG
FORCEINLINE
InterlockedExchange64(
    IN OUT LONGLONG volatile *Target,
    IN LONGLONG Value
    )
{
    LONGLONG Old;

    do {
        Old = *Target;
    } while (InterlockedCompareExchange64(Target,
                                          Value,
                                          Old) != Old);

    return Old;
}

LONGLONG
FORCEINLINE
InterlockedExchangeAdd64(
    IN OUT LONGLONG volatile *Addend,
    IN LONGLONG Value
    )
{
    LONGLONG Old;

    do {
        Old = *Addend;
    } while (InterlockedCompareExchange64(Addend,
                                          Old + Value,
                                          Old) != Old);

    return Old;
}

#endif

//

//

#ifdef __cplusplus

FORCEINLINE
PVOID
__cdecl
__InlineInterlockedCompareExchangePointer (
    IN OUT PVOID volatile *Destination,
    IN PVOID ExChange,
    IN PVOID Comperand
    )
{
    return((PVOID)(LONG_PTR)InterlockedCompareExchange((LONG volatile *)Destination, (LONG)(LONG_PTR)ExChange, (LONG)(LONG_PTR)Comperand));
}

#define InterlockedCompareExchangePointer __InlineInterlockedCompareExchangePointer

#else

#define InterlockedCompareExchangePointer(Destination, ExChange, Comperand) \
    (PVOID)(LONG_PTR)InterlockedCompareExchange((LONG volatile *)(Destination), (LONG)(LONG_PTR)(ExChange), (LONG)(LONG_PTR)(Comperand))

#endif 

#endif 

#if defined(_SLIST_HEADER_) && !defined(_NTOSP_)

WINBASEAPI
VOID
WINAPI
InitializeSListHead (
    IN PSLIST_HEADER ListHead
    );

WINBASEAPI
PSLIST_ENTRY
WINAPI
InterlockedPopEntrySList (
    IN PSLIST_HEADER ListHead
    );

WINBASEAPI
PSLIST_ENTRY
WINAPI
InterlockedPushEntrySList (
    IN PSLIST_HEADER ListHead,
    IN PSLIST_ENTRY ListEntry
    );

WINBASEAPI
PSLIST_ENTRY
WINAPI
InterlockedFlushSList (
    IN PSLIST_HEADER ListHead
    );

WINBASEAPI
USHORT
WINAPI
QueryDepthSList (
    IN PSLIST_HEADER ListHead
    );

#endif 

#endif 

#endif 

WINBASEAPI
BOOL
WINAPI
FreeResource(
        IN HGLOBAL hResData
        );

WINBASEAPI
LPVOID
WINAPI
LockResource(
        IN HGLOBAL hResData
        );

#define UnlockResource(hResData) ((hResData), 0)
#define MAXINTATOM 0xC000
#define MAKEINTATOM(i)  (LPTSTR)((ULONG_PTR)((WORD)(i)))
#define INVALID_ATOM ((ATOM)0)

#ifndef _MAC
int
WINAPI
#else
int
CALLBACK
#endif
WinMain(
    IN HINSTANCE hInstance,
    IN HINSTANCE hPrevInstance,
    IN LPSTR lpCmdLine,
    IN int nShowCmd
    );

WINBASEAPI
BOOL
WINAPI
FreeLibrary(
    IN OUT HMODULE hLibModule
    );


WINBASEAPI
DECLSPEC_NORETURN
VOID
WINAPI
FreeLibraryAndExitThread(
    IN HMODULE hLibModule,
    IN DWORD dwExitCode
    );

WINBASEAPI
BOOL
WINAPI
DisableThreadLibraryCalls(
    IN HMODULE hLibModule
    );

WINBASEAPI
FARPROC
WINAPI
GetProcAddress(
    IN HMODULE hModule,
    IN LPCSTR lpProcName
    );

WINBASEAPI
DWORD
WINAPI
GetVersion( VOID );

WINBASEAPI
HGLOBAL
WINAPI
GlobalAlloc(
    IN UINT uFlags,
    IN SIZE_T dwBytes
    );

WINBASEAPI
HGLOBAL
WINAPI
GlobalReAlloc(
    IN HGLOBAL hMem,
    IN SIZE_T dwBytes,
    IN UINT uFlags
    );

WINBASEAPI
SIZE_T
WINAPI
GlobalSize(
    IN HGLOBAL hMem
    );

WINBASEAPI
UINT
WINAPI
GlobalFlags(
    IN HGLOBAL hMem
    );


WINBASEAPI
LPVOID
WINAPI
GlobalLock(
    IN HGLOBAL hMem
    );


WINBASEAPI
HGLOBAL
WINAPI
GlobalHandle(
    IN LPCVOID pMem
    );


WINBASEAPI
BOOL
WINAPI
GlobalUnlock(
    IN HGLOBAL hMem
    );


WINBASEAPI
HGLOBAL
WINAPI
GlobalFree(
    IN HGLOBAL hMem
    );

WINBASEAPI
SIZE_T
WINAPI
GlobalCompact(
    IN DWORD dwMinFree
    );

WINBASEAPI
VOID
WINAPI
GlobalFix(
    IN HGLOBAL hMem
    );

WINBASEAPI
VOID
WINAPI
GlobalUnfix(
    IN HGLOBAL hMem
    );

WINBASEAPI
LPVOID
WINAPI
GlobalWire(
    IN HGLOBAL hMem
    );

WINBASEAPI
BOOL
WINAPI
GlobalUnWire(
    IN HGLOBAL hMem
    );

WINBASEAPI
VOID
WINAPI
GlobalMemoryStatus(
    IN OUT LPMEMORYSTATUS lpBuffer
    );

typedef struct _MEMORYSTATUSEX {
    DWORD dwLength;
    DWORD dwMemoryLoad;
    DWORDLONG ullTotalPhys;
    DWORDLONG ullAvailPhys;
    DWORDLONG ullTotalPageFile;
    DWORDLONG ullAvailPageFile;
    DWORDLONG ullTotalVirtual;
    DWORDLONG ullAvailVirtual;
    DWORDLONG ullAvailExtendedVirtual;
} MEMORYSTATUSEX, *LPMEMORYSTATUSEX;

WINBASEAPI
BOOL
WINAPI
GlobalMemoryStatusEx(
    IN OUT LPMEMORYSTATUSEX lpBuffer
    );

WINBASEAPI
HLOCAL
WINAPI
LocalAlloc(
    IN UINT uFlags,
    IN SIZE_T uBytes
    );

WINBASEAPI
HLOCAL
WINAPI
LocalReAlloc(
    IN HLOCAL hMem,
    IN SIZE_T uBytes,
    IN UINT uFlags
    );

WINBASEAPI
LPVOID
WINAPI
LocalLock(
    IN HLOCAL hMem
    );

WINBASEAPI
HLOCAL
WINAPI
LocalHandle(
    IN LPCVOID pMem
    );

WINBASEAPI
BOOL
WINAPI
LocalUnlock(
    IN HLOCAL hMem
    );

WINBASEAPI
SIZE_T
WINAPI
LocalSize(
    IN HLOCAL hMem
    );

WINBASEAPI
UINT
WINAPI
LocalFlags(
    IN HLOCAL hMem
    );

WINBASEAPI
HLOCAL
WINAPI
LocalFree(
    IN HLOCAL hMem
    );

WINBASEAPI
SIZE_T
WINAPI
LocalShrink(
    IN HLOCAL hMem,
    IN UINT cbNewSize
    );

WINBASEAPI
SIZE_T
WINAPI
LocalCompact(
    IN UINT uMinFree
    );

WINBASEAPI
BOOL
WINAPI
FlushInstructionCache(
    IN HANDLE hProcess,
    IN LPCVOID lpBaseAddress,
    IN SIZE_T dwSize
    );

WINBASEAPI
LPVOID
WINAPI
VirtualAlloc(
    IN LPVOID lpAddress,
    IN SIZE_T dwSize,
    IN DWORD flAllocationType,
    IN DWORD flProtect
    );

WINBASEAPI
BOOL
WINAPI
VirtualFree(
    IN LPVOID lpAddress,
    IN SIZE_T dwSize,
    IN DWORD dwFreeType
    );

WINBASEAPI
BOOL
WINAPI
VirtualProtect(
    IN  LPVOID lpAddress,
    IN  SIZE_T dwSize,
    IN  DWORD flNewProtect,
    OUT PDWORD lpflOldProtect
    );

WINBASEAPI
SIZE_T
WINAPI
VirtualQuery(
    IN LPCVOID lpAddress,
    OUT PMEMORY_BASIC_INFORMATION lpBuffer,
    IN SIZE_T dwLength
    );

WINBASEAPI
LPVOID
WINAPI
VirtualAllocEx(
    IN HANDLE hProcess,
    IN LPVOID lpAddress,
    IN SIZE_T dwSize,
    IN DWORD flAllocationType,
    IN DWORD flProtect
    );

WINBASEAPI
UINT
WINAPI
GetWriteWatch(
    IN DWORD  dwFlags,
    IN PVOID  lpBaseAddress,
    IN SIZE_T dwRegionSize,
    IN OUT PVOID *lpAddresses,
    IN OUT PULONG_PTR lpdwCount,
    OUT PULONG lpdwGranularity
    );

WINBASEAPI
UINT
WINAPI
ResetWriteWatch(
    IN LPVOID lpBaseAddress,
    IN SIZE_T dwRegionSize
    );

WINBASEAPI
SIZE_T
WINAPI
GetLargePageMinimum(
    VOID
    );

WINBASEAPI
BOOL
WINAPI
VirtualFreeEx(
    IN HANDLE hProcess,
    IN LPVOID lpAddress,
    IN SIZE_T dwSize,
    IN DWORD dwFreeType
    );

WINBASEAPI
BOOL
WINAPI
VirtualProtectEx(
    IN  HANDLE hProcess,
    IN  LPVOID lpAddress,
    IN  SIZE_T dwSize,
    IN  DWORD flNewProtect,
    OUT PDWORD lpflOldProtect
    );

WINBASEAPI
SIZE_T
WINAPI
VirtualQueryEx(
    IN HANDLE hProcess,
    IN LPCVOID lpAddress,
    OUT PMEMORY_BASIC_INFORMATION lpBuffer,
    IN SIZE_T dwLength
    );

WINBASEAPI
HANDLE
WINAPI
HeapCreate(
    IN DWORD flOptions,
    IN SIZE_T dwInitialSize,
    IN SIZE_T dwMaximumSize
    );

WINBASEAPI
BOOL
WINAPI
HeapDestroy(
    IN OUT HANDLE hHeap
    );


WINBASEAPI
LPVOID
WINAPI
HeapAlloc(
    IN HANDLE hHeap,
    IN DWORD dwFlags,
    IN SIZE_T dwBytes
    );

WINBASEAPI
LPVOID
WINAPI
HeapReAlloc(
    IN HANDLE hHeap,
    IN DWORD dwFlags,
    IN LPVOID lpMem,
    IN SIZE_T dwBytes
    );

WINBASEAPI
BOOL
WINAPI
HeapFree(
    IN HANDLE hHeap,
    IN DWORD dwFlags,
    IN LPVOID lpMem
    );

WINBASEAPI
SIZE_T
WINAPI
HeapSize(
    IN HANDLE hHeap,
    IN DWORD dwFlags,
    IN LPCVOID lpMem
    );

WINBASEAPI
BOOL
WINAPI
HeapValidate(
    IN HANDLE hHeap,
    IN DWORD dwFlags,
    IN LPCVOID lpMem
    );

WINBASEAPI
SIZE_T
WINAPI
HeapCompact(
    IN HANDLE hHeap,
    IN DWORD dwFlags
    );

WINBASEAPI
HANDLE
WINAPI
GetProcessHeap( VOID );

WINBASEAPI
DWORD
WINAPI
GetProcessHeaps(
    IN DWORD NumberOfHeaps,
    OUT PHANDLE ProcessHeaps
    );

typedef struct _PROCESS_HEAP_ENTRY {
    PVOID lpData;
    DWORD cbData;
    BYTE cbOverhead;
    BYTE iRegionIndex;
    WORD wFlags;
    union {
        struct {
            HANDLE hMem;
            DWORD dwReserved[ 3 ];
        } Block;
        struct {
            DWORD dwCommittedSize;
            DWORD dwUnCommittedSize;
            LPVOID lpFirstBlock;
            LPVOID lpLastBlock;
        } Region;
    };
} PROCESS_HEAP_ENTRY, *LPPROCESS_HEAP_ENTRY, *PPROCESS_HEAP_ENTRY;

#define PROCESS_HEAP_REGION             0x0001
#define PROCESS_HEAP_UNCOMMITTED_RANGE  0x0002
#define PROCESS_HEAP_ENTRY_BUSY         0x0004
#define PROCESS_HEAP_ENTRY_MOVEABLE     0x0010
#define PROCESS_HEAP_ENTRY_DDESHARE     0x0020

WINBASEAPI
BOOL
WINAPI
HeapLock(
    IN HANDLE hHeap
    );

WINBASEAPI
BOOL
WINAPI
HeapUnlock(
    IN HANDLE hHeap
    );


WINBASEAPI
BOOL
WINAPI
HeapWalk(
    IN HANDLE hHeap,
    IN OUT LPPROCESS_HEAP_ENTRY lpEntry
    );


WINBASEAPI
BOOL
WINAPI
HeapSetInformation (
    IN HANDLE HeapHandle, 
    IN HEAP_INFORMATION_CLASS HeapInformationClass,
    IN PVOID HeapInformation OPTIONAL,
    IN SIZE_T HeapInformationLength OPTIONAL
    );

WINBASEAPI
BOOL
WINAPI
HeapQueryInformation (
    IN HANDLE HeapHandle, 
    IN HEAP_INFORMATION_CLASS HeapInformationClass,
    OUT PVOID HeapInformation OPTIONAL,
    IN SIZE_T HeapInformationLength OPTIONAL,
    OUT PSIZE_T ReturnLength OPTIONAL
    );



#define SCS_32BIT_BINARY    0
#define SCS_DOS_BINARY      1
#define SCS_WOW_BINARY      2
#define SCS_PIF_BINARY      3
#define SCS_POSIX_BINARY    4
#define SCS_OS216_BINARY    5
#define SCS_64BIT_BINARY    6

#if defined(_WIN64)
# define SCS_THIS_PLATFORM_BINARY SCS_64BIT_BINARY
#else
# define SCS_THIS_PLATFORM_BINARY SCS_32BIT_BINARY
#endif

WINBASEAPI
BOOL
WINAPI
GetBinaryTypeA(
    IN LPCSTR lpApplicationName,
    OUT LPDWORD lpBinaryType
    );
WINBASEAPI
BOOL
WINAPI
GetBinaryTypeW(
    IN LPCWSTR lpApplicationName,
    OUT LPDWORD lpBinaryType
    );
#ifdef UNICODE
#define GetBinaryType  GetBinaryTypeW
#else
#define GetBinaryType  GetBinaryTypeA
#endif 

WINBASEAPI
DWORD
WINAPI
GetShortPathNameA(
    IN LPCSTR lpszLongPath,
    OUT LPSTR  lpszShortPath,
    IN DWORD    cchBuffer
    );
WINBASEAPI
DWORD
WINAPI
GetShortPathNameW(
    IN LPCWSTR lpszLongPath,
    OUT LPWSTR  lpszShortPath,
    IN DWORD    cchBuffer
    );
#ifdef UNICODE
#define GetShortPathName  GetShortPathNameW
#else
#define GetShortPathName  GetShortPathNameA
#endif 

WINBASEAPI
DWORD
WINAPI
GetLongPathNameA(
    IN LPCSTR lpszShortPath,
    OUT LPSTR  lpszLongPath,
    IN DWORD    cchBuffer
    );
WINBASEAPI
DWORD
WINAPI
GetLongPathNameW(
    IN LPCWSTR lpszShortPath,
    OUT LPWSTR  lpszLongPath,
    IN DWORD    cchBuffer
    );
#ifdef UNICODE
#define GetLongPathName  GetLongPathNameW
#else
#define GetLongPathName  GetLongPathNameA
#endif 

WINBASEAPI
BOOL
WINAPI
GetProcessAffinityMask(
    IN HANDLE hProcess,
    OUT PDWORD_PTR lpProcessAffinityMask,
    OUT PDWORD_PTR lpSystemAffinityMask
    );

WINBASEAPI
BOOL
WINAPI
SetProcessAffinityMask(
    IN HANDLE hProcess,
    IN DWORD_PTR dwProcessAffinityMask
    );

#if _WIN32_WINNT >= 0x0501

WINBASEAPI
BOOL
WINAPI
GetProcessHandleCount(
    IN HANDLE hProcess,
    OUT PDWORD pdwHandleCount
    );

#endif 

WINBASEAPI
BOOL
WINAPI
GetProcessTimes(
    IN HANDLE hProcess,
    OUT LPFILETIME lpCreationTime,
    OUT LPFILETIME lpExitTime,
    OUT LPFILETIME lpKernelTime,
    OUT LPFILETIME lpUserTime
    );

WINBASEAPI
BOOL
WINAPI
GetProcessIoCounters(
    IN HANDLE hProcess,
    OUT PIO_COUNTERS lpIoCounters
    );

WINBASEAPI
BOOL
WINAPI
GetProcessWorkingSetSize(
    IN HANDLE hProcess,
    OUT PSIZE_T lpMinimumWorkingSetSize,
    OUT PSIZE_T lpMaximumWorkingSetSize
    );

WINBASEAPI
BOOL
WINAPI
GetProcessWorkingSetSizeEx(
    IN HANDLE hProcess,
    OUT PSIZE_T lpMinimumWorkingSetSize,
    OUT PSIZE_T lpMaximumWorkingSetSize,
    OUT PDWORD Flags
    );

WINBASEAPI
BOOL
WINAPI
SetProcessWorkingSetSize(
    IN HANDLE hProcess,
    IN SIZE_T dwMinimumWorkingSetSize,
    IN SIZE_T dwMaximumWorkingSetSize
    );

WINBASEAPI
BOOL
WINAPI
SetProcessWorkingSetSizeEx(
    IN HANDLE hProcess,
    IN SIZE_T dwMinimumWorkingSetSize,
    IN SIZE_T dwMaximumWorkingSetSize,
    IN DWORD Flags
    );


WINBASEAPI
HANDLE
WINAPI
OpenProcess(
    IN DWORD dwDesiredAccess,
    IN BOOL bInheritHandle,
    IN DWORD dwProcessId
    );

WINBASEAPI
HANDLE
WINAPI
GetCurrentProcess(
    VOID
    );

WINBASEAPI
DWORD
WINAPI
GetCurrentProcessId(
    VOID
    );

WINBASEAPI
DECLSPEC_NORETURN
VOID
WINAPI
ExitProcess(
    IN UINT uExitCode
    );

WINBASEAPI
BOOL
WINAPI
TerminateProcess(
    IN HANDLE hProcess,
    IN UINT uExitCode
    );

WINBASEAPI
BOOL
WINAPI
GetExitCodeProcess(
    IN HANDLE hProcess,
    OUT LPDWORD lpExitCode
    );


WINBASEAPI
VOID
WINAPI
FatalExit(
    IN int ExitCode
    );

WINBASEAPI
LPSTR
WINAPI
GetEnvironmentStrings(
    VOID
    );

WINBASEAPI
LPWSTR
WINAPI
GetEnvironmentStringsW(
    VOID
    );

#ifdef UNICODE
#define GetEnvironmentStrings  GetEnvironmentStringsW
#else
#define GetEnvironmentStringsA  GetEnvironmentStrings
#endif 

WINBASEAPI
BOOL
WINAPI
SetEnvironmentStringsA(
    IN LPSTR NewEnvironment
    );
WINBASEAPI
BOOL
WINAPI
SetEnvironmentStringsW(
    IN LPWSTR NewEnvironment
    );
#ifdef UNICODE
#define SetEnvironmentStrings  SetEnvironmentStringsW
#else
#define SetEnvironmentStrings  SetEnvironmentStringsA
#endif 

WINBASEAPI
BOOL
WINAPI
FreeEnvironmentStringsA(
    IN LPSTR
    );
WINBASEAPI
BOOL
WINAPI
FreeEnvironmentStringsW(
    IN LPWSTR
    );
#ifdef UNICODE
#define FreeEnvironmentStrings  FreeEnvironmentStringsW
#else
#define FreeEnvironmentStrings  FreeEnvironmentStringsA
#endif 

WINBASEAPI
VOID
WINAPI
RaiseException(
    IN DWORD dwExceptionCode,
    IN DWORD dwExceptionFlags,
    IN DWORD nNumberOfArguments,
    IN CONST ULONG_PTR *lpArguments
    );

WINBASEAPI
LONG
WINAPI
UnhandledExceptionFilter(
    IN struct _EXCEPTION_POINTERS *ExceptionInfo
    );

typedef LONG (WINAPI *PTOP_LEVEL_EXCEPTION_FILTER)(
    struct _EXCEPTION_POINTERS *ExceptionInfo
    );
typedef PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

WINBASEAPI
LPTOP_LEVEL_EXCEPTION_FILTER
WINAPI
SetUnhandledExceptionFilter(
    IN LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter
    );

#if(_WIN32_WINNT >= 0x0400)

//

//

#define FIBER_FLAG_FLOAT_SWITCH 0x1     

WINBASEAPI
LPVOID
WINAPI
CreateFiber(
    IN SIZE_T dwStackSize,
    IN LPFIBER_START_ROUTINE lpStartAddress,
    IN LPVOID lpParameter
    );

WINBASEAPI
LPVOID
WINAPI
CreateFiberEx(
    SIZE_T dwStackCommitSize,
    SIZE_T dwStackReserveSize,
    DWORD dwFlags,
    LPFIBER_START_ROUTINE lpStartAddress,
    LPVOID lpParameter
    );

WINBASEAPI
VOID
WINAPI
DeleteFiber(
    IN LPVOID lpFiber
    );

WINBASEAPI
LPVOID
WINAPI
ConvertThreadToFiber(
    IN LPVOID lpParameter
    );

WINBASEAPI
LPVOID
WINAPI
ConvertThreadToFiberEx(
    IN LPVOID lpParameter,
    IN DWORD dwFlags
    );

WINBASEAPI
BOOL
WINAPI
ConvertFiberToThread(
    VOID
    );

WINBASEAPI
VOID
WINAPI
SwitchToFiber(
    IN LPVOID lpFiber
    );

WINBASEAPI
BOOL
WINAPI
SwitchToThread(
    VOID
    );

#endif 

WINBASEAPI
HANDLE
WINAPI
CreateThread(
    IN LPSECURITY_ATTRIBUTES lpThreadAttributes,
    IN SIZE_T dwStackSize,
    IN LPTHREAD_START_ROUTINE lpStartAddress,
    IN LPVOID lpParameter,
    IN DWORD dwCreationFlags,
    OUT LPDWORD lpThreadId
    );

WINBASEAPI
HANDLE
WINAPI
CreateRemoteThread(
    IN HANDLE hProcess,
    IN LPSECURITY_ATTRIBUTES lpThreadAttributes,
    IN SIZE_T dwStackSize,
    IN LPTHREAD_START_ROUTINE lpStartAddress,
    IN LPVOID lpParameter,
    IN DWORD dwCreationFlags,
    OUT LPDWORD lpThreadId
    );

WINBASEAPI
HANDLE
WINAPI
GetCurrentThread(
    VOID
    );

WINBASEAPI
DWORD
WINAPI
GetCurrentThreadId(
    VOID
    );

WINBASEAPI
DWORD
WINAPI
GetProcessIdOfThread(
    HANDLE Thread
    );

WINBASEAPI
DWORD
WINAPI
GetThreadId(
    HANDLE Thread
    );

WINBASEAPI
DWORD
WINAPI
GetProcessId(
    HANDLE Process
    );

WINBASEAPI
DWORD
WINAPI
GetCurrentProcessorNumber(
    VOID
    );

WINBASEAPI
DWORD_PTR
WINAPI
SetThreadAffinityMask(
    IN HANDLE hThread,
    IN DWORD_PTR dwThreadAffinityMask
    );

#if(_WIN32_WINNT >= 0x0400)
WINBASEAPI
DWORD
WINAPI
SetThreadIdealProcessor(
    IN HANDLE hThread,
    IN DWORD dwIdealProcessor
    );
#endif 

WINBASEAPI
BOOL
WINAPI
SetProcessPriorityBoost(
    IN HANDLE hProcess,
    IN BOOL bDisablePriorityBoost
    );

WINBASEAPI
BOOL
WINAPI
GetProcessPriorityBoost(
    IN HANDLE hProcess,
    OUT PBOOL pDisablePriorityBoost
    );

WINBASEAPI
BOOL
WINAPI
RequestWakeupLatency(
    IN LATENCY_TIME latency
    );

WINBASEAPI
BOOL
WINAPI
IsSystemResumeAutomatic(
    VOID
    );

WINBASEAPI
HANDLE
WINAPI
OpenThread(
    DWORD dwDesiredAccess,
    BOOL bInheritHandle,
    DWORD dwThreadId
    );

WINBASEAPI
BOOL
WINAPI
SetThreadPriority(
    IN HANDLE hThread,
    IN int nPriority
    );

WINBASEAPI
BOOL
WINAPI
SetThreadPriorityBoost(
    IN HANDLE hThread,
    IN BOOL bDisablePriorityBoost
    );

WINBASEAPI
BOOL
WINAPI
GetThreadPriorityBoost(
    IN HANDLE hThread,
    OUT PBOOL pDisablePriorityBoost
    );

WINBASEAPI
int
WINAPI
GetThreadPriority(
    IN HANDLE hThread
    );

WINBASEAPI
BOOL
WINAPI
GetThreadTimes(
    IN HANDLE hThread,
    OUT LPFILETIME lpCreationTime,
    OUT LPFILETIME lpExitTime,
    OUT LPFILETIME lpKernelTime,
    OUT LPFILETIME lpUserTime
    );

#if _WIN32_WINNT >= 0x0501

WINBASEAPI
BOOL
WINAPI
GetThreadIOPendingFlag(
    IN HANDLE hThread,
    OUT PBOOL lpIOIsPending
    );

#endif 

WINBASEAPI
DECLSPEC_NORETURN
VOID
WINAPI
ExitThread(
    IN DWORD dwExitCode
    );

WINBASEAPI
BOOL
WINAPI
TerminateThread(
    IN OUT HANDLE hThread,
    IN DWORD dwExitCode
    );

WINBASEAPI
BOOL
WINAPI
GetExitCodeThread(
    IN HANDLE hThread,
    OUT LPDWORD lpExitCode
    );

WINBASEAPI
BOOL
WINAPI
GetThreadSelectorEntry(
    IN HANDLE hThread,
    IN DWORD dwSelector,
    OUT LPLDT_ENTRY lpSelectorEntry
    );

WINBASEAPI
EXECUTION_STATE
WINAPI
SetThreadExecutionState(
    IN EXECUTION_STATE esFlags
    );

WINBASEAPI
DWORD
WINAPI
GetLastError(
    VOID
    );

WINBASEAPI
VOID
WINAPI
SetLastError(
    IN DWORD dwErrCode
    );

#if !defined(RC_INVOKED) 

#if defined(WINBASE_DECLARE_RESTORE_LAST_ERROR)

WINBASEAPI
VOID
WINAPI
RestoreLastError(
    IN DWORD dwErrCode
    );

typedef VOID (WINAPI* PRESTORE_LAST_ERROR)(DWORD);
#define RESTORE_LAST_ERROR_NAME_A      "RestoreLastError"
#define RESTORE_LAST_ERROR_NAME_W     L"RestoreLastError"
#define RESTORE_LAST_ERROR_NAME   TEXT("RestoreLastError")

#endif
#endif

#define HasOverlappedIoCompleted(lpOverlapped) ((lpOverlapped)->Internal != STATUS_PENDING)

WINBASEAPI
BOOL
WINAPI
GetOverlappedResult(
    IN HANDLE hFile,
    IN LPOVERLAPPED lpOverlapped,
    OUT LPDWORD lpNumberOfBytesTransferred,
    IN BOOL bWait
    );

WINBASEAPI
HANDLE
WINAPI
CreateIoCompletionPort(
    IN HANDLE FileHandle,
    IN HANDLE ExistingCompletionPort,
    IN ULONG_PTR CompletionKey,
    IN DWORD NumberOfConcurrentThreads
    );

WINBASEAPI
BOOL
WINAPI
GetQueuedCompletionStatus(
    IN  HANDLE CompletionPort,
    OUT LPDWORD lpNumberOfBytesTransferred,
    OUT PULONG_PTR lpCompletionKey,
    OUT LPOVERLAPPED *lpOverlapped,
    IN  DWORD dwMilliseconds
    );

WINBASEAPI
BOOL
WINAPI
PostQueuedCompletionStatus(
    IN HANDLE CompletionPort,
    IN DWORD dwNumberOfBytesTransferred,
    IN ULONG_PTR dwCompletionKey,
    IN LPOVERLAPPED lpOverlapped
    );

#define SEM_FAILCRITICALERRORS      0x0001
#define SEM_NOGPFAULTERRORBOX       0x0002
#define SEM_NOALIGNMENTFAULTEXCEPT  0x0004
#define SEM_NOOPENFILEERRORBOX      0x8000

WINBASEAPI
UINT
WINAPI
SetErrorMode(
    IN UINT uMode
    );

WINBASEAPI
BOOL
WINAPI
ReadProcessMemory(
    IN HANDLE hProcess,
    IN LPCVOID lpBaseAddress,
    OUT LPVOID lpBuffer,
    IN SIZE_T nSize,
    OUT SIZE_T * lpNumberOfBytesRead
    );

WINBASEAPI
BOOL
WINAPI
WriteProcessMemory(
    IN HANDLE hProcess,
    IN LPVOID lpBaseAddress,
    IN LPCVOID lpBuffer,
    IN SIZE_T nSize,
    OUT SIZE_T * lpNumberOfBytesWritten
    );

#if !defined(MIDL_PASS)
WINBASEAPI
BOOL
WINAPI
GetThreadContext(
    IN HANDLE hThread,
    IN OUT LPCONTEXT lpContext
    );

WINBASEAPI
BOOL
WINAPI
SetThreadContext(
    IN HANDLE hThread,
    IN CONST CONTEXT *lpContext
    );
#endif

WINBASEAPI
DWORD
WINAPI
SuspendThread(
    IN HANDLE hThread
    );

WINBASEAPI
DWORD
WINAPI
ResumeThread(
    IN HANDLE hThread
    );


#if(_WIN32_WINNT >= 0x0400) || (_WIN32_WINDOWS > 0x0400)

typedef
VOID
(APIENTRY *PAPCFUNC)(
    ULONG_PTR dwParam
    );

WINBASEAPI
DWORD
WINAPI
QueueUserAPC(
    IN PAPCFUNC pfnAPC,
    IN HANDLE hThread,
    IN ULONG_PTR dwData
    );

#endif 

#if (_WIN32_WINNT >= 0x0400) || (_WIN32_WINDOWS > 0x0400)
WINBASEAPI
BOOL
WINAPI
IsDebuggerPresent(
    VOID
    );
#endif

#if _WIN32_WINNT >= 0x0501

WINBASEAPI
BOOL
WINAPI
CheckRemoteDebuggerPresent(
    IN HANDLE hProcess,
    OUT PBOOL pbDebuggerPresent
    );

#endif 

WINBASEAPI
VOID
WINAPI
DebugBreak(
    VOID
    );

WINBASEAPI
BOOL
WINAPI
WaitForDebugEvent(
    IN LPDEBUG_EVENT lpDebugEvent,
    IN DWORD dwMilliseconds
    );

WINBASEAPI
BOOL
WINAPI
ContinueDebugEvent(
    IN DWORD dwProcessId,
    IN DWORD dwThreadId,
    IN DWORD dwContinueStatus
    );

WINBASEAPI
BOOL
WINAPI
DebugActiveProcess(
    IN DWORD dwProcessId
    );

WINBASEAPI
BOOL
WINAPI
DebugActiveProcessStop(
    IN DWORD dwProcessId
    );

WINBASEAPI
BOOL
WINAPI
DebugSetProcessKillOnExit(
    IN BOOL KillOnExit
    );

WINBASEAPI
BOOL
WINAPI
DebugBreakProcess (
    IN HANDLE Process
    );

WINBASEAPI
VOID
WINAPI
InitializeCriticalSection(
    OUT LPCRITICAL_SECTION lpCriticalSection
    );

WINBASEAPI
VOID
WINAPI
EnterCriticalSection(
    IN OUT LPCRITICAL_SECTION lpCriticalSection
    );

WINBASEAPI
VOID
WINAPI
LeaveCriticalSection(
    IN OUT LPCRITICAL_SECTION lpCriticalSection
    );

#if (_WIN32_WINNT >= 0x0403)
WINBASEAPI
BOOL
WINAPI
InitializeCriticalSectionAndSpinCount(
    IN OUT LPCRITICAL_SECTION lpCriticalSection,
    IN DWORD dwSpinCount
    );

WINBASEAPI
DWORD
WINAPI
SetCriticalSectionSpinCount(
    IN OUT LPCRITICAL_SECTION lpCriticalSection,
    IN DWORD dwSpinCount
    );
#endif

#if(_WIN32_WINNT >= 0x0400)
WINBASEAPI
BOOL
WINAPI
TryEnterCriticalSection(
    IN OUT LPCRITICAL_SECTION lpCriticalSection
    );
#endif 

WINBASEAPI
VOID
WINAPI
DeleteCriticalSection(
    IN OUT LPCRITICAL_SECTION lpCriticalSection
    );

WINBASEAPI
BOOL
WINAPI
SetEvent(
    IN HANDLE hEvent
    );

WINBASEAPI
BOOL
WINAPI
ResetEvent(
    IN HANDLE hEvent
    );

WINBASEAPI
BOOL
WINAPI
PulseEvent(
    IN HANDLE hEvent
    );

WINBASEAPI
BOOL
WINAPI
ReleaseSemaphore(
    IN HANDLE hSemaphore,
    IN LONG lReleaseCount,
    OUT LPLONG lpPreviousCount
    );

WINBASEAPI
BOOL
WINAPI
ReleaseMutex(
    IN HANDLE hMutex
    );

WINBASEAPI
DWORD
WINAPI
WaitForSingleObject(
    IN HANDLE hHandle,
    IN DWORD dwMilliseconds
    );

WINBASEAPI
DWORD
WINAPI
WaitForMultipleObjects(
    IN DWORD nCount,
    IN CONST HANDLE *lpHandles,
    IN BOOL bWaitAll,
    IN DWORD dwMilliseconds
    );

WINBASEAPI
VOID
WINAPI
Sleep(
    IN DWORD dwMilliseconds
    );

WINBASEAPI
HGLOBAL
WINAPI
LoadResource(
    IN HMODULE hModule,
    IN HRSRC hResInfo
    );

WINBASEAPI
DWORD
WINAPI
SizeofResource(
    IN HMODULE hModule,
    IN HRSRC hResInfo
    );


WINBASEAPI
ATOM
WINAPI
GlobalDeleteAtom(
    IN ATOM nAtom
    );

WINBASEAPI
BOOL
WINAPI
InitAtomTable(
    IN DWORD nSize
    );

WINBASEAPI
ATOM
WINAPI
DeleteAtom(
    IN ATOM nAtom
    );

WINBASEAPI
UINT
WINAPI
SetHandleCount(
    IN UINT uNumber
    );

WINBASEAPI
DWORD
WINAPI
GetLogicalDrives(
    VOID
    );

WINBASEAPI
BOOL
WINAPI
LockFile(
    IN HANDLE hFile,
    IN DWORD dwFileOffsetLow,
    IN DWORD dwFileOffsetHigh,
    IN DWORD nNumberOfBytesToLockLow,
    IN DWORD nNumberOfBytesToLockHigh
    );

WINBASEAPI
BOOL
WINAPI
UnlockFile(
    IN HANDLE hFile,
    IN DWORD dwFileOffsetLow,
    IN DWORD dwFileOffsetHigh,
    IN DWORD nNumberOfBytesToUnlockLow,
    IN DWORD nNumberOfBytesToUnlockHigh
    );

WINBASEAPI
BOOL
WINAPI
LockFileEx(
    IN HANDLE hFile,
    IN DWORD dwFlags,
    IN DWORD dwReserved,
    IN DWORD nNumberOfBytesToLockLow,
    IN DWORD nNumberOfBytesToLockHigh,
    IN LPOVERLAPPED lpOverlapped
    );

#define LOCKFILE_FAIL_IMMEDIATELY   0x00000001
#define LOCKFILE_EXCLUSIVE_LOCK     0x00000002

WINBASEAPI
BOOL
WINAPI
UnlockFileEx(
    IN HANDLE hFile,
    IN DWORD dwReserved,
    IN DWORD nNumberOfBytesToUnlockLow,
    IN DWORD nNumberOfBytesToUnlockHigh,
    IN LPOVERLAPPED lpOverlapped
    );

typedef struct _BY_HANDLE_FILE_INFORMATION {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD dwVolumeSerialNumber;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD nNumberOfLinks;
    DWORD nFileIndexHigh;
    DWORD nFileIndexLow;
} BY_HANDLE_FILE_INFORMATION, *PBY_HANDLE_FILE_INFORMATION, *LPBY_HANDLE_FILE_INFORMATION;

WINBASEAPI
BOOL
WINAPI
GetFileInformationByHandle(
    IN HANDLE hFile,
    OUT LPBY_HANDLE_FILE_INFORMATION lpFileInformation
    );

WINBASEAPI
DWORD
WINAPI
GetFileType(
    IN HANDLE hFile
    );

WINBASEAPI
DWORD
WINAPI
GetFileSize(
    IN HANDLE hFile,
    OUT LPDWORD lpFileSizeHigh
    );

WINBASEAPI
BOOL
WINAPI
GetFileSizeEx(
    HANDLE hFile,
    PLARGE_INTEGER lpFileSize
    );


WINBASEAPI
HANDLE
WINAPI
GetStdHandle(
    IN DWORD nStdHandle
    );

WINBASEAPI
BOOL
WINAPI
SetStdHandle(
    IN DWORD nStdHandle,
    IN HANDLE hHandle
    );

WINBASEAPI
BOOL
WINAPI
WriteFile(
    IN HANDLE hFile,
    IN LPCVOID lpBuffer,
    IN DWORD nNumberOfBytesToWrite,
    OUT LPDWORD lpNumberOfBytesWritten,
    IN LPOVERLAPPED lpOverlapped
    );

WINBASEAPI
BOOL
WINAPI
ReadFile(
    IN HANDLE hFile,
    OUT LPVOID lpBuffer,
    IN DWORD nNumberOfBytesToRead,
    OUT LPDWORD lpNumberOfBytesRead,
    IN LPOVERLAPPED lpOverlapped
    );

WINBASEAPI
BOOL
WINAPI
FlushFileBuffers(
    IN HANDLE hFile
    );

WINBASEAPI
BOOL
WINAPI
DeviceIoControl(
    IN HANDLE hDevice,
    IN DWORD dwIoControlCode,
    IN LPVOID lpInBuffer,
    IN DWORD nInBufferSize,
    OUT LPVOID lpOutBuffer,
    IN DWORD nOutBufferSize,
    OUT LPDWORD lpBytesReturned,
    IN LPOVERLAPPED lpOverlapped
    );

WINBASEAPI
BOOL
WINAPI
RequestDeviceWakeup(
    IN HANDLE hDevice
    );

WINBASEAPI
BOOL
WINAPI
CancelDeviceWakeupRequest(
    IN HANDLE hDevice
    );

WINBASEAPI
BOOL
WINAPI
GetDevicePowerState(
    IN HANDLE hDevice,
    OUT BOOL *pfOn
    );

WINBASEAPI
BOOL
WINAPI
SetMessageWaitingIndicator(
    IN HANDLE hMsgIndicator,
    IN ULONG ulMsgCount
    );

WINBASEAPI
BOOL
WINAPI
SetEndOfFile(
    IN HANDLE hFile
    );

WINBASEAPI
DWORD
WINAPI
SetFilePointer(
    IN HANDLE hFile,
    IN LONG lDistanceToMove,
    IN PLONG lpDistanceToMoveHigh,
    IN DWORD dwMoveMethod
    );

WINBASEAPI
BOOL
WINAPI
SetFilePointerEx(
    HANDLE hFile,
    LARGE_INTEGER liDistanceToMove,
    PLARGE_INTEGER lpNewFilePointer,
    DWORD dwMoveMethod
    );

WINBASEAPI
BOOL
WINAPI
FindClose(
    IN OUT HANDLE hFindFile
    );

WINBASEAPI
BOOL
WINAPI
GetFileTime(
    IN HANDLE hFile,
    OUT LPFILETIME lpCreationTime,
    OUT LPFILETIME lpLastAccessTime,
    OUT LPFILETIME lpLastWriteTime
    );

WINBASEAPI
BOOL
WINAPI
SetFileTime(
    IN HANDLE hFile,
    IN CONST FILETIME *lpCreationTime,
    IN CONST FILETIME *lpLastAccessTime,
    IN CONST FILETIME *lpLastWriteTime
    );

WINBASEAPI
BOOL
WINAPI
SetFileValidData(
    IN HANDLE hFile,
    IN LONGLONG ValidDataLength
    );

WINBASEAPI
BOOL
WINAPI
SetFileShortNameA(
    IN HANDLE hFile,
    IN LPCSTR lpShortName
    );
WINBASEAPI
BOOL
WINAPI
SetFileShortNameW(
    IN HANDLE hFile,
    IN LPCWSTR lpShortName
    );
#ifdef UNICODE
#define SetFileShortName  SetFileShortNameW
#else
#define SetFileShortName  SetFileShortNameA
#endif 

WINBASEAPI
BOOL
WINAPI
CloseHandle(
    IN OUT HANDLE hObject
    );

WINBASEAPI
BOOL
WINAPI
DuplicateHandle(
    IN HANDLE hSourceProcessHandle,
    IN HANDLE hSourceHandle,
    IN HANDLE hTargetProcessHandle,
    OUT LPHANDLE lpTargetHandle,
    IN DWORD dwDesiredAccess,
    IN BOOL bInheritHandle,
    IN DWORD dwOptions
    );

WINBASEAPI
BOOL
WINAPI
GetHandleInformation(
    IN HANDLE hObject,
    OUT LPDWORD lpdwFlags
    );

WINBASEAPI
BOOL
WINAPI
SetHandleInformation(
    IN HANDLE hObject,
    IN DWORD dwMask,
    IN DWORD dwFlags
    );

#define HANDLE_FLAG_INHERIT             0x00000001
#define HANDLE_FLAG_PROTECT_FROM_CLOSE  0x00000002

#define HINSTANCE_ERROR 32

WINBASEAPI
DWORD
WINAPI
LoadModule(
    IN LPCSTR lpModuleName,
    IN LPVOID lpParameterBlock
    );

WINBASEAPI
UINT
WINAPI
WinExec(
    IN LPCSTR lpCmdLine,
    IN UINT uCmdShow
    );

WINBASEAPI
BOOL
WINAPI
ClearCommBreak(
    IN HANDLE hFile
    );

WINBASEAPI
BOOL
WINAPI
ClearCommError(
    IN HANDLE hFile,
    OUT LPDWORD lpErrors,
    OUT LPCOMSTAT lpStat
    );

WINBASEAPI
BOOL
WINAPI
SetupComm(
    IN HANDLE hFile,
    IN DWORD dwInQueue,
    IN DWORD dwOutQueue
    );

WINBASEAPI
BOOL
WINAPI
EscapeCommFunction(
    IN HANDLE hFile,
    IN DWORD dwFunc
    );

WINBASEAPI
BOOL
WINAPI
GetCommConfig(
    IN HANDLE hCommDev,
    OUT LPCOMMCONFIG lpCC,
    IN OUT LPDWORD lpdwSize
    );

WINBASEAPI
BOOL
WINAPI
GetCommMask(
    IN HANDLE hFile,
    OUT LPDWORD lpEvtMask
    );

WINBASEAPI
BOOL
WINAPI
GetCommProperties(
    IN HANDLE hFile,
    OUT LPCOMMPROP lpCommProp
    );

WINBASEAPI
BOOL
WINAPI
GetCommModemStatus(
    IN HANDLE hFile,
    OUT LPDWORD lpModemStat
    );

WINBASEAPI
BOOL
WINAPI
GetCommState(
    IN HANDLE hFile,
    OUT LPDCB lpDCB
    );

WINBASEAPI
BOOL
WINAPI
GetCommTimeouts(
    IN HANDLE hFile,
    OUT LPCOMMTIMEOUTS lpCommTimeouts
    );

WINBASEAPI
BOOL
WINAPI
PurgeComm(
    IN HANDLE hFile,
    IN DWORD dwFlags
    );

WINBASEAPI
BOOL
WINAPI
SetCommBreak(
    IN HANDLE hFile
    );

WINBASEAPI
BOOL
WINAPI
SetCommConfig(
    IN HANDLE hCommDev,
    IN LPCOMMCONFIG lpCC,
    IN DWORD dwSize
    );

WINBASEAPI
BOOL
WINAPI
SetCommMask(
    IN HANDLE hFile,
    IN DWORD dwEvtMask
    );

WINBASEAPI
BOOL
WINAPI
SetCommState(
    IN HANDLE hFile,
    IN LPDCB lpDCB
    );

WINBASEAPI
BOOL
WINAPI
SetCommTimeouts(
    IN HANDLE hFile,
    IN LPCOMMTIMEOUTS lpCommTimeouts
    );

WINBASEAPI
BOOL
WINAPI
TransmitCommChar(
    IN HANDLE hFile,
    IN char cChar
    );

WINBASEAPI
BOOL
WINAPI
WaitCommEvent(
    IN HANDLE hFile,
    OUT LPDWORD lpEvtMask,
    IN LPOVERLAPPED lpOverlapped
    );


WINBASEAPI
DWORD
WINAPI
SetTapePosition(
    IN HANDLE hDevice,
    IN DWORD dwPositionMethod,
    IN DWORD dwPartition,
    IN DWORD dwOffsetLow,
    IN DWORD dwOffsetHigh,
    IN BOOL bImmediate
    );

WINBASEAPI
DWORD
WINAPI
GetTapePosition(
    IN HANDLE hDevice,
    IN DWORD dwPositionType,
    OUT LPDWORD lpdwPartition,
    OUT LPDWORD lpdwOffsetLow,
    OUT LPDWORD lpdwOffsetHigh
    );

WINBASEAPI
DWORD
WINAPI
PrepareTape(
    IN HANDLE hDevice,
    IN DWORD dwOperation,
    IN BOOL bImmediate
    );

WINBASEAPI
DWORD
WINAPI
EraseTape(
    IN HANDLE hDevice,
    IN DWORD dwEraseType,
    IN BOOL bImmediate
    );

WINBASEAPI
DWORD
WINAPI
CreateTapePartition(
    IN HANDLE hDevice,
    IN DWORD dwPartitionMethod,
    IN DWORD dwCount,
    IN DWORD dwSize
    );

WINBASEAPI
DWORD
WINAPI
WriteTapemark(
    IN HANDLE hDevice,
    IN DWORD dwTapemarkType,
    IN DWORD dwTapemarkCount,
    IN BOOL bImmediate
    );

WINBASEAPI
DWORD
WINAPI
GetTapeStatus(
    IN HANDLE hDevice
    );

WINBASEAPI
DWORD
WINAPI
GetTapeParameters(
    IN HANDLE hDevice,
    IN DWORD dwOperation,
    OUT LPDWORD lpdwSize,
    OUT LPVOID lpTapeInformation
    );

#define GET_TAPE_MEDIA_INFORMATION 0
#define GET_TAPE_DRIVE_INFORMATION 1

WINBASEAPI
DWORD
WINAPI
SetTapeParameters(
    IN HANDLE hDevice,
    IN DWORD dwOperation,
    IN LPVOID lpTapeInformation
    );

#define SET_TAPE_MEDIA_INFORMATION 0
#define SET_TAPE_DRIVE_INFORMATION 1

WINBASEAPI
BOOL
WINAPI
Beep(
    IN DWORD dwFreq,
    IN DWORD dwDuration
    );

WINBASEAPI
int
WINAPI
MulDiv(
    IN int nNumber,
    IN int nNumerator,
    IN int nDenominator
    );

WINBASEAPI
VOID
WINAPI
GetSystemTime(
    OUT LPSYSTEMTIME lpSystemTime
    );

WINBASEAPI
VOID
WINAPI
GetSystemTimeAsFileTime(
    OUT LPFILETIME lpSystemTimeAsFileTime
    );

WINBASEAPI
BOOL
WINAPI
SetSystemTime(
    IN CONST SYSTEMTIME *lpSystemTime
    );

WINBASEAPI
VOID
WINAPI
GetLocalTime(
    OUT LPSYSTEMTIME lpSystemTime
    );

WINBASEAPI
BOOL
WINAPI
SetLocalTime(
    IN CONST SYSTEMTIME *lpSystemTime
    );

WINBASEAPI
VOID
WINAPI
GetSystemInfo(
    OUT LPSYSTEM_INFO lpSystemInfo
    );

#if _WIN32_WINNT >= 0x0501

WINBASEAPI
BOOL
WINAPI
GetSystemRegistryQuota(
    OUT PDWORD pdwQuotaAllowed,
    OUT PDWORD pdwQuotaUsed
    );

BOOL
WINAPI
GetSystemTimes(
    LPFILETIME lpIdleTime,
    LPFILETIME lpKernelTime,
    LPFILETIME lpUserTime
    );

#endif 

#if _WIN32_WINNT >= 0x0501
WINBASEAPI
VOID
WINAPI
GetNativeSystemInfo(
    OUT LPSYSTEM_INFO lpSystemInfo
    );
#endif

WINBASEAPI
BOOL
WINAPI
IsProcessorFeaturePresent(
    IN DWORD ProcessorFeature
    );

typedef struct _TIME_ZONE_INFORMATION {
    LONG Bias;
    WCHAR StandardName[ 32 ];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[ 32 ];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
} TIME_ZONE_INFORMATION, *PTIME_ZONE_INFORMATION, *LPTIME_ZONE_INFORMATION;

WINBASEAPI
BOOL
WINAPI
SystemTimeToTzSpecificLocalTime(
    IN LPTIME_ZONE_INFORMATION lpTimeZoneInformation,
    IN LPSYSTEMTIME lpUniversalTime,
    OUT LPSYSTEMTIME lpLocalTime
    );

WINBASEAPI
BOOL
WINAPI
TzSpecificLocalTimeToSystemTime(
    IN LPTIME_ZONE_INFORMATION lpTimeZoneInformation,
    IN LPSYSTEMTIME lpLocalTime,
    OUT LPSYSTEMTIME lpUniversalTime
    );

WINBASEAPI
DWORD
WINAPI
GetTimeZoneInformation(
    OUT LPTIME_ZONE_INFORMATION lpTimeZoneInformation
    );

WINBASEAPI
BOOL
WINAPI
SetTimeZoneInformation(
    IN CONST TIME_ZONE_INFORMATION *lpTimeZoneInformation
    );


//

//

WINBASEAPI
BOOL
WINAPI
SystemTimeToFileTime(
    IN CONST SYSTEMTIME *lpSystemTime,
    OUT LPFILETIME lpFileTime
    );

WINBASEAPI
BOOL
WINAPI
FileTimeToLocalFileTime(
    IN CONST FILETIME *lpFileTime,
    OUT LPFILETIME lpLocalFileTime
    );

WINBASEAPI
BOOL
WINAPI
LocalFileTimeToFileTime(
    IN CONST FILETIME *lpLocalFileTime,
    OUT LPFILETIME lpFileTime
    );

WINBASEAPI
BOOL
WINAPI
FileTimeToSystemTime(
    IN CONST FILETIME *lpFileTime,
    OUT LPSYSTEMTIME lpSystemTime
    );

WINBASEAPI
LONG
WINAPI
CompareFileTime(
    IN CONST FILETIME *lpFileTime1,
    IN CONST FILETIME *lpFileTime2
    );

WINBASEAPI
BOOL
WINAPI
FileTimeToDosDateTime(
    IN CONST FILETIME *lpFileTime,
    OUT LPWORD lpFatDate,
    OUT LPWORD lpFatTime
    );

WINBASEAPI
BOOL
WINAPI
DosDateTimeToFileTime(
    IN WORD wFatDate,
    IN WORD wFatTime,
    OUT LPFILETIME lpFileTime
    );

WINBASEAPI
DWORD
WINAPI
GetTickCount(
    VOID
    );

WINBASEAPI
BOOL
WINAPI
SetSystemTimeAdjustment(
    IN DWORD dwTimeAdjustment,
    IN BOOL  bTimeAdjustmentDisabled
    );

WINBASEAPI
BOOL
WINAPI
GetSystemTimeAdjustment(
    OUT PDWORD lpTimeAdjustment,
    OUT PDWORD lpTimeIncrement,
    OUT PBOOL  lpTimeAdjustmentDisabled
    );

#if !defined(MIDL_PASS)
WINBASEAPI
DWORD
WINAPI
FormatMessageA(
    IN DWORD dwFlags,
    IN LPCVOID lpSource,
    IN DWORD dwMessageId,
    IN DWORD dwLanguageId,
    OUT LPSTR lpBuffer,
    IN DWORD nSize,
    IN va_list *Arguments
    );
WINBASEAPI
DWORD
WINAPI
FormatMessageW(
    IN DWORD dwFlags,
    IN LPCVOID lpSource,
    IN DWORD dwMessageId,
    IN DWORD dwLanguageId,
    OUT LPWSTR lpBuffer,
    IN DWORD nSize,
    IN va_list *Arguments
    );
#ifdef UNICODE
#define FormatMessage  FormatMessageW
#else
#define FormatMessage  FormatMessageA
#endif 
#endif

#define FORMAT_MESSAGE_ALLOCATE_BUFFER 0x00000100
#define FORMAT_MESSAGE_IGNORE_INSERTS  0x00000200
#define FORMAT_MESSAGE_FROM_STRING     0x00000400
#define FORMAT_MESSAGE_FROM_HMODULE    0x00000800
#define FORMAT_MESSAGE_FROM_SYSTEM     0x00001000
#define FORMAT_MESSAGE_ARGUMENT_ARRAY  0x00002000
#define FORMAT_MESSAGE_MAX_WIDTH_MASK  0x000000FF


WINBASEAPI
BOOL
WINAPI
CreatePipe(
    OUT PHANDLE hReadPipe,
    OUT PHANDLE hWritePipe,
    IN LPSECURITY_ATTRIBUTES lpPipeAttributes,
    IN DWORD nSize
    );

WINBASEAPI
BOOL
WINAPI
ConnectNamedPipe(
    IN HANDLE hNamedPipe,
    IN LPOVERLAPPED lpOverlapped
    );

WINBASEAPI
BOOL
WINAPI
DisconnectNamedPipe(
    IN HANDLE hNamedPipe
    );

WINBASEAPI
BOOL
WINAPI
SetNamedPipeHandleState(
    IN HANDLE hNamedPipe,
    IN LPDWORD lpMode,
    IN LPDWORD lpMaxCollectionCount,
    IN LPDWORD lpCollectDataTimeout
    );

WINBASEAPI
BOOL
WINAPI
GetNamedPipeInfo(
    IN HANDLE hNamedPipe,
    IN LPDWORD lpFlags,
    OUT LPDWORD lpOutBufferSize,
    OUT LPDWORD lpInBufferSize,
    OUT LPDWORD lpMaxInstances
    );

WINBASEAPI
BOOL
WINAPI
PeekNamedPipe(
    IN HANDLE hNamedPipe,
    OUT LPVOID lpBuffer,
    IN DWORD nBufferSize,
    OUT LPDWORD lpBytesRead,
    OUT LPDWORD lpTotalBytesAvail,
    OUT LPDWORD lpBytesLeftThisMessage
    );

WINBASEAPI
BOOL
WINAPI
TransactNamedPipe(
    IN HANDLE hNamedPipe,
    IN LPVOID lpInBuffer,
    IN DWORD nInBufferSize,
    OUT LPVOID lpOutBuffer,
    IN DWORD nOutBufferSize,
    OUT LPDWORD lpBytesRead,
    IN LPOVERLAPPED lpOverlapped
    );

WINBASEAPI
HANDLE
WINAPI
CreateMailslotA(
    IN LPCSTR lpName,
    IN DWORD nMaxMessageSize,
    IN DWORD lReadTimeout,
    IN LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
WINBASEAPI
HANDLE
WINAPI
CreateMailslotW(
    IN LPCWSTR lpName,
    IN DWORD nMaxMessageSize,
    IN DWORD lReadTimeout,
    IN LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
#ifdef UNICODE
#define CreateMailslot  CreateMailslotW
#else
#define CreateMailslot  CreateMailslotA
#endif 

WINBASEAPI
BOOL
WINAPI
GetMailslotInfo(
    IN HANDLE hMailslot,
    IN LPDWORD lpMaxMessageSize,
    IN LPDWORD lpNextSize,
    IN LPDWORD lpMessageCount,
    IN LPDWORD lpReadTimeout
    );

WINBASEAPI
BOOL
WINAPI
SetMailslotInfo(
    IN HANDLE hMailslot,
    IN DWORD lReadTimeout
    );

WINBASEAPI
LPVOID
WINAPI
MapViewOfFile(
    IN HANDLE hFileMappingObject,
    IN DWORD dwDesiredAccess,
    IN DWORD dwFileOffsetHigh,
    IN DWORD dwFileOffsetLow,
    IN SIZE_T dwNumberOfBytesToMap
    );

WINBASEAPI
BOOL
WINAPI
FlushViewOfFile(
    IN LPCVOID lpBaseAddress,
    IN SIZE_T dwNumberOfBytesToFlush
    );

WINBASEAPI
BOOL
WINAPI
UnmapViewOfFile(
    IN LPCVOID lpBaseAddress
    );

//

//

WINADVAPI
BOOL
WINAPI
EncryptFileA(
    IN LPCSTR lpFileName
    );
WINADVAPI
BOOL
WINAPI
EncryptFileW(
    IN LPCWSTR lpFileName
    );
#ifdef UNICODE
#define EncryptFile  EncryptFileW
#else
#define EncryptFile  EncryptFileA
#endif 

WINADVAPI
BOOL
WINAPI
DecryptFileA(
    IN LPCSTR lpFileName,
    IN DWORD    dwReserved
    );
WINADVAPI
BOOL
WINAPI
DecryptFileW(
    IN LPCWSTR lpFileName,
    IN DWORD    dwReserved
    );
#ifdef UNICODE
#define DecryptFile  DecryptFileW
#else
#define DecryptFile  DecryptFileA
#endif 

//

//

#define FILE_ENCRYPTABLE                0
#define FILE_IS_ENCRYPTED               1
#define FILE_SYSTEM_ATTR                2
#define FILE_ROOT_DIR                   3
#define FILE_SYSTEM_DIR                 4
#define FILE_UNKNOWN                    5
#define FILE_SYSTEM_NOT_SUPPORT         6
#define FILE_USER_DISALLOWED            7
#define FILE_READ_ONLY                  8
#define FILE_DIR_DISALLOWED             9

WINADVAPI
BOOL
WINAPI
FileEncryptionStatusA(
    LPCSTR lpFileName,
    LPDWORD  lpStatus
    );
WINADVAPI
BOOL
WINAPI
FileEncryptionStatusW(
    LPCWSTR lpFileName,
    LPDWORD  lpStatus
    );
#ifdef UNICODE
#define FileEncryptionStatus  FileEncryptionStatusW
#else
#define FileEncryptionStatus  FileEncryptionStatusA
#endif 

//

//

#define EFS_USE_RECOVERY_KEYS  (0x1)

typedef
DWORD
(WINAPI *PFE_EXPORT_FUNC)(
    PBYTE pbData,
    PVOID pvCallbackContext,
    ULONG ulLength
    );

typedef
DWORD
(WINAPI *PFE_IMPORT_FUNC)(
    PBYTE pbData,
    PVOID pvCallbackContext,
    PULONG ulLength
    );


//

//

#define CREATE_FOR_IMPORT  (1)
#define CREATE_FOR_DIR     (2)
#define OVERWRITE_HIDDEN   (4)


WINADVAPI
DWORD
WINAPI
OpenEncryptedFileRawA(
    IN LPCSTR        lpFileName,
    IN ULONG           ulFlags,
    IN PVOID *         pvContext
    );
WINADVAPI
DWORD
WINAPI
OpenEncryptedFileRawW(
    IN LPCWSTR        lpFileName,
    IN ULONG           ulFlags,
    IN PVOID *         pvContext
    );
#ifdef UNICODE
#define OpenEncryptedFileRaw  OpenEncryptedFileRawW
#else
#define OpenEncryptedFileRaw  OpenEncryptedFileRawA
#endif 

WINADVAPI
DWORD
WINAPI
ReadEncryptedFileRaw(
    IN PFE_EXPORT_FUNC pfExportCallback,
    IN PVOID           pvCallbackContext,
    IN PVOID           pvContext
    );

WINADVAPI
DWORD
WINAPI
WriteEncryptedFileRaw(
    IN PFE_IMPORT_FUNC pfImportCallback,
    IN PVOID           pvCallbackContext,
    IN PVOID           pvContext
    );

WINADVAPI
VOID
WINAPI
CloseEncryptedFileRaw(
    IN PVOID           pvContext
    );

//

//

WINBASEAPI
int
WINAPI
lstrcmpA(
    IN LPCSTR lpString1,
    IN LPCSTR lpString2
    );
WINBASEAPI
int
WINAPI
lstrcmpW(
    IN LPCWSTR lpString1,
    IN LPCWSTR lpString2
    );
#ifdef UNICODE
#define lstrcmp  lstrcmpW
#else
#define lstrcmp  lstrcmpA
#endif 

WINBASEAPI
int
WINAPI
lstrcmpiA(
    IN LPCSTR lpString1,
    IN LPCSTR lpString2
    );
WINBASEAPI
int
WINAPI
lstrcmpiW(
    IN LPCWSTR lpString1,
    IN LPCWSTR lpString2
    );
#ifdef UNICODE
#define lstrcmpi  lstrcmpiW
#else
#define lstrcmpi  lstrcmpiA
#endif 

WINBASEAPI
LPSTR
WINAPI
lstrcpynA(
    OUT LPSTR lpString1,
    IN LPCSTR lpString2,
    IN int iMaxLength
    );
WINBASEAPI
LPWSTR
WINAPI
lstrcpynW(
    OUT LPWSTR lpString1,
    IN LPCWSTR lpString2,
    IN int iMaxLength
    );
#ifdef UNICODE
#define lstrcpyn  lstrcpynW
#else
#define lstrcpyn  lstrcpynA
#endif 

WINBASEAPI
LPSTR
WINAPI
lstrcpyA(
    OUT LPSTR lpString1,
    IN LPCSTR lpString2
    );
WINBASEAPI
LPWSTR
WINAPI
lstrcpyW(
    OUT LPWSTR lpString1,
    IN LPCWSTR lpString2
    );
#ifdef UNICODE
#define lstrcpy  lstrcpyW
#else
#define lstrcpy  lstrcpyA
#endif 

WINBASEAPI
LPSTR
WINAPI
lstrcatA(
    IN OUT LPSTR lpString1,
    IN LPCSTR lpString2
    );
WINBASEAPI
LPWSTR
WINAPI
lstrcatW(
    IN OUT LPWSTR lpString1,
    IN LPCWSTR lpString2
    );
#ifdef UNICODE
#define lstrcat  lstrcatW
#else
#define lstrcat  lstrcatA
#endif 

WINBASEAPI
int
WINAPI
lstrlenA(
    IN LPCSTR lpString
    );
WINBASEAPI
int
WINAPI
lstrlenW(
    IN LPCWSTR lpString
    );
#ifdef UNICODE
#define lstrlen  lstrlenW
#else
#define lstrlen  lstrlenA
#endif 

WINBASEAPI
HFILE
WINAPI
OpenFile(
    IN LPCSTR lpFileName,
    OUT LPOFSTRUCT lpReOpenBuff,
    IN UINT uStyle
    );

WINBASEAPI
HFILE
WINAPI
_lopen(
    IN LPCSTR lpPathName,
    IN int iReadWrite
    );

WINBASEAPI
HFILE
WINAPI
_lcreat(
    IN LPCSTR lpPathName,
    IN int  iAttribute
    );

WINBASEAPI
UINT
WINAPI
_lread(
    IN HFILE hFile,
    OUT LPVOID lpBuffer,
    IN UINT uBytes
    );

WINBASEAPI
UINT
WINAPI
_lwrite(
    IN HFILE hFile,
    IN LPCSTR lpBuffer,
    IN UINT uBytes
    );

WINBASEAPI
long
WINAPI
_hread(
    IN HFILE hFile,
    OUT LPVOID lpBuffer,
    IN long lBytes
    );

WINBASEAPI
long
WINAPI
_hwrite(
    IN HFILE hFile,
    IN LPCSTR lpBuffer,
    IN long lBytes
    );

WINBASEAPI
HFILE
WINAPI
_lclose(
    IN OUT HFILE hFile
    );

WINBASEAPI
LONG
WINAPI
_llseek(
    IN HFILE hFile,
    IN LONG lOffset,
    IN int iOrigin
    );

WINADVAPI
BOOL
WINAPI
IsTextUnicode(
    IN CONST VOID* lpBuffer,
    IN int cb,
    IN OUT LPINT lpi
    );

typedef
VOID
(WINAPI *PFLS_CALLBACK_FUNCTION) (
    IN PVOID lpFlsData
    );

#define FLS_OUT_OF_INDEXES ((DWORD)0xFFFFFFFF)

WINBASEAPI
DWORD
WINAPI
FlsAlloc(
    IN PFLS_CALLBACK_FUNCTION lpCallback OPTIONAL
    );

WINBASEAPI
PVOID
WINAPI
FlsGetValue(
    IN DWORD dwFlsIndex
    );

WINBASEAPI
BOOL
WINAPI
FlsSetValue(
    IN DWORD dwFlsIndex,
    IN PVOID lpFlsData
    );

WINBASEAPI
BOOL
WINAPI
FlsFree(
    IN DWORD dwFlsIndex
    );

#define TLS_OUT_OF_INDEXES ((DWORD)0xFFFFFFFF)

WINBASEAPI
DWORD
WINAPI
TlsAlloc(
    VOID
    );

WINBASEAPI
LPVOID
WINAPI
TlsGetValue(
    IN DWORD dwTlsIndex
    );

WINBASEAPI
BOOL
WINAPI
TlsSetValue(
    IN DWORD dwTlsIndex,
    IN LPVOID lpTlsValue
    );

WINBASEAPI
BOOL
WINAPI
TlsFree(
    IN DWORD dwTlsIndex
    );

typedef
VOID
(WINAPI *LPOVERLAPPED_COMPLETION_ROUTINE)(
    DWORD dwErrorCode,
    DWORD dwNumberOfBytesTransfered,
    LPOVERLAPPED lpOverlapped
    );

WINBASEAPI
DWORD
WINAPI
SleepEx(
    IN DWORD dwMilliseconds,
    IN BOOL bAlertable
    );

WINBASEAPI
DWORD
WINAPI
WaitForSingleObjectEx(
    IN HANDLE hHandle,
    IN DWORD dwMilliseconds,
    IN BOOL bAlertable
    );

WINBASEAPI
DWORD
WINAPI
WaitForMultipleObjectsEx(
    IN DWORD nCount,
    IN CONST HANDLE *lpHandles,
    IN BOOL bWaitAll,
    IN DWORD dwMilliseconds,
    IN BOOL bAlertable
    );

#if(_WIN32_WINNT >= 0x0400)
WINBASEAPI
DWORD
WINAPI
SignalObjectAndWait(
    IN HANDLE hObjectToSignal,
    IN HANDLE hObjectToWaitOn,
    IN DWORD dwMilliseconds,
    IN BOOL bAlertable
    );
#endif 

WINBASEAPI
BOOL
WINAPI
ReadFileEx(
    IN HANDLE hFile,
    OUT LPVOID lpBuffer,
    IN DWORD nNumberOfBytesToRead,
    IN LPOVERLAPPED lpOverlapped,
    IN LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    );

WINBASEAPI
BOOL
WINAPI
WriteFileEx(
    IN HANDLE hFile,
    IN LPCVOID lpBuffer,
    IN DWORD nNumberOfBytesToWrite,
    IN LPOVERLAPPED lpOverlapped,
    IN LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    );

WINBASEAPI
BOOL
WINAPI
BackupRead(
    IN HANDLE hFile,
    OUT LPBYTE lpBuffer,
    IN DWORD nNumberOfBytesToRead,
    OUT LPDWORD lpNumberOfBytesRead,
    IN BOOL bAbort,
    IN BOOL bProcessSecurity,
    OUT LPVOID *lpContext
    );

WINBASEAPI
BOOL
WINAPI
BackupSeek(
    IN HANDLE hFile,
    IN DWORD  dwLowBytesToSeek,
    IN DWORD  dwHighBytesToSeek,
    OUT LPDWORD lpdwLowByteSeeked,
    OUT LPDWORD lpdwHighByteSeeked,
    IN LPVOID *lpContext
    );

WINBASEAPI
BOOL
WINAPI
BackupWrite(
    IN HANDLE hFile,
    IN LPBYTE lpBuffer,
    IN DWORD nNumberOfBytesToWrite,
    OUT LPDWORD lpNumberOfBytesWritten,
    IN BOOL bAbort,
    IN BOOL bProcessSecurity,
    OUT LPVOID *lpContext
    );

//

//
typedef struct _WIN32_STREAM_ID {
        DWORD          dwStreamId ;
        DWORD          dwStreamAttributes ;
        LARGE_INTEGER  Size ;
        DWORD          dwStreamNameSize ;
        WCHAR          cStreamName[ ANYSIZE_ARRAY ] ;
} WIN32_STREAM_ID, *LPWIN32_STREAM_ID ;

//

//

#define BACKUP_INVALID          0x00000000
#define BACKUP_DATA             0x00000001
#define BACKUP_EA_DATA          0x00000002
#define BACKUP_SECURITY_DATA    0x00000003
#define BACKUP_ALTERNATE_DATA   0x00000004
#define BACKUP_LINK             0x00000005
#define BACKUP_PROPERTY_DATA    0x00000006
#define BACKUP_OBJECT_ID        0x00000007
#define BACKUP_REPARSE_DATA     0x00000008
#define BACKUP_SPARSE_BLOCK     0x00000009


//

//

#define STREAM_NORMAL_ATTRIBUTE         0x00000000
#define STREAM_MODIFIED_WHEN_READ       0x00000001
#define STREAM_CONTAINS_SECURITY        0x00000002
#define STREAM_CONTAINS_PROPERTIES      0x00000004
#define STREAM_SPARSE_ATTRIBUTE         0x00000008

WINBASEAPI
BOOL
WINAPI
ReadFileScatter(
    IN HANDLE hFile,
    IN FILE_SEGMENT_ELEMENT aSegmentArray[],
    IN DWORD nNumberOfBytesToRead,
    IN LPDWORD lpReserved,
    IN LPOVERLAPPED lpOverlapped
    );

WINBASEAPI
BOOL
WINAPI
WriteFileGather(
    IN HANDLE hFile,
    OUT FILE_SEGMENT_ELEMENT aSegmentArray[],
    IN DWORD nNumberOfBytesToWrite,
    IN LPDWORD lpReserved,
    IN LPOVERLAPPED lpOverlapped
    );

//

//

#define STARTF_USESHOWWINDOW    0x00000001
#define STARTF_USESIZE          0x00000002
#define STARTF_USEPOSITION      0x00000004
#define STARTF_USECOUNTCHARS    0x00000008
#define STARTF_USEFILLATTRIBUTE 0x00000010
#define STARTF_RUNFULLSCREEN    0x00000020  
#define STARTF_FORCEONFEEDBACK  0x00000040
#define STARTF_FORCEOFFFEEDBACK 0x00000080
#define STARTF_USESTDHANDLES    0x00000100

#if(WINVER >= 0x0400)

#define STARTF_USEHOTKEY        0x00000200
#endif 

typedef struct _STARTUPINFOA {
    DWORD   cb;
    LPSTR   lpReserved;
    LPSTR   lpDesktop;
    LPSTR   lpTitle;
    DWORD   dwX;
    DWORD   dwY;
    DWORD   dwXSize;
    DWORD   dwYSize;
    DWORD   dwXCountChars;
    DWORD   dwYCountChars;
    DWORD   dwFillAttribute;
    DWORD   dwFlags;
    WORD    wShowWindow;
    WORD    cbReserved2;
    LPBYTE  lpReserved2;
    HANDLE  hStdInput;
    HANDLE  hStdOutput;
    HANDLE  hStdError;
} STARTUPINFOA, *LPSTARTUPINFOA;
typedef struct _STARTUPINFOW {
    DWORD   cb;
    LPWSTR  lpReserved;
    LPWSTR  lpDesktop;
    LPWSTR  lpTitle;
    DWORD   dwX;
    DWORD   dwY;
    DWORD   dwXSize;
    DWORD   dwYSize;
    DWORD   dwXCountChars;
    DWORD   dwYCountChars;
    DWORD   dwFillAttribute;
    DWORD   dwFlags;
    WORD    wShowWindow;
    WORD    cbReserved2;
    LPBYTE  lpReserved2;
    HANDLE  hStdInput;
    HANDLE  hStdOutput;
    HANDLE  hStdError;
} STARTUPINFOW, *LPSTARTUPINFOW;
#ifdef UNICODE
typedef STARTUPINFOW STARTUPINFO;
typedef LPSTARTUPINFOW LPSTARTUPINFO;
#else
typedef STARTUPINFOA STARTUPINFO;
typedef LPSTARTUPINFOA LPSTARTUPINFO;
#endif 

#define SHUTDOWN_NORETRY                0x00000001

typedef struct _WIN32_FIND_DATAA {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD dwReserved0;
    DWORD dwReserved1;
    CHAR   cFileName[ MAX_PATH ];
    CHAR   cAlternateFileName[ 14 ];
#ifdef _MAC
    DWORD dwFileType;
    DWORD dwCreatorType;
    WORD  wFinderFlags;
#endif
} WIN32_FIND_DATAA, *PWIN32_FIND_DATAA, *LPWIN32_FIND_DATAA;
typedef struct _WIN32_FIND_DATAW {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD dwReserved0;
    DWORD dwReserved1;
    WCHAR  cFileName[ MAX_PATH ];
    WCHAR  cAlternateFileName[ 14 ];
#ifdef _MAC
    DWORD dwFileType;
    DWORD dwCreatorType;
    WORD  wFinderFlags;
#endif
} WIN32_FIND_DATAW, *PWIN32_FIND_DATAW, *LPWIN32_FIND_DATAW;
#ifdef UNICODE
typedef WIN32_FIND_DATAW WIN32_FIND_DATA;
typedef PWIN32_FIND_DATAW PWIN32_FIND_DATA;
typedef LPWIN32_FIND_DATAW LPWIN32_FIND_DATA;
#else
typedef WIN32_FIND_DATAA WIN32_FIND_DATA;
typedef PWIN32_FIND_DATAA PWIN32_FIND_DATA;
typedef LPWIN32_FIND_DATAA LPWIN32_FIND_DATA;
#endif 

typedef struct _WIN32_FILE_ATTRIBUTE_DATA {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
} WIN32_FILE_ATTRIBUTE_DATA, *LPWIN32_FILE_ATTRIBUTE_DATA;

WINBASEAPI
HANDLE
WINAPI
CreateMutexA(
    IN LPSECURITY_ATTRIBUTES lpMutexAttributes,
    IN BOOL bInitialOwner,
    IN LPCSTR lpName
    );
WINBASEAPI
HANDLE
WINAPI
CreateMutexW(
    IN LPSECURITY_ATTRIBUTES lpMutexAttributes,
    IN BOOL bInitialOwner,
    IN LPCWSTR lpName
    );
#ifdef UNICODE
#define CreateMutex  CreateMutexW
#else
#define CreateMutex  CreateMutexA
#endif 

WINBASEAPI
HANDLE
WINAPI
OpenMutexA(
    IN DWORD dwDesiredAccess,
    IN BOOL bInheritHandle,
    IN LPCSTR lpName
    );
WINBASEAPI
HANDLE
WINAPI
OpenMutexW(
    IN DWORD dwDesiredAccess,
    IN BOOL bInheritHandle,
    IN LPCWSTR lpName
    );
#ifdef UNICODE
#define OpenMutex  OpenMutexW
#else
#define OpenMutex  OpenMutexA
#endif 

WINBASEAPI
HANDLE
WINAPI
CreateEventA(
    IN LPSECURITY_ATTRIBUTES lpEventAttributes,
    IN BOOL bManualReset,
    IN BOOL bInitialState,
    IN LPCSTR lpName
    );
WINBASEAPI
HANDLE
WINAPI
CreateEventW(
    IN LPSECURITY_ATTRIBUTES lpEventAttributes,
    IN BOOL bManualReset,
    IN BOOL bInitialState,
    IN LPCWSTR lpName
    );
#ifdef UNICODE
#define CreateEvent  CreateEventW
#else
#define CreateEvent  CreateEventA
#endif 

WINBASEAPI
HANDLE
WINAPI
OpenEventA(
    IN DWORD dwDesiredAccess,
    IN BOOL bInheritHandle,
    IN LPCSTR lpName
    );
WINBASEAPI
HANDLE
WINAPI
OpenEventW(
    IN DWORD dwDesiredAccess,
    IN BOOL bInheritHandle,
    IN LPCWSTR lpName
    );
#ifdef UNICODE
#define OpenEvent  OpenEventW
#else
#define OpenEvent  OpenEventA
#endif 

WINBASEAPI
HANDLE
WINAPI
CreateSemaphoreA(
    IN LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
    IN LONG lInitialCount,
    IN LONG lMaximumCount,
    IN LPCSTR lpName
    );
WINBASEAPI
HANDLE
WINAPI
CreateSemaphoreW(
    IN LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
    IN LONG lInitialCount,
    IN LONG lMaximumCount,
    IN LPCWSTR lpName
    );
#ifdef UNICODE
#define CreateSemaphore  CreateSemaphoreW
#else
#define CreateSemaphore  CreateSemaphoreA
#endif 

WINBASEAPI
HANDLE
WINAPI
OpenSemaphoreA(
    IN DWORD dwDesiredAccess,
    IN BOOL bInheritHandle,
    IN LPCSTR lpName
    );
WINBASEAPI
HANDLE
WINAPI
OpenSemaphoreW(
    IN DWORD dwDesiredAccess,
    IN BOOL bInheritHandle,
    IN LPCWSTR lpName
    );
#ifdef UNICODE
#define OpenSemaphore  OpenSemaphoreW
#else
#define OpenSemaphore  OpenSemaphoreA
#endif 

#if (_WIN32_WINNT >= 0x0400) || (_WIN32_WINDOWS > 0x0400)
typedef
VOID
(APIENTRY *PTIMERAPCROUTINE)(
    LPVOID lpArgToCompletionRoutine,
    DWORD dwTimerLowValue,
    DWORD dwTimerHighValue
    );

WINBASEAPI
HANDLE
WINAPI
CreateWaitableTimerA(
    IN LPSECURITY_ATTRIBUTES lpTimerAttributes,
    IN BOOL bManualReset,
    IN LPCSTR lpTimerName
    );
WINBASEAPI
HANDLE
WINAPI
CreateWaitableTimerW(
    IN LPSECURITY_ATTRIBUTES lpTimerAttributes,
    IN BOOL bManualReset,
    IN LPCWSTR lpTimerName
    );
#ifdef UNICODE
#define CreateWaitableTimer  CreateWaitableTimerW
#else
#define CreateWaitableTimer  CreateWaitableTimerA
#endif 

WINBASEAPI
HANDLE
WINAPI
OpenWaitableTimerA(
    IN DWORD dwDesiredAccess,
    IN BOOL bInheritHandle,
    IN LPCSTR lpTimerName
    );
WINBASEAPI
HANDLE
WINAPI
OpenWaitableTimerW(
    IN DWORD dwDesiredAccess,
    IN BOOL bInheritHandle,
    IN LPCWSTR lpTimerName
    );
#ifdef UNICODE
#define OpenWaitableTimer  OpenWaitableTimerW
#else
#define OpenWaitableTimer  OpenWaitableTimerA
#endif 

WINBASEAPI
BOOL
WINAPI
SetWaitableTimer(
    IN HANDLE hTimer,
    IN const LARGE_INTEGER *lpDueTime,
    IN LONG lPeriod,
    IN PTIMERAPCROUTINE pfnCompletionRoutine,
    IN LPVOID lpArgToCompletionRoutine,
    IN BOOL fResume
    );

WINBASEAPI
BOOL
WINAPI
CancelWaitableTimer(
    IN HANDLE hTimer
    );
#endif 

WINBASEAPI
HANDLE
WINAPI
CreateFileMappingA(
    IN HANDLE hFile,
    IN LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
    IN DWORD flProtect,
    IN DWORD dwMaximumSizeHigh,
    IN DWORD dwMaximumSizeLow,
    IN LPCSTR lpName
    );
WINBASEAPI
HANDLE
WINAPI
CreateFileMappingW(
    IN HANDLE hFile,
    IN LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
    IN DWORD flProtect,
    IN DWORD dwMaximumSizeHigh,
    IN DWORD dwMaximumSizeLow,
    IN LPCWSTR lpName
    );
#ifdef UNICODE
#define CreateFileMapping  CreateFileMappingW
#else
#define CreateFileMapping  CreateFileMappingA
#endif 

WINBASEAPI
HANDLE
WINAPI
OpenFileMappingA(
    IN DWORD dwDesiredAccess,
    IN BOOL bInheritHandle,
    IN LPCSTR lpName
    );
WINBASEAPI
HANDLE
WINAPI
OpenFileMappingW(
    IN DWORD dwDesiredAccess,
    IN BOOL bInheritHandle,
    IN LPCWSTR lpName
    );
#ifdef UNICODE
#define OpenFileMapping  OpenFileMappingW
#else
#define OpenFileMapping  OpenFileMappingA
#endif 

WINBASEAPI
DWORD
WINAPI
GetLogicalDriveStringsA(
    IN DWORD nBufferLength,
    OUT LPSTR lpBuffer
    );
WINBASEAPI
DWORD
WINAPI
GetLogicalDriveStringsW(
    IN DWORD nBufferLength,
    OUT LPWSTR lpBuffer
    );
#ifdef UNICODE
#define GetLogicalDriveStrings  GetLogicalDriveStringsW
#else
#define GetLogicalDriveStrings  GetLogicalDriveStringsA
#endif 

#if _WIN32_WINNT >= 0x0501

typedef enum _MEMORY_RESOURCE_NOTIFICATION_TYPE {
    LowMemoryResourceNotification,
    HighMemoryResourceNotification
} MEMORY_RESOURCE_NOTIFICATION_TYPE;

WINBASEAPI
HANDLE
WINAPI
CreateMemoryResourceNotification(
    IN MEMORY_RESOURCE_NOTIFICATION_TYPE NotificationType
    );

WINBASEAPI
BOOL
WINAPI
QueryMemoryResourceNotification(
    IN  HANDLE ResourceNotificationHandle,
    OUT PBOOL  ResourceState
    );

#endif 


WINBASEAPI
HMODULE
WINAPI
LoadLibraryA(
    IN LPCSTR lpLibFileName
    );
WINBASEAPI
HMODULE
WINAPI
LoadLibraryW(
    IN LPCWSTR lpLibFileName
    );
#ifdef UNICODE
#define LoadLibrary  LoadLibraryW
#else
#define LoadLibrary  LoadLibraryA
#endif 

WINBASEAPI
HMODULE
WINAPI
LoadLibraryExA(
    IN LPCSTR lpLibFileName,
    IN HANDLE hFile,
    IN DWORD dwFlags
    );
WINBASEAPI
HMODULE
WINAPI
LoadLibraryExW(
    IN LPCWSTR lpLibFileName,
    IN HANDLE hFile,
    IN DWORD dwFlags
    );
#ifdef UNICODE
#define LoadLibraryEx  LoadLibraryExW
#else
#define LoadLibraryEx  LoadLibraryExA
#endif 


#define DONT_RESOLVE_DLL_REFERENCES   0x00000001
#define LOAD_LIBRARY_AS_DATAFILE      0x00000002
#define LOAD_WITH_ALTERED_SEARCH_PATH 0x00000008
#define LOAD_IGNORE_CODE_AUTHZ_LEVEL  0x00000010


WINBASEAPI
DWORD
WINAPI
GetModuleFileNameA(
    IN HMODULE hModule,
    OUT LPSTR lpFilename,
    IN DWORD nSize
    );
WINBASEAPI
DWORD
WINAPI
GetModuleFileNameW(
    IN HMODULE hModule,
    OUT LPWSTR lpFilename,
    IN DWORD nSize
    );
#ifdef UNICODE
#define GetModuleFileName  GetModuleFileNameW
#else
#define GetModuleFileName  GetModuleFileNameA
#endif 

WINBASEAPI
HMODULE
WINAPI
GetModuleHandleA(
    IN LPCSTR lpModuleName
    );
WINBASEAPI
HMODULE
WINAPI
GetModuleHandleW(
    IN LPCWSTR lpModuleName
    );
#ifdef UNICODE
#define GetModuleHandle  GetModuleHandleW
#else
#define GetModuleHandle  GetModuleHandleA
#endif 

#if !defined(RC_INVOKED)
#if _WIN32_WINNT > 0x0500 || defined(WINBASE_DECLARE_GET_MODULE_HANDLE_EX) || ISOLATION_AWARE_ENABLED

#define GET_MODULE_HANDLE_EX_FLAG_PIN                 (0x00000001)
#define GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT  (0x00000002)
#define GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS        (0x00000004)

typedef
BOOL
(WINAPI*
PGET_MODULE_HANDLE_EXA)(
    IN DWORD        dwFlags,
    IN LPCSTR     lpModuleName,
    OUT HMODULE*    phModule
    );
typedef
BOOL
(WINAPI*
PGET_MODULE_HANDLE_EXW)(
    IN DWORD        dwFlags,
    IN LPCWSTR     lpModuleName,
    OUT HMODULE*    phModule
    );
#ifdef UNICODE
#define PGET_MODULE_HANDLE_EX  PGET_MODULE_HANDLE_EXW
#else
#define PGET_MODULE_HANDLE_EX  PGET_MODULE_HANDLE_EXA
#endif 

WINBASEAPI
BOOL
WINAPI
GetModuleHandleExA(
    IN DWORD        dwFlags,
    IN LPCSTR     lpModuleName,
    OUT HMODULE*    phModule
    );
WINBASEAPI
BOOL
WINAPI
GetModuleHandleExW(
    IN DWORD        dwFlags,
    IN LPCWSTR     lpModuleName,
    OUT HMODULE*    phModule
    );
#ifdef UNICODE
#define GetModuleHandleEx  GetModuleHandleExW
#else
#define GetModuleHandleEx  GetModuleHandleExA
#endif 

#endif
#endif

WINBASEAPI
BOOL
WINAPI
CreateProcessA(
    IN LPCSTR lpApplicationName,
    IN LPSTR lpCommandLine,
    IN LPSECURITY_ATTRIBUTES lpProcessAttributes,
    IN LPSECURITY_ATTRIBUTES lpThreadAttributes,
    IN BOOL bInheritHandles,
    IN DWORD dwCreationFlags,
    IN LPVOID lpEnvironment,
    IN LPCSTR lpCurrentDirectory,
    IN LPSTARTUPINFOA lpStartupInfo,
    OUT LPPROCESS_INFORMATION lpProcessInformation
    );
WINBASEAPI
BOOL
WINAPI
CreateProcessW(
    IN LPCWSTR lpApplicationName,
    IN LPWSTR lpCommandLine,
    IN LPSECURITY_ATTRIBUTES lpProcessAttributes,
    IN LPSECURITY_ATTRIBUTES lpThreadAttributes,
    IN BOOL bInheritHandles,
    IN DWORD dwCreationFlags,
    IN LPVOID lpEnvironment,
    IN LPCWSTR lpCurrentDirectory,
    IN LPSTARTUPINFOW lpStartupInfo,
    OUT LPPROCESS_INFORMATION lpProcessInformation
    );
#ifdef UNICODE
#define CreateProcess  CreateProcessW
#else
#define CreateProcess  CreateProcessA
#endif 



WINBASEAPI
BOOL
WINAPI
SetProcessShutdownParameters(
    IN DWORD dwLevel,
    IN DWORD dwFlags
    );

WINBASEAPI
BOOL
WINAPI
GetProcessShutdownParameters(
    OUT LPDWORD lpdwLevel,
    OUT LPDWORD lpdwFlags
    );

WINBASEAPI
DWORD
WINAPI
GetProcessVersion(
    IN DWORD ProcessId
    );

WINBASEAPI
VOID
WINAPI
FatalAppExitA(
    IN UINT uAction,
    IN LPCSTR lpMessageText
    );
WINBASEAPI
VOID
WINAPI
FatalAppExitW(
    IN UINT uAction,
    IN LPCWSTR lpMessageText
    );
#ifdef UNICODE
#define FatalAppExit  FatalAppExitW
#else
#define FatalAppExit  FatalAppExitA
#endif 

WINBASEAPI
VOID
WINAPI
GetStartupInfoA(
    OUT LPSTARTUPINFOA lpStartupInfo
    );
WINBASEAPI
VOID
WINAPI
GetStartupInfoW(
    OUT LPSTARTUPINFOW lpStartupInfo
    );
#ifdef UNICODE
#define GetStartupInfo  GetStartupInfoW
#else
#define GetStartupInfo  GetStartupInfoA
#endif 

WINBASEAPI
LPSTR
WINAPI
GetCommandLineA(
    VOID
    );
WINBASEAPI
LPWSTR
WINAPI
GetCommandLineW(
    VOID
    );
#ifdef UNICODE
#define GetCommandLine  GetCommandLineW
#else
#define GetCommandLine  GetCommandLineA
#endif 

WINBASEAPI
DWORD
WINAPI
GetEnvironmentVariableA(
    IN LPCSTR lpName,
    OUT LPSTR lpBuffer,
    IN DWORD nSize
    );
WINBASEAPI
DWORD
WINAPI
GetEnvironmentVariableW(
    IN LPCWSTR lpName,
    OUT LPWSTR lpBuffer,
    IN DWORD nSize
    );
#ifdef UNICODE
#define GetEnvironmentVariable  GetEnvironmentVariableW
#else
#define GetEnvironmentVariable  GetEnvironmentVariableA
#endif 

WINBASEAPI
BOOL
WINAPI
SetEnvironmentVariableA(
    IN LPCSTR lpName,
    IN LPCSTR lpValue
    );
WINBASEAPI
BOOL
WINAPI
SetEnvironmentVariableW(
    IN LPCWSTR lpName,
    IN LPCWSTR lpValue
    );
#ifdef UNICODE
#define SetEnvironmentVariable  SetEnvironmentVariableW
#else
#define SetEnvironmentVariable  SetEnvironmentVariableA
#endif 

WINBASEAPI
DWORD
WINAPI
ExpandEnvironmentStringsA(
    IN LPCSTR lpSrc,
    OUT LPSTR lpDst,
    IN DWORD nSize
    );
WINBASEAPI
DWORD
WINAPI
ExpandEnvironmentStringsW(
    IN LPCWSTR lpSrc,
    OUT LPWSTR lpDst,
    IN DWORD nSize
    );
#ifdef UNICODE
#define ExpandEnvironmentStrings  ExpandEnvironmentStringsW
#else
#define ExpandEnvironmentStrings  ExpandEnvironmentStringsA
#endif 

WINBASEAPI
DWORD
WINAPI
GetFirmwareEnvironmentVariableA(
    IN LPCSTR lpName,
    IN LPCSTR lpGuid,
    OUT PVOID   pBuffer,
    IN DWORD    nSize
    );
WINBASEAPI
DWORD
WINAPI
GetFirmwareEnvironmentVariableW(
    IN LPCWSTR lpName,
    IN LPCWSTR lpGuid,
    OUT PVOID   pBuffer,
    IN DWORD    nSize
    );
#ifdef UNICODE
#define GetFirmwareEnvironmentVariable  GetFirmwareEnvironmentVariableW
#else
#define GetFirmwareEnvironmentVariable  GetFirmwareEnvironmentVariableA
#endif 

WINBASEAPI
BOOL
WINAPI
SetFirmwareEnvironmentVariableA(
    IN LPCSTR lpName,
    IN LPCSTR lpGuid,
    IN PVOID    pValue,
    IN DWORD    nSize
    );
WINBASEAPI
BOOL
WINAPI
SetFirmwareEnvironmentVariableW(
    IN LPCWSTR lpName,
    IN LPCWSTR lpGuid,
    IN PVOID    pValue,
    IN DWORD    nSize
    );
#ifdef UNICODE
#define SetFirmwareEnvironmentVariable  SetFirmwareEnvironmentVariableW
#else
#define SetFirmwareEnvironmentVariable  SetFirmwareEnvironmentVariableA
#endif 


WINBASEAPI
VOID
WINAPI
OutputDebugStringA(
    IN LPCSTR lpOutputString
    );
WINBASEAPI
VOID
WINAPI
OutputDebugStringW(
    IN LPCWSTR lpOutputString
    );
#ifdef UNICODE
#define OutputDebugString  OutputDebugStringW
#else
#define OutputDebugString  OutputDebugStringA
#endif 

WINBASEAPI
HRSRC
WINAPI
FindResourceA(
    IN HMODULE hModule,
    IN LPCSTR lpName,
    IN LPCSTR lpType
    );
WINBASEAPI
HRSRC
WINAPI
FindResourceW(
    IN HMODULE hModule,
    IN LPCWSTR lpName,
    IN LPCWSTR lpType
    );
#ifdef UNICODE
#define FindResource  FindResourceW
#else
#define FindResource  FindResourceA
#endif 

WINBASEAPI
HRSRC
WINAPI
FindResourceExA(
    IN HMODULE hModule,
    IN LPCSTR lpType,
    IN LPCSTR lpName,
    IN WORD    wLanguage
    );
WINBASEAPI
HRSRC
WINAPI
FindResourceExW(
    IN HMODULE hModule,
    IN LPCWSTR lpType,
    IN LPCWSTR lpName,
    IN WORD    wLanguage
    );
#ifdef UNICODE
#define FindResourceEx  FindResourceExW
#else
#define FindResourceEx  FindResourceExA
#endif 

#ifdef STRICT
typedef BOOL (CALLBACK* ENUMRESTYPEPROCA)(HMODULE hModule, LPSTR lpType,
        LONG_PTR lParam);
typedef BOOL (CALLBACK* ENUMRESTYPEPROCW)(HMODULE hModule, LPWSTR lpType,
        LONG_PTR lParam);
#ifdef UNICODE
#define ENUMRESTYPEPROC  ENUMRESTYPEPROCW
#else
#define ENUMRESTYPEPROC  ENUMRESTYPEPROCA
#endif 
typedef BOOL (CALLBACK* ENUMRESNAMEPROCA)(HMODULE hModule, LPCSTR lpType,
        LPSTR lpName, LONG_PTR lParam);
typedef BOOL (CALLBACK* ENUMRESNAMEPROCW)(HMODULE hModule, LPCWSTR lpType,
        LPWSTR lpName, LONG_PTR lParam);
#ifdef UNICODE
#define ENUMRESNAMEPROC  ENUMRESNAMEPROCW
#else
#define ENUMRESNAMEPROC  ENUMRESNAMEPROCA
#endif 
typedef BOOL (CALLBACK* ENUMRESLANGPROCA)(HMODULE hModule, LPCSTR lpType,
        LPCSTR lpName, WORD  wLanguage, LONG_PTR lParam);
typedef BOOL (CALLBACK* ENUMRESLANGPROCW)(HMODULE hModule, LPCWSTR lpType,
        LPCWSTR lpName, WORD  wLanguage, LONG_PTR lParam);
#ifdef UNICODE
#define ENUMRESLANGPROC  ENUMRESLANGPROCW
#else
#define ENUMRESLANGPROC  ENUMRESLANGPROCA
#endif 
#else
typedef FARPROC ENUMRESTYPEPROCA;
typedef FARPROC ENUMRESTYPEPROCW;
#ifdef UNICODE
typedef ENUMRESTYPEPROCW ENUMRESTYPEPROC;
#else
typedef ENUMRESTYPEPROCA ENUMRESTYPEPROC;
#endif 
typedef FARPROC ENUMRESNAMEPROCA;
typedef FARPROC ENUMRESNAMEPROCW;
#ifdef UNICODE
typedef ENUMRESNAMEPROCW ENUMRESNAMEPROC;
#else
typedef ENUMRESNAMEPROCA ENUMRESNAMEPROC;
#endif 
typedef FARPROC ENUMRESLANGPROCA;
typedef FARPROC ENUMRESLANGPROCW;
#ifdef UNICODE
typedef ENUMRESLANGPROCW ENUMRESLANGPROC;
#else
typedef ENUMRESLANGPROCA ENUMRESLANGPROC;
#endif 
#endif

WINBASEAPI
BOOL
WINAPI
EnumResourceTypesA(
    IN HMODULE hModule,
    IN ENUMRESTYPEPROCA lpEnumFunc,
    IN LONG_PTR lParam
    );
WINBASEAPI
BOOL
WINAPI
EnumResourceTypesW(
    IN HMODULE hModule,
    IN ENUMRESTYPEPROCW lpEnumFunc,
    IN LONG_PTR lParam
    );
#ifdef UNICODE
#define EnumResourceTypes  EnumResourceTypesW
#else
#define EnumResourceTypes  EnumResourceTypesA
#endif 


WINBASEAPI
BOOL
WINAPI
EnumResourceNamesA(
    IN HMODULE hModule,
    IN LPCSTR lpType,
    IN ENUMRESNAMEPROCA lpEnumFunc,
    IN LONG_PTR lParam
    );
WINBASEAPI
BOOL
WINAPI
EnumResourceNamesW(
    IN HMODULE hModule,
    IN LPCWSTR lpType,
    IN ENUMRESNAMEPROCW lpEnumFunc,
    IN LONG_PTR lParam
    );
#ifdef UNICODE
#define EnumResourceNames  EnumResourceNamesW
#else
#define EnumResourceNames  EnumResourceNamesA
#endif 

WINBASEAPI
BOOL
WINAPI
EnumResourceLanguagesA(
    IN HMODULE hModule,
    IN LPCSTR lpType,
    IN LPCSTR lpName,
    IN ENUMRESLANGPROCA lpEnumFunc,
    IN LONG_PTR lParam
    );
WINBASEAPI
BOOL
WINAPI
EnumResourceLanguagesW(
    IN HMODULE hModule,
    IN LPCWSTR lpType,
    IN LPCWSTR lpName,
    IN ENUMRESLANGPROCW lpEnumFunc,
    IN LONG_PTR lParam
    );
#ifdef UNICODE
#define EnumResourceLanguages  EnumResourceLanguagesW
#else
#define EnumResourceLanguages  EnumResourceLanguagesA
#endif 

WINBASEAPI
HANDLE
WINAPI
BeginUpdateResourceA(
    IN LPCSTR pFileName,
    IN BOOL bDeleteExistingResources
    );
WINBASEAPI
HANDLE
WINAPI
BeginUpdateResourceW(
    IN LPCWSTR pFileName,
    IN BOOL bDeleteExistingResources
    );
#ifdef UNICODE
#define BeginUpdateResource  BeginUpdateResourceW
#else
#define BeginUpdateResource  BeginUpdateResourceA
#endif 

WINBASEAPI
BOOL
WINAPI
UpdateResourceA(
    IN HANDLE      hUpdate,
    IN LPCSTR     lpType,
    IN LPCSTR     lpName,
    IN WORD        wLanguage,
    IN LPVOID      lpData,
    IN DWORD       cbData
    );
WINBASEAPI
BOOL
WINAPI
UpdateResourceW(
    IN HANDLE      hUpdate,
    IN LPCWSTR     lpType,
    IN LPCWSTR     lpName,
    IN WORD        wLanguage,
    IN LPVOID      lpData,
    IN DWORD       cbData
    );
#ifdef UNICODE
#define UpdateResource  UpdateResourceW
#else
#define UpdateResource  UpdateResourceA
#endif 

WINBASEAPI
BOOL
WINAPI
EndUpdateResourceA(
    IN HANDLE      hUpdate,
    IN BOOL        fDiscard
    );
WINBASEAPI
BOOL
WINAPI
EndUpdateResourceW(
    IN HANDLE      hUpdate,
    IN BOOL        fDiscard
    );
#ifdef UNICODE
#define EndUpdateResource  EndUpdateResourceW
#else
#define EndUpdateResource  EndUpdateResourceA
#endif 

WINBASEAPI
ATOM
WINAPI
GlobalAddAtomA(
    IN LPCSTR lpString
    );
WINBASEAPI
ATOM
WINAPI
GlobalAddAtomW(
    IN LPCWSTR lpString
    );
#ifdef UNICODE
#define GlobalAddAtom  GlobalAddAtomW
#else
#define GlobalAddAtom  GlobalAddAtomA
#endif 

WINBASEAPI
ATOM
WINAPI
GlobalFindAtomA(
    IN LPCSTR lpString
    );
WINBASEAPI
ATOM
WINAPI
GlobalFindAtomW(
    IN LPCWSTR lpString
    );
#ifdef UNICODE
#define GlobalFindAtom  GlobalFindAtomW
#else
#define GlobalFindAtom  GlobalFindAtomA
#endif 

WINBASEAPI
UINT
WINAPI
GlobalGetAtomNameA(
    IN ATOM nAtom,
    OUT LPSTR lpBuffer,
    IN int nSize
    );
WINBASEAPI
UINT
WINAPI
GlobalGetAtomNameW(
    IN ATOM nAtom,
    OUT LPWSTR lpBuffer,
    IN int nSize
    );
#ifdef UNICODE
#define GlobalGetAtomName  GlobalGetAtomNameW
#else
#define GlobalGetAtomName  GlobalGetAtomNameA
#endif 

WINBASEAPI
ATOM
WINAPI
AddAtomA(
    IN LPCSTR lpString
    );
WINBASEAPI
ATOM
WINAPI
AddAtomW(
    IN LPCWSTR lpString
    );
#ifdef UNICODE
#define AddAtom  AddAtomW
#else
#define AddAtom  AddAtomA
#endif 

WINBASEAPI
ATOM
WINAPI
FindAtomA(
    IN LPCSTR lpString
    );
WINBASEAPI
ATOM
WINAPI
FindAtomW(
    IN LPCWSTR lpString
    );
#ifdef UNICODE
#define FindAtom  FindAtomW
#else
#define FindAtom  FindAtomA
#endif 

WINBASEAPI
UINT
WINAPI
GetAtomNameA(
    IN ATOM nAtom,
    OUT LPSTR lpBuffer,
    IN int nSize
    );
WINBASEAPI
UINT
WINAPI
GetAtomNameW(
    IN ATOM nAtom,
    OUT LPWSTR lpBuffer,
    IN int nSize
    );
#ifdef UNICODE
#define GetAtomName  GetAtomNameW
#else
#define GetAtomName  GetAtomNameA
#endif 

WINBASEAPI
UINT
WINAPI
GetProfileIntA(
    IN LPCSTR lpAppName,
    IN LPCSTR lpKeyName,
    IN INT nDefault
    );
WINBASEAPI
UINT
WINAPI
GetProfileIntW(
    IN LPCWSTR lpAppName,
    IN LPCWSTR lpKeyName,
    IN INT nDefault
    );
#ifdef UNICODE
#define GetProfileInt  GetProfileIntW
#else
#define GetProfileInt  GetProfileIntA
#endif 

WINBASEAPI
DWORD
WINAPI
GetProfileStringA(
    IN LPCSTR lpAppName,
    IN LPCSTR lpKeyName,
    IN LPCSTR lpDefault,
    OUT LPSTR lpReturnedString,
    IN DWORD nSize
    );
WINBASEAPI
DWORD
WINAPI
GetProfileStringW(
    IN LPCWSTR lpAppName,
    IN LPCWSTR lpKeyName,
    IN LPCWSTR lpDefault,
    OUT LPWSTR lpReturnedString,
    IN DWORD nSize
    );
#ifdef UNICODE
#define GetProfileString  GetProfileStringW
#else
#define GetProfileString  GetProfileStringA
#endif 

WINBASEAPI
BOOL
WINAPI
WriteProfileStringA(
    IN LPCSTR lpAppName,
    IN LPCSTR lpKeyName,
    IN LPCSTR lpString
    );
WINBASEAPI
BOOL
WINAPI
WriteProfileStringW(
    IN LPCWSTR lpAppName,
    IN LPCWSTR lpKeyName,
    IN LPCWSTR lpString
    );
#ifdef UNICODE
#define WriteProfileString  WriteProfileStringW
#else
#define WriteProfileString  WriteProfileStringA
#endif 

WINBASEAPI
DWORD
WINAPI
GetProfileSectionA(
    IN LPCSTR lpAppName,
    OUT LPSTR lpReturnedString,
    IN DWORD nSize
    );
WINBASEAPI
DWORD
WINAPI
GetProfileSectionW(
    IN LPCWSTR lpAppName,
    OUT LPWSTR lpReturnedString,
    IN DWORD nSize
    );
#ifdef UNICODE
#define GetProfileSection  GetProfileSectionW
#else
#define GetProfileSection  GetProfileSectionA
#endif 

WINBASEAPI
BOOL
WINAPI
WriteProfileSectionA(
    IN LPCSTR lpAppName,
    IN LPCSTR lpString
    );
WINBASEAPI
BOOL
WINAPI
WriteProfileSectionW(
    IN LPCWSTR lpAppName,
    IN LPCWSTR lpString
    );
#ifdef UNICODE
#define WriteProfileSection  WriteProfileSectionW
#else
#define WriteProfileSection  WriteProfileSectionA
#endif 

WINBASEAPI
UINT
WINAPI
GetPrivateProfileIntA(
    IN LPCSTR lpAppName,
    IN LPCSTR lpKeyName,
    IN INT nDefault,
    IN LPCSTR lpFileName
    );
WINBASEAPI
UINT
WINAPI
GetPrivateProfileIntW(
    IN LPCWSTR lpAppName,
    IN LPCWSTR lpKeyName,
    IN INT nDefault,
    IN LPCWSTR lpFileName
    );
#ifdef UNICODE
#define GetPrivateProfileInt  GetPrivateProfileIntW
#else
#define GetPrivateProfileInt  GetPrivateProfileIntA
#endif 

WINBASEAPI
DWORD
WINAPI
GetPrivateProfileStringA(
    IN LPCSTR lpAppName,
    IN LPCSTR lpKeyName,
    IN LPCSTR lpDefault,
    OUT LPSTR lpReturnedString,
    IN DWORD nSize,
    IN LPCSTR lpFileName
    );
WINBASEAPI
DWORD
WINAPI
GetPrivateProfileStringW(
    IN LPCWSTR lpAppName,
    IN LPCWSTR lpKeyName,
    IN LPCWSTR lpDefault,
    OUT LPWSTR lpReturnedString,
    IN DWORD nSize,
    IN LPCWSTR lpFileName
    );
#ifdef UNICODE
#define GetPrivateProfileString  GetPrivateProfileStringW
#else
#define GetPrivateProfileString  GetPrivateProfileStringA
#endif 

WINBASEAPI
BOOL
WINAPI
WritePrivateProfileStringA(
    IN LPCSTR lpAppName,
    IN LPCSTR lpKeyName,
    IN LPCSTR lpString,
    IN LPCSTR lpFileName
    );
WINBASEAPI
BOOL
WINAPI
WritePrivateProfileStringW(
    IN LPCWSTR lpAppName,
    IN LPCWSTR lpKeyName,
    IN LPCWSTR lpString,
    IN LPCWSTR lpFileName
    );
#ifdef UNICODE
#define WritePrivateProfileString  WritePrivateProfileStringW
#else
#define WritePrivateProfileString  WritePrivateProfileStringA
#endif 

WINBASEAPI
DWORD
WINAPI
GetPrivateProfileSectionA(
    IN LPCSTR lpAppName,
    OUT LPSTR lpReturnedString,
    IN DWORD nSize,
    IN LPCSTR lpFileName
    );
WINBASEAPI
DWORD
WINAPI
GetPrivateProfileSectionW(
    IN LPCWSTR lpAppName,
    OUT LPWSTR lpReturnedString,
    IN DWORD nSize,
    IN LPCWSTR lpFileName
    );
#ifdef UNICODE
#define GetPrivateProfileSection  GetPrivateProfileSectionW
#else
#define GetPrivateProfileSection  GetPrivateProfileSectionA
#endif 

WINBASEAPI
BOOL
WINAPI
WritePrivateProfileSectionA(
    IN LPCSTR lpAppName,
    IN LPCSTR lpString,
    IN LPCSTR lpFileName
    );
WINBASEAPI
BOOL
WINAPI
WritePrivateProfileSectionW(
    IN LPCWSTR lpAppName,
    IN LPCWSTR lpString,
    IN LPCWSTR lpFileName
    );
#ifdef UNICODE
#define WritePrivateProfileSection  WritePrivateProfileSectionW
#else
#define WritePrivateProfileSection  WritePrivateProfileSectionA
#endif 


WINBASEAPI
DWORD
WINAPI
GetPrivateProfileSectionNamesA(
    OUT LPSTR lpszReturnBuffer,
    IN DWORD nSize,
    IN LPCSTR lpFileName
    );
WINBASEAPI
DWORD
WINAPI
GetPrivateProfileSectionNamesW(
    OUT LPWSTR lpszReturnBuffer,
    IN DWORD nSize,
    IN LPCWSTR lpFileName
    );
#ifdef UNICODE
#define GetPrivateProfileSectionNames  GetPrivateProfileSectionNamesW
#else
#define GetPrivateProfileSectionNames  GetPrivateProfileSectionNamesA
#endif 

WINBASEAPI
BOOL
WINAPI
GetPrivateProfileStructA(
    IN LPCSTR lpszSection,
    IN LPCSTR lpszKey,
    OUT LPVOID   lpStruct,
    IN UINT     uSizeStruct,
    IN LPCSTR szFile
    );
WINBASEAPI
BOOL
WINAPI
GetPrivateProfileStructW(
    IN LPCWSTR lpszSection,
    IN LPCWSTR lpszKey,
    OUT LPVOID   lpStruct,
    IN UINT     uSizeStruct,
    IN LPCWSTR szFile
    );
#ifdef UNICODE
#define GetPrivateProfileStruct  GetPrivateProfileStructW
#else
#define GetPrivateProfileStruct  GetPrivateProfileStructA
#endif 

WINBASEAPI
BOOL
WINAPI
WritePrivateProfileStructA(
    IN LPCSTR lpszSection,
    IN LPCSTR lpszKey,
    IN LPVOID   lpStruct,
    IN UINT     uSizeStruct,
    IN LPCSTR szFile
    );
WINBASEAPI
BOOL
WINAPI
WritePrivateProfileStructW(
    IN LPCWSTR lpszSection,
    IN LPCWSTR lpszKey,
    IN LPVOID   lpStruct,
    IN UINT     uSizeStruct,
    IN LPCWSTR szFile
    );
#ifdef UNICODE
#define WritePrivateProfileStruct  WritePrivateProfileStructW
#else
#define WritePrivateProfileStruct  WritePrivateProfileStructA
#endif 


WINBASEAPI
UINT
WINAPI
GetDriveTypeA(
    IN LPCSTR lpRootPathName
    );
WINBASEAPI
UINT
WINAPI
GetDriveTypeW(
    IN LPCWSTR lpRootPathName
    );
#ifdef UNICODE
#define GetDriveType  GetDriveTypeW
#else
#define GetDriveType  GetDriveTypeA
#endif 

WINBASEAPI
UINT
WINAPI
GetSystemDirectoryA(
    OUT LPSTR lpBuffer,
    IN UINT uSize
    );
WINBASEAPI
UINT
WINAPI
GetSystemDirectoryW(
    OUT LPWSTR lpBuffer,
    IN UINT uSize
    );
#ifdef UNICODE
#define GetSystemDirectory  GetSystemDirectoryW
#else
#define GetSystemDirectory  GetSystemDirectoryA
#endif 

WINBASEAPI
DWORD
WINAPI
GetTempPathA(
    IN DWORD nBufferLength,
    OUT LPSTR lpBuffer
    );
WINBASEAPI
DWORD
WINAPI
GetTempPathW(
    IN DWORD nBufferLength,
    OUT LPWSTR lpBuffer
    );
#ifdef UNICODE
#define GetTempPath  GetTempPathW
#else
#define GetTempPath  GetTempPathA
#endif 

WINBASEAPI
UINT
WINAPI
GetTempFileNameA(
    IN LPCSTR lpPathName,
    IN LPCSTR lpPrefixString,
    IN UINT uUnique,
    OUT LPSTR lpTempFileName
    );
WINBASEAPI
UINT
WINAPI
GetTempFileNameW(
    IN LPCWSTR lpPathName,
    IN LPCWSTR lpPrefixString,
    IN UINT uUnique,
    OUT LPWSTR lpTempFileName
    );
#ifdef UNICODE
#define GetTempFileName  GetTempFileNameW
#else
#define GetTempFileName  GetTempFileNameA
#endif 

WINBASEAPI
UINT
WINAPI
GetWindowsDirectoryA(
    OUT LPSTR lpBuffer,
    IN UINT uSize
    );
WINBASEAPI
UINT
WINAPI
GetWindowsDirectoryW(
    OUT LPWSTR lpBuffer,
    IN UINT uSize
    );
#ifdef UNICODE
#define GetWindowsDirectory  GetWindowsDirectoryW
#else
#define GetWindowsDirectory  GetWindowsDirectoryA
#endif 

WINBASEAPI
UINT
WINAPI
GetSystemWindowsDirectoryA(
    OUT LPSTR lpBuffer,
    IN UINT uSize
    );
WINBASEAPI
UINT
WINAPI
GetSystemWindowsDirectoryW(
    OUT LPWSTR lpBuffer,
    IN UINT uSize
    );
#ifdef UNICODE
#define GetSystemWindowsDirectory  GetSystemWindowsDirectoryW
#else
#define GetSystemWindowsDirectory  GetSystemWindowsDirectoryA
#endif 

#if !defined(RC_INVOKED) 
#if _WIN32_WINNT >= 0x0501 || defined(WINBASE_DECLARE_GET_SYSTEM_WOW64_DIRECTORY)

WINBASEAPI
UINT
WINAPI
GetSystemWow64DirectoryA(
    OUT LPSTR lpBuffer,
    IN UINT uSize
    );
WINBASEAPI
UINT
WINAPI
GetSystemWow64DirectoryW(
    OUT LPWSTR lpBuffer,
    IN UINT uSize
    );
#ifdef UNICODE
#define GetSystemWow64Directory  GetSystemWow64DirectoryW
#else
#define GetSystemWow64Directory  GetSystemWow64DirectoryA
#endif 

//

//
typedef UINT (WINAPI* PGET_SYSTEM_WOW64_DIRECTORY_A)(OUT  LPSTR lpBuffer, UINT uSize);
typedef UINT (WINAPI* PGET_SYSTEM_WOW64_DIRECTORY_W)(OUT LPWSTR lpBuffer, UINT uSize);

//



//
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A      "GetSystemWow64DirectoryA"
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W     L"GetSystemWow64DirectoryA"
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T TEXT("GetSystemWow64DirectoryA")
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A      "GetSystemWow64DirectoryW"
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W     L"GetSystemWow64DirectoryW"
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T TEXT("GetSystemWow64DirectoryW")

#ifdef UNICODE
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T
#else
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T
#endif

#endif 
#endif

WINBASEAPI
BOOL
WINAPI
SetCurrentDirectoryA(
    IN LPCSTR lpPathName
    );
WINBASEAPI
BOOL
WINAPI
SetCurrentDirectoryW(
    IN LPCWSTR lpPathName
    );
#ifdef UNICODE
#define SetCurrentDirectory  SetCurrentDirectoryW
#else
#define SetCurrentDirectory  SetCurrentDirectoryA
#endif 

WINBASEAPI
DWORD
WINAPI
GetCurrentDirectoryA(
    IN DWORD nBufferLength,
    OUT LPSTR lpBuffer
    );
WINBASEAPI
DWORD
WINAPI
GetCurrentDirectoryW(
    IN DWORD nBufferLength,
    OUT LPWSTR lpBuffer
    );
#ifdef UNICODE
#define GetCurrentDirectory  GetCurrentDirectoryW
#else
#define GetCurrentDirectory  GetCurrentDirectoryA
#endif 

#if _WIN32_WINNT >= 0x0502

WINBASEAPI
BOOL
WINAPI
SetDllDirectoryA(
    IN LPCSTR lpPathName
    );
WINBASEAPI
BOOL
WINAPI
SetDllDirectoryW(
    IN LPCWSTR lpPathName
    );
#ifdef UNICODE
#define SetDllDirectory  SetDllDirectoryW
#else
#define SetDllDirectory  SetDllDirectoryA
#endif 

WINBASEAPI
DWORD
WINAPI
GetDllDirectoryA(
    IN DWORD nBufferLength,
    OUT LPSTR lpBuffer
    );
WINBASEAPI
DWORD
WINAPI
GetDllDirectoryW(
    IN DWORD nBufferLength,
    OUT LPWSTR lpBuffer
    );
#ifdef UNICODE
#define GetDllDirectory  GetDllDirectoryW
#else
#define GetDllDirectory  GetDllDirectoryA
#endif 

#endif 

WINBASEAPI
BOOL
WINAPI
GetDiskFreeSpaceA(
    IN LPCSTR lpRootPathName,
    OUT LPDWORD lpSectorsPerCluster,
    OUT LPDWORD lpBytesPerSector,
    OUT LPDWORD lpNumberOfFreeClusters,
    OUT LPDWORD lpTotalNumberOfClusters
    );
WINBASEAPI
BOOL
WINAPI
GetDiskFreeSpaceW(
    IN LPCWSTR lpRootPathName,
    OUT LPDWORD lpSectorsPerCluster,
    OUT LPDWORD lpBytesPerSector,
    OUT LPDWORD lpNumberOfFreeClusters,
    OUT LPDWORD lpTotalNumberOfClusters
    );
#ifdef UNICODE
#define GetDiskFreeSpace  GetDiskFreeSpaceW
#else
#define GetDiskFreeSpace  GetDiskFreeSpaceA
#endif 

WINBASEAPI
BOOL
WINAPI
GetDiskFreeSpaceExA(
    IN LPCSTR lpDirectoryName,
    OUT PULARGE_INTEGER lpFreeBytesAvailableToCaller,
    OUT PULARGE_INTEGER lpTotalNumberOfBytes,
    OUT PULARGE_INTEGER lpTotalNumberOfFreeBytes
    );
WINBASEAPI
BOOL
WINAPI
GetDiskFreeSpaceExW(
    IN LPCWSTR lpDirectoryName,
    OUT PULARGE_INTEGER lpFreeBytesAvailableToCaller,
    OUT PULARGE_INTEGER lpTotalNumberOfBytes,
    OUT PULARGE_INTEGER lpTotalNumberOfFreeBytes
    );
#ifdef UNICODE
#define GetDiskFreeSpaceEx  GetDiskFreeSpaceExW
#else
#define GetDiskFreeSpaceEx  GetDiskFreeSpaceExA
#endif 

WINBASEAPI
BOOL
WINAPI
CreateDirectoryA(
    IN LPCSTR lpPathName,
    IN LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
WINBASEAPI
BOOL
WINAPI
CreateDirectoryW(
    IN LPCWSTR lpPathName,
    IN LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
#ifdef UNICODE
#define CreateDirectory  CreateDirectoryW
#else
#define CreateDirectory  CreateDirectoryA
#endif 

WINBASEAPI
BOOL
WINAPI
CreateDirectoryExA(
    IN LPCSTR lpTemplateDirectory,
    IN LPCSTR lpNewDirectory,
    IN LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
WINBASEAPI
BOOL
WINAPI
CreateDirectoryExW(
    IN LPCWSTR lpTemplateDirectory,
    IN LPCWSTR lpNewDirectory,
    IN LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
#ifdef UNICODE
#define CreateDirectoryEx  CreateDirectoryExW
#else
#define CreateDirectoryEx  CreateDirectoryExA
#endif 

WINBASEAPI
BOOL
WINAPI
RemoveDirectoryA(
    IN LPCSTR lpPathName
    );
WINBASEAPI
BOOL
WINAPI
RemoveDirectoryW(
    IN LPCWSTR lpPathName
    );
#ifdef UNICODE
#define RemoveDirectory  RemoveDirectoryW
#else
#define RemoveDirectory  RemoveDirectoryA
#endif 

WINBASEAPI
DWORD
WINAPI
GetFullPathNameA(
    IN LPCSTR lpFileName,
    IN DWORD nBufferLength,
    OUT LPSTR lpBuffer,
    OUT LPSTR *lpFilePart
    );
WINBASEAPI
DWORD
WINAPI
GetFullPathNameW(
    IN LPCWSTR lpFileName,
    IN DWORD nBufferLength,
    OUT LPWSTR lpBuffer,
    OUT LPWSTR *lpFilePart
    );
#ifdef UNICODE
#define GetFullPathName  GetFullPathNameW
#else
#define GetFullPathName  GetFullPathNameA
#endif 


#define DDD_RAW_TARGET_PATH         0x00000001
#define DDD_REMOVE_DEFINITION       0x00000002
#define DDD_EXACT_MATCH_ON_REMOVE   0x00000004
#define DDD_NO_BROADCAST_SYSTEM     0x00000008
#define DDD_LUID_BROADCAST_DRIVE    0x00000010

WINBASEAPI
BOOL
WINAPI
DefineDosDeviceA(
    IN DWORD dwFlags,
    IN LPCSTR lpDeviceName,
    IN LPCSTR lpTargetPath
    );
WINBASEAPI
BOOL
WINAPI
DefineDosDeviceW(
    IN DWORD dwFlags,
    IN LPCWSTR lpDeviceName,
    IN LPCWSTR lpTargetPath
    );
#ifdef UNICODE
#define DefineDosDevice  DefineDosDeviceW
#else
#define DefineDosDevice  DefineDosDeviceA
#endif 

WINBASEAPI
DWORD
WINAPI
QueryDosDeviceA(
    IN LPCSTR lpDeviceName,
    OUT LPSTR lpTargetPath,
    IN DWORD ucchMax
    );
WINBASEAPI
DWORD
WINAPI
QueryDosDeviceW(
    IN LPCWSTR lpDeviceName,
    OUT LPWSTR lpTargetPath,
    IN DWORD ucchMax
    );
#ifdef UNICODE
#define QueryDosDevice  QueryDosDeviceW
#else
#define QueryDosDevice  QueryDosDeviceA
#endif 

#define EXPAND_LOCAL_DRIVES

WINBASEAPI
HANDLE
WINAPI
CreateFileA(
    IN LPCSTR lpFileName,
    IN DWORD dwDesiredAccess,
    IN DWORD dwShareMode,
    IN LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    IN DWORD dwCreationDisposition,
    IN DWORD dwFlagsAndAttributes,
    IN HANDLE hTemplateFile
    );
WINBASEAPI
HANDLE
WINAPI
CreateFileW(
    IN LPCWSTR lpFileName,
    IN DWORD dwDesiredAccess,
    IN DWORD dwShareMode,
    IN LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    IN DWORD dwCreationDisposition,
    IN DWORD dwFlagsAndAttributes,
    IN HANDLE hTemplateFile
    );
#ifdef UNICODE
#define CreateFile  CreateFileW
#else
#define CreateFile  CreateFileA
#endif 

#if _WIN32_WINNT >= 0x0502

WINBASEAPI
HANDLE
WINAPI
ReOpenFile(
    HANDLE  hOriginalFile,
    DWORD   dwDesiredAccess,
    DWORD   dwShareMode,
    DWORD   dwFlagsAndAttributes
    );
    
#endif 

WINBASEAPI
BOOL
WINAPI
SetFileAttributesA(
    IN LPCSTR lpFileName,
    IN DWORD dwFileAttributes
    );
WINBASEAPI
BOOL
WINAPI
SetFileAttributesW(
    IN LPCWSTR lpFileName,
    IN DWORD dwFileAttributes
    );
#ifdef UNICODE
#define SetFileAttributes  SetFileAttributesW
#else
#define SetFileAttributes  SetFileAttributesA
#endif 

WINBASEAPI
DWORD
WINAPI
GetFileAttributesA(
    IN LPCSTR lpFileName
    );
WINBASEAPI
DWORD
WINAPI
GetFileAttributesW(
    IN LPCWSTR lpFileName
    );
#ifdef UNICODE
#define GetFileAttributes  GetFileAttributesW
#else
#define GetFileAttributes  GetFileAttributesA
#endif 

typedef enum _GET_FILEEX_INFO_LEVELS {
    GetFileExInfoStandard,
    GetFileExMaxInfoLevel
} GET_FILEEX_INFO_LEVELS;

WINBASEAPI
BOOL
WINAPI
GetFileAttributesExA(
    IN LPCSTR lpFileName,
    IN GET_FILEEX_INFO_LEVELS fInfoLevelId,
    OUT LPVOID lpFileInformation
    );
WINBASEAPI
BOOL
WINAPI
GetFileAttributesExW(
    IN LPCWSTR lpFileName,
    IN GET_FILEEX_INFO_LEVELS fInfoLevelId,
    OUT LPVOID lpFileInformation
    );
#ifdef UNICODE
#define GetFileAttributesEx  GetFileAttributesExW
#else
#define GetFileAttributesEx  GetFileAttributesExA
#endif 

WINBASEAPI
DWORD
WINAPI
GetCompressedFileSizeA(
    IN LPCSTR lpFileName,
    OUT LPDWORD lpFileSizeHigh
    );
WINBASEAPI
DWORD
WINAPI
GetCompressedFileSizeW(
    IN LPCWSTR lpFileName,
    OUT LPDWORD lpFileSizeHigh
    );
#ifdef UNICODE
#define GetCompressedFileSize  GetCompressedFileSizeW
#else
#define GetCompressedFileSize  GetCompressedFileSizeA
#endif 

WINBASEAPI
BOOL
WINAPI
DeleteFileA(
    IN LPCSTR lpFileName
    );
WINBASEAPI
BOOL
WINAPI
DeleteFileW(
    IN LPCWSTR lpFileName
    );
#ifdef UNICODE
#define DeleteFile  DeleteFileW
#else
#define DeleteFile  DeleteFileA
#endif 

#if _WIN32_WINNT >= 0x0501

WINBASEAPI
BOOL
WINAPI
CheckNameLegalDOS8Dot3A(
    IN LPCSTR lpName,
    OUT LPSTR lpOemName OPTIONAL,
    IN DWORD OemNameSize OPTIONAL,
    OUT PBOOL pbNameContainsSpaces OPTIONAL,
    OUT PBOOL pbNameLegal
    );
WINBASEAPI
BOOL
WINAPI
CheckNameLegalDOS8Dot3W(
    IN LPCWSTR lpName,
    OUT LPSTR lpOemName OPTIONAL,
    IN DWORD OemNameSize OPTIONAL,
    OUT PBOOL pbNameContainsSpaces OPTIONAL,
    OUT PBOOL pbNameLegal
    );
#ifdef UNICODE
#define CheckNameLegalDOS8Dot3  CheckNameLegalDOS8Dot3W
#else
#define CheckNameLegalDOS8Dot3  CheckNameLegalDOS8Dot3A
#endif 

#endif 

#if(_WIN32_WINNT >= 0x0400)
typedef enum _FINDEX_INFO_LEVELS {
    FindExInfoStandard,
    FindExInfoMaxInfoLevel
} FINDEX_INFO_LEVELS;

typedef enum _FINDEX_SEARCH_OPS {
    FindExSearchNameMatch,
    FindExSearchLimitToDirectories,
    FindExSearchLimitToDevices,
    FindExSearchMaxSearchOp
} FINDEX_SEARCH_OPS;

#define FIND_FIRST_EX_CASE_SENSITIVE   0x00000001

WINBASEAPI
HANDLE
WINAPI
FindFirstFileExA(
    IN LPCSTR lpFileName,
    IN FINDEX_INFO_LEVELS fInfoLevelId,
    OUT LPVOID lpFindFileData,
    IN FINDEX_SEARCH_OPS fSearchOp,
    IN LPVOID lpSearchFilter,
    IN DWORD dwAdditionalFlags
    );
WINBASEAPI
HANDLE
WINAPI
FindFirstFileExW(
    IN LPCWSTR lpFileName,
    IN FINDEX_INFO_LEVELS fInfoLevelId,
    OUT LPVOID lpFindFileData,
    IN FINDEX_SEARCH_OPS fSearchOp,
    IN LPVOID lpSearchFilter,
    IN DWORD dwAdditionalFlags
    );
#ifdef UNICODE
#define FindFirstFileEx  FindFirstFileExW
#else
#define FindFirstFileEx  FindFirstFileExA
#endif 
#endif 

WINBASEAPI
HANDLE
WINAPI
FindFirstFileA(
    IN LPCSTR lpFileName,
    OUT LPWIN32_FIND_DATAA lpFindFileData
    );
WINBASEAPI
HANDLE
WINAPI
FindFirstFileW(
    IN LPCWSTR lpFileName,
    OUT LPWIN32_FIND_DATAW lpFindFileData
    );
#ifdef UNICODE
#define FindFirstFile  FindFirstFileW
#else
#define FindFirstFile  FindFirstFileA
#endif 

WINBASEAPI
BOOL
WINAPI
FindNextFileA(
    IN HANDLE hFindFile,
    OUT LPWIN32_FIND_DATAA lpFindFileData
    );
WINBASEAPI
BOOL
WINAPI
FindNextFileW(
    IN HANDLE hFindFile,
    OUT LPWIN32_FIND_DATAW lpFindFileData
    );
#ifdef UNICODE
#define FindNextFile  FindNextFileW
#else
#define FindNextFile  FindNextFileA
#endif 


WINBASEAPI
DWORD
WINAPI
SearchPathA(
    IN LPCSTR lpPath,
    IN LPCSTR lpFileName,
    IN LPCSTR lpExtension,
    IN DWORD nBufferLength,
    OUT LPSTR lpBuffer,
    OUT LPSTR *lpFilePart
    );
WINBASEAPI
DWORD
WINAPI
SearchPathW(
    IN LPCWSTR lpPath,
    IN LPCWSTR lpFileName,
    IN LPCWSTR lpExtension,
    IN DWORD nBufferLength,
    OUT LPWSTR lpBuffer,
    OUT LPWSTR *lpFilePart
    );
#ifdef UNICODE
#define SearchPath  SearchPathW
#else
#define SearchPath  SearchPathA
#endif 

WINBASEAPI
BOOL
WINAPI
CopyFileA(
    IN LPCSTR lpExistingFileName,
    IN LPCSTR lpNewFileName,
    IN BOOL bFailIfExists
    );
WINBASEAPI
BOOL
WINAPI
CopyFileW(
    IN LPCWSTR lpExistingFileName,
    IN LPCWSTR lpNewFileName,
    IN BOOL bFailIfExists
    );
#ifdef UNICODE
#define CopyFile  CopyFileW
#else
#define CopyFile  CopyFileA
#endif 

#if(_WIN32_WINNT >= 0x0400)
typedef
DWORD
(WINAPI *LPPROGRESS_ROUTINE)(
    LARGE_INTEGER TotalFileSize,
    LARGE_INTEGER TotalBytesTransferred,
    LARGE_INTEGER StreamSize,
    LARGE_INTEGER StreamBytesTransferred,
    DWORD dwStreamNumber,
    DWORD dwCallbackReason,
    HANDLE hSourceFile,
    HANDLE hDestinationFile,
    LPVOID lpData OPTIONAL
    );

WINBASEAPI
BOOL
WINAPI
CopyFileExA(
    IN LPCSTR lpExistingFileName,
    IN LPCSTR lpNewFileName,
    IN LPPROGRESS_ROUTINE lpProgressRoutine OPTIONAL,
    IN LPVOID lpData OPTIONAL,
    IN LPBOOL pbCancel OPTIONAL,
    IN DWORD dwCopyFlags
    );
WINBASEAPI
BOOL
WINAPI
CopyFileExW(
    IN LPCWSTR lpExistingFileName,
    IN LPCWSTR lpNewFileName,
    IN LPPROGRESS_ROUTINE lpProgressRoutine OPTIONAL,
    IN LPVOID lpData OPTIONAL,
    IN LPBOOL pbCancel OPTIONAL,
    IN DWORD dwCopyFlags
    );
#ifdef UNICODE
#define CopyFileEx  CopyFileExW
#else
#define CopyFileEx  CopyFileExA
#endif 
#endif 

WINBASEAPI
BOOL
WINAPI
MoveFileA(
    IN LPCSTR lpExistingFileName,
    IN LPCSTR lpNewFileName
    );
WINBASEAPI
BOOL
WINAPI
MoveFileW(
    IN LPCWSTR lpExistingFileName,
    IN LPCWSTR lpNewFileName
    );
#ifdef UNICODE
#define MoveFile  MoveFileW
#else
#define MoveFile  MoveFileA
#endif 

WINBASEAPI
BOOL
WINAPI
MoveFileExA(
    IN LPCSTR lpExistingFileName,
    IN LPCSTR lpNewFileName,
    IN DWORD dwFlags
    );
WINBASEAPI
BOOL
WINAPI
MoveFileExW(
    IN LPCWSTR lpExistingFileName,
    IN LPCWSTR lpNewFileName,
    IN DWORD dwFlags
    );
#ifdef UNICODE
#define MoveFileEx  MoveFileExW
#else
#define MoveFileEx  MoveFileExA
#endif 

#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI
BOOL
WINAPI
MoveFileWithProgressA(
    IN LPCSTR lpExistingFileName,
    IN LPCSTR lpNewFileName,
    IN LPPROGRESS_ROUTINE lpProgressRoutine OPTIONAL,
    IN LPVOID lpData OPTIONAL,
    IN DWORD dwFlags
    );
WINBASEAPI
BOOL
WINAPI
MoveFileWithProgressW(
    IN LPCWSTR lpExistingFileName,
    IN LPCWSTR lpNewFileName,
    IN LPPROGRESS_ROUTINE lpProgressRoutine OPTIONAL,
    IN LPVOID lpData OPTIONAL,
    IN DWORD dwFlags
    );
#ifdef UNICODE
#define MoveFileWithProgress  MoveFileWithProgressW
#else
#define MoveFileWithProgress  MoveFileWithProgressA
#endif 
#endif 

#define MOVEFILE_REPLACE_EXISTING       0x00000001
#define MOVEFILE_COPY_ALLOWED           0x00000002
#define MOVEFILE_DELAY_UNTIL_REBOOT     0x00000004
#define MOVEFILE_WRITE_THROUGH          0x00000008
#if (_WIN32_WINNT >= 0x0500)
#define MOVEFILE_CREATE_HARDLINK        0x00000010
#define MOVEFILE_FAIL_IF_NOT_TRACKABLE  0x00000020
#endif 



#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI
BOOL
WINAPI
ReplaceFileA(
    LPCSTR  lpReplacedFileName,
    LPCSTR  lpReplacementFileName,
    LPCSTR  lpBackupFileName,
    DWORD   dwReplaceFlags,
    LPVOID  lpExclude,
    LPVOID  lpReserved
    );
WINBASEAPI
BOOL
WINAPI
ReplaceFileW(
    LPCWSTR lpReplacedFileName,
    LPCWSTR lpReplacementFileName,
    LPCWSTR lpBackupFileName,
    DWORD   dwReplaceFlags,
    LPVOID  lpExclude,
    LPVOID  lpReserved
    );
#ifdef UNICODE
#define ReplaceFile  ReplaceFileW
#else
#define ReplaceFile  ReplaceFileA
#endif 
#endif 


#if (_WIN32_WINNT >= 0x0500)
//

//

WINBASEAPI
BOOL
WINAPI
CreateHardLinkA(
    IN LPCSTR lpFileName,
    IN LPCSTR lpExistingFileName,
    IN LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
WINBASEAPI
BOOL
WINAPI
CreateHardLinkW(
    IN LPCWSTR lpFileName,
    IN LPCWSTR lpExistingFileName,
    IN LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
#ifdef UNICODE
#define CreateHardLink  CreateHardLinkW
#else
#define CreateHardLink  CreateHardLinkA
#endif 

#endif 


#if (_WIN32_WINNT >= 0x0501)

//

//

typedef enum _STREAM_INFO_LEVELS {
    
    FindStreamInfoStandard,
    FindStreamInfoMaxInfoLevel

} STREAM_INFO_LEVELS;

typedef struct _WIN32_FIND_STREAM_DATA {
    
    LARGE_INTEGER StreamSize;
    WCHAR cStreamName[ MAX_PATH + 36 ]; 

} WIN32_FIND_STREAM_DATA, *PWIN32_FIND_STREAM_DATA; 


HANDLE
WINAPI
FindFirstStreamW(
    LPCWSTR lpFileName,
    STREAM_INFO_LEVELS InfoLevel,
    LPVOID lpFindStreamData,
    DWORD dwFlags
    );

BOOL
APIENTRY
FindNextStreamW(
    HANDLE hFindStream,
    LPVOID lpFindStreamData
    );

#endif 



WINBASEAPI
HANDLE
WINAPI
CreateNamedPipeA(
    IN LPCSTR lpName,
    IN DWORD dwOpenMode,
    IN DWORD dwPipeMode,
    IN DWORD nMaxInstances,
    IN DWORD nOutBufferSize,
    IN DWORD nInBufferSize,
    IN DWORD nDefaultTimeOut,
    IN LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
WINBASEAPI
HANDLE
WINAPI
CreateNamedPipeW(
    IN LPCWSTR lpName,
    IN DWORD dwOpenMode,
    IN DWORD dwPipeMode,
    IN DWORD nMaxInstances,
    IN DWORD nOutBufferSize,
    IN DWORD nInBufferSize,
    IN DWORD nDefaultTimeOut,
    IN LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
#ifdef UNICODE
#define CreateNamedPipe  CreateNamedPipeW
#else
#define CreateNamedPipe  CreateNamedPipeA
#endif 

WINBASEAPI
BOOL
WINAPI
GetNamedPipeHandleStateA(
    IN HANDLE hNamedPipe,
    OUT LPDWORD lpState,
    OUT LPDWORD lpCurInstances,
    OUT LPDWORD lpMaxCollectionCount,
    OUT LPDWORD lpCollectDataTimeout,
    OUT LPSTR lpUserName,
    IN DWORD nMaxUserNameSize
    );
WINBASEAPI
BOOL
WINAPI
GetNamedPipeHandleStateW(
    IN HANDLE hNamedPipe,
    OUT LPDWORD lpState,
    OUT LPDWORD lpCurInstances,
    OUT LPDWORD lpMaxCollectionCount,
    OUT LPDWORD lpCollectDataTimeout,
    OUT LPWSTR lpUserName,
    IN DWORD nMaxUserNameSize
    );
#ifdef UNICODE
#define GetNamedPipeHandleState  GetNamedPipeHandleStateW
#else
#define GetNamedPipeHandleState  GetNamedPipeHandleStateA
#endif 

WINBASEAPI
BOOL
WINAPI
CallNamedPipeA(
    IN LPCSTR lpNamedPipeName,
    IN LPVOID lpInBuffer,
    IN DWORD nInBufferSize,
    OUT LPVOID lpOutBuffer,
    IN DWORD nOutBufferSize,
    OUT LPDWORD lpBytesRead,
    IN DWORD nTimeOut
    );
WINBASEAPI
BOOL
WINAPI
CallNamedPipeW(
    IN LPCWSTR lpNamedPipeName,
    IN LPVOID lpInBuffer,
    IN DWORD nInBufferSize,
    OUT LPVOID lpOutBuffer,
    IN DWORD nOutBufferSize,
    OUT LPDWORD lpBytesRead,
    IN DWORD nTimeOut
    );
#ifdef UNICODE
#define CallNamedPipe  CallNamedPipeW
#else
#define CallNamedPipe  CallNamedPipeA
#endif 

WINBASEAPI
BOOL
WINAPI
WaitNamedPipeA(
    IN LPCSTR lpNamedPipeName,
    IN DWORD nTimeOut
    );
WINBASEAPI
BOOL
WINAPI
WaitNamedPipeW(
    IN LPCWSTR lpNamedPipeName,
    IN DWORD nTimeOut
    );
#ifdef UNICODE
#define WaitNamedPipe  WaitNamedPipeW
#else
#define WaitNamedPipe  WaitNamedPipeA
#endif 

WINBASEAPI
BOOL
WINAPI
SetVolumeLabelA(
    IN LPCSTR lpRootPathName,
    IN LPCSTR lpVolumeName
    );
WINBASEAPI
BOOL
WINAPI
SetVolumeLabelW(
    IN LPCWSTR lpRootPathName,
    IN LPCWSTR lpVolumeName
    );
#ifdef UNICODE
#define SetVolumeLabel  SetVolumeLabelW
#else
#define SetVolumeLabel  SetVolumeLabelA
#endif 

WINBASEAPI
VOID
WINAPI
SetFileApisToOEM( VOID );

WINBASEAPI
VOID
WINAPI
SetFileApisToANSI( VOID );

WINBASEAPI
BOOL
WINAPI
AreFileApisANSI( VOID );

WINBASEAPI
BOOL
WINAPI
GetVolumeInformationA(
    IN LPCSTR lpRootPathName,
    OUT LPSTR lpVolumeNameBuffer,
    IN DWORD nVolumeNameSize,
    OUT LPDWORD lpVolumeSerialNumber,
    OUT LPDWORD lpMaximumComponentLength,
    OUT LPDWORD lpFileSystemFlags,
    OUT LPSTR lpFileSystemNameBuffer,
    IN DWORD nFileSystemNameSize
    );
WINBASEAPI
BOOL
WINAPI
GetVolumeInformationW(
    IN LPCWSTR lpRootPathName,
    OUT LPWSTR lpVolumeNameBuffer,
    IN DWORD nVolumeNameSize,
    OUT LPDWORD lpVolumeSerialNumber,
    OUT LPDWORD lpMaximumComponentLength,
    OUT LPDWORD lpFileSystemFlags,
    OUT LPWSTR lpFileSystemNameBuffer,
    IN DWORD nFileSystemNameSize
    );
#ifdef UNICODE
#define GetVolumeInformation  GetVolumeInformationW
#else
#define GetVolumeInformation  GetVolumeInformationA
#endif 

WINBASEAPI
BOOL
WINAPI
CancelIo(
    IN HANDLE hFile
    );

//

//

WINADVAPI
BOOL
WINAPI
ClearEventLogA (
    IN HANDLE hEventLog,
    IN LPCSTR lpBackupFileName
    );
WINADVAPI
BOOL
WINAPI
ClearEventLogW (
    IN HANDLE hEventLog,
    IN LPCWSTR lpBackupFileName
    );
#ifdef UNICODE
#define ClearEventLog  ClearEventLogW
#else
#define ClearEventLog  ClearEventLogA
#endif 

WINADVAPI
BOOL
WINAPI
BackupEventLogA (
    IN HANDLE hEventLog,
    IN LPCSTR lpBackupFileName
    );
WINADVAPI
BOOL
WINAPI
BackupEventLogW (
    IN HANDLE hEventLog,
    IN LPCWSTR lpBackupFileName
    );
#ifdef UNICODE
#define BackupEventLog  BackupEventLogW
#else
#define BackupEventLog  BackupEventLogA
#endif 

WINADVAPI
BOOL
WINAPI
CloseEventLog (
    IN OUT HANDLE hEventLog
    );

WINADVAPI
BOOL
WINAPI
DeregisterEventSource (
    IN OUT HANDLE hEventLog
    );

WINADVAPI
BOOL
WINAPI
NotifyChangeEventLog(
    IN HANDLE  hEventLog,
    IN HANDLE  hEvent
    );

WINADVAPI
BOOL
WINAPI
GetNumberOfEventLogRecords (
    IN HANDLE hEventLog,
    OUT PDWORD NumberOfRecords
    );

WINADVAPI
BOOL
WINAPI
GetOldestEventLogRecord (
    IN HANDLE hEventLog,
    OUT PDWORD OldestRecord
    );

WINADVAPI
HANDLE
WINAPI
OpenEventLogA (
    IN LPCSTR lpUNCServerName,
    IN LPCSTR lpSourceName
    );
WINADVAPI
HANDLE
WINAPI
OpenEventLogW (
    IN LPCWSTR lpUNCServerName,
    IN LPCWSTR lpSourceName
    );
#ifdef UNICODE
#define OpenEventLog  OpenEventLogW
#else
#define OpenEventLog  OpenEventLogA
#endif 

WINADVAPI
HANDLE
WINAPI
RegisterEventSourceA (
    IN LPCSTR lpUNCServerName,
    IN LPCSTR lpSourceName
    );
WINADVAPI
HANDLE
WINAPI
RegisterEventSourceW (
    IN LPCWSTR lpUNCServerName,
    IN LPCWSTR lpSourceName
    );
#ifdef UNICODE
#define RegisterEventSource  RegisterEventSourceW
#else
#define RegisterEventSource  RegisterEventSourceA
#endif 

WINADVAPI
HANDLE
WINAPI
OpenBackupEventLogA (
    IN LPCSTR lpUNCServerName,
    IN LPCSTR lpFileName
    );
WINADVAPI
HANDLE
WINAPI
OpenBackupEventLogW (
    IN LPCWSTR lpUNCServerName,
    IN LPCWSTR lpFileName
    );
#ifdef UNICODE
#define OpenBackupEventLog  OpenBackupEventLogW
#else
#define OpenBackupEventLog  OpenBackupEventLogA
#endif 

WINADVAPI
BOOL
WINAPI
ReadEventLogA (
     IN HANDLE     hEventLog,
     IN DWORD      dwReadFlags,
     IN DWORD      dwRecordOffset,
     OUT LPVOID     lpBuffer,
     IN DWORD      nNumberOfBytesToRead,
     OUT DWORD      *pnBytesRead,
     OUT DWORD      *pnMinNumberOfBytesNeeded
    );
WINADVAPI
BOOL
WINAPI
ReadEventLogW (
     IN HANDLE     hEventLog,
     IN DWORD      dwReadFlags,
     IN DWORD      dwRecordOffset,
     OUT LPVOID     lpBuffer,
     IN DWORD      nNumberOfBytesToRead,
     OUT DWORD      *pnBytesRead,
     OUT DWORD      *pnMinNumberOfBytesNeeded
    );
#ifdef UNICODE
#define ReadEventLog  ReadEventLogW
#else
#define ReadEventLog  ReadEventLogA
#endif 

WINADVAPI
BOOL
WINAPI
ReportEventA (
     IN HANDLE     hEventLog,
     IN WORD       wType,
     IN WORD       wCategory,
     IN DWORD      dwEventID,
     IN PSID       lpUserSid,
     IN WORD       wNumStrings,
     IN DWORD      dwDataSize,
     IN LPCSTR   *lpStrings,
     IN LPVOID     lpRawData
    );
WINADVAPI
BOOL
WINAPI
ReportEventW (
     IN HANDLE     hEventLog,
     IN WORD       wType,
     IN WORD       wCategory,
     IN DWORD      dwEventID,
     IN PSID       lpUserSid,
     IN WORD       wNumStrings,
     IN DWORD      dwDataSize,
     IN LPCWSTR   *lpStrings,
     IN LPVOID     lpRawData
    );
#ifdef UNICODE
#define ReportEvent  ReportEventW
#else
#define ReportEvent  ReportEventA
#endif 


#define EVENTLOG_FULL_INFO      0

typedef struct _EVENTLOG_FULL_INFORMATION
{
    DWORD    dwFull;
}
EVENTLOG_FULL_INFORMATION, *LPEVENTLOG_FULL_INFORMATION;

WINADVAPI
BOOL
WINAPI
GetEventLogInformation (
     IN  HANDLE     hEventLog,
     IN  DWORD      dwInfoLevel,
     OUT LPVOID     lpBuffer,
     IN  DWORD      cbBufSize,
     OUT LPDWORD    pcbBytesNeeded
    );

//
//

//


WINADVAPI
BOOL
WINAPI
DuplicateToken(
    IN HANDLE ExistingTokenHandle,
    IN SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,
    OUT PHANDLE DuplicateTokenHandle
    );

WINADVAPI
BOOL
WINAPI
GetKernelObjectSecurity (
    IN HANDLE Handle,
    IN SECURITY_INFORMATION RequestedInformation,
    OUT PSECURITY_DESCRIPTOR pSecurityDescriptor,
    IN DWORD nLength,
    OUT LPDWORD lpnLengthNeeded
    );

WINADVAPI
BOOL
WINAPI
ImpersonateNamedPipeClient(
    IN HANDLE hNamedPipe
    );

WINADVAPI
BOOL
WINAPI
ImpersonateSelf(
    IN SECURITY_IMPERSONATION_LEVEL ImpersonationLevel
    );


WINADVAPI
BOOL
WINAPI
RevertToSelf (
    VOID
    );

WINADVAPI
BOOL
APIENTRY
SetThreadToken (
    IN PHANDLE Thread,
    IN HANDLE Token
    );

WINADVAPI
BOOL
WINAPI
AccessCheck (
    IN PSECURITY_DESCRIPTOR pSecurityDescriptor,
    IN HANDLE ClientToken,
    IN DWORD DesiredAccess,
    IN PGENERIC_MAPPING GenericMapping,
    OUT PPRIVILEGE_SET PrivilegeSet,
    IN LPDWORD PrivilegeSetLength,
    OUT LPDWORD GrantedAccess,
    OUT LPBOOL AccessStatus
    );

#if(_WIN32_WINNT >= 0x0500)
WINADVAPI
BOOL
WINAPI
AccessCheckByType (
    IN PSECURITY_DESCRIPTOR pSecurityDescriptor,
    IN PSID PrincipalSelfSid,
    IN HANDLE ClientToken,
    IN DWORD DesiredAccess,
    OUT POBJECT_TYPE_LIST ObjectTypeList,
    IN DWORD ObjectTypeListLength,
    OUT PGENERIC_MAPPING GenericMapping,
    OUT PPRIVILEGE_SET PrivilegeSet,
    OUT LPDWORD PrivilegeSetLength,
    OUT LPDWORD GrantedAccess,
    OUT LPBOOL AccessStatus
    );

WINADVAPI
BOOL
WINAPI
AccessCheckByTypeResultList (
    IN PSECURITY_DESCRIPTOR pSecurityDescriptor,
    IN PSID PrincipalSelfSid,
    IN HANDLE ClientToken,
    IN DWORD DesiredAccess,
    OUT POBJECT_TYPE_LIST ObjectTypeList,
    IN DWORD ObjectTypeListLength,
    OUT PGENERIC_MAPPING GenericMapping,
    OUT PPRIVILEGE_SET PrivilegeSet,
    OUT LPDWORD PrivilegeSetLength,
    OUT LPDWORD GrantedAccessList,
    OUT LPDWORD AccessStatusList
    );
#endif 


WINADVAPI
BOOL
WINAPI
OpenProcessToken (
    IN HANDLE ProcessHandle,
    IN DWORD DesiredAccess,
    OUT PHANDLE TokenHandle
    );


WINADVAPI
BOOL
WINAPI
OpenThreadToken (
    IN HANDLE ThreadHandle,
    IN DWORD DesiredAccess,
    IN BOOL OpenAsSelf,
    OUT PHANDLE TokenHandle
    );


WINADVAPI
BOOL
WINAPI
GetTokenInformation (
    IN HANDLE TokenHandle,
    IN TOKEN_INFORMATION_CLASS TokenInformationClass,
    OUT LPVOID TokenInformation,
    IN DWORD TokenInformationLength,
    OUT PDWORD ReturnLength
    );


WINADVAPI
BOOL
WINAPI
SetTokenInformation (
    IN HANDLE TokenHandle,
    IN TOKEN_INFORMATION_CLASS TokenInformationClass,
    IN LPVOID TokenInformation,
    IN DWORD TokenInformationLength
    );


WINADVAPI
BOOL
WINAPI
AdjustTokenPrivileges (
    IN HANDLE TokenHandle,
    IN BOOL DisableAllPrivileges,
    IN PTOKEN_PRIVILEGES NewState,
    IN DWORD BufferLength,
    OUT PTOKEN_PRIVILEGES PreviousState,
    OUT PDWORD ReturnLength
    );


WINADVAPI
BOOL
WINAPI
AdjustTokenGroups (
    IN HANDLE TokenHandle,
    IN BOOL ResetToDefault,
    IN PTOKEN_GROUPS NewState,
    IN DWORD BufferLength,
    OUT PTOKEN_GROUPS PreviousState,
    OUT PDWORD ReturnLength
    );


WINADVAPI
BOOL
WINAPI
PrivilegeCheck (
    IN HANDLE ClientToken,
    IN PPRIVILEGE_SET RequiredPrivileges,
    OUT LPBOOL pfResult
    );


WINADVAPI
BOOL
WINAPI
AccessCheckAndAuditAlarmA (
    IN LPCSTR SubsystemName,
    IN LPVOID HandleId,
    IN LPSTR ObjectTypeName,
    IN LPSTR ObjectName,
    IN PSECURITY_DESCRIPTOR SecurityDescriptor,
    IN DWORD DesiredAccess,
    IN PGENERIC_MAPPING GenericMapping,
    IN BOOL ObjectCreation,
    OUT LPDWORD GrantedAccess,
    OUT LPBOOL AccessStatus,
    OUT LPBOOL pfGenerateOnClose
    );
WINADVAPI
BOOL
WINAPI
AccessCheckAndAuditAlarmW (
    IN LPCWSTR SubsystemName,
    IN LPVOID HandleId,
    IN LPWSTR ObjectTypeName,
    IN LPWSTR ObjectName,
    IN PSECURITY_DESCRIPTOR SecurityDescriptor,
    IN DWORD DesiredAccess,
    IN PGENERIC_MAPPING GenericMapping,
    IN BOOL ObjectCreation,
    OUT LPDWORD GrantedAccess,
    OUT LPBOOL AccessStatus,
    OUT LPBOOL pfGenerateOnClose
    );
#ifdef UNICODE
#define AccessCheckAndAuditAlarm  AccessCheckAndAuditAlarmW
#else
#define AccessCheckAndAuditAlarm  AccessCheckAndAuditAlarmA
#endif 

#if(_WIN32_WINNT >= 0x0500)

WINADVAPI
BOOL
WINAPI
AccessCheckByTypeAndAuditAlarmA (
    IN LPCSTR SubsystemName,
    IN LPVOID HandleId,
    IN LPCSTR ObjectTypeName,
    IN LPCSTR ObjectName,
    IN PSECURITY_DESCRIPTOR SecurityDescriptor,
    IN PSID PrincipalSelfSid,
    IN DWORD DesiredAccess,
    IN AUDIT_EVENT_TYPE AuditType,
    IN DWORD Flags,
    IN POBJECT_TYPE_LIST ObjectTypeList,
    IN DWORD ObjectTypeListLength,
    IN PGENERIC_MAPPING GenericMapping,
    IN BOOL ObjectCreation,
    OUT LPDWORD GrantedAccess,
    OUT LPBOOL AccessStatus,
    OUT LPBOOL pfGenerateOnClose
    );
WINADVAPI
BOOL
WINAPI
AccessCheckByTypeAndAuditAlarmW (
    IN LPCWSTR SubsystemName,
    IN LPVOID HandleId,
    IN LPCWSTR ObjectTypeName,
    IN LPCWSTR ObjectName,
    IN PSECURITY_DESCRIPTOR SecurityDescriptor,
    IN PSID PrincipalSelfSid,
    IN DWORD DesiredAccess,
    IN AUDIT_EVENT_TYPE AuditType,
    IN DWORD Flags,
    IN POBJECT_TYPE_LIST ObjectTypeList,
    IN DWORD ObjectTypeListLength,
    IN PGENERIC_MAPPING GenericMapping,
    IN BOOL ObjectCreation,
    OUT LPDWORD GrantedAccess,
    OUT LPBOOL AccessStatus,
    OUT LPBOOL pfGenerateOnClose
    );
#ifdef UNICODE
#define AccessCheckByTypeAndAuditAlarm  AccessCheckByTypeAndAuditAlarmW
#else
#define AccessCheckByTypeAndAuditAlarm  AccessCheckByTypeAndAuditAlarmA
#endif 

WINADVAPI
BOOL
WINAPI
AccessCheckByTypeResultListAndAuditAlarmA (
    IN LPCSTR SubsystemName,
    IN LPVOID HandleId,
    IN LPCSTR ObjectTypeName,
    IN LPCSTR ObjectName,
    IN PSECURITY_DESCRIPTOR SecurityDescriptor,
    IN PSID PrincipalSelfSid,
    IN DWORD DesiredAccess,
    IN AUDIT_EVENT_TYPE AuditType,
    IN DWORD Flags,
    IN POBJECT_TYPE_LIST ObjectTypeList,
    IN DWORD ObjectTypeListLength,
    IN PGENERIC_MAPPING GenericMapping,
    IN BOOL ObjectCreation,
    OUT LPDWORD GrantedAccess,
    OUT LPDWORD AccessStatusList,
    OUT LPBOOL pfGenerateOnClose
    );
WINADVAPI
BOOL
WINAPI
AccessCheckByTypeResultListAndAuditAlarmW (
    IN LPCWSTR SubsystemName,
    IN LPVOID HandleId,
    IN LPCWSTR ObjectTypeName,
    IN LPCWSTR ObjectName,
    IN PSECURITY_DESCRIPTOR SecurityDescriptor,
    IN PSID PrincipalSelfSid,
    IN DWORD DesiredAccess,
    IN AUDIT_EVENT_TYPE AuditType,
    IN DWORD Flags,
    IN POBJECT_TYPE_LIST ObjectTypeList,
    IN DWORD ObjectTypeListLength,
    IN PGENERIC_MAPPING GenericMapping,
    IN BOOL ObjectCreation,
    OUT LPDWORD GrantedAccess,
    OUT LPDWORD AccessStatusList,
    OUT LPBOOL pfGenerateOnClose
    );
#ifdef UNICODE
#define AccessCheckByTypeResultListAndAuditAlarm  AccessCheckByTypeResultListAndAuditAlarmW
#else
#define AccessCheckByTypeResultListAndAuditAlarm  AccessCheckByTypeResultListAndAuditAlarmA
#endif 

WINADVAPI
BOOL
WINAPI
AccessCheckByTypeResultListAndAuditAlarmByHandleA (
    IN LPCSTR SubsystemName,
    IN LPVOID HandleId,
    IN HANDLE ClientToken,
    IN LPCSTR ObjectTypeName,
    IN LPCSTR ObjectName,
    IN PSECURITY_DESCRIPTOR SecurityDescriptor,
    IN PSID PrincipalSelfSid,
    IN DWORD DesiredAccess,
    IN AUDIT_EVENT_TYPE AuditType,
    IN DWORD Flags,
    IN POBJECT_TYPE_LIST ObjectTypeList,
    IN DWORD ObjectTypeListLength,
    IN PGENERIC_MAPPING GenericMapping,
    IN BOOL ObjectCreation,
    OUT LPDWORD GrantedAccess,
    OUT LPDWORD AccessStatusList,
    OUT LPBOOL pfGenerateOnClose
    );
WINADVAPI
BOOL
WINAPI
AccessCheckByTypeResultListAndAuditAlarmByHandleW (
    IN LPCWSTR SubsystemName,
    IN LPVOID HandleId,
    IN HANDLE ClientToken,
    IN LPCWSTR ObjectTypeName,
    IN LPCWSTR ObjectName,
    IN PSECURITY_DESCRIPTOR SecurityDescriptor,
    IN PSID PrincipalSelfSid,
    IN DWORD DesiredAccess,
    IN AUDIT_EVENT_TYPE AuditType,
    IN DWORD Flags,
    IN POBJECT_TYPE_LIST ObjectTypeList,
    IN DWORD ObjectTypeListLength,
    IN PGENERIC_MAPPING GenericMapping,
    IN BOOL ObjectCreation,
    OUT LPDWORD GrantedAccess,
    OUT LPDWORD AccessStatusList,
    OUT LPBOOL pfGenerateOnClose
    );
#ifdef UNICODE
#define AccessCheckByTypeResultListAndAuditAlarmByHandle  AccessCheckByTypeResultListAndAuditAlarmByHandleW
#else
#define AccessCheckByTypeResultListAndAuditAlarmByHandle  AccessCheckByTypeResultListAndAuditAlarmByHandleA
#endif 

#endif 


WINADVAPI
BOOL
WINAPI
ObjectOpenAuditAlarmA (
    IN LPCSTR SubsystemName,
    IN LPVOID HandleId,
    IN LPSTR ObjectTypeName,
    IN LPSTR ObjectName,
    IN PSECURITY_DESCRIPTOR pSecurityDescriptor,
    IN HANDLE ClientToken,
    IN DWORD DesiredAccess,
    IN DWORD GrantedAccess,
    IN PPRIVILEGE_SET Privileges,
    IN BOOL ObjectCreation,
    IN BOOL AccessGranted,
    OUT LPBOOL GenerateOnClose
    );
WINADVAPI
BOOL
WINAPI
ObjectOpenAuditAlarmW (
    IN LPCWSTR SubsystemName,
    IN LPVOID HandleId,
    IN LPWSTR ObjectTypeName,
    IN LPWSTR ObjectName,
    IN PSECURITY_DESCRIPTOR pSecurityDescriptor,
    IN HANDLE ClientToken,
    IN DWORD DesiredAccess,
    IN DWORD GrantedAccess,
    IN PPRIVILEGE_SET Privileges,
    IN BOOL ObjectCreation,
    IN BOOL AccessGranted,
    OUT LPBOOL GenerateOnClose
    );
#ifdef UNICODE
#define ObjectOpenAuditAlarm  ObjectOpenAuditAlarmW
#else
#define ObjectOpenAuditAlarm  ObjectOpenAuditAlarmA
#endif 


WINADVAPI
BOOL
WINAPI
ObjectPrivilegeAuditAlarmA (
    IN LPCSTR SubsystemName,
    IN LPVOID HandleId,
    IN HANDLE ClientToken,
    IN DWORD DesiredAccess,
    IN PPRIVILEGE_SET Privileges,
    IN BOOL AccessGranted
    );
WINADVAPI
BOOL
WINAPI
ObjectPrivilegeAuditAlarmW (
    IN LPCWSTR SubsystemName,
    IN LPVOID HandleId,
    IN HANDLE ClientToken,
    IN DWORD DesiredAccess,
    IN PPRIVILEGE_SET Privileges,
    IN BOOL AccessGranted
    );
#ifdef UNICODE
#define ObjectPrivilegeAuditAlarm  ObjectPrivilegeAuditAlarmW
#else
#define ObjectPrivilegeAuditAlarm  ObjectPrivilegeAuditAlarmA
#endif 


WINADVAPI
BOOL
WINAPI
ObjectCloseAuditAlarmA (
    IN LPCSTR SubsystemName,
    IN LPVOID HandleId,
    IN BOOL GenerateOnClose
    );
WINADVAPI
BOOL
WINAPI
ObjectCloseAuditAlarmW (
    IN LPCWSTR SubsystemName,
    IN LPVOID HandleId,
    IN BOOL GenerateOnClose
    );
#ifdef UNICODE
#define ObjectCloseAuditAlarm  ObjectCloseAuditAlarmW
#else
#define ObjectCloseAuditAlarm  ObjectCloseAuditAlarmA
#endif 


WINADVAPI
BOOL
WINAPI
ObjectDeleteAuditAlarmA (
    IN LPCSTR SubsystemName,
    IN LPVOID HandleId,
    IN BOOL GenerateOnClose
    );
WINADVAPI
BOOL
WINAPI
ObjectDeleteAuditAlarmW (
    IN LPCWSTR SubsystemName,
    IN LPVOID HandleId,
    IN BOOL GenerateOnClose
    );
#ifdef UNICODE
#define ObjectDeleteAuditAlarm  ObjectDeleteAuditAlarmW
#else
#define ObjectDeleteAuditAlarm  ObjectDeleteAuditAlarmA
#endif 


WINADVAPI
BOOL
WINAPI
PrivilegedServiceAuditAlarmA (
    IN LPCSTR SubsystemName,
    IN LPCSTR ServiceName,
    IN HANDLE ClientToken,
    IN PPRIVILEGE_SET Privileges,
    IN BOOL AccessGranted
    );
WINADVAPI
BOOL
WINAPI
PrivilegedServiceAuditAlarmW (
    IN LPCWSTR SubsystemName,
    IN LPCWSTR ServiceName,
    IN HANDLE ClientToken,
    IN PPRIVILEGE_SET Privileges,
    IN BOOL AccessGranted
    );
#ifdef UNICODE
#define PrivilegedServiceAuditAlarm  PrivilegedServiceAuditAlarmW
#else
#define PrivilegedServiceAuditAlarm  PrivilegedServiceAuditAlarmA
#endif 



#if(_WIN32_WINNT >= 0x0501)


WINADVAPI
BOOL
WINAPI
IsWellKnownSid (
    IN  PSID pSid,
    IN  WELL_KNOWN_SID_TYPE WellKnownSidType
    );

WINADVAPI
BOOL
WINAPI
CreateWellKnownSid(
    IN WELL_KNOWN_SID_TYPE WellKnownSidType,
    IN PSID DomainSid  OPTIONAL,
    OUT PSID pSid,
    IN OUT DWORD *cbSid
    );

WINADVAPI
BOOL
WINAPI
EqualDomainSid(
    IN PSID pSid1,
    IN PSID pSid2,
    OUT BOOL *pfEqual
    );

WINADVAPI
BOOL
WINAPI
GetWindowsAccountDomainSid(
    IN PSID pSid,
    OUT PSID ppDomainSid OPTIONAL,
    IN OUT DWORD *cbSid
    );

#endif 

WINADVAPI
BOOL
WINAPI
IsValidSid (
    IN PSID pSid
    );


WINADVAPI
BOOL
WINAPI
EqualSid (
    IN PSID pSid1,
    IN PSID pSid2
    );


WINADVAPI
BOOL
WINAPI
EqualPrefixSid (
    PSID pSid1,
    PSID pSid2
    );


WINADVAPI
DWORD
WINAPI
GetSidLengthRequired (
    IN UCHAR nSubAuthorityCount
    );


WINADVAPI
BOOL
WINAPI
AllocateAndInitializeSid (
    IN PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,
    IN BYTE nSubAuthorityCount,
    IN DWORD nSubAuthority0,
    IN DWORD nSubAuthority1,
    IN DWORD nSubAuthority2,
    IN DWORD nSubAuthority3,
    IN DWORD nSubAuthority4,
    IN DWORD nSubAuthority5,
    IN DWORD nSubAuthority6,
    IN DWORD nSubAuthority7,
    OUT PSID *pSid
    );

WINADVAPI
PVOID
WINAPI
FreeSid(
    IN PSID pSid
    );

WINADVAPI
BOOL
WINAPI
InitializeSid (
    OUT PSID Sid,
    IN PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,
    IN BYTE nSubAuthorityCount
    );


WINADVAPI
PSID_IDENTIFIER_AUTHORITY
WINAPI
GetSidIdentifierAuthority (
    IN PSID pSid
    );


WINADVAPI
PDWORD
WINAPI
GetSidSubAuthority (
    IN PSID pSid,
    IN DWORD nSubAuthority
    );


WINADVAPI
PUCHAR
WINAPI
GetSidSubAuthorityCount (
    IN PSID pSid
    );


WINADVAPI
DWORD
WINAPI
GetLengthSid (
    IN PSID pSid
    );


WINADVAPI
BOOL
WINAPI
CopySid (
    IN DWORD nDestinationSidLength,
    OUT PSID pDestinationSid,
    IN PSID pSourceSid
    );


WINADVAPI
BOOL
WINAPI
AreAllAccessesGranted (
    IN DWORD GrantedAccess,
    IN DWORD DesiredAccess
    );


WINADVAPI
BOOL
WINAPI
AreAnyAccessesGranted (
    IN DWORD GrantedAccess,
    IN DWORD DesiredAccess
    );


WINADVAPI
VOID
WINAPI
MapGenericMask (
    OUT PDWORD AccessMask,
    IN PGENERIC_MAPPING GenericMapping
    );


WINADVAPI
BOOL
WINAPI
IsValidAcl (
    IN PACL pAcl
    );


WINADVAPI
BOOL
WINAPI
InitializeAcl (
    OUT PACL pAcl,
    IN DWORD nAclLength,
    IN DWORD dwAclRevision
    );


WINADVAPI
BOOL
WINAPI
GetAclInformation (
    IN PACL pAcl,
    OUT LPVOID pAclInformation,
    IN DWORD nAclInformationLength,
    IN ACL_INFORMATION_CLASS dwAclInformationClass
    );


WINADVAPI
BOOL
WINAPI
SetAclInformation (
    IN PACL pAcl,
    IN LPVOID pAclInformation,
    IN DWORD nAclInformationLength,
    IN ACL_INFORMATION_CLASS dwAclInformationClass
    );


WINADVAPI
BOOL
WINAPI
AddAce (
    IN OUT PACL pAcl,
    IN DWORD dwAceRevision,
    IN DWORD dwStartingAceIndex,
    IN LPVOID pAceList,
    IN DWORD nAceListLength
    );


WINADVAPI
BOOL
WINAPI
DeleteAce (
    IN OUT PACL pAcl,
    IN DWORD dwAceIndex
    );


WINADVAPI
BOOL
WINAPI
GetAce (
    IN PACL pAcl,
    IN DWORD dwAceIndex,
    OUT LPVOID *pAce
    );


WINADVAPI
BOOL
WINAPI
AddAccessAllowedAce (
    IN OUT PACL pAcl,
    IN DWORD dwAceRevision,
    IN DWORD AccessMask,
    IN PSID pSid
    );

#if(_WIN32_WINNT >= 0x0500)
WINADVAPI
BOOL
WINAPI
AddAccessAllowedAceEx (
    IN OUT PACL pAcl,
    IN DWORD dwAceRevision,
    IN DWORD AceFlags,
    IN DWORD AccessMask,
    IN PSID pSid
    );
#endif 


WINADVAPI
BOOL
WINAPI
AddAccessDeniedAce (
    IN OUT PACL pAcl,
    IN DWORD dwAceRevision,
    IN DWORD AccessMask,
    IN PSID pSid
    );

#if(_WIN32_WINNT >= 0x0500)
WINADVAPI
BOOL
WINAPI
AddAccessDeniedAceEx (
    IN OUT PACL pAcl,
    IN DWORD dwAceRevision,
    IN DWORD AceFlags,
    IN DWORD AccessMask,
    IN PSID pSid
    );
#endif 

WINADVAPI
BOOL
WINAPI
AddAuditAccessAce(
    IN OUT PACL pAcl,
    IN DWORD dwAceRevision,
    IN DWORD dwAccessMask,
    IN PSID pSid,
    IN BOOL bAuditSuccess,
    IN BOOL bAuditFailure
    );

#if(_WIN32_WINNT >= 0x0500)
WINADVAPI
BOOL
WINAPI
AddAuditAccessAceEx(
    IN OUT PACL pAcl,
    IN DWORD dwAceRevision,
    IN DWORD AceFlags,
    IN DWORD dwAccessMask,
    IN PSID pSid,
    IN BOOL bAuditSuccess,
    IN BOOL bAuditFailure
    );

WINADVAPI
BOOL
WINAPI
AddAccessAllowedObjectAce (
    IN OUT PACL pAcl,
    IN DWORD dwAceRevision,
    IN DWORD AceFlags,
    IN DWORD AccessMask,
    IN GUID *ObjectTypeGuid,
    IN GUID *InheritedObjectTypeGuid,
    IN PSID pSid
    );

WINADVAPI
BOOL
WINAPI
AddAccessDeniedObjectAce (
    IN OUT PACL pAcl,
    IN DWORD dwAceRevision,
    IN DWORD AceFlags,
    IN DWORD AccessMask,
    IN GUID *ObjectTypeGuid,
    IN GUID *InheritedObjectTypeGuid,
    IN PSID pSid
    );

WINADVAPI
BOOL
WINAPI
AddAuditAccessObjectAce (
    IN OUT PACL pAcl,
    IN DWORD dwAceRevision,
    IN DWORD AceFlags,
    IN DWORD AccessMask,
    IN GUID *ObjectTypeGuid,
    IN GUID *InheritedObjectTypeGuid,
    IN PSID pSid,
    IN BOOL bAuditSuccess,
    IN BOOL bAuditFailure
    );
#endif 

WINADVAPI
BOOL
WINAPI
FindFirstFreeAce (
    IN PACL pAcl,
    OUT LPVOID *pAce
    );


WINADVAPI
BOOL
WINAPI
InitializeSecurityDescriptor (
    OUT PSECURITY_DESCRIPTOR pSecurityDescriptor,
    IN DWORD dwRevision
    );


WINADVAPI
BOOL
WINAPI
IsValidSecurityDescriptor (
    IN PSECURITY_DESCRIPTOR pSecurityDescriptor
    );


WINADVAPI
DWORD
WINAPI
GetSecurityDescriptorLength (
    IN PSECURITY_DESCRIPTOR pSecurityDescriptor
    );


WINADVAPI
BOOL
WINAPI
GetSecurityDescriptorControl (
    IN PSECURITY_DESCRIPTOR pSecurityDescriptor,
    OUT PSECURITY_DESCRIPTOR_CONTROL pControl,
    OUT LPDWORD lpdwRevision
    );

#if(_WIN32_WINNT >= 0x0500)
WINADVAPI
BOOL
WINAPI
SetSecurityDescriptorControl (
    IN PSECURITY_DESCRIPTOR pSecurityDescriptor,
    IN SECURITY_DESCRIPTOR_CONTROL ControlBitsOfInterest,
    IN SECURITY_DESCRIPTOR_CONTROL ControlBitsToSet
    );
#endif 

WINADVAPI
BOOL
WINAPI
SetSecurityDescriptorDacl (
    IN OUT PSECURITY_DESCRIPTOR pSecurityDescriptor,
    IN BOOL bDaclPresent,
    IN PACL pDacl,
    IN BOOL bDaclDefaulted
    );


WINADVAPI
BOOL
WINAPI
GetSecurityDescriptorDacl (
    IN PSECURITY_DESCRIPTOR pSecurityDescriptor,
    OUT LPBOOL lpbDaclPresent,
    OUT PACL *pDacl,
    OUT LPBOOL lpbDaclDefaulted
    );


WINADVAPI
BOOL
WINAPI
SetSecurityDescriptorSacl (
    IN OUT PSECURITY_DESCRIPTOR pSecurityDescriptor,
    IN BOOL bSaclPresent,
    IN PACL pSacl,
    IN BOOL bSaclDefaulted
    );


WINADVAPI
BOOL
WINAPI
GetSecurityDescriptorSacl (
    IN PSECURITY_DESCRIPTOR pSecurityDescriptor,
    OUT LPBOOL lpbSaclPresent,
    OUT PACL *pSacl,
    OUT LPBOOL lpbSaclDefaulted
    );


WINADVAPI
BOOL
WINAPI
SetSecurityDescriptorOwner (
    IN OUT PSECURITY_DESCRIPTOR pSecurityDescriptor,
    IN PSID pOwner,
    IN BOOL bOwnerDefaulted
    );


WINADVAPI
BOOL
WINAPI
GetSecurityDescriptorOwner (
    IN PSECURITY_DESCRIPTOR pSecurityDescriptor,
    OUT PSID *pOwner,
    OUT LPBOOL lpbOwnerDefaulted
    );


WINADVAPI
BOOL
WINAPI
SetSecurityDescriptorGroup (
    IN OUT PSECURITY_DESCRIPTOR pSecurityDescriptor,
    IN PSID pGroup,
    IN BOOL bGroupDefaulted
    );


WINADVAPI
BOOL
WINAPI
GetSecurityDescriptorGroup (
    IN PSECURITY_DESCRIPTOR pSecurityDescriptor,
    OUT PSID *pGroup,
    OUT LPBOOL lpbGroupDefaulted
    );


WINADVAPI
DWORD
WINAPI
SetSecurityDescriptorRMControl(
    IN OUT PSECURITY_DESCRIPTOR SecurityDescriptor,
    IN PUCHAR RMControl OPTIONAL
    );

WINADVAPI
DWORD
WINAPI
GetSecurityDescriptorRMControl(
    IN PSECURITY_DESCRIPTOR SecurityDescriptor,
    OUT PUCHAR RMControl
    );

WINADVAPI
BOOL
WINAPI
CreatePrivateObjectSecurity (
    IN PSECURITY_DESCRIPTOR ParentDescriptor,
    IN PSECURITY_DESCRIPTOR CreatorDescriptor,
    OUT PSECURITY_DESCRIPTOR * NewDescriptor,
    IN BOOL IsDirectoryObject,
    IN HANDLE Token,
    IN PGENERIC_MAPPING GenericMapping
    );

#if(_WIN32_WINNT >= 0x0500)
WINADVAPI
BOOL
WINAPI
ConvertToAutoInheritPrivateObjectSecurity(
    IN PSECURITY_DESCRIPTOR ParentDescriptor,
    IN PSECURITY_DESCRIPTOR CurrentSecurityDescriptor,
    OUT PSECURITY_DESCRIPTOR *NewSecurityDescriptor,
    IN GUID *ObjectType,
    IN BOOLEAN IsDirectoryObject,
    IN PGENERIC_MAPPING GenericMapping
    );

WINADVAPI
BOOL
WINAPI
CreatePrivateObjectSecurityEx (
    IN PSECURITY_DESCRIPTOR ParentDescriptor,
    IN PSECURITY_DESCRIPTOR CreatorDescriptor,
    OUT PSECURITY_DESCRIPTOR * NewDescriptor,
    IN GUID *ObjectType OPTIONAL,
    IN BOOL IsContainerObject,
    IN ULONG AutoInheritFlags,
    IN HANDLE Token,
    IN PGENERIC_MAPPING GenericMapping
    );

WINADVAPI
BOOL
WINAPI
CreatePrivateObjectSecurityWithMultipleInheritance (
    IN PSECURITY_DESCRIPTOR ParentDescriptor,
    IN PSECURITY_DESCRIPTOR CreatorDescriptor,
    OUT PSECURITY_DESCRIPTOR * NewDescriptor,
    IN GUID **ObjectTypes OPTIONAL,
    IN ULONG GuidCount,
    IN BOOL IsContainerObject,
    IN ULONG AutoInheritFlags,
    IN HANDLE Token,
    IN PGENERIC_MAPPING GenericMapping
    );
#endif 

WINADVAPI
BOOL
WINAPI
SetPrivateObjectSecurity (
    IN SECURITY_INFORMATION SecurityInformation,
    IN PSECURITY_DESCRIPTOR ModificationDescriptor,
    OUT PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,
    IN PGENERIC_MAPPING GenericMapping,
    IN HANDLE Token
    );

#if(_WIN32_WINNT >= 0x0500)
WINADVAPI
BOOL
WINAPI
SetPrivateObjectSecurityEx (
    IN SECURITY_INFORMATION SecurityInformation,
    IN PSECURITY_DESCRIPTOR ModificationDescriptor,
    OUT PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,
    IN ULONG AutoInheritFlags,
    IN PGENERIC_MAPPING GenericMapping,
    IN HANDLE Token OPTIONAL
    );
#endif 

WINADVAPI
BOOL
WINAPI
GetPrivateObjectSecurity (
    IN PSECURITY_DESCRIPTOR ObjectDescriptor,
    IN SECURITY_INFORMATION SecurityInformation,
    OUT PSECURITY_DESCRIPTOR ResultantDescriptor,
    IN DWORD DescriptorLength,
    OUT PDWORD ReturnLength
    );


WINADVAPI
BOOL
WINAPI
DestroyPrivateObjectSecurity (
    IN OUT PSECURITY_DESCRIPTOR * ObjectDescriptor
    );


WINADVAPI
BOOL
WINAPI
MakeSelfRelativeSD (
    IN PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,
    OUT PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,
    OUT LPDWORD lpdwBufferLength
    );


WINADVAPI
BOOL
WINAPI
MakeAbsoluteSD (
    IN PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,
    OUT PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,
    OUT LPDWORD lpdwAbsoluteSecurityDescriptorSize,
    OUT PACL pDacl,
    OUT LPDWORD lpdwDaclSize,
    OUT PACL pSacl,
    OUT LPDWORD lpdwSaclSize,
    OUT PSID pOwner,
    OUT LPDWORD lpdwOwnerSize,
    OUT PSID pPrimaryGroup,
    OUT LPDWORD lpdwPrimaryGroupSize
    );


WINADVAPI
BOOL
WINAPI
MakeAbsoluteSD2 (
    IN PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,
    OUT LPDWORD lpdwBufferSize
    );

WINADVAPI
BOOL
WINAPI
SetFileSecurityA (
    IN LPCSTR lpFileName,
    IN SECURITY_INFORMATION SecurityInformation,
    IN PSECURITY_DESCRIPTOR pSecurityDescriptor
    );
WINADVAPI
BOOL
WINAPI
SetFileSecurityW (
    IN LPCWSTR lpFileName,
    IN SECURITY_INFORMATION SecurityInformation,
    IN PSECURITY_DESCRIPTOR pSecurityDescriptor
    );
#ifdef UNICODE
#define SetFileSecurity  SetFileSecurityW
#else
#define SetFileSecurity  SetFileSecurityA
#endif 


WINADVAPI
BOOL
WINAPI
GetFileSecurityA (
    IN LPCSTR lpFileName,
    IN SECURITY_INFORMATION RequestedInformation,
    OUT PSECURITY_DESCRIPTOR pSecurityDescriptor,
    IN DWORD nLength,
    OUT LPDWORD lpnLengthNeeded
    );
WINADVAPI
BOOL
WINAPI
GetFileSecurityW (
    IN LPCWSTR lpFileName,
    IN SECURITY_INFORMATION RequestedInformation,
    OUT PSECURITY_DESCRIPTOR pSecurityDescriptor,
    IN DWORD nLength,
    OUT LPDWORD lpnLengthNeeded
    );
#ifdef UNICODE
#define GetFileSecurity  GetFileSecurityW
#else
#define GetFileSecurity  GetFileSecurityA
#endif 


WINADVAPI
BOOL
WINAPI
SetKernelObjectSecurity (
    IN HANDLE Handle,
    IN SECURITY_INFORMATION SecurityInformation,
    IN PSECURITY_DESCRIPTOR SecurityDescriptor
    );

WINBASEAPI
HANDLE
WINAPI
FindFirstChangeNotificationA(
    IN LPCSTR lpPathName,
    IN BOOL bWatchSubtree,
    IN DWORD dwNotifyFilter
    );
WINBASEAPI
HANDLE
WINAPI
FindFirstChangeNotificationW(
    IN LPCWSTR lpPathName,
    IN BOOL bWatchSubtree,
    IN DWORD dwNotifyFilter
    );
#ifdef UNICODE
#define FindFirstChangeNotification  FindFirstChangeNotificationW
#else
#define FindFirstChangeNotification  FindFirstChangeNotificationA
#endif 

WINBASEAPI
BOOL
WINAPI
FindNextChangeNotification(
    IN HANDLE hChangeHandle
    );

WINBASEAPI
BOOL
WINAPI
FindCloseChangeNotification(
    IN HANDLE hChangeHandle
    );

#if(_WIN32_WINNT >= 0x0400)
WINBASEAPI
BOOL
WINAPI
ReadDirectoryChangesW(
    IN HANDLE hDirectory,
    IN OUT LPVOID lpBuffer,
    IN DWORD nBufferLength,
    IN BOOL bWatchSubtree,
    IN DWORD dwNotifyFilter,
    OUT LPDWORD lpBytesReturned,
    IN LPOVERLAPPED lpOverlapped,
    IN LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    );
#endif 

WINBASEAPI
BOOL
WINAPI
VirtualLock(
    IN LPVOID lpAddress,
    IN SIZE_T dwSize
    );

WINBASEAPI
BOOL
WINAPI
VirtualUnlock(
    IN LPVOID lpAddress,
    IN SIZE_T dwSize
    );

WINBASEAPI
LPVOID
WINAPI
MapViewOfFileEx(
    IN HANDLE hFileMappingObject,
    IN DWORD dwDesiredAccess,
    IN DWORD dwFileOffsetHigh,
    IN DWORD dwFileOffsetLow,
    IN SIZE_T dwNumberOfBytesToMap,
    IN LPVOID lpBaseAddress
    );

WINBASEAPI
BOOL
WINAPI
SetPriorityClass(
    IN HANDLE hProcess,
    IN DWORD dwPriorityClass
    );

WINBASEAPI
DWORD
WINAPI
GetPriorityClass(
    IN HANDLE hProcess
    );

WINBASEAPI
BOOL
WINAPI
IsBadReadPtr(
    IN CONST VOID *lp,
    IN UINT_PTR ucb
    );

WINBASEAPI
BOOL
WINAPI
IsBadWritePtr(
    IN LPVOID lp,
    IN UINT_PTR ucb
    );

WINBASEAPI
BOOL
WINAPI
IsBadHugeReadPtr(
    IN CONST VOID *lp,
    IN UINT_PTR ucb
    );

WINBASEAPI
BOOL
WINAPI
IsBadHugeWritePtr(
    IN LPVOID lp,
    IN UINT_PTR ucb
    );

WINBASEAPI
BOOL
WINAPI
IsBadCodePtr(
    IN FARPROC lpfn
    );

WINBASEAPI
BOOL
WINAPI
IsBadStringPtrA(
    IN LPCSTR lpsz,
    IN UINT_PTR ucchMax
    );
WINBASEAPI
BOOL
WINAPI
IsBadStringPtrW(
    IN LPCWSTR lpsz,
    IN UINT_PTR ucchMax
    );
#ifdef UNICODE
#define IsBadStringPtr  IsBadStringPtrW
#else
#define IsBadStringPtr  IsBadStringPtrA
#endif 

WINADVAPI
BOOL
WINAPI
LookupAccountSidA(
    IN LPCSTR lpSystemName,
    IN PSID Sid,
    OUT LPSTR Name,
    IN OUT LPDWORD cbName,
    OUT LPSTR ReferencedDomainName,
    IN OUT LPDWORD cbReferencedDomainName,
    OUT PSID_NAME_USE peUse
    );
WINADVAPI
BOOL
WINAPI
LookupAccountSidW(
    IN LPCWSTR lpSystemName,
    IN PSID Sid,
    OUT LPWSTR Name,
    IN OUT LPDWORD cbName,
    OUT LPWSTR ReferencedDomainName,
    IN OUT LPDWORD cbReferencedDomainName,
    OUT PSID_NAME_USE peUse
    );
#ifdef UNICODE
#define LookupAccountSid  LookupAccountSidW
#else
#define LookupAccountSid  LookupAccountSidA
#endif 

WINADVAPI
BOOL
WINAPI
LookupAccountNameA(
    IN LPCSTR lpSystemName,
    IN LPCSTR lpAccountName,
    OUT PSID Sid,
    IN OUT LPDWORD cbSid,
    OUT LPSTR ReferencedDomainName,
    IN OUT LPDWORD cbReferencedDomainName,
    OUT PSID_NAME_USE peUse
    );
WINADVAPI
BOOL
WINAPI
LookupAccountNameW(
    IN LPCWSTR lpSystemName,
    IN LPCWSTR lpAccountName,
    OUT PSID Sid,
    IN OUT LPDWORD cbSid,
    OUT LPWSTR ReferencedDomainName,
    IN OUT LPDWORD cbReferencedDomainName,
    OUT PSID_NAME_USE peUse
    );
#ifdef UNICODE
#define LookupAccountName  LookupAccountNameW
#else
#define LookupAccountName  LookupAccountNameA
#endif 

WINADVAPI
BOOL
WINAPI
LookupPrivilegeValueA(
    IN LPCSTR lpSystemName,
    IN LPCSTR lpName,
    OUT PLUID   lpLuid
    );
WINADVAPI
BOOL
WINAPI
LookupPrivilegeValueW(
    IN LPCWSTR lpSystemName,
    IN LPCWSTR lpName,
    OUT PLUID   lpLuid
    );
#ifdef UNICODE
#define LookupPrivilegeValue  LookupPrivilegeValueW
#else
#define LookupPrivilegeValue  LookupPrivilegeValueA
#endif 

WINADVAPI
BOOL
WINAPI
LookupPrivilegeNameA(
    IN LPCSTR lpSystemName,
    IN PLUID   lpLuid,
    OUT LPSTR lpName,
    IN OUT LPDWORD cbName
    );
WINADVAPI
BOOL
WINAPI
LookupPrivilegeNameW(
    IN LPCWSTR lpSystemName,
    IN PLUID   lpLuid,
    OUT LPWSTR lpName,
    IN OUT LPDWORD cbName
    );
#ifdef UNICODE
#define LookupPrivilegeName  LookupPrivilegeNameW
#else
#define LookupPrivilegeName  LookupPrivilegeNameA
#endif 

WINADVAPI
BOOL
WINAPI
LookupPrivilegeDisplayNameA(
    IN LPCSTR lpSystemName,
    IN LPCSTR lpName,
    OUT LPSTR lpDisplayName,
    IN OUT LPDWORD cbDisplayName,
    OUT LPDWORD lpLanguageId
    );
WINADVAPI
BOOL
WINAPI
LookupPrivilegeDisplayNameW(
    IN LPCWSTR lpSystemName,
    IN LPCWSTR lpName,
    OUT LPWSTR lpDisplayName,
    IN OUT LPDWORD cbDisplayName,
    OUT LPDWORD lpLanguageId
    );
#ifdef UNICODE
#define LookupPrivilegeDisplayName  LookupPrivilegeDisplayNameW
#else
#define LookupPrivilegeDisplayName  LookupPrivilegeDisplayNameA
#endif 

WINADVAPI
BOOL
WINAPI
AllocateLocallyUniqueId(
    OUT PLUID Luid
    );

WINBASEAPI
BOOL
WINAPI
BuildCommDCBA(
    IN LPCSTR lpDef,
    OUT LPDCB lpDCB
    );
WINBASEAPI
BOOL
WINAPI
BuildCommDCBW(
    IN LPCWSTR lpDef,
    OUT LPDCB lpDCB
    );
#ifdef UNICODE
#define BuildCommDCB  BuildCommDCBW
#else
#define BuildCommDCB  BuildCommDCBA
#endif 

WINBASEAPI
BOOL
WINAPI
BuildCommDCBAndTimeoutsA(
    IN LPCSTR lpDef,
    OUT LPDCB lpDCB,
    IN LPCOMMTIMEOUTS lpCommTimeouts
    );
WINBASEAPI
BOOL
WINAPI
BuildCommDCBAndTimeoutsW(
    IN LPCWSTR lpDef,
    OUT LPDCB lpDCB,
    IN LPCOMMTIMEOUTS lpCommTimeouts
    );
#ifdef UNICODE
#define BuildCommDCBAndTimeouts  BuildCommDCBAndTimeoutsW
#else
#define BuildCommDCBAndTimeouts  BuildCommDCBAndTimeoutsA
#endif 

WINBASEAPI
BOOL
WINAPI
CommConfigDialogA(
    IN LPCSTR lpszName,
    IN HWND hWnd,
    IN OUT LPCOMMCONFIG lpCC
    );
WINBASEAPI
BOOL
WINAPI
CommConfigDialogW(
    IN LPCWSTR lpszName,
    IN HWND hWnd,
    IN OUT LPCOMMCONFIG lpCC
    );
#ifdef UNICODE
#define CommConfigDialog  CommConfigDialogW
#else
#define CommConfigDialog  CommConfigDialogA
#endif 

WINBASEAPI
BOOL
WINAPI
GetDefaultCommConfigA(
    IN LPCSTR lpszName,
    OUT LPCOMMCONFIG lpCC,
    IN OUT LPDWORD lpdwSize
    );
WINBASEAPI
BOOL
WINAPI
GetDefaultCommConfigW(
    IN LPCWSTR lpszName,
    OUT LPCOMMCONFIG lpCC,
    IN OUT LPDWORD lpdwSize
    );
#ifdef UNICODE
#define GetDefaultCommConfig  GetDefaultCommConfigW
#else
#define GetDefaultCommConfig  GetDefaultCommConfigA
#endif 

WINBASEAPI
BOOL
WINAPI
SetDefaultCommConfigA(
    IN LPCSTR lpszName,
    IN LPCOMMCONFIG lpCC,
    IN DWORD dwSize
    );
WINBASEAPI
BOOL
WINAPI
SetDefaultCommConfigW(
    IN LPCWSTR lpszName,
    IN LPCOMMCONFIG lpCC,
    IN DWORD dwSize
    );
#ifdef UNICODE
#define SetDefaultCommConfig  SetDefaultCommConfigW
#else
#define SetDefaultCommConfig  SetDefaultCommConfigA
#endif 

#ifndef _MAC
#define MAX_COMPUTERNAME_LENGTH 15
#else
#define MAX_COMPUTERNAME_LENGTH 31
#endif

WINBASEAPI
BOOL
WINAPI
GetComputerNameA (
    OUT LPSTR lpBuffer,
    IN OUT LPDWORD nSize
    );
WINBASEAPI
BOOL
WINAPI
GetComputerNameW (
    OUT LPWSTR lpBuffer,
    IN OUT LPDWORD nSize
    );
#ifdef UNICODE
#define GetComputerName  GetComputerNameW
#else
#define GetComputerName  GetComputerNameA
#endif 

WINBASEAPI
BOOL
WINAPI
SetComputerNameA (
    IN LPCSTR lpComputerName
    );
WINBASEAPI
BOOL
WINAPI
SetComputerNameW (
    IN LPCWSTR lpComputerName
    );
#ifdef UNICODE
#define SetComputerName  SetComputerNameW
#else
#define SetComputerName  SetComputerNameA
#endif 


#if (_WIN32_WINNT >= 0x0500)

typedef enum _COMPUTER_NAME_FORMAT {
    ComputerNameNetBIOS,
    ComputerNameDnsHostname,
    ComputerNameDnsDomain,
    ComputerNameDnsFullyQualified,
    ComputerNamePhysicalNetBIOS,
    ComputerNamePhysicalDnsHostname,
    ComputerNamePhysicalDnsDomain,
    ComputerNamePhysicalDnsFullyQualified,
    ComputerNameMax
} COMPUTER_NAME_FORMAT ;

WINBASEAPI
BOOL
WINAPI
GetComputerNameExA (
    IN COMPUTER_NAME_FORMAT NameType,
    OUT LPSTR lpBuffer,
    IN OUT LPDWORD nSize
    );
WINBASEAPI
BOOL
WINAPI
GetComputerNameExW (
    IN COMPUTER_NAME_FORMAT NameType,
    OUT LPWSTR lpBuffer,
    IN OUT LPDWORD nSize
    );
#ifdef UNICODE
#define GetComputerNameEx  GetComputerNameExW
#else
#define GetComputerNameEx  GetComputerNameExA
#endif 

WINBASEAPI
BOOL
WINAPI
SetComputerNameExA (
    IN COMPUTER_NAME_FORMAT NameType,
    IN LPCSTR lpBuffer
    );
WINBASEAPI
BOOL
WINAPI
SetComputerNameExW (
    IN COMPUTER_NAME_FORMAT NameType,
    IN LPCWSTR lpBuffer
    );
#ifdef UNICODE
#define SetComputerNameEx  SetComputerNameExW
#else
#define SetComputerNameEx  SetComputerNameExA
#endif 
    
WINBASEAPI
DWORD
WINAPI
AddLocalAlternateComputerNameA (
    IN LPCSTR lpDnsFQHostname,
    IN ULONG    ulFlags
    );
WINBASEAPI
DWORD
WINAPI
AddLocalAlternateComputerNameW (
    IN LPCWSTR lpDnsFQHostname,
    IN ULONG    ulFlags
    );
#ifdef UNICODE
#define AddLocalAlternateComputerName  AddLocalAlternateComputerNameW
#else
#define AddLocalAlternateComputerName  AddLocalAlternateComputerNameA
#endif 

WINBASEAPI
DWORD
WINAPI
RemoveLocalAlternateComputerNameA (
    IN LPCSTR lpAltDnsFQHostname,
    IN ULONG    ulFlags
    );
WINBASEAPI
DWORD
WINAPI
RemoveLocalAlternateComputerNameW (
    IN LPCWSTR lpAltDnsFQHostname,
    IN ULONG    ulFlags
    );
#ifdef UNICODE
#define RemoveLocalAlternateComputerName  RemoveLocalAlternateComputerNameW
#else
#define RemoveLocalAlternateComputerName  RemoveLocalAlternateComputerNameA
#endif 

WINBASEAPI
DWORD
WINAPI
SetLocalPrimaryComputerNameA (
    IN LPCSTR  lpAltDnsFQHostname,
    IN ULONG     ulFlags
    );
WINBASEAPI
DWORD
WINAPI
SetLocalPrimaryComputerNameW (
    IN LPCWSTR  lpAltDnsFQHostname,
    IN ULONG     ulFlags
    );
#ifdef UNICODE
#define SetLocalPrimaryComputerName  SetLocalPrimaryComputerNameW
#else
#define SetLocalPrimaryComputerName  SetLocalPrimaryComputerNameA
#endif 

typedef enum _COMPUTER_NAME_TYPE {
    PrimaryComputerName,
    AlternateComputerNames,
    AllComputerNames,
    ComputerNameTypeMax
} COMPUTER_NAME_TYPE ;

WINBASEAPI
DWORD
WINAPI
EnumerateLocalComputerNamesA (
    IN COMPUTER_NAME_TYPE        NameType,
    IN ULONG                     ulFlags,
    IN OUT LPSTR               lpDnsFQHostname,
    IN OUT LPDWORD               nSize
    );
WINBASEAPI
DWORD
WINAPI
EnumerateLocalComputerNamesW (
    IN COMPUTER_NAME_TYPE        NameType,
    IN ULONG                     ulFlags,
    IN OUT LPWSTR               lpDnsFQHostname,
    IN OUT LPDWORD               nSize
    );
#ifdef UNICODE
#define EnumerateLocalComputerNames  EnumerateLocalComputerNamesW
#else
#define EnumerateLocalComputerNames  EnumerateLocalComputerNamesA
#endif 

WINBASEAPI
BOOL
WINAPI
DnsHostnameToComputerNameA (
    IN LPCSTR Hostname,
    OUT LPSTR ComputerName,
    IN OUT LPDWORD nSize
    );
WINBASEAPI
BOOL
WINAPI
DnsHostnameToComputerNameW (
    IN LPCWSTR Hostname,
    OUT LPWSTR ComputerName,
    IN OUT LPDWORD nSize
    );
#ifdef UNICODE
#define DnsHostnameToComputerName  DnsHostnameToComputerNameW
#else
#define DnsHostnameToComputerName  DnsHostnameToComputerNameA
#endif 

#endif 

WINADVAPI
BOOL
WINAPI
GetUserNameA (
    OUT LPSTR lpBuffer,
    IN OUT LPDWORD nSize
    );
WINADVAPI
BOOL
WINAPI
GetUserNameW (
    OUT LPWSTR lpBuffer,
    IN OUT LPDWORD nSize
    );
#ifdef UNICODE
#define GetUserName  GetUserNameW
#else
#define GetUserName  GetUserNameA
#endif 

//

//

#define LOGON32_LOGON_INTERACTIVE       2
#define LOGON32_LOGON_NETWORK           3
#define LOGON32_LOGON_BATCH             4
#define LOGON32_LOGON_SERVICE           5
#define LOGON32_LOGON_UNLOCK            7
#if(_WIN32_WINNT >= 0x0500)
#define LOGON32_LOGON_NETWORK_CLEARTEXT 8
#define LOGON32_LOGON_NEW_CREDENTIALS   9
#endif 

#define LOGON32_PROVIDER_DEFAULT    0
#define LOGON32_PROVIDER_WINNT35    1
#if(_WIN32_WINNT >= 0x0400)
#define LOGON32_PROVIDER_WINNT40    2
#endif 
#if(_WIN32_WINNT >= 0x0500)
#define LOGON32_PROVIDER_WINNT50    3
#endif 



WINADVAPI
BOOL
WINAPI
LogonUserA (
    IN LPCSTR lpszUsername,
    IN LPCSTR lpszDomain,
    IN LPCSTR lpszPassword,
    IN DWORD dwLogonType,
    IN DWORD dwLogonProvider,
    OUT PHANDLE phToken
    );
WINADVAPI
BOOL
WINAPI
LogonUserW (
    IN LPCWSTR lpszUsername,
    IN LPCWSTR lpszDomain,
    IN LPCWSTR lpszPassword,
    IN DWORD dwLogonType,
    IN DWORD dwLogonProvider,
    OUT PHANDLE phToken
    );
#ifdef UNICODE
#define LogonUser  LogonUserW
#else
#define LogonUser  LogonUserA
#endif 

WINADVAPI
BOOL
WINAPI
LogonUserExA (
    IN LPCSTR lpszUsername,
    IN LPCSTR lpszDomain,
    IN LPCSTR lpszPassword,
    IN DWORD dwLogonType,
    IN DWORD dwLogonProvider,
    OUT PHANDLE phToken           OPTIONAL,
    OUT PSID  *ppLogonSid       OPTIONAL,
    OUT PVOID *ppProfileBuffer  OPTIONAL,
    OUT LPDWORD pdwProfileLength  OPTIONAL,
    OUT PQUOTA_LIMITS pQuotaLimits OPTIONAL
    );
WINADVAPI
BOOL
WINAPI
LogonUserExW (
    IN LPCWSTR lpszUsername,
    IN LPCWSTR lpszDomain,
    IN LPCWSTR lpszPassword,
    IN DWORD dwLogonType,
    IN DWORD dwLogonProvider,
    OUT PHANDLE phToken           OPTIONAL,
    OUT PSID  *ppLogonSid       OPTIONAL,
    OUT PVOID *ppProfileBuffer  OPTIONAL,
    OUT LPDWORD pdwProfileLength  OPTIONAL,
    OUT PQUOTA_LIMITS pQuotaLimits OPTIONAL
    );
#ifdef UNICODE
#define LogonUserEx  LogonUserExW
#else
#define LogonUserEx  LogonUserExA
#endif 

WINADVAPI
BOOL
WINAPI
ImpersonateLoggedOnUser(
    IN HANDLE  hToken
    );

WINADVAPI
BOOL
WINAPI
CreateProcessAsUserA (
    IN HANDLE hToken,
    IN LPCSTR lpApplicationName,
    IN LPSTR lpCommandLine,
    IN LPSECURITY_ATTRIBUTES lpProcessAttributes,
    IN LPSECURITY_ATTRIBUTES lpThreadAttributes,
    IN BOOL bInheritHandles,
    IN DWORD dwCreationFlags,
    IN LPVOID lpEnvironment,
    IN LPCSTR lpCurrentDirectory,
    IN LPSTARTUPINFOA lpStartupInfo,
    OUT LPPROCESS_INFORMATION lpProcessInformation
    );
WINADVAPI
BOOL
WINAPI
CreateProcessAsUserW (
    IN HANDLE hToken,
    IN LPCWSTR lpApplicationName,
    IN LPWSTR lpCommandLine,
    IN LPSECURITY_ATTRIBUTES lpProcessAttributes,
    IN LPSECURITY_ATTRIBUTES lpThreadAttributes,
    IN BOOL bInheritHandles,
    IN DWORD dwCreationFlags,
    IN LPVOID lpEnvironment,
    IN LPCWSTR lpCurrentDirectory,
    IN LPSTARTUPINFOW lpStartupInfo,
    OUT LPPROCESS_INFORMATION lpProcessInformation
    );
#ifdef UNICODE
#define CreateProcessAsUser  CreateProcessAsUserW
#else
#define CreateProcessAsUser  CreateProcessAsUserA
#endif 


#if(_WIN32_WINNT >= 0x0500)

//

//
#define LOGON_WITH_PROFILE              0x00000001
#define LOGON_NETCREDENTIALS_ONLY       0x00000002
#define LOGON_ZERO_PASSWORD_BUFFER      0x80000000

WINADVAPI
BOOL
WINAPI
CreateProcessWithLogonW(
      LPCWSTR lpUsername,
      LPCWSTR lpDomain,
      LPCWSTR lpPassword,
      DWORD   dwLogonFlags,
      LPCWSTR lpApplicationName,
      LPWSTR lpCommandLine,
      DWORD dwCreationFlags,
      LPVOID lpEnvironment,
      LPCWSTR lpCurrentDirectory,
      LPSTARTUPINFOW lpStartupInfo,
      LPPROCESS_INFORMATION lpProcessInformation
      );

WINADVAPI
BOOL
WINAPI
CreateProcessWithTokenW(
      HANDLE hToken,
      DWORD   dwLogonFlags,
      LPCWSTR lpApplicationName,
      LPWSTR lpCommandLine,
      DWORD dwCreationFlags,
      LPVOID lpEnvironment,
      LPCWSTR lpCurrentDirectory,
      LPSTARTUPINFOW lpStartupInfo,
      LPPROCESS_INFORMATION lpProcessInformation
      );

#endif 

WINADVAPI
BOOL
APIENTRY
ImpersonateAnonymousToken(
    IN HANDLE ThreadHandle
    );

WINADVAPI
BOOL
WINAPI
DuplicateTokenEx(
    IN HANDLE hExistingToken,
    IN DWORD dwDesiredAccess,
    IN LPSECURITY_ATTRIBUTES lpTokenAttributes,
    IN SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,
    IN TOKEN_TYPE TokenType,
    OUT PHANDLE phNewToken);

WINADVAPI
BOOL
APIENTRY
CreateRestrictedToken(
    IN HANDLE ExistingTokenHandle,
    IN DWORD Flags,
    IN DWORD DisableSidCount,
    IN PSID_AND_ATTRIBUTES SidsToDisable OPTIONAL,
    IN DWORD DeletePrivilegeCount,
    IN PLUID_AND_ATTRIBUTES PrivilegesToDelete OPTIONAL,
    IN DWORD RestrictedSidCount,
    IN PSID_AND_ATTRIBUTES SidsToRestrict OPTIONAL,
    OUT PHANDLE NewTokenHandle
    );


WINADVAPI
BOOL
WINAPI
IsTokenRestricted(
    IN HANDLE TokenHandle
    );

WINADVAPI
BOOL
WINAPI
IsTokenUntrusted(
    IN HANDLE TokenHandle
    );


BOOL
APIENTRY
CheckTokenMembership(
    IN HANDLE TokenHandle OPTIONAL,
    IN PSID SidToCheck,
    OUT PBOOL IsMember
    );

//

//

#if (_WIN32_WINNT >= 0x0500)

typedef WAITORTIMERCALLBACKFUNC WAITORTIMERCALLBACK ;

WINBASEAPI
BOOL
WINAPI
RegisterWaitForSingleObject(
    PHANDLE phNewWaitObject,
    HANDLE hObject,
    WAITORTIMERCALLBACK Callback,
    PVOID Context,
    ULONG dwMilliseconds,
    ULONG dwFlags
    );

WINBASEAPI
HANDLE
WINAPI
RegisterWaitForSingleObjectEx(
    HANDLE hObject,
    WAITORTIMERCALLBACK Callback,
    PVOID Context,
    ULONG dwMilliseconds,
    ULONG dwFlags
    );

WINBASEAPI
BOOL
WINAPI
UnregisterWait(
    HANDLE WaitHandle
    );

WINBASEAPI
BOOL
WINAPI
UnregisterWaitEx(
    HANDLE WaitHandle,
    HANDLE CompletionEvent
    );

WINBASEAPI
BOOL
WINAPI
QueueUserWorkItem(
    LPTHREAD_START_ROUTINE Function,
    PVOID Context,
    ULONG Flags
    );

WINBASEAPI
BOOL
WINAPI
BindIoCompletionCallback (
    HANDLE FileHandle,
    LPOVERLAPPED_COMPLETION_ROUTINE Function,
    ULONG Flags
    );

WINBASEAPI
HANDLE
WINAPI
CreateTimerQueue(
    VOID
    );

WINBASEAPI
BOOL
WINAPI
CreateTimerQueueTimer(
    PHANDLE phNewTimer,
    HANDLE TimerQueue,
    WAITORTIMERCALLBACK Callback,
    PVOID Parameter,
    DWORD DueTime,
    DWORD Period,
    ULONG Flags
    ) ;

WINBASEAPI
BOOL
WINAPI
ChangeTimerQueueTimer(
    HANDLE TimerQueue,
    HANDLE Timer,
    ULONG DueTime,
    ULONG Period
    );

WINBASEAPI
BOOL
WINAPI
DeleteTimerQueueTimer(
    HANDLE TimerQueue,
    HANDLE Timer,
    HANDLE CompletionEvent
    );

WINBASEAPI
BOOL
WINAPI
DeleteTimerQueueEx(
    HANDLE TimerQueue,
    HANDLE CompletionEvent
    );

WINBASEAPI
HANDLE
WINAPI
SetTimerQueueTimer(
    HANDLE TimerQueue,
    WAITORTIMERCALLBACK Callback,
    PVOID Parameter,
    DWORD DueTime,
    DWORD Period,
    BOOL PreferIo
    );

WINBASEAPI
BOOL
WINAPI
CancelTimerQueueTimer(
    HANDLE TimerQueue,
    HANDLE Timer
    );

WINBASEAPI
BOOL
WINAPI
DeleteTimerQueue(
    HANDLE TimerQueue
    );

#endif 


#if(_WIN32_WINNT >= 0x0400)
//

//

#define HW_PROFILE_GUIDLEN         39      
#define MAX_PROFILE_LEN            80

#define DOCKINFO_UNDOCKED          (0x1)
#define DOCKINFO_DOCKED            (0x2)
#define DOCKINFO_USER_SUPPLIED     (0x4)
#define DOCKINFO_USER_UNDOCKED     (DOCKINFO_USER_SUPPLIED | DOCKINFO_UNDOCKED)
#define DOCKINFO_USER_DOCKED       (DOCKINFO_USER_SUPPLIED | DOCKINFO_DOCKED)

typedef struct tagHW_PROFILE_INFOA {
    DWORD  dwDockInfo;
    CHAR   szHwProfileGuid[HW_PROFILE_GUIDLEN];
    CHAR   szHwProfileName[MAX_PROFILE_LEN];
} HW_PROFILE_INFOA, *LPHW_PROFILE_INFOA;
typedef struct tagHW_PROFILE_INFOW {
    DWORD  dwDockInfo;
    WCHAR  szHwProfileGuid[HW_PROFILE_GUIDLEN];
    WCHAR  szHwProfileName[MAX_PROFILE_LEN];
} HW_PROFILE_INFOW, *LPHW_PROFILE_INFOW;
#ifdef UNICODE
typedef HW_PROFILE_INFOW HW_PROFILE_INFO;
typedef LPHW_PROFILE_INFOW LPHW_PROFILE_INFO;
#else
typedef HW_PROFILE_INFOA HW_PROFILE_INFO;
typedef LPHW_PROFILE_INFOA LPHW_PROFILE_INFO;
#endif 


WINADVAPI
BOOL
WINAPI
GetCurrentHwProfileA (
    OUT LPHW_PROFILE_INFOA  lpHwProfileInfo
    );
WINADVAPI
BOOL
WINAPI
GetCurrentHwProfileW (
    OUT LPHW_PROFILE_INFOW  lpHwProfileInfo
    );
#ifdef UNICODE
#define GetCurrentHwProfile  GetCurrentHwProfileW
#else
#define GetCurrentHwProfile  GetCurrentHwProfileA
#endif 
#endif 

//

//

WINBASEAPI
BOOL
WINAPI
QueryPerformanceCounter(
    OUT LARGE_INTEGER *lpPerformanceCount
    );

WINBASEAPI
BOOL
WINAPI
QueryPerformanceFrequency(
    OUT LARGE_INTEGER *lpFrequency
    );



WINBASEAPI
BOOL
WINAPI
GetVersionExA(
    IN OUT LPOSVERSIONINFOA lpVersionInformation
    );
WINBASEAPI
BOOL
WINAPI
GetVersionExW(
    IN OUT LPOSVERSIONINFOW lpVersionInformation
    );
#ifdef UNICODE
#define GetVersionEx  GetVersionExW
#else
#define GetVersionEx  GetVersionExA
#endif 



WINBASEAPI
BOOL
WINAPI
VerifyVersionInfoA(
    IN LPOSVERSIONINFOEXA lpVersionInformation,
    IN DWORD dwTypeMask,
    IN DWORDLONG dwlConditionMask
    );
WINBASEAPI
BOOL
WINAPI
VerifyVersionInfoW(
    IN LPOSVERSIONINFOEXW lpVersionInformation,
    IN DWORD dwTypeMask,
    IN DWORDLONG dwlConditionMask
    );
#ifdef UNICODE
#define VerifyVersionInfo  VerifyVersionInfoW
#else
#define VerifyVersionInfo  VerifyVersionInfoA
#endif 



//

#include <winerror.h>



#define TC_NORMAL       0
#define TC_HARDERR      1
#define TC_GP_TRAP      2
#define TC_SIGNAL       3

#if(WINVER >= 0x0400)
//

//

#define AC_LINE_OFFLINE                 0x00
#define AC_LINE_ONLINE                  0x01
#define AC_LINE_BACKUP_POWER            0x02
#define AC_LINE_UNKNOWN                 0xFF

#define BATTERY_FLAG_HIGH               0x01
#define BATTERY_FLAG_LOW                0x02
#define BATTERY_FLAG_CRITICAL           0x04
#define BATTERY_FLAG_CHARGING           0x08
#define BATTERY_FLAG_NO_BATTERY         0x80
#define BATTERY_FLAG_UNKNOWN            0xFF

#define BATTERY_PERCENTAGE_UNKNOWN      0xFF

#define BATTERY_LIFE_UNKNOWN        0xFFFFFFFF

typedef struct _SYSTEM_POWER_STATUS {
    BYTE ACLineStatus;
    BYTE BatteryFlag;
    BYTE BatteryLifePercent;
    BYTE Reserved1;
    DWORD BatteryLifeTime;
    DWORD BatteryFullLifeTime;
}   SYSTEM_POWER_STATUS, *LPSYSTEM_POWER_STATUS;

BOOL
WINAPI
GetSystemPowerStatus(
    OUT LPSYSTEM_POWER_STATUS lpSystemPowerStatus
    );

BOOL
WINAPI
SetSystemPowerState(
    IN BOOL fSuspend,
    IN BOOL fForce
    );

#endif 

#if (_WIN32_WINNT >= 0x0500)
//

//

WINBASEAPI
BOOL
WINAPI
AllocateUserPhysicalPages(
    IN HANDLE hProcess,
    IN OUT PULONG_PTR NumberOfPages,
    OUT PULONG_PTR PageArray
    );

WINBASEAPI
BOOL
WINAPI
FreeUserPhysicalPages(
    IN HANDLE hProcess,
    IN OUT PULONG_PTR NumberOfPages,
    IN PULONG_PTR PageArray
    );

WINBASEAPI
BOOL
WINAPI
MapUserPhysicalPages(
    IN PVOID VirtualAddress,
    IN ULONG_PTR NumberOfPages,
    IN PULONG_PTR PageArray OPTIONAL
    );

WINBASEAPI
BOOL
WINAPI
MapUserPhysicalPagesScatter(
    IN PVOID *VirtualAddresses,
    IN ULONG_PTR NumberOfPages,
    IN PULONG_PTR PageArray OPTIONAL
    );

WINBASEAPI
HANDLE
WINAPI
CreateJobObjectA(
    IN LPSECURITY_ATTRIBUTES lpJobAttributes,
    IN LPCSTR lpName
    );
WINBASEAPI
HANDLE
WINAPI
CreateJobObjectW(
    IN LPSECURITY_ATTRIBUTES lpJobAttributes,
    IN LPCWSTR lpName
    );
#ifdef UNICODE
#define CreateJobObject  CreateJobObjectW
#else
#define CreateJobObject  CreateJobObjectA
#endif 

WINBASEAPI
HANDLE
WINAPI
OpenJobObjectA(
    IN DWORD dwDesiredAccess,
    IN BOOL bInheritHandle,
    IN LPCSTR lpName
    );
WINBASEAPI
HANDLE
WINAPI
OpenJobObjectW(
    IN DWORD dwDesiredAccess,
    IN BOOL bInheritHandle,
    IN LPCWSTR lpName
    );
#ifdef UNICODE
#define OpenJobObject  OpenJobObjectW
#else
#define OpenJobObject  OpenJobObjectA
#endif 

WINBASEAPI
BOOL
WINAPI
AssignProcessToJobObject(
    IN HANDLE hJob,
    IN HANDLE hProcess
    );

WINBASEAPI
BOOL
WINAPI
TerminateJobObject(
    IN HANDLE hJob,
    IN UINT uExitCode
    );

WINBASEAPI
BOOL
WINAPI
QueryInformationJobObject(
    IN HANDLE hJob,
    IN JOBOBJECTINFOCLASS JobObjectInformationClass,
    OUT LPVOID lpJobObjectInformation,
    IN DWORD cbJobObjectInformationLength,
    OUT LPDWORD lpReturnLength
    );

WINBASEAPI
BOOL
WINAPI
SetInformationJobObject(
    IN HANDLE hJob,
    IN JOBOBJECTINFOCLASS JobObjectInformationClass,
    IN LPVOID lpJobObjectInformation,
    IN DWORD cbJobObjectInformationLength
    );

WINBASEAPI
BOOL
WINAPI
IsProcessInJob (
    IN HANDLE ProcessHandle,
    IN HANDLE JobHandle,
    OUT PBOOL Result
    );


WINBASEAPI
BOOL
WINAPI
CreateJobSet (
    IN ULONG NumJob,
    IN PJOB_SET_ARRAY UserJobSet,
    IN ULONG Flags);


WINBASEAPI
PVOID
WINAPI
AddVectoredExceptionHandler(
    IN ULONG FirstHandler,
    IN PVECTORED_EXCEPTION_HANDLER VectoredHandler
    );

WINBASEAPI
ULONG
WINAPI
RemoveVectoredExceptionHandler(
    IN PVOID VectoredHandlerHandle
    );

//

//

WINBASEAPI
HANDLE
WINAPI
FindFirstVolumeA(
    LPSTR lpszVolumeName,
    DWORD cchBufferLength
    );
WINBASEAPI
HANDLE
WINAPI
FindFirstVolumeW(
    LPWSTR lpszVolumeName,
    DWORD cchBufferLength
    );
#ifdef UNICODE
#define FindFirstVolume FindFirstVolumeW
#else
#define FindFirstVolume FindFirstVolumeA
#endif 

WINBASEAPI
BOOL
WINAPI
FindNextVolumeA(
    HANDLE hFindVolume,
    LPSTR lpszVolumeName,
    DWORD cchBufferLength
    );
WINBASEAPI
BOOL
WINAPI
FindNextVolumeW(
    HANDLE hFindVolume,
    LPWSTR lpszVolumeName,
    DWORD cchBufferLength
    );
#ifdef UNICODE
#define FindNextVolume FindNextVolumeW
#else
#define FindNextVolume FindNextVolumeA
#endif 

WINBASEAPI
BOOL
WINAPI
FindVolumeClose(
    HANDLE hFindVolume
    );

WINBASEAPI
HANDLE
WINAPI
FindFirstVolumeMountPointA(
    LPCSTR lpszRootPathName,
    LPSTR lpszVolumeMountPoint,
    DWORD cchBufferLength
    );
WINBASEAPI
HANDLE
WINAPI
FindFirstVolumeMountPointW(
    LPCWSTR lpszRootPathName,
    LPWSTR lpszVolumeMountPoint,
    DWORD cchBufferLength
    );
#ifdef UNICODE
#define FindFirstVolumeMountPoint FindFirstVolumeMountPointW
#else
#define FindFirstVolumeMountPoint FindFirstVolumeMountPointA
#endif 

WINBASEAPI
BOOL
WINAPI
FindNextVolumeMountPointA(
    HANDLE hFindVolumeMountPoint,
    LPSTR lpszVolumeMountPoint,
    DWORD cchBufferLength
    );
WINBASEAPI
BOOL
WINAPI
FindNextVolumeMountPointW(
    HANDLE hFindVolumeMountPoint,
    LPWSTR lpszVolumeMountPoint,
    DWORD cchBufferLength
    );
#ifdef UNICODE
#define FindNextVolumeMountPoint FindNextVolumeMountPointW
#else
#define FindNextVolumeMountPoint FindNextVolumeMountPointA
#endif 

WINBASEAPI
BOOL
WINAPI
FindVolumeMountPointClose(
    HANDLE hFindVolumeMountPoint
    );

WINBASEAPI
BOOL
WINAPI
SetVolumeMountPointA(
    LPCSTR lpszVolumeMountPoint,
    LPCSTR lpszVolumeName
    );
WINBASEAPI
BOOL
WINAPI
SetVolumeMountPointW(
    LPCWSTR lpszVolumeMountPoint,
    LPCWSTR lpszVolumeName
    );
#ifdef UNICODE
#define SetVolumeMountPoint  SetVolumeMountPointW
#else
#define SetVolumeMountPoint  SetVolumeMountPointA
#endif 

WINBASEAPI
BOOL
WINAPI
DeleteVolumeMountPointA(
    LPCSTR lpszVolumeMountPoint
    );
WINBASEAPI
BOOL
WINAPI
DeleteVolumeMountPointW(
    LPCWSTR lpszVolumeMountPoint
    );
#ifdef UNICODE
#define DeleteVolumeMountPoint  DeleteVolumeMountPointW
#else
#define DeleteVolumeMountPoint  DeleteVolumeMountPointA
#endif 

WINBASEAPI
BOOL
WINAPI
GetVolumeNameForVolumeMountPointA(
    LPCSTR lpszVolumeMountPoint,
    LPSTR lpszVolumeName,
    DWORD cchBufferLength
    );
WINBASEAPI
BOOL
WINAPI
GetVolumeNameForVolumeMountPointW(
    LPCWSTR lpszVolumeMountPoint,
    LPWSTR lpszVolumeName,
    DWORD cchBufferLength
    );
#ifdef UNICODE
#define GetVolumeNameForVolumeMountPoint  GetVolumeNameForVolumeMountPointW
#else
#define GetVolumeNameForVolumeMountPoint  GetVolumeNameForVolumeMountPointA
#endif 

WINBASEAPI
BOOL
WINAPI
GetVolumePathNameA(
    LPCSTR lpszFileName,
    LPSTR lpszVolumePathName,
    DWORD cchBufferLength
    );
WINBASEAPI
BOOL
WINAPI
GetVolumePathNameW(
    LPCWSTR lpszFileName,
    LPWSTR lpszVolumePathName,
    DWORD cchBufferLength
    );
#ifdef UNICODE
#define GetVolumePathName  GetVolumePathNameW
#else
#define GetVolumePathName  GetVolumePathNameA
#endif 

WINBASEAPI
BOOL
WINAPI
GetVolumePathNamesForVolumeNameA(
    LPCSTR lpszVolumeName,
    LPSTR lpszVolumePathNames,
    DWORD cchBufferLength,
    PDWORD lpcchReturnLength
    );
WINBASEAPI
BOOL
WINAPI
GetVolumePathNamesForVolumeNameW(
    LPCWSTR lpszVolumeName,
    LPWSTR lpszVolumePathNames,
    DWORD cchBufferLength,
    PDWORD lpcchReturnLength
    );
#ifdef UNICODE
#define GetVolumePathNamesForVolumeName  GetVolumePathNamesForVolumeNameW
#else
#define GetVolumePathNamesForVolumeName  GetVolumePathNamesForVolumeNameA
#endif 

#endif

#if (_WIN32_WINNT >= 0x0500) || (_WIN32_FUSION >= 0x0100) || ISOLATION_AWARE_ENABLED

#define ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID    (0x00000001)
#define ACTCTX_FLAG_LANGID_VALID                    (0x00000002)
#define ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID        (0x00000004)
#define ACTCTX_FLAG_RESOURCE_NAME_VALID             (0x00000008)
#define ACTCTX_FLAG_SET_PROCESS_DEFAULT             (0x00000010)
#define ACTCTX_FLAG_APPLICATION_NAME_VALID          (0x00000020)
#define ACTCTX_FLAG_SOURCE_IS_ASSEMBLYREF           (0x00000040)
#define ACTCTX_FLAG_HMODULE_VALID                   (0x00000080)

typedef struct tagACTCTXA {
    ULONG       cbSize;
    DWORD       dwFlags;
    LPCSTR      lpSource;
    USHORT      wProcessorArchitecture;
    LANGID      wLangId;
    LPCSTR      lpAssemblyDirectory;
    LPCSTR      lpResourceName;
    LPCSTR      lpApplicationName;
    HMODULE     hModule;
} ACTCTXA, *PACTCTXA;
typedef struct tagACTCTXW {
    ULONG       cbSize;
    DWORD       dwFlags;
    LPCWSTR     lpSource;
    USHORT      wProcessorArchitecture;
    LANGID      wLangId;
    LPCWSTR     lpAssemblyDirectory;
    LPCWSTR     lpResourceName;
    LPCWSTR     lpApplicationName;
    HMODULE     hModule;
} ACTCTXW, *PACTCTXW;
#ifdef UNICODE
typedef ACTCTXW ACTCTX;
typedef PACTCTXW PACTCTX;
#else
typedef ACTCTXA ACTCTX;
typedef PACTCTXA PACTCTX;
#endif 

typedef const ACTCTXA *PCACTCTXA;
typedef const ACTCTXW *PCACTCTXW;
#ifdef UNICODE
typedef ACTCTXW ACTCTX;
typedef PCACTCTXW PCACTCTX;
#else
typedef ACTCTXA ACTCTX;
typedef PCACTCTXA PCACTCTX;
#endif 

#endif

#if (_WIN32_WINNT >= 0x0500) || (_WIN32_FUSION >= 0x0100)


WINBASEAPI
HANDLE
WINAPI
CreateActCtxA(
    PCACTCTXA pActCtx
    );
WINBASEAPI
HANDLE
WINAPI
CreateActCtxW(
    PCACTCTXW pActCtx
    );
#ifdef UNICODE
#define CreateActCtx  CreateActCtxW
#else
#define CreateActCtx  CreateActCtxA
#endif 

WINBASEAPI
VOID
WINAPI
AddRefActCtx(
    HANDLE hActCtx
    );


WINBASEAPI
VOID
WINAPI
ReleaseActCtx(
    HANDLE hActCtx
    );

WINBASEAPI
BOOL
WINAPI
ZombifyActCtx(
    HANDLE hActCtx
    );


WINBASEAPI
BOOL
WINAPI
ActivateActCtx(
    HANDLE hActCtx,
    ULONG_PTR *lpCookie
    );


#define DEACTIVATE_ACTCTX_FLAG_FORCE_EARLY_DEACTIVATION (0x00000001)

WINBASEAPI
BOOL
WINAPI
DeactivateActCtx(
    DWORD dwFlags,
    ULONG_PTR ulCookie
    );

WINBASEAPI
BOOL
WINAPI
GetCurrentActCtx(
    HANDLE *lphActCtx);

#endif

#if (_WIN32_WINNT >= 0x0500) || (_WIN32_FUSION >= 0x0100) || ISOLATION_AWARE_ENABLED

typedef struct tagACTCTX_SECTION_KEYED_DATA_2600 {
    ULONG cbSize;
    ULONG ulDataFormatVersion;
    PVOID lpData;
    ULONG ulLength;
    PVOID lpSectionGlobalData;
    ULONG ulSectionGlobalDataLength;
    PVOID lpSectionBase;
    ULONG ulSectionTotalLength;
    HANDLE hActCtx;
    ULONG ulAssemblyRosterIndex;
} ACTCTX_SECTION_KEYED_DATA_2600, *PACTCTX_SECTION_KEYED_DATA_2600;
typedef const ACTCTX_SECTION_KEYED_DATA_2600 * PCACTCTX_SECTION_KEYED_DATA_2600;

typedef struct tagACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA {
    PVOID lpInformation;
    PVOID lpSectionBase;
    ULONG ulSectionLength;
    PVOID lpSectionGlobalDataBase;
    ULONG ulSectionGlobalDataLength;
} ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA, *PACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA;
typedef const ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA *PCACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA;

typedef struct tagACTCTX_SECTION_KEYED_DATA {
    ULONG cbSize;
    ULONG ulDataFormatVersion;
    PVOID lpData;
    ULONG ulLength;
    PVOID lpSectionGlobalData;
    ULONG ulSectionGlobalDataLength;
    PVOID lpSectionBase;
    ULONG ulSectionTotalLength;
    HANDLE hActCtx;
    ULONG ulAssemblyRosterIndex;

    ULONG ulFlags;
    ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA AssemblyMetadata;
} ACTCTX_SECTION_KEYED_DATA, *PACTCTX_SECTION_KEYED_DATA;
typedef const ACTCTX_SECTION_KEYED_DATA * PCACTCTX_SECTION_KEYED_DATA;

#define FIND_ACTCTX_SECTION_KEY_RETURN_HACTCTX (0x00000001)
#define FIND_ACTCTX_SECTION_KEY_RETURN_FLAGS   (0x00000002)
#define FIND_ACTCTX_SECTION_KEY_RETURN_ASSEMBLY_METADATA (0x00000004)

#endif

#if (_WIN32_WINNT >= 0x0500) || (_WIN32_FUSION >= 0x0100)


WINBASEAPI
BOOL
WINAPI
FindActCtxSectionStringA(
    DWORD dwFlags,
    const GUID *lpExtensionGuid,
    ULONG ulSectionId,
    LPCSTR lpStringToFind,
    PACTCTX_SECTION_KEYED_DATA ReturnedData
    );
WINBASEAPI
BOOL
WINAPI
FindActCtxSectionStringW(
    DWORD dwFlags,
    const GUID *lpExtensionGuid,
    ULONG ulSectionId,
    LPCWSTR lpStringToFind,
    PACTCTX_SECTION_KEYED_DATA ReturnedData
    );
#ifdef UNICODE
#define FindActCtxSectionString  FindActCtxSectionStringW
#else
#define FindActCtxSectionString  FindActCtxSectionStringA
#endif 

WINBASEAPI
BOOL
WINAPI
FindActCtxSectionGuid(
    DWORD dwFlags,
    const GUID *lpExtensionGuid,
    ULONG ulSectionId,
    const GUID *lpGuidToFind,
    PACTCTX_SECTION_KEYED_DATA ReturnedData
    );

#endif

#if (_WIN32_WINNT >= 0x0500) || (_WIN32_FUSION >= 0x0100) || ISOLATION_AWARE_ENABLED

#if !defined(RC_INVOKED) 
#if !defined(ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED)

typedef struct _ACTIVATION_CONTEXT_BASIC_INFORMATION {
    HANDLE  hActCtx;
    DWORD   dwFlags;
} ACTIVATION_CONTEXT_BASIC_INFORMATION, *PACTIVATION_CONTEXT_BASIC_INFORMATION;

typedef const struct _ACTIVATION_CONTEXT_BASIC_INFORMATION *PCACTIVATION_CONTEXT_BASIC_INFORMATION;

#define ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED 1

#endif 
#endif

#define QUERY_ACTCTX_FLAG_USE_ACTIVE_ACTCTX (0x00000004)
#define QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE (0x00000008)
#define QUERY_ACTCTX_FLAG_ACTCTX_IS_ADDRESS (0x00000010)
#define QUERY_ACTCTX_FLAG_NO_ADDREF         (0x80000000)

#endif

#if (_WIN32_WINNT >= 0x0500) || (_WIN32_FUSION >= 0x0100)


//

//



//



//




//





//

//
WINBASEAPI
BOOL
WINAPI
QueryActCtxW(
    IN DWORD dwFlags,
    IN HANDLE hActCtx,
    IN PVOID pvSubInstance,
    IN ULONG ulInfoClass,
    OUT PVOID pvBuffer,
    IN SIZE_T cbBuffer OPTIONAL,
    OUT SIZE_T *pcbWrittenOrRequired OPTIONAL
    );

typedef BOOL (WINAPI * PQUERYACTCTXW_FUNC)(
    IN DWORD dwFlags,
    IN HANDLE hActCtx,
    IN PVOID pvSubInstance,
    IN ULONG ulInfoClass,
    OUT PVOID pvBuffer,
    IN SIZE_T cbBuffer OPTIONAL,
    OUT SIZE_T *pcbWrittenOrRequired OPTIONAL
    );

#endif 


WINBASEAPI
BOOL
WINAPI
ProcessIdToSessionId(
    IN  DWORD dwProcessId,
    OUT DWORD *pSessionId
    );

#if _WIN32_WINNT >= 0x0501

WINBASEAPI
DWORD
WINAPI
WTSGetActiveConsoleSessionId();

WINBASEAPI
BOOL
WINAPI
IsWow64Process(
    HANDLE hProcess,
    PBOOL Wow64Process
    );

#endif 

WINBASEAPI
BOOL
WINAPI
GetLogicalProcessorInformation(
    PSYSTEM_LOGICAL_PROCESSOR_INFORMATION Buffer,
    PDWORD ReturnedLength
    );

//

//

WINBASEAPI
BOOL
WINAPI
GetNumaHighestNodeNumber(
    PULONG HighestNodeNumber
    );

WINBASEAPI
BOOL
WINAPI
GetNumaProcessorNode(
    UCHAR Processor,
    PUCHAR NodeNumber
    );

WINBASEAPI
BOOL
WINAPI
GetNumaNodeProcessorMask(
    UCHAR Node,
    PULONGLONG ProcessorMask
    );

WINBASEAPI
BOOL
WINAPI
GetNumaAvailableMemoryNode(
    UCHAR Node,
    PULONGLONG AvailableBytes
    );



#if !defined(RC_INVOKED) 
#if defined(ISOLATION_AWARE_ENABLED) && (ISOLATION_AWARE_ENABLED != 0)
#include "winbase.inl"
#endif 
#endif 

#ifdef __cplusplus
}
#endif



#endif 

