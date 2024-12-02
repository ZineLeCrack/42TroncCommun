/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:41:24 by rlebaill          #+#    #+#             */
/*   Updated: 2024/12/02 10:04:01 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_chicken	create_chicken(t_game game)
{
	t_chicken	chicken;
	int			i;
	int			w;
	int			h;

	chicken.img = mlx_xpm_file_to_image(game.init,
			"img/poussin2.xpm", &w, &h);
	i = 0;
	while (game.str[i] && game.str[i] != 'E')
		i++;
	if (game.str[i] == 'E')
	{
		chicken.x = (i % (game.map.x + 1)) * 48;
		chicken.y = (i / (game.map.x + 1)) * 48;
	}
	return (chicken);
}

static t_coq	create_coq(t_game game)
{
	t_coq	coq;
	int		w;
	int		h;
	int		i;

	i = 0;
	coq.x = 0;
	coq.y = 0;
	coq.img = mlx_xpm_file_to_image(game.init, "img/coq2.xpm", &w, &h);
	while (game.str[i] && game.str[i] != 'P')
		i++;
	if (game.str[i] == 'P')
	{
		coq.x = (i % (game.map.x + 1)) * 48;
		coq.y = (i / (game.map.x + 1)) * 48;
	}
	return (coq);
}

static t_map	create_map(t_game game)
{
	t_map	map;
	int		w;
	int		h;
	int		i;

	map.fond = mlx_xpm_file_to_image(game.init,
			"img/1a.xpm", &w, &h);
	map.wall = mlx_xpm_file_to_image(game.init,
			"img/2e.xpm", &w, &h);
	map.x = 0;
	map.y = 0;
	i = 0;
	while (game.str[i])
	{
		if (game.str[i] == '\n')
			map.y++;
		else if (map.y == 0)
			map.x++;
		i++;
	}
	map.y++;
	return (map);
}

void	put_decor(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->str[i])
	{
		if (game->str[i] == '\n')
			j++;
		if (game->str[i] == '1')
			mlx_put_image_to_window(game->init, game->window, game->map.wall,
				(i - (j * (game->map.x + 1))) * 48, j * 48);
		else if (game->str[i] == 'E' && all_taken(*game))
			mlx_put_image_to_window(game->init, game->window, game->chicken.img,
				(i - (j * (game->map.x + 1))) * 48, j * 48);
		else if (i != (game->coq.y / 48) * (game->map.x + 1)
			+ (game->coq.x / 48) && game->str[i] != '\n' && game->str[i] != 'C')
			mlx_put_image_to_window(game->init, game->window, game->map.fond,
				(i - (j * (game->map.x + 1))) * 48, j * 48);
		i++;
	}
	put_worms(*game);
}

t_game	create_game(char **argv)
{
	t_game	game;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	game.str = fill_map(fd);
	if (!game.str)
		exit (1);
	if (check_map(game))
	{
		write(2, "Error\nmap error\n", 16);
		free(game.str);
		exit (1);
	}
	game.init = mlx_init();
	if (!game.init)
		exit (1);
	game.map = create_map(game);
	game.coq = create_coq(game);
	game.chicken = create_chicken(game);
	game.worms = create_worms(&game);
	return (game);
}
