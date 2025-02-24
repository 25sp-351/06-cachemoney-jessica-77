#include "memoize.h"

long memo[MAX_MEMO];


void init_memoization() {
    for (long indx = 0; indx < MAX_MEMO; indx++) {
        memo[indx] = NOT_PRESENT;
    }
}
// returns the value of the memoized value at index num
long get_memoized_value(long num) {
    if (num < 0 || num >= MAX_MEMO) {
        return NOT_PRESENT;
    }
    return memo[num];
}
// sets the value of the memoized value at index num to 0
void set_memoized_value(long num) {
    if (num >= 0 && num < MAX_MEMO) {
        memo[num] = 0;
    }
}
