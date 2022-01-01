/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:30:49 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/01 16:32:53 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	ft_arrlen(void **arr)
{
	size_t	arrlen;

	arrlen = 0;
	while (arr[arrlen] != '\0')
		arrlen ++;
	return (arrlen);
}
