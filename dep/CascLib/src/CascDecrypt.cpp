/*****************************************************************************/
/* CascDecrypt.cpp                        Copyright (c) Ladislav Zezula 2015 */
/*---------------------------------------------------------------------------*/
/* Decryption functions for CascLib                                          */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 31.10.15  1.00  Lad  The first version of CascDecrypt.cpp                 */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "CascLib.h"
#include "CascCommon.h"

//-----------------------------------------------------------------------------
// Local structures

typedef struct _CASC_ENCRYPTION_KEY
{
    ULONGLONG KeyName;                  // "Name" of the key
    BYTE Key[0x10];                     // The key itself
} CASC_ENCRYPTION_KEY, *PCASC_ENCRYPTION_KEY;

typedef struct _CASC_SALSA20
{
    DWORD Key[0x10];
    DWORD dwRounds;

} CASC_SALSA20, *PCASC_SALSA20;

//-----------------------------------------------------------------------------
// Local variables

//keyName FB680CB6A8BF81F3 key 62D90EFA7F36D71C398AE2F1FE37BDB9 keyNameSize 8 keySize 16
//keyName 402CD9D8D6BFED98 key AEB0EADEA47612FE6C041A03958DF241 keyNameSize 8 keySize 16
//keyName 87AEBBC9C4E6B601 key 685E86C6063DFDA6C9E85298076B3D42 keyNameSize 8 keySize 16
//keyName A19C4F859F6EFA54 key 0196CB6F5ECBAD7CB5283891B9712B4B keyNameSize 8 keySize 16
//keyName 11A9203C9881710A key 2E2CB8C397C2F24ED0B5E452F18DC267 keyNameSize 8 keySize 16
//keyName DBD3371554F60306 key 34E397ACE6DD30EEFDC98A2AB093CD3C keyNameSize 8 keySize 16
//keyName DEE3A0521EFF6F03 key AD740CE3FFFF9231468126985708E1B9 keyNameSize 8 keySize 16
//keyName 8C9106108AA84F07 key 53D859DDA2635A38DC32E72B11B32F29 keyNameSize 8 keySize 16

static CASC_ENCRYPTION_KEY CascKeys[] =
{
    {0xFB680CB6A8BF81F3ULL, {0x62, 0xD9, 0x0E, 0xFA, 0x7F, 0x36, 0xD7, 0x1C, 0x39, 0x8A, 0xE2, 0xF1, 0xFE, 0x37, 0xBD, 0xB9}},
    {0x402CD9D8D6BFED98ULL, {0xAE, 0xB0, 0xEA, 0xDE, 0xA4, 0x76, 0x12, 0xFE, 0x6C, 0x04, 0x1A, 0x03, 0x95, 0x8D, 0xF2, 0x41}},
    {0x87AEBBC9C4E6B601ULL, {0x68, 0x5E, 0x86, 0xC6, 0x06, 0x3D, 0xFD, 0xA6, 0xC9, 0xE8, 0x52, 0x98, 0x07, 0x6B, 0x3D, 0x42}},
    {0xA19C4F859F6EFA54ULL, {0x01, 0x96, 0xCB, 0x6F, 0x5E, 0xCB, 0xAD, 0x7C, 0xB5, 0x28, 0x38, 0x91, 0xB9, 0x71, 0x2B, 0x4B}},
    {0x11A9203C9881710AULL, {0x2E, 0x2C, 0xB8, 0xC3, 0x97, 0xC2, 0xF2, 0x4E, 0xD0, 0xB5, 0xE4, 0x52, 0xF1, 0x8D, 0xC2, 0x67}},
    {0xDBD3371554F60306ULL, {0x34, 0xE3, 0x97, 0xAC, 0xE6, 0xDD, 0x30, 0xEE, 0xFD, 0xC9, 0x8A, 0x2A, 0xB0, 0x93, 0xCD, 0x3C}},
    {0xDEE3A0521EFF6F03ULL, {0xAD, 0x74, 0x0C, 0xE3, 0xFF, 0xFF, 0x92, 0x31, 0x46, 0x81, 0x26, 0x98, 0x57, 0x08, 0xE1, 0xB9}},
    {0x8C9106108AA84F07ULL, {0x53, 0xD8, 0x59, 0xDD, 0xA2, 0x63, 0x5A, 0x38, 0xDC, 0x32, 0xE7, 0x2B, 0x11, 0xB3, 0x2F, 0x29}},
    {0x49166D358A34D815ULL, {0x66, 0x78, 0x68, 0xCD, 0x94, 0xEA, 0x01, 0x35, 0xB9, 0xB1, 0x6C, 0x93, 0xB1, 0x12, 0x4A, 0xBA}},
    {0, {0}}
};

