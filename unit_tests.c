#include "doublelinkedlist.h"
#include <stdio.h>
#include <assert.h>

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

/*
Инициализируем пустой список
*/
void unit_test_00()
{
    // init
    list *dl1 = list_init();

    // assert
    assert(dl1->root == NULL);
    assert(dl1->last == NULL);

    // free
    list_free(&dl1);
}

/*
Заполняем список числами от 0-10
*/
void unit_test_01()
{
    // init
    int n = 10;
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        a[i] = i;

    list* dl1 = list_init();
    for (int i = 0; i < n; i++)
        list_add(dl1, &a[i]);

    // assert
    node *c = dl1->root;

    // Проверка в прямом направлении
    int i = 0;
    while (c != NULL)
    {
        assert(*(int *)c->data == i++);
        c = c->next;
    }

    // Проверка в обратном направлении
    i = 9;
    c = dl1->last;
    while (c != NULL)
    {
        assert(*(int *)c->data == i--);
        c = c->prev;
    }

    assert(dl1->last->next == NULL);
    assert(dl1->root->prev == NULL);

    // free
    list_free(&dl1);
    free(a);
}

/* 
Создаем список из одного элемента и удаляем его
*/
void unit_test_02()
{
    // init
    list *dl1 = list_init();
    int a = 1;
    list_add(dl1, &a);

    list_remove(dl1, dl1->root);

    // assert
    assert(dl1->root == NULL);
    assert(dl1->last == NULL);

    // free
    list_free(&dl1);
}

/*
Создаем список из двух элементов и удаляем первый
*/
void unit_test_03()
{
    // init
    list *dl1 = list_init();
    int a = 1;
    int b = 2;
    list_add(dl1, &a);
    list_add(dl1, &b);

    // assert
    assert(dl1->root->data == &a);
    assert(dl1->last->data == &b);
    assert(dl1->root->next == dl1->last);
    assert(dl1->last->prev == dl1->root);
    
    list_remove(dl1, dl1->root);

    assert(dl1->root->data == &b);
    assert(dl1->last->data == &b);
    assert(dl1->last->prev == NULL);
    assert(dl1->root->next == NULL);

    // free
    list_free(&dl1);
}

/*
Создаем список из двух элементов и удаляем первый
*/
void unit_test_04()
{
    // init
    list *dl1 = list_init();
    int a = 1;
    int b = 2;
    list_add(dl1, &a);
    list_add(dl1, &b);

    //assert
    assert(dl1->root->data == &a);
    assert(dl1->last->data == &b);
    assert(dl1->root->next == dl1->last);
    assert(dl1->last->prev == dl1->root);
    
    list_remove(dl1, dl1->last);

    assert(dl1->root->data == &a);
    assert(dl1->last->data == &a);
    assert(dl1->root->next == NULL);
    assert(dl1->last->prev == NULL);

    // free
    list_free(&dl1);
}

/*
Создаем список из трех элементов и удаляем первый
*/
void unit_test_05()
{
    // init
    list *dl1 = list_init();
    int a = 1;
    int b = 2;
    int c = 3;
    list_add(dl1, &a);
    list_add(dl1, &b);
    list_add(dl1, &c);

    // assert
    assert(dl1->root->data == &a);
    assert(dl1->last->data == &c);
    assert(dl1->root->next->data && dl1->last->prev->data == &b);
    
    list_remove(dl1, dl1->root);

    assert(dl1->root->data == &b);
    assert(dl1->last->data == &c);
    assert(dl1->last->next == NULL); //I think that this doesn't need to be done 
    assert(dl1->root->prev == NULL);

    // free
    list_free(&dl1);
}

/*
Создаем список из трех элемента и удаляем второй
*/
void unit_test_06()
{
    // init
    list *dl1 = list_init();
    int a = 1;
    int b = 2;
    int c = 3;
    list_add(dl1, &a);
    list_add(dl1, &b);
    list_add(dl1, &c);

    // assert
    assert(dl1->root->data == &a);
    assert(dl1->last->data == &c);
    assert(dl1->root->next->data && dl1->last->prev->data == &b);
    
    list_remove(dl1, dl1->root->next);

    assert(dl1->root->data && dl1->last->prev->data == &a);
    assert(dl1->last->data && dl1->root->next->data== &c);
    assert(dl1->last->next == NULL);
    assert(dl1->root->prev == NULL);

    // free
    list_free(&dl1);
}

/*
Создаем список из трех элемента и удаляем третий
*/
void unit_test_07()
{
    // init
    list *dl1 = list_init();
    int a = 1;
    int b = 2;
    int c = 3;
    list_add(dl1, &a);
    list_add(dl1, &b);
    list_add(dl1, &c);

    // assert
    assert(dl1->root->data == &a);
    assert(dl1->last->data == &c);
    assert(dl1->root->next->data && dl1->last->prev->data == &b);
    
    list_remove(dl1, dl1->last);

    assert(dl1->root->data && dl1->last->prev->data == &a);
    assert(dl1->last->data && dl1->root->next->data== &b);
    assert(dl1->last->next == NULL); 
    assert(dl1->root->prev == NULL);

    // free
    list_free(&dl1);
}

