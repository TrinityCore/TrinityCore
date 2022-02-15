/*****************************************************************************/
/* Mime.cpp                               Copyright (c) Ladislav Zezula 2021 */
/*---------------------------------------------------------------------------*/
/* Mime functions for CascLib                                                */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 21.01.21  1.00  Lad  Created                                              */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "../CascLib.h"
#include "../CascCommon.h"

//-----------------------------------------------------------------------------
// Local variables

#define BASE64_INVALID_CHAR 0xFF
#define BASE64_WHITESPACE_CHAR 0xFE

static const char * CascBase64Table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static unsigned char CascBase64ToBits[0x80] = {0};

//-----------------------------------------------------------------------------
// CASC_MIME_HTTP implementation

static size_t DecodeValueInt32(const char * string, const char * string_end)
{
    size_t result = 0;

    while(string < string_end && isdigit(string[0]))
    {
        result = (result * 10) + (string[0] - '0');
        string++;
    }

    return result;
}

bool CASC_MIME_HTTP::IsDataComplete(const char * response, size_t response_length)
{
    const char * content_length_ptr;
    const char * content_begin_ptr;

    // Do not parse the HTTP response multiple times
    if(response_valid == 0 && response_length > 8)
    {
        // Check the begin of the response
        if(!strncmp(response, "HTTP/1.1", 8))
        {
            // Check if there's begin of the content
            if((content_begin_ptr = strstr(response, "\r\n\r\n")) != NULL)
            {
                // HTTP responses contain "Content-Length: %u\n\r"
                if((content_length_ptr = strstr(response, "Content-Length: ")) != NULL)
                {
                    // The content length info muse be before the actual content
                    if(content_length_ptr < content_begin_ptr)
                    {
                        // Fill the HTTP info cache
                        response_valid = 0x48545450;    // 'HTTP'
                        content_offset = (content_begin_ptr + 4) - response;
                        content_length = DecodeValueInt32(content_length_ptr + 16, content_begin_ptr);
                        total_length = content_offset + content_length;
                    }
                }
            }
        }
    }

    // If we know the expected total length, we can tell whether it's complete or not
    return ((response_valid != 0) && (total_length == response_length));
}

//-----------------------------------------------------------------------------
// The MIME blob class

CASC_MIME_BLOB::CASC_MIME_BLOB(char * mime_ptr, char * mime_end)
{
    ptr = mime_ptr;
    end = mime_end;
}

CASC_MIME_BLOB::~CASC_MIME_BLOB()
{
    ptr = end = NULL;
}

char * CASC_MIME_BLOB::GetNextLine()
{
    char * mime_line = ptr;

    while(ptr < end)
    {
        // Every line, even the last one, must be terminated with 0D 0A
        if(ptr[0] == 0x0D && ptr[1] == 0x0A)
        {
            // If space or tabulator follows, then this is continuation of the line
            if(ptr[2] == 0x09 || ptr[2] == 0x20)
            {
                ptr = ptr + 2;
                continue;
            }

            // Terminate the line and return its begin
            ptr[0] = 0;
            ptr[1] = 0;
            ptr = ptr + 2;
            return mime_line;
        }

        // Move to tne next character
        ptr++;
    }

    // No EOL terminated line found, break the search
    return NULL;
}

//-----------------------------------------------------------------------------
// The MIME element class

CASC_MIME_ELEMENT::CASC_MIME_ELEMENT()
{
    memset(this, 0, sizeof(CASC_MIME_ELEMENT));
}

CASC_MIME_ELEMENT::~CASC_MIME_ELEMENT()
{
    // Free the children and next elements
    if(folder.pChild != NULL)
        delete folder.pChild;
    folder.pChild = NULL;

    if(folder.pNext != NULL)
        delete folder.pNext;
    folder.pNext = NULL;

    // Free the data
    if(data.begin != NULL)
        CASC_FREE(data.begin);
    data.begin = NULL;
}

unsigned char * CASC_MIME_ELEMENT::GiveAway(size_t * ptr_data_length)
{
    unsigned char * give_away_data = data.begin;
    size_t give_away_length = data.length;

    // Clear the data (DO NOT FREE)
    data.begin = NULL;
    data.length = 0;

    // Copy the data to local buffer
    if(ptr_data_length != NULL)
        ptr_data_length[0] = give_away_length;
    return give_away_data;
}

