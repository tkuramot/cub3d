/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:08:38 by tokazaki          #+#    #+#             */
/*   Updated: 2023/11/07 18:37:36 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	read_map(int fd, t_world *world, t_list **lst);
void	arrange_map(t_world *world, t_list *lst);
void	*ft_lst_push_back(t_list **lst, char *line);

void	set_map(int fd, t_world *world)
{
	t_list	*lst;

	ft_dprintf(1, "-----set_map-----\n");
	read_map(fd, world, &lst);
	arrange_map(world, lst);
}

//読み込みをして、線形リストにする
void	read_map(int fd, t_world *world, t_list **lst)
{
	char	*line;

	lst = NULL;
	line = read_file(fd);
	if (line == NULL)
		error_exit_msg("mapがないよ");
	while (line != NULL)
	{
		del_newline_cord(line);
		ft_dprintf(1, "[%s]\n", line);
		*lst = ft_lst_push_back(lst, line);
		line = get_next_line(fd);
		if (errno != 0)
			error_exit_msg("mallocに失敗してたお");
	}
}

void	*ft_lst_push_back(t_list **lst, char *line)
{
	if (*lst == NULL)
		*lst = ft_lstnew(line);
	else
		ft_lstadd_back(lst, ft_lstnew(line));
	return (*lst);
}

//mapの整形をする
void	arrange_map(t_world *world, t_list *lst)
{
	int	max_len;

	max_len = 0;
	while (lst != NULL)
	{
		if (max_len < ft_strlen(lst->content))
			max_len = ft_strlen(lst->content);
		lst = lst->next;
	}
	world->map = (char **) malloc (sizeof(char *) * (max_len + 1));
}
