/*****************************************************************************/
/* CascMndxRoot.h                         Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* Interface file for MNDX structures                                        */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 15.05.14  1.00  Lad  Created                                              */
/*****************************************************************************/

#ifndef __CASC_MNDX_ROOT__
#define __CASC_MNDX_ROOT__

class TFileNameDatabase;

#define CASC_MAX_ENTRIES(type) (0xFFFFFFFF / sizeof(type))

#define CASC_SEARCH_INITIALIZING    0
#define CASC_SEARCH_SEARCHING       2
#define CASC_SEARCH_FINISHED        4

typedef struct _TRIPLET
{
    DWORD BaseValue;
    DWORD Value2;
    DWORD Value3;
} TRIPLET, *PTRIPLET;

typedef struct _NAME_FRAG
{
    DWORD ItemIndex;                                // Back index to various tables
    DWORD NextIndex;                                // The following item index
    DWORD FragOffs;                                 // Higher 24 bits are 0xFFFFFF00 --> A single matching character
                                                    // Otherwise --> Offset to the name fragment table
} NAME_FRAG, *PNAME_FRAG;

typedef struct _PATH_STOP
{
    DWORD ItemIndex;
    DWORD field_4;
    DWORD field_8;
    DWORD field_C;
    DWORD field_10;
} PATH_STOP, *PPATH_STOP;

typedef union _ARRAY_POINTER
{
    LPBYTE Bytes;                                   // Pointer to an octet
    char * Chars;                                   // Pointer to a character
    PDWORD Uint32s;                                 // Pointer to a DWORD
    PTRIPLET Triplets;                              // Pointer to TRIPLET
    PNAME_FRAG NameFrags;                           // Pointer to name fragment entry
    PPATH_STOP PathStopPtr;                         // Pointer to path checkpoint
    PULONGLONG Int64Ptr;                            // Pointer to 64-bit integer

} ARRAY_POINTER, *PARRAY_POINTER;

// Simple access to various tables within TGenericArray
#define ByteArray     ArrayPointer.Bytes  
#define CharArray     ArrayPointer.Chars  
#define Uint32Array   ArrayPointer.Uint32s
#define TripletArray  ArrayPointer.Triplets
#define NameFragArray ArrayPointer.NameFrags

class TByteStream
{
    public:

    TByteStream();

    void ExchangeWith(TByteStream & Target);
    int GetBytes(DWORD cbByteCount, PARRAY_POINTER PtrArray);
    int SkipBytes(DWORD cbByteCount);
    int SetByteBuffer(LPBYTE pbNewMarData, DWORD cbNewMarData);
    int GetValue_DWORD(DWORD & Value);
    int GetValue_ItemCount(DWORD & NumberOfBytes, DWORD & ItemCount, DWORD ItemSize);
    int GetArray_DWORDs(PARRAY_POINTER PtrArray, DWORD ItemCount);
    int GetArray_Triplets(PARRAY_POINTER PtrArray, DWORD ItemCount);
    int GetArray_NameTable(PARRAY_POINTER PtrArray, DWORD ItemCount);
    int GetArray_BYTES(PARRAY_POINTER PtrArray, DWORD ItemCount);

    LPBYTE pbByteData;
    void * pvMappedFile;
    DWORD cbByteData;
    DWORD field_C;
    HANDLE hFile;
    HANDLE hMap;
};

class TGenericArray 
{
    public:

    TGenericArray();
    ~TGenericArray();

    int SetArrayValid();

    void ExchangeWith(TGenericArray & Target);
    void CopyFrom(TGenericArray & Source);

    void SetMaxItems_CHARS(DWORD NewMaxItemCount);
    void SetMaxItems_PATH_STOP(DWORD NewMaxItemCount);

    void InsertOneItem_CHAR(char OneChar);
    void InsertOneItem_PATH_STOP(PATH_STOP & NewItem);

    void sub_19583A0(DWORD NewItemCount);

    int LoadDwordsArray(TByteStream & InStream);
    int LoadTripletsArray(TByteStream & InStream);
    int LoadByteArray(TByteStream & InStream);
    int LoadFragmentInfos(TByteStream & InStream);
    int LoadStrings(TByteStream & InStream);

    int LoadDwordsArray_Copy(TByteStream & InStream);
    int LoadTripletsArray_Copy(TByteStream & InStream);
    int LoadBytes_Copy(TByteStream & InStream);
    int LoadFragmentInfos_Copy(TByteStream & InStream);
    int LoadStringsWithCopy(TByteStream & InStream);

