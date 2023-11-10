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

# include "libft.h"

# include "type.h"
# include "constant.h"

# include "utils.h"

//get_config
void	get_config(char *argv[], t_world *world);

//set_data
void	set_texture(int fd, t_world *world);
void	set_color(int fd, t_world *world);
void	set_map(int fd, t_world *world);

//about_color
void	set_color_to_world(char	*line, t_world *world);

//about_map
void	check_map(t_world *world);
void	check_wall(const char **map);
void	arrange_map_lst_to_ptr(t_world *world, t_list *lst);
bool	is_start_char(char chr);
//void	read_map(int fd, t_world *world, t_list **lst);

//utils
char	*skip_space(char *line);
char	*read_file(int fd);
void	del_newline_code(char *line);

#endif
