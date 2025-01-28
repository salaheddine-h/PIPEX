/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:24:01 by salhali           #+#    #+#             */
/*   Updated: 2025/01/28 20:31:45 by salhali          ###   ########.fr       */
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
		return (ft_putstr_fd("Pipex: We Don't have PATH", 2), NULL);
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
	return (NULL);
}

void	ft_free(char **str)
{
	int	i;

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
	char	**cmd_args;

	if (cmd[0] == '\0')
	{
		write(2, "Pipex: command not found\n", 26);
		exit(EXIT_FAILURE);
	}
	cmd_args = ft_split(cmd, ' ');
	if (NULL == cmd_args)
	{
		perror("Pipex: ft_split:");
		exit(EXIT_FAILURE);
	}
	handle_path(cmd_args, env);
}
