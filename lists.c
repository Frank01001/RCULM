#include "lists.h"
#include <stdio.h>
#include <math.h>

//Initialization
void init(List *l)
{
    l->last_index = 0;
}

//Add Element to the list
void addElement(List *l, int value)
{
    l->data[l->last_index] = value;
    l->last_index++;
}

//Make a Graph of the list
void graph(List* l, int scale)
{
    int dataBuffer = 0;

    printf("Line numbers");


    for(int i = 0; i < l->last_index; i++)
    {

        //Calculates number of digits in number representation
        if((i + 1) >= 10)
            printf("  %d ", i + 1);
        else
            printf("  %d  ", i + 1);
    }

    printf("\n\n");

    printf("            ");

    for(int y = 1; y <= MAX_HEIGHT; y++)
    {
        for(int i = 0; i < l->last_index; i++)
        {
            dataBuffer = l->data[i] * MAX_HEIGHT / scale;
            if((dataBuffer - (MAX_HEIGHT - y)) > 0)
            {
                printf(" %c%c%c ", (char)219, (char)219, (char)219);
            }
            else
            {
                printf("     ");
            }
        }

        printf("\n            ");
    }

    printf("\n  Values    ");

    int digit_number = 0;

    for(int i = 0; i < l->last_index; i++)
    {

        //Calculates number of digits in number representation
        if(l->data[i] != 0)
            digit_number = log10(l->data[i]) + 1;
        else
            digit_number = 1;

        switch(digit_number)
        {

        case 1:
            printf("  %d  ", l->data[i]);
            break;
        case 2:
            printf("  %d ", l->data[i]);
            break;
        case 3:
            printf(" %d ", l->data[i]);
            break;
        default:
            printf(" ERR ", l->data[i]);
            break;
        }
    }

    printf("\n");

}
