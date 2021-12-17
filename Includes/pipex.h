/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:53:27 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/17 15:02:17 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include "libft.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define ARGS_ERROR 0
# define INFILE_ERROR 1
# define OUTFILE_ERROR 2
# define MALLOC_ERROR 3

char	**ft_parsing(char **envp);
char	*ft_get_envp_path(char **envp, char *path);

typedef struct s_fd
{
	int		fd[2];
	int		fd1;
	int		fd2;
	pid_t	pid;
	int		pipe_nb;
}	t_fd;

typedef struct s_args
{
	int		ac;
	char	**av;
	char	**env;
	char	**paths;
	char	**arg;
	char	*cmd;
}	t_args;

#endif
