#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include "philo.h"

//struct timeval begin_time;

int	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

int since_start(t_data *data)
{
	int time;

	time = get_time();
	return(time - data->time_start);
}

void	my_usleep(int sleep)
{
	int	time;

	time = get_time();
	while (1)
	{
		if (get_time() - time >= sleep)
			break ;
		usleep(20);
	}
}
