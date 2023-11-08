/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:08:38 by tokazaki          #+#    #+#             */
/*   Updated: 2023/11/08 20:05:32 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	read_map(int fd, t_world *world, t_list **lst);
void	arrange_map(t_world *world, t_list *lst);
void	*ft_lst_push_back(t_list **lst, char *line);
void	print_list(void *line);
int		count_max_len(t_list *lst);

void	set_map(int fd, t_world *world)
{
	t_list	*lst;

	ft_dprintf(1, "-----set_map-----\n");
	read_map(fd, world, &lst);
	ft_lstiter(lst, print_list);
	arrange_map(world, lst);
}

void	print_list(void *line)
{
	ft_dprintf(1, "[%s]\n", (char *)line);
}

//読み込みをして、線形リストにする
//void	ft_lstiter(t_list *lst, void (*f)(void *))
//t_list	*ft_lstnew(void *content)
//void	ft_lstadd_back(t_list **lst, t_list *new)
void	read_map(int fd, t_world *world, t_list **lst)
{
	char	*line;

	line = read_file(fd);
	if (line == NULL)
		error_exit_msg("mapがないよ");
	del_newline_cord(line);
	*lst = ft_lstnew(line);
	while (1)
	{
		line = get_next_line(fd);
		if (errno != 0)
			error_exit_msg("mallocに失敗してたお");
		if (line == NULL)
			break ;
		del_newline_cord(line);
		ft_lstadd_back(lst, ft_lstnew(line));
	}
}

//mapの整形をする
void	arrange_map(t_world *world, t_list *lst)
{
	int	max_len;
	int	lst_size;
	int	i;

	i = 0;
	lst_size = ft_lstsize(lst);
	max_len = count_max_len(lst);
	ft_dprintf(1, "max_len %d : size %d\n", max_len, lst_size);
	world->map = (char **) malloc (sizeof(char *) * (max_len + 1));
	world->map[max_len] = NULL;
	while (world->map[i] != NULL)
	{
		i++;
	}
}

int	count_max_len(t_list *lst)
{
	int	max_len;

	max_len = 0;
	while (lst != NULL)
	{
		if (max_len < ft_strlen(lst->content))
			max_len = ft_strlen(lst->content);
		lst = lst->next;
	}
	return (max_len);
}
