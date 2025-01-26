/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:38:42 by salhali           #+#    #+#             */
/*   Updated: 2025/01/26 18:24:08 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include <sys/types.h>
#include <sys/wait.h>

void	child_process1(char **argv, char **envp, int *fd);
void	child_process2(char **argv, char **envp, int *fd);
void	execute(char *argv, char **envp);
char	*find_path(char *cmd, char **envp);
void	ft_free(char **str);

#endif
