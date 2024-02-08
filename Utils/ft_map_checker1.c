/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:25:20 by zouddach          #+#    #+#             */
/*   Updated: 2024/02/05 18:10:36 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SRC/so_long.h"

void	is_exit_reachable(t_data *data)
{
	int	ex;
	int	ey;
	int	i;
	int	j;

	i = 0;
	while (i < data->map.map_size.y / 32)
	{
		j = 0;
		while (j < data->map.map_size.x / 32)
		{
			if (data->map.map[i][j] == 'E')
			{
				if (data->map.map[ey][ex + 1] == '1' && data->map.
					map[ey][ex - 1] == '1' && data->map.
					map[ey + 1][ex] == '1' && data->map.
					map[ey - 1][ex] == '1')
					(ft_putstr_fd("Error\nExit is not reachable\n", 2),
						free_arrs(data, 2), exit(0));
			}
			j++;
		}
		i++;
	}
}

void	is_map_rectangular(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.map_size.y / 32)
	{
		if (ft_strlen_nl(data->map.map[i]) != data->map.map_size.x / 32)
			(ft_putstr_fd("Error\nMap is not rectangular\n", 2),
				free_arrs(data, 2), exit(1));
		i++;
	}
}

void	is_map_surrounded(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	if (!(fts_strchr(data->map.map[data->map.map_size.y / 32 - 1])
			&& fts_strchr(data->map.map[y])))
		(ft_putstr_fd("Error\nMap is not surrounded buy walls\n", 2),
			free_arrs(data, 2), exit(0));
	while (data->map.map[y])
	{
		x = 0;
		if (data->map.map[y][0] != '1' || data->map.map[y]
			[((data->map.map_size.x / 32) - 1)] != '1')
			(ft_putstr_fd("Error\nMap is not surrounded buy walls\n", 2),
				free_arrs(data, 2), exit(0));
		y++;
	}
}

void	is_it_valid(t_data *data, int px, int py)
{
	if (data->map.map_to_check_path[py][px] == '1' || data->map.
		map_to_check_path[py][px] == 'V' || data->map.
		map_to_check_path[py][px] == 'E')
		return ;
	if (data->map.map_to_check_path[py][px] == 'C')
		data->checker_coins++;
	data->map.map_to_check_path[py][px] = 'V';
	is_it_valid(data, px + 1, py);
	is_it_valid(data, px - 1, py);
	is_it_valid(data, px, py + 1);
	is_it_valid(data, px, py - 1);
}

void	is_there_a_valid_path(t_data *data)
{
	is_it_valid(data, data->player.pos.x, data->player.pos.y);
	if (data->checker_coins != data->map.coin)
		(ft_putstr_fd("Error\nPlayer cannot get all coins\n", 2),
			free_arrs(data, 2), exit(0));
	is_exit_reachable(data);
}
