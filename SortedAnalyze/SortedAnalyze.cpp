
#include "TXLib.h"
#include "MyInterfaceLib.h"
#include "BubleSorting.h"

#include <stdio.h>
#include <assert.h>

const COLORREF Sort1color = RGB (255,   0,   0);
const COLORREF Sort2color = RGB (128,   0, 255);
const COLORREF Sort3color = RGB (  0,   0, 255);
const COLORREF Sort4color = RGB (  0, 183,   0);
const COLORREF Sort5color = RGB (  0, 215, 250);

const int MaxSize   = 1000;
//int ButtonDimetsion = 8;

void MenuManager(mButton_t* button);

void ArrayDraw (COLORREF color, int funct); //переделать под цикл вызовов сортировки и рисования графиков

void ExitProc();//НАПИСАТЬ!!!

void ArrayClear(int* number[]);

int main()
    {
     mButton_t buttons [ButtonDimetsion] = {
                             { 10, 120, 200, 33, "Сброс генератора rand()",     TX_LIGHTGRAY      , false},
                             { 10, 180, 200, 33, "Сортировка Bubble",    RGB(175, 235, 185), false},
                             { 10, 240, 200, 33, "Гномья сортировка",  RGB(175, 235, 185), false},
                             { 10, 300, 200, 33, "NextSort #3",         RGB(175, 235, 185), false},
                             { 10, 360, 200, 33, "NextSort #4",         RGB(175, 235, 185), false},
                             { 10, 420, 200, 33, "NextSort #5",         RGB(175, 235, 185), false},
                             { 10, 550, 200, 33, "Выход",               TX_LIGHTGRAY,       false},
                             {500, 550, 200, 33, "Очистить график",    TX_LIGHTGRAY,       false}
                             };
    txCreateWindow (1000, 600);
    StartDraw(buttons, ButtonDimetsion, 1000, 600);
    MenuManager(buttons);

    return 0;
    }



//{============================================================================
//                          Описания функций
//}============================================================================


void MenuManager(mButton_t* button)
    {
    while (!txGetAsyncKeyState(VK_ESCAPE))
        {
        for (int i = 0; i < ButtonDimetsion; i++)
            {
            if (button[i].Click())
               {
                switch (i)
                    {
                    case 0:
                        srand(1);
                        break;
                    case 1:
                        txSetColor (Sort1color);
                        txSetFillColor(Sort1color);
                        txCircle ((button[i].x_ + button[i].sizeX_- 7), (button[i].y_ + button[i].sizeY_ /2), 5);
                        ArrayDraw(Sort1color, 1);
                        break;
                    case 2:
                        txSetColor (Sort2color);
                        txSetFillColor(Sort2color);
                        txCircle ((button[i].x_ + button[i].sizeX_- 7), (button[i].y_ + button[i].sizeY_ /2), 5);
                        ArrayDraw(Sort1color, 2);
                        break;
                    case 3:
                        txSetColor (Sort3color);
                        txSetFillColor(Sort3color);
                        txCircle ((button[i].x_ + button[i].sizeX_- 7), (button[i].y_ + button[i].sizeY_ /2), 5);
                        ArrayDraw(Sort1color, 3);
                        break;
                    case 4:
                        txSetColor (Sort4color);
                        txSetFillColor(Sort4color);
                        txCircle ((button[i].x_ + button[i].sizeX_- 7), (button[i].y_ + button[i].sizeY_ /2), 5);
                        ArrayDraw(Sort1color, 4);
                        break;
                    case 5:
                        txSetColor (Sort5color);
                        txSetFillColor(Sort5color);
                        txCircle ((button[i].x_ + button[i].sizeX_- 7), (button[i].y_ + button[i].sizeY_ /2), 5);
                        ArrayDraw(Sort1color, 1);
                        break;
                    case 6:
                        ExitProc ();
                        break;
                    case 7:
                        Plane (230, 40, 1000);
                        //ClearPlane();
                        break;
                    };

                };
            };
        }
    }


void ArrayDraw (COLORREF color, int funct)
    {

    int sizeArray = 10;
    int number[MaxSize] = {0};

    txSetFillColor (color);
    srand(1);
    for (int i = sizeArray; i <= MaxSize; i+=5)
        {
        ArrayCreateRand (sizeArray, number);
//        assert(i=0, i<DimensionButton);
        int sswop  = 0; // счетчик обменов
        int eequal = 0; // счетчик сравниваний

        switch (funct)
            {
            case 1:
                BubblSorting (i, number, &sswop, &eequal);
                color = Sort1color;
                MyPoint(i, eequal, color, 230, 40);
                MyPoint(i, sswop,  color, 610, 40);
                break;
            case 2:
                //printf("сортировка %d\n",funct);
                GnomeSorting (i, number, &sswop, &eequal);
                color = Sort2color;
                MyPoint(i, eequal, color, 230, 40);
                MyPoint(i, sswop,  color, 610, 40);
                break;
            case 3:
                //printf("сортировка %d\n",funct);
                break;
            case 4:
                //printf("сортировка %d\n",funct);
                break;
            case 5:
                //printf("сортировка %d\n",funct);
                break;
            default: break;
            }

        }

    }

void ArrayClear(int* number[])
    {
    srand(1);
    number[MaxSize] = {0};
    }

//НАПИСАТЬ!!!
void ExitProc()
    { ;
    }
