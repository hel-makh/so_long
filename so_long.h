#ifndef SO_LONG_H
# define SO_LONG_H

// # include <mlx.h>
# include "minilibx_mms_20200219/mlx.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define KEY_A 0
# define KEY_W 13
# define KEY_S 1
# define KEY_D 2

# define HERO_XPM "./wutface.xpm"

typedef struct	s_position {
	int		x_pos;
	int		y_pos;
	int		width;
	int		height;
}				t_position;

typedef struct	s_data {
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	    *mlx;
	void	    *mlx_win;
	t_data	    img;
    t_position  hero;
}				t_vars;

#endif