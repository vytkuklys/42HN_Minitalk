/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:37:07 by vkuklys           #+#    #+#             */
/*   Updated: 2021/08/25 19:12:16 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	initialise_data(t_data *data)
{
	data->bits_read = 0;
	data->char_read = '\0';
	ft_bzero(data->bits, 9);
	data->tmp_string = NULL;
	data->string = ft_calloc(1, 1);
	if (data->string == NULL)
		free_and_exit(&data->string, &data->tmp_string);
}

static char	bits_to_char(char *binary)
{
	char	char_read;
	int		decimal;
	int		power;
	int		i;

	if (binary == NULL || ft_strlen(binary) != 8)
		return (0);
	decimal = 0;
	power = 0;
	i = 0;
	while (i <= 7)
	{
		decimal += (binary[i] - 48) * ft_pow(2, power);
		power++;
		i++;
	}
	char_read = (char)decimal;
	return (char_read);
}

static void	display_string(t_data *data)
{
	ft_putstr_fd(data->string, 1);
	write(1, "\n", 1);
	free(data->string);
	data->bits_read = 0;
}

static void	signal_to_bit(int signum)
{
	static t_data	data;
	int				index;

	if (!data.bits_read)
		initialise_data(&data);
	index = data.bits_read++ % 8;
	if (signum == 30)
		data.bits[index] = '1';
	else
		data.bits[index] = '0';
	if (index == 7)
	{
		data.char_read = bits_to_char(data.bits);
		if (data.char_read == '\0')
			display_string(&data);
		else
		{
			data.tmp_string = data.string;
			data.string = ft_strjoin(data.tmp_string, &data.char_read);
			if (data.string == NULL)
				free_and_exit(&data.string, &data.tmp_string);
			free(data.tmp_string);
		}
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, signal_to_bit);
	signal(SIGUSR2, signal_to_bit);
	while (1)
		pause();
	return (0);
}
