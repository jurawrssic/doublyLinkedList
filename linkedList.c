#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"
#define DEBUG 1

linkedList* new_linkedList(int size){
    linkedList *l = (linkedList*) malloc(sizeof(linkedList));
    l->count = 0;
    l->max = size;
    l->first = NULL;
    l->last = NULL;
    return l;
}

node* create_node(int x){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->value = x;
    new_node->next = NULL;
    new_node->previous = NULL;
    return new_node;
}

int is_null(linkedList *l){
    return (l == NULL);
}

int is_empty(linkedList *l){
    return (l->first == NULL);
}

int is_full(linkedList *l){
    return (l != NULL || l->max == -1 ? 0 : l->count == l->max);
}

void insert_first(int x, linkedList *l){
    if (is_full(l)) return;
    if (l == NULL){
        int s;
        scanf("Qual tamanho deseja para a lista? %d", &s);
        new_linkedList(s);
    }
    node* new_node = create_node(x);
    new_node->value = x;
    if (is_empty(l)){
        l->first = new_node;
        l->last = new_node;
    }
    else{
        new_node->next = l->first;
        l->first->previous = new_node;
        l->first = new_node;
    }
    l->count++;
}

void insert_at(int x, int y, linkedList *l){
    if (is_full(l)) return;
    if (l == NULL){
        int s;
        scanf("Qual tamanho deseja para a lista? %d", &s);
        new_linkedList(s);
    }
    if ((is_empty(l) || (y == 0) || (is_empty(l) && y == 0)){
        insert_first(x, l);
        return;
    }
    if (y == l->count){
        insert_last(x, l);
        return;
    }
    int j = 0;
    node* new_node = create_node(x);
    new_node->value = x;
    node *aux = l->first;
    while(j < y){
        aux = aux->next;
        j++;
    }
    node *aux2 = aux->next;
    aux2->previous = new_node;
    new_node->next = aux2;
    new_node->previous = aux;
    aux->next = new_node;
    l->count++;
}

void insert_last(int x, linkedList *l){
    if (is_full(l)) return;
        if (l == NULL){
        int s;
        scanf("Qual tamanho deseja para a lista? %d", &s);
        new_linkedList(s);
    }
    if (is_empty(l)){
        insert_first(x, l);
        return;
    }
    node *new_node = create_node(x);
    new_node->previous = l->last;
    l->last->next = new_node;
    l->last = new_node;
    l->count++;
}

int remove_first(linkedList *l){
    if (is_null(l) || is_empty(l)) return -1;
    node* aux = l->first;
    int x = aux->value;
    l->first = aux->next;
    l->first->previous = NULL;
    aux->previous = NULL;
    aux->next = NULL;
    free(aux);
    l->count--;
    return x;
}

int remove_at (int y, linkedList *l){
    if (is_empty(l) || is_null(l) || y > l->count) return -1;
    int x = 0;
    if (l->first == l->last){
        x = l->first->value;
        l->first = l->last = NULL;
        free(l->first);
    }
    else {
        node *aux = l->first;
        int i = 0;
        while(i < y){
            aux = aux->next;
            i++;
        }
        node *aux2 = aux->next;
        node *aux3 = aux2->next;
        x = aux2->value;
        aux->next = aux2->next;
        aux3->previous = aux;
        aux2->next = NULL;
        aux2->previous = NULL;
        free(aux2);
    }
    l->count--;
    return x;
}

int remove_last (linkedList *l){
    if (l == NULL || is_empty(l)) return -1;
    int x = 0;
    if (l->first == l->last){
        x = l->first->value;
        l->first = l->last = NULL;
        free(l->first);
    }
    else{
        x = l->last->value;
        node *aux = l->last->previous;
        node *aux2 = l->last;
        aux->next = NULL;
        l->last = aux;
        aux2->previous = NULL;
        aux2->next = NULL;
        free(aux2);
    }
    l->count--;
    return x;
}

int search(int x, linkedList *l){
    if (is_empty(l) || is_null(l)) return -1;
    node* aux = l->first;
    int y = 0;
    while(x != aux->value){
        aux = aux->next;
        y++;
    }
    return y;
}

void print(linkedList *l){
    if (is_empty(l) || is_null(l)) return;
    node *aux = l->first;
    int i = 0;
    while(aux != NULL){
        printf("Elemento, posicao = %d, %d\n", i, aux->value);
        aux = aux->next;
        i++;
    }
}

void destroy_list(linkedList **l){
    if (is_empty(*l)) return;
    node *aux = (*l)->first;
    while(aux != NULL){0
        node *del = aux;
        aux = aux->next;
        del->next = NULL;
        del->previous = NULL;
        free(del);
    }
    free(*l);
    *l = NULL;
}
