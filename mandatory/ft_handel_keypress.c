/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handel_keypress.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:54:31 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/07 00:03:52 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int ft_exit_game(t_game *game)
{
    int i;

    i = 0;
    printf("\n🎉 Congratulations! You won the game in %d moves! 🎉\n", game->moves);
    printf("Thanks for playing! 👏\n");
    while (i < game->map.rows)
    {
        free(game->map.map[i]);
        i++;
    }
    free(game->map.map);
    
    if (game->mlxptr && game->window)
        mlx_destroy_window(game->mlxptr, game->window);
    // printf("game over %d\n", game->moves);
    //ft_error_msg("")

    exit(0);
    
}
void ft_call_over_it(t_game *game, int x, int y)
{
    game->over_it.over_it = 'Q';
    game->over_it.x = x;
    game->over_it.y = y;
    
    game->map.map[game->player.x][game->player.y] = '0';
    game->player.x = x ;
    game->player.y = y ;
    game->map.map[game->player.x][game->player.y] = 'P';
    game->moves++;
    
}
void ft_call_render_map(t_game *game, int x, int y)
{
    game->map.map[game->player.x][game->player.y] = '0';
    game->player.x = x ;
    game->player.y = y ;
     if (game->over_it.over_it == 'Q')
    {
        game->map.map[game->over_it.x][game->over_it.y] = 'E';
        game->over_it.over_it = 'P';
    }
    game->map.map[game->player.x][game->player.y] = 'P';
    game->moves++;
    printf("moves %d \n", game->moves);
    ft_render_map(game);
    return ;
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
    if (game->map.map[x][y] == 'E')
    {
        
        if (game->collected == game->total_collectibles)
        {
            ft_exit_game(game);  
            return;
        }
        else
        {
            ft_call_over_it(game, x, y);
            ft_render_map(game);
            return ;
        }
    }
    ft_call_render_map(game, x, y);
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