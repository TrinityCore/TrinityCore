#ifndef JEMALLOC_H_
#define	JEMALLOC_H_
#ifdef __cplusplus
extern "C" {
#endif

#define	JEMALLOC_VERSION "1.0.0-0-g5523399"
#define	JEMALLOC_VERSION_MAJOR 1
#define	JEMALLOC_VERSION_MINOR 0
#define	JEMALLOC_VERSION_BUGFIX 0
#define	JEMALLOC_VERSION_NREV 0
#define	JEMALLOC_VERSION_GID "5523399"

#include "jemalloc_defs.h"
#ifndef JEMALLOC_P
#  define JEMALLOC_P(s) s
#endif

extern const char	*JEMALLOC_P(malloc_options);
extern void		(*JEMALLOC_P(malloc_message))(void *, const char *);

void	*JEMALLOC_P(malloc)(size_t size) JEMALLOC_ATTR(malloc);
void	*JEMALLOC_P(calloc)(size_t num, size_t size) JEMALLOC_ATTR(malloc);
int	JEMALLOC_P(posix_memalign)(void **memptr, size_t alignment, size_t size)
    JEMALLOC_ATTR(nonnull(1));
void	*JEMALLOC_P(realloc)(void *ptr, size_t size);
void	JEMALLOC_P(free)(void *ptr);

size_t	JEMALLOC_P(malloc_usable_size)(const void *ptr);
void	JEMALLOC_P(malloc_stats_print)(void (*write_cb)(void *, const char *),
    void *cbopaque, const char *opts);
int	JEMALLOC_P(mallctl)(const char *name, void *oldp, size_t *oldlenp,
    void *newp, size_t newlen);
int	JEMALLOC_P(mallctlnametomib)(const char *name, size_t *mibp,
    size_t *miblenp);
int	JEMALLOC_P(mallctlbymib)(const size_t *mib, size_t miblen, void *oldp,
    size_t *oldlenp, void *newp, size_t newlen);

#ifdef __cplusplus
};
#endif
#endif /* JEMALLOC_H_ */
