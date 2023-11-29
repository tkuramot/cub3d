/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:08:38 by tokazaki          #+#    #+#             */
/*   Updated: 2023/11/29 20:19:11 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "ft_string.h"
#include "parser.h"
#include "utils.h"

static void	read_map(int fd, t_world *world, t_list **lst);
void		print_list(void *line);

void	set_map(int fd, t_world *world)
{
	t_list	*lst;

	read_map(fd, world, &lst);
	arrange_map_lst_to_ptr(world, lst);
	ft_lstclear(&lst, free);
}

static void	read_map(int fd, t_world *world, t_list **lst)
{
	char	*line;
	int		line_count;

	line = read_file(fd);
	if (line == NULL)
		error_exit_msg("No map in file");
	del_newline_code(line);
	*lst = ft_lstnew(line);
	line_count = 0;
	while (1)
	{
		if (ft_strlen(line) > MAX_MAP_SIZE)
			error_exit_msg("Too many columns");
		line = get_next_line(fd);
		if (errno != 0)
			error_exit_msg("malloc error");
		if (line == NULL)
			break ;
		del_newline_code(line);
		ft_lstadd_back(lst, ft_lstnew(line));
		if (++line_count > MAX_MAP_SIZE)
			error_exit_msg("Too many rows");
	}
	(void)world;
}

//debug用
//	ft_dprintf(1, "-----set_map-----\n");
//	ft_lstiter(lst, print_list);
void	print_list(void *line)
{
	ft_dprintf(1, "[%s]\n", (char *)line);
}
