#include <string.h>
#include "gtest/gtest.h"

extern "C" {
	size_t strlen2(const char* str);
}

TEST(strlen2, StringVazia)
{
	ASSERT_EQ(strlen(""), strlen2(""));
}

TEST(strlen2, StringUmCaractere)
{
	ASSERT_EQ(strlen("a"), strlen2("a"));
}

TEST(strlen2, StringDoisCaracteres)
{
	ASSERT_EQ(strlen("ab"), strlen2("ab"));
}

TEST(strlen2, StringCincoCaracteres)
{
	ASSERT_EQ(strlen("abcd "), strlen2("abcd "));
}

TEST(strlen2, StringDezCaracteres)
{
	ASSERT_EQ(strlen("abcdefghi\n"), strlen2("abcdefghi\n"));
}