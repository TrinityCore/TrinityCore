/* ---- NUMBER THEORY ---- */

enum {
   PK_PUBLIC=0,
   PK_PRIVATE=1
};

int rand_prime(void *N, long len, prng_state *prng, int wprng);

/* ---- RSA ---- */
#ifdef LTC_MRSA

/* Min and Max RSA key sizes (in bits) */
#define MIN_RSA_SIZE 1024
#define MAX_RSA_SIZE 4096

/** RSA LTC_PKCS style key */
typedef struct Rsa_key {
    /** Type of key, PK_PRIVATE or PK_PUBLIC */
    int type;
    /** The public exponent */
    void *e; 
    /** The private exponent */
    void *d; 
    /** The modulus */
    void *N; 
    /** The p factor of N */
    void *p; 
    /** The q factor of N */
    void *q; 
    /** The 1/q mod p CRT param */
    void *qP; 
    /** The d mod (p - 1) CRT param */
    void *dP; 
    /** The d mod (q - 1) CRT param */
    void *dQ;
} rsa_key;

int rsa_make_key(prng_state *prng, int wprng, int size, long e, rsa_key *key);

int rsa_exptmod(const unsigned char *in,   unsigned long inlen,
                      unsigned char *out,  unsigned long *outlen, int which,
                      rsa_key *key);

void rsa_free(rsa_key *key);

/* These use LTC_PKCS #1 v2.0 padding */
#define rsa_encrypt_key(_in, _inlen, _out, _outlen, _lparam, _lparamlen, _prng, _prng_idx, _hash_idx, _key) \
  rsa_encrypt_key_ex(_in, _inlen, _out, _outlen, _lparam, _lparamlen, _prng, _prng_idx, _hash_idx, LTC_LTC_PKCS_1_OAEP, _key)

#define rsa_decrypt_key(_in, _inlen, _out, _outlen, _lparam, _lparamlen, _hash_idx, _stat, _key) \
  rsa_decrypt_key_ex(_in, _inlen, _out, _outlen, _lparam, _lparamlen, _hash_idx, LTC_LTC_PKCS_1_OAEP, _stat, _key)

#define rsa_sign_hash(_in, _inlen, _out, _outlen, _prng, _prng_idx, _hash_idx, _saltlen, _key) \
  rsa_sign_hash_ex(_in, _inlen, _out, _outlen, LTC_LTC_PKCS_1_PSS, _prng, _prng_idx, _hash_idx, _saltlen, _key)

#define rsa_verify_hash(_sig, _siglen, _hash, _hashlen, _hash_idx, _saltlen, _stat, _key) \
  rsa_verify_hash_ex(_sig, _siglen, _hash, _hashlen, LTC_LTC_PKCS_1_PSS, _hash_idx, _saltlen, _stat, _key)

/* These can be switched between LTC_PKCS #1 v2.x and LTC_PKCS #1 v1.5 paddings */
int rsa_encrypt_key_ex(const unsigned char *in,     unsigned long inlen,
                             unsigned char *out,    unsigned long *outlen,
                       const unsigned char *lparam, unsigned long lparamlen,
                       prng_state *prng, int prng_idx, int hash_idx, int padding, rsa_key *key);

int rsa_decrypt_key_ex(const unsigned char *in,       unsigned long  inlen,
                             unsigned char *out,      unsigned long *outlen,
                       const unsigned char *lparam,   unsigned long  lparamlen,
                             int            hash_idx, int            padding,
                             int           *stat,     rsa_key       *key);

int rsa_sign_hash_ex(const unsigned char *in,       unsigned long  inlen,
                           unsigned char *out,      unsigned long *outlen,
                           int            padding,
                           prng_state    *prng,     int            prng_idx,
                           int            hash_idx, unsigned long  saltlen,
                           rsa_key *key);

