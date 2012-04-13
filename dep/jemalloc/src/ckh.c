/*
 *******************************************************************************
 * Implementation of (2^1+,2) cuckoo hashing, where 2^1+ indicates that each
 * hash bucket contains 2^n cells, for n >= 1, and 2 indicates that two hash
 * functions are employed.  The original cuckoo hashing algorithm was described
 * in:
 *
 *   Pagh, R., F.F. Rodler (2004) Cuckoo Hashing.  Journal of Algorithms
 *     51(2):122-144.
 *
 * Generalization of cuckoo hashing was discussed in:
 *
 *   Erlingsson, U., M. Manasse, F. McSherry (2006) A cool and practical
 *     alternative to traditional hash tables.  In Proceedings of the 7th
 *     Workshop on Distributed Data and Structures (WDAS'06), Santa Clara, CA,
 *     January 2006.
 *
 * This implementation uses precisely two hash functions because that is the
 * fewest that can work, and supporting multiple hashes is an implementation
 * burden.  Here is a reproduction of Figure 1 from Erlingsson et al. (2006)
 * that shows approximate expected maximum load factors for various
 * configurations:
 *
 *           |         #cells/bucket         |
 *   #hashes |   1   |   2   |   4   |   8   |
 *   --------+-------+-------+-------+-------+
 *         1 | 0.006 | 0.006 | 0.03  | 0.12  |
 *         2 | 0.49  | 0.86  |>0.93< |>0.96< |
 *         3 | 0.91  | 0.97  | 0.98  | 0.999 |
 *         4 | 0.97  | 0.99  | 0.999 |       |
 *
 * The number of cells per bucket is chosen such that a bucket fits in one cache
 * line.  So, on 32- and 64-bit systems, we use (8,2) and (4,2) cuckoo hashing,
 * respectively.
 *
 ******************************************************************************/
#define	JEMALLOC_CKH_C_
#include "jemalloc/internal/jemalloc_internal.h"

/******************************************************************************/
/* Function prototypes for non-inline static functions. */

static bool	ckh_grow(ckh_t *ckh);
static void	ckh_shrink(ckh_t *ckh);

/******************************************************************************/

/*
 * Search bucket for key and return the cell number if found; SIZE_T_MAX
 * otherwise.
 */
JEMALLOC_INLINE size_t
ckh_bucket_search(ckh_t *ckh, size_t bucket, const void *key)
{
	ckhc_t *cell;
	unsigned i;

	for (i = 0; i < (ZU(1) << LG_CKH_BUCKET_CELLS); i++) {
		cell = &ckh->tab[(bucket << LG_CKH_BUCKET_CELLS) + i];
		if (cell->key != NULL && ckh->keycomp(key, cell->key))
			return ((bucket << LG_CKH_BUCKET_CELLS) + i);
	}

	return (SIZE_T_MAX);
}

/*
 * Search table for key and return cell number if found; SIZE_T_MAX otherwise.
 */
JEMALLOC_INLINE size_t
ckh_isearch(ckh_t *ckh, const void *key)
{
	size_t hash1, hash2, bucket, cell;

	assert(ckh != NULL);
	dassert(ckh->magic == CKH_MAGIC);

	ckh->hash(key, ckh->lg_curbuckets, &hash1, &hash2);

	/* Search primary bucket. */
	bucket = hash1 & ((ZU(1) << ckh->lg_curbuckets) - 1);
	cell = ckh_bucket_search(ckh, bucket, key);
	if (cell != SIZE_T_MAX)
		return (cell);

	/* Search secondary bucket. */
	bucket = hash2 & ((ZU(1) << ckh->lg_curbuckets) - 1);
	cell = ckh_bucket_search(ckh, bucket, key);
	return (cell);
}

