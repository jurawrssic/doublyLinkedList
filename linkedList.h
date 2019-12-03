#ifndef linkedList_h
#define linkedList_h

typedef struct{
    struct Node *first;
    struct Node *last;
    int count;
    int max;
}linkedList;

typedef struct Node{
    int value;
    struct Node *next;
    struct Node *previous;
}node;

linkedList* new_linkedList(int size);
node* create_node(int x);
int is_null(linkedList *l);
int is_empty(linkedList *l);
int is_full(linkedList *l);
void insert_first(int x, linkedList *l);
void insert_at(int x, int y, linkedList *l);
void insert_last(int x, linkedList *l);
int remove_first(linkedList *l);
int remove_at(int y, linkedList *l);
int remove_last(linkedList *l);
int search (int x, linkedList *l);
void print(linkedList *l);
void destroy_list(linkedList **l);

#endif