static const char * szKeyConstant16 = "expand 16-byte k";
static const char * szKeyConstant32 = "expand 32-byte k";

//-----------------------------------------------------------------------------
// Local functions

static DWORD Rol32(DWORD dwValue, DWORD dwRolCount)
{
    return (dwValue << dwRolCount) | (dwValue >> (32 - dwRolCount));
}

static LPBYTE FindCascKey(ULONGLONG KeyName)
{
    // Search the known keys
    for(size_t i = 0; CascKeys[i].KeyName != 0; i++)
    {
        if(CascKeys[i].KeyName == KeyName)
            return CascKeys[i].Key;
    }

    // Key not found
    return NULL;
}

static void Initialize(PCASC_SALSA20 pState, LPBYTE pbKey, DWORD cbKeyLength, LPBYTE pbVector)
{
    const char * szConstants = (cbKeyLength == 32) ? szKeyConstant32 : szKeyConstant16;
    DWORD KeyIndex = cbKeyLength - 0x10;

    memset(pState, 0, sizeof(CASC_SALSA20));
    pState->Key[0]  = *(PDWORD)(szConstants + 0x00);
    pState->Key[1]  = *(PDWORD)(pbKey + 0x00);
    pState->Key[2]  = *(PDWORD)(pbKey + 0x04);
    pState->Key[3]  = *(PDWORD)(pbKey + 0x08);
    pState->Key[4]  = *(PDWORD)(pbKey + 0x0C);
    pState->Key[5]  = *(PDWORD)(szConstants + 0x04);
    pState->Key[6]  = *(PDWORD)(pbVector + 0x00);
    pState->Key[7]  = *(PDWORD)(pbVector + 0x04);
    pState->Key[8]  = 0;
    pState->Key[9]  = 0;
    pState->Key[10] = *(PDWORD)(szConstants + 0x08);
    pState->Key[11] = *(PDWORD)(pbKey + KeyIndex + 0x00);
    pState->Key[12] = *(PDWORD)(pbKey + KeyIndex + 0x04);
    pState->Key[13] = *(PDWORD)(pbKey + KeyIndex + 0x08);
    pState->Key[14] = *(PDWORD)(pbKey + KeyIndex + 0x0C);
    pState->Key[15] = *(PDWORD)(szConstants + 0x0C);

    pState->dwRounds = 20;
}

