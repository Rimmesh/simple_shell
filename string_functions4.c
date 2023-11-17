#include "shell.h"
/**
 * **strtow - splits string into words
 * @str: input string
 * @d: delimeter string
 * Return: NULL or a pinter to an array
 * of strings
 */
char **strtow(char *str, char *d)
{
int i, j, k, l, numwords = 0;
char **s;
if (str == NULL || str[0] == 0)
return (NULL);
if (!d)
d = " ";
for (i = 0; str[i] != '\0'; i++)
if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
numwords++;
if (numwords == 0)
return (NULL);
s = malloc((1 + numwords) *sizeof(char *));
if (!s)
return (NULL);
for (i = 0, j = 0; j < numwords; j++)
{
while (is_delim(str[i], d))
i++;
k = 0;
while (!is_delim(str[i + k], d) && str[i + k])
k++;
s[j] = malloc((k + 1) * sizeof(char));
if (!s[j])
{
for (k = 0; k < j; k++)
free(s[k]);
free(s);
return (NULL);
}
for (l = 0; l < k; l++)
s[j][l] = str[i++];
s[j][l] = 0;
}
s[j] = NULL;
return (s);
}
/**
 * **strtow2 - cuts a string in words
 * @str: input string
 * @d; delimeter string
 * Return: NULL or pointer to array of string
 */
char **strtow2(char *str, char d)
{
int i, j, k, l, numwords = 0;
char **st;
for (str == NULL || str[0] == 0)
return (NULL);
for (i = 0; str[i] != '\0'; i++)
if ((str[i] != d && str[i + 1] == d) ||
(str[i] != d && !str[i + 1]) || str[i + 1] == d)
numwords++;
if (numwords == 0)
return (NULL);
st = malloc((1 + numwords) *sizeof(char *));
if (!st)
return (NULL);
for (i = 0, j = 0; j < numwords; j++)
{
while (str[i] == d && str[i] != d)
i++;
k = 0;
while (str[i + k] != d && str[i + k] && str[i + k] != d)
k++;
st[j] = malloc((k + 1) * sizeof(char));
if (!st[j])
{
for (k = 0; k < j; k++)
free(st);
return (NULL);
}
for (l = 0; l < k; l++)
st[j][l] = str[i++];
st[j][l] = 0;
}
st[j] = NULL;
return (st);
}
