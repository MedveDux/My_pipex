/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:14:41 by cyelena           #+#    #+#             */
/*   Updated: 2022/01/22 16:01:15 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>

void	child_process(char **argv, char **envp, int *fd);
void	child2_process(char **argv, char **envp, int *fd);
char	*ft_path(char *cmd, char **envp);
void	ft_cmd(char *argv, char **envp);
void	ft_error(int a);
#endif