static int Decrypt(PCASC_SALSA20 pState, LPBYTE pbOutBuffer, LPBYTE pbInBuffer, size_t cbInBuffer)
{
    LPBYTE pbXorValue;
    DWORD KeyMirror[0x10];
    DWORD XorValue[0x10];
    DWORD BlockSize;
    DWORD i;

    // Repeat until we have data to read
    while(cbInBuffer > 0)
    {
        // Create the copy of the key
        memcpy(KeyMirror, pState->Key, sizeof(KeyMirror));

        // Shuffle the key
        for(i = 0; i < pState->dwRounds; i += 2)
        {
            KeyMirror[0x04] ^= Rol32((KeyMirror[0x00] + KeyMirror[0x0C]), 0x07);
            KeyMirror[0x08] ^= Rol32((KeyMirror[0x04] + KeyMirror[0x00]), 0x09);
            KeyMirror[0x0C] ^= Rol32((KeyMirror[0x08] + KeyMirror[0x04]), 0x0D);
            KeyMirror[0x00] ^= Rol32((KeyMirror[0x0C] + KeyMirror[0x08]), 0x12);

            KeyMirror[0x09] ^= Rol32((KeyMirror[0x05] + KeyMirror[0x01]), 0x07);
            KeyMirror[0x0D] ^= Rol32((KeyMirror[0x09] + KeyMirror[0x05]), 0x09);
            KeyMirror[0x01] ^= Rol32((KeyMirror[0x0D] + KeyMirror[0x09]), 0x0D);
            KeyMirror[0x05] ^= Rol32((KeyMirror[0x01] + KeyMirror[0x0D]), 0x12);

            KeyMirror[0x0E] ^= Rol32((KeyMirror[0x0A] + KeyMirror[0x06]), 0x07);
            KeyMirror[0x02] ^= Rol32((KeyMirror[0x0E] + KeyMirror[0x0A]), 0x09);
            KeyMirror[0x06] ^= Rol32((KeyMirror[0x02] + KeyMirror[0x0E]), 0x0D);
            KeyMirror[0x0A] ^= Rol32((KeyMirror[0x06] + KeyMirror[0x02]), 0x12);

            KeyMirror[0x03] ^= Rol32((KeyMirror[0x0F] + KeyMirror[0x0B]), 0x07);
            KeyMirror[0x07] ^= Rol32((KeyMirror[0x03] + KeyMirror[0x0F]), 0x09);
            KeyMirror[0x0B] ^= Rol32((KeyMirror[0x07] + KeyMirror[0x03]), 0x0D);
            KeyMirror[0x0F] ^= Rol32((KeyMirror[0x0B] + KeyMirror[0x07]), 0x12);

            KeyMirror[0x01] ^= Rol32((KeyMirror[0x00] + KeyMirror[0x03]), 0x07);
            KeyMirror[0x02] ^= Rol32((KeyMirror[0x01] + KeyMirror[0x00]), 0x09);
            KeyMirror[0x03] ^= Rol32((KeyMirror[0x02] + KeyMirror[0x01]), 0x0D);
            KeyMirror[0x00] ^= Rol32((KeyMirror[0x03] + KeyMirror[0x02]), 0x12);

            KeyMirror[0x06] ^= Rol32((KeyMirror[0x05] + KeyMirror[0x04]), 0x07);
            KeyMirror[0x07] ^= Rol32((KeyMirror[0x06] + KeyMirror[0x05]), 0x09);
            KeyMirror[0x04] ^= Rol32((KeyMirror[0x07] + KeyMirror[0x06]), 0x0D);
            KeyMirror[0x05] ^= Rol32((KeyMirror[0x04] + KeyMirror[0x07]), 0x12);

            KeyMirror[0x0B] ^= Rol32((KeyMirror[0x0A] + KeyMirror[0x09]), 0x07);
            KeyMirror[0x08] ^= Rol32((KeyMirror[0x0B] + KeyMirror[0x0A]), 0x09);
            KeyMirror[0x09] ^= Rol32((KeyMirror[0x08] + KeyMirror[0x0B]), 0x0D);
            KeyMirror[0x0A] ^= Rol32((KeyMirror[0x09] + KeyMirror[0x08]), 0x12);

            KeyMirror[0x0C] ^= Rol32((KeyMirror[0x0F] + KeyMirror[0x0E]), 0x07);
            KeyMirror[0x0D] ^= Rol32((KeyMirror[0x0C] + KeyMirror[0x0F]), 0x09);
            KeyMirror[0x0E] ^= Rol32((KeyMirror[0x0D] + KeyMirror[0x0C]), 0x0D);
            KeyMirror[0x0F] ^= Rol32((KeyMirror[0x0E] + KeyMirror[0x0D]), 0x12);
        }

        // Set the number of remaining bytes
        pbXorValue = (LPBYTE)XorValue;
        BlockSize = (DWORD)CASCLIB_MIN(cbInBuffer, 0x40);

        // Prepare the XOR constants
        for(i = 0; i < 16; i++)
        {
            XorValue[i] = KeyMirror[i] + pState->Key[i];
        }

        // Decrypt the block
        for(i = 0; i < BlockSize; i++)
        {
            pbOutBuffer[i] = pbInBuffer[i] ^ pbXorValue[i];
        }

        pState->Key[8] = pState->Key[8] + 1;
        if(pState->Key[8] == 0)
            pState->Key[9] = pState->Key[9] + 1;

        // Adjust buffers
        pbOutBuffer += BlockSize;
        pbInBuffer += BlockSize;
        cbInBuffer -= BlockSize;
    }

    return ERROR_SUCCESS;
}

static int Decrypt_Salsa20(LPBYTE pbOutBuffer, LPBYTE pbInBuffer, size_t cbInBuffer, LPBYTE pbKey, DWORD cbKeySize, LPBYTE pbVector)
{
    CASC_SALSA20 SalsaState;

    Initialize(&SalsaState, pbKey, cbKeySize, pbVector);
    return Decrypt(&SalsaState, pbOutBuffer, pbInBuffer, cbInBuffer);
}

