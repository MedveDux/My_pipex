/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:14:41 by cyelena           #+#    #+#             */
/*   Updated: 2022/01/30 17:17:43 by cyelena          ###   ########.fr       */
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
#endif