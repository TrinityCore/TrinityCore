#include <sys/mman.h>
#include <sys/param.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/uio.h>

#include <errno.h>
#include <limits.h>
#ifndef SIZE_T_MAX
#  define SIZE_T_MAX	SIZE_MAX
#endif
#include <pthread.h>
#include <sched.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#ifndef offsetof
#  define offsetof(type, member)	((size_t)&(((type *)NULL)->member))
#endif
#include <inttypes.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <math.h>

#define	JEMALLOC_MANGLE
#include "../jemalloc.h"

#ifdef JEMALLOC_ZONE
#include <mach/mach_error.h>
#include <mach/mach_init.h>
#include <mach/vm_map.h>
#include <malloc/malloc.h>
#endif

#ifdef JEMALLOC_LAZY_LOCK
#include <dlfcn.h>
#endif

#define	RB_COMPACT
#include "jemalloc/internal/rb.h"
#include "jemalloc/internal/qr.h"
#include "jemalloc/internal/ql.h"

extern void	(*JEMALLOC_P(malloc_message))(void *wcbopaque, const char *s);

/*
 * Define a custom assert() in order to reduce the chances of deadlock during
 * assertion failure.
 */
#ifdef JEMALLOC_DEBUG
#  define assert(e) do {						\
	if (!(e)) {							\
		char line_buf[UMAX2S_BUFSIZE];				\
		malloc_write("<jemalloc>: ");				\
		malloc_write(__FILE__);					\
		malloc_write(":");					\
		malloc_write(u2s(__LINE__, 10, line_buf));		\
		malloc_write(": Failed assertion: ");			\
		malloc_write("\"");					\
		malloc_write(#e);					\
		malloc_write("\"\n");					\
		abort();						\
	}								\
} while (0)
#else
#define assert(e)
#endif

/*
 * jemalloc can conceptually be broken into components (arena, tcache, etc.),
 * but there are circular dependencies that cannot be broken without
 * substantial performance degradation.  In order to reduce the effect on
 * visual code flow, read the header files in multiple passes, with one of the
 * following cpp variables defined during each pass:
 *
 *   JEMALLOC_H_TYPES   : Preprocessor-defined constants and psuedo-opaque data
 *                        types.
 *   JEMALLOC_H_STRUCTS : Data structures.
 *   JEMALLOC_H_EXTERNS : Extern data declarations and function prototypes.
 *   JEMALLOC_H_INLINES : Inline functions.
 */
/******************************************************************************/
#define JEMALLOC_H_TYPES

#define	ALLOCM_LG_ALIGN_MASK	((int)0x3f)

#define	ZU(z)	((size_t)z)

#ifndef __DECONST
#  define	__DECONST(type, var)	((type)(uintptr_t)(const void *)(var))
#endif

#ifdef JEMALLOC_DEBUG
   /* Disable inlining to make debugging easier. */
#  define JEMALLOC_INLINE
#  define inline
#else
#  define JEMALLOC_ENABLE_INLINE
#  define JEMALLOC_INLINE static inline
#endif

/* Size of stack-allocated buffer passed to buferror(). */
#define	BUFERROR_BUF		64

/* Minimum alignment of allocations is 2^LG_QUANTUM bytes. */
#ifdef __i386__
#  define LG_QUANTUM		4
#endif
#ifdef __ia64__
#  define LG_QUANTUM		4
#endif
#ifdef __alpha__
#  define LG_QUANTUM		4
#endif
#ifdef __sparc64__
#  define LG_QUANTUM		4
#endif
#if (defined(__amd64__) || defined(__x86_64__))
#  define LG_QUANTUM		4
#endif
#ifdef __arm__
#  define LG_QUANTUM		3
#endif
#ifdef __mips__
#  define LG_QUANTUM		3
#endif
#ifdef __powerpc__
#  define LG_QUANTUM		4
#endif
#ifdef __s390x__
#  define LG_QUANTUM		4
#endif

