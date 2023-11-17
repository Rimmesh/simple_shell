#include "shell.h"
/**
 * *_memset - fill a bloc of memory with byte
 * @s: pointer to memory
 * @b; byte that fills *s
 * @n: amount of byte to fill
 * Return: s
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;
for (i = 0; i < n; i++)
s[i] = b;
return (s);
}
/*
 * _realloc - reallocates bloc of memory
 * @ptr: pointer to prev allocatted memory
 * @old_size: size of prev block
 * @new_size: size of new block
 * Return: pointer to old block
 */
void *_realloc(void *ptr, unsigned int old_size,
		unsigned int new_size)
{
char *pt;
if (!ptr)
return (malloc(new_size));
if (!new_size)
return (ptr);
if (new_size == old_size)
return (ptr);
pt = malloc(new_size);
if (!p)
return (NULL);
old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
pt[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (pt);
/**
 * ffree - frees string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
char **a = pp;
if (!pp)
return;
while (*pp)
free(*pp++);
free(a);
}
