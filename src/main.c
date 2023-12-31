/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:37:11 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/26 03:15:41 by tkuramot         ###   ########.fr       */
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

	errno = 0;
	if (argc != 2)
		error_exit_msg("Only one argument is allowed");
	get_config(argv, &world);
	init_player(&world);
	init_mlx_data(&world);
	mlx_hook(world.mlx_data.mlx_win, ON_KEYDOWN,
		1LL << 0, key_hook_down, &world);
	mlx_hook(world.mlx_data.mlx_win, ON_KEYUP,
		1LL << 1, key_hook_up, &world);
	mlx_hook(world.mlx_data.mlx_win, ON_DESTROY,
		1LL << 17, close_window, &world);
	mlx_hook(world.mlx_data.mlx_win, ON_MOUSEMOVE,
		1L << 6, mouse_hook, &world);
	mlx_loop_hook(world.mlx_data.mlx, game_loop, &world);
	mlx_loop(world.mlx_data.mlx);
	return (0);
}
