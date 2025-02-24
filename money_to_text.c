#include <stdio.h>
#include <string.h>

#include "money_to_text.h"
#include "memoize.h"

char *units[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", 
    "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
    "sixteen", "seventeen", "eighteen", "nineteen" };

char *tens[] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };


void print_number(long num) {
    if (num < 20) {
        printf("%s", units[num]);
    } else if (num < 100) {
        printf("%s", tens[num / 10 - 2]);
        if (num % 10 != 0) {
            printf(" %s", units[num % 10]);
        }
    } else if (num < 1000) {
        print_number(num / 100);
        printf(" hundred");
        if (num % 100 != 0) {
            printf(" ");
            print_number(num % 100);
        }
    } else {
        if (num == 1000000) {
            printf("one million");
            return;
        }
        if (num == 1000000000) {
            printf("one billion");
            return;
        }

        long values[] = {1000000000, 1000000, 1000};
        char *values_names[] = {"billion", "million", "thousand"};

        for (int indx = 0; indx < 3; indx++) {
            if (num >= values[indx]) {
                print_number(num / values[indx]);
                printf(" %s", values_names[indx]);
                num %= values[indx];

                if (num > 0) {
                    printf(" ");
                }
            }
        }

        if (num > 0) {
            print_number(num);
        }
    }
}


void number_to_words_cached(long num) {
    if (num < 0 || num >= MAX_MEMO) {
        return;
    }

    if (get_memoized_value(num) != NOT_PRESENT) {
        return;
    }

    print_number(num);
    set_memoized_value(num);
}

void money_to_words(long cents) {
    long dollars = cents / 100;
    long remaining_cents = cents % 100;

    printf("%ld = ", cents);

    if (dollars > 0) {
        if (dollars == 1) {
            printf("one dollar");
        } else {
            number_to_words_cached(dollars);
            printf(" dollars");
        }
    } else {
        printf("zero dollars");
    }

    if (remaining_cents > 0) {
        printf(" and ");
        if (remaining_cents == 1) {
            printf("one cent");
        } else {
            number_to_words_cached(remaining_cents);
            printf(" cents");
        }
    } else {
        printf(" and zero cents");
    }
    printf("\n");
}
