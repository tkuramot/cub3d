/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:12:24 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/02 23:53:24 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include <inttypes.h>

typedef struct s_tecture	t_texture;
typedef struct s_world		t_world;

struct s_tecture
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
};

struct s_world
{
	char			**map;
	int64_t			height;
	int64_t			width;
	int				floor_color;
	int				ceiling_color;
	t_texture		texture;
};

#endif
