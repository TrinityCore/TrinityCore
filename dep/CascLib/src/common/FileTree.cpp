/*****************************************************************************/
/* FileTree.cpp                           Copyright (c) Ladislav Zezula 2018 */
/*---------------------------------------------------------------------------*/
/* Common implementation of a file tree object for various ROOt file formats */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 29.05.18  1.00  Lad  The first version of FileTree.cpp                    */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "../CascLib.h"
#include "../CascCommon.h"

//-----------------------------------------------------------------------------
// Local defines

#define START_ITEM_COUNT          0x4000

inline DWORD GET_NODE_INT32(void * node, size_t offset)
{
    PDWORD PtrValue = (PDWORD)((LPBYTE)node + offset);
    
    return PtrValue[0];
}

inline void SET_NODE_INT32(void * node, size_t offset, DWORD value)
{
    PDWORD PtrValue = (PDWORD)((LPBYTE)node + offset);
    
    PtrValue[0] = value;
}

//-----------------------------------------------------------------------------
// Protected functions

// Inserts a new file node to the file tree.
// If the pointer to file node array changes, the function also rebuilds all maps
PCASC_FILE_NODE CASC_FILE_TREE::InsertNew(PCASC_CKEY_ENTRY pCKeyEntry)
{
    PCASC_FILE_NODE pFileNode;

    // Create a brand new node
    pFileNode = InsertNew();
    if(pFileNode != NULL)
    {
        // Initialize the file node's CKeyEntry
        pFileNode->pCKeyEntry = pCKeyEntry;

        // Don't insert the node into any of the arrays here.
        // That is the caller's responsibility
    }

    return pFileNode;
}

PCASC_FILE_NODE CASC_FILE_TREE::InsertNew()
{
    PCASC_FILE_NODE pFileNode;
    void * SaveItemArray = NodeTable.ItemArray();   // We need to save the array pointers. If it changes, we must rebuild both maps

    // Create a brand new node
    pFileNode = (PCASC_FILE_NODE)NodeTable.Insert(1);
    if(pFileNode != NULL)
    {
        // Initialize the file node
        pFileNode->FileNameHash = 0;
        pFileNode->pCKeyEntry = NULL;
        pFileNode->Parent = 0;
        pFileNode->NameIndex = 0;
        pFileNode->NameLength = 0;
        pFileNode->Flags = 0;

        // We need to supply a file data id for the new entry, otherwise the rebuilding function
        // will use the uninitialized one
        SetExtras(pFileNode, CASC_INVALID_ID, CASC_INVALID_ID, CASC_INVALID_ID);

        // If the array pointer changed or we are close to the size of the array, we need to rebuild the maps
        if(NodeTable.ItemArray() != SaveItemArray || (NodeTable.ItemCount() * 3 / 2) > NameMap.HashTableSize())
        {
            // Rebuild both maps. Note that rebuilding also inserts all items to the maps, so no need to insert them here
            if(!RebuildNameMaps())
            {
                pFileNode = NULL;
                assert(false);
            }
        }
    }

    return pFileNode;
}

// Insert the node to the map of FileNameHash -> CASC_FILE_NODE
bool CASC_FILE_TREE::InsertToHashTable(PCASC_FILE_NODE pFileNode)
{
    bool bResult = false;

    // Insert the file node to the table
    if(pFileNode->FileNameHash != 0)
        bResult = NameMap.InsertObject(pFileNode, &pFileNode->FileNameHash);
    return bResult;
}

// Inserts the file node to the array of file data ids
bool CASC_FILE_TREE::InsertToIdTable(PCASC_FILE_NODE pFileNode)
{
    PCASC_FILE_NODE * RefElement;
    DWORD FileDataId = CASC_INVALID_ID;

    if(FileDataIds.IsInitialized())
    {
        // Retrieve the file data id
        GetExtras(pFileNode, &FileDataId, NULL, NULL);
        if(FileDataId != CASC_INVALID_ID)
        {
            // Sanity check
            assert(FileDataId < 0x10000000);

            // Insert the element to the array
            RefElement = (PCASC_FILE_NODE *)FileDataIds.InsertAt(FileDataId);
            if(RefElement != NULL)
            {
                RefElement[0] = pFileNode;
                return true;
            }
        }
    }

    return false;
}

