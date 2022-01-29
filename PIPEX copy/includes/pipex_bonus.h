/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus1.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 14:23:56 by cyelena           #+#    #+#             */
/*   Updated: 2022/01/29 17:28:11 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

void	child_process_bonus(char *argv, char **envp);
void	ft_here_doc_bonus(char *limiter, int argc);
int		ft_file_bonus(char *argv, int i);
int		ft_gnl_bonus(char **line);
void	ft_error_bonus(int a);
void	ft_cmd_bonus(char *argv, char **envp);
char	*ft_path_bonus(char *cmd, char **envp);
#endif