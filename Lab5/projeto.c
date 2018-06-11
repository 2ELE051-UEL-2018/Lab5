#include <stddef.h>
#include <math.h>

int comparaDouble(double a, double b, double limiar)
{
	if (fabs(a - b) > limiar)
	{
		if (a > b)
			return 1;
		else
			return -1;
	}
	else
		return 0;
}

int resolveEq2Grau(double a, double b, double c, double* x1, double* x2)
{
	double delta = b * b - 4.0*a*c;

	if (comparaDouble(a, 0.0, 1e-10) == 0)
		return -1;
	else
	{
		int sinalDelta = comparaDouble(delta, 0.0, 1e-10);

		switch (sinalDelta)
		{
			case -1:
				return 0;

			case 0:
				*x1 = -b / (2.0*a);
				return 1;

			case 1:
				*x1 = (-b - sqrt(delta)) / (2 * a);
				*x2 = (-b + sqrt(delta)) / (2 * a);
				return 2;

			default:
				return -1;
		}
	}
}

size_t strlen2(const char* str)
{
	size_t res = 0;

	while (*str++)
		res++;

	return res;
}

size_t strlen3(const char* str)
{
	size_t res = 0;

	while (str[res++] != '\0')
	{
	}

	return res - 1;
}

const char* strchr2(const char* str, int chr)
{
	while (*str != chr && *str != '\0')
		str++;

	if (*str == chr)
		return str;
	else
		return NULL;
}

const char* strchr3(const char* str, int chr)
{
	size_t i = 0;

	while (str[i] != chr && str[i] != '\0')
		i++;

	if (str[i] == chr)
		return &str[i];
	else
		return NULL;
}

const char* strstr2(const char* str1, const char* str2)
{
	const char* str2Inicio = str2;
	const char* str1InicioComparacao = str1;
	while (1)
	{
		if (*str2 == '\0')
			return str1InicioComparacao;

		if (*str1 == '\0')
			return NULL;

		if (*str1++ == *str2++)
			continue;

		str1 = ++str1InicioComparacao;
		str2 = str2Inicio;
	}
}

const char* strstr3(const char* str1, const char* str2)
{
	size_t str2Indice = 0;
	size_t str1Indice = 0, str1IndiceInicioComparacao = 0;
	while (1)
	{
		if (str2[str2Indice] == '\0')
			return &str1[str1IndiceInicioComparacao];

		if (str1[str1Indice] == '\0')
			return NULL;

		if (str1[str1Indice++] == str2[str2Indice++])
			continue;

		str1Indice = ++str1IndiceInicioComparacao;
		str2Indice = 0;
	}
}

int strcmp2(const char* str1, const char* str2)
{
	while (*str1 == *str2 && *str1 != '\0' && *str2 != '\0')
	{
		str1++;
		str2++;
	}

	if (*str1 > *str2)
		return 1;
	else if (*str1 < *str2)
		return -1;
	else
		return 0;
}

int strcmp3(const char* str1, const char* str2)
{
	size_t indice = 0;
	while (str1[indice] == str2[indice] && str1[indice] != '\0' && str2[indice] != '\0')
	{
		indice++;
	}

	if (str1[indice] > str2[indice])
		return 1;
	else if (str1[indice] < str2[indice])
		return -1;
	else
		return 0;
}

char* strcpy2(char* dst, const char* src)
{
	char* dstOriginal = dst;

	while ((*dst++ = *src++) != '\0')
	{
	}

	return dstOriginal;
}

char* strcpy3(char* dst, const char* src)
{
	size_t indice = 0;

	while ((dst[indice] = src[indice]) != '\0')
	{
		indice++;
	}

	return dst;
}

char* strcat2(char* dst, const char* src)
{
	char* dstOriginal = dst;

	while (*dst++ != '\0')
	{
	}

	dst--;

	while ((*dst++ = *src++) != '\0')
	{
	}

	return dstOriginal;
}

char* strcat3(char* dst, const char* src)
{
	size_t indiceDst = 0, indiceSrc = 0;

	while (dst[indiceDst] != '\0')
	{
		indiceDst++;
	}

	while ((dst[indiceDst++] = src[indiceSrc++]) != '\0')
	{
	}

	return dst;
}

char* strncat2(char* dst, const char* src, size_t num)
{
	char* dstOriginal = dst;
	size_t caracteresCopiados;

	while (*dst != '\0')
	{
		dst++;
	}

	for (caracteresCopiados = 0; caracteresCopiados < num; caracteresCopiados++)
	{
		if ((*dst++ = *src++) == '\0')
			return dstOriginal;
	}

	*dst = '\0';

	return dstOriginal;
}

char* strncat3(char* dst, const char* src, size_t num)
{
	size_t indiceDst = 0, indiceSrc = 0;
	size_t caracteresCopiados = 0;

	while (dst[indiceDst] != '\0')
	{
		indiceDst++;
	}


	for (caracteresCopiados = 0; caracteresCopiados < num; caracteresCopiados++, indiceSrc++)
	{
		if ((dst[indiceDst + caracteresCopiados] = src[indiceSrc]) == '\0')
			return dst;
	}

	dst[indiceDst + caracteresCopiados] = '\0';

	return dst;
}

int memcmp2(const void* ptr1, const void* ptr2, size_t num)
{
	const unsigned char* p1 = ptr1;
	const unsigned char* p2 = ptr2;
	size_t i = 0;

	for (i = 0; i < num; i++)
	{
		if (*p1 != *p2)
			return *p1 - *p2;

		p1++;
		p2++;
	}

	return 0;
}

int memcmp3(const void* ptr1, const void* ptr2, size_t num)
{
	const unsigned char* v1 = ptr1;
	const unsigned char* v2 = ptr2;
	size_t i = 0;

	for (i = 0; i < num; i++)
	{
		if (v1[i] != v2[i])
			return v1[i] - v2[i];
	}

	return 0;
}

void* memcpy2(void* dst, const void* src, size_t num)
{
	unsigned char* v1 = dst;
	const unsigned char* v2 = src;
	size_t i;

	for (i = 0; i < num; i++)
		*v1++ = *v2++;

	return dst;
}

void* memcpy3(void* dst, const void* src, size_t num)
{
	unsigned char* v1 = dst;
	const unsigned char* v2 = src;
	size_t i;

	for (i = 0; i < num; i++)
		v1[i] = v2[i];

	return dst;
}

void* memset2(void* ptr, char value, size_t num)
{
	char* p = ptr;
	size_t i;

	for (i = 0; i < num; i++)
		*p++ = value;

	return ptr;
}

void* memset3(void* ptr, char value, size_t num)
{
	char* p = ptr;
	size_t i;

	for (i = 0; i < num; i++)
		p[i] = value;

	return ptr;
}
