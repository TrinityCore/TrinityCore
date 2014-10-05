/*****************************************************************************/
/* SFileVerify.cpp                        Copyright (c) Ladislav Zezula 2010 */
/*---------------------------------------------------------------------------*/
/* MPQ files and MPQ archives verification.                                  */
/*                                                                           */
/* The MPQ signature verification has been written by Jean-Francois Roy      */
/* <bahamut@macstorm.org> and Justin Olbrantz (Quantam).                     */
/* The MPQ public keys have been created by MPQKit, using OpenSSL library.   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 04.05.10  1.00  Lad  The first version of SFileVerify.cpp                 */
/*****************************************************************************/

#define __STORMLIB_SELF__
#include "StormLib.h"
#include "StormCommon.h"

//-----------------------------------------------------------------------------
// Local defines

#define SIGNATURE_TYPE_NONE             0
#define SIGNATURE_TYPE_WEAK             1
#define SIGNATURE_TYPE_STRONG           2

#define MPQ_DIGEST_UNIT_SIZE      0x10000

typedef struct _MPQ_SIGNATURE_INFO
{
    ULONGLONG BeginMpqData;                 // File offset where the hashing starts
    ULONGLONG BeginExclude;                 // Begin of the excluded area (used for (signature) file)
    ULONGLONG EndExclude;                   // End of the excluded area (used for (signature) file)
    ULONGLONG EndMpqData;                   // File offset where the hashing ends
    ULONGLONG EndOfFile;                    // Size of the entire file
    BYTE  Signature[MPQ_STRONG_SIGNATURE_SIZE + 0x10];
    DWORD cbSignatureSize;                  // Length of the signature
    int nSignatureType;                     // See SIGNATURE_TYPE_XXX

} MPQ_SIGNATURE_INFO, *PMPQ_SIGNATURE_INFO;

//-----------------------------------------------------------------------------
// Known Blizzard public keys
// Created by Jean-Francois Roy using OpenSSL

static const char * szBlizzardWeakPublicKey =
    "-----BEGIN PUBLIC KEY-----"
    "MFwwDQYJKoZIhvcNAQEBBQADSwAwSAJBAJJidwS/uILMBSO5DLGsBFknIXWWjQJe"
    "2kfdfEk3G/j66w4KkhZ1V61Rt4zLaMVCYpDun7FLwRjkMDSepO1q2DcCAwEAAQ=="
    "-----END PUBLIC KEY-----";

static const char * szBlizzardStrongPublicKey =
    "-----BEGIN PUBLIC KEY-----"
    "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAsQZ+ziT2h8h+J/iMQpgd"
    "tH1HaJzOBE3agjU4yMPcrixaPOZoA4t8bwfey7qczfWywocYo3pleytFF+IuD4HD"
    "Fl9OXN1SFyupSgMx1EGZlgbFAomnbq9MQJyMqQtMhRAjFgg4TndS7YNb+JMSAEKp"
    "kXNqY28n/EVBHD5TsMuVCL579gIenbr61dI92DDEdy790IzIG0VKWLh/KOTcTJfm"
    "Ds/7HQTkGouVW+WUsfekuqNQo7ND9DBnhLjLjptxeFE2AZqYcA1ao3S9LN3GL1tW"
    "lVXFIX9c7fWqaVTQlZ2oNsI/ARVApOK3grNgqvwH6YoVYVXjNJEo5sQJsPsdV/hk"
    "dwIDAQAB"
    "-----END PUBLIC KEY-----";

static const char * szWarcraft3MapPublicKey =
    "-----BEGIN PUBLIC KEY-----"
    "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA1BwklUUQ3UvjizOBRoF5"
    "yyOVc7KD+oGOQH5i6eUk1yfs0luCC70kNucNrfqhmviywVtahRse1JtXCPrx2bd3"
    "iN8Dx91fbkxjYIOGTsjYoHKTp0BbaFkJih776fcHgnFSb+7mJcDuJVvJOXxEH6w0"
    "1vo6VtujCqj1arqbyoal+xtAaczF3us5cOEp45sR1zAWTn1+7omN7VWV4QqJPaDS"
    "gBSESc0l1grO0i1VUSumayk7yBKIkb+LBvcG6WnYZHCi7VdLmaxER5m8oZfER66b"
    "heHoiSQIZf9PAY6Guw2DT5BTc54j/AaLQAKf2qcRSgQLVo5kQaddF3rCpsXoB/74"
    "6QIDAQAB"
    "-----END PUBLIC KEY-----";

