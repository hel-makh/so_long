/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:23:18 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/01 01:21:27 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_exit_program(int status, t_vars *vars)
{
	if (status == EXIT_SUCCESS)
	{
		mlx_destroy_image(vars->mlx, vars->map.assets.empty_space);
		mlx_destroy_image(vars->mlx, vars->map.assets.wall);
		mlx_destroy_image(vars->mlx, vars->map.assets.gemstone);
		mlx_destroy_image(vars->mlx, vars->map.assets.exit);
		mlx_destroy_image(vars->mlx, vars->map.assets.player);
		mlx_destroy_window(vars->mlx, vars->win.mlx_win);
	}
	ft_free_2d(vars->map.parsed_map);
	exit(status);
}
