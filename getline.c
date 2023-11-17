#include "shell.h"
/**
 * input_buf - buffers commands taht are chained
 * @info: parameter struct
 * @buf: buffer s address
 * @len: len var s address
 * Return: byte that are read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
ssize_t r = 0;
size_t len_p = 0;
if (!*len) /* if the buffer is empty fill it */
{
free(*buf);
*buf = NULL;
signal(SIGINT, sigintHandler);
#if USE_GETLINE
r = getline(buf, &len_p, stdin);
#else
r = _getline(info, buf, &len_p);
#endif
if (r > 0)
{
if ((*buf)[r - 1] == '\n')
{
(*buf)[r - 1] = '\0';
r--;
}
info->linecount_flag = 1;
remove_comments(*buf);
build_history_list(info, *buf, info->histcount++);
{
*len = r;
info->cmd_buf = buf;
}
}
}
return (r);
}
/**
 * get_input - gets line -the new line
 * @info: parameter struct
 * Return: bytes that are read
 */
ssize_t get_input(info_t *info)
{
static char *buf;
static size_t i, j, len;
ssize_t r = 0;
char **buf_p = &(info->arg), *p;
_putchar(BUF_FLUSH);
r = input_buf(info, &buf, &len);
if (r == -1)
return (-1);
if (len) /*commands still in chain buffer*/
{
j = i; /* init j to buf position */
p = buf + i; /* get pointer for return */
check_chain(info, buf, &j, i, len);
while (j < len)
{
if (is_chain(info, buf, &j))
break;
j++;
}
i = j + 1; /* increment */
if (i >= len) /* if reachs the end of buffer */
{
i = len = 0; /* reset */
info->cmd_buf_type = CMD_NORM;
}
*buf_p = p; /* pass pointer back to current position */
return (_strlen(p)); /*length of current command */
}
*buf_p = buf; /* pass back buffer from _getline() */
return (r); /* length of buffer*/
}
/**
 * read_buf - reads buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
ssize_t r = 0;
if (*i)
return (0);
r = read(info->readfd, buf, READ_BUF_SIZE);
if (r >= 0)
*i = r;
return (r);
}
/**
 * _getline - gets upcoming line to input from STDIN
 * @info: parameter struct
 * @ptr: address of ptr to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer or NULL
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
static char buf[READ_BUF_SIZE];
static size_t i, len;
size_t k;
ssize_t r = 0, s = 0;
char *p = NULL, *new_p = NULL, *c;
p = *ptr;
if (p && length)
s = *length;
if (i == len)
i = len = 0;
r = read_buf(info, buf, &len);
if (r == -1 || (r == 0 && len == 0))
return (-1);
c = _strchr(buf + i, '\n');
k = c ? 1 + (unsigned int)(c - buf) : len;
new_p = _realloc(p, s, s ? s + k : k + 1);
if (!new_p)
return (p ? free(p), -1 : -1);
if (s)
_strncat(new_p, buf + i, k - i);
else
_strncpy(new_p, buf + i, k - i + 1);
s += k - i;
i = k;
p = new_p;
if (length)
*length = s;
*ptr = p;
return (s);
}
/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: signal number
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
_puts("\n");
_puts("$ ");
_putchar(BUF_FLUSH);
}
