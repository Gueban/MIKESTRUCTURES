#include "matrix.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include "Node.h"

Node::Node(){
    //this->data=0;
    this->righty=NULL;
    this->lefty=NULL;
    this->down=NULL;
    this->up=NULL;
}

Node::Node(int d, int px, int py){
        this->data=d;
        this->x=px;
        this->y=py;
        this->righty=NULL;
        this->lefty=NULL;
        this->down=NULL;
        this->up=NULL;
}

Node::Node(int d){
        this->data=d;
        this->righty=NULL;
        this->lefty=NULL;
        this->down=NULL;
        this->up=NULL;
}
int Node::get_data(){return data;}
int Node::get_x(){return x;}
int Node :: get_y(){return y;}
Node::~Node()
{
}

