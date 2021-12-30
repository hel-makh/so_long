/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:43:25 by hel-makh          #+#    #+#             */
/*   Updated: 2021/12/29 11:43:38 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_free(void *ptr)
{
	free(ptr);
	return (NULL);
}

void	ft_free_2d(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	ft_free_3d(char ***array)
{
	int	i;

	i = 0;
	while (array[i])
		ft_free_2d(array[i++]);
}