DWORD CASC_MIME_ELEMENT::Load(char * mime_data_begin, char * mime_data_end, const char * boundary_ptr)
{
    CASC_MIME_ENCODING Encoding = MimeEncodingTextPlain;
    CASC_MIME_BLOB mime_data(mime_data_begin, mime_data_end);
    CASC_MIME_HTTP HttpInfo;
    size_t length_begin;
    size_t length_end;
    char * mime_line;
    char boundary_begin[MAX_LENGTH_BOUNDARY + 2];
    char boundary_end[MAX_LENGTH_BOUNDARY + 4];
    DWORD dwErrCode = ERROR_SUCCESS;
    bool mime_version = false;

    // Diversion for HTTP: No need to parse the entire headers and stuff.
    // Just give the data right away
    if(HttpInfo.IsDataComplete(mime_data_begin, (mime_data_end - mime_data_begin)))
    {
        if((data.begin = CASC_ALLOC<BYTE>(HttpInfo.content_length)) == NULL)
            return ERROR_NOT_ENOUGH_MEMORY;
        
        memcpy(data.begin, mime_data_begin + HttpInfo.content_offset, HttpInfo.content_length);
        data.length = HttpInfo.content_length;
        return ERROR_SUCCESS;
    }

    // Reset the boundary
    boundary[0] = 0;

    // Parse line-by-line untile we find the end of data
    while((mime_line = mime_data.GetNextLine()) != NULL)
    {
        // If the line is empty, this means that it's the end of the MIME header and begin of the MIME data
        if(mime_line[0] == 0)
        {
            mime_data.ptr = mime_line + 2;
            break;
        }

        // Root nodes are required to have MIME version
        if(boundary_ptr == NULL && mime_version == false)
        {
            if(!strcmp(mime_line, "MIME-Version: 1.0"))
            {
                mime_version = true;
                continue;
            }
            if(!strcmp(mime_line, "HTTP/1.1 200 OK"))
            {
                mime_version = true;
                continue;
            }
        }

        // Get the encoding
        if(!strncmp(mime_line, "Content-Transfer-Encoding: ", 27))
        {
            ExtractEncoding(mime_line + 27, Encoding);
            continue;
        }

        // Is there content type?
        if(!strncmp(mime_line, "Content-Type: ", 14))
        {
            ExtractBoundary(mime_line + 14);
            continue;
        }
    }

    // Keep going only if we have MIME version
    if(boundary_ptr != NULL || mime_version == true)
    {
        // If we have boundary, it means that the element begin
        // and end is marked by the boundary
        if(boundary[0])
        {
            CASC_MIME_ELEMENT * pLast = NULL;
            CASC_MIME_ELEMENT * pChild;
            CASC_MIME_BLOB sub_mime(mime_data.ptr, NULL);

            // Construct the begin of the boundary. Don't include newline there,
            // as it must also match end of the boundary
            length_begin = CascStrPrintf(boundary_begin, _countof(boundary_begin), "--%s", boundary);
            dwErrCode = ERROR_SUCCESS;

            // The current line must point to the begin of the boundary
            // Find the end of the boundary
            if(memcmp(sub_mime.ptr, boundary_begin, length_begin))
                return ERROR_BAD_FORMAT;
            sub_mime.ptr += length_begin;

            // Find the end of the boundary
            length_end = CascStrPrintf(boundary_end, _countof(boundary_end), "--%s--\r\n", boundary);
            sub_mime.end = strstr(sub_mime.ptr, boundary_end);
            if(sub_mime.end == NULL)
                return ERROR_BAD_FORMAT;

            // This is the end of the MIME section. Cut it to blocks
            // and put each into the separate CASC_MIME_ELEMENT
            while(sub_mime.ptr < sub_mime.end)
            {
                char * sub_mime_next;

                // At this point, there must be newline in the current data pointer
                if(sub_mime.ptr[0] != 0x0D || sub_mime.ptr[1] != 0x0A)
                    return ERROR_BAD_FORMAT;
                sub_mime.ptr += 2;

                // Find the next MIME element. This must succeed, as the last element also matches the first element
                sub_mime_next = strstr(sub_mime.ptr, boundary_begin);
                if(sub_mime_next == NULL)
                    return ERROR_BAD_FORMAT;

                // Allocate the element
                pChild = AllocateAndLoadElement(sub_mime.ptr, sub_mime_next - 2, boundary_begin);
                if(pChild == NULL)
                {
                    dwErrCode = GetCascError();
                    break;
                }

                // Link the element
                if(folder.pChild == NULL)
                    folder.pChild = pChild;
                if(pLast != NULL)
                    pLast->folder.pNext = pChild;
                pLast = pChild;

                // Move to the next MIME element. Note that if we are at the ending boundary,
                // this moves past the end, but it's OK, because the while loop will catch that
                sub_mime.ptr = sub_mime_next + length_begin;
            }
        }
        else
        {
            CASC_MIME_BLOB content(mime_data.ptr, NULL);
            unsigned char * data_buffer;
            size_t data_length = 0;
            size_t raw_length;

            // If we have boundary pointer, we need to cut the data up to the boundary end.
            // Otherwise, we decode the data to the end of the document
            if(boundary_ptr != NULL)
            {
                // Find the end of the current data by the boundary. It is 2 characters before the next boundary 
                content.end = strstr(content.ptr, boundary_ptr);
                if(content.end == NULL)
                    return ERROR_BAD_FORMAT;
                if((content.ptr + 2) >= content.end)
                    return ERROR_BAD_FORMAT;
                content.end -= 2;
            }
            else
            {
                content.end = mime_data_end - 2;
                if(content.end[0] != 0x0D || content.end[1] != 0x0A)
                    return ERROR_BAD_FORMAT;
                if((content.ptr + 2) >= content.end)
                    return ERROR_BAD_FORMAT;
            }

            // Allocate buffer for decoded data.
            // Make it the same size like source data plus zero at the end
            raw_length = (content.end - content.ptr);
            data_buffer = CASC_ALLOC<unsigned char>(raw_length);
            if(data_buffer != NULL)
            {
                // Decode the data
                switch(Encoding)
                {
                    case MimeEncodingTextPlain:
                        dwErrCode = DecodeTextPlain(content.ptr, content.end, data_buffer, &data_length);
                        break;

                    case MimeEncodingQuotedPrintable:
                        dwErrCode = DecodeQuotedPrintable(content.ptr, content.end, data_buffer, &data_length);
                        break;

                    case MimeEncodingBase64:
                        dwErrCode = DecodeBase64(content.ptr, content.end, data_buffer, &data_length);
                        break;
                    
                    default:;
                        // to remove warning
                }

                // If failed, free the buffer back
                if(dwErrCode != ERROR_SUCCESS)
                {
                    CASC_FREE(data_buffer);
                    data_buffer = NULL;
                    data_length = 0;
                }
            }
            else
            {
                dwErrCode = ERROR_NOT_ENOUGH_MEMORY;
            }

            // Put the data there, even if they are invalid
            data.begin = data_buffer;
            data.length = data_length;
        }
    }
    else
    {
        dwErrCode = ERROR_NOT_SUPPORTED;
    }

    // Return the result of the decoding
    return dwErrCode;
}

