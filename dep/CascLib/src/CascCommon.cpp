/*****************************************************************************/
/* CascCommon.cpp                         Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* Common functions for CascLib                                              */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 29.04.14  1.00  Lad  The first version of CascCommon.cpp                  */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "CascLib.h"
#include "CascCommon.h"

//-----------------------------------------------------------------------------
// Conversion of big-endian to integer

// Read the 24-bit big-endian offset into ULONGLONG
DWORD ConvertBytesToInteger_3(LPBYTE ValueAsBytes)
{
    DWORD Value = 0;

    Value = (Value << 0x08) | ValueAsBytes[0];
    Value = (Value << 0x08) | ValueAsBytes[1];
    Value = (Value << 0x08) | ValueAsBytes[2];

    return Value;
}

// Read the 32-bit big-endian offset into ULONGLONG
DWORD ConvertBytesToInteger_4(LPBYTE ValueAsBytes)
{
    DWORD Value = 0;

    Value = (Value << 0x08) | ValueAsBytes[0];
    Value = (Value << 0x08) | ValueAsBytes[1];
    Value = (Value << 0x08) | ValueAsBytes[2];
    Value = (Value << 0x08) | ValueAsBytes[3];

    return Value;
}

DWORD ConvertBytesToInteger_4_LE(LPBYTE ValueAsBytes)
{
    DWORD Value = 0;

    Value = (Value << 0x08) | ValueAsBytes[3];
    Value = (Value << 0x08) | ValueAsBytes[2];
    Value = (Value << 0x08) | ValueAsBytes[1];
    Value = (Value << 0x08) | ValueAsBytes[0];

    return Value;
}

// Read the 40-bit big-endian offset into ULONGLONG
ULONGLONG ConvertBytesToInteger_5(LPBYTE ValueAsBytes)
{
    ULONGLONG Value = 0;

    Value = (Value << 0x08) | ValueAsBytes[0];
    Value = (Value << 0x08) | ValueAsBytes[1];
    Value = (Value << 0x08) | ValueAsBytes[2];
    Value = (Value << 0x08) | ValueAsBytes[3];
    Value = (Value << 0x08) | ValueAsBytes[4];

    return Value;
}

void ConvertIntegerToBytes_4(DWORD Value, LPBYTE ValueAsBytes)
{
    ValueAsBytes[0] = (Value >> 0x18) & 0xFF;
    ValueAsBytes[1] = (Value >> 0x10) & 0xFF;
    ValueAsBytes[2] = (Value >> 0x08) & 0xFF;
    ValueAsBytes[3] = (Value >> 0x00) & 0xFF;
}

//-----------------------------------------------------------------------------
// Common fre routine of a CASC blob

void FreeCascBlob(PQUERY_KEY pBlob)
{
    if(pBlob != NULL)
    {
        if(pBlob->pbData != NULL)
            CASC_FREE(pBlob->pbData);

        pBlob->pbData = NULL;
        pBlob->cbData = 0;
    }
}