#define	QUANTUM			((size_t)(1U << LG_QUANTUM))
#define	QUANTUM_MASK		(QUANTUM - 1)

/* Return the smallest quantum multiple that is >= a. */
#define	QUANTUM_CEILING(a)						\
	(((a) + QUANTUM_MASK) & ~QUANTUM_MASK)

#define	SIZEOF_PTR		(1U << LG_SIZEOF_PTR)

/* We can't use TLS in non-PIC programs, since TLS relies on loader magic. */
#if (!defined(PIC) && !defined(NO_TLS))
#  define NO_TLS
#endif

/*
 * Maximum size of L1 cache line.  This is used to avoid cache line aliasing.
 * In addition, this controls the spacing of cacheline-spaced size classes.
 */
#define	LG_CACHELINE		6
#define	CACHELINE		((size_t)(1U << LG_CACHELINE))
#define	CACHELINE_MASK		(CACHELINE - 1)

/* Return the smallest cacheline multiple that is >= s. */
#define	CACHELINE_CEILING(s)						\
	(((s) + CACHELINE_MASK) & ~CACHELINE_MASK)

/*
 * Page size.  STATIC_PAGE_SHIFT is determined by the configure script.  If
 * DYNAMIC_PAGE_SHIFT is enabled, only use the STATIC_PAGE_* macros where
 * compile-time values are required for the purposes of defining data
 * structures.
 */
#define	STATIC_PAGE_SIZE ((size_t)(1U << STATIC_PAGE_SHIFT))
#define	STATIC_PAGE_MASK ((size_t)(STATIC_PAGE_SIZE - 1))

#ifdef PAGE_SHIFT
#  undef PAGE_SHIFT
#endif
#ifdef PAGE_SIZE
#  undef PAGE_SIZE
#endif
#ifdef PAGE_MASK
#  undef PAGE_MASK
#endif

#ifdef DYNAMIC_PAGE_SHIFT
#  define PAGE_SHIFT	lg_pagesize
#  define PAGE_SIZE	pagesize
#  define PAGE_MASK	pagesize_mask
#else
#  define PAGE_SHIFT	STATIC_PAGE_SHIFT
#  define PAGE_SIZE	STATIC_PAGE_SIZE
#  define PAGE_MASK	STATIC_PAGE_MASK
#endif

/* Return the smallest pagesize multiple that is >= s. */
#define	PAGE_CEILING(s)							\
	(((s) + PAGE_MASK) & ~PAGE_MASK)

#include "jemalloc/internal/jemprn.h"
#include "jemalloc/internal/ckh.h"
#include "jemalloc/internal/stats.h"
#include "jemalloc/internal/ctl.h"
#include "jemalloc/internal/mutex.h"
#include "jemalloc/internal/mb.h"
#include "jemalloc/internal/extent.h"
#include "jemalloc/internal/arena.h"
#include "jemalloc/internal/base.h"
#include "jemalloc/internal/chunk.h"
#include "jemalloc/internal/huge.h"
#include "jemalloc/internal/rtree.h"
#include "jemalloc/internal/tcache.h"
#include "jemalloc/internal/hash.h"
#ifdef JEMALLOC_ZONE
#include "jemalloc/internal/zone.h"
#endif
#include "jemalloc/internal/prof.h"

#undef JEMALLOC_H_TYPES
/******************************************************************************/
#define JEMALLOC_H_STRUCTS

#include "jemalloc/internal/jemprn.h"
#include "jemalloc/internal/ckh.h"
#include "jemalloc/internal/stats.h"
#include "jemalloc/internal/ctl.h"
#include "jemalloc/internal/mutex.h"
#include "jemalloc/internal/mb.h"
#include "jemalloc/internal/extent.h"
#include "jemalloc/internal/arena.h"
#include "jemalloc/internal/base.h"
#include "jemalloc/internal/chunk.h"
#include "jemalloc/internal/huge.h"
#include "jemalloc/internal/rtree.h"
#include "jemalloc/internal/tcache.h"
#include "jemalloc/internal/hash.h"
#ifdef JEMALLOC_ZONE
#include "jemalloc/internal/zone.h"
#endif
#include "jemalloc/internal/prof.h"

