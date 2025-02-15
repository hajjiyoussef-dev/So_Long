/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:25:42 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/15 17:34:29 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


void ft_draw_wall(t_game *game, int x, int y)
{
    mlx_put_image_to_window(game->mlxptr, game->window, game->wall_img, (x * TILE_SIZE), (y * TILE_SIZE));
}

void ft_draw_player(t_game *game, int x, int y)
{
    mlx_put_image_to_window(game->mlxptr, game->window, game->player_img, (x * TILE_SIZE), (y * TILE_SIZE));   
}

void ft_draw_collec(t_game *game, int x, int y)
{
    void *current_collect_img;

    current_collect_img = game->arr_collect_frames[game->current_collect_frame];
    mlx_put_image_to_window(game->mlxptr, game->window, current_collect_img, (x * TILE_SIZE), (y * TILE_SIZE));
}

void ft_draw_exit(t_game *game, int x , int y)
{
    if (game->collected == game->total_collectibles)
        mlx_put_image_to_window(game->mlxptr, game->window, game->exit_open_img, (x * TILE_SIZE), (y * TILE_SIZE));
    else 
        mlx_put_image_to_window(game->mlxptr, game->window, game->exit_closed_img, (x *TILE_SIZE),( y * TILE_SIZE));
}

void ft_draw_empty(t_game *game, int x, int y)
{
    mlx_put_image_to_window(game->mlxptr, game->window, game->floor_img, (x * TILE_SIZE), (y * TILE_SIZE));
}
void ft_draw_enemy(t_game *game, int x, int y)
{
    mlx_put_image_to_window(game->mlxptr, game->window, game->enemy_img, (x * TILE_SIZE), (y * TILE_SIZE));
}

void    ft_render_map(t_game *game)
{
    int i = 0;
    int j;
    
    //aaaaaaaa(game->mlxptr, game->window);
    
    while (i < game->map.rows)
    {
        j = 0;
        while (j < game->map.cols)
        {   
            if (game->map.map[i][j] == '1')
                ft_draw_wall(game, j, i);
            else if (game->map.map[i][j] == '0')
                ft_draw_empty(game, j, i);
            else if (game->map.map[i][j] == 'P')
                ft_draw_player(game, j, i);
            else if (game->map.map[i][j] == 'C')
                ft_draw_collec(game, j, i);
            else if (game->map.map[i][j] == 'E')
                ft_draw_exit(game, j, i);
            else if (game->map.map[i][j] == 'M')
                ft_draw_enemy(game, j, i);
            
            j++;
        }
        i++;
        
    }
    
    
}


