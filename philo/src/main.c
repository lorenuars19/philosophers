#include "philo.h"


void	*print_msg(void *ptr)
{
	puts((char *)ptr);
	return (ptr);
}

int main(int argc, char *argv[])
{
	pthread_t	thread1;
	pthread_t	thread2;

	char		*msg1 = "Hello from thread 1\n";
	char		*msg2 = "Helllo from thread 2\n";

	int			ret1 = 0;
	int			ret2 = 0;

	if (argc != 3)
		return (0);

	msg1 = argv[1];
	msg2 = argv[2];

	ret1 = pthread_create(&thread1, NULL, print_msg, (void *)msg1);
	ret1 = pthread_create(&thread2, NULL, print_msg, (void *)msg2);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);


	printf("ret1 %d ret2 %d\n", ret1, ret2);
}
