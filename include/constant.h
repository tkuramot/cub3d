/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:37:11 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/26 03:14:05 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANT_H
# define CONSTANT_H

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define INFINITY INT_MAX
# define MOVEMENT_SPEED 0.1
# define ROTATE_KEY_SPEED 0.05
# define ROTATE_MOUSE_SPEED 0.02
# define MOVEMENT_LIMIT 50
# define NUMBER_OF_BLOCK_FACES 4

typedef enum e_direction	t_direction;
typedef enum e_axis			t_axis;
typedef enum e_map_chr		t_map_chr;
typedef enum e_key_code		t_key_code;
typedef enum e_event		t_event;
typedef enum e_event_mask	t_event_mask;

enum e_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	INIT
};

enum e_axis
{
	X_AXIS,
	Y_AXIS
};

enum e_rotate
{
	LEFT = -1,
	RIGHT = 1
};

enum e_map_chr
{
	WALL = '1',
	EMPTY = '0'
};

enum e_key_code
{
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_ESC = 65307,
	KEY_LEFT_ARROW = 65361,
	KEY_RIGHT_ARROW = 65363
};

enum e_event {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum e_event_mask
{
	MASK_NO_EVENT = 0LL,
	MASK_KEY_PRESS = 1LL << 0
};

#endif
