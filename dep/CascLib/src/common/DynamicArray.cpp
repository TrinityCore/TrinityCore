/*****************************************************************************/
/* DynamicArray.cpp                       Copyright (c) Ladislav Zezula 2015 */
/*---------------------------------------------------------------------------*/
/* Description:                                                              */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 30.10.15  1.00  Lad  The first version of DynamicArray.cpp                */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "../CascLib.h"
#include "../CascCommon.h"

//-----------------------------------------------------------------------------
// Local functions

static bool EnlargeArray(PDYNAMIC_ARRAY pArray, size_t NewItemCount)
{
    char * NewItemArray;
    size_t ItemCountMax;

    // We expect the array to be already allocated
    assert(pArray->ItemArray != NULL);
    assert(pArray->ItemCountMax != 0);
    
    // Shall we enlarge the table?
    if(NewItemCount > pArray->ItemCountMax)
    {
        // Calculate new table size
        ItemCountMax = pArray->ItemCountMax;
        while(ItemCountMax < NewItemCount)
            ItemCountMax = ItemCountMax << 1;

        // Allocate new table
        NewItemArray = CASC_REALLOC(char, pArray->ItemArray, pArray->ItemSize * ItemCountMax);
        if(NewItemArray == NULL)
            return false;

        // Set the new table size
        pArray->ItemCountMax = ItemCountMax;
        pArray->ItemArray = NewItemArray;
    }

    return true;
}

//-----------------------------------------------------------------------------
// Public functions

int Array_Create_(PDYNAMIC_ARRAY pArray, size_t ItemSize, size_t ItemCountMax)
{
    pArray->ItemArray = CASC_ALLOC(char, (ItemSize * ItemCountMax));
    if(pArray->ItemArray == NULL)
        return ERROR_NOT_ENOUGH_MEMORY;

    pArray->ItemCountMax = ItemCountMax;
    pArray->ItemCount = 0;
    pArray->ItemSize = ItemSize;
    return ERROR_SUCCESS;
}

void * Array_Insert(PDYNAMIC_ARRAY pArray, const void * NewItems, size_t NewItemCount)
{
    char * NewItemPtr;

    // Try to enlarge the buffer, if needed
    if(!EnlargeArray(pArray, pArray->ItemCount + NewItemCount))
        return NULL;
    NewItemPtr = pArray->ItemArray + (pArray->ItemCount * pArray->ItemSize);

    // Copy the old item(s), if any
    if(NewItems != NULL)
        memcpy(NewItemPtr, NewItems, (NewItemCount * pArray->ItemSize));

    // Increment the size of the array
    pArray->ItemCount += NewItemCount;
    return NewItemPtr;
}

void * Array_ItemAt(PDYNAMIC_ARRAY pArray, size_t ItemIndex)
{
    assert(ItemIndex < pArray->ItemCount);
    return pArray->ItemArray + (ItemIndex * pArray->ItemSize);
}

size_t Array_IndexOf(PDYNAMIC_ARRAY pArray, const void * ArrayPtr)
{
    char * ArrayItem = (char *)ArrayPtr;

    assert(pArray->ItemArray <= ArrayItem && ArrayItem <= pArray->ItemArray + (pArray->ItemCount * pArray->ItemSize));
    return ((ArrayItem - pArray->ItemArray) / pArray->ItemSize);
}

void Array_Free(PDYNAMIC_ARRAY pArray)
{
    if(pArray != NULL && pArray->ItemArray != NULL)
    {
        CASC_FREE(pArray->ItemArray);
    }
}
