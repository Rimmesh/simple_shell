#include "shell.h"
/**
 * _strlen - the lenght of string
 * @s : string
 * Return : lenght od string (integer)
 */
int _strlen(char *s)
{
int j = 0;
if (!s)
return (0);
while (*s++)
j++;
return (j);
}
/**
 * _strcmp - comparison of 2 strings.
 * @s1: 1st string
 * @s2: 2nd string
 * Return: Zero if s1=s2,Positive if s1>s2
 * Negative if s1<s2
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}
/**
 * _strcat - concatenates the destination string
 * and the source string
 * @dest: destination string
 * @src: source string
 * Return: pointer to destination string.
 */
char *_strcat(char *dest, char *src)
{
char *RET = dest;
while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (RET);
}
/**
 * starts_with - sees if needle starts with haystack
 * @haystack: string to search
 * @needle: substring to find
 * Return: NULL or addresse of next char (of haystack)
 */
char *start_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

