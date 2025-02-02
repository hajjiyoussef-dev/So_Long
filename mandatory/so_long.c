/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:04:53 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/02 23:54:55 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"



void ft_start_game(t_game *game)
{
    ft_init_mlx(game);
    ft_load_images(game);
    ft_render_map(game);
    
}


int main(int argc, char **argv)
{
     t_game *game;
    
    game = malloc(sizeof(t_game));
    ft_pars_argement(argc, argv, game);
    ft_init_mape(&argv[1], game);
    ft_start_game(game);



    return (0);
}