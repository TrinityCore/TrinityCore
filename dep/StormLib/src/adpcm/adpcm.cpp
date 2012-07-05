/*****************************************************************************/
/* adpcm.cpp                              Copyright (c) Ladislav Zezula 2003 */
/*---------------------------------------------------------------------------*/
/* This module contains implementation of adpcm decompression method used by */
/* Storm.dll to decompress WAVE files. Thanks to Tom Amigo for releasing     */
/* his sources.                                                              */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 11.03.03  1.00  Lad  Splitted from Pkware.cpp                             */
/* 20.05.03  2.00  Lad  Added compression                                    */
/* 19.11.03  2.01  Dan  Big endian handling                                  */
/*****************************************************************************/

#include "adpcm.h"

//------------------------------------------------------------------------------
// Structures

typedef union _BYTE_AND_WORD_PTR
{
    short * pw;
    unsigned char * pb;
} BYTE_AND_WORD_PTR;

typedef union _WORD_AND_BYTE_ARRAY
{
    short w;
    unsigned char b[2];
} WORD_AND_BYTE_ARRAY;

//-----------------------------------------------------------------------------
// Tables necessary dor decompression

static long Table1503F120[] =
{
    0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000004, 0xFFFFFFFF, 0x00000002, 0xFFFFFFFF, 0x00000006,
    0xFFFFFFFF, 0x00000001, 0xFFFFFFFF, 0x00000005, 0xFFFFFFFF, 0x00000003, 0xFFFFFFFF, 0x00000007,
    0xFFFFFFFF, 0x00000001, 0xFFFFFFFF, 0x00000005, 0xFFFFFFFF, 0x00000003, 0xFFFFFFFF, 0x00000007,  
    0xFFFFFFFF, 0x00000002, 0xFFFFFFFF, 0x00000004, 0xFFFFFFFF, 0x00000006, 0xFFFFFFFF, 0x00000008  
};

static long step_table[] =
{
    0x00000007, 0x00000008, 0x00000009, 0x0000000A, 0x0000000B, 0x0000000C, 0x0000000D, 0x0000000E,
    0x00000010, 0x00000011, 0x00000013, 0x00000015, 0x00000017, 0x00000019, 0x0000001C, 0x0000001F,
    0x00000022, 0x00000025, 0x00000029, 0x0000002D, 0x00000032, 0x00000037, 0x0000003C, 0x00000042,
    0x00000049, 0x00000050, 0x00000058, 0x00000061, 0x0000006B, 0x00000076, 0x00000082, 0x0000008F,
    0x0000009D, 0x000000AD, 0x000000BE, 0x000000D1, 0x000000E6, 0x000000FD, 0x00000117, 0x00000133,
    0x00000151, 0x00000173, 0x00000198, 0x000001C1, 0x000001EE, 0x00000220, 0x00000256, 0x00000292,
    0x000002D4, 0x0000031C, 0x0000036C, 0x000003C3, 0x00000424, 0x0000048E, 0x00000502, 0x00000583,
    0x00000610, 0x000006AB, 0x00000756, 0x00000812, 0x000008E0, 0x000009C3, 0x00000ABD, 0x00000BD0,
    0x00000CFF, 0x00000E4C, 0x00000FBA, 0x0000114C, 0x00001307, 0x000014EE, 0x00001706, 0x00001954,
    0x00001BDC, 0x00001EA5, 0x000021B6, 0x00002515, 0x000028CA, 0x00002CDF, 0x0000315B, 0x0000364B,
    0x00003BB9, 0x000041B2, 0x00004844, 0x00004F7E, 0x00005771, 0x0000602F, 0x000069CE, 0x00007462,
    0x00007FFF
};

//----------------------------------------------------------------------------
// CompressWave

