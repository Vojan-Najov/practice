#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main()
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		execlp("ls", "ls", "-l", "-a", "/var",NULL);
		perror("ls");
		exit(1);
	}
	wait(NULL);
	printf("Ok\n");
	return (0);
}
