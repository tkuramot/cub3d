/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:42:41 by tokazaki          #+#    #+#             */
/*   Updated: 2023/11/07 18:37:39 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//改行だけの行は飛ばして、情報の入っている行だけ返すGNL
char	*read_file(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[0] != '\n')
			break ;
		free(line);
	}
	if (errno != 0)
		error_exit_msg("mallocに失敗してるお");
	return (line);
}

//スペースを飛ばすだけの関数
char	*skip_space(char *line)
{
	while (*line == ' ')
		line++;
	return (line);
}

bool	del_newline_cord(char *line)
{
	char	*del_point;

	del_point = ft_strchr(line, '\n');
	if (del_point == NULL)
		return (false);
	*del_point = '\0';
	return (true);
}
