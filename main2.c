/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 15:05:51 by hel-makh          #+#    #+#             */
/*   Updated: 2021/12/28 19:01:51 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <mlx.h>
#include "so_long2.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode != 0 && keycode != 2 && keycode != 13 && keycode != 1)
		return (0);
	mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->img.addr = (int *)mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length,
								&vars->img.endian);
	if (keycode == KEY_A && vars->hero.x_pos - vars->hero.radius > 0)
		vars->hero.x_pos -= vars->hero.radius;
	else if (keycode == KEY_D && vars->hero.x_pos + vars->hero.radius < WIN_WIDTH)
		vars->hero.x_pos += vars->hero.radius;
	else if (keycode == KEY_W && vars->hero.y_pos - vars->hero.radius > 0)
		vars->hero.y_pos -= vars->hero.radius;
	else if (keycode == KEY_S && vars->hero.y_pos + vars->hero.radius < WIN_HEIGHT)
		vars->hero.y_pos += vars->hero.radius;
	int i = 0;
	while (i < WIN_WIDTH)
	{
		int j = 0;
		while (j < WIN_HEIGHT)
		{
			if ((i < vars->hero.x_pos + vars->hero.radius && i > vars->hero.x_pos - vars->hero.radius)
				&& (j < vars->hero.y_pos + vars->hero.radius && j > vars->hero.y_pos - vars->hero.radius))
				vars->img.addr[j * WIN_WIDTH + i] = create_trgb(0, 255, 255, 255);
			j ++;
		}
		i ++;
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.img, 0, 0);
	return (keycode);
}

int	main(void)
{
	t_vars		vars;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
	vars.img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	vars.img.addr = (int *)mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length,
								&vars.img.endian);
	vars.hero.x_pos = 300;
	vars.hero.y_pos = 250;
	vars.hero.radius = 5;
	int i = 0;
	while (i < WIN_WIDTH)
	{
		int j = 0;
		while (j < WIN_HEIGHT)
		{
			if ((i < vars.hero.x_pos + vars.hero.radius && i > vars.hero.x_pos - vars.hero.radius)
				&& (j < vars.hero.y_pos + vars.hero.radius && j > vars.hero.y_pos - vars.hero.radius))
				vars.img.addr[j * WIN_WIDTH + i] = create_trgb(0, 255, 255, 255);
			j ++;
		}
		i ++;
	}
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img.img, 0, 0);
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
