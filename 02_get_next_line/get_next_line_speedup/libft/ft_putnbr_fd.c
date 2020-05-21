/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 13:18:00 by jtsai             #+#    #+#             */
/*   Updated: 2018/07/17 16:57:09 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num[20];
	int		i;
	int		sign;

	if (n == 0)
		write(fd, "0", 1);
	else if (n < 0)
		write(fd, "-", 1);
	sign = (n > 0) ? 1 : -1;
	i = 0;
	while (n)
	{
		num[i++] = '0' + (n % 10) * sign;
		n /= 10;
	}
	while (--i >= 0)
		write(fd, &(num[i]), 1);
}