int rsa_verify_hash_ex(const unsigned char *sig,      unsigned long siglen,
                       const unsigned char *hash,     unsigned long hashlen,
                             int            padding,
                             int            hash_idx, unsigned long saltlen,
                             int           *stat,     rsa_key      *key);

/* LTC_PKCS #1 import/export */
int rsa_export(unsigned char *out, unsigned long *outlen, int type, rsa_key *key);
int rsa_import(const unsigned char *in, unsigned long inlen, rsa_key *key);

/* Ladik: Added for verifying Blizzard strong signature verification */
int rsa_verify_simple(const unsigned char *sig,  unsigned long siglen,
                      const unsigned char *hash, unsigned long hashlen,
                            int           *stat,
                            rsa_key       *key);

#endif

/* ---- Katja ---- */
#ifdef MKAT

/* Min and Max KAT key sizes (in bits) */
#define MIN_KAT_SIZE 1024
#define MAX_KAT_SIZE 4096

/** Katja LTC_PKCS style key */
typedef struct KAT_key {
    /** Type of key, PK_PRIVATE or PK_PUBLIC */
    int type;
    /** The private exponent */
    void *d; 
    /** The modulus */
    void *N; 
    /** The p factor of N */
    void *p; 
    /** The q factor of N */
    void *q; 
    /** The 1/q mod p CRT param */
    void *qP; 
    /** The d mod (p - 1) CRT param */
    void *dP; 
    /** The d mod (q - 1) CRT param */
    void *dQ;
    /** The pq param */
    void *pq;
} katja_key;

int katja_make_key(prng_state *prng, int wprng, int size, katja_key *key);

int katja_exptmod(const unsigned char *in,   unsigned long inlen,
                        unsigned char *out,  unsigned long *outlen, int which,
                        katja_key *key);

void katja_free(katja_key *key);

/* These use LTC_PKCS #1 v2.0 padding */
int katja_encrypt_key(const unsigned char *in,     unsigned long inlen,
                            unsigned char *out,    unsigned long *outlen,
                      const unsigned char *lparam, unsigned long lparamlen,
                      prng_state *prng, int prng_idx, int hash_idx, katja_key *key);
                                        
int katja_decrypt_key(const unsigned char *in,       unsigned long inlen,
                            unsigned char *out,      unsigned long *outlen, 
                      const unsigned char *lparam,   unsigned long lparamlen,
                            int            hash_idx, int *stat,
                            katja_key       *key);

/* LTC_PKCS #1 import/export */
int katja_export(unsigned char *out, unsigned long *outlen, int type, katja_key *key);
int katja_import(const unsigned char *in, unsigned long inlen, katja_key *key);
                        
#endif

/* ---- ECC Routines ---- */
#ifdef LTC_MECC

/* size of our temp buffers for exported keys */
#define ECC_BUF_SIZE 256

/* max private key size */
#define ECC_MAXSIZE  66

/** Structure defines a NIST GF(p) curve */
typedef struct {
   /** The size of the curve in octets */
   int size;

   /** name of curve */
   char *name; 

   /** The prime that defines the field the curve is in (encoded in hex) */
   char *prime;

   /** The fields B param (hex) */
   char *B;

   /** The order of the curve (hex) */
   char *order;
  
   /** The x co-ordinate of the base point on the curve (hex) */
   char *Gx;
 
   /** The y co-ordinate of the base point on the curve (hex) */
   char *Gy;
} ltc_ecc_set_type;

/** A point on a ECC curve, stored in Jacbobian format such that (x,y,z) => (x/z^2, y/z^3, 1) when interpretted as affine */
typedef struct {
    /** The x co-ordinate */
    void *x;

    /** The y co-ordinate */
    void *y;

    /** The z co-ordinate */
    void *z;
} ecc_point;

