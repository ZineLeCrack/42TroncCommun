/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:31:28 by rlebaill          #+#    #+#             */
/*   Updated: 2024/12/02 09:40:21 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_max(t_game *game)
{
	t_map	map;
	int		i;

	i = 0;
	map.x = 0;
	map.y = 0;
	while (game->str[i])
	{
		if (game->str[i] == '\n')
			map.y++;
		else if (map.y == 0)
			map.x++;
		i++;
	}
	map.y++;
	if (map.y > 21 || map.x > 40)
		return (1);
	game->map = map;
	return (0);
}

int	is_exit_or_collectible(t_game *game, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map.y)
	{
		x = 0;
		while (x < game->map.x)
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	put_count(t_game game)
{
	char	*str;

	str = ft_itoa(game.count);
	mlx_string_put(game.init, game.window, (game.map.x - 1) * 48 + 20,
		(game.map.y - 1) * 48 + 27, 0x0000FF, str);
	free(str);
}
