/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 02:55:04 by mavicent          #+#    #+#             */
/*   Updated: 2023/06/12 13:47:29 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *message)
{
	ft_printf("Error\n%s", message);
	exit(1);
}

static	int	ft_argv_checker(char *argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == 'r' && argv[i - 1] == 'e'
		&& argv[i - 2] == 'b' && argv[i - 3] == '.')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		ft_bzero(&game, sizeof(t_game));
		game.map = ft_read_map(argv[1], &game);
		if (ft_map_checker(&game) && ft_argv_checker(argv[1]))
		{
			ft_start_game(&game);
			ft_gameplay(&game);
			mlx_loop(game.mlx);
		}
		else
		{
			if (game.map)
				ft_free_map(game.map);
			ft_error("Invalid map");
		}
	}
	else
		ft_error("Invalid Syntaxe");
	return (0);
}
