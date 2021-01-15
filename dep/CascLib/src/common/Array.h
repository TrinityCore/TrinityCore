/*****************************************************************************/
/* Array.h                                Copyright (c) Ladislav Zezula 2015 */
/*---------------------------------------------------------------------------*/
/* Common array implementation                                               */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 30.10.15  1.00  Lad  The first version of DynamicArray.h                  */
/* 10.08.18  1.00  Lad  CLASS-ified, renamed to Array.h                      */
/*****************************************************************************/

#ifndef __CASC_ARRAY_H__
#define __CASC_ARRAY_H__

//-----------------------------------------------------------------------------
// Structures

class CASC_ARRAY
{
    public:

    CASC_ARRAY()
    {
        m_pItemArray = NULL;
        m_ItemCountMax = 0;
        m_ItemCount = 0;
        m_ItemSize = 0;
    }

    ~CASC_ARRAY()
    {
        Free();
    }

    // Creates an array with a custom element type
    template<typename TYPE>
    int Create(size_t ItemCountMax)
    {
        return Create(sizeof(TYPE), ItemCountMax);
    }

    // Creates an array with a custom element size
    int Create(size_t ItemSize, size_t ItemCountMax)
    {
        // Create the array
        if ((m_pItemArray = CASC_ALLOC<BYTE>(ItemSize * ItemCountMax)) == NULL)
            return ERROR_NOT_ENOUGH_MEMORY;

        m_ItemCountMax = ItemCountMax;
        m_ItemCount = 0;
        m_ItemSize = ItemSize;
        return ERROR_SUCCESS;
    }

    // Inserts one or more items; returns pointer to the first inserted item
    void * Insert(size_t NewItemCount, bool bEnlargeAllowed = true)
    {
        void * pNewItems;

        // Try to enlarge the buffer, if needed
        if (!EnlargeArray(m_ItemCount + NewItemCount, bEnlargeAllowed))
            return NULL;
        pNewItems = m_pItemArray + (m_ItemCount * m_ItemSize);

        // Increment the size of the array
        m_ItemCount += NewItemCount;

        // Return pointer to the new item
        return pNewItems;
    }

    // Inserts one or more items; returns pointer to the first inserted item
    void * Insert(const void * NewItems, size_t NewItemCount, bool bEnlargeAllowed = true)
    {
        void * pNewItem = Insert(NewItemCount, bEnlargeAllowed);

        // Copy the item(s) to the array, if any
        if (pNewItem && NewItems)
            memcpy(pNewItem, NewItems, (NewItemCount * m_ItemSize));
        return pNewItem;
    }

    // Returns an item at a given index
    void * ItemAt(size_t ItemIndex)
    {
        return (ItemIndex < m_ItemCount) ? (m_pItemArray + (ItemIndex * m_ItemSize)) : NULL;
    }

    void * LastItem()
    {
        return m_pItemArray + (m_ItemCount * m_ItemSize);
    }

    // Inserts an item at a given index. If there is not enough items in the array,
    // the array will be enlarged. Should any gaps to be created, the function will zero them
    void * InsertAt(size_t ItemIndex)
    {
        LPBYTE pbLastItem;
        LPBYTE pbNewItem;

        // Make sure we have array large enough
        if(!EnlargeArray(ItemIndex + 1, true))
            return NULL;
        
        // Get the items range
        pbLastItem = m_pItemArray + (m_ItemCount * m_ItemSize);
        pbNewItem = m_pItemArray + (ItemIndex * m_ItemSize);
        m_ItemCount = CASCLIB_MAX(m_ItemCount, ItemIndex+1);

        // If we inserted an item past the current end, we need to clear the items in-between
        if (pbNewItem > pbLastItem)
        {
            memset(pbLastItem, 0, (pbNewItem - pbLastItem));
            m_ItemCount = ItemIndex + 1;
        }

        return pbNewItem;
    }

    // Returns index of an item
    size_t IndexOf(const void * pItem)
    {
        LPBYTE pbItem = (LPBYTE)pItem;

        assert((m_pItemArray <= pbItem) && (pbItem <= m_pItemArray + (m_ItemCount * m_ItemSize)));
        assert(((pbItem - m_pItemArray) % m_ItemSize) == 0);

        return ((pbItem - m_pItemArray) / m_ItemSize);
     }

    void * ItemArray()
    {
        return m_pItemArray;
    }

    size_t ItemCount()
    {
        return m_ItemCount;
    }

    size_t ItemCountMax()
    {
        return m_ItemCountMax;
    }

    size_t ItemSize()
    {
        return m_ItemSize;
    }

    bool IsInitialized()
    {
        return (m_pItemArray && m_ItemCountMax);
    }

    // Invalidates the entire array, but keeps memory allocated
    void Reset()
    {
        memset(m_pItemArray, 0, m_ItemCountMax * m_ItemSize);
        m_ItemCount = 0;
    }

    // Frees the array
    void Free()
    {
        CASC_FREE(m_pItemArray);
        m_ItemCountMax = m_ItemCount = m_ItemSize = 0;
    }

    protected:

    bool EnlargeArray(size_t NewItemCount, bool bEnlargeAllowed)
    {
        LPBYTE NewItemArray;
        size_t ItemCountMax;

        // We expect the array to be already allocated
        assert(m_pItemArray != NULL);
        assert(m_ItemCountMax != 0);

        // Shall we enlarge the table?
        if (NewItemCount > m_ItemCountMax)
        {
            // Deny enlarge if not allowed
            if(bEnlargeAllowed == false)
                return false;

            // Calculate new table size
            ItemCountMax = m_ItemCountMax;
            while (ItemCountMax < NewItemCount)
                ItemCountMax = ItemCountMax << 1;

            // Allocate new table
            NewItemArray = CASC_REALLOC(BYTE, m_pItemArray, (ItemCountMax * m_ItemSize));
            if (NewItemArray == NULL)
                return false;

            // Set the new table size
            m_ItemCountMax = ItemCountMax;
            m_pItemArray = NewItemArray;
        }

        return true;
    }

    LPBYTE m_pItemArray;                        // Pointer to item array
    size_t m_ItemCountMax;                      // Maximum item count
    size_t m_ItemCount;                         // Current item count
    size_t m_ItemSize;                          // Size of an item
};

#endif // __CASC_ARRAY__
