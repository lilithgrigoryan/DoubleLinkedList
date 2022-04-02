#include <stdlib.h>
#include "doublelinkedlist.h"

dll* init_dll()
{
    dll* dl = (dll *) malloc(sizeof(dll)*1);
    
    dl->last = NULL;
    dl->root = NULL;

    return dl;
};

node* init_node(void* data)
{
    node* n = (node*) malloc(sizeof(node)*1);

    n->data = data;
    n->next = NULL;
    n->prev = NULL;
};

void add(dll* dl, void* data)
{
    node* new = init_node(data);

    if(NULL == dl->root)
    {
        dl->root = new; 
        dl->last = new;
    } else
    {
        dl->last->next = new;
        new->prev = dl->last;
        dl->last = new;
    }
};

void freedll(dll** dl)
{
    node* c = (*dl)->root;
    while(c != NULL)
    {
        node* t = c->next;
        free(c);
        c = t;
    };
    free(*dl);
    *dl = NULL;
};

void insert_node_after(dll* dl, node* n, void* data)
{
    node* new = init_node(data);
    if(n->next == NULL)
    {
        add(dl, data);
    } else
    {
        node* t = n->next;
        t->prev = new;
        n->next = new;
        new->next = t;
        new->prev = n;
    };
};

void insert_node_before(dll* dl, node* n, void* data)
{
    node* new = init_node(data);
    if(n == dl->root)
    {
        new->next = dl->root;
        (new->next)->prev = new;
        dl->root = new;
    } else
    {
        insert_node_after(dl, n->prev, data);
    };
};

void insert_node(dll* dl, node* n, void* data, int p) 
//p=1 for adding element before and anything else for adding after 
{
    if(p != 1)
    {
        insert_node_after(dl, n, data);
    } else
    {
        insert_node_before(dl, n, data);        
    }
}

void delete_node(dll* dl, node* n)
{
    if(n == dl->root)
    {
        dl->root = n->next;
        (n->next)->prev = NULL;
        free(n);
    } else if(n !=dl->last)
    {
        (n->prev)->next = n->next;
        (n->next)->prev = n->prev;
        free(n);
    } else 
    {
        (n->prev)->next = n->next;
        free(n);
    };
}


