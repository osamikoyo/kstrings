#ifndef KSTRINGS_H
#define KSTRINGS_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct kstrings {
    uint8_t *data;
    uint8_t length;
    uint8_t how_much;
} str_t;

void free_str(str_t *str);

uint8_t str_len(str_t *str);

void output_str(str_t *str, FILE *writer);

str_t *str_dup(const char *text);

str_t *str_sum(str_t *str, str_t *summed_str);


#endif
