/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:26:20 by sliashko          #+#    #+#             */
/*   Updated: 2023/12/04 15:41:47 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void	retrieve_path_dirs(char **envp, char ***arr_dirs)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strnstr(envp[i], "PATH=", 5) != NULL)
		{
			*arr_dirs = ft_split(envp[i] + 5, ':');
			return ;
		}
		i++;
	}
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**path_dirs;
	char	*correct_path;
	char	*exec_file;

	retrieve_path_dirs(envp, &path_dirs);
	i = 0;
	while (path_dirs[i] != NULL)
	{
		exec_file = ft_strjoin(path_dirs[i], "/");
		exec_file = ft_strjoin(exec_file, cmd);
		if (access(exec_file, F_OK | X_OK) != -1)
		{
			free(path_dirs);
			return (exec_file);
		}
		i++;
	}
	return (NULL);
}

void	ft_free_table(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
