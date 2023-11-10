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

void	check_wall(char **map);
void	check_start_position(char **map);
bool	is_start_char(char chr);
bool	is_map_char(char chr);

void	check_map(t_world *world)
{
	char	**map;

	map = world->map;
	check_wall(map);
	check_start_position(map);
}

void	check_start_position(char **map)
{
	int	row;
	int	col;
	int	start_point;

	row = 0;
	start_point = 0;
	while (map[row][0] != '\0')
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (is_map_char(map[row][col]) == false)
				error_exit_msg("mapが間違ってるよ");
			if (is_start_char(map[row][col]) == true && start_point == 0)
				start_point = 1;
			else if (is_start_char(map[row][col]) == true && start_point == 0)
				error_exit_msg("開始地点が複数ケ所あるよ");
			col++;
		}
		row++;
	}
	if (start_point == 0)
		error_exit_msg("start地点が書かれてないよ！");
}

bool	is_map_char(char chr)
{
	if (chr == ' ' || \
		chr == '1' || \
		chr == '0' )
		return (true);
	else if (is_start_char(chr) == true)
		return (true);
	else
		return (false);
}

bool	is_start_char(char chr)
{
	if (chr == 'N' || \
		chr == 'S' || \
		chr == 'E' || \
		chr == 'W' )
		return (true);
	else
		return (false);
}
