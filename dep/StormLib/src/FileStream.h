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
// Function prototypes

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

typedef bool (*STREAM_GETPOS)(
    struct TFileStream * pStream,       // Pointer to an open stream
    ULONGLONG & ByteOffset              // Pointer to store current file position
    );

typedef bool (*STREAM_GETSIZE)(
    struct TFileStream * pStream,       // Pointer to an open stream
    ULONGLONG & FileSize                // Receives the file size, in bytes
    );

typedef bool (*STREAM_SETSIZE)(
    struct TFileStream * pStream,       // Pointer to an open stream
    ULONGLONG FileSize                  // New size for the file, in bytes
    );

typedef bool (*STREAM_GETTIME)(
    struct TFileStream * pStream,
    ULONGLONG * pFT
    );

typedef bool (*STREAM_SWITCH)(
    struct TFileStream * pStream,
    struct TFileStream * pNewStream
    );

typedef bool (*STREAM_GETBMP)(
    TFileStream * pStream,
    TFileBitmap * pBitmap,
    DWORD Length,
    LPDWORD LengthNeeded
    );

typedef void (*STREAM_CLOSE)(
    struct TFileStream * pStream
    );

//-----------------------------------------------------------------------------
// Local structures - part file structure

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

//-----------------------------------------------------------------------------
// Local structures

union TBaseData
{
    struct
    {
        ULONGLONG FileSize;                 // Size of the file
        ULONGLONG FilePos;                  // Current file position
        ULONGLONG FileTime;                 // Date/time of last modification of the file
        HANDLE hFile;                       // File handle
    } File;

    struct
    {
        ULONGLONG FileSize;                 // Mapped file size
        ULONGLONG FilePos;                  // Current stream position
        ULONGLONG FileTime;                 // Date/time of last modification of the file
        LPBYTE pbFile;                      // Pointer to mapped view
    } Map;

    struct
    {
        ULONGLONG FileSize;                 // Size of the internet file
        ULONGLONG FilePos;                  // Current position in the file
        ULONGLONG FileTime;                 // Date/time of last modification of the file
        HANDLE hInternet;                   // Internet handle
        HANDLE hConnect;                    // Connection to the internet server
    } Http;
};

//-----------------------------------------------------------------------------
// Structure for linear stream

struct TFileStream
{
    // Stream provider functions
    STREAM_READ    StreamRead;              // Pointer to stream read function for this archive. Do not use directly.
    STREAM_WRITE   StreamWrite;             // Pointer to stream write function for this archive. Do not use directly.
    STREAM_GETPOS  StreamGetPos;            // Pointer to function that returns current file position
    STREAM_GETSIZE StreamGetSize;           // Pointer to function returning file size
    STREAM_SETSIZE StreamSetSize;           // Pointer to function changing file size
    STREAM_GETTIME StreamGetTime;           // Pointer to function retrieving the file time
    STREAM_GETBMP  StreamGetBmp;            // Pointer to function that retrieves the file bitmap
    STREAM_SWITCH  StreamSwitch;            // Pointer to function changing the stream to another file
    STREAM_CLOSE   StreamClose;             // Pointer to function closing the stream

    // Stream provider data members
    TCHAR szFileName[MAX_PATH];             // File name
    DWORD dwFlags;                          // Stream flags

    // Base provider functions
    STREAM_READ    BaseRead;
    STREAM_WRITE   BaseWrite;
    STREAM_GETPOS  BaseGetPos;              // Pointer to function that returns current file position
    STREAM_GETSIZE BaseGetSize;             // Pointer to function returning file size
    STREAM_SETSIZE BaseSetSize;             // Pointer to function changing file size
    STREAM_GETTIME BaseGetTime;             // Pointer to function retrieving the file time
    STREAM_CLOSE   BaseClose;               // Pointer to function closing the stream

    // Base provider data members
    TBaseData Base;                         // Base provider data

    // Followed by stream provider data, with variable length
};

//-----------------------------------------------------------------------------
// Structure for linear stream

struct TLinearStream : public TFileStream
{
    TFileBitmap * pBitmap;                  // Pointer to the stream bitmap
};

//-----------------------------------------------------------------------------
// Structure for partial stream

struct TPartialStream : public TFileStream
{
    ULONGLONG VirtualSize;                  // Virtual size of the file
    ULONGLONG VirtualPos;                   // Virtual position in the file
    DWORD     BlockCount;                   // Number of file blocks. Used by partial file stream
    DWORD     BlockSize;                    // Size of one block. Used by partial file stream

    PPART_FILE_MAP_ENTRY PartMap;           // File map, variable length
};

//-----------------------------------------------------------------------------
// Structure for encrypted stream

#define MPQE_CHUNK_SIZE 0x40                // Size of one chunk to be decrypted

struct TEncryptedStream : public TFileStream
{
    BYTE Key[MPQE_CHUNK_SIZE];              // File key
};

#endif // __FILESTREAM_H__
