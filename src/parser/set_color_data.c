/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:43:41 by tokazaki          #+#    #+#             */
/*   Updated: 2023/11/08 19:48:46 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_color(char *line);
char	*check_mono_color_data(char *line);
int		check_floor_or_ceiling(char *line);
int		create_trgb(int color);
void	set_color_to_world(char	*line, t_world *world);

void	set_color(int fd, t_world *world)
{
	int		i;
	char	*line;

	i = 0;
	while (i < 2)
	{
		line = read_file(fd);
		del_newline_cord(line);
		check_color(line);
		set_color_to_world(line, world);
		free(line);
		i++;
	}
}
//	ft_dprintf(1, "-----set_color-----\n");

void	check_color(char *line)
{
	int	i;

	line = skip_space(&line[2]);
	i = 0;
	while (i < 3)
	{
		if (ft_isdigit(*line) == 0)
			error_exit_msg("色の入力形式が間違っているよ！正しいデータを入れてね");
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
