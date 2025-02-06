/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_of_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:40:26 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/06 17:30:01 by yhajji           ###   ########.fr       */
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

void ft_floo_fill(char **map_copy, int x, int y, int rows, int clos)
{
    if (x < 0 || y < 0 ||  x >= rows || y >= clos)
        return ;
    if (map_copy[x][y] == '1' || map_copy[x][y] == 'F')
        return ;
    map_copy[x][y] = 'F';
    
    ft_floo_fill(map_copy, x + 1, y, rows, clos); // down
    ft_floo_fill(map_copy, x - 1, y , rows, clos); // up
    ft_floo_fill(map_copy, x, y + 1, rows, clos); // right
    ft_floo_fill(map_copy, x, y - 1, rows, clos); // left
}


int ft_is_valid_path(t_game *game)
{
    int i;
    int j;
    int k;
    int player_x;
    int player_y;
    char **map_copy;

    i = 0;
    player_x = -1;
    player_y = -1;
    // fprintf(stderr, "hannna");
    while (i < game->map.rows)
    {
        j = 0;
        while (j < ft_strlen(game->map.map[i]))
        {
           if (game->map.map[i][j] == 'P')
           {
                // fprintf(stderr, "hannna1");
                player_x = i;
                player_y = j;
                break;
           }
           j++;
        }   
        i++;
    }
    // fprintf(stderr, "hannna3");
    if (player_x == -1 || player_y == -1)
        ft_error_msg("Invalid map: No player position found.", game);
    // fprintf(stderr, "hannna4");
    map_copy = malloc(sizeof(char *) * (game->map.rows));
    if (!map_copy)
        ft_error_msg("Memory allocation failed for map copy.", game);
    i = 0;
    j = 0;
    // fprintf(stderr, "hannna5");
    while (i < game->map.rows)
    {
        map_copy[i] = ft_strdup(game->map.map[i]);
        if (!map_copy[i])
            ft_error_msg("Memory allocation failed for row copy.", game);
        i++;
    }
    // fprintf(stderr, "hannna6");
    ft_floo_fill(map_copy, player_x, player_y, game->map.rows, game->map.cols);
    // fprintf(stderr, "hannna7");
    i = 0;
    j = 0;

    while (i < game->map.rows)
    {
        j = 0;
        while (j < ft_strlen(game->map.map[i]))
        {
            if (((game->map.map[i][j] == 'C') || (game->map.map[i][j] == 'E')) && (map_copy[i][j] != 'F'))
            {
                if (map_copy[i][j] != 'F')
                {
                    // fprintf(stderr, "hannna8");
                    k = 0;
                    while (k < game->map.rows)
                    {
                        free(map_copy[k]);
                        k++;
                    }
                    free(map_copy);
                    return (0);
                }
            }
            j++;
        }
        i++;
    }
    i = 0;
    // fprintf(stderr, "hannna9");
    while (i < game->map.rows)
    {
        free(map_copy[i]);
        i++;
    }
    free(map_copy);
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
    //  fprintf(stderr, "hannna10");
    if (!ft_IsRectanguler(game))
        ft_error_msg("Invalid map: The map is not rectangular.", game);
    // fprintf(stderr, "hannna11");
    if (!ft_is_closed_by_walls(game))
        ft_error_msg("Invalid map: The map is not fully enclosed by walls.", game);
    // fprintf(stderr, "hannna12");
    if (!ft_is_valid_characters(game))
        ft_error_msg("Invalid map: The map contains an invalid character.", game);
    // fprintf(stderr, "hannna13");
    if (!ft_is_valid_path(game))
        ft_error_msg("Invalid map: No valid path exists between player, collectibles, and exit.", game);
    while (i < game->map.rows)
    {
        j = 0;
        while (j < ft_strlen(game->map.map[i]))
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

