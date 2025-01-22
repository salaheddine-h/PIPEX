/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:09:43 by salhali           #+#    #+#             */
/*   Updated: 2025/01/21 17:47:40 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    parent_process(char **argv, char **envp, int *fd)
{
    int fileout;

    fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if(fileout == -1)
            error("Check");
    dup2(fd[0], STDIN_FILENO);
    dup2(fileout, STDOUT_FILENO);
    close(fd[1]);
	execute(argv[3], envp);
    
}
void    child_process(char **argv, char **envp, int *fd)
{
    int filein;

    filein = open(argv[1], O_RDONLY);
    if(filein == -1)
            error("Check");
    dup2(fd[1], STDOUT_FILENO);
    dup2(filein, STDIN_FILENO);
    close(fd[0]);
	execute(argv[2], envp);
}

int main(int argc, char **argv,  char **env)
{
    int     pid_fd[2];
    pid_t   pid;
    //s_name Name;

    
    //name-> input_inpyt , file->output
    // s_name.input_file = argv[1];
    // s_name.output_file = argv[4];
    
    // t_name.input_fd = 
    // t_name.input_fd = 

    if(argc == 5)
    {
        if(pipe(pid_fd) == -1)
            perror("Check");
        pid = fork();
        if(pid == -1)
            perror("Check");
        if(pid == 0)
            child_process(argv, env, pid_fd);
        parent_process(argv, env, pid_fd); 
    }
    else
    {
        ft_putstr_fd("ERROR : Bad arguments\n", 2);
        ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	ft_putstr_fd("\n---------- Check Again ----------\n", 1);
		exit(EXIT_FAILURE);
    }
    return(0);
}
