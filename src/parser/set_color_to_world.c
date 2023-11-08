/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_to_world.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:46:31 by tokazaki          #+#    #+#             */
/*   Updated: 2023/11/08 19:48:45 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_color(char *line);
char	*check_mono_color_data(char *line);
int		check_floor_or_ceiling(char *line);
int		create_trgb(int color);
void	set_color_to_world(char	*line, t_world *world);

void	set_color_to_world(char	*line, t_world *world)
{
	int	color;
	int	mono_color;
	int	ceiling_or_floor;

	color = 0;
	ceiling_or_floor = check_floor_or_ceiling(line);
	line = skip_space(&line[2]);
	while (line != NULL)
	{
		mono_color = ft_atoi(line);
		if (255 < mono_color)
			error_exit_msg("255以上の値が入力されています");
		color = create_trgb(mono_color);
		line = ft_strchr(line, ',');
		if (line == NULL)
			break ;
		line++;
	}
	if (ceiling_or_floor == 'C' && world->ceiling_color == 0)
		world->ceiling_color = color;
	else if (ceiling_or_floor == 'F' && world->floor_color == 0)
		world->floor_color = color;
	else
		error_exit_msg("同じ天井・地面の色が複数回指定されているよ");
}
//	ft_dprintf(1, "[%s]\n", line);

int	create_trgb(int mono_color)
{
	static int	color;
	static int	red;
	static int	green;
	static int	blue;
	static int	i;

	i++;
	if (i == 1)
	{
		color = 0;
		red = mono_color;
	}
	if (i == 2)
		green = mono_color;
	if (i == 3)
	{
		blue = mono_color;
		color = (0 << 24 | red << 16 | green << 8 | blue);
		red = 0;
		green = 0;
		blue = 0;
		i = 0;
	}
	return (color);
}

int	check_floor_or_ceiling(char *line)
{
	int	direction;

	direction = INIT;
	if (strncmp("F ", line, 2) == 0)
		direction = 'F';
	if (strncmp("C ", line, 2) == 0)
		direction = 'C';
	return (direction);
}
