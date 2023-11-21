#include<string.h>
#include<stdlib.h>
#include<stdio.h>
struct string_t;
typedef struct string_t {
    char* buffer;
    size_t cap;
} string;

void clear_str(string* str) {
    if (str->buffer != NULL) {
        free(str->buffer);
    }
}
size_t size_str(string* str) {
    if (str->buffer != NULL)
        return strlen(str->buffer);
    return 0;
}
size_t length_str(string* str) {
    if (str->buffer != NULL)
        return strlen(str->buffer);
    return 0;
}
void reserve_str(string* str, int capacity) {
    if (str->buffer == NULL) {
        str->buffer = malloc(capacity);
        str->cap = capacity;
    } else if (str->cap < capacity) {
        str->buffer = realloc(str->buffer, capacity);
        str->cap = capacity;
    }
}
void trim(string* str, size_t len) {
    if (length_str(str) > len) {
        memset(str->buffer + len, 0, 1);
    }
}
void set_length(string* str, size_t len) {
    reserve_str(str, len + 1);
    trim(str, len);
}
string* new_string() {
    string* str = malloc(sizeof(string));
    str->buffer = NULL;
    str->cap = 0;
    return str;
}
string* init_str(string* str, const char* value) {
    set_length(str, strlen(value));
    strcpy(str->buffer, value);
    return str;
}
string* append(string* str, const char* value) {
    set_length(str, strlen(value) + length_str(str));
    strcat(str->buffer, value);
    return str;
}

string* substring(string* str, size_t idx, size_t len) {
    string* res = new_string();
    init_str(res, str->buffer + idx);
    trim(res, len);
    return res;
}
void shrink_to_fit(string* str) {
    size_t len = length_str(str) + 1;
    if (len < str->cap) {
        str->buffer = realloc(str->buffer, len);
        str->cap = len;
    }
}
void print_str(string* str) {
    printf("%s", str->buffer);
}