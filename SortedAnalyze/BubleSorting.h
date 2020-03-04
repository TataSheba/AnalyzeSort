
#include "TXLib.h"
#include <assert.h>

void ArrayCreateRand (int ArraySize, int numberr[]);

void Swopss (int number[], int left, int right);

void BubblSorting (int sizeArray, int number[], int* Swops, int* Equals);

void GnomeSorting (int sizeArray, int number[], int* Swops, int* Equals);

//{----------------------------------------------------------------------------
//  Bubble Sort
//}----------------------------------------------------------------------------

void BubblSorting (int sizeArray, int number[], int* Swops, int* Equals)
    {
    int sw = 0;
    int eq = 0;

    int lastIndex = sizeArray;

      // ------------- ѕервый проход сортировки-------------
      for (int firstIndex = 0; firstIndex <= lastIndex; firstIndex++)
        {

        for (int leftIndex = lastIndex; leftIndex > firstIndex; leftIndex--)
            {
            if ( (number [leftIndex]) < (number [leftIndex - 1]) )
                {
                Swopss (number, leftIndex - 1, leftIndex);
                ;
                };
            sw++;
            eq++;
            }
        }
    *Swops  = sw;
    *Equals = eq;
    }

void GnomeSorting (int sizeArray, int number[], int* Swops, int* Equals)
    {
    int sw = 0;
    int eq = 0;
    //gnomeSort(a[0..size - 1])
    int LeftIndex = 1;
    int Index = 2;
    while (LeftIndex < sizeArray)
        {
        if (number[LeftIndex - 1] > number[LeftIndex]) //дл€ сортировки по возрастанию помен€йте знак сравнени€ на <
            {
            LeftIndex = Index;
            Index = Index + 1;
            }
        else
            {
            Swopss (number, LeftIndex - 1, LeftIndex);
            sw++;
            LeftIndex = LeftIndex - 1;
            if (LeftIndex == 0)
                {
                LeftIndex = Index;
                Index = Index + 1;
                }
            };
        eq++;
        }
    *Swops  = sw;
    *Equals = eq;
    }


void ArrayCreateRand (int ArraySize, int numberr[])
    {
    for (int index = 0; index < ArraySize; index++)
        {
//        assert(i=0, i<ArraySize);
        numberr [index] = rand()%100;
        //printf("%d  ", number [index]);
        }
    }

//-------------ќбмен элементов массива случайными числами-------------
void Swopss (int number[], int left, int right)
    {
    int temp = number[left];
    number[left] = number[right];
    number[right] = temp;
    }