/** An ECC key */
typedef struct {
    /** Type of key, PK_PRIVATE or PK_PUBLIC */
    int type;

    /** Index into the ltc_ecc_sets[] for the parameters of this curve; if -1, then this key is using user supplied curve in dp */
    int idx;

	/** pointer to domain parameters; either points to NIST curves (identified by idx >= 0) or user supplied curve */
	const ltc_ecc_set_type *dp;

    /** The public key */
    ecc_point pubkey;

    /** The private key */
    void *k;
} ecc_key;

/** the ECC params provided */
extern const ltc_ecc_set_type ltc_ecc_sets[];

int  ecc_test(void);
void ecc_sizes(int *low, int *high);
int  ecc_get_size(ecc_key *key);

int  ecc_make_key(prng_state *prng, int wprng, int keysize, ecc_key *key);
int  ecc_make_key_ex(prng_state *prng, int wprng, ecc_key *key, const ltc_ecc_set_type *dp);
void ecc_free(ecc_key *key);

int  ecc_export(unsigned char *out, unsigned long *outlen, int type, ecc_key *key);
int  ecc_import(const unsigned char *in, unsigned long inlen, ecc_key *key);
int  ecc_import_ex(const unsigned char *in, unsigned long inlen, ecc_key *key, const ltc_ecc_set_type *dp);

int ecc_ansi_x963_export(ecc_key *key, unsigned char *out, unsigned long *outlen);
int ecc_ansi_x963_import(const unsigned char *in, unsigned long inlen, ecc_key *key);
int ecc_ansi_x963_import_ex(const unsigned char *in, unsigned long inlen, ecc_key *key, ltc_ecc_set_type *dp);

int  ecc_shared_secret(ecc_key *private_key, ecc_key *public_key, 
                       unsigned char *out, unsigned long *outlen);

int  ecc_encrypt_key(const unsigned char *in,   unsigned long inlen,
                           unsigned char *out,  unsigned long *outlen, 
                           prng_state *prng, int wprng, int hash, 
                           ecc_key *key);

int  ecc_decrypt_key(const unsigned char *in,  unsigned long  inlen,
                           unsigned char *out, unsigned long *outlen, 
                           ecc_key *key);

int  ecc_sign_hash(const unsigned char *in,  unsigned long inlen, 
                         unsigned char *out, unsigned long *outlen, 
                         prng_state *prng, int wprng, ecc_key *key);

int  ecc_verify_hash(const unsigned char *sig,  unsigned long siglen,
                     const unsigned char *hash, unsigned long hashlen, 
                     int *stat, ecc_key *key);

/* low level functions */
ecc_point *ltc_ecc_new_point(void);
void       ltc_ecc_del_point(ecc_point *p);
int        ltc_ecc_is_valid_idx(int n);

/* point ops (mp == montgomery digit) */
#if !defined(LTC_MECC_ACCEL) || defined(LTM_LTC_DESC) || defined(GMP_LTC_DESC)
/* R = 2P */
int ltc_ecc_projective_dbl_point(ecc_point *P, ecc_point *R, void *modulus, void *mp);

/* R = P + Q */
int ltc_ecc_projective_add_point(ecc_point *P, ecc_point *Q, ecc_point *R, void *modulus, void *mp);
#endif

#if defined(LTC_MECC_FP)
/* optimized point multiplication using fixed point cache (HAC algorithm 14.117) */
int ltc_ecc_fp_mulmod(void *k, ecc_point *G, ecc_point *R, void *modulus, int map);

/* functions for saving/loading/freeing/adding to fixed point cache */
int ltc_ecc_fp_save_state(unsigned char **out, unsigned long *outlen);
int ltc_ecc_fp_restore_state(unsigned char *in, unsigned long inlen);
void ltc_ecc_fp_free(void);
int ltc_ecc_fp_add_point(ecc_point *g, void *modulus, int lock);

/* lock/unlock all points currently in fixed point cache */
void ltc_ecc_fp_tablelock(int lock);
#endif

