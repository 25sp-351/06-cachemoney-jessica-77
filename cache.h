#ifndef CACHE_H
#define CACHE_H

#include <stdio.h>
#include <stdlib.h>

typedef void (*Void_fptr)(void);
typedef void (*SetProvider_fptr)(long (*)(int));

typedef struct Cache {
    SetProvider_fptr set_provider_func;
    Void_fptr reset_statistics;
    Void_fptr cache_cleanup;
} Cache;

Cache *load_cache_module(const char *libname);

#endif // CACHE_H