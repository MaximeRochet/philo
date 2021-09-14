/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:36:22 by mrochet           #+#    #+#             */
/*   Updated: 2021/09/14 11:36:45 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t ft_strlen(char *s)
{
	char *tmp;

	tmp = s;
	while(*s++)
		;
	return (s - tmp);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1++ == *s2++)
		;
	return  (*s1 - *s2);
}
