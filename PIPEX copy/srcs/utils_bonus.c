/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:48:18 by cyelena           #+#    #+#             */
/*   Updated: 2022/01/25 18:35:35 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_file(char *argv, int i)
{
	int	file;

	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0777);
	if (file == -1)
		ft_error(1);
	return(file);
}

int	ft_gnl(char **line)
{
	char	*buf;
	int		i;
	int		bytes;
	char	c;

	i = 0;
	bytes = 0;
	buf = malloc(sizeof (char) * 10000);
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
	buf[i++] = '\0';
	*line = buf;
	free(buf);
	return (bytes);
}

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
