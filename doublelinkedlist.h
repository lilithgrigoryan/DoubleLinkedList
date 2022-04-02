#ifndef _DOUBLELINKEDLIST_
#define _DOUBLELINKEDLIST_

typedef struct _point
{
    float x;
    float y;
} point;

typedef struct _node
{
    void* data;
    struct _node* next;
    struct _node* prev;
} node;

typedef struct doublelinkedlist
{
    node* root;
    node* last; 
} dll;

dll* init_dll();
node* init_node(void*);
void add(dll*, void*);
void freedll(dll**);
void insert_node(dll*, node*, void*, int);
void delete_node(dll*, node*);

#endif 