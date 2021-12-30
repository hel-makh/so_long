/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 20:54:40 by hel-makh          #+#    #+#             */
/*   Updated: 2021/12/29 20:55:56 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	ft_arrlen(char **arr)
{
	size_t	arrlen;

	arrlen = 0;
	while (arr[arrlen])
		arrlen ++;
	return (arrlen);
}
