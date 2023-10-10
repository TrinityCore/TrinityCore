/*****************************************************************************/
/* overwatch.h                            Copyright (c) Ladislav Zezula 2023 */
/*---------------------------------------------------------------------------*/
/* Definitions for overwatch on-disk structures                              */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 28.04.19  1.00  Lad  The first version of CascStructs.h                   */
/*****************************************************************************/

#ifndef __CASC_OVERWATCH_H__
#define __CASC_OVERWATCH_H__

//-----------------------------------------------------------------------------
// Definitions

#define CASC_OVERWATCH_VERSION_122_PTR  47161
#define CASC_OVERWATCH_VERSION_148_PTR  68309
#define CASC_OVERWATCH_VERSION_152_PTR  72317

#define CASC_CMF_ENCRYPTED_MAGIC  0x636D66

#define CASC_AES_KEY_LENGTH     0x20
#define CASC_AES_IV_LENGTH      0x10
#define SHA1_DIGESTSIZE         SHA1_HASH_SIZE      // Used in cmf-key.cpp

//-----------------------------------------------------------------------------
// Data types used in cmf-key.cpp

typedef unsigned char  byte;
typedef unsigned short ushort;
typedef unsigned int   uint;

//-----------------------------------------------------------------------------
// Data structures related to Content Manifest Files (.cmf)

// 1.00+
struct CASC_CMF_HEADER_100
{
    unsigned dwBuildVersion;
    unsigned dwField04;
    unsigned dwField08;
    unsigned dwField10;
    unsigned dwField14;
    int      nDataCount;
    unsigned dwField1C;
    int      nEntryCount;
    unsigned dwHeaderMagic;
};

// 1.22+
struct CASC_CMF_HEADER_122
{
    unsigned dwBuildVersion;
    unsigned dwField04;
    unsigned dwField08;
    unsigned dwField0C;
    unsigned dwField10;
    unsigned dwField14;
    int      nDataCount;
    unsigned dwField1C;
    int      nEntryCount;
    unsigned dwHeaderMagic;
};

// 1.48+
struct CASC_CMF_HEADER_148
{
    unsigned dwBuildVersion;
    unsigned dwField04;
    unsigned dwField08;
    unsigned dwField0C;
    unsigned dwField10;
    unsigned dwField14;
    unsigned dwField18;
    int      nDataPatchRecordCount;
    int      nDataCount;
    int      nEntryPatchRecordCount;
    int      nEntryCount;
    unsigned dwHeaderMagic;
};

// This structure has the members with the same names like CMFHeader in TACTLib
// This is because we reuse the C# code from that library as C++
struct CASC_CMF_HEADER
{
    bool IsEncrypted() const
    {
        return ((m_magic >> 0x08) == CASC_CMF_ENCRYPTED_MAGIC);
    }

    byte GetVersion() const
    {
        return IsEncrypted() ? (byte)(m_magic & 0x000000FF) : (byte)((m_magic & 0xFF000000) >> 24);
    }

    uint GetNonEncryptedMagic() const
    {
        return (uint)(0x00666D63u | (GetVersion() << 24));
    }

    void operator = (const CASC_CMF_HEADER_100 & src)
    {
        memset(this, 0, sizeof(CASC_CMF_HEADER_148));
        m_buildVersion = src.dwBuildVersion;
        m_dataCount = src.nDataCount;
        m_entryCount = src.nEntryCount;
        m_magic = src.dwHeaderMagic;
    }

    void operator = (const CASC_CMF_HEADER_122 & src)
    {
        memset(this, 0, sizeof(CASC_CMF_HEADER_148));
        m_buildVersion = src.dwBuildVersion;
        m_dataCount = src.nDataCount;
        m_entryCount = src.nEntryCount;
        m_magic = src.dwHeaderMagic;
    }

    void operator = (const CASC_CMF_HEADER_148 & src)
    {
        // Copy 1:1
        memcpy(this, &src, sizeof(CASC_CMF_HEADER_148));
    }

    uint m_buildVersion;
    uint m_unk04;
    uint m_unk08;
    uint m_unk0C;
    uint m_unk10;
    uint m_unk14;
    uint m_unk18;
    int  m_dataPatchRecordCount;
    int  m_dataCount;
    int  m_entryPatchRecordCount;
    int  m_entryCount;
    uint m_magic;
};

typedef struct _CASC_CMF_HASH_ENTRY_100
{
    BYTE GUID[8];
    BYTE Size[4];
    BYTE CKey[CASC_CKEY_SIZE];
} CASC_CMF_HASH_ENTRY_100, *PCASC_CMF_HASH_ENTRY_100;

typedef struct _CASC_CMF_HASH_ENTRY_135
{
    BYTE GUID[8];
    BYTE Size[4];
    BYTE field_C;
    BYTE CKey[CASC_CKEY_SIZE];
} CASC_CMF_HASH_ENTRY_135, *PCASC_CMF_HASH_ENTRY_135;

