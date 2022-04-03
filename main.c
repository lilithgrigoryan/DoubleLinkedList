#include <stdio.h>
#include <stdlib.h>
#include "doublelinkedlist.h"

typedef struct _point
{
    float x;
    float y;
} point;

void point_print(node* n)
{
    point* t = (point* )n->data;
    printf("(%f, %f) \n", (*t).x, (*t).y);
}

void list_print(list* dl)
{
    if(dl == NULL){
        printf("The pointer is free. \n");
    }else
    {    
        node* c = dl->root;
        while(c != NULL)
        {
            point_print(c);
            c = c->next;
        };
        printf("\n");
    };
}

void list_print_inv(list* dl)
{
    if(dl == NULL){
        printf("The pointer is free. \n");
    }else
    {    
        node* c = dl->last;
        while(c != NULL)
        {
            point_print(c);
            c = c->prev;
        };
        printf("\n");
    };
}

int main()
{
    point p1; point p2; point p3; point p4;
    list* dl;

    dl = list_init();

    p1.x = 1; p1.y = 3;
    p2.x = -3; p2.y = 9;

    p3.x = p1.x + p2.x;
    p3.y = p1.y + p2.y;

    p4.x = p3.x + p2.x;
    p4.y = p3.y + p2.y;

    list_add(dl, &p1);
    list_add(dl, &p2);
    list_add(dl, &p3);
    list_add(dl, &p4);

    //list_free(&dl);
    list_insert(dl, (dl->root), &p2, 1);

    list_remove(dl, (dl->last));

    list_print(dl);
    }