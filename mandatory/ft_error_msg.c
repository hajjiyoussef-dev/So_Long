/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:46:28 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/13 15:15:27 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void ft_error_msg(char *str, t_game *game)
{
    int i = 0;
    // t_collectible *help;
    // if (game->map.map)
    // {
    //     while (i < game->map.rows)
    //     {
    //         free(game->map.map[i]);
    //         i++;
    //     }
    //     free(game->map.map);
        
    // }
    // i  = 0;
    // while (game->collect)
    // {
    //     help = game->collect;
    //     game->collect = game->collect->next;
    //     free(help);
    // }
    if (game)
        free(game);
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }

    exit(1);
}