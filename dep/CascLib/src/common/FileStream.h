/*****************************************************************************/
/* FileStream.h                           Copyright (c) Ladislav Zezula 2012 */
/*---------------------------------------------------------------------------*/
/* Description: Definitions for FileStream object                            */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 14.04.12  1.00  Lad  The first version of FileStream.h                    */
/*****************************************************************************/

#ifndef __FILESTREAM_H__
#define __FILESTREAM_H__

//-----------------------------------------------------------------------------
// Flags for file stream

#define BASE_PROVIDER_FILE          0x00000000  // Base data source is a file
#define BASE_PROVIDER_MAP           0x00000001  // Base data source is memory-mapped file
#define BASE_PROVIDER_HTTP          0x00000002  // Base data source is a file on web server via the HTTP protocol
#define BASE_PROVIDER_RIBBIT        0x00000003  // Base data source is a file on web server via the Ribbit protocol
#define BASE_PROVIDER_MASK          0x0000000F  // Mask for base provider value

#define STREAM_PROVIDER_FLAT        0x00000000  // Stream is linear with no offset mapping
#define STREAM_PROVIDER_PARTIAL     0x00000010  // Stream is partial file (.part)
#define STREAM_PROVIDER_ENCRYPTED   0x00000020  // Stream is an encrypted archive
#define STREAM_PROVIDER_BLOCK4      0x00000030  // 0x4000 per block, text MD5 after each block, max 0x2000 blocks per file
#define STREAM_PROVIDER_MASK        0x000000F0  // Mask for stream provider value

#define STREAM_FLAG_READ_ONLY       0x00000100  // Stream is read only
#define STREAM_FLAG_WRITE_SHARE     0x00000200  // Allow write sharing when open for write
#define STREAM_FLAG_USE_BITMAP      0x00000400  // If the file has a file bitmap, load it and use it
#define STREAM_FLAG_FILL_MISSING    0x00000800  // If less than expected was read from the file, fill the missing part with zeros
#define STREAM_OPTIONS_MASK         0x0000FF00  // Mask for stream options

#define STREAM_PROVIDERS_MASK       0x000000FF  // Mask to get stream providers
#define STREAM_FLAGS_MASK           0x0000FFFF  // Mask for all stream flags (providers+options)

//-----------------------------------------------------------------------------
// Function prototypes

typedef void (*STREAM_INIT)(
    struct TFileStream * pStream        // Pointer to an unopened stream
);

typedef bool (*STREAM_CREATE)(
    struct TFileStream * pStream        // Pointer to an unopened stream
    );

typedef bool (*STREAM_OPEN)(
    struct TFileStream * pStream,       // Pointer to an unopened stream
    LPCTSTR szFileName,           // Pointer to file name to be open
    DWORD dwStreamFlags                 // Stream flags
    );

typedef bool (*STREAM_READ)(
    struct TFileStream * pStream,       // Pointer to an open stream
    ULONGLONG * pByteOffset,            // Pointer to file byte offset. If NULL, it reads from the current position
    void * pvBuffer,                    // Pointer to data to be read
    DWORD dwBytesToRead                 // Number of bytes to read from the file
    );

typedef bool (*STREAM_WRITE)(
    struct TFileStream * pStream,       // Pointer to an open stream
    ULONGLONG * pByteOffset,            // Pointer to file byte offset. If NULL, it writes to the current position
    const void * pvBuffer,              // Pointer to data to be written
    DWORD dwBytesToWrite                // Number of bytes to read from the file
    );

typedef bool (*STREAM_RESIZE)(
    struct TFileStream * pStream,       // Pointer to an open stream
    ULONGLONG FileSize                  // New size for the file, in bytes
    );

typedef bool (*STREAM_GETSIZE)(
    struct TFileStream * pStream,       // Pointer to an open stream
    ULONGLONG * pFileSize               // Receives the file size, in bytes
    );

typedef bool (*STREAM_GETPOS)(
    struct TFileStream * pStream,       // Pointer to an open stream
    ULONGLONG * pByteOffset             // Pointer to store current file position
    );

typedef void (*STREAM_CLOSE)(
    struct TFileStream * pStream        // Pointer to an open stream
    );

