/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:40:09 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/03 14:29:18 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	**ft_get_frames(char *asset_path, t_vars *vars)
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

static void	ft_initialize_sprites(t_vars *vars)
{
	t_frames	*frame;

	frame = &vars->map.assets.player;
	frame->idle.right = ft_get_frames(R_PLAYER_IDLE_IMG, vars);
	frame->idle.left = ft_get_frames(L_PLAYER_IDLE_IMG, vars);
	frame->collect.right = ft_get_frames(R_PLAYER_COLLECT_IMG, vars);
	frame->collect.left = ft_get_frames(L_PLAYER_COLLECT_IMG, vars);
	frame->dead.right = ft_get_frames(R_PLAYER_DEAD_IMG, vars);
	frame->dead.left = ft_get_frames(L_PLAYER_DEAD_IMG, vars);
	frame = &vars->map.assets.enemy;
	frame->idle.right = ft_get_frames(R_ENEMY_IDLE_IMG, vars);
	frame->idle.left = ft_get_frames(L_ENEMY_IDLE_IMG, vars);
	frame->attack.right = ft_get_frames(R_ENEMY_ATTACK_IMG, vars);
	frame->attack.left = ft_get_frames(L_ENEMY_ATTACK_IMG, vars);
}

void	ft_initialize_assets(t_vars *vars)
{
	t_assets	*asset;

	asset = &vars->map.assets;
	asset->empty_space = mlx_png_file_to_image(vars->mlx,
			SPACE_IMG, &asset->width, &asset->height);
	asset->wall = ft_get_frames(WALL_IMG, vars);
	asset->gemstones = ft_get_frames(GEMSTONE_IMG, vars);
	asset->right_exit = mlx_png_file_to_image(vars->mlx,
			R_EXIT_IMG, &asset->width, &asset->height);
	asset->left_exit = mlx_png_file_to_image(vars->mlx,
			L_EXIT_IMG, &asset->width, &asset->height);
	ft_initialize_sprites(vars);
	if (!asset->empty_space || !asset->wall || !asset->gemstones[0]
		|| !asset->right_exit || !asset->left_exit
		|| !asset->player.idle.right[0] || !asset->player.idle.left[0]
		|| !asset->player.collect.right[0] || !asset->player.collect.left[0]
		|| !asset->player.dead.right[0] || !asset->player.dead.left[0]
		|| !asset->enemy.idle.right[0])
	{
		perror("Error\nCouldn't load assets");
		ft_quit_program(EXIT_FAILURE, vars);
	}
}
