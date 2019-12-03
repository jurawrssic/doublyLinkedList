#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main()
{
    linkedList *l = new_linkedList(6);
    insert_first(10, l);
    insert_at(20, 1, l);
    insert_at(30, 1, l);
    insert_last(40, l);
    insert_first(50, l);
    insert_last(100, l);
    print(l);
    remove_first(l);
    print(l);
    remove_at(2, l);
    print(l);
    printf("%d: ", search(100, l));
    destroy_list(&l);
    printf("\nLista destruida e sem dangling pointers?\n%d", l == NULL);
}
