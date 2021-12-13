
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

char *ft_child_process(char **argv, char **envp, char **paths, int *j)
{
    char        *cmd;
    char        **args;
    int         i;

    i = 0;
    args = ft_split(argv[*j], ' ');
    if (!args)
        return (NULL);
    while (paths[i])
    {
        cmd = ft_strjoin(paths[i],args[0]);
        execve(cmd, args, envp);
        free(cmd);
        i++;
    }
    ft_free_all((void **)args);
    return (NULL);
}

void ft_get_fd(t_fd *fd, int *j)
{
    if (fd->id == 0)
    {
        dup2(fd->fd1, STDIN);
        dup2(fd->fd[1], STDOUT);
        close(fd->fd[0]);
        close (fd->fd1);
    }
    else
    {
        *j += 1;
        waitpid(-1, &fd->id, 0);
        dup2(fd->fd[0], STDIN);
        dup2(fd->fd2, STDOUT);
        close(fd->fd[1]);
        close(fd->fd2);
    }
}

int ft_get_cmd_number(char **argv)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (argv[i])
        if (argv[i][0] == '|')
            j++;
    return (j);
}

int ft_pipex(int argc, char **argv, char **envp, char **paths)
{
    static int  j = 2;
    t_fd    fd;

    fd.fd1 = open(argv[1], O_RDONLY);
    fd.fd2 = open(argv[argc], O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (fd.fd1 < 0 || fd.fd2 < 0)
        return (0);
    fd.pipe_nb = ft_get_cmd_number(argv);
    pipe(fd.fd);
    fd.id = fork();
    ft_get_fd(&fd, &j);
    if (!ft_child_process(argv, envp, paths, &j))
        return (0);
    return (1);
}


int main(int argc, char **argv, char **envp)
{
    char    **paths;

    if (!argc)
        return (0);
    paths = ft_parsing(envp);
    if (!paths)
        return (0);
    if (!ft_pipex(argc, argv, envp, paths))
    {
        ft_free_all((void **)paths);
        return (0);
    }
    return (0);
}
