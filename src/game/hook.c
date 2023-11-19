/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:12:28 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/19 00:49:24 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "game.h"
#include "type.h"
#include <stdio.h>

int	key_hook(int keycode, t_world *world)
{
	if (keycode == KEY_LEFT_ARROW)
		printf("%d\n", keycode);
	if (keycode == KEY_RIGHT_ARROW)
		printf("%d\n", keycode);
	if (keycode == KEY_W)
		move_forward(world);
	else if (keycode == KEY_A)
		move_leftward(world);
	else if (keycode == KEY_S)
		move_backward(world);
	else if (keycode == KEY_D)
		move_rightward(world);
	return (0);
}
