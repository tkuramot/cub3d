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

static void	check_start_position(char **map);
static bool	is_map_char(char chr);
static void	change_end_ptr_to_null(t_world *world);

void	check_map(t_world *world)
{
	check_wall((const char **)world->map);
	check_start_position(world->map);
	change_end_ptr_to_null(world);
}

static void	check_start_position(char **map)
{
	int		row;
	int		col;
	bool	start_point;

	row = 0;
	start_point = false;
	while (map[row][0] != '\0')
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (is_map_char(map[row][col]) == false)
				error_exit_msg("mapが間違ってるよ");
			if (is_start_char(map[row][col]) == true && start_point == false)
				start_point = true;
			else if (is_start_char(map[row][col]) == true \
					&& start_point == true)
				error_exit_msg("開始地点が複数ケ所あるよ");
			col++;
		}
		row++;
	}
	if (start_point == false)
		error_exit_msg("start地点が書かれてないよ！");
}

static bool	is_map_char(char chr)
{
	if (ft_strchr(" 10", chr) != NULL)
		return (true);
	else if (ft_strchr("NSEW", chr) != NULL)
		return (true);
	else
		return (false);
}

bool	is_start_char(char chr)
{
	if (chr == '\0')
		return (false);
	else if (ft_strchr("NSEW", chr) != NULL)
		return (true);
	else
		return (false);
}

static void	change_end_ptr_to_null(t_world *world)
{
	free(world->map[world->height]);
	world->map[world->height] = NULL;
}
