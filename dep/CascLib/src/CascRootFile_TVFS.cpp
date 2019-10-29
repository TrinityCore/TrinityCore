/*****************************************************************************/
/* CascRootFile_TVFS.cpp                  Copyright (c) Ladislav Zezula 2018 */
/*---------------------------------------------------------------------------*/
/* ROOT handler for TACT VFS manifest format (root)                          */
/* Note: TACT = Trusted Application Content Transfer                         */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 24.05.18  1.00  Lad  The first version of CascRootFile_TVFS.cpp           */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "CascLib.h"
#include "CascCommon.h"

//-----------------------------------------------------------------------------
// Local defines

#define TVFS_FLAG_INCLUDE_CKEY       0x0001         // Include C-key in content file record
#define TVFS_FLAG_WRITE_SUPPORT      0x0002         // Write support. Include a table of encoding specifiers. This is required for writing files to the underlying storage. This bit is implied by the patch-support bit
#define TVFS_FLAG_PATCH_SUPPORT      0x0004         // Patch support. Include patch records in the content file records.
#define TVFS_FLAG_LOWERCASE_MANIFEST 0x0008         // Lowercase manifest. All paths in the path table have been converted to ASCII lowercase (i.e. [A-Z] converted to [a-z])

#define TVFS_PTE_PATH_SEPARATOR_PRE  0x0001         // There is path separator before the name
#define TVFS_PTE_PATH_SEPARATOR_POST 0x0002         // There is path separator after the name
#define TVFS_PTE_NODE_VALUE          0x0004         // The NodeValue in path table entry is valid

#define TVFS_FOLDER_NODE            0x80000000      // Highest bit is set if a file node is a folder
#define TVFS_FOLDER_SIZE_MASK       0x7FFFFFFF      // Mask to get length of the folder

//-----------------------------------------------------------------------------
// Local structures

// In-memory layout of the TVFS file header
typedef struct _TVFS_DIRECTORY_HEADER
{
    DWORD Signature;                                // Must be CASC_TVFS_ROOT_SIGNATURE
    BYTE  FormatVersion;                            // Version of the format. Should be 1.
    BYTE  HeaderSize;                               // Size of the header, in bytes
    BYTE  EKeySize;                                 // Size of an E-Key. TACT uses 9-byte E-keys
    BYTE  PatchKeySize;                             // Size of a patch key. TACT uses 9-byte P-keys
    DWORD Flags;                                    // Flags. See TVFS_FLAG_XXX

    // Followed by the offset table (variable length)
    DWORD  PathTableOffset;                         // Offset of the path table
    DWORD  PathTableSize;                           // Size of the path table
    DWORD  VfsTableOffset;                          // Offset of the VFS table
    DWORD  VfsTableSize;                            // Size of the VFS table
    DWORD  CftTableOffset;                          // Offset of the container file table
    DWORD  CftTableSize;                            // Size of the container file table
    USHORT MaxDepth;                                // The maximum depth of the path prefix tree stored in the path table
    DWORD  EstTableOffset;                          // The offset of the encoding specifier table. Only if the write-support bit is set in the header flag
    DWORD  EstTableSize;                            // The size of the encoding specifier table. Only if the write-support bit is set in the header flag

    DWORD  CftOffsSize;                             // Byte length of the offset in the Content File Table entry
    DWORD  EstOffsSize;                             // Byte length of the offset in the Encoding Specifier Table entry

    LPBYTE pbDirectoryData;                         // Pointer to the begin of directory data
    LPBYTE pbDirectoryEnd;                          // Pointer to the end of directory data

//  LPBYTE pbPathFileTable;                         // Begin and end of the path table
//  LPBYTE pbPathTableEnd;

//  LPBYTE pbVfsFileTable;                          // Begin and end of the VFS file table
//  LPBYTE pbVfsTableEnd;

//  LPBYTE pbCftFileTable;                          // Begin and end of the content file table
//  LPBYTE pbCftTableEnd;

} TVFS_DIRECTORY_HEADER, *PTVFS_DIRECTORY_HEADER;

