/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_sumilation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:09:58 by zouddach          #+#    #+#             */
/*   Updated: 2024/02/05 18:16:48 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SRC/so_long.h"

void	put_images(t_data *data, int x, int y)
{
	if (data->map.map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs.border, x * 32, y * 32);
	else if (data->map.map[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs.land, x * 32, y * 32);
	else if (data->map.map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs.player, x * 32, y * 32);
	else if (data->map.map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs.coin, x * 32, y * 32);
	else if (data->map.map[y][x] == 'E' && data->map.is_door_open)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs.opened_door, x * 32, y * 32);
	else if (data->map.map[y][x] == 'E' && !data->map.is_door_open)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs.closed_door, x * 32, y * 32);
}

void	simulate_game(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (data->player.coins == data->map.coin)
		data->map.is_door_open = 1;
	mlx_clear_window(data->mlx, data->mlx_win);
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x] != '\0' && data->map.map[y][x] != '\n')
		{
			put_images(data, x, y);
			x++;
		}
		y++;
	}
}
