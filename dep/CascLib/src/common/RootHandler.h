/*****************************************************************************/
/* RootHandler.h                          Copyright (c) Ladislav Zezula 2015 */
/*---------------------------------------------------------------------------*/
/* Interface for root handlers                                               */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 09.03.15  1.00  Lad  Created                                              */
/*****************************************************************************/

#ifndef __ROOT_HANDLER_H__
#define __ROOT_HANDLER_H__

//-----------------------------------------------------------------------------
// Defines

#define CASC_MNDX_ROOT_SIGNATURE        0x58444E4D  // 'MNDX'
#define CASC_DIABLO3_ROOT_SIGNATURE     0x8007D0C4
#define CASC_OVERWATCH_ROOT_SIGNATURE   0x35444D23  // '#MD5'

#define ROOT_FLAG_HAS_NAMES             0x00000001  // The root file contains file names

#define DUMP_LEVEL_ROOT_FILE                    1   // Dump root file
#define DUMP_LEVEL_ENCODING_FILE                2   // Dump root file + encoding file
#define DUMP_LEVEL_INDEX_ENTRIES                3   // Dump root file + encoding file + index entries

//-----------------------------------------------------------------------------
// Root file function prototypes

typedef int (*ROOT_INSERT)(
    struct TRootHandler * pRootHandler,             // Pointer to an initialized root handler
    const char * szFileName,                        // Pointer to the file name
    LPBYTE pbEncodingKey                            // Pointer to the encoding key of the file name
    );

typedef LPBYTE (*ROOT_SEARCH)(
    struct TRootHandler * pRootHandler,             // Pointer to an initialized root handler
    struct _TCascSearch * pSearch,                  // Pointer to the initialized search structure
    PDWORD PtrFileSize,                             // Pointer to receive file size (optional)
    PDWORD PtrLocaleFlags                           // Pointer to receive locale flags (optional)
    );

typedef void (*ROOT_ENDSEARCH)(
    struct TRootHandler * pRootHandler,             // Pointer to an initialized root handler
    struct _TCascSearch * pSearch                   // Pointer to the initialized search structure
    );

typedef LPBYTE (*ROOT_GETKEY)(
    struct TRootHandler * pRootHandler,             // Pointer to an initialized root handler
    const char * szFileName                         // Pointer to the name of a file
    );

typedef void (*ROOT_DUMP)(
    struct _TCascStorage * hs,                      // Pointer to the open storage
    TDumpContext * dc,                              // Opened dump context
    LPBYTE pbRootHandler,                           // Pointer to the loaded ROOT file
    DWORD cbRootHandler,                            // Length of the loaded ROOT file
    const TCHAR * szListFile,
    int nDumpLevel
    );

typedef void (*ROOT_CLOSE)(
    struct TRootHandler * pRootHandler              // Pointer to an initialized root handler
    );

struct TRootHandler
{
    ROOT_INSERT    Insert;                          // Inserts an existing file name
    ROOT_SEARCH    Search;                          // Performs the root file search
    ROOT_ENDSEARCH EndSearch;                       // Performs cleanup after searching
    ROOT_GETKEY    GetKey;                          // Retrieves encoding key for a file name
    ROOT_DUMP      Dump;
    ROOT_CLOSE     Close;                           // Closing the root file

    DWORD dwRootFlags;                              // Root flags - see the ROOT_FLAG_XXX
};

//-----------------------------------------------------------------------------
// Public functions

int    RootHandler_Insert(TRootHandler * pRootHandler, const char * szFileName, LPBYTE pbEncodingKey);
LPBYTE RootHandler_Search(TRootHandler * pRootHandler, struct _TCascSearch * pSearch, PDWORD PtrFileSize, PDWORD PtrLocaleFlags);
void   RootHandler_EndSearch(TRootHandler * pRootHandler, struct _TCascSearch * pSearch);
LPBYTE RootHandler_GetKey(TRootHandler * pRootHandler, const char * szFileName);
void   RootHandler_Dump(struct _TCascStorage * hs, LPBYTE pbRootHandler, DWORD cbRootHandler, const TCHAR * szNameFormat, const TCHAR * szListFile, int nDumpLevel);
void   RootHandler_Close(TRootHandler * pRootHandler);

#endif  // __ROOT_HANDLER_H__
