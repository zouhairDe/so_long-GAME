/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:33:18 by zouddach          #+#    #+#             */
/*   Updated: 2024/02/05 17:37:13 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SRC/so_long.h"

void	checkers(int ac, char *av, t_data *data)
{
	if (ac != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		exit(1);
	}
	if (ft_strncmp(av + ft_strlen(av) - 4, ".ber", 4))
	{
		ft_putstr_fd("Error\nInvalid file extension\n", 2);
		exit(1);
	}
	init_data(av, data);
}
