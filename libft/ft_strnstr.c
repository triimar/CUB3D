/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:41:02 by crepou            #+#    #+#             */
/*   Updated: 2022/11/22 15:08:01 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_samestr(const char *p, const char *s2, size_t c, size_t ln)
{
	if ((ln - c) < ft_strlen(s2))
		return (0);
	while ((c < ln) && (*s2 != '\0'))
	{
		if (*p != *s2)
			return (0);
		s2++;
		p++;
	}
	return (1);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t			count;
	const char		*p;
	char			*p2;

	count = 0;
	p = s1;
	if (!s1 && len == 0)
		return (NULL);
	if (ft_strlen(s1) < len)
		len = ft_strlen(s1);
	if (!ft_strlen(s2))
		return ((char *)s1);
	while ((*p != '\0') && (count < len))
	{
		if (*p == *s2)
		{
			p2 = (char *)p;
			if (ft_samestr(p, s2, count, len) == 1)
				return (p2);
		}
		p++;
		count++;
	}
	return (0);
}
