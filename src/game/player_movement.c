/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:12:48 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/18 12:31:14 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "type.h"
#include <stdio.h>

static void	move_player(t_world *world, double dy, double dx)
{
	double	new_y;
	double	new_x;

	new_y = world->player.precise_pos.y + dy * MOVEMENT_SPEED;
	new_x = world->player.precise_pos.x + dx * MOVEMENT_SPEED;
	if (world->map[(int)new_y][(int)world->player.precise_pos.x] != WALL)
		world->player.precise_pos.y = new_y;
	if (world->map[(int)world->player.precise_pos.y][(int)new_x] != WALL)
		world->player.precise_pos.x = new_x;
}

// W
void	move_forward(t_world *world)
{
	move_player(world, world->player.dir.y, world->player.dir.x);
}

// A
void	move_leftward(t_world *world)
{
	move_player(world, -world->player.dir.x, world->player.dir.y);
}

// S
void	move_backward(t_world *world)
{
	move_player(world, -world->player.dir.y, -world->player.dir.x);
}

void	move_rightward(t_world *world)
{
	move_player(world, world->player.dir.x, -world->player.dir.y);
}
