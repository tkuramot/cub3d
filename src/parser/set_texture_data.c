/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:08:06 by tokazaki          #+#    #+#             */
/*   Updated: 2023/11/08 14:32:15 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		check_direction(char *line);
void	set_texture_to_world(char *line, t_world *world);

void	set_texture(int fd, t_world *world)
{
	int		i;
	char	*line;

	i = 0;
	while (i < 4)
	{
		line = read_file(fd);
		if (line == NULL)
			error_exit_msg("方角のtextureが不足しています");
		del_newline_cord(line);
		set_texture_to_world(line, world);
		free(line);
		i++;
	}
}
//	ft_dprintf(1, "-----set_texture-----\n");

void	set_texture_to_world(char *line, t_world *world)
{
	int	direction;

	direction = check_direction(line);
	line = skip_space(&line[2]);
	if (direction == NORTH && world->texture.north_texture == NULL)
		world->texture.north_texture = ft_strdup(line);
	else if (direction == SOUTH && world->texture.south_texture == NULL)
		world->texture.south_texture = ft_strdup(line);
	else if (direction == WEST && world->texture.west_texture == NULL)
		world->texture.west_texture = ft_strdup(line);
	else if (direction == EAST && world->texture.east_texture == NULL)
		world->texture.east_texture = ft_strdup(line);
	else
		error_exit_msg("Please 正しい方角のテクスチャ入れてね");
}
//	ft_dprintf(1, "[%d : %s]\n", direction, line);

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
	if (ft_strncmp("NO ", line, 3) == 0)
		return (NORTH);
	else if (ft_strncmp("SO ", line, 3) == 0)
		return (SOUTH);
	else if (ft_strncmp("WE ", line, 3) == 0)
		return (WEST);
	else if (ft_strncmp("EA ", line, 3) == 0)
		return (EAST);
	else
		return (INIT);
}