typedef bool (*BLOCK_READ)(
    struct TFileStream * pStream,       // Pointer to a block-oriented stream
    ULONGLONG StartOffset,              // Byte offset of start of the block array
    ULONGLONG EndOffset,                // End offset (either end of the block or end of the file)
    LPBYTE BlockBuffer,                 // Pointer to block-aligned buffer
    DWORD BytesNeeded,                  // Number of bytes that are really needed
    bool bAvailable                     // true if the block is available
    );

typedef bool (*BLOCK_CHECK)(
    struct TFileStream * pStream,       // Pointer to a block-oriented stream
    ULONGLONG BlockOffset               // Offset of the file to check
    );

typedef void (*BLOCK_SAVEMAP)(
    struct TFileStream * pStream        // Pointer to a block-oriented stream
    );

typedef void (WINAPI * STREAM_DOWNLOAD_CALLBACK)(
    void * pvUserData,
    ULONGLONG ByteOffset,
    DWORD dwTotalBytes
    );

//-----------------------------------------------------------------------------
// Local structures - partial file structure and bitmap footer

#define ID_FILE_BITMAP_FOOTER   0x33767470  // Signature of the file bitmap footer ('ptv3')
#define DEFAULT_BLOCK_SIZE      0x00004000  // Default size of the stream block
#define DEFAULT_BUILD_NUMBER         10958  // Build number for newly created partial MPQs

typedef struct _PART_FILE_HEADER
{
    DWORD PartialVersion;                   // Always set to 2
    char  GameBuildNumber[0x20];            // Minimum build number of the game that can use this MPQ
    DWORD Flags;                            // Flags (details unknown)
    DWORD FileSizeLo;                       // Low 32 bits of the contained file size
    DWORD FileSizeHi;                       // High 32 bits of the contained file size
    DWORD BlockSize;                        // Size of one file block, in bytes

} PART_FILE_HEADER, *PPART_FILE_HEADER;

// Structure describing the block-to-file map entry
typedef struct _PART_FILE_MAP_ENTRY
{
    DWORD Flags;                            // 3 = the block is present in the file
    DWORD BlockOffsLo;                      // Low 32 bits of the block position in the file
    DWORD BlockOffsHi;                      // High 32 bits of the block position in the file
    DWORD LargeValueLo;                     // 64-bit value, meaning is unknown
    DWORD LargeValueHi;

} PART_FILE_MAP_ENTRY, *PPART_FILE_MAP_ENTRY;

typedef struct _FILE_BITMAP_FOOTER
{
    DWORD Signature;                      // 'ptv3' (ID_FILE_BITMAP_FOOTER)
    DWORD Version;                        // Unknown, seems to always have value of 3 (version?)
    DWORD BuildNumber;                    // Game build number for that MPQ
    DWORD MapOffsetLo;                    // Low 32-bits of the offset of the bit map
    DWORD MapOffsetHi;                    // High 32-bits of the offset of the bit map
    DWORD BlockSize;                      // Size of one block (usually 0x4000 bytes)

} FILE_BITMAP_FOOTER, *PFILE_BITMAP_FOOTER;

//-----------------------------------------------------------------------------
// Structure for file stream

union TBaseProviderData
{
    struct
    {
        ULONGLONG FileSize;                 // Size of the file
        ULONGLONG FilePos;                  // Current file position
        ULONGLONG FileTime;                 // Last write time
        HANDLE hFile;                       // File handle
    } File;

    struct
    {
        ULONGLONG FileSize;                 // Size of the file
        ULONGLONG FilePos;                  // Current file position
        ULONGLONG FileTime;                 // Last write time
        LPBYTE pbFile;                      // Pointer to mapped view
    } Map;

    struct
    {
        class CASC_SOCKET * pSocket;        // An open socket
        unsigned char * fileData;           // Raw response converted to file data
        char * hostName;                    // Name of the remote host
        char * fileName;                    // Name of the remote resource
        size_t fileDataLength;              // Length of the file data, in bytes
        size_t fileDataPos;                 // Current position in the data
    } Socket;
};

struct TFileStream
{
    // Stream provider functions
    STREAM_READ    StreamRead;              // Pointer to stream read function for this archive. Do not use directly.
    STREAM_WRITE   StreamWrite;             // Pointer to stream write function for this archive. Do not use directly.
    STREAM_RESIZE  StreamResize;            // Pointer to function changing file size
    STREAM_GETSIZE StreamGetSize;           // Pointer to function returning file size
    STREAM_GETPOS  StreamGetPos;            // Pointer to function that returns current file position
    STREAM_CLOSE   StreamClose;             // Pointer to function closing the stream

