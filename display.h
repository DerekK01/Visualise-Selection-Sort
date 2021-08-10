#ifndef DISPLAY_H
#define DISPLAY_H
void display(int *numArray, int count, int red, int currentIndex);
int displayRed(int *numArray, int count, int min, int red, int currentIndex);
void arrowAnimation(int *numArray, int count, int start, float sleepTime, int** minArray);
void swapAnimation(int *numArray, int count,int start, int swap1, int swap2, float sleepTime);
#endif