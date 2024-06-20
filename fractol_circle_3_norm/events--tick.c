/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events--tick.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kforfoli <kforfoli@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 01:07:08 by kforfoli          #+#    #+#             */
/*   Updated: 2024/06/17 01:10:05 by kforfoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close_handler(t_my_f *f)
{
	mlx_destroy_image(f->mlx_api, f->img.img);
	mlx_destroy_window(f->mlx_api, f->mlx_win);
	mlx_destroy_display(f->mlx_api);
	free(f->mlx_api);
	exit(EXIT_SUCCESS);
}

int	ft_mouse(int button, int x, int y, t_my_f *f)
{
	if (button == Button4)
		f->zoom = f->zoom * 0.95;
	else if (button == Button5)
		f->zoom = f->zoom * 1.05;
	ft_render_fractal(f);
	return (0);
}

/*track the mouse to change julia dynamically*/
int	ft_julia_track(int x, int y, t_my_f *f)
{
	if (!ft_strncmp(f->id, "julia", 5) || !ft_strncmp(f->id, "flower", 6))
	{
		f->julia_x = (map(x, -2, +2, WIDTH) * f->zoom) + f->s_x;
		f->julia_y = (map(y, +2, -2, HEIGHT) * f->zoom) + f->s_y;
		ft_render_fractal(f);
		/*if (f->julia_x - f->julia_y > 3 || f->julia_x - f->julia_y > -3)
			ft_render_fractal(f);
		else if(f->julia_y - f->julia_x > 3 || f->julia_y - f->julia_x > -3)
			ft_render_fractal(f);*/
	}
	return (0);
}

int	ft_handler(int keysym, t_my_f *f)
{
	if (keysym == XK_Escape)
		ft_close_handler(f);
	else if (keysym == XK_Up)
		f->s_y -= (0.5 * f->zoom);
	else if (keysym == XK_Down)
		f->s_y += (0.5 * f->zoom);
	else if (keysym == XK_Right)
		f->s_x -= (0.5 * f->zoom);
	else if (keysym == XK_Left)
		f->s_x += (0.5 * f->zoom);
	else if (keysym == XK_F1)
		f->iter += 10;
	else if (keysym == XK_F5 && f->iter > 10)
		f->iter -= 10;
	ft_render_fractal(f);
	return (0);
}
