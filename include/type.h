/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:12:24 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/12 23:08:36 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include <inttypes.h>

typedef struct s_coord		t_coord;
typedef struct s_vector2d	t_vector2d;
typedef struct s_tecture	t_texture;
typedef struct s_mlx_data	t_mlx_data;
typedef struct s_dda		t_dda;
typedef struct s_player		t_player;
typedef struct s_world		t_world;

struct s_vector2d
{
	double	x;
	double	y;
};

struct s_coord
{
	int	x;
	int	y;
};

struct s_tecture
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
};

struct s_mlx_data
{
	void	*mlx;
	void	*mlx_win;
	double	time;
	double	old_time;
};

// DDA stands for digital differential analysis
struct s_dda
{
	double		camera_x;
	t_vector2d	ray_dir;
	double		ray_len_to_wall_x;
	double		ray_len_to_wall_y;
	double		ray_len_btw_x_axis;
	double		ray_len_btw_y_axis;
};

struct s_player
{
	t_coord		grid_pos;
	t_vector2d	precise_pos;
	t_vector2d	dir;
	t_vector2d	camera_plane;
};

struct s_world
{
	char		**map;
	int64_t		height;
	int64_t		width;
	int			floor_color;
	int			ceiling_color;
	t_texture	texture;
	t_mlx_data	mlx_data;
	t_player	player;
};

#endif
