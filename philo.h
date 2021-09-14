/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:12:59 by mrochet           #+#    #+#             */
/*   Updated: 2021/09/14 15:16:12 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_data
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	each_eat;
	int time_start;
}	t_data;

int	error(char *s);
int parse_arg(int ac, char **av);
int atoi_positif(char *s);
size_t ft_strlen(char *s);
int ft_strcmp(char *s1, char *s2);

void print_data(t_data *data);
void fill_data(t_data *data, char **av);
int fonction_time();
#endif
