/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_of_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:40:26 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/04 17:24:37 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int ft_IsRectanguler(t_game *game)
{
    int i;
    int width;


    if (game->map.rows <= 0)
        return (0);
    width = ft_strlen(game->map.map[0]);
    i = 1;
    while (i < game->map.rows)
    {
        if (ft_strlen(game->map.map[i]) != width)
            return (0);
        i++;
    }
    return (1);    
}

int ft_is_closed_by_walls(t_game *game)
{
    int i;
    int width;

    width =  ft_strlen(game->map.map[0]);
    i = 0;
    while ( i < width)
    {
        if (game->map.map[0][i] != '1' || game->map.map[game->map.rows - 1][i] != '1')
            return (0);
        i++;
    }
    i = 0;
    while (i < game->map.rows)
    {
        if (game->map.map[i][0] != '1' || game->map.map[i][width - 1]  != '1')
            return (0); 
        i++;
    }
    return(1);     
}

int ft_is_valid_characters(t_game *game)
{
    int i ;
    int j;

    i = 0;
    while (i < game->map.rows)
    {
        j = 0;
        while (j < game->map.cols)
        {
            if (game->map.map[i][j] != '1' &&
                game->map.map[i][j] != 'P' &&
                game->map.map[i][j] != 'C' &&
                game->map.map[i][j] != 'E' &&
                game->map.map[i][j] != '0' )
            {
                return (0);
            }
            j++;
        }
        
        i++;
    }

    return (1);
    
}

void ft_validate_map(t_game *game)
{
    int palyer_count = 0;
    int exit_count = 0;
    int colle_count = 0;
    int i;
    int j;


    
    i = 0;

    if (!ft_IsRectanguler(game))
        ft_error_msg("Invalid map: The map is not rectangular.", game);
    if (!ft_is_closed_by_walls(game))
        ft_error_msg("Invalid map: The map is not fully enclosed by walls.", game);
    if (!ft_is_valid_characters(game))
        ft_error_msg("Invalid map: The map contains an invalid character.", game);
    while (i < game->map.rows)
    {
        j = 0;
        while (j < game->map.cols)
        {
            if (game->map.map[i][j] == 'P')
                palyer_count++;
            else if (game->map.map[i][j] == 'C')
                colle_count++;
            else if (game->map.map[i][j] == 'E')
                exit_count++;
            j++;
        }
        i++;
    }
    if (palyer_count != 1)
        ft_error_msg("Invalid map: There should be exactly one player :(", game);
    if (exit_count != 1)
        ft_error_msg("Invalid map: There should be exactly one exit :(", game);
    if (colle_count < 1)
        ft_error_msg("Invalid map: There should be at least one collectible :(", game);
    
}

