#include "shell.h"
/**
* is_cmd - sees if excutable command file
* @info: info struct
* @path; path to file
* Return: if true 1, else 0
*/
int is_cmd(info_t *info, char *path)
{
struct stat st;
(void)info;
if (!path || stat(path, &st))
return (0);
if (st.st_mode & S_IFREG)
{
return (1);
}
return (0);
}
/**
* dup_chars - duplicates chars
* @pathstr: path string
* @start: start index
* @stop: stop index
* Return: pointer to new buff
*/
char *dup_chars(char *pathstr, int start, int stop)
{
static char buf[1024];
int i = 0, j = 0;
for (j = 0, i = start; i < stop; i++)
if (pathstr[i] != ':')
buf[j++] = pathstr[i];
buf[j] = 0;
return (buf);
}
/**
* find_path - finds cmd in path string
* @info: info struct
* @pathstr: path string
* @cmd: command
* Return: path of cmd
*/
char *find_path(info_t *info, char *pathstr, char *cmd)
{
int i = 0, curr_pos = 0;
char *path;
if (!pathstr)
return (NULL);
if ((_strlen(cmd) > 2) && starts_with(cmd, ". / "))
{
if (is_cmd(info, cmd))
return (cmd);
}
while (1)
{
if (!pathstr[i] || pathstr[i] == ':')
{
path = dup_chars(pathstr, surr_pos, i);
if (!*path)
_strcat(path, cmd);
else
{
_strcat(path, " / ");
_strcat(path, cmd);
}
if (is_cmd(info, path))
return (path);
if (!pathstr[i])
break;
curr_pos = i;
}
i++;
}
return (NULL);
}
