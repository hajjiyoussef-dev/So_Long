/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:38:33 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/04 17:37:53 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void ft_init_mlx(t_game *game)
{

    int window_width = game->map.cols * TILE_SIZE;
    int window_height = game->map.rows * TILE_SIZE;
    game->mlxptr = mlx_init();
    if (!game->mlxptr)
        ft_error_msg("Failed to initialize MiniLibX.", game);
    
    game->window = mlx_new_window(game->mlxptr, window_width, window_height, "so_long");
    
    if (!game->window)
    {
        mlx_destroy_display(game->mlxptr);
        //free(game->mlxptr);
        ft_error_msg("Failed to create window.", game);
    }
}

void ft_load_images(t_game *game)
{
    int img_withe = TILE_SIZE; 
    int img_height = TILE_SIZE;

    // void *(*p)(char *a, char *b, int *c, int *d);
    
    // p = &mlx_xpm_file_to_image;
    
    // game->wall_img = p(game->mlxptr, WALL_XPM, &img_withe, &img_height);
    game->wall_img = mlx_xpm_file_to_image(game->mlxptr, WALL_XPM, &img_withe, &img_height);
    // if (!game->wall_img)
    //     ft_error_msg("Failed to load image wall.", game);  
    game->collect_img = mlx_xpm_file_to_image(game->mlxptr, COINS_XPM, &img_withe, &img_height);
    // if (!game->collect_img)
    //     ft_error_msg("Failed to load image collectibles", game);  
    game->exit_closed_img = mlx_xpm_file_to_image(game->mlxptr, EXIT_CLOSED_XPM, &img_withe, &img_height);
    // if (!game->exit_closed_img)
    //     ft_error_msg("Failed to load image exit_closed_img.", game);  
    game->exit_open_img = mlx_xpm_file_to_image(game->mlxptr, OPEN_EXIT_XPM, &img_withe, &img_height);
    // if (!game->exit_open_img)
    //     ft_error_msg("Failed to load image exit_open_img.", game);  
    game->player_img = mlx_xpm_file_to_image(game->mlxptr, PLAYER_XPM, &img_withe, &img_height);
    // if (!game->player_img)
    //     ft_error_msg("Failed to load image player_img.", game);  
    game->floor_img = mlx_xpm_file_to_image(game->mlxptr, FLOOR_XPM, &img_withe, &img_height);
    // if (!game->floor_img)
    //     ft_error_msg("Failed to load image floor_img.", game);  

    if (!game->wall_img || !game->player_img || !game->exit_closed_img || !game->exit_open_img || !game->collect_img) {
        ft_error_msg("Failed to load images.", game);
    } else {
        printf("Images loaded successfully\n");
    }  
}




