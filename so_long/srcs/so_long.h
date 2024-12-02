/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:18:10 by rlebaill          #+#    #+#             */
/*   Updated: 2024/11/27 10:51:44 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"

/* STRUCTURES */

typedef struct s_worm
{
	int		x;
	int		y;
	void	*img;
	int		status;
}	t_worm;

typedef struct s_chicken
{
	int		x;
	int		y;
	void	*img;
}	t_chicken;

typedef struct s_coq
{
	int		x;
	int		y;
	void	*img;
}	t_coq;

typedef struct s_map
{
	int		x;
	int		y;
	void	*fond;
	void	*wall;
}	t_map;

typedef struct s_game
{
	void		*init;
	void		*window;
	char		*str;
	t_chicken	chicken;
	t_coq		coq;
	t_map		map;
	t_worm		*worms;
	int			number_of_worms;
}	t_game;

/* UTILS */

int			is_exit_or_collectible(t_game *game, char **map);
char		*fill_map(int fd);

/* CHECK MAP */

void		flood_fill(char **map, int x, int y, t_game *game);
int			check_path(t_game *game);
int			check_map(t_game game);
int			check_max(t_game *game);

/* CREATE */

void		put_decor(t_game *game);
t_game		create_game(char **argv);

/* WORMS */

t_worm		*create_worms(t_game *game);
void		put_worms(t_game game);
void		is_on_worm(t_game *game);
int			all_taken(t_game game);

/* COLLISIONS */

int			is_wall_right(t_game game);
int			is_wall_left(t_game game);
int			is_wall_up(t_game game);
int			is_wall_down(t_game game);

#endif