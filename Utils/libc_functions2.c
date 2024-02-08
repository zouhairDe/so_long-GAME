/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libc_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 08:45:40 by zouddach          #+#    #+#             */
/*   Updated: 2024/02/05 19:27:11 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SRC/so_long.h"

size_t	ft_strcpy(char *dest, char *src)
{
	size_t	len;

	len = ft_strlen(src);
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (len);
}

int	fts_strchr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_strlen_nl(char *str)
{
	size_t	length;

	length = 0;
	while (str[length] && str[length] != '\n')
		length++;
	return (length);
}
