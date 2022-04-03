#ifndef _DOUBLELINKEDLIST_
#define _DOUBLELINKEDLIST_

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
} list;

list* init_dll();
node* init_node(void*);
void add(list*, void*);
void freedll(list**);
void insert_node(list*, node*, void*, int);
void delete_node(list*, node*);

#endif 