// 1500EF70
int CompressADPCM(unsigned char * pbOutBuffer, int dwOutLength, short * pwInBuffer, int dwInLength, int nChannels, int nCmpLevel)
//                ECX                          EDX
{
    WORD_AND_BYTE_ARRAY Wcmp;
    BYTE_AND_WORD_PTR out;                    // Pointer to the output buffer
    long SInt32Array1[2];
    long SInt32Array2[2];
    long SInt32Array3[2];
    long nBytesRemains = dwOutLength;       // Number of bytes remaining
    long nWordsRemains;                     // Number of words remaining
//  unsigned char * pbSaveOutBuffer;        // Copy of output buffer (actually not used)
    unsigned long dwBitBuff;
    unsigned long dwStopBit;
    unsigned long dwBit;
    unsigned long ebx;
    unsigned long esi;
    long nTableValue;
    long nOneWord;
    long var_1C;
    long var_2C;
    int nLength;
    int nIndex;
    int nValue;
    int i, chnl;

    // If less than 2 bytes remain, don't decompress anything
//  pbSaveOutBuffer = pbOutBuffer;
    out.pb = pbOutBuffer;
    if(nBytesRemains < 2)
        return 2;

    Wcmp.b[1] = (unsigned char)(nCmpLevel - 1);
    Wcmp.b[0] = (unsigned char)0;

    *out.pw++ = BSWAP_INT16_SIGNED(Wcmp.w);
    if((out.pb - pbOutBuffer + (nChannels * 2)) > nBytesRemains)
        return (int)(out.pb - pbOutBuffer + (nChannels * 2));

    SInt32Array1[0] = SInt32Array1[1] = 0x2C;

    for(i = 0; i < nChannels; i++)
    {
        nOneWord = BSWAP_INT16_SIGNED(*pwInBuffer++);
        *out.pw++ = BSWAP_INT16_SIGNED((short)nOneWord);
        SInt32Array2[i] = nOneWord;
    }

    // Weird. But it's there
    nLength = dwInLength;
    if(nLength < 0)                     // mov eax, dwInLength; cdq; sub eax, edx;
        nLength++;

    nLength = (nLength / 2) - (int)(out.pb - pbOutBuffer);
    nLength = (nLength < 0) ? 0 : nLength;
    
    nIndex  = nChannels - 1;            // edi
    nWordsRemains = dwInLength / 2;     // eax
    
    // ebx - nChannels
    // ecx - pwOutPos
    for(chnl = nChannels; chnl < nWordsRemains; chnl++)
    {
        // 1500F030
        if((out.pb - pbOutBuffer + 2) > nBytesRemains)
            return (int)(out.pb - pbOutBuffer + 2);

        // Switch index
        if(nChannels == 2)
            nIndex = (nIndex == 0) ? 1 : 0;

        // Load one word from the input stream
        nOneWord = BSWAP_INT16_SIGNED(*pwInBuffer++);   // ecx - nOneWord
        SInt32Array3[nIndex] = nOneWord;

        // esi - SInt32Array2[nIndex]
        // eax - nValue
        nValue = nOneWord - SInt32Array2[nIndex];
        nValue = (nValue < 0) ? ((nValue ^ 0xFFFFFFFF) + 1) : nValue;

        ebx = (nOneWord >= SInt32Array2[nIndex]) ? 0 : 0x40;

        // esi - SInt32Array2[nIndex]
        // edx - step_table[SInt32Array2[nIndex]]
        // edi - (step_table[SInt32Array1[nIndex]] >> nCmpLevel)
        nTableValue = step_table[SInt32Array1[nIndex]];
        dwStopBit = (unsigned long)nCmpLevel;

        // edi - nIndex;
        if(nValue < (nTableValue >> nCmpLevel))
        {
            if(SInt32Array1[nIndex] != 0)
                SInt32Array1[nIndex]--;
            *out.pb++ = 0x80;
        }
        else
        {
            while(nValue > nTableValue * 2)
            {
                if(SInt32Array1[nIndex] >= 0x58 || nLength == 0)
                    break;

                SInt32Array1[nIndex] += 8;
                if(SInt32Array1[nIndex] > 0x58)
                    SInt32Array1[nIndex] = 0x58;

                nTableValue = step_table[SInt32Array1[nIndex]];
                *out.pb++ = 0x81;
                nLength--;
            }

            var_2C = nTableValue >> Wcmp.b[1];
            dwBitBuff = 0;

            esi = (1 << (dwStopBit - 2));
            dwStopBit = (esi <= 0x20) ? esi : 0x20;

            for(var_1C = 0, dwBit = 1; ; dwBit <<= 1)
            {
//              esi = var_1C + nTableValue;
                if((var_1C + nTableValue) <= nValue)
                {
                    var_1C += nTableValue;
                    dwBitBuff |= dwBit;
                }
                if(dwBit == dwStopBit)
                    break;
               
                nTableValue >>= 1;
            }

            nValue = SInt32Array2[nIndex];
            if(ebx != 0)
            {
                nValue -= (var_1C + var_2C);
                if(nValue < -32768)
                    nValue = -32768;
            }
            else
            {
                nValue += (var_1C + var_2C);
                if(nValue > 32767)
                    nValue = 32767;
            }

            SInt32Array2[nIndex]  = nValue;
            *out.pb++ = (unsigned char)(dwBitBuff | ebx);
            nTableValue = Table1503F120[dwBitBuff & 0x1F];
            SInt32Array1[nIndex]  = SInt32Array1[nIndex] + nTableValue; 
            if(SInt32Array1[nIndex] < 0)
                SInt32Array1[nIndex] = 0;
            else if(SInt32Array1[nIndex] > 0x58)
                SInt32Array1[nIndex] = 0x58;
        }
    }

    return (int)(out.pb - pbOutBuffer);
}

