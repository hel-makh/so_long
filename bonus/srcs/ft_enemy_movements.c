/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_movements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:38:16 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/04 18:24:29 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_move_enemy_to(char *current_pos, char *new_pos, t_vars *vars)
{
	if (*new_pos == WALL || *new_pos == EXIT || *new_pos == COLLECTIBLE
		|| *new_pos == ENEMY || *new_pos == KILLER
		|| *new_pos == R_ENEMY || *new_pos == L_ENEMY
		|| (*new_pos == START_POSITION
			&& (vars->map.game_over || vars->map.game_ended)))
		return ;
	if (*new_pos == START_POSITION)
	{
		*current_pos = KILLER;
		vars->map.assets.enemy.frame_count = 0;
		vars->map.assets.enemy.attack_frame_count = 0;
		vars->map.assets.enemy.attacking = 1;
		vars->map.assets.player.frame_count = 0;
		vars->map.assets.player.dying = 1;
		return ;
	}
	*new_pos = *current_pos;
	*current_pos = EMPTY_SPACE;
}

static void	ft_move_enemy(int x, int y, t_vars *vars)
{
	int	rand;

	rand = arc4random_uniform(4);
	if (rand == 0)
	{
		vars->map.parsed_map[x][y] = L_ENEMY;
		ft_move_enemy_to(&vars->map.parsed_map[x][y],
			&vars->map.parsed_map[x][y - 1], vars);
	}
	else if (rand == 1)
	{
		vars->map.parsed_map[x][y] = R_ENEMY;
		ft_move_enemy_to(&vars->map.parsed_map[x][y],
			&vars->map.parsed_map[x][y + 1], vars);
	}
	else if (rand == 2)
		ft_move_enemy_to(&vars->map.parsed_map[x][y],
			&vars->map.parsed_map[x - 1][y], vars);
	else if (rand == 3)
		ft_move_enemy_to(&vars->map.parsed_map[x][y],
			&vars->map.parsed_map[x + 1][y], vars);
}

void	ft_update_enemy_position(t_vars *vars)
{
	static int	frame_count;
	int			i;
	int			j;

	if (++frame_count < 12000)
		return ;
	frame_count = 0;
	i = -1;
	while (vars->map.parsed_map[++i])
	{
		j = -1;
		while (vars->map.parsed_map[i][++j])
		{
			if (vars->map.parsed_map[i][j] == ENEMY
				|| (vars->map.parsed_map[i][j] == KILLER
						&& !vars->map.assets.enemy.attacking)
				|| vars->map.parsed_map[i][j] == R_ENEMY
				|| vars->map.parsed_map[i][j] == L_ENEMY)
			{
				ft_move_enemy(i, j, vars);
				ft_render_assets(vars);
				ft_render_text(vars);
			}
		}
	}
}
