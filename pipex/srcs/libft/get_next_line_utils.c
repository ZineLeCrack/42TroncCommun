/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:03:45 by rlebaill          #+#    #+#             */
/*   Updated: 2024/11/27 18:34:00 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strcpy(char *buff, char *new_buff)
{
	int	i;

	if (!new_buff)
		return ;
	i = 0;
	while (i < BUFFER_SIZE)
	{
		buff[i] = '\0';
		i++;
	}
	i = 0;
	while (new_buff[i] && i < BUFFER_SIZE)
	{
		buff[i] = new_buff[i];
		i++;
	}
}
