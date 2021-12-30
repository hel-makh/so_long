/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:03:53 by hel-makh          #+#    #+#             */
/*   Updated: 2021/12/29 19:14:46 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_initialize_map(t_map	*map)
{
	map->empty_spaces = 0;
	map->walls = 0;
	map->collectibles = 0;
	map->exit = 0;
	map->start_position = 0;
}

static int	ft_validate_walls(t_map *map, char *parsed_map)
{
	int	i;

	i = 0;
	while (parsed_map[i])
	{
		if (parsed_map[i] != WALL)
			return (0);
		map->walls ++;
		i ++;
	}
	return (1);
}

static int	ft_validate_components(t_map *map, char *parsed_map)
{
	int	i;

	i = 0;
	while (parsed_map[i])
	{
		if ((i == 0 || !parsed_map[i + 1])
			&& parsed_map[i] != WALL)
			return (0);
		if (parsed_map[i] == EMPTY_SPACE)
			map->empty_spaces ++;
		else if (parsed_map[i] == WALL)
			map->walls ++;
		else if (parsed_map[i] == COLLECTIBLE)
			map->collectibles ++;
		else if (parsed_map[i] == EXIT)
			map->exit ++;
		else if (parsed_map[i] == START_POSITION)
			map->start_position ++;
		else
			return (0);
		i ++;
	}
	return (1);
}

int	ft_valid_map(t_map *map)
{
	size_t	map_width;
	size_t	i;

	ft_initialize_map(map);
	i = 0;
	while (map->parsed_map[i])
	{
		if (i == 0)
			map_width = ft_strlen(map->parsed_map[i]);
		else if (ft_strlen(map->parsed_map[i]) != map_width)
			return (0);
		if ((i == 0 || !map->parsed_map[i + 1])
			&& !ft_validate_walls(map, map->parsed_map[i]))
			return (0);
		else if (!ft_validate_components(map, map->parsed_map[i]))
			return (0);
		i ++;
	}
	if (map->exit < 1 || map->collectibles < 1 || map->start_position < 1)
		return (0);
	return (1);
}
