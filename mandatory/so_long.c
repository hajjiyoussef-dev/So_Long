/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:04:53 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/08 00:28:12 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"



void ft_start_game(t_game *game)
{
    ft_init_mlx(game);
    ft_load_images(game);
    ft_render_map(game);
    mlx_hook(game->window, 2, 1L << 0, ft_handel_keypress, game);
    mlx_hook(game->window, 17, 0, ft_exit_game, game);
    
    mlx_loop(game->mlxptr);
}


int main(int argc, char **argv)
{
    t_game *game;
    
    game = malloc(sizeof(t_game));
    game->player.x = 0;
    game->player.y = 0;
    game->exit.x = 0;
    game->exit.y = 0;
    game->collect = NULL;
    game->collected = 0;
    game->total_collectibles = 0;
    game->moves = 0;
    game->map.map = NULL;
    game->mlxptr = NULL;
    game->window = NULL;
    
    ft_pars_argement(argc, argv, game);
    ft_init_mape(&argv[0], game);
    ft_start_game(game);
    return (0);
}
