/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 21:07:01 by hel-makh          #+#    #+#             */
/*   Updated: 2021/12/30 18:33:40 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_get_component_image(char component, t_vars *vars)
{
	if (component == EMPTY_SPACE)
		vars->img.img = mlx_png_file_to_image(vars->mlx,
				SPACE_IMG, &vars->img.width, &vars->img.height);
	else if (component == WALL)
		vars->img.img = mlx_png_file_to_image(vars->mlx,
				WALL_IMG, &vars->img.width, &vars->img.height);
	else if (component == COLLECTIBLE)
		vars->img.img = mlx_png_file_to_image(vars->mlx,
				COLLECTIBLE_IMG, &vars->img.width, &vars->img.height);
	else if (component == EXIT)
		vars->img.img = mlx_png_file_to_image(vars->mlx,
				EXIT_IMG, &vars->img.width, &vars->img.height);
	else if (component == START_POSITION)
		vars->img.img = mlx_png_file_to_image(vars->mlx,
				PLAYER_IMG, &vars->img.width, &vars->img.height);
}

void	ft_render_images(t_vars *vars)
{
	int	i;
	int	j;

	vars->img.y_pos = 0;
	i = 0;
	while (vars->map.parsed_map[i])
	{
		vars->img.x_pos = 0;
		j = 0;
		while (vars->map.parsed_map[i][j])
		{
			ft_get_component_image(vars->map.parsed_map[i][j], vars);
			mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
				vars->img.img, vars->img.x_pos, vars->img.y_pos);
			vars->img.x_pos += vars->img.width;
			j ++;
		}
		vars->img.y_pos += vars->img.height;
		i ++;
	}
}
