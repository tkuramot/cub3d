/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:37:11 by tkuramot          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/11/26 03:11:52 by tkuramot         ###   ########.fr       */
=======
/*   Updated: 2023/11/20 23:53:58 by tkuramot         ###   ########.fr       */
>>>>>>> 2296370 (Add textures)
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "drawing.h"
#include "mlx.h"
#include "type.h"

void	init_mlx_data(t_mlx_data *mlx_data)
{
	mlx_data->mlx = mlx_init();
	mlx_data->mlx_win = mlx_new_window(mlx_data->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	frame_buffer_allocate(mlx_data);
}

<<<<<<< HEAD
void	load_texture(t_texture *texture, t_texture_path *texture_path)
{
	(void)texture;
	(void)texture_path;
}
=======
// void	load_texture(t_texture_data *texture_data, t_texture_path *texture_path)
// {
// }
>>>>>>> 2296370 (Add textures)