#undef JEMALLOC_H_STRUCTS
/******************************************************************************/
#define JEMALLOC_H_EXTERNS

extern bool	opt_abort;
#ifdef JEMALLOC_FILL
extern bool	opt_junk;
#endif
#ifdef JEMALLOC_SYSV
extern bool	opt_sysv;
#endif
#ifdef JEMALLOC_XMALLOC
extern bool	opt_xmalloc;
#endif
#ifdef JEMALLOC_FILL
extern bool	opt_zero;
#endif
extern size_t	opt_narenas;

#ifdef DYNAMIC_PAGE_SHIFT
extern size_t		pagesize;
extern size_t		pagesize_mask;
extern size_t		lg_pagesize;
#endif

/* Number of CPUs. */
extern unsigned		ncpus;

extern malloc_mutex_t	arenas_lock; /* Protects arenas initialization. */
#ifndef NO_TLS
/*
 * Map of pthread_self() --> arenas[???], used for selecting an arena to use
 * for allocations.
 */
extern __thread arena_t	*arenas_tls JEMALLOC_ATTR(tls_model("initial-exec"));
#  define ARENA_GET()	arenas_tls
#  define ARENA_SET(v)	do {						\
	arenas_tls = (v);						\
} while (0)
#else
extern pthread_key_t	arenas_tsd;
#  define ARENA_GET()	((arena_t *)pthread_getspecific(arenas_tsd))
#  define ARENA_SET(v)	do {						\
	pthread_setspecific(arenas_tsd, (void *)(v));			\
} while (0)
#endif

/*
 * Arenas that are used to service external requests.  Not all elements of the
 * arenas array are necessarily used; arenas are created lazily as needed.
 */
extern arena_t		**arenas;
extern unsigned		narenas;

#ifdef JEMALLOC_STATS
typedef struct {
	uint64_t	allocated;
	uint64_t	deallocated;
} thread_allocated_t;
#  ifndef NO_TLS
extern __thread thread_allocated_t	thread_allocated_tls;
#    define ALLOCATED_GET() thread_allocated_tls.allocated
#    define DEALLOCATED_GET() thread_allocated_tls.deallocated
#    define ALLOCATED_ADD(a, d) do {					\
	thread_allocated_tls.allocated += a;				\
	thread_allocated_tls.deallocated += d;				\
} while (0)
#  else
extern pthread_key_t	thread_allocated_tsd;
#    define ALLOCATED_GET()						\
	(uint64_t)((pthread_getspecific(thread_allocated_tsd) != NULL)	\
	    ? ((thread_allocated_t *)					\
	    pthread_getspecific(thread_allocated_tsd))->allocated : 0)
#    define DEALLOCATED_GET()						\
	(uint64_t)((pthread_getspecific(thread_allocated_tsd) != NULL)	\
	    ? ((thread_allocated_t					\
	    *)pthread_getspecific(thread_allocated_tsd))->deallocated :	\
	    0)
#    define ALLOCATED_ADD(a, d) do {					\
	thread_allocated_t *thread_allocated = (thread_allocated_t *)	\
	    pthread_getspecific(thread_allocated_tsd);			\
	if (thread_allocated != NULL) {					\
		thread_allocated->allocated += (a);			\
		thread_allocated->deallocated += (d);			\
	} else {							\
		thread_allocated = (thread_allocated_t *)		\
		    imalloc(sizeof(thread_allocated_t));		\
		if (thread_allocated != NULL) {				\
			pthread_setspecific(thread_allocated_tsd,	\
			    thread_allocated);				\
			thread_allocated->allocated = (a);		\
			thread_allocated->deallocated = (d);		\
		}							\
	}								\
} while (0)
#  endif
#endif

