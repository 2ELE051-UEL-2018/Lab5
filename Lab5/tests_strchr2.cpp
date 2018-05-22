#include <string.h>
#include "gtest/gtest.h"

extern "C" {
	const char* strchr2(const char* str, int chr);
}

TEST(strchr2, StringVaziaBuscaCaractere)
{
	char* string = "";
	ASSERT_EQ(strchr(string, 'a'), strchr2(string, 'a'));
}

TEST(strchr2, StringVaziaBuscaTerminador)
{
	char* string = "";
	ASSERT_EQ(strchr(string, '\0'), strchr2(string, '\0'));
}

TEST(strchr2, StringUmCaractereBuscaOutroCaractere)
{
	char* string = "b";
	ASSERT_EQ(strchr(string, 'a'), strchr2(string, 'a'));
}

TEST(strchr2, StringUmCaractereBuscaMesmoCaractere)
{
	char* string = "a";
	ASSERT_EQ(strchr(string, 'a'), strchr2(string, 'a'));
}

TEST(strchr2, StringUmCaractereBuscaTerminador)
{
	char* string = "a";
	ASSERT_EQ(strchr(string, '\0'), strchr2(string, '\0'));
}

TEST(strchr2, StringDoisCaracteresIguaisBuscaMesmoCaractere)
{
	char* string = "aa";
	ASSERT_EQ(strchr(string, 'a'), strchr2(string, 'a'));
}

TEST(strchr2, StringDezCaracteresBuscaCaractereNoMeio)
{
	char* string = "abcdefghij";
	ASSERT_EQ(strchr(string, 'f'), strchr2(string, 'f'));
}

TEST(strchr2, StringDezCaracteresBuscaCaractereInexistente)
{
	char* string = "abcdefghij";
	ASSERT_EQ(strchr(string, 'k'), strchr2(string, 'k'));
}

TEST(strchr2, StringDezCaracteresBuscaTerminador)
{
	char* string = "abcdefghij";
	ASSERT_EQ(strchr(string, '\0'), strchr2(string, '\0'));
}