/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 09:43:36 by pfichepo          #+#    #+#             */
/*   Updated: 2016/11/17 11:23:48 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rtv1.h"

t_vector *nvector(double x, double y, double z)
{
	t_vector *vec;

	vec = (t_vector*)malloc(sizeof(t_vector));
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}


t_ray *nray(t_vector *origin, t_vector *direction)
{
	t_ray *ray;

	ray = (t_ray*)malloc(sizeof(t_ray));
	ray->origin = origin;
	ray->direction = direction;
	return (ray);
}

t_cam *ncam(t_vector *pos, t_vector *dir, t_vector *right, t_vector *down)
{
	t_cam *cam;

	cam = (t_cam*)malloc(sizeof(t_cam));
	cam->pos = pos;
	cam->dir = dir;
	cam->right = right;
	cam->down = down;
	return (cam);
}

t_sphere *nsphere(t_vector *center, double radius, int color)
{
	t_sphere *shpere;

	shpere = (t_sphere*)malloc(sizeof(t_sphere));
	shpere->color = color;
	shpere->center = center;
	shpere->radius = radius;
	return (shpere);
}


t_cam *necam(void)
{
	t_cam *cam;

	cam = ncam(nvector(0,0,0),nvector(0,0,1),nvector(0,0,0),nvector(0,0,0));
	return (cam);
}

double vecmagn(t_vector *vec)
{
	double x;
	double y;
	double z;
	double result;

	x = vec->x;
	y = vec->y;
	z = vec->z;
	result = sqrt((x*x) + (y*y) + (z*z));
	return (result);
}

t_vector *vecnorm(t_vector *vec)
{
	double magn;
	magn = (vecmagn(vec));
	return (nvector(vec->x/magn,vec->y/magn,vec->z/magn ));
}

t_vector *vecneg(t_vector *vec)
{
	return (nvector(-(vec->x), -(vec->y), -(vec->z)));
}

double vecdot(t_vector *vec1, t_vector *vec2)
{
	return (  (vec1->x) * (vec2->x) + (vec1->y) * (vec2->y) + (vec1->z) * (vec2->z)  );
}

t_vector *veccross(t_vector *vec1, t_vector *vec2)
{
	double x;
	double y;
	double z;

	x = (vec1->y) * (vec2->z) - (vec1->z) * (vec2->y);
	y = (vec1->z) * (vec2->x) - (vec1->x) * (vec2->z);
	z = (vec1->x) * (vec2->y) - (vec1->y) * (vec2->x);

	return ( nvector(x,y,z));
}


t_vector *vecadd(t_vector *vec1, t_vector *vec2)
{
	return (  nvector((vec1->x) + (vec2->x) , (vec1->y) + (vec2->y),(vec1->z) + (vec2->z)  ));
}

t_vector *vecmult(t_vector *vec1, double scale)
{
	return (  nvector(vec1->x * scale, vec1->y * scale, vec1->z * scale  ));	
}

