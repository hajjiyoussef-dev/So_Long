/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:29:47 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/19 18:57:46 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_draw_empty(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlxptr, game->window, game->floor_img, (x
			* TILE_SIZE), (y * TILE_SIZE));
}

void	ft_draw_enemy(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlxptr, game->window, game->enemy_img, (x
			* TILE_SIZE), (y * TILE_SIZE));
}

void	ft_init_mlx(t_game *game)
{
	game->mlxptr = mlx_init();
	if (!game->mlxptr)
	{
		ft_free_enemy(game);
		ft_freemap(game);
		ft_freecollectible(game);
		ft_error_msg("Failed to initialize MiniLibX.", game);
	}
}

void	ft_load_img_help(t_game *game)
{
	int	img_withe;
	int	img_height;

	img_withe = TILE_SIZE;
	img_height = TILE_SIZE;
	game->wall_img = mlx_xpm_file_to_image(game->mlxptr, WALL_XPM, &img_withe,
			&img_height);
	game->exit_closed_img = mlx_xpm_file_to_image(game->mlxptr, EXIT_CLOSED_XPM,
			&img_withe, &img_height);
	game->exit_open_img = mlx_xpm_file_to_image(game->mlxptr, OPEN_EXIT_XPM,
			&img_withe, &img_height);
	game->player_img = mlx_xpm_file_to_image(game->mlxptr, PLAYER_XPM,
			&img_withe, &img_height);
	game->floor_img = mlx_xpm_file_to_image(game->mlxptr, FLOOR_XPM, &img_withe,
			&img_height);
	game->enemy_img = mlx_xpm_file_to_image(game->mlxptr, ENEMY_XPM, &img_withe,
			&img_height);
	game->player_over_it_img = mlx_xpm_file_to_image(game->mlxptr, PLAYER_O_IT,
			&img_withe, &img_height);
}

void	ft_load_images(t_game *game)
{
	int	window_width;
	int	window_height;

	ft_check_map_size(game);
	window_width = game->map.cols * TILE_SIZE;
	window_height = game->map.rows * TILE_SIZE;
	ft_load_img_help(game);
	if (!game->wall_img || !game->player_img || !game->exit_closed_img
		|| !game->exit_open_img || !game->floor_img || !game->enemy_img
		|| !game->player_over_it_img)
	{
		ft_mlxfree(game, 0);
		ft_freemap(game);
		ft_error_msg("Failed to load images.", game);
	}
	game->window = mlx_new_window(game->mlxptr, window_width, window_height,
			"so_long");
	if (!game->window)
	{
		ft_free_enemy(game);
		ft_freemap(game);
		ft_freecollectible(game);
		ft_mlxfree(game, 0);
		ft_error_msg("Failed to create window.", game);
	}
}
