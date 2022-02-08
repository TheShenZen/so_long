/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:01:50 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/10 16:21:01 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H
# if __APPLE__
#  define SYS "macOS"
#  define ESC 53
#  define K_W 13
#  define K_A 0
#  define K_S 1
#  define K_D 2
#  define ARR_UP 126
#  define ARR_LT 123
#  define ARR_RT 125
#  define ARR_DN 124
# elif __linux__
#  define SYS "linux"
#  define ESC 0xff1b
#  define K_W 119
#  define K_A 97
#  define K_S 115
#  define K_D 100
#  define ARR_UP 126
#  define ARR_LT 65361
#  define ARR_RT 65363
#  define ARR_DN 125
# endif
#endif