/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:12:59 by mrochet           #+#    #+#             */
/*   Updated: 2021/09/28 16:10:54 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

typedef struct s_philo
{
	int forkr;
	int forkl;
	int i_philo;
	int n_eat;
	int last_eat;

}	t_philo;

typedef struct s_data
{
	int	n_philo;
	int tmp_i_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	e_eat;
	int time_start;
	int die;
	int t_end;
	pthread_t *philo;
	pthread_mutex_t *fork;
	pthread_mutex_t print;
	t_philo *d_philo;
}	t_data;

int	error(char *s);
int parse_arg(int ac, char **av);
int atoi_positif(char *s);
size_t ft_strlen(char *s);
int ft_strcmp(char *s1, char *s2);

void print_data(t_data *data);
void print_philo(t_philo *philo);
void fill_data(t_data *data, char **av);
int fonction_time();

void action(t_philo *d_philo, t_data *data);
void action_eat(t_philo *d_philo, t_data *data);
void action_sleep(t_philo *d_philo, t_data *data);
void action_think(t_philo *d_philo, t_data *data);

int get_time(void);
int since_start(t_data *data);
void my_usleep(int sleep);
void my_print(char *str, t_philo *philo, t_data *data, int fork);
int print_death(t_philo *d_philo, t_data *data);

int before_eat(t_philo *d_philo, t_data *data);
void start_thread(t_data *data);
void free_data(t_data *data);
void *philo();

#endif
