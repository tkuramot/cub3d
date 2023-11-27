/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:26:10 by tokazaki          #+#    #+#             */
/*   Updated: 2023/11/28 01:30:33 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "dda.h"
#include "drawing.h"
#include "libft.h"
#include "mlx.h"
#include "type.h"
#include <stdint.h>
#include <stdio.h>
#include <utils.h>
#include <stdbool.h>

bool	is_render_mini_map(int x, int y, int center, int radius);
void	translucent_my_mlx_pixel_put(t_frame_buffer *frame_buffer, \
								int x, int y, int color);

//minimapに壁ブロックの描画
void	render_wall_brock(t_world *world, int col, int row)
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
			if (is_render_mini_map(col + x + i, row + y + j, \
						MINIMAP_PLAYER_POS, MINIMAP_RADIUS_SIZE) == true)
			{
				my_mlx_pixel_put(&world->mlx_data.frame_buffer, \
					col + x + i, row + y + j, 0xFFFFFF);
			}
			j++;
		}
		i++;
	}
}

//どのに壁があるか確認する
void	render_blocks(t_world *world)
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
				render_wall_brock(world, col * MINIMAP_PIXEL_SIZE, \
					row * MINIMAP_PIXEL_SIZE);
			col++;
		}
		row++;
	}
}

//mapのベースを描画する
void	render_map_base(t_world *world)
{
	int	i;
	int	j;

	i = MINIMAP_PLAYER_POS - MINIMAP_RADIUS_SIZE - MINIMAP_MARGIN;
	while (i < MINIMAP_PLAYER_POS + MINIMAP_RADIUS_SIZE + MINIMAP_MARGIN)
	{
		j = MINIMAP_PLAYER_POS - MINIMAP_RADIUS_SIZE - MINIMAP_MARGIN;
		while (j < MINIMAP_PLAYER_POS + MINIMAP_RADIUS_SIZE + MINIMAP_MARGIN)
		{
			if (is_render_mini_map(i, j, \
						MINIMAP_PLAYER_POS, MINIMAP_RADIUS_SIZE) == true)
				translucent_my_mlx_pixel_put(&world->mlx_data.frame_buffer, \
								i, j, 0xfff462);
			else if (is_render_mini_map(i, j, MINIMAP_PLAYER_POS, \
						MINIMAP_RADIUS_SIZE + MINIMAP_MARGIN) == true)
				my_mlx_pixel_put(&world->mlx_data.frame_buffer, i, j, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

//プレイヤーの場所の表示
void	render_player(t_world *world)
{
	int	i;
	int	j;

	i = -6;
	while (i < -1)
	{
		j = -5;
		while (j < 0)
		{
			my_mlx_pixel_put(&world->mlx_data.frame_buffer, \
				i + MINIMAP_PLAYER_POS, j + MINIMAP_PLAYER_POS, 0x0);
			j++;
		}
		i++;
	}
}

void	render_minimap(t_world *world)
{
	render_map_base(world);
	render_blocks(world);
	render_player(world);
}
