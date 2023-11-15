/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:57:43 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/15 12:33:23 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

// TODO Replace temporary values with config ones
// Exit this program when an error occurs
void	init_player(t_player *player)
{
	player->precise_pos.x = 1.5;
	player->precise_pos.y = 1.5;
	player->dir.x = 1;
	player->dir.y = 0;
	player->camera_plane.x = 0;
	player->camera_plane.y = 0.66;
}