bool CASC_FILE_TREE::SetNodePlainName(PCASC_FILE_NODE pFileNode, const char * szPlainName, const char * szPlainNameEnd)
{
    char * szNodeName;
    size_t nLength = (szPlainNameEnd - szPlainName);

    // Insert all chars to the name array
    szNodeName = (char *)NameTable.Insert(nLength);
    if(szNodeName != NULL)
    {
        // Copy the plain name to the node. Do not include the string terminator
        memcpy(szNodeName, szPlainName, nLength);

        // Supply the file name to the file node
        pFileNode->NameIndex = (DWORD)NameTable.IndexOf(szNodeName);
        pFileNode->NameLength = (USHORT)nLength;
        return true;
    }

    return false;
}

bool CASC_FILE_TREE::SetKeyLength(DWORD aKeyLength)
{
    if(aKeyLength > MD5_HASH_SIZE)
        return false;
    KeyLength = aKeyLength;
    return true;
}

DWORD CASC_FILE_TREE::GetNextFileDataId()
{
    if(FileDataIds.IsInitialized())
        return (DWORD)(FileDataIds.ItemCount() + 1);
    return CASC_INVALID_ID;
}

bool CASC_FILE_TREE::RebuildNameMaps()
{
    PCASC_FILE_NODE pFileNode;
    size_t nMaxItems = NodeTable.ItemCountMax();

    // Free the map of "FullName -> CASC_FILE_NODE"
    NameMap.Free();

    // Create new map map "FullName -> CASC_FILE_NODE"
    if(NameMap.Create(nMaxItems, sizeof(ULONGLONG), FIELD_OFFSET(CASC_FILE_NODE, FileNameHash)) != ERROR_SUCCESS)
        return false;

    // Reset the entire array, but keep the buffer allocated
    FileDataIds.Reset();

    // Parse all items and insert them to the map
    for(size_t i = 0; i < NodeTable.ItemCount(); i++)
    {
        // Retrieve the n-th object
        pFileNode = (PCASC_FILE_NODE)NodeTable.ItemAt(i);
        if(pFileNode != NULL)
        {
            // Insert it to the map "FileNameHash -> CASC_FILE_NODE"
            if(pFileNode->FileNameHash != 0)
                InsertToHashTable(pFileNode);

            // Insert it to the array "FileDataId -> CASC_FILE_NODE"
            if(FileDataIds.IsInitialized())
                InsertToIdTable(pFileNode);
        }
    }

    return true;
}

//-----------------------------------------------------------------------------
// Public functions

