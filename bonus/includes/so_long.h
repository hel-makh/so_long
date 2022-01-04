/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:03:16 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/04 16:12:49 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
// # include "../../minilibx_opengl_20191021/mlx.h"
# include "../../minilibx_mms_20200219/mlx.h"
# include "../../Libft/libft.h"

enum e_keycodes
{
	KEY_ESC = 53,
	KEY_A = 0,
	KEY_W = 13,
	KEY_S = 1,
	KEY_D = 2
};

enum e_components
{
	EMPTY_SPACE = 48,
	WALL = 49,
	COLLECTIBLE = 67,
	EXIT = 69,
	START_POSITION = 80,
	ENEMY = 78,
	R_ENEMY = 82,
	L_ENEMY = 76,
	KILLER = 75
};

# define SPACE_IMG				"assets/space.png"
# define WALL_IMG				"assets/wall.png,assets/wall2.png,assets/wall3.png"
# define GEMSTONE_IMG			"assets/gemstone1.png,assets/gemstone2.png,\
assets/gemstone3.png,assets/gemstone4.png"
# define R_EXIT_IMG				"assets/right_exit.png"
# define L_EXIT_IMG 			"assets/left_exit.png"
# define R_PLAYER_IDLE_IMG		"assets/right_miner_idle1.png,assets/right_miner_idle2.png,\
assets/right_miner_idle3.png,assets/right_miner_idle4.png"
# define L_PLAYER_IDLE_IMG		"assets/left_miner_idle1.png,assets/left_miner_idle2.png,\
assets/left_miner_idle3.png,assets/left_miner_idle4.png"
# define R_PLAYER_COLLECT_IMG	"assets/right_miner_collect1.png,assets/right_miner_collect2.png,\
assets/right_miner_collect3.png,assets/right_miner_collect4.png,assets/right_miner_collect5.png"
# define L_PLAYER_COLLECT_IMG	"assets/left_miner_collect1.png,assets/left_miner_collect2.png,\
assets/left_miner_collect3.png,assets/left_miner_collect4.png,assets/left_miner_collect5.png"
# define R_PLAYER_DEAD_IMG		"assets/right_miner_die1.png,assets/right_miner_die2.png,\
assets/right_miner_die3.png,assets/right_miner_die4.png,assets/right_miner_die5.png,\
assets/right_miner_die6.png,assets/right_miner_die7.png,assets/right_miner_die8.png,\
assets/right_miner_die9.png"
# define L_PLAYER_DEAD_IMG		"assets/left_miner_die1.png,assets/left_miner_die2.png,\
assets/left_miner_die3.png,assets/left_miner_die4.png,assets/left_miner_die5.png,\
assets/left_miner_die6.png,assets/left_miner_die7.png,assets/left_miner_die8.png,\
assets/left_miner_die9.png"
# define R_ENEMY_IDLE_IMG		"assets/right_enemy_idle1.png,assets/right_enemy_idle2.png,\
assets/right_enemy_idle3.png,assets/right_enemy_idle4.png"
# define L_ENEMY_IDLE_IMG		"assets/left_enemy_idle1.png,assets/left_enemy_idle2.png,\
assets/left_enemy_idle3.png,assets/left_enemy_idle4.png"
# define R_ENEMY_ATTACK_IMG		"assets/right_enemy_attack1.png,assets/right_enemy_attack2.png,\
assets/right_enemy_attack3.png,assets/right_enemy_attack4.png,assets/right_enemy_attack5.png,\
assets/right_enemy_attack6.png,assets/right_enemy_attack7.png"
# define L_ENEMY_ATTACK_IMG		"assets/left_enemy_attack1.png,assets/left_enemy_attack2.png,\
assets/left_enemy_attack3.png,assets/left_enemy_attack4.png,assets/left_enemy_attack5.png,\
assets/left_enemy_attack6.png,assets/left_enemy_attack7.png"

typedef struct s_direction {
	void		**right;
	void		**left;
}	t_direction;

typedef struct s_frames {
	int			frame_count;
	int			collecting;
	int			dying;
	int			attacking;
	t_direction	idle;
	t_direction	collect;
	t_direction	dead;
	t_direction	attack;
	int			attack_frame_count;
	char		direction;
}	t_frames;

typedef struct s_assets {
	void		*empty_space;
	void		**wall;
	void		**gemstones;
	void		*right_exit;
	void		*left_exit;
	t_frames	player;
	t_frames	enemy;
	int			width;
	int			height;
}	t_assets;

typedef struct s_map {
	char		**parsed_map;
	int			collectibles;
	int			exit;
	int			start_position;
	int			movements;
	int			game_ended;
	int			game_over;
	int			width;
	int			height;
	t_assets	assets;
}	t_map;

typedef struct s_win {
	void		*mlx_win;
	int			width;
	int			height;
}	t_win;

typedef struct s_vars {
	void		*mlx;
	t_win		win;
	t_map		map;
}	t_vars;

# define BUFFER_SIZE 1

typedef struct s_line
{
	int				fd;
	char			content[BUFFER_SIZE + 1];
	struct s_line	*next;
}	t_line;

char	*ft_strcpy(char *dst, const char *src);
size_t	ft_arrlen(void **arr);
char	*ft_strnjoin(char const *s1, char const *s2, size_t n);
void	*ft_free(void *ptr);
void	*ft_free_2d(char **ptr);
void	*ft_free_3d(char ***ptr);
char	*get_next_line(int fd);
int		create_trgb(int t, int r, int g, int b);
void	ft_parse_map(char *file, char ***map);
int		ft_is_map_valid(t_map *map);
void	ft_initialize_assets(t_vars *vars);
int		render_next_frame(t_vars *vars);
void	ft_update_player_frames(t_vars *vars);
void	ft_update_enemy_frames(t_vars *vars);
void	ft_update_enemy_position(t_vars *vars);
void	ft_render_text(t_vars *vars);
void	ft_render_assets(t_vars *vars);
void	ft_render_walls(int x, int y, t_vars *vars);
void	ft_render_collectibles(int x, int y, t_vars *vars);
void	ft_render_player_frames(int x, int y, t_vars *vars);
void	ft_render_enemy_frames(int x, int y, int type, t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		window_destroyed(t_vars *vars);
void	ft_quit_program(int status, t_vars *vars);

#endif