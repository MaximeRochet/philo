/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:47:56 by mrochet           #+#    #+#             */
/*   Updated: 2021/09/28 18:02:00 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void action(t_philo *d_philo, t_data *data)
{
	while(d_philo->n_eat != data->e_eat && data->die == 0)
	{
		action_eat(d_philo, data);
		if(data->e_eat != -1)
			d_philo->n_eat++;
		if(d_philo->n_eat == data->e_eat && data->die == 0)
			break;
		action_sleep(d_philo, data);
		action_think(d_philo, data);
	}
}

void action_eat(t_philo *d_philo, t_data *data)
{
	if(!before_eat(d_philo, data))
		return;
	//if(data->t_eat > data->t_die)

	pthread_mutex_lock(&data->fork[d_philo->forkl]);
	my_print("%d philo %d has taken fork %d\n", d_philo, data, d_philo->forkl);
	if (data->n_philo % 2 && (data->t_die < since_start(data) + data->t_eat) && data->t_die / 3 < data->t_eat)
	{
		pthread_mutex_lock(&data->print);
		data->die = 1;
	 	printf("%d philo |%d is dead \n", d_philo->last_eat + data->t_die, d_philo->i_philo);
	}
	pthread_mutex_lock(&data->fork[d_philo->forkr]);
	my_print("%d philo %d has taken fork %d\n", d_philo, data, d_philo->forkr);
	my_print("%d philo %d is eating\n", d_philo, data, 0);
	d_philo->last_eat = since_start(data);
	my_usleep(data->t_eat);
	pthread_mutex_unlock(&data->fork[d_philo->forkl]);
	pthread_mutex_unlock(&data->fork[d_philo->forkr]);
	//my_print("%d philo %d drop forks\n", d_philo, data, 0);
}

void action_sleep(t_philo *d_philo, t_data *data)
{
	if(data->t_sleep + data->t_eat > data->t_die)
		print_death(d_philo, data);
	if(data->die == 0)
		my_print("%d philo %d is sleeping\n", d_philo, data, 0 );
	my_usleep(data->t_sleep);
}

void action_think(t_philo *d_philo, t_data *data)
{
	my_print("%d philo %d is thinking\n", d_philo, data, 0);
}

int before_eat(t_philo *d_philo, t_data *data)
{
	
	if(data->n_philo == 1)
		return(print_death(d_philo, data));
	if(data->t_eat > data->t_die || data->t_eat > data->t_die)
		return(print_death(d_philo, data));
/*	else if (data->n_philo % 2 == 0 && data->t_eat >= data->t_sleep)
	{
		if(data->t_eat*2 > data->t_die)
			return(print_death(d_philo, data));
	}
	else if(data->n_philo % 2 == 0 && data->t_eat < data->t_sleep)
	{
		if(data->t_eat + data->t_sleep > data->t_die)
			return(print_death(d_philo, data));
	}
	else if(data->n_philo % 2 == 1 && data->t_eat*2 <= data->t_sleep)
	{
		if(data->t_eat + data->t_sleep > + data->t_die)
			return(print_death(d_philo, data));
	}
	else if(data->n_philo % 2 == 1 && data->t_eat*2 > data->t_sleep)
	{
		if(data->t_eat*3 >  data->t_die)
			return(print_death(d_philo, data));
	}*/
	return(1);
}