/*
// Minimum size of a valid path table entry. 1 byte + 1-byte name + 1 byte + DWORD
#define TVFS_HEADER_LENGTH FIELD_OFFSET(TVFS_DIRECTORY_HEADER, CftOffsSize)

// Minimum size of a valid path table entry. 1 byte + 1-byte name + 1 byte + DWORD
#define TVFS_MIN_PATH_ENTRY (1 + 1 + 1 + sizeof(DWORD)) 

// Minimum size of the VFS entry (SpanCount + FileOffset + SpanLength + CftOffset)
#define TVFS_MIN_VFS_ENTRY (1 + sizeof(DWORD) + sizeof(DWORD) + 1)

// Minimum size of the Content File Table entry (CASC_EKEY_SIZE + EncodedSize + ContentSize)
#define TVFS_MIN_CFT_ENTRY (CASC_EKEY_SIZE + sizeof(DWORD) + sizeof(DWORD))

// Minimum size of the TVFS folder data
#define TVFS_MIN_FILE_SIZE (TVFS_HEADER_LENGTH + TVFS_MIN_PATH_ENTRY + TVFS_MIN_VFS_ENTRY + TVFS_MIN_CFT_ENTRY)

// Maximum estimated file table. Empirically set to 8 MB, increase if needed.
#define TVFS_MAX_FILE_SIZE 0x00800000
*/

// In-memory layout of the path table entry
typedef struct _TVFS_PATH_TABLE_ENTRY
{
    LPBYTE pbNamePtr;                               // Pointer to the begin of the node name
    LPBYTE pbNameEnd;                               // Pointer to the end of the file name
    DWORD NodeFlags;                                // TVFS_PTE_XXX
    DWORD NodeValue;                                // Node value
} TVFS_PATH_TABLE_ENTRY, *PTVFS_PATH_TABLE_ENTRY;

//-----------------------------------------------------------------------------
// Handler definition for TVFS root file

// Structure for the root handler
struct TRootHandler_TVFS : public TFileTreeRoot
{
    public:

    TRootHandler_TVFS() : TFileTreeRoot(0)
    {
        // TVFS supports file names, but DOESN'T support CKeys.
        dwFeatures |= CASC_FEATURE_FILE_NAMES;
    }

    // Returns size of "container file table offset" field in the VFS.
    // - If the container file table is larger than 0xffffff bytes, it's 4 bytes
    // - If the container file table is larger than 0xffff bytes, it's 3 bytes
    // - If the container file table is larger than 0xff bytes, it's 2 bytes
    // - If the container file table is smaller than 0xff bytes, it's 1 byte
    static DWORD GetOffsetFieldSize(DWORD dwTableSize)
    {
        if(dwTableSize > 0xffffff)
            return 4;
        if(dwTableSize > 0xffff)
            return 3;
        if(dwTableSize > 0xff)
            return 2;
        return 1;
    }

    bool PathBuffer_AppendNode(CASC_PATH<char> & PathBuffer, TVFS_PATH_TABLE_ENTRY & PathEntry)
    {
        // Append the prefix separator, if needed
        if (PathEntry.NodeFlags & TVFS_PTE_PATH_SEPARATOR_PRE)
            PathBuffer.AppendChar('/');

        // Append the name fragment, if any
        if (PathEntry.pbNameEnd > PathEntry.pbNamePtr)
            PathBuffer.AppendStringN((const char *)PathEntry.pbNamePtr, (PathEntry.pbNameEnd - PathEntry.pbNamePtr), false);

        // Append the postfix separator, if needed
        if (PathEntry.NodeFlags & TVFS_PTE_PATH_SEPARATOR_POST)
            PathBuffer.AppendChar('/');

        return true;
    }

