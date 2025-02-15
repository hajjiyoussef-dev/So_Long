/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:53:56 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/15 17:28:34 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


int ft_game_loop(t_game *game)
{
    static int frame_count = 0;
    int need_redraw = 0;
    
    if (frame_count % 200 == 0)
    {
        ft_move_enemy(game);
        need_redraw = 1;
    }
    frame_count++;
    game->frame_counter++;
    if (game->frame_counter >= 10)
    {
        game->current_collect_frame = (game->current_collect_frame + 1) % 4 ;
        game->frame_counter = 0;
        need_redraw = 1;
    }
    if (need_redraw)
        ft_render_map(game);
    return (0);
}

// int ft_move_up(t_game *game)
// {
//     static int frame_count = 0;
//     if (frame_count % 1000 == 0)
//         ft_move_enemy(game);
//     frame_count++;
//     //ft_render_map(game);
//     return (0);
// }
// int ft_animate_coins(t_game *game)
// {
//     game->frame_counter++;
//     if (game->frame_counter >= 30)
//     {
//         game->current_collect_frame = (game->current_collect_frame + 1) % 4 ;
//         game->frame_counter = 0;
//     }
//     ft_render_map(game);
//     return (0);
// }

void ft_start_game(t_game *game)
{
   
    ft_init_mlx(game);
    ft_load_images(game);
    ft_load_collect_img(game);
    ft_render_map(game);
    mlx_loop_hook(game->mlxptr, ft_game_loop, game);
    mlx_hook(game->window, 2, 1L << 0, ft_handel_keypress, game);
    mlx_hook(game->window, 17, 0, ft_exit_game, game);
    mlx_loop(game->mlxptr);
}


int main(int argc, char **argv)
{
    t_game *game;
    
    game = malloc(sizeof(t_game));
    if (!game)
        exit(1);
    ft_pars_argement(argc, argv, game);
    game->moves = 0;
    game->collected = 0;
    game->over_it.over_it = '0'; 
    game->over_it.x = -1;        
    game->over_it.y = -1;  
    game->collect = NULL;
    game->total_collectibles = 0;
    game->collected = 0; 
    game->player.x = -1;
    game->player.y = -1;
    game->exit.x = -1;
    game->exit.y = -1;
    game->enemy = NULL;
    ft_init_mape(&argv[0], game);
    ft_start_game(game);
    return (0);
}

