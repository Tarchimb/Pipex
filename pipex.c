/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:49:21 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/17 15:11:02 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/pipex.h"

int	ft_exec_process(t_args *args, int *j)
{
	int		i;

	i = -1;
	if (*args->av[*j])
	{
		args->arg = ft_split(args->av[*j], ' ');
		if (!args->arg)
			return (ft_putstr_fd("a problem has occured with malloc", STDERR));
	}
	else
		return (ft_putstr_fd("zsh: command not found", STDERR));
	while (args->paths[++i])
	{
		args->cmd = ft_strjoin(args->paths[i], args->arg[0]);
		if (access(args->cmd, F_OK) == 0)
		{
			ft_free_all((void **)args->paths);
			free(args->cmd);
			execve(args->cmd, args->arg, args->env);
		}
		free(args->cmd);
	}
	ft_free_all((void **)args->arg);
	return (0);
}

int	ft_get_fd(t_fd *fd, int *j, t_args *args)
{
	pipe(fd->fd);
	fd->pid = fork();
	if (fd->pid != 0)
	{
		close(fd->fd[1]);
		dup2(fd->fd[0], STDIN);
		close(fd->fd[0]);
	}
	else
	{
		close(fd->fd[0]);
		if (*j != fd->pipe_nb + 1)
			dup2(fd->fd[1], STDOUT);
		close(fd->fd[1]);
		if (!ft_exec_process(args, j))
			return (0);
	}
	return (1);
}

int	ft_pipex(t_args *args, t_fd *fd)
{
	int	j;

	j = 1;
	fd->pipe_nb = args->ac - 3;
	pipe(fd->fd);
	fd->pid = fork();
	if (fd->pid == 0)
	{
		dup2(fd->fd1, STDIN);
		dup2(fd->fd2, STDOUT);
		while (++j <= fd->pipe_nb + 1)
			if (!ft_get_fd(fd, &j, args))
				return (0);
		while (wait(NULL) != -1)
			;
	}
	else
	{
		waitpid(fd->pid, NULL, 0);
		close(fd->fd[0]);
		close(fd->fd[1]);
	}
	return (0);
}

int	ft_error(int error, t_fd *fd)
{
	if (fd->fd1)
		close(fd->fd1);
	if (fd->fd2)
		close(fd->fd2);
	if (error == INFILE_ERROR)
	{
		perror("can't open infile");
		return (0);
	}
	if (error == OUTFILE_ERROR)
	{
		perror("can't open outfile");
		return (0);
	}
	if (error == ARGS_ERROR)
		return (ft_putstr_fd("not enough arguments\n", STDERR));
	if (error == MALLOC_ERROR)
		return (ft_putstr_fd("something bad happened in parsing\n", STDERR));
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_args	args;
	t_fd	fd;

	args.ac = argc;
	args.av = argv;
	args.env = envp;
	if (access("infile", F_OK) == 0)
		fd.fd1 = open(args.av[1], O_RDONLY);
	if (argc < 5)
		return (ft_error(ARGS_ERROR, &fd));
	if (fd.fd1 < 0)
		return (ft_error(INFILE_ERROR, &fd));
	fd.fd2 = open(args.av[args.ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd.fd2 < 0)
		return (ft_error(OUTFILE_ERROR, &fd));
	args.paths = ft_parsing(envp);
	if (!args.paths)
		return (ft_error(MALLOC_ERROR, &fd));
	if (!ft_pipex(&args, &fd))
	{
		ft_free_all((void **)args.paths);
		close(fd.fd1);
		close(fd.fd2);
	}
	return (0);
}
