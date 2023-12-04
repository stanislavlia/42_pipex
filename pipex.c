/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:20:21 by sliashko          #+#    #+#             */
/*   Updated: 2023/12/04 14:14:15 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

/*
 * Executes the first command (command1) in the pipeline.
 *
 * This function opens the input file, setting it as the standard input (stdin).
 * It then redirects its output to a pipe for further processing. The function
 * dynamically splits the command arguments and executes command1 using execv.
 *
 * Parameters:
 *  fds: file descriptors for pipe communication
 *  argv: program arguments
 *  envp: environment variables
 *
 */
void	child_command1(int fds[2], char **argv, char **envp)
{
	int		inp_fd;
	char	**args;

	inp_fd = open(argv[1], O_RDONLY);
	args = ft_split(argv[2], ' ');
	if (inp_fd == -1)
	{
		write(1, "pipex erros: Input file reading error\n", 39);
		exit(-1);
	}
	args[0] = find_path(args[0], envp);
	if (args[0] == NULL)
	{
		write(1, "pipex error: command not found\n", 32);
		exit(-1);
	}
	dup2(inp_fd, STDIN_FILENO);
	dup2(fds[1], STDOUT_FILENO);
	close(inp_fd);
	close(fds[1]);
	close(fds[0]);
	if (execv(args[0], args) == -1)
		exit(-1);
}

// /*
//  * Executes the second command (command2) in the pipeline.
//  *
//  * This function takes input from the pipe (output of command1) and redirects
//  * it to the command2 process, 
//  * then writes the output of command2 to the specified
//  * output file. In this code snippet, 
//  * command2 is hardcoded as 'wc -c', but it
//  * can be modified for dynamic argument handling similar to child_command1.
//  *
//  * Parameters:
//  *  fds: file descriptors for pipe communication
//  *  argv: program arguments
//  *  envp: environment variables
//  *
//  */
void	child_command2(int fds[2], char **argv, char **envp)
{
	int		out_fd;
	char	**args;

	args = ft_split(argv[3], ' ');
	args[0] = find_path(args[0], envp);
	if (args[0] != NULL)
		out_fd = open(argv[4], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if (out_fd == -1)
	{
		write(1, "pipex error: Invalid or non existing file\n", 43);
		exit(-1);
	}
	dup2(out_fd, STDOUT_FILENO);
	dup2(fds[0], STDIN_FILENO);
	close(fds[0]);
	close(fds[1]);
	if (execv(args[0], args) == -1)
	{
		write(1, "pipex error: command not found\n", 32);
		exit(-1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	fds[2];

	if (argc != 5)
	{
		ft_putstr_fd("format: ./pipex infile \"ls -l\" \"wc -l\" outfile\n", 1);
		return (3);
	}
	if (pipe(fds) == -1)
	{
		ft_putstr_fd("Some error occured with pipe\n", 1);
		return (2);
	}
	if (fork() == 0)
	{
		child_command1(fds, argv, envp);
	}
	if (fork() == 0)
	{
		child_command2(fds, argv, envp);
	}
	close(fds[0]);
	close(fds[1]);
}
