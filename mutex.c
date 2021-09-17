/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:12:22 by mrochet           #+#    #+#             */
/*   Updated: 2021/09/17 15:44:15 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void start_thread(t_data *data)
{
	int i = 0;
	void **ret_thread;

	dprintf(1, "1\n");

	data->philo = malloc(sizeof(pthread_t)*data->n_philo);

	dprintf(1, "2\n");
	while(i < data->n_philo)
	{
		dprintf(1, "3\n");
		pthread_create(data->philo + i, NULL, philo, data);
		usleep(50);
		i++;
	}
	dprintf(1, "1\n");
	pthread_join(*data->philo, NULL);
	dprintf(1, "1\n");
}

void free_data(t_data *data)
{
	free(data->philo);
}

init_forks()
{
	
}

void *philo(void *arg)
{
	t_data *data;
	t_philo d_philo;
	int index_philo;
	
	data = arg;

	data->d_philo = &d_philo;

	data->d_philo->i_philo = data->tmp_i_philo;
	data->tmp_i_philo++;

	dprintf(1,"coucou je suis le philo %d\n",d_philo.i_philo);
	usleep(20);
	dprintf(1,"coucou je suis le philo %d\n",d_philo.i_philo);
	return(0);
}
