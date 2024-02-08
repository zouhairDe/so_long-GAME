/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:12:55 by zouddach          #+#    #+#             */
/*   Updated: 2024/02/05 19:22:37 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SRC/so_long.h"

void	to_save_line(t_data *data)
{
	data->map.map = (char **)malloc(sizeof(char *)
			* ((data->map.map_size.y / 32) + 1));
	if (!data->map.map)
		(ft_putstr_fd("Error\nMemory allocation failed\n",
				2), exit(1));
	data->map.map_to_check_path = (char **)malloc(sizeof(char *)
			* ((data->map.map_size.y / 32) + 1));
	if (!data->map.map_to_check_path)
		(ft_putstr_fd("Error\nMemory allocation failed\n",
				2), free(data->map.map), exit(1));
	data->map.map[data->map.map_size.y / 32] = NULL;
	data->map.map_to_check_path[data->map.map_size.y / 32] = NULL;
}

void	free_arrs(t_data *data, int i)
{
	int	j;

	j = 0;
	if (i == 1)
	{
		while (j < data->map.map_size.y / 32)
			free(data->map.map[j++]);
		free(data->map.map);
	}
	else
	{
		while (j < data->map.map_size.y / 32)
		{
			free(data->map.map[j]);
			free(data->map.map_to_check_path[j]);
			j++;
		}
		free(data->map.map);
		free(data->map.map_to_check_path);
	}
}

void	allocate_map_space(t_data *data)
{
	int	i;

	i = 0;
	to_save_line(data);
	while (i < data->map.map_size.y / 32)
	{
		data->map.map[i] = malloc(sizeof(char) * (data->map.map_size.x / 32));
		if (!data->map.map[i])
			(ft_putstr_fd("Error\nMemory allocation failed\n", 2),
				free_arrs(data, 1), exit(1));
		data->map.map_to_check_path[i] = malloc(sizeof(char)
				* (data->map.map_size.x / 32));
		if (!data->map.map_to_check_path[i])
			(ft_putstr_fd("Error\nMemory allocation failed\n", 2),
				free_arrs(data, 2), exit(1));
		i++;
	}
}

void	copy_data(char *av, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		(ft_putstr_fd("Error\ncouldn't open file\n", 2),
			free_arrs(data, 2), exit(1));
	line = get_next_line(fd);
	while (i < data->map.map_size.y / 32)
	{
		ft_strcpy(data->map.map[i], line);
		ft_strcpy(data->map.map_to_check_path[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
}

void	copy_map(char *av, t_data *data)
{
	int	i;

	i = 0;
	allocate_map_space(data);
	copy_data(av, data);
}
