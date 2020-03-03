
#include "TXLib.h"
#include <stdio.h>

struct mButton_t {
                 int x_; int y_;
                 int sizeX_; int sizeY_;
                 char* buttonName_;
                 COLORREF color_;
                 int* func_;
                 void Draw();
                 void Click();
                };

void TextShadow(int x, int y, COLORREF colorText, COLORREF colorShadow, char* text);

void Plane (int x0, int y0, int MaxY);

void StartDraw(mButton_t* button, int DimensionButton);

int SelectMenu();

void ArrayCreateRand (int ArraySize, int* number);

void Rotation (int* number, int left, int right);

void BubblSort(int sizeArray, int* number, int* Swops, int* Equals); // �������� � ������� �������� ������������ � ���������

void QuiqSort (int sizeArray, int* number, int* Swops, int* Equals);   //��������!!!

void ArrayDraw (int startX, int startY, int sizeArray, int* number, COLORREF color); //���������� ��� ���� ������� ���������� � ��������� ��������

void ArrayClear();  //

void ClearPlane(); // ���������� ���������� rand()

void ExitProc();


const int ButtonDimetsion = 6;


int main()
    {
     mButton_t buttons [ButtonDimetsion] = {{10, 120, 200, 33, "������������ ������", RGB(175, 235, 235), (int*) ArrayCreateRand},
                             {10, 180, 200, 33, "�������� ������",     TX_LIGHTGRAY, (int*) ArrayClear},
                             {10, 240, 200, 33, "���������� Bubble",   RGB(175, 235, 185), (int*) BubblSort},
                             {10, 300, 200, 33, "������� ����������",  RGB(175, 235, 185), (int*) QuiqSort},
                             {10, 550, 200, 33, "�����",               TX_LIGHTGRAY,       (int*) ExitProc},
                             {500, 550, 200, 33, "�������� ������",    TX_LIGHTGRAY,       (int*) ClearPlane}
                             };

    int Swops  = 0; // ������� �������
    int Equals = 0; // ������� �����������

    StartDraw(buttons, ButtonDimetsion);

    return 0;
    }



//{============================================================================
//                          �������� �������
//}============================================================================

void TextShadow(int x, int y, COLORREF colorText, COLORREF colorShadow, char* text)
    {
    txSetColor (colorShadow);
    txTextOut (x+1, y+1, text);
    txSetColor (colorText);
    txTextOut (x, y, text);
    }

void Plane (int x0, int y0, int MaxY)
    {

    txSetTextAlign (TA_LEFT);
    txSelectFont ("Comic Sans MS", 40, 10, 1, true);

    TextShadow(x0 + 10,       y0 - 45, TX_WHITE, TX_BLACK, "����������� ��������� �� ������� �������");
    TextShadow(x0 + 380 + 10, y0 - 45, TX_WHITE, TX_BLACK, "����������� ������������ �� ������� �������");

    txSetFillColor(RGB (239, 239, 239));
    txRectangle (x0, y0, x0 + 370, y0 + 490);
    txRectangle (x0 + 380, y0, x0 + 370 + 380, y0 + 490);

    //--- ��� ������������---
    txSetColor (TX_BLACK);
    int dx = 15, dy = 15;
    txLine (      x0 + dx,       y0 + dy,             x0 + dx,  y0 + 490 - dy);
    txLine (      x0 + dx, y0 - dy + 490,       x0 - dx + 370,  y0 + 490 - dy);

    txLine (x0 + 380 + dx,       y0 + dy,       x0 + 380 + dx,  y0 + 490 - dy);
    txLine (x0 + 380 + dx, y0 - dy + 490, x0 - dx + 370 + 380,  y0 + 490 - dy);


    // --- ������� � �������� ����������
    //txSetColor(TX_WHITE);
    }

void StartDraw(mButton_t* button, int DimensionButton)
    {
    txCreateWindow (1000, 600);
    txSetFillColor(TX_DARKGRAY);
    txRectangle (0, 0, 1000, 600);

    Plane (230, 50, 1000);


    /*int choice = 0;
    choice = SelectMenu();

    printf ("%d", choice);
    getch();  */

    //------ ��������� ������= ���������� ���������-----
    for (int i = 0; i < DimensionButton; i++)
        {
        button[i].Draw();
        }
    }


