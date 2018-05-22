#include <stddef.h>
#include "gtest/gtest.h"

void testStrcpyApenasRetorno(char* dst, const char* src, char* (*myStrcpy)(char*, const char*))
{
	ASSERT_EQ(dst, myStrcpy(dst, src));
}

void testStrcpyCompleto(char* dst, const char* src, char* (*myStrcpy)(char*, const char*))
{
	testStrcpyApenasRetorno(dst, src, myStrcpy);

	ASSERT_STREQ(src, dst);
}

void testStrcat(const char* expected, char* str1, const char *str2, char* (*myStrcat)(char*, const char*))
{
	ASSERT_EQ(str1, myStrcat(str1, str2));

	ASSERT_STREQ(expected, str1);
}

void testStrncat(const char* expected, char* str1, const char *str2, size_t num, char* (*myStrncat)(char*, const char*, size_t))
{
	ASSERT_EQ(str1, myStrncat(str1, str2, num));

	ASSERT_STREQ(expected, str1);
}

void testMemcmp(const void* ptr1, const void* ptr2, size_t num, int(*myMemcmp)(const void*, const void*, size_t))
{
	int memcmpResult = memcmp(ptr1, ptr2, num);
	int myMemcmpResult = myMemcmp(ptr1, ptr2, num);

	ASSERT_TRUE((memcmpResult == 0 && myMemcmpResult == 0) || (memcmpResult > 0 && myMemcmpResult > 0) || (memcmpResult < 0 && myMemcmpResult < 0));
}

void testMemcpyApenasRetorno(void* ptr1, const void* ptr2, size_t num, void*(*myMemcpy)(void*, const void*, size_t))
{
	ASSERT_EQ(ptr1, myMemcpy(ptr1, ptr2, num));
}

void testMemcpyCompleto(void* ptr1, const void* ptr2, size_t num, void*(*myMemcpy)(void*, const void*, size_t))
{
	testMemcpyApenasRetorno(ptr1, ptr2, num, myMemcpy);

	ASSERT_EQ(memcmp(ptr1, ptr2, num), 0);
}

void testMemsetApenasRetorno(void* ptr, char value, size_t num, void*(*myMemset)(void* ptr, char value, size_t num))
{
	ASSERT_EQ(ptr, myMemset(ptr, value, num));
}

void testMemsetCompleto(void* ptr, char value, size_t num, void*(*myMemset)(void* ptr, char value, size_t num))
{
	size_t i;
	char* p = (char*)ptr;

	testMemsetApenasRetorno(ptr, value, num, myMemset);

	for (i = 0; i < num; i++)
		ASSERT_EQ(value, p[i]);
}
