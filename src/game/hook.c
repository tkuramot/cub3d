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
#include <stdio.h>

int	key_hook_down(int keycode, t_world *world)
{
	if (keycode == KEY_LEFT_ARROW)
		world->key_press.is_left_arrow = true;
	if (keycode == KEY_RIGHT_ARROW)
		world->key_press.is_right_arrow = true;
	if (keycode == KEY_W)
		world->key_press.is_w = true;
	if (keycode == KEY_A)
		world->key_press.is_a = true;
	if (keycode == KEY_S)
		world->key_press.is_s = true;
	if (keycode == KEY_D)
		world->key_press.is_d = true;
	if (keycode == KEY_ESC)
		close_window(world);
	return (0);
}

int	key_hook_up(int keycode, t_world *world)
{
	if (keycode == KEY_LEFT_ARROW)
		world->key_press.is_left_arrow = false;
	if (keycode == KEY_RIGHT_ARROW)
		world->key_press.is_right_arrow = false;
	if (keycode == KEY_W)
		world->key_press.is_w = false;
	if (keycode == KEY_A)
		world->key_press.is_a = false;
	if (keycode == KEY_S)
		world->key_press.is_s = false;
	if (keycode == KEY_D)
		world->key_press.is_d = false;
	if (keycode == KEY_ESC)
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
