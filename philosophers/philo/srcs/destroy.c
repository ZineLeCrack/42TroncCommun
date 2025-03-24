/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:59:38 by rlebaill          #+#    #+#             */
/*   Updated: 2024/12/09 18:09:07 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_mutexes(t_data *data)
{
	pthread_mutex_destroy(data->all_alive);
	pthread_mutex_destroy(data->forks);
	pthread_mutex_destroy(data->kill);
}
