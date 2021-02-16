#include <stdio.h> 
#include <unistd.h> 

void forkEx() 
{
	int y = 4; 

	if (fork() == 0)
	{
		printf("Child has y = %d\n", ++y); 
	}
	else 
	{
		printf("Parent has y = %d\n", --y); 
	}
}

int main() 
{
	forkEx(); 
	return 0; 
}
