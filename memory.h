#ifndef MEMORY_H
#define MEMORY_H

void* _malloc(size_t size);
void* _realloc(void* ptr, size_t size);
void _free(void* ptr);
const char* _strdup(const char* str);
const char* _strdup_cat(const char* str, const char* p);
const char* strupper(const char* str);

#endif
