/*****************************************************************************/
/* IndexMap.h                             Copyright (c) Ladislav Zezula 2019 */
/*---------------------------------------------------------------------------*/
/* Interface of index-based map for CascLib. This is a map type created      */
/* on top of an array of contant-size objects, that is already sorted.       */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 29.04.19  1.00  Lad  The first version of Index.h                         */
/*****************************************************************************/

#ifndef __CASC_INDEX_MAP_H__
#define __CASC_INDEX_MAP_H__

//-----------------------------------------------------------------------------
// Structures

class CASC_INDEX_MAP
{
    public:

    int Create(size_t MaxItems, size_t ObjectLength_, size_t KeyLength_, size_t KeyOffset_)
    {
        DWORD IndexBitSize = 8;

        // Determine the index size
        if(MaxItems >= 0x10000)
            IndexBitSize = 16;
        if(MaxItems >= 0x100000)
            IndexBitSize = 20;

        // Save the values
        IndexTableSize = (1 << IndexBitSize);
        IndexTableMask = IndexTableSize - 1;
        ObjectLength = ObjectLength_;
        KeyOffset = KeyOffset_;
        KeyLength = KeyLength_;

        // Allocate the new index object
        IndexTable = CASC_ALLOC(void *, IndexTableSize);
        if(IndexTable != NULL)
        {
            memset(IndexTable, 0, IndexTableSize * sizeof(void *));
            return ERROR_SUCCESS;
        }

        return ERROR_NOT_ENOUGH_MEMORY;
    }

    void * FindObject(void * pvKey)
    {
        LPBYTE StartObject;
        DWORD StartIndex;

        // Verify pointer to the map
        if(IndexTable != NULL)
        {
            // Retrieve the index from the key
            StartIndex = KeyToIndex(pvKey);
            StartObject = (LPBYTE)IndexTable[StartIndex];
            if(StartObject == NULL)
                return NULL;

            // Enumerate the array as long as the index matches
            do
            {
                // Compare the key
                if(!memcmp(StartObject + KeyOffset, pvKey, KeyLength))
                    return StartObject;

                // Key mismatch -> go next object
                StartObject = StartObject + ObjectLength;
            }
            while(KeyToIndex(StartObject + KeyOffset) == StartIndex);
        }

        // Not found
        return NULL;
    }

    protected:

    inline DWORD KeyToIndex(void * pvKey)
    {
        return *((PDWORD)pvKey) & IndexTableMask;
    }

    void ** IndexTable;                         // Pointer table. Each entry, if non-NULL, contains a pointer to the first object
                                                // into a sorted array. Search function must then match the entire key.
                                                // In case of no match, the search process must go to the next-in-array object.
    size_t ObjectLength;                        // Length of the single object
    size_t KeyOffset;                           // How far is the key from the begin of the structure (in bytes)
    size_t KeyLength;                           // Length of the key
    DWORD  IndexTableSize;                      // Size of the IndexTableSize, in bytes
    DWORD  IndexTableMask;                      // Bit mask for conversion from hash to index
};

typedef CASC_INDEX_MAP *PCASC_INDEX_MAP;

//-----------------------------------------------------------------------------
// Functions

bool IndexMap_InsertObject(PCASC_INDEX_MAP pIndexMap, void * pvNewObject, void * pvKey);
void IndexMap_Free(PCASC_INDEX_MAP pIndexMap);

#endif // __CASC_INDEX_MAP_H__
