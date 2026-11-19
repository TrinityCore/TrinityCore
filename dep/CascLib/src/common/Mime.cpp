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

static const char * GetContentLengthValue(const char * response, const char * end)
{
    const char * ptr;

    if((ptr = strstr(response, "Content-Length: ")) != NULL && ptr < end)
        return ptr;
    if((ptr = strstr(response, "content-length: ")) != NULL && ptr < end)
        return ptr;
    return NULL;
}

bool CASC_MIME_RESPONSE::ParseResponse(const char * response, size_t length, bool final)
{
    const char * ptr;

    // Only parse the data if there was an increment
    if(length > response_length)
    {
        // Set the header offset
        header_offset = 0;

        // Check for the complete header
        if(header_length == CASC_INVALID_SIZE_T)
        {
            if((ptr = strstr(response, "\r\n\r\n")) != NULL)
            {
                header_length = (ptr - response) - header_offset;
                content_offset = header_length + 4;
            }
        }

        // Determine the presence of the HTTP field
        if(http_presence == FieldPresenceUnknown && header_length != CASC_INVALID_SIZE_T)
        {
            const char * http_ptr = (response + header_offset);

            if(!_strnicmp(http_ptr, "HTTP/1.1 ", 9))
            {
                http_presence = FieldPresencePresent;
                http_code = DecodeValueInt32(response + 9, response + 13);
            }
            else
            {
                http_presence = FieldPresenceNotPresent;
            }
        }

        // Determine the presence of content length
        if(clength_presence == FieldPresenceUnknown && header_length != CASC_INVALID_SIZE_T)
        {
            const char * clength_ptr = GetContentLengthValue(response + header_offset, response + header_length);

            if(clength_ptr != NULL)
            {
                content_length = DecodeValueInt32(clength_ptr + 16, response + header_length);
                clength_presence = FieldPresencePresent;
            }
            else
            {
                clength_presence = FieldPresenceNotPresent;
            }
        }

        // Update the length
        response_length = length;
    }

    // If this is a final response parsing we calculate the content length
    if(content_length == CASC_INVALID_SIZE_T && final == true && (content_offset + 2) < length)
    {
        // The field must end with \r\n (0D 0A)
        const char * end_ptr = (response + length - 2);

        // Is the MIME data terminated with "\r\n"?
        if(end_ptr[0] == 0x0D && end_ptr[1] == 0x0A)
        {
            content_length = (response + length - 2) - (response + content_offset);
        }
    }

    // Determine if we are finished or not
    if(header_length != CASC_INVALID_SIZE_T && content_length != CASC_INVALID_SIZE_T)
        return (length >= content_offset + content_length);
    return false;
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
}

DWORD CASC_MIME_ELEMENT::GiveAway(CASC_BLOB & target)
{
    if(data.pbData && data.cbData)
    {
        target.MoveFrom(data);
        return ERROR_SUCCESS;
    }
    return ERROR_HANDLE_EOF;
}

DWORD CASC_MIME_ELEMENT::LoadSingle(char * data_ptr, size_t data_length)
{
    return data.SetData(data_ptr, data_length);
}

DWORD CASC_MIME_ELEMENT::Load(char * mime_data_begin, char * mime_data_end, const char * boundary_ptr)
{
    CASC_MIME_ENCODING Encoding = MimeEncodingTextPlain;
    CASC_MIME_BLOB mime_data(mime_data_begin, mime_data_end);
    size_t length_begin;
    size_t length_end;
    char * mime_line;
    char boundary_begin[MAX_LENGTH_BOUNDARY + 2];
    char boundary_end[MAX_LENGTH_BOUNDARY + 4];
    DWORD dwErrCode = ERROR_SUCCESS;
    bool mime_version = false;

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
            CASC_BLOB data_buffer;

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

            // Decode the data
            switch(Encoding)
            {
                case MimeEncodingTextPlain:
                    dwErrCode = DecodeTextPlain(content.ptr, content.end, data);
                    break;

                case MimeEncodingQuotedPrintable:
                    dwErrCode = DecodeQuotedPrintable(content.ptr, content.end, data);
                    break;

                case MimeEncodingBase64:
                    dwErrCode = DecodeBase64(content.ptr, content.end, data);
                    break;

                default:
                    dwErrCode = ERROR_NOT_SUPPORTED;
                    assert(false);
                    break;
            }
        }
    }
    else
    {
        dwErrCode = ERROR_NOT_SUPPORTED;
    }

    // Return the result of the decoding
    return dwErrCode;
}

