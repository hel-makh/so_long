/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 15:05:51 by hel-makh          #+#    #+#             */
/*   Updated: 2021/12/28 19:01:28 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode != KEY_A && keycode != KEY_D && keycode != KEY_W && keycode != KEY_S)
		return (0);
	mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img.img = mlx_xpm_file_to_image(vars->mlx, HERO_XPM, &vars->hero.width, &vars->hero.height);
	vars->img.addr = (int *)mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length,
								&vars->img.endian);
	if (keycode == KEY_A && vars->hero.x_pos - vars->hero.width > 0)
		vars->hero.x_pos -= vars->hero.width;
	else if (keycode == KEY_D && vars->hero.x_pos + vars->hero.width < WIN_WIDTH)
		vars->hero.x_pos += vars->hero.width;
	else if (keycode == KEY_W && vars->hero.y_pos - vars->hero.height > 0)
		vars->hero.y_pos -= vars->hero.height;
	else if (keycode == KEY_S && vars->hero.y_pos + vars->hero.height < WIN_HEIGHT)
		vars->hero.y_pos += vars->hero.height;
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.img, vars->hero.x_pos, vars->hero.y_pos);
	return (keycode);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "so_long");
	vars.img.img = mlx_xpm_file_to_image(vars.mlx, HERO_XPM, &vars.hero.width, &vars.hero.height);
	vars.img.addr = (int *)mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length,
								&vars.img.endian);
	vars.hero.x_pos = 300;
	vars.hero.y_pos = 250;
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img.img, vars.hero.x_pos, vars.hero.y_pos);
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
