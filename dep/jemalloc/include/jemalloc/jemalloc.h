#ifndef JEMALLOC_H_
#define	JEMALLOC_H_
#ifdef __cplusplus
extern "C" {
#endif

#include <limits.h>
#include <strings.h>

#define	JEMALLOC_VERSION "3.3.1-0-g9ef9d9e8c271cdf14f664b871a8f98c827714784"
#define	JEMALLOC_VERSION_MAJOR 3
#define	JEMALLOC_VERSION_MINOR 3
#define	JEMALLOC_VERSION_BUGFIX 1
#define	JEMALLOC_VERSION_NREV 0
#define	JEMALLOC_VERSION_GID "9ef9d9e8c271cdf14f664b871a8f98c827714784"

#include "jemalloc_defs.h"

#ifdef JEMALLOC_EXPERIMENTAL
#define	ALLOCM_LG_ALIGN(la)	(la)
#if LG_SIZEOF_PTR == 2
#define	ALLOCM_ALIGN(a)	(ffs(a)-1)
#else
#define	ALLOCM_ALIGN(a)	((a < (size_t)INT_MAX) ? ffs(a)-1 : ffs(a>>32)+31)
#endif
#define	ALLOCM_ZERO	((int)0x40)
#define	ALLOCM_NO_MOVE	((int)0x80)
/* Bias arena index bits so that 0 encodes "ALLOCM_ARENA() unspecified". */
#define	ALLOCM_ARENA(a)	((int)(((a)+1) << 8))

#define	ALLOCM_SUCCESS		0
#define	ALLOCM_ERR_OOM		1
#define	ALLOCM_ERR_NOT_MOVED	2
#endif

/*
 * The je_ prefix on the following public symbol declarations is an artifact of
 * namespace management, and should be omitted in application code unless
 * JEMALLOC_NO_DEMANGLE is defined (see below).
 */
extern JEMALLOC_EXPORT const char	*je_malloc_conf;
extern JEMALLOC_EXPORT void		(*je_malloc_message)(void *cbopaque,
    const char *s);

JEMALLOC_EXPORT void	*je_malloc(size_t size) JEMALLOC_ATTR(malloc);
JEMALLOC_EXPORT void	*je_calloc(size_t num, size_t size)
    JEMALLOC_ATTR(malloc);
JEMALLOC_EXPORT int	je_posix_memalign(void **memptr, size_t alignment,
    size_t size) JEMALLOC_ATTR(nonnull(1));
JEMALLOC_EXPORT void	*je_aligned_alloc(size_t alignment, size_t size)
    JEMALLOC_ATTR(malloc);
JEMALLOC_EXPORT void	*je_realloc(void *ptr, size_t size);
JEMALLOC_EXPORT void	je_free(void *ptr);

#ifdef JEMALLOC_OVERRIDE_MEMALIGN
JEMALLOC_EXPORT void *	je_memalign(size_t alignment, size_t size)
    JEMALLOC_ATTR(malloc);
#endif

#ifdef JEMALLOC_OVERRIDE_VALLOC
JEMALLOC_EXPORT void *	je_valloc(size_t size) JEMALLOC_ATTR(malloc);
#endif

JEMALLOC_EXPORT size_t	je_malloc_usable_size(
    JEMALLOC_USABLE_SIZE_CONST void *ptr);
JEMALLOC_EXPORT void	je_malloc_stats_print(void (*write_cb)(void *,
    const char *), void *je_cbopaque, const char *opts);
JEMALLOC_EXPORT int	je_mallctl(const char *name, void *oldp,
    size_t *oldlenp, void *newp, size_t newlen);
JEMALLOC_EXPORT int	je_mallctlnametomib(const char *name, size_t *mibp,
    size_t *miblenp);
JEMALLOC_EXPORT int	je_mallctlbymib(const size_t *mib, size_t miblen,
    void *oldp, size_t *oldlenp, void *newp, size_t newlen);

#ifdef JEMALLOC_EXPERIMENTAL
JEMALLOC_EXPORT int	je_allocm(void **ptr, size_t *rsize, size_t size,
    int flags) JEMALLOC_ATTR(nonnull(1));
JEMALLOC_EXPORT int	je_rallocm(void **ptr, size_t *rsize, size_t size,
    size_t extra, int flags) JEMALLOC_ATTR(nonnull(1));
JEMALLOC_EXPORT int	je_sallocm(const void *ptr, size_t *rsize, int flags)
    JEMALLOC_ATTR(nonnull(1));
JEMALLOC_EXPORT int	je_dallocm(void *ptr, int flags)
    JEMALLOC_ATTR(nonnull(1));
JEMALLOC_EXPORT int	je_nallocm(size_t *rsize, size_t size, int flags);
#endif

/*
 * By default application code must explicitly refer to mangled symbol names,
 * so that it is possible to use jemalloc in conjunction with another allocator
 * in the same application.  Define JEMALLOC_MANGLE in order to cause automatic
 * name mangling that matches the API prefixing that happened as a result of
 * --with-mangling and/or --with-jemalloc-prefix configuration settings.
 */
#ifdef JEMALLOC_MANGLE
#ifndef JEMALLOC_NO_DEMANGLE
#define	JEMALLOC_NO_DEMANGLE
#endif
#define	malloc_conf je_malloc_conf
#define	malloc_message je_malloc_message
#define	malloc je_malloc
#define	calloc je_calloc
#define	posix_memalign je_posix_memalign
#define	aligned_alloc je_aligned_alloc
#define	realloc je_realloc
#define	free je_free
#define	malloc_usable_size je_malloc_usable_size
#define	malloc_stats_print je_malloc_stats_print
#define	mallctl je_mallctl
#define	mallctlnametomib je_mallctlnametomib
#define	mallctlbymib je_mallctlbymib
#define	memalign je_memalign
#define	valloc je_valloc
#ifdef JEMALLOC_EXPERIMENTAL
#define	allocm je_allocm
#define	rallocm je_rallocm
#define	sallocm je_sallocm
#define	dallocm je_dallocm
#define	nallocm je_nallocm
#endif
#endif

/*
 * The je_* macros can be used as stable alternative names for the public
 * jemalloc API if JEMALLOC_NO_DEMANGLE is defined.  This is primarily meant
 * for use in jemalloc itself, but it can be used by application code to
 * provide isolation from the name mangling specified via --with-mangling
 * and/or --with-jemalloc-prefix.
 */
#ifndef JEMALLOC_NO_DEMANGLE
#undef je_malloc_conf
#undef je_malloc_message
#undef je_malloc
#undef je_calloc
#undef je_posix_memalign
#undef je_aligned_alloc
#undef je_realloc
#undef je_free
#undef je_malloc_usable_size
#undef je_malloc_stats_print
#undef je_mallctl
#undef je_mallctlnametomib
#undef je_mallctlbymib
#undef je_memalign
#undef je_valloc
#ifdef JEMALLOC_EXPERIMENTAL
#undef je_allocm
#undef je_rallocm
#undef je_sallocm
#undef je_dallocm
#undef je_nallocm
#endif
#endif

#ifdef __cplusplus
};
#endif
#endif /* JEMALLOC_H_ */
