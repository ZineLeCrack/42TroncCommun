/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:55:54 by rlebaill          #+#    #+#             */
/*   Updated: 2024/12/10 11:16:23 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct s_philo
{
	int				id;
	bool			dead;
	bool			r_fork;
	bool			l_fork;
	long long		last_eat;
	struct s_data	*data;
	struct s_philo	*next;
	struct s_philo	*prev;
}	t_philo;

typedef struct s_data
{
	int				count;
	int				max;
	int				n;
	int				stop;
	long long		time_to_die;
	long long		eat;
	long long		sleep;
	pthread_t		*threads;
	pthread_mutex_t	*all_alive;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*kill;
	struct s_philo	*first;
}	t_data;

/* CHECK_ERROR */

int			check_error(int ac, char **av);

/* DESTROY */

void		destroy_mutexes(t_data *data);

/* CREATE PHILOSOPHERS */

void		init_count(t_data *data, char *str);
void		init_data(t_data *data, char **argv);
t_philo		*create_table(t_data *data, int n);
void		init_mutexes(t_data *data);

/* EAT AND SLEEP */

int			take_forks(t_philo *philo);
void		start_eat(t_philo *philo);

/* UTILS */

long long	ts(void);
int			is_stop(t_data *data);
int			ft_atoi(char *str);
void		free_philosophers(t_philo *philo, int n);
void		kill(t_philo *philo);

#endif