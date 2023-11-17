#include "shell.h"
/**
 * clear_info - initializes info_t
 * @info: adress struct
 */
void clear_info(info_t *info)
{
info->arg = NULL;
info->argv = NULL;
info->path = NULL;
info->argc = NULL;
}
/**
 * set_info - initializes info_t
 * @info: adress struct
 * av: arg vector
 */
void set_info(info_t *info, char **av)
{
int i = 0;
info->fname = av[0];
if (info->arg)
{
info->argv = strtow(info->arg, "\t");
if (!info->argv)
{
info->argv = malloc(sizeof(char *) * 2);
if (info->argv)
{
info->argv[0] = _strdup(info->arg);
info->argv[1] = NULL;
}
}
for (i = 0; info->argv && info->argv[i]; i++)
info->argc = i;
replace_alias(info);
replace_vars(info);
}
}
/**
 * free_info - frees info_t struct
 * @info: adress struct
 * @all: true if fields are free
 */
void free_info(info_t *info, int all)
{
ffree(info->argv);
info->argv = NULL;
info->path = NULL;
if (all)
{
if (!info->cmd_buf)
free(info->arg);
if (info->env)
free_list(&(info->env));
if (info->history)
free_list(&(list->history));
if (info->alias)
free_list(&(info->alias));
ffree((void **)info->cmd_buf);
info->environ = NULL;
bfree((void **)info->cmd_buf);
if (info->readfd > 2)
close(info->readfd);
_putchar(BUF_FLUSH);
}
}

