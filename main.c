/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 15:05:51 by hel-makh          #+#    #+#             */
/*   Updated: 2021/12/29 23:26:15 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/so_long.h"

#include "srcs/ft_strcpy.c"
#include "srcs/ft_free.c"
#include "srcs/ft_strnjoin.c"
#include "srcs/get_next_line.c"
#include "srcs/ft_parse_map.c"
#include "srcs/ft_validate_map.c"
#include "srcs/ft_arrlen.c"
#include "srcs/ft_render_images.c"
#include "srcs/ft_controls.c"
#include "srcs/ft_exit_program.c"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		ft_exit_program(vars);
	if (keycode != KEY_A && keycode != KEY_D
		&& keycode != KEY_W && keycode != KEY_S)
		return (0);
	ft_key_move(keycode, vars);
	mlx_destroy_image(vars->win.mlx, vars->img.img);
	ft_render_images(vars);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
		return (EXIT_FAILURE);
	ft_parse_map(argv[1], &vars.map.parsed_map);
	if (!ft_valid_map(&vars.map))
		return (EXIT_FAILURE);
	vars.win.mlx = mlx_init();
	vars.img.img = mlx_png_file_to_image(vars.win.mlx,
			HERO_IMG, &vars.img.width, &vars.img.height);
	vars.win.width = vars.img.width * ft_strlen(vars.map.parsed_map[0]);
	vars.win.height = vars.img.height * ft_arrlen(vars.map.parsed_map);
	vars.win.mlx_win = mlx_new_window(vars.win.mlx,
			vars.win.width, vars.win.height, "so_long");
	ft_render_images(&vars);
	mlx_key_hook(vars.win.mlx_win, key_hook, &vars);
	mlx_loop(vars.win.mlx);
	return (EXIT_SUCCESS);
}
