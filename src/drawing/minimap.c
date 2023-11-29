/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:26:10 by tokazaki          #+#    #+#             */
/*   Updated: 2023/11/29 15:37:38 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "drawing.h"
#include <stdio.h>

static void	render_wall_block(t_world *world, int col, int row)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = MINIMAP_PLAYER_POS - world->player.precise_pos.x * MINIMAP_PIXEL_SIZE;
	y = MINIMAP_PLAYER_POS - world->player.precise_pos.y * MINIMAP_PIXEL_SIZE;
	i = 0;
	while (i < MINIMAP_WALL_BLOCK_SIZE)
	{
		j = 0;
		while (j < MINIMAP_WALL_BLOCK_SIZE)
		{
			if (is_in_minimap(col + x + i, row + y + j, \
						MINIMAP_PLAYER_POS, MINIMAP_RADIUS_SIZE) == true)
			{
				my_mlx_pixel_put(&world->mlx_data.frame_buffer, \
					col + x + i, row + y + j, WHITE);
			}
			j++;
		}
		i++;
	}
}

static void	render_obstacle_in_map(t_world *world)
{
	int	row;
	int	col;

	row = 0;
	while (world->map[row] != NULL)
	{
		col = 0;
		while (world->map[row][col] != '\0')
		{
			if (world->map[row][col] == WALL)
				render_wall_block(world, col * MINIMAP_PIXEL_SIZE, \
					row * MINIMAP_PIXEL_SIZE);
			col++;
		}
		row++;
	}
}

static void	render_map_base(t_world *world)
{
	int	i;
	int	j;

	i = MINIMAP_PLAYER_POS - MINIMAP_RADIUS_SIZE - MINIMAP_MARGIN;
	while (i < MINIMAP_PLAYER_POS + MINIMAP_RADIUS_SIZE + MINIMAP_MARGIN)
	{
		j = MINIMAP_PLAYER_POS - MINIMAP_RADIUS_SIZE - MINIMAP_MARGIN;
		while (j < MINIMAP_PLAYER_POS + MINIMAP_RADIUS_SIZE + MINIMAP_MARGIN)
		{
			if (is_in_minimap(i, j, \
						MINIMAP_PLAYER_POS, MINIMAP_RADIUS_SIZE) == true)
				translucent_my_mlx_pixel_put(&world->mlx_data.frame_buffer, \
								i, j, YELLOW);
			else if (is_in_minimap(i, j, MINIMAP_PLAYER_POS, \
						MINIMAP_RADIUS_SIZE + MINIMAP_MARGIN) == true)
				my_mlx_pixel_put(&world->mlx_data.frame_buffer, i, j, ORANGE);
			j++;
		}
		i++;
	}
}

static void	render_player(t_world *world)
{
	int	i;
	int	j;

	i = -MINIMAP_WALL_BLOCK_SIZE;
	while (i < 0)
	{
		j = -MINIMAP_WALL_BLOCK_SIZE;
		while (j < 0)
		{
			my_mlx_pixel_put(&world->mlx_data.frame_buffer, \
				i + MINIMAP_PLAYER_POS, j + MINIMAP_PLAYER_POS, ORANGE);
			j++;
		}
		i++;
	}
}

void	render_minimap(t_world *world)
{
	render_map_base(world);
	render_obstacle_in_map(world);
	render_player(world);
}
