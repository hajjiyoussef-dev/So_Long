/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:04:53 by yhajji            #+#    #+#             */
/*   Updated: 2025/01/28 02:53:25 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int main(int argc, char **argv)
{
     t_game *game;
    
    game = malloc(sizeof(t_game));
    ft_pars_argement(argc, argv);
    ft_init_mape(argv[1], game);



    
}