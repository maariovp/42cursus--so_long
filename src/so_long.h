/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 02:31:29 by mavicent          #+#    #+#             */
/*   Updated: 2023/06/12 13:47:05 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/minilibx/mlx.h"
# include "../libraries/libft/libft.h"
# include "../libraries/get_next_line/get_next_line.h"
# include "../libraries/ft_printf/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct t_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_backg;
	void	*img_wall;
	void	*img_player;
	void	*img_colect;
	void	*img_exit;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		n_colect;
	int		n_player;
	int		n_exit;
	int		x_player;
	int		y_player;
	int		moves;
	int		endgame;
	int		rows;
}	t_game;

# define KEY_ESC 65307
# define KEY_Q 113

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

char	**ft_read_map(char *path, t_game *game);
int		ft_exit_game(t_game *game);
int		ft_map_draw(t_game *game);
int		ft_map_checker(t_game *game);
void	ft_img_draw(t_game *game, void *image, int x, int y);
void	ft_start_game(t_game *game);
void	ft_gameplay(t_game *game);
void	player_w(t_game *game);
void	player_d(t_game *game);
void	player_s(t_game *game);
void	player_a(t_game *game);
void	ft_free_map(char **map);
void	ft_error(char *message);
bool	ft_has_valid_path(t_game *game);

#endif