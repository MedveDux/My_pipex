/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:48:18 by cyelena           #+#    #+#             */
/*   Updated: 2022/01/29 20:03:43 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_error_bonus(int a)
{
	if (a == 1)
	{
		perror("\033[31mError fork!");
	}
	if (a == 2)
	{
		perror("\033[31mError: Bad arguments!");
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

int	ft_file_bonus(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0777);
	if (file == -1)
		ft_error_bonus(3);
	return (file);
}

int	ft_gnl_bonus(char **line)
{
	char	*buf;
	int		i;
	int		bytes;
	char	c;

	i = 0;
	bytes = 0;
	buf = (char *)malloc(sizeof (char) * 10000);
	if (!buf)
		return (-1);
	bytes = read(0, &c, 1);
	while (bytes && (c != '\n') && (c != '\0'))
	{
		buf[i] = c;
		i++;
		bytes = read(0, &c, 1);
	}
	buf[i] = '\n';
	buf[++i] = '\0';
	*line = buf;
	free(buf);
	return (bytes);
}

char	*ft_path_bonus(char *cmd, char **envp)
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

void	ft_cmd_bonus(char *argv, char **envp)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (execve(ft_path_bonus(cmd[0], envp), cmd, envp) == -1)
		ft_error_bonus(2);
}
