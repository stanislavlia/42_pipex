/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:20:28 by sliashko          #+#    #+#             */
/*   Updated: 2023/12/11 12:44:10 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

char	*find_path(char *cmd, char **envp);
void	ft_free_table(char **tab);
void	simulate_pipe(char *cmd, char **envp);
void	put_error_msg(char *msg);
void	files_err_handler(int argc, int in_fd, int out_fd);

#endif
