/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:12:28 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/22 18:57:14 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "game.h"
#include "type.h"

int	key_hook(int keycode, t_world *world)
{
	if (keycode == KEY_LEFT_ARROW)
		rotate_view_direction(world, LEFT * ROTATE_KEY_SPEED);
	else if (keycode == KEY_RIGHT_ARROW)
		rotate_view_direction(world, RIGHT * ROTATE_KEY_SPEED);
	else if (keycode == KEY_W)
		move_forward(world);
	else if (keycode == KEY_A)
		move_leftward(world);
	else if (keycode == KEY_S)
		move_backward(world);
	else if (keycode == KEY_D)
		move_rightward(world);
	else if (keycode == KEY_ESC)
		close_window(world);
	return (0);
}

int	mouse_hook(int x, int y, t_world *world)
{
	int	x_diff;

	x_diff = x - world->player.pre_cursor_position.x;
	if (0 < x_diff && x_diff < MOVEMENT_LIMIT)
		rotate_view_direction(world, ROTATE_MOUSE_SPEED * x_diff);
	else if (-MOVEMENT_LIMIT < x_diff && x_diff < 0)
		rotate_view_direction(world, ROTATE_MOUSE_SPEED * x_diff);
	world->player.pre_cursor_position.x = x;
	return (0);
	(void)y;
}