DWORD CASC_FILE_TREE::Create(DWORD Flags)
{
    PCASC_FILE_NODE pRootNode;
    size_t FileNodeSize = FIELD_OFFSET(CASC_FILE_NODE, ExtraValues);
    DWORD dwErrCode;

    // Initialize the file tree
    memset(this, 0, sizeof(CASC_FILE_TREE));
    KeyLength = MD5_HASH_SIZE;

    // Shall we use the data ID in the tree node?
    if(Flags & FTREE_FLAG_USE_DATA_ID)
    {
        // Set the offset of the file data id in the entry
        FileDataIdOffset = FileNodeSize;
        FileNodeSize += sizeof(DWORD);

        // Create the array for FileDataId -> CASC_FILE_NODE
        dwErrCode = FileDataIds.Create<PCASC_FILE_NODE>(START_ITEM_COUNT);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;
    }

    // Shall we use the locale ID in the tree node?
    if(Flags & FTREE_FLAG_USE_LOCALE_FLAGS)
    {
        LocaleFlagsOffset = FileNodeSize;
        FileNodeSize += sizeof(DWORD);
    }

    if(Flags & FTREE_FLAG_USE_CONTENT_FLAGS)
    {
        ContentFlagsOffset = FileNodeSize;
        FileNodeSize += sizeof(DWORD);
    }

    // Align the file node size to 8 bytes
    FileNodeSize = ALIGN_TO_SIZE(FileNodeSize, 8);

    // Initialize the dynamic array
    dwErrCode = NodeTable.Create(FileNodeSize, START_ITEM_COUNT);
    if(dwErrCode == ERROR_SUCCESS)
    {
        // Create the dynamic array that will hold the node names
        dwErrCode = NameTable.Create<char>(START_ITEM_COUNT);
        if(dwErrCode == ERROR_SUCCESS)
        {
            // Insert the first "root" node, without name
            pRootNode = (PCASC_FILE_NODE)NodeTable.Insert(1);
            if(pRootNode != NULL)
            {
                // Initialize the node
                memset(pRootNode, 0, NodeTable.ItemSize());
                pRootNode->Parent = CASC_INVALID_INDEX;
                pRootNode->NameIndex = CASC_INVALID_INDEX;
                pRootNode->Flags = CFN_FLAG_FOLDER;
                SetExtras(pRootNode, CASC_INVALID_ID, CASC_INVALID_ID, CASC_INVALID_ID);
            }
        }
    }

    // Create both maps
    if(!RebuildNameMaps())
        dwErrCode = ERROR_NOT_ENOUGH_MEMORY;
    return dwErrCode;
}

void CASC_FILE_TREE::Free()
{
    // Free both arrays
    NodeTable.Free();
    NameTable.Free();
    FileDataIds.Free();

    // Free the name map
    NameMap.Free();

    // Zero the object
    memset(this, 0, sizeof(CASC_FILE_TREE));
}

PCASC_FILE_NODE CASC_FILE_TREE::InsertByName(PCASC_CKEY_ENTRY pCKeyEntry, const char * szFileName, DWORD FileDataId, DWORD LocaleFlags, DWORD ContentFlags)
{
    PCASC_FILE_NODE pFileNode;
    ULONGLONG FileNameHash;

    // Sanity checks
    assert(szFileName != NULL && szFileName[0] != 0);
    assert(pCKeyEntry != NULL);

    //char szCKey[MD5_STRING_SIZE+1];
    //char szEKey[MD5_STRING_SIZE+1];
    //StringFromBinary(pCKeyEntry->CKey, MD5_HASH_SIZE, szCKey);
    //StringFromBinary(pCKeyEntry->EKey, MD5_HASH_SIZE, szEKey);
    //printf("%s\t%s\t%s\n", szCKey, szEKey, szFileName);

    //BREAK_ON_XKEY3(pCKeyEntry->EKey, 0x03, 0xDC, 0x7D);

    // Calculate the file name hash
    FileNameHash = CalcFileNameHash(szFileName);

    // Do nothing if the file name is there already.
    pFileNode = (PCASC_FILE_NODE)NameMap.FindObject(&FileNameHash);
    if(pFileNode == NULL)
    {
        // Insert new item
        pFileNode = InsertNew(pCKeyEntry);
        if(pFileNode != NULL)
        {
            // Supply the name hash
            pFileNode->FileNameHash = FileNameHash;

            // Set the file data id and the extra values
            SetExtras(pFileNode, FileDataId, LocaleFlags, ContentFlags);

            // Insert the file node to the hash map
            InsertToHashTable(pFileNode);

            // Also make sure that it's in the file data id table, if the table is initialized
            InsertToIdTable(pFileNode);

            // Set the file name of the new file node
            SetNodeFileName(pFileNode, szFileName);

            // If we created a new node, we need to increment the reference count
            assert(pCKeyEntry->RefCount != 0xFFFF);
            pCKeyEntry->RefCount++;
            FileNodes++;
        }
    }

    return pFileNode;
}

