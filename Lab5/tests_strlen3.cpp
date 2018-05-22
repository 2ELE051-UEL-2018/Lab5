#include <string.h>
#include "gtest/gtest.h"

extern "C" {
	size_t strlen3(const char* str);
}

TEST(strlen3, StringVazia)
{
	ASSERT_EQ(strlen(""), strlen3(""));
}

TEST(strlen3, StringUmCaractere)
{
	ASSERT_EQ(strlen("a"), strlen3("a"));
}

TEST(strlen3, StringDoisCaracteres)
{
	ASSERT_EQ(strlen("ab"), strlen3("ab"));
}

TEST(strlen3, StringCincoCaracteres)
{
	ASSERT_EQ(strlen("abcd "), strlen3("abcd "));
}

TEST(strlen3, StringDezCaracteres)
{
	ASSERT_EQ(strlen("abcdefghi\n"), strlen3("abcdefghi\n"));
}