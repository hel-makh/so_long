/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_frames.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:26:34 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/04 18:14:20 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_get_frames_count(
	int *max_frames, int *max_frame_count, t_vars *vars
	)
{
	if (vars->map.assets.player.dying)
	{
		*max_frames = ft_arrlen(vars->map.assets.player.dead.right);
		*max_frame_count = 1500;
	}
	else if (vars->map.assets.player.collecting)
	{
		*max_frames = ft_arrlen(vars->map.assets.player.collect.right);
		*max_frame_count = 600;
	}
	else
	{
		*max_frames = ft_arrlen(vars->map.assets.player.idle.right);
		*max_frame_count = 3000;
	}
}

void	ft_update_player_frames(t_vars *vars)
{
	static int	frame_count;
	int			max_frame_count;
	int			max_frames;

	ft_get_frames_count(&max_frames, &max_frame_count, vars);
	if (++frame_count < max_frame_count)
		return ;
	frame_count = 0;
	if (++vars->map.assets.player.frame_count >= max_frames)
	{
		vars->map.assets.player.frame_count = 0;
		if (vars->map.assets.player.collecting)
			vars->map.assets.player.collecting = 0;
		else if (vars->map.assets.player.dying)
		{
			vars->map.game_over = 1;
			vars->map.assets.player.dying = 0;
		}
	}
	ft_render_assets(vars);
	ft_render_text(vars);
}

void	ft_update_enemy_frames(t_vars *vars)
{
	static int	frame_count;

	if (++frame_count < 2000)
		return ;
	frame_count = 0;
	if (++vars->map.assets.enemy.frame_count
		>= (int)ft_arrlen(vars->map.assets.enemy.idle.right))
		vars->map.assets.enemy.frame_count = 0;
	ft_render_assets(vars);
	ft_render_text(vars);
}

void	ft_update_attacking_enemy_frames(t_vars *vars)
{
	static int	frame_count;

	if (!vars->map.assets.enemy.attacking)
		return ;
	if (++frame_count < 1000)
		return ;
	frame_count = 0;
	if (++vars->map.assets.enemy.attack_frame_count
		>= (int)ft_arrlen(vars->map.assets.enemy.attack.right))
	{
		vars->map.assets.enemy.attack_frame_count = 0;
		vars->map.assets.enemy.attacking = 0;
	}
	ft_render_assets(vars);
	ft_render_text(vars);
}

void	ft_update_movement_sprites(int count, t_vars *vars)
{
	static int	frame_count;

	if (count)
		frame_count ++;
	else
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			vars->map.assets.movement[vars->map.assets.player.movement_frame_count],
			vars->win.width - 80, vars->win.height - 50);
	if (frame_count < 1000)
		return ;
	frame_count = 0;
	if (++vars->map.assets.player.movement_frame_count
		>= (int)ft_arrlen(vars->map.assets.movement))
		vars->map.assets.player.movement_frame_count = 0;
	mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
		vars->map.assets.movement[vars->map.assets.player.movement_frame_count],
		vars->win.width - 80, vars->win.height - 50);
}
