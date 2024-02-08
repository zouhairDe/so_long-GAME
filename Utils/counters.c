/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:00:47 by zouddach          #+#    #+#             */
/*   Updated: 2024/02/05 17:36:26 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SRC/so_long.h"

void	ft_check_for_intruders(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.map_size.y / 32)
	{
		j = 0;
		while (j < data->map.map_size.x / 32)
		{
			if (data->map.map[i][j] != '1' && data->map.map[i][j] != '0'
				&& data->map.map[i][j] != 'P' && data->map.map[i][j] != 'C'
				&& data->map.map[i][j] != 'E')
			{
				ft_putstr_fd("Error\nMap contains invalid characters\n", 2);
				free_arrs(data, 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	ft_counter(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.map_size.y / 32)
	{
		j = 0;
		while (j < data->map.map_size.x / 32)
		{
			if (data->map.map[i][j] == 'C')
				data->map.coin++;
			if (data->map.map[i][j] == 'E')
				data->map.exit++;
			j++;
		}
		i++;
	}
	if (data->map.coin == 0 || data->map.exit != 1)
		(ft_putstr_fd("Error\nNeed one Exit and some coins\n", 2),
			free_arrs(data, 2), exit(1));
}
