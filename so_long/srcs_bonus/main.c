/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:33:43 by rlebaill          #+#    #+#             */
/*   Updated: 2024/12/02 10:17:48 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_window(t_game *game)
{
	int	i;

	i = game->number_of_worms;
	while (--i >= 0)
		mlx_destroy_image(game->init, game->worms[i].img);
	i = game->number_of_foxes;
	while (--i >= 0)
		mlx_destroy_image(game->init, game->foxes[i].img);
	free(game->worms);
	free(game->foxes);
	free(game->str);
	mlx_destroy_image(game->init, game->map.wall);
	mlx_destroy_image(game->init, game->map.fond);
	mlx_destroy_image(game->init, game->chicken.img);
	mlx_destroy_image(game->init, game->coq.img);
	mlx_destroy_window(game->init, game->window);
	mlx_destroy_display(game->init);
	free(game->init);
	exit(0);
	return (0);
}

char	*fill_map(int fd)
{
	ssize_t	bytes_read;
	char	*map;

	map = malloc(1000);
	if (!map)
	{
		write(2, "Error\nmemory allocation failed\n", 32);
		return (NULL);
	}
	bytes_read = read(fd, map, 1000 - 1);
	if (bytes_read < 0)
	{
		write(2, "Error\nfailed to read file\n", 26);
		free(map);
		return (NULL);
	}
	map[bytes_read] = '\0';
	if (bytes_read == 0)
	{
		write(2, "Error\nempty file\n", 17);
		free(map);
		return (NULL);
	}
	return (map);
}

static int	key_press(int key, t_game *game)
{
	if (key == 65307)
		close_window(game);
	else if (key == 115 && game->coq.y < (game->map.y - 1) * 48
		&& is_wall_down(*game))
		game->coq.y += 48;
	else if (key == 119 && game->coq.y > 47 && is_wall_up(*game))
		game->coq.y -= 48;
	else if (key == 100 && game->coq.x < (game->map.x - 1) * 48
		&& is_wall_right(*game))
		game->coq.x += 48;
	else if (key == 97 && game->coq.x > 47 && is_wall_left(*game))
		game->coq.x -= 48;
	else
		return (0);
	game->count++;
	return (0);
}

static int	loop(t_game *game)
{
	put_decor(game);
	mlx_put_image_to_window(game->init, game->window, game->coq.img,
		game->coq.x, game->coq.y);
	if (is_on_fox(game))
	{
		ft_printf("Game over\n");
		close_window(game);
	}
	if (game->coq.x == game->chicken.x && game->coq.y == game->chicken.y
		&& all_taken(*game))
	{
		ft_printf("You won !\n");
		close_window(game);
	}
	is_on_worm(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game = create_game(argv);
		game.window = mlx_new_window(game.init, game.map.x * 48,
				game.map.y * 48, "so_long");
		if (!game.window)
			return (write(2, "Error\n", 6),
				free(game.str), free(game.worms), 1);
		mlx_hook(game.window, 17, 0, close_window, &game);
		mlx_key_hook(game.window, key_press, &game);
		mlx_loop_hook(game.init, loop, &game);
		mlx_loop(game.init);
		free(game.str);
		free(game.worms);
	}
	else
		return (write(2, "Error\narguments error\n", 22), 1);
	return (0);
}
