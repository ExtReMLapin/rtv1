/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:27:37 by pfichepo          #+#    #+#             */
/*   Updated: 2016/11/17 09:25:22 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rtv1.h"
#include "minilibx_macos/mlx.h"

int				key_press(int keycode, t_env *env)
{
	if (keycode == KEY_RIGHT)
		env->right = 1;
	if (keycode == KEY_LEFT)
		env->left = 1;
	if (keycode == KEY_UP)
		env->up = 1;
	if (keycode == KEY_DOWN)
		env->down = 1;
	return (1);
}

int				key_release(int keycode, t_env *env)
{
	if (keycode == KEY_RIGHT)
		env->right = 0;
	if (keycode == KEY_LEFT)
		env->left = 0;
	if (keycode == KEY_UP)
		env->up = 0;
	if (keycode == KEY_DOWN)
		env->down = 0;
	return (1);
}

int				close_hook(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	exit(EXIT_SUCCESS);
	return (1);
}