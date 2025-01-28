/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:38:42 by salhali           #+#    #+#             */
/*   Updated: 2025/01/28 20:31:45 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

void	child_process1(char **argv, char **envp, int *fd);
void	child_process2(char **argv, char **envp, int *fd);
void	execute(char *cmd, char **env);
char	*find_path(char *cmd, char **envp);
void	ft_free(char **str);
void	handle_path(char **cmd_args, char **env);
void	handle_relative_path(char **cmd_args, char **env);
void	handle_absolute_path(char **cmd_args, char **env);

#endif
