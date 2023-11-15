/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:12:02 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/15 13:07:08 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "type.h"

void	frame_buffer_allocate(t_mlx_data *mlx_data)
{
	mlx_data->frame_buffer.img = mlx_new_image(mlx_data->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_data->frame_buffer.addr = mlx_get_data_addr(mlx_data->frame_buffer.img,
			&mlx_data->frame_buffer.bits_per_pixel,
			&mlx_data->frame_buffer.line_length,
			&mlx_data->frame_buffer.endian);
}

void	frame_buffer_destroy(t_mlx_data *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx, mlx_data->frame_buffer.img);
}

void	frame_buffer_apply(t_mlx_data *mlx_data)
{
	mlx_put_image_to_window(mlx_data->mlx,
		mlx_data->mlx_win, mlx_data->frame_buffer.img, 0, 0);
}
