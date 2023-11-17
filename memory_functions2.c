#include "shell.h"
/**
 * bfree - frees a pointer + returnss the adresse NULL
 * @ptr: adress of pointer
 * Return: 1 in succes , 0 otherwise
 */
int bfree(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
