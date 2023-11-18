/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:12:28 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/17 12:43:13 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "game.h"
#include "type.h"
#include <stdio.h>

int	key_hook(int keycode, t_world *world)
{
		if (keycode == 123)
	{
			printf("%d\n", keycode);
	}
	if (keycode == 124)
	{
			printf("%d\n", keycode);
	}
	if (keycode == 126)
	{
			printf("%d\n", keycode);
	}
	if (keycode == 125)
	{
			printf("%d\n", keycode);
	}
	if (keycode == KEY_W)
		move_forward(world);
	else if (keycode == KEY_A)
		move_leftward(world);
	else if (keycode == KEY_S)
		move_backward(world);
	else if (keycode == KEY_D)
		move_rightward(world);
	else if (keycode == 65361)
		move_rightward(world);
	else if (keycode == KEY_D)
		move_rightward(world);
	return (0);
}
