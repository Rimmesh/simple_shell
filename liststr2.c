#include "shell.h"
/**
 * list_len - lenght of list
 * @h: pointer to first node
 * Return: size of list
 */
size_t list_len(const list_t *h)
{
size_t i = 0;
while (h)
{
h = h->next;
i++;
}
return (i);
}
/**
 * list_to_strings - array of string to string list
 * @head: pointer of first node
 * Return: array of string
 */
char **list_to_strings(list_t *head)
{
list_t *node = head;
size_t i = list_len(head), k;
char **strs;
char *dtr;
if (!strs)
return (NULL);
for (i = 0; node; node = node->next; i++)
{
str = malloc(_strlen(node->str) + 1);
if (!str)
{
for (k = 0; k < i; k++)
free(strs[k]);
free(strs);
return (NULL);
}
str = _strcpy(str, node->str);
strs[i] = str;
}
strs[i] = NULL;
return (strs);
}
/**
 * print_list - prints alements of list
 * @h: pointer to first node
 * Return: sizee of list
 */
size_t print_list(const list_t *h)
{
size_t i = 0;
while (h)
{
_puts(convert_number(h->num, 10, 0);
_putchar(':');
_putchar(' ');
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
i++;
}
return (i);
}
/**
 * get_node_index - gets index to node
 * @head: pnter to head of list
 * @node: pnter to node
 * Return: index of node /-1.
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
size_t i = 0;
while (head)
{
if (head == node)
return (i);
head = head->next;
i++;
}
return (-1);
}
/**
 * node_starts_with - returns node that has
 * a string starting with prefix
 * @node: pnter to head of list
 * @prefix: string
 * @c: next char after prefix
 * Return: NULL or match node
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
char *p = NULL;
while (node)
{
p = starts_with(node->str, prefix);
if (p && ((c == -1) || (*p == c)))
return (node);
node = node->next;
}
return (NULL);
}
