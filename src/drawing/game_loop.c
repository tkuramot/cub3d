/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:37:11 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/12 23:08:59 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "ft_strings.h"
#include "type.h"

int	game_loop(void *arg)
{
	t_world	*world;
	t_dda	dda;
	int		x;

	world = (t_world *)arg;
	ft_bzero(&dda, sizeof(t_dda));
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		dda.camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
		dda.ray_dir.x = world->player.dir.x + world->player.camera_plane.x * dda.camera_x;
		dda.ray_dir.y = world->player.dir.y + world->player.camera_plane.y * dda.camera_x;
		world->player.grid_pos.x = (int)world->player.precise_pos.x;
		world->player.grid_pos.y = (int)world->player.precise_pos.y;
	}
	return (0);
}
