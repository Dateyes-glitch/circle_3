/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_frac.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kforfoli <kforfoli@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 00:59:04 by kforfoli          #+#    #+#             */
/*   Updated: 2024/06/17 01:06:25 by kforfoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_num	ft_flower(t_num z)
{
	t_num	square;

	square.x = (z.x * z.x / z.y) - (z.y * z.y / z.x);
	square.y = 2 * z.x * z.y;
	return (square);
}

t_num	ft_cool(t_num z)
{
	t_num	square;

	square.x = (z.x * z.x) - (z.y * z.y);
	square.y = -0.75 * z.x * z.y * (1 / square.x);
	return (square);
}

t_num	ft_batsig(t_num z)
{
	t_num	square;

	square.x = ((z.x * z.x * z.x * z.x) \
			- (6 * z.x * z.x * z.y * z.y) \
			- (z.y * z.y * z.y * z.y)) / 0.4 * (z.x * z.x);
	square.y = (z.x * z.x * z.x * z.y) + (z.x * z.y * z.y * z.y);
	return (square);
}