static const char * szWowPatchPublicKey =
    "-----BEGIN PUBLIC KEY-----"
    "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAwOsMV0LagAWPEtEQM6b9"
    "6FHFkUyGbbyda2/Dfc9dyl21E9QvX+Yw7qKRMAKPzA2TlQQLZKvXpnKXF/YIK5xa"
    "5uwg9CEHCEAYolLG4xn0FUOE0E/0PuuytI0p0ICe6rk00PifZzTr8na2wI/l/GnQ"
    "bvnIVF1ck6cslATpQJ5JJVMXzoFlUABS19WESw4MXuJAS3AbMhxNWdEhVv7eO51c"
    "yGjRLy9QjogZODZTY0fSEksgBqQxNCoYVJYI/sF5K2flDsGqrIp0OdJ6teJlzg1Y"
    "UjYnb6bKjlidXoHEXI2TgA/mD6O3XFIt08I9s3crOCTgICq7cgX35qrZiIVWZdRv"
    "TwIDAQAB"
    "-----END PUBLIC KEY-----";

static const char * szWowSurveyPublicKey =
    "-----BEGIN PUBLIC KEY-----"
    "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAnIt1DR6nRyyKsy2qahHe"
    "MKLtacatn/KxieHcwH87wLBxKy+jZ0gycTmJ7SaTdBAEMDs/V5IPIXEtoqYnid2c"
    "63TmfGDU92oc3Ph1PWUZ2PWxBhT06HYxRdbrgHw9/I29pNPi/607x+lzPORITOgU"
    "BR6MR8au8HsQP4bn4vkJNgnSgojh48/XQOB/cAln7As1neP61NmVimoLR4Bwi3zt"
    "zfgrZaUpyeNCUrOYJmH09YIjbBySTtXOUidoPHjFrMsCWpr6xs8xbETbs7MJFL6a"
    "vcUfTT67qfIZ9RsuKfnXJTIrV0kwDSjjuNXiPTmWAehSsiHIsrUXX5RNcwsSjClr"
    "nQIDAQAB"
    "-----END PUBLIC KEY-----";

static const char * szStarcraft2MapPublicKey =
    "-----BEGIN PUBLIC KEY-----"
    "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAmk4GT8zb+ICC25a17KZB"
    "q/ygKGJ2VSO6IT5PGHJlm1KfnHBA4B6SH3xMlJ4c6eG2k7QevZv+FOhjsAHubyWq"
    "2VKqWbrIFKv2ILc2RfMn8J9EDVRxvcxh6slRrVL69D0w1tfVGjMiKq2Fym5yGoRT"
    "E7CRgDqbAbXP9LBsCNWHiJLwfxMGzHbk8pIl9oia5pvM7ofZamSHchxlpy6xa4GJ"
    "7xKN01YCNvklTL1D7uol3wkwcHc7vrF8QwuJizuA5bSg4poEGtH62BZOYi+UL/z0"
    "31YK+k9CbQyM0X0pJoJoYz1TK+Y5J7vBnXCZtfcTYQ/ZzN6UcxTa57dJaiOlCh9z"
    "nQIDAQAB"
    "-----END PUBLIC KEY-----";

//-----------------------------------------------------------------------------
// Local functions

static void memrev(unsigned char *buf, size_t count)
{
    unsigned char *r;

    for (r = buf + count - 1; buf < r; buf++, r--)
    {
        *buf ^= *r;
        *r   ^= *buf;
        *buf ^= *r;
    }
}

static bool is_valid_md5(void * pvMd5)
{
    LPDWORD Md5 = (LPDWORD)pvMd5;

    return (Md5[0] | Md5[1] | Md5[2] | Md5[3]) ? true : false;
}

static bool decode_base64_key(const char * szKeyBase64, rsa_key * key)
{
    unsigned char decoded_key[0x200];
    const char * szBase64Begin;
    const char * szBase64End;
    unsigned long decoded_length = sizeof(decoded_key);
    unsigned long length;

    // Find out the begin of the BASE64 data
    szBase64Begin = szKeyBase64 + strlen("-----BEGIN PUBLIC KEY-----");
    szBase64End   = szBase64Begin + strlen(szBase64Begin) - strlen("-----END PUBLIC KEY-----");
    if(szBase64End[0] != '-')
        return false;

    // decode the base64 string
    length = (unsigned long)(szBase64End - szBase64Begin);
    if(base64_decode((unsigned char *)szBase64Begin, length, decoded_key, &decoded_length) != CRYPT_OK)
        return false;

    // Create RSA key
    if(rsa_import(decoded_key, decoded_length, key) != CRYPT_OK)
        return false;

    return true;
}

static void GetPlainAnsiFileName(
    const TCHAR * szFileName,
    char * szPlainName)
{
    const TCHAR * szPlainNameT = GetPlainFileNameT(szFileName);

    // Convert the plain name to ANSI
    while(*szPlainNameT != 0)
        *szPlainName++ = (char)*szPlainNameT++;
    *szPlainName = 0;
}

