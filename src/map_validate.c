/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:25:32 by mavicent          #+#    #+#             */
/*   Updated: 2023/06/12 15:28:19 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	ft_isretangular(char **map)
{
	int	i;

	i = 1;
	if (!map)
		return (0);
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
		i++;
	}
	return (1);
}

static	int	ft_iswall(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	if (!map[i])
		return (0);
	while (map[i])
		i++;
	while (map[0][j] && map[i - 1][j])
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static	int	ft_ispec(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
			{
				game->n_player++;
				game->x_player = j;
				game->y_player = i;
			}
			else if (game->map[i][j] == 'E')
				game->n_exit++;
			else if (game->map[i][j] == 'C')
				game->n_colect++;
		}
	}
	if (game->n_player != 1 || game->n_exit != 1 || game->n_colect == 0)
		return (0);
	return (1);
}

static	int	ft_isvalidate(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(map[i][j] == 'P' || map[i][j] == 'E' || map[i][j] == 'C'
		|| map[i][j] == '0' || map[i][j] == '1'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_map_checker(t_game *game)
{
	if (ft_isretangular(game->map) && ft_iswall(game->map) && ft_ispec(game)
		&& ft_isvalidate(game->map) && ft_has_valid_path(game))
		return (1);
	return (0);
}
