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

void	print_world(t_world *world);

void	get_config(char *argv[], t_world *world)
{
	int	open_fd;

	open_fd = open(argv[1], O_RDONLY);
	if (open_fd < 0)
		error_exit_msg("Please enter the correct file");
	set_texture(open_fd, world);
	set_color(open_fd, world);
	set_map(open_fd, world);
	print_world(world);
}

void	print_world(t_world *world)
{
	int	i;

	ft_dprintf(1, "----- texture -----\n");
	ft_dprintf(1, "%s\n", world->texture.north_texture);
	ft_dprintf(1, "%s\n", world->texture.south_texture);
	ft_dprintf(1, "%s\n", world->texture.west_texture);
	ft_dprintf(1, "%s\n", world->texture.east_texture);
	ft_dprintf(1, "\n----- color -----\n");
	ft_dprintf(1, "[Floor: %x]\n", world->floor_color);
	ft_dprintf(1, "[Ceiling: %x]\n", world->ceiling_color);
	ft_dprintf(1, "\n----- map -----\n");
	i = 0;
	while (world->map[i][0] != '\0')
	{
		ft_dprintf(1, "|%s|\n", world->map[i]);
		i++;
	}
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
