/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:47:04 by rlebaill          #+#    #+#             */
/*   Updated: 2024/12/10 09:20:37 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int		resultat;
	int		signe;
	int		i;

	resultat = 0;
	signe = 1;
	i = 0;
	while (whitespace(str[i]) == 1)
		i++;
	if (str[i] == '-')
		signe *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10 + (str[i] - '0');
		i++;
	}
	return (signe * resultat);
}

long long	ts(void)
{
	long long int	ts;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	ts = tv.tv_sec * 1000000 + tv.tv_usec;
	return (ts);
}

void	kill(t_philo *philo)
{
	pthread_mutex_lock(philo->data->kill);
	if (philo->data->stop)
	{
		pthread_mutex_unlock(philo->data->kill);
		return ;
	}
	printf("\033[31m%lld %d died\n\033[0m", ts() / 1000, philo->id);
	philo->dead = 1;
	philo->data->stop = 1;
	pthread_mutex_unlock(philo->data->kill);
}

void	free_philosophers(t_philo *philo, int n)
{
	t_philo	*p;
	int		i;

	p = philo;
	i = 1;
	while (i < n)
	{
		p = p->next;
		free(p->prev);
		i++;
	}
	free(p);
}