PCASC_FILE_NODE CASC_FILE_TREE::InsertByHash(PCASC_CKEY_ENTRY pCKeyEntry, ULONGLONG FileNameHash, DWORD FileDataId, DWORD LocaleFlags, DWORD ContentFlags)
{
    PCASC_FILE_NODE pFileNode;

    // Sanity checks
    assert(FileDataIds.IsInitialized());
    assert(FileDataId != CASC_INVALID_ID);
    assert(FileNameHash != 0);
    assert(pCKeyEntry != NULL);

    // Insert the node to the tree by file data id
    pFileNode = InsertById(pCKeyEntry, FileDataId, LocaleFlags, ContentFlags);
    if(pFileNode != NULL)
    {
        // Supply the name hash
        pFileNode->FileNameHash = FileNameHash;

        // Insert the file node to the hash map
        InsertToHashTable(pFileNode);
    }

    return pFileNode;
}

PCASC_FILE_NODE CASC_FILE_TREE::InsertById(PCASC_CKEY_ENTRY pCKeyEntry, DWORD FileDataId, DWORD LocaleFlags, DWORD ContentFlags)
{
    PCASC_FILE_NODE pFileNode;

    // Sanity checks
    assert(FileDataIds.IsInitialized());
    assert(FileDataId != CASC_INVALID_ID);
    assert(pCKeyEntry != NULL);

    // Check whether the file data id exists in the array of file data ids
    if((pFileNode = FindById(FileDataId)) == NULL)
    {
        // Insert the new file node
        pFileNode = InsertNew(pCKeyEntry);
        if(pFileNode != NULL)
        {
            // Set the file data id and the extra values
            SetExtras(pFileNode, FileDataId, LocaleFlags, ContentFlags);

            // Insert the file node to the FileDataId array
            InsertToIdTable(pFileNode);

            // Increment the number of references
            pCKeyEntry->RefCount++;
        }
    }

    // Return the new or old node
    return pFileNode;
}

PCASC_FILE_NODE CASC_FILE_TREE::ItemAt(size_t nItemIndex)
{
    return (PCASC_FILE_NODE)NodeTable.ItemAt(nItemIndex);
}

PCASC_FILE_NODE CASC_FILE_TREE::PathAt(char * szBuffer, size_t cchBuffer, size_t nItemIndex)
{
    PCASC_FILE_NODE pFileNode = NULL;

    // If we have FileDataId, then we need to enumerate the files by FileDataId
    if(FileDataIds.IsInitialized())
        pFileNode = *(PCASC_FILE_NODE *)FileDataIds.ItemAt(nItemIndex);
    else
        pFileNode = (PCASC_FILE_NODE)NodeTable.ItemAt(nItemIndex);

    // Construct the entire path
    PathAt(szBuffer, cchBuffer, pFileNode);
    return pFileNode;
}

size_t CASC_FILE_TREE::PathAt(char * szBuffer, size_t cchBuffer, PCASC_FILE_NODE pFileNode)
{
    PCASC_FILE_NODE pParentNode;
    const char * szNamePtr;
    char * szSaveBuffer = szBuffer;
    char * szBufferEnd = szBuffer + cchBuffer - 1;

    if(pFileNode != NULL && pFileNode->Parent != CASC_INVALID_INDEX)
    {
        // Copy all parents
        pParentNode = (PCASC_FILE_NODE)NodeTable.ItemAt(pFileNode->Parent);
        if(pParentNode != NULL)
        {
            // Query the parent and move the buffer
            szBuffer = szBuffer + PathAt(szBuffer, cchBuffer, pParentNode);
        }

        // Retrieve the node name
        szNamePtr = (const char *)NameTable.ItemAt(pFileNode->NameIndex);

        // Check whether we have enough space
        if((szBuffer + pFileNode->NameLength) < szBufferEnd)
        {
            // Copy the path part
            memcpy(szBuffer, szNamePtr, pFileNode->NameLength);
            szBuffer += pFileNode->NameLength;

            // Append backslash
            if((pFileNode->Flags & CFN_FLAG_FOLDER) && ((szBuffer + 1) < szBufferEnd))
            {
                *szBuffer++ = (pFileNode->Flags & CFN_FLAG_MOUNT_POINT) ? ':' : '\\';
            }
        }
    }

    // Terminate buffer with zero
    szBuffer[0] = 0;

    // Return length of the copied string
    return (szBuffer - szSaveBuffer);
}

