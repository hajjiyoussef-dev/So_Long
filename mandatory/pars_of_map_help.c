/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_of_map_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 23:14:57 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/17 00:03:18 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_position(t_game *game, int *player_x, int *player_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < ft_strlen(game->map.map[i]))
		{
			if (game->map.map[i][j] == 'P')
			{
				*player_x = i;
				*player_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	copy_map(t_game *game, char **map_copy)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		map_copy[i] = ft_strdup(game->map.map[i]);
		if (!map_copy[i])
		{
			ft_freemap(game);
			free(map_copy);
			ft_error_msg("Memory allocation failed for row copy.", game);
		}
		i++;
	}
}

int	check_valid_path(t_game *game, char **map_copy)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < ft_strlen(game->map.map[i]))
		{
			if (((game->map.map[i][j] == 'C') || (game->map.map[i][j] == 'E'))
				&& (map_copy[i][j] != 'F'))
			{
				if (map_copy[i][j] != 'F')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	validate_map_conditions(t_game *game)
{
	if (!ft_is_rectanguler(game))
		ft_error_msg("Invalid map: The map is not rectangular.", game);
	if (!ft_is_closed_by_walls(game))
		ft_error_msg("Invalid map: The map is not fully enclosed by walls.",
			game);
	if (!ft_is_valid_characters(game))
		ft_error_msg("Invalid map: The map contains an invalid character.",
			game);
	if (!ft_is_valid_path(game))
		ft_error_msg("Invalid map: No valid path exists between player, \
			collectibles, and exit.", game);
}

void	check_map_elements(int p_count, int e_count, int c_count, t_game *game)
{
	if (p_count != 1)
	{
		ft_freemap(game);
		ft_error_msg("Invalid map: There should be exactly one player :(",
			game);
	}
	if (e_count != 1)
	{
		ft_freemap(game);
		ft_error_msg("Invalid map: There should be exactly one exit :(", game);
	}
	if (c_count < 1)
	{
		ft_freemap(game);
		ft_error_msg("Invalid map: There should be at least one collectible :(",
			game);
	}
}
