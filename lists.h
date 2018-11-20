#ifndef LISTS_H_
#define LISTS_H_

#define MAX_ELEMENTS 16
#define MAX_HEIGHT 10
#define MAX_VAL 999


/* List type */
typedef struct
{
    int data[MAX_ELEMENTS];
    int last_index;
} List;

//Initialization
void init(List *l);

//Add Element to the list
void addElement(List *l, int value);

//Make a Graph of the list
void graph(List* l, int scale);

#endif // LISTS_H_
