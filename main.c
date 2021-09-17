/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:06:59 by mrochet           #+#    #+#             */
/*   Updated: 2021/09/15 14:56:21 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h" 

int main(int ac, char **av)
{
	t_data data;

	if (parse_arg(ac,av) == -1)
		return(-1);
	fill_data(&data, av);
	print_data(&data);
	start_thread(&data);
	usleep(5000);
	return(0);
}
