/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 15:05:51 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/01 01:07:32 by hel-makh         ###   ########.fr       */
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
#include "srcs/ft_images.c"
#include "srcs/ft_controls.c"
#include "srcs/ft_exit_program.c"

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nProgram must take 1 argument.\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (!ft_strstr(argv[1], ".ber") || ft_strstr(argv[1], ".ber")[4])
	{
		ft_putstr_fd("Error\nProgram must take a <.ber> file.\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	ft_parse_map(argv[1], &vars.map.parsed_map);
	if (!ft_is_map_valid(&vars.map))
	{
		ft_putstr_fd("Error\nInvalid map.\n", STDERR_FILENO);
		ft_exit_program(EXIT_FAILURE, &vars);
	}
	vars.mlx = mlx_init();
	ft_initialize_images(&vars);
	vars.win.width = vars.map.assets.width * vars.map.width;
	vars.win.height = vars.map.assets.height * vars.map.height;
	vars.win.mlx_win = mlx_new_window(vars.mlx,
			vars.win.width, vars.win.height, "so_long");
	ft_render_images(&vars);
	mlx_key_hook(vars.win.mlx_win, key_hook, &vars);
	mlx_loop(vars.mlx);
	ft_exit_program(EXIT_SUCCESS, &vars);
}
