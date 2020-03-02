#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <time.h>

unsigned int* MakeArr(FILE*f, int size)
{
  unsigned int*arr1 = (unsigned int*)malloc(sizeof(unsigned int)*size);
  for (int i = 0; i < size; i++){
    fscanf(f,"%u",&arr1[i]);
  }
  return arr1;
}
void PrintArray(unsigned int *Arr,int size)
{
  int i = 0;
  for (i = 0; i < size; i++)
  {
    printf("%u ", Arr[i]);
  }
  printf("...\n");
}

int kommand()
{
  int i = 0;
  scanf("%i", &i);
  return i;
}

void menu()
{
  setlocale(LC_ALL, "Rus");
  printf("На данный момент доступны следующие команды:\n1 - Вывести массив на экран\n");
  printf("2 - Сортировать Пузырьком\n3 - Сортировать Вставкой\n4 - Cортировать Быстрой сортировкой\n");
  printf("5 - Сбросить результаты сортировки\n6 - Выход\n");

}
clock_t BubbleSort(unsigned int *Arr, int size)
{
  clock_t t1, t2;
  t1 = clock();
  unsigned int tmp = 0;
  int i, j = 0;
  t1 = clock();
  for (int i = 0; i < size;i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (Arr[j] > Arr[j + 1])
      {
        tmp = Arr[j];
        Arr[j] = Arr[j + 1];
        Arr[j + 1] = tmp;
      }
    }
  }
  t2 = clock();
  return (t2 - t1);
  
}
clock_t InsertionSort(unsigned int *Arr, int size)
{
  clock_t t1, t2;
  t1 = clock();
  unsigned int newElement;
  int location;

  for (int i = 1; i < size; i++)
  {
    newElement = Arr[i];
    location = i - 1;
    while (location >= 0 && Arr[location] > newElement)
    {
      Arr[location + 1] = Arr[location];
      location = location - 1;
    }
    Arr[location + 1] = newElement;
  }
  t2 = clock();
  return t2 - t1;
}

clock_t QuickSort(unsigned int* Arr, int first, int last)
{
  clock_t t1, t2,t3;
  t1 = clock();
  int i = first, j = last;
  unsigned int tmp, x = Arr[(first + last) / 2];

  do {
    while (Arr[i] < x)
      i++;
    while (Arr[j] > x)
      j--;

    if (i <= j)
    {
      if (i < j)
      {
        tmp = Arr[i];
        Arr[i] = Arr[j];
        Arr[j] = tmp;
      }
      i++;
      j--;
    }
  } while (i <= j);

  if (i < last)
    t3=QuickSort(Arr, i, last);
  if (first < j)
    t3=QuickSort(Arr, first, j);
  t2 = clock();
  return (t2-t1);
}








