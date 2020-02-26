#include <stdio.h>
#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

class Node{
  public: 
    int data;
    Node *up;
    Node *righty;
    Node *lefty;
    Node *down;
};

int main()
{
	printf("hello world\n");
    
    getch();
	return 0;
}