// Calculate begin and end of the MPQ archive
static void CalculateArchiveRange(
    TMPQArchive * ha,
    PMPQ_SIGNATURE_INFO pSI)
{
    ULONGLONG TempPos = 0;
    char szMapHeader[0x200];

    // Get the MPQ begin
    pSI->BeginMpqData = ha->MpqPos;

    // Warcraft III maps are signed from the map header to the end
    if(FileStream_Read(ha->pStream, &TempPos, szMapHeader, sizeof(szMapHeader)))
    {
        // Is it a map header ?
        if(szMapHeader[0] == 'H' && szMapHeader[1] == 'M' && szMapHeader[2] == '3' && szMapHeader[3] == 'W')
        {
            // We will have to hash since the map header
            pSI->BeginMpqData = 0;
        }
    }

    // Get the MPQ data end. This is stored in our MPQ header,
    // and it's been already prepared by SFileOpenArchive,
    pSI->EndMpqData = ha->MpqPos + ha->pHeader->ArchiveSize64;

    // Get the size of the entire file
    FileStream_GetSize(ha->pStream, pSI->EndOfFile);
}

static bool QueryMpqSignatureInfo(
    TMPQArchive * ha,
    PMPQ_SIGNATURE_INFO pSI)
{
    ULONGLONG ExtraBytes;
    TMPQFile * hf;
    HANDLE hFile;
    DWORD dwFileSize;

    // Calculate the range of the MPQ
    CalculateArchiveRange(ha, pSI);

    // If there is "(signature)" file in the MPQ, it has a weak signature
    if(SFileOpenFileEx((HANDLE)ha, SIGNATURE_NAME, SFILE_OPEN_FROM_MPQ, &hFile))
    {
        // Get the content of the signature
        SFileReadFile(hFile, pSI->Signature, sizeof(pSI->Signature), &pSI->cbSignatureSize);

        // Verify the size of the signature
        hf = (TMPQFile *)hFile;

        // We have to exclude the signature file from the digest
        pSI->BeginExclude = ha->MpqPos + hf->pFileEntry->ByteOffset;
        pSI->EndExclude = pSI->BeginExclude + hf->pFileEntry->dwCmpSize;
        dwFileSize = hf->dwDataSize;

        // Close the file
        SFileCloseFile(hFile);
        pSI->nSignatureType = SIGNATURE_TYPE_WEAK;
        return (dwFileSize == (MPQ_WEAK_SIGNATURE_SIZE + 8)) ? true : false;
    }

    // If there is extra bytes beyond the end of the archive,
    // it's the strong signature
    ExtraBytes = pSI->EndOfFile - pSI->EndMpqData;
    if(ExtraBytes >= (MPQ_STRONG_SIGNATURE_SIZE + 4))
    {
        // Read the strong signature
        if(!FileStream_Read(ha->pStream, &pSI->EndMpqData, pSI->Signature, (MPQ_STRONG_SIGNATURE_SIZE + 4)))
            return false;

        // Check the signature header "NGIS"
        if(pSI->Signature[0] != 'N' || pSI->Signature[1] != 'G' || pSI->Signature[2] != 'I' || pSI->Signature[3] != 'S')
            return false;

        pSI->nSignatureType = SIGNATURE_TYPE_STRONG;
        return true;
    }

    // Succeeded, but no known signature found
    return true;
}

static bool CalculateMpqHashMd5(
    TMPQArchive * ha,
    PMPQ_SIGNATURE_INFO pSI,
    LPBYTE pMd5Digest)
{
    hash_state md5_state;
    ULONGLONG BeginBuffer;
    ULONGLONG EndBuffer;
    LPBYTE pbDigestBuffer = NULL;

    // Allocate buffer for creating the MPQ digest.
    pbDigestBuffer = STORM_ALLOC(BYTE, MPQ_DIGEST_UNIT_SIZE);
    if(pbDigestBuffer == NULL)
        return false;

    // Initialize the MD5 hash state
    md5_init(&md5_state);

    // Set the byte offset of begin of the data
    BeginBuffer = pSI->BeginMpqData;

    // Create the digest
    for(;;)
    {
        ULONGLONG BytesRemaining;
        LPBYTE pbSigBegin = NULL;
        LPBYTE pbSigEnd = NULL;
        DWORD dwToRead = MPQ_DIGEST_UNIT_SIZE;

        // Check the number of bytes remaining
        BytesRemaining = pSI->EndMpqData - BeginBuffer;
        if(BytesRemaining < MPQ_DIGEST_UNIT_SIZE)
            dwToRead = (DWORD)BytesRemaining;
        if(dwToRead == 0)
            break;

        // Read the next chunk 
        if(!FileStream_Read(ha->pStream, &BeginBuffer, pbDigestBuffer, dwToRead))
        {
            STORM_FREE(pbDigestBuffer);
            return false;
        }

        // Move the current byte offset
        EndBuffer = BeginBuffer + dwToRead;

        // Check if the signature is within the loaded digest
        if(BeginBuffer <= pSI->BeginExclude && pSI->BeginExclude < EndBuffer)
            pbSigBegin = pbDigestBuffer + (size_t)(pSI->BeginExclude - BeginBuffer);
        if(BeginBuffer <= pSI->EndExclude && pSI->EndExclude < EndBuffer)
            pbSigEnd = pbDigestBuffer + (size_t)(pSI->EndExclude - BeginBuffer);

        // Zero the part that belongs to the signature
        if(pbSigBegin != NULL || pbSigEnd != NULL)
        {
            if(pbSigBegin == NULL)
                pbSigBegin = pbDigestBuffer;
            if(pbSigEnd == NULL)
                pbSigEnd = pbDigestBuffer + dwToRead;

            memset(pbSigBegin, 0, (pbSigEnd - pbSigBegin));
        }

        // Pass the buffer to the hashing function
        md5_process(&md5_state, pbDigestBuffer, dwToRead);

        // Move pointers
        BeginBuffer += dwToRead;
    }

    // Finalize the MD5 hash
    md5_done(&md5_state, pMd5Digest);
    STORM_FREE(pbDigestBuffer);
    return true;
}

