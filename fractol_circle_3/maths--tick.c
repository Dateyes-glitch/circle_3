#include "fractol.h"

double map(double pxl_to_scale, double n_min, double n_max, double o_min, double o_max)
{
  double n;
  double new_range;
  double old_range;
  double dis; // distance from current pxl to starter pxl

  new_range = n_max - n_min;
  old_range = o_max - o_min;
  dis = pxl_to_scale - o_min;
  n = (new_range / old_range) * dis + n_min;
  return n;
}

c_num ft_sum_cmplxs(c_num z1, c_num z2)
{
  c_num res;

  res.x = z1.x + z2.x;
  res.y = z1.y + z2.y;

  return (res);
}

c_num ft_square(c_num z)
{
	c_num square;
	square.x = (z.x * z.x) - (z.y * z.y);
	square.y = 2 * z.x * z.y;
	return square;
}

c_num ft_flower(c_num z)
{
	c_num square;
	square.x = (z.x * z.x / z.y) - (z.y * z.y / z.x);
	square.y = 2 * z.x * z.y;
	return square;
}

c_num ft_cool(c_num z)
{
	c_num square;
	square.x = (z.x * z.x) - (z.y * z.y);
	square.y = -0.75 * z.x * z.y * (1 / square.x);
	return square;
}

c_num   ft_batsig(c_num z)
{
  //from z * z or z ^ 2 we know that real part(x) = a ^ 2 - b ^ 2
  //imaginary (y) part = 2abi so 2xy
  //now lets the x and y of another complex num which will 
  //be the square complex num equal to the real abd imaginary
  c_num square;
  square.x = ((z.x * z.x * z.x * z.x) - (6 * z.x * z.x * z.y * z.y) - (z.y * z.y * z.y * z.y)) / 0.4 * (z.x * z.x);
  square.y = (z.x * z.x * z.x * z.y) + (z.x * z.y * z.y * z.y);
  return square;
}
