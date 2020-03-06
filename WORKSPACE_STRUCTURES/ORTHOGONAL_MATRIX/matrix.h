#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include "Node.h"
    //-------------------------------------------CLASS FOR MATIX--------------------------------------------------
class matrix
{
public:
    matrix();
    ~matrix();
    Node *head;
    void add(int, int, int);
    void insertcolumn(Node *&, bool, Node *&, Node *&);//columna auxiliar, found, column, new node INSERT A NEW COLUMN
    void insertrow(Node *&, bool, Node *&, Node *&);//row auxiliar, found, row, new node INSERT A NEW ROW
    void insertnodecol(Node *&, bool, Node *&, Node *&);//column auxiliar, found, column, new node INSERT A NODE IN AN EXISTENT COLUMN
    void insertnoderow(Node *&, bool, Node *&, Node *&);//row auxiliar, found, row, new node INSERT A NODE IN AN EXITENT ROW
    void showmatrix();
};

#endif // MATRIX_H
