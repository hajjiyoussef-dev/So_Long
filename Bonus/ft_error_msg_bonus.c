/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:31:24 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/17 17:55:34 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


void    ft_error_msg(char *str, t_game *game)
{
    int i;

    i = 0;
    if (game)
        free(game);
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
    exit(1);
}

int	ft_close_game(t_game *game)
{
	ft_freemap(game);
	ft_freecollectible(game);
	ft_putstr("GAME CLOSED :( \n");
	ft_mlxfree(game);
	free(game);
	exit(0);
}