/* R = kG */
int ltc_ecc_mulmod(void *k, ecc_point *G, ecc_point *R, void *modulus, int map);

#ifdef LTC_ECC_SHAMIR
/* kA*A + kB*B = C */
int ltc_ecc_mul2add(ecc_point *A, void *kA,
                    ecc_point *B, void *kB,
                    ecc_point *C,
                         void *modulus);

#ifdef LTC_MECC_FP
/* Shamir's trick with optimized point multiplication using fixed point cache */
int ltc_ecc_fp_mul2add(ecc_point *A, void *kA,
                       ecc_point *B, void *kB,
                       ecc_point *C, void *modulus);
#endif

#endif


/* map P to affine from projective */
int ltc_ecc_map(ecc_point *P, void *modulus, void *mp);

#endif

#ifdef LTC_MDSA

/* Max diff between group and modulus size in bytes */
#define LTC_MDSA_DELTA     512

/* Max DSA group size in bytes (default allows 4k-bit groups) */
#define LTC_MDSA_MAX_GROUP 512

/** DSA key structure */
typedef struct {
   /** The key type, PK_PRIVATE or PK_PUBLIC */
   int type; 

   /** The order of the sub-group used in octets */
   int qord;

   /** The generator  */
   void *g;

   /** The prime used to generate the sub-group */
   void *q;

   /** The large prime that generats the field the contains the sub-group */
   void *p;

   /** The private key */
   void *x;

   /** The public key */
   void *y;
} dsa_key;

int dsa_make_key(prng_state *prng, int wprng, int group_size, int modulus_size, dsa_key *key);
void dsa_free(dsa_key *key);

int dsa_sign_hash_raw(const unsigned char *in,  unsigned long inlen,
                                   void *r,   void *s,
                               prng_state *prng, int wprng, dsa_key *key);

int dsa_sign_hash(const unsigned char *in,  unsigned long inlen,
                        unsigned char *out, unsigned long *outlen,
                        prng_state *prng, int wprng, dsa_key *key);

int dsa_verify_hash_raw(         void *r,          void *s,
                    const unsigned char *hash, unsigned long hashlen, 
                                    int *stat,      dsa_key *key);

int dsa_verify_hash(const unsigned char *sig,  unsigned long siglen,
                    const unsigned char *hash, unsigned long hashlen, 
                          int           *stat, dsa_key       *key);

int dsa_encrypt_key(const unsigned char *in,   unsigned long inlen,
                          unsigned char *out,  unsigned long *outlen, 
                          prng_state *prng, int wprng, int hash, 
                          dsa_key *key);
                      
int dsa_decrypt_key(const unsigned char *in,  unsigned long  inlen,
                          unsigned char *out, unsigned long *outlen, 
                          dsa_key *key);
                          
int dsa_import(const unsigned char *in, unsigned long inlen, dsa_key *key);
int dsa_export(unsigned char *out, unsigned long *outlen, int type, dsa_key *key);
int dsa_verify_key(dsa_key *key, int *stat);

int dsa_shared_secret(void          *private_key, void *base,
                      dsa_key       *public_key,
                      unsigned char *out,         unsigned long *outlen);
#endif

#ifdef LTC_DER
/* DER handling */

enum {
 LTC_ASN1_EOL,
 LTC_ASN1_BOOLEAN,
 LTC_ASN1_INTEGER,
 LTC_ASN1_SHORT_INTEGER,
 LTC_ASN1_BIT_STRING,
 LTC_ASN1_OCTET_STRING,
 LTC_ASN1_NULL,
 LTC_ASN1_OBJECT_IDENTIFIER,
 LTC_ASN1_IA5_STRING,
 LTC_ASN1_PRINTABLE_STRING,
 LTC_ASN1_UTF8_STRING,
 LTC_ASN1_UTCTIME,
 LTC_ASN1_CHOICE,
 LTC_ASN1_SEQUENCE,
 LTC_ASN1_SET,
 LTC_ASN1_SETOF
};

