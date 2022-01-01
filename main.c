/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 15:05:51 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/01 12:20:22 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

// #include "srcs/ft_strcpy.c"
// #include "srcs/ft_free.c"
// #include "srcs/ft_strnjoin.c"
// #include "srcs/get_next_line.c"
// #include "srcs/ft_parse_map.c"
// #include "srcs/ft_validate_map.c"
// #include "srcs/ft_assets.c"
// #include "srcs/ft_movements.c"
// #include "srcs/ft_quit_program.c"

static void	ft_so_long(t_vars *vars)
{
	vars->mlx = mlx_init();
	ft_initialize_assets(vars);
	vars->win.width = vars->map.assets.width * vars->map.width;
	vars->win.height = vars->map.assets.height * vars->map.height;
	vars->win.mlx_win = mlx_new_window(vars->mlx,
			vars->win.width, vars->win.height, "so_long");
	ft_render_assets(vars);
	mlx_key_hook(vars->win.mlx_win, key_hook, vars);
	mlx_hook(vars->win.mlx_win, 17, 0L, ft_window_destroyed, vars);
	mlx_loop(vars->mlx);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
	{
		ft_putendl_fd("Error\nProgram must take 1 argument.", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))
		|| ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))[4])
	{
		ft_putendl_fd("Error\nProgram must take a <.ber> file.", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	ft_parse_map(argv[1], &vars.map.parsed_map);
	if (!ft_is_map_valid(&vars.map))
	{
		ft_putendl_fd("Error\nInvalid map.", STDERR_FILENO);
		ft_quit_program(EXIT_FAILURE, &vars);
	}
	ft_so_long(&vars);
	ft_quit_program(EXIT_SUCCESS, &vars);
}
