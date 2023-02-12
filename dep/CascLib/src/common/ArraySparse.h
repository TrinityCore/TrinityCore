/*****************************************************************************/
/* ArraySparse.h                          Copyright (c) Ladislav Zezula 2022 */
/*---------------------------------------------------------------------------*/
/* This is somewhat more effective version of CASC_ARRAY, used for mapping   */
/* of uint32_t -> pointer. Works better when there are large gaps in seqs    */
/* of the source integers and when there is large gap at the beginning       */
/* of the array.                                                             */
/*                                                                           */
/* This ofject works as multi-level table, where each byte from the mapping  */
/* integer is an index to the appropriate sub-table                          */
/*                                                                           */
/* Example: Mapping of 11223344 -> POINTER                                   */
/*                                                                           */
/* The source uint_32_t is divided into 4 bytes. Each byte is an index to    */
/* the corresponding level-N sub-table                                       */
/*                                                                           */
/*  [*] 0x11223344 -> {0x11, 0x22, 0x33, 0x44}                               */
/*                                                                           */
/* 0x11 is the index to the level-0 table. Contains pointer to level-1 table */
/* 0x22 is the index to the level-1 table. Contains pointer to level-2 table */
/* 0x33 is the index to the level-2 table. Contains pointer to level-3 table */
/* 0x44 is the index to the level-3 table. Contains the result POINTER       */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 14.12.22  1.00  Lad  Created                                              */
/*****************************************************************************/

#ifndef __CASC_SPARSE_ARRAY_H__
#define __CASC_SPARSE_ARRAY_H__

//-----------------------------------------------------------------------------
// Structure of the 256-item sub-table. Each table item contains either
// pointer to the lower sub-table (if present) or the pointer to the target item

struct CASC_ARRAY_256
{
    CASC_ARRAY_256()
    {
        memset(Pointers, 0, sizeof(Pointers));
    }

    CASC_ARRAY_256 * GetLowerLevel(size_t nIndex)
    {
        return (CASC_ARRAY_256 *)(Pointers[nIndex & 0xFF]);
    }

    CASC_ARRAY_256 ** SubTable(size_t ItemIndex, size_t nLevel)
    {
        // Calculate the bit shift for getting the level index
        size_t nShift = 0x20 - (nLevel * 8);
        size_t nIndex = (ItemIndex >> nShift) & 0xFF;

        // Return reference to the item
        return (CASC_ARRAY_256 **)(&Pointers[nIndex]);
    }

    void Reset(size_t nLevel)
    {
        CASC_ARRAY_256 * pLower;

        // For levels 0, 1, 2, free the sub-items, if any
        if(nLevel < 3)
        {
            for(size_t i = 0; i < _countof(Pointers); i++)
            {
                if((pLower = GetLowerLevel(i)) != NULL)
                {
                    pLower->Reset(nLevel + 1);
                }
            }
        }

        // Set all pointers to NULL for level 3
        else
        {
            memset(Pointers, 0, sizeof(CASC_ARRAY_256));
        }
    }

    void Free(size_t nLevel)
    {
        CASC_ARRAY_256 * pLower;

        // For levels 0, 1, 2, free the sub-items, if any
        if(nLevel < 3)
        {
            for(size_t i = 0; i < _countof(Pointers); i++)
            {
                if((pLower = GetLowerLevel(i)) != NULL)
                {
                    pLower->Free(nLevel + 1);
                    delete pLower;
                }
            }
        }

        // Set all pointers to NULL
        memset(Pointers, 0, sizeof(CASC_ARRAY_256));
    }

    void * Pointers[0x100];
};

//-----------------------------------------------------------------------------
// Interface to the sparse array class

class CASC_SPARSE_ARRAY
{
    public:

    CASC_SPARSE_ARRAY()
    {
        m_LevelsAllocated = 0;
        m_ItemCount = 0;
        m_pLevel0 = NULL;
    }

    ~CASC_SPARSE_ARRAY()
    {
        Free();
    }

    // Creates an array with a custom element type
    template<typename TYPE>
    DWORD Create(size_t /* ItemCountMax */)
    {
        if((m_pLevel0 = new CASC_ARRAY_256()) != NULL)
        {
            m_LevelsAllocated++;
            return ERROR_SUCCESS;
        }
        return ERROR_NOT_ENOUGH_MEMORY;
    }