PCASC_FILE_NODE CASC_FILE_TREE::Find(const char * szFullPath, DWORD FileDataId, PCASC_FIND_DATA pFindData)
{
    PCASC_FILE_NODE pFileNode = NULL;
    ULONGLONG FileNameHash;

    // Can we search by FileDataId?
    if(FileDataIds.IsInitialized() && (FileDataId != CASC_INVALID_ID || IsFileDataIdName(szFullPath, FileDataId)))
    {
        pFileNode = FindById(FileDataId);
    }
    else
    {
        if(szFullPath != NULL && szFullPath[0] != 0)
        {
            FileNameHash = CalcFileNameHash(szFullPath);
            pFileNode = (PCASC_FILE_NODE)NameMap.FindObject(&FileNameHash);
        }
    }

    // Did we find anything?
    if(pFileNode != NULL && pFindData != NULL)
    {
        GetExtras(pFileNode, &pFindData->dwFileDataId, &pFindData->dwLocaleFlags, &pFindData->dwContentFlags);
    }

    return pFileNode;
}

PCASC_FILE_NODE CASC_FILE_TREE::Find(PCASC_CKEY_ENTRY pCKeyEntry)
{
    PCASC_FILE_NODE pFileNode;

    for(size_t i = 0; i < NodeTable.ItemCount(); i++)
    {
        pFileNode = (PCASC_FILE_NODE)NodeTable.ItemAt(i);
        if((pFileNode->Flags & (CFN_FLAG_FOLDER | CFN_FLAG_MOUNT_POINT)) == 0)
        {
            if(pFileNode->pCKeyEntry == pCKeyEntry)
                return pFileNode;
        }
    }

    return NULL;
}

PCASC_FILE_NODE CASC_FILE_TREE::Find(ULONGLONG FileNameHash)
{
    return (PCASC_FILE_NODE)NameMap.FindObject(&FileNameHash);
}

PCASC_FILE_NODE CASC_FILE_TREE::FindById(DWORD FileDataId)
{
    PCASC_FILE_NODE * RefElement;
    PCASC_FILE_NODE pFileNode = NULL;

    if(FileDataId != CASC_INVALID_ID && FileDataIds.IsInitialized())
    {
        // Insert the element to the array
        RefElement = (PCASC_FILE_NODE *)FileDataIds.ItemAt(FileDataId);
        if(RefElement != NULL)
        {
            pFileNode = RefElement[0];
        }
    }

    return pFileNode;
}

