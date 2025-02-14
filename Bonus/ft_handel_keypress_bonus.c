/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handel_keypress_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:30:34 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/14 23:48:29 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int ft_exit_game(t_game *game)
{
    int i;
    t_collectible *help;
    t_enemy *help_two;

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
    i  = 0;
    while (game->collect)
    {
        help = game->collect;
        game->collect = game->collect->next;
        free(help);
    }
    while (game->enemy)
    {
        help_two = game->enemy;
        game->enemy = game->enemy->next;
        free(help_two);
    }
    
    ft_win();
    ft_mlxfree(game);
    free(game);
    exit(0);
}
void ft_call_over_it(t_game *game, int x, int y)
{
    game->over_it.over_it = '0';
    game->over_it.x = -1;
    game->over_it.y = -1;
    game->over_it.over_it = 'Q';
    game->over_it.x = x;
    game->over_it.y = y;
    game->map.map[game->player.x][game->player.y] = '0';
    game->player.x = x ;
    game->player.y = y ;
    game->map.map[game->player.x][game->player.y] = 'P';
    game->moves++;
    ft_putchar('\n');
    ft_putstr("number of moves : ");
    ft_putnbr(game->moves);
    
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
    ft_touch_enemy(game, x, y);
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