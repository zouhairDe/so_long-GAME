/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:40:23 by zouddach          #+#    #+#             */
/*   Updated: 2024/02/08 18:11:11 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	quite(t_data *data)
{
	free_arrs(data, 2);
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
