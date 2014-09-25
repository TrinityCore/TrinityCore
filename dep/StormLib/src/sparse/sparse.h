/*****************************************************************************/
/* sparse.h                               Copyright (c) Ladislav Zezula 2010 */
/*---------------------------------------------------------------------------*/
/* implementation of Sparse compression, used in Starcraft II                */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 05.03.10  1.00  Lad  The first version of sparse.h                        */
/*****************************************************************************/

#ifndef __SPARSE_H__
#define __SPARSE_H__

#include "../StormPort.h"

void CompressSparse(unsigned char * pbOutBuffer, int * pcbOutLength, unsigned char * pbInBuffer, int cbInLength);
int  DecompressSparse(unsigned char * pbOutBuffer, int * pcbOutLength, unsigned char * pbInBuffer, int cbInLength);

#endif // __SPARSE_H__
