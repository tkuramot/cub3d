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

static char	**init_map(int lst_size, int max_len);
static int	count_max_len(t_list *lst);
static void	cpy_lst_to_ptr_map(char **map, t_list *lst);

//mapの整形をする
void	arrange_map_lst_to_ptr(t_world *world, t_list *lst)
{
	int	max_len;
	int	lst_size;

	lst_size = ft_lstsize(lst);
	max_len = count_max_len(lst);
	world->map = init_map(lst_size, max_len);
	cpy_lst_to_ptr_map(world->map, lst);
	world->height = lst_size;
	world->width = max_len;
}
//	ft_dprintf(1, "mapsize max_len %d : size %d\n", max_len, lst_size);

static char	**init_map(int lst_size, int max_len)
{
	char	**map;
	int		i;

	i = 0;
	map = (char **) malloc (sizeof(char *) * (lst_size + 1));
	if (map == NULL)
		error_exit_msg("すまん、malloc失敗したわ〜");
	while (i < lst_size)
	{
		map[i] = (char *) malloc (sizeof(char) * (max_len + 1));
		if (map[i] == NULL)
			error_exit_msg("すまん、malloc失敗したわ〜");
		ft_memset(map[i], ' ', max_len);
		map[i][max_len] = '\0';
		i++;
	}
	map[lst_size] = (char *) ft_calloc(sizeof(char), max_len + 1);
	if (map[lst_size] == NULL)
		error_exit_msg("すまん、malloc失敗したわ〜");
	return (map);
}

static int	count_max_len(t_list *lst)
{
	size_t	max_len;

	max_len = 0;
	while (lst != NULL)
	{
		if (max_len < ft_strlen(lst->content))
			max_len = ft_strlen(lst->content);
		lst = lst->next;
	}
	return (max_len);
}

static void	cpy_lst_to_ptr_map(char **map, t_list *lst)
{
	int	i;

	i = 0;
	while (map[i][0] != '\0')
	{
		ft_memmove(map[i], lst->content, ft_strlen(lst->content));
		lst = lst->next;
		i++;
	}
}
