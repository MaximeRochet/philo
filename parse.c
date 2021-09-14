/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:03:10 by mrochet           #+#    #+#             */
/*   Updated: 2021/09/14 15:17:09 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	atoi_positif(char *s)
{
	int ret;
	int tmp;

	ret = 0;
	while (*s)
	{
		tmp = ret;
		if (*s < '0' || *s > '9')
			return (error("all arguments must be positive ints"));
		else
			ret = ret * 10 + (*s - 48);
		if (ret < 0)
			return (error("all arguments must be positive ints"));
		s++;
	}
	return (ret);
}

int parse_arg(int ac, char **av)
{
	if(ac < 5 || ac > 6)
		return (error("wrong number of argument"));
	while(ac != 1)
	{
		if(atoi_positif(av[ac - 1]) < 0)
			return(-1);
		ac--;
	}
	return(0);
} 

int error(char *s)
{
	printf("%s\n", s);
	return (-1);
}

void fill_data(t_data *data, char **av)
{
	data->number_of_philosophers = atoi_positif(av[1]);
	data->time_to_die = atoi_positif(av[2]);
	data->time_to_eat = atoi_positif(av[3]);
	data->time_to_sleep = atoi_positif(av[4]);
	data->each_eat = 0;
	if(av[5])
		data->each_eat = atoi_positif(av[5]);
	data->time = gettimeofday(&begin-time, NULL);
}
void print_data(t_data *data)
{
	printf("DATA \n___________________________\n");
	printf("nb philo = %d\n", data->number_of_philosophers);
	printf("time to die = %d\n", data->time_to_die);
	printf("time to eat = %d\n", data->time_to_eat);
	printf("time to sleep = %d\n", data->time_to_sleep);
	if(data->each_eat)
		printf("each eat = %d\n",data->each_eat);
	printf("time = %d\n",data->time);
	printf("___________________________\n");
}
