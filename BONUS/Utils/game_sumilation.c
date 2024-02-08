/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_sumilation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:09:58 by zouddach          #+#    #+#             */
/*   Updated: 2024/02/07 19:00:07 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SRC/so_long_bonus.h"

void	check_mlx_result(t_data *data)
{
	if (data->mlx == NULL)
		(ft_putstr_fd("Error\nFailed to connect to the display\n", 2),
			free_arrs(data, 2), exit(1));
	if (data->mlx_win == NULL)
		(ft_putstr_fd("Error\nFailed to create a window\n", 2),
			free_arrs(data, 2), exit(1));
	if (!data->imgs.angry_enemy || !data->imgs.border || !data->imgs.coin
		|| !data->imgs.closed_door || !data->imgs.enemy || !data->imgs.enemy_axe
		|| !data->imgs.land || !data->imgs.opened_door || !data->imgs.player)
		(ft_putstr_fd("Error\nFailed to load images\n", 2),
			free_arrs(data, 2), exit(1));
}

void	animate_enemy2(t_data *data, int x, int y)
{
	if (data->animation_index == 0)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs.enemy, x * 32, y * 32);
	else if (data->animation_index == 1)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs.angry_enemy, x * 32, y * 32);
	data->animation_index++;
	if (data->animation_index == 2)
		data->animation_index = 0;
}

void	animate_enemy(t_data *data, int x, int y)
{
	if (data->animation_index == 0)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs.enemy, x * 32, y * 32);
	else if (data->animation_index == 1)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs.angry_enemy, x * 32, y * 32);
	else if (data->animation_index == 2)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs.enemy_axe, x * 32, y * 32);
	data->animation_index++;
	if (data->animation_index == 3)
		data->animation_index = 0;
}

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
	else if (data->map.map[y][x] == 'M')
	{
		if (data->map.enemy % 3 == 0)
			animate_enemy2(data, x, y);
		else
			animate_enemy(data, x, y);
	}
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
