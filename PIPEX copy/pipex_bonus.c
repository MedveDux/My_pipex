/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:13:15 by cyelena           #+#    #+#             */
/*   Updated: 2022/01/24 17:54:31 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int	intput;

	intput = open(argv[1], O_RDONLY, 0777);
	if (intput == -1)
		ft_error(1);
	dup2(intput, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	ft_cmd(argv[2], envp);
}

void	child2_process(char **argv, char **envp, int *fd)
{
	int	output;

	output = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (output == -1)
		ft_error(1);
	dup2(fd[0], STDIN_FILENO);
	dup2(output, STDOUT_FILENO);
	close(fd[1]);
	ft_cmd(argv[3], envp);
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
		while (/* condition */)
		{
			/* code */
		}
		
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	
	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			ft_here_doc(argv[2], argc);
		}
	}
	else
		ft_error(1);
}