static void AddTailToSha1(
    hash_state * psha1_state,
    const char * szTail)
{
    unsigned char szUpperCase[0x200];
    unsigned long nLength = 0;

    // Convert the tail to uppercase
    // Note that we don't need to terminate the string with zero
    while(*szTail != 0)
    {
        szUpperCase[nLength++] = (unsigned char)toupper(*szTail++);
    }

    // Append the tail to the SHA1
    sha1_process(psha1_state, szUpperCase, nLength);
}

static bool CalculateMpqHashSha1(
    TMPQArchive * ha,
    PMPQ_SIGNATURE_INFO pSI,
    unsigned char * sha1_tail0,
    unsigned char * sha1_tail1,
    unsigned char * sha1_tail2)
{
    ULONGLONG BeginBuffer;
    hash_state sha1_state_temp;
    hash_state sha1_state;
    LPBYTE pbDigestBuffer = NULL;
    char szPlainName[MAX_PATH];

    // Allocate buffer for creating the MPQ digest.
    pbDigestBuffer = STORM_ALLOC(BYTE, MPQ_DIGEST_UNIT_SIZE);
    if(pbDigestBuffer == NULL)
        return false;

    // Initialize SHA1 state structure
    sha1_init(&sha1_state);

    // Calculate begin of data to be hashed
    BeginBuffer = pSI->BeginMpqData;

    // Create the digest
    for(;;)
    {
        ULONGLONG BytesRemaining;
        DWORD dwToRead = MPQ_DIGEST_UNIT_SIZE;

        // Check the number of bytes remaining
        BytesRemaining = pSI->EndMpqData - BeginBuffer;
        if(BytesRemaining < MPQ_DIGEST_UNIT_SIZE)
            dwToRead = (DWORD)BytesRemaining;
        if(dwToRead == 0)
            break;

        // Read the next chunk 
        if(!FileStream_Read(ha->pStream, &BeginBuffer, pbDigestBuffer, dwToRead))
        {
            STORM_FREE(pbDigestBuffer);
            return false;
        }

        // Pass the buffer to the hashing function
        sha1_process(&sha1_state, pbDigestBuffer, dwToRead);

        // Move pointers
        BeginBuffer += dwToRead;
    }

    // Add all three known tails and generate three hashes
    memcpy(&sha1_state_temp, &sha1_state, sizeof(hash_state));
    sha1_done(&sha1_state_temp, sha1_tail0);

    memcpy(&sha1_state_temp, &sha1_state, sizeof(hash_state));
    GetPlainAnsiFileName(FileStream_GetFileName(ha->pStream), szPlainName);
    AddTailToSha1(&sha1_state_temp, szPlainName);
    sha1_done(&sha1_state_temp, sha1_tail1);

    memcpy(&sha1_state_temp, &sha1_state, sizeof(hash_state));
    AddTailToSha1(&sha1_state_temp, "ARCHIVE");
    sha1_done(&sha1_state_temp, sha1_tail2);

    // Finalize the MD5 hash
    STORM_FREE(pbDigestBuffer);
    return true;
}

