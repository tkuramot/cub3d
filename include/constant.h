/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:37:11 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/17 01:11:59 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANT_H
# define CONSTANT_H

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define INFINITY INT_MAX
# define MOVEMENT_SPEED 0.2

typedef enum e_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	INIT
}		t_direction;

typedef enum e_axis
{
	X_AXIS,
	Y_AXIS
}		t_axis;

typedef enum e_map_chr
{
	WALL = '1',
	EMPTY = '0'
}		t_map_chr;

#endif