    static DWORD CaptureDirectoryHeader(TVFS_DIRECTORY_HEADER & DirHeader, LPBYTE pbDataPtr, LPBYTE pbDataEnd)
    {
        // Fill the header structure with zeros
        memset(&DirHeader, 0, sizeof(TVFS_DIRECTORY_HEADER));
        DirHeader.pbDirectoryData = pbDataPtr;
        DirHeader.pbDirectoryEnd = pbDataEnd;

        // Capture the signature
        pbDataPtr = CaptureInteger32(pbDataPtr, pbDataEnd, &DirHeader.Signature);
        if(pbDataPtr == NULL || DirHeader.Signature != CASC_TVFS_ROOT_SIGNATURE)
            return ERROR_BAD_FORMAT;

        // Capture the other four integers 
        pbDataPtr = CaptureByteArray(pbDataPtr, pbDataEnd, 4, &DirHeader.FormatVersion);
        if(pbDataPtr == NULL || DirHeader.FormatVersion != 1 || DirHeader.EKeySize != 9 || DirHeader.PatchKeySize != 9 || DirHeader.HeaderSize < 8)
            return ERROR_BAD_FORMAT;

        // Capture the rest
        pbDataPtr = CaptureByteArray(pbDataPtr, pbDataEnd, DirHeader.HeaderSize - FIELD_OFFSET(TVFS_DIRECTORY_HEADER, Flags), (LPBYTE)(&DirHeader.Flags));
        if(pbDataPtr == NULL)
            return ERROR_BAD_FORMAT;

        // Swap the header values
        DirHeader.Flags = ConvertBytesToInteger_4_LE((LPBYTE)(&DirHeader.Flags));

        // Swap the offset table values
        DirHeader.PathTableOffset = ConvertBytesToInteger_4((LPBYTE)(&DirHeader.PathTableOffset));
        DirHeader.PathTableSize   = ConvertBytesToInteger_4((LPBYTE)(&DirHeader.PathTableSize));
        DirHeader.VfsTableOffset  = ConvertBytesToInteger_4((LPBYTE)(&DirHeader.VfsTableOffset));
        DirHeader.VfsTableSize    = ConvertBytesToInteger_4((LPBYTE)(&DirHeader.VfsTableSize));
        DirHeader.CftTableOffset  = ConvertBytesToInteger_4((LPBYTE)(&DirHeader.CftTableOffset));
        DirHeader.CftTableSize    = ConvertBytesToInteger_4((LPBYTE)(&DirHeader.CftTableSize));
        DirHeader.MaxDepth        = (USHORT)ConvertBytesToInteger_2((LPBYTE)(&DirHeader.MaxDepth));
        DirHeader.EstTableOffset  = ConvertBytesToInteger_4((LPBYTE)(&DirHeader.EstTableOffset));
        DirHeader.EstTableSize    = ConvertBytesToInteger_4((LPBYTE)(&DirHeader.EstTableSize));

        // Determine size of file table offsets
        DirHeader.CftOffsSize = GetOffsetFieldSize(DirHeader.CftTableSize);
        DirHeader.EstOffsSize = GetOffsetFieldSize(DirHeader.EstTableSize);

        // Capture the path table
//      DirHeader.pbPathFileTable = pbDirectory + DirHeader.PathTableOffset;
//      DirHeader.pbPathTableEnd = pbDirectory + DirHeader.PathTableOffset + DirHeader.PathTableSize;
//      if(DirHeader.pbPathTableEnd > pbDataEnd)
//          return ERROR_BAD_FORMAT;

        // Capture the VFS file table
//      DirHeader.pbVfsFileTable = pbDirectory + DirHeader.VfsTableOffset;
//      DirHeader.pbVfsTableEnd = pbDirectory + DirHeader.VfsTableOffset + DirHeader.VfsTableSize;
//      if(DirHeader.pbVfsTableEnd > pbDataEnd)
//          return ERROR_BAD_FORMAT;

        // Capture the container file table
//      DirHeader.pbCftFileTable = pbDirectory + DirHeader.CftTableOffset;
//      DirHeader.pbCftTableEnd = pbDirectory + DirHeader.CftTableOffset + DirHeader.CftTableSize;
//      if(DirHeader.pbCftTableEnd > pbDataEnd)
//          return ERROR_BAD_FORMAT;

        return ERROR_SUCCESS;
    }

    LPBYTE CaptureVfsSpanCount(TVFS_DIRECTORY_HEADER & DirHeader, DWORD dwVfsOffset, DWORD & SpanCount)
    {
        LPBYTE pbVfsFileTable = DirHeader.pbDirectoryData + DirHeader.VfsTableOffset;
        LPBYTE pbVfsFileEntry = pbVfsFileTable + dwVfsOffset;
        LPBYTE pbVfsFileEnd = pbVfsFileTable + DirHeader.VfsTableSize;

        // Get the number of span entries
        if(!(pbVfsFileTable <= pbVfsFileEntry && pbVfsFileEntry < pbVfsFileEnd))
            return NULL;
        SpanCount = *pbVfsFileEntry++;

        // 1 - 224 = valid file, 225-254 = other file, 255 = deleted file
        // We will ignore all files with unsupported span count
        return (1 <= SpanCount && SpanCount <= 224) ? pbVfsFileEntry : NULL;
    }

