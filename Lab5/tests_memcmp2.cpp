#include <string.h>
#include "gtest/gtest.h"
#include "auxTestFunctions.h"

extern "C" {
	int memcmp2(const void* ptr1, const void* ptr2, size_t num);
}

TEST(memcmp2, ArraysTamanhoZero)
{
	char v1[1], v2[1];

	testMemcmp(v1, v2, 0, memcmp2);
}

TEST(memcmp2, ArraysTamanho1Iguais)
{
	char v1[1] = { 0 }, v2[1] = { 0 };

	testMemcmp(v1, v2, 1, memcmp2);
}


TEST(memcmp2, ArraysTamanho1PrimeiroMaiorPor1)
{
	char v1[1] = { 1 }, v2[1] = { 0 };

	testMemcmp(v1, v2, 1, memcmp2);
}

TEST(memcmp2, ArraysTamanho1PrimeiroMenorPor1)
{
	char v1[1] = { 0 }, v2[1] = { 1 };

	testMemcmp(v1, v2, 1, memcmp2);
}

TEST(memcmp2, ArraysTamanho1PrimeiroMaiorPor2)
{
	char v1[1] = { 2 }, v2[1] = { 0 };

	testMemcmp(v1, v2, 1, memcmp2);
}

TEST(memcmp2, ArraysTamanho2Iguais)
{
	char v1[2] = { 0, 0 }, v2[2] = { 0, 0 };

	testMemcmp(v1, v2, 2, memcmp2);
}

TEST(memcmp2, ArraysTamanho2PrimeiroMaiorNoPrimeiroCaractere)
{
	char v1[2] = { 2, 0 }, v2[2] = { 0, 0 };

	testMemcmp(v1, v2, 2, memcmp2);
}

TEST(memcmp2, ArraysTamanho2PrimeiroMaiorNoSegundoCaractere)
{
	char v1[2] = { 0, 2 }, v2[2] = { 0, 0 };

	testMemcmp(v1, v2, 2, memcmp2);
}

TEST(memcmp2, ArraysTamanho2SegundoMaiorNoPrimeiroCaractere)
{
	char v1[2] = { 0, 0 }, v2[2] = { 2, 0 };

	testMemcmp(v1, v2, 2, memcmp2);
}

TEST(memcmp2, ArraysTamanho2SegundoMaiorNoSegundoCaractere)
{
	char v1[2] = { 0, 0 }, v2[2] = { 0, 2 };

	testMemcmp(v1, v2, 2, memcmp2);
}

TEST(memcmp2, ArraysTamanho2PrimeiroMaiorNoTerceiroCaractere)
{
	char v1[3] = { 0, 0, 2 }, v2[3] = { 0, 0, 0 };

	testMemcmp(v1, v2, 2, memcmp2);
}