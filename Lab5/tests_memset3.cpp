#include <string.h>
#include "gtest/gtest.h"
#include "auxTestFunctions.h"

extern "C" {
	void* memset3(void* ptr, char value, size_t num);
}

TEST(memset3, ArrayTamanhoUmNum1ApenasRetorno)
{
	unsigned char v1[1];

	testMemsetApenasRetorno(v1, 'a', 1, memset3);
}

TEST(memset3, ArrayTamanhoUmNum1Completo)
{
	unsigned char v1[1] = { 0x13 };

	testMemsetCompleto(v1, 'a', 1, memset3);
}

TEST(memset3, ArrayTamanhoUmNum1NaoUltrapassaFimDoArray)
{
	unsigned char v1[2] = { 0x13, 0x37 };

	testMemsetCompleto(v1, 'b', 1, memset3);
	ASSERT_EQ(0x37, v1[1]);
}

TEST(memset3, ArrayTamanhoUmNum0NaoUltrapassaFimDoArray)
{
	unsigned char v1[2] = { 0x13 };

	testMemsetCompleto(v1, 'c', 0, memset3);
	ASSERT_EQ(0x13, v1[0]);
}

TEST(memset3, ArrayTamanhoDoisNum2)
{
	unsigned char v1[2] = { 0x13, 0x37 };

	testMemsetCompleto(v1, 'd', 2, memset3);
}

TEST(memset3, ArrayTamanhoDoisNum2NaoUltrapassaFimDoArray)
{
	unsigned char v1[3] = { 0x03, 0x13, 0x37 };

	testMemsetCompleto(v1, 'e', 2, memset3);
	ASSERT_EQ(0x37, v1[2]);
}

TEST(memset3, ArrayTamanhoCincoNum5)
{
	unsigned char v1[5] = { 0x03, 0x01, 0x03, 0x03, 0x07 };

	testMemsetCompleto(v1, 'f', 5, memset3);
}
