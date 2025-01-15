/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:22:12 by salhali           #+#    #+#             */
/*   Updated: 2025/01/15 18:15:34 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	execute(char *cmd, char **envp)
// {
// 	char	**args;
// 	char	*path;

// 	args = ft_split(cmd, ' ');
// 	path = get_command_path(args[0], envp);
// 	if (!path)
// 		error();
// 	execve(path, args, envp);
// }

// Child Process that run inside a fork, take the filein, put the output inside a pipe and then close ehit the exec function 
void	child_process(char **argv, char **envp, int *fd)
{
	int		filein;

	filein = open(argv[1], O_RDONLY);
	if(filein == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	execvp(argv[2], envp);
}
/* Parent process that take the data from the pipe, change the output for the fileout and also close ehit the exec function */
void	parent_process(char **argv, char **envp, int *fd)
{
	int		fileout;
	
	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if(fileout == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}


/*Main function that run the child and parent process or display an error message if arguments are wrong */
int	main(int argc, char **argv, char **env)
{
	int		pip_fd[2];  // pip_fd[0] (read filename) && pip_fd[1] (write to pip)
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(pip_fd) == -1)
			error();
		pid = fork();
		if (pid == -1)
			error();
		if (pid == 0)
			child_process(argv, env, pip_fd);
		//waitpid(pid, NULL, 0);
		parent_process(argv, env, pip_fd);
	}
	else
	{
		ft_putstr_fd("Error: Bad arguments\n", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
		//exit(EXIT_FAILURE);
	}
	return(0);
}

