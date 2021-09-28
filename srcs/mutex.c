/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:12:22 by mrochet           #+#    #+#             */
/*   Updated: 2021/09/28 18:06:37 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void start_thread(t_data *data)
{
	int i = 0;

	data->philo = malloc(sizeof(pthread_t)*data->n_philo);
	data->time_start = get_time();
	while(i < data->n_philo)
	{
		pthread_create(data->philo + i, NULL, philo, data);
		usleep(50);
		i++;
	}
	while (data->die != 1 && data->d_philo->n_eat != data->e_eat)
		;
	pthread_join(*data->philo, NULL);
}

void free_data(t_data *data)
{
	//free mutex
	free(data);
}

void init_forks(t_philo *d_philo, t_data *data)
{
	if(d_philo->i_philo == data->n_philo)
		d_philo->forkl = 0;
	else 	
		d_philo->forkl = d_philo->i_philo;
	d_philo->forkr = d_philo->i_philo - 1;
	d_philo->n_eat = 0;
	d_philo->last_eat = 0;
}

void *philo(void *arg)
{
	t_data *data;
	t_philo d_philo;
	
	data = arg;
	data->d_philo = &d_philo;
	data->d_philo->i_philo = data->tmp_i_philo;
	data->tmp_i_philo++;
	init_forks(&d_philo, data);
	//	print_philo(&d_philo);
	action(&d_philo, data);

	return(0);
}

void my_print(char *str, t_philo *d_philo, t_data *data, int fork)
{
	pthread_mutex_lock(&data->print);
	if(data->die == 0)
		printf(str, since_start(data), d_philo->i_philo, fork);
	pthread_mutex_unlock(&data->print);
}

int print_death(t_philo *d_philo, t_data *data)
{
	my_usleep(500);
	pthread_mutex_lock(&data->print);
	if(data->die == 0)
		printf("%d philo %d died\n",data->t_end + data->t_die + 1, d_philo->i_philo);
	data->die = 1;
	pthread_mutex_unlock(&data->print);
	return(0);
}
