/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:51:52 by rlebaill          #+#    #+#             */
/*   Updated: 2024/12/10 12:30:45 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_stop(t_data *data)
{
	pthread_mutex_lock(data->kill);
	if (data->stop)
	{
		pthread_mutex_unlock(data->kill);
		return (1);
	}
	pthread_mutex_unlock(data->kill);
	return (0);
}

static void	*observer(void *data)
{
	t_data	*d;
	t_philo	*p;

	d = (t_data *)data;
	p = d->first;
	while (d->count < d->max || !d->max)
	{
		if (is_stop(d))
			break ;
	}
	pthread_mutex_lock(d->kill);
	d->stop = 1;
	pthread_mutex_unlock(d->kill);
	return (NULL);
}

static void	*routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (ts() < (p->last_eat + p->data->time_to_die * 1000) && !p->data->stop)
	{
		take_forks(p);
		if (ts() < p->last_eat + p->data->time_to_die * 1000)
			start_eat(p);
	}
	if (!p->data->stop && (p->data->count < p->data->max || !p->data->max))
		kill(p);
	return (NULL);
}

static void	start(t_data *data)
{
	int			i;
	t_philo		*p;
	pthread_t	*thread;

	thread = malloc(sizeof(pthread_t) * (data->n + 1));
	if (!thread)
		return ;
	data->threads = thread;
	i = 0;
	p = data->first;
	while (i < data->n)
	{
		pthread_create(&thread[i], NULL, routine, p);
		p = p->next;
		i++;
	}
	pthread_create(&thread[i], NULL, observer, data);
	i = 0;
	while (i <= data->n)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	free(thread);
	free_philosophers(data->first, data->n);
}

int	main(int argc, char **argv)
{
	pthread_mutex_t	all_alive_mutex;
	pthread_mutex_t	forks_mutex;
	pthread_mutex_t	kill_mutex;
	t_data			data;

	if (check_error(argc, argv))
		return (1);
	init_data(&data, argv);
	data.all_alive = &all_alive_mutex;
	data.forks = &forks_mutex;
	data.kill = &kill_mutex;
	init_mutexes(&data);
	data.stop = 0;
	data.first = create_table(&data, data.n);
	if (!data.first)
		return (destroy_mutexes(&data), write(2, "Error malloc\n", 13));
	if (argc == 6)
		init_count(&data, argv[5]);
	start(&data);
	destroy_mutexes(&data);
	return (0);
	return (0);
}
