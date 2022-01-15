/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:13:15 by cyelena           #+#    #+#             */
/*   Updated: 2022/01/15 20:10:53 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int	intput;

	intput = open(argv[1], O_RDONLY, 0777);
	if (intput == -1)
		ft_error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(intput, STDIN_FILENO);
	close(fd[0]);
	ft_cmd(argv[2], envp);
}

void	parant_process(char **argv, char **envp, int *fd)
{
	int	output;

	output = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (output == -1)
		ft_error();
	dup2(fd[0], STDIN_FILENO);
	dup2(output, STDOUT_FILENO);
	close(fd[01]);
	ft_cmd(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	fork1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error();
		fork1 = fork();
		if (fork1 == -1)
			ft_error();
		if (fork1 == 0)
			child_process(argv, envp, fd);
		waifpid(fork1, NULL, 0);
		parant_process(argv, envp, fd);
		close(fd[0]);
		close(fd[0]);
	}
	else
	ft_error(1);
}