JEMALLOC_INLINE bool
ckh_try_bucket_insert(ckh_t *ckh, size_t bucket, const void *key,
    const void *data)
{
	ckhc_t *cell;
	unsigned offset, i;

	/*
	 * Cycle through the cells in the bucket, starting at a random position.
	 * The randomness avoids worst-case search overhead as buckets fill up.
	 */
	prn32(offset, LG_CKH_BUCKET_CELLS, ckh->prn_state, CKH_A, CKH_C);
	for (i = 0; i < (ZU(1) << LG_CKH_BUCKET_CELLS); i++) {
		cell = &ckh->tab[(bucket << LG_CKH_BUCKET_CELLS) +
		    ((i + offset) & ((ZU(1) << LG_CKH_BUCKET_CELLS) - 1))];
		if (cell->key == NULL) {
			cell->key = key;
			cell->data = data;
			ckh->count++;
			return (false);
		}
	}

	return (true);
}

/*
 * No space is available in bucket.  Randomly evict an item, then try to find an
 * alternate location for that item.  Iteratively repeat this
 * eviction/relocation procedure until either success or detection of an
 * eviction/relocation bucket cycle.
 */
JEMALLOC_INLINE bool
ckh_evict_reloc_insert(ckh_t *ckh, size_t argbucket, void const **argkey,
    void const **argdata)
{
	const void *key, *data, *tkey, *tdata;
	ckhc_t *cell;
	size_t hash1, hash2, bucket, tbucket;
	unsigned i;

	bucket = argbucket;
	key = *argkey;
	data = *argdata;
	while (true) {
		/*
		 * Choose a random item within the bucket to evict.  This is
		 * critical to correct function, because without (eventually)
		 * evicting all items within a bucket during iteration, it
		 * would be possible to get stuck in an infinite loop if there
		 * were an item for which both hashes indicated the same
		 * bucket.
		 */
		prn32(i, LG_CKH_BUCKET_CELLS, ckh->prn_state, CKH_A, CKH_C);
		cell = &ckh->tab[(bucket << LG_CKH_BUCKET_CELLS) + i];
		assert(cell->key != NULL);

		/* Swap cell->{key,data} and {key,data} (evict). */
		tkey = cell->key; tdata = cell->data;
		cell->key = key; cell->data = data;
		key = tkey; data = tdata;

#ifdef CKH_COUNT
		ckh->nrelocs++;
#endif

		/* Find the alternate bucket for the evicted item. */
		ckh->hash(key, ckh->lg_curbuckets, &hash1, &hash2);
		tbucket = hash2 & ((ZU(1) << ckh->lg_curbuckets) - 1);
		if (tbucket == bucket) {
			tbucket = hash1 & ((ZU(1) << ckh->lg_curbuckets) - 1);
			/*
			 * It may be that (tbucket == bucket) still, if the
			 * item's hashes both indicate this bucket.  However,
			 * we are guaranteed to eventually escape this bucket
			 * during iteration, assuming pseudo-random item
			 * selection (true randomness would make infinite
			 * looping a remote possibility).  The reason we can
			 * never get trapped forever is that there are two
			 * cases:
			 *
			 * 1) This bucket == argbucket, so we will quickly
			 *    detect an eviction cycle and terminate.
			 * 2) An item was evicted to this bucket from another,
			 *    which means that at least one item in this bucket
			 *    has hashes that indicate distinct buckets.
			 */
		}
		/* Check for a cycle. */
		if (tbucket == argbucket) {
			*argkey = key;
			*argdata = data;
			return (true);
		}

		bucket = tbucket;
		if (ckh_try_bucket_insert(ckh, bucket, key, data) == false)
			return (false);
	}
}

JEMALLOC_INLINE bool
ckh_try_insert(ckh_t *ckh, void const**argkey, void const**argdata)
{
	size_t hash1, hash2, bucket;
	const void *key = *argkey;
	const void *data = *argdata;

	ckh->hash(key, ckh->lg_curbuckets, &hash1, &hash2);

	/* Try to insert in primary bucket. */
	bucket = hash1 & ((ZU(1) << ckh->lg_curbuckets) - 1);
	if (ckh_try_bucket_insert(ckh, bucket, key, data) == false)
		return (false);

	/* Try to insert in secondary bucket. */
	bucket = hash2 & ((ZU(1) << ckh->lg_curbuckets) - 1);
	if (ckh_try_bucket_insert(ckh, bucket, key, data) == false)
		return (false);

	/*
	 * Try to find a place for this item via iterative eviction/relocation.
	 */
	return (ckh_evict_reloc_insert(ckh, bucket, argkey, argdata));
}

