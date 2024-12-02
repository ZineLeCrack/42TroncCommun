/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foxes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:22:13 by rlebaill          #+#    #+#             */
/*   Updated: 2024/11/29 12:12:31 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_fox	create_fox(t_game game, int i)
{
	t_fox	fox;
	int		w;
	int		h;

	fox.x = (i % (game.map.x + 1)) * 48;
	fox.y = (i / (game.map.x + 1)) * 48;
	fox.img = mlx_xpm_file_to_image(game.init,
			"img/fox.xpm", &w, &h);
	return (fox);
}

t_fox	*create_foxes(t_game *game)
{
	t_fox	*foxes;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (game->str[i])
	{
		if (game->str[i] == 'F')
			n++;
		i++;
	}
	foxes = malloc(sizeof(t_fox) * n);
	game->number_of_foxes = n;
	i = -1;
	n = 0;
	while (game->str[++i])
	{
		if (game->str[i] == 'F')
		{
			foxes[n] = create_fox(*game, i);
			n++;
		}
	}
	return (foxes);
}

void	put_foxes(t_game game)
{
	int	i;

	i = game.number_of_foxes - 1;
	while (i >= 0)
	{
		mlx_put_image_to_window(game.init, game.window, game.foxes[0].img,
			game.foxes[i].x, game.foxes[i].y);
		i--;
	}
}

int	is_on_fox(t_game *game)
{
	int	i;

	i = game->number_of_foxes - 1;
	while (i >= 0)
	{
		if (game->coq.x == game->foxes[i].x && game->coq.y == game->foxes[i].y)
			return (1);
		i--;
	}
	return (0);
}
