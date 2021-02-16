#include <stdio.h> 
#include <unistd.h> 

void printArgv(int argc, char** argv)
{
	pid_t child_pid = fork();

	//Child Process
	if (child_pid == 0)
	{
		for (int i = 1; i < argc; i++) {
			printf("%s\n", argv[i]);
		}
	}
	//Parent Process
	else if (child_pid > 0)
	{
		printf("Parent Process\n");
	}
	else
	{
		printf("Error");
	}
}

int main(int argc, char** argv)
{
	printArgv(argc, argv);

	return 0;
}
