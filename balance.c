#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

#define ARRAY_SIZE 10
#define WORKERS_COUNT 3
#define PAUSE_LENGTH 1

#ifndef PROTECTION
#define PROTECTION 1
#endif

struct	thread_start_data
{
	unsigned int	randseed;
	int				*array;
#if PROTECTION == 1
	pthread_mutex_t	*arr_mutex;
	sem_t			*data_sem;
#endif
};

static void	*worker_thread(void *v_data);

int			main(void)
{
	int							i;
	int							the_array[ARRAY_SIZE];
	struct thread_start_data	tsdata;
	pthread_t					thr;
#if PROTECTION == 1
	pthread_mutex_t				arr_mutex = PTHREAD_MUTEX_INITIALIZER;
	//pthread_mutex_t				arr_mutex;
	//pthread_mutex_init(&arr_mutex, NULL);
	sem_t						tsd_sem;
#endif

	for (i = 0; i < ARRAY_SIZE; ++i)
	{
		the_array[i] = 0;
	}
	tsdata.randseed = time(NULL);
	tsdata.array = the_array;
#if PROTECTION == 1
	tsdata.arr_mutex = &arr_mutex;
	tsdata.data_sem = &tsd_sem;
	sem_init(&tsd_sem, 0, 0);
#endif
	for(i = 0; i < WORKERS_COUNT; ++i)
	{
		tsdata.randseed++;
		pthread_create(&thr, NULL, worker_thread, &tsdata);
#if PROTECTION == 1
		sem_wait(&tsd_sem);
#endif
	}
	while (1)
	{
		int	sum;
#if PROTECTION == 1
		pthread_mutex_lock(&arr_mutex);
#endif
		printf("main mutex lock\n");
		sum = 0;
		for (i = 0; i < ARRAY_SIZE; i++)
		{
			sum += the_array[i];
		}
		printf("%d ", sum);
		for (i = 0; i < ARRAY_SIZE; ++i)
		{
			printf("%c%d", i ? ',' : '(', the_array[i]);
		}
		printf(")\n");
#if PROTECTON == 1
		pthread_mutex_unlock(&arr_mutex);
#endif
		printf("main mutex unlock\n");
		sleep(PAUSE_LENGTH);
	}
	return (0);
}

static void	*worker_thread(void *v_data)
{
	struct thread_start_data	*data;
	unsigned int				randseed;
	int							*array;

	data = (struct thread_start_data *) v_data;
	randseed = data->randseed;
	array = data->array;
#if PROTECTION == 1
	pthread_mutex_t	*arr_mutex = data->arr_mutex;
	sem_t			*data_sem = data->data_sem;
	sem_post(data_sem);
#endif
	while (1)
	{
		int	idx1, idx2;
		idx1 = rand_r(&randseed) % ARRAY_SIZE;
		idx2 = rand_r(&randseed) % ARRAY_SIZE;
		if (idx1 == idx2)
			continue;
#if PROTECTION == 1
		pthread_mutex_lock(arr_mutex);
#endif
		printf("thread %lu mutex lock\n", pthread_self());
		array[idx1]++;
		array[idx2]--;
#if PROTECTION == 1
		pthread_mutex_unlock(arr_mutex);
#endif
		printf("thread %lu mutex unlock\n", pthread_self());
	}
	return (NULL);
}
