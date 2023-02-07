/*****************************************************************************/
/* Mime.h                                 Copyright (c) Ladislav Zezula 2021 */
/*---------------------------------------------------------------------------*/
/* MIME parsing functions for CascLib                                        */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 21.01.21  1.00  Lad  Created                                              */
/*****************************************************************************/

#ifndef __MIME_H__
#define __MIME_H__

//-----------------------------------------------------------------------------
// MIME constants

#define MAX_LENGTH_BOUNDARY 128

// Flags returned by CASC_MIME_HTTP::GetHttpReplyFlags()
#define HTTP_HEADER_COMPLETE    0x01            // HTML header is complete
#define HTTP_DATA_COMPLETE      0x02            // HTML data is complete

enum CASC_MIME_ENCODING
{
    MimeEncodingTextPlain,
    MimeEncodingBase64,
    MimeEncodingQuotedPrintable,
    MimeEncodingMax
};

enum CASC_PRESENCE
{
    FieldPresenceUnknown,
    FieldPresencePresent,
    FieldPresenceNotPresent
};

//-----------------------------------------------------------------------------
// Structure for caching parsed HTTP response information

struct CASC_MIME_RESPONSE
{
    CASC_MIME_RESPONSE()
    {
        header_offset = header_length = CASC_INVALID_SIZE_T;
        content_offset = content_length = CASC_INVALID_SIZE_T;
        http_code = CASC_INVALID_SIZE_T;
        clength_presence = http_presence = FieldPresenceUnknown;
        response_length = 0;
    }

    bool ParseResponse(const char * response, size_t length, bool final = false);

    size_t response_length;             // Previous length of the response
    size_t header_offset;               // Offset of the response header, usually 0
    size_t header_length;               // Length of the header, if known
    size_t content_offset;              // Offset of the content
    size_t content_length;              // Length of the content, if known
    size_t http_code;                   // HTTP code, if present
    CASC_PRESENCE clength_presence;     // State of the "content length" field
    CASC_PRESENCE http_presence;        // Presence of the "HTTP" field
};

//-----------------------------------------------------------------------------
// MIME blob class

struct CASC_MIME_BLOB
{
    CASC_MIME_BLOB(char * mime_ptr, char * mime_end);
    ~CASC_MIME_BLOB();

    char * GetNextLine();

    char * ptr;
    char * end;
};

//-----------------------------------------------------------------------------
// MIME class

class CASC_MIME_ELEMENT
{
    public:

    CASC_MIME_ELEMENT();
    ~CASC_MIME_ELEMENT();

    DWORD GiveAway(CASC_BLOB & target);

    DWORD LoadSingle(char * data, size_t data_length);
    DWORD Load(char * mime_data_begin, char * mime_data_end, const char * boundary_ptr = NULL);

    CASC_MIME_ELEMENT * GetChild()  { return folder.pChild; }

#ifdef _DEBUG
    void Print(size_t nLevel, size_t nIndex);
#endif

    protected:

    CASC_MIME_ELEMENT * AllocateAndLoadElement(char * a_mime_data, char * a_mime_data_end, const char * boundary_begin);
    bool   ExtractEncoding(const char * line, CASC_MIME_ENCODING & Encoding);
    bool   ExtractBoundary(const char * line);

    DWORD DecodeTextPlain(char * content_begin, char * content_end, CASC_BLOB & output);
    DWORD DecodeQuotedPrintable(char * content_begin, char * content_end, CASC_BLOB & output);
    DWORD DecodeBase64(char * content_begin, char * content_end, CASC_BLOB & output);

    struct
    {
        CASC_MIME_ELEMENT * pChild;     // Pointer to the first child
        CASC_MIME_ELEMENT * pNext;      // Pointer to the next-in-folder element
    } folder;

    CASC_BLOB data;
    char boundary[MAX_LENGTH_BOUNDARY];
};

class CASC_MIME
{
    public:

    CASC_MIME();
    ~CASC_MIME();

    DWORD GiveAway(CASC_BLOB & target);

    DWORD Load(char * data, CASC_MIME_RESPONSE & MimeResponse);

#ifdef _DEBUG
    void Print();
#endif

    protected:

    CASC_MIME_ELEMENT root;
};

#endif // __MIME_H__
