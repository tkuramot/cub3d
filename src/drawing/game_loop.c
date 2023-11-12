/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:37:11 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/12 23:57:38 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "drawing.h"
#include "libft.h"
#include "type.h"
#include <utils.h>

int	game_loop(void *arg)
{
	t_world	*world;
	t_dda	dda;
	int		x;

	world = (t_world *)arg;
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		prepare_dda(world, &dda, x);
	}
	return (0);
}
