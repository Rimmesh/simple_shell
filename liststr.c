#include "shell.h"
/**
 * add_nod - adds node to start of list
 * @head: adress of pointer to head of list
 * @str: string of node
 * @num: node index
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
list_t *new_head;
if (!head)
return (NULL);
new_head = malloc(sizeof(list_t));
if (!new_head)
return (NULL);
_memset((void *)new_head, 0, sizeof(list_t));
new_head->num = num;
if (str)
{
new_head->str = _strdup(str);
if (!new_head->str)
{
free(new_head);
return (NULL);
}
}
new_head->next = *head;
*head = new_head;
return (new_head);
}
/**
 * add_node_end - adds node to end of list
 * @head: adress of pointer to head of list
 * @str: string of node
 * @num: node index
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
list_t *new_node, *node;
if (!head)
return (NULL);
node = *head;
new_node = malloc(sizeof(list_t));
if (!new_node)
return (NULL);
_memset((void *)new_node, 0, sizeof(list_t));
new_node->num = num;
if (str)
{
new_node->str = _strdup(str);
if (!new_node->str)
{
free(new_node);
return (NULL);
}
}
if (node)
{
while (node->next)
node = node->next;
noe->next = new_node;
}
else
*head = new_node;
return (new_node);
}
{
free(new_node);
return (NULL);
}
}
if (node)
{
while (node->next)
node = node->next;
noe->next = new_node;
}
else
*head = new_node;
return (new_node);
}
{
free(new_node);
return (NULL);
}
}
if (node)
{
while (node->next)
node = node->next;
noe->next = new_node;
}
else
*head = new_node;
return (new_node);
}
{
free(new_node);
return (NULL);
}
}
if (node)
{
while (node->next)
node = node->next;
noe->next = new_node;
}
else
*head = new_node;
return (new_node);
}
/**
 *  free_list - frees nodes of list
 *  @head_ptr: pointer to head node
 */
void free_list(list_t **head_ptr)
{
list_t *node, *next_node, *head;
if (!head_ptr || !*head_ptr)
return;
head = *head_ptr;
node = head;
while (node)
{
next_node = node->next;
free(node->str);
free(node);
node = next_node;
}
*head_ptr = NULL;
}
/**
 * delete_node_at_index - deletes node at index
 * @head: adress of pointer of first node
 * @index; index of node
 * Return: 0 if failled and 1 if success
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
list_t *node, *prev_node;
unsigned int j = 0;
if (!head || !*head)
return (0);
if (!index)
{
node = *head;
*head = (*head)->next;
free(node->str);
free(node);
return (1);
}
node = *head;
while (node)
{
if (j == index)
{
prev_node->next = node->next;
free(node->str);
free(node);
return (1);
}
j++;
prev_node = node;
node = node->next;
}
return (0);
}
/**
 * print_list_str - prints string element of list
 * @h: pointer of first node
 * Return: size of linked list
 */
size_t print_list_str(const list_t *h)
{
size_t i = 0;
while (h)
{
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
i++;
}
return (i);
}
