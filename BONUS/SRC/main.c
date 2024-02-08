/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:40:23 by zouddach          #+#    #+#             */
/*   Updated: 2024/02/08 18:27:35 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_mlx_imgs(t_data *data)
{
	if (data->imgs.enemy_axe || data->imgs.angry_enemy || data->imgs.enemy
		|| data->imgs.coin || data->imgs.player || data->imgs.opened_door
		|| data->imgs.closed_door || data->imgs.land || data->imgs.border)
	{
		mlx_destroy_image(data->mlx, data->imgs.border);
		mlx_destroy_image(data->mlx, data->imgs.land);
		mlx_destroy_image(data->mlx, data->imgs.closed_door);
		mlx_destroy_image(data->mlx, data->imgs.opened_door);
		mlx_destroy_image(data->mlx, data->imgs.player);
		mlx_destroy_image(data->mlx, data->imgs.coin);
		mlx_destroy_image(data->mlx, data->imgs.enemy);
		mlx_destroy_image(data->mlx, data->imgs.enemy_axe);
		mlx_destroy_image(data->mlx, data->imgs.angry_enemy);
	}
}

int	quite(t_data *data)
{
	free_arrs(data, 2);
	free_mlx_imgs(data);
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_printf("%sGame started%s\n", BOLD, GREEN);
	checkers(ac, av[1], &data);
	mlx_hook(data.mlx_win, 2, 0L, key_hook, &data);
	mlx_hook(data.mlx_win, 17, 0, quite, &data);
	mlx_loop(data.mlx);
}
