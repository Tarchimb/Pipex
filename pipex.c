
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

int ft_exec_process(t_args *args, int *j)
{
    char        *cmd;
    char        **arg;
    int         i;

    i = 0;
    arg = ft_split(args->av[*j], ' ');
    if (!arg)
    {
        ft_putstr_fd("a problem has occured with malloc", STDERR);
        return (0);
    }
    while (args->paths[i])
    {
        cmd = ft_strjoin(args->paths[i],arg[0]);
		if (access(cmd, F_OK) == 0)
        	execve(cmd, arg, args->env);
        free(cmd);
        i++;
    }
    ft_putstr_fd("command not found: ", STDERR);
    ft_putstr_fd(arg[0], STDERR);
    ft_putstr_fd("\n", STDERR);
    ft_free_all((void **)arg);
    return (0);
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
			if (!ft_exec_process(args, j))
                return (0);
	}
	return (1);
}

int ft_pipex(t_args *args, t_fd *fd)
{
    int  j;

	j = 2;
	dup2(fd->fd1, STDIN);
	dup2(fd->fd2, STDOUT);
    fd->pipe_nb = args->ac - 3;
	if (!ft_get_fd(fd, &j, args, 0))
        return (0);
	while (j <= fd->pipe_nb)
	{
    	if (!ft_get_fd(fd, &j, args, 1))
            return (0);
        j++;
	}
    close(fd->fd[0]);
    close(fd->fd[1]);
	if (!ft_exec_process(args, &j))
	    	return (0);
    return (1);
}

int ft_error(int error, t_fd *fd)
{
    if (error == INFILE_ERROR)
    {
        perror("can't open infile");
        return (0);
    }
    if (error == OUTFILE_ERROR)
    {
        perror("can't open outfile");
        close(fd->fd1);
        return (0);
    }
    if (error == ARGS_ERROR)
    {
        ft_putstr_fd("not enough arguments\n", STDERR);
        return (0);
    }
    if (error == MALLOC_ERROR)
    {
        ft_putstr_fd("something bad happened in parsing\n", STDERR);
		close(fd->fd1);
		close(fd->fd2);
        return (0);
    }
    return (0);
}

int main(int argc, char **argv, char **envp)
{
	t_args	args;
	t_fd	fd;

	args.ac = argc;
	args.av = argv;
	args.env = envp;
    if (access("infile", R_OK))
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
        return (0);
    }
    return (0);
}
