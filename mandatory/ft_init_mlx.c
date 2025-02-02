/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:38:33 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/02 21:31:03 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void ft_init_mlx(t_game *game)
{
    game->mlxptr = mlx_init();
    if (!game->mlxptr)
        ft_error_msg("Failed to initialize MiniLibX.", game);
    
    game->window = mlx_new_window(game->mlxptr, game->map.cols * TILE_SIZE, game->map.rows * TILE_SIZE, "so_long");
    
    if (!game->window)
    {
        mlx_destroy_display(game->mlxptr);
        //free(game->mlxptr);
        ft_error_msg("Failed to create window.", game);
    }
}

void load_images(t_game *game)
{
    int img_withe = TILE_SIZE;
    int img_height = TILE_SIZE;

    game->wall_img = mlx_xpm_file_to_image(game->mlxptr, "images/", img_withe, img_height);
    game->player_img = mlx_xpm_file_to_image(game->mlxptr, "images/", img_withe, img_height);
    
}