#ifdef _DEBUG
#define MAX_LEVEL 0x10
void CASC_MIME_ELEMENT::Print(size_t nLevel, size_t nIndex)
{
    char Prefix[(MAX_LEVEL * 4) + 0x20 + 1] = {0};
    size_t nSpaces;

    // Fill-in the spaces
    nSpaces = (nLevel < MAX_LEVEL) ? (nLevel * 4) : (MAX_LEVEL * 4);
    memset(Prefix, ' ', nSpaces);

    // Print the spaces and index
    nSpaces = printf("%s* [%u]: ", Prefix, (int)nIndex);
    memset(Prefix, ' ', nSpaces);

    // Is this a folder item?
    if(folder.pChild != NULL)
    {
        printf("Folder item (boundary: %s)\n", boundary);
        folder.pChild->Print(nLevel + 1, 0);
    }
    else
    {
        char data_printable[0x20] = {0};

        for(size_t i = 0; (i < data.length && i < _countof(data_printable) - 1); i++)
        {
            if(0x20 <= data.begin[i] && data.begin[i] <= 0x7F)
                data_printable[i] = data.begin[i];
            else
                data_printable[i] = '.';
        }

        printf("Data item (%u bytes): \"%s\"\n", (int)data.length, data_printable);
    }

    // Do we have a next element?
    if(folder.pNext != NULL)
    {
        folder.pNext->Print(nLevel, nIndex + 1);
    }
}
#endif

