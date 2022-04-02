#include <stdio.h>
#include <stdlib.h>
#include "doublelinkedlist.h"

void printpoint(node* n)
{
    point* t = (point* )n->data;
    printf("(%f, %f) \n", (*t).x, (*t).y);
}

void printdll(dll* dl)
{
    if(dl == NULL){
        printf("The pointer is free. \n");
    }else
    {    
        node* c = dl->root;
        while(c != NULL)
        {
            printpoint(c);
            c = c->next;
        };
        printf("\n");
    };
}

void printdllinv(dll* dl)
{
    if(dl == NULL){
        printf("The pointer is free. \n");
    }else
    {    
        node* c = dl->last;
        while(c != NULL)
        {
            printpoint(c);
            c = c->prev;
        };
        printf("\n");
    };
}

int main()
{
    point p1; point p2; point p3; point p4;
    dll* dl;

    dl = init_dll();

    p1.x = 1; p1.y = 3;
    p2.x = -3; p2.y = 9;

    p3.x = p1.x + p2.x;
    p3.y = p1.y + p2.y;

    p4.x = p3.x + p2.x;
    p4.y = p3.y + p2.y;

    add(dl, &p1);
    add(dl, &p2);
    add(dl, &p3);
    add(dl, &p4);

    //freedll(&dl);
    insert_node(dl, (dl->root), &p2, 1);

    delete_node(dl, (dl->last));    
    }