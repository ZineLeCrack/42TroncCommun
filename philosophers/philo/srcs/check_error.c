/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:02:15 by rlebaill          #+#    #+#             */
/*   Updated: 2024/12/10 11:23:38 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_error(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (write(2, "./philo number_of_philosophers time_to_die", 42),
			write(2, " time_to_eat time_to_sleep ", 27),
			write(2, "(number_of_times_each_philosopher_must_eat)\n", 44));
	if (ft_atoi(av[1]) < 1)
		return (write(2, "Error: 0 or less philospher\n", 28));
	if (ft_atoi(av[1]) > 200)
		return (write(2, "Error: too many philosphers\n", 28));
	if (ft_atoi(av[2]) < 1)
		return (write(2, "Error: 0 or less time to die\n", 29));
	if (ft_atoi(av[3]) < 1)
		return (write(2, "Error: 0 or less time to eat\n", 29));
	if (ft_atoi(av[4]) < 1)
		return (write(2, "Error: 0 or less time to sleep\n", 31));
	if (ac == 6)
	{
		if (ft_atoi(av[5]) < 1)
			return (write(2,
					"Error: 0 or less time each philosopher must eat\n", 48));
	}
	return (0);
}
