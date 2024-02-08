/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:32:40 by zouddach          #+#    #+#             */
/*   Updated: 2024/02/06 17:39:07 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SRC/so_long.h"

int	wrong_button(int keycode)
{
	if (keycode != W_BUTTON && keycode != S_BUTTON && keycode != A_BUTTON
		&& keycode != D_BUTTON && keycode != ESCAPE_BUTTON)
		return (1);
	return (0);
}

int	if_player_can_move(t_data *data, int keycode)
{
	if (keycode == W_BUTTON && data->map.map[data->player.pos.y - 1]
		[data->player.pos.x] != '1' && data->map.map[data->player.pos.y - 1]
		[data->player.pos.x] != 'E')
		return (1);
	else if (keycode == S_BUTTON && data->map.map[data->player.pos.y + 1]
		[data->player.pos.x] != '1' && data->map.map[data->player.pos.y + 1]
		[data->player.pos.x] != 'E')
		return (1);
	else if (keycode == A_BUTTON && data->map.map[data->player.pos.y]
		[data->player.pos.x - 1] != '1' && data->map.map[data->player.pos.y]
		[data->player.pos.x - 1] != 'E')
		return (1);
	else if (keycode == D_BUTTON && data->map.map[data->player.pos.y]
		[data->player.pos.x + 1] != '1' && data->map.map[data->player.pos.y]
		[data->player.pos.x + 1] != 'E')
		return (1);
	return (0);
}

int	protect_from_walls(t_data *data, int keycode)
{
	if (keycode == W_BUTTON && data->map.map[data->player.pos.y - 1]
		[data->player.pos.x] != '1')
		return (1);
	else if (keycode == S_BUTTON && data->map.map[data->player.pos.y + 1]
		[data->player.pos.x] != '1')
		return (1);
	else if (keycode == A_BUTTON && data->map.map[data->player.pos.y]
		[data->player.pos.x - 1] != '1')
		return (1);
	else if (keycode == D_BUTTON && data->map.map[data->player.pos.y]
		[data->player.pos.x + 1] != '1')
		return (1);
	return (0);
}

void	handle_move(t_data *data, int key)
{
	if (key == W_BUTTON)
		move_up(data);
	else if (key == S_BUTTON)
		move_down(data);
	else if (key == A_BUTTON)
		move_left(data);
	else if (key == D_BUTTON)
		move_right(data);
	simulate_game(data);
	ft_printf("%sPlayer has moved %d times%s\n",
		GREEN, data->player.moves, RESET);
}

int	key_hook(int keycode, t_data *data)
{
	if (wrong_button(keycode))
		ft_printf("%sError\nWrong BUTTON!!!%s\n", RED, RESET);
	else if (keycode == ESCAPE_BUTTON)
		quite(data);
	else if (!data->map.is_door_open && if_player_can_move(data, keycode))
		handle_move(data, keycode);
	else if (data->map.is_door_open && protect_from_walls(data, keycode))
		handle_move(data, keycode);
	else
		ft_printf("%sYou can't move there!%s\n", RED, RESET);
	return (0);
}
