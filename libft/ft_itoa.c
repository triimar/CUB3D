/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:39:56 by crepou            #+#    #+#             */
/*   Updated: 2022/11/19 12:38:37 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int num)
{
	int	dig;
	int	count;

	count = 0;
	if (num < 0)
	{
		num = (num + 1) * -1;
		if (num + 1 > 0)
			num += 1;
	}
	while (num > 0)
	{
		dig = num % 10;
		num = num / 10;
		count++;
	}
	return (count);
}

static int	ft_pow(int n, int p)
{
	int	num;

	num = 1;
	while (p > 0)
	{
		num *= n;
		p--;
	}
	return (num);
}

static int	ft_digit(int *n, int count)
{
	int		d;
	int		digit;

	d = ft_pow(10, (count - 1));
	digit = (*n / d) * -1;
	if (digit < 0)
		digit *= -1;
	*n = *n % d;
	return (digit);
}

static char	*ft_imalloc(int count, int n)
{
	char	*s;

	if (count == 0)
	{
		s = (char *)malloc(2);
		if (s == NULL)
			return (NULL);
		s[0] = '0';
	}
	else
	{
		if (n < 0)
		{
			s = (char *)malloc(count + 2);
			if (s == NULL)
				return (NULL);
			s[0] = '-';
		}
		else
		{
			s = (char *)malloc(count + 1);
		}
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*s;
	int		i;

	count = ft_count_digits(n);
	s = ft_imalloc(count, n);
	if (s == NULL)
		return (NULL);
	if (n > 0)
		i = 0;
	else
		i = 1;
	while (count > 0)
	{
		s[i] = ft_digit(&n, count) + 48;
		i++;
		count --;
	}
	s[i] = '\0';
	return (s);
}
