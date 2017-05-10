/* Do not define anything - we want to avoid having to maintain complex custom build scripts */

/* define if the compiler has hash_map */
//#define HAVE_HASH_MAP 1

/* define if the compiler has hash_set */
//#define HAVE_HASH_SET 1

#if !defined(_MSC_VER)
#define HAVE_PTHREAD
#endif
