/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:20:45 by pfichepo          #+#    #+#             */
/*   Updated: 2016/11/17 11:20:37 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV_H
# define RTV_H
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define BUFF_SIZE 16384


typedef struct		s_vector
{
	double				x;
	double				y;
	double				z;
}					t_vector;



typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_light
{
	t_vector		*pos;
	int				color;
}					t_light;

typedef struct		s_sphere
{
	t_vector		*center;
	double			radius;
	int				color;
}					t_sphere;

typedef struct		s_ray
{
	t_vector			*origin;
	t_vector			*direction;
}					t_ray;

typedef struct		s_cam
{
	t_vector			*pos;
	t_vector			*dir;
	t_vector			*right;
	t_vector			*down;
}					t_cam;

typedef struct		s_angle
{
	double			yaw;
	double			pitch;
	double			roll;
}					t_angle;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				w;
	int				h;
	void			*img;
	int				bpp;
	char			*data;
	int				size_line;
	int				endian;
	int				up;
	int				down;
	int				left;
	int				right;

}					t_env;

void				ft_putstr(char const *s);
void				ft_putchar(char c);
void				error(char const *s);
void				errornohalt(char const *s);
unsigned long		creatergb(int r, int g, int b);
int					fastmlx_pixel_put(t_env *env, int x, int y, int color);
int					draw(t_env *env);
int					mousekey(int x, int y, t_env *env);
int					mousebutton(int button, int x, int y, t_env *env);
int					hook_loop(t_env *env);
int					key_release(int keycode, t_env *env);
int					key_press(int keycode, t_env *env);
int					close_hook(t_env *env);
t_vector			*nvector(double x, double y, double z);
t_ray				*nray(t_vector *origin, t_vector *direction);
t_cam				*ncam(t_vector *pos, t_vector *dir, t_vector *right, t_vector *down);
t_cam				*necam(void);
t_vector			*vecnorm(t_vector *vec);
double				vecdot(t_vector *vec1, t_vector *vec2);
t_vector			*veccross(t_vector *vec1, t_vector *vec2);
t_vector			*vecadd(t_vector *vec1, t_vector *vec2);
t_vector			*vecmult(t_vector *vec, double scale);
t_vector 			*vecneg(t_vector *vec);
double				vecmagn(t_vector *vec);
t_sphere			*nsphere(t_vector *center, double radius, int color);
#endif
