/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:24:01 by salhali           #+#    #+#             */
/*   Updated: 2025/01/26 18:38:03 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;

	if (!envp[i])
	{
		ft_putstr_fd("Pipex: We Don't have PATH", 2);
		return(NULL);
	}

	paths = ft_split(envp[i] + 5, ':');
	
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0) 
			return (path); 
		free(path); 
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}
void ft_free(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	execute(char *cmd, char **env)
{
    char *path;

    // Absolute path check
    if (cmd[0] == '/')
    {
        // Hna absolute path, nrun direct
        if (execve(cmd, ft_split(cmd, ' '), env) == -1)
        {
            perror("Pipex: execve (absolute path)");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        // Use find_path to locate the relative path
        path = find_path(cmd, env);

        if (path == NULL) // If find_path returns NULL, the command is not found
        {
            perror("Pipex: command not found");
            exit(EXIT_FAILURE);
        }

        // Execute the found path
        if (execve(path, ft_split(cmd, ' '), env) == -1)
        {
            perror("Pipex: execve (relative path)");
            free(path); // Free path if execve fails
            exit(EXIT_FAILURE);
        }

        free(path); // Cleanup memory allocated by find_path
    }
}
