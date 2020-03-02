#ifndef ADD_H
#define ADD_H
#include <stdio.h>
#include <time.h>
float* MakeArr(FILE*f,int size);
void menu();
int kommand();
clock_t BubbleSort(unsigned int *Arr, int size);
clock_t InsertionSort(unsigned int *Arr, int size);
clock_t QuickSort(unsigned int *Arr, int left, int right);

void PrintArray(unsigned int *Arr,int size);
#endif