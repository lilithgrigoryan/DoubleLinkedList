#ifndef _DOUBLELINKEDLIST_
#define _DOUBLELINKEDLIST_

#include <stdlib.h>

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

list* list_init();
void list_add(list*, void*);
void list_free(list**);
void list_insert(list*, node*, void*);
void list_remove(list*, node*);

#endif //!_DOUBLELINKEDLIST_