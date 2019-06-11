#ifndef FRACTOL_H
# define FRACTOL_H
# define HEIGHT 800
# define WIDTH 800
// # define DEPTH 50
// # define RANGE_RE 3.5/800
// # define RANGE_IM 3.0/800

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

////
#include <stdio.h>
////

typedef struct			s_mlx
{
	void				*win;
	void				*mlx;
	void				*im;
	int					*imdata;
	int					ls;
}						t_mlx;

typedef struct			s_lmt
{
	double				re_max;
	double				re_min;
	double				im_max;
	double				im_min;
	double				re_range;
	double				im_range;
}						t_lmt;

typedef struct			s_frct
{
	t_mlx				*mlx;
	t_lmt				lmt;
	int					depth;
	int					num_fract;
	double				julia_a;
	double				julia_b;
}						t_frct;

/*For different threds*/
typedef struct			s_thrd
{
	int					y_min;
	int					y_max;
	t_frct				*frct;
}						t_thrd;

t_mlx					*create_win(void);
void					create_image(t_mlx *mlx);
int						mandelbrot(double a0, double b0, int depth);
double					scale_re(int x, t_lmt lmt);
double					scale_im(int y, t_lmt lmt);
void					put_pixel(int x, int y, int color, t_mlx *mlx);
int						buttons(int kc, t_frct *frct);
// int						palette(int iter);
t_lmt					set_limits(t_frct *frct);
void					*algoritm(t_thrd *t);
int						zoom(int kc, int x, int y, t_frct *frct);
void					set_new_limits(t_frct *f,int x, int y, double mult);
void					create_fractol(t_frct *frct);
int						julia(double a, double b, t_frct *frct);
int						mouse_julia(int x, int y, t_frct *frct);

#endif
