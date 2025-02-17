/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:53:56 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/17 19:25:08 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_print_on_window(t_game *game)
{
	char	*move_conut;
	char	*speed;

	move_conut = ft_itoa(game->moves);
	speed = ft_itoa(game->speed);
	if (move_conut)
	{
		mlx_string_put(game->mlxptr, game->window, 20, 20, 0xFFFF00,
			"Moves : ");
		mlx_string_put(game->mlxptr, game->window, 70, 20, 0xFFFF00,
			move_conut);
		free(move_conut);
	}
	if (move_conut)
	{
		mlx_string_put(game->mlxptr, game->window, 20, 40, 0x0000FF,
			"enemy speed : ");
		mlx_string_put(game->mlxptr, game->window, 105, 40, 0x0000FF, speed);
		free(speed);
	}
}

int	ft_game_loop(t_game *game)
{
	static int	frame_count = 0;
	int			need_redraw;

	need_redraw = 0;
	if (frame_count % game->speed == 0)
	{
		ft_move_enemy(game);
		need_redraw = 1;
	}
	frame_count = (frame_count + 1) % 10000;
	game->frame_counter++;
	if (game->frame_counter >= 10)
	{
		game->current_collect_frame = (game->current_collect_frame + 1) % 4;
		game->frame_counter = 0;
		need_redraw = 1;
	}
	if (need_redraw == 1)
		ft_render_map(game);
	ft_print_on_window(game);
	return (0);
}

void	ft_start_game(t_game *game)
{
	ft_init_mlx(game);
	ft_load_images(game);
	ft_load_collect_img(game);
	ft_render_map(game);
	mlx_loop_hook(game->mlxptr, ft_game_loop, game);
	mlx_hook(game->window, 2, 1L << 0, ft_handel_keypress, game);
	mlx_hook(game->window, 17, 0, ft_close_game, game);
	mlx_loop(game->mlxptr);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		exit(1);
	ft_pars_argement(argc, argv, game);
	game->moves = 0;
	game->collected = 0;
	game->over_it.over_it = '0';
	game->over_it.x = -1;
	game->over_it.y = -1;
	game->collect = NULL;
	game->total_collectibles = 0;
	game->collected = 0;
	game->player.x = -1;
	game->player.y = -1;
	game->exit.x = -1;
	game->exit.y = -1;
	game->enemy = NULL;
	game->speed = 500;
	ft_init_mape(&argv[0], game);
	ft_start_game(game);
	return (0);
}
