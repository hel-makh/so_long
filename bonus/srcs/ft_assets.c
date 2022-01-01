/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 21:07:01 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/02 00:32:25 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_put_asset(char component, int x, int y, t_vars *vars)
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
	else if (component == EXIT && x > vars->win.width / 2)
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			vars->map.assets.right_exit, x, y);
	else if (component == EXIT && x <= vars->win.width / 2)
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			vars->map.assets.left_exit, x, y);
	else if (component == START_POSITION)
	{
		if (vars->map.game_ended)
			ft_put_asset(EXIT, x, y, vars);
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			vars->map.assets.player[vars->map.frames.player], x, y);
	}
	else if (component == ENEMY)
		mlx_put_image_to_window(vars->mlx, vars->win.mlx_win,
			vars->map.assets.enemy[vars->map.frames.enemy], x, y);
}

void	ft_render_assets(t_vars *vars)
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
			ft_put_asset(vars->map.parsed_map[i][j], x, y, vars);
			x += vars->map.assets.width;
			j ++;
		}
		y += vars->map.assets.height;
		i ++;
	}
}

int	render_next_frame(t_vars *vars)
{
	static int	frame_count;

	if (++frame_count < 3000)
		return (1);
	frame_count = 0;
	ft_render_assets(vars);
	if (++vars->map.frames.player >= (int)ft_arrlen(vars->map.assets.player))
		vars->map.frames.player = 0;
	if (++vars->map.frames.enemy >= (int)ft_arrlen(vars->map.assets.enemy))
		vars->map.frames.enemy = 0;
	return (0);
}

void	**ft_initialize_frames(char *asset_path, t_vars *vars)
{
	char	**frames_path;
	void	**frames;
	int		i;

	frames_path = ft_split(asset_path, ',');
	i = 0;
	while (frames_path[i])
		i ++;
	frames = (void **) malloc ((i * sizeof(void *)) + 1);
	i = 0;
	while (frames_path[i])
	{
		frames[i] = mlx_png_file_to_image(vars->mlx,
				frames_path[i], &vars->map.assets.width,
				&vars->map.assets.height);
		i ++;
	}
	frames[i] = NULL;
	frames_path = ft_free_2d(frames_path);
	return (frames);
}

void	ft_initialize_assets(t_vars *vars)
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
	vars->map.assets.player = ft_initialize_frames(PLAYER_IMG, vars);
	vars->map.assets.enemy = ft_initialize_frames(ENEMY_IMG, vars);
	if (!vars->map.assets.empty_space || !vars->map.assets.wall
		|| !vars->map.assets.gemstone || !vars->map.assets.right_exit
		|| !vars->map.assets.left_exit || !vars->map.assets.player[0]
		|| !vars->map.assets.enemy[0])
	{
		perror("Error\nCouldn't load assets");
		ft_quit_program(EXIT_FAILURE, vars);
	}
}
