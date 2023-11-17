/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:59:33 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/17 01:30:17 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "type.h"

void	init_player(t_world *world);
int		game_loop(void *world);
int		key_hook(int keycode, t_world *world);
void	move_forward(t_world *world);

#endif
