/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:39:52 by vkuklys           #+#    #+#             */
/*   Updated: 2021/08/25 18:58:31 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_bit(char character, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (character & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		character = character >> 1;
		i++;
		usleep(50);
	}
	return (0);
}

/*
Making my way downtown
Walking fast, faces pass and I'm homebound
Staring blankly ahead
Just making my way
Making a way through the crowd
And I need you
And I miss you
And now I wonder
If I could fall into the sky
Do you think time would pass me by?
'Cause you know I'd walk a thousand miles
If I could just see you tonight
It's always times like these when I think of you
And wonder if you ever think of me
'Cause everything's so wrong, and I don't belong
Living in your precious memory
'Cause I need you
And I miss you
And now I wonder
If I could fall into the sky
Do you think time would pass me by?
Oh, 'cause you know I'd walk a thousand miles
If I could just see you tonight
And I, I don't wanna let you know
I, I drown in your memory
I, I don't wanna let this go
I, I don't
Making my way downtown
Walking fast, faces pass and I'm homebound
Staring blankly ahead, just making my way
Making a way through the crowd
And I s
If I could fall into the sky
Do you think time would pass us by?
'Cause you know I'd walk a thousand miles
*/

char
	*ft_add_char(char const *s1, char const *s2)
{
	int			i;
	static char	*dup;
	char		*dup_copy;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	dup = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (dup == NULL)
		return (NULL);
	dup_copy = dup;
	while (s1[i] != '\0')
	{
		*dup_copy++ = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		*dup_copy++ = s2[i];
		i++;
	}
	*dup_copy++ = '\0';
	return (dup);
}

int	read_string(char *string, int pid)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		send_bit(string[i], pid);
		i++;
	}
	send_bit('\0', pid);
	return (0);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
		return (0);
	pid = (pid_t)ft_atoi(argv[1]);
	if (ft_strlen(argv[1]) != ft_get_digit_count(pid))
		return (0);
	read_string(argv[2], pid);
	return (0);
}