    LPBYTE CaptureVfsSpanEntries(TVFS_DIRECTORY_HEADER & DirHeader, LPBYTE pbVfsSpanEntry, PCASC_CKEY_ENTRY PtrSpanEntry, size_t SpanCount)
    {
        LPBYTE pbCftFileTable;
        LPBYTE pbCftFileEntry;
        LPBYTE pbCftFileEnd;
        LPBYTE pbVfsFileTable = DirHeader.pbDirectoryData + DirHeader.VfsTableOffset;
        LPBYTE pbVfsFileEnd = pbVfsFileTable + DirHeader.VfsTableSize;
        size_t ItemSize = sizeof(DWORD) + sizeof(DWORD) + DirHeader.CftOffsSize;

        // Check whether all spans are included in the valid range
        if(pbVfsSpanEntry < pbVfsFileTable || (pbVfsSpanEntry + (ItemSize * SpanCount)) > pbVfsFileEnd)
            return NULL;

        // Convert all spans
        for(size_t i = 0; i < SpanCount; i++)
        {
            DWORD dwCftOffset = ConvertBytesToInteger_X(pbVfsSpanEntry + sizeof(DWORD) + sizeof(DWORD), DirHeader.CftOffsSize);

            //
            // Structure of the span entry:
            // (4bytes): Offset into the referenced file (big endian)
            // (4bytes): Size of the span (big endian)
            // (?bytes): Offset into Container File Table. Length depends on container file table size
            //

            // Resolve the Container File Table entry
            pbCftFileTable = DirHeader.pbDirectoryData + DirHeader.CftTableOffset;
            pbCftFileEntry = pbCftFileTable + dwCftOffset;
            pbCftFileEnd = pbCftFileTable + DirHeader.CftTableSize;

            // Capture the EKey and the file size
            if((pbCftFileEntry + DirHeader.EKeySize + sizeof(DWORD)) > pbCftFileEnd)
                return NULL;

            // Copy the EKey and content size
            CaptureEncodedKey(PtrSpanEntry->EKey, pbCftFileEntry, DirHeader.EKeySize);
            PtrSpanEntry->ContentSize  = ConvertBytesToInteger_4(pbVfsSpanEntry + sizeof(DWORD));

            // Move to the next entry
            pbVfsSpanEntry += ItemSize;
            PtrSpanEntry++;
        }

        return pbVfsSpanEntry;
    }

    //
    // Structure of the path table entry:
    // (1byte) 0x00 (optional) - means that there will be prefix path separator
    // (1byte) File name length
    // (?byte) File name
    // (1byte) 0x00 (optional) - means that there will be postfix path separator
    // (1byte) 0xFF (optional) - node value identifier
    // (4byte)                 - node value
    //
    // Note: The path "data\archive\maps\file.bmp" could be cut into nodes like:
    //                 data\0 (or data with subdirectory)
    //                   arc
    //                     hive\0
    //                       maps\0 (or folder data)
    //                         file.bmp
    //

