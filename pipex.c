
#include "./Includes/pipex.h"

char *ft_child_process(char *argv, char **envp, char **paths)
{
    char    *cmd;
    char    **args;
    static int     i = 0;
    static int     j = 0;

    (void)argv;
    (void)envp;
    (void)args;
    args = ft_split(argv, ' ');
    while (paths[i])
    {
        while (args[j])
        {
            cmd = ft_strjoin(paths[i],argv);
            if (execve(cmd, args, envp) != -1)
                return (cmd);
            free(cmd);
            j++;
        }
        j = 0;
        i++;
    }
    return (NULL);
}


int ft_pipex(char **argv, char **envp, char **paths, int fd1, int fd2)
{
    int     fd[2];
    int     id;
    int     i = 0;
    pipe(fd);
    (void)envp;
    (void)paths;
    (void)argv;
    (void)i;

    id = fork();
    if (id == 0)
    {
        dup2(fd1, 0);
        dup2(fd[1], 1);
        close(fd[0]);
        while (i++ < 10)
            execve(ft_child_process(argv[1], envp, paths), argv + 1, envp);
        close (fd1);
        //close (fd[1]);
    }
    else
    {
        waitpid(-1, &id, 0);
        dup2(fd2, 1);
        dup2(fd[0], 0);
        close(fd[1]);
        while (i++ < 10)
            execve(ft_child_process(argv[4], envp, paths), argv + 1, envp);
        close(fd2);
        //close(fd[0]);
    }
    return (1);
}

int main(int argc, char **argv, char **envp)
{
    char    **paths;
    int     fd1;
    int     fd2;
    (void)argc;
    (void)argv;
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (fd1 < 0 || fd2 < 0)
        return (0);
    //char    pat[] = "/bin/";
    paths = ft_parsing(envp);
    if (!paths)
        return (0);
    if (!ft_pipex(argv, envp, paths, fd1, fd2))
        return (0);
    //    return (0);
    //path = NULL;
    //if (access(argv[1], F_OK) == -1 || argc < 5) //check si le fichier existe
    //   return (0);
    //pipex(argv);
    // int fd;
    // fd = open("test.txt", O_RDWR);
    // if (fd < 0)
    //     return (0);
    // dup2(fd, 0);
    // execve(pat, argv + 1, envp);
    //int i;
    // for (i = 0; i < 10; i++)
    // printf("%s\n", path[i]);
    return (0);
}

// int
// main(int argc, char *argv[], char *env[])
// {
//   if (argc > 1)
//     if (execve(argv[1], argv + 1, env) == -1)
//       perror("execve");

//   printf("My pid is: %d\n", getpid());

//   return 0;
// }
