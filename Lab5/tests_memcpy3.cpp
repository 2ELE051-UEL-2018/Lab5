#include <string.h>
#include "gtest/gtest.h"
#include "auxTestFunctions.h"

extern "C" {
	void* memcpy3(void* dst, const void* src, size_t num);
}

TEST(memcpy3, ArraysTamanhoUmNum1ApenasRetorno)
{
	unsigned char v1[1];
	unsigned char v2[1];

	testMemcpyApenasRetorno(v1, v2, 1, memcpy3);
}

TEST(memcpy3, ArraysTamanhoUmNum1Completo)
{
	unsigned char v1[1] = { 0x13 };
	unsigned char v2[1] = { 0x37 };

	testMemcpyCompleto(v1, v2, 1, memcpy3);
}

TEST(memcpy3, ArraysTamanhoUmNum0)
{
	unsigned char v1[1] = { 0x13 };
	unsigned char v2[1] = { 0x37 };

	testMemcpyCompleto(v1, v2, 0, memcpy3);
	ASSERT_EQ(0x13, v1[0]);
}

TEST(memcpy3, ArraysTamanhoUmNum1NaoUltrapassaFimDoArray)
{
	unsigned char v1[2] = { 0x13, 0x13 };
	unsigned char v2[2] = { 0x37, 0x37 };

	testMemcpyCompleto(v1, v2, 1, memcpy3);
	ASSERT_EQ(0x13, v1[1]);
}

TEST(memcpy3, ArraysTamanhoDoisNum2)
{
	unsigned char v1[2] = { 0x13, 0x13 };
	unsigned char v2[2] = { 0x37, 0x37 };

	testMemcpyCompleto(v1, v2, 2, memcpy3);
}

TEST(memcpy3, ArraysTamanhoCincoNum5)
{
	unsigned char v1[5] = { 0x01, 0x23, 0x45, 0x67, 0x89 };
	unsigned char v2[5] = { 0xFE, 0xDC, 0xBA, 0x98, 0x76 };

	testMemcpyCompleto(v1, v2, 5, memcpy3);
}

TEST(memcpy3, ArraysTamanhoCincoNum3NaoUltrapassaFimDoArray)
{
	unsigned char v1[5] = { 0x01, 0x23, 0x45, 0x67, 0x89 };
	unsigned char v2[5] = { 0xFE, 0xDC, 0xBA, 0x98, 0x76 };

	testMemcpyCompleto(v1, v2, 3, memcpy3);
	ASSERT_EQ(0x67, v1[3]);
	ASSERT_EQ(0x89, v1[4]);
}