    ARRAY_POINTER DataBuffer;
    ARRAY_POINTER FirstValid;

    ARRAY_POINTER ArrayPointer;
    DWORD ItemCount;                    // Number of items in the array
    DWORD MaxItemCount;                 // Capacity of the array
    bool  bIsValidArray;
};

class TBitEntryArray : public TGenericArray 
{
    public:

    TBitEntryArray();
    ~TBitEntryArray();

    DWORD GetBitEntry(DWORD EntryIndex)
    {
        DWORD dwItemIndex = (EntryIndex * BitsPerEntry) >> 0x05;
        DWORD dwStartBit = (EntryIndex * BitsPerEntry) & 0x1F;
        DWORD dwEndBit = dwStartBit + BitsPerEntry;
        DWORD dwResult;

        // If the end bit index is greater than 32,
        // we also need to load from the next 32-bit item
        if(dwEndBit > 0x20)
        {
            dwResult = (Uint32Array[dwItemIndex + 1] << (0x20 - dwStartBit)) | (Uint32Array[dwItemIndex] >> dwStartBit);
        }
        else
        {
            dwResult = Uint32Array[dwItemIndex] >> dwStartBit;
        }

        // Now we also need to mask the result by the bit mask
        return dwResult & EntryBitMask;
    }

    void ExchangeWith(TBitEntryArray & Target);
    int LoadFromStream(TByteStream & InStream);
    int LoadFromStream_Exchange(TByteStream & InStream);

    DWORD BitsPerEntry;
    DWORD EntryBitMask;
    DWORD TotalEntries;
};

class TStruct40
{
    public:

    TStruct40();

    void InitSearchBuffers();

    TGenericArray array_00;
    TGenericArray PathStops;            // Array of path checkpoints
    DWORD ItemIndex;                    // Current name fragment: Index to various tables
    DWORD CharIndex;
    DWORD ItemCount;
    DWORD SearchPhase;                  // 0 = initializing, 2 = searching, 4 = finished
};

class TMndxFindResult
{
    public:

    TMndxFindResult();
    ~TMndxFindResult();

    int CreateStruct40();
    void FreeStruct40();

    int SetSearchPath(const char * szNewSearchPath, size_t cchNewSearchPath);

    const char * szSearchMask;          // Search mask without wioldcards
    size_t cchSearchMask;               // Length of the search mask
    DWORD field_8;
    const char * szFoundPath;           // Found path name
    size_t cchFoundPath;                // Length of the found path name
    DWORD FileNameIndex;                // Index of the file name
    TStruct40 * pStruct40;
};

class TSparseArray
{
    public:

    TSparseArray();

    void ExchangeWith(TSparseArray & TargetObject);
    int LoadFromStream(TByteStream & InStream);
    int LoadFromStream_Exchange(TByteStream & InStream);

    // Returns true if the item at n-th position is present
    DWORD IsItemPresent(DWORD ItemIndex)
    {
        return (ItemBits.Uint32Array[ItemIndex >> 0x05] & (1 << (ItemIndex & 0x1F)));
    }

    DWORD GetItemValue(DWORD ItemIndex);

    TGenericArray ItemBits;             // Bit array for each item (1 = item is present)
    DWORD TotalItemCount;               // Total number of items in the array
    DWORD ValidItemCount;               // Number of present items in the array
    TGenericArray BaseValues;           // Array of base values for item indexes >= 0x200
    TGenericArray ArrayDwords_38;
    TGenericArray ArrayDwords_50;
};

class TNameIndexStruct
{
    public:

    TNameIndexStruct();
    ~TNameIndexStruct();

    bool CheckNameFragment(TMndxFindResult * pStruct1C, DWORD dwFragOffs);
    bool CheckAndCopyNameFragment(TMndxFindResult * pStruct1C, DWORD dwFragOffs);
    void CopyNameFragment(TMndxFindResult * pStruct1C, DWORD dwFragOffs);

    void ExchangeWith(TNameIndexStruct & Target);
    int LoadFromStream(TByteStream & InStream);
    int LoadFromStream_Exchange(TByteStream & InStream);

    TGenericArray NameFragments;  
    TSparseArray Struct68;  
};

class TStruct10
{
    public:
    
    TStruct10();
    
