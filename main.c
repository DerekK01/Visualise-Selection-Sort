#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macro.h"
#include "input.h"
#include "display.h"
#include "linkedlist.h"
#include "linklistfuncptr.h"
#include "struc.h"
int main(int argc, char *argv[])
{
    float sleepTime;
    char *filename = "NONE";
    int *numArray;
    int *status = (int *)malloc(sizeof(int));
    int *count = (int *)malloc(sizeof(int));
    int i, x, y, temp, a = 0, b = 0;
    int **minArray = (int **)malloc(20 * sizeof(int *));
    int *logArray;
    log *storeData;
    LinkedList *logList;
    logList = createLinkedList();
    *status = SUCCESS;
    for (i = 0; i < 20; i++)
    {
        minArray[i] = (int *)malloc(20 * sizeof(int));
    }
    for (i = 0; i < 20; i++)
    {
        for (x = 0; x < 20; x++)
        {
            minArray[i][x] = 0;
        }
    }

    sleepTime = atof(argv[1]);
    if (argc == 3)
    {
        filename = argv[2];
        numArray = readFile(filename, status, count);
    }
    else if (argc < 2)
    {
        *status = ERROR;
        printf("[ERROR] Not enough argument");
    }
    else if (argc > 3)
    {
        *status = ERROR;
        printf("[ERROR] Too many argument");
    }
    else
    {
        numArray = randomInput(count);
    }

    if (*status != ERROR)
    {
        for (i = 0; i < *count; i++)
        {
            y = i;
            for (x = y + 1; x < *count; x++)
            {
                if (numArray[y] > numArray[x])
                {
                    y = x;
                    minArray[a][b] = numArray[y];
                    b++;
                }
            }
            a++;
            b = 0;
            arrowAnimation(numArray, *count, i, sleepTime, minArray);
            if (numArray[i] != numArray[y])
            {
                swapAnimation(numArray, *count, i, numArray[i], numArray[y], sleepTime);
            }

            temp = numArray[i];
            numArray[i] = numArray[y];
            numArray[y] = temp;

            if (i != *count - 1)
            {
                storeData = (log *)malloc(sizeof(log));
                logArray = (int *)malloc(*count * sizeof(int));
                for (x = 0; x < *count; x++)
                {
                    logArray[x] = numArray[x];
                }
                storeData->numArray = logArray;
                if (numArray[i] == numArray[y])
                {
                    storeData->swap1 = numArray[i];
                    storeData->swap2 = 9999;
                }
                else
                {
                    storeData->swap1 = numArray[i];
                    storeData->swap2 = numArray[y];
                }
                storeData->count = *count;
                insertLast(logList, storeData);
            }
        }
        system("clear");
        printf("\n");
        printf("Sorted Array: ");
        for (i = 0; i < *count; i++)
        {
            printf("\033[32m");
            printf("%03d ", numArray[i]);
            printf("\033[0m");
        }
        printf("\n\n");
        printf("Process Log: ");
        printf("\n");
        printLinkedList(logList, printData);
        for (i = 0; i < *count; i++)
        {
            printf("\033[32m");
            printf("%03d ", numArray[i]);
            printf("\033[0m");
        }
        printf("\n");
        printf("Then the last number is %d \n", numArray[*count - 1]);
    }

    for (i = 0; i < 20; i++)
    {
        free(minArray[i]);
    }
    free(minArray);
    free(status);
    free(count);
    freeLinkedList(logList, freedata);
    free(numArray);
    return 0;
}