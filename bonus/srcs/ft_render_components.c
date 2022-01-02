/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_components.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:20:16 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/02 21:22:05 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_render_player_frames(int x, int y, t_vars *vars)
{
	t_direction	*asset;
	int			frame;

	frame = vars->map.assets.player.frame_count;
	if (vars->map.assets.player.dying || vars->map.game_over)
	{
		asset = &vars->map.assets.player.dead;
		if (vars->map.game_over)
			frame = ft_arrlen(asset->right) - 1;
	}
	else if (vars->map.assets.player.collecting)
		asset = &vars->map.assets.player.collect;
	else
		asset = &vars->map.assets.player.idle;
	if (vars->map.assets.player.direction == 'R')
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			asset->right[frame], x, y);
	else if (vars->map.assets.player.direction == 'L')
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			asset->left[frame], x, y);
}

void	ft_render_collectibles(int x, int y, t_vars *vars)
{
	int	i;

	i = 0;
	if ((x + y) % 10 > 8)
		i = 0;
	else if ((x + y) % 10 > 6)
		i = 1;
	else if ((x + y) % 10 > 3)
		i = 2;
	else if ((x + y) % 10 > 0)
		i = 3;
	mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
		vars->map.assets.gemstones[i], x, y);
}