arena_t	*arenas_extend(unsigned ind);
arena_t	*choose_arena_hard(void);
int	buferror(int errnum, char *buf, size_t buflen);
void	jemalloc_prefork(void);
void	jemalloc_postfork(void);

#include "jemalloc/internal/jemprn.h"
#include "jemalloc/internal/ckh.h"
#include "jemalloc/internal/stats.h"
#include "jemalloc/internal/ctl.h"
#include "jemalloc/internal/mutex.h"
#include "jemalloc/internal/mb.h"
#include "jemalloc/internal/extent.h"
#include "jemalloc/internal/arena.h"
#include "jemalloc/internal/base.h"
#include "jemalloc/internal/chunk.h"
#include "jemalloc/internal/huge.h"
#include "jemalloc/internal/rtree.h"
#include "jemalloc/internal/tcache.h"
#include "jemalloc/internal/hash.h"
#ifdef JEMALLOC_ZONE
#include "jemalloc/internal/zone.h"
#endif
#include "jemalloc/internal/prof.h"

#undef JEMALLOC_H_EXTERNS
/******************************************************************************/
#define JEMALLOC_H_INLINES

#include "jemalloc/internal/jemprn.h"
#include "jemalloc/internal/ckh.h"
#include "jemalloc/internal/stats.h"
#include "jemalloc/internal/ctl.h"
#include "jemalloc/internal/mutex.h"
#include "jemalloc/internal/mb.h"
#include "jemalloc/internal/extent.h"
#include "jemalloc/internal/base.h"
#include "jemalloc/internal/chunk.h"
#include "jemalloc/internal/huge.h"

#ifndef JEMALLOC_ENABLE_INLINE
size_t	pow2_ceil(size_t x);
size_t	s2u(size_t size);
size_t	sa2u(size_t size, size_t alignment, size_t *run_size_p);
void	malloc_write(const char *s);
arena_t	*choose_arena(void);
#endif

#if (defined(JEMALLOC_ENABLE_INLINE) || defined(JEMALLOC_C_))
/* Compute the smallest power of 2 that is >= x. */
JEMALLOC_INLINE size_t
pow2_ceil(size_t x)
{

	x--;
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
#if (LG_SIZEOF_PTR == 3)
	x |= x >> 32;
#endif
	x++;
	return (x);
}

/*
 * Compute usable size that would result from allocating an object with the
 * specified size.
 */
JEMALLOC_INLINE size_t
s2u(size_t size)
{

	if (size <= small_maxclass)
		return arenas[0]->bins[small_size2bin[size]].reg_size;
	if (size <= arena_maxclass)
		return PAGE_CEILING(size);
	return CHUNK_CEILING(size);
}

/*
 * Compute usable size that would result from allocating an object with the
 * specified size and alignment.
 */
