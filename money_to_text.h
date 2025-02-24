#ifndef MONEY_TO_TEXT_H
#define MONEY_TO_TEXT_H

#define MAX_MEMO 1000000000
#define NOT_PRESENT -1

void print_number(long num);
void number_to_words_cached(long num);
void money_to_words(long cents);

#endif // MONEY_TO_TEXT_H