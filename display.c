#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "newSleep.h"

void display(int *numArray, int count, int red, int currentIndex)
{
    int i;
    for (i = 0; i < count; i++)
    {
        if (numArray[i] == red)
        {
            printf("\033[1;31m");
            printf("%03d ", numArray[i]);
            printf("\033[0m");
        }
        else if (i < currentIndex)
        {
            printf("\033[32m");
            printf("%03d ", numArray[i]);
            printf("\033[0m");
        }
        else
        {
            printf("%03d ", numArray[i]);
        }
    }
}

int displayRed(int *numArray, int count, int min, int red, int currentIndex)
{
    int i;
    for (i = 0; i < count; i++)
    {
        if (numArray[i] == min)
        {
            printf("\033[1;31m");
            printf("%03d ", numArray[i]);
            printf("\033[0m");
            red = numArray[i];
        }
        else if (i < currentIndex)
        {
            printf("\033[32m");
            printf("%03d ", numArray[i]);
            printf("\033[0m");
        }
        else
        {
            printf("%03d ", numArray[i]);
        }
    }
    return red;
}

void arrowAnimation(int *numArray, int count, int start, float sleepTime, int** minArray)
{
    int i, x, b = 0;
    static int a = 0;
    char **arrowArray = (char **)malloc(count * sizeof(char *));
    int red = numArray[start];
    for (x = 0; x < count; x++)
    {
        arrowArray[x] = "   ";
    }
    for (i = start; i < count; i++)
    {
        system("clear");
        printf("\n");

        if (numArray[i] == minArray[a][b])
        {
            red = displayRed(numArray, count, minArray[a][b], red, start);
            b++;
        }
        else
        {
            display(numArray, count, red, start);
        }
        printf("\n");
        arrowArray[i] = " ^ ";
        for (x = 0; x < count; x++)
        {
            printf("%s ", arrowArray[x]);
        }
        arrowArray[i] = "   ";
        printf("\n");
        newSleep(sleepTime);
    }
    a++;
    free(arrowArray);
}

void swapAnimation(int *numArray, int count, int start, int swap1, int swap2, float sleepTime)
{
    int i, x, swap2Index;
    char strNumArray[10][100];
    char swap1Array[10][100];
    char swap2Array[10][100];
    /*setup array*/
    for (i = 0; i < count; i++)
    {
        sprintf(swap1Array[i], "    ");
        sprintf(swap2Array[i], "    ");
        sprintf(strNumArray[i], "%03d ", numArray[i]);
    }
    system("clear");
    printf("\n");
    for (i = 0; i < count; i++)
    {
        if (numArray[i] == swap2)
        {
            printf("\033[1;31m");
            printf("%03d ", numArray[i]);
            printf("\033[0m");
            swap2Index = i;
        }
        else if (i < start)
        {
            printf("\033[32m");
            printf("%03d ", numArray[i]);
            printf("\033[0m");
        }
        else
        {
            printf("%03d ", numArray[i]);
        }
        
    }
    printf("\n");

    newSleep(sleepTime);
    if (start != swap2Index)
    {
        /*swap start*/

        sprintf(swap2Array[swap2Index], "%s", strNumArray[swap2Index]);
        sprintf(swap1Array[start], "%s", strNumArray[start]);
        sprintf(strNumArray[swap2Index], "    ");
        sprintf(strNumArray[start], "    ");
        for (x = 0; x <= swap2Index - start; x++)
        {
            system("clear");
            for (i = 0; i < count; i++)
            {
                printf("%s", swap1Array[i]);
            }
            printf("\n");
            for (i = 0; i < count; i++)
            {
                if (i < start)
                {
                    printf("\033[32m");
                    printf("%s", strNumArray[i]);
                    printf("\033[0m");
                }
                else
                {
                    printf("%s", strNumArray[i]);
                }
            }
            printf("\n");
            for (i = 0; i < count; i++)
            {
                printf("\033[1;31m");
                printf("%s", swap2Array[i]);
                printf("\033[0m");
            }
            printf("\n");
            sprintf(swap1Array[start + x + 1], "%s", swap1Array[start + x]);
            sprintf(swap1Array[start + x], "    ");
            sprintf(swap2Array[swap2Index - x - 1], "%s", swap2Array[swap2Index - x]);
            sprintf(swap2Array[swap2Index - x], "    ");
            newSleep(sleepTime);
        }
    }
}