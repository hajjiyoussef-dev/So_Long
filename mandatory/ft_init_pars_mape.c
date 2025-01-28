/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pars_mape.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:48:36 by yhajji            #+#    #+#             */
/*   Updated: 2025/01/28 02:26:52 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void ft_pars_argement(int argc, char **argv)
{
    size_t mapNameLen = 0;
    if (argc > 2)
        ft_error_msg("Too many arguments (It should be only two)");
    if (argc < 2)
        ft_error_msg("The Map file is missing.");
    mapNameLen = ft_strlen(argv[1]);

    if (!ft_strnstr(&argv[1][mapNameLen - 4], ".ber", 4))
        ft_error_msg("Map file extention is wrong (It should be .ber)");
}


void ft_init_mape(char **argv, t_game *game)
{
    
}