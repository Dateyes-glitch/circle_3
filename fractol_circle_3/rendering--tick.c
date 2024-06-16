#include "fractol.h"

static void   ft_pixel_put(int x, int y, my_img *img, int clr)
{
  int set;

  set = (y * img->len) + (x * (img->b_per_pxl / 8));
  *(unsigned int *)(img->pxl + set) = clr;
}

static void   mandel_or_julia(c_num *z, c_num *c, my_f *f)
{
  if (ft_strncmp(f->id, "julia", 5) == 0)
  {
    c->x = f->julia_x;
    c->y = f->julia_y;
  }
  else
  {
    c->x = z->x;
    c->y = z->y;
  }

}

static void   ft_c_h_pixel(int x, int y, my_f *f)
{
  c_num   z;

  c_num   c;
  int     i;
  int     clr;

  i = 0;

  z.x = (map(x, -2, +2, 0, WIDTH) * f->zoom) + f->s_x;
  z.y = (map(y, +2, -2, 0, HEIGHT) * f->zoom) + f->s_y;

  mandel_or_julia(&z, &c, f);

  while (i < f->iter)
  {
    if (!ft_strncmp(f->id, "cool", 4))
      z = ft_sum_cmplxs(ft_cool(z), c);
    else if (!ft_strncmp(f->id, "flower", 6))
      z = ft_sum_cmplxs(ft_flower(z), c);
    else if (!ft_strncmp(f->id, "bat", 3))
      z = ft_sum_cmplxs(ft_batsig(z), c);
    else
      z = ft_sum_cmplxs(ft_square(z), c);
    if ((z.x * z.x) + (z.y * z.y) > f->hypotenuse)
    {
      clr = map(i, BLACK, WHITE, 0, f->iter);
      ft_pixel_put(x, y, &f->img, clr);
      return ;
    }
    i++;
  }
  ft_pixel_put(x, y, &f->img, WHITE);
}
void  ft_render_fractal(my_f *f)
{
  int x;
  int y;
  
  y = -1;
  while (++y < HEIGHT)
  {
    x = -1;
    while (++x < WIDTH)
      ft_c_h_pixel(x, y, f);
  }
  mlx_put_image_to_window(f->mlx_api,
                          f->mlx_win,
                          f->img.img,
                          0,0);
}
