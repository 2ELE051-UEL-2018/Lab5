#include <string.h>
#include "gtest/gtest.h"

extern "C" {
	const char* strstr2(const char* str1, const char* str2);
}

TEST(strstr2, StringVaziaBuscaUmCaractere)
{
	char* string1 = "";
	char* string2 = "a";
	ASSERT_EQ(strstr(string1, string2), strstr2(string1, string2));
}

TEST(strstr2, StringVaziaBuscaStringVazia)
{
	char* string1 = "";
	char* string2 = "";
	ASSERT_EQ(strstr(string1, string2), strstr2(string1, string2));
}

TEST(strstr2, StringUmCaractereBuscaOutroCaractere)
{
	char* string1 = "a";
	char* string2 = "b";
	ASSERT_EQ(strstr(string1, string2), strstr2(string1, string2));
}

TEST(strstr2, StringUmCaractereBuscaMesmoCaractere)
{
	char* string1 = "a";
	char* string2 = "a";
	ASSERT_EQ(strstr(string1, string2), strstr2(string1, string2));
}

TEST(strstr2, StringUmCaractereBuscaStringVazia)
{
	char* string1 = "a";
	char* string2 = "";
	ASSERT_EQ(strstr(string1, string2), strstr2(string1, string2));
}

TEST(strstr2, StringUmCaractereBuscaStringDoisCaracteres)
{
	char* string1 = "a";
	char* string2 = "ab";
	ASSERT_EQ(strstr(string1, string2), strstr2(string1, string2));
}

TEST(strstr2, StringDoisCaracteresDiferentesBuscaPrimeiroCaractere)
{
	char* string1 = "ab";
	char* string2 = "a";
	ASSERT_EQ(strstr(string1, string2), strstr2(string1, string2));
}

TEST(strstr2, StringDoisCaracteresDiferentesBuscaSegundoCaractere)
{
	char* string1 = "ab";
	char* string2 = "b";
	ASSERT_EQ(strstr(string1, string2), strstr2(string1, string2));
}

TEST(strstr2, StringDoisCaracteresDiferentesBuscaCaractereInexistente)
{
	char* string1 = "ab";
	char* string2 = "c";
	ASSERT_EQ(strstr(string1, string2), strstr2(string1, string2));
}

TEST(strstr2, StringDoisCaracteresDiferentesBuscaDoisCaracteresPrimeiroDiferente)
{
	char* string1 = "ab";
	char* string2 = "cb";
	ASSERT_EQ(strstr(string1, string2), strstr2(string1, string2));
}

TEST(strstr2, StringDoisCaracteresDiferentesBuscaDoisCaracteresSegundoDiferente)
{
	char* string1 = "ab";
	char* string2 = "ac";
	ASSERT_EQ(strstr(string1, string2), strstr2(string1, string2));
}

TEST(strstr2, StringTresCaracteresBuscaDoisCaracteresAlarmeFalso)
{
	char* string1 = "aab";
	char* string2 = "ab";
	ASSERT_EQ(strstr(string1, string2), strstr2(string1, string2));
}

TEST(strstr2, StringSeisCaracteresBuscaTresCaracteresDoisAlarmesFalsos)
{
	char* string1 = "aababc";
	char* string2 = "abc";
	ASSERT_EQ(strstr(string1, string2), strstr2(string1, string2));
}

TEST(strstr2, StringSeisCaracteresBuscaStringFaltandoUltimoCaractere)
{
	char* string1 = "aababc";
	char* string2 = "abcd";
	ASSERT_EQ(strstr(string1, string2), strstr2(string1, string2));
}

TEST(strstr2, StringDezCaracteresBuscaStringCincoCaracteresNoMeio)
{
	char* string1 = "abcdefghij";
	char* string2 = "defg";
	ASSERT_EQ(strstr(string1, string2), strstr2(string1, string2));
}
