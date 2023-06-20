/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:14:15 by mavicent          #+#    #+#             */
/*   Updated: 2023/06/12 13:48:28 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_w(t_game *game)
{
	if (game->map[game->y_player][game->x_player] == 'E' && game->n_colect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_player + 1][game->x_player] = '0';
		game->moves++;
		game->endgame = 1;
		ft_map_draw(game);
		if (game->endgame == 1)
			ft_exit_game(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
		|| game->map[game->y_player][game->x_player] == 'E')
		game->y_player += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player + 1][game->x_player] = '0';
		game->moves++;
		ft_map_draw(game);
	}
}

void	player_s(t_game *game)
{
	if (game->map[game->y_player][game->x_player] == 'E'
		&& game->n_colect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_player - 1][game->x_player] = '0';
		game->moves++;
		game->endgame = 1;
		ft_map_draw(game);
		if (game->endgame == 1)
			ft_exit_game(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
		|| game->map[game->y_player][game->x_player] == 'E')
		game->y_player -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player - 1][game->x_player] = '0';
		game->moves++;
		ft_map_draw(game);
	}
}

void	player_d(t_game *game)
{
	if (game->map[game->y_player][game->x_player] == 'E'
		&& game->n_colect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_player][game->x_player - 1] = '0';
		game->moves++;
		game->endgame = 1;
		ft_map_draw(game);
		if (game->endgame == 1)
			ft_exit_game(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
		|| game->map[game->y_player][game->x_player] == 'E')
		game->x_player -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player - 1] = '0';
		game->moves++;
		ft_map_draw(game);
	}
}

void	player_a(t_game *game)
{
	if (game->map[game->y_player][game->x_player] == 'E'
		&& game->n_colect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		game->endgame = 1;
		ft_map_draw(game);
		if (game->endgame == 1)
			ft_exit_game(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
		|| game->map[game->y_player][game->x_player] == 'E')
		game->x_player += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		ft_map_draw(game);
	}
}
