#include "lists.h"

int main()
{
    List l;
    init(&l);

    addElement(&l, 1);
    addElement(&l, 4);
    addElement(&l, 2);
    addElement(&l, 6);
    addElement(&l, 0);
    addElement(&l, 10);
    addElement(&l, 1);
    addElement(&l, 4);
    addElement(&l, 2);
    addElement(&l, 6);
    addElement(&l, 0);
    addElement(&l, 10);
    addElement(&l, 1);
    addElement(&l, 4);
    addElement(&l, 2);
    addElement(&l, 6);

    printf("Graph:\n\n");

    graph(&l, 10);

    return 0;
}