    // Returns pointer to the cell given index
    void ** ItemAt(size_t ItemIndex)
    {
        CASC_ARRAY_256 * pLevelN;

        // The index must be 32-bit only
        assert((DWORD)(ItemIndex) == ItemIndex);

        // Get the level-0 index
        if((pLevelN = m_pLevel0) != NULL)
        {
            if((pLevelN = GetLowerLevelTable(pLevelN, ItemIndex, 1)) != NULL)
            {
                if((pLevelN = GetLowerLevelTable(pLevelN, ItemIndex, 2)) != NULL)
                {
                    if((pLevelN = GetLowerLevelTable(pLevelN, ItemIndex, 3)) != NULL)
                    {
                        return &pLevelN->Pointers[ItemIndex & 0xFF];
                    }
                }
            }
        }

        // Not present
        return NULL;
    }

    // Inserts an item at a given index and returns pointer to its cell
    void ** InsertAt(size_t ItemIndex)
    {
        CASC_ARRAY_256 * pLevelN;

        // The index must be 32-bit only
        assert((DWORD)(ItemIndex) == ItemIndex);

        // Get the level-0 index
        if((pLevelN = m_pLevel0) != NULL)
        {
            if((pLevelN = EnsureLowerLevelTable(pLevelN, ItemIndex, 1)) != NULL)
            {
                if((pLevelN = EnsureLowerLevelTable(pLevelN, ItemIndex, 2)) != NULL)
                {
                    if((pLevelN = EnsureLowerLevelTable(pLevelN, ItemIndex, 3)) != NULL)
                    {
                        // Increment the max index and return the pointer to the appropriate cell
                        if(ItemIndex >= m_ItemCount)
                            m_ItemCount = ItemIndex + 1;
                        return &pLevelN->Pointers[ItemIndex & 0xFF];
                    }
                }
            }
        }

        // Not enough memory
        return NULL;
    }

    // Invalidates the entire array, but keeps memory allocated
    void Reset()
    {
        if(m_pLevel0 != NULL)
        {
            m_pLevel0->Reset(0);
        }
    }

    // Frees the array
    void Free()
    {
        if(m_pLevel0 != NULL)
        {
            m_pLevel0->Free(0);
            delete m_pLevel0;
        }
    }

    size_t ItemCount()
    {
        return m_ItemCount;
    }

    size_t ItemCountMax()
    {
        return 0xFFFFFFFF;
    }

    size_t ItemSize()
    {
        return sizeof(void *);
    }

    bool IsInitialized()
    {
        return (m_pLevel0 != NULL);
    }

#ifdef _DEBUG
    size_t BytesAllocated()
    {
        return m_LevelsAllocated * sizeof(CASC_ARRAY_256);
    }

    void Dump(const char * szFileName)
    {
        FILE * fp;
        size_t * RefItem;
        size_t Item;

        if((fp = fopen(szFileName, "wb")) != NULL)
        {
            for(size_t i = 0; i < m_ItemCount; i++)
            {
                RefItem = (size_t *)ItemAt(i);
                Item = (RefItem != NULL) ? RefItem[0] : 0;
                fwrite(&Item, ItemSize(), 1, fp);
            }
            fclose(fp);
        }
    }
#endif

    protected:

    CASC_ARRAY_256 * GetLowerLevelTable(CASC_ARRAY_256 * pTable, size_t ItemIndex, size_t nLevel)
    {
        CASC_ARRAY_256 ** SubTable = pTable->SubTable(ItemIndex, nLevel);

        // Get the n-th item from the table
        return SubTable[0];
    }

    CASC_ARRAY_256 * EnsureLowerLevelTable(CASC_ARRAY_256 * pTable, size_t ItemIndex, size_t nLevel)
    {
        CASC_ARRAY_256 ** SubTable = pTable->SubTable(ItemIndex, nLevel);

        // Is there an item?
        if(SubTable[0] == NULL)
        {
            SubTable[0] = new CASC_ARRAY_256();
            m_LevelsAllocated++;
        }
        return SubTable[0];
    }

    // Level-0 subitem table
    CASC_ARRAY_256 * m_pLevel0;                 // Array of level 0 of pointers
    size_t m_LevelsAllocated;                   // Number of CASC_ARRAY_256's allocated (for debugging purposes)
    size_t m_ItemCount;                         // The number of items inserted
};

#endif // __CASC_SPARSE_ARRAY_H__
