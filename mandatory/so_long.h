/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:05:03 by yhajji            #+#    #+#             */
/*   Updated: 2025/01/28 02:36:33 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>


typedef struct s_player{
    
    int x;
    int y;
}   t_player;

typedef struct s_collectible{
    int x;
    int y;
    struct s_collectible *next;
}    t_collectible;

typedef struct s_exit{
    int x;
    int y;
}   t_exit;

typedef struct s_map{
    char **map;
    int rows;
    int cols;
}   t_map;

typedef struct s_game{
    t_map map;
    t_collectible *collect;
    t_player player;
    t_exit exit;
    int moves;
    int game_over;
}   t_game; 


size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);


#endif