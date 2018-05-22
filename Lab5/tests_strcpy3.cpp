#include <string.h>
#include "gtest/gtest.h"
#include "auxTestFunctions.h"

extern "C" {
	char* strcpy3(char* dst, const char* src);
}

TEST(strcpy3, StringVaziaApenasRetorno)
{
	const char expected[] = "";
	char str[sizeof(expected)];

	testStrcpyApenasRetorno(str, expected, strcpy3);
}

TEST(strcpy3, StringVaziaCompleto)
{
	const char expected[] = "";
	char str[sizeof(expected)];

	testStrcpyCompleto(str, expected, strcpy3);
}

TEST(strcpy3, StringUmCaractere)
{
	const char expected[] = "a";
	char str[sizeof(expected)];

	testStrcpyCompleto(str, expected, strcpy3);
}

TEST(strcpy3, StringUmCaractereNaoUltrapassaFimDaString)
{
	const char expected[] = { 'a', '\0', 'b' };
	char str[] = { 0x13, 0x37, 0x04 };

	testStrcpyCompleto(str, expected, strcpy3);
	ASSERT_EQ(0x04, str[2]);
}

TEST(strcpy3, StringCincoCaracteres)
{
	const char expected[] = "abcde";
	char str[sizeof(expected)];

	testStrcpyCompleto(str, expected, strcpy3);
}

TEST(strcpy3, StringDezCaracteres)
{
	const char expected[] = "abcdefghij";
	char str[sizeof(expected)];

	testStrcpyCompleto(str, expected, strcpy3);
}