/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:04:53 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/03 18:31:20 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"



void ft_start_game(t_game *game)
{
    ft_init_mlx(game);
    ft_load_images(game);
    ft_render_map(game);
    mlx_loop(game->mlxptr);
    
}


int main(int argc, char **argv)
{
     t_game *game;
    
    game = malloc(sizeof(t_game));
    ft_pars_argement(argc, argv, game);
   // printf("Opening map: %s\n", argv[1]);
    ft_init_mape("files/maps/valid/map1.ber", game);
    
    ft_start_game(game);



    return (0);
}