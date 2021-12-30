/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:23:18 by hel-makh          #+#    #+#             */
/*   Updated: 2021/12/29 22:23:35 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_exit_program(t_vars *vars)
{
	mlx_destroy_image(vars->win.mlx, vars->img.img);
	mlx_destroy_window(vars->win.mlx, vars->win.mlx_win);
	ft_free_2d(vars->map.parsed_map);
	exit(EXIT_SUCCESS);
}