//----------------------------------------------------------------------------
// DecompressADPCM

// 1500F230
int DecompressADPCM(unsigned char * pbOutBuffer, int dwOutLength, unsigned char * pbInBuffer, int dwInLength, int nChannels)
{
    BYTE_AND_WORD_PTR out;                // Output buffer
    BYTE_AND_WORD_PTR in;
    unsigned char * pbInBufferEnd = (pbInBuffer + dwInLength);
    long SInt32Array1[2];
    long SInt32Array2[2];
    long nOneWord;
    int nIndex;
    int i;

    SInt32Array1[0] = SInt32Array1[1] = 0x2C;
    out.pb = pbOutBuffer;
    in.pb = pbInBuffer;
    in.pw++;

    // Fill the Uint32Array2 array by channel values.
    for(i = 0; i < nChannels; i++)
    {
        nOneWord = BSWAP_INT16_SIGNED(*in.pw++);
        SInt32Array2[i] = nOneWord;
        if(dwOutLength < 2)
            return (int)(out.pb - pbOutBuffer);

        *out.pw++ = BSWAP_INT16_SIGNED((short)nOneWord);
        dwOutLength -= sizeof(short);
    }

    // Get the initial index
    nIndex = nChannels - 1;

    // Perform the decompression
    while(in.pb < pbInBufferEnd)
    {
        unsigned char nOneByte = *in.pb++;

        // Switch index
        if(nChannels == 2)
            nIndex = (nIndex == 0) ? 1 : 0;

        // 1500F2A2: Get one byte from input buffer
        if(nOneByte & 0x80)
        {
            switch(nOneByte & 0x7F)
            {
                case 0:     // 1500F315
                    if(SInt32Array1[nIndex] != 0)
                        SInt32Array1[nIndex]--;

                    if(dwOutLength < 2)
                        return (int)(out.pb - pbOutBuffer);

                    *out.pw++ = BSWAP_INT16_SIGNED((unsigned short)SInt32Array2[nIndex]);
                    dwOutLength -= sizeof(unsigned short);
                    break;

                case 1:     // 1500F2E8
                    SInt32Array1[nIndex] += 8;
                    if(SInt32Array1[nIndex] > 0x58)
                        SInt32Array1[nIndex] = 0x58;
                    
                    if(nChannels == 2)
                        nIndex = (nIndex == 0) ? 1 : 0;
                    break;

                case 2:     // 1500F41E
                    break;

                default:    // 1500F2C4
                    SInt32Array1[nIndex] -= 8;
                    if(SInt32Array1[nIndex] < 0)
                        SInt32Array1[nIndex] = 0;

                    if(nChannels == 2)
                        nIndex = (nIndex == 0) ? 1 : 0;
                    break;
            }
        }
        else
        {
            // 1500F349
            long temp1 = step_table[SInt32Array1[nIndex]];     // EDI
            long temp2 = temp1 >> pbInBuffer[1];               // ESI
            long temp3 = SInt32Array2[nIndex];                 // ECX

            if(nOneByte & 0x01)          // EBX = nOneByte
                temp2 += (temp1 >> 0);

            if(nOneByte & 0x02)
                temp2 += (temp1 >> 1);

            if(nOneByte & 0x04)
                temp2 += (temp1 >> 2);

            if(nOneByte & 0x08)
                temp2 += (temp1 >> 3);

            if(nOneByte & 0x10)
                temp2 += (temp1 >> 4);

            if(nOneByte & 0x20)
                temp2 += (temp1 >> 5);

            if(nOneByte & 0x40)
            {
                temp3 = temp3 - temp2;
                if(temp3 <= -32768)
                    temp3 = -32768;
            }
            else
            {
                temp3 = temp3 + temp2;
                if(temp3 >= 32767)
                    temp3 = 32767;
            }

            SInt32Array2[nIndex] = temp3;
            if(dwOutLength < 2)
                break;

            // Store the output 16-bit value
            *out.pw++ = BSWAP_INT16_SIGNED((short)SInt32Array2[nIndex]);
            dwOutLength -= 2;

            SInt32Array1[nIndex] += Table1503F120[nOneByte & 0x1F];

            if(SInt32Array1[nIndex] < 0)
                SInt32Array1[nIndex] = 0;
            else if(SInt32Array1[nIndex] > 0x58)
                SInt32Array1[nIndex] = 0x58;
        }
    }
    return (int)(out.pb - pbOutBuffer);
}