static int VerifyRawMpqData(
    TMPQArchive * ha,
    ULONGLONG ByteOffset,
    DWORD dwDataSize)
{
    ULONGLONG DataOffset = ha->MpqPos + ByteOffset;
    LPBYTE pbDataChunk;
    LPBYTE pbMD5Array1;                 // Calculated MD5 array
    LPBYTE pbMD5Array2;                 // MD5 array loaded from the MPQ
    DWORD dwBytesInChunk;
    DWORD dwChunkCount;
    DWORD dwChunkSize = ha->pHeader->dwRawChunkSize;
    DWORD dwMD5Size;
    int nError = ERROR_SUCCESS;

    // Don't verify zero-sized blocks
    if(dwDataSize == 0)
        return ERROR_SUCCESS;

    // Get the number of data chunks to calculate MD5
    assert(dwChunkSize != 0);
    dwChunkCount = ((dwDataSize - 1) / dwChunkSize) + 1;
    dwMD5Size = dwChunkCount * MD5_DIGEST_SIZE;

    // Allocate space for data chunk and for the MD5 array
    pbDataChunk = STORM_ALLOC(BYTE, dwChunkSize);
    if(pbDataChunk == NULL)
        return ERROR_NOT_ENOUGH_MEMORY;

    // Allocate space for MD5 array
    pbMD5Array1 = STORM_ALLOC(BYTE, dwMD5Size);
    pbMD5Array2 = STORM_ALLOC(BYTE, dwMD5Size);
    if(pbMD5Array1 == NULL || pbMD5Array2 == NULL)
        nError = ERROR_NOT_ENOUGH_MEMORY;

    // Calculate MD5 of each data chunk
    if(nError == ERROR_SUCCESS)
    {
        LPBYTE pbMD5 = pbMD5Array1;

        for(DWORD i = 0; i < dwChunkCount; i++)
        {
            // Get the number of bytes in the chunk
            dwBytesInChunk = STORMLIB_MIN(dwChunkSize, dwDataSize);

            // Read the data chunk
            if(!FileStream_Read(ha->pStream, &DataOffset, pbDataChunk, dwBytesInChunk))
            {
                nError = ERROR_FILE_CORRUPT;
                break;
            }

            // Calculate MD5
            CalculateDataBlockHash(pbDataChunk, dwBytesInChunk, pbMD5);

            // Move pointers and offsets
            DataOffset += dwBytesInChunk;
            dwDataSize -= dwBytesInChunk;
            pbMD5 += MD5_DIGEST_SIZE;
        }
    }

    // Read the MD5 array
    if(nError == ERROR_SUCCESS)
    {
        // Read the array of MD5
        if(!FileStream_Read(ha->pStream, &DataOffset, pbMD5Array2, dwMD5Size))
            nError = GetLastError();
    }

    // Compare the array of MD5
    if(nError == ERROR_SUCCESS)
    {
        // Compare the MD5
        if(memcmp(pbMD5Array1, pbMD5Array2, dwMD5Size))
            nError = ERROR_FILE_CORRUPT;
    }

    // Free memory and return result
    if(pbMD5Array2 != NULL)
        STORM_FREE(pbMD5Array2);
    if(pbMD5Array1 != NULL)
        STORM_FREE(pbMD5Array1);
    if(pbDataChunk != NULL)
        STORM_FREE(pbDataChunk);
    return nError;
}

static DWORD VerifyWeakSignature(
    TMPQArchive * ha,
    PMPQ_SIGNATURE_INFO pSI)
{
    BYTE RevSignature[MPQ_WEAK_SIGNATURE_SIZE];
    BYTE Md5Digest[MD5_DIGEST_SIZE];
    rsa_key key;
    int hash_idx = find_hash("md5");
    int result = 0;

    // Calculate hash of the entire archive, skipping the (signature) file
    if(!CalculateMpqHashMd5(ha, pSI, Md5Digest))
        return ERROR_VERIFY_FAILED;

    // Import the Blizzard key in OpenSSL format
    if(!decode_base64_key(szBlizzardWeakPublicKey, &key))
        return ERROR_VERIFY_FAILED;

    // Verify the signature
    memcpy(RevSignature, &pSI->Signature[8], MPQ_WEAK_SIGNATURE_SIZE);
    memrev(RevSignature, MPQ_WEAK_SIGNATURE_SIZE);
    rsa_verify_hash_ex(RevSignature, MPQ_WEAK_SIGNATURE_SIZE, Md5Digest, sizeof(Md5Digest), LTC_LTC_PKCS_1_V1_5, hash_idx, 0, &result, &key);
    rsa_free(&key);

    // Return the result
    return result ? ERROR_WEAK_SIGNATURE_OK : ERROR_WEAK_SIGNATURE_ERROR;
}

static DWORD VerifyStrongSignatureWithKey(
    unsigned char * reversed_signature,
    unsigned char * padded_digest,
    const char * szPublicKey)
{
    rsa_key key;
    int result = 0;

    // Import the Blizzard key in OpenSSL format
    if(!decode_base64_key(szPublicKey, &key))
    {
        assert(false);
        return ERROR_VERIFY_FAILED;
    }

    // Verify the signature
    if(rsa_verify_simple(reversed_signature, MPQ_STRONG_SIGNATURE_SIZE, padded_digest, MPQ_STRONG_SIGNATURE_SIZE, &result, &key) != CRYPT_OK)
        return ERROR_VERIFY_FAILED;
    
    // Free the key and return result
    rsa_free(&key);
    return result ? ERROR_STRONG_SIGNATURE_OK : ERROR_STRONG_SIGNATURE_ERROR;
}

