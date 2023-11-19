/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:59:33 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/19 21:59:12 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "type.h"

void	init_player(t_world *world);
int		game_loop(void *world);
int		key_hook(int keycode, t_world *world);
void	move_forward(t_world *world);
void	move_rightward(t_world *world);
void	move_backward(t_world *world);
void	move_leftward(t_world *world);
void	move_eye_movement(t_world *world, int rotate_direction);
int		close_window(t_world *world);

#endif
