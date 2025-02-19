/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map_help_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:22:25 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/19 18:13:05 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_load_collect_img(t_game *game)
{
	int	width;
	int	height;

	width = TILE_SIZE;
	height = TILE_SIZE;
	game->arr_collect_frames[0] = mlx_xpm_file_to_image(game->mlxptr,
			COINS_XPM0, &width, &height);
	game->arr_collect_frames[1] = mlx_xpm_file_to_image(game->mlxptr,
			COINS_XPM1, &width, &height);
	game->arr_collect_frames[2] = mlx_xpm_file_to_image(game->mlxptr,
			COINS_XPM2, &width, &height);
	game->arr_collect_frames[3] = mlx_xpm_file_to_image(game->mlxptr,
			COINS_XPM3, &width, &height);
	if (!game->arr_collect_frames[0] || !game->arr_collect_frames[1]
		|| !game->arr_collect_frames[2] || !game->arr_collect_frames[3])
	{
		ft_mlxfree(game, 1);
		ft_freemap(game);
		ft_error_msg("Failed to load coin animation frames.", game);
	}
	game->current_collect_frame = 0;
	game->frame_counter = 0;
}
