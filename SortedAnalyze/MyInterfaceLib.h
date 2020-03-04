
#include "TXLib.h"
#include <stdio.h>



struct mButton_t {
                 int x_; int y_;
                 int sizeX_; int sizeY_;
                 char* buttonName_;
                 COLORREF color_;
                 bool OnClick_;
                 void Draw();
                 bool Click();
                };

const int ButtonDimetsion = 8;
const double koefY = 340/1000;
const double koefX = 2.8;  // koefY = 1000 / 365;

void StartDraw (mButton_t* butt[], int CountButton, int SizeWindowX, int SizeWindowY);

void TextShadow(int x, int y, COLORREF colorText, COLORREF colorShadow, char* text);

void Plane (int x0, int y0, int MaxY);

void ClearPlane();

void MyPoint(int x, int y, COLORREF color, int dx, int dy);

//{============================================================================
//                          Описания функций
//}============================================================================

void StartDraw (mButton_t* butt, int CountButton, int SizeWindowX, int SizeWindowY)
    {

    txSetFillColor(TX_DARKGRAY);
    txRectangle (0, 0, SizeWindowX, SizeWindowY);

    Plane (230, 50, SizeWindowX);
    for (int i = 0; i < CountButton; i++)
            {
//            assert(i=0, i<DimensionButton);
            butt[i].Draw();
            }
   }

// ----- Текст с тенью-----
void TextShadow(int x, int y, COLORREF colorText, COLORREF colorShadow, char* text)
    {
    txSetColor (colorShadow);
    txTextOut (x+1, y+1, text);
    txSetColor (colorText);
    txTextOut (x, y, text);
    }

//--- Рисование декартовых плоскостей---
void Plane (int x0, int y0, int MaxY)
    {

    txSetTextAlign (TA_LEFT);
    txSelectFont ("Comic Sans MS", 40, 10, 1, true);

    TextShadow(x0 + 10,       y0 - 45, TX_WHITE, TX_BLACK, "Зависимость сравнений от размера массива");
    TextShadow(x0 + 380 + 10, y0 - 45, TX_WHITE, TX_BLACK, "Зависимость перестановок от размера массива");

    txSetFillColor(RGB (239, 239, 239));
    txRectangle (      x0, y0,       x0 + 370, y0 + 490);
    txRectangle (x0 + 380, y0, x0 + 380 + 370, y0 + 490);

    //--- оси координатные---
    txSetColor (TX_BLACK);
    int dx = 15, dy = 15;
    txLine (      x0 + dx,       y0 + dy,             x0 + dx,  y0 + 490 - dy);
    txLine (      x0 + dx, y0 - dy + 490,       x0 - dx + 370,  y0 + 490 - dy);

    txLine (x0 + 380 + dx,       y0 + dy,       x0 + 380 + dx,  y0 + 490 - dy);
    txLine (x0 + 380 + dx, y0 - dy + 490, x0 - dx + 370 + 380,  y0 + 490 - dy);

    // --- возврат к основным настройкам
    //txSetColor(TX_WHITE);
    }



void ClearPlane()
    {
    Plane (230, 40, 1000);
    }

void MyPoint(int x, int y, COLORREF color, int dx, int dy)
    {
    txSetColor(color);
    txSetFillColor(color);
    double x1 = dx + 15 + (double)(x*340/1000);
    double y1 = 475 + dy - (double)(y*450/500000);
    txCircle (x1, y1, 2);
    }

void mButton_t::Draw() // передаваемые из структуры параметры!!! рисование
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

bool mButton_t::Click()
    {
    RECT areaButton = { this->x_, this->y_, this->x_+sizeX_, this->y_+sizeY_ };

    if (txMouseButtons() == 1)
        {
        if ((txMouseX() >=this->x_) && (txMouseX() <= this->x_ + sizeX_) && (txMouseY() >=this->y_) && (txMouseY() <= this->y_ + sizeY_) )
            return true;
        //if (In (txMousePos(), areaButton))
        //this -> OnClick_ = true;
        txSleep (0);
        }
     return false;
    }
