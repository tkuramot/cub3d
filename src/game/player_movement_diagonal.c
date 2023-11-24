/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:12:48 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/20 15:58:14 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "type.h"

void	move_forward_right(t_world *world)
{
	move_player(world, world->player.dir.y + world->player.dir.x,
		world->player.dir.x - world->player.dir.y);
}

void	move_forward_left(t_world *world)
{
	move_player(world, world->player.dir.y - world->player.dir.x,
		world->player.dir.x + world->player.dir.y);
}

void	move_backward_right(t_world *world)
{
	move_player(world, -world->player.dir.y + world->player.dir.x,
		-world->player.dir.x - world->player.dir.y);
}

void	move_backward_left(t_world *world)
{
	move_player(world, -world->player.dir.y - world->player.dir.x,
		-world->player.dir.x + world->player.dir.y);
}