    LPBYTE CapturePathEntry(TVFS_PATH_TABLE_ENTRY & PathEntry, LPBYTE pbPathTablePtr, LPBYTE pbPathTableEnd)
    {
        // Reset the path entry structure
        PathEntry.pbNamePtr = pbPathTablePtr;
        PathEntry.pbNameEnd = pbPathTablePtr;
        PathEntry.NodeFlags = 0;
        PathEntry.NodeValue = 0;

        // Zero before the name means prefix path separator
        if (pbPathTablePtr < pbPathTableEnd && pbPathTablePtr[0] == 0)
        {
            PathEntry.NodeFlags |= TVFS_PTE_PATH_SEPARATOR_PRE;
            pbPathTablePtr++;
        }

        // Capture the length of the name fragment
        if (pbPathTablePtr < pbPathTableEnd && pbPathTablePtr[0] != 0xFF)
        {
            // Capture length of the name fragment
            size_t nLength = *pbPathTablePtr++;

            if ((pbPathTablePtr + nLength) > pbPathTableEnd)
                return NULL;
            PathEntry.pbNamePtr = pbPathTablePtr;
            PathEntry.pbNameEnd = pbPathTablePtr + nLength;
            pbPathTablePtr += nLength;
        }

        // Zero after the name means postfix path separator
        if (pbPathTablePtr < pbPathTableEnd && pbPathTablePtr[0] == 0)
        {
            PathEntry.NodeFlags |= TVFS_PTE_PATH_SEPARATOR_POST;
            pbPathTablePtr++;
        }

        if (pbPathTablePtr < pbPathTableEnd)
        {
            // Check for node value
            if (pbPathTablePtr[0] == 0xFF)
            {
                if ((pbPathTablePtr + 1 + sizeof(DWORD)) > pbPathTableEnd)
                    return NULL;
                PathEntry.NodeValue = ConvertBytesToInteger_4(pbPathTablePtr + 1);
                PathEntry.NodeFlags |= TVFS_PTE_NODE_VALUE;
                pbPathTablePtr = pbPathTablePtr + 1 + sizeof(DWORD);
            }

            // Non-0xFF after the name means path separator after
            else
            {
                PathEntry.NodeFlags |= TVFS_PTE_PATH_SEPARATOR_POST;
                assert(pbPathTablePtr[0] != 0);
            }
        }

        return pbPathTablePtr;
    }

    bool IsVfsFileEKey(TCascStorage * hs, LPBYTE EKey, size_t EKeyLength)
    {
        PCASC_CKEY_ENTRY pCKeyEntry;
        size_t ItemCount = hs->VfsRootList.ItemCount();

        // Search the array
        for (size_t i = 0; i < ItemCount; i++)
        {
            pCKeyEntry = (PCASC_CKEY_ENTRY)hs->VfsRootList.ItemAt(i);
            if (pCKeyEntry != NULL)
            {
                if (!memcmp(pCKeyEntry->EKey, EKey, EKeyLength))
                    return true;
            }
        }

        // Not found in the VFS list
        return false;
    }

    // This function verifies whether a file is actually a sub-directory.
    // If yes, it contains just another "TVFS" virtual file system, just like the ROOT file.
    DWORD IsVfsSubDirectory(TCascStorage * hs,  TVFS_DIRECTORY_HEADER & DirHeader, TVFS_DIRECTORY_HEADER & SubHeader, LPBYTE EKey, DWORD dwFileSize)
    {
        PCASC_CKEY_ENTRY pCKeyEntry;
        LPBYTE pbVfsData = NULL;
        DWORD cbVfsData = dwFileSize;
        DWORD dwErrCode = ERROR_BAD_FORMAT;

        // Verify whether the EKey is in the list of VFS root files
        if(IsVfsFileEKey(hs, EKey, DirHeader.EKeySize))
        {
            // Locate the CKey entry
            if((pCKeyEntry = FindCKeyEntry_EKey(hs, EKey)) != NULL)
            {
                // Load the entire file into memory
                pbVfsData = LoadInternalFileToMemory(hs, pCKeyEntry, &cbVfsData);
                if (pbVfsData && cbVfsData)
                {
                    // Capture the file folder. This also serves as test
                    dwErrCode = CaptureDirectoryHeader(SubHeader, pbVfsData, pbVfsData + cbVfsData);
                    if (dwErrCode == ERROR_SUCCESS)
                        return dwErrCode;

                    // Clear the captured header
                    memset(&SubHeader, 0, sizeof(TVFS_DIRECTORY_HEADER));
                    CASC_FREE(pbVfsData);
                }
            }
        }

        return dwErrCode;
    }

    PCASC_CKEY_ENTRY InsertUnknownCKeyEntry(TCascStorage * hs, LPBYTE pbEKey, size_t cbEKey, DWORD ContentSize)
    {
        PCASC_CKEY_ENTRY pCKeyEntry;

        // Insert a new entry to the array. DO NOT ALLOW enlarge array here
        pCKeyEntry = (PCASC_CKEY_ENTRY)hs->CKeyArray.Insert(1, false);
        if(pCKeyEntry != NULL)
        {
            memset(pCKeyEntry, 0, sizeof(CASC_CKEY_ENTRY));
            memcpy(pCKeyEntry->EKey, pbEKey, cbEKey);
            pCKeyEntry->StorageOffset = CASC_INVALID_OFFS64;
            pCKeyEntry->ContentSize = ContentSize;
            pCKeyEntry->EncodedSize = CASC_INVALID_SIZE;
            pCKeyEntry->Flags = CASC_CE_HAS_EKEY | CASC_CE_HAS_EKEY_PARTIAL;
            pCKeyEntry->SpanCount = 1;

            // Copy the information from index files to the CKey entry
            CopyEKeyEntry(hs, pCKeyEntry);

            // Insert the item into EKey map
            hs->EKeyMap.InsertObject(pCKeyEntry, pCKeyEntry->EKey);
        }

        return pCKeyEntry;
    }

