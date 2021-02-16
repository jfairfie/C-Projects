#include <stdio.h> 
#include <unistd.h> 

void printTest()
{
	printf("Testing printTest()\n");
}

void forkEx()
{
	pid_t child_id = fork();

	if (child_id == 0) {
		printTest(); 
	}
	 else if (child_id > 0)
	{
		printf("Parent Id\n");
	}

}

int main()
{
	forkEx();
	return 0;
}
