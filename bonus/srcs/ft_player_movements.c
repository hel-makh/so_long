/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_movements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 21:44:54 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/04 16:24:32 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_get_player_pos(int *x, int *y, t_vars *vars)
{
	*x = 0;
	while (vars->map.parsed_map[*x])
	{
		*y = 0;
		while (vars->map.parsed_map[*x][*y])
		{
			if (vars->map.parsed_map[*x][*y] == START_POSITION)
				return ;
			*y += 1;
		}
		*x += 1;
	}
}

static void	ft_move_player_to(char *current_pos, char *new_pos, t_vars *vars)
{
	if (*new_pos == COLLECTIBLE)
	{
		vars->map.assets.player.collecting = 1;
		vars->map.assets.player.frame_count = 0;
		vars->map.collectibles --;
		*new_pos = EMPTY_SPACE;
		return ;
	}
	if (*new_pos == ENEMY || *new_pos == R_ENEMY || *new_pos == L_ENEMY)
	{
		*new_pos = KILLER;
		vars->map.assets.enemy.frame_count = 0;
		vars->map.assets.enemy.attack_frame_count = 0;
		vars->map.assets.enemy.attacking = 1;
		vars->map.assets.player.frame_count = 0;
		vars->map.assets.player.dying = 1;
		return ;
	}
	if (*new_pos == WALL || (*new_pos == EXIT && vars->map.collectibles > 0))
		return ;
	if (*new_pos == EXIT && vars->map.collectibles == 0)
		vars->map.game_ended = 1;
	*current_pos = EMPTY_SPACE;
	*new_pos = START_POSITION;
	vars->map.movements ++;
}

static void	ft_key_move(int keycode, t_vars *vars)
{
	int	x;
	int	y;

	ft_get_player_pos(&x, &y, vars);
	if (keycode == KEY_A)
	{
		vars->map.assets.player.direction = 'L';
		ft_move_player_to(&vars->map.parsed_map[x][y],
			&vars->map.parsed_map[x][y - 1], vars);
	}
	else if (keycode == KEY_D)
	{
		vars->map.assets.player.direction = 'R';
		ft_move_player_to(&vars->map.parsed_map[x][y],
			&vars->map.parsed_map[x][y + 1], vars);
	}
	else if (keycode == KEY_W)
		ft_move_player_to(&vars->map.parsed_map[x][y],
			&vars->map.parsed_map[x - 1][y], vars);
	else if (keycode == KEY_S)
		ft_move_player_to(&vars->map.parsed_map[x][y],
			&vars->map.parsed_map[x + 1][y], vars);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		ft_quit_program(EXIT_SUCCESS, vars);
	if ((keycode != KEY_A && keycode != KEY_D
			&& keycode != KEY_W && keycode != KEY_S)
		|| vars->map.game_ended
		|| vars->map.game_over
		|| vars->map.assets.player.collecting
		|| vars->map.assets.player.dying)
		return (0);
	ft_key_move(keycode, vars);
	ft_render_assets(vars);
	ft_render_text(vars);
	return (1);
}
