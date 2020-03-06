#include "matrix.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include "Node.h"

using namespace std;

    //-------------------------------------------CLASS FOR MATIX--------------------------------------------------
matrix::matrix()
{
    head=new Node(0);
}

//--------------------------------------------ADD A COLUMN METHOD----------------------------------------

void matrix::insertcolumn(Node *&colaux, bool found, Node *&column, Node *&nuevo){
        colaux=head;
        found=true;
        while(found){
            colaux = colaux->righty;
            if(colaux->righty==NULL){
                found = false;
                colaux->righty = column;
                column->lefty=colaux;
                nuevo->up=column;
                column->down=nuevo;
            }else if(colaux->get_data() > column->get_data()){
                found=false;
                colaux->lefty->righty=column;
                column->lefty=colaux->lefty;
                column->righty=colaux;
                colaux->lefty=column;
                //debo ingresar el nodo de columna
                nuevo->up=column;
                column->down=nuevo;
                
            }
        }
}

//--------------------------------------------ADD A ROW METHOD-------------------------------------------

void matrix::insertrow(Node *&rowaux, bool found, Node *&row, Node *&nuevo){
    found = true;
    rowaux=head;
    while(found){
        rowaux = rowaux->down;
        if(rowaux->down==NULL){
            found = false;
            rowaux->down=row;
            row->up=rowaux;
            nuevo->lefty=row;
            row->righty=nuevo;
        }else if(rowaux->get_data() > row->get_data()){
            found=false;
            rowaux->up->down=row;
            row->up=rowaux->up;
            row->down=rowaux;
            rowaux->up=row;
            //debo ingresar el nodo de la fila
            nuevo->lefty=row;
            row->righty=nuevo;
            
        }
    }
}

//-------------------------------------------ADD A NODE IN AN EXISTENT COLUMN-------------------------------
 void matrix::insertnodecol(Node *&colaux, bool found, Node *&column, Node *&nuevo){
        found=true;
        Node *ctemp = colaux;
        while(found){
            ctemp = ctemp->down;
            if(ctemp->down==NULL){
                found = false;
                ctemp->down = nuevo;
                nuevo->up = ctemp;
            }else if(ctemp->get_x()>nuevo->get_x()){
                found = false;
                nuevo->down=ctemp;
                nuevo->up = ctemp->up;
                ctemp->up->down=nuevo;
                ctemp->up=nuevo;
            }
        }
 }

//-------------------------------------------ADD A NODE IN AN EXISTENT ROW---------------------------------
void matrix::insertnoderow(Node *&rowaux, bool found, Node *&row, Node *&nuevo){
    found=true;
    Node *rtemp = rowaux;
    while(found){
        rtemp = rtemp->righty;
        if(rtemp->righty==NULL){
            found = false;
            rtemp->righty = nuevo;
            nuevo->lefty = rtemp;
        }else if(rtemp->get_y()>nuevo->get_y()){
            found = false;
            nuevo->righty=rtemp;
            nuevo->lefty = rtemp->lefty;
            rtemp->lefty->righty=nuevo;
            rtemp->lefty=nuevo;
        }
    }
}

//--------------------------------------------ADD A NODE METHOD--------------------------------------------
void matrix::add(int value, int x, int y){
    Node *nuevo = new Node(value, x, y);
    Node *column =  new Node(y);
    Node *row = new Node(x);
    if(head->righty==NULL && head->down==NULL){
        column->down = nuevo;
        row->righty = nuevo;
        nuevo->up= column;
        nuevo->lefty=row;
        head->righty = column;
        column->lefty = head;
        head->down = row;
        row->up=head;
        printf("A NEW NODE HAS BEEN INSERTED\n");
    }
    else{
        Node *colaux=head;
        Node *rowaux=head;
        bool found=true, colfound=false, rowfound = false;
        while(found){
            colaux = colaux->righty;
            if(colaux==NULL){
                found=false;
            }else if(colaux->get_data()==column->get_data()){
                found=false;
                colfound =true;
            }
        }
        found=true;
        while(found){
            rowaux = rowaux->down;
            if(rowaux==NULL){
                found=false;
            }else if(rowaux->get_data()==row->get_data()){
                found=false;
                rowfound =true;
            }
        }
        if(colfound == false && rowfound == false){
            insertcolumn(colaux, found, column, nuevo);
            insertrow(rowaux, found, row, nuevo);
            printf("A NEW NODE HAS BEEN INSERTED\n");
        }else if(colfound == false && rowfound == true){
            insertcolumn(colaux, found, column, nuevo);
            insertnoderow(rowaux, found, row, nuevo);
            printf("A NEW NODE HAS BEEN INSERTED\n");
        }else if(colfound == true && rowfound == false){
            insertrow(rowaux, found, row, nuevo);
            insertnodecol(colaux, found, column, nuevo);
            printf("A NEW NODE HAS BEEN INSERTED\n");
        }else if(colfound == true && rowfound == true){
            insertnoderow(rowaux, found, row,nuevo);
            insertnodecol(colaux, found, column, nuevo);
            printf("A NEW NODE HAS BEEN INSERTED\n");
        }
        
        
    }
}




void matrix::showmatrix(){
    Node *raux=head;
    Node *caux=head;
    while(raux!=NULL){
        while(caux!=NULL){
            cout<<"<"<<caux->get_data()<<">";
            caux=caux->righty;
        }
        cout<<"\n";
        raux=raux->down;
        caux=raux;
    }
}

matrix::~matrix()
{
}

