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

static void	check_color(char *line);
static char	*check_mono_color_data(char *line);

void	set_color(int fd, t_world *world)
{
	int		i;
	char	*line;

	i = 0;
	while (i < 2)
	{
		line = read_file(fd);
		if (line == NULL)
			error_exit_msg("No color data in file");
		del_newline_code(line);
		check_color(line);
		set_color_to_world(line, world);
		free(line);
		i++;
	}
}
//	ft_dprintf(1, "-----set_color-----\n");

static void	check_color(char *line)
{
	int	i;

	line = skip_space(&line[2]);
	i = 0;
	while (i < 3)
	{
		if (ft_isdigit(*line) == 0)
			error_exit_msg("Invalid format in color input");
		line = check_mono_color_data(line);
		i++;
		if (*line != ',' && i < 3)
			error_exit_msg("Missing data in color input");
		line++;
	}
	if (i < 3)
		error_exit_msg("Missing data in color input");
	line = skip_space(line);
	if (*line != '\0')
		error_exit_msg("Extraneous data in color input");
}

static char	*check_mono_color_data(char *line)
{
	int	i;
	int	mono_color;

	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	mono_color = ft_atoi(line);
	if (3 < i || 255 < mono_color)
		error_exit_msg("Value greater than 255 in color input");
	return (line + i);
}
