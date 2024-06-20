/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main--tick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kforfoli <kforfoli@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 01:12:55 by kforfoli          #+#    #+#             */
/*   Updated: 2024/06/17 01:13:10 by kforfoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*PROJECT:
 * -Julia and mandelbrot set
 * -Infinite Zoom
 * - Able to take command line args to determine which
 *   fractal to render
 * -ESC closes the process with no leaks
 * -Click on the x window closes the program with no leaks
 *
 * */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_my_f	f;

	if (ac == 2 && (!ft_strncmp(av[1], "mandelbrot", 10) \
				|| !ft_strncmp(av[1], "cool", 4) \
				|| !ft_strncmp(av[1], "bat", 3)) \
				|| ac == 4 && (!ft_strncmp(av[1], "julia", 5) \
				|| !ft_strncmp(av[1], "flower", 6)))
	{
		f.id = av[1];
		if (!ft_strncmp(f.id, "julia", 5) || !ft_strncmp(f.id, "flower", 6))
		{
			f.julia_x = atodbl(av[2]);
			f.julia_y = atodbl(av[3]);
		}
		ft_init_fractal(&f);
		ft_render_fractal(&f);
		mlx_loop(f.mlx_api);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
