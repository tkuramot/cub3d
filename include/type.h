/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:12:24 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/02 22:34:22 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_tecture
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
} t_texture;

typedef struct s_world
{
	char		**map;
	int			floor_color;
	int			ceiling_color;
	t_texture	texture;
} t_world;