    void InsertRootVfsEntry(TCascStorage * hs, LPBYTE pbCKey, const char * szFormat, size_t nIndex)
    {
        PCASC_CKEY_ENTRY pCKeyEntry;
        char szFileName[0x20];

        // The CKey entry must exist
        if((pCKeyEntry = FindCKeyEntry_CKey(hs, pbCKey)) != NULL)
        {
            CascStrPrintf(szFileName, _countof(szFileName), szFormat, nIndex);
            Insert(szFileName, pCKeyEntry);
        }
    }

    DWORD ParsePathFileTable(TCascStorage * hs, TVFS_DIRECTORY_HEADER & DirHeader, CASC_PATH<char> & PathBuffer, LPBYTE pbPathTablePtr, LPBYTE pbPathTableEnd)
    {
        TVFS_DIRECTORY_HEADER SubHeader;
        TVFS_PATH_TABLE_ENTRY PathEntry;
        PCASC_CKEY_ENTRY pCKeyEntry;
        LPBYTE pbVfsSpanEntry;
        size_t  nSavePos = PathBuffer.Save();
        DWORD dwSpanCount;
        DWORD dwErrCode;

        // Sanity check
        assert(SpanArray.IsInitialized());

        // Parse the file table
        while(pbPathTablePtr < pbPathTableEnd)
        {
            // Capture the single path table entry
            pbPathTablePtr = CapturePathEntry(PathEntry, pbPathTablePtr, pbPathTableEnd);
            if(pbPathTablePtr == NULL)
                return ERROR_BAD_FORMAT;

            // Append the node name to the total path. Also add backslash, if it's a folder
            PathBuffer_AppendNode(PathBuffer, PathEntry);

            // Folder component
            if (PathEntry.NodeFlags & TVFS_PTE_NODE_VALUE)
            {
                // If the TVFS_FOLDER_NODE is set, then the path node is a directory,
                // with its data immediately following the path node. Lower 31 bits of NodeValue
                // contain the length of the directory (including the NodeValue!)
                if (PathEntry.NodeValue & TVFS_FOLDER_NODE)
                {
                    LPBYTE pbDirectoryEnd = pbPathTablePtr + (PathEntry.NodeValue & TVFS_FOLDER_SIZE_MASK) - sizeof(DWORD);

                    // Check the available data
                    assert((PathEntry.NodeValue & TVFS_FOLDER_SIZE_MASK) >= sizeof(DWORD));

                    // Recursively call the folder parser on the same file
                    dwErrCode = ParsePathFileTable(hs, DirHeader, PathBuffer, pbPathTablePtr, pbDirectoryEnd);
                    if (dwErrCode != ERROR_SUCCESS)
                        return dwErrCode;

                    // Skip the directory data
                    pbPathTablePtr = pbDirectoryEnd;
                }
                else
                {
                    // Capture the number of VFS spans
                    pbVfsSpanEntry = CaptureVfsSpanCount(DirHeader, PathEntry.NodeValue, dwSpanCount);
                    if(pbVfsSpanEntry == NULL)
                        return ERROR_BAD_FORMAT;

                    // If it's one span, it's either a subdirectory or an entire file
                    if(dwSpanCount == 1)
                    {
                        CASC_CKEY_ENTRY SpanEntry;

                        // Capture the single span entry
                        pbVfsSpanEntry = CaptureVfsSpanEntries(DirHeader, pbVfsSpanEntry, &SpanEntry, 1);
                        if(pbVfsSpanEntry == NULL)
                            return ERROR_FILE_CORRUPT;

                        // Find the CKey entry
                        pCKeyEntry = FindCKeyEntry_EKey(hs, SpanEntry.EKey);
                        if(pCKeyEntry == NULL)
                        {
                            // Some files are in the ROOT manifest even if they are not in ENCODING and DOWNLOAD.
                            // Example: "2018 - New CASC\00001", file "DivideAndConquer.w3m:war3mapMap.blp"
                            pCKeyEntry = InsertUnknownCKeyEntry(hs, SpanEntry.EKey, DirHeader.EKeySize, SpanEntry.ContentSize);
                            if(pCKeyEntry == NULL)
                            {
                                return ERROR_NOT_ENOUGH_MEMORY;
                            }
                        }

                        // We need to check whether this is another TVFS directory file
                        if (IsVfsSubDirectory(hs, DirHeader, SubHeader, SpanEntry.EKey, SpanEntry.ContentSize) == ERROR_SUCCESS)
                        {
                            // Add colon (':')
                            PathBuffer.AppendChar(':');

                            // The file content size should already be there
                            assert(pCKeyEntry->ContentSize == SpanEntry.ContentSize);
                            FileTree.InsertByName(pCKeyEntry, PathBuffer);

                            // Parse the subdir
                            ParseDirectoryData(hs, SubHeader, PathBuffer);
                            CASC_FREE(SubHeader.pbDirectoryData);
                        }
                        else
                        {
                            // If the content content size is not there, supply it now
                            if(pCKeyEntry->ContentSize == CASC_INVALID_SIZE)
                                pCKeyEntry->ContentSize = SpanEntry.ContentSize;
                            FileTree.InsertByName(pCKeyEntry, PathBuffer);
                        }
                    }
                    else
                    {
                        PCASC_CKEY_ENTRY pSpanEntries;
                        PCASC_FILE_NODE pFileNode;
                        USHORT RefCount;
                        bool bFilePresent = true;

                        //
                        // Need to support multi-span files, possibly lager than 4 GB
                        // Example: CoD: Black Ops 4, file "zone/base.xpak" 0x16 spans, over 15 GB size
                        //

                        // Allocate buffer for all span entries
                        pSpanEntries = (PCASC_CKEY_ENTRY)SpanArray.Insert(dwSpanCount);
                        if(pSpanEntries == NULL)
                            return ERROR_NOT_ENOUGH_MEMORY;

                        // Capture all span entries
                        pbVfsSpanEntry = CaptureVfsSpanEntries(DirHeader, pbVfsSpanEntry, pSpanEntries, dwSpanCount);
                        if(pbVfsSpanEntry == NULL)
                            return ERROR_FILE_CORRUPT;

                        // Parse all span entries
                        for(DWORD dwSpanIndex = 0; dwSpanIndex < dwSpanCount; dwSpanIndex++)
                        {
                            PCASC_CKEY_ENTRY pSpanEntry = pSpanEntries + dwSpanIndex;

                            // Find the CKey entry
                            pCKeyEntry = FindCKeyEntry_EKey(hs, pSpanEntries[dwSpanIndex].EKey);
                            if(pCKeyEntry == NULL)
                            {
                                bFilePresent = false;
                                break;
                            }

                            // Supply the content size
                            if(pCKeyEntry->ContentSize == CASC_INVALID_SIZE)
                                pCKeyEntry->ContentSize = pSpanEntry->ContentSize;
                            assert(pCKeyEntry->ContentSize == pSpanEntry->ContentSize);

                            // Fill-in the span entry
                            if(dwSpanIndex == 0)
                            {
                                pCKeyEntry->SpanCount = (BYTE)(dwSpanCount);
                                pCKeyEntry->RefCount++;
                            }
                            else
                            {
                                // Mark the CKey entry as a file span. Note that a CKey entry
                                // can actually be both a file span and a standalone file:
                                // * zone/zm_red.xpak - { zone/zm_red.xpak_1, zone/zm_red.xpak_2, ..., zone/zm_red.xpak_6 }
                                pCKeyEntry->Flags |= CASC_CE_FILE_SPAN;
                            }

                            // Copy all from the existing CKey entry
                            memcpy(pSpanEntry, pCKeyEntry, sizeof(CASC_CKEY_ENTRY));
                        }

                        // Do nothing if the file is not present locally
                        if(bFilePresent)
                        {
                            // Insert a new file node that will contain pointer to the span entries
                            RefCount = pSpanEntries->RefCount;
                            pFileNode = FileTree.InsertByName(pSpanEntries, PathBuffer);
                            pSpanEntries->RefCount = RefCount;

                            if(pFileNode == NULL)
                                return ERROR_NOT_ENOUGH_MEMORY;
                        }
                    }
                }

                // Reset the position of the path buffer
                PathBuffer.Restore(nSavePos);
            }
        }

        // Return the total number of entries
        return ERROR_SUCCESS;
    }

