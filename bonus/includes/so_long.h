/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:03:16 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/05 18:17:00 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../../minilibx/mlx.h"
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

# define SPACE_IMG				"bonus/assets/space.png"
# define WALL_IMG				"bonus/assets/wall.png,bonus/assets/wall2.png,\
bonus/assets/wall3.png"
# define GEMSTONE_IMG			"bonus/assets/gemstone1.png,bonus/assets/gemstone2.png,\
bonus/assets/gemstone3.png,bonus/assets/gemstone4.png"
# define R_EXIT_IMG				"bonus/assets/right_exit.png"
# define L_EXIT_IMG 			"bonus/assets/left_exit.png"
# define MOVEMENT_IMG 			"bonus/assets/miner_running1.png,bonus/assets/miner_running2.png,\
bonus/assets/miner_running3.png,bonus/assets/miner_running4.png,bonus/assets/miner_running5.png,\
bonus/assets/miner_running6.png,bonus/assets/miner_running7.png,\
bonus/assets/miner_running8.png"
# define R_PLAYER_IDLE_IMG		"bonus/assets/right_miner_idle1.png,bonus/assets/right_miner_idle2.png,\
bonus/assets/right_miner_idle3.png,bonus/assets/right_miner_idle4.png"
# define L_PLAYER_IDLE_IMG		"bonus/assets/left_miner_idle1.png,bonus/assets/left_miner_idle2.png,\
bonus/assets/left_miner_idle3.png,bonus/assets/left_miner_idle4.png"
# define R_PLAYER_COLLECT_IMG	"bonus/assets/right_miner_collect1.png,bonus/assets/right_miner_collect2.png,\
bonus/assets/right_miner_collect3.png,bonus/assets/right_miner_collect4.png,\
bonus/assets/right_miner_collect5.png"
# define L_PLAYER_COLLECT_IMG	"bonus/assets/left_miner_collect1.png,bonus/assets/left_miner_collect2.png,\
bonus/assets/left_miner_collect3.png,bonus/assets/left_miner_collect4.png,\
bonus/assets/left_miner_collect5.png"
# define R_PLAYER_DEAD_IMG		"bonus/assets/right_miner_die1.png,bonus/assets/right_miner_die2.png,\
bonus/assets/right_miner_die3.png,bonus/assets/right_miner_die4.png,bonus/assets/right_miner_die5.png,\
bonus/assets/right_miner_die6.png,bonus/assets/right_miner_die7.png,bonus/assets/right_miner_die8.png,\
bonus/assets/right_miner_die9.png"
# define L_PLAYER_DEAD_IMG		"bonus/assets/left_miner_die1.png,bonus/assets/left_miner_die2.png,\
bonus/assets/left_miner_die3.png,bonus/assets/left_miner_die4.png,bonus/assets/left_miner_die5.png,\
bonus/assets/left_miner_die6.png,bonus/assets/left_miner_die7.png,bonus/assets/left_miner_die8.png,\
bonus/assets/left_miner_die9.png"
# define R_ENEMY_IDLE_IMG		"bonus/assets/right_enemy_idle1.png,bonus/assets/right_enemy_idle2.png,\
bonus/assets/right_enemy_idle3.png,bonus/assets/right_enemy_idle4.png"
# define L_ENEMY_IDLE_IMG		"bonus/assets/left_enemy_idle1.png,bonus/assets/left_enemy_idle2.png,\
bonus/assets/left_enemy_idle3.png,bonus/assets/left_enemy_idle4.png"
# define R_ENEMY_ATTACK_IMG		"bonus/assets/right_enemy_attack1.png,bonus/assets/right_enemy_attack2.png,\
bonus/assets/right_enemy_attack3.png,bonus/assets/right_enemy_attack4.png,bonus/assets/right_enemy_attack5.png,\
bonus/assets/right_enemy_attack6.png,bonus/assets/right_enemy_attack7.png"
# define L_ENEMY_ATTACK_IMG		"bonus/assets/left_enemy_attack1.png,bonus/assets/left_enemy_attack2.png,\
bonus/assets/left_enemy_attack3.png,bonus/assets/left_enemy_attack4.png,bonus/assets/left_enemy_attack5.png,\
bonus/assets/left_enemy_attack6.png,bonus/assets/left_enemy_attack7.png"

typedef struct s_direction {
	void		**right;
	void		**left;
}	t_direction;

typedef struct s_frames {
	int			frame_count;
	int			movement_frame_count;
	int			attack_frame_count;
	int			collecting;
	int			dying;
	int			attacking;
	t_direction	idle;
	t_direction	collect;
	t_direction	dead;
	t_direction	attack;
	char		direction;
}	t_frames;

typedef struct s_assets {
	void		*empty_space;
	void		**wall;
	void		**gemstones;
	void		*right_exit;
	void		*left_exit;
	void		**movement;
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
void	ft_update_attacking_enemy_frames(t_vars *vars);
void	ft_update_enemy_position(t_vars *vars);
void	ft_update_movement_sprites(int count, t_vars *vars);
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