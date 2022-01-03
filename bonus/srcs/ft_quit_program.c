/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:23:18 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/03 14:29:26 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_destroy_frames(void *mlx, void **frames)
{
	int	i;

	i = 0;
	while (frames[i])
	{
		mlx_destroy_image(mlx, frames[i]);
		i ++;
	}
	frames = ft_free(frames);
}

void	ft_quit_program(int status, t_vars *vars)
{
	if (status == EXIT_SUCCESS)
	{
		mlx_destroy_image(vars->mlx, vars->map.assets.empty_space);
		ft_destroy_frames(vars->mlx, vars->map.assets.wall);
		ft_destroy_frames(vars->mlx, vars->map.assets.gemstones);
		mlx_destroy_image(vars->mlx, vars->map.assets.right_exit);
		mlx_destroy_image(vars->mlx, vars->map.assets.left_exit);
		ft_destroy_frames(vars->mlx, vars->map.assets.player.idle.right);
		ft_destroy_frames(vars->mlx, vars->map.assets.player.idle.left);
		ft_destroy_frames(vars->mlx, vars->map.assets.player.collect.right);
		ft_destroy_frames(vars->mlx, vars->map.assets.player.collect.left);
		ft_destroy_frames(vars->mlx, vars->map.assets.player.dead.right);
		ft_destroy_frames(vars->mlx, vars->map.assets.player.dead.left);
		ft_destroy_frames(vars->mlx, vars->map.assets.enemy.idle.right);
		ft_destroy_frames(vars->mlx, vars->map.assets.enemy.idle.left);
		ft_destroy_frames(vars->mlx, vars->map.assets.enemy.attack.right);
		ft_destroy_frames(vars->mlx, vars->map.assets.enemy.attack.left);
		mlx_destroy_window(vars->mlx, vars->win.mlx_win);
	}
	ft_free_2d(vars->map.parsed_map);
	exit(status);
}

int	window_destroyed(t_vars *vars)
{
	ft_quit_program(EXIT_SUCCESS, vars);
	return (EXIT_SUCCESS);
}
