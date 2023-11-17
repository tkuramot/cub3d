/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:12:48 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/17 12:29:01 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "type.h"
#include <stdio.h>

void	move_forward(t_world *world)
{
	if (world->map[(int)(world->player.precise_pos.y
			+ world->player.dir.y * MOVEMENT_SPEED)]
			[(int)world->player.precise_pos.y] != WALL)
		world->player.precise_pos.y += world->player.dir.y * MOVEMENT_SPEED;
	if (world->map[(int)world->player.precise_pos.y]
		[(int)(world->player.precise_pos.x
			+ world->player.dir.x * MOVEMENT_SPEED)] != WALL)
		world->player.precise_pos.x += world->player.dir.x * MOVEMENT_SPEED;
}
