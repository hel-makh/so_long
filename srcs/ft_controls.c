/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 21:44:54 by hel-makh          #+#    #+#             */
/*   Updated: 2021/12/29 23:24:13 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_get_player_pos(int *x, int *y, t_vars *vars)
{
	*x = 0;
	while (vars->map.parsed_map[*x])
	{
		*y = 0;
		while (vars->map.parsed_map[*x][*y])
		{
			if (vars->map.parsed_map[*x][*y] == START_POSITION)
				return ;
			*y += 1;
		}
		*x += 1;
	}
}

static void ft_move_to(char *current_pos, char *new_pos, t_vars *vars)
{
    if (*new_pos == EMPTY_SPACE
        || *new_pos == COLLECTIBLE
        || (*new_pos == EXIT && vars->map.collectibles == 0))
    {
        if (*new_pos == COLLECTIBLE)
            vars->map.collectibles --;
        else if (*new_pos == EXIT)
	    	ft_exit_program(vars);
        *current_pos = EMPTY_SPACE;
        *new_pos = START_POSITION;
    }
}

void	ft_key_move(int keycode, t_vars *vars)
{
	int	i;
	int	j;

	ft_get_player_pos(&i, &j, vars);
	if (keycode == KEY_A)
		ft_move_to(&vars->map.parsed_map[i][j],
			&vars->map.parsed_map[i][j - 1], vars);
	else if (keycode == KEY_D)
		ft_move_to(&vars->map.parsed_map[i][j],
			&vars->map.parsed_map[i][j + 1], vars);
	else if (keycode == KEY_W)
		ft_move_to(&vars->map.parsed_map[i][j],
			&vars->map.parsed_map[i - 1][j], vars);
	else if (keycode == KEY_S)
		ft_move_to(&vars->map.parsed_map[i][j],
			&vars->map.parsed_map[i + 1][j], vars);
}
