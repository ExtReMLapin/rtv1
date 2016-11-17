/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:07:38 by pfichepo          #+#    #+#             */
/*   Updated: 2016/11/17 09:29:23 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rtv1.h"
#include "minilibx_macos/mlx.h"

static int					envint(t_env *env)
{
	env->w = 1600;
	env->h = 1080;
	return (1);
}

static void					checkmlx(t_env *env)
{
	env->mlx = mlx_init();
	if (!(env->mlx))
		error("FAILED TO INIT MLX/MAYBE LINKING TO X11 SERVER");
	env->win = mlx_new_window(env->mlx, env->w, env->h, "RTV1");
	if (!(env->win))
		error("FAILED TO CREATE X11 WINDOW");
	env->img = mlx_new_image(env->mlx, env->w, env->h);
	if (!(env->img))
		error("FAILED TO CREATE IMG");
	env->data = mlx_get_data_addr(env->img, &env->bpp, \
		&env->size_line, &env->endian);
	if (!(env->data))
		error("FAILED TO CREATE DATA");
}

static void					initenv(t_env *env)
{
	envint(env);
	checkmlx(env);
}

int							main(void)
{
	t_env *env;

	env = (t_env *)malloc(sizeof(t_env));
	initenv(env);
	mlx_expose_hook(env->win, draw, env);
	mlx_hook(env->win, 2, (1L << 0), key_press, env);
	mlx_hook(env->win, 3, (1L << 1), key_release, env);
	mlx_hook(env->win, 17, (1L << 17), close_hook, env);
	//mlx_loop_hook(env->mlx, hook_loop, env);
	mlx_do_key_autorepeatoff(env->mlx);
	mlx_loop(env->mlx);
	exit(1);
	return (1);
}
