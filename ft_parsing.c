#include "Includes/pipex.h"

char *ft_get_envp_path(char **envp, char *path)
{
    int i;

    i = 0;
    while (envp[i])
    {
        path = ft_strnstr(envp[i],
            "PATH=", ft_strlen(envp[i]));
        if (path != NULL && ft_strlen(path) > 70)
            return (path);
        i++;
    }
    return (NULL);
}

char    **ft_parsing(char **envp)
{
    char    *envp_path;
    char    **paths;
    char    *tmp;
    int     i;

    i = 0;
    tmp = NULL;
    envp_path = NULL;
    envp_path = ft_get_envp_path(envp, envp_path);
    if (!envp_path)
        return (0);
    envp_path = ft_substr(envp_path, 5, ft_strlen(envp_path) - 5);
    paths = ft_split(envp_path, ':');
    while (paths[i])
    {
        tmp = paths[i];
        paths[i] = ft_strjoin(paths[i], "/");
        free(tmp);
        i++;
    }
    if (!paths)
        return (0);
    return (paths);
}
