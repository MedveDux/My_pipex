/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:14:41 by cyelena           #+#    #+#             */
/*   Updated: 2022/01/29 20:25:34 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

void	ft_error(int a);
void	ft_cmd(char *argv, char **envp);
char	*ft_path(char *cmd, char **envp);
void	child_process(char **argv, char **envp, int *fd);
void	child2_process(char **argv, char **envp, int *fd);

// void	ft_error(void);
// int		next_line(char **line);
// void	ft_cmd(char *argv, char **envp);
// int		ft_file(char *argv, int i);
// void	ft_usage(void);

// void	child_process_bonus(char *argv, char **envp);
// void	ft_here_doc_bonus(char *limiter, int argc);
// void	ft_usage_bonus(void);
// int		ft_file_bonus(char *argv, int i);
// int		next_line_bonus(char **line);
// char	*ft_cmd2_bonus(char *cmd, char **envp);
// void	ft_error_bonus(void);
// void	ft_cmd_bonus(char *argv, char **envp);

// void	child_process_bonus(char *argv, char **envp);
// void	ft_here_doc_bonus(char *limiter, int argc);
// int		ft_file_bonus(char *argv, int i);
// int		ft_gnl_bonus(char **line);
// void	ft_error_bonus(int a);
// void	ft_cmd_bonus(char *argv, char **envp);
// char	*ft_path_bonus(char *cmd, char **envp);
#endif