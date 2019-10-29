/*****************************************************************************/
/* Map.h                                  Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* Interface of hash-to-ptr map for CascLib                                  */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 10.06.14  1.00  Lad  The first version of Map.h                           */
/*****************************************************************************/

#ifndef __CASC_MAP_H__
#define __CASC_MAP_H__

//-----------------------------------------------------------------------------
// Structures

#define MIN_HASH_TABLE_SIZE     0x00000100      // The smallest size of the hash table.
#define MAX_HASH_TABLE_SIZE     0x00800000      // The largest size of the hash table. Should be enough for any game.

typedef int   (*PFNCOMPAREFUNC)(const void * pvObjectKey, const void * pvKey, size_t nKeyLength);
typedef DWORD (*PFNHASHFUNC)(void * pvKey, size_t nKeyLength);

typedef enum _KEY_TYPE
{
    KeyIsHash,                                  // Use when the key is already a hash. If specified, the map will not hash the key
    KeyIsArbitrary,                             // The key is an arbitrary array of bytes. The map will hash it to get a map index
    KeyIsString                                 // Use when the key is a string
} KEY_TYPE, *PKEY_TYPE;

#define KEY_LENGTH_STRING 0xFFFFFFFF

//-----------------------------------------------------------------------------
// Hashing functions

// Used when the key is a hash already - no need to hash it again
inline DWORD CalcHashValue_Hash(void * pvKey, size_t /* nKeyLength */)
{
    // Get the hash directly as value
    return ConvertBytesToInteger_4((LPBYTE)pvKey);
}

// Calculates hash value from a key
inline DWORD CalcHashValue_Key(void * pvKey, size_t nKeyLength)
{
    LPBYTE pbKey = (LPBYTE)pvKey;
    DWORD dwHash = 0x7EEE7EEE;

    // Construct the hash from the key
    for(DWORD i = 0; i < nKeyLength; i++)
        dwHash = (dwHash >> 24) ^ (dwHash << 5) ^ dwHash ^ pbKey[i];

    // Return the hash limited by the table size
    return dwHash;
}

// Calculates hash value from a string
inline DWORD CalcHashValue_String(const char * szString, const char * szStringEnd)
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
    return dwHash;
}

//-----------------------------------------------------------------------------
// Map implementation

class CASC_MAP
{
    public:

    CASC_MAP()
    {
        PfnCalcHashValue = NULL;
        m_HashTable = NULL;
        m_HashTableSize = 0;
        m_ItemCount = 0;
        m_KeyOffset = 0;
        m_KeyLength = 0;
        m_bKeyIsHash = false;
    }

    ~CASC_MAP()
    {
        Free();
    }

    DWORD Create(size_t MaxItems, size_t KeyLength, size_t KeyOffset, KEY_TYPE KeyType = KeyIsHash)
    {
        // Set the class variables
        m_KeyLength = CASCLIB_MAX(KeyLength, 8);
        m_KeyOffset = KeyOffset;
        m_ItemCount = 0;

        // Setup the hashing function
        switch(KeyType)
        {
            case KeyIsHash:
                PfnCalcHashValue = CalcHashValue_Hash;
                break;

            case KeyIsArbitrary:
                PfnCalcHashValue = CalcHashValue_Key;
                break;

            case KeyIsString:
                PfnCalcHashValue = NULL;
                break;

            default:
                assert(false);
                return ERROR_NOT_SUPPORTED;
        }

        // Calculate the hash table size. Take 133% of the item count and round it up to the next power of two
        // This will make the hash table indexes somewhat more resilient against count changes and will make
        // e.g. file order in the file tree more stable.
        m_HashTableSize = GetNearestPowerOfTwo(MaxItems * 4 / 3);
        if(m_HashTableSize == 0)
            return ERROR_NOT_ENOUGH_MEMORY;

        // Allocate new map for the objects
        m_HashTable = (void **)CASC_ALLOC_ZERO<void *>(m_HashTableSize);
        return (m_HashTable != NULL) ? ERROR_SUCCESS : ERROR_NOT_ENOUGH_MEMORY;
    }

    void * FindObject(void * pvKey, PDWORD PtrIndex = NULL)
    {
        void * pvObject;
        DWORD dwHashIndex;

        // Verify pointer to the map
        if(m_HashTable != NULL)
        {
            // Construct the hash index
            dwHashIndex = HashToIndex(PfnCalcHashValue(pvKey, m_KeyLength));

            // Search the hash table
            while((pvObject = m_HashTable[dwHashIndex]) != NULL)
            {
                // Compare the hash
                if(CompareObject_Key(pvObject, pvKey))
                {
                    if(PtrIndex != NULL)
                        PtrIndex[0] = dwHashIndex;
                    return pvObject;
                }

                // Move to the next entry
                dwHashIndex = HashToIndex(dwHashIndex + 1);
            }
        }

        // Not found, sorry
        return NULL;
    }

