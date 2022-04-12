#include "doublelinkedlist.h"

list* list_init()
{
    list* dl = (list *) malloc(sizeof(list));
    
    dl->last = NULL;
    dl->root = NULL;

    return dl;
};

node* node_init(void* data)
{
    node* n = (node*) malloc(sizeof(node)*1);

    n->data = data;
    n->next = NULL;
    n->prev = NULL;
};

void list_add(list* dl, void* data)
{
    node* new = node_init(data);

    if(dl->root == NULL)
    {
        dl->root = new; 
        dl->last = new;
    } else
    {
        dl->last->next = new;
        new->prev = dl->last;
        dl->last = new;
    }
}

void list_free(list** dl)
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

void list_insert(list* dl, node* n, void* data)
{
    node* new = node_init(data);
    if(n->next == NULL)
    {
        list_add(dl, data);
    } else
    {
        node* t = n->next;
        t->prev = new;
        n->next = new;
        new->next = t;
        new->prev = n;
    };
};

void list_remove(list* dl, node* n)
{
    if(n == dl->root && n == dl->last)
    {
        dl->root = NULL;
        dl->last = NULL;
    }
    else if(n == dl->root)
    {
        (n->next)->prev = NULL;
        dl->root = n->next;
    } 
    else if(n != dl->root && n != dl->last)
    {
        (n->prev)->next = n->next;
        (n->next)->prev = n->prev;
    }
    else if(n == dl->last){
        (n->prev)->next = n->next;
        dl->last = n->prev;
    }
    free(n);
}


