#include <shell.h>
/**
 * _strcpy - copies string
 * @dest: destination
 * @src: source
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;
if (dest == src || src == 0)
return (dest);
while (src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = 0;
return (dest);
}
/**
 * _strdup - duplicates string
 * @str; string
 *Return: pointer to dup string
 */
char *_strdup(const char *str)
{
int leng = 0;
char *ret;
if (str == NULL)
return (NULL);
while (*str++)
leng++;
ret = malloc(sizeof(char) * (leng + 1));
if (!ret)
return (NULL);
for (leng++; leng--;)
ret[leng] = *--str;
return (ret);
}
/**
 * _puts - prints a string
 * @str: string
 * Return: nothing
 */
void _puts(char *str)
{
int j = 0;
if (!str)
return;
while (str[j] != '\0')
{
_putchar(str[j]);
j++;
}
}
/**
 * _putchar - writes the char to print
 * @c: character
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
static int  i;
static char buf[WRITE_BUF_SIZE]
if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(1, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}
