#ifndef AUX_TEST_FUNCTIONS_H
#define AUX_TEST_FUNCTIONS_H

#include <stddef.h>

void testStrcpyApenasRetorno(char* dst, const char* src, char* (*myStrcpy)(char*, const char*));
void testStrcpyCompleto(char* dst, const char* src, char* (*myStrcpy)(char*, const char*));
void testStrcat(const char* expected, char* str1, const char *str2, char* (*myStrcat)(char*, const char*));
void testStrncat(const char* expected, char* str1, const char *str2, size_t num, char* (*myStrncat)(char*, const char*, size_t));
void testMemcmp(const void* ptr1, const void* ptr2, size_t num, int(*myMemcmp)(const void*, const void*, size_t));
void testMemcpyApenasRetorno(void* ptr1, const void* ptr2, size_t num, void*(*myMemcpy)(void*, const void*, size_t));
void testMemcpyCompleto(void* ptr1, const void* ptr2, size_t num, void*(*myMemcpy)(void*, const void*, size_t));
void testMemsetApenasRetorno(void* ptr, char value, size_t num, void*(*myMemset)(void* ptr, char value, size_t num));
void testMemsetCompleto(void* ptr, char value, size_t num, void*(*myMemset)(void* ptr, char value, size_t num));

#endif // AUX_TEST_FUNCTIONS_H