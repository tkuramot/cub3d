/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:53:38 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/07 17:08:23 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	get_config(char *argv[], t_world *world)
{
	int	open_fd;

	open_fd = open(argv[1]);
	if (fd < 0)
		error_exit_msg("Please enter the correct file");
	set_texture_data(fd, world);
	set_color_data(fd, world);
	set_map_data(fd, world);
}