CASC_MIME_ELEMENT * CASC_MIME_ELEMENT::AllocateAndLoadElement(char * a_mime_data, char * a_mime_data_end, const char * boundary_begin)
{
    CASC_MIME_ELEMENT * pElement;
    DWORD dwErrCode = ERROR_NOT_ENOUGH_MEMORY;

    // Allocate the element
    if((pElement = new CASC_MIME_ELEMENT()) != NULL)
    {
        // Load the element
        dwErrCode = pElement->Load(a_mime_data, a_mime_data_end, boundary_begin);
        if(dwErrCode == ERROR_SUCCESS)
            return pElement;

        // Free the element on failure
        delete pElement;
    }

    SetCascError(dwErrCode);
    return NULL;
}

bool CASC_MIME_ELEMENT::ExtractEncoding(const char * line, CASC_MIME_ENCODING & Encoding)
{
    if(!_stricmp(line, "base64"))
    {
        Encoding = MimeEncodingBase64;
        return true;
    }

    if(!_stricmp(line, "quoted-printable"))
    {
        Encoding = MimeEncodingQuotedPrintable;
        return true;
    }

    // Unknown encoding
    return false;
}


bool CASC_MIME_ELEMENT::ExtractBoundary(const char * line)
{
    const char * begin;
    const char * end;

    // Find the begin of the boundary
    if((begin = strstr(line, "boundary=\"")) != NULL)
    {
        // Set begin of the boundary
        begin = begin + 10;
        
        // Is there also end?
        if((end = strchr(begin, '\"')) != NULL)
        {
            CascStrCopy(boundary, _countof(boundary), begin, end - begin);
            return true;
        }
    }

    return false;
}

DWORD CASC_MIME_ELEMENT::DecodeTextPlain(char * content_begin, char * content_end, unsigned char * data_buffer, size_t * ptr_length)
{
    size_t data_length = (size_t)(content_end - content_begin);

    // Sanity checks
    assert(content_begin && content_end);
    assert(content_end > content_begin);

    // Plain copy
    memcpy(data_buffer, content_begin, data_length);

    // Give the result
    if(ptr_length != NULL)
        ptr_length[0] = data_length;
    return ERROR_SUCCESS;
}


DWORD CASC_MIME_ELEMENT::DecodeQuotedPrintable(char * content_begin, char * content_end, unsigned char * data_buffer, size_t * ptr_length)
{
    unsigned char * save_data_buffer = data_buffer;
    char * content_ptr;
    DWORD dwErrCode;

    // Sanity checks
    assert(content_begin && content_end);
    assert(content_end > content_begin);

    // Decode the data
    for(content_ptr = content_begin; content_ptr < content_end; )
    {
        // If the data begins with '=', there is either newline or 2-char hexa number
        if(content_ptr[0] == '=')
        {
            // Is there a newline after the equal sign?
            if(content_ptr[1] == 0x0D && content_ptr[2] == 0x0A)
            {
                content_ptr += 3;
                continue;
            }

            // Is there hexa number after the equal sign?
            dwErrCode = BinaryFromString(content_ptr + 1, 2, data_buffer);
            if(dwErrCode != ERROR_SUCCESS)
                return dwErrCode;

            content_ptr += 3;
            data_buffer++;
            continue;
        }
        else
        {
            *data_buffer++ = (unsigned char)(*content_ptr++);
        }
    }

    if(ptr_length != NULL)
        ptr_length[0] = (size_t)(data_buffer - save_data_buffer);
    return ERROR_SUCCESS;
}

