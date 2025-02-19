/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_of_map_help2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:28:45 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/18 21:51:28 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_is_rectanguler(t_game *game)
{
	int	i;
	int	width;

	width = ft_strlen(game->map.map[0]);
	i = 0;
	if (game->map.rows <= 0)
		return (0);
	while (i < game->map.rows)
	{
		if (ft_strlen(game->map.map[i]) != width)
		{
			ft_freemap(game);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_is_closed_by_walls(t_game *game)
{
	int	i;
	int	width;

	width = ft_strlen(game->map.map[0]);
	i = 0;
	while (i < width)
	{
		if (game->map.map[0][i] != '1' || game->map.map[game->map.rows
			- 1][i] != '1')
			return (ft_freemap(game), 0);
		i++;
	}
	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.map[i][0] != '1' || game->map.map[i][width - 1] != '1')
			return (ft_freemap(game), 0);
		i++;
	}
	return (1);
}

int	ft_enemy_blocked(char **map_copy, int x, int y, t_game *game)
{
	if (map_copy[x][y] != 'M')
		return (0);
	if ((y > 0 && (map_copy[x][y - 1] == '1' || map_copy[x][y - 1] == 'C'))
		|| (y < game->map.cols - 1 && (map_copy[x][y + 1] == '1'
				|| map_copy[x][y + 1] == 'C')) || (y < game->map.cols - 2
			&& (map_copy[x][y + 2] == '1' || map_copy[x][y + 2] == 'C')))
		return (1);
	return (0);
}

int	ft_count_enemies(char **map_copy, int x, t_game *game)
{
	int	j;
	int	enemy_count;

	j = 0;
	enemy_count = 0;
	while (j < game->map.cols)
	{
		if (map_copy[x][j] == 'M')
			enemy_count++;
		j++;
	}
	return (enemy_count);
}
