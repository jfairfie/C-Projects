#include <iostream> 
#include <stdio.h>
#include <unistd.h> 
#include <sys/wait.h> 
#include <string>
#include <cstring>

#define MAXLINE 80

using namespace std; 

int main(void)
{
	char *args[MAXLINE/2 + 1];
	int should_run = 1;

	while (should_run) 
	{
		printf("mysh ");
		fflush(stdout);

		//Recieving Input from User
		string str;  

		getline(cin, str)
		
		int index = 0;
		int k = 0;

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ' || i == str.length() - 1)
			{
				if (i == str.length() - 1)
				{
					i++;
				}
				string str2 = str.substr(k, i); 
				cout << str2 << endl; 
				args[index] = strcpy(new char[str2.length() + 1], str2.c_str());
				k = i+1;
				index += 1;
			}
		}

		args[index] = NULL;

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
		}
	}

	return 0; 
}
