/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:59:13 by crepou            #+#    #+#             */
/*   Updated: 2022/11/22 14:09:44 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t					count;
	const unsigned char		*p;

	count = 0;
	p = (const unsigned char *)str;
	while (count < n)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
		count++;
	}
	return (0);
}
