#include <unistd.h>
#include <iostream>
#include <string> 
#include <cstring> 
#include <sys/wait.h>

#define MAXLENGTH 100 //Number of characters supported in command

using namespace std;

void execArgs(char** command)
{
	pid_t child_pid = fork();

	cout << command[0] << " " << command[1] << endl;

	//Child Process
	if (child_pid == 0)
	{
		wait(NULL);
	} else if (child_pid > 0) { //Parent Process
		execvp(command[0], command);
	} else { //Error forking 
		printf("Failed to fork");
	}

}

void execPiped(char** command, char** command2)
{
	int pipefd[2];
	pid_t child_pid1, child_pid2;

	if (pipe(pipefd) < 0)
	{
		printf("Pipe failed");
	}

	child_pid1 = fork();
	//Child 
	if (child_pid1 == 0)
	{
		close (pipefd[0]);
		dup2(pipefd[1], 1);
		//execlp("ls", "ls", "-l", NULL);
		execvp(command[0], command);
	} else 
	{
		child_pid2 = fork();
		if (child_pid2 == 0)
		{
			close(pipefd[1]);
			dup2(pipefd[0], 0);
			close(pipefd[0]);
			//execlp("wc", "wc", "-l", NULL);
			execvp(command2[0], command2);
		}
	}
	waitpid(child_pid1, 0, 0);
	close(pipefd[1]);
	waitpid(child_pid2, 0, 0);
}

int main(int argc, char *argv[])
{
	int times = 5;

	while(times > 0)
	{

	char* args[MAXLENGTH];
	char command[MAXLENGTH];
	fflush(stdout);
	printf("myshl >> ");
	cin.getline(command, MAXLENGTH);
	string str;
	int index = 0;

	//Parsing user input into command
	for (int i = 0; i < MAXLENGTH; i++)
	{
		if (command[i] == ' ' || command[i] == -1)
		{
			if (str.length() > 0)
			{
				args[index] = strcpy(new char[str.length() + 1], str.c_str());
				str = "";
				index += 1;
			}
		} else if (command[i] != -1) {
			str += command[i];
		}
	}

	args[index] = NULL;

	while (index > 0) 
	{
		index--;

		if (strcmp(args[index], "|") == 0)
		{
			//Process through pipe
			args[index] = NULL;
			char* piped[MAXLENGTH];

			for (int i = index+1; i < MAXLENGTH; i++) {
				piped[i - (index + 1)] = args[i];
				args[i] = NULL;
			}

			execPiped(args, piped);
			break;
		} else if (index == 0)
		{
			//Process traditionally using fork() only
			execArgs(args);
		}
	}
	times--;
	}
	return 0;
}
