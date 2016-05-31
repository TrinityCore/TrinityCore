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

// Returns the extension, right after "."
static const char * String_GetExtension(const char * szString)
{
    const char * szExtension = strrchr(szString, '.');
    return (szExtension != NULL) ? szExtension + 1 : NULL;
}

static DWORD CalcHashIndex_Key(PCASC_MAP pMap, void * pvKey)
{
    LPBYTE pbKey = (LPBYTE)pvKey;
    DWORD dwHash = 0x7EEE7EEE;

    // Construct the hash from the first 8 digits
    dwHash = (dwHash >> 24) ^ (dwHash << 5) ^ dwHash ^ pbKey[0];
    dwHash = (dwHash >> 24) ^ (dwHash << 5) ^ dwHash ^ pbKey[1];
    dwHash = (dwHash >> 24) ^ (dwHash << 5) ^ dwHash ^ pbKey[2];
    dwHash = (dwHash >> 24) ^ (dwHash << 5) ^ dwHash ^ pbKey[3];
    dwHash = (dwHash >> 24) ^ (dwHash << 5) ^ dwHash ^ pbKey[4];
    dwHash = (dwHash >> 24) ^ (dwHash << 5) ^ dwHash ^ pbKey[5];
    dwHash = (dwHash >> 24) ^ (dwHash << 5) ^ dwHash ^ pbKey[6];
    dwHash = (dwHash >> 24) ^ (dwHash << 5) ^ dwHash ^ pbKey[7];

    // Return the hash limited by the table size
    return (dwHash % pMap->TableSize);
}

static DWORD CalcHashIndex_String(PCASC_MAP pMap, const char * szString, const char * szStringEnd)
{
    LPBYTE pbKeyEnd = (LPBYTE)szStringEnd;
    LPBYTE pbKey = (LPBYTE)szString;
    DWORD dwHash = 0x7EEE7EEE;

    // Hash the string itself
    while(pbKey < pbKeyEnd)
    {
        dwHash = (dwHash >> 24) ^ (dwHash << 5) ^ dwHash ^ AsciiToUpperTable_BkSlash[pbKey[0]];
        pbKey++;
    }

    // Return the hash limited by the table size
    return (dwHash % pMap->TableSize);
}

static bool CompareObject_Key(PCASC_MAP pMap, void * pvObject, void * pvKey)
{
    LPBYTE pbObjectKey = (LPBYTE)pvObject + pMap->KeyOffset;

    return (memcmp(pbObjectKey, pvKey, pMap->KeyLength) == 0);
}

static bool CompareObject_String(
    PCASC_MAP pMap,
    const char * szExistingString,
    const char * szString,
    const char * szStringEnd)
{
    // Keep compiler happy
    CASCLIB_UNUSED(pMap);

    // Compare the whole part, case insensitive
    while(szString < szStringEnd)
    {
        if(AsciiToUpperTable_BkSlash[*szExistingString] != AsciiToUpperTable_BkSlash[*szString])
            return false;

        szExistingString++;
        szString++;
    }

    return true;
}

//-----------------------------------------------------------------------------
// Public functions

PCASC_MAP Map_Create(DWORD dwMaxItems, DWORD dwKeyLength, DWORD dwKeyOffset)
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
        pMap->KeyOffset = dwKeyOffset;
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

void * Map_FindObject(PCASC_MAP pMap, void * pvKey, PDWORD PtrIndex)
{
    void * pvObject;
    DWORD dwHashIndex;

    // Verify pointer to the map
    if(pMap != NULL)
    {
        // Construct the main index
        dwHashIndex = CalcHashIndex_Key(pMap, pvKey);
        while(pMap->HashTable[dwHashIndex] != NULL)
        {
            // Get the pointer at that position
            pvObject = pMap->HashTable[dwHashIndex];

            // Compare the hash
            if(CompareObject_Key(pMap, pvObject, pvKey))
            {
                if(PtrIndex != NULL)
                    PtrIndex[0] = dwHashIndex;
                return pvObject;
            }

            // Move to the next entry
            dwHashIndex = (dwHashIndex + 1) % pMap->TableSize;
        }
    }

    // Not found, sorry
    return NULL;
}

bool Map_InsertObject(PCASC_MAP pMap, void * pvNewObject, void * pvKey)
{
    void * pvExistingObject;
    DWORD dwHashIndex;

    // Verify pointer to the map
    if(pMap != NULL)
    {
        // Limit check
        if((pMap->ItemCount + 1) >= pMap->TableSize)
            return false;

        // Construct the hash index
        dwHashIndex = CalcHashIndex_Key(pMap, pvKey);
        while(pMap->HashTable[dwHashIndex] != NULL)
        {
            // Get the pointer at that position
            pvExistingObject = pMap->HashTable[dwHashIndex];

            // Check if hash being inserted conflicts with an existing hash
            if(CompareObject_Key(pMap, pvExistingObject, pvKey))
                return false;

            // Move to the next entry
            dwHashIndex = (dwHashIndex + 1) % pMap->TableSize;
        }

        // Insert at that position
        pMap->HashTable[dwHashIndex] = pvNewObject;
        pMap->ItemCount++;
        return true;
    }

    // Failed
    return false;
}

bool Map_InsertString(PCASC_MAP pMap, const char * szString, bool bCutExtension)
{
    const char * szExistingString;
    const char * szStringEnd = NULL;
    DWORD dwHashIndex;

    // Verify pointer to the map
    if(pMap != NULL)
    {
        // Limit check
        if((pMap->ItemCount + 1) >= pMap->TableSize)
            return false;

        // Retrieve the length of the string without extension
        if(bCutExtension)
            szStringEnd = String_GetExtension(szString);
        if(szStringEnd == NULL)
            szStringEnd = szString + strlen(szString);

        // Construct the hash index
        dwHashIndex = CalcHashIndex_String(pMap, szString, szStringEnd);
        while(pMap->HashTable[dwHashIndex] != NULL)
        {
            // Get the pointer at that position
            szExistingString = (const char *)pMap->HashTable[dwHashIndex];

            // Check if hash being inserted conflicts with an existing hash
            if(CompareObject_String(pMap, szExistingString, szString, szStringEnd))
                return false;

            // Move to the next entry
            dwHashIndex = (dwHashIndex + 1) % pMap->TableSize;
        }

        // Insert at that position
        pMap->HashTable[dwHashIndex] = (void *)szString;
        pMap->ItemCount++;
        return true;
    }

    // Failed
    return false;
}

const char * Map_FindString(PCASC_MAP pMap, const char * szString, const char * szStringEnd)
{
    const char * szExistingString;
    DWORD dwHashIndex;

    // Verify pointer to the map
    if(pMap != NULL)
    {
        // Construct the main index
        dwHashIndex = CalcHashIndex_String(pMap, szString, szStringEnd);
        while(pMap->HashTable[dwHashIndex] != NULL)
        {
            // Get the pointer at that position
            szExistingString = (const char *)pMap->HashTable[dwHashIndex];

            // Compare the hash
            if(CompareObject_String(pMap, szExistingString, szString, szStringEnd))
                return szExistingString;

            // Move to the next entry
            dwHashIndex = (dwHashIndex + 1) % pMap->TableSize;
        }
    }

    // Not found, sorry
    return NULL;
}

void Map_Free(PCASC_MAP pMap)
{
    if(pMap != NULL)
    {
        CASC_FREE(pMap);
    }
}
