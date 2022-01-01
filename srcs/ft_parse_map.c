/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:07:46 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/01 11:46:42 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_parse_map(char *file, char ***map)
{
	int		fd;
	char	*line;
	char	*lines;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nCouldn't open map");
		exit(EXIT_FAILURE);
	}
	lines = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		lines = ft_strnjoin(lines, line, ft_strlen(line));
		line = ft_free(line);
	}
	close(fd);
	*map = ft_split(lines, '\n');
	lines = ft_free(lines);
}
