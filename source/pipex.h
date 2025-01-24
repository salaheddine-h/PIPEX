/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:38:42 by salhali           #+#    #+#             */
/*   Updated: 2025/01/21 17:35:34 by salhali          ###   ########.fr       */
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

void	error(const char *str); //Done
void	child_process(char **argv, char **envp, int *fd); //Done
void	parent_process(char **argv, char **envp, int *fd); //Done
void	execute(char *argv, char **envp); //Done
char	*find_path(char *cmd, char **envp); //Done
int	get_next_line(char **line); //Done
#endif
