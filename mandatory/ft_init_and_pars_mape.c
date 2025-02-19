/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_and_pars_mape.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:48:36 by yhajji            #+#    #+#             */
/*   Updated: 2025/02/19 13:36:18 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_pars_argement(int argc, char **argv, t_game *game)
{
	size_t	map_len_name;

	map_len_name = 0;
	if (argc > 2)
		ft_error_msg("Too many arguments (It should be only two)", game);
	if (argc < 2)
		ft_error_msg("The Map file is missing.", game);
	map_len_name = ft_strlen(argv[1]);
	if (map_len_name < 4 || !ft_strnstr(&argv[1][map_len_name - 4], ".ber", 4))
		ft_error_msg("Map file extention is wrong (It should be .ber)", game);
}

void	ft_is_empty(char *map, t_game *game)
{
	int	i;
	int	len;

	if (!map)
		ft_error_msg("Invalid map. The map is NULL.", game);
	len = ft_strlen(map);
	if (len > 0 && map[0] == '\n')
	{
		free(map);
		ft_error_msg("Invalid map. The map has an empty line at the beginning",
			game);
	}
	i = 0;
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_error_msg("Invalid map. The map has an \
				empty line in the middle.", game);
		}
		i++;
	}
}

void	ft_init_game_components(t_game *game)
{
	int	i;
	int	j;

	j = 0;
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
				ft_create_new_collec(game, &i, &j);
			i++;
		}
		j++;
	}
}

void	ft_columns_num(t_game *game, char *map_help)
{
	if (map_help == NULL || ft_strlen(map_help) == 0)
		ft_error_msg("The map is empty or invalid.", game);
	game->map.map = ft_split(map_help, '\n');
	free(map_help);
	if (game->map.rows > 0)
		game->map.cols = ft_strlen(game->map.map[0]);
	else
		ft_error_msg("Invalid map: The map has no rows.", game);
	ft_validate_map(game);
	ft_init_game_components(game);
}

void	ft_init_mape(char **argv, t_game *game)
{
	int		map_read;
	char	*map_help;
	char	*line_map;
	int		i;

	map_read = open(argv[1], O_RDONLY);
	if (map_read == -1)
		ft_error_msg("The Map couldn't be opened. Does the Map exist?", game);
	map_help = NULL;
	game->map.rows = 0;
	i = 0;
	while (1)
	{
		line_map = get_next_line(map_read, 0);
		if (line_map == NULL)
			break ;
		map_help = ft_strjoin(map_help, line_map);
		free(line_map);
		game->map.rows++;
		i++;
	}
	close(map_read);
	if (!line_map && i == 0)
		ft_error_msg("Error the map is empty or invalid.", game);
	(ft_is_empty(map_help, game), ft_columns_num(game, map_help));
}
