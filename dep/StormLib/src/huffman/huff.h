/*****************************************************************************/
/* huffman.h                              Copyright (c) Ladislav Zezula 2003 */
/*---------------------------------------------------------------------------*/
/* Description :                                                             */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* xx.xx.xx  1.00  Lad  The first version of huffman.h                       */
/* 03.05.03  2.00  Lad  Added compression                                    */
/* 08.12.03  2.01  Dan  High-memory handling (> 0x80000000)                  */
/*****************************************************************************/
 
#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__

#include "../StormPort.h"
 
//-----------------------------------------------------------------------------
// Defines
 
#define INSERT_ITEM    1                   
#define SWITCH_ITEMS   2                    // Switch the item1 and item2
 
#define PTR_NOT(ptr)  (THTreeItem *)(~(DWORD_PTR)(ptr))
#define PTR_PTR(ptr)  ((THTreeItem *)(ptr))
#define PTR_INT(ptr)  (INT_PTR)(ptr)
 
#ifndef NULL
#define NULL 0
#endif
 
//-----------------------------------------------------------------------------
// Structures and classes
 
// Input stream for Huffmann decompression
class TInputStream
{
    public:
 
    unsigned long GetBit();
    unsigned long Get7Bits();
    unsigned long Get8Bits();
    void SkipBits(unsigned int BitCount);
 
    unsigned char * pbInBuffer;         // Input data
    unsigned char * pbInBufferEnd;      // End of the input buffer
    unsigned long   BitBuffer;          // Input bit buffer
    unsigned int    BitCount;           // Number of bits remaining in 'dwBitBuff'
};
 
// Output stream for Huffmann compression
class TOutputStream
{
    public:
 
    void PutBits(unsigned long dwBuff, unsigned int nPutBits);
 
    unsigned char * pbOutBuffer;        // 00 : Output buffer
    unsigned long   cbOutSize;          // 04 : Size of output buffer
    unsigned char * pbOutPos;           // 08 : Current output position
    unsigned long   dwBitBuff;          // 0C : Bit buffer
    unsigned long   nBits;              // 10 : Number of bits in the bit buffer
};
 
// Huffmann tree item (?)
struct THTreeItem
{
    public:
    
    THTreeItem * Call1501DB70(THTreeItem * pLast);
    THTreeItem * GetPrevItem(LONG_PTR value);
    void         ClearItemLinks();
    void         RemoveItem();
 
    THTreeItem  * next;                 // 00 - Pointer to next THTreeItem
    THTreeItem  * prev;                 // 04 - Pointer to prev THTreeItem (< 0 if none)
    unsigned long dcmpByte;             // 08 - Index of this item in item pointer array, decompressed byte value
    unsigned long byteValue;            // 0C - Some byte value
    THTreeItem  * parent;               // 10 - Pointer to parent THTreeItem (NULL if none)
    THTreeItem  * child;                // 14 - Pointer to child  THTreeItem
    int           addressMultiplier;    // -1 if object on negative address (>0x80000000), +1 if positive
};
 
// Structure used for quick decompress. The 'bitCount' contains number of bits
// and byte value contains result decompressed byte value.
// After each walk through Huffman tree are filled all entries which are
// multiplies of number of bits loaded from input stream. These entries
// contain number of bits and result value. At the next 7 bits is tested this
// structure first. If corresponding entry found, decompression routine will
// not walk through Huffman tree and directly stores output byte to output stream.
struct TQDecompress
{
    unsigned long offs00;               // 00 - 1 if resolved
    unsigned long nBits;                // 04 - Bit count
    union
    {
        unsigned long dcmpByte;         // 08 - Byte value for decompress (if bitCount <= 7)
        THTreeItem  * pItem;            // 08 - THTreeItem (if number of bits is greater than 7
    };
};
 
// Structure for Huffman tree (Size 0x3674 bytes). Because I'm not expert
// for the decompression, I do not know actually if the class is really a Hufmann
// tree. If someone knows the decompression details, please let me know
class THuffmannTree
{
    public:
    
    THuffmannTree();
    void  InitTree(bool bCompression);
    void  BuildTree(unsigned int nCmpType);
//  void  ModifyTree(unsigned long dwIndex);
//  void  UninitTree();
 
//  void  Call15007010(Bit32 dwInLength, THTreeItem * item);
    THTreeItem * Call1500E740(unsigned int nValue);
    void         Call1500E820(THTreeItem * pItem);
    unsigned int DoCompression(TOutputStream * os, unsigned char * pbInBuffer, int nInLength, int nCmpType);
    unsigned int DoDecompression(unsigned char * pbOutBuffer, unsigned int dwOutLength, TInputStream * is);
 
    unsigned long bIsCmp0;              // 0000 - 1 if compression type 0
    unsigned long offs0004;             // 0004 - Some flag
    THTreeItem    items0008[0x203];     // 0008 - HTree items
 
    //- Sometimes used as HTree item -----------
    THTreeItem  * pItem3050;            // 3050 - Always NULL (?)
    THTreeItem  * pItem3054;            // 3054 - Pointer to Huffman tree item
    THTreeItem  * pItem3058;            // 3058 - Pointer to Huffman tree item (< 0 if invalid)
 
    //- Sometimes used as HTree item -----------
    THTreeItem  * pItem305C;            // 305C - Usually NULL
    THTreeItem  * pFirst;               // 3060 - Pointer to top (first) Huffman tree item
    THTreeItem  * pLast;                // 3064 - Pointer to bottom (last) Huffman tree item (< 0 if invalid)
    unsigned long nItems;               // 3068 - Number of used HTree items
 
    //-------------------------------------------
    THTreeItem * items306C[0x102];      // 306C - THTreeItem pointer array
    TQDecompress qd3474[0x80];          // 3474 - Array for quick decompression
    int          addressMultiplier;     // -1 if object on negative address (>0x80000000), +1 if positive
 
    static unsigned char Table1502A630[];// Some table
};
 
#endif // __HUFFMAN_H__
