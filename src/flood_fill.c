/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:29:00 by mavicent          #+#    #+#             */
/*   Updated: 2023/06/12 15:29:04 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ft_flood_fill(t_game *game, int x, int y, char **matrix_map)
{
	static int		coins = 0;
	static bool		found_exit = false;

	if (matrix_map[y][x] == '1')
		return (false);
	else if (matrix_map[y][x] == 'C')
		coins++;
	else if (matrix_map[y][x] == 'E')
	{
		found_exit = true;
		return (false);
	}
	matrix_map[y][x] = '1';
	ft_flood_fill(game, x + 1, y, matrix_map);
	ft_flood_fill(game, x - 1, y, matrix_map);
	ft_flood_fill(game, x, y + 1, matrix_map);
	ft_flood_fill(game, x, y - 1, matrix_map);
	return (coins == game->n_colect && found_exit);
}

void	ft_matrix_delete(char **matrix)
{
	size_t	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

bool	ft_has_valid_path(t_game *game)
{
	char	**dup;
	bool	is_valid;
	int		i;

	i = 0;
	dup = ft_calloc(game->rows + 1, sizeof(char *));
	if (!dup)
		ft_printf("Failed allocation on has_valid_path()\n");
	while (i < game->rows)
	{
		dup[i] = ft_strdup(game->map[i]);
		if (!dup[i])
		{
			ft_matrix_delete(dup);
			ft_printf("Failed allocation on has_valid_path()\n");
		}
		i++;
	}
	is_valid = ft_flood_fill(game, game->x_player, game->y_player, dup);
	ft_matrix_delete(dup);
	return (is_valid);
}
