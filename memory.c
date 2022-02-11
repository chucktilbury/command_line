

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void* _malloc(size_t size) {

    void* ptr = malloc(size);
    if(ptr == NULL) {
        fprintf(stderr, "cannot allocate %lu bytes\n", size);
        exit(1);
    }
    memset(ptr, 0, size);

    return ptr;
}

void* _realloc(void* ptr, size_t size) {

    void* nptr = realloc(ptr, size);
    if(nptr == NULL) {
        fprintf(stderr, "cannot reallocate %lu bytes\n", size);
        exit(1);
    }

    return nptr;
}

void _free(void* ptr) {

    if(ptr != NULL)
        free(ptr);
}

const char* _strdup(const char* str) {

    char* buff;

    if(str != NULL) {
        size_t len = strlen(str) + 1;
        buff = _malloc(len);
        memcpy(buff, str, len);
    }
    else {
        buff = _malloc(1);    // not an error
        buff[0] = '\0';
    }

    return buff;
}

const char* _strdup_cat(const char* str, const char* p) {

    size_t len = strlen(str) + strlen(p) + 1;
    char* buff = _malloc(len);
    memcpy(buff, str, strlen(str)+1);
    strcat(buff, p);

    return buff;
}

const char* strupper(const char* str) {

    char* buf = (char*)_strdup(str);

    for(int i = 0; buf[i] != '\0'; i++) {
        if(buf[i] == '.')
            buf[i] = '_';
        else
            buf[i] = toupper(buf[i]);
    }

    return buf;
}
