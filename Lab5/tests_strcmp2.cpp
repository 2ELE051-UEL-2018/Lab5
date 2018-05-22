#include <string.h>
#include "gtest/gtest.h"

extern "C" {
	int strcmp2(const char* str1, const char* str2);
}

TEST(strcmp2, StringsVazias)
{
	ASSERT_EQ(strcmp("", ""), strcmp2("", ""));
}

TEST(strcmp2, StringsUmCaractereIguais)
{
	ASSERT_EQ(strcmp("a", "a"), strcmp2("a", "a"));
}

TEST(strcmp2, StringsUmCaractereString1Maior)
{
	ASSERT_EQ(strcmp("b", "a"), strcmp2("b", "a"));
}

TEST(strcmp2, StringsUmCaractereString1Menor)
{
	ASSERT_EQ(strcmp("a", "b"), strcmp2("a", "b"));
}

TEST(strcmp2, StringsDoisCaracteresIguais)
{
	ASSERT_EQ(strcmp("aa", "aa"), strcmp2("aa", "aa"));
}

TEST(strcmp2, StringsDoisCaracteresPrimeiroCaractereString1Maior)
{
	ASSERT_EQ(strcmp("ba", "aa"), strcmp2("ba", "aa"));
}

TEST(strcmp2, StringsDoisCaracteresPrimeiroCaractereString1Menor)
{
	ASSERT_EQ(strcmp("aa", "ba"), strcmp2("aa", "ba"));
}

TEST(strcmp2, StringsDoisCaracteresSegundoCaractereString1Maior)
{
	ASSERT_EQ(strcmp("aa", "ab"), strcmp2("aa", "ab"));
}

TEST(strcmp2, StringsDoisCaracteresSegundoCaractereString1Menor)
{
	ASSERT_EQ(strcmp("ab", "aa"), strcmp2("ab", "aa"));
}

TEST(strcmp2, StringsDezCaracteresIguais)
{
	ASSERT_EQ(strcmp("abcdefghij", "abcdefghij"), strcmp2("abcdefghij", "abcdefghij"));
}

TEST(strcmp2, StringsDezCaracteresUltimoCaractereString1Maior)
{
	ASSERT_EQ(strcmp("abcdefghik", "abcdefghij"), strcmp2("abcdefghik", "abcdefghij"));
}

TEST(strcmp2, StringsDezCaracteresUltimoCaractereString1Menor)
{
	ASSERT_EQ(strcmp("abcdefghia", "abcdefghij"), strcmp2("abcdefghia", "abcdefghij"));
}