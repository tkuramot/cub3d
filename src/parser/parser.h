/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:43:41 by tokazaki          #+#    #+#             */
/*   Updated: 2023/11/07 14:55:10 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <libc.h>
# include <sys/errno.h>
# include <stdbool.h>
# include "../../include/type.h"
# include "../../lib/libft/include/libft.h"
# include "../../lib/libft/include/ft_stdio.h"

typedef enum e_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	INIT
}		t_direction;

void	set_color(int fd, t_world *world);
void	set_map(int fd, t_world *world);
void	set_texture(int fd, t_world *world);

char	*skip_space(char *line);
char	*read_file(int fd);
void	error_exit_msg(char *line);
bool	del_newline_cord(char *line);

#endif
