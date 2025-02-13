/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:03:24 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/13 14:51:21 by yhajji           ###   ########.fr       */
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

void ft_freemap(t_game *game)
{
    int i;
    i = 0;
    if (game->map.map)
    {
        while (i < game->map.rows)
        {
            free(game->map.map[i]);
            i++;
        }
        free(game->map.map);
    }
}

void ft_freecollectible(t_game *game)
{
    int i;
    t_collectible *help;
    i  = 0;
    while (game->collect)
    {
        help = game->collect;
        game->collect = game->collect->next;
        free(help);
    }
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
