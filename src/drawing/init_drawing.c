/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:37:11 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/02 20:39:22 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "mlx.h"
#include "type.h"

// TODO Replace temporary values with config ones
// Exit this program when an error occurs
void	init_dda(t_dda *dda)
{
	dda->position.x = 0;
	dda->position.y = 0;
	dda->direction.x = -1;
	dda->direction.y = 0;
	dda->camera_plane.x = 0;
	dda->camera_plane.y = 0.66;
	dda->time = 0;
	dda->old_time = 0;
}

void	init_mlx_data(t_mlx_data *mlx_data)
{
	mlx_data->mlx = mlx_init();
	mlx_data->mlx_win = mlx_new_window(mlx_data->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
}
