/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:37:11 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/14 09:01:26 by tkuramot         ###   ########.fr       */
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
		error_exit_msg("only one argument is allowed");
	get_config(argv, &world);
	init_player(&world.player);
	init_mlx_data(&world.mlx_data);
	mlx_loop_hook(world.mlx_data.mlx, game_loop, &world);
	mlx_loop(world.mlx_data.mlx);
	return (0);
}
