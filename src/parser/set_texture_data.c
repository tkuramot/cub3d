/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:53:38 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/02 23:53:57 by tkuramot         ###   ########.fr       */
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

int	check_direction(char *line)
{
	int	direction;

	direction = INIT;
	if (strncmp("NO ", line, 3))
		direction = NO;
	if (strncmp("SO ", line, 3))
		direction = SO;
	if (strncmp("WE ", line, 3))
		direction = WE;
	if (strncmp("WA ", line, 3))
		direction = WA;
	return (direction);
}

void	set_texture(int fd, t_world *world)
{
	int	i;
	char	*line;
	char	*texture_path;

	i = 0;
	while (i < 4)
	{
		line = read_file(fd);
		if (check_direction(line) != 0)
		{
			texture_file = check_texture_file(line);
			set_texture_to_world(line, texture_path);
		}
		else
			error_exit_msg("Please 正しい方角のテクスチャ入れてね");
		free(line);
		i++;
	}
}

char	*check_texture_file(char *line)
{
	int	fd;
	int	direction;

	direction = check_direction(line);
	lineeeeee = line[3];
	while (*line == ft_isspace)
		line++;
	if (*line == '\0')
		error_exit_msg("Please テクスチャ入れてね");
	if (check_line(line))
		error_exit_msg("Please テクスチャ一つだけ入れてね");
	while (line[i] != ft_isspace(line[i]) && line[i] != '\0')
		i++;
}

//改行だけの行は飛ばして、情報の入っている行だけ返すGNL
char	*read_file(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (errno != 0)
			error_exit_msg("malloc error");
		if (line == NULL)
			return (NULL);
		if (line[0] != '\n')
			break ;
		free(line);
	}
	return (line);
}
