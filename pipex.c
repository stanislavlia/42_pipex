/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:20:21 by sliashko          #+#    #+#             */
/*   Updated: 2023/12/11 12:49:50 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void	handle_args(char **args, char **envp)
{
	if (args == NULL)
		put_error_msg("Memory allocation failed\n");
	if (args[0] == NULL)
		put_error_msg("Invalid command provided\n");
	if (access(args[0], F_OK | X_OK) == -1)
		args[0] = find_path(args[0], envp);
}

void	simulate_pipe(char *cmd, char **envp)
{
	int		fds[2];
	pid_t	pid;
	char	**args;

	args = ft_split(cmd, ' ');
	handle_args(args, envp);
	if (pipe(fds) == -1)
		put_error_msg("Pipe function failed\n");
	pid = fork();
	if (pid == 0)
	{
		close(fds[0]);
		dup2(fds[1], STDOUT_FILENO);
		if (execv(args[0], args) == -1)
		{
			ft_free_table(args);
			put_error_msg("pipex error: command not found\n");
		}
	}
	else
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
	}
}

//test for 3 commands
int	main(int argc, char **argv, char **envp)
{
	int		in_fd;
	int		out_fd;
	int		i;
	char	**args;

	in_fd = open(argv[1], O_RDONLY);
	out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	files_err_handler(argc, in_fd, out_fd);
	i = 2;
	dup2(in_fd, STDIN_FILENO);
	while (i < argc - 2)
	{
		simulate_pipe(argv[i], envp);
		i++;
	}
	dup2(out_fd, STDOUT_FILENO);
	args = ft_split(argv[argc - 2], ' ');
	if (access(args[0], F_OK | X_OK) == -1)
		args[0] = find_path(args[0], envp);
	if (execv(args[0], args) == -1)
	{
		ft_free_table(args);
		put_error_msg("Last command failed to run\n");
	}
}
// ./pipex inpit cmd1 cmd2 cmd3 cmd4 out
//     0     1    2     3   4    5    6
