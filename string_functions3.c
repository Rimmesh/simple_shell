#include <shell.h>
/**
 * *_strncpy - copies string
 * @dest: destination string
 * @src: source string
 * @n: number of characters to be copied
 * Return; concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
int i, j;
char *s = dest;
j = 0;
while (src[j] != '\0' && j < n - 1)
{
dest[j] = src[j];
j++;
}
if (j < n)
{
i = j;
while (i < n)
{
dest[i] = '\0';
i++;
}
}
return (s);
}
/**
 *  _strchr - locates a char in a string
 *  @s: string
 *  @c: characrter
 *  Return: pointer to memory area s
 */
char *_strchr(char *s, char c)
{
do {
if (*s == c)
return (s);
} while (*s++ != '\0';
return (NULL);
}
/**
 * _strncat - concatenates 2 strings
 * @dest : 1st string
 * @src; 2nd string
 * @n: number of bytes to use
 * Return: concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
int j, i;
char *s = dest;
j = 0;
i = 0;
while (dest[i] != '\0')
i++;
while (src[j] != '\0' && j < n)
{
dest[i] = src[j];
i++;
j++;
}
if (j < n)
dest[i] = '\0';
return (s);
}
