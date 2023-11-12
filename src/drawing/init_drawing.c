/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:37:11 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/13 00:36:01 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "mlx.h"
#include "type.h"

// TODO Replace temporary values with config ones
// Exit this program when an error occurs
void	init_player(t_player *player)
{
	player->precise_pos.x = 0;
	player->precise_pos.y = 0;
	player->dir.x = -1;
	player->dir.y = 0;
	player->camera_plane.x = 0;
	player->camera_plane.y = 0.66;
}

void	init_mlx_data(t_mlx_data *mlx_data)
{
	mlx_data->mlx = mlx_init();
	mlx_data->mlx_win = mlx_new_window(mlx_data->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
}
