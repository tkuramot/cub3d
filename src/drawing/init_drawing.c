/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:37:11 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/29 10:34:18 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "cub3d.h"
#include "drawing.h"
#include "mlx.h"
#include "type.h"
#include "utils.h"
#include <stdio.h>

static void	allocate_texture_data(t_mlx_data *mlx_data,
								t_texture *texture, char *texture_path)
{
	texture->img = mlx_xpm_file_to_image(mlx_data->mlx,
			texture_path, &texture->width, &texture->height);
	if (!texture->img)
	{
		errno = 0;
		error_exit_msg("Failed to load texture data\n");
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
			&texture->line_length,
			&texture->endian);
}

static void	load_texture_data(t_mlx_data *mlx_data,
							t_texture_path *texture_path)
{
	allocate_texture_data(mlx_data,
		&mlx_data->textures[NORTH], texture_path->north_texture);
	allocate_texture_data(mlx_data,
		&mlx_data->textures[SOUTH], texture_path->south_texture);
	allocate_texture_data(mlx_data,
		&mlx_data->textures[WEST], texture_path->west_texture);
	allocate_texture_data(mlx_data,
		&mlx_data->textures[EAST], texture_path->east_texture);
}

void	init_mlx_data(t_world *world)
{
	world->mlx_data.mlx = mlx_init();
	world->mlx_data.mlx_win = mlx_new_window(world->mlx_data.mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	frame_buffer_allocate(&world->mlx_data);
	load_texture_data(&world->mlx_data, &world->texture_path);
}