int SelectMenu()
    {
    // ---- !!++++  ������� ��������� ������------
    printf("b - BubbleSort \n s - QuikSort \n  c - Clear \n  e - Exit \n");
    int ch;

    while (!txGetAsyncKeyState(VK_ESCAPE))
        {
          ch = getch();
        if (ch == 'b' || ch == 'B')
            {
            printf("�������� ��������� \n");
             return 1;
             };
        if (ch =='s' || ch =='S' )
            {
            printf("�������� QuekSort \n");
             return  2;
             };
        if (ch =='c' || ch =='C' )
            {
            printf("������.... \n");
            return  6;
            };
        if (ch =='e' || ch =='E' )
            {
            printf("Exit. Good bye! \n");
            return  7;
            };
        }
    }

void ArrayCreateRand (int ArraySize, int* number)
    {
      // --------���������� ������� ���������� ������� --------
      for (int index = 0; index < ArraySize; index++)
        {
        number [index] = 100-rand()%200;
        //printf("%d  ", number [index]);
        }
     // printf("\n  ");
    }

void Rotation (int* number, int left, int right)
    {
    int temp = number[left];
    number[left] = number[right];
    number[right] = temp;
    }

//{----------------------------------------------------------------------------
//  Bubble Sort
//}----------------------------------------------------------------------------

void BubblSort(int sizeArray, int* number, int* Swops, int* Equals)
    {
    int sw = 0, eq = 0;
    int lastIndex = sizeArray;
      // ------------- ������ ������ ����������-------------
      for (int firstIndex = 0; firstIndex <= lastIndex; firstIndex++)
        {

        for (int leftIndex = lastIndex; leftIndex >= firstIndex; leftIndex--)
            {
            if ( (number [leftIndex]) < (number [leftIndex-1]) )
                {
                Rotation (number, leftIndex-1, leftIndex);
                sw++;
                };
            eq++;
            }
        }
    *Swops  = sw;
    *Equals = eq;
    }


void QuiqSort (int sizeArray, int* number, int* Swops, int* Equals)
    {
    }


void ArrayDraw (int startX, int startY, int sizeArray, int* number, COLORREF color)
    {
    const int sizeX = 10;
    const int sizeY = 2;

    txSetFillColor (color);

    for (int index = 1; index <= sizeArray; index++)
        {
        txRectangle(startX + sizeX * index, startY - sizeY * number[index], startX + sizeX * (index+1), startY);
        printf("%d  ", number [index]);
        }
    }

void ArrayClear()
    {
    }

void ClearPlane()
    {
    Plane (230, 40, 1000);
    }

void ExitProc()
    {
    }

void mButton_t::Draw() // ������������ �� ��������� ���������!!! ���������
    {
    double x0 = this -> x_;
    double y0 = this -> y_;
    double w  = this -> x_ + this -> sizeX_;
    double h  = this -> y_ + this -> sizeY_;
    double centerX = (x0 + w) / 2;
    txSetColor(TX_WHITE);
    txSetFillColor(this->color_);
    txRectangle (x0, y0, w, h);

    txSetColor(TX_BLACK);
    txSetTextAlign (TA_CENTER);
    txSelectFont ("Comic Sans MS", 27, 8, 1);
    txTextOut (centerX, y0, this->buttonName_);
    //txSetColor(TX_WHITE);
    }

void mButton_t::Click()
    {
     // 1 - ���������, ������ �� ������� ����
     // 2 - ���� ������, ��� ��������� ����������
     // 3 ���� �������� � ������� ������, �� {���������� ������ - ������ �� ���� ������}
     //         ������� *funk_
     //         � ������� ���� ������ � ���������




 /*
 int x_; int y_;
 int sizeX_; int sizeY_;
 char* buttonName_;
 COLORREF color_;
 int* func_;
 */
    }