/** A LTC ASN.1 list type */
typedef struct ltc_asn1_list_ {
   /** The LTC ASN.1 enumerated type identifier */
   int           type;
   /** The data to encode or place for decoding */
   void         *data;
   /** The size of the input or resulting output */
   unsigned long size;
   /** The used flag, this is used by the CHOICE ASN.1 type to indicate which choice was made */
   int           used;
   /** prev/next entry in the list */
   struct ltc_asn1_list_ *prev, *next, *child, *parent;
} ltc_asn1_list;

#define LTC_SET_ASN1(list, index, Type, Data, Size)  \
   do {                                              \
      int LTC_MACRO_temp            = (index);       \
      ltc_asn1_list *LTC_MACRO_list = (list);        \
      LTC_MACRO_list[LTC_MACRO_temp].type = (Type);  \
      LTC_MACRO_list[LTC_MACRO_temp].data = (void*)(Data);  \
      LTC_MACRO_list[LTC_MACRO_temp].size = (Size);  \
      LTC_MACRO_list[LTC_MACRO_temp].used = 0;       \
   } while (0);

/* SEQUENCE */
int der_encode_sequence_ex(ltc_asn1_list *list, unsigned long inlen,
                           unsigned char *out,  unsigned long *outlen, int type_of);
                          
#define der_encode_sequence(list, inlen, out, outlen) der_encode_sequence_ex(list, inlen, out, outlen, LTC_ASN1_SEQUENCE)                        

int der_decode_sequence_ex(const unsigned char *in, unsigned long  inlen,
                           ltc_asn1_list *list,     unsigned long  outlen, int ordered);
                              
#define der_decode_sequence(in, inlen, list, outlen) der_decode_sequence_ex(in, inlen, list, outlen, 1)

int der_length_sequence(ltc_asn1_list *list, unsigned long inlen,
                        unsigned long *outlen);

/* SET */
#define der_decode_set(in, inlen, list, outlen) der_decode_sequence_ex(in, inlen, list, outlen, 0)
#define der_length_set der_length_sequence
int der_encode_set(ltc_asn1_list *list, unsigned long inlen,
                   unsigned char *out,  unsigned long *outlen);

int der_encode_setof(ltc_asn1_list *list, unsigned long inlen,
                     unsigned char *out,  unsigned long *outlen);
                        
/* VA list handy helpers with triplets of <type, size, data> */
int der_encode_sequence_multi(unsigned char *out, unsigned long *outlen, ...);
int der_decode_sequence_multi(const unsigned char *in, unsigned long inlen, ...);

/* FLEXI DECODER handle unknown list decoder */
int  der_decode_sequence_flexi(const unsigned char *in, unsigned long *inlen, ltc_asn1_list **out);
void der_free_sequence_flexi(ltc_asn1_list *list);
void der_sequence_free(ltc_asn1_list *in);

/* BOOLEAN */
int der_length_boolean(unsigned long *outlen);
int der_encode_boolean(int in, 
                       unsigned char *out, unsigned long *outlen);
int der_decode_boolean(const unsigned char *in, unsigned long inlen,
                                       int *out);		       
/* INTEGER */
int der_encode_integer(void *num, unsigned char *out, unsigned long *outlen);
int der_decode_integer(const unsigned char *in, unsigned long inlen, void *num);
int der_length_integer(void *num, unsigned long *len);

/* INTEGER -- handy for 0..2^32-1 values */
int der_decode_short_integer(const unsigned char *in, unsigned long inlen, unsigned long *num);
int der_encode_short_integer(unsigned long num, unsigned char *out, unsigned long *outlen);
int der_length_short_integer(unsigned long num, unsigned long *outlen);

/* BIT STRING */
int der_encode_bit_string(const unsigned char *in, unsigned long inlen,
                                unsigned char *out, unsigned long *outlen);