#ifdef CASCLIB_DEBUG
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

        for(size_t i = 0; (i < data.cbData && i < _countof(data_printable) - 1); i++)
        {
            if(0x20 <= data.pbData[i] && data.pbData[i] <= 0x7F)
                data_printable[i] = data.pbData[i];
            else
                data_printable[i] = '.';
        }

        printf("Data item (%u bytes): \"%s\"\n", (int)data.cbData, data_printable);
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

DWORD CASC_MIME_ELEMENT::DecodeTextPlain(char * content_begin, char * content_end, CASC_BLOB & output)
{
    return output.SetData(content_begin, (content_end - content_begin));
}


DWORD CASC_MIME_ELEMENT::DecodeQuotedPrintable(char * content_begin, char * content_end, CASC_BLOB & output)
{
    DWORD dwErrCode;

    // Sanity checks
    assert(content_begin && content_end);
    assert(content_end > content_begin);

    // Allocate space for the output
    if((dwErrCode = output.SetSize(content_end - content_begin)) == ERROR_SUCCESS)
    {
        unsigned char * output_ptr = output.pbData;
        char * content_ptr;

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
                dwErrCode = BinaryFromString(content_ptr + 1, 2, output_ptr);
                if(dwErrCode != ERROR_SUCCESS)
                    return dwErrCode;

                content_ptr += 3;
                output_ptr++;
                continue;
            }
            else
            {
                *output_ptr++ = (unsigned char)(*content_ptr++);
            }
        }

        // Set the real length
        output.cbData = (size_t)(output_ptr - output.pbData);
    }
    return dwErrCode;
}

DWORD CASC_MIME_ELEMENT::DecodeBase64(char * content_begin, char * content_end, CASC_BLOB & output)
{
    DWORD dwErrCode;
    DWORD BitBuffer = 0;
    DWORD BitCount = 0;
    BYTE OneByte;

    if((dwErrCode = output.SetSize(content_end - content_begin)) == ERROR_SUCCESS)
    {
        unsigned char * output_ptr = output.pbData;

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
                *output_ptr++ = OneByte;
            }
        }

        // Set the decoded length
        output.cbData = (output_ptr - output.pbData);
    }
    return dwErrCode;
}

//-----------------------------------------------------------------------------
// The MIME class

CASC_MIME::CASC_MIME()
{}

CASC_MIME::~CASC_MIME()
{}

DWORD CASC_MIME::GiveAway(CASC_BLOB & target)
{
    CASC_MIME_ELEMENT * pElement;

    // 1) Give the data from the root
    if(root.GiveAway(target) == ERROR_SUCCESS)
        return ERROR_SUCCESS;

    // 2) If we have children, then give away from the first child
    if((pElement = root.GetChild()) != NULL)
        return pElement->GiveAway(target);

    return ERROR_CAN_NOT_COMPLETE;
}

DWORD CASC_MIME::Load(char * data, CASC_MIME_RESPONSE & MimeResponse)
{
    // Avoid parsing empty responses
    if(MimeResponse.response_length == 0)
        return ERROR_BAD_FORMAT;
    if(MimeResponse.header_offset == CASC_INVALID_SIZE_T || MimeResponse.header_length == CASC_INVALID_SIZE_T)
        return ERROR_BAD_FORMAT;
    if(MimeResponse.content_offset == CASC_INVALID_SIZE_T || MimeResponse.content_offset == 0)
        return ERROR_BAD_FORMAT;
    if(MimeResponse.content_length == CASC_INVALID_SIZE_T || MimeResponse.content_length == 0)
        return ERROR_BAD_FORMAT;

    // Avoid parsing responses where the data are incomplete
    // Example: http://level3.blizzard.com/tpr/wow/data/c6/50/c650c203d52b9e5bdcf1d4b2b8b5bd16.index
    if(MimeResponse.response_length < (MimeResponse.content_offset + MimeResponse.content_length))
        return ERROR_BAD_FORMAT;

    // Debug: dump the MIME data to file
#ifdef CASCLIB_DEBUG
    //CascDumpData("E:\\mime_raw_data.txt", data, MimeResponse.response_length);
#endif

    // Special handling of HTTP responses
    if(MimeResponse.http_presence == FieldPresencePresent)
    {
        // Avoid parsing of failed HTTP requests
        if(MimeResponse.http_code != 200)
            return ERROR_FILE_NOT_FOUND;

        // Directly setup the root item
        return root.LoadSingle(data + MimeResponse.content_offset, MimeResponse.content_length);
    }

    // Load the root element
    memset(&root, 0, sizeof(CASC_MIME_ELEMENT));
    return root.Load(data, data + MimeResponse.response_length);
}

#ifdef CASCLIB_DEBUG
void CASC_MIME::Print()
{
    root.Print(0, 0);
}
#endif

