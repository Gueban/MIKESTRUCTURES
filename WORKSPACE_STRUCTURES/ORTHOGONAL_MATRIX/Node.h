#ifndef NODE_H
#define NODE_H
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <conio.h>
//-----------------------------------------CLASS FOR MATRIXS NODES-------------------------------------------
class Node
{
public:
    Node *righty;
    Node *lefty;
    Node *down;
    Node *up;
    Node();
    Node(int, int, int);
    Node(int);
    ~Node();
    int get_data();
    int get_x();
    int get_y();
private: 
    int data, x, y;
};

#endif // NODE_H
