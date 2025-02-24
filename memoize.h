#ifndef MEMOIZE_H
#define MEMOIZE_H

#define MAX_MEMO 1000000000 
#define NOT_PRESENT -1

void init_memoization();
long get_memoized_value(long num);
void set_memoized_value(long num);

#endif // MEMOIZE_H