    // Block-oriented functions
    BLOCK_READ     BlockRead;               // Pointer to function reading one or more blocks
    BLOCK_CHECK    BlockCheck;              // Pointer to function checking whether the block is present

    // Base provider functions
    STREAM_CREATE  BaseCreate;              // Pointer to base create function
    STREAM_OPEN    BaseOpen;                // Pointer to base open function
    STREAM_READ    BaseRead;                // Read from the stream
    STREAM_WRITE   BaseWrite;               // Write to the stream
    STREAM_RESIZE  BaseResize;              // Pointer to function changing file size
    STREAM_GETSIZE BaseGetSize;             // Pointer to function returning file size
    STREAM_GETPOS  BaseGetPos;              // Pointer to function that returns current file position
    STREAM_CLOSE   BaseClose;               // Pointer to function closing the stream

    // Base provider data (file size, file position)
    TBaseProviderData Base;                 // Stream information, like size or current position
    CASC_LOCK Lock;                         // For multi-threaded synchronization

    // Stream provider data
    TFileStream * pMaster;                  // Master stream (e.g. MPQ on a web server)
    LPTSTR szFileName;                      // File name (self-relative pointer)

    ULONGLONG StreamSize;                   // Stream size (can be less than file size)
    ULONGLONG StreamPos;                    // Stream position
    DWORD BuildNumber;                      // Game build number
    DWORD dwFlags;                          // Stream flags

    // Followed by stream provider data, with variable length
};

//-----------------------------------------------------------------------------
// Structures for block-oriented stream

struct TBlockStream : public TFileStream
{
    STREAM_DOWNLOAD_CALLBACK pfnCallback;   // Callback for downloading
    void * FileBitmap;                      // Array of bits for file blocks
    void * UserData;                        // User data to be passed to the download callback
    DWORD BitmapSize;                       // Size of the file bitmap (in bytes)
    DWORD BlockSize;                        // Size of one block, in bytes
    DWORD BlockCount;                       // Number of data blocks in the file
    DWORD IsComplete;                       // If nonzero, no blocks are missing
    DWORD IsModified;                       // nonzero if the bitmap has been modified
};        

//-----------------------------------------------------------------------------
// Structure for encrypted stream

#define ENCRYPTED_CHUNK_SIZE 0x40           // Size of one chunk to be decrypted

struct TEncryptedStream : public TBlockStream
{
    BYTE Key[ENCRYPTED_CHUNK_SIZE];         // File key
};

//-----------------------------------------------------------------------------
// Public functions for file stream

TFileStream * FileStream_CreateFile(LPCTSTR szFileName, DWORD dwStreamFlags);
TFileStream * FileStream_OpenFile(LPCTSTR szFileName, DWORD dwStreamFlags = 0);
LPCTSTR FileStream_GetFileName(TFileStream * pStream);
size_t FileStream_Prefix(LPCTSTR szFileName, DWORD * pdwProvider);

bool FileStream_SetCallback(TFileStream * pStream, STREAM_DOWNLOAD_CALLBACK pfnCallback, void * pvUserData);

bool FileStream_Read(TFileStream * pStream, ULONGLONG * pByteOffset, void * pvBuffer, DWORD dwBytesToRead);
bool FileStream_Write(TFileStream * pStream, ULONGLONG * pByteOffset, const void * pvBuffer, DWORD dwBytesToWrite);
bool FileStream_SetSize(TFileStream * pStream, ULONGLONG NewFileSize);
bool FileStream_GetSize(TFileStream * pStream, ULONGLONG * pFileSize);
bool FileStream_GetPos(TFileStream * pStream, ULONGLONG * pByteOffset);
bool FileStream_GetTime(TFileStream * pStream, ULONGLONG * pFT);
bool FileStream_GetFlags(TFileStream * pStream, PDWORD pdwStreamFlags);
bool FileStream_Replace(TFileStream * pStream, TFileStream * pNewStream);
void FileStream_Close(TFileStream * pStream);


#endif // __FILESTREAM_H__