    DWORD ParseDirectoryData(TCascStorage * hs, TVFS_DIRECTORY_HEADER & DirHeader, CASC_PATH<char> & PathBuffer)
    {
        LPBYTE pbRootDirectory = DirHeader.pbDirectoryData + DirHeader.PathTableOffset;
        LPBYTE pbRootDirPtr = pbRootDirectory;
        LPBYTE pbRootDirEnd = pbRootDirPtr + DirHeader.PathTableSize;
        DWORD dwNodeValue = 0;

        // Most usually, there is a root directory in the folder
        if((pbRootDirPtr + 1 + sizeof(DWORD)) < pbRootDirEnd)
        {
            //
            // The structure of the root directory
            // -----------------------------------
            // 1byte   0xFF
            // 4bytes  NodeValue (BigEndian). The most significant bit is set
            //          - Lower 31 bits contain length of the directory data, including NodeValue
            //

            if(pbRootDirPtr[0] == 0xFF)
            {
                // Get the NodeValue and check its highest bit
                if(CaptureInteger32_BE(pbRootDirPtr + 1, pbRootDirEnd, &dwNodeValue) == NULL || (dwNodeValue & TVFS_FOLDER_NODE) == 0)
                    return ERROR_BAD_FORMAT;
                
                // Get the range of the root directory
                pbRootDirEnd = pbRootDirPtr + 1 + (dwNodeValue & TVFS_FOLDER_SIZE_MASK);
                pbRootDirPtr = pbRootDirPtr + 1 + sizeof(DWORD);

                // Check the directory
                if(pbRootDirEnd > (pbRootDirectory + DirHeader.PathTableSize))
                    return ERROR_BAD_FORMAT;
            }
        }

        // Now go parse the path file table
        return ParsePathFileTable(hs, DirHeader, PathBuffer, pbRootDirPtr, pbRootDirEnd);
    }

