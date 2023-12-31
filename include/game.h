/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:59:33 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/22 02:17:38 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "type.h"

void	init_player(t_world *world);
int		game_loop(void *world);
int		key_hook_down(int keycode, t_world *world);
int		key_hook_up(int keycode, t_world *world);
int		mouse_hook(int x, int y, t_world *world);
void	move_player(t_world *world, double dy, double dx);
void	rotate_view_direction(t_world *world, double rotate_dir);
int		close_window(t_world *world);

#endif
