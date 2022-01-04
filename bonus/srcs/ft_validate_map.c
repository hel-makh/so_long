/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:03:53 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/04 16:12:57 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_initialize_map(t_map	*map)
{
	map->collectibles = 0;
	map->exit = 0;
	map->start_position = 0;
	map->movements = 0;
	map->game_ended = 0;
	map->game_over = 0;
	map->width = 0;
	map->height = 0;
	map->assets.player.direction = 'R';
	map->assets.player.frame_count = 0;
	map->assets.player.collecting = 0;
	map->assets.player.dying = 0;
	map->assets.enemy.frame_count = 0;
	map->assets.enemy.attack_frame_count = 0;
	map->assets.enemy.attacking = 0;
}

static int	ft_validate_walls(char *parsed_map)
{
	int	i;

	i = 0;
	while (parsed_map[i])
	{
		if (parsed_map[i] != WALL)
			return (0);
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
		if (parsed_map[i] == COLLECTIBLE)
			map->collectibles ++;
		else if (parsed_map[i] == EXIT)
			map->exit ++;
		else if (parsed_map[i] == START_POSITION)
			map->start_position ++;
		else if (parsed_map[i] != EMPTY_SPACE && parsed_map[i] != WALL
			&& parsed_map[i] != ENEMY)
			return (0);
		i ++;
	}
	return (1);
}

int	ft_is_map_valid(t_map *map)
{
	ft_initialize_map(map);
	while (map->parsed_map[map->height])
	{
		if (map->height == 0)
			map->width = ft_strlen(map->parsed_map[map->height]);
		else if ((int)ft_strlen(map->parsed_map[map->height]) != map->width)
			return (0);
		if ((map->height == 0 || !map->parsed_map[map->height + 1])
			&& !ft_validate_walls(map->parsed_map[map->height]))
			return (0);
		else if (!ft_validate_components(map, map->parsed_map[map->height]))
			return (0);
		map->height ++;
	}
	if (map->exit != 1 || map->collectibles < 1 || map->start_position != 1)
		return (0);
	return (1);
}
