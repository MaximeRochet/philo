/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:12:59 by mrochet           #+#    #+#             */
/*   Updated: 2021/09/15 14:07:29 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

typedef struct s_data
{
	int	n_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	e_eat;
	int i_philo;
	int time_start;

	pthread_t *philo;
	pthread_mutex_t *fork;
	pthread_mutex_t *print;
}	t_data;

typedef struct s_philo
{
	
}	t_philo;


int	error(char *s);
int parse_arg(int ac, char **av);
int atoi_positif(char *s);
size_t ft_strlen(char *s);
int ft_strcmp(char *s1, char *s2);

void print_data(t_data *data);
void fill_data(t_data *data, char **av);
int fonction_time();

void start_thread(t_data *data);
void free_data(t_data *data);
void *philo();
#endif