static DWORD VerifyStrongSignature(
    TMPQArchive * ha,
    PMPQ_SIGNATURE_INFO pSI)
{
    unsigned char reversed_signature[MPQ_STRONG_SIGNATURE_SIZE];
    unsigned char Sha1Digest_tail0[SHA1_DIGEST_SIZE];
    unsigned char Sha1Digest_tail1[SHA1_DIGEST_SIZE];
    unsigned char Sha1Digest_tail2[SHA1_DIGEST_SIZE];
    unsigned char padded_digest[MPQ_STRONG_SIGNATURE_SIZE];
    DWORD dwResult;
    size_t digest_offset;

    // Calculate SHA1 hash of the archive
    if(!CalculateMpqHashSha1(ha, pSI, Sha1Digest_tail0, Sha1Digest_tail1, Sha1Digest_tail2))
        return ERROR_VERIFY_FAILED;

    // Prepare the signature for decryption
    memcpy(reversed_signature, &pSI->Signature[4], MPQ_STRONG_SIGNATURE_SIZE);
    memrev(reversed_signature, MPQ_STRONG_SIGNATURE_SIZE);

    // Prepare the padded digest for comparison
    digest_offset = sizeof(padded_digest) - SHA1_DIGEST_SIZE;
    memset(padded_digest, 0xbb, digest_offset);
    padded_digest[0] = 0x0b;

    // Try Blizzard Strong public key with no SHA1 tail
    memcpy(padded_digest + digest_offset, Sha1Digest_tail0, SHA1_DIGEST_SIZE);
    memrev(padded_digest + digest_offset, SHA1_DIGEST_SIZE);
    dwResult = VerifyStrongSignatureWithKey(reversed_signature, padded_digest, szBlizzardStrongPublicKey);
    if(dwResult == ERROR_STRONG_SIGNATURE_OK)
        return dwResult;

    // Try War 3 map public key with plain file name as SHA1 tail
    memcpy(padded_digest + digest_offset, Sha1Digest_tail1, SHA1_DIGEST_SIZE);
    memrev(padded_digest + digest_offset, SHA1_DIGEST_SIZE);
    dwResult = VerifyStrongSignatureWithKey(reversed_signature, padded_digest, szWarcraft3MapPublicKey);
    if(dwResult == ERROR_STRONG_SIGNATURE_OK)
        return dwResult;

    // Try WoW-TBC public key with "ARCHIVE" as SHA1 tail
    memcpy(padded_digest + digest_offset, Sha1Digest_tail2, SHA1_DIGEST_SIZE);
    memrev(padded_digest + digest_offset, SHA1_DIGEST_SIZE);
    dwResult = VerifyStrongSignatureWithKey(reversed_signature, padded_digest, szWowPatchPublicKey);
    if(dwResult == ERROR_STRONG_SIGNATURE_OK)
        return dwResult;

    // Try Survey public key with no SHA1 tail
    memcpy(padded_digest + digest_offset, Sha1Digest_tail0, SHA1_DIGEST_SIZE);
    memrev(padded_digest + digest_offset, SHA1_DIGEST_SIZE);
    dwResult = VerifyStrongSignatureWithKey(reversed_signature, padded_digest, szWowSurveyPublicKey);
    if(dwResult == ERROR_STRONG_SIGNATURE_OK)
        return dwResult;

    // Try Starcraft II public key with no SHA1 tail
    memcpy(padded_digest + digest_offset, Sha1Digest_tail0, SHA1_DIGEST_SIZE);
    memrev(padded_digest + digest_offset, SHA1_DIGEST_SIZE);
    dwResult = VerifyStrongSignatureWithKey(reversed_signature, padded_digest, szStarcraft2MapPublicKey);
    if(dwResult == ERROR_STRONG_SIGNATURE_OK)
        return dwResult;

    return ERROR_STRONG_SIGNATURE_ERROR;
}

