/*****************************************************************************/
/* Map.cpp                                Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* Implementation of map for CascLib                                         */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 10.06.14  1.00  Lad  The first version of Map.cpp                         */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "../CascLib.h"
#include "../CascCommon.h"

//-----------------------------------------------------------------------------
// Local functions

static DWORD CalcHashIndex(PCASC_MAP pMap, void * pvIdentifier)
{
    DWORD dwHash = 0x7EEE7EEE;

    // Is it a string table?
    if(pMap->KeyLength == KEY_LENGTH_STRING)
    {
        char * szString = (char *)pvIdentifier;

        for(size_t i = 0; szString[i] != 0; i++)
            dwHash = (dwHash >> 24) ^ (dwHash << 5) ^ dwHash ^ szString[i];
    }
    else
    {
        LPBYTE pbHash = (LPBYTE)pvIdentifier;

        // Construct the hash from the first 4 digits
        for(size_t i = 0; i < pMap->KeyLength; i++)
            dwHash = (dwHash >> 24) ^ (dwHash << 5) ^ dwHash ^ pbHash[i];
    }

    // Return the hash limited by the table size
    return (dwHash % pMap->TableSize);
}

static bool CompareIdentifier(PCASC_MAP pMap, void * pvTableEntry, void * pvIdentifier)
{
    // Is it a string table?
    if(pMap->KeyLength == KEY_LENGTH_STRING)
    {
        char * szTableEntry = (char *)pvTableEntry;
        char * szIdentifier = (char *)pvIdentifier;

        return (strcmp(szTableEntry, szIdentifier) == 0);
    }
    else
    {
        return (memcmp(pvTableEntry, pvIdentifier, pMap->KeyLength) == 0);
    }
}

//-----------------------------------------------------------------------------
// Public functions

PCASC_MAP Map_Create(DWORD dwMaxItems, DWORD dwKeyLength, DWORD dwMemberOffset)
{
    PCASC_MAP pMap;
    size_t cbToAllocate;
    size_t dwTableSize;

    // Calculate the size of the table
    dwTableSize = (dwMaxItems * 3 / 2) | 0x01;

    // Allocate new map for the objects
    cbToAllocate = sizeof(CASC_MAP) + (dwTableSize * sizeof(void *));
    pMap = (PCASC_MAP)CASC_ALLOC(LPBYTE, cbToAllocate);
    if(pMap != NULL)
    {
        memset(pMap, 0, cbToAllocate);
        pMap->KeyLength = dwKeyLength;
        pMap->TableSize = dwTableSize;
        pMap->MemberOffset = dwMemberOffset;
    }

    // Return the allocated map
    return pMap;
}

size_t Map_EnumObjects(PCASC_MAP pMap, void **ppvArray)
{
    size_t nIndex = 0;

    // Verify pointer to the map
    if(pMap != NULL && ppvArray != NULL)
    {
        // Enumerate all items in main table
        for(size_t i = 0; i < pMap->TableSize; i++)
        {
            // Is that cell valid?
            if(pMap->HashTable[i] != NULL)
            {
                ppvArray[nIndex++] = pMap->HashTable[i];
            }
        }
    }

    return pMap->ItemCount;
}

void * Map_FindObject(PCASC_MAP pMap, void * pvIdentifier)
{
    void * pvTableEntry;
    DWORD dwHashIndex;

    // Verify pointer to the map
    if(pMap != NULL)
    {
        // Construct the main index
        dwHashIndex = CalcHashIndex(pMap, pvIdentifier);
        while(pMap->HashTable[dwHashIndex] != NULL)
        {
            // Get the pointer at that position
            pvTableEntry = pMap->HashTable[dwHashIndex];

            // Compare the hash
            if(CompareIdentifier(pMap, pvTableEntry, pvIdentifier))
                return ((LPBYTE)pvTableEntry - pMap->MemberOffset);

            // Move to the next entry
            dwHashIndex = (dwHashIndex + 1) % pMap->TableSize;
        }
    }

    // Not found, sorry
    return NULL;
}

bool Map_InsertObject(PCASC_MAP pMap, void * pvIdentifier)
{
    void * pvTableEntry;
    DWORD dwHashIndex;

    // Verify pointer to the map
    if(pMap != NULL)
    {
        // Limit check
        if((pMap->ItemCount + 1) >= pMap->TableSize)
            return false;

        // Construct the hash index
        dwHashIndex = CalcHashIndex(pMap, pvIdentifier);
        while(pMap->HashTable[dwHashIndex] != NULL)
        {
            // Get the pointer at that position
            pvTableEntry = pMap->HashTable[dwHashIndex];

            // Check if hash being inserted conflicts with an existing hash
            if(CompareIdentifier(pMap, pvTableEntry, pvIdentifier))
                return false;

            // Move to the next entry
            dwHashIndex = (dwHashIndex + 1) % pMap->TableSize;
        }

        // Insert at that position
        pMap->HashTable[dwHashIndex] = pvIdentifier;
        pMap->ItemCount++;
        return true;
    }

    // Failed
    return false;
}

void Map_Free(PCASC_MAP pMap)
{
    if(pMap != NULL)
    {
        CASC_FREE(pMap);
    }
}
