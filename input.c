#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "macro.h"

int *readFile(char *fileName,int *status, int *count)
{
    int i;
    int *array;
    FILE *file = fopen(fileName, "r");
    *count = 0;
    if (file == NULL)
    {
        perror("Error opening the file");
        *status = ERROR;
    }
    else
    {
        while (fscanf(file, "%d", &i) == 1)
        {
            *count = *count + 1;
        }
        if (*count < 3 || *count > 10)
        {
            printf("[ERROR] It need to be 3-10 inclusive\n");
            *status = ERROR;
        }
        rewind(file);
        array = (int *)malloc(*count * sizeof(int));
        i = 0;
        while (fscanf(file, "%d", &array[i]) == 1)
        {
            if (array[i] > 999 || array[i] < 0)
            {
                printf("[ERROR] The number need to be in the range of 0 - 999");
                *status = ERROR;
            }
            i++;
        }
        fclose(file);
    }
    return array;
}

int *randomInput(int *count)
{
    int i, status=ERROR;
    int *array;
    srand(time(NULL));
    while (status == ERROR)
    {
        printf("Please enter the amount of numbers you want to sort (3-10 inclusive) : ");
        scanf("%d", count);
        if (*count < 3 || *count > 10)
        {
            status = ERROR;
            printf("[ERROR] It need to be 3-10 inclusive\n");
        }
        else
        {
            status = SUCCESS;
        }
    }

    array = (int *)malloc(*count * sizeof(int));
    for (i = 0; i < *count; i++)
    {
        array[i] = rand() % 1000;
    }
    return array;
}