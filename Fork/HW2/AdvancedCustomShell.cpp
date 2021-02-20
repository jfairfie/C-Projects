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

execPiped(char** command)
{
	int pipefd[2];
	pid_t child_pid1, child_pid2;

	if (pipe(pipefd) < 0)
	{
		printf("Pipe failed");
	}

	p1 = fork();
	//Child 
	if (child_pid1 == 0)
	{

	}
}

int main(int argc, char *argv[])
{
	char* args[MAXLENGTH];
	char command[MAXLENGTH];

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
		} else if (index == 0)
		{
			//Process traditionally using fork() only
			execArgs(args);
		}
	}

	return 0;
}
