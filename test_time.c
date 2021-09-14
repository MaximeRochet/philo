#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

struct timeval begin_time;

long	set_timestamp(void)
{
	struct timeval	current_time;
	long			timestamp;

	gettimeofday(&current_time, NULL);

	printf("current_time = __________________  \n\t\t| sec = %ld\n\t\t| usec =  %d\n\t\t_________________\n", current_time.tv_sec, current_time.tv_usec);
	
	timestamp = ((current_time.tv_sec* 1000000 + current_time.tv_usec) - \
	(begin_time.tv_sec * 1000000 + begin_time.tv_usec)) / 1000;
	return (timestamp);
}

int fonction_time()
{
	long  time;

	gettimeofday(&begin_time, NULL);
	printf("%ld \n", begin_time.tv_sec);
	while(1)
	{
		usleep(500000);
		time = set_timestamp();
		printf("time en millier de usec= %ld\n\n", time);
	}
}
