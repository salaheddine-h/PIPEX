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
	
	//paths = 
	//*paths[0]: /usr/local/sbin/ls
	//*paths[1]: /usr/local/bin/ls
	//*paths[2]: /usr/sbin/ls
	//*paths[3]: /usr/bin/ls
	//*paths[4]: /sbin/ls
	//*paths[5]: /bin/ls
	//*paths[6]: /usr/games/ls
	//*paths[7]: /usr/local/games/ls
	//*paths[8]: /snap/bin/ls 
	
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0) // check is this cmd file is here or not 
			return (path); //valid
		free(path); //not valid
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

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	
	cmd = ft_split(argv, ' ');
	if (NULL == cmd)
	{
		ft_putstr_fd("Pipex: malloc failed in ft_split", 2);
		exit(EXIT_FAILURE);
	}
	path = find_path(cmd[0], envp);
	if (!path)	
	{
		ft_free(cmd);
		exit(1);
	}
	if (execve(path, cmd, NULL) == -1)
	{
		perror("Pipex: execve");
		ft_free(cmd);
		free(path);
		exit (EXIT_FAILURE);		
	}
}

