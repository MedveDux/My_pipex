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

void	child_process(char *argv, char **envp);
void	ft_here_doc(char *limiter, int argc);
void	ft_usage(void);
int		ft_file(char *argv, int i);
int		next_line(char **line);
char	*ft_cmd2(char *cmd, char **envp);
void	ft_error(void);
void	ft_cmd(char *argv, char **envp);
#endif