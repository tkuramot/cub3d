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

#include "parser.h"

void	set_color_data(fd, world)
{
	int		i;
	char	*line;
	char	*texture_path;

	i = 0;
	while (i < 2)
	{
		line = read_file(fd);
		if (check_floor_or_ceiling(line) != INIT)
		{
			check_color_data(line);
			set_color_to_world(line, world);
		}
		else
			error_exit_msg("Please 色の頭文字で、データを入れてね");
		free(line);
		i++;
	}
}

void	check_color_data(char *line)
{
	int	i;

	line = skip_space(&line[2]);
	i = 0;
	while (i < 3)
	{
		line = check_mono_color_data(line);
		i++;
		if (*line != ',' && i < 3)
			error_exit_msg("色の入力形式が間違っているよ！正しいデータを入れてね");
		line++;
	}
	if (i < 3)
		error_exit_msg("Please 色の頭文字で、データを入れてね");
	line = skip_space(line);
	if (*line != '\0')
		error_exit_msg("余計なデータが入ってるよ！");
}

char	*check_mono_color_data(char *line)
{
	int	j;

	j = 0;
	while (ft_isdigit(*line))
	{
		line++;
		j++;
	}
	if (3 < j)
		error_exit_msg("0 ~ 255 の間の正しい色のデータを入れてね");
	return (line);
}

void	set_color_to_world(char	*line, t_world *world)
{
}

int	check_floor_or_ceiling(char *line)
{
	int	direction;

	direction = INIT;
	if (strncmp("F ", line, 3))
		direction = 'F';
	if (strncmp("C ", line, 3))
		direction = 'C';
	return (direction);
}
