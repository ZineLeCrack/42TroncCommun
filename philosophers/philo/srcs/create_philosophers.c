/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:02:34 by rlebaill          #+#    #+#             */
/*   Updated: 2024/12/10 11:14:21 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_data(t_data *data, char **argv)
{
	data->n = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->eat = ft_atoi(argv[3]);
	data->sleep = ft_atoi(argv[4]);
	data->count = 0;
	data->max = 0;
	data->stop = 0;
	data->first = NULL;
}

void	init_mutexes(t_data *data)
{
	pthread_mutex_init(data->all_alive, NULL);
	pthread_mutex_init(data->forks, NULL);
	pthread_mutex_init(data->kill, NULL);
}

void	init_count(t_data *data, char *str)
{
	data->count = 0;
	data->max = ft_atoi(str);
}

static t_philo	*new_philo(int id)
{
	t_philo			*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->r_fork = true;
	philo->l_fork = true;
	philo->dead = false;
	philo->id = id;
	philo->next = NULL;
	philo->prev = NULL;
	philo->data = NULL;
	philo->last_eat = ts();
	return (philo);
}

t_philo	*create_table(t_data *data, int n)
{
	t_philo			*first_philo;
	t_philo			*philo;
	int				id;

	id = 1;
	first_philo = new_philo(id);
	first_philo->data = data;
	philo = first_philo;
	while (id < n)
	{
		id++;
		philo->next = new_philo(id);
		if (!philo->next)
			return (free_philosophers(first_philo, first_philo->data->n), NULL);
		philo->next->prev = philo;
		philo = philo->next;
		philo->data = data;
	}
	philo->next = first_philo;
	first_philo->prev = philo;
	return (first_philo);
}