static DWORD VerifyFile(
    HANDLE hMpq,
    const char * szFileName,
    LPDWORD pdwCrc32,
    char * pMD5,
    DWORD dwFlags)
{
    hash_state md5_state;
    unsigned char * pFileMd5;
    unsigned char md5[MD5_DIGEST_SIZE];
    TFileEntry * pFileEntry;
    TMPQFile * hf;
    BYTE Buffer[0x1000];
    HANDLE hFile = NULL;
    DWORD dwVerifyResult = 0;
    DWORD dwSearchScope = SFILE_OPEN_FROM_MPQ;
    DWORD dwTotalBytes = 0;
    DWORD dwBytesRead;
    DWORD dwCrc32 = 0;

    // Fix the open type for patched archives
    if(SFileIsPatchedArchive(hMpq))
        dwSearchScope = SFILE_OPEN_PATCHED_FILE;

    // If we have to verify raw data MD5, do it before file open
    if(dwFlags & SFILE_VERIFY_RAW_MD5)
    {
        TMPQArchive * ha = (TMPQArchive *)hMpq;

        // Parse the base MPQ and all patches
        while(ha != NULL)
        {
            // Does the archive have support for raw MD5?
            if(ha->pHeader->dwRawChunkSize != 0)
            {
                // The file has raw MD5 if the archive supports it
                dwVerifyResult |= VERIFY_FILE_HAS_RAW_MD5;

                // Find file entry for the file
                pFileEntry = GetFileEntryLocale(ha, szFileName, lcFileLocale);
                if(pFileEntry != NULL)
                {
                    // If the file's raw MD5 doesn't match, don't bother with more checks
                    if(VerifyRawMpqData(ha, pFileEntry->ByteOffset, pFileEntry->dwCmpSize) != ERROR_SUCCESS)
                        return dwVerifyResult | VERIFY_FILE_RAW_MD5_ERROR;
                }
            }

            // Move to the next patch
            ha = ha->haPatch;
        }
    }

    // Attempt to open the file
    if(SFileOpenFileEx(hMpq, szFileName, dwSearchScope, &hFile))
    {
        // Get the file size
        hf = (TMPQFile *)hFile;
        pFileEntry = hf->pFileEntry;
        dwTotalBytes = SFileGetFileSize(hFile, NULL);

        // Initialize the CRC32 and MD5 contexts
        md5_init(&md5_state);
        dwCrc32 = crc32(0, Z_NULL, 0);

        // Also turn on sector checksum verification
        if(dwFlags & SFILE_VERIFY_SECTOR_CRC)
            hf->bCheckSectorCRCs = true;

        // Go through entire file and update both CRC32 and MD5
        for(;;)
        {
            // Read data from file
            SFileReadFile(hFile, Buffer, sizeof(Buffer), &dwBytesRead, NULL);
            if(dwBytesRead == 0)
            {
                if(GetLastError() == ERROR_CHECKSUM_ERROR)
                    dwVerifyResult |= VERIFY_FILE_SECTOR_CRC_ERROR;
                break;
            }

            // Update CRC32 value
            if(dwFlags & SFILE_VERIFY_FILE_CRC)
                dwCrc32 = crc32(dwCrc32, Buffer, dwBytesRead);
            
            // Update MD5 value
            if(dwFlags & SFILE_VERIFY_FILE_MD5)
                md5_process(&md5_state, Buffer, dwBytesRead);

            // Decrement the total size
            dwTotalBytes -= dwBytesRead;
        }

        // If the file has sector checksums, indicate it in the flags
        if(dwFlags & SFILE_VERIFY_SECTOR_CRC)
        {
            if((hf->pFileEntry->dwFlags & MPQ_FILE_SECTOR_CRC) && hf->SectorChksums != NULL && hf->SectorChksums[0] != 0)
                dwVerifyResult |= VERIFY_FILE_HAS_SECTOR_CRC;
        }

        // Check if the entire file has been read
        // No point in checking CRC32 and MD5 if not
        // Skip checksum checks if the file has patches
        if(dwTotalBytes == 0)
        {
            // Check CRC32 and MD5 only if there is no patches
            if(hf->hfPatchFile == NULL)
            {
                // Check if the CRC32 matches.
                if(dwFlags & SFILE_VERIFY_FILE_CRC)
                {
                    // Only check the CRC32 if it is valid
                    if(pFileEntry->dwCrc32 != 0)
                    {
                        dwVerifyResult |= VERIFY_FILE_HAS_CHECKSUM;
                        if(dwCrc32 != pFileEntry->dwCrc32)
                            dwVerifyResult |= VERIFY_FILE_CHECKSUM_ERROR;
                    }
                }

                // Check if MD5 matches
                if(dwFlags & SFILE_VERIFY_FILE_MD5)
                {
                    // Patch files have their MD5 saved in the patch info
                    pFileMd5 = (hf->pPatchInfo != NULL) ? hf->pPatchInfo->md5 : pFileEntry->md5;
                    md5_done(&md5_state, md5);

                    // Only check the MD5 if it is valid
                    if(is_valid_md5(pFileMd5))
                    {
                        dwVerifyResult |= VERIFY_FILE_HAS_MD5;
                        if(memcmp(md5, pFileMd5, MD5_DIGEST_SIZE))
                            dwVerifyResult |= VERIFY_FILE_MD5_ERROR;
                    }
                }
            }
            else
            {
                // Patched files are MD5-checked automatically
                dwVerifyResult |= VERIFY_FILE_HAS_MD5;
            }
        }
        else
        {
            dwVerifyResult |= VERIFY_READ_ERROR;
        }

        SFileCloseFile(hFile);
    }
    else
    {
        // Remember that the file couldn't be open
        dwVerifyResult |= VERIFY_OPEN_ERROR;
    }

    // If the caller required CRC32 and/or MD5, give it to him
    if(pdwCrc32 != NULL)
        *pdwCrc32 = dwCrc32;
    if(pMD5 != NULL)
        memcpy(pMD5, md5, MD5_DIGEST_SIZE); 

    return dwVerifyResult;
}

//-----------------------------------------------------------------------------
// Public (exported) functions