/*
Создаем список из трех элемента и удаляем первый и второй
*/
void unit_test_08()
{
    // init
    list *dl1 = list_init();
    int a = 1;
    int b = 2;
    int c = 3;
    list_add(dl1, &a);
    list_add(dl1, &b);
    list_add(dl1, &c);

    // assert
    assert(dl1->root->data == &a);
    assert(dl1->last->data == &c);
    assert(dl1->root->next->data && dl1->last->prev->data == &b);
    
    list_remove(dl1, dl1->root);
    list_remove(dl1, dl1->root);

    assert(dl1->root->data == &c);
    assert(dl1->last->data == &c);
    assert(dl1->last->next == NULL);
    assert(dl1->root->prev == NULL);
    assert(dl1->root == dl1->last);

    // free
    list_free(&dl1);
}

/*
Создаем список из трех элемента и удаляем первый и третий
*/
void unit_test_09()
{
    // init
    list *dl1 = list_init();
    int a = 1;
    int b = 2;
    int c = 3;
    list_add(dl1, &a);
    list_add(dl1, &b);
    list_add(dl1, &c);

    // assert
    assert(dl1->root->data == &a);
    assert(dl1->last->data == &c);
    assert(dl1->root->next->data && dl1->last->prev->data == &b);
    
    list_remove(dl1, dl1->root);
    list_remove(dl1, dl1->last);    
    
    assert(dl1->root->data == &b);
    assert(dl1->last->data == &b);
    assert(dl1->last->next == NULL);
    assert(dl1->root->prev == NULL);
    assert(dl1->root == dl1->last);

    // free
    list_free(&dl1);
}

/*
Создаем список из трех элемента и удаляем второй и третий
*/
void unit_test_10()
{
    // init
    list *dl1 = list_init();
    int a = 1;
    int b = 2;
    int c = 3;
    list_add(dl1, &a);
    list_add(dl1, &b);
    list_add(dl1, &c);

    // assert
    assert(dl1->root->data == &a);
    assert(dl1->last->data == &c);
    assert(dl1->root->next->data && dl1->last->prev->data == &b);
    
    list_remove(dl1, dl1->last);    
    list_remove(dl1, dl1->last);    

    assert(dl1->root->data == &a);
    assert(dl1->last->data == &a);
    assert(dl1->last->next == NULL);
    assert(dl1->root->prev == NULL);
    assert(dl1->root == dl1->last);

    // free
    list_free(&dl1);
}

/*
Создаем список из трех элемента и удаляем первый, второй и третий
*/
void unit_test_11()
{
    // init
    list *dl1 = list_init();
    int a = 1;
    int b = 2;
    int c = 3;
    list_add(dl1, &a);
    list_add(dl1, &b);
    list_add(dl1, &c);

    // assert
    assert(dl1->root->data == &a);
    assert(dl1->last->data == &c);
    assert(dl1->root->next->data && dl1->last->prev->data == &b);
    
    list_remove(dl1, dl1->root);    
    list_remove(dl1, dl1->root);    
    list_remove(dl1, dl1->root);    

    assert(dl1->root == NULL);
    assert(dl1->last == NULL);

    // free
    list_free(&dl1);
}

/*
Создаем список из одного элемента и вставляем новый элемент
*/
void unit_test_12()
{
    // init
    int a = 1;
    int b = 2;
    list *dl1 = list_init();
    list_add(dl1, &a);

    // assert
    assert(dl1->root->data == &a);
    assert(dl1->last->data == &a);

    list_insert(dl1, dl1->root, &b);

    assert(dl1->root->data == &a);
    assert(dl1->last->data == &b);
    assert(dl1->last->prev->data == &a);
    assert(dl1->root->next->data == &b);
    assert(dl1->last->next == NULL);
    assert(dl1->root->prev == NULL);

    // free
    list_free(&dl1);
}

/*
Создаем список из двух элементов и вставляем новый элемент после первого
*/
void unit_test_13()
{
    // init
    list *dl1 = list_init();
    int a = 1;
    int b = 2;
    int c = 2;
    list_add(dl1, &a);
    list_add(dl1, &c);

    // assert
    assert(dl1->root->data == &a);
    assert(dl1->last->data == &c);
    list_insert(dl1, dl1->root, &b);
    assert(dl1->root->data == &a);
    assert(dl1->last->data == &c);
    assert(dl1->root->next->data == &b);
    assert(dl1->last->prev->data == &b);
    assert(dl1->last->next == NULL);
    assert(dl1->root->prev == NULL);

    // free
    list_free(&dl1);
}

/*
Создаем список из двух элементов и вставляем новый элемент после второго
*/
void unit_test_14()
{
    // init
    list *dl1 = list_init();
    int a = 1;
    int b = 2;
    int c = 2;
    list_add(dl1, &a);
    list_add(dl1, &b);

    // assert
    assert(dl1->root->data == &a);
    assert(dl1->last->data == &b);
    list_insert(dl1, dl1->root->next, &c);
    assert(dl1->root->data == &a);
    assert(dl1->last->data == &c);
    assert(dl1->root->next->data == &b);
    assert(dl1->last->prev->data == &b);
    assert(dl1->last->next == NULL);
    assert(dl1->root->prev == NULL);

    // free
    list_free(&dl1);
}

int main()
{
    unit_test_00();
    unit_test_01();
    unit_test_02();
    unit_test_03();
    unit_test_04();
    unit_test_05();
    unit_test_06();
    unit_test_07();
    unit_test_08();
    unit_test_09();
    unit_test_10();
    unit_test_11();
    unit_test_12();
    unit_test_13();
    unit_test_14();
}