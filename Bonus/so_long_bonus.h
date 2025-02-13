/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:54:23 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/13 22:30:39 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONGBONUS_H
#define SO_LONGBONUS_H


#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <mlx.h>



#define BUFFER_SIZE 42

#define TILE_SIZE 64



#define ESC_KEY     65307  
#define W_KEY       119   
#define S_KEY       115   
#define A_KEY       97    
#define D_KEY       100   
#define UP_ARROW    65362  
#define DOWN_ARROW  65364  
#define LEFT_ARROW  65361  
#define RIGHT_ARROW 65363  

#define WALL_XPM            "files/sprites/wall.xpm"
#define COINS_XPM           "files/sprites/coins_bag.xpm"
#define EXIT_CLOSED_XPM     "files/sprites/close_exit.xpm"
#define OPEN_EXIT_XPM       "files/sprites/open-exit.xpm"
#define PLAYER_XPM          "files/player/finn.xpm"
#define FLOOR_XPM           "files/sprites/floor.xpm"
#define ENEMY_XPM           "files/player/M.xpm"


typedef struct s_player {
    int x;
    int y;
}   t_player;

typedef struct s_collectible {
    int x;
    int y;
    struct s_collectible *next;
}   t_collectible;

typedef struct s_exit {
    int x;
    int y;
}   t_exit;

typedef struct s_map {
    char **map;
    int rows;
    int cols;
}   t_map;

typedef struct s_over_it{
    char over_it;
    int x;
    int y;
} t_over_it;

typedef struct s_enemy{
    int x;
    int y;
    struct s_enemy *next;
}   t_enemy;

typedef struct s_game {
    void *mlxptr;
    void *window;
    void *wall_img;
    void *player_img;
    void *exit_open_img;   
    void *exit_closed_img; 
    void *collect_img;
    void *floor_img;
    void *enemy_img;
    int collected;          
    int total_collectibles; 
    int moves;
    int win_lose;
    
    
    t_over_it over_it;          
    t_map map;
    t_collectible *collect;
    t_player player;
    t_exit exit;
    t_enemy *enemy;
}   t_game;


void ft_error_msg(char *str, t_game *game);

int	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	*ft_memcpy_get_next_line(void *dest, const void *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);

char	*get_next_line(int fd, int cleanup);
char	**ft_split(char const *s, char c);

void ft_pars_argement(int argc, char **argv, t_game *game);
void ft_init_mape(char **argv, t_game *game);
void ft_validate_map(t_game *game);

void ft_init_mlx(t_game *game);
void ft_load_images(t_game *game);
void    ft_render_map(t_game *game);

int ft_handel_keypress(int keycode, t_game *game);
int ft_exit_game(t_game *game);

void ft_mlxfree(t_game *game);
void ft_freemap(t_game *game);
void ft_freecollectible(t_game *game);

void ft_putchar(char c);
void ft_putstr(char *str);
void	ft_putnbr(int nbr);
void ft_win();
void ft_lose();


void ft_touch_enemy(t_game *game, int x, int y);


void ft_exit_game_losing(t_game *game);


#endif