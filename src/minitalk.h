#ifndef MINITALK_H
# define MINITALK_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include <sys/wait.h>
# include <signal.h>
# include "../libft/libft.h"

typedef struct s_data
{
	int		bits_read;
	char	char_read;
	char	*string;
	char	*tmp_string;
	char	bits[9];
}				t_data;

void	free_and_exit(char **string, char **tmp_string);

#endif