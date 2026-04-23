/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: mosimon <morgane.simon@learner.42.tech>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/11 08:22:38 by mosimon          #+#    #+#              */
/*   Updated: 2026/04/22 13:30:22 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <string.h>
#include <ctype.h>

void	test_strlen(void)
{
	printf("---STRLEN---\n");
	printf("%zu vs %zu\n", ft_strlen("hello"), strlen("hello"));
	printf("%zu vs %zu\n\n", ft_strlen(""), strlen(""));
}

void	test_istype(void)
{
	printf("---IS-TYPE---\n");
	printf("'a' is_alpha: %d vs %d\n", ft_isalpha('a'), isalpha('a') != 0);
	printf("'0' is_alpha: %d vs %d\n", ft_isalpha('0'), isalpha('0') != 0);
	printf("'a' is_alnum: %d vs %d\n", ft_isalnum('a'), isalnum('a') != 0);
	printf("'0' is_alnum: %d vs %d\n", ft_isalnum('0'), isalnum('0') != 0);
	printf("'a' is_digit: %d vs %d\n", ft_isdigit('a'), isdigit('a') != 0);
	printf("'0' is_digit: %d vs %d\n", ft_isdigit('0'), isdigit('0') != 0);
	printf("'a' is_ascii: %d vs %d\n", ft_isascii('a'), isascii('a') != 0);
	printf("[SPACE] is_ascii: %d vs %d\n", ft_isascii(' '), isascii(' ') != 0);
	printf("'a' is_print: %d vs %d\n", ft_isprint('a'), isprint('a') != 0);
	printf("[CARRIAGE RETURN] is_print: %d vs %d\n\n", ft_isprint(24), isprint(24) != 0);
}

void	test_str(void)
{
	char dst1[10];
	char dst2[10];
	size_t r1 = ft_strlcpy(dst1, "hello", 6);
	size_t r2 = strlcpy(dst2, "hello", 6);

	printf("---STR---\n");
	printf("strlcpy res: %zu vs %zu\n", r1, r2);
	printf("dst1 = %s\n", dst1);
	printf("dst2 = %s\n", dst2);
	printf("strncmp: %d vs %d\n", ft_strncmp("hi", "hello", 2), strncmp("hi", "hello", 2));
	printf("strncmp: %d vs %d\n\n", ft_strncmp("hi", "hi", 2), strncmp("hi", "hi", 2));
}

void	test_atoi_itoa(void)
{
	printf("---ATOI---\n");
	printf("   -42: %d vs %d\n", ft_atoi("   -42"), atoi("   -42"));
	printf("-2147483648: %d vs %d\n\n", ft_atoi("-2147483648"), atoi("-2147483648"));
	printf("---ITOA---\n");
	char *s = ft_itoa(-2147483648);
	printf("ft_itoa: %s\n\n", s);
}

void	test_memset(void)
{
	char s1[10] = "hello";
	char s2[10] = "hello";
	ft_memset(s1 + 2, 'X', 4);
	memset(s2 + 2, 'X', 4);
	printf("---MEMSET---\n");
	printf("ft: [%s]\n", s1);
	printf("og: [%s]\n\n", s2);
}

void	test_bzero(void)
{
	char s1[10] = "abcde";
	char s2[10] = "abcde";
	ft_bzero(s1 + 2, 3);
	ft_bzero(s2 + 2, 3);
	printf("---BZERO---\n");
	int i = 0;
	printf("ft: ");
	while (i < 10)
		printf("%d ", s1[i++]);
	i = 0;
	printf("\nog: ");
	while (i < 10)
		printf("%d ", s2[i++]);
	printf("\n\n");
}

void	test_memcpy(void)
{
	char src[] = "12345";
	char dst1[10] = "abcde";
	char dst2[10] = "abcde";
	ft_memcpy(dst1, src, 4);
	memcpy(dst2, src, 4);
	printf("---MEMCPY---\n");
	printf("ft: [%s]\n", dst1);
	printf("og: [%s]\n\n", dst2);
}

void	test_memmove(void)
{
	char s1[10] = "abcdef";
	char s2[10] = "abcdef";
	char s3[10] = "abcdef";
	char s4[10] = "abcdef";
	ft_memmove(s1 + 2, s1, 5);
	memmove(s2 + 2, s2, 5);
	ft_memmove(s3, s3 + 2, 5);
	memmove(s4, s4 + 2, 5);
	printf("---MEMMOVE OVERLAP---\n");
	printf("ft: [%s]\n", s1);
	printf("og: [%s]\n", s2);
	printf("---MEMMOVE REVERSE OVERLAP---\n");
	printf("ft: [%s]\n", s3);
	printf("og: [%s]\n\n", s4);
}

void	test_memchr(void)
{
	char str[] = "abcdeab";
	void	*p1;
	void	*p2;
	p1 = ft_memchr(str, 'd', 7);
	p2 = memchr(str, 'd', 7);
	printf("---MEMCHR---\n");
	printf("ft: %s\n", (char *)p1);
	printf("og: %s\n\n", (char *)p2);
	p1 = ft_memchr(str, 'z', 7);
	p2 = memchr(str, 'z', 7);
	printf("ft not found: %s\n", (char *)p1);
	printf("og not found: %s\n\n", (char *)p2);
}

void	test_memcmp(void)
{
	char s1[] = "abcdef";
	char s2[] = "abcdeg";
	char s3[] = "abcdef";
	printf("---MEMCMP---\n");
	printf("ft diff: %d\n", ft_memcmp(s1, s2, 6));
	printf("og diff: %d\n\n", ft_memcmp(s1, s2, 6));
	printf("ft same: %d\n", ft_memcmp(s1, s3, 6));
	printf("og same: %d\n\n", ft_memcmp(s1, s3, 6));
	printf("ft n = 0: %d\n", ft_memcmp(s1, s2, 0));
	printf("og n = 0: %d\n\n", ft_memcmp(s1, s2, 0));
}

void	test_calloc(void)
{
	size_t i;
	unsigned char *p1;
	unsigned char *p2;

	p1 = ft_calloc(5, sizeof(int));
	p2 = calloc(5, sizeof(int));
	printf("---CALLOC---\n");
	printf("ft: ");
	i = 0;
	while (i < 5 * sizeof(int))
		printf("%d", p1[i++]);
	printf("\nog: ");
	i = 0;
	while (i < 5 * sizeof(int))
		printf("%d", p2[i++]);
	printf("\n\n");
	free(p1);
	free(p2);
}

int	main(void)
{
	test_istype();
	test_strlen();
	test_str();
	test_atoi_itoa();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	test_memchr();
	test_memcmp();
	test_calloc();
	return (0);
}
