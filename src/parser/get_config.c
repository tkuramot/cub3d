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

	open_fd = open(argv[1], O_RDONLY);
	if (open_fd < 0)
		error_exit_msg("Please enter the correct file");
	set_texture(open_fd, world);
	set_color(open_fd, world);
	set_map(open_fd, world);
}

int	main(int argc, char *argv[])
{
	static t_world	world;

	if (argc != 2)
		error_exit_msg("引数の数が間違ってるよ");
	get_config(argv, &world);
	printf("end\n");
	return (0);
}
