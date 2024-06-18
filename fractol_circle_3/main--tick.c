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

int   main(int ac, char **av)
{
  my_f f;

  if (ac == 2 && (!ft_strncmp(av[1], "mandelbrot", 10) || !ft_strncmp(av[1], "flower", 6) || !ft_strncmp(av[1], "cool", 4) || !ft_strncmp(av[1], "bat",3)) || ac == 4 && !ft_strncmp(av[1], "julia", 5))
  {
    f.id = av[1];
    if (!ft_strncmp(f.id, "julia", 5))
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

/*
int   main(int ac, char **av)
{
  my_f f;

  if ((ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0) || (ac == 4 && ft_strcmp(av[1], "julia") == 0))
  {
    f.id = av[1];
    if (ft_strcmp(f.id, "julia") == 0)
    {
      if ((int)atodb(av[2]) / 2 > 1 || (int)atodb(av[3]) / 2 > 1)
      {
        printf("too big, or small number please try again");
        return 1;
      }
      else
      {
        f.julia_x = atodb(av[2]);
        f.julia_y = atodb(av[3]);
      }
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
*/