/*
 * Try to rebuild the hash table from scratch by inserting all items from the
 * old table into the new.
 */
JEMALLOC_INLINE bool
ckh_rebuild(ckh_t *ckh, ckhc_t *aTab)
{
	size_t count, i, nins;
	const void *key, *data;

	count = ckh->count;
	ckh->count = 0;
	for (i = nins = 0; nins < count; i++) {
		if (aTab[i].key != NULL) {
			key = aTab[i].key;
			data = aTab[i].data;
			if (ckh_try_insert(ckh, &key, &data)) {
				ckh->count = count;
				return (true);
			}
			nins++;
		}
	}

	return (false);
}

static bool
ckh_grow(ckh_t *ckh)
{
	bool ret;
	ckhc_t *tab, *ttab;
	size_t lg_curcells;
	unsigned lg_prevbuckets;

#ifdef CKH_COUNT
	ckh->ngrows++;
#endif

	/*
	 * It is possible (though unlikely, given well behaved hashes) that the
	 * table will have to be doubled more than once in order to create a
	 * usable table.
	 */
	lg_prevbuckets = ckh->lg_curbuckets;
	lg_curcells = ckh->lg_curbuckets + LG_CKH_BUCKET_CELLS;
	while (true) {
		size_t usize;

		lg_curcells++;
		usize = sa2u(sizeof(ckhc_t) << lg_curcells, CACHELINE, NULL);
		if (usize == 0) {
			ret = true;
			goto RETURN;
		}
		tab = (ckhc_t *)ipalloc(usize, CACHELINE, true);
		if (tab == NULL) {
			ret = true;
			goto RETURN;
		}
		/* Swap in new table. */
		ttab = ckh->tab;
		ckh->tab = tab;
		tab = ttab;
		ckh->lg_curbuckets = lg_curcells - LG_CKH_BUCKET_CELLS;

		if (ckh_rebuild(ckh, tab) == false) {
			idalloc(tab);
			break;
		}

		/* Rebuilding failed, so back out partially rebuilt table. */
		idalloc(ckh->tab);
		ckh->tab = tab;
		ckh->lg_curbuckets = lg_prevbuckets;
	}

	ret = false;
RETURN:
	return (ret);
}

static void
ckh_shrink(ckh_t *ckh)
{
	ckhc_t *tab, *ttab;
	size_t lg_curcells, usize;
	unsigned lg_prevbuckets;

	/*
	 * It is possible (though unlikely, given well behaved hashes) that the
	 * table rebuild will fail.
	 */
	lg_prevbuckets = ckh->lg_curbuckets;
	lg_curcells = ckh->lg_curbuckets + LG_CKH_BUCKET_CELLS - 1;
	usize = sa2u(sizeof(ckhc_t) << lg_curcells, CACHELINE, NULL);
	if (usize == 0)
		return;
	tab = (ckhc_t *)ipalloc(usize, CACHELINE, true);
	if (tab == NULL) {
		/*
		 * An OOM error isn't worth propagating, since it doesn't
		 * prevent this or future operations from proceeding.
		 */
		return;
	}
	/* Swap in new table. */
	ttab = ckh->tab;
	ckh->tab = tab;
	tab = ttab;
	ckh->lg_curbuckets = lg_curcells - LG_CKH_BUCKET_CELLS;

	if (ckh_rebuild(ckh, tab) == false) {
		idalloc(tab);
#ifdef CKH_COUNT
		ckh->nshrinks++;
#endif
		return;
	}

	/* Rebuilding failed, so back out partially rebuilt table. */
	idalloc(ckh->tab);
	ckh->tab = tab;
	ckh->lg_curbuckets = lg_prevbuckets;
#ifdef CKH_COUNT
	ckh->nshrinkfails++;
#endif
}

