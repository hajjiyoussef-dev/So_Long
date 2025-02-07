/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlxfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:03:24 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/07 19:17:00 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_cleanup_img(t_game *game)
{
    if (game->collect_img)
        mlx_destroy_image(game->mlxptr, game->collect_img);
    if(game->wall_img)
        mlx_destroy_image(game->mlxptr, game->wall_img);
    if (game->floor_img)
        mlx_destroy_image(game->mlxptr, game->floor_img);
    if (game->player_img)
        mlx_destroy_image(game->mlxptr, game->player_img);
    if (game->exit_closed_img)
        mlx_destroy_image(game->mlxptr, game->exit_closed_img);
    if (game->exit_open_img)
        mlx_destroy_image(game->mlxptr, game->exit_open_img);
    
}

void ft_mlxfree(t_game *game)
{
    ft_cleanup_img(game);
    if (game->window && game->mlxptr)
        mlx_destroy_window(game->mlxptr, game->window);
    if (game->mlxptr)
    {
        mlx_destroy_display(game->mlxptr);
        free(game->mlxptr); 
    } 
}
