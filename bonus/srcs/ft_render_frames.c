/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frames.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 21:07:01 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/02 23:47:27 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_render_asset(char component, int x, int y, t_vars *vars)
{
	if (component != WALL)
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			vars->map.assets.empty_space, x, y);
	if (component == WALL)
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			vars->map.assets.wall, x, y);
	else if (component == COLLECTIBLE)
		ft_render_collectibles(x, y, vars);
	else if (component == EXIT && x > vars->win.width / 2)
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			vars->map.assets.right_exit, x, y);
	else if (component == EXIT && x <= vars->win.width / 2)
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			vars->map.assets.left_exit, x, y);
	else if (component == START_POSITION)
	{
		if (vars->map.game_ended)
			ft_render_asset(EXIT, x, y, vars);
		ft_render_player_frames(x, y, vars);
	}
	else if (component == ENEMY)
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			vars->map.assets.enemy.idle.right
		[vars->map.assets.enemy.frame_count], x, y);
}

void	ft_render_assets(t_vars *vars)
{
	int	i;
	int	j;
	int	x;
	int	y;

	y = 0;
	i = 0;
	while (vars->map.parsed_map[i])
	{
		x = 0;
		j = 0;
		while (vars->map.parsed_map[i][j])
		{
			ft_render_asset(vars->map.parsed_map[i][j], x, y, vars);
			x += vars->map.assets.width;
			j ++;
		}
		y += vars->map.assets.height;
		i ++;
	}
}

static void ft_render_text(t_vars *vars)
{
	if (vars->map.game_ended)
		mlx_string_put(vars->mlx, vars->win.mlx_win, 20, 35,
			create_trgb(0, 204, 153, 0), "Congratulation, You won!");
	if (vars->map.assets.player.dying || vars->map.game_over)
		mlx_string_put(vars->mlx, vars->win.mlx_win, 20, 35,
			create_trgb(0, 204, 51, 0), "Game over!");
	mlx_string_put(vars->mlx, vars->win.mlx_win, vars->win.width - 40,
		vars->win.height - 30, create_trgb(0, 204, 153, 0),
		ft_itoa(vars->map.movements));
}

static void	ft_update_player_frames(t_vars *vars)
{
	static int	frame_count;
	int			max_frame_count;
	int			max_frames;

	if (vars->map.assets.player.dying)
	{
		max_frames = ft_arrlen(vars->map.assets.player.dead.right);
		max_frame_count = 1000;
	}
	else if (vars->map.assets.player.collecting)
	{
		max_frames = ft_arrlen(vars->map.assets.player.collect.right);
		max_frame_count = 600;
	}
	else
	{
		max_frames = ft_arrlen(vars->map.assets.player.idle.right);
		max_frame_count = 3000;
	}
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

int	render_next_frame(t_vars *vars)
{
	static int	frame_count;

	ft_update_player_frames(vars);
	if (++frame_count < 2000)
		return (1);
	frame_count = 0;
	if (++vars->map.assets.enemy.frame_count
		>= (int)ft_arrlen(vars->map.assets.enemy.idle.right))
		vars->map.assets.enemy.frame_count = 0;
	ft_render_assets(vars);
	ft_render_text(vars);
	return (0);
}
