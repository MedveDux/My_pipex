/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:16:22 by cyelena           #+#    #+#             */
/*   Updated: 2022/01/27 16:01:17 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error(int a)
{
	if (a == 1)
	{
		perror("\033[31mError fork!");
	}
	if (a == 2)
	{
		perror("\033[31mError: Bad arguments\n./pipex file1 cmd1 cmd2 file2");
	}
	if (a == 3)
	{
		perror("\033[31mBad open!");
	}
	if (a == 4)
	{
		perror("\033[31mBad pipe!");
	}
	exit(EXIT_FAILURE);
}

void	ft_cmd(char *argv, char **envp)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (execve(ft_path(cmd[0], envp), cmd, envp) == -1)
		ft_error(2);
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
