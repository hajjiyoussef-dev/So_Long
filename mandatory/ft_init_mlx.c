/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:38:33 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/16 23:04:42 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_mlx(t_game *game)
{
	game->mlxptr = mlx_init();
	if (!game->mlxptr)
	{
		ft_freemap(game);
		ft_freecollectible(game);
		ft_error_msg("Failed to initialize MiniLibX.", game);
	}
}

void	ft_load_images(t_game *game)
{
	int	img_withe;
	int	img_height;
	int	window_width;
	int	window_height;

	img_withe = TILE_SIZE;
	img_height = TILE_SIZE;
	window_width = game->map.cols * TILE_SIZE;
	window_height = game->map.rows * TILE_SIZE;
	game->wall_img = mlx_xpm_file_to_image(game->mlxptr, WALL_XPM, &img_withe,
			&img_height);
	game->collect_img = mlx_xpm_file_to_image(game->mlxptr, COINS_XPM,
			&img_withe, &img_height);
	game->exit_closed_img = mlx_xpm_file_to_image(game->mlxptr, EXIT_CLOSED_XPM,
			&img_withe, &img_height);
	game->exit_open_img = mlx_xpm_file_to_image(game->mlxptr, OPEN_EXIT_XPM,
			&img_withe, &img_height);
	game->player_img = mlx_xpm_file_to_image(game->mlxptr, PLAYER_XPM,
			&img_withe, &img_height);
	game->floor_img = mlx_xpm_file_to_image(game->mlxptr, FLOOR_XPM, &img_withe,
			&img_height);
	if (!game->wall_img || !game->player_img || !game->exit_closed_img
		|| !game->exit_open_img || !game->collect_img || !game->floor_img)
	{
		ft_mlxfree(game);
		ft_freecollectible(game);
		ft_freemap(game);
		ft_error_msg("Failed to load images.", game);
	}
	game->window = mlx_new_window(game->mlxptr, window_width, window_height,
			"so_long");
	if (!game->window)
	{
		mlx_destroy_display(game->mlxptr);
		ft_freemap(game);
		ft_freecollectible(game);
		free(game->mlxptr);
		ft_error_msg("Failed to create window.", game);
	}
}
