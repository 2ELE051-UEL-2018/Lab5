#include <string.h>
#include "gtest/gtest.h"

extern "C" {
	int strcmp3(const char* str1, const char* str2);
}

TEST(strcmp3, StringsVazias)
{
	ASSERT_EQ(strcmp("", ""), strcmp3("", ""));
}

TEST(strcmp3, StringsUmCaractereIguais)
{
	ASSERT_EQ(strcmp("a", "a"), strcmp3("a", "a"));
}

TEST(strcmp3, StringsUmCaractereString1Maior)
{
	ASSERT_EQ(strcmp("b", "a"), strcmp3("b", "a"));
}

TEST(strcmp3, StringsUmCaractereString1Menor)
{
	ASSERT_EQ(strcmp("a", "b"), strcmp3("a", "b"));
}

TEST(strcmp3, StringsDoisCaracteresIguais)
{
	ASSERT_EQ(strcmp("aa", "aa"), strcmp3("aa", "aa"));
}

TEST(strcmp3, StringsDoisCaracteresPrimeiroCaractereString1Maior)
{
	ASSERT_EQ(strcmp("ba", "aa"), strcmp3("ba", "aa"));
}

TEST(strcmp3, StringsDoisCaracteresPrimeiroCaractereString1Menor)
{
	ASSERT_EQ(strcmp("aa", "ba"), strcmp3("aa", "ba"));
}

TEST(strcmp3, StringsDoisCaracteresSegundoCaractereString1Maior)
{
	ASSERT_EQ(strcmp("aa", "ab"), strcmp3("aa", "ab"));
}

TEST(strcmp3, StringsDoisCaracteresSegundoCaractereString1Menor)
{
	ASSERT_EQ(strcmp("ab", "aa"), strcmp3("ab", "aa"));
}

TEST(strcmp3, StringsDezCaracteresIguais)
{
	ASSERT_EQ(strcmp("abcdefghij", "abcdefghij"), strcmp3("abcdefghij", "abcdefghij"));
}

TEST(strcmp3, StringsDezCaracteresUltimoCaractereString1Maior)
{
	ASSERT_EQ(strcmp("abcdefghik", "abcdefghij"), strcmp3("abcdefghik", "abcdefghij"));
}

TEST(strcmp3, StringsDezCaracteresUltimoCaractereString1Menor)
{
	ASSERT_EQ(strcmp("abcdefghia", "abcdefghij"), strcmp3("abcdefghia", "abcdefghij"));
}