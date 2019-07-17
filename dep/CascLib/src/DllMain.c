/*****************************************************************************/
/* DllMain.c                              Copyright (c) Ladislav Zezula 2015 */
/*---------------------------------------------------------------------------*/
/* Description: DllMain for the CascLib.dll library                          */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 26.10.15  1.00  Lad  The first version of DllMain.c                       */
/*****************************************************************************/

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

//-----------------------------------------------------------------------------
// DllMain

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD dwReason, LPVOID lpReserved)
{
    UNREFERENCED_PARAMETER(hInst);
    UNREFERENCED_PARAMETER(dwReason);
    UNREFERENCED_PARAMETER(lpReserved);

    return TRUE;
}
