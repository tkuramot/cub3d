/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:57:43 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/15 17:15:52 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_strings.h"
#include "parser.h"
#include "type.h"
#include <stdio.h>

static void	assign_player_pos(t_world *world)
{
	int	y;
	int	x;

	y = 0;
	while (y < world->height)
	{
		x = 0;
		while (x < world->width)
		{
			if (is_start_char(world->map[y][x]))
			{
				world->player.precise_pos.x = x + 0.5;
				world->player.precise_pos.y = y + 0.5;
				break ;
			}
			x++;
		}
		y++;
	}
}

// TODO Replace temporary values with config ones
// Exit this program when an error occurs
void	init_player(t_world *world)
{
	ft_bzero(&world->player, sizeof(t_player));
	assign_player_pos(world);
	world->player.dir.x = 1;
	world->player.dir.y = 0;
	world->player.camera_plane.x = 0;
	world->player.camera_plane.y = 0.66;
}