bool
ckh_new(ckh_t *ckh, size_t minitems, ckh_hash_t *hash, ckh_keycomp_t *keycomp)
{
	bool ret;
	size_t mincells, usize;
	unsigned lg_mincells;

	assert(minitems > 0);
	assert(hash != NULL);
	assert(keycomp != NULL);

#ifdef CKH_COUNT
	ckh->ngrows = 0;
	ckh->nshrinks = 0;
	ckh->nshrinkfails = 0;
	ckh->ninserts = 0;
	ckh->nrelocs = 0;
#endif
	ckh->prn_state = 42; /* Value doesn't really matter. */
	ckh->count = 0;

	/*
	 * Find the minimum power of 2 that is large enough to fit aBaseCount
	 * entries.  We are using (2+,2) cuckoo hashing, which has an expected
	 * maximum load factor of at least ~0.86, so 0.75 is a conservative load
	 * factor that will typically allow 2^aLgMinItems to fit without ever
	 * growing the table.
	 */
	assert(LG_CKH_BUCKET_CELLS > 0);
	mincells = ((minitems + (3 - (minitems % 3))) / 3) << 2;
	for (lg_mincells = LG_CKH_BUCKET_CELLS;
	    (ZU(1) << lg_mincells) < mincells;
	    lg_mincells++)
		; /* Do nothing. */
	ckh->lg_minbuckets = lg_mincells - LG_CKH_BUCKET_CELLS;
	ckh->lg_curbuckets = lg_mincells - LG_CKH_BUCKET_CELLS;
	ckh->hash = hash;
	ckh->keycomp = keycomp;

	usize = sa2u(sizeof(ckhc_t) << lg_mincells, CACHELINE, NULL);
	if (usize == 0) {
		ret = true;
		goto RETURN;
	}
	ckh->tab = (ckhc_t *)ipalloc(usize, CACHELINE, true);
	if (ckh->tab == NULL) {
		ret = true;
		goto RETURN;
	}

#ifdef JEMALLOC_DEBUG
	ckh->magic = CKH_MAGIC;
#endif

	ret = false;
RETURN:
	return (ret);
}

void
ckh_delete(ckh_t *ckh)
{

	assert(ckh != NULL);
	dassert(ckh->magic == CKH_MAGIC);

#ifdef CKH_VERBOSE
	malloc_printf(
	    "%s(%p): ngrows: %"PRIu64", nshrinks: %"PRIu64","
	    " nshrinkfails: %"PRIu64", ninserts: %"PRIu64","
	    " nrelocs: %"PRIu64"\n", __func__, ckh,
	    (unsigned long long)ckh->ngrows,
	    (unsigned long long)ckh->nshrinks,
	    (unsigned long long)ckh->nshrinkfails,
	    (unsigned long long)ckh->ninserts,
	    (unsigned long long)ckh->nrelocs);
#endif

	idalloc(ckh->tab);
#ifdef JEMALLOC_DEBUG
	memset(ckh, 0x5a, sizeof(ckh_t));
#endif
}

size_t
ckh_count(ckh_t *ckh)
{

	assert(ckh != NULL);
	dassert(ckh->magic == CKH_MAGIC);

	return (ckh->count);
}

bool
ckh_iter(ckh_t *ckh, size_t *tabind, void **key, void **data)
{
	size_t i, ncells;

	for (i = *tabind, ncells = (ZU(1) << (ckh->lg_curbuckets +
	    LG_CKH_BUCKET_CELLS)); i < ncells; i++) {
		if (ckh->tab[i].key != NULL) {
			if (key != NULL)
				*key = (void *)ckh->tab[i].key;
			if (data != NULL)
				*data = (void *)ckh->tab[i].data;
			*tabind = i + 1;
			return (false);
		}
	}

	return (true);
}

bool
ckh_insert(ckh_t *ckh, const void *key, const void *data)
{
	bool ret;

	assert(ckh != NULL);
	dassert(ckh->magic == CKH_MAGIC);
	assert(ckh_search(ckh, key, NULL, NULL));

#ifdef CKH_COUNT
	ckh->ninserts++;
#endif

	while (ckh_try_insert(ckh, &key, &data)) {
		if (ckh_grow(ckh)) {
			ret = true;
			goto RETURN;
		}
	}

	ret = false;
RETURN:
	return (ret);
}

