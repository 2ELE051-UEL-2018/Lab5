#include <string.h>
#include "gtest/gtest.h"

extern "C" {
	const char* strstr3(const char* str1, const char* str2);
}

TEST(strstr3, StringVaziaBuscaUmCaractere)
{
	char* string1 = "";
	char* string2 = "a";
	ASSERT_EQ(strstr(string1, string2), strstr3(string1, string2));
}

TEST(strstr3, StringVaziaBuscaStringVazia)
{
	char* string1 = "";
	char* string2 = "";
	ASSERT_EQ(strstr(string1, string2), strstr3(string1, string2));
}

TEST(strstr3, StringUmCaractereBuscaOutroCaractere)
{
	char* string1 = "a";
	char* string2 = "b";
	ASSERT_EQ(strstr(string1, string2), strstr3(string1, string2));
}

TEST(strstr3, StringUmCaractereBuscaMesmoCaractere)
{
	char* string1 = "a";
	char* string2 = "a";
	ASSERT_EQ(strstr(string1, string2), strstr3(string1, string2));
}

TEST(strstr3, StringUmCaractereBuscaStringVazia)
{
	char* string1 = "a";
	char* string2 = "";
	ASSERT_EQ(strstr(string1, string2), strstr3(string1, string2));
}

TEST(strstr3, StringUmCaractereBuscaStringDoisCaracteres)
{
	char* string1 = "a";
	char* string2 = "ab";
	ASSERT_EQ(strstr(string1, string2), strstr3(string1, string2));
}

TEST(strstr3, StringDoisCaracteresDiferentesBuscaPrimeiroCaractere)
{
	char* string1 = "ab";
	char* string2 = "a";
	ASSERT_EQ(strstr(string1, string2), strstr3(string1, string2));
}

TEST(strstr3, StringDoisCaracteresDiferentesBuscaSegundoCaractere)
{
	char* string1 = "ab";
	char* string2 = "b";
	ASSERT_EQ(strstr(string1, string2), strstr3(string1, string2));
}

TEST(strstr3, StringDoisCaracteresDiferentesBuscaCaractereInexistente)
{
	char* string1 = "ab";
	char* string2 = "c";
	ASSERT_EQ(strstr(string1, string2), strstr3(string1, string2));
}

TEST(strstr3, StringDoisCaracteresDiferentesBuscaDoisCaracteresPrimeiroDiferente)
{
	char* string1 = "ab";
	char* string2 = "cb";
	ASSERT_EQ(strstr(string1, string2), strstr3(string1, string2));
}

TEST(strstr3, StringDoisCaracteresDiferentesBuscaDoisCaracteresSegundoDiferente)
{
	char* string1 = "ab";
	char* string2 = "ac";
	ASSERT_EQ(strstr(string1, string2), strstr3(string1, string2));
}

TEST(strstr3, StringTresCaracteresBuscaDoisCaracteresAlarmeFalso)
{
	char* string1 = "aab";
	char* string2 = "ab";
	ASSERT_EQ(strstr(string1, string2), strstr3(string1, string2));
}

TEST(strstr3, StringSeisCaracteresBuscaTresCaracteresDoisAlarmesFalsos)
{
	char* string1 = "aababc";
	char* string2 = "abc";
	ASSERT_EQ(strstr(string1, string2), strstr3(string1, string2));
}

TEST(strstr3, StringSeisCaracteresBuscaStringFaltandoUltimoCaractere)
{
	char* string1 = "aababc";
	char* string2 = "abcd";
	ASSERT_EQ(strstr(string1, string2), strstr3(string1, string2));
}

TEST(strstr3, StringDezCaracteresBuscaStringCincoCaracteresNoMeio)
{
	char* string1 = "abcdefghij";
	char* string2 = "defg";
	ASSERT_EQ(strstr(string1, string2), strstr3(string1, string2));
}
