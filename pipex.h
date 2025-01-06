/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:43:19 by salhali           #+#    #+#             */
/*   Updated: 2024/12/31 21:23:47 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

void	error(void);
void	child_proc(char **argv, char **env, int *fd);
void	parent_proc(char **argv, char **env, int *fd);
void	execute(char *argv, char **env);
char	*find_path(char *cmd, char **envp);

#endif
