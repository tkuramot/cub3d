/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:37:11 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/13 22:37:57 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "cub3d.h"
#include "drawing.h"
#include "game.h"
#include "mlx.h"
#include <stdio.h>

// TODO Read texture files
int	main(int argc, char *argv[])
{
	static t_world	world;

	if (argc != 2)
		error_exit_msg("引数の数が間違ってるよ");
	get_config(argv, &world);
	init_player(&world.player);
	init_mlx_data(&world.mlx_data);
	draw_square(&world, (t_vec2i){0, 0}, (t_vec2i){40, 40}, 0X00FF0000);
	mlx_loop_hook(world.mlx_data.mlx, game_loop, &world);
	mlx_loop(world.mlx_data.mlx);
	return (0);
}
