/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:25:07 by mavicent          #+#    #+#             */
/*   Updated: 2023/06/12 13:42:10 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_img_draw(t_game *game, void *image, int x, int y)
{
	if (!image)
		ft_error("Invalid Map");
	mlx_put_image_to_window(game->mlx, game->win, image, x * 32, y * 32);
}

static	void	ft_player_draw(t_game *game, void *image, int x, int y)
{
	game->x_player = x;
	game->y_player = y;
	ft_img_draw(game, image, x, y);
}

static	void	exit_draw(t_game *game, int x, int y)
{
	if (game->n_colect == 0)
	{
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image
			(game->mlx, "img/exit_2.xpm", &game->img_w, &game->img_h);
		ft_img_draw(game, game->img_exit, x, y);
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image
			(game->mlx, "img/exit_3.xpm", &game->img_w, &game->img_h);
	}
	ft_img_draw(game, game->img_exit, x, y);
}

int	ft_map_draw(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				ft_img_draw(game, game->img_wall, x, y);
			else if (game->map[y][x] == '0')
				ft_img_draw(game, game->img_backg, x, y);
			else if (game->map[y][x] == 'P')
				ft_player_draw(game, game->img_player, x, y);
			else if (game->map[y][x] == 'C')
				ft_img_draw(game, game->img_colect, x, y);
			else if (game->map[y][x] == 'E')
				exit_draw(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
