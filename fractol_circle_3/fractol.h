#ifndef FRACTOL_H
# define FRACTOL_H


#define ERROR_MESSAGE "Invalid input!\n\n" \
                       "Usage:\n" \
                       "  ./fractol mandelbrot\n" \
                       "  or\n" \
                       "  ./fractol julia <value_1> <value_2>\n\n" \
                       "Please ensure you follow the correct format and provide appropriate values.\n" \
                       "Example:\n" \
                       "  ./fractol julia 0.355 0.355\n"


//#define ERROR_MESSAGE "\n" \
                     "******************************************\n" \
                     "*                ERROR MENU              *\n" \
                     "******************************************\n" \
                     "* 1. File not found                      *\n" \
                     "* 2. Invalid input                       *\n" \
                     "* 3. Connection timed out                *\n" \
                     "* 4. Out of memory                       *\n" \
                     "* 5. Access denied                       *\n" \
                     "* 6. Unknown error                       *\n" \
                     "******************************************\n" \
                     "* Please contact support if you see this *\n" \
                     "******************************************\n"
#define MALLOC_ERROR_MSG "Malloc issues friend :("

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

#define WIDTH 800
#define HEIGHT 800

/*(1). BASIC COLORS*/
#define BLACK     0x000000 // RGB(0, 0 , 0)
#define WHITE     0xFFFFFF // (255, 255, 255)
#define RED       0xFF0000 // (255, 0 , 0)
#define GREEN     0x00FF00 // (0, 255, 0)
#define BLUE      0x0000FF // (0, 0, 255)

/*Psychedelic colors*/
#define MAGENTA_BURST 0xFF00FF
#define LIME_SHOCK 0xCCFF00
#define NEON_ORANGE 0xFF6600
#define PSYCHEDELIC_PURPLE 0x660066
#define AQUA_DREAM 0x33CCCC
#define HOT_PINK 0xFF66B2
#define ELECTRIC_BLUE 0x0066FF
#define LAVA_RED 0xFF3300

/*struct for complex num*/
typedef struct t_num
{
  double x;
  double y;
} c_num;

/*struct for image*/
typedef struct t_img
{
  char *pxl; // points to the actual pxls
  void *img; //pointer to img struct
  int b_per_pxl;
  int endian;
  int len;
} my_img;

/*struct for fractal*/
typedef struct t_fractal
{
  char *id;
  //mlx
  void *mlx_api; // mlx_init()
  void *mlx_win; //mlx_new_window()
  //img
  my_img img;

  double hypotenuse; //i.e escape value a^2 + b^2 = c^2 pythagorean theorem
  int iter;
  double s_x;//s for shift needed for julia? 
  double s_y;
  double zoom;
  double julia_x;
  double julia_y;
} my_f;

/*strs.c*/
//int   ft_strcmp(char *s1, char *s2);
int   ft_strncmp(char *s1, char *s2, int n);
void  ft_putstr_fd(char *s, int fd);
double atodbl(char *s);
//double atodb(char *s);

/*init.c*/
void  ft_init_fractal(my_f *f);

/*rendering.c*/
void ft_render_fractal(my_f *f);

/*math_utils.c*/
double map (double non_scaled, double n_min, double n_max, double o_min, double o_max);
c_num  ft_sum_cmplxs(c_num z1, c_num z2);
c_num  ft_square(c_num z);
c_num  ft_flower(c_num z);
c_num  ft_cool(c_num z);
c_num  ft_batsig(c_num z);
/*events*/
/*hooks*/
int   ft_handler(int keysym, my_f *f);

/*clean_up*/
int   ft_close_handler(my_f *f);
int   ft_mouse(int button, int x, int y, my_f *f);
int   ft_julia_track(int x, int y, my_f *f);

#endif
