/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:09:43 by salhali           #+#    #+#             */
/*   Updated: 2025/01/28 17:40:56 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process1(char **argv, char **envp, int *fd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY);
	if (filein == -1)
	{
		perror("Pipex: open(child_process1)");
		exit(EXIT_FAILURE);
	}
	dup2(filein, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execute(argv[2], envp);
}

void	child_process2(char **argv, char **envp, int *fd)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
	{
		perror("Pipex: open(child_proess2)");
		exit(EXIT_FAILURE);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fileout);
	close(fd[0]);
	close(fd[1]);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **env)
{
	int		pid_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
	{
		ft_putstr_fd("ERROR : Bad arguments\n", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
		exit(EXIT_FAILURE);
	}
	if (pipe(pid_fd) == -1)
		perror("Pipex: pipe");
	pid1 = fork();
	if (pid1 == -1)
		perror("Pipex: fork_process1");
	if (pid1 == 0)
		child_process1(argv, env, pid_fd);
	pid2 = fork();
	if (pid2 == -1)
		perror("Pipex: fork_process2");
	if (pid2 == 0)
		child_process2(argv, env, pid_fd);
	close(pid_fd[0]);
	close(pid_fd[1]);
	return (waitpid(pid1, NULL, 0), waitpid(pid2, NULL, 0), 0);
}
