#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void test_result(const char *func, int a, int b) {
    printf("%s: %s\n", func, (a == b) ? "✅ PASS" : "❌ FAIL");
}

void test_result_str(const char *func, const char *a, const char *b) {
    printf("%s: %s\n", func, (strcmp(a, b) == 0) ? "✅ PASS" : "❌ FAIL");
}

int main(void)
{
    // ===== ft_atoi vs atoi =====
    test_result("ft_atoi", ft_atoi("  -123"), atoi("  -123"));

    // ===== ft_isalpha vs isalpha =====
    test_result("ft_isalpha", ft_isalpha('A'), isalpha('A'));
    test_result("ft_isalpha", ft_isalpha('1'), isalpha('1'));

    // ===== ft_isdigit vs isdigit =====
    test_result("ft_isdigit", ft_isdigit('4'), isdigit('4'));
    test_result("ft_isdigit", ft_isdigit('a'), isdigit('a'));

    // ===== ft_isalnum vs isalnum =====
    test_result("ft_isalnum", ft_isalnum('3'), isalnum('3'));

    // ===== ft_isascii vs isascii =====
    test_result("ft_isascii", ft_isascii(127), isascii(127));
    test_result("ft_isascii", ft_isascii(200), isascii(200));

    // ===== ft_isprint vs isprint =====
    test_result("ft_isprint", ft_isprint('A'), isprint('A'));
    test_result("ft_isprint", ft_isprint(8), isprint(8));

    // ===== ft_tolower vs tolower =====
    test_result("ft_tolower", ft_tolower('A'), tolower('A'));

    // ===== ft_toupper vs toupper =====
    test_result("ft_toupper", ft_toupper('a'), toupper('a'));

    // ===== ft_strlen vs strlen =====
    printf("ft_strlen vs strlen: %s\n", 
        (ft_strlen("libft") == strlen("libft")) ? "✅ PASS" : "❌ FAIL");

    // ===== ft_strdup vs strdup =====
    char *dup1 = ft_strdup("libft");
    char *dup2 = strdup("libft");
    test_result_str("ft_strdup", dup1, dup2);
    free(dup1);
    free(dup2);

    // ===== ft_memcpy vs memcpy =====
    char dst1[10], dst2[10];
    ft_memcpy(dst1, "abc", 4);
    memcpy(dst2, "abc", 4);
    test_result_str("ft_memcpy", dst1, dst2);

    // ===== ft_memset vs memset =====
    ft_memset(dst1, 'A', 3);
    memset(dst2, 'A', 3);
    test_result_str("ft_memset", dst1, dst2);

    // ===== ft_strchr vs strchr =====
    test_result_str("ft_strchr", ft_strchr("libft", 'f'), strchr("libft", 'f'));

    // ===== ft_strrchr vs strrchr =====
    test_result_str("ft_strrchr", ft_strrchr("hello hello", 'l'), strrchr("hello hello", 'l'));

    // ===== ft_strncmp vs strncmp =====
    test_result("ft_strncmp", ft_strncmp("abc", "abd", 2), strncmp("abc", "abd", 2));

    // ===== ft_memcmp vs memcmp =====
    test_result("ft_memcmp", ft_memcmp("123", "123", 3), memcmp("123", "123", 3));

    // ===== ft_strnstr vs strstr (custom fallback) =====
    const char *big = "Find the needle in this haystack";
    const char *little = "needle";
    char *res1 = ft_strnstr(big, little, 30);
    char *res2 = strstr(big, little); // not exactly same, but good comparison
    printf("ft_strnstr: %s\n", res1);
    printf("   strstr: %s\n", res2);

    return 0;
}

