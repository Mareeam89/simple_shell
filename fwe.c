#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	pid_t child_pid;
	int status;
	int i;
	char *args[] = {"ls", "-l", "/tmp", NULL};

	for (i = 1; i <= 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error;");
			return (i);
		}
	}

	if (child_pid == 0)
	{
		execve("/usr/bin/ls", args, NULL);
		perror("Error:");
		exit(i);
	}
	else
	{
		/*parent*/
		wait (&status);
	}
}