bool WINAPI SFileGetFileChecksums(HANDLE hMpq, const char * szFileName, LPDWORD pdwCrc32, char * pMD5)
{
    DWORD dwVerifyResult;
    DWORD dwVerifyFlags = 0;

    if(pdwCrc32 != NULL)
        dwVerifyFlags |= SFILE_VERIFY_FILE_CRC;
    if(pMD5 != NULL)
        dwVerifyFlags |= SFILE_VERIFY_FILE_MD5;

    dwVerifyResult = VerifyFile(hMpq,
                                szFileName,
                                pdwCrc32,
                                pMD5,
                                dwVerifyFlags);

    // If verification failed, return zero
    if(dwVerifyResult & VERIFY_FILE_ERROR_MASK)
    {
        SetLastError(ERROR_FILE_CORRUPT);
        return false;
    }

    return true;
}


DWORD WINAPI SFileVerifyFile(HANDLE hMpq, const char * szFileName, DWORD dwFlags)
{
    return VerifyFile(hMpq,
                      szFileName,
                      NULL,
                      NULL,
                      dwFlags);
}

// Verifies raw data of the archive Only works for MPQs version 4 or newer
int WINAPI SFileVerifyRawData(HANDLE hMpq, DWORD dwWhatToVerify, const char * szFileName)
{
    TMPQArchive * ha = (TMPQArchive *)hMpq;
    TFileEntry * pFileEntry;
    TMPQHeader * pHeader;

    // Verify input parameters
    if(!IsValidMpqHandle(ha))
        return ERROR_INVALID_PARAMETER;
    pHeader = ha->pHeader;

    // If the archive doesn't have raw data MD5, report it as OK
    if(pHeader->dwRawChunkSize == 0)
        return ERROR_SUCCESS;

    // If we have to verify MPQ header, do it
    switch(dwWhatToVerify)
    {
        case SFILE_VERIFY_MPQ_HEADER:
            
            // Only if the header is of version 4 or newer
            if(pHeader->dwHeaderSize >= (MPQ_HEADER_SIZE_V4 - MD5_DIGEST_SIZE))
                return VerifyRawMpqData(ha, 0, MPQ_HEADER_SIZE_V4 - MD5_DIGEST_SIZE);
            return ERROR_SUCCESS;

        case SFILE_VERIFY_HET_TABLE:

            // Only if we have HET table
            if(pHeader->HetTablePos64 && pHeader->HetTableSize64)
                return VerifyRawMpqData(ha, pHeader->HetTablePos64, (DWORD)pHeader->HetTableSize64);
            return ERROR_SUCCESS;

        case SFILE_VERIFY_BET_TABLE:

            // Only if we have BET table
            if(pHeader->BetTablePos64 && pHeader->BetTableSize64)
                return VerifyRawMpqData(ha, pHeader->BetTablePos64, (DWORD)pHeader->BetTableSize64);
            return ERROR_SUCCESS;

        case SFILE_VERIFY_HASH_TABLE:

            // Hash table is not protected by MD5
            return ERROR_SUCCESS;

        case SFILE_VERIFY_BLOCK_TABLE:

            // Block table is not protected by MD5
            return ERROR_SUCCESS;

        case SFILE_VERIFY_HIBLOCK_TABLE:

            // It is unknown if the hi-block table is protected my MD5 or not.
            return ERROR_SUCCESS;

        case SFILE_VERIFY_FILE:

            // Verify parameters
            if(szFileName == NULL || *szFileName == 0)
                return ERROR_INVALID_PARAMETER;

            // Get the offset of a file
            pFileEntry = GetFileEntryLocale(ha, szFileName, lcFileLocale);
            if(pFileEntry == NULL)
                return ERROR_FILE_NOT_FOUND;

            return VerifyRawMpqData(ha, pFileEntry->ByteOffset, pFileEntry->dwCmpSize);
    }

    return ERROR_INVALID_PARAMETER;
}


// Verifies the archive against the signature
DWORD WINAPI SFileVerifyArchive(HANDLE hMpq)
{
    MPQ_SIGNATURE_INFO si;
    TMPQArchive * ha = (TMPQArchive *)hMpq;

    // Verify input parameters
    if(!IsValidMpqHandle(ha))
        return ERROR_VERIFY_FAILED;

    // Get the MPQ signature and signature type
    memset(&si, 0, sizeof(MPQ_SIGNATURE_INFO));
    if(!QueryMpqSignatureInfo(ha, &si))
        return ERROR_VERIFY_FAILED;

    // Verify the signature
    switch(si.nSignatureType)
    {
        case SIGNATURE_TYPE_NONE:
            return ERROR_NO_SIGNATURE;

        case SIGNATURE_TYPE_WEAK:
            return VerifyWeakSignature(ha, &si);

        case SIGNATURE_TYPE_STRONG:
            return VerifyStrongSignature(ha, &si);
    }

    return ERROR_VERIFY_FAILED;
}
