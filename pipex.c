
#include "./Includes/pipex.h"

void	*ft_free_all(void **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

char *ft_child_process(t_args *args, int *j)
{
    char        *cmd;
    char        **arg;
    int         i;

    i = 0;
    arg = ft_split(args->av[*j], ' ');
    if (!arg)
        return (NULL);
    while (args->paths[i])
    {
        cmd = ft_strjoin(args->paths[i],arg[0]);
		if (access(cmd, F_OK) == 0)
        	execve(cmd, arg, args->env);
        free(cmd);
        i++;
    }
    ft_free_all((void **)arg);
    return (NULL);
}

int ft_get_fd(t_fd *fd, int *j, t_args *args, int fdin)
{
	pipe(fd->fd);
	fd->pid = fork();
	if (fd->pid != 0)
	{
		close(fd->fd[1]);
		dup2(fd->fd[0], STDIN);
		waitpid(fd->pid, NULL, 0);
	}
	else
	{
		close(fd->fd[0]);
		dup2(fd->fd[1], STDOUT);
		if (fdin == STDIN)
		 	exit(1);
		else
			ft_child_process(args, j);
	}
	return (0);
}

int ft_pipex(t_args *args, t_fd *fd)
{
    int  j;

	j = 2;
	dup2(fd->fd1, STDIN);
	dup2(fd->fd2, STDOUT);
    fd->pipe_nb = args->ac - 3;
	ft_get_fd(fd, &j, args, 0);
	while (j <= fd->pipe_nb)
	{
    	ft_get_fd(fd, &j, args, 1);
        j++;
	}
	if (!ft_child_process(args, &j))
	    	return (0);
    wait(NULL);
    return (1);
}


int main(int argc, char **argv, char **envp)
{
	t_args	args;
	t_fd	fd;

	args.ac = argc;
	args.av = argv;
	args.env = envp;
	fd.fd1 = open(args.av[1], O_RDONLY);
	if (fd.fd1 < 0)
		return (0);
	fd.fd2 = open(args.av[args.ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd.fd2 < 0)
	{
		close(fd.fd1);
        return (0);
	}
    if (!argc)
        return (0);
    args.paths = ft_parsing(envp);
    if (!args.paths)
	{
		close(fd.fd1);
		close(fd.fd2);
        return (0);
	}
    if (!ft_pipex(&args, &fd))
    {
        ft_free_all((void **)args.paths);
		close(fd.fd1);
		close(fd.fd2);
        return (0);
    }
    return (0);
}
