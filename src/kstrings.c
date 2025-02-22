#include "kstrings.h"
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct kstrings
{
    uint8_t *data;
    uint8_t length;
    uint8_t how_much;
}str_t;

static str_t * create_str(uint8_t len)
{
    str_t * result = malloc(sizeof(str_t));
    result->data = malloc(len);
    result->length = len;
    result->how_much = 0;
    return result;
}

void free_str(str_t *str)
{
    free(str->data);
    free(str);
}

uint8_t str_len(str_t *str)
{
    return str->length;
}

void output_str(str_t *str, FILE *writer){
    fwrite(str->data, sizeof(uint8_t), str->length, writer);
}

str_t * str_dup(const char *text) {
    str_t * result = create_str(strlen_kstring(text));
    memcpy(result->data, text, strlen_kstring(text));
    return result;
}

bool kstr_has_prefix(str_t *str, char *prefix){
    char pref[strlen(prefix)];
    strncpy(str, prefix, strlen(prefix));
    pref[strlen(prefix)-1] = '\0';

    if (strcmp(pref, prefix) == 0)
    {
        return true;
    }
    return false;
}

str_t * str_sum(str_t *str, str_t *summed_str){
    str_t * result = create_str(str->length + summed_str->length);
    if (result == NULL) {
        return NULL;
    }

    memcpy(result->data, str->data, str->length);
    memcpy(result->data + str->length, summed_str->data, summed_str->length);

    result->length = str->length + summed_str->length;
    result->how_much = str->how_much + summed_str->how_much;

    return result;
}

static str_t * strlen_kstring(const char * text){
    size_t length = 0;
    while (*text != '\0')
    {
        length++;
        text++;
    }
    return length;
}

