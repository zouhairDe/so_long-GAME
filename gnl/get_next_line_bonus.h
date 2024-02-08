/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:30:18 by zouddach          #+#    #+#             */
/*   Updated: 2024/02/03 22:49:39 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*ft_trim(char *buffer);
char	*ft_strchr(char *str, char arg);
char	*ft_strjoin(char *buffer, char *return_val);
char	*ft_gnl_strdup(char *str);
char	*get_next_line(int fd);

#endif