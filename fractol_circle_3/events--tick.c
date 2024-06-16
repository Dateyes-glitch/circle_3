#include "fractol.h"

/*
 *ESC or press x
 */
//#include "fractol--tick.h"
int   ft_close_handler(my_f *f)
{
  mlx_destroy_image(f->mlx_api,
                    f->img.img);
  mlx_destroy_window(f->mlx_api,
                     f->mlx_win);
  mlx_destroy_display(f->mlx_api);
  free(f->mlx_api);
}
 
/**/
int   ft_mouse(int button, int x, int y, my_f *f) //do we need x or y as params?
{
  if (button == Button4)
    f->zoom = f->zoom * 0.95;
  else if (button == Button5)
    f->zoom = f->zoom * 1.05;
  ft_render_fractal(f);
  return 0;
}

/*track the mouse to change julia dynamically*/
int   ft_julia_track(int x, int y, my_f *f)
{
  if (ft_strncmp(f->id, "julia", 5) == 0) //ie !ft_strcmp(f->name,"julia")
  {
    f->julia_x = (map (x, -2, +2, 0, WIDTH) * f->zoom) + f->s_x;
    f->julia_y = (map (y, +2, -2, 0, HEIGHT) * f->zoom) + f->s_y;
    ft_render_fractal(f);
  }
  return 0;
}
int   ft_handler(int keysym, my_f *f)
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
  else if (keysym == XK_plus)
      f->iter += 10;
  else if (keysym == XK_minus)
      f->iter -= 10;
  ft_render_fractal(f);
  return 0;

  


}
