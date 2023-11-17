/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:37:11 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/17 10:24:08 by tkuramot         ###   ########.fr       */
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
	init_player(&world);
	init_mlx_data(&world.mlx_data);
	mlx_hook(world.mlx_data.mlx_win, ON_KEYDOWN, 1LL << 0, key_hook, &world);
	mlx_loop_hook(world.mlx_data.mlx, game_loop, &world);
	mlx_loop(world.mlx_data.mlx);
	return (0);
}
