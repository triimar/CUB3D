/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:08:29 by crepou            #+#    #+#             */
/*   Updated: 2022/11/22 16:00:59 by crepou           ###   ########.fr       */
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

void	ft_putnbr_fd(int n, int fd)
{
	int		count;
	int		d;
	int		digit;
	char	s[1];

	if (n < 0)
		write(fd, "-", 1);
	count = ft_count_digits(n);
	if (count == 0)
		write(fd, "0", 1);
	while (count > 0)
	{
		d = ft_pow(10, (count - 1));
		digit = (n / d) * -1;
		if (digit < 0)
			digit *= -1;
		s[0] = 48 + digit;
		write(fd, s, 1);
		n = n % d;
		count --;
	}
}
