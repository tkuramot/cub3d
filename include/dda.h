/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:58:24 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/13 01:13:05 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H

# include "type.h"

void	prepare_dda(t_world *world, t_dda *dda, int x);
void	perform_dda(t_world *world, t_dda *dda);
double	get_dist_camera_plane_to_wall(t_dda *dda);

#endif