bool CASC_FILE_TREE::SetNodeFileName(PCASC_FILE_NODE pFileNode, const char * szFileName)
{
    ULONGLONG FileNameHash = 0;
    PCASC_FILE_NODE pFolderNode = NULL;
    CASC_PATH<char> PathBuffer;
    LPCSTR szNodeBegin = szFileName;
    size_t nFileNode = NodeTable.IndexOf(pFileNode);
    size_t i;
    DWORD Parent = 0;

    // Sanity checks
    assert(szFileName != NULL && szFileName[0] != 0);

    // Traverse the entire path. For each subfolder, we insert an appropriate fake entry
    for(i = 0; szFileName[i] != 0; i++)
    {
        char chOneChar = szFileName[i];

        // Is there a path separator?
        // Note: Warcraft III paths may contain "mount points".
        // Example: "frFR-War3Local.mpq:Maps/FrozenThrone/Campaign/NightElfX06Interlude.w3x:war3map.j"
        if(chOneChar == '\\' || chOneChar == '/' || chOneChar == ':')
        {
            // Calculate hash of the file name up to the end of the node name
            FileNameHash = CalcNormNameHash(PathBuffer, i);

            // If the entry is not there yet, create new one
            if((pFolderNode = Find(FileNameHash)) == NULL)
            {
                // Insert new entry to the tree
                pFolderNode = InsertNew();
                if(pFolderNode == NULL)
                    return false;

                // Populate the file entry
                pFolderNode->FileNameHash = FileNameHash;
                pFolderNode->Parent = Parent;
                pFolderNode->Flags |= (chOneChar == ':') ? (CFN_FLAG_FOLDER | CFN_FLAG_MOUNT_POINT) : CFN_FLAG_FOLDER;
                FolderNodes++;

                // Set the node sub name to the node
                SetNodePlainName(pFolderNode, szNodeBegin, szFileName + i);

                // Insert the entry to the name map
                InsertToHashTable(pFolderNode);
            }

            // Move the parent to the current node
            Parent = (DWORD)NodeTable.IndexOf(pFolderNode);

            // Move the begin of the node after the separator
            szNodeBegin = szFileName + i + 1;
        }

        // Copy the next character, even if it was slash/backslash before
        PathBuffer.AppendChar(AsciiToUpperTable_BkSlash[chOneChar]);
    }

    // If anything left, this is gonna be our node name
    if(szNodeBegin < szFileName + i)
    {
        // We need to reset the file node pointer, as the file node table might have changed
        pFileNode = (PCASC_FILE_NODE)NodeTable.ItemAt(nFileNode);
        
        // Write the plain file name to the node
        SetNodePlainName(pFileNode, szNodeBegin, szFileName + i);
        pFileNode->Parent = Parent;

        // Also insert the node to the hash table so CascOpenFile can find it
        if(pFileNode->FileNameHash == 0)
        {
            pFileNode->FileNameHash = CalcNormNameHash(PathBuffer, i);
            InsertToHashTable(pFileNode);
        }
    }
    return true;
}
/*
bool CASC_FILE_TREE::SetNodeFileName(PCASC_FILE_NODE pFileNode, const char * szFileName)
{
    ULONGLONG FileNameHash = 0;
    PCASC_FILE_NODE pFolderNode = NULL;
    LPCSTR szNodeBegin = szFileName;
    char szPathBuffer[MAX_PATH+1];
    size_t nFileNode = NodeTable.IndexOf(pFileNode);
    size_t i;
    DWORD Parent = 0;

    // Sanity checks
    assert(szFileName != NULL && szFileName[0] != 0);

    // Traverse the entire path. For each subfolder, we insert an appropriate fake entry
    for(i = 0; szFileName[i] != 0; i++)
    {
        char chOneChar = szFileName[i];

        // Is there a path separator?
        // Note: Warcraft III paths may contain "mount points".
        // Example: "frFR-War3Local.mpq:Maps/FrozenThrone/Campaign/NightElfX06Interlude.w3x:war3map.j"
        if(chOneChar == '\\' || chOneChar == '/' || chOneChar == ':')
        {
            // Calculate hash of the file name up to the end of the node name
            FileNameHash = CalcNormNameHash(szPathBuffer, i);

            // If the entry is not there yet, create new one
            if((pFolderNode = Find(FileNameHash)) == NULL)
            {
                // Insert new entry to the tree
                pFolderNode = InsertNew();
                if(pFolderNode == NULL)
                    return false;

                // Populate the file entry
                pFolderNode->FileNameHash = FileNameHash;
                pFolderNode->Parent = Parent;
                pFolderNode->Flags |= (chOneChar == ':') ? (CFN_FLAG_FOLDER | CFN_FLAG_MOUNT_POINT) : CFN_FLAG_FOLDER;
                FolderNodes++;

                // Set the node sub name to the node
                SetNodePlainName(pFolderNode, szNodeBegin, szFileName + i);

                // Insert the entry to the name map
                InsertToHashTable(pFolderNode);
            }

            // Move the parent to the current node
            Parent = (DWORD)NodeTable.IndexOf(pFolderNode);

            // Move the begin of the node after the separator
            szNodeBegin = szFileName + i + 1;
        }

        // Copy the next character, even if it was slash/backslash before
        szPathBuffer[i] = AsciiToUpperTable_BkSlash[chOneChar];
    }

    // If anything left, this is gonna be our node name
    if(szNodeBegin < szFileName + i)
    {
        // We need to reset the file node pointer, as the file node table might have changed
        pFileNode = (PCASC_FILE_NODE)NodeTable.ItemAt(nFileNode);
        
        // Write the plain file name to the node
        SetNodePlainName(pFileNode, szNodeBegin, szFileName + i);
        pFileNode->Parent = Parent;

        // Also insert the node to the hash table so CascOpenFile can find it
        if(pFileNode->FileNameHash == 0)
        {
            pFileNode->FileNameHash = CalcNormNameHash(szPathBuffer, i);
            InsertToHashTable(pFileNode);
        }
    }
    return true;
}
*/
size_t CASC_FILE_TREE::GetMaxFileIndex()
{
    if(FileDataIds.IsInitialized())
    {
        return FileDataIds.ItemCount();
    }
    else
    {
        return NodeTable.ItemCount();
    }
}

