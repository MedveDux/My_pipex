/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:25:36 by cyelena           #+#    #+#             */
/*   Updated: 2022/01/29 17:32:41 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(char *argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		ft_error();
	pid = fork();
	if (pid == -1)
		ft_error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ft_cmd(argv, envp);
	}
	else
	{
		waitpid(pid, NULL, 0);
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
	}
}

void	ft_here_doc(char *limiter, int argc)
{
	pid_t	reader;
	int		fd[2];
	char	*line;

	if (argc < 6)
		ft_usage();
	if (pipe(fd) == -1)
		ft_error();
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		while (next_line(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		wait(NULL);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}

void	ft_usage(void)
{
	ft_putstr_fd("error:./pipex here_doc \
	<LIMITER> <cmd> <cmd1> <...> file\n", 1);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	filein;
	int	fileout;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			fileout = ft_file(argv[argc - 1], 0);
			ft_here_doc(argv[2], argc);
		}
		else
		{
			i = 2;
			fileout = ft_file(argv[argc - 1], 1);
			filein = ft_file(argv[1], 2);
			dup2(filein, STDIN_FILENO);
		}
		while (i < argc - 2)
			child_process(argv[i++], envp);
		dup2(fileout, STDOUT_FILENO);
		ft_cmd(argv[argc - 2], envp);
	}
	ft_usage();
}
