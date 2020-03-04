
#include "TXLib.h"
#include <stdio.h>
#include <assert.h>

void ArrayCreateRand (int ArraySize, int numberr[]);

void Swopsss (int number[], int left, int right);

/*void ArrayClear(int number[]);  // перезапуск генератора rand()  */


//{============================================================================
//                          Описания функций
//}============================================================================



/*void ArrayClear(int number[])
    {
      number[1000]  = {{0}};       //   assert(i=0, i<DimensionButton);
    }

 */

//-------------Заполнение массива случайными числами-------------
void ArrayCreateRand (int ArraySize, int numberr[])
    {
    for (int index = 0; index < ArraySize; index++)
        {
//        assert(i=0, i<ArraySize);
        numberr [index] = 100-rand()%200;
        //printf("%d  ", number [index]);
        }
    }

//-------------Обмен элементов массива случайными числами-------------
void Swopsss (int number[], int left, int right)
    {
    int temp = number[left];
    number[left] = number[right];
    number[right] = temp;
    }
