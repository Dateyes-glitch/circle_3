/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init--tick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kforfoli <kforfoli@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 01:31:37 by kforfoli          #+#    #+#             */
/*   Updated: 2024/06/17 01:31:40 by kforfoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*1st:initialize data, init_data*/
/*2nd:events_init*/
/*3rd:ft_init_fractal*/

static void	m_err(void)
{
	perror(MALLOC_ERROR_MSG);
	exit(EXIT_FAILURE);
}
//-->1st

static void	init_data(t_my_f *f)
{
	f->hypotenuse = 4;
	f->iter = 42;
	f->s_x = 0.0;
	f->s_y = 0.0;
	f->zoom = 1.0;
}

static void	init_events(t_my_f *f)
{
	mlx_hook(f->mlx_win, KeyPress, KeyPressMask, ft_handler, f);
	mlx_hook(f->mlx_win, ButtonPress, ButtonPressMask, ft_mouse, f);
	mlx_hook(f->mlx_win, DestroyNotify, StructureNotifyMask, ft_close_handler,
		f);
	mlx_hook(f->mlx_win, MotionNotify, PointerMotionMask, ft_julia_track, f);
}

void	ft_init_fractal(t_my_f *f)
{
	f->mlx_api = mlx_init();
	if (f->mlx_api == NULL)
		m_err();
	f->mlx_win = mlx_new_window(f->mlx_api, WIDTH, HEIGHT, f->id);
	if (f->mlx_win == NULL)
	{
		mlx_destroy_display(f->mlx_api);
		free(f->mlx_api);
		m_err();
	}
	f->img.img = mlx_new_image(f->mlx_api, WIDTH, HEIGHT);
	if (NULL == f->img.img)
	{
		mlx_destroy_window(f->mlx_api, f->mlx_win);
		mlx_destroy_display(f->mlx_api);
		free(f->mlx_api);
		m_err();
	}
	f->img.pxl = mlx_get_data_addr(f->img.img, &f->img.b_per_pxl, &f->img.len,
			&f->img.endian);
	init_events(f);
	init_data(f);
}