size_t CASC_FILE_TREE::GetCount()
{
    return NodeTable.ItemCount();
}

size_t CASC_FILE_TREE::IndexOf(PCASC_FILE_NODE pFileNode)
{
    return NodeTable.IndexOf(pFileNode);
}

void CASC_FILE_TREE::GetExtras(PCASC_FILE_NODE pFileNode, PDWORD PtrFileDataId, PDWORD PtrLocaleFlags, PDWORD PtrContentFlags)
{
    DWORD FileDataId = CASC_INVALID_ID;
    DWORD LocaleFlags = CASC_INVALID_ID;
    DWORD ContentFlags = CASC_INVALID_ID;

    // Retrieve the data ID, if supported
    if(PtrFileDataId != NULL)
    {
        if(FileDataIdOffset != 0)
            FileDataId = GET_NODE_INT32(pFileNode, FileDataIdOffset);
        PtrFileDataId[0] = FileDataId;
    }

    // Retrieve the locale ID, if supported
    if(PtrLocaleFlags != NULL)
    {
        if(LocaleFlagsOffset != 0)
            LocaleFlags = GET_NODE_INT32(pFileNode, LocaleFlagsOffset);
        PtrLocaleFlags[0] = LocaleFlags;
    }

    if(PtrContentFlags != NULL)
    {
        if(ContentFlagsOffset != 0)
            ContentFlags = GET_NODE_INT32(pFileNode, ContentFlagsOffset);
        PtrContentFlags[0] = ContentFlags;
    }
}

void CASC_FILE_TREE::SetExtras(PCASC_FILE_NODE pFileNode, DWORD FileDataId, DWORD LocaleFlags, DWORD ContentFlags)
{
    // Set the file data ID, if supported
    if(FileDataIdOffset != 0)
    {
        SET_NODE_INT32(pFileNode, FileDataIdOffset, FileDataId);
    }

    // Set the locale ID, if supported
    if(LocaleFlagsOffset != 0)
    {
        SET_NODE_INT32(pFileNode, LocaleFlagsOffset, LocaleFlags);
    }

    // Set the locale ID, if supported
    if(ContentFlagsOffset != 0)
    {
        SET_NODE_INT32(pFileNode, ContentFlagsOffset, ContentFlags);
    }
}
