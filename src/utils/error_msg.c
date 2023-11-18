/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:42:41 by tokazaki          #+#    #+#             */
/*   Updated: 2023/11/07 18:37:39 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>

void	error_exit_msg(char *line)
{
	ft_dprintf(2, "ERROR\n");
	if (errno != 0)
		perror("cub3D");
	else
		ft_dprintf(2, "cub3D: %s\n", line);
	exit (1);
}
