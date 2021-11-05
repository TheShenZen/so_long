/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:08:16 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/02 15:41:57 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(t_win *win, char *msg)
{
	(void)win;
	printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}