    bool InsertObject(void * pvNewObject, void * pvKey)
    {
        void * pvExistingObject;
        DWORD dwHashIndex;

        // Verify pointer to the map
        if(m_HashTable != NULL)
        {
            // Limit check
            if((m_ItemCount + 1) >= m_HashTableSize)
                return false;

            // Construct the hash index
            dwHashIndex = HashToIndex(PfnCalcHashValue(pvKey, m_KeyLength));

            // Search the hash table
            while((pvExistingObject = m_HashTable[dwHashIndex]) != NULL)
            {
                // Check if hash being inserted conflicts with an existing hash
                if(CompareObject_Key(pvExistingObject, pvKey))
                    return false;

                // Move to the next entry
                dwHashIndex = HashToIndex(dwHashIndex + 1);
            }

            // Insert at that position
            m_HashTable[dwHashIndex] = pvNewObject;
            m_ItemCount++;
            return true;
        }

        // Failed
        return false;
    }

    const char * FindString(const char * szString, const char * szStringEnd)
    {
        const char * szExistingString;
        DWORD dwHashIndex;

        // Verify pointer to the map
        if(m_HashTable != NULL)
        {
            // Construct the main index
            dwHashIndex = HashToIndex(CalcHashValue_String(szString, szStringEnd));

            // Search the hash table
            while((szExistingString = (const char *)m_HashTable[dwHashIndex]) != NULL)
            {
                // Compare the hash
                if(CompareObject_String(szExistingString, szString, szStringEnd))
                    return szExistingString;

                // Move to the next entry
                dwHashIndex = HashToIndex(dwHashIndex + 1);
            }
        }

        // Not found, sorry
        return NULL;
    }

    bool InsertString(const char * szString, bool bCutExtension)
    {
        const char * szExistingString;
        const char * szStringEnd = NULL;
        DWORD dwHashIndex;

        // Verify pointer to the map
        if(m_HashTable != NULL)
        {
            // Limit check
            if((m_ItemCount + 1) >= m_HashTableSize)
                return false;

            // Retrieve the length of the string without extension
            if(bCutExtension)
                szStringEnd = GetFileExtension(szString);
            else
                szStringEnd = szString + strlen(szString);

            // Construct the hash index
            dwHashIndex = HashToIndex(CalcHashValue_String(szString, szStringEnd));

            // Search the hash table
            while((szExistingString = (const char *)m_HashTable[dwHashIndex]) != NULL)
            {
                // Check if hash being inserted conflicts with an existing hash
                if(CompareObject_String(szExistingString, szString, szStringEnd))
                    return false;

                // Move to the next entry
                dwHashIndex = HashToIndex(dwHashIndex + 1);
            }

            // Insert at that position
            m_HashTable[dwHashIndex] = (void *)szString;
            m_ItemCount++;
            return true;
        }

        // Failed
        return false;
    }

    void * ItemAt(size_t nIndex)
    {
        assert(nIndex < m_HashTableSize);
        return m_HashTable[nIndex];
    }

    size_t HashTableSize()
    {
        return m_HashTableSize;
    }

    size_t ItemCount()
    {
        return m_ItemCount;
    }

    bool IsInitialized()
    {
        return (m_HashTable && m_HashTableSize);
    }

    void Free()
    {
        PfnCalcHashValue = NULL;
        CASC_FREE(m_HashTable);
        m_HashTableSize = 0;
    }

    protected:

    DWORD HashToIndex(DWORD HashValue)
    {
        return HashValue & (m_HashTableSize - 1);
    }

    bool CompareObject_Key(void * pvObject, void * pvKey)
    {
        LPBYTE pbObjectKey = (LPBYTE)pvObject + m_KeyOffset;
        return (memcmp(pbObjectKey, pvKey, m_KeyLength) == 0);
    }

    bool CompareObject_String(const char * szExistingString, const char * szString, const char * szStringEnd)
    {
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

    size_t GetNearestPowerOfTwo(size_t MaxItems)
    {
        size_t PowerOfTwo;
        
        // Round the hash table size up to the nearest power of two
        for(PowerOfTwo = MIN_HASH_TABLE_SIZE; PowerOfTwo <= MAX_HASH_TABLE_SIZE; PowerOfTwo <<= 1)
        {
            if(PowerOfTwo > MaxItems)
            {
                return PowerOfTwo;
            }
        }

        // If the hash table is too big, we cannot create the map
        assert(false);
        return 0;
    }

    PFNHASHFUNC PfnCalcHashValue;
    void ** m_HashTable;                        // Hash table
    size_t m_HashTableSize;                     // Size of the hash table, in entries. Always a power of two.
    size_t m_ItemCount;                         // Number of objects in the map
    size_t m_KeyOffset;                         // How far is the hash from the begin of the objects (in bytes)
    size_t m_KeyLength;                         // Length of the hash key, in bytes
    bool m_bKeyIsHash;                          // If set, then it means that the key is a hash of some sort.
                                                // Will improve performance, as we will not hash a hash :-)
};

#endif // __CASC_MAP_H__
