/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:13:15 by cyelena           #+#    #+#             */
/*   Updated: 2022/01/25 18:45:50 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(char *argv, char **envp)
{
	int		fd[2];
	pid_t	fork1;

	if (pipe(fd) == -1)
		ft_error(1);
	fork1 = fork();
	if (fork1 == -1)
		ft_error(1);
	if (fork1 == 0)
	{
		close (fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ft_cmd(argv, envp);
	}
	else
	{
		waitpid(pid, NULL, 0);
		dup2(fd[0], STDIN_FILENO);
		close (fd[1]);
	}
}

void	ft_here_doc(char *limiter, int argc)
{
	int		fd[2];
	char	*line;
	pid_t	fork1;

	if (argc < 6)
		ft_error(1);
	if (pipe(fd) == -1)
		ft_error(1);
	fork1 = fork();
	if (fork1 == -1)
		ft_error(1);
	if (fork1 == 0)
	{
		close(fd[0]);
		while (ft_gnl(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit (EXIT_SUCCESS);
			write (fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		wait (NULL);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	outfile;
	int	infile;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			ft_here_doc(argv[2], argc);
		}
		else
		{
			i = 2;
			infile = ft_file(argv[1], 2);
			outfile = ft_file(argv[argc - 1], 2);
			dup2(infile, STDIN_FILENO);
		}
		while (i < argc - 2)
			child_process(argv[i++], envp);
		dup2(outfile, STDOUT_FILENO);
		ft_cmd(argv[argc - 2], envp);
	}
	ft_error(1);
}
