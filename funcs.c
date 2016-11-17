/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:18:44 by pfichepo          #+#    #+#             */
/*   Updated: 2016/11/17 09:25:54 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rtv1.h"

void				ft_putchar(char c)
{
	write(1, &c, 1);
}

void				ft_putstr(char const *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void				error(const char *s)
{
	ft_putstr("\033[1;31m");
	ft_putstr("[FATAL ERROR] : ");
	ft_putstr(s);
	ft_putstr("\033[0m");
	ft_putchar('\n');
	exit(EXIT_FAILURE);
}

void				errornohalt(const char *s)
{
	ft_putstr("\033[1;31m");
	ft_putstr("[SPOOKY ERROR] : ");
	ft_putstr(s);
	ft_putstr("\033[0m");
	ft_putchar('\n');
}
