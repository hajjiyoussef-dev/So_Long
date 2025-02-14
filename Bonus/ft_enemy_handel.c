/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_handel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:19:02 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/14 16:22:17 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


void ft_exit_game_losing(t_game *game)
{
    int i;
    t_collectible *help;

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
    ft_lose();
    ft_mlxfree(game);
    free(game);
    exit(0);
}

void ft_move_enemy(t_game *game)
{
    t_enemy *enemy ;
    int new_x;
    int new_y;
    int moved;

    enemy = game->enemy;
    moved = 0;
    while (enemy)
    {
        new_x = enemy->x;
        new_y = enemy->y + enemy->direction;
        if (game->map.map[enemy->x][enemy->y - 1] == '1' &&
            game->map.map[enemy->x][enemy->y + 1] == '1')
        {
            enemy = enemy->next;
            continue;
        }
        if (game->map.map[new_x][new_y] == 'P')
            ft_exit_game_losing(game);
        if (game->map.map[new_x][new_y] == '0')
        {
            game->map.map[enemy->x][enemy->y] = '0';
            game->map.map[new_x][new_y] = 'M';
            enemy->y = new_y;
            moved = 1;
            
        }
        else 
        {
            enemy->direction *= -1;
        }
        enemy = enemy->next;
    }
    if (moved)
        ft_render_map(game);
    
}

void ft_touch_enemy(t_game *game, int x, int y)
{
    game->win_lose = 1;
    if (game->map.map[x][y] == 'M')
    {
        game->win_lose = -1;
        ft_exit_game_losing(game);
    }
}