/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 21:07:01 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/01 11:48:23 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_put_image(char component, int x, int y, t_vars *vars)
{
	if (component != WALL)
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			vars->map.assets.empty_space, x, y);
	if (component == WALL)
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			vars->map.assets.wall, x, y);
	else if (component == COLLECTIBLE)
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			vars->map.assets.gemstone, x, y);
	else if (component == EXIT)
	{
		if (x > vars->win.width)
			mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
				vars->map.assets.right_exit, x, y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
				vars->map.assets.left_exit, x, y);
	}
	else if (component == START_POSITION)
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			vars->map.assets.player, x, y);
}

void	ft_render_images(t_vars *vars)
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
			ft_put_image(vars->map.parsed_map[i][j], x, y, vars);
			x += vars->map.assets.width;
			j ++;
		}
		y += vars->map.assets.height;
		i ++;
	}
}

void	ft_initialize_images(t_vars *vars)
{
	vars->map.assets.empty_space = mlx_png_file_to_image(vars->mlx,
			SPACE_IMG, &vars->map.assets.width, &vars->map.assets.height);
	vars->map.assets.wall = mlx_png_file_to_image(vars->mlx,
			WALL_IMG, &vars->map.assets.width, &vars->map.assets.height);
	vars->map.assets.gemstone = mlx_png_file_to_image(vars->mlx,
			GEMSTONE_IMG, &vars->map.assets.width, &vars->map.assets.height);
	vars->map.assets.right_exit = mlx_png_file_to_image(vars->mlx,
			R_EXIT_IMG, &vars->map.assets.width, &vars->map.assets.height);
	vars->map.assets.left_exit = mlx_png_file_to_image(vars->mlx,
			L_EXIT_IMG, &vars->map.assets.width, &vars->map.assets.height);
	vars->map.assets.player = mlx_png_file_to_image(vars->mlx,
			PLAYER_IMG, &vars->map.assets.width, &vars->map.assets.height);
	if (!vars->map.assets.empty_space || !vars->map.assets.wall
		|| !vars->map.assets.gemstone || !vars->map.assets.right_exit
		|| !vars->map.assets.left_exit || !vars->map.assets.player)
	{
		perror("Error\nCouldn't load assets");
		ft_exit_program(EXIT_FAILURE, vars);
	}
}
