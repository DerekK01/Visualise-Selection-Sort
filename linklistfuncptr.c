#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struc.h"
#include "linkedlist.h"

void printData(void *data)
{
    int i;
    static int current = 1;
    log *logData = (log *)data;

    for (i = 0; i < logData->count; i++)
    {
        if (i < current)
        {
            printf("\033[32m");
            printf("%03d ", logData->numArray[i]);
            printf("\033[0m");
        }
        else
        {
            printf("%03d ", logData->numArray[i]);
        }
    }
    printf("\n");
    if (logData->swap2 != 9999)
    {
        printf("value number %d is %03d after replacing %03d.", current, logData->swap1, logData->swap2);
    }
    else
    {
        printf("value number %d is %03d. It was already in the right spot.", current, logData->swap1);
    }
    printf("\n\n");
    current++;
}

void freedata(void *data)
{
    log *logData = (log *)data;
    free(logData->numArray);
    free(data);
}