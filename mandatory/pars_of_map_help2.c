/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_of_map_help2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:48:13 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/17 15:51:25 by yhajji           ###   ########.fr       */
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
