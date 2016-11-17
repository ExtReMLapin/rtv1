/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcextmain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 18:38:59 by pfichepo          #+#    #+#             */
/*   Updated: 2016/11/17 11:21:53 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rtv1.h"
#include "minilibx_macos/mlx.h"

int			fastmlx_pixel_put(t_env *env, int x, int y, int color)
{
	int h;
	int w;

	h = env->h;
	w = env->w;
	if ((y < 0) || (x < 0))
		return (0);
	if ((y + 1 > h) || (x + 1 > w))
		return (0);
	*(unsigned int*)(env->data + (x * 4) + (env->size_line * y)) = color;
	return (1);
}

int draw(t_env *env)
{
	int x;
	int y;

	x = 0;
	mlx_clear_window(env->mlx, env->win);
	t_vector *vecx = nvector(1,0,0);
	t_vector *vecy = nvector(0,1,0);
	t_vector *vecz = nvector(0,0,1);
	t_vector *O = nvector(0,0,0);

	t_vector *campos = nvector(3,1.5, -4);

	t_vector *look_at = nvector(0,0,0);
	t_vector *diff_btw = nvector(campos->x - look_at->x, campos->y - look_at->y, campos->z - look_at->z);
	t_vector *camdir = vecnorm((vecneg(diff_btw)));
	t_vector *camright = vecnorm(veccross(vecy, camdir));
	t_vector *camdown = veccross(camright, camright);
	t_cam *cam = ncam(campos, camdir, camright, camdown);
	int color_white = 0xffffff;
	int grey = 0x777777;
	int green = 0x007700;
	int black = 0x000000;

	t_light *light = (t_light*)malloc(sizeof(t_light));
	light->pos = nvector(-7,10,-10);
	light->color = color_white;


	t_sphere *sphere = nsphere(O, 1, green);

	/*while (x < env->w)
	{
		y = 0;
		while (y < env->h)
		{
			fastmlx_pixel_put(env, x,y,  );
			y++;
		}

		x++;
	}*/


	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);

	return (1);
}