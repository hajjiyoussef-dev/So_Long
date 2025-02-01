/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:04:53 by yhajji            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/02/01 20:13:17 by yhajji           ###   ########.fr       */
=======
/*   Updated: 2025/01/28 02:53:25 by yhajji           ###   ########.fr       */
>>>>>>> 6980f356c1dfa740c4ab7ee1149e374a58601c37
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int main(int argc, char **argv)
{
     t_game *game;
    
    game = malloc(sizeof(t_game));
    ft_pars_argement(argc, argv);
<<<<<<< HEAD
    ft_init_mape(&argv[1], game);
=======
    ft_init_mape(argv[1], game);
>>>>>>> 6980f356c1dfa740c4ab7ee1149e374a58601c37



    
}