/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:27:22 by salhali           #+#    #+#             */
/*   Updated: 2025/01/28 20:32:17 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_absolute_path(char **cmd_args, char **env)
{
	if (access(cmd_args[0], X_OK) == 0)
	{
		if (execve(cmd_args[0], cmd_args, env) == -1)
		{
			perror("Pipex: execve (absolute path)");
			ft_free(cmd_args);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		perror("Pipex: access (absolute path)");
		ft_free(cmd_args);
		exit(EXIT_FAILURE);
	}
}

void	handle_relative_path(char **cmd_args, char **env)
{
	char	*path;

	path = find_path(cmd_args[0], env);
	if (path == NULL)
	{
		write(2, "Pipex: command not found\n", 25);
		ft_free(cmd_args);
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd_args, env) == -1)
	{
		perror("Pipex: execve (relative path)");
		ft_free(cmd_args);
		free(path);
		exit(EXIT_FAILURE);
	}
	free(path);
}

void	handle_path(char **cmd_args, char **env)
{
	if (ft_strchr(cmd_args[0], '/'))
		handle_absolute_path(cmd_args, env);
	else
		handle_relative_path(cmd_args, env);
}
