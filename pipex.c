
#include "./Includes/pipex.h"

int ft_child_process(char **argv, char **envp, char **paths, char **args)
{
    char    *cmd;
    int     i;
    int     j;

    i = 0;
    j = 0;
    (void)argv;
    (void)envp;
    (void)args;
    while (paths[i])
    {
        while (args[j])
        {
            cmd = ft_strjoin(paths[i],argv[2]);
            printf("%s\n", cmd);
            if (execve(cmd, args, envp) == -1)
                printf("shit");
            free(cmd);
            j++;
        }
        j = 0;
        i++;
    }
    return (0);
}


int ft_pipex(char **argv, char **envp, char **paths)
{
//    int     fd[2];
   // int     id;
    char    **args;

   // args = NULL;
    args = ft_split(argv[2], ' ');
    //pipe(fd);
    // id = fork();
    // if (id == 0)
    // {
    ft_child_process(argv, envp, paths, args);
    //}
    // else
    // {
    //     //ft_parent_process(argv, envp, paths);
    // }
    return (1);
}

int main(int argc, char **argv, char **envp)
{
    char    **paths;
    (void)argc;
    (void)argv;
    //char    pat[] = "/bin/";
    paths = ft_parsing(envp);
    execve("/usr/bin/ls", argv + 2, envp);
    if (!paths)
        return (0);
  //  if (!ft_pipex(argv, envp, paths))
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