    DWORD Load(TCascStorage * hs, TVFS_DIRECTORY_HEADER & RootHeader)
    {
        CASC_PATH<char> PathBuffer;
        DWORD dwErrCode;

        // Save the length of the key
        FileTree.SetKeyLength(RootHeader.EKeySize);

        // Initialize the array of span entries
        dwErrCode = SpanArray.Create(sizeof(CASC_CKEY_ENTRY), 0x100);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        // Insert the main VFS root file as named entry
        InsertRootVfsEntry(hs, hs->VfsRoot.CKey, "vfs-root", 0);

        // Insert all VFS roots folders as files
        //for(size_t i = 0; i < hs->VfsRootList.ItemCount(); i++)
        //{
        //    pCKeyEntry = (PCASC_CKEY_ENTRY)hs->VfsRootList.ItemAt(i);
        //    InsertRootVfsEntry(hs, pCKeyEntry->CKey, "vfs-%u", i+1);
        //}

        // Parse the entire directory data
        return ParseDirectoryData(hs, RootHeader, PathBuffer);
    }

    CASC_ARRAY SpanArray;           // Array of CASC_SPAN_ENTRY for all multi-span files
};

//-----------------------------------------------------------------------------
// Public functions - TVFS root

DWORD RootHandler_CreateTVFS(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile)
{
    TRootHandler_TVFS * pRootHandler = NULL;
    TVFS_DIRECTORY_HEADER RootHeader;
    DWORD dwErrCode;

    // Capture the entire root directory
    dwErrCode = TRootHandler_TVFS::CaptureDirectoryHeader(RootHeader, pbRootFile, pbRootFile + cbRootFile);
    if(dwErrCode == ERROR_SUCCESS)
    {
        // Allocate the root handler object
        pRootHandler = new TRootHandler_TVFS();
        if(pRootHandler != NULL)
        {
            // Load the root directory. If load failed, we free the object
            dwErrCode = pRootHandler->Load(hs, RootHeader);
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
