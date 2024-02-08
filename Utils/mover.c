/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:57:01 by zouddach          #+#    #+#             */
/*   Updated: 2024/02/06 17:38:06 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SRC/so_long.h"

void	move_up(t_data *data)
{
	if (data->map.map[data->player.pos.y - 1][data->player.pos.x] == 'C')
		data->player.coins++;
	else if (data->map.map[data->player.pos.y - 1]
		[data->player.pos.x] == 'E' && data->map.is_door_open)
	{
		data->map.map[data->player.pos.y - 1][data->player.pos.x] = 'P';
		data->map.map[data->player.pos.y][data->player.pos.x] = '0';
		ft_printf("%sRb7ti!! dir m3ak like l repo%s\n", BLUE, RESET);
		ft_printf("%sTotal moves is : %d\n", YELLOW, data->player.moves);
		simulate_game(data);
		quite(data);
	}
	data->map.map[data->player.pos.y][data->player.pos.x] = '0';
	data->map.map[data->player.pos.y - 1][data->player.pos.x] = 'P';
	data->player.pos.y -= 1;
	data->player.moves++;
}

void	move_down(t_data *data)
{
	if (data->map.map[data->player.pos.y + 1][data->player.pos.x] == 'C')
		data->player.coins++;
	else if (data->map.map[data->player.pos.y + 1]
		[data->player.pos.x] == 'E' && data->map.is_door_open)
	{
		data->map.map[data->player.pos.y + 1][data->player.pos.x] = 'P';
		data->map.map[data->player.pos.y][data->player.pos.x] = '0';
		ft_printf("%sRb7ti!! dir m3ak like l repo%s\n", BLUE, RESET);
		ft_printf("%sTotal moves is : %d\n", YELLOW, data->player.moves);
		simulate_game(data);
		quite(data);
	}
	data->map.map[data->player.pos.y][data->player.pos.x] = '0';
	data->map.map[data->player.pos.y + 1][data->player.pos.x] = 'P';
	data->player.pos.y += 1;
	data->player.moves++;
}

void	move_left(t_data *data)
{
	if (data->map.map[data->player.pos.y][data->player.pos.x - 1] == 'C')
		data->player.coins++;
	else if (data->map.map[data->player.pos.y]
		[data->player.pos.x - 1] == 'E' && data->map.is_door_open)
	{
		data->map.map[data->player.pos.y][data->player.pos.x - 1] = 'P';
		data->map.map[data->player.pos.y][data->player.pos.x] = '0';
		ft_printf("%sRb7ti!! dir m3ak like l repo%s\n", BLUE, RESET);
		ft_printf("%sTotal moves is : %d\n", YELLOW, data->player.moves);
		simulate_game(data);
		quite(data);
	}
	data->map.map[data->player.pos.y][data->player.pos.x] = '0';
	data->map.map[data->player.pos.y][data->player.pos.x - 1] = 'P';
	data->player.pos.x -= 1;
	data->player.moves++;
}

void	move_right(t_data *data)
{
	if (data->map.map[data->player.pos.y][data->player.pos.x + 1] == 'C')
		data->player.coins++;
	else if (data->map.map[data->player.pos.y]
		[data->player.pos.x + 1] == 'E' && data->map.is_door_open)
	{
		data->map.map[data->player.pos.y][data->player.pos.x + 1] = 'P';
		data->map.map[data->player.pos.y][data->player.pos.x] = '0';
		ft_printf("%sRb7ti!! dir m3ak like l repo%s\n", BLUE, RESET);
		ft_printf("%sTotal moves is : %d\n", YELLOW, data->player.moves);
		simulate_game(data);
		quite(data);
	}
	data->map.map[data->player.pos.y][data->player.pos.x] = '0';
	data->map.map[data->player.pos.y][data->player.pos.x + 1] = 'P';
	data->player.pos.x += 1;
	data->player.moves++;
}
