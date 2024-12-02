/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:10:13 by rlebaill          #+#    #+#             */
/*   Updated: 2024/11/26 17:52:15 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->map.x || y >= game->map.y)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
}

int	is_wall_right(t_game game)
{
	int	i;

	i = (game.coq.y / 48) * (game.map.x + 1) + (game.coq.x / 48) + 1;
	if (game.str[i] == '1')
		return (0);
	return (1);
}

int	is_wall_left(t_game game)
{
	int	i;

	i = (game.coq.y / 48) * (game.map.x + 1) + (game.coq.x / 48) - 1;
	if (game.str[i] == '1')
		return (0);
	return (1);
}

int	is_wall_up(t_game game)
{
	int	i;

	i = (game.coq.y / 48 - 1) * (game.map.x + 1) + (game.coq.x / 48);
	if (game.str[i] == '1')
		return (0);
	return (1);
}

int	is_wall_down(t_game game)
{
	int	i;

	i = (game.coq.y / 48 + 1) * (game.map.x + 1) + (game.coq.x / 48);
	if (game.str[i] == '1')
		return (0);
	return (1);
}
