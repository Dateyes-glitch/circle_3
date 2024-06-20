/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths--tick.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kforfoli <kforfoli@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 00:50:44 by kforfoli          #+#    #+#             */
/*   Updated: 2024/06/17 00:57:24 by kforfoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double pxl_to_scale, double n_min, double n_max, double o_max)
{
	double	n;
	double	new_range;
	double	old_range;
	double	dis;

	new_range = n_max - n_min;
	old_range = o_max - 0;
	dis = pxl_to_scale - 0;
	n = (new_range / old_range) * dis + n_min;
	return (n);
}

t_num	ft_sum_cmplxs(t_num z1, t_num z2)
{
	t_num	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

t_num	ft_square(t_num z)
{
	t_num	square;

	square.x = (z.x * z.x) - (z.y * z.y);
	square.y = 2 * z.x * z.y;
	return (square);
}
