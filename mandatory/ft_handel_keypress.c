/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handel_keypress.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:54:31 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/14 22:52:48 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int ft_exit_game(t_game *game)
{
    ft_freemap(game);
    ft_freecollectible(game);
    ft_win();
    ft_mlxfree(game);
    free(game);
    exit(0);
}
void ft_call_over_it(t_game *game, int x, int y)
{
    // game->over_it.over_it = '0';
    // game->over_it.x = -1;
    // game->over_it.y = -1;
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
        game->over_it.over_it = '0';
    }
    game->map.map[game->player.x][game->player.y] = 'P';
    game->moves++;
    ft_putchar('\n');
    ft_putstr("number of moves : ");
    ft_putnbr(game->moves);
    ft_render_map(game);
    return ;
}

void ft_move_player(t_game *game, int x, int y)
{
    if (x < 0 ||  x >= game->map.rows || y < 0 || y >= game->map.cols)
        return ;
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
            ft_exit_game(game);
        else
        {
            ft_call_over_it(game, x, y);
            ft_render_map(game);
        }
        return ;
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