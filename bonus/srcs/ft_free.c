/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:43:25 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/01 15:51:46 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_free(void *ptr)
{
	free(ptr);
	return (NULL);
}

void	*ft_free_2d(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
	return (NULL);
}

void	*ft_free_3d(char ***ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		ft_free_2d(ptr[i++]);
	return (NULL);
}
