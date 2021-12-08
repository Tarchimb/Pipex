#ifndef PIPEX_H
#define PIPEX_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

char    **ft_parsing(char **envp);
char    *ft_get_envp_path(char **envp, char *path);



#endif
