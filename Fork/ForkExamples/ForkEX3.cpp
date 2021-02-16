#include <stdio.h> 
#include <unistd.h> 

int main(int argc, char **argv)
{
	printf("--beginning of program\n");
	int counter = 0; 
	pid_t pid= fork(); 

	if (pid == 0) {
		for (int i = 0; i < 5; ++i) {
			printf("child process: counter=%d\n", ++counter);
		}

	} else if (pid > 0) {
		for (int j = 0; j < 5; ++j) {
			printf("parent process: counter=%d\n", ++counter); 
		}
	} else {
		printf("fork() failed!\n"); 
		return 1; 
	}

	printf("-- end of program--\n"); 
	return 0; 
}

