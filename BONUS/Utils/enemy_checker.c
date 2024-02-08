/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:24:41 by zouddach          #+#    #+#             */
/*   Updated: 2024/02/06 14:09:01 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SRC/so_long_bonus.h"

void	is_enemy_surounded(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.map_size.y / 32)
	{
		j = 0;
		while (j < data->map.map_size.x / 32)
		{
			if (data->map.map[i][j] == 'M')
			{
				if (data->map.map[i][j + 1] == '1' && data->map.
					map[i][j - 1] == '1' && data->map.
					map[i + 1][j] == '1' && data->map.
					map[i - 1][j] == '1')
					(ft_putstr_fd("Error\nEnemy can't be locked in!!\n", 2),
						free_arrs(data, 2), exit(0));
			}
			j++;
		}
		i++;
	}
}
