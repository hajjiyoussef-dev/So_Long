/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:03:24 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/14 19:23:04 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_cleanup_img(t_game *game)
{
    if (game->collect_img)
        mlx_destroy_image(game->mlxptr, game->collect_img);
    if(game->wall_img)
        mlx_destroy_image(game->mlxptr, game->wall_img);
    if (game->floor_img)
        mlx_destroy_image(game->mlxptr, game->floor_img);
    if (game->player_img)
        mlx_destroy_image(game->mlxptr, game->player_img);
    if (game->exit_closed_img)
        mlx_destroy_image(game->mlxptr, game->exit_closed_img);
    if (game->exit_open_img)
        mlx_destroy_image(game->mlxptr, game->exit_open_img);
    
}

void ft_freemap(t_game *game)
{
    int i;
    i = 0;
    if (game->map.map)
    {
        while (i < game->map.rows)
        {
            free(game->map.map[i]);
            i++;
        }
        free(game->map.map);
    }
}

void ft_freecollectible(t_game *game)
{
    if (!game) {
        printf("Error: game is NULL\n");
        return;
    }

    t_collectible *current = game->collect;
    t_collectible *next;

    printf("\nStarting to free collectibles...\n");

    if (!current) {
        printf("No collectibles to free (game->collect is NULL)\n");
        return;
    }

    while (current) {
        if (!current) {
            printf("Error: current is NULL\n");
            break;
        }

        next = current->next;  // Save next collectible
        printf("Freeing collectible at address: %p\n", (void*)current);
        free(current);         // Free current collectible
        current = next;        // Move to the next collectible
    }

    game->collect = NULL;  // Set the list to NULL after freeing all
    printf("Collectibles freed and list set to NULL\n");
}




void ft_mlxfree(t_game *game)
{
    ft_cleanup_img(game);
    if (game->window && game->mlxptr)
        mlx_destroy_window(game->mlxptr, game->window);
    if (game->mlxptr)
    {
        mlx_destroy_display(game->mlxptr);
        free(game->mlxptr); 
    } 
}
