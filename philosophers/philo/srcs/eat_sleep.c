/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:36:38 by rlebaill          #+#    #+#             */
/*   Updated: 2025/03/17 09:32:57 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_forks(t_philo *p)
{
	int	l;
	int	r;

	l = 0;
	r = 0;
	while ((!r || !l) && ts() < p->last_eat + p->data->time_to_die * 1000)
	{
		pthread_mutex_lock(p->data->forks);
		if (is_stop(p->data))
			return (pthread_mutex_unlock(p->data->forks), 0);
		if (p->l_fork == true && p->next->r_fork == true && !p->data->stop)
		{
			p->l_fork = false;
			p->next->r_fork = false;
			l = printf("\033[0m%lld %d has taken a fork\n", ts() / 1000, p->id);
		}
		if (p->r_fork == true && p->prev->l_fork == true && !p->data->stop)
		{
			p->r_fork = false;
			p->prev->l_fork = false;
			r = printf("\033[0m%lld %d has taken a fork\n", ts() / 1000, p->id);
		}
		pthread_mutex_unlock(p->data->forks);
	}
	return (0);
}

static void	wait(t_data *data, long long start, long long t)
{
	while (1)
	{
		pthread_mutex_lock(data->kill);
		if (data->stop || ts() > start + t * 1000)
			break ;
		pthread_mutex_unlock(data->kill);
	}
	pthread_mutex_unlock(data->kill);
}

static void	start_sleep(t_philo *philo)
{
	long long	start;

	start = ts();
	wait(philo->data, start, philo->data->sleep);
	if (!is_stop(philo->data))
		printf("\033[33m%lld %d is thinking\n", ts() / 1000, philo->id);
}

void	start_eat(t_philo *philo)
{
	long long	start;

	philo->last_eat = ts();
	if (!is_stop(philo->data))
	{
		printf("\033[32m%lld %d is eating\n", ts() / 1000, philo->id);
		philo->data->count++;
		start = ts();
		wait(philo->data, start, philo->data->eat);
	}
	if (!is_stop(philo->data))
	{
		printf("\033[34m%lld %d is sleeping\n", ts() / 1000, philo->id);
		pthread_mutex_lock(philo->data->forks);
		philo->l_fork = true;
		philo->r_fork = true;
		philo->prev->l_fork = true;
		philo->next->r_fork = true;
		pthread_mutex_unlock(philo->data->forks);
		start_sleep(philo);
	}
}
