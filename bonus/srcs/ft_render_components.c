/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_components.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:20:16 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/03 19:59:04 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_render_walls(int x, int y, t_vars *vars)
{
	if ((y == 0 && x != 0
			&& x != (vars->win.width - vars->map.assets.width))
		|| y == (vars->win.height - vars->map.assets.height))
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			vars->map.assets.wall[0], x, y);
	else if (x != 0 && y != 0
		&& x != (vars->win.width - vars->map.assets.width)
		&& y != (vars->win.height - vars->map.assets.height))
	{
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			vars->map.assets.empty_space, x, y);
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			vars->map.assets.wall[2], x, y);
	}
	else
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			vars->map.assets.wall[1], x, y);
}

void	ft_render_collectibles(int x, int y, t_vars *vars)
{
	int	i;

	i = 0;
	if ((x + y) % 10 > 8)
		i = 0;
	else if ((x + y) % 10 > 6)
		i = 1;
	else if ((x + y) % 10 > 3)
		i = 2;
	else if ((x + y) % 10 > 0)
		i = 3;
	mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
		vars->map.assets.gemstones[i], x, y);
}

void	ft_render_player_frames(int x, int y, t_vars *vars)
{
	t_direction	*asset;
	int			frame;

	frame = vars->map.assets.player.frame_count;
	if (vars->map.assets.player.dying || vars->map.game_over)
	{
		asset = &vars->map.assets.player.dead;
		if (vars->map.game_over)
			frame = ft_arrlen(asset->right) - 1;
	}
	else if (vars->map.assets.player.collecting)
		asset = &vars->map.assets.player.collect;
	else
		asset = &vars->map.assets.player.idle;
	if (vars->map.assets.player.direction == 'R')
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			asset->right[frame], x, y);
	else if (vars->map.assets.player.direction == 'L')
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			asset->left[frame], x, y);
}

void	ft_render_enemy_frames(int x, int y, int type, t_vars *vars)
{
	t_direction	*asset;
	int			frame;

	frame = vars->map.assets.enemy.frame_count;
	if (type == KILLER && vars->map.assets.enemy.attacking)
		asset = &vars->map.assets.enemy.attack;
	else
		asset = &vars->map.assets.enemy.idle;
	if ((type == KILLER && vars->map.assets.enemy.attacking
			&& vars->map.assets.player.direction == 'L')
		|| (type == R_ENEMY
			&& !vars->map.assets.enemy.attacking))
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			asset->right[frame], x, y);
	else if ((type == KILLER && vars->map.assets.enemy.attacking
			&& vars->map.assets.player.direction == 'R')
		|| (type == L_ENEMY
			&& !vars->map.assets.enemy.attacking))
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			asset->left[frame], x, y);
	else if (type == ENEMY || type == KILLER)
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			asset->right[frame], x, y);
}
