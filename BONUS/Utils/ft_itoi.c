/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:10:14 by zouddach          #+#    #+#             */
/*   Updated: 2024/02/06 15:54:45 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SRC/so_long_bonus.h"

static int	numlen(int nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static void	assignstr(int num_len, int sign, int n, char *number)
{
	while (num_len--)
	{
		number[num_len + sign] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*number;
	int		num_len;
	int		sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	if (n <= -2147483648)
		return (ft_strdup("-2147483648"));
	if (n >= 2147483647)
		return (ft_strdup("2147483647"));
	if (n == 0)
		return (ft_strdup("0"));
	num_len = numlen(n);
	number = (char *)malloc(num_len + sign + 1);
	if (!number)
		return (NULL);
	if (sign)
	{
		*number = '-';
		n = -n;
	}
	number[num_len + sign] = '\0';
	assignstr(num_len, sign, n, number);
	return (number);
}
