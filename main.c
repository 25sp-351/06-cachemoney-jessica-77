#include <stdio.h>
#include <stdlib.h>

#include "cache.h"
#include "money_to_text.h"
#include "memoize.h"

// to do
/*
1. clean up all files (comments, variable names, etc. )
2. finish tests.sh
3. finish makefile
4. finish readme
5. push to github
*/

int main() {
    init_memoization();

    Cache *cache = load_cache_module(NULL);
    if (!cache) {
        fprintf(stderr, "Failed to load cache module\n");
        return EXIT_FAILURE;
    }

    cache->set_provider_func(NULL);
    cache->reset_statistics();
    cache->cache_cleanup();

    long cents;
    printf("Enter amounts in cents (Ctrl+D to end):\n");
    while (scanf("%ld", &cents) != EOF) {
        money_to_words(cents);
    }

    free(cache);
    return EXIT_SUCCESS;
}