int der_decode_bit_string(const unsigned char *in, unsigned long inlen,
                                unsigned char *out, unsigned long *outlen);
int der_length_bit_string(unsigned long nbits, unsigned long *outlen);

/* OCTET STRING */
int der_encode_octet_string(const unsigned char *in, unsigned long inlen,
                                  unsigned char *out, unsigned long *outlen);
int der_decode_octet_string(const unsigned char *in, unsigned long inlen,
                                  unsigned char *out, unsigned long *outlen);
int der_length_octet_string(unsigned long noctets, unsigned long *outlen);

/* OBJECT IDENTIFIER */
int der_encode_object_identifier(unsigned long *words, unsigned long  nwords,
                                 unsigned char *out,   unsigned long *outlen);
int der_decode_object_identifier(const unsigned char *in,    unsigned long  inlen,
                                       unsigned long *words, unsigned long *outlen);
int der_length_object_identifier(unsigned long *words, unsigned long nwords, unsigned long *outlen);
unsigned long der_object_identifier_bits(unsigned long x);

/* IA5 STRING */
int der_encode_ia5_string(const unsigned char *in, unsigned long inlen,
                                unsigned char *out, unsigned long *outlen);
int der_decode_ia5_string(const unsigned char *in, unsigned long inlen,
                                unsigned char *out, unsigned long *outlen);
int der_length_ia5_string(const unsigned char *octets, unsigned long noctets, unsigned long *outlen);

int der_ia5_char_encode(int c);
int der_ia5_value_decode(int v);

/* Printable STRING */
int der_encode_printable_string(const unsigned char *in, unsigned long inlen,
                                unsigned char *out, unsigned long *outlen);
int der_decode_printable_string(const unsigned char *in, unsigned long inlen,
                                unsigned char *out, unsigned long *outlen);
int der_length_printable_string(const unsigned char *octets, unsigned long noctets, unsigned long *outlen);

int der_printable_char_encode(int c);
int der_printable_value_decode(int v);

/* UTF-8 */
#if (defined(SIZE_MAX) || __STDC_VERSION__ >= 199901L || defined(WCHAR_MAX) || defined(_WCHAR_T) || defined(_WCHAR_T_DEFINED) || defined (__WCHAR_TYPE__)) && !defined(LTC_NO_WCHAR) 
#include <wchar.h>
#else
typedef ulong32 wchar_t;
#endif

int der_encode_utf8_string(const wchar_t *in,  unsigned long inlen,
                           unsigned char *out, unsigned long *outlen);

int der_decode_utf8_string(const unsigned char *in,  unsigned long inlen,
                                       wchar_t *out, unsigned long *outlen);
unsigned long der_utf8_charsize(const wchar_t c);
int der_length_utf8_string(const wchar_t *in, unsigned long noctets, unsigned long *outlen);


/* CHOICE */
int der_decode_choice(const unsigned char *in,   unsigned long *inlen,
                            ltc_asn1_list *list, unsigned long  outlen);

/* UTCTime */
typedef struct {
   unsigned YY, /* year */
            MM, /* month */
            DD, /* day */
            hh, /* hour */
            mm, /* minute */
            ss, /* second */
            off_dir, /* timezone offset direction 0 == +, 1 == - */
            off_hh, /* timezone offset hours */
            off_mm; /* timezone offset minutes */
} ltc_utctime;

int der_encode_utctime(ltc_utctime *utctime, 
                       unsigned char *out,   unsigned long *outlen);

int der_decode_utctime(const unsigned char *in, unsigned long *inlen,
                             ltc_utctime   *out);

int der_length_utctime(ltc_utctime *utctime, unsigned long *outlen);


#endif

/* $Source: /cvs/libtom/libtomcrypt/src/headers/tomcrypt_pk.h,v $ */
/* $Revision: 1.81 $ */
/* $Date: 2007/05/12 14:32:35 $ */
