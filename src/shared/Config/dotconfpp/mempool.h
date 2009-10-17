

#ifndef ASYNC_DNS_MEMPOOL_H
#define ASYNC_DNS_MEMPOOL_H
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#undef free
#undef calloc
#undef strdup
class AsyncDNSMemPool
{
private:
    struct PoolChunk {
        void * pool;
        size_t pos;
        size_t size;
        PoolChunk(size_t _size);
        ~PoolChunk();
    };
    PoolChunk ** chunks;
    size_t chunksCount;
    size_t defaultSize;
    size_t poolUsage;
    size_t poolUsageCounter;
    void addNewChunk(size_t size);
public:
    AsyncDNSMemPool(size_t _defaultSize = 4096);
    virtual ~AsyncDNSMemPool();
    int initialize();
    void free();
    void * alloc(size_t size);
    void * calloc(size_t size);
    char * strdup(const char *str);
};
#endif

