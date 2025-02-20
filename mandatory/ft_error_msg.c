/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:46:28 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/20 17:57:21 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_msg(char *str, t_game *game)
{
	int	i;

	i = 0;
	if (game)
		free(game);
	write(1, "Error\n", 7);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	exit(1);
}
