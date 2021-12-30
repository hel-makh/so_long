/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:03:16 by hel-makh          #+#    #+#             */
/*   Updated: 2021/12/30 18:22:08 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
// # include <mlx.h>
// # include "../minilibx_opengl_20191021/mlx.h"
# include "../minilibx_mms_20200219/mlx.h"
# include "../Libft/libft.h"

# define KEY_ESC 53
# define KEY_A 0
# define KEY_W 13
# define KEY_S 1
# define KEY_D 2

# define EMPTY_SPACE 48
# define WALL 49
# define COLLECTIBLE 67
# define EXIT 69
# define START_POSITION 80

# define SPACE_IMG "./textures/space.png"
# define WALL_IMG "./textures/wall.png"
# define COLLECTIBLE_IMG "./textures/collectible.png"
# define EXIT_IMG "./textures/exit.png"
# define PLAYER_IMG "./textures/player.png"

typedef struct s_win {
	void	*mlx_win;
	int		width;
	int		height;
}	t_win;

typedef struct s_map {
	char	**parsed_map;
	int		width;
	int		height;
	int		collectibles;
	int		exit;
	int		start_position;
	int		movements;
	int		game_ended;
}	t_map;

typedef struct s_image {
	void	*img;
	int		x_pos;
	int		y_pos;
	int		width;
	int		height;
}	t_img;

typedef struct s_vars {
	void	*mlx;
	t_win	win;
	t_map	map;
	t_img	img;
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
char	*ft_free(void *ptr);
void	ft_free_2d(char **array);
void	ft_free_3d(char ***array);
char	*get_next_line(int fd);
void	ft_parse_map(char *file, char ***map);
int		ft_valid_map(t_map *map);
void	ft_render_images(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
void	ft_exit_program(int status, t_vars *vars);

#endif