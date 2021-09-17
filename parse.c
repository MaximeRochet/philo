/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:03:10 by mrochet           #+#    #+#             */
/*   Updated: 2021/09/17 15:44:18 by mrochet          ###   ########lyon.fr   */
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
	int i;

	i = 0;
	data->n_philo = atoi_positif(av[1]);
	data->t_die = atoi_positif(av[2]);
	data->t_eat = atoi_positif(av[3]);
	data->t_sleep = atoi_positif(av[4]);
	data->e_eat = 0;
	if(av[5])
		data->e_eat = atoi_positif(av[5]);
	data->tmp_i_philo = 1;
	print_data(data);
	dprintf(1,"un\n");
	data->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
			* data->n_philo);
	while(i < data->n_philo)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
	dprintf(1,"deux\n");

}

void print_data(t_data *data)
{
	printf("DATA \n___________________________\n");
	printf("nb philo = %d\n", data->n_philo);
	printf("time to die = %d\n", data->t_die);
	printf("time to eat = %d\n", data->t_eat);
	printf("time to sleep = %d\n", data->t_sleep);
	if(data->e_eat)
		printf("each eat = %d\n",data->e_eat);
	printf("time = %d\n",data->time_start);
	printf("___________________________\n");
}

void print_data(t_philo *philo)
{
	printf("PHILO \n___________________________\n");
	printf("fork1 = %d\n", philo->fork1);
	printf("fork2 = %d\n", philo->fork2);
	printf("id philo = %d\n",philo->i_philo);
	printf("___________________________\n");
}
