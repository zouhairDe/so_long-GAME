/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:46:47 by zouddach          #+#    #+#             */
/*   Updated: 2024/02/07 19:20:50 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "./../gnl/get_next_line_bonus.h"
# include "./../ft_printf/ft_printf.h"
# include "/usr/local/include/mlx.h"
# include <fcntl.h>
# include <stdlib.h>

# define ESCAPE_BUTTON 53
# define W_BUTTON 13
# define A_BUTTON 0
# define S_BUTTON 1
# define D_BUTTON 2
# define UP_BUTTON 126
# define DOWN_BUTTON 125
# define LEFT_BUTTON 123
# define RIGHT_BUTTON 124
# define QUIT_BUTTON 12

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"
# define BOLD "\033[1m"

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_player
{
	t_vector	pos;
	int			coins;
	int			moves;
}	t_player;

typedef struct s_map
{
	char		**map;
	char		**map_to_check_path;
	int			coin;
	int			exit;
	int			player;
	int			enemy;
	int			is_door_open;
	t_vector	map_size;
}	t_map;

typedef struct s_img
{
	void	*land;
	void	*border;
	void	*coin;
	void	*closed_door;
	void	*opened_door;
	void	*player;
	void	*enemy;
	void	*angry_enemy;
	void	*ending_land;
	void	*enemy_axe;
}	t_img;

typedef struct s_data
{
	t_img		imgs;
	t_map		map;
	t_player	player;
	int			checker_coins;
	void		*mlx;
	void		*mlx_win;
	int			animation_index;
	int			d_w;
	int			d_h;
}	t_data;

int		ft_strncmp(char *str1, char *str2, size_t n);
int		key_hook(int keycode, t_data *data);
int		fts_strchr(char *str);
int		quite(t_data *data);
void	checkers(int ac, char *av, t_data *data);
void	ft_putstr_fd(char *s, int fd);
void	init_data(char *av, t_data *data);
void	get_window_size(char *av, t_data *data);
void	copy_map(char *av, t_data *data);
void	free_arrs(t_data *data, int i);
void	is_map_rectangular(t_data *data);
void	is_map_surrounded(t_data *data);
void	ft_counter(t_data *data);
void	ft_check_for_intruders(t_data *data);
void	is_there_a_valid_path(t_data *data);
void	is_enemy_surounded(t_data *data);
void	simulate_game(t_data *data);
void	check_mlx_result(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
size_t	ft_strcpy(char *dest, char *src);
size_t	ft_strlen(char *str);
size_t	ft_strlen_nl(char *str);
char	*ft_strdup(char *str);
char	*ft_itoa(int n);

#endif