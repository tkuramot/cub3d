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

static void	search_wall(const char **map, int row, int col);
static bool	is_valid_in_wall(char c);

void	check_wall(const char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row][0] != '\0')
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == '0' || \
			is_start_char(map[row][col]) == true)
				search_wall(map, row, col);
			col++;
		}
		row++;
	}
}

static void	search_wall(const char **map, int row, int col)
{
	if (row == 0 || col == 0)
		error_exit_msg("invalid map");
	if (is_valid_in_wall(map[row][col + 1]) == false)
		error_exit_msg("invalid map");
	if (is_valid_in_wall(map[row][col - 1]) == false)
		error_exit_msg("invalid map");
	if (is_valid_in_wall(map[row + 1][col]) == false)
		error_exit_msg("invalid map");
	if (is_valid_in_wall(map[row - 1][col]) == false)
		error_exit_msg("invalid map");
}

static bool	is_valid_in_wall(char c)
{
	if (c == '0' || c == '1' || \
			is_start_char(c) == true)
		return (true);
	return (false);
}
