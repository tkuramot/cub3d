/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:08:06 by tokazaki          #+#    #+#             */
/*   Updated: 2023/11/07 17:08:19 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	set_texture(int fd, t_world *world)
{
	int		i;
	char	*line;
	char	*texture_path;

	i = 0;
	while (i < 4)
	{
		line = read_file(fd);
		set_texture_to_world(line, world);
		free(line);
		i++;
	}
}

void	set_texture_to_world(char *line, t_world *world)
{
	char		*texture_path;
	int			direction;

	direction = check_direction(line);
	line = skip_space(&line[2]);
	if (direction == NORTH && world->north_texture == NULL)
		world->north_texture = ft_strdup(line);
	else if (direction == SOUTH && world->south_texture == NULL)
		world->south_texture = ft_strdup(line);
	else if (direction == WEST && world->ewst_texture == NULL)
		world->west_texture = ft_strdup(line);
	else if (direction == EAST && world->east_texture == NULL)
		world->east_texture = ft_strdup(line);
	else
		error_exit_msg("Please 正しい方角のテクスチャ入れてね");
}

//char	*check_texture_file(char *line)
//{
//	int	fd;
//	int	direction;
//
//	direction = check_direction(line);
//	line = line[3];
//	while (*line == ft_isspace)
//		line++;
//	if (*line == '\0')
//		error_exit_msg("Please テクスチャ入れてね");
//	if (check_line(line))
//		error_exit_msg("Please テクスチャ一つだけ入れてね");
//	while (line[i] != ft_isspace(line[i]) && line[i] != '\0')
//		i++;
//}
//
int	check_direction(char *line)
{
	int	direction;

	direction = INIT;
	if (strncmp("NO ", line, 3))
		direction = NORTH;
	if (strncmp("SO ", line, 3))
		direction = SOUTH;
	if (strncmp("WE ", line, 3))
		direction = WEST;
	if (strncmp("EA ", line, 3))
		direction = EAST;
	return (direction);
}
