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
	ft_free(paths);
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
	char **cmd_args;

	if (cmd[0] == '\0')
	{
		write(2, "Pipex: \"========\" command not found\n", 37);
		exit(EXIT_FAILURE);
	}
	cmd_args = ft_split(cmd, ' ');
	if (NULL == cmd_args)
	{
		perror("Pipex: ft_split:");
		exit (EXIT_FAILURE);
	}

    if (ft_strchr(cmd_args[0], '/')) // we check realtive and absolute path at the same time (ex: ./program || /usr/bin/ls)
    {
		if (access(cmd_args[0], X_OK) == 0)
			execve(cmd_args[0], cmd_args, env);
		else
		{
			perror("Pipex: ");
			ft_free(cmd_args);
			exit(EXIT_FAILURE);
		}
    }

    else // the user passe the command only, so we have to search for its path! (ex: ls -la)
    {
        // Use find_path to locate the relative path
        path = find_path(cmd_args[0], env);
        if (path == NULL) // If find_path returns NULL, the command is not found
        {
            write(2, "Pipex: +++++++ command not found", 33);
			ft_free(cmd_args);
            exit(EXIT_FAILURE);
        }

        // Execute the found path
        if (execve(path, cmd_args, env) == -1)
        {
            perror("Pipex: execve (relative path)");
			ft_free(cmd_args);
            free(path); // Free path if execve fails
            exit(EXIT_FAILURE);
        }

        // frwee(path); // Cleanup memory allocated by find_path
    }
}
