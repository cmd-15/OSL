#include<iostream>
#include<thread>
using namespace std;

bool Flag[2]={false,false};
int turn;

void process0(){
    Flag[0] = true;
    turn = 1;

    while(Flag[1] && turn==1);
    cout << "process0 is in critical section" << endl;

    Flag[0] = false;
    }

void process1(){
    Flag[1] = true;
    turn = 0;

    while(Flag[0] && turn==0);
    cout << "process 1 is in critical section" << endl;

    Flag[1] = false;
    }

int main(){
    thread t1(process0);
    thread t2(process1);

    t1.join();
    t2.join();

    return 0;
}