bool
ckh_remove(ckh_t *ckh, const void *searchkey, void **key, void **data)
{
	size_t cell;

	assert(ckh != NULL);
	dassert(ckh->magic == CKH_MAGIC);

	cell = ckh_isearch(ckh, searchkey);
	if (cell != SIZE_T_MAX) {
		if (key != NULL)
			*key = (void *)ckh->tab[cell].key;
		if (data != NULL)
			*data = (void *)ckh->tab[cell].data;
		ckh->tab[cell].key = NULL;
		ckh->tab[cell].data = NULL; /* Not necessary. */

		ckh->count--;
		/* Try to halve the table if it is less than 1/4 full. */
		if (ckh->count < (ZU(1) << (ckh->lg_curbuckets
		    + LG_CKH_BUCKET_CELLS - 2)) && ckh->lg_curbuckets
		    > ckh->lg_minbuckets) {
			/* Ignore error due to OOM. */
			ckh_shrink(ckh);
		}

		return (false);
	}

	return (true);
}

bool
ckh_search(ckh_t *ckh, const void *searchkey, void **key, void **data)
{
	size_t cell;

	assert(ckh != NULL);
	dassert(ckh->magic == CKH_MAGIC);

	cell = ckh_isearch(ckh, searchkey);
	if (cell != SIZE_T_MAX) {
		if (key != NULL)
			*key = (void *)ckh->tab[cell].key;
		if (data != NULL)
			*data = (void *)ckh->tab[cell].data;
		return (false);
	}

	return (true);
}

void
ckh_string_hash(const void *key, unsigned minbits, size_t *hash1, size_t *hash2)
{
	size_t ret1, ret2;
	uint64_t h;

	assert(minbits <= 32 || (SIZEOF_PTR == 8 && minbits <= 64));
	assert(hash1 != NULL);
	assert(hash2 != NULL);

	h = hash(key, strlen((const char *)key), 0x94122f335b332aeaLLU);
	if (minbits <= 32) {
		/*
		 * Avoid doing multiple hashes, since a single hash provides
		 * enough bits.
		 */
		ret1 = h & ZU(0xffffffffU);
		ret2 = h >> 32;
	} else {
		ret1 = h;
		ret2 = hash(key, strlen((const char *)key),
		    0x8432a476666bbc13LLU);
	}

	*hash1 = ret1;
	*hash2 = ret2;
}

bool
ckh_string_keycomp(const void *k1, const void *k2)
{

    assert(k1 != NULL);
    assert(k2 != NULL);

    return (strcmp((char *)k1, (char *)k2) ? false : true);
}

void
ckh_pointer_hash(const void *key, unsigned minbits, size_t *hash1,
    size_t *hash2)
{
	size_t ret1, ret2;
	uint64_t h;
	union {
		const void	*v;
		uint64_t	i;
	} u;

	assert(minbits <= 32 || (SIZEOF_PTR == 8 && minbits <= 64));
	assert(hash1 != NULL);
	assert(hash2 != NULL);

	assert(sizeof(u.v) == sizeof(u.i));
#if (LG_SIZEOF_PTR != LG_SIZEOF_INT)
	u.i = 0;
#endif
	u.v = key;
	h = hash(&u.i, sizeof(u.i), 0xd983396e68886082LLU);
	if (minbits <= 32) {
		/*
		 * Avoid doing multiple hashes, since a single hash provides
		 * enough bits.
		 */
		ret1 = h & ZU(0xffffffffU);
		ret2 = h >> 32;
	} else {
		assert(SIZEOF_PTR == 8);
		ret1 = h;
		ret2 = hash(&u.i, sizeof(u.i), 0x5e2be9aff8709a5dLLU);
	}

	*hash1 = ret1;
	*hash2 = ret2;
}

bool
ckh_pointer_keycomp(const void *k1, const void *k2)
{

	return ((k1 == k2) ? true : false);
}
