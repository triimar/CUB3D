/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:27:40 by crepou            #+#    #+#             */
/*   Updated: 2022/11/23 17:23:54 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calc_num(const char *end, int len)
{
	int			num;
	int			mult;

	mult = 1;
	num = 0;
	end--;
	while (len > 0)
	{
		if (*end == '-')
			num *= -1;
		if (ft_isdigit(*end))
		{
			num += mult * (*end - 48);
			mult *= 10;
		}
		len--;
		end--;
	}
	return (num);
}

static int	ft_allowed_chars(char c)
{
	if (c == '\n' || c == '\t' || c == '\f')
		return (1);
	if (c == '\v' || c == '\r' || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			len;
	int			count;

	len = 0;
	count = 0;
	if (ft_strncmp(str, "\0", 1) == 0)
		return (0);
	while (*str != '\0')
	{
		if (*str == '-' || *str == '+' || ft_isdigit(*str))
			break ;
		if (!(ft_allowed_chars(*str)))
			return (0);
		count++;
		str++;
	}
	str++;
	len++;
	while (ft_isdigit(*str) && *str != '\0')
	{
		len++;
		str++;
	}
	return (ft_calc_num(str, len));
}
