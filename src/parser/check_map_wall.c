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
static void	search_left_right_wall(const char **map, int row, int col);
static void	search_up_down_wall(const char **map, int row, int col);
bool		is_start_char(char chr);

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
	search_up_down_wall(map, row, col);
	search_left_right_wall(map, row, col);
}

static void	search_left_right_wall(const char **map, int row, int col)
{
	int	i;

	i = col;
	while (map[row][i] != '\0')
	{
		if (map[row][i] == ' ')
			error_exit_msg("空白が入ってる");
		if (map[row][i] == '1')
			break ;
		i++;
	}
	if (i == -1)
		error_exit_msg("右の壁ないよ");
	i = col;
	while (0 <= i)
	{
		if (map[row][i] == ' ')
			error_exit_msg("空白が入ってる");
		if (map[row][i] == '1')
			break ;
		i--;
	}
	if (i == -1)
		error_exit_msg("左の壁ないよ");
}

static void	search_up_down_wall(const char **map, int row, int col)
{
	int	i;

	i = row;
	while (0 <= i)
	{
		if (map[i][col] == ' ')
			error_exit_msg("空白が入ってるよ");
		if (map[i][col] == '1')
			break ;
		i--;
	}
	if (i == -1)
		error_exit_msg("上の壁ないよ");
	i = row;
	while (map[i][col] != '\0')
	{
		if (map[i][col] == ' ')
			error_exit_msg("空白が入ってるよ");
		if (map[i][col] == '1')
			break ;
		i++;
	}
	if (map[i][col] == '\0')
		error_exit_msg("下の壁ないよ");
}
