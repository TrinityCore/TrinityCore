/**
 @file Crypto.cpp

 @author Morgan McGuire, matrix@graphics3d.com


 @created 2006-03-28
 @edited  2006-04-06
 */

#include "G3D/platform.h"
#include "G3D/Crypto.h"
#include "G3D/g3dmath.h"

namespace G3D {


int Crypto::smallPrime(int n) {
    debugAssert(n < numSmallPrimes() && n >= 0);

    // From:
    // http://primes.utm.edu/lists/small/1000.txt

    static const int table[] = {
          2,      3,      5,      7,     11,     13,     17,     19,     23,     29,
         31,     37,     41,     43,     47,     53,     59,     61,     67,     71,
         73,     79,     83,     89,     97,    101,    103,    107,    109,    113,
        127,    131,    137,    139,    149,    151,    157,    163,    167,    173,
        179,    181,    191,    193,    197,    199,    211,    223,    227,    229,
        233,    239,    241,    251,    257,    263,    269,    271,    277,    281,
        283,    293,    307,    311,    313,    317,    331,    337,    347,    349,
        353,    359,    367,    373,    379,    383,    389,    397,    401,    409,
        419,    421,    431,    433,    439,    443,    449,    457,    461,    463,
        467,    479,    487,    491,    499,    503,    509,    521,    523,    541,
        547,    557,    563,    569,    571,    577,    587,    593,    599,    601,
        607,    613,    617,    619,    631,    641,    643,    647,    653,    659,
        661,    673,    677,    683,    691,    701,    709,    719,    727,    733,
        739,    743,    751,    757,    761,    769,    773,    787,    797,    809,
        811,    821,    823,    827,    829,    839,    853,    857,    859,    863,
        877,    881,    883,    887,    907,    911,    919,    929,    937,    941,
        947,    953,    967,    971,    977,    983,    991,    997,   1009,   1013,
       1019,   1021,   1031,   1033,   1039,   1049,   1051,   1061,   1063,   1069,
       1087,   1091,   1093,   1097,   1103,   1109,   1117,   1123,   1129,   1151,
       1153,   1163,   1171,   1181,   1187,   1193,   1201,   1213,   1217,   1223,
       1229,   1231,   1237,   1249,   1259,   1277,   1279,   1283,   1289,   1291,
       1297,   1301,   1303,   1307,   1319,   1321,   1327,   1361,   1367,   1373,
       1381,   1399,   1409,   1423,   1427,   1429,   1433,   1439,   1447,   1451,
       1453,   1459,   1471,   1481,   1483,   1487,   1489,   1493,   1499,   1511,
       1523,   1531,   1543,   1549,   1553,   1559,   1567,   1571,   1579,   1583,
       1597,   1601,   1607,   1609,   1613,   1619,   1621,   1627,   1637,   1657,
       1663,   1667,   1669,   1693,   1697,   1699,   1709,   1721,   1723,   1733,
       1741,   1747,   1753,   1759,   1777,   1783,   1787,   1789,   1801,   1811,
       1823,   1831,   1847,   1861,   1867,   1871,   1873,   1877,   1879,   1889,
       1901,   1907,   1913,   1931,   1933,   1949,   1951,   1973,   1979,   1987,
       1993,   1997,   1999};

    return table[n];
}


int Crypto::numSmallPrimes() {
    return 303;
}

uint32 Crypto::crc32(const void* byte, size_t numBytes) {
    static const uint32 crc32Table[256] = {
        0x00000000, 0x77073096, 0xEE0E612C, 0x990951BA,
        0x076DC419, 0x706AF48F, 0xE963A535, 0x9E6495A3,
        0x0EDB8832, 0x79DCB8A4, 0xE0D5E91E, 0x97D2D988,
        0x09B64C2B, 0x7EB17CBD, 0xE7B82D07, 0x90BF1D91,
        0x1DB71064, 0x6AB020F2, 0xF3B97148, 0x84BE41DE,
        0x1ADAD47D, 0x6DDDE4EB, 0xF4D4B551, 0x83D385C7,
        0x136C9856, 0x646BA8C0, 0xFD62F97A, 0x8A65C9EC,
        0x14015C4F, 0x63066CD9, 0xFA0F3D63, 0x8D080DF5,
        0x3B6E20C8, 0x4C69105E, 0xD56041E4, 0xA2677172,
        0x3C03E4D1, 0x4B04D447, 0xD20D85FD, 0xA50AB56B,
        0x35B5A8FA, 0x42B2986C, 0xDBBBC9D6, 0xACBCF940,
        0x32D86CE3, 0x45DF5C75, 0xDCD60DCF, 0xABD13D59,
        0x26D930AC, 0x51DE003A, 0xC8D75180, 0xBFD06116,
        0x21B4F4B5, 0x56B3C423, 0xCFBA9599, 0xB8BDA50F,
        0x2802B89E, 0x5F058808, 0xC60CD9B2, 0xB10BE924,
        0x2F6F7C87, 0x58684C11, 0xC1611DAB, 0xB6662D3D,

        0x76DC4190, 0x01DB7106, 0x98D220BC, 0xEFD5102A,
        0x71B18589, 0x06B6B51F, 0x9FBFE4A5, 0xE8B8D433,
        0x7807C9A2, 0x0F00F934, 0x9609A88E, 0xE10E9818,
        0x7F6A0DBB, 0x086D3D2D, 0x91646C97, 0xE6635C01,
        0x6B6B51F4, 0x1C6C6162, 0x856530D8, 0xF262004E,
        0x6C0695ED, 0x1B01A57B, 0x8208F4C1, 0xF50FC457,
        0x65B0D9C6, 0x12B7E950, 0x8BBEB8EA, 0xFCB9887C,
        0x62DD1DDF, 0x15DA2D49, 0x8CD37CF3, 0xFBD44C65,
        0x4DB26158, 0x3AB551CE, 0xA3BC0074, 0xD4BB30E2,
        0x4ADFA541, 0x3DD895D7, 0xA4D1C46D, 0xD3D6F4FB,
        0x4369E96A, 0x346ED9FC, 0xAD678846, 0xDA60B8D0,
        0x44042D73, 0x33031DE5, 0xAA0A4C5F, 0xDD0D7CC9,
        0x5005713C, 0x270241AA, 0xBE0B1010, 0xC90C2086,
        0x5768B525, 0x206F85B3, 0xB966D409, 0xCE61E49F,
        0x5EDEF90E, 0x29D9C998, 0xB0D09822, 0xC7D7A8B4,
        0x59B33D17, 0x2EB40D81, 0xB7BD5C3B, 0xC0BA6CAD,

        0xEDB88320, 0x9ABFB3B6, 0x03B6E20C, 0x74B1D29A,
        0xEAD54739, 0x9DD277AF, 0x04DB2615, 0x73DC1683,
        0xE3630B12, 0x94643B84, 0x0D6D6A3E, 0x7A6A5AA8,
        0xE40ECF0B, 0x9309FF9D, 0x0A00AE27, 0x7D079EB1,
        0xF00F9344, 0x8708A3D2, 0x1E01F268, 0x6906C2FE,
        0xF762575D, 0x806567CB, 0x196C3671, 0x6E6B06E7,
        0xFED41B76, 0x89D32BE0, 0x10DA7A5A, 0x67DD4ACC,
        0xF9B9DF6F, 0x8EBEEFF9, 0x17B7BE43, 0x60B08ED5,
        0xD6D6A3E8, 0xA1D1937E, 0x38D8C2C4, 0x4FDFF252,
        0xD1BB67F1, 0xA6BC5767, 0x3FB506DD, 0x48B2364B,
        0xD80D2BDA, 0xAF0A1B4C, 0x36034AF6, 0x41047A60,
        0xDF60EFC3, 0xA867DF55, 0x316E8EEF, 0x4669BE79,
        0xCB61B38C, 0xBC66831A, 0x256FD2A0, 0x5268E236,
        0xCC0C7795, 0xBB0B4703, 0x220216B9, 0x5505262F,
        0xC5BA3BBE, 0xB2BD0B28, 0x2BB45A92, 0x5CB36A04,
        0xC2D7FFA7, 0xB5D0CF31, 0x2CD99E8B, 0x5BDEAE1D,

        0x9B64C2B0, 0xEC63F226, 0x756AA39C, 0x026D930A,
        0x9C0906A9, 0xEB0E363F, 0x72076785, 0x05005713,
        0x95BF4A82, 0xE2B87A14, 0x7BB12BAE, 0x0CB61B38,
        0x92D28E9B, 0xE5D5BE0D, 0x7CDCEFB7, 0x0BDBDF21,
        0x86D3D2D4, 0xF1D4E242, 0x68DDB3F8, 0x1FDA836E,
        0x81BE16CD, 0xF6B9265B, 0x6FB077E1, 0x18B74777,
        0x88085AE6, 0xFF0F6A70, 0x66063BCA, 0x11010B5C,
        0x8F659EFF, 0xF862AE69, 0x616BFFD3, 0x166CCF45,
        0xA00AE278, 0xD70DD2EE, 0x4E048354, 0x3903B3C2,
        0xA7672661, 0xD06016F7, 0x4969474D, 0x3E6E77DB,
        0xAED16A4A, 0xD9D65ADC, 0x40DF0B66, 0x37D83BF0,
        0xA9BCAE53, 0xDEBB9EC5, 0x47B2CF7F, 0x30B5FFE9,
        0xBDBDF21C, 0xCABAC28A, 0x53B39330, 0x24B4A3A6,
        0xBAD03605, 0xCDD70693, 0x54DE5729, 0x23D967BF,
        0xB3667A2E, 0xC4614AB8, 0x5D681B02, 0x2A6F2B94,
        0xB40BBE37, 0xC30C8EA1, 0x5A05DF1B, 0x2D02EF8D,
    };

    // By definition, initialize to all binary 1's
    uint32 value = 0xFFFFFFFF;

    for (size_t i = 0; i < numBytes; ++i) {
        value = (value >> 8 ) ^ crc32Table[static_cast<const uint8*>(byte)[i] ^ (value & 0xFF)];
    }

    return value;
}

} // G3D