    void CopyFrom(TStruct10 & Target);
    int sub_1956FD0(DWORD dwBitMask);
    int sub_1957050(DWORD dwBitMask);
    int sub_19572E0(DWORD dwBitMask);
    int sub_1957800(DWORD dwBitMask);

    DWORD field_0;
    DWORD field_4;
    DWORD field_8;
    DWORD field_C;
};

class TFileNameDatabasePtr
{
    public:

    TFileNameDatabasePtr();
    ~TFileNameDatabasePtr();

    int FindFileInDatabase(TMndxFindResult * pStruct1C);
    int sub_1956CE0(TMndxFindResult * pStruct1C, bool * pbFindResult);

    int GetFileNameCount(PDWORD PtrFileNameCount);
    int CreateDatabase(LPBYTE pbMarData, DWORD cbMarData);
    int SetDatabase(TFileNameDatabase * pNewDB);

    TFileNameDatabase * pDB;
};

class TFileNameDatabase
{
    public:
    
    TFileNameDatabase();

    void ExchangeWith(TFileNameDatabase & Target);
    int LoadFromStream(TByteStream & InStream);
    int LoadFromStream_Exchange(TByteStream & InStream);

    DWORD sub_1959CB0(DWORD dwHashValue);
    DWORD sub_1959F50(DWORD arg_0);

    // Retrieves the name fragment distance
    // HOTS: 19573D0/inlined
    DWORD GetNameFragmentOffsetEx(DWORD LoBitsIndex, DWORD HiBitsIndex)
    {
        return (FrgmDist_HiBits.GetBitEntry(HiBitsIndex) << 0x08) | FrgmDist_LoBits.ByteArray[LoBitsIndex];
    }

    // HOTS: 1957350, inlined
    DWORD GetNameFragmentOffset(DWORD LoBitsIndex)
    {
        return GetNameFragmentOffsetEx(LoBitsIndex, Struct68_D0.GetItemValue(LoBitsIndex));
    }

    bool sub_1957B80(TMndxFindResult * pStruct1C, DWORD dwKey);
    bool CheckNextPathFragment(TMndxFindResult * pStruct1C);
    bool FindFileInDatabase(TMndxFindResult * pStruct1C);

    void sub_1958D70(TMndxFindResult * pStruct1C, DWORD arg_4);
    bool sub_1959010(TMndxFindResult * pStruct1C, DWORD arg_4);
    bool sub_1958B00(TMndxFindResult * pStruct1C);
    bool sub_1959460(TMndxFindResult * pStruct1C);

    TSparseArray Struct68_00;
    TSparseArray FileNameIndexes;               // Array of file name indexes
    TSparseArray Struct68_D0;

    // This pair of arrays serves for fast conversion from name hash to fragment offset
    TGenericArray  FrgmDist_LoBits;             // Array of lower 8 bits of name fragment offset
    TBitEntryArray FrgmDist_HiBits;             // Array of upper x bits of name fragment offset

    TNameIndexStruct IndexStruct_174;
    TFileNameDatabasePtr NextDB;

    TGenericArray NameFragTable;

    DWORD NameFragIndexMask;
    DWORD field_214;
    TStruct10 Struct10;
    TByteStream MarStream;
};

typedef struct _MAR_FILE
{
    TFileNameDatabasePtr * pDatabasePtr;
    LPBYTE pbMarData;
    DWORD cbMarData;
} MAR_FILE, *PMAR_FILE;

//-----------------------------------------------------------------------------
// Macros

// Returns nonzero if the name fragment match is a single-char match
inline bool IS_SINGLE_CHAR_MATCH(TGenericArray & Table, DWORD ItemIndex)
{
    return ((Table.NameFragArray[ItemIndex].FragOffs & 0xFFFFFF00) == 0xFFFFFF00);
}

//-----------------------------------------------------------------------------
// CASC functions related to MNDX

int  LoadMndxRootFile(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile);
PCASC_PACKAGE FindMndxPackage(TCascStorage * hs, const char * szFileName);
int  SearchMndxInfo(PCASC_MNDX_INFO pMndxInfo, const char * szFileName, DWORD dwPackage, PCASC_ROOT_KEY_INFO pFoundInfo);
bool DoStorageSearch_MNDX(TCascSearch * pSearch, PCASC_FIND_DATA pFindData);
void FreeMndxInfo(PCASC_MNDX_INFO pMndxInfo);

#endif  // __CASC_MNDX_ROOT__