//-----------------------------------------------------------------------------
// Public functions

int CascDecrypt(LPBYTE pbOutBuffer, PDWORD pcbOutBuffer, LPBYTE pbInBuffer, DWORD cbInBuffer, DWORD dwFrameIndex)
{
    ULONGLONG KeyName = 0;
    LPBYTE pbBufferEnd = pbInBuffer + cbInBuffer;
    LPBYTE pbKey;
    DWORD KeyNameSize;
    DWORD dwShift = 0;
    DWORD IVSize;
    BYTE Vector[0x08];
    BYTE EncryptionType;
    int nError;

    // Verify and retrieve the key name size
    if(pbInBuffer >= pbBufferEnd)
        return ERROR_FILE_CORRUPT;
    if(pbInBuffer[0] != 0 && pbInBuffer[0] != 8)
        return ERROR_NOT_SUPPORTED;
    KeyNameSize = *pbInBuffer++;

    // Copy the key name
    if((pbInBuffer + KeyNameSize) >= pbBufferEnd)
        return ERROR_FILE_CORRUPT;
    memcpy(&KeyName, pbInBuffer, KeyNameSize);
    pbInBuffer += KeyNameSize;

    // Verify and retrieve the Vector size
    if(pbInBuffer >= pbBufferEnd)
        return ERROR_FILE_CORRUPT;
    if(pbInBuffer[0] != 4 && pbInBuffer[0] != 8)
        return ERROR_NOT_SUPPORTED;
    IVSize = *pbInBuffer++;

    // Copy the initialization vector
    if((pbInBuffer + IVSize) >= pbBufferEnd)
        return ERROR_FILE_CORRUPT;
    memset(Vector, 0, sizeof(Vector));
    memcpy(Vector, pbInBuffer, IVSize);
    pbInBuffer += IVSize;

    // Verify and retrieve the encryption type
    if(pbInBuffer >= pbBufferEnd)
        return ERROR_FILE_CORRUPT;
    if(pbInBuffer[0] != 'S' && pbInBuffer[0] != 'A')
        return ERROR_NOT_SUPPORTED;
    EncryptionType = *pbInBuffer++;

    // Do we have enough space in the output buffer?
    if((DWORD)(pbBufferEnd - pbInBuffer) > pcbOutBuffer[0])
        return ERROR_INSUFFICIENT_BUFFER;

    // Check if we know the key
    pbKey = FindCascKey(KeyName);
    if(pbKey == NULL)
        return ERROR_UNKNOWN_FILE_KEY;

    // Shuffle the Vector with the block index
    // Note that there's no point to go beyond 32 bits, unless the file has
    // more than 0xFFFFFFFF frames.
    for(int i = 0; i < sizeof(dwFrameIndex); i++)
    {
        Vector[i] = Vector[i] ^ (BYTE)((dwFrameIndex >> dwShift) & 0xFF);
        dwShift += 8;
    }

    // Perform the decryption-specific action
    switch(EncryptionType)
    {
        case 'S':   // Salsa20
            nError = Decrypt_Salsa20(pbOutBuffer, pbInBuffer, (pbBufferEnd - pbInBuffer), pbKey, 0x10, Vector);
            if(nError != ERROR_SUCCESS)
                return nError;

            // Supply the size of the output buffer
            pcbOutBuffer[0] = (DWORD)(pbBufferEnd - pbInBuffer);
            return ERROR_SUCCESS;

//      case 'A':   
//          return ERROR_NOT_SUPPORTED;
    }

    assert(false);
    return ERROR_NOT_SUPPORTED;
}

int CascDirectCopy(LPBYTE pbOutBuffer, PDWORD pcbOutBuffer, LPBYTE pbInBuffer, DWORD cbInBuffer)
{
    // Check the buffer size
    if((cbInBuffer - 1) > pcbOutBuffer[0])
        return ERROR_INSUFFICIENT_BUFFER;

    // Copy the data
    memcpy(pbOutBuffer, pbInBuffer, cbInBuffer);
    pcbOutBuffer[0] = cbInBuffer;
    return ERROR_SUCCESS;
}