JEMALLOC_INLINE size_t
sa2u(size_t size, size_t alignment, size_t *run_size_p)
{
	size_t usize;

	/*
	 * Round size up to the nearest multiple of alignment.
	 *
	 * This done, we can take advantage of the fact that for each small
	 * size class, every object is aligned at the smallest power of two
	 * that is non-zero in the base two representation of the size.  For
	 * example:
	 *
	 *   Size |   Base 2 | Minimum alignment
	 *   -----+----------+------------------
	 *     96 |  1100000 |  32
	 *    144 | 10100000 |  32
	 *    192 | 11000000 |  64
	 *
	 * Depending on runtime settings, it is possible that arena_malloc()
	 * will further round up to a power of two, but that never causes
	 * correctness issues.
	 */
	usize = (size + (alignment - 1)) & (-alignment);
	/*
	 * (usize < size) protects against the combination of maximal
	 * alignment and size greater than maximal alignment.
	 */
	if (usize < size) {
		/* size_t overflow. */
		return (0);
	}

	if (usize <= arena_maxclass && alignment <= PAGE_SIZE) {
		if (usize <= small_maxclass) {
			return
			    (arenas[0]->bins[small_size2bin[usize]].reg_size);
		}
		return (PAGE_CEILING(usize));
	} else {
		size_t run_size;

		/*
		 * We can't achieve subpage alignment, so round up alignment
		 * permanently; it makes later calculations simpler.
		 */
		alignment = PAGE_CEILING(alignment);
		usize = PAGE_CEILING(size);
		/*
		 * (usize < size) protects against very large sizes within
		 * PAGE_SIZE of SIZE_T_MAX.
		 *
		 * (usize + alignment < usize) protects against the
		 * combination of maximal alignment and usize large enough
		 * to cause overflow.  This is similar to the first overflow
		 * check above, but it needs to be repeated due to the new
		 * usize value, which may now be *equal* to maximal
		 * alignment, whereas before we only detected overflow if the
		 * original size was *greater* than maximal alignment.
		 */
		if (usize < size || usize + alignment < usize) {
			/* size_t overflow. */
			return (0);
		}

		/*
		 * Calculate the size of the over-size run that arena_palloc()
		 * would need to allocate in order to guarantee the alignment.
		 */
		if (usize >= alignment)
			run_size = usize + alignment - PAGE_SIZE;
		else {
			/*
			 * It is possible that (alignment << 1) will cause
			 * overflow, but it doesn't matter because we also
			 * subtract PAGE_SIZE, which in the case of overflow
			 * leaves us with a very large run_size.  That causes
			 * the first conditional below to fail, which means
			 * that the bogus run_size value never gets used for
			 * anything important.
			 */
			run_size = (alignment << 1) - PAGE_SIZE;
		}
		if (run_size_p != NULL)
			*run_size_p = run_size;

		if (run_size <= arena_maxclass)
			return (PAGE_CEILING(usize));
		return (CHUNK_CEILING(usize));
	}
}

/*
 * Wrapper around malloc_message() that avoids the need for
 * JEMALLOC_P(malloc_message)(...) throughout the code.
 */
JEMALLOC_INLINE void
malloc_write(const char *s)
{

	JEMALLOC_P(malloc_message)(NULL, s);
}

/*
 * Choose an arena based on a per-thread value (fast-path code, calls slow-path
 * code if necessary).
 */
JEMALLOC_INLINE arena_t *
choose_arena(void)
{
	arena_t *ret;

	ret = ARENA_GET();
	if (ret == NULL) {
		ret = choose_arena_hard();
		assert(ret != NULL);
	}

	return (ret);
}
#endif

#include "jemalloc/internal/rtree.h"
#include "jemalloc/internal/tcache.h"
#include "jemalloc/internal/arena.h"
#include "jemalloc/internal/hash.h"
#ifdef JEMALLOC_ZONE
#include "jemalloc/internal/zone.h"
#endif

#ifndef JEMALLOC_ENABLE_INLINE
void	*imalloc(size_t size);
void	*icalloc(size_t size);
void	*ipalloc(size_t size, size_t alignment, bool zero);
size_t	isalloc(const void *ptr);
#  ifdef JEMALLOC_IVSALLOC
size_t	ivsalloc(const void *ptr);
#  endif
void	idalloc(void *ptr);
void	*iralloc(void *ptr, size_t size, size_t extra, size_t alignment,
    bool zero, bool no_move);
#endif

#if (defined(JEMALLOC_ENABLE_INLINE) || defined(JEMALLOC_C_))
JEMALLOC_INLINE void *
imalloc(size_t size)
{

	assert(size != 0);

	if (size <= arena_maxclass)
		return (arena_malloc(size, false));
	else
		return (huge_malloc(size, false));
}

JEMALLOC_INLINE void *
icalloc(size_t size)
{

	if (size <= arena_maxclass)
		return (arena_malloc(size, true));
	else
		return (huge_malloc(size, true));
}