//-----------------------------------------------------------------------------
// Data structures related to Application Package Manifests (.apm)

#define CASC_APM_HEADER_MAGIC       0x00636D66

typedef struct _CASC_APM_HEADER_V1
{
    ULONGLONG BuildVersion;
    DWORD BuildNumber;                   // Build number of the game
    DWORD PackageCount;
    DWORD EntryCount;
    DWORD HeaderMagic;

    // Followed by the array of APM_ENTRY (count is in "EntryCount")
    // Followed by the array of APM_PACKAGE (count is in "PackageCount")

} CASC_APM_HEADER_V1, *PCASC_APM_HEADER_V1;

#pragma pack(push, 4)
typedef struct _CASC_APM_HEADER_V2
{
    ULONGLONG BuildNumber;              // Build number of the game
    ULONGLONG ZeroValue1;
    DWORD ZeroValue2;
    DWORD PackageCount;
    DWORD ZeroValue3;
    DWORD EntryCount;
    DWORD HeaderMagic;

    // Followed by the array of APM_ENTRY (count is in "EntryCount")
    // Followed by the array of APM_PACKAGE (count is in "PackageCount")

} CASC_APM_HEADER_V2, *PCASC_APM_HEADER_V2;
#pragma pack(pop)

typedef struct _CASC_APM_HEADER
{
    ULONGLONG BuildNumber;
    DWORD PackageCount;
    DWORD EntryCount;
    DWORD HeaderMagic;
} CASC_APM_HEADER, *PCASC_APM_HEADER;

// On-disk format, size = 0x0C
typedef struct _CASC_APM_ENTRY_V1
{
    DWORD     Index;
    BYTE      HashValue[8];
} CASC_APM_ENTRY_V1, *PCASC_APM_ENTRY_V1;

// On-disk format, size = 0x14
typedef struct _CASC_APM_ENTRY_V2
{
    DWORD     Index;
    BYTE      HashValueA[8];
    BYTE      HashValueB[8];
} CASC_APM_ENTRY_V2, *PCASC_APM_ENTRY_V2;

// On-disk format
typedef struct _CASC_APM_PACKAGE_ENTRY_V1
{
    ULONGLONG EntryPointGUID;
    BYTE      GUID[8];
    ULONGLONG SecondaryGUID;
    ULONGLONG Key;
    ULONGLONG PackageGUID;
    DWORD     Unknown1;
    DWORD     ContentSize;
    ULONGLONG Unknown3;
    BYTE CKey[CASC_CKEY_SIZE];              // Content key
} CASC_APM_PACKAGE_ENTRY_V1, *PCASC_APM_PACKAGE_ENTRY_V1;

// On-disk format
typedef struct _CASC_APM_PACKAGE_ENTRY_V2
{
    ULONGLONG GUID;                         // 077 file
    ULONGLONG Unknown1;
    ULONGLONG Unknown2;
    ULONGLONG Unknown3;
} CASC_APM_PACKAGE_ENTRY_V2, *PCASC_APM_PACKAGE_ENTRY_V2;

//-----------------------------------------------------------------------------
// Functions common to both. Implemented in CascRootFile_OW.cpp

// Prepares the template of the asset file name. The file name is in format like:
// ContentManifestFiles\Windows-RCN\enUS\speech\05d0000000000086
size_t BuildAssetFileNameTemplate(
    char * szNameTemplate,              // File name template
    size_t ccNameTemplate,              // Offset of the plain name, relative to szNameTemplate
    const char * szPrefix,              // Top level folder name for asset files
    const char * szAssetName            // Plain name of the asset file ("Win_SPWin_RCN_LesES_EExt.apm")
    );

// Inserts the asset file into the file tree.
DWORD InsertAssetFile(
    TCascStorage * hs,
    CASC_FILE_TREE & FileTree,          // Reference to the file tree
    char * szFileName,                  // Pointer to mutable asset file name template
    size_t nPlainName,                  // Offset of the plain name in the name template
    LPBYTE pbCKey,                      // Pointer to CKey (unaligned)
    LPBYTE pbGuid                       // Pointer to file GUID (unaligned)
    );

template <typename GUID_ENTRY>
DWORD InsertAssetFiles(
    TCascStorage * hs,
    CASC_FILE_TREE & FileTree,          // Reference to the file tree
    char * szFileName,                  // Pointer to mutable asset file name template
    size_t nPlainName,                  // Offset of the plain name in the name template
    GUID_ENTRY * pEntries,              // Array of entries
    size_t nEntries)                    // Number of entries
{
    DWORD dwErrCode = ERROR_SUCCESS;

    for(size_t i = 0; i < nEntries; i++)
    {
        dwErrCode = InsertAssetFile(hs, FileTree, szFileName, nPlainName, pEntries[i].CKey, pEntries[i].GUID);
        if(dwErrCode != ERROR_SUCCESS)
            break;
    }
    return dwErrCode;
}

#endif  // __CASC_OVERWATCH_H__

