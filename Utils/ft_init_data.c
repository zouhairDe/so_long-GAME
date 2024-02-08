/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:56:29 by zouddach          #+#    #+#             */
/*   Updated: 2024/02/05 19:18:16 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SRC/so_long.h"

void	set_to_zero(t_data *data)
{
	data->game_end = 0;
	data->map.is_door_open = 0;
	data->map.map_size.x = 0;
	data->map.map_size.y = 0;
	data->map.player = 0;
	data->map.coin = 0;
	data->map.exit = 0;
	data->map.is_door_open = 0;
	data->player.moves = 0;
	data->player.coins = 0;
	data->player.pos.x = 0;
	data->player.pos.y = 0;
}

void	set_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.map_size.y / 32)
	{
		j = 0;
		while (j < data->map.map_size.x / 32)
		{
			if (data->map.player > 1)
				(ft_putstr_fd("Error\nOne player needed\n", 2),
					free_arrs(data, 2), exit(1));
			if (data->map.map[i][j] == 'P')
			{
				data->player.pos.x = j;
				data->player.pos.y = i;
				data->map.player++;
			}
			j++;
		}
		i++;
	}
	if (!data->map.player)
		(ft_putstr_fd("Error\nNo player found\n", 2),
			free_arrs(data, 2), exit(1));
}

void	get_window_size(char *av, t_data *data)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		(ft_putstr_fd("Error\nCan't open the file\n", 2), exit(1));
	line = get_next_line(fd);
	if (!line)
		(ft_putstr_fd("Error\nEmpty file\n", 2), exit(1));
	if (ft_strlen(line) < 5)
		(ft_putstr_fd("Error\nMap is too small\n", 2), exit(1));
	data->map.map_size.x = (ft_strlen(line) - 1) * 32;
	while (line)
	{
		data->map.map_size.y += 32;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if ((data->map.map_size.y / 32) < 3)
		(ft_putstr_fd("Error\nMap is too small\n", 2), exit(1));
}

void	init_mlx_images(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx,
			data->map.map_size.x, data->map.map_size.y, "so_long");
	data->imgs.land = mlx_xpm_file_to_image(data->mlx,
			"imgs/land.xpm", &data->d_w, &data->d_h);
	data->imgs.border = mlx_xpm_file_to_image(data->mlx,
			"imgs/border.xpm", &data->d_w, &data->d_h);
	data->imgs.coin = mlx_xpm_file_to_image(data->mlx,
			"imgs/coin.xpm", &data->d_w, &data->d_h);
	data->imgs.closed_door = mlx_xpm_file_to_image(data->mlx,
			"imgs/door_closed.xpm", &data->d_w, &data->d_h);
	data->imgs.opened_door = mlx_xpm_file_to_image(data->mlx,
			"imgs/door_open.xpm", &data->d_w, &data->d_h);
	data->imgs.player = mlx_xpm_file_to_image(data->mlx,
			"imgs/player.xpm", &data->d_w, &data->d_h);
	if (!data->imgs.land || !data->imgs.border
		|| !data->imgs.coin || !data->imgs.closed_door
		|| !data->imgs.opened_door || !data->imgs.player)
		(ft_putstr_fd("Error\nmlx_xpm_file_to_image failed\n", 2),
			mlx_destroy_image(data->mlx, data->mlx_win), exit(1));
}

void	init_data(char *av, t_data *data)
{
	set_to_zero(data);
	get_window_size(av, data);
	init_mlx_images(data);
	copy_map(av, data);
	is_map_rectangular(data);
	set_player(data);
	is_map_surrounded(data);
	ft_check_for_intruders(data);
	ft_counter(data);
	is_there_a_valid_path(data);
	simulate_game(data);
}
