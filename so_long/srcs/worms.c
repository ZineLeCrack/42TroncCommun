/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:58:37 by rlebaill          #+#    #+#             */
/*   Updated: 2024/11/26 16:39:59 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_worm	create_worm(t_game game, int i)
{
	t_worm	worm;
	int		w;
	int		h;

	worm.status = 1;
	worm.x = (i % (game.map.x + 1)) * 48;
	worm.y = (i / (game.map.x + 1)) * 48;
	worm.img = mlx_xpm_file_to_image(game.init,
			"img/worm.xpm", &w, &h);
	return (worm);
}

t_worm	*create_worms(t_game *game)
{
	t_worm	*worms;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (game->str[i])
	{
		if (game->str[i] == 'C')
			n++;
		i++;
	}
	worms = malloc(sizeof(t_worm) * n);
	game->number_of_worms = n;
	i = -1;
	n = 0;
	while (game->str[++i])
	{
		if (game->str[i] == 'C')
		{
			worms[n] = create_worm(*game, i);
			n++;
		}
	}
	return (worms);
}

void	put_worms(t_game game)
{
	int	i;

	i = game.number_of_worms - 1;
	while (i >= 0)
	{
		if (game.worms[i].status)
			mlx_put_image_to_window(game.init, game.window, game.worms[0].img,
				game.worms[i].x, game.worms[i].y);
		else
			mlx_put_image_to_window(game.init, game.window, game.map.fond,
				game.worms[i].x, game.worms[i].y);
		i--;
	}
}

void	is_on_worm(t_game *game)
{
	int	i;

	i = game->number_of_worms - 1;
	while (i >= 0)
	{
		if (game->coq.x == game->worms[i].x && game->coq.y == game->worms[i].y)
			game->worms[i].status = 0;
		i--;
	}
}

int	all_taken(t_game game)
{
	int	i;

	i = game.number_of_worms - 1;
	while (i >= 0)
	{
		if (game.worms[i].status)
			return (0);
		i--;
	}
	return (1);
}
