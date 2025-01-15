/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:20:16 by salhali           #+#    #+#             */
/*   Updated: 2025/01/15 19:31:26 by salhali          ###   ########.fr       */
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
#include <sys/types.h>    //NOTE: Added


// Mandatory Funtions

void    error(void); //here
char    *find_path(char *cmd, char **envp); //here
int     get_next_line(char **line); //here
void    execute(char *argv, char **envp);//here

#endif
