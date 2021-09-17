/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:12:22 by mrochet           #+#    #+#             */
/*   Updated: 2021/09/15 14:56:54 by mrochet          ###   ########lyon.fr   */
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

void *philo(void *osef)
{
	t_data *data;
	int index_philo;

	data = osef;
	index_philo = data->i_philo;
	data->i_philo++;

	usleep(5000);
	dprintf(1,"coucou je suis le philo %d\n",index_philo);
	return(0);
}
