#include <string.h>
#include "gtest/gtest.h"
#include "auxTestFunctions.h"

extern "C" {
	char* strncat2(char* dst, const char* src, size_t num);
}

TEST(strncat2, StringVaziaComStringVaziaNum0)
{
	const char expected[] = "";
	char str1[sizeof(expected)] = "";
	const char str2[] = "";

	testStrncat(expected, str1, str2, 0, strncat2);
}

TEST(strncat2, StringUmCaractereComStringVaziaNum0)
{
	const char expected[] = "a";
	char str1[sizeof(expected)] = "a";
	const char str2[] = "";

	testStrncat(expected, str1, str2, 0, strncat2);
}

TEST(strncat2, StringUmCaractereComStringVaziaNum1)
{
	const char expected[] = "a";
	char str1[sizeof(expected)] = "a";
	const char str2[] = "";

	testStrncat(expected, str1, str2, 1, strncat2);
}

TEST(strncat2, StringVaziaComStringUmCaractereNum1)
{
	const char expected[] = "a";
	char str1[sizeof(expected)] = "";
	const char str2[] = "a";

	testStrncat(expected, str1, str2, 1, strncat2);
}

TEST(strncat2, StringVaziaComStringUmCaractereNum0)
{
	const char expected[] = "";
	char str1[sizeof(expected)] = "";
	const char str2[] = "a";

	testStrncat(expected, str1, str2, 0, strncat2);
}

TEST(strncat2, StringUmCaractereComStringUmCaractereNum1)
{
	const char expected[] = "aa";
	char str1[sizeof(expected)] = "a";
	const char str2[] = "a";

	testStrncat(expected, str1, str2, 1, strncat2);
}

TEST(strncat2, StringUmCaractereComStringUmCaractereNum1NaoUltrapassaFimDaString)
{
	const char expected[] = "aa";
	char str1[] = { 'a', '\0', 0x13, 0x37 };
	const char str2[] = { 'a', '\0', 'b' };

	testStrncat(expected, str1, str2, 1, strncat2);
	ASSERT_EQ(0x37, str1[3]);
}

TEST(strncat2, StringUmCaractereComStringUmCaractereNum0)
{
	const char expected[] = "a";
	char str1[sizeof(expected)] = "a";
	const char str2[] = "a";

	testStrncat(expected, str1, str2, 0, strncat2);
}

TEST(strncat2, StringCincoCaracteresComStringVaziaNum0)
{
	const char expected[] = "abcde";
	char str1[sizeof(expected)] = "abcde";
	const char str2[] = "";

	testStrncat(expected, str1, str2, 0, strncat2);
}

TEST(strncat2, StringVaziaComStringCincoCaracteresNum5)
{
	const char expected[] = "abcde";
	char str1[sizeof(expected)] = "";
	const char str2[] = "abcde";

	testStrncat(expected, str1, str2, 5, strncat2);
}

TEST(strncat2, StringVaziaComStringCincoCaracteresNum3)
{
	const char expected[] = "abc";
	char str1[sizeof(expected)] = "";
	const char str2[] = "abcde";

	testStrncat(expected, str1, str2, 3, strncat2);
}

TEST(strncat2, StringVaziaComStringCincoCaracteresNum3NaoUltrapassaFimDaString)
{
	const char expected[] = "abc";
	char str1[] = { '\0', 0x01, 0x03, 0x03, 0x07 };
	const char str2[] = "abcde";

	testStrncat(expected, str1, str2, 3, strncat2);
	ASSERT_EQ(0x07, str1[4]);
}

TEST(strncat2, StringCincoCaracteresComStringQuatroCaracteresNum4)
{
	const char expected[] = "abcdefghi";
	char str1[sizeof(expected)] = "abcde";
	const char str2[] = "fghi";

	testStrncat(expected, str1, str2, 4, strncat2);
}

TEST(strncat2, StringCincoCaracteresComStringQuatroCaracteresNum10)
{
	const char expected[] = "abcdefghi";
	char str1[sizeof(expected)] = "abcde";
	const char str2[] = "fghi";

	testStrncat(expected, str1, str2, 10, strncat2);
}
TEST(strncat2, StringCincoCaracteresComStringQuatroCaracteresNum1)
{
	const char expected[] = "abcdef";
	char str1[sizeof(expected)] = "abcde";
	const char str2[] = "fghi";

	testStrncat(expected, str1, str2, 1, strncat2);
}