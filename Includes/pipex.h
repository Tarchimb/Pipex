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

#define STDIN 0
#define STDOUT 1

char    **ft_parsing(char **envp);
char    *ft_get_envp_path(char **envp, char *path);

typedef struct s_fd
{
    int     fd[2];
    int     fd1;
    int     fd2;
    pid_t   pid;
    int     pipe_nb;
}   t_fd;

typedef struct s_args
{
    int     ac;
    char    **av;
    char    **env;
    char    **paths;
}   t_args;



#endif
