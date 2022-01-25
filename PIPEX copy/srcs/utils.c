/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:16:22 by cyelena           #+#    #+#             */
/*   Updated: 2022/01/25 15:27:03 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error(int a)
{
	if (a == 1)
	{
		ft_putstr_fd("\033[31mError: Bad arguments", 2);
		ft_putstr_fd("\033[31./pipex file1 cmd1 cmd2 file2", 1);
	}
	if (a == 2)
		ft_putstr_fd("\033[31Error: Bad arguments1232141", 2);
	exit(EXIT_FAILURE);
}

void	ft_cmd(char *argv, char **envp)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (execve(ft_path(cmd[0], envp), cmd, envp) == -1)
		ft_error(1);
}

char	*ft_path(char *cmd, char **envp)
{
	char	*path;
	char	**paths;
	char	*part_path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}
