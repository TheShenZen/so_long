/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:13:04 by seciurte          #+#    #+#             */
/*   Updated: 2021/10/23 19:24:49 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	absol(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	is_movement_key(int key)
{
	if (key == K_W || key == K_A || key == K_S || key == K_D)
		return (1);
	return (0);
}