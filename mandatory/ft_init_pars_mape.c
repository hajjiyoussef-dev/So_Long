/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pars_mape.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:48:36 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/06 22:01:38 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"



void ft_pars_argement(int argc, char **argv, t_game *game)
{
    size_t mapNameLen = 0;
    
    if (argc > 2)
        ft_error_msg("Too many arguments (It should be only two)", game);
    if (argc < 2)
        ft_error_msg("The Map file is missing.", game);
    mapNameLen = ft_strlen(argv[1]);

    if (mapNameLen < 4 || !ft_strnstr(&argv[1][mapNameLen - 4], ".ber", 4))
        ft_error_msg("Map file extention is wrong (It should be .ber)", game);
}

void ft_is_empty(char *map, t_game *game)
{
    int i;
    int len;

    if (!map)
        ft_error_msg("Invalid map. The map is NULL.", game);
    len = ft_strlen(map);
    if (len > 0 && map[0] == '\n')
    {
        free(map);
        game->map.map = NULL;
        ft_error_msg("Invalid map. The map has an empty line at the beginning", game);
    }
    if (len > 0 && map[len - 1] == '\n')
    {
        free(map);
        game->map.map = NULL;
        ft_error_msg("Invalid map. The map has an empty line at the end.", game);
    }
    i = 0;
    while (map[i + 1])
    {
        if (map[i] == '\n' && map[i + 1] == '\n')
        {
            free(map);
            game->map.map = NULL;
            ft_error_msg("Invalid map. The map has an empty line in the middle.", game);
        }
        i++;
    }
}

void ft_columns_num(t_game *game)
{
    if (game->map.rows > 0)
        game->map.cols = ft_strlen(game->map.map[0]);
    else 
        ft_error_msg("Invalid map: The map has no rows.", game);
}




void ft_init_game_components(t_game *game)
{
    int i;
    int j = 0;
    t_collectible *new_collectible;

    while (j < game->map.rows)
    {
        i = 0;
        while (i < ft_strlen(game->map.map[j]))
        {
            if (game->map.map[j][i] == 'P')
            {
                game->player.x = j;
                game->player.y = i;
            }
            else if (game->map.map[j][i] == 'E')
            {
                game->exit.x = i;
                game->exit.y = j;
            }
            else if (game->map.map[j][i] == 'C')
            {
               new_collectible = malloc(sizeof(t_collectible));
               if (!new_collectible)
                    ft_error_msg("Memory allocation failed for collectible.", game);
                new_collectible->x = i;
                new_collectible->y = j;
                new_collectible->next = game->collect;
                game->collect = new_collectible;
                game->total_collectibles++;
                
            }
            i++;
        }   
        j++;
    }
}



void ft_init_mape(char **argv, t_game *game)
{
    int map_read;
    char *map_help;
    char *line_map;

    //printf("Opening map: %s\n", argv[1]);
    map_read = open(argv[1], O_RDONLY);
    if (map_read == -1)
        ft_error_msg("The Map couldn't be opened. Does the Map exist?", game);
    // else 
    //     ft_error_msg("open succssfly", game);
    map_help = ft_strdup("");
    game->map.rows = 0;
    while (1)
    {
        line_map = get_next_line(map_read, 0);
        if (line_map == NULL)
            break;
        map_help = ft_strappend(&map_help, line_map);
        free(line_map);
        game->map.rows++;
    }
    close(map_read);
    ft_is_empty(map_help, game);
    if (map_help == NULL || ft_strlen(map_help) == 0)
        ft_error_msg("The map is empty or invalid.", game);
    game->map.map = ft_split(map_help, '\n');
    free(map_help);
    ft_columns_num(game);
    ft_validate_map(game);
    ft_init_game_components(game);
}



