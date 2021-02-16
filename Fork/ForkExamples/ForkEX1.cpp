#include <stdio.h> 
#include <unistd.h> 

void forkEx()
{
	if (fork() == 0) 
	{
		printf("This is the Child\n"); 
	}
	else 
	{
		printf("This is the Parent\n"); 
	}
}

int main()
{
	forkEx();
	return 0;
}