DWORD CASC_MIME_ELEMENT::DecodeBase64(char * content_begin, char * content_end, unsigned char * data_buffer, size_t * ptr_length)
{
    unsigned char * save_data_buffer = data_buffer;
    DWORD BitBuffer = 0;
    DWORD BitCount = 0;
    BYTE OneByte;

    // One time preparation of the conversion table
    if(CascBase64ToBits[0] == 0)
    {
        // Fill the entire table with 0xFF to mark invalid characters
        memset(CascBase64ToBits, BASE64_INVALID_CHAR, sizeof(CascBase64ToBits));

        // Set all whitespace characters
        for(BYTE i = 1; i <= 0x20; i++)
            CascBase64ToBits[i] = BASE64_WHITESPACE_CHAR;

        // Set all valid characters
        for(BYTE i = 0; CascBase64Table[i] != 0; i++)
        {
            OneByte = CascBase64Table[i];
            CascBase64ToBits[OneByte] = i;
        }
    }

    // Do the decoding
    while(content_begin < content_end && content_begin[0] != '=')
    {
        // Check for end of string
        if(content_begin[0] > sizeof(CascBase64ToBits))
            return ERROR_BAD_FORMAT;
        if((OneByte = CascBase64ToBits[*content_begin++]) == BASE64_INVALID_CHAR)
            return ERROR_BAD_FORMAT;
        if(OneByte == BASE64_WHITESPACE_CHAR)
            continue;

        // Put the 6 bits into the bit buffer
        BitBuffer = (BitBuffer << 6) | OneByte;
        BitCount += 6;

        // Flush all values
        while(BitCount >= 8)
        {
            // Decrement the bit count in the bit buffer
            BitCount -= 8;

            // The byte is the upper 8 bits of the bit buffer
            OneByte = (BYTE)(BitBuffer >> BitCount);
            BitBuffer = BitBuffer % (1 << BitCount);

            // Put the byte value. The buffer can not overflow,
            // because it is guaranteed to be equal to the length of the base64 string
            *data_buffer++ = OneByte;
        }
    }

    // Return the decoded length
    if(ptr_length != NULL)
        ptr_length[0] = (data_buffer - save_data_buffer);
    return ERROR_SUCCESS;
}

//-----------------------------------------------------------------------------
// The MIME class

CASC_MIME::CASC_MIME()
{}

CASC_MIME::~CASC_MIME()
{}

unsigned char * CASC_MIME::GiveAway(size_t * ptr_data_length)
{
    CASC_MIME_ELEMENT * pElement = &root;
    unsigned char * data;

    // 1) Give the data from the root
    if((data = root.GiveAway(ptr_data_length)) != NULL)
        return data;

    // 2) If we have children, then give away from the first child
    pElement = root.GetChild();
    if(pElement && (data = pElement->GiveAway(ptr_data_length)) != NULL)
        return data;

    // Return NULL
    if(ptr_data_length != NULL)
        ptr_data_length[0] = 0;
    return NULL;
}

DWORD CASC_MIME::Load(char * data, size_t length)
{
    // Clear the root element
    memset(&root, 0, sizeof(CASC_MIME_ELEMENT));

    //FILE * fp = fopen("E:\\html_response.txt", "wb");
    //if(fp != NULL)
    //{
    //    fwrite(data, 1, length, fp);
    //    fclose(fp);
    //}

    // Load the root element
    return root.Load(data, data + length);
}

DWORD CASC_MIME::Load(LPCTSTR szFileName)
{
    char * szFileData;
    DWORD cbFileData = 0;
    DWORD dwErrCode = ERROR_SUCCESS;

    // Note that LoadFileToMemory allocated one byte more and puts zero at the end
    // Thus, we can treat it as zero-terminated string
    szFileData = (char *)LoadFileToMemory(szFileName, &cbFileData);
    if(szFileData != NULL)
    {
        dwErrCode = Load(szFileData, cbFileData);
        CASC_FREE(szFileData);
    }
    else
    {
        dwErrCode = GetCascError();
    }

    return dwErrCode;
}

#ifdef _DEBUG
void CASC_MIME::Print()
{
    root.Print(0, 0);
}
#endif

