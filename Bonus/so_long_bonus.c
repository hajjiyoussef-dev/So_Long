/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:53:56 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/13 22:04:15 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


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
    if (!game)
        exit(1);
    ft_pars_argement(argc, argv, game);
    ft_init_mape(&argv[0], game);
    ft_start_game(game);
    return (0);
}

