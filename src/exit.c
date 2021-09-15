/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:56:21 by vkuklys           #+#    #+#             */
/*   Updated: 2021/08/25 19:21:48 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	free_and_exit(char **string, char **tmp_string)
{
	write(1, "ERROR OCURRED", 14);
	if (*string)
	{
		free(*string);
		*string = NULL;
	}
	if (*tmp_string)
	{
		free(*tmp_string);
		*tmp_string = NULL;
	}
	exit(EXIT_FAILURE);
}
