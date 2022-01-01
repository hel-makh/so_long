/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:03:16 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/01 22:32:14 by hel-makh         ###   ########.fr       */
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
	START_POSITION = 80
};

# define SPACE_IMG "./assets/space.png"
# define WALL_IMG "./assets/wall.png"
# define GEMSTONE_IMG "./assets/gemstone.png"
# define R_EXIT_IMG "./assets/right_exit.png"
# define L_EXIT_IMG "./assets/left_exit.png"
# define PLAYER_IMG "./assets/miner.png"

typedef struct s_win {
	void		*mlx_win;
	int			width;
	int			height;
}	t_win;

typedef struct s_assets {
	void		*empty_space;
	void		*wall;
	void		*gemstone;
	void		*right_exit;
	void		*left_exit;
	void		*player;
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
	int			width;
	int			height;
	t_assets	assets;
}	t_map;

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
char	*ft_strnjoin(char const *s1, char const *s2, size_t n);
void	*ft_free(void *ptr);
void	*ft_free_2d(char **ptr);
void	*ft_free_3d(char ***ptr);
char	*get_next_line(int fd);
void	ft_parse_map(char *file, char ***map);
int		ft_is_map_valid(t_map *map);
void	ft_initialize_assets(t_vars *vars);
void	ft_render_assets(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		window_destroyed(t_vars *vars);
void	ft_quit_program(int status, t_vars *vars);

#endif