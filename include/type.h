/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:12:24 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/26 23:21:52 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include "constant.h"
# include <inttypes.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_vec2i			t_vec2i;
typedef struct s_vec2d			t_vec2d;
typedef struct s_frame_buffer	t_frame_buffer;
typedef struct s_texture_path	t_texture_path;
typedef struct s_texture		t_texture;
typedef struct s_mlx_data		t_mlx_data;
typedef struct s_dda			t_dda;
typedef struct s_player			t_player;
typedef struct s_key_press		t_key_press;
typedef struct s_world			t_world;

struct s_vec2d
{
	double	x;
	double	y;
};

struct s_vec2i
{
	int	x;
	int	y;
};

struct s_texture_path
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
};

struct s_texture
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
};

struct s_frame_buffer
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct s_mlx_data
{
	void			*mlx;
	void			*mlx_win;
	t_frame_buffer	frame_buffer;
	t_texture		textures[NUMBER_OF_BLOCK_FACES];
};

// DDA stands for digital differential analysis
struct s_dda
{
	double		camera_x;
	t_vec2d		ray_dir;
	t_vec2i		grid_pos;
	t_vec2i		next_step_dir;
	double		ray_len_to_wall_x;
	double		ray_len_to_wall_y;
	double		ray_len_btw_x_axis;
	double		ray_len_btw_y_axis;
	bool		did_hit_wall;
	t_direction	hit_side;
};

struct s_player
{
	t_vec2d	precise_pos;
	t_vec2d	dir;
	t_vec2d	camera_plane;
	t_vec2i	pre_cursor_position;
};

struct s_key_press
{
	bool	is_w;
	bool	is_a;
	bool	is_s;
	bool	is_d;
	bool	is_left_arrow;
	bool	is_right_arrow;
};

struct s_world
{
	char			**map;
	int64_t			height;
	int64_t			width;
	int				floor_color;
	int				ceiling_color;
	t_texture_path	texture_path;
	t_mlx_data		mlx_data;
	t_player		player;
	t_key_press		key_press;
};

#endif
