/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:52:46 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/20 01:29:26 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawing.h"
#include "mlx.h"
#include "type.h"
#include <stdlib.h>

int	close_window(t_world *world)
{
	mlx_destroy_window(world->mlx_data.mlx, world->mlx_data.mlx_win);
	mlx_destroy_display(world->mlx_data.mlx);
	frame_buffer_destroy(&world->mlx_data);
	exit(0);
}
