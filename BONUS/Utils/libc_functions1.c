/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libc_functions1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:39:39 by zouddach          #+#    #+#             */
/*   Updated: 2024/02/06 14:09:30 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SRC/so_long_bonus.h"

int	ft_strncmp(char *str1, char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i] || !str1[i] || !str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
	return ;
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	if (s && fd >= 0)
	{
		while (s[++i])
			ft_putchar_fd(s[i], fd);
	}
	return ;
}

char	*ft_strdup(char *str)
{
	char	*dest;
	int		len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	dest = (char *)malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	while (*str || *str != '\n')
	{
		*dest = *str;
		dest++;
		str++;
	}
	*dest = '\0';
	return (dest - len);
}
