/*****************************************************************************/
/* Map.h                                  Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* Interface of hash-to-ptr map for CascLib                                  */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 10.06.14  1.00  Lad  The first version of Map.h                           */
/*****************************************************************************/

#ifndef __HASHTOPTR_H__
#define __HASHTOPTR_H__

//-----------------------------------------------------------------------------
// Structures

#define KEY_LENGTH_STRING    0xFFFFFFFF        // Pass this to Map_Create as dwKeyLength when you want map of string->object

typedef struct _CASC_MAP
{
    size_t TableSize;
    size_t ItemCount;                           // Number of items in the map
    size_t MemberOffset;                        // How far is the hash from the begin of the structure (in bytes)
    size_t KeyLength;                           // Length of the hash key
    void * HashTable[1];                        // Pointer table

} CASC_MAP, *PCASC_MAP;

//-----------------------------------------------------------------------------
// Functions

PCASC_MAP Map_Create(DWORD dwMaxItems, DWORD dwKeyLength, DWORD dwMemberOffset);
size_t Map_EnumObjects(PCASC_MAP pMap, void **ppvArray); 
void * Map_FindObject(PCASC_MAP pMap, void * pvIdentifier);
bool Map_InsertObject(PCASC_MAP pMap, void * pvIdentifier);
void Map_Sort(PCASC_MAP pMap);
void Map_Free(PCASC_MAP pMap);

#endif // __HASHTOPTR_H__
