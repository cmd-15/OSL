#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
using namespace std;

int main(){
    int pid = fork();

    if (pid<0){
        cout << "process creation failed";
        return 1;
    }

    else if(pid==0){
        cout << "process created successfully" << endl;
        cout << "get process Id: " << getpid() << endl;
        cout << "get parent process ID: " << getppid() << endl;

        execl("/bin/ls", "ls", NULL);

        cout << "exec failed";

        exit(0);
    }
    else{
        wait(NULL);

        cout << "\nParent Process Running" << endl;
        cout << "Parent PID: " << getppid() << endl;
        cout << "Child Process Completed" << endl;
    }
    return 0;
}