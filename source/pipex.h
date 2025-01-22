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

void	error(const char *str);
void	child_process(char **argv, char **envp, int *fd);
void	parent_process(char **argv, char **envp, int *fd);
void	execute(char *argv, char **envp);
char	*find_path(char *cmd, char **envp);
int	get_next_line(char **line);

/*typedef struct t_name
{
	char *input_file;
	char *output_file;
	int input_fd;
	int output_fd;
} s_name;

typedef struct t_list
{
	char **comand;
	char *full_path;
	
} s_list;*/

#endif
