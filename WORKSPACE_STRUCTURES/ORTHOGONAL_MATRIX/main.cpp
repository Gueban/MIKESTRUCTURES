#include <stdio.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include "matrix.h"

using namespace std;

int main()
{
	matrix obj;
    
    int val=0, x=0, y=0;
    char salir = 'n';
    while(salir=='n'){
        printf("AN INTEGER NUMBER MA FELLA\n");
        cin>>val;
        printf("AN X POSITION MA CRACK\n");
        cin>>x;
        printf("AN Y POSITION MA MACHO\n");
        cin>>y;
        obj.add(val, x, y);
        printf("HEY HABITUE OF MY CREATIONS, WANNA LEAVE?\n");
        salir=getch();
    }
    
    obj.showmatrix();
    
    getch();
	return 0;
}
