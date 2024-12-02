/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:25:40 by rlebaill          #+#    #+#             */
/*   Updated: 2024/11/29 12:04:05 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_path(t_game *game)
{
	int		x;
	int		y;
	int		n;
	char	**map_copy;

	map_copy = ft_split(game->str, '\n');
	x = 0;
	y = 0;
	while (y < game->map.y && map_copy[y][x] != 'P')
	{
		x = (x + 1) % game->map.x;
		y += (x == 0);
	}
	flood_fill(map_copy, x, y, game);
	n = is_exit_or_collectible(game, map_copy);
	y = game->map.y - 1;
	while (y >= 0)
	{
		free(map_copy[y]);
		y--;
	}
	free(map_copy);
	if (n)
		return (1);
	return (0);
}

static int	check_rectangle(t_game game)
{
	int	i;
	int	n;
	int	m;

	m = 0;
	i = 0;
	n = 0;
	while (game.str[i])
	{
		while (game.str[i] != '\n' && game.str[i])
		{
			i++;
			n++;
		}
		if (n != m && m)
			return (1);
		m = n;
		n = 0;
		if (game.str[i])
			i++;
	}
	return (0);
}

static int	check_letters(t_game game)
{
	int	i;
	int	e;
	int	p;
	int	c;

	i = 0;
	e = 0;
	p = 0;
	c = 0;
	while (game.str[i])
	{
		if (game.str[i] == 'E')
			e++;
		else if (game.str[i] == 'P')
			p++;
		else if (game.str[i] == 'C')
			c++;
		i++;
	}
	if (e != 1 || p != 1 || c < 1)
		return (1);
	return (0);
}

static int	check_borders(t_game game)
{
	int	i;

	i = 0;
	while (game.str[i] != '\n')
	{
		if (game.str[i] != '1')
			return (1);
		i++;
	}
	while (game.str[i + 1])
	{
		if (game.str[i] == '\n' && (game.str[i - 1] != '1'
				|| game.str[i + 1] != '1'))
			return (1);
		i++;
	}
	while (game.str[i] != '\n')
	{
		if (game.str[i] != '1')
			return (1);
		i--;
	}
	return (0);
}

int	check_map(t_game game)
{
	int	i;

	if (!game.str || game.str[0] == '\0')
		return (1);
	i = 0;
	while (game.str[i])
	{
		if (game.str[i] != '0' && game.str[i] != '1' && game.str[i] != 'P'
			&& game.str[i] != 'F'
			&& game.str[i] != 'E' && game.str[i] != 'C' && game.str[i] != '\n')
			return (1);
		i++;
	}
	if (check_borders(game) || check_letters(game) || check_rectangle(game)
		|| check_max(&game) || check_path(&game))
		return (1);
	return (0);
}
