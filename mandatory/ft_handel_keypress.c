/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handel_keypress.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:54:31 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/06 20:10:41 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int ft_exit_game(t_game *game)
{
    int i;

    i = 0;
    while (i < game->map.rows)
    {
        free(game->map.map[i]);
        i++;
    }
    free(game->map.map);
    
    if (game->mlxptr && game->window)
        mlx_destroy_window(game->mlxptr, game->window);
    printf("game over %d\n", game->moves);

    exit(0);
    
}


void ft_move_player(t_game *game, int x, int y)
{
    
    if (game->map.map[x][y] == '1')
        return;
    if (game->map.map[x][y] == 'C')
    {
        game->collected++;
        game->map.map[x][y] = '0';
    }
    

    // if (game->map.map[x][y] == 'E')
    // {
    //     if (game->collected == game->total_collectibles)
    //         ft_exit_game(game);
    //     else 
    //         return ;
    // }

    

    // if (game->map.map[game->player.x][game->player.y] != 'E')
    // {
    //     game->map.map[game->player.x][game->player.y] = '0';
    //     printf("Old Position Set to '0': (%d, %d)\n", game->player.x, game->player.y);
    // }
   char previous_tile = game->map.map[game->player.x][game->player.y];

    // Handle the exit logic
    if (game->map.map[x][y] == 'E')
    {
        // If all collectibles are collected, allow exiting
        if (game->collected == game->total_collectibles)
        {
            ft_exit_game(game);  // Exit the game if all collectibles are collected
            return;
        }
        else
        {
            // If not all collectibles are collected, prevent the player from overwriting the exit
            return;
        }
    }

    // If the player was on the exit previously, restore the exit at that position
    if (previous_tile == 'E')
    {
        game->map.map[game->player.x][game->player.y] = 'E';  // Restore the exit
    }
    else
    {
        game->map.map[game->player.x][game->player.y] = '0';  // Mark the previous position as empty
    }

    //printf("Player moved to: (%d, %d)\n", game->player.x, game->player.y);
    game->player.x = x ;
    game->player.y = y ;
    game->map.map[game->player.x][game->player.y] = 'P';
    
    game->moves++;
    
    printf("moves %d \n", game->moves);
    // print_map1(game->map.map, game->map.rows);
    ft_render_map(game);
}


int ft_handel_keypress(int keycode, t_game *game)
{
    
    if (keycode == ESC_KEY)
        ft_exit_game(game);
    else if (keycode == W_KEY || keycode == UP_ARROW)
        ft_move_player(game, game->player.x - 1, game->player.y);
    else if (keycode == S_KEY || keycode == DOWN_ARROW)
        ft_move_player(game, game->player.x + 1, game->player.y);
    else if (keycode == A_KEY || keycode == LEFT_ARROW)
        ft_move_player(game, game->player.x, game->player.y - 1);
    else if (keycode == D_KEY || keycode == RIGHT_ARROW)
        ft_move_player(game, game->player.x, game->player.y + 1);
    return (0);
    
}