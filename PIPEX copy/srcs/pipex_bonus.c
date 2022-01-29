/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:13:15 by cyelena           #+#    #+#             */
/*   Updated: 2022/01/29 20:03:37 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	child_process_bonus(char *argv, char **envp)
{
	int		fd[2];
	pid_t	fork1;

	if (pipe(fd) == -1)
		ft_error_bonus(4);
	fork1 = fork();
	if (fork1 == -1)
		ft_error_bonus(1);
	if (fork1 == 0)
	{
		close (fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ft_cmd_bonus(argv, envp);
	}
	else
	{
		waitpid(fork1, NULL, 0);
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
	}
}

void	ft_here_doc_bonus(char *limiter, int argc)
{
	pid_t	fork1;
	int		fd[2];
	char	*line;

	if (argc < 6)
		ft_error_bonus(2);
	if (pipe(fd) == -1)
		ft_error_bonus(4);
	fork1 = fork();
	if (fork1 == 0)
	{
		close(fd[0]);
		while (ft_gnl_bonus(&line))
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
			outfile = ft_file_bonus(argv[argc - 1], 0);
			ft_here_doc_bonus(argv[2], argc);
		}
		else
		{
			i = 2;
			outfile = ft_file_bonus(argv[argc - 1], 1);
			infile = ft_file_bonus(argv[1], 2);
			dup2(infile, STDIN_FILENO);
		}
		while (i < argc - 2)
			child_process_bonus(argv[i++], envp);
		dup2(outfile, STDOUT_FILENO);
		ft_cmd_bonus(argv[argc - 2], envp);
	}
	ft_error_bonus(2);
}
