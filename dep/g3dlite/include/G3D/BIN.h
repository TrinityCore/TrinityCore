#ifndef G3D_BIN_h
#define G3D_BIN_h

#define _BIT(N, K) (((N >> (3*K)) & 1) << K)

#define _OCT_CODED_BIN(N) \
    (_BIT(N, 0) | _BIT(N, 1) | _BIT(N, 2) | _BIT(N, 3) | \
     _BIT(N, 4) | _BIT(N, 5) | _BIT(N, 6) | _BIT(N, 7) | \
     _BIT(N,    | _BIT(N, 9) | _BIT(N, 10))

/** 
    \def BIN11()

    \brief Create a binary constant up to 11 digits long at compile time.

    \code
    int i = BIN(01100101001)
    \endcode

    \cite By Kaz Kylheku http://www.velocityreviews.com/forums/t620780-mathew-hendrys-macro-for-binary-integer-literals.html 
    \sa BIN8(), BIN11(), BIN16(), BIN32()
*/
#define BIN11(N) _OCT_CODED_BIN(0 ## N ## UL)



/* turn a numeric literal into a hex constant 
   (avoids problems with leading zeroes) 
   8-bit constants max value 0x11111111, always fits in unsigned long 
*/ 
#define HEX__(n) 0x##n##LU 

/* 8-bit conversion function */ 
#define B8__(x) ((x&0x0000000FLU)?1:0)      \
+((x&0x000000F0LU)?2:0)      \
+((x&0x00000F00LU)?4:0)      \
+((x&0x0000F000LU)?8:0)      \
+((x&0x000F0000LU)?16:0)     \
+((x&0x00F00000LU)?32:0)     \
+((x&0x0F000000LU)?64:0)     \
+((x&0xF0000000LU)?128:0) 

/**
    \def BIN8()
    \brief Generate a 16-bit constant in binary notation, in 8-bit strings.
    
    The most significant byte is first.

    \code
    unsigned int i = BIN8(01010101); // 85 
    \endcode

    \cite Tom Torfs http://groups.google.com/group/comp.arch.embedded/msg/9d430b6d3da12c8f
    \sa BIN8(), BIN11(), BIN16(), BIN32()
*/
#define BIN8(d) ((unsigned char)B8__(HEX__(d))) 

/** \def BIN16()
    \brief Generate a 16-bit constant in binary notation, in 8-bit strings.
    
    The most significant byte is first.

    \code
    unsigned int i = BIN16(10101010,01010101); // 43605 
    \endcode

    \cite Tom Torfs http://groups.google.com/group/comp.arch.embedded/msg/9d430b6d3da12c8f
    \sa BIN8(), BIN11(), BIN16(), BIN32()
*/
#define BIN16(dmsb, dlsb) (((unsigned short)BIN8(dmsb) << 8) + BIN8(dlsb)) 


/** 
    \def BIN32()
    \brief Generate a 32-bit constant in binary notation, in 8-bit strings.
    
    The most significant byte is first.

    \code
    unsigned int = BIN32(10000000,11111111,10101010,01010101); // 2164238933 
    \endcode

    \cite Tom Torfs http://groups.google.com/group/comp.arch.embedded/msg/9d430b6d3da12c8f
    \sa BIN8(), BIN11(), BIN16(), BIN32()
*/
#define BIN32(dmsb,db2,db3,dlsb) \
    (((unsigned long)BIN8(dmsb) << 24) + \
     ((unsigned long)BIN8(db2)  << 16) + \
     ((unsigned long)BIN8(db3)  << 8) + \
     BIN8(dlsb)) 

#endif
