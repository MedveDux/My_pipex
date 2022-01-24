#include <stdio.h>
#include <unistd.h>

int main()
{
	int	fork1;
	printf("Hello %d\n", getpid());
	fork1 = fork();
	if (fork1 == 0)
	printf("Hello %d\n", getpid());
	fork();
	printf("Hello %d\n", getpid());
	
}