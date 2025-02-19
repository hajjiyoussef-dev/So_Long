/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:31:24 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/19 18:36:55 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_error_msg(char *str, t_game *game)
{
	int	i;

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

void	ft_free_enemy(t_game *game)
{
	t_enemy	*help_two;

	while (game->enemy)
	{
		help_two = game->enemy;
		game->enemy = game->enemy->next;
		free(help_two);
	}
}

int	ft_close_game(t_game *game)
{
	t_enemy	*help_two;

	while (game->enemy)
	{
		help_two = game->enemy;
		game->enemy = game->enemy->next;
		free(help_two);
	}
	ft_freemap(game);
	ft_freecollectible(game);
	ft_putstr("GAME CLOSED :( \n");
	ft_mlxfree(game, 1);
	free(game);
	exit(0);
}
