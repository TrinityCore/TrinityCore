/*****************************************************************************/
/* CascRootFile_Text.cpp                  Copyright (c) Ladislav Zezula 2017 */
/*---------------------------------------------------------------------------*/
/* Support for generic ROOT handler with mapping of FileName -> CKey         */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 28.10.15  1.00  Lad  The first version of CascRootFile_Text.cpp           */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "CascLib.h"
#include "CascCommon.h"

//-----------------------------------------------------------------------------
// Handler definitions for Starcraft I root file

struct TRootHandler_SC1 : public TFileTreeRoot
{
    public:

    TRootHandler_SC1() : TFileTreeRoot(0)
    {
        // We have file names and return CKey as result of search
        dwFeatures |= (CASC_FEATURE_FILE_NAMES | CASC_FEATURE_ROOT_CKEY);
    }

    static bool IsRootFile(LPBYTE pbRootFile, DWORD cbRootFile)
    {
        CASC_CSV Csv(1, false);
        size_t nColumns;
        bool bResult = false;

        // Get the first line from the listfile
        if(Csv.Load(pbRootFile, cbRootFile) == ERROR_SUCCESS)
        {
            // There must be 2 or 3 elements
            nColumns = Csv[CSV_ZERO].GetColumnCount();
            if (nColumns == 2 || nColumns == 3)
            {
                const CASC_CSV_COLUMN & FileName = Csv[CSV_ZERO][CSV_ZERO];
                const CASC_CSV_COLUMN & CKeyStr = Csv[CSV_ZERO][1];

                bResult = (FileName.szValue && CKeyStr.szValue && CKeyStr.nLength == MD5_STRING_SIZE);
            }
        }

        // We need to reset the listfile to the begin position
        return bResult;
    }

    DWORD Load(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile)
    {
        PCASC_CKEY_ENTRY pCKeyEntry;
        CASC_CSV Csv(0, false);
        BYTE CKey[MD5_HASH_SIZE];
        DWORD dwErrCode;

        // Parse the ROOT file first in order to see whether we have the correct format
        dwErrCode = Csv.Load(pbRootFile, cbRootFile);
        if(dwErrCode == ERROR_SUCCESS)
        {
            // Parse all lines
            while(Csv.LoadNextLine())
            {
                const CASC_CSV_COLUMN & FileName = Csv[CSV_ZERO][CSV_ZERO];
                const CASC_CSV_COLUMN & CKeyStr = Csv[CSV_ZERO][1];

                // Convert the CKey to binary
                if(BinaryFromString(CKeyStr.szValue, MD5_STRING_SIZE, CKey) == ERROR_SUCCESS)
                {
                    // Verify whether it is a known entry
                    if((pCKeyEntry = FindCKeyEntry_CKey(hs, CKey)) != NULL)
                    {
                        // Insert the FileName+CKey to the file tree
                        FileTree.InsertByName(pCKeyEntry, FileName.szValue);
                    }
                }
            }
        }

        return dwErrCode;
    }
};

//-----------------------------------------------------------------------------
// Public functions

//
// Starcraft ROOT file is a text file with the following format:
// HD2/portraits/NBluCrit/NLCFID01.webm|c2795b120592355d45eba9cdc37f691e
// locales/enUS/Assets/campaign/EXPZerg/Zerg08/staredit/wav/zovtra01.ogg|316b0274bf2dabaa8db60c3ff1270c85
// locales/zhCN/Assets/sound/terran/ghost/tghdth01.wav|6637ed776bd22089e083b8b0b2c0374c
//

DWORD RootHandler_CreateStarcraft1(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile)
{
    TRootHandler_SC1 * pRootHandler = NULL;
    DWORD dwErrCode = ERROR_BAD_FORMAT;

    // Verify whether this looks like a Starcraft I root file
    if(TRootHandler_SC1::IsRootFile(pbRootFile, cbRootFile))
    {
        // Allocate the root handler object
        pRootHandler = new TRootHandler_SC1();
        if(pRootHandler != NULL)
        {
            // Load the root directory. If load failed, we free the object
            dwErrCode = pRootHandler->Load(hs, pbRootFile, cbRootFile);
            if(dwErrCode != ERROR_SUCCESS)
            {
                delete pRootHandler;
                pRootHandler = NULL;
            }
        }
    }

    // Assign the root directory (or NULL) and return error
    hs->pRootHandler = pRootHandler;
    return dwErrCode;
}
