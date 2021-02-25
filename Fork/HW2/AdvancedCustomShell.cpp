#include <iostream> 
#include <stdio.h>
#include <unistd.h> 
#include <sys/wait.h> 
#include <string>
#include <string.h>
#include <cstring>

#define MAXLINE 80

using namespace std;

int main(void)
{
	char *args[MAXLINE/2 + 1];
	char *pipeargs[MAXLINE/2 + 1];
	int should_run = 1;
	char command[MAXLINE];
		

	while (should_run)
	{
		
		printf("mysh ");
		
		//Checking for end of script file
		if (cin.eof()) {
			return 0;
		}
		cin.getline(command, MAXLINE/2+1);
		
		//Obtaining tokens from user input 
		char *pch; 
		pch = strtok(command, " ");
		int index = 0;
		int pipIndex = 0;
		int pip = 0;
		
		while (pch != NULL)
		{
			if (strcmp(pch, "|") == 0) {
				pip = 1;
				args[index] = NULL;
				index = 0;
			} else if (pip == 0) {
				args[index] = pch;
				index += 1;
			} else if (pip == 1) {
				pipeargs[index] = pch;
				index += 1;
			}
			
			if (strcmp(pch, "exit") == 0) {
				return 0;
			}
			
			pch = strtok(NULL, " ");
		}
		
		if (pip == 1) {
			pipeargs[index] = NULL;
		}
		
		if (pip == 0) {

			pid_t child_pid = fork();

			//Child Process
			if (child_pid == 0)
			{
				execvp(args[0], args);   
			}
			//Parent Process
			else if (child_pid > 0) 
			{
				wait(NULL); 
			}
			else
			{
				perror("Error -- Failed to fork()"); 
				return 1; 
			}
		} else {
			int pipefd[2];
			pid_t child_pid1, child_pid2;

			if (pipe(pipefd) < 0)
			{
				printf("Pipe Failed");
			}

			child_pid1 = fork();
			if (child_pid1 == 0)
			{
				close(pipefd[0]);
				dup2(pipefd[1], 1);
				//execlp("ls", "ls", "-l", NULL);
				execvp(args[0], args);
			} else {
				child_pid2 = fork();
				if (child_pid2 == 0)
				{
					close(pipefd[1]);
					dup2(pipefd[0], 0);
					close(pipefd[0]);
					//execlp("wc", "wc", "-l", NULL);
					execvp(pipeargs[0], pipeargs);
				}
			}
			waitpid(child_pid1, 0, 0);
			close(pipefd[1]);
			waitpid(child_pid2, 0, 0);
		}
		
	}
		
		
	return 0;
}
