/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_of_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:22:45 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/20 17:38:06 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
				&& game->map.map[i][j] != 'M' && game->map.map[i][j] != '0')
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

void	ft_flood_fill(char **map_copy, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->map.rows || y >= game->map.cols
		|| map_copy[x][y] == '1' || map_copy[x][y] == 'F')
		return ;
	if (ft_enemy_blocked(map_copy, x, y, game) || ft_count_enemies(map_copy, x,
			game) > 2)
		return ;
	map_copy[x][y] = 'F';
	ft_flood_fill(map_copy, x + 1, y, game);
	ft_flood_fill(map_copy, x - 1, y, game);
	ft_flood_fill(map_copy, x, y + 1, game);
	ft_flood_fill(map_copy, x, y - 1, game);
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
	ft_flood_fill(map_copy, player_x, player_y, game);
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

	i = 0;
	(1) && (palyer_count = 0, exit_count = 0, colle_count = 0);
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