JEMALLOC_INLINE void *
ipalloc(size_t size, size_t alignment, bool zero)
{
	void *ret;
	size_t usize;
	size_t run_size
#  ifdef JEMALLOC_CC_SILENCE
	    = 0
#  endif
	    ;

	usize = sa2u(size, alignment, &run_size);
	if (usize == 0)
		return (NULL);
	if (usize <= arena_maxclass && alignment <= PAGE_SIZE)
		ret = arena_malloc(usize, zero);
	else if (run_size <= arena_maxclass) {
		ret = arena_palloc(choose_arena(), usize, run_size, alignment,
		    zero);
	} else if (alignment <= chunksize)
		ret = huge_malloc(usize, zero);
	else
		ret = huge_palloc(usize, alignment, zero);

	assert(((uintptr_t)ret & (alignment - 1)) == 0);
	return (ret);
}

JEMALLOC_INLINE size_t
isalloc(const void *ptr)
{
	size_t ret;
	arena_chunk_t *chunk;

	assert(ptr != NULL);

	chunk = (arena_chunk_t *)CHUNK_ADDR2BASE(ptr);
	if (chunk != ptr) {
		/* Region. */
		assert(chunk->arena->magic == ARENA_MAGIC);

#ifdef JEMALLOC_PROF
		ret = arena_salloc_demote(ptr);
#else
		ret = arena_salloc(ptr);
#endif
	} else
		ret = huge_salloc(ptr);

	return (ret);
}

#ifdef JEMALLOC_IVSALLOC
JEMALLOC_INLINE size_t
ivsalloc(const void *ptr)
{

	/* Return 0 if ptr is not within a chunk managed by jemalloc. */
	if (rtree_get(chunks_rtree, (uintptr_t)CHUNK_ADDR2BASE(ptr)) == NULL)
		return (0);

	return (isalloc(ptr));
}
#endif

JEMALLOC_INLINE void
idalloc(void *ptr)
{
	arena_chunk_t *chunk;

	assert(ptr != NULL);

	chunk = (arena_chunk_t *)CHUNK_ADDR2BASE(ptr);
	if (chunk != ptr)
		arena_dalloc(chunk->arena, chunk, ptr);
	else
		huge_dalloc(ptr, true);
}

JEMALLOC_INLINE void *
iralloc(void *ptr, size_t size, size_t extra, size_t alignment, bool zero,
    bool no_move)
{
	void *ret;
	size_t oldsize;

	assert(ptr != NULL);
	assert(size != 0);

	oldsize = isalloc(ptr);

	if (alignment != 0 && ((uintptr_t)ptr & ((uintptr_t)alignment-1))
	    != 0) {
		size_t copysize;

		/*
		 * Existing object alignment is inadquate; allocate new space
		 * and copy.
		 */
		if (no_move)
			return (NULL);
		ret = ipalloc(size + extra, alignment, zero);
		if (ret == NULL) {
			if (extra == 0)
				return (NULL);
			/* Try again, without extra this time. */
			ret = ipalloc(size, alignment, zero);
			if (ret == NULL)
				return (NULL);
		}
		/*
		 * Copy at most size bytes (not size+extra), since the caller
		 * has no expectation that the extra bytes will be reliably
		 * preserved.
		 */
		copysize = (size < oldsize) ? size : oldsize;
		memcpy(ret, ptr, copysize);
		idalloc(ptr);
		return (ret);
	}

	if (no_move) {
		if (size <= arena_maxclass) {
			return (arena_ralloc_no_move(ptr, oldsize, size,
			    extra, zero));
		} else {
			return (huge_ralloc_no_move(ptr, oldsize, size,
			    extra));
		}
	} else {
		if (size + extra <= arena_maxclass) {
			return (arena_ralloc(ptr, oldsize, size, extra,
			    alignment, zero));
		} else {
			return (huge_ralloc(ptr, oldsize, size, extra,
			    alignment, zero));
		}
	}
}
#endif

#include "jemalloc/internal/prof.h"

#undef JEMALLOC_H_INLINES
/******************************************************************************/
