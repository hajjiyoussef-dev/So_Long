/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_and_pars_map_help2_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 23:28:54 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/20 17:29:44 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_creat_new_enemy(t_game *game, int *i, int *j)
{
	t_enemy	*new_enemy;

	new_enemy = malloc(sizeof(t_enemy));
	if (!new_enemy)
	{
		ft_freemap(game);
		ft_error_msg("Memory allocation failed for enemy. ", game);
	}
	new_enemy->x = *j;
	new_enemy->y = *i;
	new_enemy->direction = 1;
	new_enemy->next = game->enemy;
	game->enemy = new_enemy;
}

void	ft_create_new_collec(t_game *game, int *i, int *j)
{
	t_collectible	*new_collectible;

	new_collectible = malloc(sizeof(t_collectible));
	if (!new_collectible)
	{
		ft_freemap(game);
		ft_error_msg("Memory allocation failed for collectible.", game);
	}
	new_collectible->x = *i;
	new_collectible->y = *j;
	new_collectible->next = game->collect;
	game->collect = new_collectible;
	game->total_collectibles++;
}

void	ft_check_map_size(t_game *game)
{
	int	map_size_h;
	int	map_size_w;

	map_size_w = 0;
	map_size_w = ft_strlen(game->map.map[0]);
	map_size_h = 0;
	while (game->map.map[map_size_h])
		map_size_h++;
	if (map_size_w * TILE_SIZE > 2560 || map_size_h * TILE_SIZE > 1440)
	{
		if (game->mlxptr)
		{
			mlx_destroy_display(game->mlxptr);
			free(game->mlxptr);
		}
		ft_free_enemy(game);
		ft_freecollectible(game);
		ft_freemap(game);
		ft_error_msg("Failed to load map is too long.", game);
	}
}
