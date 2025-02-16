/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_of_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:40:26 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/16 23:06:13 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_is_valid_characters(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.map[i][j] != '1' && game->map.map[i][j] != 'P'
				&& game->map.map[i][j] != 'C' && game->map.map[i][j] != 'E'
				&& game->map.map[i][j] != '0')
			{
				ft_freemap(game);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_floo_fill(char **map_copy, int x, int y, int rows, int clos)
{
	if (x < 0 || y < 0 || x >= rows || y >= clos)
		return ;
	if (map_copy[x][y] == '1' || map_copy[x][y] == 'F')
		return ;
	map_copy[x][y] = 'F';
	ft_floo_fill(map_copy, x + 1, y, rows, clos);
	ft_floo_fill(map_copy, x - 1, y, rows, clos);
	ft_floo_fill(map_copy, x, y + 1, rows, clos);
	ft_floo_fill(map_copy, x, y - 1, rows, clos);
}

int	ft_is_valid_path(t_game *game)
{
	int		player_x;
	int		player_y;
	char	**map_copy;

	player_x = -1;
	player_y = -1;
	find_player_position(game, &player_x, &player_y);
	if (player_x == -1 || player_y == -1)
	{
		ft_freemap(game);
		ft_error_msg("Invalid map: No player position found.", game);
	}
	map_copy = malloc(sizeof(char *) * (game->map.rows));
	if (!map_copy)
	{
		ft_freemap(game);
		ft_error_msg("Memory allocation failed for map copy.", game);
	}
	copy_map(game, map_copy);
	ft_floo_fill(map_copy, player_x, player_y, game->map.rows, game->map.cols);
	if (!check_valid_path(game, map_copy))
		return (ft_free_map_copy(map_copy, game->map.rows), ft_freemap(game),
			0);
	ft_free_map_copy(map_copy, game->map.rows);
	return (1);
}

void	ft_validate_map(t_game *game)
{
	int	palyer_count;
	int	exit_count;
	int	colle_count;
	int	i;
	int	j;

	palyer_count = 0;
	exit_count = 0;
	colle_count = 0;
	i = 0;
	validate_map_conditions(game);
	while (i < game->map.rows)
	{
		j = 0;
		while (j < ft_strlen(game->map.map[i]))
		{
			if (game->map.map[i][j] == 'P')
				palyer_count++;
			else if (game->map.map[i][j] == 'C')
				colle_count++;
			else if (game->map.map[i][j] == 'E')
				exit_count++;
			j++;
		}
		i++;
	}
	check_map_elements(palyer_count, exit_count, colle_count, game);
}
