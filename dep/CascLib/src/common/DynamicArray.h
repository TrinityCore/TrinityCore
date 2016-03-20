/*****************************************************************************/
/* DynamicArray.h                         Copyright (c) Ladislav Zezula 2015 */
/*---------------------------------------------------------------------------*/
/* Common array implementation                                               */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 30.10.15  1.00  Lad  The first version of DynamicArray.h                  */
/*****************************************************************************/

#ifndef __DYNAMIC_ARRAY_H__
#define __DYNAMIC_ARRAY_H__

//-----------------------------------------------------------------------------
// Structures

typedef struct _DYNAMIC_ARRAY
{
    char * ItemArray;                               // Pointer to items
    size_t ItemCountMax;                            // Current number of items
    size_t ItemCount;                               // Total size of the buffer
    size_t ItemSize;                                // Size of the single item

} DYNAMIC_ARRAY, *PDYNAMIC_ARRAY;

//-----------------------------------------------------------------------------
// Functions for managing the array

int Array_Create_(PDYNAMIC_ARRAY pArray, size_t ItemSize, size_t ItemCountMax);
void * Array_Insert(PDYNAMIC_ARRAY pArray, const void * NewItems, size_t NewItemCount);
void * Array_ItemAt(PDYNAMIC_ARRAY pArray, size_t ItemIndex);
size_t Array_IndexOf(PDYNAMIC_ARRAY pArray, const void * ArrayPtr);
void Array_Free(PDYNAMIC_ARRAY pArray);

#define Array_Create(pArray, type, ItemCountMax)    Array_Create_(pArray, sizeof(type), ItemCountMax)

#endif // __DYNAMIC_ARRAY__
