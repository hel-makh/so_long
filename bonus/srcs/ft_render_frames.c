/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frames.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 21:07:01 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/05 16:07:03 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_render_asset(char component, int x, int y, t_vars *vars)
{
	if (component != WALL)
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			vars->map.assets.empty_space, x, y);
	if (component == WALL)
		ft_render_walls(x, y, vars);
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
	else if (component == ENEMY || component == KILLER
		|| component == R_ENEMY || component == L_ENEMY)
		ft_render_enemy_frames(x, y, component, vars);
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

void	ft_render_text(t_vars *vars)
{
	if (vars->map.game_ended)
		mlx_string_put(vars->mlx, vars->win.mlx_win, 20, 35,
			create_trgb(0, 204, 153, 0), "Congratulations, You won!");
	if (vars->map.game_over)
		mlx_string_put(vars->mlx, vars->win.mlx_win, 85, 35,
			create_trgb(0, 204, 51, 0), "Game over!");
	ft_update_movement_sprites(0, vars);
	mlx_string_put(vars->mlx, vars->win.mlx_win, vars->win.width - 45,
		vars->win.height - 30, create_trgb(0, 204, 153, 0),
		ft_itoa(vars->map.movements));
}

int	render_next_frame(t_vars *vars)
{
	ft_update_player_frames(vars);
	ft_update_enemy_frames(vars);
	ft_update_attacking_enemy_frames(vars);
	ft_update_enemy_position(vars);
	ft_update_movement_sprites(1, vars);
	return (0);
}
