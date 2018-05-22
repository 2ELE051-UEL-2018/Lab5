#include <string.h>
#include "gtest/gtest.h"

extern "C" {
	const char* strchr3(const char* str, int chr);
}

TEST(strchr3, StringVaziaBuscaCaractere)
{
	char* string = "";
	ASSERT_EQ(strchr(string, 'a'), strchr3(string, 'a'));
}

TEST(strchr3, StringVaziaBuscaTerminador)
{
	char* string = "";
	ASSERT_EQ(strchr(string, '\0'), strchr3(string, '\0'));
}

TEST(strchr3, StringUmCaractereBuscaOutroCaractere)
{
	char* string = "b";
	ASSERT_EQ(strchr(string, 'a'), strchr3(string, 'a'));
}

TEST(strchr3, StringUmCaractereBuscaMesmoCaractere)
{
	char* string = "a";
	ASSERT_EQ(strchr(string, 'a'), strchr3(string, 'a'));
}

TEST(strchr3, StringUmCaractereBuscaTerminador)
{
	char* string = "a";
	ASSERT_EQ(strchr(string, '\0'), strchr3(string, '\0'));
}

TEST(strchr3, StringDoisCaracteresIguaisBuscaMesmoCaractere)
{
	char* string = "aa";
	ASSERT_EQ(strchr(string, 'a'), strchr3(string, 'a'));
}

TEST(strchr3, StringDezCaracteresBuscaCaractereNoMeio)
{
	char* string = "abcdefghij";
	ASSERT_EQ(strchr(string, 'f'), strchr3(string, 'f'));
}

TEST(strchr3, StringDezCaracteresBuscaCaractereInexistente)
{
	char* string = "abcdefghij";
	ASSERT_EQ(strchr(string, 'k'), strchr3(string, 'k'));
}

TEST(strchr3, StringDezCaracteresBuscaTerminador)
{
	char* string = "abcdefghij";
	ASSERT_EQ(strchr(string, '\0'), strchr3(string, '\0'));
}